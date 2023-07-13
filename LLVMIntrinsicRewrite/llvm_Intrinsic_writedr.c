#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writedr.md
#ifdef _WIN64
void
__writedr(unsigned int reg, unsigned long long value)
{
    switch (reg)
    {
    case 0:
        __asm__("movq %q[value], %%dr0" : : [value] "r"(value) : "memory");
        break;
    case 1:
        __asm__("movq %q[value], %%dr1" : : [value] "r"(value) : "memory");
        break;
    case 2:
        __asm__("movq %q[value], %%dr2" : : [value] "r"(value) : "memory");
        break;
    case 3:
        __asm__("movq %q[value], %%dr3" : : [value] "r"(value) : "memory");
        break;
    case 4:
        __asm__("movq %q[value], %%dr4" : : [value] "r"(value) : "memory");
        break;
    case 5:
        __asm__("movq %q[value], %%dr5" : : [value] "r"(value) : "memory");
        break;
    case 6:
        __asm__("movq %q[value], %%dr6" : : [value] "r"(value) : "memory");
        break;
    case 7:
        __asm__("movq %q[value], %%dr7" : : [value] "r"(value) : "memory");
        break;
    }
}
#else
void
__writedr(unsigned int reg, unsigned int value)
{
    switch (reg)
    {
    case 0:
        __asm__("mov %[value], %%dr0" : : [value] "r"(value) : "memory");
        break;
    case 1:
        __asm__("mov %[value], %%dr1" : : [value] "r"(value) : "memory");
        break;
    case 2:
        __asm__("mov %[value], %%dr2" : : [value] "r"(value) : "memory");
        break;
    case 3:
        __asm__("mov %[value], %%dr3" : : [value] "r"(value) : "memory");
        break;
    case 4:
        __asm__("mov %[value], %%dr4" : : [value] "r"(value) : "memory");
        break;
    case 5:
        __asm__("mov %[value], %%dr5" : : [value] "r"(value) : "memory");
        break;
    case 6:
        __asm__("mov %[value], %%dr6" : : [value] "r"(value) : "memory");
        break;
    case 7:
        __asm__("mov %[value], %%dr7" : : [value] "r"(value) : "memory");
        break;
    }
}
#endif // _WIN64
