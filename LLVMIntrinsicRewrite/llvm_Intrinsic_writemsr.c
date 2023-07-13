

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/writemsr.md
#ifdef _WIN64
void
__writemsr(unsigned long Register, unsigned long long Value)
{
    __asm__ __volatile__("wrmsr" : : "a"(Value), "d"(Value >> 32), "c"(Register));
}
#endif
