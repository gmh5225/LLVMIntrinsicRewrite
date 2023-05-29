#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosd.md
void
__stosd(unsigned long *Dest, unsigned long Data, size_t Count)
{
    __asm__ __volatile__("rep; stosl"
                         : [Dest] "=D"(Dest), [Count] "=c"(Count)
                         : "[Dest]"(Dest), "a"(Data), "[Count]"(Count));
}
