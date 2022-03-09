

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writemsr.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __writemsr(unsigned long Register, unsigned __int64 Value)
{
#ifdef _WIN64
  _asm {
		mov eax, edx
		shr rdx, 32
		wrmsr
  }
#else
  _asm {
	    push ecx
		push edx
		push eax

	    mov ecx, dword ptr[esp + 4 + 0xc]
		mov eax, dword ptr[esp + 8 + 0xc]
		mov edx, dword ptr[esp + 0xc + 0xc]
		wrmsr

		pop eax
		pop edx
		pop ecx

		ret 0xc
  }
#endif // _WIN64
}
