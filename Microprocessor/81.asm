; lab 8, no 1
TITLE to display string

.model small
.stack
.data 
    str db "Programming in Assembly Language is Fun$"
.code
main proc far
    mov ax, @data
    mov ds, ax

    ; set video mode
    mov ax, 0003h 
    int 10h

    ; scroll window
    mov ax, 0600h 
    mov bh, 70h     ; black on white bg
    mov cx, 0413h 
    mov dx, 133bh 
    int 10h

    ; set cursor position
    mov ah, 02h 
    mov bh, 00h 
    mov dx, 0c1eh   ; (10, 30)d
    int 10h 

    ; display string
    lea dx, str
    mov ah, 09h
    int 21h 

    mov ax, 4c00h 
    int 21H
main endp 
end main