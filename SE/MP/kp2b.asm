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

a dw 22h
b dw 12h

segment .bss

buffer resb 100
cnt resb 10

segment .text

global _start
_start:
mov rax,0
mov al,byte[a]
mov bl,byte[b]
add al,bl


mov byte[cnt],16
mov rsi,buffer
lp:roL rax,4


mov cl,al
and cl,0fh

cmp cl,09h
jg l1
add cl,30h
jmp l2
l1:add cl,37h
l2:mov [rsi],cl
inc rsi
dec byte[cnt]
jnz lp
print msg,msglen

print buffer,16

mov rax,60
mov rbx,0
syscall
