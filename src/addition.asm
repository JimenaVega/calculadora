segment .text
        global  addition
        global  substraction

addition:
        enter   0,0              ; make room for sum on stack

        mov     eax, [ebp+12]    ; eax = B
        add     eax, [ebp+8]     ; eax = eax + A

        leave
        ret

substraction:
        enter   0,0             ; make room for sub on stack

        mov     eax, [ebp+8]    ; eax = A
        sub     eax, [ebp+12]   ; eax = eax - B

        leave
        ret