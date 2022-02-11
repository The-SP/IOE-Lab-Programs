;lab 7, no 3
TITLE to read string from the user with promt and display the string in another line

.model small
.stack 32
.data        
    prompt1 db "Enter your string:", 0ah, 0dh, "$"
    prompt2 db 0ah, 0dh, "Your string is:", 0ah, 0dh, "$"
    max_len db 50
    actual_len db ?
    str db 50 dup('$')
.code
main proc far 
    mov ax, @data
    mov ds, ax

    ;display prompt
    lea dx, prompt1
    mov ah, 09h
    int 21h
    
    mov dx, offset max_len    
    mov ah,0ah
    int 21h
       
    ;display prompt
    lea dx, prompt2
    mov ah, 09h
    int 21h
     
    lea dx, str
    mov ah, 09h
    int 21h

    mov ax, 4c00h
    int 21h    
main endp
end main   