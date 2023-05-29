#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/indwordstring.md

void
__indwordstring(unsigned short Port, unsigned long *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; insl"
                         : [Buffer] "=D"(Buffer), [Count] "=c"(Count)
                         : "d"(Port), "[Buffer]"(Buffer), "[Count]"(Count)
                         : "memory");
}
