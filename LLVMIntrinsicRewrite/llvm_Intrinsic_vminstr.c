#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmwrite.md
#ifdef _WIN64
unsigned char
__vmx_vmwrite(size_t Field, size_t FieldValue)
{
    _asm {
		pushfq
		vmwrite rcx, rdx
		jc _vmwrite_err1
		jz _vmwrite_err2

		popfq
		mov rsp, rbp
		pop rbx
		pop rbp
		xor eax, eax
		ret
	  _vmwrite_err1:
		popfq
		mov rsp, rbp
		pop rbx
		pop rbp
		mov eax, 1
		ret
	  _vmwrite_err2:
		popfq
		mov rsp, rbp
		pop rbx
		pop rbp
		mov eax, 2
		ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmread.md
#ifdef _WIN64
unsigned char
__vmx_vmread(size_t Field, size_t *FieldValue)
{
    _asm {
	  pushfq
	  mov qword ptr[rdx], 0
	  vmread [rdx], rcx

	  jc _vmread_err1
	  jz _vmread_err2

	  popfq
	  mov rsp, rbp
      pop rbx
	  pop rbp
	  xor rax, rax
	  ret

	_vmread_err1:
	  popfq
	  mov rsp, rbp
      pop rbx
	  pop rbp
	  mov eax, 1
	  ret

    _vmread_err2:
	  popfq
	  mov rsp, rbp
      pop rbx
	  pop rbp
	  mov eax, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmlaunch.md
#ifdef _WIN64
unsigned char
__vmx_vmlaunch(void)
{
    _asm {

	  add rsp, 0x18
	  vmlaunch
	  sub rsp, 0x18
    }
    return 1;
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-off.md
#ifdef _WIN64
void
__vmx_off()
{
    _asm {
	  vmxoff
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmclear.md
#ifdef _WIN64
unsigned char
__vmx_vmclear(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmcsPhysicalAddress
	  pushfq
	  vmclear [rdi]
	  pop rdi

	  jc _vmclear_err
	  jz _vmclear_err2
	  
	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmclear_err:
	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret

    _vmclear_err2:
	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov rax, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrld.md
#ifdef _WIN64
int
__vmx_vmptrld(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmcsPhysicalAddress
	  pushfq
	  vmptrld [rdi]
	  pop rdi
	  jc _vmptrld_err
	  jz _vmptrld_err2

	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmptrld_err:
	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret

    _vmptrld_err2:
	  popfq
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov rax, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrst.md
#ifdef _WIN64
void
__vmx_vmptrst(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	    push rdi
		mov rdi, VmcsPhysicalAddress
		pushfq
		vmptrst [rdi]
		popfq
		pop rdi
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmresume.md
#ifdef _WIN64
unsigned char
__vmx_vmresume(void)
{
    _asm {
		add rsp, 0x18
		vmresume
		sub rsp, 0x18
    }
    return 1;
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-on.md
#ifdef _WIN64
unsigned char
__vmx_on(unsigned __int64 *VmsSupportPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmsSupportPhysicalAddress
	  pushfq
	  vmxon [rdi]
	  pop rdi

	  jc _vmxon_err
	  
	  popfq
	  mov rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor rax, rax
	  ret

	_vmxon_err:
	  popfq
	  mov rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov rax, 1
	  ret
    }
}
#endif
