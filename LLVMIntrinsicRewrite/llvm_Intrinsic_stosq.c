#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosq.md
#ifdef _WIN64
void
__stosq(unsigned long long *Dest, unsigned long long Data, size_t Count)
{
    __asm__ __volatile__("rep; stosq"
                         : [Dest] "=D"(Dest), [Count] "=c"(Count)
                         : "[Dest]"(Dest), "a"(Data), "[Count]"(Count));
}
#endif
