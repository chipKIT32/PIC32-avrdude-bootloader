/* MikroE boards */

#define     prodPIC32MXClicker          0x0001
#define     prodPIC32MZFlipNClick       0x0002

#if defined(_BOARD_MIKROE_PIC32MX_CLICKER_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

 // DEVCFG3
// USERID = No Setting
#pragma config FSRSSEL = PRIORITY_7     // SRS Select (SRS Priority 7)
#pragma config FCANIO = ON              // CAN I/O Pin Select (Default CAN I/O)
#pragma config FUSBIDIO = ON            // USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO = ON           // USB VBUS ON Selection (Controlled by USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider (2x Divider)
#pragma config UPLLEN = ON              // USB PLL Enable (Enabled)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
#pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = HS             // Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enable, FSCM Enabled)
#pragma config WDTPS = PS1024           // Watchdog Timer Postscaler (1:1024)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#endif

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     D
    #define BLedBit     1

    // Data LED
    #define DLedLat     D
    #define DLedBit     4

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    4

    // Program button
    #define PBntPort    B
    #define PBntBit     4

    #define _CPU_NAME_                  "32MX534F064H"
    #define VEND                        vendMikroE
    #define PROD                        prodPIC32MXClicker
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x10000                     // 64K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

#if defined(_BOARD_MIKROE_PIC32MZ_FLIP_N_CLICK_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

     //*    Oscillator Settings
    #pragma config POSCMOD      = EC                                // External Clock

    #pragma config FPLLIDIV     = DIV_3                             // 8 MHz
    #pragma config FPLLICLK     = PLL_POSC                          // 8MHz Posc

    #pragma config FNOSC        = SPLL                              // Oscillator selection
    #pragma config FPLLMULT     = MUL_63                            // 504 MHz
    #pragma config FPLLODIV     = DIV_2                             // 252 MHz

    #pragma config FPLLRNG      = RANGE_5_10_MHZ                    // 5-10Mhz
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable
    #pragma config UPLLFSEL     = FREQ_24MHZ                        // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

    //*    Clock control settings
    #pragma config IESO         = ON                                // Internal/external clock switchover
    #pragma config FCKSM        = CSECME                            // Clock switching (CSx)/Clock monitor (CMx)
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
    #pragma config DEBUG       = OFF                               // turn debugging on
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection
    #pragma config JTAGEN       = OFF                               // Disable JTAG pins

    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    #pragma config BOOTISA  = MIPS32

    //*    USB Settings
    #pragma config FUSBIDIO     = OFF                               // USBID pin control

    #pragma config DMTCNT       = 0
    
    #pragma config TSEQ         = 0x0000
    #pragma config CSEQ         = 0xFFFF

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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       High

    // Boot LED
    #define BLedLat     B
    #define BLedBit     14

    // Data LED
    #define DLedLat     A
    #define DLedBit     7

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    4

    // Program button
    #define PBntPort    B
    #define PBntBit     4
    
    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             5                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U5RXR = 0b1011)    // RPD14 -> U5RX
    #define UARTMapTX()                 (RPD15R = 0b0011)    // RPD15 -> U5TX

    #define _CPU_NAME_                  "32MZ2048EFH100"
    #define VEND                        vendMikroE
    #define PROD                        prodPIC32MZFlipNClick
    #define F_CPU                       252000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K
#endif

