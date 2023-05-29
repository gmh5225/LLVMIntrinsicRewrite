
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr3.md
__declspec(naked) void __writecr3(unsigned __int64 Data)
{
    _asm
    {
		mov cr3, rcx
		ret
    }
}
