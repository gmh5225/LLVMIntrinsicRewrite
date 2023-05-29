#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr8.md
#ifdef _WIN64
__declspec(naked) void __writecr8(unsigned __int64 Data)
{
    _asm
    {
	    mov cr8, rcx
        ret
    }
}
#endif // _WIN64
