#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/indwordstring.md
void __indwordstring(unsigned short Port, unsigned long *Buffer,
                     unsigned long Count) {
  for (unsigned long i = 0; i < Count; ++i) {
    unsigned long *pOut = (unsigned long *)(Buffer + i);
    _asm {
        mov dx, Port
#ifdef _WIN64
        mov rdi, pOut
#else
        mov edi, pOut
#endif
        insd

    }
  }
}
