#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
#ifdef _WIN64
unsigned long long
__readcr2(void)
{
    unsigned long long value;
    __asm__ __volatile__("mov %%cr2, %[value]" : [value] "=r"(value));
    return value;
}
#else
unsigned long
__readcr2(void)
{
    unsigned long value;
    __asm__ __volatile__("mov %%cr2, %[value]" : [value] "=r"(value));
    return value;
}
#endif
