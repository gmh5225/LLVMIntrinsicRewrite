#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/invlpg.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __invlpg(void *Address) {
#ifdef _WIN64
  _asm {
		invlpg [rcx]
  }
#else
  _asm {
	    push eax
		mov eax, dword ptr[esp + 4]
	    invlpg [eax]
		pop eax
	    ret 4
  }
#endif // _WIN64
}
