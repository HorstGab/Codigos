	.file	"lista1.c"
	.intel_syntax noprefix
	.section .rdata,"dr"
LC0:
	.ascii "%d\0"
	.text
	.globl	_ler
	.def	_ler;	.scl	2;	.type	32;	.endef
_ler:
	push	edi
	push	esi
	push	ebx
	sub	esp, 16
	mov	edi, DWORD PTR [esp+32]
	mov	esi, DWORD PTR [esp+36]
	cmp	DWORD PTR [esi], 0
	jle	L1
	mov	ebx, 0
L3:
	mov	eax, DWORD PTR [edi+ebx*4]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_scanf
	add	ebx, 1
	cmp	DWORD PTR [esi], ebx
	jg	L3
L1:
	add	esp, 16
	pop	ebx
	pop	esi
	pop	edi
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
	push	ebp
	mov	ebp, esp
	push	ebx
	and	esp, -16
	sub	esp, 528
	call	___main
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_puts
	lea	eax, [esp+124]
	mov	DWORD PTR [esp+4], eax
	lea	eax, [esp+128]
	mov	DWORD PTR [esp], eax
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
	mov	ebx, 0
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_printf
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC3
	call	_printf
	lea	eax, [esp+24]
	mov	DWORD PTR [esp], eax
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
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
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
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_printf
	mov	DWORD PTR [esp], OFFSET FLAT:LC4
	call	_system
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	ret
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_gets;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
