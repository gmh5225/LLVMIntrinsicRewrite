#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writedr.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __writedr(unsigned int DebugRegister, ULONG_PTR DebugValue) {
#ifdef _WIN64
  _asm {
		pushfq
		cmp ecx, 0
		je _dr0
		cmp ecx, 1
		je _dr1
		cmp ecx, 2
		je _dr2
		cmp ecx, 3
		je _dr3
		cmp ecx, 6
		je _dr6
		cmp ecx, 7
		je _dr7
		jmp _end
	_dr0:
		mov dr0, rdx
		jmp _end
	_dr1:
		mov dr1, rdx
	    jmp _end
	_dr2:
		mov dr2, rdx
		jmp _end
	_dr3:
		mov dr3, rdx
		jmp _end
	_dr6:
		mov dr6, rdx
		jmp _end
	_dr7:
		mov dr7, rdx
	_end:
		popfq
  }
#else
  _asm {
	    pushfd
		push eax
		cmp dword ptr[esp + 4 + 8], 0
		je _dr0
		cmp dword ptr[esp + 4 + 8], 1
		je _dr1
		cmp dword ptr[esp + 4 + 8], 2
		je _dr2
		cmp dword ptr[esp + 4 + 8], 3
		je _dr3
		cmp dword ptr[esp + 4 + 8], 6
		je _dr6
		cmp dword ptr[esp + 4 + 8], 7
		je _dr7
		jmp _end
	_dr0:	
		mov eax, dword ptr[esp + 8 + 8]
		mov dr0, eax
		jmp _end
	_dr1:
		mov eax, dword ptr[esp + 8 + 8]
		mov dr1, eax
		jmp _end
	_dr2:
		mov eax, dword ptr[esp + 8 + 8]
		mov dr2, eax
		jmp _end
	_dr3:
		mov eax, dword ptr[esp + 8 + 8]
		mov dr3, eax
		jmp _end
	_dr6:
		mov eax, dword ptr[esp + 8 + 8]
		mov dr6, eax
		jmp _end
	_dr7:
		mov eax, dword ptr[esp + 8 + 8]
		mov dr7, eax
		jmp _end
	_end:
		pop eax
		popfd
		ret 0x8
  }
#endif // _WIN64
}
