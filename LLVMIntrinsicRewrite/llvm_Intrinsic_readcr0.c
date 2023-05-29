#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr0.md
__declspec(naked) ULONG_PTR __readcr0(void)
{
    _asm
    {
	    mov rax, cr0
		ret
    }
}
