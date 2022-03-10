#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosw.md
void
__stosw(unsigned short *Destination, unsigned short Data, size_t Count)
{
    for (size_t i = 0; i < Count; ++i)
    {
        unsigned short *p = (unsigned short *)(Destination + i);
        _asm {
#ifdef _WIN64
            mov rdi, p
#else
            mov edi, p
#endif
            mov ax, Data
            stosw
        }
    }
}
