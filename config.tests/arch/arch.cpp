begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QGLOBAL_H
define|#
directive|define
name|QGLOBAL_H
end_define
begin_include
include|#
directive|include
file|"../../src/corelib/global/archdetect.cpp"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
specifier|extern
specifier|const
name|char
name|msg
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|msg
specifier|const
name|char
name|msg
index|[]
init|=
literal|"==Qt=magic=Qt== Architecture:"
name|ARCH_PROCESSOR
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|char
name|msg2
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|msg2
specifier|const
name|char
name|msg2
index|[]
init|=
literal|"==Qt=magic=Qt== Sub-architecture:"
comment|// This is the list of features found in GCC or MSVC
comment|// We don't use all of them, but this is ready for future expansion
comment|// -- x86 --
ifdef|#
directive|ifdef
name|__3dNOW__
comment|// 3dNow!, introduced with the AMD K6-2, discontinued after 2010
literal|" 3dnow"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__3dNOW_A__
comment|// Athlon
literal|" 3dnow-a"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__ABM__
comment|// Advanced Bit Manipulation, AMD Barcelona (family 10h)
literal|" abm"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__ADX__
comment|// Multi-Precision Add-Carry Instruction Extensions, Intel Core 5th generation ("Broadwell")
literal|" adx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AES__
comment|// AES New Instructions, Intel Core-i7 second generation ("Sandy Bridge")
literal|" aes"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX__
comment|// Advanced Vector Extensions, Intel Core-i7 second generation ("Sandy Bridge")
literal|" avx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX2__
comment|// AVX 2, Intel Core 4th Generation ("Haswell")
literal|" avx2"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512F__
comment|// AVX512 Foundation, Intel Xeon Phi codename "Knights Landing" and Intel Xeon codename "Skylake"
literal|" avx512f"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512CD__
comment|// AVX512 Conflict Detection, Intel Xeon Phi codename "Knights Landing" and Intel Xeon codename "Skylake"
literal|" avx512cd"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512DQ__
comment|// AVX512 Double& Quadword, Intel Xeon processor codename "Skylake"
literal|" avx512dq"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512BW__
comment|// AVX512 Byte& Word, Intel Xeon processor codename "Skylake"
literal|" avx512bw"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512ER__
comment|// AVX512 Exponentiation& Reciprocal, Intel Xeon Phi codename "Knights Landing"
literal|" avx512ef"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512PF__
comment|// AVX512 Prefetch, Intel Xeon Phi codename "Knights Landing"
literal|" avx512pf"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512VL__
comment|// AVX512 Vector Length, Intel Xeon processor codename "Skylake"
literal|" avx512vl"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512IFMA__
comment|// AVX512 Integer Fused Multiply-Add, Intel processor codename "Cannonlake"
literal|" avx512ifma"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__AVX512VBMI__
comment|// AVX512 Vector Byte Manipulation Instructions, Intel processor codename "Cannonlake"
literal|" avx512vbmi"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__BMI__
comment|// Bit Manipulation Instructions 1, Intel Core 4th Generation ("Haswell"), AMD "Bulldozer 2"
literal|" bmi"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__BMI2__
comment|// Bit Manipulation Instructions 2, Intel Core 4th Generation ("Haswell")
literal|" bmi2"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16
comment|// cmpxchg16b instruction, Intel Pentium 4 64-bit ("Nocona"), AMD Barcelona (family 10h)
comment|// Notably, this instruction is missing on earlier AMD Athlon 64
literal|" cx16"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__F16C__
comment|// 16-bit floating point conversion, Intel Core 3rd Generation ("Ivy Bridge")
literal|" f16c"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FMA__
comment|// Fused Multiply-Add with 3 arguments, Intel Core 4th Generation ("Haswell"), AMD "Bulldozer 2"
comment|// a.k.a. "FMA3"
literal|" fma"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FMA4__
comment|// Fused Multiply-Add with 4 arguments, AMD "Bulldozer"
literal|" fma4"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FSGSBASE__
comment|// rdfsgsbase, wrfsgsbase, Intel Core 3rd Generation ("Ivy Bridge")
literal|" fsgsbase"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__LWP__
comment|// LWP instructions, AMD "Bulldozer"
literal|" lwp"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__LZCNT__
comment|// Leading-Zero bit count, Intel Core 4th Generation ("Haswell")
literal|" lzcnt"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__MMX__
comment|// Multimedia Extensions, Pentium MMX, AMD K6-2
literal|" mmx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__MOVBE__
comment|// Move Big Endian, Intel Atom& "Haswell"
literal|" movbe"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__MPX__
comment|// Memory Protection Extensions, Intel Core processor codename "Skylake"
literal|" mpx"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__NO_SAHF__
comment|// missing SAHF instruction in 64-bit, up to Intel Pentium 4 64-bit ("Nocona"), AMD Athlon FX
comment|// Note: the macro is not defined, so this will never show up
literal|" no-sahf"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__PCLMUL__
comment|// (Packed) Carry-less multiplication, Intel Core-i7 second generation ("Sandy Bridge")
literal|" pclmul"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__POPCNT__
comment|// Population Count (count of set bits), Intel Core-i7 second generation ("Sandy Bridge")
literal|" popcnt"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__PREFETCHWT1__
comment|// Prefetch data for writing with T1 hint, Intel processor TBA
literal|" prefetchwt1"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__PRFCHW__
comment|// Prefetch data for writing, Intel Core 5th Generation ("Broadwell")
literal|" prfchw"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__RDRND__
comment|// Random number generator, Intel Core 3rd Generation ("Ivy Bridge")
literal|" rdrnd"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__RDSEED__
comment|// Random number generator, Intel Core 5th Generation ("Broadwell")
literal|" rdseed"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__RTM__
comment|// Restricted Transactional Memory, Intel Core 4th Generation ("Haswell")
literal|" rtm"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SHA__
comment|// SHA-1 and SHA-256 instructions, Intel processor TBA
literal|" sha"
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__SSE__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_M_IX86_FP
argument_list|)
operator|&&
name|_M_IX86_FP
operator|>=
literal|1
operator|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
comment|// Streaming SIMD Extensions, Intel Pentium III, AMD Athlon
literal|" sse"
endif|#
directive|endif
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
name|_M_IX86_FP
argument_list|)
operator|&&
name|_M_IX86_FP
operator|>=
literal|2
operator|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
comment|// SSE2, Intel Pentium-M, Intel Pentium 4, AMD Opteron and Athlon 64
literal|" sse2"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SSE3__
comment|// SSE3, Intel Pentium 4 "Prescott", AMD Athlon 64 rev E
literal|" sse3"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SSSE3__
comment|// Supplemental SSE3, Intel Core 2 ("Merom"), AMD "Bulldozer"
literal|" ssse3"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SSE4A__
comment|// SSE4a, AMD Barcelona
literal|" sse4a"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SSE4_1__
comment|// SSE 4.1, Intel Core2 45nm shrink ("Penryn"), AMD "Bulldozer"
literal|" sse4.1"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SSE4_2__
comment|// SSE 4.2, Intel Core-i7 ("Nehalem"), AMD "Bulldozer"
literal|" sse4.2"
comment|// Since no processor supports SSE4.2 without 4.1 and since no Intel processor
comment|// supports SSE4a, define "sse4" to indicate SSE4"
literal|" sse4"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__TBM__
comment|// TBM, AMD "Bulldozer"
literal|" tbm"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__XOP__
comment|// XOP, AMD "Bulldozer"
literal|" xop"
endif|#
directive|endif
comment|// -- ARM --
if|#
directive|if
name|defined
argument_list|(
name|__ARM_NEON
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_NEON__
argument_list|)
literal|" neon"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__IWMMXT__
literal|" iwmmxt"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__ARM_FEATURE_CRC32
literal|" crc32"
endif|#
directive|endif
comment|// -- SPARC --
ifdef|#
directive|ifdef
name|__VIS__
literal|" vis"
if|#
directive|if
name|__VIS__
operator|>=
literal|0x200
literal|" vis2"
endif|#
directive|endif
if|#
directive|if
name|__VIS__
operator|>=
literal|0x300
literal|" vis3"
endif|#
directive|endif
endif|#
directive|endif
comment|// -- MIPS --
if|#
directive|if
name|__mips_dsp
literal|" dsp"
endif|#
directive|endif
if|#
directive|if
name|__mips_dspr2
literal|" dspr2"
endif|#
directive|endif
comment|// -- POWER, PowerPC --
ifdef|#
directive|ifdef
name|__ALTIVEC__
literal|" altivec"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__SPE__
literal|" spe"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__VSX__
literal|" vsx"
endif|#
directive|endif
literal|""
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|puts
argument_list|(
name|msg
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|msg2
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
