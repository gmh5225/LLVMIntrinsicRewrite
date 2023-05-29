#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outdword.md
void
__outdword(unsigned short Port, unsigned long Data)
{
    __asm__ __volatile__("outl %k[Data], %w[Port]" : : [Port] "Nd"(Port), [Data] "a"(Data));
}
