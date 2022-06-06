; Lab 1, No 1
; A table consists of ten 8-bit data starting at 8050H. Write an 8085 program to store the sum of odd numbers at 8060H and store sum of even numbers at 8070H. Also display the sum at output ports.

MVI A, 80H 
OUT 43H
LXI H, 8050H
LXI D, 0H
MVI C, 0AH
BACK: MOV A, M
RRC
MOV A, M
JC ODD
ADD E
MOV E, A
JMP SKIP
ODD: ADD D
MOV D, A
SKIP: INX H
DCR C
JNZ BACK
MVI L, 60H
MOV M, D
MOV A, D
OUT 42H
MVI L, 70H
MOV M, E
MOV A, E
OUT 41H
HLT