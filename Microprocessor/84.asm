;lab 8, no 4
TITLE to input string and scroll a window of size 20x20 at the center of the screen then, display string at the centre

row_c equ 12d   ; 25/2
col_c equ 40d   ; 80/2
row_cs equ row_c-10d 
col_cs equ col_c-10d
row_ce equ row_c+10d
col_ce equ col_c+10d

.model small
.stack 32
.data        
    max_len db 14
    act_len db ?
    str db 15 dup('$')
.code
main proc far 
    mov ax, @data
    mov ds, ax
    
    ; input string
    mov dx, offset max_len    
    mov ah,0ah
    int 21h
    
    ; set video mode
    mov ax, 0003h
    int 10h
    
    ; clear screen
    mov ax, 0600h
    mov bh, 07h
    mov cx, 0000h
    mov dx, 184fh
    int 10h     
    
    ; scroll 20X20 at centre
    mov bh, 70h     ; black on white
    mov ch, row_cs  ; (25/2-10)
    mov cl, col_cs  ; (80/2-10)
    mov dh, row_ce  ; (25/2+10)
    mov dl, col_ce  ; (80/2+10)
    int 10h 
          
    ; set start position for text
    mov ah, 0          
    mov al, act_len
    mov bl, 02h
    div bl
    mov dl, col_c
    sub dl, al
    
    ; set cursor position
    mov ah, 02h
    mov bh, 0h
    mov dh, row_c
    int 10h
    
    lea dx, str
    mov ah, 09h 
    int 21h
    
    mov ax, 4c00h
    int 21h    
main endp 
end main   