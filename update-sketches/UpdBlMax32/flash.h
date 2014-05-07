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
#if defined(_BOARD_FUBARINO_MINI_)
    //*********************************************************************
    //
    //                 MX1,2 Page info
    //
    //*********************************************************************
    #define PAGE_SIZE               256                // # of 32-bit Instructions per Page
    #define ROW_SIZE                32                 // # of 32-bit Instructions per Row
#else
    //*********************************************************************
    //
    //                 MX3,4,5,6,7 Page info
    //
    //*********************************************************************
    #define PAGE_SIZE               1024                // # of 32-bit Instructions per Page
    #define ROW_SIZE                128                 // # of 32-bit Instructions per Row
#endif

//*********************************************************************
//
//                 MX1,2,3,4,5,6,7 Page info
//
//*********************************************************************
#define BYTE_ROW_SIZE           (4 * ROW_SIZE)      // # Row size in Bytes
#define BYTE_PAGE_SIZE          (4 * PAGE_SIZE)     // Page size in Bytes
#define NUM_ROWS_PAGE           8                   //Number of Rows per Page

//*********************************************************************
//
//                  Macros
//
//*********************************************************************
// convert to a physical address
#define KVA_2_PA(v)         (((unsigned long) v) & 0x1fffffff)  // you can find this in <sys/kmen.h>
#define NVMOP_PAGE_ERASE    0x4004                              // Page erase operation
#define NVMOP_ROW_PGM       0x4003                              // Row program operation
#define NVMOP_WORD_PGM      0x4001                              // Word program operation

#define SuspendINT(status) asm volatile ("di %0" : "=r" (status))
#define RestoreINT(status) {if(status & 0x00000001) asm volatile ("ei"); else asm volatile ("di");}

#define ReadK0(dest) __asm__ __volatile__("mfc0 %0,$16" : "=r" (dest))
#define WriteK0(src) __asm__ __volatile__("mtc0 %0,$16" : : "r" (src))
#define K0_UNCACHED 0x00000002
#define K0_CACHED   0x00000003

#define FLASH_START_ADDR        0xBD000000ul
#define MAX_FLASH_ADDR          0xC0000000ul
#define MAX_PAGES               ((MAX_FLASH_ADDR - FLASH_START_ADDR) / BYTE_PAGE_SIZE) 

#define StartOfFlashPage(a) (a & (~(BYTE_PAGE_SIZE - 1)))
#define NextFlashPage(a) (StartOfFlashPage(a) + BYTE_PAGE_SIZE)
#define PageIndex(a) ((StartOfFlashPage(a) - FLASH_START_ADDR) / BYTE_PAGE_SIZE)

//*********************************************************************
//
//                  Forward References
//
//*********************************************************************
uint32_t FlashOperation(uint32_t nvmop, uint32_t addr, uint32_t data);
void FlashWriteBuff(uint32_t addr, const uint8_t rgbData[], uint32_t cbData);

