#ifdef _WIN64
__declspec(naked) void _sgdt(void *Destination)
{
    _asm
    {
		sgdt    fword ptr [rcx]
		ret
    }
}
#endif
