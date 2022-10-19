#include <Windows.h>

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_invpcid&ig_expand=4132
#ifndef _WIN64
__declspec(naked)
#endif
    void _invpcid(unsigned int type, void *descriptor)
{
#ifdef _WIN64
    _asm {
		push rax
		xor rax, rax
		mov eax, ecx
		invpcid rax, [rdx]
		pop rax
    }
#else
    _asm {
	    push eax
		pusb ebx
		mov eax, dword ptr[esp + 0xc]
		mov ebx, dword ptr[esp + 0x10]
	    invpcid eax, [ebx]
		pop ebx
		pop eax
	    ret 8
    }
#endif // _WIN64
}
