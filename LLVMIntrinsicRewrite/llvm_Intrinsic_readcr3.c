#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr3.md
#ifdef _WIN64
unsigned long long
__readcr3(void)
{
    unsigned long long value;
    __asm__ __volatile__("mov %%cr3, %[value]" : [value] "=r"(value));
    return value;
}
#else
unsigned long
__readcr3(void)
{
    unsigned long value;
    __asm__ __volatile__("mov %%cr3, %[value]" : [value] "=r"(value));
    return value;
}
#endif
