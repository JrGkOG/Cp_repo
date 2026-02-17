	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 26, 0	sdk_version 26, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	xzr, [x29, #-16]
	stur	wzr, [x29, #-20]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-20]
	mov	w9, #36224                      ; =0x8d80
	movk	w9, #91, lsl #16
	subs	w8, w8, w9
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #11                         ; =0xb
	str	w8, [sp, #24]
	mov	w8, #9                          ; =0x9
	str	w8, [sp, #20]
	ldr	w8, [sp, #24]
	ldr	w9, [sp, #20]
	mul	w8, w8, w9
	str	w8, [sp, #16]
	ldr	w8, [sp, #24]
	ldr	w9, [sp, #20]
	mul	w8, w8, w9
	str	w8, [sp, #12]
	ldr	w8, [sp, #24]
	ldr	w9, [sp, #20]
	add	w8, w8, w9
	ldr	w9, [sp, #24]
	ldr	w10, [sp, #20]
	add	w9, w9, w10
	mul	w8, w8, w9
	str	w8, [sp, #8]
	ldur	x8, [x29, #-16]
	ldrsw	x9, [sp, #16]
	add	x8, x8, x9
	ldrsw	x9, [sp, #12]
	add	x8, x8, x9
	ldrsw	x9, [sp, #8]
	add	x8, x8, x9
	stur	x8, [x29, #-16]
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB0_1
LBB0_4:
	ldur	x8, [x29, #-16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Total value: %lld\n"

.subsections_via_symbols
