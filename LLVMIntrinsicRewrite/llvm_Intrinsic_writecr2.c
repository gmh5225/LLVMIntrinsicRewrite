
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
__declspec(naked) void __writecr2(unsigned __int64 Data)
{
    _asm
    {
		mov cr2, rcx
        ret
    }
}
