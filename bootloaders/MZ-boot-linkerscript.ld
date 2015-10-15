/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-tradlittlemips")
OUTPUT_ARCH(pic32mx)
ENTRY(_reset)
/*
 * Provide for a minimum stack and heap size
 * - _min_stack_size - represents the minimum space that must be made
 *                     available for the stack.  Can be overridden from
 *                     the command line using the linker's --defsym option.
 * - _min_heap_size  - represents the minimum space that must be made
 *                     available for the heap.  Can be overridden from
 *                     the command line using the linker's --defsym option.
 */
EXTERN (_min_stack_size _min_heap_size)
PROVIDE(_min_stack_size = 0x400) ;
PROVIDE(_min_heap_size = 0) ;
/*************************************************************************
 * Processor-specific object file.  Contains SFR definitions.
 *************************************************************************/
INPUT("processor.o")

/*************************************************************************
 * For interrupt vector handling
 *************************************************************************/
PROVIDE(_vector_spacing = 0x00000001);

/*************************************************************************
 * Memory Regions
 *
 * Memory regions without attributes cannot be used for orphaned sections.
 * Only sections specifically assigned to these regions can be allocated
 * into these regions.
 *************************************************************************/
MEMORY
{
    kseg0_program_mem  (rx) : ORIGIN = 0x9fc004b0, LENGTH = 0x0000fa50
    kseg0_boot_mem          : ORIGIN = 0x9fc004b0, LENGTH = 0x00000000
    kseg1_boot_mem          : ORIGIN = 0xbfc00000, LENGTH = 0x00000300
    kseg1_debug_mem         : ORIGIN = 0xbfc00300, LENGTH = 0x000001B0
    kseg1_boot_mem_4B0      : ORIGIN = 0xbfc004b0, LENGTH = 0x0000fa50
    config_BFC0FF40         : ORIGIN = 0xbfc0ff40, LENGTH = 0x00000004
    config_BFC0FF44         : ORIGIN = 0xbfc0ff44, LENGTH = 0x00000004
    config_BFC0FF48         : ORIGIN = 0xbfc0ff48, LENGTH = 0x00000004
    config_BFC0FF4C         : ORIGIN = 0xbfc0ff4c, LENGTH = 0x00000004
    config_BFC0FF50         : ORIGIN = 0xbfc0ff50, LENGTH = 0x00000004
    config_BFC0FF54         : ORIGIN = 0xbfc0ff54, LENGTH = 0x00000004
    config_BFC0FF58         : ORIGIN = 0xbfc0ff58, LENGTH = 0x00000004
    config_BFC0FF5C         : ORIGIN = 0xbfc0ff5c, LENGTH = 0x00000004
    config_BFC0FF60         : ORIGIN = 0xbfc0ff60, LENGTH = 0x00000004
    config_BFC0FF64         : ORIGIN = 0xbfc0ff64, LENGTH = 0x00000004
    config_BFC0FF68         : ORIGIN = 0xbfc0ff68, LENGTH = 0x00000004
    config_BFC0FF6C         : ORIGIN = 0xbfc0ff6c, LENGTH = 0x00000004
    config_BFC0FF70         : ORIGIN = 0xbfc0ff70, LENGTH = 0x00000004
    config_BFC0FF74         : ORIGIN = 0xbfc0ff74, LENGTH = 0x00000004
    config_BFC0FF78         : ORIGIN = 0xbfc0ff78, LENGTH = 0x00000004
    config_BFC0FF7C         : ORIGIN = 0xbfc0ff7c, LENGTH = 0x00000004
    config_BFC0FFC0         : ORIGIN = 0xbfc0ffc0, LENGTH = 0x00000004
    config_BFC0FFC4         : ORIGIN = 0xbfc0ffc4, LENGTH = 0x00000004
    config_BFC0FFC8         : ORIGIN = 0xbfc0ffc8, LENGTH = 0x00000004
    config_BFC0FFCC         : ORIGIN = 0xbfc0ffcc, LENGTH = 0x00000004
    config_BFC0FFD0         : ORIGIN = 0xbfc0ffd0, LENGTH = 0x00000004
    config_BFC0FFD4         : ORIGIN = 0xbfc0ffd4, LENGTH = 0x00000004
    config_BFC0FFD8         : ORIGIN = 0xbfc0ffd8, LENGTH = 0x00000004
    config_BFC0FFDC         : ORIGIN = 0xbfc0ffdc, LENGTH = 0x00000004
    config_BFC0FFE0         : ORIGIN = 0xbfc0ffe0, LENGTH = 0x00000004
    config_BFC0FFE4         : ORIGIN = 0xbfc0ffe4, LENGTH = 0x00000004
    config_BFC0FFE8         : ORIGIN = 0xbfc0ffe8, LENGTH = 0x00000004
    config_BFC0FFEC         : ORIGIN = 0xbfc0ffec, LENGTH = 0x00000004
    config_BFC0FFF0         : ORIGIN = 0xbfc0fff0, LENGTH = 0x00000004
    config_BFC0FFF4         : ORIGIN = 0xbfc0fff4, LENGTH = 0x00000004
    config_BFC0FFF8         : ORIGIN = 0xbfc0fff8, LENGTH = 0x00000004
    config_BFC0FFFC         : ORIGIN = 0xbfc0fffc, LENGTH = 0x00000004
    lowerbootaliaslastpage  : ORIGIN = 0xbfc10000, LENGTH = 0x00004000
    upperbootalias          : ORIGIN = 0xbfc20000, LENGTH = 0x00014000
    boot1                   : ORIGIN = 0xbfc40000, LENGTH = 0x0000ff00
    config_BFC4FF40         : ORIGIN = 0xbfc4ff40, LENGTH = 0x00000004
    config_BFC4FF44         : ORIGIN = 0xbfc4ff44, LENGTH = 0x00000004
    config_BFC4FF48         : ORIGIN = 0xbfc4ff48, LENGTH = 0x00000004
    config_BFC4FF4C         : ORIGIN = 0xbfc4ff4c, LENGTH = 0x00000004
    config_BFC4FF50         : ORIGIN = 0xbfc4ff50, LENGTH = 0x00000004
    config_BFC4FF54         : ORIGIN = 0xbfc4ff54, LENGTH = 0x00000004
    config_BFC4FF58         : ORIGIN = 0xbfc4ff58, LENGTH = 0x00000004
    config_BFC4FF5C         : ORIGIN = 0xbfc4ff5c, LENGTH = 0x00000004
    config_BFC4FF60         : ORIGIN = 0xbfc4ff60, LENGTH = 0x00000004
    config_BFC4FF64         : ORIGIN = 0xbfc4ff64, LENGTH = 0x00000004
    config_BFC4FF68         : ORIGIN = 0xbfc4ff68, LENGTH = 0x00000004
    config_BFC4FF6C         : ORIGIN = 0xbfc4ff6c, LENGTH = 0x00000004
    config_BFC4FF70         : ORIGIN = 0xbfc4ff70, LENGTH = 0x00000004
    config_BFC4FF74         : ORIGIN = 0xbfc4ff74, LENGTH = 0x00000004
    config_BFC4FF78         : ORIGIN = 0xbfc4ff78, LENGTH = 0x00000004
    config_BFC4FF7C         : ORIGIN = 0xbfc4ff7c, LENGTH = 0x00000004
    config_BFC4FFC0         : ORIGIN = 0xbfc4ffc0, LENGTH = 0x00000004
    config_BFC4FFC4         : ORIGIN = 0xbfc4ffc4, LENGTH = 0x00000004
    config_BFC4FFC8         : ORIGIN = 0xbfc4ffc8, LENGTH = 0x00000004
    config_BFC4FFCC         : ORIGIN = 0xbfc4ffcc, LENGTH = 0x00000004
    config_BFC4FFD0         : ORIGIN = 0xbfc4ffd0, LENGTH = 0x00000004
    config_BFC4FFD4         : ORIGIN = 0xbfc4ffd4, LENGTH = 0x00000004
    config_BFC4FFD8         : ORIGIN = 0xbfc4ffd8, LENGTH = 0x00000004
    config_BFC4FFDC         : ORIGIN = 0xbfc4ffdc, LENGTH = 0x00000004
    config_BFC4FFE0         : ORIGIN = 0xbfc4ffe0, LENGTH = 0x00000004
    config_BFC4FFE4         : ORIGIN = 0xbfc4ffe4, LENGTH = 0x00000004
    config_BFC4FFE8         : ORIGIN = 0xbfc4ffe8, LENGTH = 0x00000004
    config_BFC4FFEC         : ORIGIN = 0xbfc4ffec, LENGTH = 0x00000004
    config_BFC4FFF0         : ORIGIN = 0xbfc4fff0, LENGTH = 0x00000004
    config_BFC4FFF4         : ORIGIN = 0xbfc4fff4, LENGTH = 0x00000004
    config_BFC4FFF8         : ORIGIN = 0xbfc4fff8, LENGTH = 0x00000004
    config_BFC4FFFC         : ORIGIN = 0xbfc4fffc, LENGTH = 0x00000004
    boot1lastpage           : ORIGIN = 0xbfc50000, LENGTH = 0x00004000
    config_BFC54000         : ORIGIN = 0xbfc54000, LENGTH = 0x00000004
    config_BFC54004         : ORIGIN = 0xbfc54004, LENGTH = 0x00000004
    config_BFC54008         : ORIGIN = 0xbfc54008, LENGTH = 0x00000004
    config_BFC5400C         : ORIGIN = 0xbfc5400c, LENGTH = 0x00000004
    config_BFC54010         : ORIGIN = 0xbfc54010, LENGTH = 0x00000004
    config_BFC54020         : ORIGIN = 0xbfc54020, LENGTH = 0x00000004
    config_BFC54024         : ORIGIN = 0xbfc54024, LENGTH = 0x00000004
    boot2                   : ORIGIN = 0xbfc60000, LENGTH = 0x0000ff00
    config_BFC6FF40         : ORIGIN = 0xbfc6ff40, LENGTH = 0x00000004
    config_BFC6FF44         : ORIGIN = 0xbfc6ff44, LENGTH = 0x00000004
    config_BFC6FF48         : ORIGIN = 0xbfc6ff48, LENGTH = 0x00000004
    config_BFC6FF4C         : ORIGIN = 0xbfc6ff4c, LENGTH = 0x00000004
    config_BFC6FF50         : ORIGIN = 0xbfc6ff50, LENGTH = 0x00000004
    config_BFC6FF54         : ORIGIN = 0xbfc6ff54, LENGTH = 0x00000004
    config_BFC6FF58         : ORIGIN = 0xbfc6ff58, LENGTH = 0x00000004
    config_BFC6FF5C         : ORIGIN = 0xbfc6ff5c, LENGTH = 0x00000004
    config_BFC6FF60         : ORIGIN = 0xbfc6ff60, LENGTH = 0x00000004
    config_BFC6FF64         : ORIGIN = 0xbfc6ff64, LENGTH = 0x00000004
    config_BFC6FF68         : ORIGIN = 0xbfc6ff68, LENGTH = 0x00000004
    config_BFC6FF6C         : ORIGIN = 0xbfc6ff6c, LENGTH = 0x00000004
    config_BFC6FF70         : ORIGIN = 0xbfc6ff70, LENGTH = 0x00000004
    config_BFC6FF74         : ORIGIN = 0xbfc6ff74, LENGTH = 0x00000004
    config_BFC6FF78         : ORIGIN = 0xbfc6ff78, LENGTH = 0x00000004
    config_BFC6FF7C         : ORIGIN = 0xbfc6ff7c, LENGTH = 0x00000004
    config_BFC6FFC0         : ORIGIN = 0xbfc6ffc0, LENGTH = 0x00000004
    config_BFC6FFC4         : ORIGIN = 0xbfc6ffc4, LENGTH = 0x00000004
    config_BFC6FFC8         : ORIGIN = 0xbfc6ffc8, LENGTH = 0x00000004
    config_BFC6FFCC         : ORIGIN = 0xbfc6ffcc, LENGTH = 0x00000004
    config_BFC6FFD0         : ORIGIN = 0xbfc6ffd0, LENGTH = 0x00000004
    config_BFC6FFD4         : ORIGIN = 0xbfc6ffd4, LENGTH = 0x00000004
    config_BFC6FFD8         : ORIGIN = 0xbfc6ffd8, LENGTH = 0x00000004
    config_BFC6FFDC         : ORIGIN = 0xbfc6ffdc, LENGTH = 0x00000004
    config_BFC6FFE0         : ORIGIN = 0xbfc6ffe0, LENGTH = 0x00000004
    config_BFC6FFE4         : ORIGIN = 0xbfc6ffe4, LENGTH = 0x00000004
    config_BFC6FFE8         : ORIGIN = 0xbfc6ffe8, LENGTH = 0x00000004
    config_BFC6FFEC         : ORIGIN = 0xbfc6ffec, LENGTH = 0x00000004
    config_BFC6FFF0         : ORIGIN = 0xbfc6fff0, LENGTH = 0x00000004
    config_BFC6FFF4         : ORIGIN = 0xbfc6fff4, LENGTH = 0x00000004
    config_BFC6FFF8         : ORIGIN = 0xbfc6fff8, LENGTH = 0x00000004
    config_BFC6FFFC         : ORIGIN = 0xbfc6fffc, LENGTH = 0x00000004
    boot2lastpage           : ORIGIN = 0xbfc70000, LENGTH = 0x00004000
    kseg0_data_mem  (w!x)   : ORIGIN = 0x80000000, LENGTH = 0x00080000
    sfrs                    : ORIGIN = 0xbf800000, LENGTH = 0x00100000
    configsfrs_BFC0FF40     : ORIGIN = 0xbfc0ff40, LENGTH = 0x00000040
    configsfrs_BFC0FFC0     : ORIGIN = 0xbfc0ffc0, LENGTH = 0x00000040
    configsfrs_BFC4FF40     : ORIGIN = 0xbfc4ff40, LENGTH = 0x00000040
    configsfrs_BFC4FFC0     : ORIGIN = 0xbfc4ffc0, LENGTH = 0x00000040
    configsfrs_BFC54000     : ORIGIN = 0xbfc54000, LENGTH = 0x00000014
    configsfrs_BFC54020     : ORIGIN = 0xbfc54020, LENGTH = 0x00000008
    configsfrs_BFC6FF40     : ORIGIN = 0xbfc6ff40, LENGTH = 0x00000040
    configsfrs_BFC6FFC0     : ORIGIN = 0xbfc6ffc0, LENGTH = 0x00000040
    kseg2_ebi_data_mem      : ORIGIN = 0xc0000000, LENGTH = 0x04000000
    kseg2_sqi_data_mem      : ORIGIN = 0xd0000000, LENGTH = 0x04000000
    kseg3_ebi_data_mem      : ORIGIN = 0xe0000000, LENGTH = 0x04000000
    kseg3_sqi_data_mem      : ORIGIN = 0xf0000000, LENGTH = 0x04000000
}


/*************************************************************************
 * Memory Address Equates
 *************************************************************************/
_ebase_address  			= 0x9d000000;
_RESET_ADDR             	= 0xbfc00000;
/* _DBG_EXCPT_ADDR         	= 0xbfc00480; */
/* _DBG_CODE_ADDR 				= ORIGIN(debug_exec_mem); */
_RAM_SKIP_SIZE				= 0x600;

/* these are not used */
/* _BEV_EXCPT_ADDR             = 0xbfc00380; */
/* _GEN_EXCPT_ADDR             = (_ebase_address + 0x180); */
/* _CACHE_ERR_EXCPT_ADDR       = (_ebase_address + 0x100); */
/* _SIMPLE_TLB_REFILL_EXCPT_ADDR = (_ebase_address + 0x0); */
/* end of not used */

SECTIONS
{
    .config_BFC0FF40 : {
     KEEP(*(.config_BFC0FF40))
     } > config_BFC0FF40

    .config_BFC0FF44 : {
     KEEP(*(.config_BFC0FF44))
     } > config_BFC0FF44

    .config_BFC0FF48 : {
     KEEP(*(.config_BFC0FF48))
     } > config_BFC0FF48

    .config_BFC0FF4C : {
     KEEP(*(.config_BFC0FF4C))
     } > config_BFC0FF4C

    .config_BFC0FF50 : {
     KEEP(*(.config_BFC0FF50))
     } > config_BFC0FF50

    .config_BFC0FF54 : {
     KEEP(*(.config_BFC0FF54))
     } > config_BFC0FF54

    .config_BFC0FF58 : {
     KEEP(*(.config_BFC0FF58))
     } > config_BFC0FF58

    .config_BFC0FF5C : {
     KEEP(*(.config_BFC0FF5C))
     } > config_BFC0FF5C

    .config_BFC0FF60 : {
     KEEP(*(.config_BFC0FF60))
     } > config_BFC0FF60

    .config_BFC0FF64 : {
     KEEP(*(.config_BFC0FF64))
     } > config_BFC0FF64

    .config_BFC0FF68 : {
     KEEP(*(.config_BFC0FF68))
     } > config_BFC0FF68

    .config_BFC0FF6C : {
     KEEP(*(.config_BFC0FF6C))
     } > config_BFC0FF6C

    .config_BFC0FF70 : {
     KEEP(*(.config_BFC0FF70))
     } > config_BFC0FF70

    .config_BFC0FF74 : {
     KEEP(*(.config_BFC0FF74))
     } > config_BFC0FF74

    .config_BFC0FF78 : {
     KEEP(*(.config_BFC0FF78))
     } > config_BFC0FF78

    .config_BFC0FF7C : {
     KEEP(*(.config_BFC0FF7C))
     } > config_BFC0FF7C

    .config_BFC0FFC0 : {
     KEEP(*(.config_BFC0FFC0))
     } > config_BFC0FFC0

    .config_BFC0FFC4 : {
     KEEP(*(.config_BFC0FFC4))
     } > config_BFC0FFC4

    .config_BFC0FFC8 : {
     KEEP(*(.config_BFC0FFC8))
     } > config_BFC0FFC8

    .config_BFC0FFCC : {
     KEEP(*(.config_BFC0FFCC))
     } > config_BFC0FFCC

    .config_BFC0FFD0 : {
     KEEP(*(.config_BFC0FFD0))
     } > config_BFC0FFD0

    .config_BFC0FFD4 : {
     KEEP(*(.config_BFC0FFD4))
     } > config_BFC0FFD4

    .config_BFC0FFD8 : {
     KEEP(*(.config_BFC0FFD8))
     } > config_BFC0FFD8

    .config_BFC0FFDC : {
     KEEP(*(.config_BFC0FFDC))
     } > config_BFC0FFDC

    .config_BFC0FFE0 : {
     KEEP(*(.config_BFC0FFE0))
     } > config_BFC0FFE0

    .config_BFC0FFE4 : {
     KEEP(*(.config_BFC0FFE4))
     } > config_BFC0FFE4

    .config_BFC0FFE8 : {
     KEEP(*(.config_BFC0FFE8))
     } > config_BFC0FFE8

    .config_BFC0FFEC : {
     KEEP(*(.config_BFC0FFEC))
     } > config_BFC0FFEC

    .config_BFC0FFF0 : {
     KEEP(*(.config_BFC0FFF0))
     } > config_BFC0FFF0

    .config_BFC0FFF4 : {
     KEEP(*(.config_BFC0FFF4))
     } > config_BFC0FFF4

    .config_BFC0FFF8 : {
     KEEP(*(.config_BFC0FFF8))
     } > config_BFC0FFF8

    .config_BFC0FFFC : {
     KEEP(*(.config_BFC0FFFC))
     } > config_BFC0FFFC

    .config_BFC4FF40 : {
     KEEP(*(.config_BFC4FF40))
     } > config_BFC4FF40

    .config_BFC4FF44 : {
     KEEP(*(.config_BFC4FF44))
     } > config_BFC4FF44

    .config_BFC4FF48 : {
     KEEP(*(.config_BFC4FF48))
     } > config_BFC4FF48

    .config_BFC4FF4C : {
     KEEP(*(.config_BFC4FF4C))
     } > config_BFC4FF4C

    .config_BFC4FF50 : {
     KEEP(*(.config_BFC4FF50))
     } > config_BFC4FF50

    .config_BFC4FF54 : {
     KEEP(*(.config_BFC4FF54))
     } > config_BFC4FF54

    .config_BFC4FF58 : {
     KEEP(*(.config_BFC4FF58))
     } > config_BFC4FF58

    .config_BFC4FF5C : {
     KEEP(*(.config_BFC4FF5C))
     } > config_BFC4FF5C

    .config_BFC4FF60 : {
     KEEP(*(.config_BFC4FF60))
     } > config_BFC4FF60

    .config_BFC4FF64 : {
     KEEP(*(.config_BFC4FF64))
     } > config_BFC4FF64

    .config_BFC4FF68 : {
     KEEP(*(.config_BFC4FF68))
     } > config_BFC4FF68

    .config_BFC4FF6C : {
     KEEP(*(.config_BFC4FF6C))
     } > config_BFC4FF6C

    .config_BFC4FF70 : {
     KEEP(*(.config_BFC4FF70))
     } > config_BFC4FF70

    .config_BFC4FF74 : {
     KEEP(*(.config_BFC4FF74))
     } > config_BFC4FF74

    .config_BFC4FF78 : {
     KEEP(*(.config_BFC4FF78))
     } > config_BFC4FF78

    .config_BFC4FF7C : {
     KEEP(*(.config_BFC4FF7C))
     } > config_BFC4FF7C

    .config_BFC4FFC0 : {
     KEEP(*(.config_BFC4FFC0))
     } > config_BFC4FFC0

    .config_BFC4FFC4 : {
     KEEP(*(.config_BFC4FFC4))
     } > config_BFC4FFC4

    .config_BFC4FFC8 : {
     KEEP(*(.config_BFC4FFC8))
     } > config_BFC4FFC8

    .config_BFC4FFCC : {
     KEEP(*(.config_BFC4FFCC))
     } > config_BFC4FFCC

    .config_BFC4FFD0 : {
     KEEP(*(.config_BFC4FFD0))
     } > config_BFC4FFD0

    .config_BFC4FFD4 : {
     KEEP(*(.config_BFC4FFD4))
     } > config_BFC4FFD4

    .config_BFC4FFD8 : {
     KEEP(*(.config_BFC4FFD8))
     } > config_BFC4FFD8

    .config_BFC4FFDC : {
     KEEP(*(.config_BFC4FFDC))
     } > config_BFC4FFDC

    .config_BFC4FFE0 : {
     KEEP(*(.config_BFC4FFE0))
     } > config_BFC4FFE0

    .config_BFC4FFE4 : {
     KEEP(*(.config_BFC4FFE4))
     } > config_BFC4FFE4

    .config_BFC4FFE8 : {
     KEEP(*(.config_BFC4FFE8))
     } > config_BFC4FFE8

    .config_BFC4FFEC : {
     KEEP(*(.config_BFC4FFEC))
     } > config_BFC4FFEC

    .config_BFC4FFF0 : {
     KEEP(*(.config_BFC4FFF0))
     } > config_BFC4FFF0

    .config_BFC4FFF4 : {
     KEEP(*(.config_BFC4FFF4))
     } > config_BFC4FFF4

    .config_BFC4FFF8 : {
     KEEP(*(.config_BFC4FFF8))
     } > config_BFC4FFF8

    .config_BFC4FFFC : {
     KEEP(*(.config_BFC4FFFC))
     } > config_BFC4FFFC

    .config_BFC54000 : {
     KEEP(*(.config_BFC54000))
     } > config_BFC54000

    .config_BFC54004 : {
     KEEP(*(.config_BFC54004))
     } > config_BFC54004

    .config_BFC54008 : {
     KEEP(*(.config_BFC54008))
     } > config_BFC54008

    .config_BFC5400C : {
     KEEP(*(.config_BFC5400C))
     } > config_BFC5400C

    .config_BFC54010 : {
     KEEP(*(.config_BFC54010))
     } > config_BFC54010

    .config_BFC54020 : {
     KEEP(*(.config_BFC54020))
     } > config_BFC54020

    .config_BFC54024 : {
     KEEP(*(.config_BFC54024))
     } > config_BFC54024

    .config_BFC6FF40 : {
     KEEP(*(.config_BFC6FF40))
     } > config_BFC6FF40

    .config_BFC6FF44 : {
     KEEP(*(.config_BFC6FF44))
     } > config_BFC6FF44

    .config_BFC6FF48 : {
     KEEP(*(.config_BFC6FF48))
     } > config_BFC6FF48

    .config_BFC6FF4C : {
     KEEP(*(.config_BFC6FF4C))
     } > config_BFC6FF4C

    .config_BFC6FF50 : {
     KEEP(*(.config_BFC6FF50))
     } > config_BFC6FF50

    .config_BFC6FF54 : {
     KEEP(*(.config_BFC6FF54))
     } > config_BFC6FF54

    .config_BFC6FF58 : {
     KEEP(*(.config_BFC6FF58))
     } > config_BFC6FF58

    .config_BFC6FF5C : {
     KEEP(*(.config_BFC6FF5C))
     } > config_BFC6FF5C

    .config_BFC6FF60 : {
     KEEP(*(.config_BFC6FF60))
     } > config_BFC6FF60

    .config_BFC6FF64 : {
     KEEP(*(.config_BFC6FF64))
     } > config_BFC6FF64

    .config_BFC6FF68 : {
     KEEP(*(.config_BFC6FF68))
     } > config_BFC6FF68

    .config_BFC6FF6C : {
     KEEP(*(.config_BFC6FF6C))
     } > config_BFC6FF6C

    .config_BFC6FF70 : {
     KEEP(*(.config_BFC6FF70))
     } > config_BFC6FF70

    .config_BFC6FF74 : {
     KEEP(*(.config_BFC6FF74))
     } > config_BFC6FF74

    .config_BFC6FF78 : {
     KEEP(*(.config_BFC6FF78))
     } > config_BFC6FF78

    .config_BFC6FF7C : {
     KEEP(*(.config_BFC6FF7C))
     } > config_BFC6FF7C

    .config_BFC6FFC0 : {
     KEEP(*(.config_BFC6FFC0))
     } > config_BFC6FFC0

    .config_BFC6FFC4 : {
     KEEP(*(.config_BFC6FFC4))
     } > config_BFC6FFC4

    .config_BFC6FFC8 : {
     KEEP(*(.config_BFC6FFC8))
     } > config_BFC6FFC8

    .config_BFC6FFCC : {
     KEEP(*(.config_BFC6FFCC))
     } > config_BFC6FFCC

    .config_BFC6FFD0 : {
     KEEP(*(.config_BFC6FFD0))
     } > config_BFC6FFD0

    .config_BFC6FFD4 : {
     KEEP(*(.config_BFC6FFD4))
     } > config_BFC6FFD4

    .config_BFC6FFD8 : {
     KEEP(*(.config_BFC6FFD8))
     } > config_BFC6FFD8

    .config_BFC6FFDC : {
     KEEP(*(.config_BFC6FFDC))
     } > config_BFC6FFDC

    .config_BFC6FFE0 : {
     KEEP(*(.config_BFC6FFE0))
     } > config_BFC6FFE0

    .config_BFC6FFE4 : {
     KEEP(*(.config_BFC6FFE4))
     } > config_BFC6FFE4

    .config_BFC6FFE8 : {
     KEEP(*(.config_BFC6FFE8))
     } > config_BFC6FFE8

    .config_BFC6FFEC : {
     KEEP(*(.config_BFC6FFEC))
     } > config_BFC6FFEC

    .config_BFC6FFF0 : {
     KEEP(*(.config_BFC6FFF0))
     } > config_BFC6FFF0

    .config_BFC6FFF4 : {
     KEEP(*(.config_BFC6FFF4))
     } > config_BFC6FFF4

    .config_BFC6FFF8 : {
     KEEP(*(.config_BFC6FFF8))
     } > config_BFC6FFF8

    .config_BFC6FFFC : {
     KEEP(*(.config_BFC6FFFC))
     } > config_BFC6FFFC
}

SECTIONS
{
  /* Boot Sections */
  .reset _RESET_ADDR :
  {
    KEEP(*(.reset))
/*    KEEP(*(.startup)) */
    KEEP(*(.reset.startup)) 
  } > kseg1_boot_mem
/*
  .bev_excpt _BEV_EXCPT_ADDR :
  {
    KEEP(*(.bev_handler))
  } > kseg1_boot_mem
*/
  /*  Starting with C32 v2.00, the startup code is in the .reset.startup section.
   *  Keep this here for backwards compatibility.
   */
/*
  .startup ORIGIN(kseg0_boot_mem) :
  {
    KEEP(*(.startup))
  } > kseg0_program_mem
*/ 
  /* Code Sections - Note that input sections *(.text) and *(.text.*)
  ** are not mapped here. Starting in C32 v2.00, the best-fit allocator
  ** locates them, so that .text may flow around absolute sections
  ** as needed.
  */
  .text :
  {
    *(.stub .gnu.linkonce.t.*)
    KEEP (*(.text.*personality*))
    *(.mips16.fn.*)
    *(.mips16.call.*)
    *(.gnu.warning)
  } >kseg0_program_mem
  /* Read-only sections */
  .rodata   :
  {
    *( /* .rodata */  .rodata.* .gnu.linkonce.r.*)
    *(.rodata1)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /*
   * Small initialized constant global and static data can be placed in the
   * .sdata2 section.  This is different from .sdata, which contains small
   * initialized non-constant global and static data.
   */
  .sdata2 ALIGN(4)   :
  {
    *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /*
   * Uninitialized constant global and static data (i.e., variables which will
   * always be zero).  Again, this is different from .sbss, which contains
   * small non-initialized, non-constant global and static data.
   */
  .sbss2 ALIGN(4)   :
  {
    *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .eh_frame_hdr : { *(.eh_frame_hdr) }
  .eh_frame       : ONLY_IF_RO { KEEP (*(.eh_frame)) }

 
   /*
	* We always need to keep this space, if it is not
	* used by the debugger, it is used by shared RAM
	* with the loading sketch.	
	*/	
  .dbg_data ORIGIN(kseg0_data_mem) :
  {
   _skip_ram_space_addr = . ;
     . += 0x380;
  } >kseg0_data_mem

   /*
	* Now we need to reserve the max shared ram
	*/	
  .skip_ram_space :
  {
    . += (_RAM_SKIP_SIZE - SIZEOF(.dbg_data));
	_skip_ram_space_end_adder = .;
  } >kseg0_data_mem

  .eh_frame       : ONLY_IF_RW { KEEP (*(.eh_frame)) }
  . = .;
   _gp = ALIGN(16) + 0x7ff0;

  .got ALIGN(4)   :
  {
     *(.got.plt) *(.got)
  } >kseg0_data_mem
  /*
   * Note that "small" data sections are still mapped in the linker
   * script. This ensures that they are grouped together for
   * gp-relative addressing. Absolute sections are allocated after
   * the "small" data sections so small data cannot flow around them.
   */
  /*
   * We want the small data sections together, so single-instruction offsets
   * can access them all, and initialized data all before uninitialized, so
   * we can shorten the on-disk segment size.
   */
  .sdata ALIGN(4) /*   */ :
  {
    _sdata_begin = . ;
    *(.sdata .sdata.* .gnu.linkonce.s.*)
    _sdata_end = . ;
  } >kseg0_data_mem
  .lit8           :
  {
    *(.lit8)
  } >kseg0_data_mem
  .lit4           :
  {
    *(.lit4)
  } >kseg0_data_mem
  . = ALIGN (4) ;
  _data_end = . ;
  _bss_begin = . ;
  .sbss ALIGN(4)   :
  {
    _sbss_begin = . ;
    *(.dynsbss)
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
    _sbss_end = . ;
  } >kseg0_data_mem
  /*
   * Note that input sections named .data* are no longer mapped here.
   * Starting in C32 v2.00, the best-fit allocator locates them, so
   * that they may flow around absolute sections as needed.
   */
  /*
   * Align here to ensure that the .bss section occupies space up to
   * _end.  Align after .bss to ensure correct alignment even if the
   * .bss section disappears because there are no input sections.
   *
   * Note that input sections named .bss* are no longer mapped here.
   * Starting in C32 v2.00, the best-fit allocator locates them, so
   * that they may flow around absolute sections as needed.
   *
   */
  .bss   :
  {
    *(.dynbss)
    *(COMMON)
    . = ALIGN(4) ;
  } >kseg0_data_mem
  . = ALIGN(4) ;
  _end = . ;
  _bss_end = . ;
 /* Starting with C32 v2.00, the heap and stack are dynamically
   * allocated by the linker.
   */
  /*
   * RAM functions go at the end of our stack and heap allocation.
   * Alignment of 2K required by the boundary register (BMXDKPBA).
   *
   * RAM functions are now allocated by the linker. The linker generates
   * _ramfunc_begin and _bmxdkpba_address symbols depending on the
   * location of RAM functions.
   */
  _bmxdudba_address = LENGTH(kseg0_data_mem) ;
  _bmxdupba_address = LENGTH(kseg0_data_mem) ;
    /* The .pdr section belongs in the absolute section */
    /DISCARD/ : { *(.pdr) }
    /* We don't load .reginfo onto the target, so don't locate it
     * in real memory
     */
    /DISCARD/ : { *(.reginfo) }
  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  /DISCARD/ : { *(.rel.dyn) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) *(.discard) }
}
SECTIONS
{
  /DISCARD/ : { *(._debug_exception) }
}
