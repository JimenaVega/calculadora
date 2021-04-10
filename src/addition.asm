segment .text
        global  addition
        global substraction

addition:
        enter   0,0              ; make room for sum on stack

        mov     eax, [ebp+12]    ; eax = B
        add     eax, [ebp+8]     ; ecx = ecx + A

        leave
        ret



