#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readdr.md
#ifdef _WIN64
unsigned long long
__readdr(unsigned int reg)
{
    unsigned long long value;
    switch (reg)
    {
    case 0:
        __asm__ __volatile__("movq %%dr0, %q[value]" : [value] "=r"(value));
        break;
    case 1:
        __asm__ __volatile__("movq %%dr1, %q[value]" : [value] "=r"(value));
        break;
    case 2:
        __asm__ __volatile__("movq %%dr2, %q[value]" : [value] "=r"(value));
        break;
    case 3:
        __asm__ __volatile__("movq %%dr3, %q[value]" : [value] "=r"(value));
        break;
    case 4:
        __asm__ __volatile__("movq %%dr4, %q[value]" : [value] "=r"(value));
        break;
    case 5:
        __asm__ __volatile__("movq %%dr5, %q[value]" : [value] "=r"(value));
        break;
    case 6:
        __asm__ __volatile__("movq %%dr6, %q[value]" : [value] "=r"(value));
        break;
    case 7:
        __asm__ __volatile__("movq %%dr7, %q[value]" : [value] "=r"(value));
        break;
    }
    return value;
}
#else
unsigned int
__readdr(unsigned int reg)
{
    unsigned int value;
    switch (reg)
    {
    case 0:
        __asm__ __volatile__("mov %%dr0, %[value]" : [value] "=r"(value));
        break;
    case 1:
        __asm__ __volatile__("mov %%dr1, %[value]" : [value] "=r"(value));
        break;
    case 2:
        __asm__ __volatile__("mov %%dr2, %[value]" : [value] "=r"(value));
        break;
    case 3:
        __asm__ __volatile__("mov %%dr3, %[value]" : [value] "=r"(value));
        break;
    case 4:
        __asm__ __volatile__("mov %%dr4, %[value]" : [value] "=r"(value));
        break;
    case 5:
        __asm__ __volatile__("mov %%dr5, %[value]" : [value] "=r"(value));
        break;
    case 6:
        __asm__ __volatile__("mov %%dr6, %[value]" : [value] "=r"(value));
        break;
    case 7:
        __asm__ __volatile__("mov %%dr7, %[value]" : [value] "=r"(value));
        break;
    }
    return value;
}
#endif
