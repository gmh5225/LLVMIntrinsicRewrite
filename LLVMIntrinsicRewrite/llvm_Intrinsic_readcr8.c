#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr8.md
__declspec(naked) ULONG_PTR __readcr8(void)
{
    _asm
    {
	    mov rax, cr8
		ret
    }
}
