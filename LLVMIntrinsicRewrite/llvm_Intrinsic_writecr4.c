
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr4.md
__declspec(naked) void __writecr4(unsigned __int64 Data)
{
    _asm
    {
		mov cr4, rcx
        ret
    }
}
