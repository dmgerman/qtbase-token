begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLOBAL_H
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QPROCESSORDETECTION_H
end_ifndef
begin_define
DECL|macro|QPROCESSORDETECTION_H
define|#
directive|define
name|QPROCESSORDETECTION_H
end_define
begin_comment
comment|/*     This file uses preprocessor #defines to set various Q_PROCESSOR_* #defines     based on the following patterns:      Q_PROCESSOR_{FAMILY}     Q_PROCESSOR_{FAMILY}_{VARIANT}     Q_PROCESSOR_{FAMILY}_{REVISION}      The first is always defined. Defines for the various revisions/variants are     optional and usually dependent on how the compiler was invoked. Variants     that are a superset of another should have a define for the superset.      In addition to the procesor family, variants, and revisions, we also set     Q_BYTE_ORDER appropriately for the target processor. For bi-endian     processors, we try to auto-detect the byte order using the __BIG_ENDIAN__,     __LITTLE_ENDIAN__, or __BYTE_ORDER__ preprocessor macros.      Note: when adding support for new processors, be sure to update     config.tests/arch/arch.cpp to ensure that configure can detect the target     and host architectures. */
end_comment
begin_comment
comment|/* Machine byte-order, reuse preprocessor provided macros when available */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ORDER_BIG_ENDIAN__
argument_list|)
end_if
begin_define
DECL|macro|Q_BIG_ENDIAN
define|#
directive|define
name|Q_BIG_ENDIAN
value|__ORDER_BIG_ENDIAN__
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_BIG_ENDIAN
define|#
directive|define
name|Q_BIG_ENDIAN
value|4321
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ORDER_LITTLE_ENDIAN__
argument_list|)
end_if
begin_define
DECL|macro|Q_LITTLE_ENDIAN
define|#
directive|define
name|Q_LITTLE_ENDIAN
value|__ORDER_LITTLE_ENDIAN__
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_LITTLE_ENDIAN
define|#
directive|define
name|Q_LITTLE_ENDIAN
value|1234
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     Alpha family, no revisions or variants      Alpha is bi-endian, use endianness auto-detection implemented below. */
end_comment
begin_comment
comment|// #elif defined(__alpha__) || defined(_M_ALPHA)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_ALPHA
end_comment
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_comment
comment|/*     ARM family, known revisions: V5, V6, V7, V8      ARM is bi-endian, detect using __ARMEL__ or __ARMEB__, falling back to     auto-detection implemented below. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm64__
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_ARM
define|#
directive|define
name|Q_PROCESSOR_ARM
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm64__
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_ARM_64
define|#
directive|define
name|Q_PROCESSOR_ARM_64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_PROCESSOR_ARM_32
define|#
directive|define
name|Q_PROCESSOR_ARM_32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM64_ARCH_8__
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_ARM_V8
define|#
directive|define
name|Q_PROCESSOR_ARM_V8
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V7
define|#
directive|define
name|Q_PROCESSOR_ARM_V7
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V6
define|#
directive|define
name|Q_PROCESSOR_ARM_V6
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7S__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_ARM_ARCH_7
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|&&
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|7
operator|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|_M_ARM
argument_list|)
operator|&&
name|_M_ARM
operator|-
literal|0
operator|>=
literal|7
operator|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_ARM_V7
define|#
directive|define
name|Q_PROCESSOR_ARM_V7
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V6
define|#
directive|define
name|Q_PROCESSOR_ARM_V6
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6M__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|&&
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|6
operator|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|_M_ARM
argument_list|)
operator|&&
name|_M_ARM
operator|-
literal|0
operator|>=
literal|6
operator|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_ARM_V6
define|#
directive|define
name|Q_PROCESSOR_ARM_V6
end_define
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__TARGET_ARCH_ARM
argument_list|)
operator|&&
name|__TARGET_ARCH_ARM
operator|-
literal|0
operator|>=
literal|5
operator|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|_M_ARM
argument_list|)
operator|&&
name|_M_ARM
operator|-
literal|0
operator|>=
literal|5
operator|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_ARM_V5
define|#
directive|define
name|Q_PROCESSOR_ARM_V5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARMEL__
argument_list|)
end_if
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_LITTLE_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
end_elif
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_BIG_ENDIAN
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     AVR32 family, no revisions or variants      AVR32 is big-endian. */
end_comment
begin_comment
comment|// #elif defined(__avr32__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_AVR32
end_comment
begin_comment
comment|// #  define Q_BYTE_ORDER Q_BIG_ENDIAN
end_comment
begin_comment
comment|/*     Blackfin family, no revisions or variants      Blackfin is little-endian. */
end_comment
begin_comment
comment|// #elif defined(__bfin__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_BLACKFIN
end_comment
begin_comment
comment|// #  define Q_BYTE_ORDER Q_LITTLE_ENDIAN
end_comment
begin_comment
comment|/*     X86 family, known variants: 32- and 64-bit      X86 is little-endian. */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86_32
define|#
directive|define
name|Q_PROCESSOR_X86_32
end_define
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_LITTLE_ENDIAN
end_define
begin_comment
comment|/*  * We define Q_PROCESSOR_X86 == 6 for anything above a equivalent or better  * than a Pentium Pro (the processor whose architecture was called P6) or an  * Athlon.  *  * All processors since the Pentium III and the Athlon 4 have SSE support, so  * we use that to detect. That leaves the original Athlon, Pentium Pro and  * Pentium II.  */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|(_M_IX86/100)
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i686__
argument_list|)
operator|||
name|defined
argument_list|(
name|__athlon__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SSE__
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|6
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i586__
argument_list|)
operator|||
name|defined
argument_list|(
name|__k6__
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|5
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i486__
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|4
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|3
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
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_X86
define|#
directive|define
name|Q_PROCESSOR_X86
value|6
end_define
begin_define
DECL|macro|Q_PROCESSOR_X86_64
define|#
directive|define
name|Q_PROCESSOR_X86_64
end_define
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_LITTLE_ENDIAN
end_define
begin_define
DECL|macro|Q_PROCESSOR_WORDSIZE
define|#
directive|define
name|Q_PROCESSOR_WORDSIZE
value|8
end_define
begin_comment
comment|/*     Itanium (IA-64) family, no revisions or variants      Itanium is bi-endian, use endianness auto-detection implemented below. */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IA64
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_IA64
define|#
directive|define
name|Q_PROCESSOR_IA64
end_define
begin_define
DECL|macro|Q_PROCESSOR_WORDSIZE
define|#
directive|define
name|Q_PROCESSOR_WORDSIZE
value|8
end_define
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_comment
comment|/*     MIPS family, known revisions: I, II, III, IV, 32, 64      MIPS is bi-endian, use endianness auto-detection implemented below. */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_MRX000
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_MIPS
define|#
directive|define
name|Q_PROCESSOR_MIPS
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS1
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|1
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_I
define|#
directive|define
name|Q_PROCESSOR_MIPS_I
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS2
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|2
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_II
define|#
directive|define
name|Q_PROCESSOR_MIPS_II
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips32
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_32
define|#
directive|define
name|Q_PROCESSOR_MIPS_32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS3
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|3
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_III
define|#
directive|define
name|Q_PROCESSOR_MIPS_III
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS4
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|4
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_IV
define|#
directive|define
name|Q_PROCESSOR_MIPS_IV
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS5
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|&&
name|__mips
operator|-
literal|0
operator|>=
literal|5
operator|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_V
define|#
directive|define
name|Q_PROCESSOR_MIPS_V
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MIPS_ARCH_MIPS64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips64
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_MIPS_64
define|#
directive|define
name|Q_PROCESSOR_MIPS_64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
end_if
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_LITTLE_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MIPSEB__
argument_list|)
end_elif
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_BIG_ENDIAN
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     Power family, known variants: 32- and 64-bit      There are many more known variants/revisions that we do not handle/detect.     See http://en.wikipedia.org/wiki/Power_Architecture     and http://en.wikipedia.org/wiki/File:PowerISA-evolution.svg      Power is bi-endian, use endianness auto-detection implemented below. */
end_comment
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
name|__ppc
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_ARCH_COM
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PWR
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_M_MPPC
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_PPC
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_POWER
define|#
directive|define
name|Q_PROCESSOR_POWER
end_define
begin_if
if|#
directive|if
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
name|__64BIT__
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_POWER_64
define|#
directive|define
name|Q_PROCESSOR_POWER_64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_PROCESSOR_POWER_32
define|#
directive|define
name|Q_PROCESSOR_POWER_32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_comment
comment|/*     S390 family, known variant: S390X (64-bit)      S390 is big-endian. */
end_comment
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__s390__
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_S390
define|#
directive|define
name|Q_PROCESSOR_S390
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if
begin_define
DECL|macro|Q_PROCESSOR_S390_X
define|#
directive|define
name|Q_PROCESSOR_S390_X
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_BIG_ENDIAN
end_define
begin_comment
comment|/*     SuperH family, optional revision: SH-4A      SuperH is bi-endian, use endianness auto-detection implemented below. */
end_comment
begin_comment
comment|// #elif defined(__sh__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_SH
end_comment
begin_comment
comment|// #  if defined(__sh4a__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_SH_4A
end_comment
begin_comment
comment|// #  endif
end_comment
begin_comment
comment|// Q_BYTE_ORDER not defined, use endianness auto-detection
end_comment
begin_comment
comment|/*     SPARC family, optional revision: V9      SPARC is big-endian only prior to V9, while V9 is bi-endian with big-endian     as the default byte order. Assume all SPARC systems are big-endian. */
end_comment
begin_comment
comment|// #elif defined(__sparc__)
end_comment
begin_comment
comment|// #  define Q_PROCESSOR_SPARC
end_comment
begin_comment
comment|// #  if defined(__sparc_v9__)
end_comment
begin_comment
comment|// #    define Q_PROCESSOR_SPARC_V9
end_comment
begin_comment
comment|// #  endif
end_comment
begin_comment
comment|// #  define Q_BYTE_ORDER Q_BIG_ENDIAN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*   NOTE:   GCC 4.6 added __BYTE_ORDER__, __ORDER_BIG_ENDIAN__, __ORDER_LITTLE_ENDIAN__   and __ORDER_PDP_ENDIAN__ in SVN r165881. If you are using GCC 4.6 or newer,   this code will properly detect your target byte order; if you are not, and   the __LITTLE_ENDIAN__ or __BIG_ENDIAN__ macros are not defined, then this   code will fail to detect the target byte order. */
end_comment
begin_comment
comment|// Some processors support either endian format, try to detect which we are using.
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_BYTE_ORDER
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BYTE_ORDER__
argument_list|)
operator|&&
operator|(
name|__BYTE_ORDER__
operator|==
name|Q_BIG_ENDIAN
operator|||
name|__BYTE_ORDER__
operator|==
name|Q_LITTLE_ENDIAN
operator|)
end_if
begin_comment
comment|// Reuse __BYTE_ORDER__ as-is, since our Q_*_ENDIAN #defines match the preprocessor defaults
end_comment
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|__BYTE_ORDER__
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BIG_ENDIAN__
argument_list|)
operator|||
name|defined
argument_list|(
name|_big_endian__
argument_list|)
operator|||
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
operator|||
name|defined
argument_list|(
name|_little_endian__
argument_list|)
operator|||
name|defined
argument_list|(
name|_LITTLE_ENDIAN
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
operator|||
name|defined
argument_list|(
name|WINAPI_FAMILY
argument_list|)
end_elif
begin_comment
comment|// Windows CE is always little-endian according to MSDN.
end_comment
begin_define
DECL|macro|Q_BYTE_ORDER
define|#
directive|define
name|Q_BYTE_ORDER
value|Q_LITTLE_ENDIAN
end_define
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"Unable to determine byte order!"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*    Define Q_PROCESSOR_WORDSIZE to be the size of the machine's word (usually,    the size of the register). On some architectures where a pointer could be    smaller than the register, the macro is defined above.     Falls back to QT_POINTER_SIZE if not set explicitly for the platform. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_PROCESSOR_WORDSIZE
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|__SIZEOF_POINTER__
end_ifdef
begin_comment
comment|/* GCC& friends define this */
end_comment
begin_define
DECL|macro|Q_PROCESSOR_WORDSIZE
define|#
directive|define
name|Q_PROCESSOR_WORDSIZE
value|__SIZEOF_POINTER__
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|||
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_elif
begin_define
DECL|macro|Q_PROCESSOR_WORDSIZE
define|#
directive|define
name|Q_PROCESSOR_WORDSIZE
value|8
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_PROCESSOR_WORDSIZE
define|#
directive|define
name|Q_PROCESSOR_WORDSIZE
value|QT_POINTER_SIZE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROCESSORDETECTION_H
end_comment
end_unit
