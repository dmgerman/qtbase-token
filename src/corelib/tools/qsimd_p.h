begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIMD_P_H
end_ifndef
begin_define
DECL|macro|QSIMD_P_H
define|#
directive|define
name|QSIMD_P_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
comment|/*  * qt_module_config.prf defines the QT_COMPILER_SUPPORTS_XXX macros.  * They mean the compiler supports the necessary flags and the headers  * for the x86 and ARM intrinsics:  *  - GCC: the -mXXX or march=YYY flag is necessary before #include  *  - Intel CC: #include can happen unconditionally  *  - MSVC: #include can happen unconditionally  *  - RVCT: ???  *  * We will try to include all headers possible under this configuration.  *  * MSVC does not define __SSE2__& family, so we will define them.  *  * Supported XXX are:  *   Flag  | Arch |  GCC  | Intel CC |  MSVC  |  *  NEON   | ARM  | I& C | None     |   ?    |  *  IWMMXT | ARM  | I& C | None     | I& C  |  *  SSE2   | x86  | I& C | I& C    | I& C  |  *  SSE3   | x86  | I& C | I& C    | I only |  *  SSSE3  | x86  | I& C | I& C    | I only |  *  SSE4_1 | x86  | I& C | I& C    | I only |  *  SSE4_2 | x86  | I& C | I& C    | I only |  *  AVX    | x86  | I& C | I& C    | I& C  |  *  AVX2   | x86  | I& C | I& C    | I only |  * I = intrinsics; C = code generation  */
ifdef|#
directive|ifdef
name|__MINGW64_VERSION_MAJOR
include|#
directive|include
file|<intrin.h>
endif|#
directive|endif
comment|// SSE intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__SSE2__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE2
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
if|#
directive|if
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
comment|/// this is an evil hack - the posix_memalign declaration in LSB
comment|/// is wrong - see http://bugs.linuxbase.org/show_bug.cgi?id=2431
DECL|macro|posix_memalign
define|#
directive|define
name|posix_memalign
value|_lsb_hack_posix_memalign
include|#
directive|include
file|<emmintrin.h>
DECL|macro|posix_memalign
undef|#
directive|undef
name|posix_memalign
else|#
directive|else
include|#
directive|include
file|<emmintrin.h>
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|_M_IX86_FP
operator|>=
literal|2
operator|)
DECL|macro|__SSE__
define|#
directive|define
name|__SSE__
value|1
DECL|macro|__SSE2__
define|#
directive|define
name|__SSE2__
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|// SSE3 intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__SSE3__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE3
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
include|#
directive|include
file|<pmmintrin.h>
endif|#
directive|endif
comment|// SSSE3 intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__SSSE3__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSSE3
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
include|#
directive|include
file|<tmmintrin.h>
endif|#
directive|endif
comment|// SSE4.1 intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_1__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE4_1
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
include|#
directive|include
file|<smmintrin.h>
endif|#
directive|endif
comment|// SSE4.2 intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_2__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE4_2
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
include|#
directive|include
file|<nmmintrin.h>
endif|#
directive|endif
comment|// AVX intrinsics
if|#
directive|if
name|defined
argument_list|(
name|__AVX__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_AVX
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|)
comment|// immintrin.h is the ultimate header, we don't need anything else after this
include|#
directive|include
file|<immintrin.h>
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_AVX
argument_list|)
comment|// MS Visual Studio 2010 has no macro pre-defined to identify the use of /arch:AVX
comment|// See: http://connect.microsoft.com/VisualStudio/feedback/details/605858/arch-avx-should-define-a-predefined-macro-in-x64-and-set-a-unique-value-for-m-ix86-fp-in-win32
comment|// When such a macro exists, add it above, replacing _M_AVX as appropriate
DECL|macro|__SSE3__
define|#
directive|define
name|__SSE3__
value|1
DECL|macro|__SSSE3__
define|#
directive|define
name|__SSSE3__
value|1
comment|// no Intel CPU supports SSE4a, so don't define it
DECL|macro|__SSE4_1__
define|#
directive|define
name|__SSE4_1__
value|1
DECL|macro|__SSE4_2__
define|#
directive|define
name|__SSE4_2__
value|1
DECL|macro|__AVX__
define|#
directive|define
name|__AVX__
value|1
ifdef|#
directive|ifdef
name|_M_AVX2
comment|// replace the macro above with the proper MS macro when it exists
comment|// All processors with AVX2 will support BMI1 and FMA
DECL|macro|__AVX2__
define|#
directive|define
name|__AVX2__
value|1
DECL|macro|__BMI__
define|#
directive|define
name|__BMI__
value|1
DECL|macro|__FMA__
define|#
directive|define
name|__FMA__
value|1
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|// other x86 intrinsics
if|#
directive|if
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_AVX
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
DECL|macro|QT_COMPILER_SUPPORTS_X86INTRIN
define|#
directive|define
name|QT_COMPILER_SUPPORTS_X86INTRIN
include|#
directive|include
file|<x86intrin.h>
endif|#
directive|endif
comment|// NEON intrinsics
if|#
directive|if
name|defined
name|__ARM_NEON__
include|#
directive|include
file|<arm_neon.h>
endif|#
directive|endif
comment|// IWMMXT intrinsics
if|#
directive|if
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_IWMMXT
argument_list|)
include|#
directive|include
file|<mmintrin.h>
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
include|#
directive|include
file|"qplatformdefs.h"
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_IWMMXT
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IWMMXT__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
include|#
directive|include
file|<xmmintrin.h>
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE_STD
argument_list|)
operator|&&
name|defined
argument_list|(
name|_X86_
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4391
name|)
include|#
directive|include
file|<xmmintrin.h>
endif|#
directive|endif
endif|#
directive|endif
name|QT_BEGIN_NAMESPACE
type|enum
DECL|enum|CPUFeatures
name|CPUFeatures
block|{
DECL|enumerator|None
name|None
operator|=
literal|0
operator|,
DECL|enumerator|IWMMXT
name|IWMMXT
operator|=
literal|0x1
operator|,
DECL|enumerator|NEON
name|NEON
operator|=
literal|0x2
operator|,
DECL|enumerator|SSE2
name|SSE2
operator|=
literal|0x4
operator|,
DECL|enumerator|SSE3
name|SSE3
operator|=
literal|0x8
operator|,
DECL|enumerator|SSSE3
name|SSSE3
operator|=
literal|0x10
operator|,
DECL|enumerator|SSE4_1
name|SSE4_1
operator|=
literal|0x20
operator|,
DECL|enumerator|SSE4_2
name|SSE4_2
operator|=
literal|0x40
operator|,
DECL|enumerator|AVX
name|AVX
operator|=
literal|0x80
operator|,
DECL|enumerator|AVX2
name|AVX2
operator|=
literal|0x100
operator|,
DECL|enumerator|HLE
name|HLE
operator|=
literal|0x200
operator|,
DECL|enumerator|RTM
name|RTM
operator|=
literal|0x400
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|uint
name|qDetectCPUFeatures
parameter_list|()
function_decl|;
end_function_decl
begin_define
DECL|macro|ALIGNMENT_PROLOGUE_16BYTES
define|#
directive|define
name|ALIGNMENT_PROLOGUE_16BYTES
parameter_list|(
name|ptr
parameter_list|,
name|i
parameter_list|,
name|length
parameter_list|)
define|\
value|for (; i< static_cast<int>(qMin(static_cast<quintptr>(length), ((4 - ((reinterpret_cast<quintptr>(ptr)>> 2)& 0x3))& 0x3))); ++i)
end_define
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIMD_P_H
end_comment
end_unit
