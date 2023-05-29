#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr3.md
__declspec(naked) ULONG_PTR __readcr3(void)
{
    _asm
    {
	    mov rax, cr3
		ret
    }
}
