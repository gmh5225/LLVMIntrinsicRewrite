#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr4.md
__declspec(naked) ULONG_PTR __readcr4(void)
{
    _asm
    {
	    mov rax, cr4
		ret
    }
}
