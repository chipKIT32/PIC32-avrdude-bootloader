/* Example board configs */

#if defined(_BOARD_EXAMPLE_MX1_)               
#define _CONFIG_VALID_

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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       High

    // Boot LED
    #define BLedLat     A
    #define BLedBit     7

    // Download LED
    #define DLedLat     A
    #define DLedBit     8

    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    4

    // Program button
    #define PBntPort    A
    #define PBntBit     4

    #define _CPU_NAME_              "32MX120F032D"
    #define VEND                    vendUnassigned
    #define PROD                    prodUnassigned
    #define F_CPU                   40000000UL              // CPU frequence
    #define F_PBUS                  F_CPU                   // Peripheral bus rate F_CPU / FPBDIV; just set it, saves code.

    #define FLASH_BYTES             0x8000                  // 32K
    #define FLASH_PAGE_SIZE         1024

    #define BOOTLOADER_UART         1                       // avrdude program UART
    #define BAUDRATE                115200                  // avrdude baudrate
    #define UARTMapRX()             (U1RXR = 0x1)           // RPB6 -> U1RX
    #define UARTMapTX()             (RPB7R = 0x1)           // RB7 -> U1TX
#endif
