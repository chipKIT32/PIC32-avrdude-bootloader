/************************************************************************/
/*                                                                      */
/*  flash.c -- PLib free flash erase write functions                    */
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
*//************************************************************************/
/*  Module Description:                                                 */
/*                                                                      */
/*                                                                      */
/*  Revision History:                                                   */
/*                                                                      */
/*    09/28/2012(KeithV): Created                                       */
/*                                                                      */
/************************************************************************/
#include "WProgram.h"
#include "p32xxxx.h"
#include "flash.h"
#include "HexData.h"

//*********************************************************************
//
//                  Module Scope Variables
//
//*********************************************************************
#define cMapEntries ((MAX_PAGES + 31) / 32)
static uint32_t pageMap[cMapEntries];

/***    uint32_t * GetpMapEntry(unsigned long addr, uint32_t * poMapIndex) 
**
**    Synopsis:   
**      Gets the uint32 from the map array that represents the page the address is in
**
**    Parameters:
**      addr        - the address to find the page it is in
**      poMapIndex  - each dword represents 32 pages, these gets the bit offest
**                      that represents whether the page has been erased or not
**    Return Values:
**      a pointer to the dword in the map list that contains the bit for the requested page.
**
**    Errors:
**      NULL if the requested page is out of bounds.
**
**  Notes:
**
**
*/
static inline uint32_t * __attribute__((always_inline)) GetpMapEntry(uint32_t addr, uint32_t * poMapIndex) 
{
    uint32_t iPage = PageIndex(addr);
    uint32_t iMap = iPage / 32;

    *poMapIndex = iPage % 32;
    if(iMap > cMapEntries)
    {
         return(NULL);
    }

    return(&pageMap[iMap]);
}

/***    uint32_t WasPageErased(unsigned long addr)
**
**    Synopsis:   
**      Sees if the page where the addr exits has already been erased once
**
**    Parameters:
**      addr    - any addr in the page to see if the page was erased
**
**    Return Values:
**      TRUE if the page has already been erased, false if it has never been erased.
**
**    Errors:
**      None
**
**  Notes:
**
**
*/
static  inline uint32_t WasPageErased(uint32_t addr)
{
    uint32_t    oMapEntry = 0;
    uint32_t *  pMapEntry = GetpMapEntry(addr, &oMapEntry);

    if(pMapEntry == NULL)
    {
        return(0);
    }

    return(((*pMapEntry) >> oMapEntry) & 0x1);
}

/***    void SetPageAsErased(unsigned long addr)
**
**    Synopsis:   
**      sets the page that the addr exists in as being erased
**
**    Parameters:
**      addr    - any address in the page to set the has been erased bit
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**
*/
static inline void SetPageAsErased(uint32_t addr)
{
    uint32_t    oMapEntry = 0;
    uint32_t *  pMapEntry = GetpMapEntry(addr, &oMapEntry);
    uint32_t    mask = 0x1;

    if(pMapEntry == NULL)
    {
        return;
    }

    *pMapEntry |= (mask << oMapEntry);
}

/***    void flashOperation(uint32 nvmop, uint32 addr, uint32 data)
**
**    Synopsis:   
**      Performs either a page erase, word write, or row write
**
**    Parameters:
**      nvmop    either NVMOP_PAGE_ERASE, NVMOP_WORD_PGM, or NVMOP_ROW_PGM
**        addr    the uint32_t flash address of: the page to erase, word location to write, or row location to write
**        data    a uint32_t of data to write, or the uint32_t of the SRAM address containing the array of data to write to the row
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
uint32_t FlashOperation(uint32_t nvmop, uint32_t addr, uint32_t data)
{
    unsigned long   t0;
    unsigned int    status;

    #if defined(_PCACHE)
        unsigned long   K0;
        unsigned long   PFEN = CHECON & _CHECON_PREFEN_MASK;
    #endif

    // Convert Address to Physical Address
    NVMADDR = KVA_2_PA(addr);
    NVMDATA = data;
    NVMSRCADDR = KVA_2_PA(data);

    // Suspend or Disable all Interrupts
    SuspendINT(status);

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
    RestoreINT(status);

    // assert no errors
    return(! (NVMCON & (_NVMCON_WRERR_MASK | _NVMCON_LVDERR_MASK)));
}

/***    void flashErasePage(uint32 addrPage)
**
**    Synopsis:   
**      Erases the page starting at the page address.
**
**    Parameters:
**      addrPage    The virtual address of the page to erase
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
static void FlashErasePage(uint32_t addrPage)
{
    int i;
    int j;
    int32_t x = 0xFFFFFFFF;
    uint32_t *rgUint32 = (uint32_t *) addrPage;

    // we learned that just because the flash does not successfully
    // erase on the first attempt, it might on another. We found that
    // we can double the life of flash by attempting to
    // erase the flash up to 5 times before quitting.
    for(j=0; j<5; j++)
    {
        // first check to see if the page needs to be erased
           for (i = 0; i < BYTE_PAGE_SIZE/sizeof(uint32_t); i++) 
        {
            x &= rgUint32[i];
        }
        
        // flash erased, we are done.
        if(x == 0xFFFFFFFF)
        {
            break;
        } 
    
        // Unlock and Erase Page
        FlashOperation(NVMOP_PAGE_ERASE, addrPage, 0);
    }

    // at this point, we don't care if the flash ever actually erased as
    // as we will catch the failure when we verify the programming.
 }

/***    void justInTimeFlashErase(uint32 addrLow, uint32 addrHigh)
**
**    Synopsis:   
**      Erases all pages that have not been erased in the address range
**
**    Parameters:
**      addrLow:    low virtual address of where the page needs erased
**        addrHigh    1 + the last high byte to be erased.
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
static void JustInTimeFlashErase(uint32_t addrLow, uint32_t addrHigh)
{
    uint32_t addrCurPage    = StartOfFlashPage(addrLow);
    uint32_t addrLastPage   = NextFlashPage(addrHigh - 1);

    while(addrCurPage < addrLastPage)
    {
        // if this has never been erased, erase it.
        if(!WasPageErased(addrCurPage))
        {
            FlashErasePage(addrCurPage);
            SetPageAsErased(addrCurPage);
        }

        addrCurPage += BYTE_PAGE_SIZE;
    }
}

/***    void flashWriteBuff(uint32_t addr, const uint8_t *rgbData, uint32_t cbData)
**
**    Synopsis:   
**      Writes the buffer to flash at the specified addr
**
**    Parameters:
**      addr    - the addr where to start the write
**      rgbData - a pointer to the data to write to flash
**      cbData  - The number of bytes to write to flash
**
**    Return Values:
**      None
**
**    Errors:
**      None
**
**  Notes:
**
**      If the page has never been erased, this will automatically erase
**      the page first, on demand. Also if the buffer is not a mult
**      of a dword, the buffer will be padded with 0xFF and written. Remember
**      writing an 0xFF will not effect anything that might already exist in flash
**      so this is totally safe even if the remainder of the dword had data in it.
*/
void FlashWriteBuff(uint32_t addr, const uint8_t rgbData[], uint32_t cbData)
{
    uint32_t    addrStartAligned    = addr & (~(sizeof(uint32_t) - 1));
    uint32_t    addrEndAligned      = (addr + cbData + sizeof(uint32_t) - 1) & (~(sizeof(uint32_t) - 1));
    uint32_t    addrEnd             = addr + cbData;
    uint8_t *   prgbData            = rgbData;
    uint32_t *  pdwData             = NULL;
    int i                           = 0;

    // do nothing if we have nothing to write.
    if(cbData == 0)
    {
        return;
    }

    // make sure the pages are erased
    JustInTimeFlashErase(addr, addr + cbData);

    // if we have unaligned data at the begining of the buffer.
    if(addrStartAligned < addr)
    {
        uint32_t    addrCur     = addrStartAligned;
        uint32_t    dwordT      = 0xFFFFFFFF;
        uint8_t *   pdwordT     = &dwordT;
 
        for(i=0; i<sizeof(uint32_t); i++)
        {
            if(addrCur == addr)
            {
                pdwordT[i] = *prgbData;
                addr++;
                prgbData++;
            }
            addrCur++;
        }

        // only do this if the data is not what is already in flash
        if(dwordT != 0xFFFFFFFF)
        {    
            // Write the data
            FlashOperation(NVMOP_WORD_PGM, addrStartAligned, dwordT);
        }
    }

    // if we have unaligned data at the end of the buffer.
    if(addrEnd < addrEndAligned)
    {
        uint32_t    addrCur     = addrEndAligned;
        uint32_t    dwordT      = 0xFFFFFFFF;
        uint8_t *   pdwordT     = &dwordT;
        uint8_t *   prgbDataEnd = &rgbData[cbData];

         for(i=sizeof(uint32_t); i>0; i--)
        {
            if(addrCur == addrEnd)
            {
                pdwordT[i-1] = *(prgbDataEnd-1);
                addrEnd--;
                prgbDataEnd--;
            }
            addrCur--;
        }

        // only do this if the data is not what is already in flash
        if(dwordT != 0xFFFFFFFF)
        {    
            // Write the data
            FlashOperation(NVMOP_WORD_PGM, addrCur, dwordT);
        }
    }

    // do all of the aligned data   
    for(pdwData = (uint32_t *) prgbData; addr < addrEnd; addr += sizeof(uint32_t), pdwData++)
    {
        // only do this if the data is not what is already in flash
        if(*pdwData != 0xFFFFFFFF)
        {    
            // Write the data
            FlashOperation(NVMOP_WORD_PGM, addr, *pdwData);
        }
    }
}

