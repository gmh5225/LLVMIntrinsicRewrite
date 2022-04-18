
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/segmentlimit.md

unsigned long
__segmentlimit(unsigned long a)
{
    unsigned long ret = 0;
    _asm {
        lsl eax, [a]
        mov ret, eax
    }

    return ret;
}
