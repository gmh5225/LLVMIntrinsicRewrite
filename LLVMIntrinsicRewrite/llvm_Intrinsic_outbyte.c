#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outbyte.md
void
__outbyte(unsigned short Port, unsigned char Data)
{
    __asm__ __volatile__("outb %b[Data], %w[Port]" : : [Port] "Nd"(Port), [Data] "a"(Data));
}
