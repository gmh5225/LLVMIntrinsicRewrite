#include <Windows.h>

// https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/intrinsics/intrinsics-for-avx2/intrinsics-for-tsx/intrinsics-for-restrict-transactional-mem-ops/xend.html
__declspec(naked) unsigned int _xend()
{
    __asm { 
        xend 
		ret
    }
}
