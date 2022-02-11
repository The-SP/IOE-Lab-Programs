;lab 7, no 2
TITLE to display string using character reading function

.model small
.stack 32
.data
    str db "Programming is Fun"
    len dw $-str ;addressOf($)-addressOf(str)
.code
main proc far 
    mov ax, @data
    mov ds, ax
    
    mov cx, len            
    lea bx, str
    next:
    mov dl, [bx]
    mov ah, 02h
    int 21h
    inc bx
    loop next                  
    mov ax, 4c00h
    int 21h    
main endp
end main
