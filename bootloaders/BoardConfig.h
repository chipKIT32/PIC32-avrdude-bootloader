/************************************************************************/
/*                                                                      */
/*    BoardConfig.h   This configures board specific features           */
/*                  for the stk500v2 avrdude/MPIDE PIC32                */
/*                    compilient bootloader                             */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2012, Digilent Inc.                                     */
/************************************************************************/
/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    2/23/2011(KeithV): Created                                        */
/*    6/17/2012(KeithV): Added Just In Time Flash Erase                 */
/*    6/17/2012(KeithV): Added header information                       */
/*    6/25/2012(KeithV): Added Vendor ID and Product IDs                */
/*    1/15/2013(BrianS): Added PPS unlock for MX1/MX2 devices           */
/*                                                                      */
/************************************************************************/


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

// *****************************************************************************
// *****************************************************************************
//                    Digilent Product IDs
// *****************************************************************************
// *****************************************************************************
#define     prodUnknown         0xFFFF
#define     prodUnassigned      0x0000

#define     prodChipKITUno32    0x0101
#define     prodChipKITMax32    0x0102
#define     prodChipKITuC32     0x0103
#define     prodCerebot32MX4    0x0201
#define     prodCerebot32MX7    0x0202
#define     prodCerebotMX3cK128 0x0203
#define     prodCerebotMX4cK    0x0204
#define     prodCerebotMX7cK    0x0205
#define     prodCerebotMX3cK512 0x0206

// *****************************************************************************
// *****************************************************************************
//                    Fubarino Product IDs
// *****************************************************************************
// *****************************************************************************
#define     prodFubarinoSD      0x0001
#define     prodFubarinoMini    0x0002
#define     prodFubarinoSD_512K 0x0003
#define     prodFubarinoMini50MHz 0x0004

// *****************************************************************************
// *****************************************************************************
//                    Schmalz Haus Product IDs
// *****************************************************************************
// *****************************************************************************
#define     prodEBBv3      		0x0001
#define     prodUBW32MX460 		0x0002
#define     prodUBW32MX795 		0x0003

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
#define blCapLkInstrFullFlashEraseLess4KEEProm          0x00010000ul        // The original bootloader method of erasing all of program flash except the last 4K reserved for eeprom
#define blCapLkInstrJustInTimeFlashErase                0x00020000ul        // Only flash pages written too needed by the sketch is erased
#define blCapLkInstrFlashErase                          0x00040000ul        // The linker defines the flash range to erase
#define blCapLkInstrFullFlashErase                      0x00080000ul        // All of flash is erased
#define blCapLkInstrExecutionJumpAddress                0x01000000ul        // the bootloader will jump to the execution jump address immediately after programming
#define blCapLkInstrExecutionJumpToFirstInFlash         0x02000000ul        // the bootloader will jump to the first sketch loaded in flash ignoring the execution jump address immediately after programming
#define blCapSupportsRamHeaderAndPersistentData         0x10000000ul        // This checks and clears the Ram Header and adds RAM header data like the RCON value
#define blCapSplitFlashBootloader                       0x20000000ul        // This is a split flash bootloader with some of the bootloader in program flash
#define blCapSmartStart                                 0x40000000ul        // To indicate that the bootloader has implemented a smart start sequence to prevent execution of the sketch until all start sequences have stabalized.
#define blCapNotProvided                                0x80000000ul        // If this is set, then all capability bits have no meaning. This will be set if flash is in its erased state and the bootloader did not set any bits.

#define CAPCOMMON (blCapBootLED | blCapLkInstrFullFlashEraseLess4KEEProm | blCapLkInstrJustInTimeFlashErase | blCapLkInstrFlashErase | blCapLkInstrFullFlashErase | blCapLkInstrExecutionJumpAddress | blCapLkInstrExecutionJumpToFirstInFlash | blCapSupportsRamHeaderAndPersistentData)

#if !defined(__PIC32MX__)
    #error "This project was designed for PIC32MX family devices. Please select the appropriate project for your target device family."
#endif

// For historical reasons, these must be defined as these specific constants and nothing else
#define FLASH_START             0x9D000000
#define USER_APP_ADDR           0x9D001000
#define DEFAULT_EEPROM_SIZE     4096

//************************************************************************
#if defined(_BOARD_EXAMPLE_MX1_)               

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator Selection
    #pragma config POSCMOD  = XT                            // Primary Oscillator
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_2                         // PLL output divider
    #pragma config FPBDIV   = DIV_1                         // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                           // Secondary Oscillator Enable

    //*    Clock control settings
    #pragma config IESO     = ON                            // Internal/External Switch-over
    #pragma config FCKSM    = CSDCMD                        // Clock Switching & Fail Safe Clock Monitor
    #pragma config OSCIOFNC = OFF                           // CLKO Enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                           // Watchdog Timer
    #pragma config WDTPS    = PS1024                        // Watchdog Timer Postscale
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                           // JTAG port disabled

    //*    Code Protection settings
    #pragma config CP       = OFF                           // Code Protect
    #pragma config BWP      = OFF                           // Boot Flash Write Protect
    #pragma config PWP      = OFF                           // Program Flash Write Protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           // Allow multiple reconfigurations
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot/Heartbeat LED
    #define EnableBootLED()         (TRISACLR = (1 << 7))
    #define DisableBootLED()        (TRISASET = (1 << 7))
    #define BootLED_Toggle()        (LATAINV = (1 << 7))
    #define BootLED_On()            (LATASET = (1 << 7))
    #define BootLED_Off()           (LATACLR = (1 << 7))

    // Download LED
    #define EnableDownLoadLED()     (TRISACLR = (1 << 8))
    #define DisableDownLoadLED()    (TRISASET = (1 << 8))
    #define DownloadLED_Toggle()    (LATAINV = (1 << 8))    
    #define DownloadLED_On()        (LATASET = (1 << 8))
    #define DownloadLED_Off()       (LATACLR = (1 << 8))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA4 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATAbits.LATA4 == 1) 
    #define ClearVirtualProgramButton()             (LATACLR = (1 << 4))

    #define _CPU_NAME_              "32MX120F032D"
    #define VEND                    vendUnassigned
    #define PROD                    prodUnassigned
    #define F_CPU                   40000000UL              // CPU frequence
    #define F_PBUS                  F_CPU                   // Peripheral bus rate F_CPU / FPBDIV; just set it, saves code.

    #define FLASH_BYTES             0x8000                  // 32K
    #define FLASH_PAGE_SIZE         1024

    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                115200                  // avrdude baudrate
    #define UARTMapRX()             (U1RXR = 0x1)           // RPB6 -> U1RX
    #define UARTMapTX()             (RPB7R = 0x1)           // RB7 -> U1TX
 
//************************************************************************
#elif defined(_BOARD_CHIPKIT_UNO32_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = XT                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_1                         // PLL output divider
    #pragma config FPBDIV   = DIV_1                         // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                            // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO     = OFF                           // Internal/external clock switchover
    #pragma config FCKSM    = CSDCMD                        // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                           // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                           // Watchdog timer enable
    #pragma config WDTPS    =  PS1024                       // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx2                      // ICE pin selection
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 6))
    #define DisableBootLED()            (TRISGSET = (1 << 6))
    #define BootLED_Toggle()            (LATGINV = (1 << 6))
    #define BootLED_On()                (LATGSET = (1 << 6))
    #define BootLED_Off()               (LATGCLR = (1 << 6))

    // Download LED
    #define EnableDownLoadLED()         (TRISFCLR = (1 << 0))
    #define DisableDownLoadLED()        (TRISFSET = (1 << 0))
    #define DownloadLED_Toggle()        (LATFINV = (1 << 0))    
    #define DownloadLED_On()            (LATFSET = (1 << 0))
    #define DownloadLED_Off()           (LATFCLR = (1 << 0))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))
 
    #define _CPU_NAME_                  "32MX320F128H"
    #define VEND                        vendDigilent
    #define PROD                        prodChipKITUno32
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x20000             // 128K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)

//************************************************************************
#elif defined(_BOARD_CEREBOT_MX3CK_128_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC    = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD  = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                             // PLL input divider
    #pragma config FPLLMUL  = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV = DIV_1                             // PLL output divider
    #pragma config FPBDIV   = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO     = OFF                               // Internal/external clock switchover
    #pragma config FCKSM    = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                               // Watchdog timer enable
    #pragma config WDTPS    = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP       = OFF                               // Code protection
    #pragma config BWP      = OFF                               // Boot flash write protect
    #pragma config PWP      = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx2                          // ICE pin selection
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISFCLR = (1 << 0))
    #define DisableBootLED()            (TRISFSET = (1 << 0))
    #define BootLED_Toggle()            (LATFINV = (1 << 0))
    #define BootLED_On()                (LATFSET = (1 << 0))
    #define BootLED_Off()               (LATFCLR = (1 << 0))

    // Download LED
    #define EnableDownLoadLED()         (TRISFCLR = (1 << 1))
    #define DisableDownLoadLED()        (TRISFSET = (1 << 1))
    #define DownloadLED_Toggle()        (LATFINV = (1 << 1))    
    #define DownloadLED_On()            (LATFSET = (1 << 1))
    #define DownloadLED_Off()           (LATFCLR = (1 << 1))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))
 
    #define _CPU_NAME_                  "32MX320F128H"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebotMX3cK128
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x20000             // 128K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)        // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CHIPKIT_UC32_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC    = PRIPLL                        // Oscillator selection
    #pragma config POSCMOD  = XT                            // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                         // PLL input divider
    #pragma config FPLLMUL  = MUL_20                        // PLL multiplier
    #pragma config FPLLODIV = DIV_1                         // PLL output divider
    #pragma config FPBDIV   = DIV_1                         // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                            // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO     = OFF                           // Internal/external clock switchover
    #pragma config FCKSM    = CSDCMD                        // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                           // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                           // Watchdog timer enable
    #pragma config WDTPS    = PS1024                        // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP       = OFF                           // Code protection
    #pragma config BWP      = OFF                           // Boot flash write protect
    #pragma config PWP      = OFF                           // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx2                      // ICE pin selection
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 6))
    #define DisableBootLED()            (TRISGSET = (1 << 6))
    #define BootLED_Toggle()            (LATGINV = (1 << 6))
    #define BootLED_On()                (LATGSET = (1 << 6))
    #define BootLED_Off()               (LATGCLR = (1 << 6))

    // Download LED
    #define EnableDownLoadLED()         (TRISFCLR = (1 << 0))
    #define DisableDownLoadLED()        (TRISFSET = (1 << 0))
    #define DownloadLED_Toggle()        (LATFINV = (1 << 0))    
    #define DownloadLED_On()            (LATFSET = (1 << 0))
    #define DownloadLED_Off()           (LATFCLR = (1 << 0))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX340F512H"
    #define VEND                        vendDigilent
    #define PROD                        prodChipKITuC32
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000         // 512K   
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)

//************************************************************************
#elif defined(_BOARD_CEREBOT_MX3CK_512_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC    = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD  = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                             // PLL input divider
    #pragma config FPLLMUL  = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV = DIV_1                             // PLL output divider
    #pragma config FPBDIV   = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO     = OFF                               // Internal/external clock switchover
    #pragma config FCKSM    = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                               // Watchdog timer enable
    #pragma config WDTPS    = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP       = OFF                               // Code protection
    #pragma config BWP      = OFF                               // Boot flash write protect
    #pragma config PWP      = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx2                          // ICE pin selection
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISFCLR = (1 << 0))
    #define DisableBootLED()            (TRISFSET = (1 << 0))
    #define BootLED_Toggle()            (LATFINV = (1 << 0))
    #define BootLED_On()                (LATFSET = (1 << 0))
    #define BootLED_Off()               (LATFCLR = (1 << 0))

    // Download LED
    #define EnableDownLoadLED()         (TRISFCLR = (1 << 1))
    #define DisableDownLoadLED()        (TRISFSET = (1 << 1))
    #define DownloadLED_Toggle()        (LATFINV = (1 << 1))    
    #define DownloadLED_On()            (LATFSET = (1 << 1))
    #define DownloadLED_Off()           (LATFCLR = (1 << 1))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))
 
    #define _CPU_NAME_                  "32MX340F512H"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebotMX3cK512
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000         // 512K   
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)        // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CEREBOT_32MX4_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_1                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                    // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
#endif
    
    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISBCLR = (1 << 10))
    #define DisableBootLED()            (TRISBSET = (1 << 10))
    #define BootLED_Toggle()            (LATBINV = (1 << 10))
    #define BootLED_On()                (LATBSET = (1 << 10))
    #define BootLED_Off()               (LATBCLR = (1 << 10))

    // Download LED
    #define EnableDownLoadLED()         (TRISBCLR = (1 << 11))
    #define DisableDownLoadLED()        (TRISBSET = (1 << 11))
    #define DownloadLED_Toggle()        (LATBINV = (1 << 11))    
    #define DownloadLED_On()            (LATBSET = (1 << 11))
    #define DownloadLED_Off()           (LATBCLR = (1 << 11))

     // Other capabilities
    #define _USE_UART1_FOR_BOOTLOADER_                                  
    #define BAUDRATE                                115200              
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA6 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX460F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebot32MX4
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                 // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CEREBOT_32MX4_USB_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_1                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                    // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
#endif
    
    #define CAPABILITIES    (blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISBCLR = (1 << 10))
    #define DisableBootLED()            (TRISBSET = (1 << 10))
    #define BootLED_Toggle()            (LATBINV = (1 << 10))
    #define BootLED_On()                (LATBSET = (1 << 10))
    #define BootLED_Off()               (LATBCLR = (1 << 10))

    // Download LED
    #define EnableDownLoadLED()         (TRISBCLR = (1 << 11))
    #define DisableDownLoadLED()        (TRISBSET = (1 << 11)) 
    #define DownloadLED_Toggle()        (LATBINV = (1 << 11))    
    #define DownloadLED_On()            (LATBSET = (1 << 11))
    #define DownloadLED_Off()           (LATBCLR = (1 << 11))

    // Other capabilities
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA6 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX460F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebot32MX4
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CEREBOT_MX4CK_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_1                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                    // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
#endif
    
    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISBCLR = (1 << 10))
    #define DisableBootLED()            (TRISBSET = (1 << 10))
    #define BootLED_Toggle()            (LATBINV = (1 << 10))
    #define BootLED_On()                (LATBSET = (1 << 10))
    #define BootLED_Off()               (LATBCLR = (1 << 10))

    // Download LED
    #define EnableDownLoadLED()         (TRISBCLR = (1 << 11))
    #define DisableDownLoadLED()        (TRISBSET = (1 << 11))
    #define DownloadLED_Toggle()        (LATBINV = (1 << 11))    
    #define DownloadLED_On()            (LATBSET = (1 << 11))
    #define DownloadLED_Off()           (LATBCLR = (1 << 11))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX460F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebotMX4cK
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                 // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CHIPKIT_MAX32_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISACLR = (1 << 3))
    #define DisableBootLED()            (TRISASET = (1 << 3))
    #define BootLED_Toggle()            (LATAINV = (1 << 3))
    #define BootLED_On()                (LATASET = (1 << 3))
    #define BootLED_Off()               (LATACLR = (1 << 3))

    // Download LED
    #define EnableDownLoadLED()         (TRISCCLR = (1 << 1))
    #define DisableDownLoadLED()        (TRISCSET = (1 << 1))
    #define DownloadLED_Toggle()        (LATCINV = (1 << 1))    
    #define DownloadLED_On()            (LATCSET = (1 << 1))
    #define DownloadLED_Off()           (LATCCLR = (1 << 1))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodChipKITMax32
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CEREBOT_32MX7_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx1                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 12))
    #define DisableBootLED()            (TRISGSET = (1 << 12))
    #define BootLED_Toggle()            (LATGINV = (1 << 12))
    #define BootLED_On()                (LATGSET = (1 << 12))
    #define BootLED_Off()               (LATGCLR = (1 << 12))

    // Download LED
    #define EnableDownLoadLED()         (TRISGCLR = (1 << 13))
    #define DisableDownLoadLED()        (TRISGSET = (1 << 13))
    #define DownloadLED_Toggle()        (LATGINV = (1 << 13))    
    #define DownloadLED_On()            (LATGSET = (1 << 13))
    #define DownloadLED_Off()           (LATGCLR = (1 << 13))

    // Other capabilities
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaProgramButton        (PORTGbits.RG6 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebot32MX7
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                 // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_CEREBOT_32MX7_USB_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx1                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 12))
    #define DisableBootLED()            (TRISGSET = (1 << 12))
    #define BootLED_Toggle()            (LATGINV = (1 << 12))
    #define BootLED_On()                (LATGSET = (1 << 12))
    #define BootLED_Off()               (LATGCLR = (1 << 12))

    // Download LED
    #define EnableDownLoadLED()         (TRISGCLR = (1 << 13))
    #define DisableDownLoadLED()        (TRISGSET = (1 << 13))
    #define DownloadLED_Toggle()        (LATGINV = (1 << 13))    
    #define DownloadLED_On()            (LATGSET = (1 << 13))
    #define DownloadLED_Off()           (LATGCLR = (1 << 13))

    // Other capabilities
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaProgramButton        (PORTGbits.RG6 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebot32MX7
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
 
//************************************************************************
#elif defined(_BOARD_CEREBOT_32MX7_USB_SPLIT_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx1                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 12))
    #define DisableBootLED()            (TRISGSET = (1 << 12))
    #define BootLED_Toggle()            (LATGINV = (1 << 12))
    #define BootLED_On()                (LATGSET = (1 << 12))
    #define BootLED_Off()               (LATGCLR = (1 << 12))

    // Download LED
    #define EnableDownLoadLED()         (TRISGCLR = (1 << 13))
    #define DisableDownLoadLED()        (TRISGSET = (1 << 13))
    #define DownloadLED_Toggle()        (LATGINV = (1 << 13))    
    #define DownloadLED_On()            (LATGSET = (1 << 13))
    #define DownloadLED_Off()           (LATGCLR = (1 << 13))

    // Other capabilities
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaProgramButton        (PORTGbits.RG6 == 1) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebot32MX7
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x80000-4096)              // 512K less 4K for the splitflash bootloader in program flash
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
 
//************************************************************************
#elif defined(_BOARD_CEREBOT_MX7CK_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx1                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISGCLR = (1 << 12))
    #define DisableBootLED()            (TRISGSET = (1 << 12))
    #define BootLED_Toggle()            (LATGINV = (1 << 12))
    #define BootLED_On()                (LATGSET = (1 << 12))
    #define BootLED_Off()               (LATGCLR = (1 << 12))

    // Download LED
    #define EnableDownLoadLED()         (TRISGCLR = (1 << 13))
    #define DisableDownLoadLED()        (TRISGSET = (1 << 13))
    #define DownloadLED_Toggle()        (LATGINV = (1 << 13))    
    #define DownloadLED_On()            (LATGSET = (1 << 13))
    #define DownloadLED_Off()           (LATGCLR = (1 << 13))

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define _USE_UART1_FOR_BOOTLOADER_                      // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATCbits.LATC12 == 1) 
    #define ClearVirtualProgramButton()             (LATCCLR = (1 << 12))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendDigilent
    #define PROD                        prodCerebotMX7cK
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                 // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_UBW32_MX460_USB_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = ON                                // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISECLR = (1 << 3))
    #define DisableBootLED()            (TRISESET = (1 << 3))
    #define BootLED_Toggle()            (LATEINV = (1 << 3))
    #define BootLED_On()                (LATESET = (1 << 3))
    #define BootLED_Off()               (LATECLR = (1 << 3))

    // Download LED
    #define EnableDownLoadLED()         (TRISECLR = (1 << 2))
    #define DisableDownLoadLED()        (TRISESET = (1 << 2))
    #define DownloadLED_Toggle()        (LATEINV = (1 << 2))
    #define DownloadLED_On()            (LATESET = (1 << 2))
    #define DownloadLED_Off()           (LATECLR = (1 << 2))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTEbits.RE7 == 0)
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATEbits.LATE7 == 1)
    #define ClearVirtualProgramButton()             (LATECLR = (1 << 7))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodUBW32MX460
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_UBW32_MX795_USB_)

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = ON                                // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1024                            // Watchdog timer postscaler

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection
    #pragma config BWP          = OFF                               // Boot flash write protect
    #pragma config PWP          = OFF                               // Program flash write protect

    //*    Debug settings
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    //*    Other Peripheral Device settings
    #pragma config FSRSSEL      = PRIORITY_7                        // SRS interrupt priority
    #pragma config FCANIO       = OFF                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config UPLLIDIV     = DIV_2                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    (blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISECLR = (1 << 3))
    #define DisableBootLED()            (TRISESET = (1 << 3))
    #define BootLED_Toggle()            (LATEINV = (1 << 3))
    #define BootLED_On()                (LATESET = (1 << 3))
    #define BootLED_Off()               (LATECLR = (1 << 3))

    // Download LED
    #define EnableDownLoadLED()         (TRISECLR = (1 << 2))
    #define DisableDownLoadLED()        (TRISESET = (1 << 2))
    #define DownloadLED_Toggle()        (LATEINV = (1 << 2))    
    #define DownloadLED_On()            (LATESET = (1 << 2))
    #define DownloadLED_Off()           (LATECLR = (1 << 2))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTEbits.RE7 == 0) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATEbits.LATE7 == 1) 
    #define ClearVirtualProgramButton()             (LATECLR = (1 << 7))

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodUBW32MX795
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_FUBARINO_SD_USB_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = HS                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_1                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                   // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
#endif
    
    #define CAPABILITIES    (blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISECLR = (1 << 5))
    #define DisableBootLED()            (TRISESET = (1 << 5))
    #define BootLED_Toggle()            (LATEINV = (1 << 5))
    #define BootLED_On()                (LATESET = (1 << 5))
    #define BootLED_Off()               (LATECLR = (1 << 5))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTEbits.RE7 == 0) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATEbits.LATE7 == 1) 
    #define ClearVirtualProgramButton()             (LATECLR = (1 << 7))
 
    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoSD
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x40000                     // 256K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_FUBARINO_SD_512K_USB_)

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = HS                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_1                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                   // Secondary oscillator enable

    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable

    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider

    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler

    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect

    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
#endif

    #define CAPABILITIES    (blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISECLR = (1 << 5))
    #define DisableBootLED()            (TRISESET = (1 << 5))
    #define BootLED_Toggle()            (LATEINV = (1 << 5))
    #define BootLED_On()                (LATESET = (1 << 5))
    #define BootLED_Off()               (LATECLR = (1 << 5))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTEbits.RE7 == 0)
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATEbits.LATE7 == 1)
    #define ClearVirtualProgramButton()             (LATECLR = (1 << 7))

    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoSD_512K
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

//************************************************************************
#elif defined(_BOARD_FUBARINO_MINI_USB_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_2                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                   // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      		// ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           		// Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           		// Allow multiple reconfigurations
#endif
    
    #define CAPABILITIES    (blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISACLR = (1 << 10))
    #define DisableBootLED()            (TRISASET = (1 << 10))
    #define BootLED_Toggle()            (LATAINV = (1 << 10))
    #define BootLED_On()                (LATASET = (1 << 10))
    #define BootLED_Off()               (LATACLR = (1 << 10))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA8 == 0) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATAbits.LATA8 == 1) 
    #define ClearVirtualProgramButton()             (LATACLR = (1 << 8))
  
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoMini
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes

//************************************************************************
#elif defined(_BOARD_FUBARINO_MINI_USB_50MHZ_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_25                                // PLL multiplier
    #pragma config FPLLODIV = DIV_2                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                   // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      		// ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           		// Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           		// Allow multiple reconfigurations
#endif
    
    #define CAPABILITIES    (blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISACLR = (1 << 10))
    #define DisableBootLED()            (TRISASET = (1 << 10))
    #define BootLED_Toggle()            (LATAINV = (1 << 10))
    #define BootLED_On()                (LATASET = (1 << 10))
    #define BootLED_Off()               (LATACLR = (1 << 10))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA8 == 0) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATAbits.LATA8 == 1) 
    #define ClearVirtualProgramButton()             (LATACLR = (1 << 8))
  
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoMini50MHz
    #define F_CPU                       50000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes

//************************************************************************
#elif defined(_BOARD_EBBV3_USB_)
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_2                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = ON                                    // Secondary oscillator enable
    
    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable
    
    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    
    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
    
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //*    Debug settings
    #pragma config ICESEL   = ICS_PGx1                      		// ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           		// Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           		// Allow multiple reconfigurations
#endif
    
    #define CAPABILITIES    (blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // Boot LED
    #define EnableBootLED()             (TRISBCLR = (1 << 15))
    #define DisableBootLED()            (TRISBSET = (1 << 15))
    #define BootLED_Toggle()            (LATBINV = (1 << 15))
    #define BootLED_On()                (LATBSET = (1 << 15))
    #define BootLED_Off()               (LATBCLR = (1 << 15))

    // Other capabilities
    #define fLoadFromAVRDudeViaProgramButton        (PORTAbits.RA0 == 0) 
    #define fLoadFromAVRDudeViaVirtualProgramButton (LATAbits.LATA0 == 1) 
    #define ClearVirtualProgramButton()             (LATACLR = (1 << 0))
  
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodEBBv3
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes

#else
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
    (__32MX250F128D__)          )

	#define PPS_IN_USE		1		// indicate that this is a PPS type processor

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
        #error LoadFlashWaitStates is not supported and unneeded for the MX1/2
    #endif

   // define nothing for the flash wait states
    #define LoadFlashWaitStates()                           // not supported on MX1/2

#endif  // MX1 or MX2

// Assign the bootloader UART
#if( ((CAPABILITIES & blCapUARTInterface) == blCapUARTInterface) )
    #if defined(_USE_UART1_FOR_BOOTLOADER_)
        #define UMODE       U1MODE
        #define USTA        U1STA
        #define UBRG        U1BRG
        #define UMODEbits   U1MODEbits
        #define USTAbits    U1STAbits
        #define UTXREG      U1TXREG
        #define URXREG      U1RXREG
    #elif defined(_USE_UART2_FOR_BOOTLOADER_)
        #define UMODE       U2MODE
        #define USTA        U2STA
        #define UBRG        U2BRG
        #define UMODEbits   U2MODEbits
        #define USTAbits    U2STAbits
        #define UTXREG      U2TXREG
        #define URXREG      U2RXREG
    #elif defined(_USE_UART3_FOR_BOOTLOADER_)
        #define UMODE       U3MODE
        #define USTA        U3STA
        #define UBRG        U3BRG
        #define UMODEbits   U3MODEbits
        #define USTAbits    U3STAbits
        #define UTXREG      U3TXREG
        #define URXREG      U3RXREG
    #else
        #error a UART 1 thru 3 must be specified.
    #endif  // UART number
#elif ((CAPABILITIES & blCapUSBInterface) == blCapUSBInterface)
    // do nothing
#else  
    #error blCapUARTInterface or blCapUSBInterface must be assigned in CAPABILITIES
#endif

// if no DOWNLOAD LED
#if ((CAPABILITIES & blCapDownloadLED) == 0)
    #define EnableDownLoadLED()
    #define DisableDownLoadLED()
    #define DownloadLED_Toggle()
    #define DownloadLED_On()
    #define DownloadLED_Off()
#endif

// if no program button
#if ((CAPABILITIES & blCapProgramButton) == 0)
    #define fLoadFromAVRDudeViaProgramButton            (false)
#endif

// if no virtual program button
#if ((CAPABILITIES & blCapVirtualProgramButton) == 0)
    #define fLoadFromAVRDudeViaVirtualProgramButton     (false) 
    #define ClearVirtualProgramButton()
#endif

// if no auto reset listen time
#if ((CAPABILITIES & blCapAutoResetListening) == 0)
        #define LISTEN_BEFORE_LOAD                      0 
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

// core timer ticks per second is always 1/2 the CPU ticks
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
     
    #ifdef _AD1PCFG_w_POSITION
        AD1PCFG = 0xffff;
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
    	    byte value = 0;
    		value = URXREG;
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

