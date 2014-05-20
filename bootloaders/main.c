/**** main.c ******************************************************************
 *
 * this is the main program that is launched by crt0.S; it just
 * initializes all of the modules of the os and then runs the main
 * application program loop.
 *
 * This file originated from the cpustick.com skeleton project from
 * http://www.cpustick.com/downloads.htm and was originally written
 * by Rich Testardi; please preserve this reference and share bug
 * fixes with rich@testardi.com.
 * Copyright 2014 Rich Testardi
 *
 * This program is free software; distributed under the terms of
 * BSD 3-clause license ("Revised BSD License", "New BSD License", or "Modified BSD License")
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1.    Redistributions of source code must retain the above copyright notice, this
 *        list of conditions and the following disclaimer.
 * 2.    Redistributions in binary form must reproduce the above copyright notice,
 *        this list of conditions and the following disclaimer in the documentation
 *        and/or other materials provided with the distribution.
 * 3.    Neither the name(s) of the above-listed copyright holder(s) nor the names
 *        of its contributors may be used to endorse or promote products derived
 *        from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define PUT_CONFIG_BITS_HERE
#include "main.h"

// the stk500v2 state machine states
// see: http://www.atmel.com/dyn/resources/prod_documents/doc2591.pdf
enum {
    STATE_START,
    STATE_GETSEQ,
    STATE_GETMS1,
    STATE_GETMS2,
    STATE_GETTOK,
    STATE_GETDATA,
    STATE_GETCSUM
};

// the stk500v2 constants
#define CMD_SIGN_ON                         0x01
#define CMD_SET_PARAMETER                   0x02
#define CMD_GET_PARAMETER                   0x03
#define CMD_LOAD_ADDRESS                    0x06
#define CMD_ENTER_PROGMODE_ISP              0x10
#define CMD_LEAVE_PROGMODE_ISP              0x11
#define CMD_CHIP_ERASE_ISP                  0x12
#define CMD_PROGRAM_FLASH_ISP               0x13
#define CMD_READ_FLASH_ISP                  0x14
#define CMD_SPI_MULTI                       0x1D

#define STATUS_CMD_OK                       0x00

#define SIGNATURE_BYTES 0x504943

// indicates stk500v2 protocol is active
static volatile bool active;  // bootloader is active
static volatile bool fLoaded = false;  // bootloader has loaded

static uint32 tLoopTime;
static uint32 tLoopStart;
static uint32 tLastBlink;

static FNUSERAPP UserApp = (FNUSERAPP) USER_APP_ADDR;
static bool fLoadProgramFromFlash = false;

// stuff about the bootloader written into the image header
static uint32 bootloaderVer             = BOOTLOADERVER;
static uint32 prodAndVend               =  PROD << 16 | VEND;
static uint32 bootloaderCapabilities    = CAPABILITIES;
static RAM_HEADER_INFO ramHeader;

// indicates flash has been erased
static bool erased;

// stk500v2 request state
static int state = STATE_START;
static byte seq;
static int size;
static byte csum;

// stk500v2 request message
static bool ready;          // request has been received and is ready to process
static int requesti;        // number of request bytes
static byte request[1024];  // request buffer
#define REQUEST_OFFSET  2   // shift request buffer so flash data at byte offset 10 is 32-bit aligned

// stk500v2 reply message
static int replyi;          // number of reply bytes
static byte reply[1024];    // reply buffer

// Just-In-Time-Flash variables.

// Unfortunately FLASH_BYTES is calculated at run time, so we have to just
// an array that is bigger than any part. For now we allow for 2MB or Flash
// static byte rgPageMap[FLASH_BYTES/FLASH_PAGE_SIZE];
static byte pageMap[FLASH_BYTES/FLASH_PAGE_SIZE];
static uint32 addrBase = FLASH_START;
static uint32 avrdudeAddrBase = FLASH_START;
static uint32 cbSkipRam = ((uint32) &_RAM_SKIP_SIZE);  

int main()  // we're called directly by Crt0.S
{
    ASSERT(sizeof(byte) == 1);
    ASSERT(sizeof(uint16) == 2);
    ASSERT(sizeof(uint32) == 4);
 
    ramHeader.rcon = RCON;
    InitLEDsAndButtons();

    // sometimes there is a debugger circuit on the board that needs to intialize and will
    // pull the reset line after 6 seconds or so and abruptly abort the loaded applicaiton.
    // this pause is put in for a Power On Reset only and waits for the debug circuit to come up
    // and apply the external reset which this call will ignore.
    WaitForFinalReset();

    // Determine if there is anything loaded in flash
    fLoadProgramFromFlash = fIsUserAppLoadedInFlash;

    // we have 3 conditions

    // 1. The program button tells use to wait indefinitely (don't load from flash) for an upload
    fLoadProgramFromFlash &= !fLoadFromAVRDudeViaProgramButton;

    // 2. The virtual program button tells us to wait indefinitly for an upload
    //      but only if this is not from a real reset of the processor and must come as a software reset.
    fLoadProgramFromFlash &= !(fLoadFromAVRDudeViaVirtualProgramButton && !RCONbits.POR && !RCONbits.EXTR && RCONbits.SWR);

    // 3. Otherwise we will either load the program immediately, or wait our timeout time to load
    // this will happen in the for loop below

	// Always clear out RCON after 'using' it's values, so it doesn't screw things up next time
    // This must occur after the WaitForFinalReset() and checking our program buttons states
    ClearVirtualProgramButton();
	RCON = 0;	
	
    // If we are just going to immediately load from flash
    // don't even init the UART or USB, just load the application
    if (fLoadProgramFromFlash && LISTEN_BEFORE_LOAD == 0)
	{
        // launch the application!
        ExecuteApp();
    }
	
    tLoopStart = _CP0_GET_COUNT();
    tLastBlink = tLoopStart;

    // at this point we know that we either are going to wait
    // for something to be download, or are going to wait indefinitly for
    // for a download, in any case we need to enable the the interface for the download
    InitStk500v2Interface();

    // forever...
    for (;;) {
        tLoopTime = _CP0_GET_COUNT();

        // This is the listening heartbeat LED.
        // we blink at twice the speed when downloading, thus the divide by 2 shift with active
        // In reality, when downloading starts the boot LED is erratic; look at the download LED
        // to see if you are downloading.
        if ((tLoopTime - tLastBlink) >= ((CORE_TIMER_TICKS_PER_MILLISECOND  * 125) >> active)) {
            
            // blink the heartbeat LED
            BootLED_Toggle();

            // set up for the next blink
            tLastBlink = tLoopTime;
       }

        // See if we should jump to the application in flash
        // If we just loaded an application via the Stk500v2Interface, we know there is an applicaiton
        // in flash and we can jump right to it now.
        if( fLoaded ||

            // If a program button is used, fLoadProgramFromFlash will be set false
            // as a program button will instruct to either immediately load from flash
            // and that will happen before this while loop, or wait forever for a program to load
            // and we will jump to the applicaiton only once fLoaded is true
            // This is also be false if there was never an application loaded in flash
            // Also when we are downloading and app, this is set false to block jumping to the application until fLoaded is true
            (fLoadProgramFromFlash &&

            // This is to support the auto-reset feature.
            // After a reset we listen for an stk500v2 download request.
            // However if a new application isn't loaded for LISTEN_BEFORE_LOAD milliseconds
            // then just jump to the loaded application in flash. If there is no application in
            // flash, fLoadProgramFromFlash will be false and we wait until something is downloaded
            // via stk500v2 and fLoaded becomes true.
           ((tLoopTime - tLoopStart) >= (LISTEN_BEFORE_LOAD * CORE_TIMER_TICKS_PER_MILLISECOND))
          ))
        {
            // launch the application!
            ExecuteApp();
        }

        // There are no interrupts, so we must poll
        // the stk500v2 interface to see if a character came in.
        // This may be from the UART or USB input (depending on what is being used).
        stk500v2_isr();

        // if we've received an stk500v2 request...
        // that is, something come in and we need to process it
        if (ready) {
            // process it
            avrbl_message(request+REQUEST_OFFSET, requesti);
            ready = false;
        }
    }

    ASSERT(0);  // stop!
    return 0;
}

// *** avrbl.c *****************************************************************
//
// this file implements the main program loop of the PIC32 USB CDC/ACM
// avrdude bootloader that lives entirely in bootflash
//
// This file originated from the cpustick.com skeleton project from
// http://www.cpustick.com/downloads.htm and was originally written
// by Rich Testardi; please preserve this reference and share bug
// fixes with rich@testardi.com.
//
// KeithV (Digilent) 2/21/2012 Made code configurable by including BoardConfig.h
//                              Removed all references to plib.h C-runtime libarary

// this function handles the stk500v2 message protocol state machine
void avrbl_state_machine(byte b)
{
    csum ^= b;
    
    switch (state) {
        case STATE_START:
            if (b == 27) {
                state = STATE_GETSEQ;
            }
            csum = b;
            break;
        case STATE_GETSEQ:
            seq = b;
            state = STATE_GETMS1;
            break;
        case STATE_GETMS1:
            size = b<<8;
            state = STATE_GETMS2;
            break;
        case STATE_GETMS2:
            size |= b;
            state = STATE_GETTOK;
            break;
        case STATE_GETTOK:
            if (b == 14) {
                requesti = 0;
                state = STATE_GETDATA;
            } else {
                state = STATE_START;
            }
            break;
        case STATE_GETDATA:
            request[REQUEST_OFFSET+requesti++] = b;
            if (requesti == size) {
                state = STATE_GETCSUM;
            }
            break;
        case STATE_GETCSUM:
            if (csum) {
                ASSERT(0);
            } else {
                ready = true;
            }
            state = STATE_START;
            break;
        default:
            ASSERT(0);
            break;
    }
}

// this function sends bytes to the CDC/ACM port
static void 
avrbl_print(const byte *buffer, int length)
{
    stk500v2_print(buffer, length);
}

// this function handle an stk500v2 message
static void
avrbl_message(byte *request, int size)
{
    static uint32 load_address;  // load address for stk500v2 flash read/write operations
    static byte parameters[256];  // track stk500v2 parameters (we ignore them all)
	static bool fGetBaseAddress = true;

    uint32 i;
    uint32 nbytes;
    uint32 nbytesAligned;
    uint32 endAddr;
    uint32 address;
    int rawi;
    byte raw[64];

    ASSERT(! replyi);

    // our reply message always starts with the message and status bytes
    reply[replyi++] = *request;
    reply[replyi++] = STATUS_CMD_OK;

    // process the request message and generate additional reply message bytes
    switch (*request) {
        case CMD_SIGN_ON:

            // this will block us from loading from flash if our auto-reset timeout occures while we are actually
            // in the process of downloading a new applicaiton. We wil have to wait until fLoaded is true before
            // we will load the application.
            fLoadProgramFromFlash = false; 

            active = true;
            erased = false;
            reply[replyi++] = 8;
            ilstrcpy(reply+replyi, "STK500_2");
            replyi += 8;
            DownloadLED_On();
            break;
        case CMD_SET_PARAMETER:
            parameters[request[1]] = request[2];
            break;
        case CMD_GET_PARAMETER:
            reply[replyi++] = parameters[request[1]];
            break;
        case CMD_ENTER_PROGMODE_ISP:
            break;
        case CMD_SPI_MULTI:
            reply[replyi++] = 0;
            reply[replyi++] = request[4];
            reply[replyi++] = 0;
            if (request[4] == 0x30) {
                if (request[6] == 0) {
                    reply[replyi++] = (byte)(SIGNATURE_BYTES>>16);
                } else if ( request[6] == 1 ) {
                    reply[replyi++] = (byte)(SIGNATURE_BYTES>>8);
                } else {
                    reply[replyi++] = (byte)SIGNATURE_BYTES;
                }

           } else if ((request[4] == 0x20) || (request[4] == 0x28)) {

/* this is never called, but lets just lie and say 0xFF
                //* read one byte from flash
                //* 0x20 is read odd byte
                //* 0x28 is read even byte

                //* read the even address
                address = (request[5]<<8)|(request[6]);
                //* the address is in 16 bit words
                address = address<<1;

                if (request[4] == 0x20) {
                    reply[replyi++] = *(uint16 *)(FLASH_START+address);
                } else {
                    reply[replyi++] = (*(uint16 *)(FLASH_START+address))>>8;
                }
*/
				reply[replyi++] = 0xFF;
            } else {
                reply[replyi++] = 0;
            }
            reply[replyi++] = STATUS_CMD_OK;
            break;
        case CMD_CHIP_ERASE_ISP:
			// removed so we can get the base address on the program flash
            //flash_erase_pages((void *)FLASH_START, FLASH_BYTES/FLASH_PAGE_SIZE);
            //erased = true;
            break;
        case CMD_LOAD_ADDRESS:
            load_address = (request[1]<<24)|(request[2]<<16)|(request[3]<<8)|(request[4]);
            //* the address is in 16 bit words
            load_address = load_address<<1;
            ASSERT((load_address&3)==0);
			load_address += avrdudeAddrBase;	// lets get our virtual address
            break;
        case CMD_PROGRAM_FLASH_ISP:

            // start of our buffer needs to be DWORD aligned
            ASSERT(((uintptr)(request+10)&3)==0);

            // according to the spec, the message body can not exceed 275 bytes
            // our buffer is 1024, more than big enough
            // if we have an odd number of bytes, we need to round up and make it DWORD aligned
            // The last thing in this message is data, so we can just put 0xFFs at the end
            // and round up to a word alignment.
            nbytes = ((request[1])<<8)|(request[2]); 
            nbytesAligned = (nbytes + 3) & (~(0x3));

            // just put 0xFF at the end of the buffer until we are DWORD aligned
            for(i=nbytes; i<nbytesAligned; i++)
            {
                request[10+i] = 0xFF;  // append some 0xFFs
            }

			if(fGetBaseAddress)
			{
				// here we must know how old and new ones look 
				// old images all started at offest 0x180, so the first
				// avrdude load address was 0x100 - 0x1FF
				// new images all start at offset 0xF8, so avrdude will
				// send us the block at 0x000 - 0xFF
				if(nbytesAligned >= 0x100 && (load_address & 0x1FF) == 0x000)		// must not be offset 0x100 - 0x1FF
				{
					uint32 addrBaseT = *((uint32 *)(request+10+offsetBaseAddrInfo));
					
					// stupid avrdude only knows about 64K of memory and doesn't really know
					// about anything above that, so the upper 16bits are masked. We use the upper
					// 16 bits as our base address to add on. Fortunately, avrdude can program more than 64K.
					if(addrBaseT != ALLF)
					{
						load_address -= avrdudeAddrBase;			// back out the assigned base
						avrdudeAddrBase = addrBaseT & 0xFFFF0000;	// use the new base address
						load_address += avrdudeAddrBase;			// apply the new base address
						addrBase = addrBaseT;
					}
				}
				fGetBaseAddress = false;
			}

            // erase the pages we are about to write to if needed.
            justInTimeFlashErase(load_address, load_address + nbytesAligned)

            // program the words
            ASSERT((load_address & 3) == 0);    // this will assert if we got off DWORD alignment
            flashWriteUint32(load_address, (uint32 *)(request+10), nbytesAligned/4);
            load_address += nbytes;             // we tell the truth even if we are not DWORD aligned
            break;                              // this will cause an assert if we do not get a new load address the next time

        case CMD_READ_FLASH_ISP:

            endAddr = load_address + ((request[1])<<8)|(request[2]);

			// do this page by page as we might have to lie to avrdude.
			while(load_address < endAddr)
			{
				uint32 addrEndPage = nextFlashPage(load_address);
				byte lieMask = wasPageErased(load_address) ? 0 : 0xFF;

				// don't go beyond what was requested; might be before the end of the page
				if(addrEndPage >= endAddr)
				{
					addrEndPage = endAddr;
				}

				// load the data and apply lie.
				while(load_address < addrEndPage)
				{
					reply[replyi++] = *((byte *)(load_address)) | lieMask;
					load_address++;
				}
			}
 
            reply[replyi++] = STATUS_CMD_OK;
            break;
        case CMD_LEAVE_PROGMODE_ISP:
            finshFlashProcessingAfterLoad();
            fLoaded = true;
            DownloadLED_Off();
            break;
        default:
            ASSERT(0);
            break;
    }

    // send our reply header
    rawi = 0;
    raw[rawi++] = 27;
    raw[rawi++] = seq;
    raw[rawi++] = replyi>>8;
    raw[rawi++] = replyi;
    raw[rawi++] = 14;
    csum = 0;
    for (i = 0; i < rawi; i++) {
        csum ^= raw[i];
    }
    avrbl_print(raw, rawi);

    // send the reply message bytes
    for (i = 0; i < replyi; i++) {
        csum ^= reply[i];
    }
    avrbl_print(reply, replyi);

    // send the reply checksum
    avrbl_print(&csum, 1);

    replyi = 0;
}

// The remainder of this source file was included for higher optimizations on the MX 1/2 bootloaders
// but is provided under the BSD 3-Clause license

/************************************************************************/
/*  Author:     Keith Vogel                                             */
/*  Copyright 2013, Digilent Inc.                                       */
/************************************************************************/
/*
*
* Copyright (c) 2013-2014, Digilent <www.digilentinc.com>
* Contact Digilent for the latest version.
*
* This program is free software; distributed under the terms of
* BSD 3-clause license ("Revised BSD License", "New BSD License", or "Modified BSD License")
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* 1.    Redistributions of source code must retain the above copyright notice, this
*        list of conditions and the following disclaimer.
* 2.    Redistributions in binary form must reproduce the above copyright notice,
*        this list of conditions and the following disclaimer in the documentation
*        and/or other materials provided with the distribution.
* 3.    Neither the name(s) of the above-listed copyright holder(s) nor the names
*        of its contributors may be used to endorse or promote products derived
*        from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/***    void ExecuteApp(void)
**
**    Synopsis:   
**      Jumps to the application
*
**    Parameters:
**      None
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**		If there is a header, it will jump to the location specified by the header
**		Remeber that UserApp is set by default to the jump address assigned in BoardConfig.h
*/
static void ExecuteApp(void)
{
  IMAGE_HEADER_INFO *   pHeaderInfo;

    UninitStk500v2Interface(); 
    UninitLEDsAndButtons();
    
	// We are about to jump to the application
	// but lets first check to see if the header info gave me a 
	// special jump location
	// see if we have a header
	if((pHeaderInfo = getHeaderStructure(addrBase)) != NULL)
    {
        // if we just programmed, and we are told to jump to the first sketch in flash
        // Don't do this on a simple reset start.
        if(fLoaded && (pHeaderInfo->imageType & imageExecutionJumpToFirstInFlash) == imageExecutionJumpToFirstInFlash)
        {
            if((pHeaderInfo = getHeaderStructure(FLASH_START)) != NULL)
            {
       		    // Set the jump location
    		    UserApp = pHeaderInfo->pJumpAddr;
            } 
        }
        else
        {
      		// Set the jump location
    		UserApp = pHeaderInfo->pJumpAddr;
        }

        // now load the RAM HEADER DATA
        // check to see if we have header info? We use the cbHeader as a version number
        if( pHeaderInfo->cbHeader >= OFFSETOF(IMAGE_HEADER_INFO,cbBlPreservedRam) &&        
            // is the header in our perserved space? Can we at least save the number of bytes written to the header?
            ((uint32) pHeaderInfo->pRamHeader) <= (((uint32) &_skip_ram_space_end_adder) - sizeof(uint32)) )    
        {
            uint32 cb = MIN(pHeaderInfo->cbRamHeader, sizeof(RAM_HEADER_INFO)); // only copy what we the bootloader and sketch both know
            
            // and make sure we don't walk on our (the bootloaders) own memory
            cb = MIN(cb, (((uint32) &_skip_ram_space_end_adder) - ((uint32) pHeaderInfo->pRamHeader)));

            // store how much the bootloader is going to write.
            ramHeader.cbBlRamHeader = cb;

            // copy, ensuring not to whack the bootloader's own memory, or the sketches persistent data
            ilmemcpy(pHeaderInfo->pRamHeader, &ramHeader, cb);
        }
	}


    // jump to the sketch
    // by default, USER_APP_ADDR as defined in BoardConfig.h is used.
	UserApp();
}

/***    static HEADER_INFO * getHeaderStructure(uint32 imageBaseAddr)
**
**    Synopsis:   
**      See if we have a header and gets a pointer to it
*
**    Parameters:
**      imageBaseAddr the base address of the image, like FLASH_START
**
**    Return Values:
**      A pointer to the header or NULL if one does not exist
**
**    Errors:
**      None
**
**  Notes:
**
**
*/
static IMAGE_HEADER_INFO * getHeaderStructure(uint32 imageBaseAddr)
{
  	IMAGE_HEADER_INFO *     pHeaderInfo;
	uint32 			        addr 		= imageBaseAddr + offsetHeaderInfo;
    uint32 			        addrHigh 	= FLASH_START + FLASH_BYTES;

	// see if we even wrote the header address in the image
    if(addr+sizeof(uint32) <= addrHigh)
    {
        addr = *((uint32 *) addr);		// dereference and get the header address

		// now lets see if it was an old, pre-header image; if so it will have 0xFFFFFFFF (ALLF) there.
        if( addr != ALLF && ((addr % 4) == 0) && addr+sizeof(IMAGE_HEADER_INFO) <= addrHigh)
        {
            pHeaderInfo = (IMAGE_HEADER_INFO *) addr;		// it is a header, set our header struct to it.

            if(pHeaderInfo->pProgramFlash == imageBaseAddr)
            {
				// all looks good, so we have the header.
				return(pHeaderInfo);
            }           
        }     
    }

	return(NULL);
}

/***    void eraseFlashViaHeaderInstructions(void)
**
**    Synopsis:   
**      When done loading a program, clear the rest of flash as defined by the header info
*
**    Parameters:
**      None
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**		If no header then all of flash is cleared like the original bootloader did
*/
static void finshFlashProcessingAfterLoad(void)
{
  	IMAGE_HEADER_INFO *   pHeaderInfo;

	// Historically we use to clear all of flash except 4K of EEProm, so set the flash limits
	// to what they use to be, if we have no header this is what will be done.
    uint32 			addrLow		= FLASH_START;
    uint32 			addrHigh 	= FLASH_START + FLASH_BYTES - DEFAULT_EEPROM_SIZE;

	// see if we have a header
	if((pHeaderInfo = getHeaderStructure(addrBase)) != NULL)
    {    
        // This is stuff that needs to be put in the header
        flashWriteUint32((uint32) &pHeaderInfo->verBootloader, &bootloaderVer, 1);
        flashWriteUint32((uint32) &pHeaderInfo->vend, &prodAndVend , 1);
        flashWriteUint32((uint32) &pHeaderInfo->bootloaderCapabilities, &bootloaderCapabilities, 1);
        flashWriteUint32((uint32) &pHeaderInfo->cbBlPreservedRam, &cbSkipRam, 1);

		// if we are instructed to only erase pages touched, we are done.
		if((pHeaderInfo->imageType & imageJustInTimeFlashErase) == imageJustInTimeFlashErase)
		{
			return;	// nothing more to do
		}		
		// if we are asked to erase the range of pages in the header, erase to those limits
		else if((pHeaderInfo->imageType & imageLinkerSpecifiedFlashErase) == imageLinkerSpecifiedFlashErase)
		{
		            	addrLow 	= pHeaderInfo->pProgramFlash;
		            	addrHigh 	= addrLow + pHeaderInfo->cbProgramFlash;
		}

        // if we are instructed to erase all of flash, do everything, including eeprom
		else if((pHeaderInfo->imageType & imageFullFlashErase) == imageFullFlashErase)
		{
		            	addrHigh 	= FLASH_START + FLASH_BYTES;
		}

        // and if none of the above, we will erase all but the last 4K reserved for EEProm 
        // as we did in the past.
 	}           

    // Cleared any pages that have not been cleared to the requested limits
	// by default his will be all of flash if we did not have a header.
    justInTimeFlashErase(addrLow, addrHigh);
}

// *** flash.c *****************************************************************
//
// this file implements the low level flash control and access.
//
// This file originated from the cpustick.com skeleton project from
// http://www.cpustick.com/downloads.htm and was originally written
// by Rich Testardi; please preserve this reference and share bug
// fixes with rich@testardi.com.
// KeithV (Digilent) 6/10/2012 Modified for Just-In-Time-Flash-Erase; moved to main.c

/***    void flashOperation(uint32 nvmop, uint32 addr, uint32 data)
**
**    Synopsis:   
**      Performs either a page erase, word write, or row write
**
**    Parameters:
**      nvmop	either NVMOP_PAGE_ERASE, NVMOP_WORD_PGM, or NVMOP_ROW_PGM
**		addr	the uint32_t flash address of: the page to erase, word location to write, or row location to write
**		data	a uint32_t of data to write, or the uint32_t of the SRAM address containing the array of data to write to the row
**
**    Return Values:
**      True if successful, false if failed
**
**    Errors:
**      None
**
**  Notes:
**      data has no meaning when page erase is specified and should be set to 0ul
**
*/
static void __attribute__((nomips16)) flashOperation(uint32 nvmop, uint32 addr, uint32 data)
{
    unsigned long   t0;
//    unsigned int    status;

    #if defined(_PCACHE)
        unsigned long   K0;
        unsigned long   PFEN = CHECON & _CHECON_PREFEN_MASK;
    #endif

    // Convert Address to Physical Address
    NVMADDR = KVA_2_PA(addr);

#if defined(__PIC32MZ__)
    NVMDATA0 = data;
#else
    NVMDATA = data;
#endif
    NVMSRCADDR = KVA_2_PA(data);

    // Suspend or Disable all Interrupts
// no interrupts in the bootloader
//    SuspendINT(status);  

    #if defined(_PCACHE)
        // disable predictive prefetching, see errata
        CHECONCLR = _CHECON_PREFEN_MASK;

        // turn off caching, see errata
        ReadK0(K0);
        WriteK0((K0 & ~0x07) | K0_UNCACHED);
    #endif

 	// Enable Flash Write/Erase Operations
    NVMCON = NVMCON_WREN | nvmop;

    // this is a poorly documented yet very important
    // required delay on newer silicon.
    // If you do not delay, on some silicon it will
    // completely latch up the flash to where you need
    // to cycle power, so wait for at least
    // 6us for LVD start-up, see errata
    t0 = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() - t0 < ((6 * F_CPU) / 2 / 1000000UL));

    // magic unlock sequence
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    NVMCONSET = NVMCON_WR;

    // Wait for WR bit to clear
    while (NVMCON & NVMCON_WR);

    // see errata, wait 500ns before writing to any NVM register
    t0 = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() - t0 < ((F_CPU / 2 / 2000000UL)));

    // Disable Flash Write/Erase operations
    NVMCONCLR = NVMCON_WREN;

    #if defined(_PCACHE)
        // restore predictive prefetching and caching, see errata
        WriteK0(K0);
        CHECONSET = PFEN;
    #endif

    // Restore Interrupts 
//no interrupts in the bootloader
//    RestoreINT(status);

    // assert no errors
// no return type in bootloader
//    return(! (NVMCON & (_NVMCON_WRERR_MASK | _NVMCON_LVDERR_MASK)));
}

/***    void flashErasePage(uint32 addrPage)
**
**    Synopsis:   
**      Erases the page starting at the page address.
*
**    Parameters:
**      addrPage	The virtual address of the page to erase
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**      addrPage must be page aligned.
**
*/
static void flashErasePage(uint32 addrPage)
{
    int i;
    int j;
    int32 x = ALLF;
    uint32 *rgUint32 = (uint32 *) addrPage;

    // we learned that just because the flash does not successfully
    // erase on the first attempt, it might on another. We found that
    // we can double the life of flash by attempting to
    // erase the flash up to 5 times before quitting.
    for(j=0; j<5; j++)
    {
    	// first check to see if the page needs to be erased
       	for (i = 0; i < FLASH_PAGE_SIZE/sizeof(uint32); i++) 
    	{
    		x &= rgUint32[i];
    	}
    	
        // flash erased, we are done.
        if(x == ALLF)
        {
            break;
        } 
	
        // Unlock and Erase Page
        flashOperation(NVMOP_PAGE_ERASE, addrPage, 0);
    }

    // at this point, we don't care if the flash ever actually erased as
    // as we will catch the failure when we verify the programming.
 }

/***    void flashWriteUint32(uint32 addrUint32, uint32 *rgu32Data, uint32 cu32Data)
**
**    Synopsis:   
**      Writes an array to uint32 to flash
*
**    Parameters:
**      rgu32Data	Pointer to an array of uint32
**		cu32Data	The number of uint32 to write
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**      Assumes the pages have already been erased.
**
*/
static void flashWriteUint32(uint32 addrUint32, uint32 *rgu32Data, uint32 cu32Data)
{
    int  i = 0;

    for(i=0; i < cu32Data; i++) 
	{

		// only do this if the data is not what is already in flash
		if(rgu32Data[i] != ALLF)
		{	
	        // Write the data
	        flashOperation(NVMOP_WORD_PGM, addrUint32, rgu32Data[i]);
		}

        addrUint32 += sizeof(uint32);
    }
}

/***    void justInTimeFlashErase(uint32 addrLow, uint32 addrHigh)
**
**    Synopsis:   
**      Erases all pages that have not been erased in the address range
*
**    Parameters:
**      addrLow:	low virtual address of where the page needs erased
**		addrHigh	1 + the last high byte to be erased.
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**      The address do not need to be page aligned.
**
*/
static void justInTimeFlashErase(uint32 addrLow, uint32 addrHigh)
{
	uint32 addrCurPage 		= startOfFlashPage(addrLow);
	uint32 addrLastPage 	= nextFlashPage(addrHigh - 1);
	uint32 iPage 			= getPageIndex(addrCurPage);

	while(addrCurPage < addrLastPage)
	{
		// if this has never been erased, erase it.
		if(pageMap[iPage] == 0)
		{
			flashErasePage(addrCurPage);
			pageMap[iPage] = 1;
		}

		iPage++;
		addrCurPage += FLASH_PAGE_SIZE;
	}
}
