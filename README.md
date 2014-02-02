PIC32-avrdude-bootloader
========================

The 'new' bootloader for MPIDE/chipKIT PIC32 boards

This bootloader is buildable for all currently available official chipKIT boards (UNO32, MAX32, uC32) as well
as many "3rd-party" boards (meaning other boards that either happen to work with MPIDE or were designed that way, but
not by Digilent) like the UBW32 and Fubarino boards.

The bootloader codebase supports two methods of bootloading - over UART (async serial) or USB CDC-ACM (virtual serial).
These two methods are mutually exclusive in the current bootloader code - for a given board, you build the bootloader
for EITHER serial OR USB, but not both. This decission is made by which files are included in the build, and the #define
CAPIBILITIES in the BoardConfig.h file.

There is a separate project and workspace for each board for MPLAB 8 (no longer maintained), and a single project 
and multiple build targets for MPLAB X. To build the code requires eiher MPLAB 8 or MPLAB X and the XC32 v1.20 (or
higher) compiler. Note that the full size optomizations are needed for this bootloader, so the free XC32 won't work.

IMPORTANT NOTE: While the majority of this code was written and tested by Keith Vogel of Digilent Inc., this software
is NOT a product of Digilent Inc. and Digilent will provide no suport for it. They have gracefully contributed this 
code as open source code to the MPIDE community, and it is now being maintined and supported purely through the ChipKIT
forums (http://www.chipkit.org/forum/index.php) and the GetHub repo site (https://github.com/organizations/chipKIT32) for
code updates and issue tracking. This means that the official bootloader HEX file for a board purchased from Digilent
is NOT contained here. If you want the official HEX file for the bootloader for your Digilent board, you should go to
Digilent's website and download it from there. You can of course also use the bootloader HEX files from this codebase,
but they are not official Digilent bootloaders.

The BoardConfig.h file contains all of the board-speciffic information (what capibilities the board has, what pins
the LEDs and buttons (if any) are on, what the config bits are, etc.).

