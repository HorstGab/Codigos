	.file	"lista1.c"
	.section .rdata,"dr"
LC0:
	.ascii "%d\0"
	.text
	.globl	_ler
	.def	_ler;	.scl	2;	.type	32;	.endef
_ler:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	addl	$1, -12(%ebp)
L2:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	-12(%ebp), %eax
	jg	L3
	nop
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Entre com o vetor\0"
LC2:
	.ascii "%d\12\0"
LC3:
	.ascii "entre com a string\12\0"
LC4:
	.ascii "PAUSE\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$528, %esp
	call	___main
	movl	$LC1, (%esp)
	call	_puts
	leal	120(%esp), %eax
	movl	%eax, 4(%esp)
	leal	124(%esp), %eax
	movl	%eax, (%esp)
	call	_ler
/APP
 # 22 "lista1.c" 1
	.intel_syntax noprefix 
 	mov eax, 1				
 	mov ecx, _n 			
 	xor ebx, ebx			
   v0:						
 	cmp ecx, 0				
 	je v1					
 	imul eax, [ebx*4+_v]   
 	inc ebx                
 	dec ecx     			
 	jmp v0					
   v1:						
 	mov _t, eax 			
 	.att_syntax prefix		

 # 0 "" 2
/NO_APP
	movl	524(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	524(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_gets
/APP
 # 46 "lista1.c" 1
	.intel_syntax noprefix	 
 	xor ebx, ebx 			 
   s0:						 
 	cmp byte ptr [ebx+_s],0 
 	je s1					 
 	inc ebx 				 
 	jmp s0					 
   s1:						 
 	mov _t, ebx 			 
 	.att_syntax prefix		 

 # 0 "" 2
/NO_APP
	movl	524(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
/APP
 # 63 "lista1.c" 1
	.intel_syntax noprefix  
 	lea ebx, _s			 
 	mov edi, ebx 			 
   t0: 						 
 	cmp byte ptr [ebx], 0   
 	je t1					 
 	inc ebx 				 
 	jmp t0 				 
   t1:						 
 	sub ebx, edi			 
 	mov _t, ebx 			 
   .att_syntax prefix 	 

 # 0 "" 2
/NO_APP
	movl	524(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_system
	movl	$0, %eax
	leave
	ret
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_gets;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
