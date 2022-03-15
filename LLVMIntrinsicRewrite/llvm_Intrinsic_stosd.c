#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosd.md
void
__stosd(unsigned long *Destination, unsigned long Data, size_t Count)
{
#ifdef _WIN64
    _asm {
            push rax
            push rcx
            push rdi
            mov rax, Data
            mov rcx, Count
            mov rdi, Destination
            rep stosd
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
            rep stosd
            pop edi
            pop ecx
            pop eax
    }
#endif
}
