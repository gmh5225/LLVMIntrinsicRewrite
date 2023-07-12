
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writecr3.md
#ifdef _WIN64
void
__writecr3(unsigned long long Data)
{
    __asm__("mov %[Data], %%cr3" : : [Data] "r"(Data) : "memory");
}
#else
void
__writecr3(unsigned int Data)
{
    __asm__("mov %[Data], %%cr3" : : [Data] "r"(Data) : "memory");
}
#endif
