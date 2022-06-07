; Lab 2, No 2

; 2(a)
MVI A, 90H  ; control word
OUT 83H     ; control register
MVI A, AAH  ; output AAH
OUT 81H     ; port B
OUT 82H     ; port C

; 2(b)
MVI A, 01H
MVI C, 08H  ; counter
loop:
OUT 82H     ; port C
RLC
DCR C 
JNZ loop

; 2(b) Alternative solution
; set PC0 - PC7 using BSR mode
MVI A, 01H
MVI C, 08H
back:
OUT 83H     ; control register
INR A 
INR A 
DCR C 
JNZ back
HLT