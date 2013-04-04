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
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006, 2008, 2009 by       */
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
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_FixedSqrt                                                       */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Computes the square root of a 16.16 fixed point value.             */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    x :: The value to compute the root for.                            */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    The result of `sqrt(x)'.                                           */
comment|/*                                                                       */
comment|/*<Note>                                                                */
comment|/*    This function is not very fast.                                    */
comment|/*                                                                       */
name|FT_BASE
parameter_list|(
name|FT_Int32
parameter_list|)
function_decl|FT_SqrtFixed
parameter_list|(
name|FT_Int32
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
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
comment|/*    FT_Sqrt32                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Computes the square root of an Int32 integer (which will be        */
end_comment
begin_comment
comment|/*    handled as an unsigned long value).                                */
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
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Int32
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Sqrt32
name|FT_Sqrt32
argument_list|(
argument|FT_Int32  x
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Sqrt32
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* FT_MulDiv() and FT_MulFix() are declared in freetype.h.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
end_ifdef
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
comment|/*    (without rounding) with maximal accuracy (it uses a 64-bit         */
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_USE_BYTECODE_INTERPRETER */
end_comment
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
comment|/*    *  Return TRUE if a corner is flat or nearly flat.  This is equivalent to    *  saying that the angle difference between the `in' and `out' vectors is    *  very small.    */
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
