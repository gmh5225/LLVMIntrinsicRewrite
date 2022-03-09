

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr4.md
#ifndef _WIN64
__declspec(naked)
#endif
    unsigned __int64 __readcr4(void)
{
#ifdef _WIN64
    _asm {
	    mov rax, cr4
    }
#else
    _asm {
		mov eax, cr4
		ret
    }
#endif // _WIN64
}
