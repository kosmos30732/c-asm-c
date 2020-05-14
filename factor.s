global factorization

SECTION .bss
    string resb 200
    reverse resb 200
SECTION .text
    factorization:
    xor eax, eax
    mov eax, ecx
    xor ecx, ecx
    mov ecx, [esp+4]
    
; save registers
    push ebx
    push eax ;like a ecx
    push edx

; clean registers    
    xor ebx, ebx
    xor eax, eax
    xor edx, edx

; mov first del
    mov ebx, 2

; process of factorization
    _next_del:
    xor edx, edx
    mov eax, ecx
    div ebx
    cmp edx, 0x0
    jne _inc_del
    mov ecx, eax
    push ecx
    push ebx

; write number of del to reverse
    mov eax, ebx
    _next_number_of_del:
    xor edx, edx
    mov ebx, 10
    div ebx
    add edx, '0'
    mov ebx, edx
    mov [reverse+edi], bl
    inc edi
    cmp eax, 0x0
    jne _next_number_of_del

; write del to string
    _next_number:
    dec edi
    mov al, [reverse+edi]
    mov [string+esi], al
    inc esi
    cmp edi, 0x0
    jne _next_number
    mov al, '*'
    mov [string+esi], al
    inc esi

    pop ebx
    pop ecx
    jmp _next_del
; inc del and check that the number not equal zero

    _inc_del:
    cmp eax, 0x0
    je _end_factorization
    inc ebx
    jmp _next_del
    _end_factorization:

; mov 0x0 to the end of string
    mov al, 0x0
    mov [string+esi], al

; mov pointer to string to return
    mov eax, string

; return value registers
    pop edx
    pop ecx
    pop ebx

    ret