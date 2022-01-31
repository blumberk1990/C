	.file	"race.c"
	.text
	.comm	_sum, 4, 2
	.globl	_threadWork@4
	.def	_threadWork@4;	.scl	2;	.type	32;	.endef
_threadWork@4:
LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L2
L3:
	movl	_sum, %eax
	addl	$1, %eax
	movl	%eax, _sum
	addl	$1, -4(%ebp)
L2:
	cmpl	$99999, -4(%ebp)
	jle	L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE34:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "sum=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB35:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$52, %esp
	call	___main
	movl	$0, _sum
	leal	-24(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$_threadWork@4, 8(%esp)
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	_CreateThread@24
	subl	$24, %esp
	movl	%eax, -16(%ebp)
	leal	-24(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$_threadWork@4, 8(%esp)
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	_CreateThread@24
	subl	$24, %esp
	movl	%eax, -12(%ebp)
	movl	$-1, 12(%esp)
	movl	$1, 8(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	_WaitForMultipleObjects@16
	subl	$16, %esp
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_CloseHandle@4
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_CloseHandle@4
	subl	$4, %esp
	movl	_sum, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE35:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_CreateThread@24;	.scl	2;	.type	32;	.endef
	.def	_WaitForMultipleObjects@16;	.scl	2;	.type	32;	.endef
	.def	_CloseHandle@4;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
