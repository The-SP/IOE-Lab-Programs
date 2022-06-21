; Lab 2, No 4(a)

        MVI A, BOH
        OUT 83H
        MVI A, 09H  ; set PC4 i.e enable STBa
        OUT 83H
        MVI A, 0EH  ; initialize interrupts
        SIM         ; unmask RST 5.5
        EI          ; enable interrupt
LOOP:   JMP LOOP  
; wait until interrupt
; On interrupt at RST 5.5, Program counter is vectored to 8FB3H

; 8FB3 Memory Address
8FB3:   JMP ISR ; jump to RST 5.5 service routine

ISR:    IN 80H      ; read from Port A
        OUT 81H     ; output to Port B
        EI          ; Re-enable interrupt
        RET