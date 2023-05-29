#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inwordstring.md
void
__inwordstring(unsigned short Port, unsigned short *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; insw"
                         : [Buffer] "=D"(Buffer), [Count] "=c"(Count)
                         : "d"(Port), "[Buffer]"(Buffer), "[Count]"(Count)
                         : "memory");
}
