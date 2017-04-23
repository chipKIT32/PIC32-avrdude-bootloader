/* Olimex Boards */

#define     prodOlimex_PIC32_Pinguino   0x0001
#define     prodOlimex_Duinomite        0x0002
#define     prodOlimex_Pinguino_Micro   0x0003

#if defined(_BOARD_OLIMEX_PINGUINO_MICRO_UART_57600_)
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
//    #pragma config WINDIS   = OFF
//    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
   
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging
#endif
    
    #define CAPABILITIES    (blCapProgramButton | blCapVirtualProgramButton | blCapBootLED | blCapDownloadLED | blCapSplitFlashBootloader | blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     G
    #define BLedBit     6

    // Download LED
    #define DLedLat     D
    #define DLedBit     1

    // Virtual program button
    #define VPBntLat    D
    #define VPBntBit    4

    // Program button
    #define PBntPort    D
    #define PBntBit     4

    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    57600               // avrdude baudrate
 
    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendOlimex
    #define PROD                        prodOlimex_Pinguino_Micro
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x40000                     // 256K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************
#if defined(_BOARD_OLIMEX_PINGUINO_MICRO_UART_)
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
//    #pragma config WINDIS   = OFF
//    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
   
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging
#endif
    
    #define CAPABILITIES    (blCapBootLED | blCapSplitFlashBootloader | blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     G
    #define BLedBit     6

    // Virtual program button
    #define VPBntLat    D
    #define VPBntBit    0

    // Program button
    #define PBntPort    D
    #define PBntBit     0

    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
 
    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendOlimex
    #define PROD                        prodOlimex_Pinguino_Micro
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x40000                     // 256K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_OLIMEX_PIC32_PINGUINO_)
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
//    #pragma config WINDIS   = OFF
//    #pragma config JTAGEN   = OFF                          			// JTAG port disabled
   
    //* Code Protection settings
    #pragma config CP       = OFF                                   // Code protection
    #pragma config BWP      = OFF                                   // Boot flash write protect
    #pragma config PWP      = OFF                                   // Program flash write protect
    
    //* Debug settings
    #pragma config ICESEL   = ICS_PGx2                              // ICE pin selection
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging
#endif
    
    #define CAPABILITIES    (blCapBootLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     G
    #define BLedBit     6

    // Virtual program button
    #define VPBntLat    D
    #define VPBntBit    0

    // Program button
    #define PBntPort    D
    #define PBntBit     0
 
    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendOlimex
    #define PROD                        prodOlimex_PIC32_Pinguino
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x40000                     // 256K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_OLIMEX_DUINOMITE_) // 32MX795F512H, Microchip version (v1.5)
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
    #pragma config FUSBIDIO = OFF                                   // USB USID pin controlled by port function
    #pragma config FVBUSONIO = OFF                                  // USB VBUSON pin controlled by port function

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
    #define BLedLat     B
    #define BLedBit     15

    // Virtual program button
    #define VPBntLat    D
    #define VPBntBit    8

    // Program button
    #define PBntPort    D
    #define PBntBit     8

    #define _CPU_NAME_                  "32MX795F512H"
    #define VEND                        vendOlimex
    #define PROD                        prodOlimex_Duinomite
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif
