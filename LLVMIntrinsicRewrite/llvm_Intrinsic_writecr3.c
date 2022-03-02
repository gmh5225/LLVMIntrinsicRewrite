
#ifndef _WIN64
__declspec(naked)
#endif
    void __writecr3(unsigned __int64 Data) {
#ifdef _WIN64
  _asm {
		mov cr3, rcx
		ret
  }
#else
  _asm {
	    mov eax, dword ptr[esp + 4]
		mov cr3, eax
		ret
  }
#endif // _WIN64
}
