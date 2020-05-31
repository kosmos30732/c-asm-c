global factorization

SECTION .text
    factorization:

;save registers
    push ebx
    push esi
    push edi

; mov start value
    mov ecx, [esp+16]
    mov edi, [esp+20]
    
; mov first divider
    mov ebx, 2

; process of factorization
    _next_divider:
    xor edx, edx
    mov eax, ecx
    div ebx
    cmp edx, 0x0
    jne _inc_del
    mov esi, eax

; call print_res for print divider
    push esi
    push ebx
    call edi
    add esp, 8

; checking the returned value
    cmp eax, 0x0
    jne _end_factorization

; checking if it was the last divider
    cmp esi, 0x0
    je _end_factorization
    mov ecx, esi
    jmp _next_divider

; inc divider and check that the number not equal zero
    _inc_del:
    cmp eax, 0x0
    je _end_factorization
    inc ebx
    jmp _next_divider

; exit from factorization
    _end_factorization:

; return registers
    pop edi
    pop esi
    pop ebx

    ret