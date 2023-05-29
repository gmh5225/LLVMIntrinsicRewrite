#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outword.md
void
__outword(unsigned short Port, unsigned short Data)
{
    __asm__ __volatile__("outw %w[Data], %w[Port]" : : [Port] "Nd"(Port), [Data] "a"(Data));
}
