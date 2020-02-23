	.file	"main.cc"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1242:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1242:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"? "
.LC1:
	.string	"= "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1485:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	_ZSt4cout(%rip), %rbx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	leaq	8(%rsp), %r12
	leaq	7(%rsp), %r14
	leaq	16(%rsp), %rbp
	leaq	24(%rsp), %r13
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L18:
	movsbl	67(%r15), %esi
.L13:
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
.L14:
	movl	$2, %edx
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo5flushEv@PLT
	leaq	_ZSt3cin(%rip), %rsi
	movq	%r12, %rdi
	call	_Z4readR8RationalRSi@PLT
	movq	%r14, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	leaq	_ZSt3cin(%rip), %rsi
	movq	%rbp, %rdi
	call	_Z4readR8RationalRSi@PLT
	movzbl	7(%rsp), %eax
	cmpb	$45, %al
	je	.L4
	jg	.L5
	cmpb	$42, %al
	je	.L6
	cmpb	$43, %al
	jne	.L8
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	_Z3addRK8RationalS1_@PLT
	movq	%rax, 24(%rsp)
.L10:
	movl	$2, %edx
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rsi
	movq	%r13, %rdi
	call	_Z5writeRK8RationalRSo@PLT
	movq	(%rbx), %rax
	movq	-24(%rax), %rax
	movq	240(%rbx,%rax), %r15
	testq	%r15, %r15
	je	.L17
	cmpb	$0, 56(%r15)
	jne	.L18
	movq	%r15, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r15), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rcx
	movq	48(%rax), %rax
	cmpq	%rcx, %rax
	je	.L13
	movq	%r15, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L5:
	cmpb	$47, %al
	jne	.L8
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	_Z6divideRK8RationalS1_@PLT
	movq	%rax, 24(%rsp)
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L4:
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	_Z9substractRK8RationalS1_@PLT
	movq	%rax, 24(%rsp)
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L8:
	xorl	%esi, %esi
	xorl	%edi, %edi
	call	_Z8rationalii@PLT
	movq	%rax, 24(%rsp)
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%rbp, %rsi
	movq	%r12, %rdi
	call	_Z8multiplyRK8RationalS1_@PLT
	movq	%rax, 24(%rsp)
	jmp	.L10
.L17:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE1485:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1811:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE1811:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Debian 9.2.1-25) 9.2.1 20200123"
	.section	.note.GNU-stack,"",@progbits
