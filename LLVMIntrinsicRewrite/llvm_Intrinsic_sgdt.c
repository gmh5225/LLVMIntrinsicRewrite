__declspec(naked) void _sgdt(void *Destination)
{
    _asm
    {
		sgdt    fword ptr [rcx]
		ret
    }
}
