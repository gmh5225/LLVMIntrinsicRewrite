#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/invlpg.md
void
__invlpg(void *Address)
{
    __asm__ __volatile__("invlpg (%[Address])" : : [Address] "b"(Address) : "memory");
}
