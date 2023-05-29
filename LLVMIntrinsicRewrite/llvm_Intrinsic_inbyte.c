#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inbyte.md
unsigned char
__inbyte(unsigned short Port)
{
    unsigned char byte;
    __asm__ __volatile__("inb %w[Port], %b[byte]" : [byte] "=a"(byte) : [Port] "Nd"(Port));
    return byte;
}

int __cdecl _inp(unsigned short Port)
{
    return __inbyte(Port);
}
