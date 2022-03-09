#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outwordstring.md
void
__outwordstring(unsigned short Port, unsigned short *Buffer, unsigned long Count)
{
    for (unsigned long i = 0; i < Count; ++i)
    {
        unsigned short *pOut = (unsigned short *)(Buffer + i);
        _asm {
        mov dx, Port
#ifdef _WIN64
        mov rsi, pOut
#else
        mov esi, pOut
#endif
        outsw

        }
    }
}
