;lab 9, no 3
TITLE to count no of words in a string

.model small
.stack 32
.data        
    prompt db "Enter a string: $"
    output_prompt db 0ah, 0dh, "No of words = $"
    max_len db 100
    act_len db ?
    str db 100 dup('$')
    ten dw 10
    sixteen dw 16
    count dw 0
.code
main proc far 
    mov ax, @data
    mov ds, ax

    lea dx, prompt
    mov ah, 09h
    int 21h

    mov ah, 0ah
    lea dx, max_len
    int 21h

    ; count words
    mov cl, act_len
    cmp cl, 0
    jz nowords
    lea si, str
next:
    cmp byte ptr [si], ' '
    jne notspace
    inc count
notspace:
    inc si
    loop next
    inc count
nowords:    ; count = 0

    lea dx, output_prompt
    mov ah, 09h
    int 21h
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
    add dl, 30h
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