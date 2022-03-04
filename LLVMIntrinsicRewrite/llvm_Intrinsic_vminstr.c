#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmwrite.md
#ifdef _WIN64
unsigned char __vmx_vmwrite(size_t Field, size_t FieldValue) {
  _asm {
		vmwrite rcx, rdx
		jc _vmwrite_err1
		jz _vmwrite_err2
		xor eax, eax
		ret
	_vmwrite_err1 :
		mov eax, 1
		ret
	_vmwrite_err2 :
		mov eax, 2
		ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmread.md
#ifdef _WIN64
unsigned char __vmx_vmread(size_t Field, size_t *FieldValue) {
  _asm {
	  push rsi
	  vmread rsi, rcx

	  jc _vmread_err1
	  jz _vmread_err2
	  mov qword ptr[rdx], rsi
	  pop rsi
	  xor rax, rax
	  ret

	_vmread_err1 :
	  mov eax, 1
	  pop rsi
	  ret

    _vmread_err2 :
	  mov eax, 2
	  pop rsi
	  ret
  }
}
#endif
