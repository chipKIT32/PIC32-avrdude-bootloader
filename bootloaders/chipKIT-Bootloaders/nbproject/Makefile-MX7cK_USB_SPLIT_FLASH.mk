#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-MX7cK_USB_SPLIT_FLASH.mk)" "nbproject/Makefile-local-MX7cK_USB_SPLIT_FLASH.mk"
include nbproject/Makefile-local-MX7cK_USB_SPLIT_FLASH.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=MX7cK_USB_SPLIT_FLASH
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../main.c ../crt0.S ../cdcacm.c ../usb.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/crt0.o ${OBJECTDIR}/_ext/1472/cdcacm.o ${OBJECTDIR}/_ext/1472/usb.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/crt0.o.d ${OBJECTDIR}/_ext/1472/cdcacm.o.d ${OBJECTDIR}/_ext/1472/usb.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/crt0.o ${OBJECTDIR}/_ext/1472/cdcacm.o ${OBJECTDIR}/_ext/1472/usb.o

# Source Files
SOURCEFILES=../main.c ../crt0.S ../cdcacm.c ../usb.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-MX7cK_USB_SPLIT_FLASH.mk dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=,--script="..\MX3-7-split-boot-linkerscript.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/crt0.o: ../crt0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o.ok ${OBJECTDIR}/_ext/1472/crt0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crt0.o.d" "${OBJECTDIR}/_ext/1472/crt0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/crt0.o.d"  -o ${OBJECTDIR}/_ext/1472/crt0.o ../crt0.S  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1472/crt0.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1 -I".."
	
else
${OBJECTDIR}/_ext/1472/crt0.o: ../crt0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o 
	@${RM} ${OBJECTDIR}/_ext/1472/crt0.o.ok ${OBJECTDIR}/_ext/1472/crt0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crt0.o.d" "${OBJECTDIR}/_ext/1472/crt0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/crt0.o.d"  -o ${OBJECTDIR}/_ext/1472/crt0.o ../crt0.S  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1472/crt0.o.asm.d",--gdwarf-2 -I".."
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c   
	
${OBJECTDIR}/_ext/1472/cdcacm.o: ../cdcacm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/cdcacm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/cdcacm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/cdcacm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/cdcacm.o.d" -o ${OBJECTDIR}/_ext/1472/cdcacm.o ../cdcacm.c   
	
${OBJECTDIR}/_ext/1472/usb.o: ../usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/usb.o.d" -o ${OBJECTDIR}/_ext/1472/usb.o ../usb.c   
	
else
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c   
	
${OBJECTDIR}/_ext/1472/cdcacm.o: ../cdcacm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/cdcacm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/cdcacm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/cdcacm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/cdcacm.o.d" -o ${OBJECTDIR}/_ext/1472/cdcacm.o ../cdcacm.c   
	
${OBJECTDIR}/_ext/1472/usb.o: ../usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -mips16 -mno-float -Os -D_BOARD_CEREBOT_32MX7_USB_SPLIT_ -I".." -MMD -MF "${OBJECTDIR}/_ext/1472/usb.o.d" -o ${OBJECTDIR}/_ext/1472/usb.o ../usb.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../MX3-7-split-boot-linkerscript.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -nostdlib -nostartfiles -mips16 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-L"../../../../../../../../Program Files (x86)/Microchip/MPLAB C32 Suite/lib",-L"../../../../../../../../Program Files (x86)/Microchip/MPLAB C32 Suite/pic32mx/lib",-Map="${DISTDIR}/MX7cK.X.${IMAGE_TYPE}.map",-Os
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../MX3-7-split-boot-linkerscript.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -nostdlib -nostartfiles -mips16 -mno-float -o dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-L"../../../../../../../../Program Files (x86)/Microchip/MPLAB C32 Suite/lib",-L"../../../../../../../../Program Files (x86)/Microchip/MPLAB C32 Suite/pic32mx/lib",-Map="${DISTDIR}/MX7cK.X.${IMAGE_TYPE}.map",-Os
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/chipKIT-Bootloaders.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/MX7cK_USB_SPLIT_FLASH
	${RM} -r dist/MX7cK_USB_SPLIT_FLASH

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
