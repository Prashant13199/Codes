%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

segment .data
msg db 10,13,"Addition is",10,13
msglen equ $-msg

a db 1
b db 1

segment .bss

res resb 01

segment .text
global _start
_start:

mov al,byte[a]
mov bl,byte[b]
add al,bl
cmp al,09h
jg l1
add al,30h
jmp l2
l1:add al,37h

l2:mov [res],al

print msg,msglen

print res,01

mov rax,60
mov rbx,0
syscall
