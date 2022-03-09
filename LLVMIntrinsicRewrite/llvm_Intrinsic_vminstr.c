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
	_vmwrite_err1:
		mov eax, 1
		ret
	_vmwrite_err2:
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

	  pop rsi; add by ourself
	  pop rbp

	  xor rax, rax
	  ret

	_vmread_err1:
	  mov eax, 1
	  pop rsi

	  pop rsi; add by ourself
	  pop rbp

	  ret

    _vmread_err2:
	  mov eax, 2
	  pop rsi

	  pop rsi; add by ourself
	  pop rbp

	  ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmlaunch.md
#ifdef _WIN64
unsigned char __vmx_vmlaunch(void) {
  _asm {
	  pop rbp; add by ourself
	  add rsp, 8 ;if Vmlaunch succeed we add rsp by ourself
	  vmlaunch 
	  jc _vmlaunch_err ;if Vmlaunch succeed will never be here
	  jz _vmlaunch_err_half
	  xor eax, eax
	  sub rsp, 8
	  ret
	  
	_vmlaunch_err:
	  mov eax, 1
	  sub rsp, 8
	  ret

    _vmlaunch_err_half:
      mov eax, 2
	  sub rsp, 8
      ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-off.md
#ifdef _WIN64
void __vmx_off() {
  _asm {
	  pop rbp; add by ourself
	  add rsp, 8
	  vmxoff
	  sub rsp, 8
	  ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmclear.md
#ifdef _WIN64
unsigned char __vmx_vmclear(unsigned __int64 *VmcsPhysicalAddress) {
  _asm {
	  push rdi
	  mov rdi, VmcsPhysicalAddress
	  vmclear [rdi]
	  pop rdi

	  jc _vmclear_err
	  jz _vmclear_err2
	  
	  pop rax
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmclear_err:

	  pop rax
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret

   _vmclear_err2:
	  pop rax
	  pop rdi
	  pop rbp

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
	  mov rdi, VmcsPhysicalAddress
	  vmptrld [rdi]
	  pop rdi
	  jc _vmptrld_err
	  jz _vmptrld_err2

	  pop rax
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmptrld_err:
	  pop rax
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret

    _vmptrld_err2:
	  pop rax
	  pop rdi
	  pop rbp

	  mov rax, 2
	  ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrst.md
#ifdef _WIN64
void __vmx_vmptrst(unsigned __int64 *VmcsPhysicalAddress) {
  _asm {
	    push rdi
		mov rdi, VmcsPhysicalAddress
		vmptrst [rdi]
		pop rdi
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmresume.md
#ifdef _WIN64
unsigned char __vmx_vmresume(void) {
  _asm {
	    pop rbp; add by ourself
		add rsp, 8
		vmresume
		sub rsp, 8
		ret
  }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-on.md
#ifdef _WIN64
unsigned char __vmx_on(unsigned __int64 *VmsSupportPhysicalAddress) {
  _asm {
	  push rdi
	  mov rdi, VmsSupportPhysicalAddress
	  vmxon [rdi]
	  pop rdi

	  jc _vmxon_err
	  
	  pop rax
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmxon_err:

	  pop rax
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret
  }
}
#endif
