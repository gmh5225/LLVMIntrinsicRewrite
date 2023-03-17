#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosb.md
void
__stosb(unsigned char *Destination, unsigned char Data, size_t Count)
{
#ifdef _WIN64
    _asm {
            push rax
            push rcx
            push rdi
            mov rax, Data
            mov rcx, Count
            mov rdi, Destination
            rep stosb
            pop rdi
            pop rcx
            pop rax
    }
#else
    _asm {
            push eax
            push ecx
            push edi
            mov eax, Data
            mov ecx, Count
            mov edi, Destination
            rep stosb
            pop edi
            pop ecx
            pop eax
    }
#endif
}
