

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
#ifndef _WIN64
__declspec(naked)
#endif
    unsigned __int64 __readcr2(void)
{
#ifdef _WIN64
  _asm {
	    mov rax, cr2
  }
#else
  _asm {
		mov eax, cr2
		ret
  }
#endif // _WIN64
}
