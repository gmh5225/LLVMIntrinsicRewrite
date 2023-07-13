// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/sidt.md
#ifdef _WIN64
__declspec(naked) void __sidt(void *Destination)
{
    _asm
    {
		sidt    fword ptr [rcx]
        ret
    }
}

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/lidt.md
__declspec(naked) void __lidt(void *Source)
{
    _asm
    {
		lidt    fword ptr [rcx]
        ret
    }
}
#endif
