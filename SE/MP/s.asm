section .data
    str: db 100    
section .bss

section .text

global _start

_start:
    mov eax, 3          
    mov ebx, 0          
    mov ecx, str       
    mov edx, 100       
    int 80h             

    mov eax, 4         
    mov ebx, 1       
    mov ecx, str        
    mov edx, 100        
    int 80h           

    mov eax, 1         
    mov ebx, 0         
    int 80h          
