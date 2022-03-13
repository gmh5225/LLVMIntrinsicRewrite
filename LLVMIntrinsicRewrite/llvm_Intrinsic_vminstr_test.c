#include <Windows.h>

////////////////////////////////////////////////////////////////////////////////////////
//// this file only for testing

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmwrite.md
#ifdef _WIN64
unsigned char
test__vmx_vmwrite(size_t Field, size_t FieldValue)
{
    _asm {
		vmwrite rcx, rdx
		jc _vmwrite_err1
		jz _vmwrite_err2

		mov rsp, rbp
		pop rbx
		pop rbp
		xor al, al
		ret
	  _vmwrite_err1:
		mov rsp, rbp
		pop rbx
		pop rbp
		mov al, 1
		ret
	  _vmwrite_err2:
		mov rsp, rbp
		pop rbx
		pop rbp
		mov al, 2
		ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmread.md
#ifdef _WIN64
unsigned char
test__vmx_vmread(size_t Field, size_t *FieldValue)
{
    _asm {

	  mov qword ptr[rdx], 0
	  vmread [rdx], rcx
	  jc _vmread_err1
	  jz _vmread_err2

	  mov rsp, rbp
      pop rbx
	  pop rbp
	  xor al, al
	  ret

	_vmread_err1:
	  mov rsp, rbp
      pop rbx
	  pop rbp
	  mov al, 1
	  ret

    _vmread_err2:
	  mov rsp, rbp
      pop rbx
	  pop rbp
	  mov al, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmlaunch.md
#ifdef _WIN64
unsigned char
test__vmx_vmlaunch(void)
{
    _asm {
	  mov rsp, rbp
	  pop rbx
	  pop rbp
	  vmlaunch
	  jc _vmlaunch_err ;if vmlaunch succeed will never be here
	  jz _vmlaunch_err_half

	  xor al, al
	  ret

	_vmlaunch_err:
	  mov al, 1
	  ret

    _vmlaunch_err_half:
	  mov al, 2
      ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-off.md
#ifdef _WIN64
void
test__vmx_off()
{
    _asm {
	  vmxoff
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmclear.md
#ifdef _WIN64
unsigned char
test__vmx_vmclear(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmcsPhysicalAddress
	  vmclear [rdi]
	  pop rdi

	  jc _vmclear_err
	  jz _vmclear_err2
	  
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor al, al
	  ret

	_vmclear_err:
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov al, 1
	  ret

    _vmclear_err2:
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov al, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrld.md
#ifdef _WIN64
int
test__vmx_vmptrld(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmcsPhysicalAddress

	  vmptrld [rdi]
	  pop rdi
	  jc _vmptrld_err
	  jz _vmptrld_err2

	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor eax, eax
	  ret

	_vmptrld_err:
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov eax, 1
	  ret

    _vmptrld_err2:
	  mov     rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov eax, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrst.md
#ifdef _WIN64
void
test__vmx_vmptrst(unsigned __int64 *VmcsPhysicalAddress)
{
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
unsigned char
test__vmx_vmresume(void)
{
    _asm {
		mov rsp, rbp
		pop rbx
		pop rbp
		vmresume
		jc _vmresume_err ;if vmresume succeed will never be here
	    jz _vmresume_err_half

	    xor al, al
	    ret

	  _vmresume_err:
	    mov al, 1
	    ret

      _vmresume_err_half:
	    mov al, 2
        ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-on.md
#ifdef _WIN64
unsigned char
test__vmx_on(unsigned __int64 *VmsSupportPhysicalAddress)
{
    _asm {
	  push rdi
	  mov rdi, VmsSupportPhysicalAddress
	  vmxon [rdi]
	  pop rdi

	  jc _vmxon_err
	  mov rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  xor al, al
	  ret

	_vmxon_err:
	  mov rsp, rbp
	  pop rbx
	  pop rdi
	  pop rbp

	  mov al, 1
	  ret
    }
}
#endif
