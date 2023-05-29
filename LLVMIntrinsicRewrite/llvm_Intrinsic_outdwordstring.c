#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outdwordstring.md
void
__outdwordstring(unsigned short Port, unsigned long *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; outsl" : : [Port] "d"(Port), [Buffer] "S"(Buffer), "c"(Count));
}
