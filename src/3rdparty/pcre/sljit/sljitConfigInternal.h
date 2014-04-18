begin_unit
begin_comment
comment|/*  *    Stack-less Just-In-Time compiler  *  *    Copyright 2009-2012 Zoltan Herczeg (hzmester@freemail.hu). All rights reserved.  *  * Redistribution and use in source and binary forms, with or without modification, are  * permitted provided that the following conditions are met:  *  *   1. Redistributions of source code must retain the above copyright notice, this list of  *      conditions and the following disclaimer.  *  *   2. Redistributions in binary form must reproduce the above copyright notice, this list  *      of conditions and the following disclaimer in the documentation and/or other materials  *      provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT  * SHALL THE COPYRIGHT HOLDER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_SLJIT_CONFIG_INTERNAL_H_
end_ifndef
begin_define
DECL|macro|_SLJIT_CONFIG_INTERNAL_H_
define|#
directive|define
name|_SLJIT_CONFIG_INTERNAL_H_
end_define
begin_comment
comment|/*    SLJIT defines the following macros depending on the target architecture:     Feature detection (boolean) macros:    SLJIT_32BIT_ARCHITECTURE : 32 bit architecture    SLJIT_64BIT_ARCHITECTURE : 64 bit architecture    SLJIT_WORD_SHIFT : the shift required to apply when accessing a sljit_sw/sljit_uw array by index    SLJIT_DOUBLE_SHIFT : the shift required to apply when accessing a double array by index    SLJIT_LITTLE_ENDIAN : little endian architecture    SLJIT_BIG_ENDIAN : big endian architecture    SLJIT_UNALIGNED : allows unaligned memory accesses for non-fpu operations (only!)    SLJIT_INDIRECT_CALL : see SLJIT_FUNC_OFFSET() for more information    SLJIT_RETURN_ADDRESS_OFFSET : a return instruction always adds this offset to the return address     Types and useful macros:    sljit_sb, sljit_ub : signed and unsigned 8 bit byte    sljit_sh, sljit_uh : signed and unsigned 16 bit half-word (short) type    sljit_si, sljit_ui : signed and unsigned 32 bit integer type    sljit_sw, sljit_uw : signed and unsigned machine word, enough to store a pointer    sljit_p : unsgined pointer value (usually the same as sljit_uw, but              some 64 bit ABIs may use 32 bit pointers)    sljit_s : single precision floating point value    sljit_d : double precision floating point value    SLJIT_CALL : C calling convention define for both calling JIT form C and C callbacks for JIT    SLJIT_W(number) : defining 64 bit constants on 64 bit architectures (compiler independent helper) */
end_comment
begin_if
if|#
directive|if
operator|!
operator|(
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_V5
operator|&&
name|SLJIT_CONFIG_ARM_V5
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_V7
operator|&&
name|SLJIT_CONFIG_ARM_V7
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_THUMB2
operator|&&
name|SLJIT_CONFIG_ARM_THUMB2
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_64
operator|&&
name|SLJIT_CONFIG_ARM_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_32
operator|&&
name|SLJIT_CONFIG_MIPS_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_64
operator|&&
name|SLJIT_CONFIG_MIPS_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_SPARC_32
operator|&&
name|SLJIT_CONFIG_SPARC_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_TILEGX
operator|&&
name|SLJIT_CONFIG_TILEGX
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_AUTO
operator|&&
name|SLJIT_CONFIG_AUTO
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_UNSUPPORTED
operator|&&
name|SLJIT_CONFIG_UNSUPPORTED
operator|)
operator|)
end_if
begin_error
error|#
directive|error
literal|"An architecture must be selected"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Sanity check. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_ARM_V5
operator|&&
name|SLJIT_CONFIG_ARM_V5
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_ARM_V7
operator|&&
name|SLJIT_CONFIG_ARM_V7
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_ARM_THUMB2
operator|&&
name|SLJIT_CONFIG_ARM_THUMB2
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_ARM_64
operator|&&
name|SLJIT_CONFIG_ARM_64
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_TILEGX
operator|&&
name|SLJIT_CONFIG_TILEGX
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_32
operator|&&
name|SLJIT_CONFIG_MIPS_32
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_64
operator|&&
name|SLJIT_CONFIG_MIPS_64
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_SPARC_32
operator|&&
name|SLJIT_CONFIG_SPARC_32
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_AUTO
operator|&&
name|SLJIT_CONFIG_AUTO
operator|)
expr|\
operator|+
operator|(
name|defined
name|SLJIT_CONFIG_UNSUPPORTED
operator|&&
name|SLJIT_CONFIG_UNSUPPORTED
operator|)
operator|>=
literal|2
end_if
begin_error
error|#
directive|error
literal|"Multiple architectures are selected"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Auto select option (requires compiler support) */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_AUTO
operator|&&
name|SLJIT_CONFIG_AUTO
operator|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386
argument_list|)
end_if
begin_define
DECL|macro|SLJIT_CONFIG_X86_32
define|#
directive|define
name|SLJIT_CONFIG_X86_32
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_X86_64
define|#
directive|define
name|SLJIT_CONFIG_X86_64
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM__
argument_list|)
end_elif
begin_ifdef
ifdef|#
directive|ifdef
name|__thumb2__
end_ifdef
begin_define
DECL|macro|SLJIT_CONFIG_ARM_THUMB2
define|#
directive|define
name|SLJIT_CONFIG_ARM_THUMB2
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_ARM_V7
define|#
directive|define
name|SLJIT_CONFIG_ARM_V7
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_CONFIG_ARM_V5
define|#
directive|define
name|SLJIT_CONFIG_ARM_V5
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_ARM_64
define|#
directive|define
name|SLJIT_CONFIG_ARM_64
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC64
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_POWER
argument_list|)
operator|&&
name|defined
argument_list|(
name|__64BIT__
argument_list|)
operator|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_PPC_64
define|#
directive|define
name|SLJIT_CONFIG_PPC_64
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PWR
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PWR2
argument_list|)
operator|||
name|defined
argument_list|(
name|_POWER
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_PPC_32
define|#
directive|define
name|SLJIT_CONFIG_PPC_32
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LP64
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_MIPS_32
define|#
directive|define
name|SLJIT_CONFIG_MIPS_32
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips64
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_MIPS_64
define|#
directive|define
name|SLJIT_CONFIG_MIPS_64
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_SPARC_32
define|#
directive|define
name|SLJIT_CONFIG_SPARC_32
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__tilegx__
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_TILEGX
define|#
directive|define
name|SLJIT_CONFIG_TILEGX
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Unsupported architecture */
end_comment
begin_define
DECL|macro|SLJIT_CONFIG_UNSUPPORTED
define|#
directive|define
name|SLJIT_CONFIG_UNSUPPORTED
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !_WIN32 */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if
begin_define
DECL|macro|SLJIT_CONFIG_X86_64
define|#
directive|define
name|SLJIT_CONFIG_X86_64
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_ARM_
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CONFIG_ARM_V5
define|#
directive|define
name|SLJIT_CONFIG_ARM_V5
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_CONFIG_X86_32
define|#
directive|define
name|SLJIT_CONFIG_X86_32
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !WIN32 */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SLJIT_CONFIG_AUTO */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_UNSUPPORTED
operator|&&
name|SLJIT_CONFIG_UNSUPPORTED
operator|)
end_if
begin_undef
DECL|macro|SLJIT_EXECUTABLE_ALLOCATOR
undef|#
directive|undef
name|SLJIT_EXECUTABLE_ALLOCATOR
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
operator|(
name|defined
name|SLJIT_STD_MACROS_DEFINED
operator|&&
name|SLJIT_STD_MACROS_DEFINED
operator|)
end_if
begin_comment
comment|/* These libraries are needed for the macros below. */
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* STD_MACROS_DEFINED */
end_comment
begin_comment
comment|/* General macros:    Note: SLJIT is designed to be independent from them as possible.     In release mode (SLJIT_DEBUG is not defined) only the following macros are needed: */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_MALLOC
end_ifndef
begin_define
DECL|macro|SLJIT_MALLOC
define|#
directive|define
name|SLJIT_MALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_FREE
end_ifndef
begin_define
DECL|macro|SLJIT_FREE
define|#
directive|define
name|SLJIT_FREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_MEMMOVE
end_ifndef
begin_define
DECL|macro|SLJIT_MEMMOVE
define|#
directive|define
name|SLJIT_MEMMOVE
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
value|memmove(dest, src, len)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_ZEROMEM
end_ifndef
begin_define
DECL|macro|SLJIT_ZEROMEM
define|#
directive|define
name|SLJIT_ZEROMEM
parameter_list|(
name|dest
parameter_list|,
name|len
parameter_list|)
value|memset(dest, 0, len)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SLJIT_LIKELY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SLJIT_UNLIKELY
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>=
literal|3
operator|)
end_if
begin_define
DECL|macro|SLJIT_LIKELY
define|#
directive|define
name|SLJIT_LIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x), 1)
end_define
begin_define
DECL|macro|SLJIT_UNLIKELY
define|#
directive|define
name|SLJIT_UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x), 0)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_LIKELY
define|#
directive|define
name|SLJIT_LIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define
begin_define
DECL|macro|SLJIT_UNLIKELY
define|#
directive|define
name|SLJIT_UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !defined(SLJIT_LIKELY)&& !defined(SLJIT_UNLIKELY) */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_INLINE
end_ifndef
begin_comment
comment|/* Inline functions. Some old compilers do not support them. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
operator|&&
name|__SUNPRO_C
operator|<=
literal|0x510
end_if
begin_define
DECL|macro|SLJIT_INLINE
define|#
directive|define
name|SLJIT_INLINE
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_INLINE
define|#
directive|define
name|SLJIT_INLINE
value|__inline
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_INLINE */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_CONST
end_ifndef
begin_comment
comment|/* Const variables. */
end_comment
begin_define
DECL|macro|SLJIT_CONST
define|#
directive|define
name|SLJIT_CONST
value|const
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_UNUSED_ARG
end_ifndef
begin_comment
comment|/* Unused arguments. */
end_comment
begin_define
DECL|macro|SLJIT_UNUSED_ARG
define|#
directive|define
name|SLJIT_UNUSED_ARG
parameter_list|(
name|arg
parameter_list|)
value|(void)arg
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_STATIC
operator|&&
name|SLJIT_CONFIG_STATIC
operator|)
end_if
begin_comment
comment|/* Static ABI functions. For all-in-one programs. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if
begin_comment
comment|/* Disable unused warnings in gcc. */
end_comment
begin_define
DECL|macro|SLJIT_API_FUNC_ATTRIBUTE
define|#
directive|define
name|SLJIT_API_FUNC_ATTRIBUTE
value|static __attribute__((unused))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_API_FUNC_ATTRIBUTE
define|#
directive|define
name|SLJIT_API_FUNC_ATTRIBUTE
value|static
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_API_FUNC_ATTRIBUTE
define|#
directive|define
name|SLJIT_API_FUNC_ATTRIBUTE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* (defined SLJIT_CONFIG_STATIC&& SLJIT_CONFIG_STATIC) */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_CACHE_FLUSH
end_ifndef
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
end_if
begin_comment
comment|/* Not required to implement on archs with unified caches. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
end_define
begin_elif
elif|#
directive|elif
name|defined
name|__APPLE__
end_elif
begin_comment
comment|/* Supported by all macs since Mac OS 10.5.    However, it does not work on non-jailbroken iOS devices,    although the compilation is successful. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|sys_icache_invalidate((char*)(from), (char*)(to) - (char*)(from))
end_define
begin_elif
elif|#
directive|elif
name|defined
name|__ANDROID__
end_elif
begin_comment
comment|/* Android lacks __clear_cache; instead, cacheflush should be used. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|cacheflush((long)(from), (long)(to), 0)
end_define
begin_elif
elif|#
directive|elif
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
end_elif
begin_comment
comment|/* The __clear_cache() implementation of GCC is a dummy function on PowerPC. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|ppc_cache_flush((from), (to))
end_define
begin_elif
elif|#
directive|elif
operator|(
name|defined
name|SLJIT_CONFIG_SPARC_32
operator|&&
name|SLJIT_CONFIG_SPARC_32
operator|)
end_elif
begin_comment
comment|/* The __clear_cache() implementation of GCC is a dummy function on Sparc. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|sparc_cache_flush((from), (to))
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Calls __ARM_NR_cacheflush on ARM-Linux. */
end_comment
begin_define
DECL|macro|SLJIT_CACHE_FLUSH
define|#
directive|define
name|SLJIT_CACHE_FLUSH
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|__clear_cache((char*)(from), (char*)(to))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_CACHE_FLUSH */
end_comment
begin_comment
comment|/* 8 bit byte type. */
end_comment
begin_typedef
DECL|typedef|sljit_ub
typedef|typedef
name|unsigned
name|char
name|sljit_ub
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sb
typedef|typedef
name|signed
name|char
name|sljit_sb
typedef|;
end_typedef
begin_comment
comment|/* 16 bit half-word type. */
end_comment
begin_typedef
DECL|typedef|sljit_uh
typedef|typedef
name|unsigned
name|short
name|int
name|sljit_uh
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sh
typedef|typedef
name|signed
name|short
name|int
name|sljit_sh
typedef|;
end_typedef
begin_comment
comment|/* 32 bit integer type. */
end_comment
begin_typedef
DECL|typedef|sljit_ui
typedef|typedef
name|unsigned
name|int
name|sljit_ui
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_si
typedef|typedef
name|signed
name|int
name|sljit_si
typedef|;
end_typedef
begin_comment
comment|/* Machine word type. Can encapsulate a pointer.      32 bit for 32 bit machines.      64 bit for 64 bit machines. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_UNSUPPORTED
operator|&&
name|SLJIT_CONFIG_UNSUPPORTED
operator|)
end_if
begin_comment
comment|/* Just to have something. */
end_comment
begin_define
DECL|macro|SLJIT_WORD_SHIFT
define|#
directive|define
name|SLJIT_WORD_SHIFT
value|0
end_define
begin_typedef
DECL|typedef|sljit_uw
typedef|typedef
name|unsigned
name|long
name|int
name|sljit_uw
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sw
typedef|typedef
name|long
name|int
name|sljit_sw
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
operator|!
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
expr|\
operator|&&
operator|!
operator|(
name|defined
name|SLJIT_CONFIG_ARM_64
operator|&&
name|SLJIT_CONFIG_ARM_64
operator|)
expr|\
operator|&&
operator|!
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
expr|\
operator|&&
operator|!
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_64
operator|&&
name|SLJIT_CONFIG_MIPS_64
operator|)
expr|\
operator|&&
operator|!
operator|(
name|defined
name|SLJIT_CONFIG_TILEGX
operator|&&
name|SLJIT_CONFIG_TILEGX
operator|)
end_elif
begin_define
DECL|macro|SLJIT_32BIT_ARCHITECTURE
define|#
directive|define
name|SLJIT_32BIT_ARCHITECTURE
value|1
end_define
begin_define
DECL|macro|SLJIT_WORD_SHIFT
define|#
directive|define
name|SLJIT_WORD_SHIFT
value|2
end_define
begin_typedef
DECL|typedef|sljit_uw
typedef|typedef
name|unsigned
name|int
name|sljit_uw
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sw
typedef|typedef
name|int
name|sljit_sw
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_64BIT_ARCHITECTURE
define|#
directive|define
name|SLJIT_64BIT_ARCHITECTURE
value|1
end_define
begin_define
DECL|macro|SLJIT_WORD_SHIFT
define|#
directive|define
name|SLJIT_WORD_SHIFT
value|3
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef
begin_typedef
DECL|typedef|sljit_uw
typedef|typedef
name|unsigned
name|__int64
name|sljit_uw
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sw
typedef|typedef
name|__int64
name|sljit_sw
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|sljit_uw
typedef|typedef
name|unsigned
name|long
name|int
name|sljit_uw
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_sw
typedef|typedef
name|long
name|int
name|sljit_sw
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|sljit_p
typedef|typedef
name|sljit_uw
name|sljit_p
typedef|;
end_typedef
begin_comment
comment|/* Floating point types. */
end_comment
begin_typedef
DECL|typedef|sljit_s
typedef|typedef
name|float
name|sljit_s
typedef|;
end_typedef
begin_typedef
DECL|typedef|sljit_d
typedef|typedef
name|double
name|sljit_d
typedef|;
end_typedef
begin_comment
comment|/* Shift for pointer sized data. */
end_comment
begin_define
DECL|macro|SLJIT_POINTER_SHIFT
define|#
directive|define
name|SLJIT_POINTER_SHIFT
value|SLJIT_WORD_SHIFT
end_define
begin_comment
comment|/* Shift for double precision sized data. */
end_comment
begin_define
DECL|macro|SLJIT_DOUBLE_SHIFT
define|#
directive|define
name|SLJIT_DOUBLE_SHIFT
value|3
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_W
end_ifndef
begin_comment
comment|/* Defining long constants. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_64BIT_ARCHITECTURE
operator|&&
name|SLJIT_64BIT_ARCHITECTURE
operator|)
end_if
begin_define
DECL|macro|SLJIT_W
define|#
directive|define
name|SLJIT_W
parameter_list|(
name|w
parameter_list|)
value|(w##ll)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_W
define|#
directive|define
name|SLJIT_W
parameter_list|(
name|w
parameter_list|)
value|(w)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_W */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_CALL
end_ifndef
begin_comment
comment|/* ABI (Application Binary Interface) types. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if
begin_define
DECL|macro|SLJIT_CALL
define|#
directive|define
name|SLJIT_CALL
value|__attribute__ ((fastcall))
end_define
begin_define
DECL|macro|SLJIT_X86_32_FASTCALL
define|#
directive|define
name|SLJIT_X86_32_FASTCALL
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CALL
define|#
directive|define
name|SLJIT_CALL
value|__fastcall
end_define
begin_define
DECL|macro|SLJIT_X86_32_FASTCALL
define|#
directive|define
name|SLJIT_X86_32_FASTCALL
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_elif
begin_define
DECL|macro|SLJIT_CALL
define|#
directive|define
name|SLJIT_CALL
value|__msfastcall
end_define
begin_define
DECL|macro|SLJIT_X86_32_FASTCALL
define|#
directive|define
name|SLJIT_X86_32_FASTCALL
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Unknown compiler. */
end_comment
begin_comment
comment|/* The cdecl attribute is the default. */
end_comment
begin_define
DECL|macro|SLJIT_CALL
define|#
directive|define
name|SLJIT_CALL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Non x86-32 architectures. */
end_comment
begin_define
DECL|macro|SLJIT_CALL
define|#
directive|define
name|SLJIT_CALL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SLJIT_CONFIG_X86_32 */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_CALL */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SLJIT_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SLJIT_LITTLE_ENDIAN
argument_list|)
end_if
begin_comment
comment|/* These macros are useful for the applications. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
end_if
begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef
begin_define
DECL|macro|SLJIT_LITTLE_ENDIAN
define|#
directive|define
name|SLJIT_LITTLE_ENDIAN
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_BIG_ENDIAN
define|#
directive|define
name|SLJIT_BIG_ENDIAN
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_32
operator|&&
name|SLJIT_CONFIG_MIPS_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_MIPS_64
operator|&&
name|SLJIT_CONFIG_MIPS_64
operator|)
end_elif
begin_ifdef
ifdef|#
directive|ifdef
name|__MIPSEL__
end_ifdef
begin_define
DECL|macro|SLJIT_LITTLE_ENDIAN
define|#
directive|define
name|SLJIT_LITTLE_ENDIAN
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_BIG_ENDIAN
define|#
directive|define
name|SLJIT_BIG_ENDIAN
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
operator|(
name|defined
name|SLJIT_CONFIG_SPARC_32
operator|&&
name|SLJIT_CONFIG_SPARC_32
operator|)
end_elif
begin_define
DECL|macro|SLJIT_BIG_ENDIAN
define|#
directive|define
name|SLJIT_BIG_ENDIAN
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_LITTLE_ENDIAN
define|#
directive|define
name|SLJIT_LITTLE_ENDIAN
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !defined(SLJIT_BIG_ENDIAN)&& !defined(SLJIT_LITTLE_ENDIAN) */
end_comment
begin_comment
comment|/* Sanity check. */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_BIG_ENDIAN
operator|&&
name|SLJIT_BIG_ENDIAN
operator|)
operator|&&
operator|(
name|defined
name|SLJIT_LITTLE_ENDIAN
operator|&&
name|SLJIT_LITTLE_ENDIAN
operator|)
end_if
begin_error
error|#
directive|error
literal|"Exactly one endianness must be selected"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
operator|(
name|defined
name|SLJIT_BIG_ENDIAN
operator|&&
name|SLJIT_BIG_ENDIAN
operator|)
operator|&&
operator|!
operator|(
name|defined
name|SLJIT_LITTLE_ENDIAN
operator|&&
name|SLJIT_LITTLE_ENDIAN
operator|)
end_if
begin_error
error|#
directive|error
literal|"Exactly one endianness must be selected"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_INDIRECT_CALL
end_ifndef
begin_if
if|#
directive|if
operator|(
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
operator|&&
operator|(
name|defined
name|SLJIT_BIG_ENDIAN
operator|&&
name|SLJIT_BIG_ENDIAN
operator|)
operator|)
expr|\
operator|||
operator|(
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
operator|&&
name|defined
name|_AIX
operator|)
end_if
begin_comment
comment|/* It seems certain ppc compilers use an indirect addressing for functions    which makes things complicated. */
end_comment
begin_define
DECL|macro|SLJIT_INDIRECT_CALL
define|#
directive|define
name|SLJIT_INDIRECT_CALL
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SLJIT_INDIRECT_CALL */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_RETURN_ADDRESS_OFFSET
end_ifndef
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_SPARC_32
operator|&&
name|SLJIT_CONFIG_SPARC_32
operator|)
end_if
begin_define
DECL|macro|SLJIT_RETURN_ADDRESS_OFFSET
define|#
directive|define
name|SLJIT_RETURN_ADDRESS_OFFSET
value|8
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SLJIT_RETURN_ADDRESS_OFFSET
define|#
directive|define
name|SLJIT_RETURN_ADDRESS_OFFSET
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SLJIT_RETURN_ADDRESS_OFFSET */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_SSE2
end_ifndef
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
end_if
begin_comment
comment|/* Turn on SSE2 support on x86. */
end_comment
begin_define
DECL|macro|SLJIT_SSE2
define|#
directive|define
name|SLJIT_SSE2
value|1
end_define
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
end_if
begin_comment
comment|/* Auto detect SSE2 support using CPUID.    On 64 bit x86 cpus, sse2 must be present. */
end_comment
begin_define
DECL|macro|SLJIT_DETECT_SSE2
define|#
directive|define
name|SLJIT_DETECT_SSE2
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* (defined SLJIT_CONFIG_X86_32&& SLJIT_CONFIG_X86_32) || (defined SLJIT_CONFIG_X86_64&& SLJIT_CONFIG_X86_64) */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_SSE2 */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_UNALIGNED
end_ifndef
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_CONFIG_X86_32
operator|&&
name|SLJIT_CONFIG_X86_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_X86_64
operator|&&
name|SLJIT_CONFIG_X86_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_V7
operator|&&
name|SLJIT_CONFIG_ARM_V7
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_THUMB2
operator|&&
name|SLJIT_CONFIG_ARM_THUMB2
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_ARM_64
operator|&&
name|SLJIT_CONFIG_ARM_64
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_32
operator|&&
name|SLJIT_CONFIG_PPC_32
operator|)
expr|\
operator|||
operator|(
name|defined
name|SLJIT_CONFIG_PPC_64
operator|&&
name|SLJIT_CONFIG_PPC_64
operator|)
end_if
begin_define
DECL|macro|SLJIT_UNALIGNED
define|#
directive|define
name|SLJIT_UNALIGNED
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_UNALIGNED */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_EXECUTABLE_ALLOCATOR
operator|&&
name|SLJIT_EXECUTABLE_ALLOCATOR
operator|)
end_if
begin_function_decl
name|SLJIT_API_FUNC_ATTRIBUTE
name|void
modifier|*
name|sljit_malloc_exec
parameter_list|(
name|sljit_uw
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|SLJIT_API_FUNC_ATTRIBUTE
name|void
name|sljit_free_exec
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|SLJIT_API_FUNC_ATTRIBUTE
name|void
name|sljit_free_unused_memory_exec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|SLJIT_MALLOC_EXEC
define|#
directive|define
name|SLJIT_MALLOC_EXEC
parameter_list|(
name|size
parameter_list|)
value|sljit_malloc_exec(size)
end_define
begin_define
DECL|macro|SLJIT_FREE_EXEC
define|#
directive|define
name|SLJIT_FREE_EXEC
parameter_list|(
name|ptr
parameter_list|)
value|sljit_free_exec(ptr)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_VERBOSE
operator|&&
name|SLJIT_VERBOSE
operator|)
end_if
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
name|SLJIT_DEBUG
operator|&&
name|SLJIT_DEBUG
operator|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SLJIT_ASSERT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SLJIT_ASSERT_STOP
argument_list|)
end_if
begin_comment
comment|/* SLJIT_HALT_PROCESS must halt the process. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_HALT_PROCESS
end_ifndef
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_define
DECL|macro|SLJIT_HALT_PROCESS
define|#
directive|define
name|SLJIT_HALT_PROCESS
parameter_list|()
define|\
value|abort();
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_HALT_PROCESS */
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_ASSERT || !SLJIT_ASSERT_STOP */
end_comment
begin_comment
comment|/* Feel free to redefine these two macros. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_ASSERT
end_ifndef
begin_define
DECL|macro|SLJIT_ASSERT
define|#
directive|define
name|SLJIT_ASSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|do { \ 		if (SLJIT_UNLIKELY(!(x))) { \ 			printf("Assertion failed at " __FILE__ ":%d\n", __LINE__); \ 			SLJIT_HALT_PROCESS(); \ 		} \ 	} while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_ASSERT */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_ASSERT_STOP
end_ifndef
begin_define
DECL|macro|SLJIT_ASSERT_STOP
define|#
directive|define
name|SLJIT_ASSERT_STOP
parameter_list|()
define|\
value|do { \ 		printf("Should never been reached " __FILE__ ":%d\n", __LINE__); \ 		SLJIT_HALT_PROCESS(); \ 	} while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_ASSERT_STOP */
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* (defined SLJIT_DEBUG&& SLJIT_DEBUG) */
end_comment
begin_comment
comment|/* Forcing empty, but valid statements. */
end_comment
begin_undef
DECL|macro|SLJIT_ASSERT
undef|#
directive|undef
name|SLJIT_ASSERT
end_undef
begin_undef
DECL|macro|SLJIT_ASSERT_STOP
undef|#
directive|undef
name|SLJIT_ASSERT_STOP
end_undef
begin_define
DECL|macro|SLJIT_ASSERT
define|#
directive|define
name|SLJIT_ASSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|do { } while (0)
end_define
begin_define
DECL|macro|SLJIT_ASSERT_STOP
define|#
directive|define
name|SLJIT_ASSERT_STOP
parameter_list|()
define|\
value|do { } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* (defined SLJIT_DEBUG&& SLJIT_DEBUG) */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_COMPILE_ASSERT
end_ifndef
begin_comment
comment|/* Should be improved eventually. */
end_comment
begin_define
DECL|macro|SLJIT_COMPILE_ASSERT
define|#
directive|define
name|SLJIT_COMPILE_ASSERT
parameter_list|(
name|x
parameter_list|,
name|description
parameter_list|)
define|\
value|SLJIT_ASSERT(x)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !SLJIT_COMPILE_ASSERT */
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
