

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readmsr.md
#ifndef _WIN64
__declspec(naked)
#endif
    __int64 __readmsr(int reg)
{
#ifdef _WIN64
    _asm {
	    xor rax, rax
		rdmsr
		shl rdx, 32
		or rax, rdx
    }
#else
    _asm {
		xor eax, eax
		xor edx, edx
		mov ecx, dword ptr[esp + 4]
		rdmsr
		ret 4
    }
#endif // _WIN64
}
