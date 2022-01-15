;hello world
%macro write 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro
section .data
msg1 db "first program",10,13
msg2 db "2nd Program ",10,13
msg3 db "3rd program ",10,13


lmsg1 equ $-msg1
lmsg2 equ $-msg2
lmsg3 equ $-msg3

section .text
global _start
_start:
	write 1,1,msg1,lmsg1
	write 1,1,msg2,lmsg2
	write 1,1,msg3,lmsg3
	
	mov rax,60
	mov rdi,0
	syscall
