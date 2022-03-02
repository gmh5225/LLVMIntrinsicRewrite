
#ifndef _WIN64
__declspec(naked)
#endif
    void __writemsr(unsigned long Register, unsigned __int64 Value) {
#ifdef _WIN64
  _asm {
		mov eax,edx
		shr rdx,32
		wrmsr
  }
#else
  _asm {
	    mov ecx, dword ptr[esp + 4]
		mov eax, dword ptr[esp + 8]
		mov edx, dword ptr[esp + 0xc]
		wrmsr
		ret 0xc
  }
#endif // _WIN64
}
