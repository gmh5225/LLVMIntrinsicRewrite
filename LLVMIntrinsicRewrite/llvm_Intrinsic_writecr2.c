
// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readcr2.md
#ifdef _WIN64
void
__writecr2(unsigned long long Data)
{
    __asm__("mov %[Data], %%cr2" : : [Data] "r"(Data) : "memory");
}
#else
void
__writecr2(unsigned int Data)
{
    __asm__("mov %[Data], %%cr2" : : [Data] "r"(Data) : "memory");
}
#endif
