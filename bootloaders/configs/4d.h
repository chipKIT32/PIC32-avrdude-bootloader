/* 4D Boards */


#define     prodPICadillo35t            0x0001

#if defined(_BOARD_PICADILLO_35T_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD      = XT                                // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_3                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = ON                                // Secondary oscillator enable

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
    #pragma config UPLLIDIV     = DIV_3                             // USB PLL input divider
    #pragma config FVBUSONIO    = OFF                               // VBUS pin control
    #pragma config FUSBIDIO     = OFF                               // USBID pin control
#endif

    #define CAPABILITIES    ( blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

//    // BTN / LED sense
//    #define LedOn       High
//    #define BntOn       High
//
//    // Boot LED
//    #define BLedLat     A
//    #define BLedBit     3
//
//    // Download LED
//    #define DLedLat     C
//    #define DLedBit     1

    // Virtual program button
    #define VPBntLat    C
    #define VPBntBit    12

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             1                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vend4DSystems
    #define PROD                        prodPICadillo35t
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

