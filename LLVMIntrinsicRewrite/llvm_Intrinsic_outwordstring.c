#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outwordstring.md
void
__outwordstring(unsigned short Port, unsigned short *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; outsw" : : [Port] "d"(Port), [Buffer] "S"(Buffer), "c"(Count));
}
