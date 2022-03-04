#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/stosq.md
#ifdef _WIN64
void __stosq(unsigned __int64 *Destination, unsigned __int64 Data,
             size_t Count) {
  for (size_t i = 0; i < Count; ++i) {
    unsigned __int64 *p = (unsigned __int64 *)(Destination + i);
    _asm {
            mov rdi, p
            mov rax,rdx
            stosq
    }
  }
}
#endif
