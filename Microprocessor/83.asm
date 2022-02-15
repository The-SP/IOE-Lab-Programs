; lab 8, no 3
TITLE to input a string and display each character at center of each line

.model small
.stack 32
.data
    max_len db 24
    act_len db ?
    str db 24 dup('$')
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
    mov al, 03h
    int 10h 

    ; display string
    lea si, str
    mov cx, 0028h   ; col = (80/2)d = 28h
    mov ah, 02h     ; set cursor position / display char
next:
    mov dx, cx      ; set cursor position
    int 10h
    mov dl, [si]    ; display char
    int 21h 
    inc ch          ; inc row no
    inc si
    cmp byte ptr [si], '$'
    jne next

    mov ax, 4c00h 
    int 21h 
main endp
end main
