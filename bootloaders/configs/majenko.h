/* Majenko Boards */

// *****************************************************************************
// *****************************************************************************
//                    Majenko Technologies Product IDs
// *****************************************************************************
// *****************************************************************************
#define     prodSDXL                    0x0001
#define     prodSDAU                    0x0002
#define     prodSDZL                    0x0003
#define     prodUltraNano               0x0004
#define     prodLenny                   0x0005
#define     prodPKRelay                 0x0007
#define     prodDSMini                  0x0008
#define     prodModProg                 0x1001
#define     prodFXBase                  0x1002
#define     prodMotionTracker           0x1003

#if defined(_BOARD_MAJENKO_DSMINI_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_20                                // PLL multiplier
    #pragma config FPLLODIV = DIV_2                                 // PLL output divider
    #pragma config FPBDIV   = DIV_1                                 // Peripheral bus clock divider
    #pragma config FSOSCEN  = OFF                                   // Secondary oscillator enable

    //* Clock control settings
    #pragma config IESO     = OFF                                   // Internal/external clock switchover
    #pragma config FCKSM    = CSECME                                // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC = OFF                                   // Clock output on OSCO pin enable

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
    #pragma config ICESEL   = ICS_PGx3                              // ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                                  // DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                                   // Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                                   // Allow multiple reconfigurations
#endif

    #define CAPABILITIES    (blCapBootLED | blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     C
    #define BLedBit     3

    #define _CPU_NAME_                  "32MX150F128C"
    #define VEND                        vendMajenko
    #define PROD                        prodDSMini
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             1                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U1RXR = 0b0110)    // RPB7 -> U2RX (A9)
    #define UARTMapTX()                 (RPC0R = 0b0001)    // RPB6 -> U2TX (A8)

    #define FLASH_BYTES                 (0x20000-0x1000)            // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

#if defined(_BOARD_MAJENKO_SDXL_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
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
    #define BLedLat     E
    #define BLedBit     7

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    5

    // Program button
    #define PBntPort    B
    #define PBntBit     5

    #define _CPU_NAME_                  "32MX795F512H"
    #define VEND                        vendMajenko
    #define PROD                        prodSDXL
    #define F_CPU                       80000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_MAJENKO_SDAU_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_24                                // PLL multiplier
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

    // PPS
    #pragma config PMDL1WAY = OFF                                   // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
    #pragma config IOL1WAY = OFF                                    // Peripheral Pin Select Configuration (Allow multiple reconfigurations)

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
    #define BLedBit     7

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    5

    // Program button
    #define PBntPort    B
    #define PBntBit     5

    #define _CPU_NAME_                  "32MX470F512H"
    #define VEND                        vendMajenko
    #define PROD                        prodSDAU
    #define F_CPU                       96000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz
#endif

//************************************************************************

#if defined(_BOARD_MAJENKO_SDZL_)
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

    #define CAPABILITIES    (blCapBootLED | blCapProgramButton | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Program button
    #define PBntPort    B
    #define PBntBit     5

    // Boot LED
    #define BLedLat     E
    #define BLedBit     7

    // Virtual program button
    #define VPBntLat    C
    #define VPBntBit    12

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0b0111)    // RPB7 -> U2RX (A9)
    #define UARTMapTX()                 (RPB6R = 0b0010)    // RPB6 -> U2TX (A8)

    #define _CPU_NAME_                  "PIC32MZ2048ECG"
    #define VEND                        vendMajenko
    #define PROD                        prodSDZL
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K
#endif

#if defined(_BOARD_MAJENKO_MOTION_TRACKER_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

// DEVCFG3
// USERID = No Setting
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = OFF            // Permission Group Lock One Way Configuration (Allow multiple reconfigurations)
#pragma config PMDL1WAY = OFF           // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)
#pragma config FUSBIDIO = OFF           // USB USBID Selection (Controlled by Port Function)

// DEVCFG2
#pragma config FPLLIDIV = DIV_3         // System PLL Input Divider (1x Divider)
#pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_50        // System PLL Multiplier (PLL Multiply by 50)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (2x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = SPLL             // Oscillator Selection Bits (System PLL)
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = EC             // Primary Oscillator Configuration (External clock mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disabled, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = ALLOW_PG2       // Debug Mode CPU Access Permission (Allow CPU access to Permission Group 2 permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = OFF          // Secondary Oscillator Boost Kick Start Enable bit (Normal start of the oscillator)
#pragma config POSCGAIN = GAIN_1X       // Primary Oscillator Gain Control bits (1x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ3


#endif

    #define CAPABILITIES    (blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0b0111)    // RPB7 -> U2RX
    #define UARTMapTX()                 (RPB6R = 0b0010)    // RPB6 -> U2TX 

    #define _CPU_NAME_                  "PIC32MZ2048EFG"
    #define VEND                        vendMajenko
    #define PROD                        prodMotionTracker
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K

    #define HOOK_INIT \
                extern int hook_init(); \
                hook_init(); 
    #define HOOK_CMD_SIGN_ON \
                extern int hook_cmd_sign_on(); \
                hook_cmd_sign_on();
    #define HOOK_CMD_PROGRAM_FLASH_ISP \
                extern int hook_cmd_program_flash_isp(uint32_t a); \
                hook_cmd_program_flash_isp(load_address);

#endif
//************************************************************************

#if defined(_BOARD_MAJENKO_FX_BASE_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

// DEVCFG3
// USERID = No Setting
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = OFF            // Permission Group Lock One Way Configuration (Allow multiple reconfigurations)
#pragma config PMDL1WAY = OFF           // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)
#pragma config FUSBIDIO = OFF           // USB USBID Selection (Controlled by Port Function)

// DEVCFG2
#pragma config FPLLIDIV = DIV_3         // System PLL Input Divider (1x Divider)
#pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_50        // System PLL Multiplier (PLL Multiply by 50)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (2x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = SPLL             // Oscillator Selection Bits (System PLL)
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = EC             // Primary Oscillator Configuration (External clock mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disabled, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = ALLOW_PG2       // Debug Mode CPU Access Permission (Allow CPU access to Permission Group 2 permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = OFF          // Secondary Oscillator Boost Kick Start Enable bit (Normal start of the oscillator)
#pragma config POSCGAIN = GAIN_1X       // Primary Oscillator Gain Control bits (1x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ3


#endif

    #define CAPABILITIES    (blCapUARTInterface | blCapAutoResetListening | CAPCOMMON)

    // Other capabilities
    #define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0b0111)    // RPB7 -> U2RX
    #define UARTMapTX()                 (RPB6R = 0b0010)    // RPB6 -> U2TX 

    #define _CPU_NAME_                  "PIC32MZ2048EFG"
    #define VEND                        vendMajenko
    #define PROD                        prodFXBase
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K

#endif
//************************************************************************

#if defined(_BOARD_MAJENKO_MOD_PROG_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_24                                // PLL multiplier
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

    #define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     B
    #define BLedBit     14

    #define DLedLat     A
    #define DLedBit     1


    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    2

    // Program button
    #define PBntPort    B
    #define PBntBit     2
    #define PBntPu      High

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendMajenko
    #define PROD                        prodModProg
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

#if defined(_BOARD_MAJENKO_ULTRANANO_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_24                                // PLL multiplier
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

    #define CAPABILITIES    (blCapBootLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     B
    #define BLedBit     13


    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    3

    // Program button
    #define PBntPort    A
    #define PBntBit     3
    #define PBntPu      High

    #define _CPU_NAME_                  "32MX250F128B"
    #define VEND                        vendMajenko
    #define PROD                        prodUltraNano
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x20000-0x1000)		    // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

#if defined(_BOARD_MAJENKO_LENNY_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
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
    #pragma config ICESEL   = ICS_PGx3                      		// ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           		// Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           		// Allow multiple reconfigurations
#endif

    #define CAPABILITIES    ( blCapUSBSerialNumber | blCapBootLED | blCapDownloadLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     10

    // Boot LED
    #define DLedLat     A
    #define DLedBit     8

    #define USBManufacturerLen 40
    #define USBManufacturer 'M',0,'a',0,'j',0,'e',0,'n',0,'k',0,'o',0,' ',0,'T',0,'e',0,'c',0,'h',0,'n',0,'o',0,'l',0,'o',0,'g',0,'i',0,'e',0,'s',0
    #define USBProductLen 26
    #define USBProduct 'c',0,'h',0,'i',0,'p',0,'K',0,'I',0,'T',0,' ',0,'L',0,'e',0,'n',0,'n',0,'y',0


    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    4

    // Program button
    #define PBntPort    B
    #define PBntBit     4
    #define PBntPu      High

    #define _CPU_NAME_                  "32MX270F256D"
    #define VEND                        vendMajenko
    #define PROD                        prodLenny
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)		    // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

#if defined(_BOARD_MAJENKO_LENNY48_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = EC                                    // Primary oscillator mode
    #pragma config FPLLIDIV = DIV_2                                 // PLL input divider
    #pragma config FPLLMUL  = MUL_24                                // PLL multiplier
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
    #pragma config ICESEL   = ICS_PGx3                      		// ICE/ICD Comm Channel Select
    //#pragma config DEBUG    = ON                          		// DO NOT SET THIS CONFIG BIT, it will break debugging

    #pragma config PMDL1WAY = OFF                           		// Allow multiple reconfigurations
    #pragma config IOL1WAY  = OFF                           		// Allow multiple reconfigurations
#endif

    #define CAPABILITIES    ( blCapUSBSerialNumber | blCapBootLED | blCapDownloadLED | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     A
    #define BLedBit     10

    // Boot LED
    #define DLedLat     A
    #define DLedBit     8

    #define USBManufacturerLen 40
    #define USBManufacturer 'M',0,'a',0,'j',0,'e',0,'n',0,'k',0,'o',0,' ',0,'T',0,'e',0,'c',0,'h',0,'n',0,'o',0,'l',0,'o',0,'g',0,'i',0,'e',0,'s',0
    #define USBProductLen 26
    #define USBProduct 'c',0,'h',0,'i',0,'p',0,'K',0,'I',0,'T',0,' ',0,'L',0,'e',0,'n',0,'n',0,'y',0


    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    4

    // Program button
    #define PBntPort    B
    #define PBntBit     4
    #define PBntPu      High

    #define _CPU_NAME_                  "32MX270F256D"
    #define VEND                        vendMajenko
    #define PROD                        prodLenny
    #define F_CPU                       48000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)		    // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

#if defined(_BOARD_MAJENKO_PKRELAY_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)
    // DEVCFG3
    // USERID = No Setting
    #pragma config FSRSSEL = PRIORITY_7     // Shadow Register Set Priority Select (SRS Priority 7)
    #pragma config PMDL1WAY = OFF           // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
    #pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)
    #pragma config FUSBIDIO = OFF           // USB USID Selection (Controlled by Port Function)
    #pragma config FVBUSONIO = OFF          // USB VBUS ON Selection (Controlled by Port Function)

    // DEVCFG2
    #pragma config FPLLIDIV = DIV_2         // PLL Input Divider (1x Divider)
    #pragma config FPLLMUL = MUL_24         // PLL Multiplier (15x Multiplier)
    #pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider (2x Divider)
    #pragma config UPLLEN = ON              // USB PLL Enable (Enabled)
    #pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

    // DEVCFG1
    #pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
    #pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
    #pragma config IESO = ON                // Internal/External Switch Over (Enabled)
    #pragma config POSCMOD = EC             // Primary Oscillator Configuration (External clock mode)
    #pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
    #pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
    #pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enable, FSCM Enabled)
    #pragma config WDTPS = PS65536          // Watchdog Timer Postscaler (1:1048576)
    #pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
    #pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
    #pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

    // DEVCFG0
    #pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is Disabled)
    #pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
    #pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC2/PGED2)
    #pragma config PWP = OFF                // Program Flash Write Protect (Disable)
    #pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
    #pragma config CP = OFF                 // Code Protect (Protection Disabled)

#endif

    #define CAPABILITIES    (blCapUSBSerialNumber | blCapDownloadLED | blCapBootLED | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     B
    #define BLedBit     9
    
    // Download LED
    #define DLedLat     B
    #define DLedBit     10

    // Virtual program button
    #define VPBntLat    G
    #define VPBntBit    6

    // Program button
    #define PBntPort    G
    #define PBntBit     6

    #define _CPU_NAME_                  "32MX470F512H"
    #define VEND                        vendMajenko
    #define PROD                        prodPKRelay
    #define F_CPU                       96000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 0x80000                     // 512K
    #define FLASH_PAGE_SIZE             4096
    #define LoadFlashWaitStates()       (CHECON = 2)            // 0 for 0-30Mhz, 1 for 31-60Mhz, 2 for 61-80Mhz

    #define USBManufacturerLen 26
    #define USBManufacturer 'P',0,'r',0,'e',0,'c',0,'i',0,'s',0,'i',0,'o',0,'n',0,'K',0,'i',0,'n',0,'g',0
    #define USBProductLen 24
    #define USBProduct 'R',0,'e',0,'m',0,'o',0,'t',0,'e',0,' ',0,'R',0,'e',0,'l',0,'a',0,'y',0
    #define USBSerialTemplate 'P', 0, 'K', 0, 'R', 0, 'L', 0, 'P', 0, 'R', 0, 'T', 0, '0', 0, '0', 0, '1', 0, '*', 0, '*', 0, '*', 0, '*', 0


#endif

//
