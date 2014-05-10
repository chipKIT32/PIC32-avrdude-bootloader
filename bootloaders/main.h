/**** main.h ******************************************************************
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
#ifndef MAIN_INCLUDED

#define BOOTLOADERVER               0x01000301ul
#define NULL                        ((void*)0)
#define ALLF                        (0xFFFFFFFF)
#define cbRAMReservedForDebugger    0x200ul

#include <p32xxxx.h>

// thing re-written out of plib.h for open source
#define KVA_2_PA(v) 			((v) & 0x1fffffff)
#define PA_2_KVA0(pa)           ((pa) | 0x80000000)  // cachable
#define PA_2_KVA1(pa)           ((pa) | 0xa0000000)
#define UART_RX_ENABLE			(1<<12)					/* Enable RX*/
#define UART_TX_ENABLE         	(1<<10)                 /* Enable TX*/
#define UART_ENABLE             (1<<15)                 /* UART enable */
#define TF_LITTLE(x)            (x)

// Flash operations
#define NVMOP_WORD_PGM          0x4001      // Word program operation
#define NVMOP_ROW_PGM           0x4003      // Row write
#define NVMOP_PAGE_ERASE        0x4004      // Page erase operation

#define NVMCON_NVMOP           	0x0000000f
#define NVMCON_ERASE            0x00000040
#define NVMCON_WRERR            0x00002000
#define NVMCON_WREN             0x00004000
#define NVMCON_WR               0x00008000

#define ReadK0(dest) __asm__ __volatile__("mfc0 %0,$16" : "=r" (dest))
#define WriteK0(src) __asm__ __volatile__("mtc0 %0,$16" : : "r" (src))
#define K0_UNCACHED 0x00000002
#define K0_CACHED   0x00000003

// local typedefs so we have something to use
typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef int intptr;
typedef unsigned int uintptr;

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int uint;

enum {
    false,
    true
};

#define IN
#define OUT
#define OPTIONAL
#define VARIABLE  1
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define ROUNDUP(n, s)  (((n)+(s)-1)&~((s)-1))  // N.B. s must be power of 2!
#define ROUNDDOWN(n, s)  ((n)&~((s)-1))  // N.B. s must be power of 2!
#define LENGTHOF(a)  (sizeof(a)/sizeof(a[0]))
#define OFFSETOF(t, f)  ((int)(intptr)(&((t *)0)->f))
#define IS_POWER_OF_2(x) ((((x)-1)&(x))==0)
#define MKSTR2(s) #s
#define MKSTR(s) MKSTR2(s)

//#define asm_halt()  asm("SDBBP 0");
//#define ASSERT(x)  do { if (! (x)) { asm_halt(); } } while (0)
#define ASSERT(x)
#define assert ASSERT

// forward references to the avrbl code
// needed by serial.h in BoardConfig.h
void avrbl_state_machine(byte b);
static void avrbl_run(void);
static void avrbl_message(byte *request, int size);

#include "BoardConfig.h"
#include "util.h"

typedef void __attribute__((far, noreturn)) (* FNUSERAPP)(void);
#define fIsUserAppLoadedInFlash ((*((unsigned long *) USER_APP_ADDR)) != ((unsigned long) -1))

#define startOfFlashPage(a) (a & (~(FLASH_PAGE_SIZE - 1)))
#define nextFlashPage(a) (startOfFlashPage(a) + FLASH_PAGE_SIZE)
#define numberOfFlashPages(ihigh, ilow) ((ihigh - ilow + FLASH_PAGE_SIZE - 1) / FLASH_PAGE_SIZE)
#define getPageIndex(a) (((startOfFlashPage(KVA_2_PA(a))) - KVA_2_PA(FLASH_START)) / FLASH_PAGE_SIZE)
#define wasPageErased(a) (pageMap[getPageIndex(a)] == 1)

#define imageReserved                                   0x00000000ul
#define imageMPIDE                                      0x00000001ul                        // This is a normal MPIDE sketch
#define imageBootFlashBootloader                        0x00000002ul                        // This is a boot flash bootloader
#define imageProgramFlashBootloader                     0x00000004ul                        // This is a program flash bootloader
#define imageSplitFlashBootloader                       0x00000008ul                        // This has bootloader code in both boot and program flash
#define imageFullFlashEraseLess4KEEProm                 blCapLkInstrFullFlashEraseLess4KEEProm                
#define imageJustInTimeFlashErase                       blCapLkInstrJustInTimeFlashErase                       
#define imageLinkerSpecifiedFlashErase                  blCapLkInstrFlashErase                  
#define imageFullFlashErase                             blCapLkInstrFullFlashErase                              
#define imageExecutionJumpAddress                       blCapLkInstrExecutionJumpAddress                       
#define imageExecutionJumpToFirstInFlash                blCapLkInstrExecutionJumpToFirstInFlash                

#define FNIMGJMP FNUSERAPP

#pragma pack(push,2)
typedef struct {
    uint32    cbBlRamHeader;        // the number of bytes of this header, as known by this bootloader
    uint32    rcon;                 // value of RCON before the bootloader clears it
} RAM_HEADER_INFO;

typedef struct {
    uint32  cbHeader;               // length of this structure
    uint32  verBootloader;          // version of the booloader that loaded the sketch, it will be 0xFFFFFFFF if the bootloader did not write the version.
    uint32  verMPIDE;               // the version number of MPIDE that build the sketch
    uint32  bootloaderCapabilities; // capabilities of the bootloader defined by the blCapXXX bits.
    uint16  vend;                   // vendor ID as assigned by the bootloader, 0xFF if undefined
    uint16  prod;                   // product ID as assigned by the bootloader, 0xFF if undefined, or 0xFE is unassigned
    uint32  imageType;              // see image bit field definition above
    FNIMGJMP  pJumpAddr;            // the execution address that the bootloader will jump to
    uint32  pProgramFlash;          // also known as base address, that is, the first byte of program flash used by the sketch
    uint32  cbProgramFlash;         // the number of bytes of flash used by the sketch as defined by the linker script
    uint32  pEEProm;                // pointer to the eeprom area, usually at the end of flash, but now can be defined by the linker script
    uint32  cbEEProm;               // the length of eeprom, usually 4K but can now be defined by the linker script
    uint32  pConfig;                // physical address pointer to the config bits
    uint32  cbConfig;               // length of config bits.
    RAM_HEADER_INFO * pRamHeader;   // pointer to the ram header as defined by the sketch application
    uint32  cbRamHeader;            // length of the ram header as specified by the linker and will be cleared/used by the bootloader
    uint32  cbBlPreservedRam;       // the amount RAM the bootloader will not touch, 0xA0000000 -> 0xA0000000 + cbBlPerservedRam
} IMAGE_HEADER_INFO;
#pragma pack(pop) 

extern uint32 _skip_ram_space_addr;
extern uint32 _skip_ram_space_end_adder;
extern uint32 _RAM_SKIP_SIZE;

#define offsetBaseAddrInfo 	(0x0F8ul)
#define offsetHeaderInfo 	(0x0FCul)

// The reset of the forward references
static void ExecuteApp(void);
static void justInTimeFlashErase(uint32 iLow, uint32 iHigh);
static void flashErasePage(uint32 addrPage);
static void flashWriteUint32(uint32 addrUint32, uint32 *rgu32Data, uint32 cu32Data);
static IMAGE_HEADER_INFO * getHeaderStructure(uint32 imageBaseAddr);
static void finshFlashProcessingAfterLoad(void);

#define MAIN_INCLUDED  1
#endif  // MAIN_INCLUDED
