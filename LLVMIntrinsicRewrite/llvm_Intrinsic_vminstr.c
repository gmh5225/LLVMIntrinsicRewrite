#include <Windows.h>

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmwrite.md
#ifdef _WIN64
__declspec(naked) unsigned char __vmx_vmwrite(size_t Field, size_t FieldValue)
{
    _asm {
		vmwrite rcx, rdx
		jc _vmwrite_err1
		jz _vmwrite_err2
		xor al, al
		ret
		
	  _vmwrite_err1:
		mov al, 1
		ret
			
	  _vmwrite_err2:
		mov al, 2
		ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmread.md
#ifdef _WIN64
__declspec(naked) unsigned char __vmx_vmread(size_t Field, size_t *FieldValue)
{
    _asm {

	  mov qword ptr[rdx], 0
	  vmread [rdx], rcx
	  jc _vmread_err1
	  jz _vmread_err2
	  xor al, al
	  ret

	  _vmread_err1:
	  mov al, 1
	  ret
		
      _vmread_err2:
	  mov al, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmlaunch.md
#ifdef _WIN64
__declspec(naked) unsigned char __vmx_vmlaunch(void)
{
    _asm {
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
__declspec(naked) void __vmx_off()
{
    _asm {
	  vmxoff
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmclear.md
#ifdef _WIN64
__declspec(naked) unsigned char __vmx_vmclear(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  vmclear [rcx]

	  jc _vmclear_err
	  jz _vmclear_err2
	  xor al, al
	  ret

	_vmclear_err:
	  mov al, 1
	  ret

    _vmclear_err2:
	  mov al, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrld.md
#ifdef _WIN64
__declspec(naked) int __vmx_vmptrld(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
	  vmptrld [rcx]
	
	  jc _vmptrld_err
	  jz _vmptrld_err2

	  xor eax, eax
	  ret

	_vmptrld_err:
	  mov eax, 1
	  ret

    _vmptrld_err2:
	  mov eax, 2
	  ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmptrst.md
#ifdef _WIN64
__declspec(naked) void __vmx_vmptrst(unsigned __int64 *VmcsPhysicalAddress)
{
    _asm {
		vmptrst [rcx]
		ret
    }
}
#endif

// https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/intrinsics/vmx-vmresume.md
#ifdef _WIN64
__declspec(naked) unsigned char __vmx_vmresume(void)
{
    _asm {
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
__declspec(naked) unsigned char __vmx_on(unsigned __int64 *VmsSupportPhysicalAddress)
{
    _asm {
	  vmxon [rcx]

	  jc _vmxon_err

	  xor al, al
	  ret

	_vmxon_err:

	  mov al, 1
	  ret
    }
}
#endif
