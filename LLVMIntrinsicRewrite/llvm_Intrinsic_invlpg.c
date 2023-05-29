#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/invlpg.md
__declspec(naked) void __invlpg(void *Address)
{
#ifdef _WIN64
    _asm {
		invlpg [rcx]
		ret
    }
#else
    _asm {
	    push eax
		mov eax, dword ptr[esp + 8]
	    invlpg [eax]
		pop eax
	    ret 4
    }
#endif // _WIN64
}
