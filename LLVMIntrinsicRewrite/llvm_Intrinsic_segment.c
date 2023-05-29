
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/segmentlimit.md

unsigned long
__segmentlimit(unsigned long a)
{
    unsigned long retval;
    __asm__ __volatile__("lsl %[a], %[retval]" : [retval] "=r"(retval) : [a] "rm"(a));
    return retval;
}
