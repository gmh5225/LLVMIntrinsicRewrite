
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr0.md

#ifdef _WIN64
void
__writecr0(unsigned long long Data)
{
    __asm__("mov %[Data], %%cr0" : : [Data] "r"(Data) : "memory");
}
#else
void
__writecr0(unsigned int Data)
{
    __asm__("mov %[Data], %%cr0" : : [Data] "r"(Data) : "memory");
}
#endif
