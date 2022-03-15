#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/rdtscp.md
#ifndef _WIN64
__declspec(naked)
#endif
    unsigned __int64 __rdtscp(unsigned int *AUX)
{
#ifdef _WIN64
    _asm {
		xor rax, rax
	    push rcx
		push rdx
		push rsi
		rdtscp
		shl rdx, 32
		or rax, rdx
		mov rsi, qword ptr[rsp + 8]
		mov dword ptr[rsi], ecx
		pop rsi
		pop rdx
		pop rcx
    }
#else
    _asm {
	    xor eax, eax
	    xor edx, edx
		rdtscp
		push esi
	    mov esi, dword ptr[esp + 4]
		mov dword ptr[esi], ecx
		pop esi
	    ret 4
    }
#endif // _WIN64
}
