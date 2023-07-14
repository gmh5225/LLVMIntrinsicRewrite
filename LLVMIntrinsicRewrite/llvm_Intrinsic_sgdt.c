#ifdef _WIN64
__declspec(naked) void _sgdt(void *Destination)
{
    _asm
    {
		sgdt    fword ptr [rcx]
		ret
    }
}

__declspec(naked) void _lgdt(void *Source)
{
    _asm
    {
		lgdt    fword ptr [rcx]
		ret
    }
}
#endif
