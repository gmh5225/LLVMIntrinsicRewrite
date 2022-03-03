#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readpmc.md
#ifndef _WIN64
__declspec(naked)
#endif
    unsigned __int64 __readpmc(unsigned long counter) {
#ifdef _WIN64
  _asm {
	    xor rax, rax
	    rdpmc
		shl rdx, 32
		or rax, rdx
  }
#else
  _asm {
		xor eax, eax
		xor edx, edx
		mov ecx, dword ptr[esp + 4]
		rdpmc
		ret 4
  }
#endif // _WIN64
}
