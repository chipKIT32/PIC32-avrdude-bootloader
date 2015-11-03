/* PONTECH Boards */


#define     prodQuick240                0x0001
#define     prodPontechUAV100           0x0002

#if defined(_BOARD_UAV100_)  // 32MX440F512H
#define _CONFIG_VALID_

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

    #define CAPABILITIES    (blCapBootLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     F
    #define BLedBit     0

    // Virtual program button
    #define VPBntLat    D
    #define VPBntBit    4

    // Program button
    #define PBntPort    D
    #define PBntBit     4

    #define _CPU_NAME_                  "32MX440F512H"
    #define VEND                        vendPontech
    #define PROD                        prodPontechUAV100
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_QUICK240_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //*    Oscillator Settings
    #pragma config FNOSC        = PRIPLL                            // Oscillator selection
    #pragma config POSCMOD  = HS                                    // Primary oscillator mode
    #pragma config FPLLIDIV     = DIV_2                             // PLL input divider
    #pragma config FPLLMUL      = MUL_20                            // PLL multiplier
    #pragma config FPLLODIV     = DIV_1                             // PLL output divider
    #pragma config FPBDIV       = DIV_1                             // Peripheral bus clock divider
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable

    //*    Clock control settings
    #pragma config IESO         = OFF                               // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //* USB Settings
    #pragma config UPLLEN   = ON                                    // USB PLL enable
    #pragma config UPLLIDIV = DIV_2                                 // USB PLL input divider
    #pragma config FUSBIDIO = OFF                                   // USB USID pin controlled by port function
    #pragma config FVBUSONIO = OFF                                  // USB VBUSON pin controlled by port function

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
    #pragma config FCANIO       = ON                               // Standard/alternate CAN pin select (OFF=Alt)
    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

#endif

    #define CAPABILITIES    (blCapBootLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     E
    #define BLedBit     0

    // Download LED
    #define DLedLat     A
    #define DLedBit     7

    // Virtual program button
    #define VPBntLat    G
    #define VPBntBit    15

    // Program button
    #define PBntPort    G
    #define PBntBit     15

    // Other capabilities
    //#define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    //#define BOOTLOADER_UART             1                   // avrdude program UART
    //#define BAUDRATE                    115200              // avrdude baudrate

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendPontech
    #define PROD                        prodQuick240
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

