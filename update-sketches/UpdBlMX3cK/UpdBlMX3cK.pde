/************************************************************************/
/*                                                                      */
/*  UpdBL.cpp -- Updates the bootloader to the code specified           */
/*               by the binary in the rgBTL structure                   */
/*                                                                      */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2012, Digilent Inc., All Rights Reserved                */
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
/************************************************************************/
/*  Module Description:                                                 */
/*                                                                      */
/*    This updates the bootloader code to data as specified in          */
/*    BLT (BootLoader Table) data. The BLT was automatically            */
/*    generated chipKITdude from the original bootloader .HEX file.     */
/*                                                                      */
/*                                                                      */
/*    Note:                                                             */
/*    There are 2 windows of unrecoverable failure, immediately         */
/*    after the first page is erased, and immediately after             */
/*    the config bits are erased. This time is kept short, but          */
/*    should power be lost during this time, the bootlaoder will        */
/*    have to be reprogrammed using either the licensed debugger        */
/*    or a PICkit3 depending on the board.                              */
/*                                                                      */
/*  Revision History:                                                   */
/*                                                                      */
/*    09/28/2012(KeithV): Created                                       */
/*                                                                      */
/************************************************************************/

//*********************************************************************
//
//                  external C includeds
//
//*********************************************************************
extern "C"
{
    #include "flash.h"
    #include "HexData.h"
}

//*********************************************************************
//
//                  #defines 
//
//*********************************************************************
#define ADDR_RESET  0xBFC00000ul
#define iJmp        0
#define iConfig     1

//*********************************************************************
//
//                  Header Info
//
//*********************************************************************
static const IMAGE_HEADER_INFO * pImageHeader = getImageHeaderInfoStructure();

//*********************************************************************
//
//                  const variables
//
//*********************************************************************
// The new bootloader code always has a jump instruction as the reset address; the jump just jumps around
// the jump instruction to _startup which immediatel follows the jump instruction. We need to make sure this
// sequence exists, or the new bootloader will not work correctly. This has has to do with the new code; not
// what the current bootloader is. This is just to verify that we aren't going to hose ourselves.
const uint8_t rgbCrt0Jump[] = {0xc0, 0xbf, 0x1a, 0x3c, 0x10, 0x00, 0x5a, 0x27, 0x08, 0x00, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00};

// This is our temporary replacement jump instruction, this will cause the processor to jump to our update
// sketch should the board be reset during the process of the updata. This is just like the original jump instruction
// except it jumps directly to the sketches startup location.
const uint8_t rgbTempJump[] = {0x00, 0x9d, 0x1a, 0x3c, 0x00, 0x10, 0x5a, 0x27, 0x08, 0x00, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00};

// these are actually NOP instructions on the PIC32, we will replace the above jump with NOPs when we are done so on
// reset we will just fall through to _startup in the bootloader
const uint8_t rgbNOP[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// this is a sneaky variable that will presist though a reboot. This lets me know that I already programed the bootloader
// successfully. The weird pointer stuff is to defeat the compiler optimizations.
const uint32_t fNotProgrammed = 0xFFFFFFFF;
volatile uint32_t * pfNotProgrammed = (volatile uint32_t *) &fNotProgrammed;

//*********************************************************************
//  
//                  State Variables
//
//*********************************************************************
typedef enum
{
    stCheckBootloader,
    stPrintRequest,
    stWaitForConfirmation,
    stCheckBoard,
    stNormalizeAddresses,
    stSortBLT,
    stPrintBLT,
    stVerifyJump,
    stComposeConfig,
    stEnterCriticalSection,
    stProgramBootloader,
    stProgramNOPs,
    stReset,
    stHalt,
    stDone,
    stDoNothing
} STATE;
STATE state = stCheckBootloader;

//*********************************************************************
//
//                  Module Scope Variables
//
//*********************************************************************
uint32_t ledState       = LOW;
uint32_t iBLT           = 0;
uint32_t iConfirmation  = 0;
BLT bltCritical[]       = { {ADDR_RESET, sizeof(rgbTempJump), (unsigned char *) rgbTempJump}, {0, 0, 0} };

/***    setup
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        Program entry point as defined by the chipKIT/Arduino
**        system. This function performs one-time initialization
**        required by the sketch.
*/
void setup() { 
  
    // setup button 2 on the MX4 as reset buttons, since they don't have one.
    #if defined(_BOARD_CEREBOT_MX4CK_) || defined(_BOARD_CEREBOT_32MX4_)
        pinMode(PIN_BTN2, INPUT);
    #endif

    Serial.begin(9600);

    // give you time to get the serial monitor open after the USB port is opened.
    #if defined(_BOARD_FUBARINO_SD_) || defined(_BOARD_FUBARINO_MINI_)
        // the 5 second delay is put in for the Furbario USB to allow time to open the serial monitor
        delay(5000);
    #endif

    Serial.println("UpdBL");
    Serial.println("Digilent Inc, 2012");
    Serial.println();
}

/* ------------------------------------------------------------ */
/***    loop
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is defined by the chipKIT/Arduino system.
**        It is called repeatedly, and implements the event loop
**        behavior of the sketch.
*/
void loop() {

    switch(state)
    {
        case stCheckBootloader:

            if(!(*pfNotProgrammed) || pImageHeader->verBootloader == bootloaderVer)
            {
                Serial.print("Bootloader is up-to-date at version ");
                Serial.println(bootloaderVer, HEX);
                state = stDone;
            }
            else
            {
                Serial.print("Existing bootloader version: ");
                Serial.println(pImageHeader->verBootloader, HEX);

                Serial.print("Updating to bootloader version: ");
                Serial.println(bootloaderVer, HEX);
                Serial.println();

                state = stPrintRequest;
            }
            break;

        case stPrintRequest:

            Serial.print("Please comfirm that you are updating the \"");
            Serial.print(szUpdBd);
            Serial.println("\".");
            Serial.print("If this is the board you are updating enter \"");
            Serial.print(szUpdBd);
            Serial.println("\" exactly in the serial monitor input window.");
           
            iConfirmation = 0;
            state = stWaitForConfirmation;
            break;

        case stWaitForConfirmation:

            if(iConfirmation == strlen(szUpdBd))
            {
                state = stCheckBoard;
            }
            else if (Serial.available() > 0) 
            {
                uint8_t inChar = Serial.read();

                if(inChar == szUpdBd[iConfirmation])
                {
                    iConfirmation++;
                }
                else
                {
                    Serial.println("Incorrect board name, exiting.");
                    state = stHalt;
                }
            }
            break;

        case stCheckBoard:
            {
                int cchUpdBd = strlen(szUpdBd);
                int cchCurBd = strlen(_BOARD_NAME_);

                if(cchUpdBd == cchCurBd  && (memcmp(szUpdBd, _BOARD_NAME_, cchUpdBd) == 0))
                {
                    Serial.print("Preparing to update the ");
                    Serial.println(szUpdBd);
                    Serial.println();
                    state = stNormalizeAddresses;
                }
                else
                {
                    Serial.print("This update is for the ");
                    Serial.print(szUpdBd);
                    Serial.print(";\nand it appears you are trying to update a ");
                    Serial.println(_BOARD_NAME_);
                    state = stHalt;
                }
            }
            break;

        case stNormalizeAddresses:
            {
            int i = 0;

                // we are going to normalize to the non-cashed kernel mode addressing for memory referencing.
                for(i=0; i<cBLT; i++)
                {
                    rgBLT[i].addr = ((rgBLT[i].addr & 0x0FFFFFFF) | 0xB0000000);
                }
            }
            state = stSortBLT;
            break;

        case stSortBLT:
            {
            int i = 0;
            int j = 0;
                
                // speed is not an issue, simplicity is; so lets do a well defined bubble sort
                // this will sort our addresses in asending order
                for(i=cBLT-1; i>0; i--)
                {
                    for(j=0; j<i; j++)
                    {
                        if(rgBLT[j].addr > rgBLT[j+1].addr)
                        {
                            BLT bltT;

                            memcpy(&bltT, &rgBLT[j+1], sizeof(BLT));
                            memcpy(&rgBLT[j+1], &rgBLT[j], sizeof(BLT));
                            memcpy(&rgBLT[j], &bltT, sizeof(BLT));
                        }
                    }
                }
            }
            state = stPrintBLT;
            break;

        case stPrintBLT:
            {
                int i = 0;

                Serial.println("Sorted Normalized BLT data.\n");
                for(i=0; i<cBLT; i++)
                {
                    Serial.print("BLT index ");
                    Serial.println(i, DEC);

                    Serial.print("addr = ");
                    Serial.println(rgBLT[i].addr, HEX);

                    Serial.print("cb   = ");
                    Serial.println(rgBLT[i].cb, DEC);

                    Serial.print("rgb  = ");
                    Serial.println((unsigned long) rgBLT[i].rgb, HEX);
                    Serial.println();
                }
            }
            state = stVerifyJump;
            break;

        case stVerifyJump:
            {
                int i = 0;

                // at this point we want to verify that what is going to be installed meets the requirements of this updater
                // We must have a jump instruction at the reset address _startup needs to immediately following the jump instruction

                // first find the index of the jump instruction. If this is a split-flash bootloader, there will be
                // addresses before the reset address as BD00xxxx which is program flash is less than BDC0xxxx which is bootflash
                for(i=0; i<cBLT; i++)
                {
                    if(rgBLT[i].addr == ADDR_RESET)
                    {
                        break;
                    }
                }

                // see if the new bootloader has the required jump at the ADDR_RESET
                if( i >= cBLT ||
                    (memcmp(rgbCrt0Jump, rgBLT[i].rgb, sizeof(rgbCrt0Jump)) != 0) )
                {
                    Serial.println("This bootloader updater is incompatible with the supplied bootloader.");
                    Serial.println("Exiting the updater.");
                    state = stHalt;
                }
                else
                {
                    // Update our BLT entry to not update the Jump instruction as we are going to write in the critical section.
                    rgBLT[i].addr   += sizeof(rgbCrt0Jump);
                    rgBLT[i].rgb    += sizeof(rgbCrt0Jump);
                    rgBLT[i].cb     -= sizeof(rgbCrt0Jump);
                    state = stComposeConfig;
                }
                break;
            }
        case stComposeConfig:
            {
                int i = 0;
                state = stHalt;

                // the config bits will be by definition at the end of the bootflash. However this
                // may not be the highest address. We need to find the config bit address.

                // find what block has the config bits.
                for(i=0; i<cBLT; i++)
                {
                    if( rgBLT[i].addr <= addrConfigBits && 
                        (addrConfigBits + cbConfigBits) == (rgBLT[i].addr + rgBLT[i].cb))
                    {
                        // found it; remember the end of the config bits should be at the end of the block as well.

                        // save away the config bit section
                        bltCritical[iConfig].addr  = addrConfigBits;
                        bltCritical[iConfig].cb    = cbConfigBits;
                        bltCritical[iConfig].rgb    = rgBLT[i].rgb + rgBLT[i].cb - cbConfigBits;

                        // take it out of our block since we will write this in the critical section
                        rgBLT[i].cb -= cbConfigBits;

                        // go to the next state
                        state = stEnterCriticalSection;
                        break;
                    }
                }

                // if we did not find it!
                if(state == stHalt)
                {
                    Serial.println("Unable to find an appropriate config bit block.");
                    Serial.println("Exiting the updater.");
                }
            }
    
            break;

        case stEnterCriticalSection:

            Serial.println("WARNING: Entering critical section!");
            Serial.println("Do NOT reset or remove power");
            Serial.println("Erasing and programming a temporary reset jump address");
            Serial.println("Also erasing and programming config bits");
            
            FlashWriteBuff(bltCritical[iJmp].addr, bltCritical[iJmp].rgb, bltCritical[iJmp].cb);
            FlashWriteBuff(bltCritical[iConfig].addr, bltCritical[iConfig].rgb, bltCritical[iConfig].cb);

            if( (memcmp((void *) bltCritical[iJmp].addr, bltCritical[iJmp].rgb, bltCritical[iJmp].cb) == 0) &&
                (memcmp((void *) bltCritical[iConfig].addr, bltCritical[iConfig].rgb, bltCritical[iConfig].cb) == 0) )
            {
                Serial.println("SUCCESS: Exiting critical section!");
                Serial.println("The temporary jump instruction and config bits have been successfully written and verified.");
                Serial.println("Programming the new bootloader.");
                state = stProgramBootloader;
                iBLT = 0;
            }

            // oh this is ugly! It didn't work.
            else
            {
                Serial.println("CATASTROPHIC: Erase / Write Failure!");
                Serial.println("To reprogram the bootloader you will need to use a hardware debugger.");
                state = stHalt;
            }
            break;

        case stProgramBootloader:

            if(iBLT < cBLT)
            {
                FlashWriteBuff(rgBLT[iBLT].addr, rgBLT[iBLT].rgb, rgBLT[iBLT].cb);

                if( memcmp((void *) rgBLT[iBLT].addr, rgBLT[iBLT].rgb, rgBLT[iBLT].cb) == 0 )
                {
                    iBLT++;
                }
                else
                {
                    Serial.println("Erase / Write Failure!");
                    Serial.println("To restart the update, reset or power cycle the board.");
                    state = stHalt;
                }
            }
            else
            {
                state = stProgramNOPs;
            }
            break;

        case stProgramNOPs:

            Serial.println("WARNING: Entering critical section!");
            Serial.println("Do NOT reset or remove power");
            Serial.println("Removing temporary reset jump address, linking in the new bootloader.");            

            FlashWriteBuff(bltCritical[iJmp].addr, rgbNOP, sizeof(rgbNOP));

            if(memcmp((void *) bltCritical[iJmp].addr, rgbNOP, sizeof(rgbNOP)) == 0)
            {
                Serial.println("SUCCESS: Exiting critical section!");
                Serial.println("The new bootloader had been linked into the board reset.");
                state = stReset;
            }
            else
            {
                Serial.println("CATASTROPHIC: Erase / Write Failure!");
                Serial.println("To reprogram the bootloader you will need to use a hardware debugger.");
                state = stHalt;
            }
            break;

        case stReset:

            // this is a hack to finish. Usually the bootloader programs the version number, but
            // that only happens when the sketch is loaded, since this sketch is already loaded
            // just set a flag to say we already programmed. Be careful not to erase the page 
            // as that would erase part of the sketch.
            FlashOperation(NVMOP_WORD_PGM, (uint32_t) pfNotProgrammed, 0);
            Serial.println("Reseting the board to enable the new bootloader.");
            Serial.println();
            delay(50);  // give some time to print to the serial monitor before just killing the sketch
            executeSoftReset(RUN_SKETCH_ON_BOOT);
            state = stHalt;
            break;

        case stHalt:
            Serial.println("Update is aborted.");
            Serial.println("Program Halted");
            state = stDoNothing;
            break;

        case stDone:
            Serial.println("Sketch is done.");
            state = stDoNothing;
            break;

        case stDoNothing:
        default:
            break;
    }

    // The 32MX4 and MX4cK do not have reset buttons on them, so let's make
    // button 2 a soft reset button.
    #if defined(_BOARD_CEREBOT_MX4CK_) || defined(_BOARD_CEREBOT_32MX4_)
        if(digitalRead(PIN_BTN2) == HIGH)
        {
            executeSoftReset(RUN_SKETCH_ON_BOOT);
        }
    #endif
}
