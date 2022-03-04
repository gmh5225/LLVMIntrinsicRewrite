# LLVMIntrinsicRewrite
LLVM Intrinsic rewrite for windows driver.

## DOC:
- https://github.com/MicrosoftDocs/cpp-docs/tree/main/docs/intrinsics
- https://namazso.github.io/x86/
- https://docs.oracle.com/cd/E36784_01/html/E36859/gntbx.html
- https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/intrinsics

## TODO:
```batch

1>lld-link : error : undefined symbol: __inbyte
1>lld-link : error : undefined symbol: __inword
1>lld-link : error : undefined symbol: __indword
1>lld-link : error : undefined symbol: __outbytestring
1>lld-link : error : undefined symbol: __outwordstring
1>lld-link : error : undefined symbol: __outdwordstring
1>lld-link : error : undefined symbol: __outbyte
1>lld-link : error : undefined symbol: __outword
1>lld-link : error : undefined symbol: __outdword
1>lld-link : error : undefined symbol: __readcr8
1>lld-link : error : undefined symbol: __writecr8
1>lld-link : error : undefined symbol: __cpuid
1>lld-link : error : undefined symbol: __readcr4
1>lld-link : error : undefined symbol: __writecr4
1>lld-link : error : undefined symbol: __vmx_vmlaunch
1>lld-link : error : undefined symbol: __vmx_off
1>lld-link : error : undefined symbol: __vmx_vmclear
1>lld-link : error : undefined symbol: __vmx_vmptrld
1>lld-link : error : undefined symbol: __vmx_vmptrst
1>lld-link : error : undefined symbol: __vmx_vmresume
```




