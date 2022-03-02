# LLVMIntrinsicRewrite
LLVM Intrinsic rewrite for windows driver.

## DOC:
- https://github.com/MicrosoftDocs/cpp-docs/tree/main/docs/intrinsics
- https://namazso.github.io/x86/

## TODO:
```batch
1>lld-link : error : undefined symbol: _xbegin
1>lld-link : error : undefined symbol: _xend
1>lld-link : error : undefined symbol: __cpuidex
1>lld-link : error : undefined symbol: KeQuerySystemTime
1>lld-link : error : undefined symbol: __vmx_vmwrite
1>lld-link : error : undefined symbol: __vmx_vmread
1>lld-link : error : undefined symbol: __rdtscp
1>lld-link : error : undefined symbol: __invlpg
1>lld-link : error : undefined symbol: __stosq
1>lld-link : error : undefined symbol: __readpmc
1>lld-link : error : undefined symbol: __readdr
1>lld-link : error : undefined symbol: __inbytestring
1>lld-link : error : undefined symbol: __inwordstring
1>lld-link : error : undefined symbol: __indwordstring
```




