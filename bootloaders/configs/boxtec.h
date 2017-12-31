#define     prodHK32Bot                 0x0001

#if defined(_BOARD_BOXTEC_HK32BOT_)
#define _CONFIG_VALID_

#if defined(PUT_CONFIG_BITS_HERE)

    //* Oscillator Settings
    #pragma config FNOSC    = PRIPLL                                // Oscillator selection
    #pragma config POSCMOD  = HS                                    // Primary oscillator mode
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

    #define CAPABILITIES    ( blCapUSBSerialNumber | blCapSplitFlashBootloader | blCapUSBInterface | blCapProgramButton | blCapVirtualProgramButton | CAPCOMMON)

    // BTN / LED sense
    #define BntOn       Low

    #define USBManufacturerLen 18
    #define USBManufacturer 'B',0,'o',0,'x',0,'t',0,'e',0,'c',0,'.',0,'c',0,'h',0
    #define USBProductLen 32
    #define USBProduct 'H',0,'e',0,'l',0,'v',0,'e',0,'K',0,'i',0,'t',0,'3',0,'2',0,' ',0,'R',0,'o',0,'b',0,'o',0,'t',0


    // Virtual program button
    #define VPBntLat    A
    #define VPBntBit    8

    // Program button
    #define PBntPort    A
    #define PBntBit     8
//    #define PBntPu      High

    #define _CPU_NAME_                  "32MX270F256D"
    #define VEND                        vendBoxtec
    #define PROD                        prodHK32Bot
    #define F_CPU                       40000000UL
    #define F_PBUS                      F_CPU

    #define FLASH_BYTES                 (0x40000-0x1000)		    // Leave room 4 pages (for bootloader!)
    #define FLASH_PAGE_SIZE             1024                                // In bytes
#endif

