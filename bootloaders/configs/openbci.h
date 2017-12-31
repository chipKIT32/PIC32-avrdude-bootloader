/* OpenBCI Boards */

#define     prodChipKITUDB32PIM 0x0501

#if defined(_BOARD_UDB32_MX2_DIP_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_2                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                    // Secondary oscillator enable

    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable

    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    #pragma config FVBUSONIO = OFF                                  // Make VBUSON a GPIO pin
    #pragma config FUSBIDIO = OFF                                   // Controlled by port function

    //* Other Peripheral Device settings
    #pragma config FWDTEN   = OFF                                   // Watchdog timer enable
    #pragma config WDTPS    = PS1024                                // Watchdog timer postscaler
    #pragma config WINDIS   = OFF
    #pragma config JTAGEN   = OFF                                   // JTAG port disabled

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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUARTInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       Low
    #define BntOn       High

    // Boot LED
    #define BLedLat     B
    #define BLedBit     0

    // Download LED
    #define DLedLat     B
    #define DLedBit     1

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    4

    // Program button
    #define PBntPort    B
    #define PBntBit     4

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendOpenBCI
    #define PROD                        prodChipKITUDB32PIM
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000 - 0x1000)           // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                // In bytes

    #define BOOTLOADER_UART             1                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U1RXR = 0x3)       // RPB13 -> U1RX
    #define UARTMapTX()                 (RPB3R = 0x1)       // RB3 -> U1TX
#endif
