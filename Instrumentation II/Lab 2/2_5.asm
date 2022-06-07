; Lab 2, No 5

        MVI A, 09H  ; set PC4
        OUT 83H
        MVI A, 0DH  ; set PC6
        OUT 83H 
        MVI A, F0H  ; mode 2
        OUT 83H 
        
        MVI A, 0DH  ; initialize interrupts
        SIM         ; unmask RST 6.5
        EI          ; enable interrupts
LOOP:   JMP LOOP    ; wait untill interrupt

8FB9:   JMP ISR

ISR:    IN 80H      ; read from A
        OUT 81H     ; output to B
        MVI A, 0FH
        OUT 80H     ; output OF to A
        EI          ; re-enable interrupt
        RET