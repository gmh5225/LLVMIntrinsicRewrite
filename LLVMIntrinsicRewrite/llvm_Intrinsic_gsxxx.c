void
__writegsbyte(unsigned long Offset, unsigned char Data)
{
    __asm__ __volatile__("movb %b[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}

void
__writegsword(unsigned long Offset, unsigned short Data)
{
    __asm__ __volatile__("movw %w[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}

void
__writegsdword(unsigned long Offset, unsigned long Data)
{
    __asm__ __volatile__("movl %k[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}

#ifdef _WIN64
void
__writegsqword(unsigned long Offset, unsigned long long Data)
{
    __asm__ __volatile__("movq %q[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "r"(Data) : "memory");
}
#endif

void
__incgsbyte(unsigned long Offset)
{
    __asm__ __volatile__("incb %%gs:%a[Offset]" : : [Offset] "ir"(Offset) : "memory");
}

void
__incgsword(unsigned long Offset)
{
    __asm__ __volatile__("incw %%gs:%a[Offset]" : : [Offset] "ir"(Offset) : "memory");
}

void
__incgsdword(unsigned long Offset)
{
    __asm__ __volatile__("incl %%gs:%a[Offset]" : : [Offset] "ir"(Offset) : "memory");
}

#ifdef _WIN64
void
__incgsqword(unsigned long Offset)
{
    __asm__ __volatile__("incq %%gs:%a[Offset]" : : [Offset] "ir"(Offset) : "memory");
}
#endif

void
__addgsbyte(unsigned long Offset, unsigned char Data)
{
    __asm__ __volatile__("addb %b[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}

void
__addgsword(unsigned long Offset, unsigned short Data)
{
    __asm__ __volatile__("addw %w[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}

void
__addgsdword(unsigned long Offset, unsigned long Data)
{
    __asm__ __volatile__("addl %k[Data], %%gs:%a[Offset]" : : [Offset] "ir"(Offset), [Data] "ir"(Data) : "memory");
}
