#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/inbyte.md
unsigned char
__inbyte(unsigned short Port)
{
    unsigned char ret = 0;
    _asm {
	    mov dx, Port
		in al, dx
		mov ret, al
    }
    return ret;
}
