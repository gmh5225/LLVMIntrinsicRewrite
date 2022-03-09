

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/cpuid-cpuidex.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __cpuidex(int CPUInfo[4], int Function, int SubLeaf)
{
#ifdef _WIN64
    _asm {
	    push rcx
		push rsi
	    mov eax, edx
		mov ecx, r8d
	    cpuid
		mov rsi, qword ptr[rsp + 8]
		mov dword ptr[rsi], eax
		mov dword ptr[rsi + 4], ebx
		mov dword ptr[rsi + 8], ecx
		mov dword ptr[rsi + 0xc], edx
		pop rsi
		pop rcx
    }
#else
    _asm {
	    push ebp
		mov ebp, esp
		push esi
		mov eax, dword ptr[ebp + 0xc]
		mov ecx, dword ptr[ebp + 0x10]
		cpuid
		mov esi, dword ptr[ebp + 8]
		mov dword ptr[esi], eax
		mov dword ptr[esi + 4], ebx
		mov dword ptr[esi + 8], ecx
		mov dword ptr[esi + 0xc], edx
		pop esi
		pop ebp
		ret 0xc
    }
#endif // _WIN64
}

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/cpuid-cpuidex.md
#ifndef _WIN64
__declspec(naked)
#endif
    void __cpuid(int CPUInfo[4], int Function)
{
#ifdef _WIN64
    _asm {
		push rcx
		push rsi
		mov eax, edx
		xor ecx, ecx
		cpuid
		mov rsi, qword ptr[rsp + 8]
		mov dword ptr[rsi], eax
		mov dword ptr[rsi + 4], ebx
		mov dword ptr[rsi + 8], ecx
		mov dword ptr[rsi + 0xc], edx
		pop rsi
		pop rcx
    }
#else
    _asm {
		push ebp
		mov ebp, esp
		push esi
		mov eax, dword ptr[ebp + 0xc]
		xor ecx, ecx
		cpuid
		mov esi, dword ptr[ebp + 8]
		mov dword ptr[esi], eax
		mov dword ptr[esi + 4], ebx
		mov dword ptr[esi + 8], ecx
		mov dword ptr[esi + 0xc], edx
		pop esi
		pop ebp
		ret 0xc
    }
#endif // _WIN64
}
