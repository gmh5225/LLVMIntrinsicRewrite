#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
__declspec(naked) ULONG_PTR __readcr2(void)
{
    _asm
    {
	    mov rax, cr2
		ret
    }
}
