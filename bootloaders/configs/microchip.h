/* Microchip Starter Kit board PIC32MZ2048EFM144 */

#define     prodMichrochipEthStartKitUART     0x0001
#define     prodMichrochipCuriosityUART      0x0002

#if defined(_BOARD_MICROCHIP_ETH_START_KIT_UART_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

     //*    Oscillator Settings

    #pragma config POSCMOD      = EC                                // External Clock

    #pragma config FPLLIDIV     = DIV_3                             // 8 MHz
    #pragma config FPLLICLK     = PLL_POSC                          // 8MHz Posc

    #pragma config FNOSC        = SPLL                              // Oscillator selection
    #pragma config FPLLMULT     = MUL_50                            // 400 MHz
    #pragma config FPLLODIV     = DIV_2                             // 200 MHz or 80 MHz, depending

    #pragma config FPLLRNG      = RANGE_5_10_MHZ                    // 5-10Mhz
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable
    #pragma config UPLLFSEL     = FREQ_24MHZ                        // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

    //*    Clock control settings
    #pragma config IESO         = OFF                                // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = ON                               // Clock output on OSCO pin enable

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
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    #pragma config BOOTISA  = MIPS32

    //*    USB Settings
    #pragma config FUSBIDIO     = OFF                               // USBID pin control

    #pragma config DMTCNT       = 0

    #pragma config PGL1WAY  = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
    #pragma config PMDL1WAY = ON             // Peripheral Module Disable Configuration (Allow only one reconfiguration)
    #pragma config IOL1WAY  = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
    #pragma config DMTINTV  = WIN_127_128     // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
    #pragma config EJTAGBEN = NORMAL

#endif

    #define CAPABILITIES    (blCapBootLED | blCapUARTInterface |  blCapVirtualProgramButton | blCapDownloadLED | blCapAutoResetListening | CAPCOMMON)

    #define LISTEN_BEFORE_LOAD 3000
    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED
    #define BLedLat     H
    #define BLedBit     0
    
    // Download LED
    #define DLedLat     H
    #define DLedBit     1
    

    // Virtual program button
    #define VPBntLat    B
    #define VPBntBit    12

    // Program button
    #define PBntPort    B
    #define PBntBit     12

    // Other capabilities
    #define BOOTLOADER_UART             2                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U2RXR = 0b0001)    // RPG6 -> U2RX
    #define UARTMapTX()                 (RPB14R = 0b0010)    // RPB14 -> U2TX
    
    #define _CPU_NAME_                  "PIC32MZ2048EFM"
    #define VEND                        vendMicrochip
    #define PROD                        prodMichrochipEthStartKitUART
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                    // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K
#endif

#if defined(_BOARD_MICROCHIP_CURIOSITY_UART_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

     //*    Oscillator Settings

    #pragma config POSCMOD      = EC                                // External Clock

    #pragma config FPLLIDIV     = DIV_3                             // 8 MHz
    #pragma config FPLLICLK     = PLL_POSC                          // 8MHz Posc

    #pragma config FNOSC        = SPLL                              // Oscillator selection
    #pragma config FPLLMULT     = MUL_50                            // 400 MHz
    #pragma config FPLLODIV     = DIV_2                             // 200 MHz or 80 MHz, depending

    #pragma config FPLLRNG      = RANGE_5_10_MHZ                    // 5-10Mhz
    #pragma config FSOSCEN      = OFF                               // Secondary oscillator enable
    #pragma config UPLLFSEL     = FREQ_24MHZ                        // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

    //*    Clock control settings
    #pragma config IESO         = OFF                                // Internal/external clock switchover
    #pragma config FCKSM        = CSDCMD                            // Clock switching (CSx)/Clock monitor (CMx)
    #pragma config OSCIOFNC     = ON                               // Clock output on OSCO pin enable

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
    #pragma config ICESEL       = ICS_PGx2                          // ICE pin selection

    #pragma config FETHIO       = ON                                // Standard/alternate ETH pin select (OFF=Alt)
    #pragma config FMIIEN       = OFF                               // MII/RMII select (OFF=RMII)

    #pragma config BOOTISA  = MIPS32

    //*    USB Settings
    #pragma config FUSBIDIO     = OFF                               // USBID pin control

    #pragma config DMTCNT       = 0

    #pragma config PGL1WAY  = OFF             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
    #pragma config PMDL1WAY = OFF            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
    #pragma config IOL1WAY  = OFF            // Peripheral Pin Select Configuration (Allow only one reconfiguration)
    #pragma config DMTINTV  = WIN_127_128     // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
    #pragma config EJTAGBEN = NORMAL

#endif

    #define CAPABILITIES    (blCapBootLED | blCapUARTInterface |  blCapVirtualProgramButton | blCapDownloadLED | blCapAutoResetListening | CAPCOMMON)

    #define LISTEN_BEFORE_LOAD 3000
    // BTN / LED sense
    #define LedOn       High
    #define BntOn       Low

    // Boot LED 1
    #define BLedLat     E
    #define BLedBit     3
    
    // Download LED 2
    #define DLedLat     E
    #define DLedBit     4
    

    // Virtual program button
    #define VPBntLat    G
    #define VPBntBit    12

    // Program button
    #define PBntPort    G
    #define PBntBit     12

    // Other capabilities
    #define BOOTLOADER_UART             1                   // avrdude program UART
    #define BAUDRATE                    115200              // avrdude baudrate
    #define UARTMapRX()                 (U1RXR = 0b0011)    // RPD10 -> U1RX
    #define UARTMapTX()                 (RPD15R = 0b0001)    // RPD15 -> U1TX
    
    #define _CPU_NAME_                  "PIC32MZ2048EFM"
    #define VEND                        vendMicrochip
    #define PROD                        prodMichrochipCuriosityUART
    #define F_CPU                       200000000UL
    #define F_PBUS                      (F_CPU / (PB2DIVbits.PBDIV + 1))

    #define FLASH_BYTES                 0x200000                  // 2MB
    #define FLASH_PAGE_SIZE             0x4000                      // 16K
#endif
