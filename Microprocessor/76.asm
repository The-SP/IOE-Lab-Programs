;lab 7, no 6
TITLE to read a string from the user with promt and display each word in separate lines

.model small
.stack 32
.data        
    prompt1 db "Enter your string: $"
    prompt2 db 0ah, 0dh, "Displaying each word in separate lines: ", 0ah, 0dh, '$'
    max_len db 50
    act_len db ?
    str db 50 dup('$')
.code
main proc far 
    mov ax, @data
    mov ds, ax

    ;Display Prompt
    lea dx, prompt1
    mov ah, 09h
    int 21h
    
    ;Input String
    lea dx, max_len    
    mov ah,0ah
    int 21h
    
    ;Display Prompt
    lea dx, prompt2
    mov ah, 09h
    int 21h
    
    mov cl, act_len
    lea si, str
    mov ah, 02h
next:
    mov dl, [si]
    cmp dl, ' '
    jnz display
    mov dl, 0ah
    int 21h
    mov dl, 0dh
display:
    int 21h
    inc si
    loop next

    mov ax, 4c00h
    int 21h    
main endp
end main   
