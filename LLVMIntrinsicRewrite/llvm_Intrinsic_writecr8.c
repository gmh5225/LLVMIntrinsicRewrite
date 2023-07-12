#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr8.md
#ifdef _WIN64
void
__writecr8(unsigned long long Data)
{
    __asm__("mov %[Data], %%cr8" : : [Data] "r"(Data) : "memory");
}
#endif
