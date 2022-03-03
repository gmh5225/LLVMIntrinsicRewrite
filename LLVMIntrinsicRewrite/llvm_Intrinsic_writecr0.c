
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr0.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __writecr0(unsigned __int64 Data) {
#ifdef _WIN64
  _asm {
		mov cr0, rcx
  }
#else
  _asm {
	    push eax
	    mov eax, dword ptr[esp + 4 + 4]
		mov cr0, eax
		pop eax
		ret 0x8
  }
#endif // _WIN64
}
