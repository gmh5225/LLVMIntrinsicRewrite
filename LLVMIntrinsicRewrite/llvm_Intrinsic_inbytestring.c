#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inbytestring.md
void
__inbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count)
{
    __asm__ __volatile__("rep; insb"
                         : [Buffer] "=D"(Buffer), [Count] "=c"(Count)
                         : "d"(Port), "[Buffer]"(Buffer), "[Count]"(Count)
                         : "memory");
}
