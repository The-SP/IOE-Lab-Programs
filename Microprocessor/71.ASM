;lab 7, no 1
TITLE to display a string "Programming is fun"

.model small
.stack 32
.data
    str db "Programming is Fun$"

.code
main proc far 
    mov ax, @data
    mov ds, ax
            
    mov ah, 09h
    lea dx, str
    int 21h           
    mov ax, 4c00h
    int 21h    
main endp
end main
