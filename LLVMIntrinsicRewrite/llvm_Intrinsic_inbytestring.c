#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inbytestring.md
void
__inbytestring(unsigned short Port, unsigned char *Buffer, unsigned long Count)
{
    for (unsigned long i = 0; i < Count; ++i)
    {
        unsigned char *pOut = (unsigned char *)(Buffer + i);
        _asm {
        mov dx, Port
#ifdef _WIN64
        mov rdi, pOut
#else
        mov edi, pOut
#endif
        insb

        }
    }
}
