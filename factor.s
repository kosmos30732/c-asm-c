global factorization

SECTION .text
    factorization:
    mov ecx, [esp+4]
    mov edi, [esp+8]
    
; mov first del
    mov ebx, 2

; process of factorization
    _next_devider:
    xor edx, edx
    mov eax, ecx
    div ebx
    cmp edx, 0x0
    jne _inc_del
    mov esi, eax

; call print_res
    push esi
    push ebx
    call edi
    add esp, 8

; checking the returned value
    cmp eax, 0x0
    jne _end_factorization

; checking if it was the last devider
    cmp esi, 0x0
    je _end_factorization
    mov ecx, esi
    jmp _next_devider

; inc del and check that the number not equal zero
    _inc_del:
    cmp eax, 0x0
    je _end_factorization
    inc ebx
    jmp _next_devider

; exit from factorization
    _end_factorization:
    ret