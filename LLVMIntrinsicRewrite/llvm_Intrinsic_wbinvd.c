__declspec(naked) void __wbinvd(void)
{
    _asm
    {
		wbinvd
		ret
    }
}
