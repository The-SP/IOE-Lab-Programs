;lab 9, no 3
TITLE to add ten 16-bit numbers stored in memory and display the result in decimal format

.model small
.stack 32
.data        
    arr dw 1111h, 2222h, 3333h, 4444h, 5555h, 6666h, 7777h, 8888h, 9999h, 0aaaah
    ten dw 10
    prompt db "Sum = $"
.code
main proc far 
    mov ax, @data
    mov ds, ax

    lea dx, prompt
    mov ah, 09h
    int 21h

    mov ax, 0h  ; sum
    mov dx, 0h  ; carry
    mov bx, 0   ; index
    mov cx, 10
next:
    add ax, arr[bx]
    jnc skip
    inc dx
skip:
    add bx, 2
    loop next

    call display_dec

    mov ax, 4c00h
    int 21h    
main endp

display_dec proc near
    mov cx, 0
loop1:
    div ten
    add dx, 30h
    push dx
    mov dx, 0
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