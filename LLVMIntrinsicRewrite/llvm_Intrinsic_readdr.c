#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readdr.md
__declspec(naked) ULONG_PTR __readdr(unsigned int DebugRegister)
{
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
		mov rax, dr0
		jmp _end
	_dr1:
		mov rax, dr1
	    jmp _end
	_dr2:
		mov rax, dr2
		jmp _end
	_dr3:
		mov rax, dr3
		jmp _end
	_dr6:
		mov rax, dr6
		jmp _end
	_dr7:
		mov rax, dr7
	_end:
		popfq
		ret
    }
#else
    _asm {
	    pushfd
		cmp dword ptr[esp + 8], 0
		je _dr0
		cmp dword ptr[esp + 8], 1
		je _dr1
		cmp dword ptr[esp + 8], 2
		je _dr2
		cmp dword ptr[esp + 8], 3
		je _dr3
		cmp dword ptr[esp + 8], 6
		je _dr6
		cmp dword ptr[esp + 8], 7
		je _dr7
		jmp _end
	_dr0:	
		mov eax, dr0
		jmp _end
	_dr1:
		mov eax, dr1
		jmp _end
	_dr2:
		mov eax, dr2
		jmp _end
	_dr3:
		mov eax, dr3
		jmp _end
	_dr6:
		mov eax, dr6
		jmp _end
	_dr7:
		mov eax, dr7
		jmp _end
	_end:
		popfd
		ret 0x4
    }
#endif // _WIN64
}
