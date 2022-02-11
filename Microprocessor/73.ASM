;lab 7, no 3
TITLE to read string from the user and display the string in newline

.model small
.stack 32
.data        
    max_len db 50
    actual_len db ?
    str db 50 dup('$')
.code
main proc far 
    mov ax, @data
    mov ds, ax
    
    mov dx, offset max_len    
    mov ah,0ah
    int 21h
       
    ;newline
    mov dl, 0dh
    mov ah, 02h
    int 21h
    mov dl, 0ah
    int 21h
     
    lea dx, str
    mov ah, 09h
    int 21h
    mov ax, 4c00h
    int 21h    
main endp
end main   
