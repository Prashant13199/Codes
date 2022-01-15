segment .data
newline db 0AH 
section.BSS
number resb 10 
global _start

_start:
mov rax,1
mov rdi,1
mov rsi,newline
mov rdx,1
syscall

mov al,01
cmp al,09H
jg add37
add al,30H
jmp skip
add37:add al,37
skip:mov [number],al
mov rax,1
mov rdi,1
mov rsi,number
mov rdx,1
syscall



mov rax,60
mov rdi,0
syscall
