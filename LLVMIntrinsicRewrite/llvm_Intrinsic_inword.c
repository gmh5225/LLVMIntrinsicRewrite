#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inword.md
unsigned short
__inword(unsigned short Port)
{
    unsigned short word;
    __asm__ __volatile__("inw %w[Port], %w[word]" : [word] "=a"(word) : [Port] "Nd"(Port));
    return word;
}
