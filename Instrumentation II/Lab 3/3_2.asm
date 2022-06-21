; Lab 3, No 2
; Display "PASUSE" continuously in scrolling fashion.

        MVI A, 80H
        OUT 43H
START:  MVI B, 05H
        LXI H, 9000H            ;look-up table location
TABLE:  MOV A, M
        CALL DISP               ;call display subroutine
        CALL DELAY
        INX H
        DCR B                   ;jump until we get null
        JNZ TABLE
        JMP START
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
; Hex code for "PAUSE": 8C, 88, C1, 92, 86