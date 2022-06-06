; lab 2, no 1

; 1(a)
MVI A, 81H  ; control word
OUT 43H     ; control register
MVI A, AAH
OUT 40H     ; port A
MVI A, 55H
OUT 41H     ; port b

; 1(b)
MVI A, 0DH  ; set PC6
OUT 43H     ; control register
MVI A, 09H  ; set PC4
OUT 43H
MVI A, 05H  ; set PC2
OUT 43H
MVI A, 01H  ; set PC0
OUT 43H

; 1(c)
MVI A, 80H  ; all bits of port C in output mode
OUT 43H
; reapeat 1(b)
MVI A, 0DH  ; set PC6
OUT 43H
MVI A, 09H  ; set PC4
OUT 43H
MVI A, 05H  ; set PC2
OUT 43H
MVI A, 01H  ; set PC0
OUT 43H
HLT