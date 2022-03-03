#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr0.md
#ifndef _WIN64
__declspec(naked)
#endif
    ULONG_PTR __readcr0(void) {
#ifdef _WIN64
  _asm {
	    mov rax, cr0
  }
#else
  _asm {
		mov eax, cr0
		ret
  }
#endif // _WIN64
}
