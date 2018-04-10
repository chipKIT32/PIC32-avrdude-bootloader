/************************************************************************/
/*                                                                      */
/*    BoardConfig.h   This configures board specific features           */
/*                  for the stk500v2 avrdude/MPIDE PIC32                */
/*                    compliment bootloader                             */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
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
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    2/23/2011(KeithV): Created                                        */
/*    6/17/2012(KeithV): Added Just In Time Flash Erase                 */
/*    6/17/2012(KeithV): Added header information                       */
/*    6/25/2012(KeithV): Added Vendor ID and Product IDs                */
/*    1/15/2013(BrianS): Added PPS unlock for MX1/MX2 devices           */
/*    3/18/2013(BrianS): Added 48Mhz FB Mini device, fixed USBID and    */
/*                       VBUSON                                         */
/*    22/5/2013(gmtii):  Added Olimex PIC32 Pinguino board		        */
/*    6/2302/13(BrianS): Added DP32                                     */
/*    1/15/2014 (KeithV): Added MZ support                              */
/*                                                                      */
/************************************************************************/

// *****************************************************************************
// *****************************************************************************
//                     Helper Macros
// *****************************************************************************
// *****************************************************************************
#define CAT1_2(a,b)         a##b
#define CAT_2(a,b)          CAT1_2(a,b)
#define CAT_3(a,b,c)        CAT_2(CAT_2(a,b),c)
#define CAT_4(a,b,c,d)      CAT_2(CAT_2(a,b),CAT_2(c,d))
#define CAT_5(a,b,c,d,e)    CAT_2(CAT_3(a,b,c),CAT_2(d,e))
#define Low     0
#define High    1

// *****************************************************************************
// *****************************************************************************
//                     Vendor IDs
// *****************************************************************************
// *****************************************************************************
#define     vendUnknown         0xFFFF
#define     vendUnassigned      0x0000
#define     vendDigilent        0x0001
#define     vendMicrochip       0x0002
#define     vendFubarino        0x0003
#define     vendSchmalzHausLLC  0x0004
#define     vendOlimex          0x0005
#define	    vendElement14       0x0006
#define     vendPontech         0x0007
#define     vend4DSystems       0x0008
#define     vendMajenko         0x0009
#define     vendOpenBCI         0x000A
#define     vendMikroE          0x000B
#define     vendBoxtec          0x000C
#define     vendExperimental    0x8000

#define     prodUnassigned      0xFFFF

// Bootloader Capability bits
// The first 4 bits define what type of STK500 interface is used
// The next 4 bits define what LEDs are used
// The next 8 bits define how the bootloader is to be put in programming/listen mode
// The next 8 bits are how flash is erased instructed by the linker
// The next 4 bits are this and that capabilities instructed by the linker
// The last 4 bits are this and that capabilities
#define blCapUARTInterface                              0x00000001ul        // Avrdude talks over a UART
#define blCapUSBInterface                               0x00000002ul        // Avrdude talks over the USB for serial
#define blCapBootLED                                    0x00000010ul        // A boot LED is driven
#define blCapDownloadLED                                0x00000020ul        // A download LED is driven
#define blCapAutoResetListening                         0x00000100ul        // There is a short listening delay after reset for avrdude to upload a sketch before automatically loading the in flash sketch              
#define blCapProgramButton                              0x00000200ul        // A program button is suppored  
#define blCapVirtualProgramButton                       0x00000400ul        // A virtual program button is suppored

#define blCapUSBSerialNumber                            0x00001000ul        // Generate a unique serial number from the USERID

#define blCapLkInstrFullFlashEraseLess4KEEProm          0x00010000ul        // The original bootloader method of erasing all of program flash except the last 4K reserved for eeprom
#define blCapLkInstrJustInTimeFlashErase                0x00020000ul        // Only flash pages written too needed by the sketch is erased
#define blCapLkInstrFlashErase                          0x00040000ul        // The linker defines the flash range to erase
#define blCapLkInstrFullFlashErase                      0x00080000ul        // All of flash is erased
#define blVBusPowerSensePin                             0x00100000ul        // Only listen if the VPwr* pin is HIGH. Includes delay for power rise
#define blCapLkInstrExecutionJumpAddress                0x01000000ul        // the bootloader will jump to the execution jump address immediately after programming
#define blCapLkInstrExecutionJumpToFirstInFlash         0x02000000ul        // the bootloader will jump to the first sketch loaded in flash ignoring the execution jump address immediately after programming
#define blCapSupportsRamHeaderAndPersistentData         0x10000000ul        // This checks and clears the Ram Header and adds RAM header data like the RCON value
#define blCapSplitFlashBootloader                       0x20000000ul        // This is a split flash bootloader with some of the bootloader in program flash
#define blCapSmartStart                                 0x40000000ul        // To indicate that the bootloader has implemented a smart start sequence to prevent execution of the sketch until all start sequences have stabalized.
#define blCapNotProvided                                0x80000000ul        // If this is set, then all capability bits have no meaning. This will be set if flash is in its erased state and the bootloader did not set any bits.

#define CAPCOMMON (blCapLkInstrFullFlashEraseLess4KEEProm | blCapLkInstrJustInTimeFlashErase | blCapLkInstrFlashErase | blCapLkInstrFullFlashErase | blCapLkInstrExecutionJumpAddress | blCapLkInstrExecutionJumpToFirstInFlash | blCapSupportsRamHeaderAndPersistentData)

#if !defined(__PIC32MX__) && !defined(__PIC32MZ__)
    #error "This project was designed for PIC32MX family devices. Please select the appropriate project for your target device family."
#endif

// For historical reasons, these must be defined as these specific constants and nothing else
#define FLASH_START             0x9D000000
#define USER_APP_ADDR           0x9D001000
#define DEFAULT_EEPROM_SIZE     4096

#undef _CONFIG_VALID_
#include "configs/4d.h"
#include "configs/digilent.h"
#include "configs/element14.h"
#include "configs/examples.h"
#include "configs/microchip.h"
#include "configs/fubarino.h"
#include "configs/majenko.h"
#include "configs/mikroe.h"
#include "configs/olimex.h"
#include "configs/openbci.h"
#include "configs/pontech.h"
#include "configs/schmalzhaus.h"
#include "configs/boxtec.h"

#ifndef _CONFIG_VALID_
    #error    Board/CPU combination not defined
#endif

// *****************************************************************************
// *****************************************************************************
//                     THINGS BELOW HERE SHOULD NOT NEED TO BE MODIFIED
// *****************************************************************************
// *****************************************************************************
#if !defined(CAPABILITIES)
    #error CAPABILITIES needs to be defined.
#endif

// Check processor specific stuff.
// In particular PPS for MX1 or MX2
#if (                           \
    (__32MX110F016B__)  ||      \
    (__32MX110F016C__)  ||      \
    (__32MX110F016D__)  ||      \
    (__32MX120F032B__)  ||      \
    (__32MX120F032C__)  ||      \
    (__32MX120F032D__)  ||      \
    (__32MX130F064B__)  ||      \
    (__32MX130F064C__)  ||      \
    (__32MX130F064D__)  ||      \
    (__32MX150F128B__)  ||      \
    (__32MX150F128C__)  ||      \
    (__32MX150F128D__)  ||      \
    (__32MX210F016B__)  ||      \
    (__32MX210F016C__)  ||      \
    (__32MX210F016D__)  ||      \
    (__32MX220F032B__)  ||      \
    (__32MX220F032C__)  ||      \
    (__32MX220F032D__)  ||      \
    (__32MX230F064B__)  ||      \
    (__32MX230F064C__)  ||      \
    (__32MX230F064D__)  ||      \
    (__32MX250F128B__)  ||      \
    (__32MX250F128C__)  ||      \
    (__32MX250F128D__)  ||      \
    (__32MX270F256B__)  ||      \
    (__32MX270F256C__)  ||      \
    (__32MX270F256D__)  ||      \
    (__32MX350F256H__)  ||      \
    (__32MX370F512H__)  ||      \
    (__32MZ0256ECE064__) ||     \
    (__32MZ0512ECE064__) ||     \
    (__32MZ1024ECE064__) ||     \
    (__32MZ1024ECG064__) ||     \
    (__32MZ2048ECG064__) ||     \
    (__32MZ0256ECJ064__) ||     \
    (__32MZ0512ECJ064__) ||     \
    (__32MZ1024ECJ064__) ||     \
    (__32MZ1024ECL064__) ||     \
    (__32MZ2048ECL064__) ||     \
    (__32MZ0256ECF064__) ||     \
    (__32MZ0512ECF064__) ||     \
    (__32MZ1024ECF064__) ||     \
    (__32MZ1024ECH064__) ||     \
    (__32MZ2048ECH064__) ||     \
    (__32MZ0256ECK064__) ||     \
    (__32MZ0512ECK064__) ||     \
    (__32MZ1024ECK064__) ||     \
    (__32MZ1024ECM064__) ||     \
    (__32MZ2048ECM064__) ||     \
    (__32MZ0256ECE100__) ||     \
    (__32MZ0512ECE100__) ||     \
    (__32MZ1024ECE100__) ||     \
    (__32MZ1024ECG100__) ||     \
    (__32MZ2048ECG100__) ||     \
    (__32MZ0256ECJ100__) ||     \
    (__32MZ0512ECJ100__) ||     \
    (__32MZ1024ECJ100__) ||     \
    (__32MZ1024ECL100__) ||     \
    (__32MZ2048ECL100__) ||     \
    (__32MZ0256ECF100__) ||     \
    (__32MZ0512ECF100__) ||     \
    (__32MZ1024ECF100__) ||     \
    (__32MZ1024ECH100__) ||     \
    (__32MZ2048ECH100__) ||     \
    (__32MZ0256ECK100__) ||     \
    (__32MZ0512ECK100__) ||     \
    (__32MZ1024ECK100__) ||     \
    (__32MZ1024ECM100__) ||     \
    (__32MZ2048ECM100__) ||     \
    (__32MZ0256ECE124__) ||     \
    (__32MZ0512ECE124__) ||     \
    (__32MZ1024ECE124__) ||     \
    (__32MZ1024ECG124__) ||     \
    (__32MZ2048ECG124__) ||     \
    (__32MZ0256ECJ124__) ||     \
    (__32MZ0512ECJ124__) ||     \
    (__32MZ1024ECJ124__) ||     \
    (__32MZ1024ECL124__) ||     \
    (__32MZ2048ECL124__) ||     \
    (__32MZ0256ECF124__) ||     \
    (__32MZ0512ECF124__) ||     \
    (__32MZ1024ECF124__) ||     \
    (__32MZ1024ECH124__) ||     \
    (__32MZ2048ECH124__) ||     \
    (__32MZ0256ECK124__) ||     \
    (__32MZ0512ECK124__) ||     \
    (__32MZ1024ECK124__) ||     \
    (__32MZ1024ECM124__) ||     \
    (__32MZ2048ECM124__) ||     \
    (__32MZ0256ECE144__) ||     \
    (__32MZ0512ECE144__) ||     \
    (__32MZ1024ECE144__) ||     \
    (__32MZ1024ECG144__) ||     \
    (__32MZ2048ECG144__) ||     \
    (__32MZ0256ECJ144__) ||     \
    (__32MZ0512ECJ144__) ||     \
    (__32MZ1024ECJ144__) ||     \
    (__32MZ1024ECL144__) ||     \
    (__32MZ2048ECL144__) ||     \
    (__32MZ0256ECF144__) ||     \
    (__32MZ0512ECF144__) ||     \
    (__32MZ1024ECF144__) ||     \
    (__32MZ1024ECH144__) ||     \
    (__32MZ2048ECH144__) ||     \
    (__32MZ0256ECK144__) ||     \
    (__32MZ0512ECK144__) ||     \
    (__32MZ1024ECK144__) ||     \
    (__32MZ1024ECM144__) ||     \
    (__32MZ2048ECM144__) ||     \
    (__32MZ1024EFG100__) ||     \
    (__32MZ1024EFG124__) ||     \
    (__32MZ1024EFG144__) ||     \
    (__32MZ1024EFH064__) ||     \
    (__32MZ1024EFH100__) ||     \
    (__32MZ1024EFH124__) ||     \
    (__32MZ1024EFH144__) ||     \
    (__32MZ2048EFG064__) ||     \
    (__32MZ2048EFG100__) ||     \
    (__32MZ2048EFG124__) ||     \
    (__32MZ2048EFG144__) ||     \
    (__32MZ2048EFH064__) ||     \
    (__32MZ2048EFH100__) ||     \
    (__32MZ2048EFH124__) ||     \
    (__32MZ2048EFH144__) ||     \
    (__32MZ1024EFM064__) ||     \
    (__32MZ2048EFM064__) ||     \
    (__32MZ1024EFM100__) ||     \
    (__32MZ2048EFM100__) ||     \
    (__32MZ1024EFM124__) ||     \
    (__32MZ2048EFM124__) ||     \
    (__32MZ1024EFM144__) ||     \
    (__32MZ2048EFM144__)        )

    #define PPS_IN_USE 1            // indicate that this is a PPS type processor

    #if ((CAPABILITIES & blCapUARTInterface) == blCapUARTInterface)

        // must define what pins the UART goes on
        #if !defined(UARTMapRX)
            #error UARTMapRX needs to be defined specifying how UART RX PPS pins are to be selected.
        #elif !defined(UARTMapTX)
            #error UARTMapTX needs to be defined specifying how UART TX PPS pins are to be selected.
        #endif


        // say to use PPS mapping
        #define USE_PPS_UART 1

    #endif  // UART

    #if defined(LoadFlashWaitStates)
        #error LoadFlashWaitStates is not supported and unneeded for the MX1/2 or MZ parts
    #endif

   // define nothing for the flash wait states
    #define LoadFlashWaitStates()                           // not supported on MX1/2

#endif  // MX1 or MX2

// Assign the bootloader UART
#if( ((CAPABILITIES & blCapUARTInterface) == blCapUARTInterface) )
    #if(BOOTLOADER_UART == 1)
        #define UMODE       U1MODE
        #define USTA        U1STA
        #define UBRG        U1BRG
        #define UMODEbits   U1MODEbits
        #define USTAbits    U1STAbits
        #define UTXREG      U1TXREG
        #define URXREG      U1RXREG
    #elif(BOOTLOADER_UART == 2)
        #define UMODE       U2MODE
        #define USTA        U2STA
        #define UBRG        U2BRG
        #define UMODEbits   U2MODEbits
        #define USTAbits    U2STAbits
        #define UTXREG      U2TXREG
        #define URXREG      U2RXREG
    #elif(BOOTLOADER_UART == 3)
        #define UMODE       U3MODE
        #define USTA        U3STA
        #define UBRG        U3BRG
        #define UMODEbits   U3MODEbits
        #define USTAbits    U3STAbits
        #define UTXREG      U3TXREG
        #define URXREG      U3RXREG
    #elif(BOOTLOADER_UART == 4)
        #define UMODE       U4MODE
        #define USTA        U4STA
        #define UBRG        U4BRG
        #define UMODEbits   U4MODEbits
        #define USTAbits    U4STAbits
        #define UTXREG      U4TXREG
        #define URXREG      U4RXREG
    #elif(BOOTLOADER_UART == 5)
        #define UMODE       U5MODE
        #define USTA        U5STA
        #define UBRG        U5BRG
        #define UMODEbits   U5MODEbits
        #define USTAbits    U5STAbits
        #define UTXREG      U5TXREG
        #define URXREG      U5RXREG
    #else
        #error a UART 1 thru 5 must be specified.
    #endif  // UART number
#elif ((CAPABILITIES & blCapUSBInterface) == blCapUSBInterface)
    // do nothing
#else  
    #error blCapUARTInterface or blCapUSBInterface must be assigned in CAPABILITIES
#endif

// if no BOOT/HEARTBEAT LED
#if ((CAPABILITIES & blCapBootLED) == 0)
    #define EnableBootLED()
    #define DisableBootLED()
    #define BootLED_Toggle()
    #define BootLED_On()
    #define BootLED_Off()
#else
    #define EnableBootLED()             (CAT_3(TRIS,BLedLat,CLR) = (1 << BLedBit))
    #define DisableBootLED()            (CAT_3(TRIS,BLedLat,SET) = (1 << BLedBit))
    #define BootLED_Toggle()            (CAT_3(LAT,BLedLat,INV) = (1 << BLedBit))

    #if(LedOn == High)
        #define BootLED_On()            (CAT_3(LAT,BLedLat,SET) = (1 << BLedBit))
        #define BootLED_Off()           (CAT_3(LAT,BLedLat,CLR) = (1 << BLedBit))
    #elif(LedOn == Low)
        #define BootLED_On()            (CAT_3(LAT,BLedLat,CLR) = (1 << BLedBit))
        #define BootLED_Off()           (CAT_3(LAT,BLedLat,SET) = (1 << BLedBit))
    #else
        #error Must specify if LedOn is High or Low
    #endif
#endif

// if no DOWNLOAD LED
#if ((CAPABILITIES & blCapDownloadLED) == 0)
    #define EnableDownLoadLED()
    #define DisableDownLoadLED()
    #define DownloadLED_Toggle()
    #define DownloadLED_On()
    #define DownloadLED_Off()
#else
    #define EnableDownLoadLED()         (CAT_3(TRIS,DLedLat,CLR) = (1 << DLedBit))
    #define DisableDownLoadLED()        (CAT_3(TRIS,DLedLat,SET) = (1 << DLedBit))
    #define DownloadLED_Toggle()        (CAT_3(LAT,DLedLat,INV) = (1 << DLedBit))

    #if(LedOn == High)
        #define DownloadLED_On()        (CAT_3(LAT,DLedLat,SET) = (1 << DLedBit))
        #define DownloadLED_Off()       (CAT_3(LAT,DLedLat,CLR) = (1 << DLedBit))
    #elif(LedOn == Low)
        #define DownloadLED_On()        (CAT_3(LAT,DLedLat,CLR) = (1 << DLedBit))
        #define DownloadLED_Off()       (CAT_3(LAT,DLedLat,SET) = (1 << DLedBit))
   #else
        #error Must specify if LedOn is High or Low
    #endif
#endif

// if no program button
#if ((CAPABILITIES & blCapProgramButton) == 0)
    #define fLoadFromAVRDudeViaProgramButton            (false)
#else
    #define fLoadFromAVRDudeViaProgramButton            (CAT_3(PORT,PBntPort,bits).CAT_3(R,PBntPort,PBntBit) == BntOn)
    #ifdef PBntPu
        #define enablePullup                            (CAT_3(CNPU,PBntPort,SET) = 1<<PBntBit)
        #define enablePulldown                          (CAT_3(CNPD,PBntPort,SET) = 1<<PBntBit)
    #endif
#endif

// if no virtual program button
#if ((CAPABILITIES & blCapVirtualProgramButton) == 0)
    #define fLoadFromAVRDudeViaVirtualProgramButton     (false) 
    #define ClearVirtualProgramButton()
#else
    #define fLoadFromAVRDudeViaVirtualProgramButton     (CAT_3(LAT,VPBntLat,bits).CAT_3(LAT,VPBntLat,VPBntBit) == 1)
    #define ClearVirtualProgramButton()                 (CAT_3(LAT,VPBntLat,CLR) = (1 << VPBntBit))
#endif

// if no auto reset listen time
#if ((CAPABILITIES & blCapAutoResetListening) == 0)
        #define LISTEN_BEFORE_LOAD                      0 
#endif

#ifndef JTAG
        #define JTAG 0
#endif

// error checking for #defines.
#if !defined(_CPU_NAME_)
    #error _CPU_NAME_ needs to be defined.
#elif !defined(F_CPU)
    #error F_CPU needs to be defined specifying the processor master clock frequency.
#elif !defined(VEND)
    #error VEND needs to be defined specifying the vendor ID.
#elif !defined(PROD)
    #error PROD needs to be defined specifying the product ID.
#elif !defined(F_PBUS)
    #error _F_PBUS needs to be defined specifying the peripheral buss frequency.
#elif !defined(FLASH_START)
    #error FLASH_START needs to be defined specifying the flash start address.
#elif !defined(FLASH_BYTES)
    #error FLASH_BYTES needs to be defined specifying the number of bytes in flash, less that reserved for EEPROM.
#elif !defined(FLASH_PAGE_SIZE)
    #error FLASH_PAGE_SIZE needs to be defined specifying the number of bytes in a flash page.
#elif !defined(USER_APP_ADDR)
    #error USER_APP_ADDR needs to be defined specifying where the user applicaiton is loaded in flash.
#elif !defined(EnableBootLED)
    #error EnableBootLED needs to be defined specifying how to enable the Boot LED.
#elif !defined(DisableBootLED)
    #error DisableBootLED needs to be defined specifying how to disable the Boot LED.
#elif !defined(BootLED_Toggle)
    #error BootLED_Toggle needs to be defined specifying how to toggle the Boot LED.
#elif !defined(BootLED_On)
    #error BootLED_On needs to be defined specifying how to turn on the Boot LED.
#elif !defined(BootLED_Off)
    #error BootLED_Off needs to be defined specifying how to turn off the Boot LED.
#elif !defined(EnableDownLoadLED)
    #error EnableDownLoadLED needs to be defined specifying how to enable the Download LED.
#elif !defined(DisableDownLoadLED)
    #error DisableDownLoadLED needs to be defined specifying how to disable the Download LED.
#elif !defined(DownloadLED_Toggle)
    #error DownloadLED_Toggle needs to be defined specifying how to toggle the Download LED.
#elif !defined(DownloadLED_On)
    #error DownloadLED_On needs to be defined specifying how to turn on the Download LED.
#elif !defined(DownloadLED_Off)
    #error DownloadLED_Off needs to be defined specifying how to turn off the Download LED.
#elif !defined(fLoadFromAVRDudeViaProgramButton)
    #error fLoadFromAVRDudeViaProgramButton needs to be defined specifying if the program button is active.
#elif !defined(fLoadFromAVRDudeViaVirtualProgramButton)
    #error fLoadFromAVRDudeViaVirtualProgramButton needs to be defined specifying if the virtual program latch is active.
#elif !defined(ClearVirtualProgramButton)
    #error ClearVirtualProgramButton needs to be defined specifying how to clear the virtual program latch.
#elif !defined(LoadFlashWaitStates)
    #error LoadFlashWaitStates needs to be defined specifying the number of wait states to be inserted for flash operation.
#elif !defined(LISTEN_BEFORE_LOAD)
    #error LISTEN_BEFORE_LOAD needs to be defined specifying how long in milliseconds to listen for an upload from avrdude before jumping to the application in flash.
#elif ((CAPABILITIES & blCapSmartStart) == blCapSmartStart)
    #if !defined(USE_POR_SEQUENCE)
        #error USE_POR_SEQUENCE needs to be defined specifying if a power on reset sequence is needed to prevent unwanted false starts
    #endif  // POR Sequence
#elif ((CAPABILITIES & blCapUARTInterface) == blCapUARTInterface)
    #if !defined(BAUDRATE)
        #error BAUDRATE needs to be defined specifying the baud rate for the UART to run at.
    #endif // BAUD RATE
#endif

// core timer ticks per second is always 1/2 the CPU ticks, so devide by 2 to get ticks per second
// divide by another 1000 (or 2* 1000) to get ticks per millisecond
// we add the 1000 to round up or down on a faction of a millisecond
#define CORE_TIMER_TICKS_PER_MILLISECOND    ((F_CPU + 1000) / 2000)

/***    static inline void __attribute__((always_inline)) InitLEDsAndButtons(void)
**
**    Synopsis:   
**      This initializes board specific LEDs and Buttons.
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
**      This is inlined as only one copy will exist in the code
**
*/
static inline void __attribute__((always_inline)) InitLEDsAndButtons(void)
{
    // volatile int i;
    // We assume the processor is unlocked, so let's just assert that here
    // While the processor comes up in the unlocked state after reset it is 
    // possible that the rest code was jumped to after someone locked the system
    // and we need to re-assert the unlock.
    SYSKEY = 0;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
 
    #ifdef PPS_IN_USE
        CFGCONbits.IOLOCK = 0;            // unlock PPS; same reasoning as explicitly unlocking the processor
    #endif

    #ifdef PBntPu
        if (PBntPu == High) {
            enablePullup;
        } else {
            enablePulldown;
        }
    #endif

    // define all analog pins as digital
    #ifdef _ANSELA_w_POSITION
        ANSELA = 0;
    #endif
     
    #ifdef _ANSELB_w_POSITION
        ANSELB = 0;
    #endif
     
    #ifdef _ANSELC_w_POSITION
        ANSELC = 0;
    #endif
     
    #ifdef _ANSELD_w_POSITION
        ANSELD = 0;
    #endif
     
    #ifdef _ANSELE_w_POSITION
        ANSELE = 0;
    #endif
     
    #ifdef _ANSELF_w_POSITION
        ANSELF = 0;
    #endif
     
    #ifdef _ANSELG_w_POSITION
        ANSELG = 0;
    #endif
     
    #ifdef _ANSELH_w_POSITION
        ANSELH = 0;
    #endif

    #ifdef _AD1PCFG_w_POSITION
        AD1PCFG = 0xffff;
    #endif

    #if(JTAG == 1)
        #ifdef __PIC32MZ__
            CFGCONbits.JTAGEN = 1;
//            i = 3;
        #else
            DDPCONbits.JTAGEN = 1;
        #endif

    #else
        #ifdef __PIC32MZ__
            CFGCONbits.JTAGEN = 0;
        #else
            DDPCONbits.JTAGEN = 0;
        #endif
    #endif

    // wait states flash/cache based on the system clock speed.
    // This assumes the clock is running at a 20Mhz multiple and is greater than 20Mhz.
    LoadFlashWaitStates();

    EnableBootLED();
    EnableDownLoadLED();

    // no need to enable the program button as it is tri-stated after reset

    // Intialize the download LED off
    DownloadLED_Off();
}

/***    static inline void __attribute__((always_inline)) UninitLEDsAndButtons(void)
**
**    Synopsis:   
**      This Uninitializes board specific LEDs and Buttons
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
**      This is inlined as only one copy will exist in the code
**
*/
static inline void __attribute__((always_inline)) UninitLEDsAndButtons(void)
{
    // turn the LEDs OFF before tri-stating
    BootLED_Off();
    DownloadLED_Off();

    // tri-state the LEDs
    DisableBootLED();
    DisableDownLoadLED();

    // Buttons are already input, already tri-stated
}

// USB SPECIFIC CODE
#if ((CAPABILITIES & blCapUSBInterface) == blCapUSBInterface)

    #include "cdcacm.h"
    #include "usb.h"
    
    #define stk500v2_isr                usb_isr
    #define stk500v2_print              usb_print
    #define UninitStk500v2Interface     usb_uninitialize

    static inline void __attribute__((always_inline)) InitStk500v2Interface(void)
    {
       // initialize usb
        usb_initialize();
        cdcacm_register(null_reset_cbfn);
    }
    
    // this function sends bytes to the CDC/ACM port
    static inline void __attribute__((always_inline)) usb_print(const byte *buffer, int length)
    {
        if (cdcacm_attached && cdcacm_active) {
            cdcacm_print(buffer, length);
        }
    }

    // this function receives bytes from the CDC/ACM port
    // N.B. if this routine returns false, cdcacm will drop the ball and we'll
    // call cdcacm_command_ack() later to pick it up again.
    static inline bool __attribute__((always_inline)) avrbl_receive(const byte *buffer, int length)
    {
        int i;
    
        for (i = 0; i < length; i++) {
            avrbl_state_machine(buffer[i]);
        }
    
        return true;
    }

// UART SPECIFIC CODE
#else  // using a UART

    #include "serial.h"
    
    #define stk500v2_isr                serial_isr
    #define stk500v2_print              serial_print
    
    static inline void __attribute__((always_inline)) InitStk500v2Interface(void)
    {
        // if the UART is mapped via Peripheral Pin Selection
        #if defined(USE_PPS_UART)
    
            // The unlock code is documented as required yet does not seem to be needed.
            //        SYSKEY = 0;
            //        SYSKEY = 0xAA996655;
            //        SYSKEY = 0x556699AA;
            //        CFGCONbits.IOLOCK = 0;            // unlock PPS
            // End of seemingly unneeded unlock code
        
            // modify PPS
            UARTMapRX();
            UARTMapTX();
        
            // The lock code is documented as required yet does not seem to be needed.
            //        CFGCONbits.IOLOCK = 1;            // lock PPS
            //        SYSKEY = 0x33333333;
            // End of seemingly unneeded lock code
    
        #endif
    
    	//*	Init UART
    	//*	set baudrate and enable USART receiver and transmiter without interrupts
    	UMODE	=	(UART_ENABLE);
    	USTA	=	(UART_RX_ENABLE | UART_TX_ENABLE);
    	UBRG	=	((F_PBUS / (16 * BAUDRATE))-1);	// calculate actual BAUD generate value.
    
    	//*	ok, the serial port is initialized, clear any data that may be there
    	while (USTAbits.URXDA)
    	{
            (void)URXREG;
    	}
    }

    static inline void __attribute__((always_inline)) UninitStk500v2Interface(void)
    {
        // make sure we transmitted our last byte before closeing
        while (!USTAbits.TRMT);

        // disable the UART
        UMODE = 0;
    }
#endif  // End of _USE_USB_FOR_BOOTLOADER_ and  UART specific code


// *****************************************************************************
// *****************************************************************************
//           These are power up sequences to prevent multiple restarts
// *****************************************************************************
// *****************************************************************************

/***    static inline void __attribute__((always_inline)) PowerOnResetDelay(void)
**
**    Synopsis:   
**      Some boards have a MPLAB debug circuit that takes several seconds to initialize
**      and it pulls reset several times in the process. This is a board specific sequence
**      to determine when the last reset was pulled and then can jump to normal processeing
**
**
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
**typedef union {
**  struct {
**    unsigned POR:1;
**    unsigned BOR:1;
**    unsigned IDLE:1;
**    unsigned SLEEP:1;
**    unsigned WDTO:1;
**    unsigned :1;
**    unsigned SWR:1;
**    unsigned EXTR:1;
**    unsigned VREGS:1;
**    unsigned CMR:1;
**  };
**      This is inlined as only one copy will exist in the code
**
**      state sequence; we use WDTO as a sometimes persistent state bit.
**      1. EXTR,BOR,POR      - 0x83; Action: Set WDTO and Clear BOR
**      2. EXTR,WDTO,POR     - 0x91; Action: Set BOR
**      3. EXTR,BOR,POR      - 0x83; Action: Set WDTO and Clear BOR, but... WDTO will not survive
**      4. EXTR,POR          - 0x81; Action: Exit
**
**      If just an EXTR reset (0x80) comes in, then Exit, this is not a power up situation.
**
**      If this ever gets fixed it should come up with BOR, POR only, so make that exit as well.
**
*/
#if ((CAPABILITIES & blCapSmartStart) == 0)
    #define WaitForFinalReset()
#elif (USE_POR_SEQUENCE == 1)         // PKOB reset skip for the MX4 & MX4 Cerebot boards
    static inline void __attribute__((always_inline)) WaitForFinalReset(void)
    {   
        uint16 rCon = RCON & 0xC3;
        bool fClrRCONAfter1Second = false;
        uint32 tStart = _CP0_GET_COUNT();
        uint32 tCur = tStart;
        uint32 tExit = tStart;
        uint32 tBlink = tStart;

        switch(rCon)
        {
            // external reset only, we don't wait, we are done; EXTR only
            case 0x80:      // simple reset
                tExit = 0;
                break;

            // unknown state; this shouldn't happen
            default:
            // fall through, lets just assume state 1
            // this will give us the longest reset path of a min. of 9s (7s + 2s at 0xC1)
         
            // state 2, EXTR & BOR & POR 
                // sometimes state 1 is missed when there is a glitch on the reset line that is so
                // fast that the code at state 1 does not run, or if reset comes up so slow that EXTR 
                // is set such as when JP11 enables the MPIDE RC auto-reset circuit.
             
            // state 4, EXTR & BOR & POR; with DBG connected to MPLAB prepare for the 2nd weird reset pair
                // when we go to state 5, EXTR & POR will be set; SWR will get cleared by the weird reset pair

            case 0x83:      // state 2 & 4
                RCON = 0x41;                                        // just set SWR, POR
                // fall thru as in either of these states if I don't get another reset
                // with in a second, then on the next state I want to exit

            // state 1, BOR and POR set, 
                // case 1, simple boot, we will wait 7s
                // case 2, only MPIDE is attached we will wait 6s and MPIDE will reset
                // case 3, DBG is attached, after 20ms a reset will come in
            case 0x3:       // state 1  

                // wait 1 second. We do this to make sure we are not at state 1 waiting
                // for state 2 in an MPLAB connected condition.
                // plus we need to keep either BOR or POR set in case we have those
                // resets every 650ms.
                fClrRCONAfter1Second = true;
                
                // If a reset has not occured after 1 second, then we know the next
                // state will be an exit, so clear RCON so the next state will
                // come up as either just EXTR, or EXTR and POR (state 5)
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 7000);  // 7 second delay
                break;

            // state 3; EXTR & SWR & POR
            // DBG USB + MPLAB connected, we are at about .5s, just after .4s after the long reset
            // Then next state 4 is our first weird double reset
            case 0xC1:      // state 3
                RCON = 0x3;                                         // set BOR & POR
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 2000);  // 2 second delay
                break;

            // state 5, with DBG connected to MPLAB; EXTR & POR;
            // we wait a second because if we have MPIDE, DBG, and JP11, we get 650ms spikes
            // and we want to wait for the next spike to reset us.
            case 0x81:      // state 5
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 1000);  // 1 second delay
                break;
        }
  
        // All LEDs are off, so toggle one out of phase with the other
        BootLED_On();

        // wait for a reset or completion           
        do
        {
            tCur = _CP0_GET_COUNT(); 

            // if we wait long enough, then we know we are in a state where the next
            // state we should exit, but setting RCON to 0, the next state will be just EXTR
            // and that will cause us to immediately exit. 
            // except for the condition where POR gets set and gives us EXTR & POR, state 5.
            if(fClrRCONAfter1Second && ((tCur - tStart) >= (CORE_TIMER_TICKS_PER_MILLISECOND * 1000)))
            {
                RCON = 0x0;
                fClrRCONAfter1Second = false;
            }

            // toggle our leds 8 times a second (on to on, so toggle is 16 times a second).
            if((tCur - tBlink) >= (CORE_TIMER_TICKS_PER_MILLISECOND * 62))
            {
                BootLED_Toggle();
                DownloadLED_Toggle();
                tBlink = tCur;
             }
        } while((tCur- tStart) <= tExit); 

        // when we are done, clear all bits.
        RCON = 0x0;
  }
#elif (USE_POR_SEQUENCE == 100)         // test debug for the MX7cK
    static inline void __attribute__((always_inline)) WaitForFinalReset(void)
    {   
        uint32 tStart = _CP0_GET_COUNT();
        uint32 tCur;

        // Connector JA pins 1,2,3
        TRISBCLR = (1 << 2);      
        TRISBCLR = (1 << 3);      
        TRISBCLR = (1 << 4);      

        LATBbits.LATB2 = RCONbits.POR;
        LATBbits.LATB3 = RCONbits.BOR;
        LATBbits.LATB4 = RCONbits.EXTR;

        // reset bits fro next pass
        RCON = 0;

        while(1);   // stop
 }
#elif (USE_POR_SEQUENCE == 101)         // MX7cK Logic Analyzer verification sequence
    static inline void __attribute__((always_inline)) WaitForFinalReset(void)
    {   
        uint16 rCon = RCON & 0xC3;
        bool fClrRCONAfter1Second = false;
        uint32 tStart = _CP0_GET_COUNT();
        uint32 tCur = tStart;
        uint32 tExit = tStart;

        // connector JB, pin 1,2
        // NOT ready
        TRISECLR = (1 << 0);
        TRISECLR = (2 << 0);
        LATEbits.LATE0 = 1;         // app running
        LATEbits.LATE1 = 0;         // ready

        // set up LEDs for output
        TRISGCLR = (1 << 12);      
        TRISGCLR = (1 << 13);      
        TRISGCLR = (1 << 14);      
        TRISGCLR = (1 << 15);   

        // show the bits on the LEDs
        LATGbits.LATG12 = RCONbits.POR;
        LATGbits.LATG13 = RCONbits.BOR;
        LATGbits.LATG15 = RCONbits.SWR;;
        LATGbits.LATG14 = RCONbits.EXTR;

        // Connector JA pins 1,2,3,4
        TRISBCLR = (1 << 2);      
        TRISBCLR = (1 << 3);      
        TRISBCLR = (1 << 4);      
        TRISBCLR = (1 << 6);      

        LATBbits.LATB2 = RCONbits.POR;
        LATBbits.LATB3 = RCONbits.BOR;
        LATBbits.LATB4 = RCONbits.SWR;
        LATBbits.LATB6 = RCONbits.EXTR;

        switch(rCon)
        {
            // external reset only, we don't wait, we are done; EXTR only
            case 0x80:      // simple reset
                tExit = 0;
                break;

            // unknown state; this shouldn't happen
            default:
            // fall through, lets just assume state 1
            // this will give us the longest reset path of a min. of 9s (7s + 2s at 0xC1)
         
            // state 2, EXTR & BOR & POR 
                // sometimes state 1 is missed when there is a glitch on the reset line that is so
                // fast that the code at state 1 does not run, or if reset comes up so slow that EXTR 
                // is set such as when JP11 enables the MPIDE RC auto-reset circuit.
             
            // state 4, EXTR & BOR & POR; with DBG connected to MPLAB prepare for the 2nd weird reset pair
                // when we go to state 5, EXTR & POR will be set; SWR will get cleared by the weird reset pair

            case 0x83:      // state 2 & 4
                RCON = 0x41;                                        // just set SWR, POR
                // fall thru as in either of these states if I don't get another reset
                // with in a second, then on the next state I want to exit

            // state 1, BOR and POR set, 
                // case 1, simple boot, we will wait 7s
                // case 2, only MPIDE is attached we will wait 6s and MPIDE will reset
                // case 3, DBG is attached, after 20ms a reset will come in
            case 0x3:       // state 1  

                // wait 1 second. We do this to make sure we are not at state 1 waiting
                // for state 2 in an MPLAB connected condition.
                // plus we need to keep either BOR or POR set in case we have those
                // resets every 650ms.
                fClrRCONAfter1Second = true;
                
                // If a reset has not occured after 1 second, then we know the next
                // state will be an exit, so clear RCON so the next state will
                // come up as either just EXTR, or EXTR and POR (state 5)
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 7000);  // 7 second delay
                break;

            // state 3; EXTR & SWR & POR
            // DBG USB + MPLAB connected, we are at about .5s, just after .4s after the long reset
            // Then next state 4 is our first weird double reset
            case 0xC1:      // state 3
                RCON = 0x3;                                         // set BOR & POR
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 2000);  // 2 second delay
                break;

            // state 5, with DBG connected to MPLAB; EXTR & POR;
            // we wait a second because if we have MPIDE, DBG, and JP11, we get 650ms spikes
            // and we want to wait for the next spike to reset us.
            case 0x81:      // state 5
                tExit = (CORE_TIMER_TICKS_PER_MILLISECOND * 1000);  // 1 second delay
                break;
        }
  
        // wait for a reset or completion           
        do
        {
            tCur = _CP0_GET_COUNT(); 

            // if we wait long enough, then we know we are in a state where the next
            // state we should exit, but setting RCON to 0, the next state will be just EXTR
            // and that will cause us to immediately exit. 
            // except for the condition where POR gets set and gives us EXTR & POR, state 5.
            if(fClrRCONAfter1Second && ((tCur - tStart) >= (CORE_TIMER_TICKS_PER_MILLISECOND * 1000)))
            {
                RCON = 0x0;
                fClrRCONAfter1Second = false;
            }
        } while((tCur- tStart) <= tExit);   // 5 second wait
                   
        // when we are done, clear all bits.
        RCON = 0x0;

        // display our registers on LEDs
        LATGbits.LATG12 = RCONbits.POR;
        LATGbits.LATG13 = RCONbits.BOR;
        LATGbits.LATG15 = RCONbits.SWR;;
        LATGbits.LATG14 = RCONbits.EXTR;

        // display registers to logic analyzer
        LATBbits.LATB2 = RCONbits.POR;
        LATBbits.LATB3 = RCONbits.BOR;
        LATBbits.LATB4 = RCONbits.SWR;
        LATBbits.LATB6 = RCONbits.EXTR;

        // say we are ready
        LATEbits.LATE1 = 1;

        while(1);   // stop
 }
#else
        #error USE_POR_SEQUENCE needs to be defined specifying which power on reset sequence to use to avoid the muliple resets on board power up.
#endif

