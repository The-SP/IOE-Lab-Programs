;lab8, no 4
TITLE to input string and scroll a window of size 20x20 at the center of the screen then, display string at the centre

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
    
    ; scroll 20X20 at centre
    mov ax, 0600h
    mov bh, 70h     ; black on white
    mov ch, 02      ; (25/2-10)
    mov cl, 30      ; (25/2+10)
    mov dh, 22      ; (80/2-10)
    mov dl, 50      ; (80/2+10)
    int 10h 
          
    ; set start position for text
    mov ah, 0          
    mov al, act_len
    mov bl, 2
    div bl
    mov dl, 40      ; (80/2)d
    sub dl, al
    
    ; set cursor position
    mov ah, 02h
    mov bh, 0h
    mov dh, 12
    int 10h
    
    lea dx, str
    mov ah, 09h 
    int 21h
    
    mov ax, 4c00h
    int 21h    
main endp 
end main   