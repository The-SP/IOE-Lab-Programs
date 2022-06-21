; Lab 2, No 4(b)

        MVI A, 86H
        OUT 83H 
        MVI A, 05H  ; set PC2 i.e STBb signal
        OUT 83H

        MVI A, 0DH
        SIM         ; unmask RST 6.5
        EI
LOOP:   JMP LOOP

8FB9:   JMP ISR

ISR:    IN 81H
        OUT 80H
        EI
        RET