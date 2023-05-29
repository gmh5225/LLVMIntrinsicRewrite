#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/indword.md
unsigned long
__indword(unsigned short Port)
{
    unsigned long dword;
    __asm__ __volatile__("inl %w[Port], %k[dword]" : [dword] "=a"(dword) : [Port] "Nd"(Port));
    return dword;
}
