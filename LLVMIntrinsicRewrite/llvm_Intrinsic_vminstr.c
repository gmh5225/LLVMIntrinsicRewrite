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

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmlaunch.md
#ifdef _WIN64
unsigned char __vmx_vmlaunch(void) {
  _asm {
	  mov eax, 0
	  mov ebx, 0
	  mov ecx, 0
	  mov edx, 0xf00
	  mov edi, 0
	  mov esi, 0
	  vmlaunch

	  jc _vmlaunch_err
	  jz _vmlaunch_err_half
	  xor eax, eax
	  ret
	  
	_vmlaunch_err:
	  mov eax, 1
	  ret

    _vmlaunch_err_half:
      mov eax, 2
      ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-off.md
#ifdef _WIN64
void __vmx_off() {
  _asm {
	  vmxoff
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmclear.md
#ifdef _WIN64
unsigned char __vmx_vmclear(unsigned __int64 *VmcsPhysicalAddress) {
  _asm {
	  push rdi
	  vmclear [rsp]
	  pop rdi

	  jc _vmclear_err
	  jz _vmclear_err2
	  xor rax, rax
	  ret

	_vmclear_err:
	  mov rax, 1
	  ret

	_vmclear_err2 :
	  mov rax, 2
	  ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrld.md
#ifdef _WIN64
int __vmx_vmptrld(unsigned __int64 *VmcsPhysicalAddress) {
  _asm {
	  push rdi
	  vmptrld [rsp]
	  pop rdi
	  jc _vmptrld_err
	  jz _vmptrld_err2

	  xor rax, rax
	  ret

	_vmptrld_err:
	  mov rax, 1
	  ret

	_vmptrld_err2 :
	  mov rax, 2
	  ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrst.md
#ifdef _WIN64
void __vmx_vmptrst(unsigned __int64 *VmcsPhysicalAddress) {
  _asm {
		vmptrst [rdi]
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmresume.md
#ifdef _WIN64
unsigned char __vmx_vmresume(void) {
  _asm {
		vmresume
  }
}
#endif
