#include <Windows.h>

#ifdef _WIN64
#    define KI_USER_SHARED_DATA 0xFFFFF78000000000UI64
#else
#    define KI_USER_SHARED_DATA 0xFFFF9000
#endif

#define SharedSystemTime (KI_USER_SHARED_DATA + 0x14)
#define KeQuerySystemTime_MACRO(CurrentCount) *((PULONG64)(CurrentCount)) = *((volatile ULONG64 *)(SharedSystemTime))

VOID
KeQuerySystemTime(_Out_ PLARGE_INTEGER CurrentTime)
{
    KeQuerySystemTime_MACRO(CurrentTime);
}
