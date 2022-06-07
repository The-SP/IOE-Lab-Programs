; Lab 2, No 3

; 3(a)
MVI A, 90H
OUT 83H     ; control reg. of expansion kit
MVI A, 80H 
OUT 43H     ; control reg. of mp board
IN 80H      ; port A of expansion kit
OUT 81H     ; port B of expansion kit
OUT 40H     ; port A of mp board

; 3(b)
MVI A, 80H
OUT 43H
MVI A, 92H  ; read data from port A and B
OUT 83H
IN 80H 
MOV B, A 
IN 81H
ADD B 
OUT 40H     ; port A of mp board   
JNC SKIP
MVI A, 01H
OUT 42H     ; port C of mp board
SKIP:
RST 5