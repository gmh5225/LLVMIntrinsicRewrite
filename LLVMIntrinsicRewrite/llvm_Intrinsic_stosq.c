#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosq.md
#ifdef _WIN64
void
__stosq(unsigned __int64 *Destination, unsigned __int64 Data, size_t Count)
{
    _asm {
            push rax
            push rcx
            push rdi
            mov rax, Data
            mov rcx, Count
            mov rdi, Destination
            rep stosq
            pop rdi
            pop rcx
            pop rax
    }
}
#endif
