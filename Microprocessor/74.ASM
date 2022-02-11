; lab 7, no 4
TITLE to read string using the character reading function and display the string using character displaying function

.model small
.stack 32
.data
    prompt db "Enter your string: $"
    prompt2 db 0ah, 0dh, "Your string is: $"
    max_len db 50
    act_len db 00
    str db 50 dup('$')
.code
main proc far
    mov ax, @data
    mov ds, ax

    lea dx, prompt
    mov ah, 09h
    int 21h

    mov cl, max_len
    lea si, str
	mov ah, 01h	; read char by char
back: 
    int 21h
    cmp al, 0dh	; check for carriage return
    jz skip	
    mov [si], al
    inc act_len
    inc si
    loop back
    mov byte ptr [si], '$'

skip:
    mov ah, 09h
    lea dx, prompt2
    int 21h

    mov cl, act_len
    lea si, str
    mov ah, 02h
back2:
    mov dl, [si]
    int 21h
    inc si
    loop back2

    mov ax, 4c00h
    int 21h
main endp
end main