/* Fubairno boards */

#define     prodFubarinoSD      0x0001
#define     prodFubarinoMini    0x0002
#define     prodFubarinoSD_512K 0x0003
#define     prodFubarinoMini48MHz 0x0004
#define     prodFubarinoMini50MHz 0x0005
#define     prodFubarinoSDZ     0x0006

#if defined(_BOARD_FUBARINO_SDZ_UART_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

     //*    Oscillator Settings
    // works with proper timing
    #pragma config POSCMOD      = EC                                // External Clock
//    #pragma config POSCMOD      = HS                                // Crystal

    #pragma config FPLLIDIV     = DIV_3                             // 8 MHz
    #pragma config FPLLICLK     = PLL_POSC                          // 8MHz Posc

    #pragma config FNOSC        = SPLL                              // Oscillator selection
    #pragma config FPLLMULT     = MUL_50                            // 400 MHz
    #pragma config FPLLODIV     = DIV_2                             // 200 MHz or 80 MHz, depending

    #pragma config FPLLRNG      = RANGE_5_10_MHZ                    // 5-10Mhz
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable
    #pragma config UPLLFSEL     = FREQ_24MHZ                        // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

    //*    Clock control settings
    #pragma config IESO         = ON                                // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = OFF                               // Clock output on OSCO pin enable

    //*    Other Peripheral Device settings
    #pragma config FWDTEN       = OFF                               // Watchdog timer enable
    #pragma config WDTPS        = PS1048576                         // Watchdog timer postscaler
    #pragma config WDTSPGM      = STOP                              // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
    #pragma config WINDIS       = NORMAL                            // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
    #pragma config FWDTWINSZ    = WINSZ_25                          // Watchdog Timer Window Size (Window size is 25%)
    #pragma config FDMTEN       = OFF                               // Deadman Timer Enable (Deadman Timer is disabled)

    //*    Code Protection settings
    #pragma config CP           = OFF                               // Code protection

    //*    Debug settings
//    #pragma config DEBUG       = ON                               // turn debugging on
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    #pragma config BOOTISA  = MIPS32

    //*    USB Settings
    #pragma config UPLLEN       = ON                                // USB PLL enable
    #pragma config FUSBIDIO     = OFF                               // USBID pin control

    #pragma config DMTCNT       = 0

//#pragma config PGL1WAY  = OFF             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
//#pragma config PMDL1WAY = OFF             // Peripheral Module Disable Configuration (Allow only one reconfiguration)
//#pragma config IOL1WAY  = OFF             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
//#pragma config DMTINTV  = WIN_127_128     // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
//#pragma config EJTAGBEN = NORMAL
//#pragma config DBGPER   = PG_ALL
//#pragma config FSLEEP   = OFF
//#pragma config FECCCON  = OFF_UNLOCKED
//#pragma config TRCEN    = OFF

#endif

    #define CAPABILITIES    (blCapBootLED | blCapUARTInterface |  blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     E
    #define BLedBit     5

    // Virtual program button
    #define VPBntLat    E
    #define VPBntBit    7

    // Program button
    #define PBntPort    E
    #define PBntBit     7

    // Other capabilities
    #define BOOTLOADER_UART             1                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U1RXR = 0b0010)    // RPF4 -> U1RX
    #define UARTMapTX()                 (RPF5R = 0b0001)    // RF5 -> U1TX

    #define _CPU_NAME_                  "PIC32MZ2048ECG"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoSDZ
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K
#endif

//************************************************************************

#if defined(_BOARD_FUBARINO_SD_USB_)  // 32MX440F256H, SeedStudio version (after first 100) - v1.4
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
    #define BLedLat     E
    #define BLedBit     5

    // Virtual program button
    #define VPBntLat    E
    #define VPBntBit    7

    // Program button
    #define PBntPort    E
    #define PBntBit     7

    #define _CPU_NAME_                  "32MX440F256H"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoSD
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x40000                     // 256K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_FUBARINO_SD_512K_USB_) // 32MX795F512H, Microchip version (v1.5)
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
    #pragma config FUSBIDIO = OFF									// USB USID pin controlled by port function
    #pragma config FVBUSONIO = OFF									// USB VBUSON pin controlled by port function

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
    #define BLedLat     E
    #define BLedBit     5

    // Virtual program button
    #define VPBntLat    E
    #define VPBntBit    7

    // Program button
    #define PBntPort    E
    #define PBntBit     7
 
    #define _CPU_NAME_                  "32MX795F512H"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoSD_512K
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_FUBARINO_MINI_USB_)
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
    #define BLedLat     A
    #define BLedBit     10

    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    8

    // Program button
    #define PBntPort    A
    #define PBntBit     8
  
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoMini
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes
#endif

//************************************************************************

#if defined(_BOARD_FUBARINO_MINI_USB_48MHZ_)
#define _CONFIG_VALID_
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_24                                // PLL multiplier
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
    #define BLedLat     A
    #define BLedBit     10


    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    8

    // Program button
    #define PBntPort    A
    #define PBntBit     8
  
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoMini48MHz
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes
#endif

//************************************************************************

#if defined(_BOARD_FUBARINO_MINI_USB_50MHZ_)
#define _CONFIG_VALID_
// This is a Fubarino Mini with a 20MHz crystal
 
#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = XT                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_4                                 // PLL input divider
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
    #pragma config UPLLIDIV = DIV_5                                 // USB PLL input divider
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
    #define BLedLat     A
    #define BLedBit     10

    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    8

    // Program button
    #define PBntPort    A
    #define PBntBit     8
 
    #define _CPU_NAME_                  "32MX250F128D"
    #define VEND                        vendFubarino
    #define PROD                        prodFubarinoMini50MHz
    #define F_CPU                       50000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room one flash block (for bootloader!)
    #define FLASH_PAGE_SIZE             1024						// In bytes
#endif

