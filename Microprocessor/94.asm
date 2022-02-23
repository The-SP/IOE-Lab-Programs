;lab 9, no 4
TITLE to count no of vowels in a string and display the count in decimal format

.model small
.stack 32
.data        
    input_prompt db "Enter a string: $"
    output_prompt db 0ah, 0dh, "No of vowels = $"
    max_len db 50
    act_len db ?
    str db 50 dup('$')
    vowels db 'aeiouAEIOU$'
    ten dw 10
    count dw ?
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

    lea dx, output_prompt
    mov ah, 09h
    int 21h

    mov cl, act_len
    lea si, str
next1:
    mov al, [si]
    ; check vowels
    mov bx, 0h 
next2:
    cmp al, vowels[bx]
    jne novowel
    inc count
    jmp skip
novowel:
    inc bx
    cmp bx, 0ah
    jnz next2
skip:
    inc si
    loop next1

    call display_dec

    mov ax, 4c00h
    int 21h    
main endp

display_dec proc near
    mov cx, 0
    mov ax, count
loop1:
    mov dx, 0
    div ten
    add dx, 30h
    push dx
    inc cx
    cmp ax, 0
    jnz loop1
    mov ah, 02h
loop2:
    pop dx
    int 21h
    loop loop2
    ret
display_dec endp

end main   