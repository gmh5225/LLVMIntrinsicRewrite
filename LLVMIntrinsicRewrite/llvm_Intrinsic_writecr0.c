
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr0.md
__declspec(naked) void __writecr0(unsigned __int64 Data)
{
    _asm
    {
		mov cr0, rcx
		ret
    }
}
