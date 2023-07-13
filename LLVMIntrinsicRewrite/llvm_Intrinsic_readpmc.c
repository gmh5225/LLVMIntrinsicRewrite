#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readpmc.md
unsigned long long
__readpmc(unsigned long counter)
{
    unsigned long long retval;
    __asm__ __volatile__("rdpmc" : "=A"(retval) : "c"(counter));
    return retval;
}
