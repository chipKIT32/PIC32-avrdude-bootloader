/* Schmalzhaus boards */

#define     prodEBBv3           0x0001
#define     prodUBW32MX460      0x0002
#define     prodUBW32MX795      0x0003

#if defined(_BOARD_UBW32_MX460_USB_)
#define _CONFIG_VALID_

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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     E
    #define BLedBit     3

    // Download LED
    #define DLedLat     E
    #define DLedBit     2

    // Virtual program button
    #define VPBntLat    E
    #define VPBntBit    7

    // Program button
    #define PBntPort    E
    #define PBntBit     7

    #define _CPU_NAME_                  "32MX460F512L"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodUBW32MX460
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_UBW32_MX795_USB_)
#define _CONFIG_VALID_

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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     E
    #define BLedBit     3

    // Download LED
    #define DLedLat     E
    #define DLedBit     2

    // Virtual program button
    #define VPBntLat    E
    #define VPBntBit    7

    // Program button
    #define PBntPort    E
    #define PBntBit     7

    #define _CPU_NAME_                  "32MX795F512L"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodUBW32MX795
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)                // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_EBBV3_USB_)
#define _CONFIG_VALID_
 
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
    #pragma config FUSBIDIO = OFF									// USB USID pin controlled by port function
    #pragma config FVBUSONIO = OFF									// USB VBUSON pin controlled by port function
    
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
    
    #define CAPABILITIES    (blCapBootLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     B
    #define BLedBit     15

    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    0

    // Program button
    #define PBntPort    A
    #define PBntBit     0
   
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendSchmalzHausLLC
    #define PROD                        prodEBBv3
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes
#endif

