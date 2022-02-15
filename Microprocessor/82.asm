; lab 8, no 2
TITLE to input a string and display it at the center of the clear screen

.model small
.stack 32
.data
    max_len db 60
    act_len db ?
    str db 60 dup('$')
.code
main proc far
    mov ax, @data
    mov ds, ax

    ; input string
    lea dx, max_len
    mov ah, 0ah
    int 21h
  
    ; set video mode
    mov ah, 00h 
    mov al, 03h     ; 25*80
    int 10h 

    mov al, act_len
    mov bl, 02h
    div bl

    ; set cursor position
    mov ah, 02h 
    mov dx, 0c28h   ; (25/2)d = 0ch and (80/2)d = 28h
    sub dl, al
    int 10h

    ; display string
    lea dx, str
    mov ah, 09h 
    int 21h 

    mov ax, 4c00h 
    int 21h 
main endp
end main
