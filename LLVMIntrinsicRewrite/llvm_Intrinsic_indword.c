#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/indword.md
unsigned long __inword(unsigned short Port) {
  unsigned long ret = 0;
  _asm {
	    mov dx, Port
		in eax, dx
		mov ret, eax
  }
  return ret;
}
