#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a pre- and a post- target defined where you can add customization code.
#
# This makefile implements macros and targets common to all configurations.
#
# NOCDDL


# Building and Cleaning subprojects are done by default, but can be controlled with the SUB
# macro. If SUB=no, subprojects will not be built or cleaned. The following macro
# statements set BUILD_SUB-CONF and CLEAN_SUB-CONF to .build-reqprojects-conf
# and .clean-reqprojects-conf unless SUB has the value 'no'
SUB_no=NO
SUBPROJECTS=${SUB_${SUB}}
BUILD_SUBPROJECTS_=.build-subprojects
BUILD_SUBPROJECTS_NO=
BUILD_SUBPROJECTS=${BUILD_SUBPROJECTS_${SUBPROJECTS}}
CLEAN_SUBPROJECTS_=.clean-subprojects
CLEAN_SUBPROJECTS_NO=
CLEAN_SUBPROJECTS=${CLEAN_SUBPROJECTS_${SUBPROJECTS}}


# Project Name
PROJECTNAME=chipKIT-Bootloaders

# Active Configuration
DEFAULTCONF=MAX32
CONF=${DEFAULTCONF}

# All Configurations
ALLCONFS=MAX32 MX7cK MX7_UART MX7_USB MX7cK_USB_SPLIT_FLASH MX4cK MX4_UART MX4_USB MX4_SD_USB Uno32 MX3cK_128 MX3cK_512 uC32 MX2_MINI_USB MX1_EXAMPLE_UART 


# build
.build-impl: .build-pre
	${MAKE} -f nbproject/Makefile-${CONF}.mk SUBPROJECTS=${SUBPROJECTS} .build-conf


# clean
.clean-impl: .clean-pre
	${MAKE} -f nbproject/Makefile-${CONF}.mk SUBPROJECTS=${SUBPROJECTS} .clean-conf

# clobber
.clobber-impl: .clobber-pre .depcheck-impl
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MAX32 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7cK clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7_UART clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7_USB clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7cK_USB_SPLIT_FLASH clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4cK clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_UART clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_USB clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_SD_USB clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Uno32 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX3cK_128 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX3cK_512 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=uC32 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX2_MINI_USB clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX1_EXAMPLE_UART clean



# all
.all-impl: .all-pre .depcheck-impl
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MAX32 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7cK build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7_UART build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7_USB build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX7cK_USB_SPLIT_FLASH build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4cK build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_UART build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_USB build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX4_SD_USB build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Uno32 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX3cK_128 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX3cK_512 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=uC32 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX2_MINI_USB build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MX1_EXAMPLE_UART build



# dependency checking support
.depcheck-impl:
#	@echo "# This code depends on make tool being used" >.dep.inc
#	@if [ -n "${MAKE_VERSION}" ]; then \
#	    echo "DEPFILES=\$$(wildcard \$$(addsuffix .d, \$${OBJECTFILES}))" >>.dep.inc; \
#	    echo "ifneq (\$${DEPFILES},)" >>.dep.inc; \
#	    echo "include \$${DEPFILES}" >>.dep.inc; \
#	    echo "endif" >>.dep.inc; \
#	else \
#	    echo ".KEEP_STATE:" >>.dep.inc; \
#	    echo ".KEEP_STATE_FILE:.make.state.\$${CONF}" >>.dep.inc; \
#	fi
