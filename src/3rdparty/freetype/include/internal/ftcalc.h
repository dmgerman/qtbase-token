begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcalc.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Arithmetic computations (specification).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2006, 2008, 2009, 2012-2014 by                          */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTCALC_H__
end_ifndef
begin_define
DECL|macro|__FTCALC_H__
define|#
directive|define
name|__FTCALC_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_function
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* FT_MulDiv() and FT_MulFix() are declared in freetype.h.               */
comment|/*                                                                       */
comment|/*************************************************************************/
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_ASSEMBLER
comment|/* Provide assembler fragments for performance-critical functions. */
comment|/* These must be defined `static __inline__' with GCC.             */
if|#
directive|if
name|defined
argument_list|(
name|__CC_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARMCC__
argument_list|)
comment|/* RVCT */
DECL|macro|FT_MULFIX_ASSEMBLER
define|#
directive|define
name|FT_MULFIX_ASSEMBLER
value|FT_MulFix_arm
comment|/* documentation is in freetype.h */
specifier|static
name|__inline
name|FT_Int32
DECL|function|FT_MulFix_arm
name|FT_MulFix_arm
parameter_list|(
name|FT_Int32
name|a
parameter_list|,
name|FT_Int32
name|b
parameter_list|)
block|{
specifier|register
name|FT_Int32
name|t
decl_stmt|,
name|t2
decl_stmt|;
asm|__asm
block|{
name|smull
name|t2
decl_stmt|,
name|t
decl_stmt|,
name|b
decl_stmt|,
name|a
comment|/* (lo=t2,hi=t) = a*b */
name|mov
name|a
decl_stmt|,
name|t
decl_stmt|,
name|asr
decl|#31
comment|/* a   = (hi>> 31) */
name|add
name|a
decl_stmt|,
name|a
decl_stmt|,  #0x8000
comment|/* a  += 0x8000 */
name|adds
name|t2
decl_stmt|,
name|t2
decl_stmt|,
name|a
comment|/* t2 += a */
name|adc
name|t
decl_stmt|,
name|t
decl_stmt|,  #0
comment|/* t  += carry */
name|mov
name|a
decl_stmt|,
name|t2
decl_stmt|,
name|lsr
decl|#16
comment|/* a   = t2>> 16 */
name|orr
name|a
decl_stmt|,
name|a
decl_stmt|,
name|t
decl_stmt|,
name|lsl
decl|#16
comment|/* a  |= t<< 16 */
block|}
return|return
name|a
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CC_ARM || __ARMCC__ */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__thumb__
argument_list|)
operator|||
name|defined
argument_list|(
name|__thumb2__
argument_list|)
operator|)
operator|&&
expr|\
operator|!
operator|(
name|defined
argument_list|(
name|__CC_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARMCC__
argument_list|)
operator|)
end_if
begin_define
DECL|macro|FT_MULFIX_ASSEMBLER
define|#
directive|define
name|FT_MULFIX_ASSEMBLER
value|FT_MulFix_arm
end_define
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_function
specifier|static
name|__inline__
name|FT_Int32
DECL|function|FT_MulFix_arm
name|FT_MulFix_arm
parameter_list|(
name|FT_Int32
name|a
parameter_list|,
name|FT_Int32
name|b
parameter_list|)
block|{
specifier|register
name|FT_Int32
name|t
decl_stmt|,
name|t2
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "smull  %1, %2, %4, %3\n\t"
comment|/* (lo=%1,hi=%2) = a*b */
asm|"mov    %0, %2, asr #31\n\t"
comment|/* %0  = (hi>> 31) */
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__thumb2__
argument_list|)
asm|"add.w  %0, %0, #0x8000\n\t"
comment|/* %0 += 0x8000 */
else|#
directive|else
asm|"add    %0, %0, #0x8000\n\t"
comment|/* %0 += 0x8000 */
endif|#
directive|endif
asm|"adds   %1, %1, %0\n\t"
comment|/* %1 += %0 */
asm|"adc    %2, %2, #0\n\t"
comment|/* %2 += carry */
asm|"mov    %0, %1, lsr #16\n\t"
comment|/* %0  = %1>> 16 */
asm|"orr    %0, %0, %2, lsl #16\n\t"
comment|/* %0 |= %2<< 16 */
asm|: "=r"(a), "=&r"(t2), "=&r"(t)       : "r"(a), "r"(b)       : "cc" );
return|return
name|a
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __arm__&& */
end_comment
begin_comment
comment|/* ( __thumb2__ || !__thumb__ )&& */
end_comment
begin_comment
comment|/* !( __CC_ARM || __ARMCC__ )      */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if
begin_define
DECL|macro|FT_MULFIX_ASSEMBLER
define|#
directive|define
name|FT_MULFIX_ASSEMBLER
value|FT_MulFix_i386
end_define
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_function
specifier|static
name|__inline__
name|FT_Int32
DECL|function|FT_MulFix_i386
name|FT_MulFix_i386
parameter_list|(
name|FT_Int32
name|a
parameter_list|,
name|FT_Int32
name|b
parameter_list|)
block|{
specifier|register
name|FT_Int32
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "imul  %%edx\n"       "movl  %%edx, %%ecx\n"       "sarl  $31, %%ecx\n"       "addl  $0x8000, %%ecx\n"       "addl  %%ecx, %%eax\n"       "adcl  $0, %%edx\n"       "shrl  $16, %%eax\n"       "shll  $16, %%edx\n"       "addl  %%edx, %%eax\n"       : "=a"(result), "=d"(b)       : "a"(a), "d"(b)       : "%ecx", "cc" );
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* i386 */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GNUC__ */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef
begin_comment
comment|/* Visual C++ */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_M_IX86
end_ifdef
begin_define
DECL|macro|FT_MULFIX_ASSEMBLER
define|#
directive|define
name|FT_MULFIX_ASSEMBLER
value|FT_MulFix_i386
end_define
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_function
specifier|static
name|__inline
name|FT_Int32
DECL|function|FT_MulFix_i386
name|FT_MulFix_i386
parameter_list|(
name|FT_Int32
name|a
parameter_list|,
name|FT_Int32
name|b
parameter_list|)
block|{
specifier|register
name|FT_Int32
name|result
decl_stmt|;
asm|__asm
block|{
name|mov
name|eax
decl_stmt|,
name|a
name|mov
name|edx
decl_stmt|,
name|b
name|imul
name|edx
name|mov
name|ecx
decl_stmt|,
name|edx
name|sar
name|ecx
decl_stmt|, 31
name|add
name|ecx
decl_stmt|, 8000h
name|add
name|eax
decl_stmt|,
name|ecx
name|adc
name|edx
decl_stmt|, 0
name|shr
name|eax
decl_stmt|, 16
name|shl
name|edx
decl_stmt|, 16
name|add
name|eax
decl_stmt|,
name|edx
name|mov
name|result
decl_stmt|,
name|eax
block|}
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _M_IX86 */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _MSC_VER */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if
begin_define
DECL|macro|FT_MULFIX_ASSEMBLER
define|#
directive|define
name|FT_MULFIX_ASSEMBLER
value|FT_MulFix_x86_64
end_define
begin_function
specifier|static
name|__inline__
name|FT_Int32
DECL|function|FT_MulFix_x86_64
name|FT_MulFix_x86_64
parameter_list|(
name|FT_Int32
name|a
parameter_list|,
name|FT_Int32
name|b
parameter_list|)
block|{
comment|/* Temporarily disable the warning that C90 doesn't support */
comment|/* `long long'.                                             */
if|#
directive|if
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|6
operator|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|push
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wlong-long"
endif|#
directive|endif
if|#
directive|if
literal|1
comment|/* Technically not an assembly fragment, but GCC does a really good */
comment|/* job at inlining it and generating good machine code for it.      */
name|long
name|long
name|ret
decl_stmt|,
name|tmp
decl_stmt|;
name|ret
operator|=
operator|(
name|long
name|long
operator|)
name|a
operator|*
name|b
expr_stmt|;
name|tmp
operator|=
name|ret
operator|>>
literal|63
expr_stmt|;
name|ret
operator|+=
literal|0x8000
operator|+
name|tmp
expr_stmt|;
return|return
call|(
name|FT_Int32
call|)
argument_list|(
name|ret
operator|>>
literal|16
argument_list|)
return|;
else|#
directive|else
comment|/* For some reason, GCC 4.6 on Ubuntu 12.04 generates invalid machine  */
comment|/* code from the lines below.  The main issue is that `wide_a' is not  */
comment|/* properly initialized by sign-extending `a'.  Instead, the generated */
comment|/* machine code assumes that the register that contains `a' on input   */
comment|/* can be used directly as a 64-bit value, which is wrong most of the  */
comment|/* time.                                                               */
name|long
name|long
name|wide_a
init|=
operator|(
name|long
name|long
operator|)
name|a
decl_stmt|;
name|long
name|long
name|wide_b
init|=
operator|(
name|long
name|long
operator|)
name|b
decl_stmt|;
name|long
name|long
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "imul %2, %1\n"       "mov %1, %0\n"       "sar $63, %0\n"       "lea 0x8000(%1, %0), %0\n"       "sar $16, %0\n"       : "=&r"(result), "=&r"(wide_a)       : "r"(wide_b)       : "cc" );
return|return
operator|(
name|FT_Int32
operator|)
name|result
return|;
endif|#
directive|endif
if|#
directive|if
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|6
operator|)
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|pop
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GNUC__&& __x86_64__ */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_NO_ASSEMBLER */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_INLINE_MULFIX
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_MULFIX_ASSEMBLER
end_ifdef
begin_define
DECL|macro|FT_MulFix
define|#
directive|define
name|FT_MulFix
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|FT_MULFIX_ASSEMBLER( (FT_Int32)(a), (FT_Int32)(b) )
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_MulDiv_No_Round                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to perform the computation `(a*b)/c'   */
end_comment
begin_comment
comment|/*    (without rounding) with maximum accuracy (it uses a 64-bit         */
end_comment
begin_comment
comment|/*    intermediate integer whenever necessary).                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function isn't necessarily as fast as some processor specific */
end_comment
begin_comment
comment|/*    operations, but is at least completely portable.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The first multiplier.                                         */
end_comment
begin_comment
comment|/*    b :: The second multiplier.                                        */
end_comment
begin_comment
comment|/*    c :: The divisor.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a*b)/c'.  This function never traps when trying to */
end_comment
begin_comment
comment|/*    divide by zero; it simply returns `MaxInt' or `MinInt' depending   */
end_comment
begin_comment
comment|/*    on the signs of `a' and `b'.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|FT_MulDiv_No_Round
argument_list|(
argument|FT_Long  a
argument_list|,
argument|FT_Long  b
argument_list|,
argument|FT_Long  c
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  A variant of FT_Matrix_Multiply which scales its result afterwards.    *  The idea is that both `a' and `b' are scaled by factors of 10 so that    *  the values are as precise as possible to get a correct result during    *  the 64bit multiplication.  Let `sa' and `sb' be the scaling factors of    *  `a' and `b', respectively, then the scaling factor of the result is    *  `sa*sb'.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Matrix_Multiply_Scaled
name|FT_Matrix_Multiply_Scaled
argument_list|(
argument|const FT_Matrix*  a
argument_list|,
argument|FT_Matrix        *b
argument_list|,
argument|FT_Long           scaling
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  A variant of FT_Vector_Transform.  See comments for    *  FT_Matrix_Multiply_Scaled.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Vector_Transform_Scaled
argument_list|(
argument|FT_Vector*        vector
argument_list|,
argument|const FT_Matrix*  matrix
argument_list|,
argument|FT_Long           scaling
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  Return -1, 0, or +1, depending on the orientation of a given corner.    *  We use the Cartesian coordinate system, with positive vertical values    *  going upwards.  The function returns +1 if the corner turns to the    *  left, -1 to the right, and 0 for undecidable cases.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|ft_corner_orientation
argument_list|(
argument|FT_Pos  in_x
argument_list|,
argument|FT_Pos  in_y
argument_list|,
argument|FT_Pos  out_x
argument_list|,
argument|FT_Pos  out_y
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  Return TRUE if a corner is flat or nearly flat.  This is equivalent to    *  saying that the corner point is close to its neighbors, or inside an    *  ellipse defined by the neighbor focal points to be more precise.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
DECL|variable|ft_corner_is_flat
name|ft_corner_is_flat
argument_list|(
argument|FT_Pos  in_x
argument_list|,
argument|FT_Pos  in_y
argument_list|,
argument|FT_Pos  out_x
argument_list|,
argument|FT_Pos  out_y
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  Return the most significant bit index.    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_ASSEMBLER
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
expr|\
operator|(
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
operator|)
end_if
begin_if
if|#
directive|if
name|FT_SIZEOF_INT
operator|==
literal|4
end_if
begin_define
DECL|macro|FT_MSB
define|#
directive|define
name|FT_MSB
parameter_list|(
name|x
parameter_list|)
value|( 31 - __builtin_clz( x ) )
end_define
begin_elif
elif|#
directive|elif
name|FT_SIZEOF_LONG
operator|==
literal|4
end_elif
begin_define
DECL|macro|FT_MSB
define|#
directive|define
name|FT_MSB
parameter_list|(
name|x
parameter_list|)
value|( 31 - __builtin_clzl( x ) )
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
comment|/* __GNUC__ */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_NO_ASSEMBLER */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_MSB
end_ifndef
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_MSB
argument_list|(
argument|FT_UInt32  z
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*    *  Return sqrt(x*x+y*y), which is the same as `FT_Vector_Length' but uses    *  two fixed-point arguments instead.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Hypot
name|FT_Hypot
argument_list|(
argument|FT_Fixed  x
argument_list|,
argument|FT_Fixed  y
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_SqrtFixed                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Computes the square root of a 16.16 fixed-point value.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    x :: The value to compute the root for.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `sqrt(x)'.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function is not very fast.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_endif
unit|FT_BASE( FT_Int32 )   FT_SqrtFixed( FT_Int32  x );
endif|#
directive|endif
end_endif
begin_comment
comment|/* 0 */
end_comment
begin_define
DECL|macro|INT_TO_F26DOT6
define|#
directive|define
name|INT_TO_F26DOT6
parameter_list|(
name|x
parameter_list|)
value|( (FT_Long)(x)<< 6  )
end_define
begin_define
DECL|macro|INT_TO_F2DOT14
define|#
directive|define
name|INT_TO_F2DOT14
parameter_list|(
name|x
parameter_list|)
value|( (FT_Long)(x)<< 14 )
end_define
begin_define
DECL|macro|INT_TO_FIXED
define|#
directive|define
name|INT_TO_FIXED
parameter_list|(
name|x
parameter_list|)
value|( (FT_Long)(x)<< 16 )
end_define
begin_define
DECL|macro|F2DOT14_TO_FIXED
define|#
directive|define
name|F2DOT14_TO_FIXED
parameter_list|(
name|x
parameter_list|)
value|( (FT_Long)(x)<< 2  )
end_define
begin_define
DECL|macro|FLOAT_TO_FIXED
define|#
directive|define
name|FLOAT_TO_FIXED
parameter_list|(
name|x
parameter_list|)
value|( (FT_Long)( x * 65536.0 ) )
end_define
begin_define
DECL|macro|FIXED_TO_INT
define|#
directive|define
name|FIXED_TO_INT
parameter_list|(
name|x
parameter_list|)
value|( FT_RoundFix( x )>> 16 )
end_define
begin_define
DECL|macro|ROUND_F26DOT6
define|#
directive|define
name|ROUND_F26DOT6
parameter_list|(
name|x
parameter_list|)
value|( x>= 0 ? (    ( (x) + 32 )& -64 )     \                                         : ( -( ( 32 - (x) )& -64 ) ) )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTCALC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
