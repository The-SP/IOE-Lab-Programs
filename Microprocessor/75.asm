;lab 7, no 5
TITLE to read a string and convert it into uppercase if it is in lower case and display the string

.model small
.stack 32
.data        
    prompt1 db "Enter your string: $"
    prompt2 db 0ah, 0dh, "Your string is: $"
    max_len db 50
    act_len db ?
    str db 50 dup('$')
    upperstr db 50 dup('$')
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
    lea bx, upperstr
next:
    mov al, [si]
    cmp al, 61h     ; 61h=97d = 'a' 0r, cmp dl, 'a'
    jnae skip
    cmp al, 7ah     ; 7ah=122d = 'z'
    jnbe skip
    sub al, 20h     ; 97d-65d = 20h
skip:
    mov [bx], al    ; store converted string in memory
    inc bx
    inc si
    loop next
    mov byte ptr [bx], '$'

    ;Display uppercase string
    lea dx, upperstr
    mov ah, 09h
    int 21h

    mov ax, 4c00h
    int 21h    
main endp
end main   