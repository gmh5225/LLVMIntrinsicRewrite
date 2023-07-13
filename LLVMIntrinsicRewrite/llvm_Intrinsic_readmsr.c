

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/readmsr.md
#ifdef _WIN64
unsigned __int64
__readmsr(unsigned long __register)
{
    // Loads the contents of a 64-bit model specific register (MSR) specified in
    // the ECX register into registers EDX:EAX. The EDX register is loaded with
    // the high-order 32 bits of the MSR and the EAX register is loaded with the
    // low-order 32 bits. If less than 64 bits are implemented in the MSR being
    // read, the values returned to EDX:EAX in unimplemented bit locations are
    // undefined.
    unsigned long __edx;
    unsigned long __eax;
    __asm__("rdmsr" : "=d"(__edx), "=a"(__eax) : "c"(__register));
    return (((unsigned __int64)__edx) << 32) | (unsigned __int64)__eax;
}
#endif
