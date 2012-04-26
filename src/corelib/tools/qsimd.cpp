begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsimd_p.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<cmnintrin.h>
end_include
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
name|Q_CC_GNU
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<intrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// the kernel header definitions for HWCAP_*
end_comment
begin_comment
comment|// (the ones we need/may need anyway)
end_comment
begin_comment
comment|// copied from<asm/hwcap.h> (ARM)
end_comment
begin_define
DECL|macro|HWCAP_IWMMXT
define|#
directive|define
name|HWCAP_IWMMXT
value|512
end_define
begin_define
DECL|macro|HWCAP_CRUNCH
define|#
directive|define
name|HWCAP_CRUNCH
value|1024
end_define
begin_define
DECL|macro|HWCAP_THUMBEE
define|#
directive|define
name|HWCAP_THUMBEE
value|2048
end_define
begin_define
DECL|macro|HWCAP_NEON
define|#
directive|define
name|HWCAP_NEON
value|4096
end_define
begin_define
DECL|macro|HWCAP_VFPv3
define|#
directive|define
name|HWCAP_VFPv3
value|8192
end_define
begin_define
DECL|macro|HWCAP_VFPv3D16
define|#
directive|define
name|HWCAP_VFPv3D16
value|16384
end_define
begin_comment
comment|// copied from<linux/auxvec.h>
end_comment
begin_define
DECL|macro|AT_HWCAP
define|#
directive|define
name|AT_HWCAP
value|16
end_define
begin_comment
DECL|macro|AT_HWCAP
comment|/* arch dependent hints at CPU capabilities */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
DECL|function|detectProcessorFeatures
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|ARM
argument_list|)
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_ARM_INTEL_WMMX
argument_list|)
condition|)
block|{
name|features
operator|=
name|IWMMXT
expr_stmt|;
return|return
name|features
return|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|_X86_
argument_list|)
name|features
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_XMMI64_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|SSE2
expr_stmt|;
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_SSE3_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
return|return
name|features
return|;
endif|#
directive|endif
name|features
operator|=
literal|0
expr_stmt|;
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_HAVE_IWMMXT
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_HAVE_NEON
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|int
name|auxv
init|=
name|qt_safe_open
argument_list|(
literal|"/proc/self/auxv"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|auxv
operator|!=
operator|-
literal|1
condition|)
block|{
name|unsigned
name|long
name|vector
index|[
literal|64
index|]
decl_stmt|;
name|int
name|nread
decl_stmt|;
while|while
condition|(
name|features
operator|==
literal|0
condition|)
block|{
name|nread
operator|=
name|qt_safe_read
argument_list|(
name|auxv
argument_list|,
operator|(
name|char
operator|*
operator|)
name|vector
argument_list|,
sizeof|sizeof
name|vector
argument_list|)
expr_stmt|;
if|if
condition|(
name|nread
operator|<=
literal|0
condition|)
block|{
comment|// EOF or error
break|break;
block|}
name|int
name|max
init|=
name|nread
operator|/
operator|(
sizeof|sizeof
name|vector
index|[
literal|0
index|]
operator|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|max
condition|;
name|i
operator|+=
literal|2
control|)
if|if
condition|(
name|vector
index|[
name|i
index|]
operator|==
name|AT_HWCAP
condition|)
block|{
if|if
condition|(
name|vector
index|[
name|i
operator|+
literal|1
index|]
operator|&
name|HWCAP_IWMMXT
condition|)
name|features
operator||=
name|IWMMXT
expr_stmt|;
if|if
condition|(
name|vector
index|[
name|i
operator|+
literal|1
index|]
operator|&
name|HWCAP_NEON
condition|)
name|features
operator||=
name|NEON
expr_stmt|;
break|break;
block|}
block|}
name|qt_safe_close
argument_list|(
name|auxv
argument_list|)
expr_stmt|;
return|return
name|features
return|;
block|}
comment|// fall back if /proc/self/auxv wasn't found
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_HAVE_IWMMXT
argument_list|)
comment|// runtime detection only available when running as a previlegied process
name|features
operator|=
name|IWMMXT
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_ALWAYS_HAVE_NEON
argument_list|)
name|features
operator|=
name|NEON
expr_stmt|;
endif|#
directive|endif
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_PROCESSOR_X86_32
end_ifdef
begin_define
define|#
directive|define
name|PICreg
value|"%%ebx"
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|PICreg
value|"%%rbx"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|int
name|maxBasicCpuidSupported
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// Use the __cpuid function; if the CPUID instruction isn't supported, it will return 0
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|info
index|[
literal|0
index|]
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|long
name|tmp1
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_PROCESSOR_X86_32
comment|// check if the CPUID instruction is supported
name|long
name|cpuid_supported
decl_stmt|;
asm|asm ("pushf\n"          "pop %0\n"          "mov %0, %1\n"          "xor $0x00200000, %0\n"          "push %0\n"          "popf\n"          "pushf\n"          "pop %0\n"          "xor %1, %0\n"
comment|// %eax is now 0 if CPUID is not supported
asm|: "=a" (cpuid_supported), "=r" (tmp1)          );
if|if
condition|(
operator|!
name|cpuid_supported
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
name|int
name|result
decl_stmt|;
asm|asm ("xchg " PICreg", %1\n"          "cpuid\n"          "xchg " PICreg", %1\n"         : "=&a" (result), "=&r" (tmp1)         : "0" (0)         : "ecx", "edx");
return|return
name|result
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
name|void
name|cpuidFeatures01
parameter_list|(
name|uint
modifier|&
name|ecx
parameter_list|,
name|uint
modifier|&
name|edx
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ecx
operator|=
name|info
index|[
literal|2
index|]
expr_stmt|;
name|edx
operator|=
name|info
index|[
literal|3
index|]
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|long
name|tmp1
decl_stmt|;
asm|asm ("xchg " PICreg", %2\n"          "cpuid\n"          "xchg " PICreg", %2\n"         : "=&c" (ecx), "=&d" (edx), "=&r" (tmp1)         : "a" (1));
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
name|void
name|cpuidFeatures07_00
parameter_list|(
name|uint
modifier|&
name|ebx
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuidex
argument_list|(
name|info
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ebx
operator|=
name|info
index|[
literal|1
index|]
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|unsigned
name|long
name|rbx
decl_stmt|;
comment|// in case it's 64-bit
asm|asm ("xchg " PICreg", %0\n"          "cpuid\n"          "xchg " PICreg", %0\n"         : "=&r" (rbx)         : "a" (7), "c" (0)         : "%edx");
name|ebx
operator|=
name|rbx
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_namespace
namespace|namespace
name|QtXgetbvHack
block|{
specifier|inline
name|quint64
name|_xgetbv
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
block|}
end_namespace
begin_using
using|using
namespace|namespace
name|QtXgetbvHack
namespace|;
end_using
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|void
name|xgetbv
parameter_list|(
name|int
name|in
parameter_list|,
name|uint
modifier|&
name|eax
parameter_list|,
name|uint
modifier|&
name|edx
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|quint64
name|result
init|=
name|_xgetbv
argument_list|(
name|in
argument_list|)
decl_stmt|;
name|eax
operator|=
name|result
expr_stmt|;
name|edx
operator|=
name|result
operator|>>
literal|32
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
asm|asm (".byte 0x0F, 0x01, 0xD0"
comment|// xgetbv instruction
asm|: "=a" (eax), "=d" (edx)         : "c" (in));
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
name|int
name|cpuidLevel
init|=
name|maxBasicCpuidSupported
argument_list|()
decl_stmt|;
if|if
condition|(
name|cpuidLevel
operator|<
literal|1
condition|)
return|return
literal|0
return|;
name|uint
name|cpuid01ECX
init|=
literal|0
decl_stmt|,
name|cpuid01EDX
init|=
literal|0
decl_stmt|;
name|cpuidFeatures01
argument_list|(
name|cpuid01ECX
argument_list|,
name|cpuid01EDX
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_X86_32
argument_list|)
comment|// x86 might not have SSE2 support
if|if
condition|(
name|cpuid01EDX
operator|&
operator|(
literal|1u
operator|<<
literal|26
operator|)
condition|)
name|features
operator||=
name|SSE2
expr_stmt|;
else|#
directive|else
comment|// x86-64 or x32
name|features
operator|=
name|SSE2
expr_stmt|;
endif|#
directive|endif
comment|// common part between 32- and 64-bit
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|9
operator|)
condition|)
name|features
operator||=
name|SSSE3
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|19
operator|)
condition|)
name|features
operator||=
name|SSE4_1
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|20
operator|)
condition|)
name|features
operator||=
name|SSE4_2
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|25
operator|)
condition|)
name|features
operator||=
literal|0
expr_stmt|;
comment|// AES, enable if needed
name|uint
name|xgetbvA
init|=
literal|0
decl_stmt|,
name|xgetbvD
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|27
operator|)
condition|)
block|{
comment|// XGETBV enabled
name|xgetbv
argument_list|(
literal|0
argument_list|,
name|xgetbvA
argument_list|,
name|xgetbvD
argument_list|)
expr_stmt|;
block|}
name|uint
name|cpuid0700EBX
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cpuidLevel
operator|>=
literal|7
condition|)
name|cpuidFeatures07_00
argument_list|(
name|cpuid0700EBX
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|xgetbvA
operator|&
literal|6
operator|)
operator|==
literal|6
condition|)
block|{
comment|// support for YMM and XMM registers is enabled
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|28
operator|)
condition|)
name|features
operator||=
name|AVX
expr_stmt|;
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|5
operator|)
condition|)
name|features
operator||=
name|AVX2
expr_stmt|;
block|}
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|4
operator|)
condition|)
name|features
operator||=
name|HLE
expr_stmt|;
comment|// Hardware Lock Ellision
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|11
operator|)
condition|)
name|features
operator||=
name|RTM
expr_stmt|;
comment|// Restricted Transactional Memory
return|return
name|features
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Use kdesdk/scripts/generate_string_table.pl to update the table below.  * Here's the data (don't forget the ONE leading space):  iwmmxt  neon  sse2  sse3  ssse3  sse4.1  sse4.2  avx  avx2  hle  rtm   */
end_comment
begin_comment
comment|// begin generated
end_comment
begin_decl_stmt
DECL|variable|features_string
specifier|static
specifier|const
name|char
name|features_string
index|[]
init|=
literal|" iwmmxt\0"
literal|" neon\0"
literal|" sse2\0"
literal|" sse3\0"
literal|" ssse3\0"
literal|" sse4.1\0"
literal|" sse4.2\0"
literal|" avx\0"
literal|" avx2\0"
literal|" hle\0"
literal|" rtm\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|features_indices
specifier|static
specifier|const
name|int
name|features_indices
index|[]
init|=
block|{
literal|0
block|,
literal|8
block|,
literal|14
block|,
literal|20
block|,
literal|26
block|,
literal|33
block|,
literal|41
block|,
literal|49
block|,
literal|54
block|,
literal|60
block|,
literal|65
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// end generated
end_comment
begin_decl_stmt
DECL|variable|features_count
specifier|static
specifier|const
name|int
name|features_count
init|=
operator|(
sizeof|sizeof
name|features_indices
operator|-
literal|1
operator|)
operator|/
operator|(
sizeof|sizeof
name|features_indices
index|[
literal|0
index|]
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|minFeature
specifier|static
specifier|const
name|uint
name|minFeature
init|=
name|None
if|#
directive|if
name|defined
name|__RTM__
operator||
name|RTM
endif|#
directive|endif
comment|// don't define for HLE, since the HLE prefix can be run on older CPUs
if|#
directive|if
name|defined
name|__AVX2__
operator||
name|AVX2
endif|#
directive|endif
if|#
directive|if
name|defined
name|__AVX__
operator||
name|AVX
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE4_2__
operator||
name|SSE4_2
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE4_1__
operator||
name|SSE4_1
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSSE3__
operator||
name|SSSE3
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE3__
operator||
name|SSE3
endif|#
directive|endif
if|#
directive|if
name|defined
name|__SSE2__
operator||
name|SSE2
endif|#
directive|endif
if|#
directive|if
name|defined
name|__ARM_NEON__
operator||
name|NEON
endif|#
directive|endif
if|#
directive|if
name|defined
name|__IWMMXT__
operator||
name|IWMMXT
endif|#
directive|endif
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_define
DECL|macro|ffs
define|#
directive|define
name|ffs
value|__builtin_ffs
end_define
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|ffs
name|int
name|ffs
parameter_list|(
name|int
name|i
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|unsigned
name|long
name|result
decl_stmt|;
return|return
name|_BitScanForward
argument_list|(
operator|&
name|result
argument_list|,
name|i
argument_list|)
condition|?
name|result
else|:
literal|0
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_function
DECL|function|qDetectCPUFeatures
name|uint
name|qDetectCPUFeatures
parameter_list|()
block|{
specifier|static
name|QBasicAtomicInt
name|features
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|features
operator|.
name|load
argument_list|()
operator|!=
operator|-
literal|1
condition|)
return|return
name|features
operator|.
name|load
argument_list|()
return|;
name|uint
name|f
init|=
name|detectProcessorFeatures
argument_list|()
decl_stmt|;
name|QByteArray
name|disable
init|=
name|qgetenv
argument_list|(
literal|"QT_NO_CPU_FEATURE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|disable
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|disable
operator|.
name|prepend
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|disable
operator|.
name|contains
argument_list|(
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
condition|)
name|f
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|minFeature
operator|!=
literal|0
operator|&&
operator|(
name|f
operator|&
name|minFeature
operator|)
operator|!=
name|minFeature
condition|)
block|{
name|uint
name|missing
init|=
name|minFeature
operator|&
operator|~
name|f
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Incompatible processor. This Qt build requires the following features:\n   "
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|missing
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"Aborted. Incompatible processor: missing feature 0x%x -%s."
argument_list|,
name|missing
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|ffs
argument_list|(
name|missing
argument_list|)
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|features
operator|.
name|store
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
name|f
return|;
block|}
end_function
begin_function
DECL|function|qDumpCPUFeatures
name|void
name|qDumpCPUFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
name|qDetectCPUFeatures
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"Processor features: "
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|features
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|,
name|minFeature
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|?
literal|"[required]"
else|:
literal|""
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
