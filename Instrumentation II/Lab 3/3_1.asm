; Lab 3: Interfacing 7 segment Display
; No 1: Display sequence of digits 0-9 in a right to left scrolling fashion with appropriate delay.

        MVI A, 80H
        OUT 43H
        LXI H, 9000H            ;look-up table location
        MVI B, 0AH
TABLE:  MOV A, M
        CALL DISP               ;call display subroutine
        CALL DELAY
        INX H
        DCR B
        JNZ TABLE
        RST 5

;;  Following subroutine displays the content of accumulator in 7-segment display
DISP:	MVI C, 08H              ;counter to transmit 8-bit
L1:     RLC                     ;to pass each bit serially from MSB to LSB
        MOV E, A
        OUT 41H                 ;to pass a bit via PB0
        MVI A, 01H
        OUT 42H                 ;clock single on PC0(rise)
        DCR A
        OUT 42H                 ;clock signal on PC0(fall)
        MOV A, E
        DCR C
        JNZ L1
        RET

;; Delay subroutine
DELAY:  PUSH PSW
        LXI D, FFFFH
D1:     DCX D
        MOV A, D
        ORA E
        JNZ D1
        POP PSW
        RET


; Look-up Table Data
; Hex code for digits 0-9
; C0, F9, A4, B0, 99, 92, 82, F8, 80, 90