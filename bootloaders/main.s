	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 0

 # -G value = 8, Arch = pic32mx, ISA = 33
 # GNU C (Microchip Technology) version 4.5.1 MPLAB C Compiler for PIC32 MCUs v2.02-20111116 (pic32mx)
 #	compiled by GNU C version 4.4.2, GMP version 4.3.2, MPFR version 2.4.2, MPC version 0.8.1
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -fpreprocessed main.i
 # -mconfig-data-dir=c:/users/keithv.keithsofficepc/documents/digitent/bootloaders/chipkit-bootloader-projects/mplab c32 suite/bin/../lib/gcc/pic32mx/4.5.1/../../../../pic32mx/lib/./proc/32MX120F032D
 # -fno-builtin-fabs -fno-builtin-fabsf -fverbose-asm
 # -mprocessor=32MX120F032D -mips16 -mno-float -mips32r2 -mabi=32
 # -auxbase-strip main.o -g -Os
 # options enabled:  -falign-loops -fargument-alias -fauto-inc-dec
 # -fbranch-count-reg -fcaller-saves -fcommon -fcprop-registers
 # -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdelayed-branch
 # -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
 # -feliminate-unused-debug-types -fexpensive-optimizations
 # -fforward-propagate -ffunction-cse -fgcse -fgcse-lm
 # -fguess-branch-probability -fident -fif-conversion -fif-conversion2
 # -findirect-inlining -finline-functions-called-once -fipa-cp
 # -fipa-pure-const -fipa-reference -fipa-sra -fira-share-save-slots
 # -fira-share-spill-slots -fivopts -fkeep-static-consts
 # -fleading-underscore -fmath-errno -fmerge-constants
 # -fmerge-debug-strings -fomit-frame-pointer -foptimize-register-move
 # -foptimize-sibling-calls -fpcc-struct-return -fpeephole -fpeephole2
 # -fregmove -freorder-blocks -freorder-functions -frerun-cse-after-loop
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-insns2 -fshow-column -fsigned-zeros
 # -fsplit-ivs-in-unroller -fsplit-wide-types -fstrict-aliasing
 # -fstrict-overflow -fstrict-volatile-bitfields -fthread-jumps
 # -ftoplevel-reorder -ftrapping-math -ftree-builtin-call-dce -ftree-ccp
 # -ftree-ch -ftree-copy-prop -ftree-copyrename -ftree-cselim -ftree-dce
 # -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
 # -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
 # -ftree-parallelize-loops= -ftree-phiprop -ftree-pta -ftree-reassoc
 # -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize -ftree-sra
 # -ftree-switch-conversion -ftree-ter -ftree-vect-loop-version -ftree-vrp
 # -funit-at-a-time -fvar-tracking -fvar-tracking-assignments -fverbose-asm
 # -fzero-initialized-in-bss -mbranch-likely -mcheck-zero-division
 # -mdivide-traps -mel -membedded-data -mexplicit-relocs -mextern-sdata
 # -mfused-madd -mgpopt -minterlink-mips16 -mips16 -mjals -mlocal-sdata
 # -mlong32 -mmemcpy -mno-float -mshared -msoft-float -msplit-addresses

	.section	.debug_abbrev,info
.Ldebug_abbrev0:
	.section	.debug_info,info
.Ldebug_info0:
	.section	.debug_line,info
.Ldebug_line0:
	.section	.text,code
.Ltext0:
 # Compiler executable checksum: 5f79c4fe9aea52d9a14c610405612b0e

	.cfi_sections	.debug_frame
	.align	2
.LFB12 = .
	.file 1 "main.c"
	.loc 1 268 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	avrbl_print
	.type	avrbl_print, @function
avrbl_print:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL0 = .
	.file 2 "serial.h"
	.loc 2 42 0
	li	$2,0	 # i,
	b	.L2	 #
.LVL1 = .
.L3:
.LBB38 = .
.LBB39 = .
	.loc 2 43 0
	lw	$3,.L4	 # tmp254,
	lw	$3,0($3)	 # tmp255,
	li	$6,255	 # tmp256,
	addiu	$6,1	 # tmp256,
	and	$3,$6	 # tmp255, tmp256
	beqz	$3,.L3	 #, tmp255,
	.loc 1 267 0
	addu	$3,$4,$2	 # tmp257, buffer, i
	.loc 2 47 0
	lbu	$6,0($3)	 # U1TXREG.68,
	lw	$3,.L5	 # tmp258,
	.loc 2 42 0
	addiu	$2,1	 # i,
.LVL2 = .
	.loc 2 47 0
	sw	$6,0($3)	 # U1TXREG.68, U1TXREG
.LVL3 = .
.L2:
	.loc 2 42 0
	slt	$2,$5	 # i, length
	btnez	.L3	 #,
.LBE39 = .
.LBE38 = .
	.loc 1 270 0
	j	$31
	.align	2	 #
.L4:
	.word	U1STA
.L5:
	.word	U1TXREG
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	avrbl_print
	.cfi_endproc
.LFE12:
	.size	avrbl_print, .-avrbl_print
	.align	2
.LFB15 = .
	.loc 1 574 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	getHeaderStructure
	.type	getHeaderStructure, @function
getHeaderStructure:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL4 = .
	.loc 1 580 0
	lw	$5,.L12	 # tmp230,
	.loc 1 576 0
	addiu	$3,$4,252	 # addr, imageBaseAddr,
.LVL5 = .
	.loc 1 580 0
	addiu	$2,$3,4	 # tmp229, addr,
	sltu	$5,$2	 # tmp230, tmp229
	.loc 1 597 0
	li	$2,0	 # pHeaderInfo,
	.loc 1 580 0
	btnez	.L13	 #,
	.loc 1 582 0
	lw	$3,0($3)	 # addr,* addr
.LVL6 = .
	.loc 1 585 0
	addiu	$6,$3,1	 # tmp232, addr,
	beqz	$6,.L13	 #, tmp232,
	li	$6,3	 # tmp234,
	and	$6,$3	 # tmp233, addr
	bnez	$6,.L13	 #, tmp233,
	addiu	$6,$3,7	 # tmp235, addr,
	addiu	$6,57	 # tmp235,
	sltu	$5,$6	 # tmp230, tmp235
	btnez	.L13	 #,
.LVL7 = .
	.loc 1 589 0
	lhu	$2,30($3)	 # tmp239,
	lhu	$5,28($3)	 # tmp238,
	sll	$2,$2,8	 # tmp242, tmp239,
	sll	$2,$2,8	 # tmp242, tmp242,
	or	$2,$5	 # tmp242, tmp238
	xor	$2,$4	 # tmp243, imageBaseAddr
	.loc 1 597 0
	sltu	$2,1	 # tmp243
	move	$2,$24	 # tmp246,
	neg	$2,$2	 # tmp247, tmp246
	and	$2,$3	 # pHeaderInfo, addr
.LVL8 = .
.L13:
	.loc 1 598 0
	j	$31
	.align	2	 #
.L12:
	.word	-1660911616
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	getHeaderStructure
	.cfi_endproc
.LFE15:
	.size	getHeaderStructure, .-getHeaderStructure
	.align	2
.LFB14 = .
	.loc 1 502 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	ExecuteApp
	.type	ExecuteApp, @function
ExecuteApp:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
	save	24,$16,$31
.LCFI0:
	.cfi_def_cfa_offset 24
.L15:
.LBB40 = .
.LBB41 = .
	.file 3 "BoardConfig.h"
	.loc 3 1516 0
	lw	$2,.L23	 # tmp240,
	lw	$3,0($2)	 # tmp241,
	li	$2,255	 # tmp242,
	addiu	$2,1	 # tmp242,
	and	$3,$2	 # tmp241, tmp242
.LBE41 = .
.LBE40 = .
	.loc 1 512 0
	move	$16,$28	 # tmp253,
	.cfi_offset 16, -8
	.cfi_offset 31, -4
.LBB43 = .
.LBB42 = .
	.loc 3 1516 0
	beqz	$3,.L15	 #, tmp241,
	.loc 3 1519 0
	li	$4,0	 # tmp244,
	lw	$3,.L24	 # tmp243,
	sw	$4,0($3)	 # tmp244, U1MODE
.LBE42 = .
.LBE43 = .
.LBB44 = .
.LBB45 = .
	.loc 3 1419 0
	lw	$3,.L25	 # tmp245,
	li	$4,128	 # tmp246,
	sw	$4,0($3)	 # tmp246, LATACLR
	.loc 3 1420 0
	sw	$2,0($3)	 # tmp242, LATACLR
	.loc 3 1423 0
	lw	$3,.L26	 # tmp249,
	sw	$4,0($3)	 # tmp246, TRISASET
.LBE45 = .
.LBE44 = .
	.loc 1 512 0
	lw	$4,%gprel(addrBase)($16)	 #, addrBase
.LBB47 = .
.LBB46 = .
	.loc 3 1424 0
	sw	$2,0($3)	 # tmp242, TRISASET
.LBE46 = .
.LBE47 = .
	.loc 1 512 0
	jal	getHeaderStructure	 #
.LVL9 = .
	beqz	$2,.L16	 #, pHeaderInfo,
	.loc 1 516 0
	lbu	$3,%gprel(fLoaded)($16)	 #, fLoaded
	zeb	$3	 # fLoaded.26
	beqz	$3,.L17	 #, fLoaded.26,
	lhu	$3,22($2)	 # tmp256,
	lhu	$4,20($2)	 # tmp255,
	sll	$3,$3,8	 # tmp260, tmp256,
	sll	$3,$3,8	 # tmp260, tmp260,
	or	$3,$4	 # tmp260, tmp255
	lw	$4,.L27	 # tmp261,
	and	$3,$4	 # tmp260, tmp261
	beqz	$3,.L17	 #, tmp260,
	.loc 1 518 0
	lw	$4,.L28	 #,
	jal	getHeaderStructure	 #
.LVL10 = .
	beqz	$2,.L18	 #, pHeaderInfo,
.L17:
	.loc 1 527 0
	lhu	$3,26($2)	 # tmp269,
	lhu	$4,24($2)	 # tmp268,
	sll	$3,$3,8	 # tmp272, tmp269,
	sll	$3,$3,8	 # tmp272, tmp272,
	or	$3,$4	 # tmp272, tmp268
	sw	$3,%gprel(UserApp)($16)	 # tmp272, UserApp
.L18:
	.loc 1 532 0
	lhu	$3,2($2)	 # tmp274,
	lhu	$4,0($2)	 # tmp273,* pHeaderInfo
	sll	$3,$3,8	 # tmp277, tmp274,
	sll	$3,$3,8	 # tmp277, tmp277,
	or	$3,$4	 # tmp277, tmp273
	sltu	$3,60	 # tmp277,
	btnez	.L16	 #,
	.loc 1 534 0
	lhu	$3,54($2)	 # tmp280,
	lhu	$4,52($2)	 # tmp279,
	sll	$3,$3,8	 # D.8700, tmp280,
	sll	$3,$3,8	 # D.8700, D.8700,
	or	$3,$4	 # D.8700, tmp279
	move	$4,$16	 # _skip_ram_space_end_adder.28, tmp253
	addiu	$4,%gprel(_skip_ram_space_end_adder)	 # _skip_ram_space_end_adder.28,
	addiu	$5,$4,-4	 # tmp284, _skip_ram_space_end_adder.28,
	.loc 1 532 0
	sltu	$5,$3	 # tmp284, D.8700
	btnez	.L16	 #,
.LBB48 = .
	.loc 1 536 0
	lhu	$5,56($2)	 # tmp286,
	lhu	$2,58($2)	 # tmp287,
.LVL11 = .
	sll	$2,$2,8	 # cb, tmp287,
	sll	$2,$2,8	 # cb, cb,
	or	$2,$5	 # cb, tmp286
	sltu	$2,9	 # cb,
	btnez	.L19	 #,
	li	$2,8	 # cb,
.L19:
.LVL12 = .
	.loc 1 539 0
	subu	$4,$4,$3	 # tmp292, _skip_ram_space_end_adder.28, D.8700
	sltu	$4,$2	 # tmp292, cb
	bteqz	.L20	 #,
	move	$2,$4	 # cb, tmp292
.LVL13 = .
.L20:
.LBB49 = .
.LBB50 = .
	.file 4 "util.h"
	.loc 4 17 0
	move	$4,$16	 # stemp, tmp253
.LBE50 = .
.LBE49 = .
	.loc 1 542 0
	sw	$2,%gprel(ramHeader)($16)	 # cb, ramHeader.cbBlRamHeader
.LVL14 = .
.LBB52 = .
.LBB51 = .
	.loc 4 17 0
	addiu	$4,%gprel(ramHeader)	 # stemp,
.LVL15 = .
	b	.L21	 #
.LVL16 = .
.L22:
	.loc 4 20 0
	lbu	$5,0($4)	 #,* stemp
	addiu	$2,-1	 # cb,
	addiu	$4,1	 # stemp,
.LVL17 = .
	sb	$5,0($3)	 # tmp294,* dtemp
	addiu	$3,1	 # dtemp,
.LVL18 = .
.L21:
	.loc 4 19 0
	bnez	$2,.L22	 #, cb,
.LVL19 = .
.L16:
.LBE51 = .
.LBE52 = .
.LBE48 = .
	.loc 1 552 0
	lw	$2,%gprel(UserApp)($16)	 # UserApp, UserApp
	jalr	$2	 # UserApp
	.align	2	 #
.L23:
	.word	U1STA
.L24:
	.word	U1MODE
.L25:
	.word	LATACLR
.L26:
	.word	TRISASET
.L27:
	.word	33554432
.L28:
	.word	-1660944384
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	ExecuteApp
	.cfi_endproc
.LFE14:
	.size	ExecuteApp, .-ExecuteApp
	.align	2
.LFB17 = .
	.loc 1 694 0
	.cfi_startproc
	.set	nomips16
	.set	nomicromips
	.ent	flashOperation
	.type	flashOperation, @function
flashOperation:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL20 = .
	.loc 1 704 0
	ext	$5,$5,0,29	 # NVMADDR.60, addr,
.LVL21 = .
	lui	$2,%hi(NVMADDR)	 # tmp232,
	sw	$5,%lo(NVMADDR)($2)	 # NVMADDR.60, NVMADDR
.LVL22 = .
	.loc 1 705 0
	lui	$2,%hi(NVMDATA)	 # tmp233,
	sw	$6,%lo(NVMDATA)($2)	 # data, NVMDATA
	.loc 1 706 0
	ext	$6,$6,0,29	 # NVMSRCADDR.61, data,
.LVL23 = .
	lui	$2,%hi(NVMSRCADDR)	 # tmp234,
.LVL24 = .
	sw	$6,%lo(NVMSRCADDR)($2)	 # NVMSRCADDR.61, NVMSRCADDR
.LVL25 = .
	.loc 1 722 0
	ori	$4,$4,0x4000	 # NVMCON.62, nvmop,
.LVL26 = .
	lui	$2,%hi(NVMCON)	 # tmp235,
	sw	$4,%lo(NVMCON)($2)	 # NVMCON.62, NVMCON
.LVL27 = .
	.loc 1 730 0
	mfc0	$3, $9, 0
.LVL28 = .
	move	$5,$2	 # tmp252, tmp235
.LVL29 = .
.L30:
	.loc 1 731 0
	mfc0	$2, $9, 0
	subu	$2,$2,$3	 # tmp236, D.8862, t0
	sltu	$2,$2,120	 # tmp237, tmp236,
	bne	$2,$0,.L30	 #, tmp237,,
	lui	$2,%hi(NVMKEY)	 # tmp238,

	.loc 1 734 0
	li	$3,-1432813568			# 0xaa990000	 # tmp240,
.LVL30 = .
	addiu	$3,$3,26197	 # tmp239, tmp240,
	sw	$3,%lo(NVMKEY)($2)	 # tmp239, NVMKEY
	.loc 1 735 0
	li	$3,1432748032			# 0x55660000	 # tmp243,
	ori	$3,$3,0x99aa	 # tmp242, tmp243,
	sw	$3,%lo(NVMKEY)($2)	 # tmp242, NVMKEY
	.loc 1 736 0
	li	$4,32768			# 0x8000	 # tmp245,
.LVL31 = .
	lui	$3,%hi(NVMCONSET)	 # tmp244,
	sw	$4,%lo(NVMCONSET)($3)	 # tmp245, NVMCONSET
.L31:
	.loc 1 739 0
	lw	$2,%lo(NVMCON)($5)	 # NVMCON.63, NVMCON
	andi	$2,$2,0x8000	 # tmp247, NVMCON.63,
	bne	$2,$0,.L31
	nop
	 #, tmp247,,
	.loc 1 742 0
	mfc0	$2, $9, 0
.LVL32 = .
.L32:
	.loc 1 743 0
	mfc0	$3, $9, 0
	subu	$3,$3,$2	 # tmp248, D.8866, t0
	sltu	$3,$3,10	 # tmp249, tmp248,
	bne	$3,$0,.L32	 #, tmp249,,
	li	$3,16384			# 0x4000	 # tmp251,

	.loc 1 746 0
	lui	$2,%hi(NVMCONCLR)	 # tmp250,
.LVL33 = .
	sw	$3,%lo(NVMCONCLR)($2)	 # tmp251, NVMCONCLR
	.loc 1 761 0
	j	$31
	nop

	.set	macro
	.set	reorder
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	flashOperation
	.cfi_endproc
.LFE17:
	.size	flashOperation, .-flashOperation
	.align	2
.LFB18 = .
	.loc 1 783 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	flashErasePage
	.type	flashErasePage, @function
flashErasePage:
	.frame	$sp,40,$31		# vars= 8, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL34 = .
	.loc 1 786 0
	li	$2,1	 # x,
	.loc 1 783 0
	save	40,$16,$17,$31
.LCFI1:
	.cfi_def_cfa_offset 40
	.loc 1 786 0
	neg	$2,$2	 # x, x
	.loc 1 783 0
	move	$16,$4	 # addrPage, addrPage
	.cfi_offset 16, -12
	.cfi_offset 17, -8
	.cfi_offset 31, -4
.LVL35 = .
	.loc 1 796 0
	li	$17,5	 # ivtmp.99,
	b	.L37	 #
.LVL36 = .
.L38:
	.loc 1 798 0
	lw	$5,0($3)	 # tmp256,* addrPage
	addiu	$3,4	 # addrPage,
	and	$2,$5	 # x, tmp256
.LVL37 = .
.L40:
	.loc 1 796 0
	cmp	$3,$4	 # addrPage, D.9191
	btnez	.L38	 #,
	.loc 1 802 0
	addiu	$3,$2,1	 # tmp258, x,
	beqz	$3,.L36	 #, tmp258,
	.loc 1 808 0
	li	$4,16388	 #,
	move	$5,$16	 #, addrPage
	li	$6,0	 #,
	addiu	$17,-1	 # ivtmp.99,
	.set	noreorder
	.set	nomacro
	jal	flashOperation	 #
	sw	$2,16($sp)	 #,
	.set	macro
	.set	reorder

.LVL38 = .
	.loc 1 793 0
	lw	$2,16($sp)	 #,
	beqz	$17,.L36	 #, ivtmp.99,
.LVL39 = .
.L37:
	.loc 1 782 0
	addiu	$4,$16,1024	 # D.9191, addrPage,
	move	$3,$16	 # addrPage, addrPage
	b	.L40	 #
.LVL40 = .
.L36:
	.loc 1 813 0
	restore	40,$16,$17,$31
.LVL41 = .
	j	$31	 #
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	flashErasePage
	.cfi_endproc
.LFE18:
	.size	flashErasePage, .-flashErasePage
	.align	2
.LFB20 = .
	.loc 1 874 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	justInTimeFlashErase
	.type	justInTimeFlashErase, @function
justInTimeFlashErase:
	.frame	$sp,40,$31		# vars= 8, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL42 = .
	save	40,$16,$17,$31
.LCFI2:
	.cfi_def_cfa_offset 40
	.loc 1 875 0
	li	$2,1024	 # tmp231,
	.loc 1 877 0
	lw	$17,.L45	 # tmp238,
	.cfi_offset 16, -12
	.cfi_offset 17, -8
	.cfi_offset 31, -4
	.loc 1 875 0
	neg	$2,$2	 # tmp231, tmp231
	move	$16,$4	 # addrCurPage, addrLow
	and	$16,$2	 # addrCurPage, tmp231
.LVL43 = .
	.loc 1 876 0
	addiu	$5,-1	 # tmp233,
.LVL44 = .
	.loc 1 877 0
	addu	$17,$16,$17	 # tmp237, addrCurPage, tmp238
	.loc 1 876 0
	and	$5,$2	 # tmp233, tmp231
.LVL45 = .
	.loc 1 877 0
	srl	$17,$17,8	 # iPage, tmp237,
	.loc 1 876 0
	addiu	$5,1024	 # addrLastPage,
.LVL46 = .
	.loc 1 877 0
	srl	$17,$17,2	 # iPage, iPage,
.LVL47 = .
	.loc 1 879 0
	b	.L42	 #
.LVL48 = .
.L44:
	.loc 1 873 0
	lw	$2,.L46	 # tmp240,
	addu	$2,$17,$2	 # D.9206, iPage, tmp240
	.loc 1 882 0
	lbu	$3,0($2)	 # tmp241, pageMap
	bnez	$3,.L43	 #, tmp241,
	.loc 1 884 0
	move	$4,$16	 #, addrCurPage
	sw	$2,20($sp)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashErasePage	 #
	sw	$5,16($sp)	 #,
	.set	macro
	.set	reorder

	.loc 1 885 0
	lw	$2,20($sp)	 #,
	li	$3,1	 # tmp242,
	sb	$3,0($2)	 # tmp242, pageMap
	lw	$5,16($sp)	 #,
.L43:
	.loc 1 888 0
	addiu	$17,1	 # iPage,
.LVL49 = .
	.loc 1 889 0
	addiu	$16,1024	 # addrCurPage,
.LVL50 = .
.L42:
	.loc 1 879 0
	sltu	$16,$5	 # addrCurPage, addrLastPage
	btnez	.L44	 #,
	.loc 1 891 0
	restore	40,$16,$17,$31
.LVL51 = .
	j	$31	 #
	.align	2	 #
.L45:
	.word	1660944384
.L46:
	.word	pageMap
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	justInTimeFlashErase
	.cfi_endproc
.LFE20:
	.size	justInTimeFlashErase, .-justInTimeFlashErase
	.align	2
.LFB19 = .
	.loc 1 836 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	flashWriteUint32
	.type	flashWriteUint32, @function
flashWriteUint32:
	.frame	$sp,40,$31		# vars= 8, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL52 = .
	save	40,$16,$17,$31
.LCFI3:
	.cfi_def_cfa_offset 40
	.loc 1 836 0
	move	$3,$6	 # cu32Data, cu32Data
	move	$16,$4	 # addrUint32, addrUint32
	.cfi_offset 16, -12
	.cfi_offset 17, -8
	.cfi_offset 31, -4
	.loc 1 839 0
	move	$17,$5	 # ivtmp.136, rgu32Data
	li	$2,0	 # i,
	b	.L48	 #
.LVL53 = .
.L50:
	.loc 1 843 0
	lw	$6,0($17)	 # D.8871,* ivtmp.136
	addiu	$4,$6,1	 # tmp226, D.8871,
	beqz	$4,.L49	 #, tmp226,
	.loc 1 846 0
	li	$4,16385	 #,
	move	$5,$16	 #, addrUint32
	sw	$2,16($sp)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashOperation	 #
	sw	$3,20($sp)	 #,
	.set	macro
	.set	reorder

.LVL54 = .
	lw	$3,20($sp)	 #,
	lw	$2,16($sp)	 #,
.L49:
	.loc 1 849 0
	addiu	$16,4	 # addrUint32,
.LVL55 = .
	.loc 1 839 0
	addiu	$2,1	 # i,
.LVL56 = .
	addiu	$17,4	 # ivtmp.136,
.LVL57 = .
.L48:
	sltu	$2,$3	 # i, cu32Data
	btnez	.L50	 #,
	.loc 1 851 0
	restore	40,$16,$17,$31
.LVL58 = .
	j	$31	 #
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	flashWriteUint32
	.cfi_endproc
.LFE19:
	.size	flashWriteUint32, .-flashWriteUint32
	.align	2
.LFB16 = .
	.loc 1 619 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	finshFlashProcessingAfterLoad
	.type	finshFlashProcessingAfterLoad, @function
finshFlashProcessingAfterLoad:
	.frame	$sp,32,$31		# vars= 0, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
	save	32,$16,$17,$31
.LCFI4:
	.cfi_def_cfa_offset 32
	.loc 1 628 0
	move	$17,$28	 # tmp235,
	.cfi_offset 16, -12
	.cfi_offset 17, -8
	.cfi_offset 31, -4
.LVL59 = .
	lw	$4,%gprel(addrBase)($17)	 #, addrBase
	jal	getHeaderStructure	 #
	move	$16,$2	 # pHeaderInfo,
.LVL60 = .
	beqz	$2,.L55	 #, pHeaderInfo,
	.loc 1 631 0
	move	$5,$17	 #, tmp235
	addiu	$4,$2,4	 #, pHeaderInfo,
	addiu	$5,%gprel(bootloaderVer)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashWriteUint32	 #
	li	$6,1	 #,
	.set	macro
	.set	reorder

.LVL61 = .
	.loc 1 632 0
	addiu	$4,$16,7	 #, pHeaderInfo,
	move	$5,$17	 #, tmp235
	addiu	$4,9	 #,
	addiu	$5,%gprel(prodAndVend)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashWriteUint32	 #
	li	$6,1	 #,
	.set	macro
	.set	reorder

	.loc 1 633 0
	addiu	$4,$16,7	 #, pHeaderInfo,
	move	$5,$17	 #, tmp235
	addiu	$4,5	 #,
	addiu	$5,%gprel(bootloaderCapabilities)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashWriteUint32	 #
	li	$6,1	 #,
	.set	macro
	.set	reorder

	.loc 1 634 0
	addiu	$4,$16,7	 #, pHeaderInfo,
	move	$5,$17	 #, tmp235
	addiu	$4,53	 #,
	addiu	$5,%gprel(cbSkipRam)	 #,
	.set	noreorder
	.set	nomacro
	jal	flashWriteUint32	 #
	li	$6,1	 #,
	.set	macro
	.set	reorder

	.loc 1 637 0
	lhu	$2,22($16)	 # tmp241,
	lhu	$3,20($16)	 # tmp240,
	sll	$2,$2,8	 # tmp244, tmp241,
	sll	$2,$2,8	 # tmp244, tmp244,
	or	$2,$3	 # tmp244, tmp240
	lw	$3,.L57	 # tmp246,
	and	$3,$2	 # tmp245, tmp244
	bnez	$3,.L51	 #, tmp245,
	.loc 1 642 0
	lw	$3,.L58	 # tmp248,
	and	$3,$2	 # tmp247, tmp244
	beqz	$3,.L54	 #, tmp247,
	.loc 1 644 0
	lhu	$4,30($16)	 # tmp250,
	lhu	$2,28($16)	 # tmp249,
	.loc 1 645 0
	lhu	$5,34($16)	 # tmp255,
	.loc 1 644 0
	sll	$4,$4,8	 # addrLow, tmp250,
	sll	$4,$4,8	 # addrLow, addrLow,
	or	$4,$2	 # addrLow, tmp249
.LVL62 = .
	.loc 1 645 0
	lhu	$2,32($16)	 # tmp254,
	sll	$5,$5,8	 # tmp258, tmp255,
	sll	$5,$5,8	 # tmp258, tmp258,
	or	$5,$2	 # tmp258, tmp254
	addu	$5,$5,$4	 # addrHigh, tmp258, addrLow
.LVL63 = .
	b	.L52	 #
.LVL64 = .
.L54:
	.loc 1 649 0
	lw	$3,.L59	 # tmp260,
	lw	$4,.L60	 # addrLow,
	and	$2,$3	 # tmp259, tmp260
	beqz	$2,.L56	 #, tmp259,
	.loc 1 651 0
	lw	$5,.L61	 # addrHigh,
	b	.L52	 #
.L55:
	.loc 1 625 0
	lw	$5,.L62	 # addrHigh,
	.loc 1 624 0
	lw	$4,.L60	 # addrLow,
	b	.L52	 #
.L56:
	.loc 1 625 0
	lw	$5,.L62	 # addrHigh,
.LVL65 = .
.L52:
	.loc 1 660 0
	jal	justInTimeFlashErase	 #
.LVL66 = .
.L51:
	.loc 1 661 0
	restore	32,$16,$17,$31
.LVL67 = .
	j	$31	 #
	.align	2	 #
.L57:
	.word	131072
.L58:
	.word	262144
.L59:
	.word	524288
.L60:
	.word	-1660944384
.L61:
	.word	-1660911616
.L62:
	.word	-1660915712
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	finshFlashProcessingAfterLoad
	.cfi_endproc
.LFE16:
	.size	finshFlashProcessingAfterLoad, .-finshFlashProcessingAfterLoad
	.section	.rodata,code
	.align	2
.LC17:
	.ascii	"STK500_2\000"
	.section	.text,code
	.align	2
.LFB22 = .
	.loc 1 274 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	avrbl_message.clone.0.clone.1
	.type	avrbl_message.clone.0.clone.1, @function
avrbl_message.clone.0.clone.1:
	.frame	$sp,104,$31		# vars= 72, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
	save	104,$16,$17,$31
.LCFI5:
	.cfi_def_cfa_offset 104
	.loc 1 292 0
	move	$16,$28	 # tmp336,
	.cfi_offset 16, -12
	.cfi_offset 17, -8
	.cfi_offset 31, -4
.LVL68 = .
	lw	$2,%gprel(replyi)($16)	 # replyi.33, replyi
	lw	$3,.L101	 # tmp337,
	lbu	$4,2($3)	 # D.9065, request
	lw	$5,.L102	 # tmp338,
	addu	$6,$5,$2	 # tmp339, tmp338, replyi.33
	sb	$4,0($6)	 # D.9065, reply
	addiu	$6,$2,1	 # replyi.34, replyi.33,
	.loc 1 293 0
	addu	$6,$5,$6	 # tmp341, tmp338, replyi.34
	li	$7,0	 # tmp342,
	sb	$7,0($6)	 # tmp342, reply
	.loc 1 296 0
	cmpi	$4,6	 # D.9065,
	.loc 1 293 0
	addiu	$6,$2,2	 # replyi_lsm.143, replyi.33,
	sw	$6,%gprel(replyi)($16)	 # replyi_lsm.143, replyi
	.loc 1 296 0
	bteqz	.L68	 #,
	sltu	$4,7	 # D.9065,
	bteqz	.L73	 #,
	cmpi	$4,2	 # D.9065,
	bteqz	.L66	 #,
	cmpi	$4,3	 # D.9065,
	bteqz	.L67	 #,
	li	$3,1	 #,
	xor	$4,$3	 # tmp347,
	beqz	$4,.L65	 #, tmp347,
	b	.L64	 #
.L73:
	cmpi	$4,19	 # D.9065,
	bteqz	.L70	 #,
	sltu	$4,20	 # D.9065,
	bteqz	.L74	 #,
	cmpi	$4,17	 # D.9065,
	bteqz	.L69	 #,
	b	.L64	 #
.L74:
	cmpi	$4,20	 # D.9065,
	bteqz	.L71	 #,
	li	$7,29	 #,
	xor	$4,$7	 # tmp352,
	beqz	$4,.L72	 #, tmp352,
	b	.L64	 #
.L65:
	.loc 1 304 0
	li	$3,1	 # tmp354,
	.loc 1 306 0
	addu	$6,$5,$6	 # tmp357, tmp338, replyi_lsm.143
	addiu	$2,3	 # replyi.34,
	.loc 1 304 0
	sb	$3,%gprel(active)($16)	 # tmp354, active
	.loc 1 306 0
	li	$3,8	 # tmp358,
	sb	$3,0($6)	 # tmp358, reply
	.loc 1 302 0
	sb	$4,%gprel(fLoadProgramFromFlash)($16)	 # tmp347, fLoadProgramFromFlash
	.loc 1 305 0
	sb	$4,%gprel(erased)($16)	 # tmp347, erased
	.loc 1 306 0
	sw	$2,%gprel(replyi)($16)	 # replyi.34, replyi
	.loc 1 307 0
	addu	$5,$2,$5	 # dest, replyi.34, tmp338
.LVL69 = .
	lw	$3,.L103	 # src,
.LVL70 = .
.L75:
.LBB53 = .
.LBB54 = .
	.loc 4 40 0
	lb	$4,0($3)	 # D.9131,* src
	.loc 4 41 0
	addiu	$3,1	 # src,
.LVL71 = .
	.loc 4 40 0
	sb	$4,0($5)	 # D.9131,* dest
	addiu	$5,1	 # dest,
.LVL72 = .
	.loc 4 41 0
	bnez	$4,.L75	 #, D.9131,
.LBE54 = .
.LBE53 = .
	.loc 1 308 0
	addiu	$2,8	 # tmp360,
	.loc 1 309 0
	li	$3,255	 # tmp362,
.LVL73 = .
	.loc 1 308 0
	sw	$2,%gprel(replyi)($16)	 # tmp360, replyi
	.loc 1 309 0
	addiu	$3,1	 # tmp362,
	lw	$2,.L104	 # tmp361,
	b	.L97	 #
.LVL74 = .
.L66:
	.loc 1 312 0
	lbu	$2,3($3)	 # request, request
	lbu	$3,4($3)	 #, request
	lw	$4,.L105	 # tmp363,
	addu	$2,$4,$2	 # tmp366, tmp363, request
	sb	$3,0($2)	 # request, parameters
	b	.L64	 #
.L67:
	.loc 1 315 0
	lbu	$3,3($3)	 # request, request
	lw	$4,.L105	 # tmp371,
	addu	$5,$5,$6	 # tmp370, tmp338, replyi_lsm.143
	addu	$3,$4,$3	 # tmp374, tmp371, request
	lbu	$3,0($3)	 #, parameters
	addiu	$2,3	 # tmp376,
	sb	$3,0($5)	 # tmp375, reply
	b	.L98	 #
.L72:
	.loc 1 321 0
	lbu	$7,6($3)	 # D.9076, request
	.loc 1 320 0
	addu	$6,$5,$6	 # tmp378, tmp338, replyi_lsm.143
	sb	$4,0($6)	 # tmp352, reply
	.loc 1 321 0
	addu	$6,$5,$2	 # tmp382, tmp338, replyi.33
	sb	$7,3($6)	 # D.9076, reply
	.loc 1 322 0
	sb	$4,4($6)	 # tmp352, reply
	.loc 1 323 0
	cmpi	$7,48	 # D.9076,
	.loc 1 322 0
	addiu	$6,$2,5	 # replyi.34, replyi.33,
	sw	$6,%gprel(replyi)($16)	 # replyi.34, replyi
	.loc 1 323 0
	btnez	.L76	 #,
	.loc 1 324 0
	lbu	$3,8($3)	 # D.9078, request
	addu	$5,$5,$6	 # tmp508, tmp338, replyi.34
	bnez	$3,.L77	 #, D.9078,
	.loc 1 325 0
	li	$3,80	 # tmp390,
	sb	$3,0($5)	 # tmp390, reply
	b	.L95	 #
.L77:
	.loc 1 326 0
	cmpi	$3,1	 # D.9078,
	addiu	$2,6	 # tmp509,
	.loc 1 327 0
	li	$3,73	 # tmp395,
	.loc 1 326 0
	bteqz	.L100	 #,
	.loc 1 329 0
	li	$3,67	 # tmp399,
.L100:
	sb	$3,0($5)	 # tmp399, reply
	b	.L96	 #
.L76:
	.loc 1 332 0
	cmpi	$7,32	 # D.9076,
	bteqz	.L80	 #,
	cmpi	$7,40	 # D.9076,
	btnez	.L81	 #,
.L80:
	.loc 1 350 0
	lw	$2,.L102	 # tmp403,
	li	$3,1	 # tmp405,
	addu	$2,$2,$6	 # tmp404, tmp403, replyi.34
	neg	$3,$3	 # tmp405, tmp405
	addiu	$6,1	 # tmp406,
	sb	$3,0($2)	 # tmp405, reply
	sw	$6,%gprel(replyi)($16)	 # tmp406, replyi
	b	.L78	 #
.L81:
	.loc 1 352 0
	addu	$5,$5,$6	 # tmp408, tmp338, replyi.34
	sb	$4,0($5)	 # tmp352, reply
.L95:
	addiu	$2,6	 # tmp410,
.L96:
	sw	$2,%gprel(replyi)($16)	 # tmp410, replyi
.L78:
	.loc 1 354 0
	lw	$2,%gprel(replyi)($16)	 # replyi.33, replyi
	lw	$3,.L102	 # tmp411,
	li	$4,0	 # tmp413,
	addu	$3,$3,$2	 # tmp412, tmp411, replyi.33
	sb	$4,0($3)	 # tmp413, reply
	addiu	$2,1	 # tmp414,
.L98:
	sw	$2,%gprel(replyi)($16)	 # tmp414, replyi
	b	.L64	 #
.L68:
	.loc 1 362 0
	lbu	$4,4($3)	 # request, request
	lbu	$2,3($3)	 # request, request
	sll	$4,$4,8	 # tmp420, request,
	sll	$4,$4,8	 # tmp420, tmp420,
	sll	$2,$2,24	 # tmp429, request,
	or	$2,$4	 # tmp429, tmp420
	lbu	$4,6($3)	 # request, request
	lbu	$3,5($3)	 # request, request
	or	$2,$4	 # tmp429, request
	sll	$3,$3,8	 # tmp428, request,
	or	$2,$3	 # tmp429, tmp428
	.loc 1 364 0
	sll	$2,$2,1	 # tmp430, tmp429,
	.loc 1 366 0
	lw	$3,%gprel(avrdudeAddrBase)($16)	 # avrdudeAddrBase, avrdudeAddrBase
	b	.L99	 #
.L70:
	.loc 1 378 0
	lbu	$2,3($3)	 # request, request
	lbu	$3,4($3)	 # request, request
	sll	$2,$2,8	 # i, request,
	or	$2,$3	 # i, request
.LVL75 = .
	.loc 1 379 0
	li	$3,4	 # tmp439,
	neg	$3,$3	 # tmp439, tmp439
	addiu	$17,$2,3	 # nbytesAligned, i,
	and	$17,$3	 # nbytesAligned, tmp439
.LVL76 = .
	.loc 1 382 0
	move	$3,$2	 # i, i
	b	.L82	 #
.LVL77 = .
.L83:
	.loc 1 384 0
	lw	$4,.L106	 # tmp441,
	li	$5,1	 # tmp442,
	addu	$4,$3,$4	 # tmp440, i, tmp441
	neg	$5,$5	 # tmp442, tmp442
	sb	$5,0($4)	 # tmp442,
	.loc 1 382 0
	addiu	$3,1	 # i,
.LVL78 = .
.L82:
	sltu	$3,$17	 # i, nbytesAligned
	btnez	.L83	 #,
	.loc 1 387 0
	lbu	$3,%gprel(fGetBaseAddress.6388)($16)	 # fGetBaseAddress, fGetBaseAddress
.LVL79 = .
	beqz	$3,.L84	 #, fGetBaseAddress,
	.loc 1 394 0
	sltu	$17,256	 # nbytesAligned,
	btnez	.L85	 #,
	lw	$4,%gprel(load_address.6386)($16)	 # load_address.39, load_address
	li	$3,511	 # tmp447,
	and	$3,$4	 # tmp446, load_address.39
	bnez	$3,.L85	 #, tmp446,
.LBB55 = .
	.loc 1 396 0
	lw	$3,.L107	 # tmp448,
	lw	$3,0($3)	 # addrBaseT,
.LVL80 = .
	.loc 1 401 0
	addiu	$5,$3,1	 # tmp449, addrBaseT,
	beqz	$5,.L85	 #, tmp449,
	.loc 1 403 0
	lw	$5,%gprel(avrdudeAddrBase)($16)	 # avrdudeAddrBase, avrdudeAddrBase
	.loc 1 406 0
	sw	$3,%gprel(addrBase)($16)	 # addrBaseT, addrBase
	.loc 1 403 0
	subu	$5,$4,$5	 # load_address.45, load_address.39, avrdudeAddrBase
	.loc 1 404 0
	lw	$4,.L108	 # tmp451,
	and	$4,$3	 # avrdudeAddrBase.46, addrBaseT
	sw	$4,%gprel(avrdudeAddrBase)($16)	 # avrdudeAddrBase.46, avrdudeAddrBase
	.loc 1 405 0
	addu	$4,$5,$4	 # tmp452, load_address.45, avrdudeAddrBase.46
	sw	$4,%gprel(load_address.6386)($16)	 # tmp452, load_address
.LVL81 = .
.L85:
.LBE55 = .
	.loc 1 409 0
	li	$3,0	 # tmp453,
	sb	$3,%gprel(fGetBaseAddress.6388)($16)	 # tmp453, fGetBaseAddress
.L84:
	.loc 1 413 0
	lw	$5,%gprel(load_address.6386)($16)	 # load_address.39, load_address
	sw	$2,80($sp)	 #,
	move	$4,$5	 #, load_address.39
	.set	noreorder
	.set	nomacro
	jal	justInTimeFlashErase	 #
	addu	$5,$17,$5	 #, nbytesAligned, load_address.39
	.set	macro
	.set	reorder

.LVL82 = .
	.loc 1 417 0
	lw	$4,%gprel(load_address.6386)($16)	 #, load_address
	lw	$5,.L106	 #,
	.set	noreorder
	.set	nomacro
	jal	flashWriteUint32	 #
	srl	$6,$17,2	 #, nbytesAligned,
	.set	macro
	.set	reorder

	.loc 1 418 0
	lw	$3,%gprel(load_address.6386)($16)	 # load_address, load_address
	lw	$2,80($sp)	 #,
.LVL83 = .
.L99:
	addu	$2,$3,$2	 # tmp457, load_address, i
	sw	$2,%gprel(load_address.6386)($16)	 # tmp457, load_address
	b	.L64	 #
.L71:
	.loc 1 423 0
	lbu	$4,3($3)	 # request, request
	lw	$2,%gprel(load_address.6386)($16)	 # load_address_lsm.144, load_address
	lbu	$3,4($3)	 # request, request
	sll	$4,$4,8	 # tmp460, request,
	addu	$4,$4,$2	 # addrEndPage, tmp460, load_address_lsm.144
	or	$4,$3	 # addrEndPage, request
.LVL84 = .
	b	.L86	 #
.L91:
.LBB56 = .
	.loc 1 429 0
	lw	$7,.L109	 # tmp467,
	.loc 1 428 0
	li	$5,1024	 # tmp464,
	neg	$5,$5	 # tmp464, tmp464
	and	$5,$2	 # D.9113, load_address_lsm.144
	addiu	$3,$5,1024	 # addrEndPage, D.9113,
.LVL85 = .
	.loc 1 429 0
	addu	$5,$5,$7	 # tmp466, D.9113, tmp467
	srl	$5,$5,8	 # tmp468, tmp466,
	srl	$5,$5,2	 # tmp468, tmp468,
	lw	$7,.L110	 # tmp465,
	addu	$5,$7,$5	 # tmp470, tmp465, tmp468
	lbu	$5,0($5)	 # tmp471, pageMap
	cmpi	$5,1	 # tmp471,
	li	$5,255	 # lieMask,
	btnez	.L87	 #,
	li	$5,0	 # lieMask,
.L87:
.LVL86 = .
	sltu	$4,$3	 # addrEndPage, addrEndPage
	bteqz	.L89	 #,
	move	$3,$4	 # addrEndPage, addrEndPage
.LVL87 = .
	b	.L89	 #
.LVL88 = .
.L90:
	.loc 1 440 0
	lbu	$7,0($2)	 # tmp477,* load_address_lsm.144
	.loc 1 274 0
	lw	$17,.L102	 # tmp475,
	addu	$17,$6,$17	 # tmp474, replyi_lsm.143, tmp475
	.loc 1 440 0
	or	$7,$5	 # tmp477, lieMask
	sb	$7,0($17)	 # tmp477, reply
	.loc 1 274 0
	addiu	$6,1	 # replyi_lsm.143,
	.loc 1 440 0
	addiu	$2,1	 # load_address_lsm.144,
.LVL89 = .
.L89:
	.loc 1 438 0
	sltu	$2,$3	 # load_address_lsm.144, addrEndPage
	btnez	.L90	 #,
.LVL90 = .
.L86:
.LBE56 = .
	.loc 1 426 0
	sltu	$2,$4	 # load_address_lsm.144, addrEndPage
	btnez	.L91	 #,
	sw	$2,%gprel(load_address.6386)($16)	 # load_address_lsm.144, load_address
	.loc 1 445 0
	lw	$2,.L102	 # tmp481,
	addu	$2,$2,$6	 # tmp482, tmp481, replyi_lsm.143
	li	$3,0	 # tmp483,
	addiu	$6,1	 # tmp484,
	sb	$3,0($2)	 # tmp483, reply
	sw	$6,%gprel(replyi)($16)	 # tmp484, replyi
	b	.L64	 #
.LVL91 = .
.L69:
	.loc 1 448 0
	jal	finshFlashProcessingAfterLoad	 #
	.loc 1 449 0
	li	$2,1	 # tmp485,
	.loc 1 450 0
	li	$3,255	 # tmp487,
	.loc 1 449 0
	sb	$2,%gprel(fLoaded)($16)	 # tmp485, fLoaded
	.loc 1 450 0
	addiu	$3,1	 # tmp487,
	lw	$2,.L111	 # tmp486,
.L97:
	sw	$3,0($2)	 # tmp487,
.L64:
.LVL92 = .
	.loc 1 461 0
	lw	$17,%gprel(replyi)($16)	 # replyi.33, replyi
	.loc 1 459 0
	li	$2,27	 # tmp488,
	move	$3,$sp	 #,
	sb	$2,16($3)	 # tmp488, raw
.LVL93 = .
	.loc 1 460 0
	lbu	$3,%gprel(seq)($16)	 #, seq
	move	$4,$sp	 #,
	.loc 1 461 0
	sra	$2,$17,8	 # tmp490, replyi.33,
	.loc 1 460 0
	sb	$3,17($4)	 # seq, raw
.LVL94 = .
	.loc 1 461 0
	sb	$2,18($4)	 # tmp490, raw
.LVL95 = .
	.loc 1 462 0
	sb	$17,19($4)	 # tmp5, raw
.LVL96 = .
	.loc 1 463 0
	move	$7,$sp	 #,
	li	$4,14	 # tmp491,
	sb	$4,20($7)	 # tmp491, raw
.LVL97 = .
	.loc 1 466 0
	li	$4,27	 #,
	xor	$3,$4	 # tmp494,
	xor	$2,$3	 # tmp496, tmp494
	li	$5,14	 #,
	xor	$2,$17	 # tmp498, replyi.33
	xor	$2,$5	 # tmp500,
	.loc 1 468 0
	addiu	$4,$sp,16	 #,,
	.loc 1 466 0
	sb	$2,%gprel(csum)($16)	 # tmp500, csum
	.loc 1 468 0
	.set	noreorder
	.set	nomacro
	jal	avrbl_print	 #
	li	$5,5	 #,
	.set	macro
	.set	reorder

.LVL98 = .
	lbu	$4,%gprel(csum)($16)	 # csum_lsm.141, csum
.LBB57 = .
	.loc 1 471 0
	li	$3,0	 # i,
	b	.L92	 #
.LVL99 = .
.L93:
.LBE57 = .
	.loc 1 274 0
	lw	$2,.L102	 # tmp502,
	addu	$2,$3,$2	 # tmp501, i, tmp502
	.loc 1 472 0
	lbu	$2,0($2)	 # tmp504, reply
	.loc 1 471 0
	addiu	$3,1	 # i,
.LVL100 = .
	.loc 1 472 0
	xor	$4,$2	 # csum_lsm.141, tmp504
.LVL101 = .
.L92:
	.loc 1 471 0
	move	$2,$3	 # tmp505, i
	xor	$2,$17	 # tmp505, replyi.33
	bnez	$2,.L93	 #, tmp505,
	sb	$4,%gprel(csum)($16)	 # csum_lsm.141, csum
	.loc 1 474 0
	move	$5,$17	 #, replyi.33
	lw	$4,.L102	 #,
	.set	noreorder
	.set	nomacro
	jal	avrbl_print	 #
	sw	$2,80($sp)	 #,
	.set	macro
	.set	reorder

.LVL102 = .
	.loc 1 477 0
	move	$4,$16	 #, tmp336
	addiu	$4,%gprel(csum)	 #,
	.set	noreorder
	.set	nomacro
	jal	avrbl_print	 #
	li	$5,1	 #,
	.set	macro
	.set	reorder

	.loc 1 479 0
	lw	$2,80($sp)	 #,
	sw	$2,%gprel(replyi)($16)	 # tmp505, replyi
	.loc 1 480 0
	restore	104,$16,$17,$31
	j	$31	 #
	.align	2	 #
.L101:
	.word	request
.L102:
	.word	reply
.L103:
	.word	.LC17
.L104:
	.word	LATASET
.L105:
	.word	parameters.6387
.L106:
	.word	request+12
.L107:
	.word	request+260
.L108:
	.word	-65536
.L109:
	.word	1660944384
.L110:
	.word	pageMap
.L111:
	.word	LATACLR
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	avrbl_message.clone.0.clone.1
	.cfi_endproc
.LFE22:
	.size	avrbl_message.clone.0.clone.1, .-avrbl_message.clone.0.clone.1
	.align	2
	.globl	avrbl_state_machine
.LFB11 = .
	.loc 1 215 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	avrbl_state_machine
	.type	avrbl_state_machine, @function
avrbl_state_machine:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
.LVL103 = .
	.loc 1 216 0
	move	$2,$28	 # tmp232,
	lbu	$3,%gprel(csum)($2)	 # tmp234, csum
	.loc 1 218 0
	lw	$5,%gprel(state)($2)	 # state, state
	.loc 1 215 0
	zeb	$4	 # b
	.loc 1 216 0
	xor	$3,$4	 # csum.1, b
	.loc 1 218 0
	sltu	$5,7	 # state,
	.loc 1 216 0
	sb	$3,%gprel(csum)($2)	 # csum.1, csum
	.loc 1 218 0
	bteqz	.L127	 #,
	la	$6,.L121	 # tmp238,
	sll	$5,$5,1	 # tmp239, state,
	addu	$5,$6,$5	 # tmp240, tmp238, tmp239
	lh	$5,0($5)	 # tmp242,
	addu	$6,$5,$6	 # tmp243, tmp242, tmp238
	j	$6	 # tmp243
	.align	1
	.align	2
.L121:
	.half	.L114-.L121
	.half	.L115-.L121
	.half	.L116-.L121
	.half	.L117-.L121
	.half	.L118-.L121
	.half	.L119-.L121
	.half	.L120-.L121
.L114:
	.loc 1 220 0
	cmpi	$4,27	 # b,
	btnez	.L122	 #,
	.loc 1 221 0
	li	$3,1	 # tmp246,
	sw	$3,%gprel(state)($2)	 # tmp246, state
.L122:
	.loc 1 223 0
	sb	$4,%gprel(csum)($2)	 # b, csum
	.loc 1 224 0
	j	$31
.L115:
	.loc 1 226 0
	sb	$4,%gprel(seq)($2)	 # b, seq
	.loc 1 227 0
	li	$3,2	 # tmp247,
	b	.L125	 #
.L116:
	.loc 1 230 0
	sll	$4,$4,8	 # tmp248, b,
.LVL104 = .
	sw	$4,%gprel(size)($2)	 # tmp248, size
	.loc 1 231 0
	li	$3,3	 # tmp249,
	b	.L125	 #
.LVL105 = .
.L117:
	.loc 1 234 0
	lw	$3,%gprel(size)($2)	 # tmp251, size
	or	$3,$4	 # tmp251, b
	sw	$3,%gprel(size)($2)	 # tmp251, size
	.loc 1 235 0
	li	$3,4	 # tmp252,
	b	.L125	 #
.L118:
	.loc 1 238 0
	li	$3,14	 #,
	xor	$4,$3	 # tmp253,
.LVL106 = .
	.loc 1 242 0
	li	$3,0	 # tmp256,
	.loc 1 238 0
	bnez	$4,.L125	 #, tmp253,
	.loc 1 239 0
	sw	$4,%gprel(requesti)($2)	 # tmp253, requesti
	.loc 1 240 0
	li	$3,5	 # tmp255,
	b	.L125	 #
.LVL107 = .
.L119:
	.loc 1 246 0
	lw	$3,%gprel(requesti)($2)	 # requesti.6, requesti
	lw	$5,.L126	 # tmp257,
	addu	$5,$5,$3	 # tmp258, tmp257, requesti.6
	sb	$4,2($5)	 # b, request
	.loc 1 247 0
	lw	$4,%gprel(size)($2)	 # size, size
.LVL108 = .
	.loc 1 246 0
	addiu	$3,1	 # requesti.7,
	sw	$3,%gprel(requesti)($2)	 # requesti.7, requesti
	.loc 1 247 0
	xor	$3,$4	 # tmp260, size
	bnez	$3,.L127	 #, tmp260,
	.loc 1 248 0
	li	$3,6	 # tmp261,
.L125:
	sw	$3,%gprel(state)($2)	 # tmp261, state
	j	$31
.LVL109 = .
.L120:
	.loc 1 252 0
	bnez	$3,.L124	 #, csum.1,
	.loc 1 255 0
	li	$3,1	 # tmp262,
	sb	$3,%gprel(ready)($2)	 # tmp262, ready
.L124:
	.loc 1 257 0
	li	$3,0	 # tmp263,
	sw	$3,%gprel(state)($2)	 # tmp263, state
.LVL110 = .
.L127:
	j	$31
	.align	2	 #
.L126:
	.word	request
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	avrbl_state_machine
	.cfi_endproc
.LFE11:
	.size	avrbl_state_machine, .-avrbl_state_machine
	.align	2
	.globl	main
.LFB10 = .
	.loc 1 90 0
	.cfi_startproc
	.set	mips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
# Begin mchp_output_function_prologue
# End mchp_output_function_prologue
	.loc 1 95 0
	lw	$2,.L145	 # tmp256,
	lw	$3,0($2)	 # RCON.8, RCON
	.loc 1 90 0
	save	24,$16,$31
.LCFI6:
	.cfi_def_cfa_offset 24
	.loc 1 95 0
	move	$16,$28	 # tmp257,
	.cfi_offset 16, -8
	.cfi_offset 31, -4
	move	$2,$16	 # tmp258, tmp257
	addiu	$2,%gprel(ramHeader)	 # tmp258,
	sw	$3,4($2)	 # RCON.8, ramHeader.rcon
.LBB58 = .
.LBB59 = .
	.loc 3 1369 0
	li	$2,0	 # tmp260,
	lw	$3,.L146	 # tmp259,
	sw	$2,0($3)	 # tmp260, ANSELA
	.loc 3 1373 0
	lw	$3,.L147	 # tmp261,
	sw	$2,0($3)	 # tmp260, ANSELB
	.loc 3 1377 0
	lw	$3,.L148	 # tmp263,
	sw	$2,0($3)	 # tmp260, ANSELC
	.loc 3 1388 0
	lw	$4,.L149	 # tmp265,
	.loc 3 1389 0
	addiu	$2,256	 # tmp268,
	.loc 3 1388 0
	li	$3,128	 # tmp266,
	sw	$3,0($4)	 # tmp266, TRISACLR
.LBE59 = .
.LBE58 = .
	.loc 1 105 0
	lw	$5,.L150	 # tmp276,
.LBB61 = .
.LBB60 = .
	.loc 3 1389 0
	sw	$2,0($4)	 # tmp268, TRISACLR
	.loc 3 1394 0
	lw	$4,.L151	 # tmp269,
	sw	$2,0($4)	 # tmp268, LATACLR
.LBE60 = .
.LBE61 = .
	.loc 1 110 0
	lw	$2,.L152	 # tmp271,
	lw	$2,0($2)	 # tmp272,
	lw	$5,4096($5)	 # tmp280,
	li	$4,16	 # tmp273,
	and	$2,$4	 # tmp272, tmp273
	sltu	$2,1	 # tmp272
	not	$5,$5	 # tmp279, tmp280
	move	$2,$24	 # D.8638,
	sltu	$5,1	 # tmp279
	move	$5,$24	 #, tmp283
	cmpi	$5,1	 #,
	move	$5,$24	 #, tmp284
	and	$2,$5	 # D.8638,
	.loc 1 114 0
	lw	$5,.L153	 # tmp287,
	lw	$5,0($5)	 # tmp288,
	and	$5,$4	 # tmp288, tmp273
	li	$4,1	 # iftmp.13,
	beqz	$5,.L130	 #, tmp288,
	lw	$5,.L154	 # tmp290,
	lw	$6,0($5)	 # tmp291,
	and	$6,$4	 # tmp291, iftmp.13
	bnez	$6,.L130	 #, tmp291,
	lw	$6,0($5)	 # tmp294,
	and	$6,$3	 # tmp294, tmp266
	bnez	$6,.L130	 #, tmp294,
	lw	$4,0($5)	 # tmp297,
	li	$3,64	 # tmp298,
	and	$4,$3	 # tmp297, tmp298
	sltu	$4,1	 # tmp297
	move	$4,$24	 # iftmp.13,
.L130:
	and	$2,$4	 # fLoadProgramFromFlash.14, iftmp.13
	.loc 1 121 0
	lw	$3,.L151	 # tmp302,
	li	$4,16	 # tmp303,
	sw	$4,0($3)	 # tmp303, LATACLR
	.loc 1 122 0
	li	$4,0	 # tmp305,
	lw	$3,.L145	 # tmp304,
	.loc 1 114 0
	sb	$2,%gprel(fLoadProgramFromFlash)($16)	 # fLoadProgramFromFlash.14, fLoadProgramFromFlash
	.loc 1 122 0
	sw	$4,0($3)	 # tmp305, RCON
	.loc 1 126 0
	beqz	$2,.L131	 #, fLoadProgramFromFlash.14,
	.loc 1 129 0
	jal	ExecuteApp	 #
.L131:
	.loc 1 132 0
	.set	noreorder
	jal _ISA32M164
	nop
	.align 2
	.set	nomips16
_ISA32M164: 
	.set	reorder
	mfc0	$2, $9, 0
	.set	noreorder
	jal _ISA16M165
	nop
	.align 2
	.set	mips16
_ISA16M165:	nop
	.set	reorder
.LBB62 = .
.LBB63 = .
	.loc 3 1489 0
	lw	$3,.L155	 # tmp306,
.LBE63 = .
.LBE62 = .
	.loc 1 132 0
	sw	$2,%gprel(tLoopStart)($16)	 # tLoopStart.15, tLoopStart
	.loc 1 133 0
	sw	$2,%gprel(tLastBlink)($16)	 # tLoopStart.15, tLastBlink
.LBB66 = .
.LBB65 = .
	.loc 3 1489 0
	li	$2,1	 # tmp307,
	sw	$2,0($3)	 # tmp307, U1RXR
	.loc 3 1490 0
	lw	$3,.L156	 # tmp308,
	sw	$2,0($3)	 # tmp307, RPB7R
	.loc 3 1501 0
	li	$3,32768	 # tmp311,
	lw	$2,.L157	 # tmp310,
	sw	$3,0($2)	 # tmp311, U1MODE
	.loc 3 1502 0
	addiu	$3,-27648	 # tmp313,
	lw	$2,.L158	 # tmp312,
	sw	$3,0($2)	 # tmp313, U1STA
	.loc 3 1503 0
	li	$3,20	 # tmp315,
	lw	$2,.L159	 # tmp314,
	sw	$3,0($2)	 # tmp315, U1BRG
	b	.L132	 #
.L133:
.LVL111 = .
.LBB64 = .
	.loc 3 1509 0
	lw	$2,.L160	 # tmp316,
	lw	$2,0($2)	 # U1RXREG.24, U1RXREG
.LVL112 = .
.L132:
.LBE64 = .
	.loc 3 1506 0
	lw	$2,.L161	 # tmp317,
	lw	$2,0($2)	 # tmp318,
	li	$3,1	 # tmp319,
	and	$2,$3	 # tmp318, tmp319
	bnez	$2,.L133	 #, tmp318,
.L144:
.LBE65 = .
.LBE66 = .
	.loc 1 142 0
	.set	noreorder
	jal _ISA32M166
	nop
	.align 2
	.set	nomips16
_ISA32M166: 
	.set	reorder
	mfc0	$2, $9, 0
	.set	noreorder
	jal _ISA16M167
	nop
	.align 2
	.set	mips16
_ISA16M167:	nop
	.set	reorder
	.loc 1 148 0
	lw	$3,.L162	 # tmp323,
	lbu	$5,%gprel(active)($16)	 #, active
	lw	$4,%gprel(tLastBlink)($16)	 # tLastBlink, tLastBlink
	.loc 1 142 0
	sw	$2,%gprel(tLoopTime)($16)	 # tLoopTime.17, tLoopTime
	.loc 1 148 0
	srl	$3,$5	 # tmp323, active
	subu	$4,$2,$4	 # tmp321, tLoopTime.17, tLastBlink
	sltu	$4,$3	 # tmp321, tmp323
	btnez	.L134	 #,
	.loc 1 151 0
	li	$4,128	 # tmp327,
	lw	$3,.L163	 # tmp326,
	sw	$4,0($3)	 # tmp327, LATAINV
	.loc 1 154 0
	sw	$2,%gprel(tLastBlink)($16)	 # tLoopTime.17, tLastBlink
.L134:
	.loc 1 160 0
	lbu	$2,%gprel(fLoaded)($16)	 #, fLoaded
	zeb	$2	 # fLoaded.21
	bnez	$2,.L135	 #, fLoaded.21,
	lbu	$2,%gprel(fLoadProgramFromFlash)($16)	 # fLoadProgramFromFlash, fLoadProgramFromFlash
	beqz	$2,.L136	 #, fLoadProgramFromFlash,
.L135:
	.loc 1 179 0
	jal	ExecuteApp	 #
.L136:
.LBB67 = .
.LBB68 = .
	.loc 2 54 0
	lw	$2,.L161	 # tmp330,
	lw	$2,0($2)	 # tmp331,
	li	$3,1	 # tmp332,
	and	$2,$3	 # tmp331, tmp332
	beqz	$2,.L137	 #, tmp331,
	.loc 2 57 0
	lw	$2,.L160	 # tmp333,
	lw	$4,0($2)	 # U1RXREG.32, U1RXREG
	.set	noreorder
	.set	nomacro
	jal	avrbl_state_machine	 #
	zeb	$4	 #
	.set	macro
	.set	reorder

.L137:
.LBE68 = .
.LBE67 = .
	.loc 1 189 0
	lbu	$2,%gprel(ready)($16)	 # ready, ready
	beqz	$2,.L144	 #, ready,
	.loc 1 191 0
	jal	avrbl_message.clone.0.clone.1	 #
	.loc 1 192 0
	li	$2,0	 # tmp336,
	sb	$2,%gprel(ready)($16)	 # tmp336, ready
	b	.L144	 #
	.align	2	 #
.L145:
	.word	RCON
.L146:
	.word	ANSELA
.L147:
	.word	ANSELB
.L148:
	.word	ANSELC
.L149:
	.word	TRISACLR
.L150:
	.word	-1660944384
.L151:
	.word	LATACLR
.L152:
	.word	PORTA
.L153:
	.word	LATA
.L154:
	.word	RCON
.L155:
	.word	U1RXR
.L156:
	.word	RPB7R
.L157:
	.word	U1MODE
.L158:
	.word	U1STA
.L159:
	.word	U1BRG
.L160:
	.word	U1RXREG
.L161:
	.word	U1STA
.L162:
	.word	2500000
.L163:
	.word	LATAINV
# Begin mchp_output_function_epilogue
# End mchp_output_function_epilogue
	.end	main
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.section	.sbss,bss,near
	.type	csum, @object
	.size	csum, 1
csum:
	.space	1
	.align	2
	.type	state, @object
	.size	state, 4
state:
	.space	4
	.type	seq, @object
	.size	seq, 1
seq:
	.space	1
	.align	2
	.type	size, @object
	.size	size, 4
size:
	.space	4
	.align	2
	.type	requesti, @object
	.size	requesti, 4
requesti:
	.space	4
	.section	.bss,bss
	.align	2
	.type	request, @object
	.size	request, 1024
request:
	.space	1024
	.section	.sbss,bss,near
	.type	ready, @object
	.size	ready, 1
ready:
	.space	1
	.align	2
	.type	ramHeader, @object
	.size	ramHeader, 8
ramHeader:
	.space	8
	.type	fLoadProgramFromFlash, @object
	.size	fLoadProgramFromFlash, 1
fLoadProgramFromFlash:
	.space	1
	.align	2
	.type	tLoopStart, @object
	.size	tLoopStart, 4
tLoopStart:
	.space	4
	.align	2
	.type	tLastBlink, @object
	.size	tLastBlink, 4
tLastBlink:
	.space	4
	.align	2
	.type	tLoopTime, @object
	.size	tLoopTime, 4
tLoopTime:
	.space	4
	.type	active, @object
	.size	active, 1
active:
	.space	1
	.type	fLoaded, @object
	.size	fLoaded, 1
fLoaded:
	.space	1
	.section	.sdata,data
	.align	2
	.type	addrBase, @object
	.size	addrBase, 4
addrBase:
	.word	-1660944384
	.align	2
	.type	UserApp, @object
	.size	UserApp, 4
UserApp:
	.word	-1660940288
	.section	.sbss,bss,near
	.align	2
	.type	replyi, @object
	.size	replyi, 4
replyi:
	.space	4
	.section	.bss,bss
	.align	2
	.type	reply, @object
	.size	reply, 1024
reply:
	.space	1024
	.section	.sbss,bss,near
	.type	erased, @object
	.size	erased, 1
erased:
	.space	1
	.section	.sdata,data
	.align	2
	.type	avrdudeAddrBase, @object
	.size	avrdudeAddrBase, 4
avrdudeAddrBase:
	.word	-1660944384
	.section	.bss,bss
	.align	2
	.type	pageMap, @object
	.size	pageMap, 32
pageMap:
	.space	32
	.section	.sdata,data
	.type	fGetBaseAddress.6388, @object
	.size	fGetBaseAddress.6388, 1
fGetBaseAddress.6388:
	.byte	1
	.section	.bss,bss
	.align	2
	.type	parameters.6387, @object
	.size	parameters.6387, 256
parameters.6387:
	.space	256
	.section	.sbss,bss,near
	.align	2
	.type	load_address.6386, @object
	.size	load_address.6386, 4
load_address.6386:
	.space	4
	.section	.sdata,data
	.align	2
	.type	bootloaderVer, @object
	.size	bootloaderVer, 4
bootloaderVer:
	.word	16777479
	.section	.sbss,bss,near
	.align	2
	.type	prodAndVend, @object
	.size	prodAndVend, 4
prodAndVend:
	.space	4
	.section	.sdata,data
	.align	2
	.type	bootloaderCapabilities, @object
	.size	bootloaderCapabilities, 4
bootloaderCapabilities:
	.word	319751729
	.align	2
	.type	cbSkipRam, @object
	.size	cbSkipRam, 4
cbSkipRam:
	.word	_RAM_SKIP_SIZE
	.section	.text,code
.Letext0:
	.section	.debug_loc,info
.Ldebug_loc0:
.LLST0:
	.4byte	.LVL0-.Ltext0
	.4byte	.LVL1-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL1-.Ltext0
	.4byte	.LVL2-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL2-.Ltext0
	.4byte	.LVL3-.Ltext0
	.2byte	0x3
	.byte	0x72
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL3-.Ltext0
	.4byte	.LFE12-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST1:
	.4byte	.LVL7-.Ltext0
	.4byte	.LVL8-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST2:
	.4byte	.LVL5-.Ltext0
	.4byte	.LVL6-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL6-.Ltext0
	.4byte	.LFE15-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST3:
	.4byte	.LVL9-.Ltext0
	.4byte	.LVL10-1-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL10-.Ltext0
	.4byte	.LVL11-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST4:
	.4byte	.LVL12-.Ltext0
	.4byte	.LVL13-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL13-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL16-.Ltext0
	.4byte	.LVL19-.Ltext0
	.2byte	0x5
	.byte	0x3
	.4byte	ramHeader
	.4byte	0x0
	.4byte	0x0
.LLST5:
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST6:
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL19-.Ltext0
	.2byte	0x6
	.byte	0x3
	.4byte	ramHeader
	.byte	0x9f
	.4byte	0x0
	.4byte	0x0
.LLST7:
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST8:
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL18-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL18-.Ltext0
	.4byte	.LVL19-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST9:
	.4byte	.LVL15-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0x6
	.byte	0x3
	.4byte	ramHeader
	.byte	0x9f
	.4byte	.LVL16-.Ltext0
	.4byte	.LVL17-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL17-.Ltext0
	.4byte	.LVL18-.Ltext0
	.2byte	0x3
	.byte	0x74
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL18-.Ltext0
	.4byte	.LVL19-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST10:
	.4byte	.LVL20-.Ltext0
	.4byte	.LVL26-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST11:
	.4byte	.LVL20-.Ltext0
	.4byte	.LVL21-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST12:
	.4byte	.LVL20-.Ltext0
	.4byte	.LVL23-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	0x0
	.4byte	0x0
.LLST13:
	.4byte	.LVL28-.Ltext0
	.4byte	.LVL30-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL32-.Ltext0
	.4byte	.LVL33-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST14:
	.4byte	.LVL34-.Ltext0
	.4byte	.LVL36-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL36-.Ltext0
	.4byte	.LVL41-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	0x0
	.4byte	0x0
.LLST15:
	.4byte	.LVL35-.Ltext0
	.4byte	.LVL36-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	0x0
	.4byte	0x0
.LLST16:
	.4byte	.LVL35-.Ltext0
	.4byte	.LVL36-.Ltext0
	.2byte	0x3
	.byte	0x9
	.byte	0xff
	.byte	0x9f
	.4byte	.LVL36-.Ltext0
	.4byte	.LVL37-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL37-.Ltext0
	.4byte	.LVL38-1-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL38-.Ltext0
	.4byte	.LVL39-.Ltext0
	.2byte	0x2
	.byte	0x91
	.sleb128 16
	.4byte	.LVL40-.Ltext0
	.4byte	.LFE18-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST17:
	.4byte	.LVL35-.Ltext0
	.4byte	.LVL36-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL36-.Ltext0
	.4byte	.LVL41-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	0x0
	.4byte	0x0
.LLST18:
	.4byte	.LVL42-.Ltext0
	.4byte	.LVL48-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST19:
	.4byte	.LVL42-.Ltext0
	.4byte	.LVL44-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL44-.Ltext0
	.4byte	.LVL45-.Ltext0
	.2byte	0x3
	.byte	0x75
	.sleb128 1
	.byte	0x9f
	.4byte	0x0
	.4byte	0x0
.LLST20:
	.4byte	.LVL43-.Ltext0
	.4byte	.LVL50-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	.LVL50-.Ltext0
	.4byte	.LVL51-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	0x0
	.4byte	0x0
.LLST21:
	.4byte	.LVL46-.Ltext0
	.4byte	.LVL48-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST22:
	.4byte	.LVL47-.Ltext0
	.4byte	.LVL49-.Ltext0
	.2byte	0x1
	.byte	0x61
	.4byte	.LVL49-.Ltext0
	.4byte	.LVL51-.Ltext0
	.2byte	0x1
	.byte	0x61
	.4byte	0x0
	.4byte	0x0
.LLST23:
	.4byte	.LVL52-.Ltext0
	.4byte	.LVL53-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL53-.Ltext0
	.4byte	.LVL55-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	.LVL55-.Ltext0
	.4byte	.LVL58-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	0x0
	.4byte	0x0
.LLST24:
	.4byte	.LVL52-.Ltext0
	.4byte	.LVL53-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST25:
	.4byte	.LVL52-.Ltext0
	.4byte	.LVL53-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	0x0
	.4byte	0x0
.LLST26:
	.4byte	.LVL52-.Ltext0
	.4byte	.LVL53-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL53-.Ltext0
	.4byte	.LVL54-1-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL56-.Ltext0
	.4byte	.LVL57-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL57-.Ltext0
	.4byte	.LFE19-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST27:
	.4byte	.LVL60-.Ltext0
	.4byte	.LVL61-1-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL61-1-.Ltext0
	.4byte	.LVL67-.Ltext0
	.2byte	0x1
	.byte	0x60
	.4byte	0x0
	.4byte	0x0
.LLST28:
	.4byte	.LVL59-.Ltext0
	.4byte	.LVL62-.Ltext0
	.2byte	0x6
	.byte	0xd
	.4byte	0x9d000000
	.byte	0x9f
	.4byte	.LVL62-.Ltext0
	.4byte	.LVL64-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL64-.Ltext0
	.4byte	.LVL65-.Ltext0
	.2byte	0x6
	.byte	0xd
	.4byte	0x9d000000
	.byte	0x9f
	.4byte	.LVL65-.Ltext0
	.4byte	.LVL66-1-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST29:
	.4byte	.LVL59-.Ltext0
	.4byte	.LVL63-.Ltext0
	.2byte	0x6
	.byte	0xd
	.4byte	0x9d007000
	.byte	0x9f
	.4byte	.LVL63-.Ltext0
	.4byte	.LVL64-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL64-.Ltext0
	.4byte	.LVL65-.Ltext0
	.2byte	0x6
	.byte	0xd
	.4byte	0x9d007000
	.byte	0x9f
	.4byte	.LVL65-.Ltext0
	.4byte	.LVL66-1-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST30:
	.4byte	.LVL76-.Ltext0
	.4byte	.LVL77-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL77-.Ltext0
	.4byte	.LVL78-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL78-.Ltext0
	.4byte	.LVL79-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL97-.Ltext0
	.4byte	.LVL98-.Ltext0
	.2byte	0x2
	.byte	0x35
	.byte	0x9f
	.4byte	.LVL98-.Ltext0
	.4byte	.LVL99-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL99-.Ltext0
	.4byte	.LVL100-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL100-.Ltext0
	.4byte	.LVL101-.Ltext0
	.2byte	0x3
	.byte	0x73
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL101-.Ltext0
	.4byte	.LVL102-1-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST31:
	.4byte	.LVL75-.Ltext0
	.4byte	.LVL82-1-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0x0
	.4byte	0x0
.LLST32:
	.4byte	.LVL76-.Ltext0
	.4byte	.LVL83-.Ltext0
	.2byte	0x1
	.byte	0x61
	.4byte	0x0
	.4byte	0x0
.LLST33:
	.4byte	.LVL84-.Ltext0
	.4byte	.LVL91-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST34:
	.4byte	.LVL92-.Ltext0
	.4byte	.LVL93-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL93-.Ltext0
	.4byte	.LVL94-.Ltext0
	.2byte	0x2
	.byte	0x31
	.byte	0x9f
	.4byte	.LVL94-.Ltext0
	.4byte	.LVL95-.Ltext0
	.2byte	0x2
	.byte	0x32
	.byte	0x9f
	.4byte	.LVL95-.Ltext0
	.4byte	.LVL96-.Ltext0
	.2byte	0x2
	.byte	0x33
	.byte	0x9f
	.4byte	.LVL96-.Ltext0
	.4byte	.LVL97-.Ltext0
	.2byte	0x2
	.byte	0x34
	.byte	0x9f
	.4byte	.LVL97-.Ltext0
	.4byte	.LFE22-.Ltext0
	.2byte	0x2
	.byte	0x35
	.byte	0x9f
	.4byte	0x0
	.4byte	0x0
.LLST35:
	.4byte	.LVL69-.Ltext0
	.4byte	.LVL70-.Ltext0
	.2byte	0x6
	.byte	0x3
	.4byte	.LC17
	.byte	0x9f
	.4byte	.LVL70-.Ltext0
	.4byte	.LVL71-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL71-.Ltext0
	.4byte	.LVL72-.Ltext0
	.2byte	0x3
	.byte	0x73
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL72-.Ltext0
	.4byte	.LVL73-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST36:
	.4byte	.LVL69-.Ltext0
	.4byte	.LVL72-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL72-.Ltext0
	.4byte	.LVL74-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST37:
	.4byte	.LVL69-.Ltext0
	.4byte	.LVL70-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST38:
	.4byte	.LVL80-.Ltext0
	.4byte	.LVL81-.Ltext0
	.2byte	0x5
	.byte	0x3
	.4byte	request+260
	.4byte	0x0
	.4byte	0x0
.LLST39:
	.4byte	.LVL85-.Ltext0
	.4byte	.LVL87-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL88-.Ltext0
	.4byte	.LVL89-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL89-.Ltext0
	.4byte	.LVL90-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0x0
	.4byte	0x0
.LLST40:
	.4byte	.LVL86-.Ltext0
	.4byte	.LVL90-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0x0
	.4byte	0x0
.LLST41:
	.4byte	.LVL103-.Ltext0
	.4byte	.LVL104-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL105-.Ltext0
	.4byte	.LVL106-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL107-.Ltext0
	.4byte	.LVL108-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL109-.Ltext0
	.4byte	.LVL110-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0x0
	.4byte	0x0
.LLST42:
	.4byte	.LVL111-.Ltext0
	.4byte	.LVL112-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	0x0
	.4byte	0x0
	.file 5 "c:/users/keithv.keithsofficepc/documents/digitent/bootloaders/chipkit-bootloader-projects/mplab c32 suite/bin/../lib/gcc/pic32mx/4.5.1/../../../../pic32mx/include/proc/p32mx120f032d.h"
	.file 6 "main.h"
	.section	.debug_info,info
	.4byte	0x1775
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii	"GNU C 4.5.1 MPLAB C Compiler for PIC32 MCUs v2.02-201111"
	.ascii	"16\000"
	.byte	0x1
	.ascii	"main.c\000"
	.ascii	"C:\\\\Users\\\\KeithV.KeithsOfficePC\\\\Documents\\\\Dig"
	.ascii	"itent\\\\Bootloaders\\\\chipKIT-Bootloader-Projects\\\\c"
	.ascii	"hipKIT\000"
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii	"unsigned int\000"
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x565
	.4byte	0x220
	.uleb128 0x4
	.ascii	"URXDA\000"
	.byte	0x5
	.2byte	0x566
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1f
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"OERR\000"
	.byte	0x5
	.2byte	0x567
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1e
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"FERR\000"
	.byte	0x5
	.2byte	0x568
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1d
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"PERR\000"
	.byte	0x5
	.2byte	0x569
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RIDLE\000"
	.byte	0x5
	.2byte	0x56a
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"ADDEN\000"
	.byte	0x5
	.2byte	0x56b
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1a
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"URXISEL\000"
	.byte	0x5
	.2byte	0x56c
	.4byte	0xc4
	.byte	0x4
	.byte	0x2
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"TRMT\000"
	.byte	0x5
	.2byte	0x56d
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x17
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXBF\000"
	.byte	0x5
	.2byte	0x56e
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x16
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXEN\000"
	.byte	0x5
	.2byte	0x56f
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x15
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXBRK\000"
	.byte	0x5
	.2byte	0x570
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x14
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"URXEN\000"
	.byte	0x5
	.2byte	0x571
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x13
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXINV\000"
	.byte	0x5
	.2byte	0x572
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x12
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXISEL\000"
	.byte	0x5
	.2byte	0x573
	.4byte	0xc4
	.byte	0x4
	.byte	0x2
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"ADDR\000"
	.byte	0x5
	.2byte	0x574
	.4byte	0xc4
	.byte	0x4
	.byte	0x8
	.byte	0x8
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"ADM_EN\000"
	.byte	0x5
	.2byte	0x575
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x7
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x577
	.4byte	0x286
	.uleb128 0x4
	.ascii	"URXISEL0\000"
	.byte	0x5
	.2byte	0x579
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x19
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"URXISEL1\000"
	.byte	0x5
	.2byte	0x57a
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXISEL0\000"
	.byte	0x5
	.2byte	0x57c
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x11
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"UTXISEL1\000"
	.byte	0x5
	.2byte	0x57d
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x57f
	.4byte	0x2a5
	.uleb128 0x4
	.ascii	"UTXSEL\000"
	.byte	0x5
	.2byte	0x581
	.4byte	0xc4
	.byte	0x4
	.byte	0x2
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x583
	.4byte	0x2bf
	.uleb128 0x4
	.ascii	"w\000"
	.byte	0x5
	.2byte	0x584
	.4byte	0xc4
	.byte	0x4
	.byte	0x20
	.byte	0x0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.2byte	0x564
	.4byte	0x2dd
	.uleb128 0x6
	.4byte	0xd4
	.uleb128 0x6
	.4byte	0x220
	.uleb128 0x6
	.4byte	0x286
	.uleb128 0x6
	.4byte	0x2a5
	.byte	0x0
	.uleb128 0x7
	.ascii	"__U1STAbits_t\000"
	.byte	0x5
	.2byte	0x586
	.4byte	0x2bf
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x945
	.4byte	0x3a6
	.uleb128 0x4
	.ascii	"POR\000"
	.byte	0x5
	.2byte	0x946
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1f
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"BOR\000"
	.byte	0x5
	.2byte	0x947
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1e
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"IDLE\000"
	.byte	0x5
	.2byte	0x948
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1d
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"SLEEP\000"
	.byte	0x5
	.2byte	0x949
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"WDTO\000"
	.byte	0x5
	.2byte	0x94a
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"SWR\000"
	.byte	0x5
	.2byte	0x94c
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x19
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"EXTR\000"
	.byte	0x5
	.2byte	0x94d
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"VREGS\000"
	.byte	0x5
	.2byte	0x94e
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x17
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"CMR\000"
	.byte	0x5
	.2byte	0x94f
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x16
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x951
	.4byte	0x3c0
	.uleb128 0x4
	.ascii	"w\000"
	.byte	0x5
	.2byte	0x952
	.4byte	0xc4
	.byte	0x4
	.byte	0x20
	.byte	0x0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.2byte	0x944
	.4byte	0x3d4
	.uleb128 0x6
	.4byte	0x2f3
	.uleb128 0x6
	.4byte	0x3a6
	.byte	0x0
	.uleb128 0x7
	.ascii	"__RCONbits_t\000"
	.byte	0x5
	.2byte	0x954
	.4byte	0x3c0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x10a5
	.4byte	0x496
	.uleb128 0x4
	.ascii	"RA0\000"
	.byte	0x5
	.2byte	0x10a6
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1f
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA1\000"
	.byte	0x5
	.2byte	0x10a7
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1e
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA2\000"
	.byte	0x5
	.2byte	0x10a8
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1d
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA3\000"
	.byte	0x5
	.2byte	0x10a9
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA4\000"
	.byte	0x5
	.2byte	0x10aa
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA7\000"
	.byte	0x5
	.2byte	0x10ac
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA8\000"
	.byte	0x5
	.2byte	0x10ad
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x17
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA9\000"
	.byte	0x5
	.2byte	0x10ae
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x16
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"RA10\000"
	.byte	0x5
	.2byte	0x10af
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x15
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x10b1
	.4byte	0x4b0
	.uleb128 0x4
	.ascii	"w\000"
	.byte	0x5
	.2byte	0x10b2
	.4byte	0xc4
	.byte	0x4
	.byte	0x20
	.byte	0x0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.2byte	0x10a4
	.4byte	0x4c4
	.uleb128 0x6
	.4byte	0x3e9
	.uleb128 0x6
	.4byte	0x496
	.byte	0x0
	.uleb128 0x7
	.ascii	"__PORTAbits_t\000"
	.byte	0x5
	.2byte	0x10b4
	.4byte	0x4b0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x10bb
	.4byte	0x599
	.uleb128 0x4
	.ascii	"LATA0\000"
	.byte	0x5
	.2byte	0x10bc
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1f
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA1\000"
	.byte	0x5
	.2byte	0x10bd
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1e
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA2\000"
	.byte	0x5
	.2byte	0x10be
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1d
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA3\000"
	.byte	0x5
	.2byte	0x10bf
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA4\000"
	.byte	0x5
	.2byte	0x10c0
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x1b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA7\000"
	.byte	0x5
	.2byte	0x10c2
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA8\000"
	.byte	0x5
	.2byte	0x10c3
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x17
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA9\000"
	.byte	0x5
	.2byte	0x10c4
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x16
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x4
	.ascii	"LATA10\000"
	.byte	0x5
	.2byte	0x10c5
	.4byte	0xc4
	.byte	0x4
	.byte	0x1
	.byte	0x15
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.2byte	0x10c7
	.4byte	0x5b3
	.uleb128 0x4
	.ascii	"w\000"
	.byte	0x5
	.2byte	0x10c8
	.4byte	0xc4
	.byte	0x4
	.byte	0x20
	.byte	0x0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.2byte	0x10ba
	.4byte	0x5c7
	.uleb128 0x6
	.4byte	0x4da
	.uleb128 0x6
	.4byte	0x599
	.byte	0x0
	.uleb128 0x7
	.ascii	"__LATAbits_t\000"
	.byte	0x5
	.2byte	0x10ca
	.4byte	0x5b3
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii	"long unsigned int\000"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii	"char\000"
	.uleb128 0x8
	.ascii	"uint8\000"
	.byte	0x6
	.byte	0x2a
	.4byte	0x606
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.ascii	"unsigned char\000"
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.ascii	"short int\000"
	.uleb128 0x8
	.ascii	"uint16\000"
	.byte	0x6
	.byte	0x2c
	.4byte	0x632
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii	"short unsigned int\000"
	.uleb128 0x8
	.ascii	"int32\000"
	.byte	0x6
	.byte	0x2d
	.4byte	0x655
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x8
	.ascii	"uint32\000"
	.byte	0x6
	.byte	0x2e
	.4byte	0xc4
	.uleb128 0x8
	.ascii	"intptr\000"
	.byte	0x6
	.byte	0x2f
	.4byte	0x655
	.uleb128 0x8
	.ascii	"bool\000"
	.byte	0x6
	.byte	0x32
	.4byte	0x606
	.uleb128 0x8
	.ascii	"byte\000"
	.byte	0x6
	.byte	0x33
	.4byte	0x606
	.uleb128 0x9
	.byte	0x4
	.byte	0x6
	.byte	0x36
	.4byte	0x6a8
	.uleb128 0xa
	.ascii	"false\000"
	.sleb128 0
	.uleb128 0xa
	.ascii	"true\000"
	.sleb128 1
	.byte	0x0
	.uleb128 0x8
	.ascii	"FNUSERAPP\000"
	.byte	0x6
	.byte	0x57
	.4byte	0x6b9
	.uleb128 0xb
	.byte	0x4
	.4byte	0x6bf
	.uleb128 0xc
	.4byte	0x6c4
	.uleb128 0xd
	.byte	0x1
	.uleb128 0xe
	.byte	0x8
	.byte	0x6
	.byte	0x6f
	.4byte	0x6f6
	.uleb128 0xf
	.ascii	"cbBlRamHeader\000"
	.byte	0x6
	.byte	0x70
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xf
	.ascii	"rcon\000"
	.byte	0x6
	.byte	0x71
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.ascii	"RAM_HEADER_INFO\000"
	.byte	0x6
	.byte	0x72
	.4byte	0x6c6
	.uleb128 0xe
	.byte	0x40
	.byte	0x6
	.byte	0x74
	.4byte	0x869
	.uleb128 0xf
	.ascii	"cbHeader\000"
	.byte	0x6
	.byte	0x75
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xf
	.ascii	"verBootloader\000"
	.byte	0x6
	.byte	0x76
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xf
	.ascii	"verMPIDE\000"
	.byte	0x6
	.byte	0x77
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x10
	.4byte	.LASF0
	.byte	0x6
	.byte	0x78
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xf
	.ascii	"vend\000"
	.byte	0x6
	.byte	0x79
	.4byte	0x624
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xf
	.ascii	"prod\000"
	.byte	0x6
	.byte	0x7a
	.4byte	0x624
	.byte	0x2
	.byte	0x23
	.uleb128 0x12
	.uleb128 0xf
	.ascii	"imageType\000"
	.byte	0x6
	.byte	0x7b
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xf
	.ascii	"pJumpAddr\000"
	.byte	0x6
	.byte	0x7c
	.4byte	0x6a8
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0xf
	.ascii	"pProgramFlash\000"
	.byte	0x6
	.byte	0x7d
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0xf
	.ascii	"cbProgramFlash\000"
	.byte	0x6
	.byte	0x7e
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0xf
	.ascii	"pEEProm\000"
	.byte	0x6
	.byte	0x7f
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0xf
	.ascii	"cbEEProm\000"
	.byte	0x6
	.byte	0x80
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0xf
	.ascii	"pConfig\000"
	.byte	0x6
	.byte	0x81
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.uleb128 0xf
	.ascii	"cbConfig\000"
	.byte	0x6
	.byte	0x82
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0xf
	.ascii	"pRamHeader\000"
	.byte	0x6
	.byte	0x83
	.4byte	0x869
	.byte	0x2
	.byte	0x23
	.uleb128 0x34
	.uleb128 0xf
	.ascii	"cbRamHeader\000"
	.byte	0x6
	.byte	0x84
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x38
	.uleb128 0xf
	.ascii	"cbBlPreservedRam\000"
	.byte	0x6
	.byte	0x85
	.4byte	0x65c
	.byte	0x2
	.byte	0x23
	.uleb128 0x3c
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x6f6
	.uleb128 0x8
	.ascii	"IMAGE_HEADER_INFO\000"
	.byte	0x6
	.byte	0x86
	.4byte	0x70d
	.uleb128 0x9
	.byte	0x4
	.byte	0x1
	.byte	0x11
	.4byte	0x8fb
	.uleb128 0xa
	.ascii	"STATE_START\000"
	.sleb128 0
	.uleb128 0xa
	.ascii	"STATE_GETSEQ\000"
	.sleb128 1
	.uleb128 0xa
	.ascii	"STATE_GETMS1\000"
	.sleb128 2
	.uleb128 0xa
	.ascii	"STATE_GETMS2\000"
	.sleb128 3
	.uleb128 0xa
	.ascii	"STATE_GETTOK\000"
	.sleb128 4
	.uleb128 0xa
	.ascii	"STATE_GETDATA\000"
	.sleb128 5
	.uleb128 0xa
	.ascii	"STATE_GETCSUM\000"
	.sleb128 6
	.byte	0x0
	.uleb128 0x11
	.ascii	"serial_print\000"
	.byte	0x2
	.byte	0x26
	.byte	0x1
	.byte	0x3
	.4byte	0x935
	.uleb128 0x12
	.ascii	"line\000"
	.byte	0x2
	.byte	0x26
	.4byte	0x935
	.uleb128 0x12
	.ascii	"length\000"
	.byte	0x2
	.byte	0x26
	.4byte	0x655
	.uleb128 0x13
	.ascii	"i\000"
	.byte	0x2
	.byte	0x28
	.4byte	0x655
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x93b
	.uleb128 0x14
	.4byte	0x684
	.uleb128 0x15
	.ascii	"UninitStk500v2Interface\000"
	.byte	0x3
	.2byte	0x5e9
	.byte	0x1
	.byte	0x3
	.uleb128 0x15
	.ascii	"UninitLEDsAndButtons\000"
	.byte	0x3
	.2byte	0x588
	.byte	0x1
	.byte	0x3
	.uleb128 0x16
	.ascii	"ilmemcpy\000"
	.byte	0x4
	.byte	0xe
	.byte	0x1
	.4byte	0x9c5
	.byte	0x3
	.4byte	0x9c5
	.uleb128 0x12
	.ascii	"d\000"
	.byte	0x4
	.byte	0xe
	.4byte	0x9c5
	.uleb128 0x12
	.ascii	"s\000"
	.byte	0x4
	.byte	0xe
	.4byte	0x9c7
	.uleb128 0x12
	.ascii	"n\000"
	.byte	0x4
	.byte	0xe
	.4byte	0xc4
	.uleb128 0x13
	.ascii	"dtemp\000"
	.byte	0x4
	.byte	0x10
	.4byte	0x9ce
	.uleb128 0x13
	.ascii	"stemp\000"
	.byte	0x4
	.byte	0x11
	.4byte	0x9d4
	.byte	0x0
	.uleb128 0x17
	.byte	0x4
	.uleb128 0xb
	.byte	0x4
	.4byte	0x9cd
	.uleb128 0x18
	.uleb128 0xb
	.byte	0x4
	.4byte	0x5f9
	.uleb128 0xb
	.byte	0x4
	.4byte	0x9da
	.uleb128 0x14
	.4byte	0x5f9
	.uleb128 0x16
	.ascii	"ilstrcpy\000"
	.byte	0x4
	.byte	0x23
	.byte	0x1
	.4byte	0xa1e
	.byte	0x3
	.4byte	0xa1e
	.uleb128 0x12
	.ascii	"dest\000"
	.byte	0x4
	.byte	0x23
	.4byte	0xa1e
	.uleb128 0x12
	.ascii	"src\000"
	.byte	0x4
	.byte	0x23
	.4byte	0xa24
	.uleb128 0x13
	.ascii	"orig_dest\000"
	.byte	0x4
	.byte	0x25
	.4byte	0xa1e
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x5f1
	.uleb128 0xb
	.byte	0x4
	.4byte	0xa2a
	.uleb128 0x14
	.4byte	0x5f1
	.uleb128 0x19
	.ascii	"avrbl_message\000"
	.byte	0x1
	.2byte	0x112
	.byte	0x1
	.byte	0x0
	.4byte	0xb58
	.uleb128 0x1a
	.ascii	"request\000"
	.byte	0x1
	.2byte	0x112
	.4byte	0xb58
	.uleb128 0x1a
	.ascii	"size\000"
	.byte	0x1
	.2byte	0x112
	.4byte	0x655
	.uleb128 0x1b
	.ascii	"load_address\000"
	.byte	0x1
	.2byte	0x114
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"parameters\000"
	.byte	0x1
	.2byte	0x115
	.4byte	0xb5e
	.uleb128 0x1b
	.ascii	"fGetBaseAddress\000"
	.byte	0x1
	.2byte	0x116
	.4byte	0x678
	.uleb128 0x1b
	.ascii	"i\000"
	.byte	0x1
	.2byte	0x118
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"nbytes\000"
	.byte	0x1
	.2byte	0x119
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"nbytesAligned\000"
	.byte	0x1
	.2byte	0x11a
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"endAddr\000"
	.byte	0x1
	.2byte	0x11b
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"address\000"
	.byte	0x1
	.2byte	0x11c
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"rawi\000"
	.byte	0x1
	.2byte	0x11d
	.4byte	0x655
	.uleb128 0x1b
	.ascii	"raw\000"
	.byte	0x1
	.2byte	0x11e
	.4byte	0xb6e
	.uleb128 0x1b
	.ascii	"temp\000"
	.byte	0x1
	.2byte	0x11f
	.4byte	0x65c
	.uleb128 0x1c
	.4byte	0xb31
	.uleb128 0x1b
	.ascii	"addrBaseT\000"
	.byte	0x1
	.2byte	0x18c
	.4byte	0x65c
	.byte	0x0
	.uleb128 0x1d
	.uleb128 0x1b
	.ascii	"addrEndPage\000"
	.byte	0x1
	.2byte	0x1ac
	.4byte	0x65c
	.uleb128 0x1b
	.ascii	"lieMask\000"
	.byte	0x1
	.2byte	0x1ad
	.4byte	0x684
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x684
	.uleb128 0x1e
	.4byte	0x684
	.4byte	0xb6e
	.uleb128 0x1f
	.4byte	0x5dc
	.byte	0xff
	.byte	0x0
	.uleb128 0x1e
	.4byte	0x684
	.4byte	0xb7e
	.uleb128 0x1f
	.4byte	0x5dc
	.byte	0x3f
	.byte	0x0
	.uleb128 0x15
	.ascii	"InitLEDsAndButtons\000"
	.byte	0x3
	.2byte	0x555
	.byte	0x1
	.byte	0x3
	.uleb128 0x19
	.ascii	"InitStk500v2Interface\000"
	.byte	0x3
	.2byte	0x5c4
	.byte	0x1
	.byte	0x3
	.4byte	0xbc8
	.uleb128 0x1d
	.uleb128 0x1b
	.ascii	"value\000"
	.byte	0x3
	.2byte	0x5e4
	.4byte	0x684
	.byte	0x0
	.byte	0x0
	.uleb128 0x20
	.ascii	"serial_isr\000"
	.byte	0x2
	.byte	0x33
	.byte	0x1
	.byte	0x3
	.uleb128 0x21
	.ascii	"avrbl_print\000"
	.byte	0x1
	.2byte	0x10b
	.byte	0x1
	.4byte	.LFB12
	.4byte	.LFE12
	.byte	0x1
	.byte	0x6d
	.4byte	0xc4c
	.uleb128 0x22
	.ascii	"buffer\000"
	.byte	0x1
	.2byte	0x10b
	.4byte	0x935
	.byte	0x1
	.byte	0x54
	.uleb128 0x22
	.ascii	"length\000"
	.byte	0x1
	.2byte	0x10b
	.4byte	0x655
	.byte	0x1
	.byte	0x55
	.uleb128 0x23
	.4byte	0x8fb
	.4byte	.LBB38
	.4byte	.LBE38
	.byte	0x1
	.2byte	0x10d
	.uleb128 0x24
	.4byte	0x91d
	.byte	0x1
	.byte	0x55
	.uleb128 0x24
	.4byte	0x911
	.byte	0x1
	.byte	0x54
	.uleb128 0x25
	.4byte	.LBB39
	.4byte	.LBE39
	.uleb128 0x26
	.4byte	0x92b
	.4byte	.LLST0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x27
	.ascii	"getHeaderStructure\000"
	.byte	0x1
	.2byte	0x23d
	.byte	0x1
	.4byte	0xcc1
	.4byte	.LFB15
	.4byte	.LFE15
	.byte	0x1
	.byte	0x6d
	.4byte	0xcc1
	.uleb128 0x22
	.ascii	"imageBaseAddr\000"
	.byte	0x1
	.2byte	0x23d
	.4byte	0x65c
	.byte	0x1
	.byte	0x54
	.uleb128 0x28
	.4byte	.LASF1
	.byte	0x1
	.2byte	0x23f
	.4byte	0xcc1
	.4byte	.LLST1
	.uleb128 0x29
	.ascii	"addr\000"
	.byte	0x1
	.2byte	0x240
	.4byte	0x65c
	.4byte	.LLST2
	.uleb128 0x2a
	.4byte	.LASF2
	.byte	0x1
	.2byte	0x241
	.4byte	0x65c
	.sleb128 -1660911616
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x86f
	.uleb128 0x21
	.ascii	"ExecuteApp\000"
	.byte	0x1
	.2byte	0x1f5
	.byte	0x1
	.4byte	.LFB14
	.4byte	.LFE14
	.byte	0x1
	.byte	0x6d
	.4byte	0xd73
	.uleb128 0x28
	.4byte	.LASF1
	.byte	0x1
	.2byte	0x1f7
	.4byte	0xcc1
	.4byte	.LLST3
	.uleb128 0x2b
	.4byte	0x940
	.4byte	.LBB40
	.4byte	.Ldebug_ranges0+0x0
	.byte	0x1
	.2byte	0x1f9
	.uleb128 0x2b
	.4byte	0x95e
	.4byte	.LBB44
	.4byte	.Ldebug_ranges0+0x18
	.byte	0x1
	.2byte	0x1fa
	.uleb128 0x25
	.4byte	.LBB48
	.4byte	.LBE48
	.uleb128 0x29
	.ascii	"cb\000"
	.byte	0x1
	.2byte	0x218
	.4byte	0x65c
	.4byte	.LLST4
	.uleb128 0x2c
	.4byte	0x979
	.4byte	.LBB49
	.4byte	.Ldebug_ranges0+0x30
	.byte	0x1
	.2byte	0x221
	.uleb128 0x2d
	.4byte	0x9a1
	.4byte	.LLST5
	.uleb128 0x2d
	.4byte	0x998
	.4byte	.LLST6
	.uleb128 0x2d
	.4byte	0x98f
	.4byte	.LLST7
	.uleb128 0x2e
	.4byte	.Ldebug_ranges0+0x48
	.uleb128 0x26
	.4byte	0x9aa
	.4byte	.LLST8
	.uleb128 0x26
	.4byte	0x9b7
	.4byte	.LLST9
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x21
	.ascii	"flashOperation\000"
	.byte	0x1
	.2byte	0x2b5
	.byte	0x1
	.4byte	.LFB17
	.4byte	.LFE17
	.byte	0x1
	.byte	0x6d
	.4byte	0xde8
	.uleb128 0x2f
	.ascii	"nvmop\000"
	.byte	0x1
	.2byte	0x2b5
	.4byte	0x65c
	.4byte	.LLST10
	.uleb128 0x2f
	.ascii	"addr\000"
	.byte	0x1
	.2byte	0x2b5
	.4byte	0x65c
	.4byte	.LLST11
	.uleb128 0x2f
	.ascii	"data\000"
	.byte	0x1
	.2byte	0x2b5
	.4byte	0x65c
	.4byte	.LLST12
	.uleb128 0x29
	.ascii	"t0\000"
	.byte	0x1
	.2byte	0x2b7
	.4byte	0x5dc
	.4byte	.LLST13
	.uleb128 0x1b
	.ascii	"status\000"
	.byte	0x1
	.2byte	0x2b8
	.4byte	0xc4
	.byte	0x0
	.uleb128 0x21
	.ascii	"flashErasePage\000"
	.byte	0x1
	.2byte	0x30e
	.byte	0x1
	.4byte	.LFB18
	.4byte	.LFE18
	.byte	0x1
	.byte	0x6d
	.4byte	0xe5b
	.uleb128 0x2f
	.ascii	"addrPage\000"
	.byte	0x1
	.2byte	0x30e
	.4byte	0x65c
	.4byte	.LLST14
	.uleb128 0x1b
	.ascii	"i\000"
	.byte	0x1
	.2byte	0x310
	.4byte	0x655
	.uleb128 0x29
	.ascii	"j\000"
	.byte	0x1
	.2byte	0x311
	.4byte	0x655
	.4byte	.LLST15
	.uleb128 0x29
	.ascii	"x\000"
	.byte	0x1
	.2byte	0x312
	.4byte	0x648
	.4byte	.LLST16
	.uleb128 0x29
	.ascii	"rgUint32\000"
	.byte	0x1
	.2byte	0x313
	.4byte	0xe5b
	.4byte	.LLST17
	.byte	0x0
	.uleb128 0xb
	.byte	0x4
	.4byte	0x65c
	.uleb128 0x21
	.ascii	"justInTimeFlashErase\000"
	.byte	0x1
	.2byte	0x369
	.byte	0x1
	.4byte	.LFB20
	.4byte	.LFE20
	.byte	0x1
	.byte	0x6d
	.4byte	0xef1
	.uleb128 0x2f
	.ascii	"addrLow\000"
	.byte	0x1
	.2byte	0x369
	.4byte	0x65c
	.4byte	.LLST18
	.uleb128 0x30
	.4byte	.LASF2
	.byte	0x1
	.2byte	0x369
	.4byte	0x65c
	.4byte	.LLST19
	.uleb128 0x29
	.ascii	"addrCurPage\000"
	.byte	0x1
	.2byte	0x36b
	.4byte	0x65c
	.4byte	.LLST20
	.uleb128 0x29
	.ascii	"addrLastPage\000"
	.byte	0x1
	.2byte	0x36c
	.4byte	0x65c
	.4byte	.LLST21
	.uleb128 0x29
	.ascii	"iPage\000"
	.byte	0x1
	.2byte	0x36d
	.4byte	0x65c
	.4byte	.LLST22
	.byte	0x0
	.uleb128 0x21
	.ascii	"flashWriteUint32\000"
	.byte	0x1
	.2byte	0x343
	.byte	0x1
	.4byte	.LFB19
	.4byte	.LFE19
	.byte	0x1
	.byte	0x6d
	.4byte	0xf66
	.uleb128 0x2f
	.ascii	"addrUint32\000"
	.byte	0x1
	.2byte	0x343
	.4byte	0x65c
	.4byte	.LLST23
	.uleb128 0x2f
	.ascii	"rgu32Data\000"
	.byte	0x1
	.2byte	0x343
	.4byte	0xe5b
	.4byte	.LLST24
	.uleb128 0x2f
	.ascii	"cu32Data\000"
	.byte	0x1
	.2byte	0x343
	.4byte	0x65c
	.4byte	.LLST25
	.uleb128 0x29
	.ascii	"i\000"
	.byte	0x1
	.2byte	0x345
	.4byte	0x655
	.4byte	.LLST26
	.byte	0x0
	.uleb128 0x21
	.ascii	"finshFlashProcessingAfterLoad\000"
	.byte	0x1
	.2byte	0x26a
	.byte	0x1
	.4byte	.LFB16
	.4byte	.LFE16
	.byte	0x1
	.byte	0x6d
	.4byte	0xfcc
	.uleb128 0x28
	.4byte	.LASF1
	.byte	0x1
	.2byte	0x26c
	.4byte	0xcc1
	.4byte	.LLST27
	.uleb128 0x29
	.ascii	"addrLow\000"
	.byte	0x1
	.2byte	0x270
	.4byte	0x65c
	.4byte	.LLST28
	.uleb128 0x28
	.4byte	.LASF2
	.byte	0x1
	.2byte	0x271
	.4byte	0x65c
	.4byte	.LLST29
	.byte	0x0
	.uleb128 0x31
	.4byte	0xa2f
	.4byte	.LFB22
	.4byte	.LFE22
	.byte	0x1
	.byte	0x6d
	.4byte	0x10b5
	.uleb128 0x26
	.4byte	0xaa4
	.4byte	.LLST30
	.uleb128 0x26
	.4byte	0xaae
	.4byte	.LLST31
	.uleb128 0x26
	.4byte	0xabd
	.4byte	.LLST32
	.uleb128 0x26
	.4byte	0xad3
	.4byte	.LLST33
	.uleb128 0x32
	.4byte	0xb00
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x24
	.4byte	0xa47
	.byte	0x6
	.byte	0x3
	.4byte	request+2
	.byte	0x9f
	.uleb128 0x32
	.4byte	0xa64
	.byte	0x5
	.byte	0x3
	.4byte	load_address.6386
	.uleb128 0x32
	.4byte	0xa79
	.byte	0x5
	.byte	0x3
	.4byte	parameters.6387
	.uleb128 0x32
	.4byte	0xa8c
	.byte	0x5
	.byte	0x3
	.4byte	fGetBaseAddress.6388
	.uleb128 0x33
	.4byte	0xae3
	.uleb128 0x26
	.4byte	0xaf3
	.4byte	.LLST34
	.uleb128 0x33
	.4byte	0xb0c
	.uleb128 0x34
	.4byte	0x9df
	.4byte	.LBB53
	.4byte	.LBE53
	.byte	0x1
	.2byte	0x133
	.4byte	0x1085
	.uleb128 0x2d
	.4byte	0xa01
	.4byte	.LLST35
	.uleb128 0x2d
	.4byte	0x9f5
	.4byte	.LLST36
	.uleb128 0x25
	.4byte	.LBB54
	.4byte	.LBE54
	.uleb128 0x26
	.4byte	0xa0c
	.4byte	.LLST37
	.byte	0x0
	.byte	0x0
	.uleb128 0x35
	.4byte	.LBB55
	.4byte	.LBE55
	.4byte	0x109c
	.uleb128 0x26
	.4byte	0xb1e
	.4byte	.LLST38
	.byte	0x0
	.uleb128 0x2e
	.4byte	.Ldebug_ranges0+0x60
	.uleb128 0x26
	.4byte	0xb32
	.4byte	.LLST39
	.uleb128 0x26
	.4byte	0xb46
	.4byte	.LLST40
	.byte	0x0
	.byte	0x0
	.uleb128 0x36
	.byte	0x1
	.ascii	"avrbl_state_machine\000"
	.byte	0x1
	.byte	0xd6
	.byte	0x1
	.4byte	.LFB11
	.4byte	.LFE11
	.byte	0x1
	.byte	0x6d
	.4byte	0x10ea
	.uleb128 0x37
	.ascii	"b\000"
	.byte	0x1
	.byte	0xd6
	.4byte	0x684
	.4byte	.LLST41
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.ascii	"main\000"
	.byte	0x1
	.byte	0x59
	.4byte	0x655
	.4byte	.LFB10
	.4byte	.LFE10
	.byte	0x1
	.byte	0x6d
	.4byte	0x114b
	.uleb128 0x39
	.4byte	0xb7e
	.4byte	.LBB58
	.4byte	.Ldebug_ranges0+0x78
	.byte	0x1
	.byte	0x60
	.uleb128 0x3a
	.4byte	0xb97
	.4byte	.LBB62
	.4byte	.Ldebug_ranges0+0x90
	.byte	0x1
	.byte	0x8a
	.4byte	0x113b
	.uleb128 0x25
	.4byte	.LBB64
	.4byte	.LBE64
	.uleb128 0x26
	.4byte	0xbb8
	.4byte	.LLST42
	.byte	0x0
	.byte	0x0
	.uleb128 0x3b
	.4byte	0xbc8
	.4byte	.LBB67
	.4byte	.LBE67
	.byte	0x1
	.byte	0xb9
	.byte	0x0
	.uleb128 0x3c
	.ascii	"U1MODE\000"
	.byte	0x5
	.2byte	0x513
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.4byte	0xc4
	.uleb128 0x3c
	.ascii	"U1STA\000"
	.byte	0x5
	.2byte	0x563
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF6
	.byte	0x5
	.2byte	0x587
	.ascii	"*U1STA\000"
	.4byte	0x1186
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.4byte	0x2dd
	.uleb128 0x3c
	.ascii	"U1TXREG\000"
	.byte	0x5
	.2byte	0x58f
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1RXREG\000"
	.byte	0x5
	.2byte	0x591
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1BRG\000"
	.byte	0x5
	.2byte	0x593
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMCON\000"
	.byte	0x5
	.2byte	0x91a
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF3
	.byte	0x5
	.2byte	0x939
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF4
	.byte	0x5
	.2byte	0x93a
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMKEY\000"
	.byte	0x5
	.2byte	0x93c
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMADDR\000"
	.byte	0x5
	.2byte	0x93d
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMDATA\000"
	.byte	0x5
	.2byte	0x941
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF5
	.byte	0x5
	.2byte	0x942
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"RCON\000"
	.byte	0x5
	.2byte	0x943
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF7
	.byte	0x5
	.2byte	0x955
	.ascii	"*RCON\000"
	.4byte	0x1252
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.4byte	0x3d4
	.uleb128 0x3c
	.ascii	"U1RXR\000"
	.byte	0x5
	.2byte	0x9b1
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"RPB7R\000"
	.byte	0x5
	.2byte	0xa24
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELA\000"
	.byte	0x5
	.2byte	0x107f
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF8
	.byte	0x5
	.2byte	0x10a0
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF9
	.byte	0x5
	.2byte	0x10a1
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF10
	.byte	0x5
	.2byte	0x10b5
	.ascii	"*PORTA\000"
	.4byte	0x12b9
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.4byte	0x4c4
	.uleb128 0x3d
	.4byte	.LASF11
	.byte	0x5
	.2byte	0x10cb
	.ascii	"*LATA\000"
	.4byte	0x12d2
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.4byte	0x5c7
	.uleb128 0x3c
	.ascii	"LATACLR\000"
	.byte	0x5
	.2byte	0x10cc
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"LATASET\000"
	.byte	0x5
	.2byte	0x10cd
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"LATAINV\000"
	.byte	0x5
	.2byte	0x10ce
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELB\000"
	.byte	0x5
	.2byte	0x1148
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELC\000"
	.byte	0x5
	.2byte	0x1246
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3f
	.4byte	.LASF12
	.byte	0x6
	.byte	0x8a
	.4byte	0x65c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3f
	.4byte	.LASF13
	.byte	0x6
	.byte	0x8b
	.4byte	0x65c
	.byte	0x1
	.byte	0x1
	.uleb128 0x40
	.ascii	"active\000"
	.byte	0x1
	.byte	0x2c
	.4byte	0x135d
	.byte	0x5
	.byte	0x3
	.4byte	active
	.uleb128 0xc
	.4byte	0x678
	.uleb128 0x40
	.ascii	"fLoaded\000"
	.byte	0x1
	.byte	0x2d
	.4byte	0x135d
	.byte	0x5
	.byte	0x3
	.4byte	fLoaded
	.uleb128 0x40
	.ascii	"tLoopTime\000"
	.byte	0x1
	.byte	0x2f
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	tLoopTime
	.uleb128 0x40
	.ascii	"tLoopStart\000"
	.byte	0x1
	.byte	0x30
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	tLoopStart
	.uleb128 0x40
	.ascii	"tLastBlink\000"
	.byte	0x1
	.byte	0x31
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	tLastBlink
	.uleb128 0x40
	.ascii	"UserApp\000"
	.byte	0x1
	.byte	0x33
	.4byte	0x6a8
	.byte	0x5
	.byte	0x3
	.4byte	UserApp
	.uleb128 0x40
	.ascii	"fLoadProgramFromFlash\000"
	.byte	0x1
	.byte	0x34
	.4byte	0x678
	.byte	0x5
	.byte	0x3
	.4byte	fLoadProgramFromFlash
	.uleb128 0x40
	.ascii	"bootloaderVer\000"
	.byte	0x1
	.byte	0x37
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	bootloaderVer
	.uleb128 0x40
	.ascii	"prodAndVend\000"
	.byte	0x1
	.byte	0x38
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	prodAndVend
	.uleb128 0x41
	.4byte	.LASF0
	.byte	0x1
	.byte	0x39
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	bootloaderCapabilities
	.uleb128 0x40
	.ascii	"ramHeader\000"
	.byte	0x1
	.byte	0x3a
	.4byte	0x6f6
	.byte	0x5
	.byte	0x3
	.4byte	ramHeader
	.uleb128 0x40
	.ascii	"erased\000"
	.byte	0x1
	.byte	0x3d
	.4byte	0x678
	.byte	0x5
	.byte	0x3
	.4byte	erased
	.uleb128 0x40
	.ascii	"state\000"
	.byte	0x1
	.byte	0x40
	.4byte	0x655
	.byte	0x5
	.byte	0x3
	.4byte	state
	.uleb128 0x40
	.ascii	"seq\000"
	.byte	0x1
	.byte	0x41
	.4byte	0x684
	.byte	0x5
	.byte	0x3
	.4byte	seq
	.uleb128 0x40
	.ascii	"size\000"
	.byte	0x1
	.byte	0x42
	.4byte	0x655
	.byte	0x5
	.byte	0x3
	.4byte	size
	.uleb128 0x40
	.ascii	"csum\000"
	.byte	0x1
	.byte	0x43
	.4byte	0x684
	.byte	0x5
	.byte	0x3
	.4byte	csum
	.uleb128 0x40
	.ascii	"ready\000"
	.byte	0x1
	.byte	0x46
	.4byte	0x678
	.byte	0x5
	.byte	0x3
	.4byte	ready
	.uleb128 0x40
	.ascii	"requesti\000"
	.byte	0x1
	.byte	0x47
	.4byte	0x655
	.byte	0x5
	.byte	0x3
	.4byte	requesti
	.uleb128 0x1e
	.4byte	0x684
	.4byte	0x14e8
	.uleb128 0x42
	.4byte	0x5dc
	.2byte	0x3ff
	.byte	0x0
	.uleb128 0x40
	.ascii	"request\000"
	.byte	0x1
	.byte	0x48
	.4byte	0x14d7
	.byte	0x5
	.byte	0x3
	.4byte	request
	.uleb128 0x40
	.ascii	"replyi\000"
	.byte	0x1
	.byte	0x4c
	.4byte	0x655
	.byte	0x5
	.byte	0x3
	.4byte	replyi
	.uleb128 0x40
	.ascii	"reply\000"
	.byte	0x1
	.byte	0x4d
	.4byte	0x14d7
	.byte	0x5
	.byte	0x3
	.4byte	reply
	.uleb128 0x1e
	.4byte	0x684
	.4byte	0x1534
	.uleb128 0x1f
	.4byte	0x5dc
	.byte	0x1f
	.byte	0x0
	.uleb128 0x40
	.ascii	"pageMap\000"
	.byte	0x1
	.byte	0x54
	.4byte	0x1524
	.byte	0x5
	.byte	0x3
	.4byte	pageMap
	.uleb128 0x40
	.ascii	"addrBase\000"
	.byte	0x1
	.byte	0x55
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	addrBase
	.uleb128 0x40
	.ascii	"avrdudeAddrBase\000"
	.byte	0x1
	.byte	0x56
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	avrdudeAddrBase
	.uleb128 0x40
	.ascii	"cbSkipRam\000"
	.byte	0x1
	.byte	0x57
	.4byte	0x65c
	.byte	0x5
	.byte	0x3
	.4byte	cbSkipRam
	.uleb128 0x3c
	.ascii	"U1MODE\000"
	.byte	0x5
	.2byte	0x513
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1STA\000"
	.byte	0x5
	.2byte	0x563
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF6
	.byte	0x5
	.2byte	0x587
	.ascii	"*U1STA\000"
	.4byte	0x1186
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1TXREG\000"
	.byte	0x5
	.2byte	0x58f
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1RXREG\000"
	.byte	0x5
	.2byte	0x591
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1BRG\000"
	.byte	0x5
	.2byte	0x593
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMCON\000"
	.byte	0x5
	.2byte	0x91a
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF3
	.byte	0x5
	.2byte	0x939
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF4
	.byte	0x5
	.2byte	0x93a
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMKEY\000"
	.byte	0x5
	.2byte	0x93c
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMADDR\000"
	.byte	0x5
	.2byte	0x93d
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"NVMDATA\000"
	.byte	0x5
	.2byte	0x941
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF5
	.byte	0x5
	.2byte	0x942
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"RCON\000"
	.byte	0x5
	.2byte	0x943
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF7
	.byte	0x5
	.2byte	0x955
	.ascii	"*RCON\000"
	.4byte	0x1252
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"U1RXR\000"
	.byte	0x5
	.2byte	0x9b1
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"RPB7R\000"
	.byte	0x5
	.2byte	0xa24
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELA\000"
	.byte	0x5
	.2byte	0x107f
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF8
	.byte	0x5
	.2byte	0x10a0
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.4byte	.LASF9
	.byte	0x5
	.2byte	0x10a1
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF10
	.byte	0x5
	.2byte	0x10b5
	.ascii	"*PORTA\000"
	.4byte	0x12b9
	.byte	0x1
	.byte	0x1
	.uleb128 0x3d
	.4byte	.LASF11
	.byte	0x5
	.2byte	0x10cb
	.ascii	"*LATA\000"
	.4byte	0x12d2
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"LATACLR\000"
	.byte	0x5
	.2byte	0x10cc
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"LATASET\000"
	.byte	0x5
	.2byte	0x10cd
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"LATAINV\000"
	.byte	0x5
	.2byte	0x10ce
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELB\000"
	.byte	0x5
	.2byte	0x1148
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3c
	.ascii	"ANSELC\000"
	.byte	0x5
	.2byte	0x1246
	.4byte	0x115c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3f
	.4byte	.LASF12
	.byte	0x6
	.byte	0x8a
	.4byte	0x65c
	.byte	0x1
	.byte	0x1
	.uleb128 0x3f
	.4byte	.LASF13
	.byte	0x6
	.byte	0x8b
	.4byte	0x65c
	.byte	0x1
	.byte	0x1
	.byte	0x0
	.section	.debug_abbrev,info
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xd
	.uleb128 0xb
	.uleb128 0xc
	.uleb128 0xb
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x17
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x4
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x28
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0x35
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0x15
	.byte	0x0
	.uleb128 0x27
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x14
	.uleb128 0x26
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x20
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x17
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x18
	.uleb128 0x26
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1d
	.uleb128 0xb
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1f
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x20
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x20
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x21
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x22
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x23
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0x0
	.byte	0x0
	.uleb128 0x24
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x25
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.byte	0x0
	.byte	0x0
	.uleb128 0x26
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x27
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x28
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x29
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2a
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0x0
	.byte	0x0
	.uleb128 0x2b
	.uleb128 0x1d
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0x0
	.byte	0x0
	.uleb128 0x2c
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0x0
	.byte	0x0
	.uleb128 0x2d
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2e
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x30
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x33
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x34
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x35
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x36
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x37
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x38
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x39
	.uleb128 0x1d
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x3a
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x3b
	.uleb128 0x1d
	.byte	0x0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x3c
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x3d
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x2007
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x3e
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x3f
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x40
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x41
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x42
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,info
	.4byte	0x2f
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x1779
	.4byte	0x10b5
	.ascii	"avrbl_state_machine\000"
	.4byte	0x10ea
	.ascii	"main\000"
	.4byte	0x0
	.section	.debug_pubtypes,info
	.4byte	0xd3
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x1779
	.4byte	0x2dd
	.ascii	"__U1STAbits_t\000"
	.4byte	0x3d4
	.ascii	"__RCONbits_t\000"
	.4byte	0x4c4
	.ascii	"__PORTAbits_t\000"
	.4byte	0x5c7
	.ascii	"__LATAbits_t\000"
	.4byte	0x5f9
	.ascii	"uint8\000"
	.4byte	0x624
	.ascii	"uint16\000"
	.4byte	0x648
	.ascii	"int32\000"
	.4byte	0x65c
	.ascii	"uint32\000"
	.4byte	0x66a
	.ascii	"intptr\000"
	.4byte	0x678
	.ascii	"bool\000"
	.4byte	0x684
	.ascii	"byte\000"
	.4byte	0x6a8
	.ascii	"FNUSERAPP\000"
	.4byte	0x6f6
	.ascii	"RAM_HEADER_INFO\000"
	.4byte	0x86f
	.ascii	"IMAGE_HEADER_INFO\000"
	.4byte	0x0
	.section	.debug_aranges,info
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.2byte	0x0
	.2byte	0x0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.section	.debug_ranges,info
.Ldebug_ranges0:
	.4byte	.LBB40-.Ltext0
	.4byte	.LBE40-.Ltext0
	.4byte	.LBB43-.Ltext0
	.4byte	.LBE43-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB44-.Ltext0
	.4byte	.LBE44-.Ltext0
	.4byte	.LBB47-.Ltext0
	.4byte	.LBE47-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB49-.Ltext0
	.4byte	.LBE49-.Ltext0
	.4byte	.LBB52-.Ltext0
	.4byte	.LBE52-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB50-.Ltext0
	.4byte	.LBE50-.Ltext0
	.4byte	.LBB51-.Ltext0
	.4byte	.LBE51-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB56-.Ltext0
	.4byte	.LBE56-.Ltext0
	.4byte	.LBB57-.Ltext0
	.4byte	.LBE57-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB58-.Ltext0
	.4byte	.LBE58-.Ltext0
	.4byte	.LBB61-.Ltext0
	.4byte	.LBE61-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.4byte	.LBB62-.Ltext0
	.4byte	.LBE62-.Ltext0
	.4byte	.LBB66-.Ltext0
	.4byte	.LBE66-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.section	.debug_str,info
.LASF12:
	.ascii	"_skip_ram_space_end_adder\000"
.LASF8:
	.ascii	"TRISACLR\000"
.LASF13:
	.ascii	"_RAM_SKIP_SIZE\000"
.LASF2:
	.ascii	"addrHigh\000"
.LASF7:
	.ascii	"RCONbits\000"
.LASF9:
	.ascii	"TRISASET\000"
.LASF1:
	.ascii	"pHeaderInfo\000"
.LASF6:
	.ascii	"U1STAbits\000"
.LASF4:
	.ascii	"NVMCONSET\000"
.LASF11:
	.ascii	"LATAbits\000"
.LASF3:
	.ascii	"NVMCONCLR\000"
.LASF0:
	.ascii	"bootloaderCapabilities\000"
.LASF10:
	.ascii	"PORTAbits\000"
.LASF5:
	.ascii	"NVMSRCADDR\000"
	.section	.text,code
	.ident	"GCC: (Microchip Technology) 4.5.1 MPLAB C Compiler for PIC32 MCUs v2.02-20111116"
# Begin MCHP vector dispatch table
# End MCHP vector dispatch table
# MCHP configuration words
# Configuration word @ 0xbfc00bfc
	.section	.config_BFC00BFC, code
	.type	__config_BFC00BFC, @object
	.size	__config_BFC00BFC, 4
__config_BFC00BFC:
	.word	2147483643
# Configuration word @ 0xbfc00bf8
	.section	.config_BFC00BF8, code
	.type	__config_BFC00BF8, @object
	.size	__config_BFC00BF8, 4
__config_BFC00BF8:
	.word	4285189595
# Configuration word @ 0xbfc00bf4
	.section	.config_BFC00BF4, code
	.type	__config_BFC00BF4, @object
	.size	__config_BFC00BF4, 4
__config_BFC00BF4:
	.word	4294574041
# Configuration word @ 0xbfc00bf0
	.section	.config_BFC00BF0, code
	.type	__config_BFC00BF0, @object
	.size	__config_BFC00BF0, 4
__config_BFC00BF0:
	.word	3489660927
