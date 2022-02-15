;lab8, 4
row_c equ 12d; 25/12
col_c equ 40d; 80/2
row_cs equ row_c-10d 
col_cs equ col_c-10d
row_ce equ row_c+10d
col_ce equ col_c+10d

.model small
.stack 32
.data        
maxchar db 14
enteredchar db ?
str db 15 dup('$')
.code
main proc far 
    mov ax, @data
    mov ds, ax
    
    mov dx, offset maxchar    
    mov ah,0ah
    int 21h
    
    mov ax, 0003h
    int 10h
    
    ;clear screen
    mov ax, 0600h
    mov bh, 07h
    mov cx, 0000h
    mov dx, 184fh
    int 10h     
    
    ;scroll 20X20 at centre
    mov bh, 70h
    mov ch, row_cs
    ;sub ch, 10d
    mov cl, col_cs
    ;sub cl, 10d            
    mov dh, row_ce
    ;add dh, 9d
    mov dl, col_ce
    ;add dl, 9d 
    int 10h
          
    mov ah, 0          
    mov al, enteredchar
    mov bl, 2h
    div bl
    mov dl, col_c
    sub dl, al  
    
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