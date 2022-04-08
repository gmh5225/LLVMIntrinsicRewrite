// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/disable.md
void
_disable(void)
{
    _asm {
	    cli
    }
}

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/enable.md
void
_enable(void)
{
    _asm {
	    sti
    }
}
