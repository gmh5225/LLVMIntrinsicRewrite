#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outbytestring.md
void
__outbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; outsb" : : [Port] "d"(Port), [Buffer] "S"(Buffer), "c"(Count));
}
