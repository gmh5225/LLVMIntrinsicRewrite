#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outword.md
void
__outword(unsigned short Port, unsigned short Data)
{
    _asm {
		mov dx, Port
		mov ax, Data
		out dx, ax
    }
}
