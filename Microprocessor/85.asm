; lab 8, no 5
TITLE to display each word in new line diagonally from upper left towards bottom right in a clear screen

.model small
.stack 32
.data
    max_len db 50
    act_len db ?
    str db 50 dup('$')
    row db 0
    col db 0
.code 
main proc far
    mov ax, @data
    mov ds, ax

    ; input string
    lea dx, max_len
    mov ah, 0ah 
    int 21h

    ; set video mode
    mov ah, 00h     ; set mode
    mov al, 03h     ; standard color text
    int 10h

    mov cl, act_len
    lea si, str
next:
    mov dl, [si]
    cmp dl, ' '
    jne display

    inc row         ; next row / line
    mov ah, 02h     ; set cursor position
    mov dh, row
    mov dl, col
    int 10h 
    jmp skip
display:
    mov dl, [si]
    mov ah, 02h     ; display char
    int 21h 
    
    inc col
skip:
    inc si
    loop next

    mov ax, 4c00h
    int 21h
main endp
end main