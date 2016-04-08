
BINPREFIX=xc32-

CC=${BINPREFIX}gcc
CXX=${BINPREFIX}g++
LD=${BINPREFIX}ld
AS=${BINPREFIX}as
BIN2HEX=${BINPREFIX}bin2hex

BOARDS=$(shell grep '^BIN_' Makefile | cut -f2 -d'_' | cut -f1 -d'=' | xargs echo)

# 4D configurations

BIN_4d-picadillo=PICADILLO_35T
OBJ_4d-picadillo=main.o 
CRT_4d-picadillo=crt0.S
MCU_4d-picadillo=32MX795F512L
DEF_4d-picadillo=-D_BOARD_PICADILLO_35T_
LKR_4d-picadillo=MX3-7-boot-linkerscript.ld
CFL_4d-picadillo=-mips16

BIN_4d-picaso-replacement=PICASO_REPLACEMENT
OBJ_4d-picaso-replacement=main.o 
CRT_4d-picaso-replacement=crt0.S
MCU_4d-picaso-replacement=32MX370F512H
DEF_4d-picaso-replacement=-D_BOARD_PICASO_REPLACEMENT_
LKR_4d-picaso-replacement=MX3-7-boot-linkerscript.ld
CFL_4d-picaso-replacement=-mips16

# Element 14 configurations

BIN_chipkit-pi=CHIPKIT_PI
OBJ_chipkit-pi=main.o 
CRT_chipkit-pi=crt0.S
MCU_chipkit-pi=32MX250F128B
DEF_chipkit-pi=-D_BOARD_CHIPKIT_PI_
LKR_chipkit-pi=MX1-2-boot-linkerscript.ld
CFL_chipkit-pi=-mips16

BIN_chipkit-pi-usb=CHIPKIT_PI_USB
OBJ_chipkit-pi-usb=main.o cdcacm.o usb.o
CRT_chipkit-pi-usb=crt0.S
MCU_chipkit-pi-usb=32MX250F128B
DEF_chipkit-pi-usb=-D_BOARD_CHIPKIT_PI_USB_
LKR_chipkit-pi-usb=MX1-2-USB-boot-linkerscript.ld
CFL_chipkit-pi-usb=-mips16

# Example configurations

BIN_example-mx1=EXAMPLE_MX1
OBJ_example-mx1=main.o
CRT_example-mx1=crt0.S
MCU_example-mx1=32MX120F032D
DEF_example-mx1=-D_BOARD_EXAMPLE_MX1_
LKR_example-mx1=MX1-2-boot-linkerscript.ld
CFL_example-mx1=-mips16

# Fubarino configurations

BIN_fubarino-sdz=Fubarino_SDZ_UART
OBJ_fubarino-sdz=main.o pic32_init_tlb_ebi_sqi.o pic32_init_cache.o
CRT_fubarino-sdz=crt0MZ.S
MCU_fubarino-sdz=32MZ2048ECG064
DEF_fubarino-sdz=-D_BOARD_FUBARINO_SDZ_UART_
LKR_fubarino-sdz=MZ-boot-linkerscript.ld
CFL_fubarino-sdz=-DPIC32MZ -DINIT_MMU_MZ_FIXED -DINIT_SSX -DINIT_L1_CACHE -DINIT_DSPR2 -DPIC32_SRS_SET_COUNT=8

BIN_fubarino-sd14=FUBARINO_SD_USB
OBJ_fubarino-sd14=main.o usb.o cdcacm.o
CRT_fubarino-sd14=crt0.S
MCU_fubarino-sd14=32MX440F256H
DEF_fubarino-sd14=-D_BOARD_FUBARINO_SD_USB_
LKR_fubarino-sd14=MX3-7-boot-linkerscript.ld
CFL_fubarino-sd14=-mips16

BIN_fubarino-sd15=FUBARINO_SD_512K_USB
OBJ_fubarino-sd15=main.o usb.o cdcacm.o
CRT_fubarino-sd15=crt0.S
MCU_fubarino-sd15=32MX795F512H
DEF_fubarino-sd15=-D_BOARD_FUBARINO_SD_512K_USB_
LKR_fubarino-sd15=MX3-7-boot-linkerscript.ld
CFL_fubarino-sd15=-mips16

BIN_fubarino-mini=FUBARINO_MINI_USB
OBJ_fubarino-mini=main.o usb.o cdcacm.o
CRT_fubarino-mini=crt0.S
MCU_fubarino-mini=32MX250F128D
DEF_fubarino-mini=-D_BOARD_FUBARINO_MINI_USB_
LKR_fubarino-mini=MX1-2-USB-boot-linkerscript.ld
CFL_fubarino-mini=-mips16

BIN_fubarino-mini48=FUBARINO_MINI_USB_48MHZ
OBJ_fubarino-mini48=main.o usb.o cdcacm.o
CRT_fubarino-mini48=crt0.S
MCU_fubarino-mini48=32MX250F128D
DEF_fubarino-mini48=-D_BOARD_FUBARINO_MINI_USB_48MHZ_
LKR_fubarino-mini48=MX1-2-USB-boot-linkerscript.ld
CFL_fubarino-mini48=-mips16

BIN_fubarino-mini50=FUBARINO_MINI_USB_50MHZ
OBJ_fubarino-mini50=main.o usb.o cdcacm.o
CRT_fubarino-mini50=crt0.S
MCU_fubarino-mini50=32MX250F128D
DEF_fubarino-mini50=-D_BOARD_FUBARINO_MINI_USB_50MHZ_
LKR_fubarino-mini50=MX1-2-USB-boot-linkerscript.ld
CFL_fubarino-mini50=-mips16


# Majenko configurations

BIN_majenko-sdxl=MAJENKO_SDXL
OBJ_majenko-sdxl=main.o usb.o cdcacm.o
CRT_majenko-sdxl=crt0.S
MCU_majenko-sdxl=32MX795F512H
DEF_majenko-sdxl=-D_BOARD_MAJENKO_SDXL_
LKR_majenko-sdxl=MX3-7-boot-linkerscript.ld
CFL_majenko-sdxl=-mips16

BIN_majenko-sdau=MAJENKO_SDAU
OBJ_majenko-sdau=main.o usb.o cdcacm.o
CRT_majenko-sdau=crt0.S
MCU_majenko-sdau=32MX470F512H
DEF_majenko-sdau=-D_BOARD_MAJENKO_SDAU_
LKR_majenko-sdau=MX3-7-boot-linkerscript.ld
CFL_majenko-sdau=-mips16

BIN_majenko-sdzl=MAJENKO_SDZL
OBJ_majenko-sdzl=main.o  pic32_init_tlb_ebi_sqi.o pic32_init_cache.o
CRT_majenko-sdzl=crt0MZ.S
MCU_majenko-sdzl=32MZ2048ECG064
DEF_majenko-sdzl=-D_BOARD_MAJENKO_SDZL_
LKR_majenko-sdzl=MZ-boot-linkerscript.ld
CFL_majenko-sdzl=-DPIC32MZ -DINIT_MMU_MZ_FIXED -DINIT_SSX -DINIT_L1_CACHE -DINIT_DSPR2 -DPIC32_SRS_SET_COUNT=8

BIN_majenko-ultranano=MAJENKO_ULTRANANO
OBJ_majenko-ultranano=main.o usb.o cdcacm.o
CRT_majenko-ultranano=crt0.S
MCU_majenko-ultranano=32MX250F128B
DEF_majenko-ultranano=-D_BOARD_MAJENKO_ULTRANANO_
LKR_majenko-ultranano=MX1-2-USB-boot-linkerscript.ld
CFL_majenko-ultranano=-mips16

BIN_majenko-lenny=MAJENKO_LENNY_40MHZ
OBJ_majenko-lenny=main.o usb.o cdcacm.o
CRT_majenko-lenny=crt0.S
MCU_majenko-lenny=32MX270F256B
DEF_majenko-lenny=-D_BOARD_MAJENKO_LENNY_
LKR_majenko-lenny=MX1-2-USB-boot-linkerscript.ld
CFL_majenko-lenny=-mips16

BIN_majenko-lenny48=MAJENKO_LENNY_48MHZ
OBJ_majenko-lenny48=main.o usb.o cdcacm.o
CRT_majenko-lenny48=crt0.S
MCU_majenko-lenny48=32MX270F256B
DEF_majenko-lenny48=-D_BOARD_MAJENKO_LENNY48_
LKR_majenko-lenny48=MX1-2-USB-boot-linkerscript.ld
CFL_majenko-lenny48=-mips16

# Olimex configurations

BIN_olimex-pinguino-micro-uart=Olimex_Pinguino_Micro_UART
OBJ_olimex-pinguino-micro-uart=main.o
CRT_olimex-pinguino-micro-uart=crt0.S
MCU_olimex-pinguino-micro-uart=32MX440F256H
DEF_olimex-pinguino-micro-uart=-D_BOARD_OLIMEX_PINGUINO_MICRO_UART_
LKR_olimex-pinguino-micro-uart=MX3-7-boot-linkerscript.ld
CFL_olimex-pinguino-micro-uart=-mips16

BIN_olimex-pinguino-micro-uart-57600=Olimex_Pinguino_Micro_UART_57600
OBJ_olimex-pinguino-micro-uart-57600=main.o
CRT_olimex-pinguino-micro-uart-57600=crt0.S
MCU_olimex-pinguino-micro-uart-57600=32MX440F256H
DEF_olimex-pinguino-micro-uart-57600=-D_BOARD_OLIMEX_PINGUINO_MICRO_UART_57600_
LKR_olimex-pinguino-micro-uart-57600=MX3-7-boot-linkerscript.ld
CFL_olimex-pinguino-micro-uart-57600=-mips16

BIN_olimex-pinguino=Olimex_PIC32_Pinguino
OBJ_olimex-pinguino=main.o usb.o cdcacm.o
CRT_olimex-pinguino=crt0.S
MCU_olimex-pinguino=32MX440F256H
DEF_olimex-pinguino=-D_BOARD_OLIMEX_PIC32_PINGUINO_
LKR_olimex-pinguino=MX3-7-boot-linkerscript.ld
CFL_olimex-pinguino=-mips16

BIN_olimex-duinomite=OLIMEX_DUINOMITE
OBJ_olimex-duinomite=main.o usb.o cdcacm.o
CRT_olimex-duinomite=crt0.S
MCU_olimex-duinomite=32MX795F512H
DEF_olimex-duinomite=-D_BOARD_OLIMEX_DUINOMITE_
LKR_olimex-duinomite=MX3-7-boot-linkerscript.ld
CFL_olimex-duinomite=-mips16

# OpenBCI Configurations

BIN_openbci-udb32=UDB32_MX2_DIP
OBJ_openbci-udb32=main.o
CRT_openbci-udb32=crt0.S
MCU_openbci-udb32=32MX250F128B
DEF_openbci-udb32=-D_BOARD_UDB32_MX2_DIP_
LKR_openbci-udb32=MX1-2-boot-linkerscript.ld
CFL_openbci-udb32=-mips16

# PONTECH configurations

BIN_pontech-uav100=UAV100
OBJ_pontech-uav100=main.o usb.o cdcacm.o
CRT_pontech-uav100=crt0.S
MCU_pontech-uav100=32MX440F512H
DEF_pontech-uav100=-D_BOARD_UAV100_
LKR_pontech-uav100=MX3-7-boot-linkerscript.ld
CFL_pontech-uav100=-mips16

BIN_pontech-quick240=Quick240
OBJ_pontech-quick240=main.o usb.o cdcacm.o
CRT_pontech-quick240=crt0.S
MCU_pontech-quick240=32MX795F512L
DEF_pontech-quick240=-D_BOARD_QUICK240_
LKR_pontech-quick240=MX3-7-boot-linkerscript.ld
CFL_pontech-quick240=-mips16

# Schmalzhaus configurations

BIN_ubw32-mx460=UBW32_MX460_USB
OBJ_ubw32-mx460=main.o usb.o cdcacm.o
CRT_ubw32-mx460=crt0.S
MCU_ubw32-mx460=32MX460F512L
DEF_ubw32-mx460=-D_BOARD_UBW32_MX460_USB_
LKR_ubw32-mx460=MX3-7-boot-linkerscript.ld
CFL_ubw32-mx460=-mips16

BIN_ubw32-mx795=UBW32_MX795_USB
OBJ_ubw32-mx795=main.o usb.o cdcacm.o
CRT_ubw32-mx795=crt0.S
MCU_ubw32-mx795=32MX795F512L
DEF_ubw32-mx795=-D_BOARD_UBW32_MX795_USB_
LKR_ubw32-mx795=MX3-7-boot-linkerscript.ld
CFL_ubw32-mx795=-mips16

BIN_ebbv3-usb=EBBV3_USB
OBJ_ebbv3-usb=main.o usb.o cdcacm.o
CRT_ebbv3-usb=crt0.S
MCU_ebbv3-usb=32MX250F128D
DEF_ebbv3-usb=-D_BOARD_EBBV3_USB_
LKR_ebbv3-usb=MX1-2-USB-boot-linkerscript.ld
CFL_ebbv3-usb=-mips16

# MikroE configurations

BIN_mikroe-clicker=MIKROE_PIC32MX_CLICKER
OBJ_mikroe-clicker=main.o usb.o cdcacm.o
CRT_mikroe-clicker=crt0.S
MCU_mikroe-clicker=32MX534F064H
DEF_mikroe-clicker=-D_BOARD_MIKROE_PIC32MX_CLICKER_
LKR_mikroe-clicker=MX3-7-boot-linkerscript.ld
CFL_mikroe-clicker=-mips16

CFLAGS=-mprocessor=${MCU_${BOARD}} ${DEF_${BOARD}} ${CFL_${BOARD}} -Os -mno-float -I.
ASFLAGS=-Wa,--gdwarf-2 -mprocessor=${MCU_${BOARD}} ${DEF_${BOARD}} ${CFL_${BOARD}} -Os -mno-float -I.
LDFLAGS=-mprocessor=${MCU_${BOARD}} -nostdlib -nostartfiles ${CFL_${BOARD}} -mno-float -T ${LKR_${BOARD}} -Wl,--gc-sections -ffunction-sections -fdata-sections

# Default target will list all the available targets
all:
	@echo "Specify a board to build for:"
	@for B in ${BOARDS}; do \
		echo "    make " $$B; \
	done


.PHONY: ${BOARDS}

# This is where the actual work is done:

compile: ${BIN_${BOARD}}.hex

install: ${BIN_${BOARD}}.hex
	cp ${BIN_${BOARD}}.hex ../BootloadersCurrent-hex
	
${BIN_${BOARD}}.hex: ${BIN_${BOARD}}.elf
	${BIN2HEX} -a $?

${BIN_${BOARD}}.elf: ${OBJ_${BOARD}}
	${CC} ${LDFLAGS} -o $@ ${CRT_${BOARD}} $?

clean:
	rm -f *.o *.elf

distclean:
	rm -f *.o *.elf *.hex

everything:
	for B in ${BOARDS}; do \
		echo $$B; \
		make -s clean; \
		make -s compile BOARD=$$B; \
		make -s install BOARD=$$B; \
	done
	

${BOARDS}:
	${MAKE} compile BOARD=$@
