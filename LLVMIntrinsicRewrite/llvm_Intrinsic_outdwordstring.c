#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outdwordstring.md
void __outdwordstring(unsigned short Port, unsigned long *Buffer,
                      unsigned long Count) {
  for (unsigned long i = 0; i < Count; ++i) {
    unsigned long *pOut = (unsigned long *)(Buffer + i);
    _asm {
        mov dx, Port
#ifdef _WIN64
        mov rsi, pOut
#else
        mov esi, pOut
#endif
        outsd

    }
  }
}
