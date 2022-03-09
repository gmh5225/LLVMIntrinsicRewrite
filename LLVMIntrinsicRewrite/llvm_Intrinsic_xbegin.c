#include <Windows.h>

// https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/intrinsics/intrinsics-for-avx2/intrinsics-for-tsx/intrinsics-for-restrict-transactional-mem-ops/xbegin.html
unsigned int
_xbegin()
{
    unsigned int status;
    __asm {
        mov   eax, 0xFFFFFFFF
        xbegin _txnL1
      _txnL1 :
        mov   status, eax
    }
    return status;
}
