#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outbyte.md
void __outbyte(unsigned short Port, unsigned char Data) {
  _asm {
		mov dx, Port
		mov al, Data
		out dx, al
  }
}
