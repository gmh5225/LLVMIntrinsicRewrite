#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outbytestring.md
void
__outbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count)
{
    for (unsigned long i = 0; i < Count; ++i)
    {
        unsigned char *pOut = (unsigned char *)(Buffer + i);
        _asm {
        mov dx, Port
#ifdef _WIN64
        mov rsi, pOut
#else
        mov esi, pOut
#endif
        outsb

        }
    }
}
