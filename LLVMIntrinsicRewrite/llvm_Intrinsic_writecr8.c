#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr8.md
#ifdef _WIN64
void __writecr8(unsigned __int64 Data) {
  _asm {
	    mov cr8, rcx
  }
}
#endif // _WIN64
