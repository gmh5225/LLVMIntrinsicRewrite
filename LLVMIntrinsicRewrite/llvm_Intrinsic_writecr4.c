
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr4.md
#ifdef _WIN64
void
__writecr4(unsigned long long Data)
{
    __asm__("mov %[Data], %%cr4" : : [Data] "r"(Data) : "memory");
}
#else
void
__writecr4(unsigned int Data)
{
    __asm__("mov %[Data], %%cr4" : : [Data] "r"(Data) : "memory");
}
#endif
