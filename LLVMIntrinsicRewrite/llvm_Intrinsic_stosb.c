#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosb.md
void
__stosb(unsigned char *Dest, unsigned char Data, size_t Count)
{
    __asm__ __volatile__("rep; stosb"
                         : [Dest] "=D"(Dest), [Count] "=c"(Count)
                         : "[Dest]"(Dest), "a"(Data), "[Count]"(Count));
}
