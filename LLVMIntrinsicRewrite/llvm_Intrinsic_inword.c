#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inword.md
unsigned short
__inword(unsigned short Port)
{
    unsigned short ret = 0;
    _asm {
	    mov dx, Port
		in ax, dx
		mov ret, ax
    }
    return ret;
}
