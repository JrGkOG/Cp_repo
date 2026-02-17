	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 26, 0	sdk_version 26, 2
	.globl	_process                        ; -- Begin function process
	.p2align	2
_process:                               ; @process
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #12]
	mul	w8, w8, w9
	ldr	w9, [sp, #8]
	ldr	w10, [sp, #8]
	mul	w9, w9, w10
	add	w8, w8, w9
	ldr	w9, [sp, #12]
	ldr	w10, [sp, #8]
	add	w9, w9, w10
	mul	w0, w8, w9
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	str	xzr, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	mov	w9, #19264                      ; =0x4b40
	movk	w9, #76, lsl #16
	subs	w8, w8, w9
	b.ge	LBB1_4
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	mov	w0, #3                          ; =0x3
	mov	w1, #4                          ; =0x4
	bl	_process
	ldr	x8, [sp, #16]
	add	x8, x8, w0, sxtw
	str	x8, [sp, #16]
	mov	w0, #6                          ; =0x6
	mov	w1, #7                          ; =0x7
	bl	_process
	ldr	x8, [sp, #16]
	add	x8, x8, w0, sxtw
	str	x8, [sp, #16]
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB1_1
LBB1_4:
	ldr	x8, [sp, #16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Clone total: %lld\n"

.subsections_via_symbols
