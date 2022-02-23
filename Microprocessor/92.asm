;lab 9, no 2
TITLE to find sum of series 2x4 + 3x6 + ... to n terms

.model small
.stack 32
.data  
    max_len db 3
    act_len db ?
    num db 4 dup('$') 
    ten db 10d
    ten16 dw 10d
    sixteen dw 16d
    prompt1 db 0dh, 0ah, "Decimal value     = $"
    prompt2 db 0dh, 0ah, "HexaDecimal value = $"
    prompt3 db 0dh, 0ah, "Too high to calculate$"
.code
main proc far
   mov ax, @data
   mov ds, ax
   
   lea dx, max_len
   mov ah, 0ah
   int 21h
   
   call parsedec
   
   cmp dx, 44d
   ja toohigh
   
   inc dx
   
   ;series
   mov bx, dx  ;n
   mov ax, bx  
   mov cx, 2h
   mul cx
   mov cx, ax  ;2n
   inc ax    ;2n+1
   mul bx    ;(2n+1)*n
   inc bx
   mul bx
   mov cx,3h
   div cx
   sub ax, 2
   sbb dx, 0
   
   ;unparse       
   push ax
   push dx
   call unparsedec
   pop dx
   pop ax
   
   call unparsehex
   
   mov ax,4c00h 
   int 21h  
   
toohigh: 
   lea dx, prompt3
   mov ah, 9h
   int 21h   
   
   mov ax, 4c00h
   int 21h
main endp

parsedec proc near ;returns output in dx 
    mov ax,0
    mov bh, 0 
    mov dx, 0
    mov cx, 1
    mov bl, act_len  
labelpd: 
    dec bx  
    mov ah, 0
    mov al, num[bx]  
    inc bx ;placeholder
    sub al, 30h
    push dx
    mul cx 
    pop dx   
    add dx, ax
    mov ax, cx
    mul ten
    mov cx, ax      
    dec bx
    jnz labelpd 
    ret
parsedec endp 

unparsedec proc near ;send 32-bit input as dx:ax
   mov cx,0
   
labelunpd:
   div ten16
   add dx, 30h
   push dx
   mov dx, 0
   inc cx
   cmp ax, 0
   jnz labelunpd
   
   mov ah, 09h
   lea dx, prompt1
   int 21h  
   mov ah, 02h
   
   
poppingd:
   pop dx
   int 21h  
   loop poppingd
   ret
unparsedec endp

unparsehex proc near
   mov cx,0
   
labelunph:
   div sixteen
   cmp dx,0ah 
   jb skip
   add dx, 7h
skip: add dx, 30h
   push dx
   mov dx, 0
   inc cx
   cmp ax, 0
   jnz labelunph
   
   mov ah, 09h
   lea dx, prompt2
   int 21h  
   mov ah, 02h
   
poppingh:
   pop dx
   int 21h  
   loop poppingh
   ret
    
unparsehex endp
end main