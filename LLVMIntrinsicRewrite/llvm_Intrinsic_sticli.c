// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/disable.md
__declspec(naked) void _disable(void)
{
    _asm
    {
	    cli
        ret
    }
}

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/enable.md
__declspec(naked) void _enable(void)
{
    _asm
    {
	    sti
        ret
    }
}
