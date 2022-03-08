#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/outdword.md
void __outdword(unsigned short Port, unsigned long Data) {
  _asm {
		mov dx, Port
		mov eax, Data
		out dx, eax
  }
}
