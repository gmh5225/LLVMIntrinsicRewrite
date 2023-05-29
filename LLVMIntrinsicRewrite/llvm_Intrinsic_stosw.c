#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosw.md
void
__stosw(unsigned short *Dest, unsigned short Data, size_t Count)
{
    __asm__ __volatile__("rep; stosw"
                         : [Dest] "=D"(Dest), [Count] "=c"(Count)
                         : "[Dest]"(Dest), "a"(Data), "[Count]"(Count));
}
