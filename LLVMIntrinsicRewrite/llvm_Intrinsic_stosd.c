#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosd.md
void
__stosd(unsigned long *Destination, unsigned long Data, size_t Count)
{
    for (size_t i = 0; i < Count; ++i)
    {
        unsigned long *p = (unsigned long *)(Destination + i);
        _asm {
#ifdef _WIN64
            mov rdi, p
#else
            mov edi, p
#endif
            mov eax, Data
            stosd
        }
    }
}
