
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __writecr2(unsigned __int64 Data)
{
#ifdef _WIN64
    _asm {
		mov cr2, rcx
    }
#else
    _asm {
	    push eax
	    mov eax, dword ptr[esp + 4 + 4]
		mov cr2, eax
		pop eax
		ret 0x8
    }
#endif // _WIN64
}
