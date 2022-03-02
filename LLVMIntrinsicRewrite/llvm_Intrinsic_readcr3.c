

#ifndef _WIN64
__declspec(naked)
#endif
    unsigned __int64 __readcr3(void) {
#ifdef _WIN64
  _asm {
	    mov rax, cr3
  }
#else
  _asm {
		mov eax, cr3
		ret
  }
#endif // _WIN64
}
