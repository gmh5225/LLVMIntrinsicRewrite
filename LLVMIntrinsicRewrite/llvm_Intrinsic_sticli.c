// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/disable.md
void __cdecl _disable(void)
{
    __asm__("cli" : : : "memory");
}

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/enable.md
void __cdecl _enable(void)
{
    __asm__("sti" : : : "memory");
}
