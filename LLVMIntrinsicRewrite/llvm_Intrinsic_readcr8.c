#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr8.md
#ifdef _WIN64
unsigned __int64 __readcr8(void) {
  _asm {
	    mov rax, cr8
  }
}
#endif // _WIN64
