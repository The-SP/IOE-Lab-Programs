;lab 9, no 1
TITLE to find sum of numbers from 1 to n

.model small
.stack 32
.data        
    input_prompt db "Enter a number: $"
    output_prompt1 db 0ah, 0dh, "Sum in decimal = $"
    output_prompt2 db 0ah, 0dh, "Sum in hex = $"
    max_len db 4
    act_len db ?
    str db 4 dup('$')
    ten dw 10
    sixteen dw 16
    num dw 0
    sumh dw 0
    suml dw 0
.code
main proc far 
    mov ax, @data
    mov ds, ax

    lea dx, input_prompt
    mov ah, 09h
    int 21h

    lea dx, max_len
    mov ah, 0ah
    int 21h

    ; convert ascii character to binary number
    mov cl, act_len
    lea si, str
l1: mov al, [si]
    mov ah, 0
    sub al, 30h
    push ax
    mov al, 10
    mul num
    mov num, ax
    pop ax
    add num, ax
    inc si
    loop l1

    ; calculate sum
    mov ax, 00
    mov cx, num
    cmp cx, 0
    jz labelzero
labelsum:
    add ax, cx
    jnc skip
    inc sumh
skip:
    loop labelsum
    mov suml, ax

    lea dx, output_prompt1
    mov ah, 09h
    int 21h
    call display_dec

    lea dx, output_prompt2
    mov ah, 09h
    int 21h
    call display_hex

labelzero:
    mov ax, 4c00h
    int 21h    
main endp

display_dec proc near
    mov cx, 0
    mov ax, suml
    mov dx, sumh
loop1:
    div ten
    add dx, 30h
    push dx
    mov dx, 0
    inc cx
    cmp ax, 0
    jne loop1
    mov ah, 02h
loop2:
    pop dx
    int 21h
    loop loop2
    ret
display_dec endp

display_hex proc near
    mov cx, 0
    mov ax, suml
    mov dx, sumh
loop3:
    div sixteen
    cmp dl, 0ah
    jb below
    add dl, 07h
below:
    add dl, 30h
    push dx
    mov dx, 0
    inc cx
    cmp ax, 0
    jne loop3
    mov ah, 02h
loop4:
    pop dx
    int 21h
    loop loop4
    ret
display_hex endp

end main   