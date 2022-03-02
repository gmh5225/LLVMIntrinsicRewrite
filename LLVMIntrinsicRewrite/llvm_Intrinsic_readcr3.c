

__declspec(noinline) unsigned __int64 __readcr3(void) {
#ifdef _WIN64
  _asm {
		mov rax, cr3
  }
#else
  _asm {
		mov eax, cr3
  }
#endif // _WIN64
}
