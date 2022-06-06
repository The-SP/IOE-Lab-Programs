; Lab 2, No 2

MVI A, 90H  ; control word
OUT 83H     ; control register
MVI A, AAH  ; output AAH
OUT 80H     ; port A
OUT 81H     ; port B
OUT 82H     ; port C
HLT