	.file	"main.c"
	.text
	.comm	_devId, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	_initializeDevice
	call	_connectToDevice
	movl	$4605252, _devId
	call	_disconnectFromDevice
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_initializeDevice;	.scl	2;	.type	32;	.endef
	.def	_connectToDevice;	.scl	2;	.type	32;	.endef
	.def	_disconnectFromDevice;	.scl	2;	.type	32;	.endef
