begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbbox.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType bbox computation (body).                                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004, 2006, 2010 by                         */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used        */
end_comment
begin_comment
comment|/*  modified and distributed under the terms of the FreeType project       */
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
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This component has a _single_ role: to compute exact outline bounding */
end_comment
begin_comment
comment|/* boxes.                                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_BBOX_H
end_include
begin_include
include|#
directive|include
include|FT_IMAGE_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_CALC_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_typedef
DECL|struct|TBBox_Rec_
typedef|typedef
struct|struct
name|TBBox_Rec_
block|{
DECL|member|last
name|FT_Vector
name|last
decl_stmt|;
DECL|member|bbox
name|FT_BBox
name|bbox
decl_stmt|;
block|}
DECL|typedef|TBBox_Rec
name|TBBox_Rec
typedef|;
end_typedef
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
comment|/*    BBox_Move_To                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used as a `move_to' and `line_to' emitter during  */
end_comment
begin_comment
comment|/*    FT_Outline_Decompose().  It simply records the destination point   */
end_comment
begin_comment
comment|/*    in `user->last'; no further computations are necessary since we    */
end_comment
begin_comment
comment|/*    use the cbox as the starting bbox which must be refined.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    to   :: A pointer to the destination vector.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    user :: A pointer to the current walk context.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Always 0.  Needed for the interface only.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_function
specifier|static
name|int
DECL|function|BBox_Move_To
name|BBox_Move_To
parameter_list|(
name|FT_Vector
modifier|*
name|to
parameter_list|,
name|TBBox_Rec
modifier|*
name|user
parameter_list|)
block|{
name|user
operator|->
name|last
operator|=
operator|*
name|to
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_define
DECL|macro|CHECK_X
define|#
directive|define
name|CHECK_X
parameter_list|(
name|p
parameter_list|,
name|bbox
parameter_list|)
define|\
value|( p->x< bbox.xMin || p->x> bbox.xMax )
end_define
begin_define
DECL|macro|CHECK_Y
define|#
directive|define
name|CHECK_Y
parameter_list|(
name|p
parameter_list|,
name|bbox
parameter_list|)
define|\
value|( p->y< bbox.yMin || p->y> bbox.yMax )
end_define
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
comment|/*    BBox_Conic_Check                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Finds the extrema of a 1-dimensional conic Bezier curve and update */
end_comment
begin_comment
comment|/*    a bounding range.  This version uses direct computation, as it     */
end_comment
begin_comment
comment|/*    doesn't need square roots.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    y1  :: The start coordinate.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y2  :: The coordinate of the control point.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y3  :: The end coordinate.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    min :: The address of the current minimum.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max :: The address of the current maximum.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_function
specifier|static
name|void
DECL|function|BBox_Conic_Check
name|BBox_Conic_Check
parameter_list|(
name|FT_Pos
name|y1
parameter_list|,
name|FT_Pos
name|y2
parameter_list|,
name|FT_Pos
name|y3
parameter_list|,
name|FT_Pos
modifier|*
name|min
parameter_list|,
name|FT_Pos
modifier|*
name|max
parameter_list|)
block|{
if|if
condition|(
name|y1
operator|<=
name|y3
operator|&&
name|y2
operator|==
name|y1
condition|)
comment|/* flat arc */
goto|goto
name|Suite
goto|;
if|if
condition|(
name|y1
operator|<
name|y3
condition|)
block|{
if|if
condition|(
name|y2
operator|>=
name|y1
operator|&&
name|y2
operator|<=
name|y3
condition|)
comment|/* ascending arc */
goto|goto
name|Suite
goto|;
block|}
else|else
block|{
if|if
condition|(
name|y2
operator|>=
name|y3
operator|&&
name|y2
operator|<=
name|y1
condition|)
comment|/* descending arc */
block|{
name|y2
operator|=
name|y1
expr_stmt|;
name|y1
operator|=
name|y3
expr_stmt|;
name|y3
operator|=
name|y2
expr_stmt|;
goto|goto
name|Suite
goto|;
block|}
block|}
name|y1
operator|=
name|y3
operator|=
name|y1
operator|-
name|FT_MulDiv
argument_list|(
name|y2
operator|-
name|y1
argument_list|,
name|y2
operator|-
name|y1
argument_list|,
name|y1
operator|-
literal|2
operator|*
name|y2
operator|+
name|y3
argument_list|)
expr_stmt|;
name|Suite
label|:
if|if
condition|(
name|y1
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|=
name|y1
expr_stmt|;
if|if
condition|(
name|y3
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|=
name|y3
expr_stmt|;
block|}
end_function
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
comment|/*    BBox_Conic_To                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used as a `conic_to' emitter during               */
end_comment
begin_comment
comment|/*    FT_Outline_Decompose().  It checks a conic Bezier curve with the   */
end_comment
begin_comment
comment|/*    current bounding box, and computes its extrema if necessary to     */
end_comment
begin_comment
comment|/*    update it.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    control :: A pointer to a control point.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to      :: A pointer to the destination vector.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    user    :: The address of the current walk context.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Always 0.  Needed for the interface only.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    In the case of a non-monotonous arc, we compute directly the       */
end_comment
begin_comment
comment|/*    extremum coordinates, as it is sufficiently fast.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_function
specifier|static
name|int
DECL|function|BBox_Conic_To
name|BBox_Conic_To
parameter_list|(
name|FT_Vector
modifier|*
name|control
parameter_list|,
name|FT_Vector
modifier|*
name|to
parameter_list|,
name|TBBox_Rec
modifier|*
name|user
parameter_list|)
block|{
comment|/* we don't need to check `to' since it is always an `on' point, thus */
comment|/* within the bbox                                                    */
if|if
condition|(
name|CHECK_X
argument_list|(
name|control
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
condition|)
name|BBox_Conic_Check
argument_list|(
name|user
operator|->
name|last
operator|.
name|x
argument_list|,
name|control
operator|->
name|x
argument_list|,
name|to
operator|->
name|x
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|xMin
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|xMax
argument_list|)
expr_stmt|;
if|if
condition|(
name|CHECK_Y
argument_list|(
name|control
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
condition|)
name|BBox_Conic_Check
argument_list|(
name|user
operator|->
name|last
operator|.
name|y
argument_list|,
name|control
operator|->
name|y
argument_list|,
name|to
operator|->
name|y
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|yMin
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|yMax
argument_list|)
expr_stmt|;
name|user
operator|->
name|last
operator|=
operator|*
name|to
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
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
comment|/*    BBox_Cubic_Check                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Finds the extrema of a 1-dimensional cubic Bezier curve and        */
end_comment
begin_comment
comment|/*    updates a bounding range.  This version uses splitting because we  */
end_comment
begin_comment
comment|/*    don't want to use square roots and extra accuracy.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    p1  :: The start coordinate.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    p2  :: The coordinate of the first control point.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    p3  :: The coordinate of the second control point.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    p4  :: The end coordinate.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    min :: The address of the current minimum.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max :: The address of the current maximum.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
unit|static void   BBox_Cubic_Check( FT_Pos   p1,                     FT_Pos   p2,                     FT_Pos   p3,                     FT_Pos   p4,                     FT_Pos*  min,                     FT_Pos*  max )   {     FT_Pos  stack[32*3 + 1], *arc;       arc = stack;      arc[0] = p1;     arc[1] = p2;     arc[2] = p3;     arc[3] = p4;      do     {       FT_Pos  y1 = arc[0];       FT_Pos  y2 = arc[1];       FT_Pos  y3 = arc[2];       FT_Pos  y4 = arc[3];         if ( y1 == y4 )       {         if ( y1 == y2&& y1 == y3 )
comment|/* flat */
end_comment
begin_comment
unit|goto Test;       }       else if ( y1< y4 )       {         if ( y2>= y1&& y2<= y4&& y3>= y1&& y3<= y4 )
comment|/* ascending */
end_comment
begin_comment
unit|goto Test;       }       else       {         if ( y2>= y4&& y2<= y1&& y3>= y4&& y3<= y1 )
comment|/* descending */
end_comment
begin_comment
unit|{           y2 = y1;           y1 = y4;           y4 = y2;           goto Test;         }       }
comment|/* unknown direction -- split the arc in two */
end_comment
begin_else
unit|arc[6] = y4;       arc[1] = y1 = ( y1 + y2 ) / 2;       arc[5] = y4 = ( y4 + y3 ) / 2;       y2 = ( y2 + y3 ) / 2;       arc[2] = y1 = ( y1 + y2 ) / 2;       arc[4] = y4 = ( y4 + y2 ) / 2;       arc[3] = ( y1 + y4 ) / 2;        arc += 3;       goto Suite;     Test:       if ( y1< *min ) *min = y1;       if ( y4> *max ) *max = y4;       arc -= 3;      Suite:       ;     } while ( arc>= stack );   }
else|#
directive|else
end_else
begin_function
specifier|static
name|void
DECL|function|test_cubic_extrema
name|test_cubic_extrema
parameter_list|(
name|FT_Pos
name|y1
parameter_list|,
name|FT_Pos
name|y2
parameter_list|,
name|FT_Pos
name|y3
parameter_list|,
name|FT_Pos
name|y4
parameter_list|,
name|FT_Fixed
name|u
parameter_list|,
name|FT_Pos
modifier|*
name|min
parameter_list|,
name|FT_Pos
modifier|*
name|max
parameter_list|)
block|{
comment|/* FT_Pos    a = y4 - 3*y3 + 3*y2 - y1; */
name|FT_Pos
name|b
init|=
name|y3
operator|-
literal|2
operator|*
name|y2
operator|+
name|y1
decl_stmt|;
name|FT_Pos
name|c
init|=
name|y2
operator|-
name|y1
decl_stmt|;
name|FT_Pos
name|d
init|=
name|y1
decl_stmt|;
name|FT_Pos
name|y
decl_stmt|;
name|FT_Fixed
name|uu
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|y4
argument_list|)
expr_stmt|;
comment|/* The polynomial is                      */
comment|/*                                        */
comment|/*    P(x) = a*x^3 + 3b*x^2 + 3c*x + d  , */
comment|/*                                        */
comment|/*   dP/dx = 3a*x^2 + 6b*x + 3c         . */
comment|/*                                        */
comment|/* However, we also have                  */
comment|/*                                        */
comment|/*   dP/dx(u) = 0                       , */
comment|/*                                        */
comment|/* which implies by subtraction that      */
comment|/*                                        */
comment|/*   P(u) = b*u^2 + 2c*u + d            . */
if|if
condition|(
name|u
operator|>
literal|0
operator|&&
name|u
operator|<
literal|0x10000L
condition|)
block|{
name|uu
operator|=
name|FT_MulFix
argument_list|(
name|u
argument_list|,
name|u
argument_list|)
expr_stmt|;
name|y
operator|=
name|d
operator|+
name|FT_MulFix
argument_list|(
name|c
argument_list|,
literal|2
operator|*
name|u
argument_list|)
operator|+
name|FT_MulFix
argument_list|(
name|b
argument_list|,
name|uu
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|=
name|y
expr_stmt|;
if|if
condition|(
name|y
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|=
name|y
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|BBox_Cubic_Check
name|BBox_Cubic_Check
parameter_list|(
name|FT_Pos
name|y1
parameter_list|,
name|FT_Pos
name|y2
parameter_list|,
name|FT_Pos
name|y3
parameter_list|,
name|FT_Pos
name|y4
parameter_list|,
name|FT_Pos
modifier|*
name|min
parameter_list|,
name|FT_Pos
modifier|*
name|max
parameter_list|)
block|{
comment|/* always compare first and last points */
if|if
condition|(
name|y1
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|=
name|y1
expr_stmt|;
elseif|else
if|if
condition|(
name|y1
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|=
name|y1
expr_stmt|;
if|if
condition|(
name|y4
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|=
name|y4
expr_stmt|;
elseif|else
if|if
condition|(
name|y4
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|=
name|y4
expr_stmt|;
comment|/* now, try to see if there are split points here */
if|if
condition|(
name|y1
operator|<=
name|y4
condition|)
block|{
comment|/* flat or ascending arc test */
if|if
condition|(
name|y1
operator|<=
name|y2
operator|&&
name|y2
operator|<=
name|y4
operator|&&
name|y1
operator|<=
name|y3
operator|&&
name|y3
operator|<=
name|y4
condition|)
return|return;
block|}
else|else
comment|/* y1> y4 */
block|{
comment|/* descending arc test */
if|if
condition|(
name|y1
operator|>=
name|y2
operator|&&
name|y2
operator|>=
name|y4
operator|&&
name|y1
operator|>=
name|y3
operator|&&
name|y3
operator|>=
name|y4
condition|)
return|return;
block|}
comment|/* There are some split points.  Find them. */
block|{
name|FT_Pos
name|a
init|=
name|y4
operator|-
literal|3
operator|*
name|y3
operator|+
literal|3
operator|*
name|y2
operator|-
name|y1
decl_stmt|;
name|FT_Pos
name|b
init|=
name|y3
operator|-
literal|2
operator|*
name|y2
operator|+
name|y1
decl_stmt|;
name|FT_Pos
name|c
init|=
name|y2
operator|-
name|y1
decl_stmt|;
name|FT_Pos
name|d
decl_stmt|;
name|FT_Fixed
name|t
decl_stmt|;
comment|/* We need to solve `ax^2+2bx+c' here, without floating points!      */
comment|/* The trick is to normalize to a different representation in order  */
comment|/* to use our 16.16 fixed point routines.                            */
comment|/*                                                                   */
comment|/* We compute FT_MulFix(b,b) and FT_MulFix(a,c) after normalization. */
comment|/* These values must fit into a single 16.16 value.                  */
comment|/*                                                                   */
comment|/* We normalize a, b, and c to `8.16' fixed float values to ensure   */
comment|/* that its product is held in a `16.16' value.                      */
block|{
name|FT_ULong
name|t1
decl_stmt|,
name|t2
decl_stmt|;
name|int
name|shift
init|=
literal|0
decl_stmt|;
comment|/* The following computation is based on the fact that for   */
comment|/* any value `y', if `n' is the position of the most         */
comment|/* significant bit of `abs(y)' (starting from 0 for the      */
comment|/* least significant bit), then `y' is in the range          */
comment|/*                                                           */
comment|/*   -2^n..2^n-1                                             */
comment|/*                                                           */
comment|/* We want to shift `a', `b', and `c' concurrently in order  */
comment|/* to ensure that they all fit in 8.16 values, which maps    */
comment|/* to the integer range `-2^23..2^23-1'.                     */
comment|/*                                                           */
comment|/* Necessarily, we need to shift `a', `b', and `c' so that   */
comment|/* the most significant bit of its absolute values is at     */
comment|/* _most_ at position 23.                                    */
comment|/*                                                           */
comment|/* We begin by computing `t1' as the bitwise `OR' of the     */
comment|/* absolute values of `a', `b', `c'.                         */
name|t1
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
operator|(
name|a
operator|>=
literal|0
operator|)
condition|?
name|a
else|:
operator|-
name|a
argument_list|)
expr_stmt|;
name|t2
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
operator|(
name|b
operator|>=
literal|0
operator|)
condition|?
name|b
else|:
operator|-
name|b
argument_list|)
expr_stmt|;
name|t1
operator||=
name|t2
expr_stmt|;
name|t2
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
operator|(
name|c
operator|>=
literal|0
operator|)
condition|?
name|c
else|:
operator|-
name|c
argument_list|)
expr_stmt|;
name|t1
operator||=
name|t2
expr_stmt|;
comment|/* Now we can be sure that the most significant bit of `t1'  */
comment|/* is the most significant bit of either `a', `b', or `c',   */
comment|/* depending on the greatest integer range of the particular */
comment|/* variable.                                                 */
comment|/*                                                           */
comment|/* Next, we compute the `shift', by shifting `t1' as many    */
comment|/* times as necessary to move its MSB to position 23.  This  */
comment|/* corresponds to a value of `t1' that is in the range       */
comment|/* 0x40_0000..0x7F_FFFF.                                     */
comment|/*                                                           */
comment|/* Finally, we shift `a', `b', and `c' by the same amount.   */
comment|/* This ensures that all values are now in the range         */
comment|/* -2^23..2^23, i.e., they are now expressed as 8.16         */
comment|/* fixed-float numbers.  This also means that we are using   */
comment|/* 24 bits of precision to compute the zeros, independently  */
comment|/* of the range of the original polynomial coefficients.     */
comment|/*                                                           */
comment|/* This algorithm should ensure reasonably accurate values   */
comment|/* for the zeros.  Note that they are only expressed with    */
comment|/* 16 bits when computing the extrema (the zeros need to     */
comment|/* be in 0..1 exclusive to be considered part of the arc).   */
if|if
condition|(
name|t1
operator|==
literal|0
condition|)
comment|/* all coefficients are 0! */
return|return;
if|if
condition|(
name|t1
operator|>
literal|0x7FFFFFUL
condition|)
block|{
do|do
block|{
name|shift
operator|++
expr_stmt|;
name|t1
operator|>>=
literal|1
expr_stmt|;
block|}
do|while
condition|(
name|t1
operator|>
literal|0x7FFFFFUL
condition|)
do|;
comment|/* this loses some bits of precision, but we use 24 of them */
comment|/* for the computation anyway                               */
name|a
operator|>>=
name|shift
expr_stmt|;
name|b
operator|>>=
name|shift
expr_stmt|;
name|c
operator|>>=
name|shift
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|t1
operator|<
literal|0x400000UL
condition|)
block|{
do|do
block|{
name|shift
operator|++
expr_stmt|;
name|t1
operator|<<=
literal|1
expr_stmt|;
block|}
do|while
condition|(
name|t1
operator|<
literal|0x400000UL
condition|)
do|;
name|a
operator|<<=
name|shift
expr_stmt|;
name|b
operator|<<=
name|shift
expr_stmt|;
name|c
operator|<<=
name|shift
expr_stmt|;
block|}
block|}
comment|/* handle a == 0 */
if|if
condition|(
name|a
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|b
operator|!=
literal|0
condition|)
block|{
name|t
operator|=
operator|-
name|FT_DivFix
argument_list|(
name|c
argument_list|,
name|b
argument_list|)
operator|/
literal|2
expr_stmt|;
name|test_cubic_extrema
argument_list|(
name|y1
argument_list|,
name|y2
argument_list|,
name|y3
argument_list|,
name|y4
argument_list|,
name|t
argument_list|,
name|min
argument_list|,
name|max
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* solve the equation now */
name|d
operator|=
name|FT_MulFix
argument_list|(
name|b
argument_list|,
name|b
argument_list|)
operator|-
name|FT_MulFix
argument_list|(
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|<
literal|0
condition|)
return|return;
if|if
condition|(
name|d
operator|==
literal|0
condition|)
block|{
comment|/* there is a single split point at -b/a */
name|t
operator|=
operator|-
name|FT_DivFix
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|test_cubic_extrema
argument_list|(
name|y1
argument_list|,
name|y2
argument_list|,
name|y3
argument_list|,
name|y4
argument_list|,
name|t
argument_list|,
name|min
argument_list|,
name|max
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* there are two solutions; we need to filter them */
name|d
operator|=
name|FT_SqrtFixed
argument_list|(
operator|(
name|FT_Int32
operator|)
name|d
argument_list|)
expr_stmt|;
name|t
operator|=
operator|-
name|FT_DivFix
argument_list|(
name|b
operator|-
name|d
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|test_cubic_extrema
argument_list|(
name|y1
argument_list|,
name|y2
argument_list|,
name|y3
argument_list|,
name|y4
argument_list|,
name|t
argument_list|,
name|min
argument_list|,
name|max
argument_list|)
expr_stmt|;
name|t
operator|=
operator|-
name|FT_DivFix
argument_list|(
name|b
operator|+
name|d
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|test_cubic_extrema
argument_list|(
name|y1
argument_list|,
name|y2
argument_list|,
name|y3
argument_list|,
name|y4
argument_list|,
name|t
argument_list|,
name|min
argument_list|,
name|max
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
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
comment|/*    BBox_Cubic_To                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used as a `cubic_to' emitter during               */
end_comment
begin_comment
comment|/*    FT_Outline_Decompose().  It checks a cubic Bezier curve with the   */
end_comment
begin_comment
comment|/*    current bounding box, and computes its extrema if necessary to     */
end_comment
begin_comment
comment|/*    update it.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    control1 :: A pointer to the first control point.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    control2 :: A pointer to the second control point.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to       :: A pointer to the destination vector.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    user     :: The address of the current walk context.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Always 0.  Needed for the interface only.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    In the case of a non-monotonous arc, we don't compute directly     */
end_comment
begin_comment
comment|/*    extremum coordinates, we subdivide instead.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_function
specifier|static
name|int
DECL|function|BBox_Cubic_To
name|BBox_Cubic_To
parameter_list|(
name|FT_Vector
modifier|*
name|control1
parameter_list|,
name|FT_Vector
modifier|*
name|control2
parameter_list|,
name|FT_Vector
modifier|*
name|to
parameter_list|,
name|TBBox_Rec
modifier|*
name|user
parameter_list|)
block|{
comment|/* we don't need to check `to' since it is always an `on' point, thus */
comment|/* within the bbox                                                    */
if|if
condition|(
name|CHECK_X
argument_list|(
name|control1
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
operator|||
name|CHECK_X
argument_list|(
name|control2
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
condition|)
name|BBox_Cubic_Check
argument_list|(
name|user
operator|->
name|last
operator|.
name|x
argument_list|,
name|control1
operator|->
name|x
argument_list|,
name|control2
operator|->
name|x
argument_list|,
name|to
operator|->
name|x
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|xMin
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|xMax
argument_list|)
expr_stmt|;
if|if
condition|(
name|CHECK_Y
argument_list|(
name|control1
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
operator|||
name|CHECK_Y
argument_list|(
name|control2
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
condition|)
name|BBox_Cubic_Check
argument_list|(
name|user
operator|->
name|last
operator|.
name|y
argument_list|,
name|control1
operator|->
name|y
argument_list|,
name|control2
operator|->
name|y
argument_list|,
name|to
operator|->
name|y
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|yMin
argument_list|,
operator|&
name|user
operator|->
name|bbox
operator|.
name|yMax
argument_list|)
expr_stmt|;
name|user
operator|->
name|last
operator|=
operator|*
name|to
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_OUTLINE_FUNCS
argument_list|(
argument|bbox_interface
argument_list|,
argument|(FT_Outline_MoveTo_Func) BBox_Move_To
argument_list|,
DECL|variable|BBox_Move_To
argument|(FT_Outline_LineTo_Func) BBox_Move_To
argument_list|,
DECL|variable|BBox_Conic_To
argument|(FT_Outline_ConicTo_Func)BBox_Conic_To
argument_list|,
DECL|variable|BBox_Cubic_To
argument|(FT_Outline_CubicTo_Func)BBox_Cubic_To
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
end_macro
begin_comment
comment|/* documentation is in ftbbox.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Outline_Get_BBox
argument_list|(
argument|FT_Outline*  outline
argument_list|,
argument|FT_BBox     *abbox
argument_list|)
end_macro
begin_block
block|{
name|FT_BBox
name|cbox
decl_stmt|;
name|FT_BBox
name|bbox
decl_stmt|;
name|FT_Vector
modifier|*
name|vec
decl_stmt|;
name|FT_UShort
name|n
decl_stmt|;
if|if
condition|(
operator|!
name|abbox
condition|)
return|return
name|FT_Err_Invalid_Argument
return|;
if|if
condition|(
operator|!
name|outline
condition|)
return|return
name|FT_Err_Invalid_Outline
return|;
comment|/* if outline is empty, return (0,0,0,0) */
if|if
condition|(
name|outline
operator|->
name|n_points
operator|==
literal|0
operator|||
name|outline
operator|->
name|n_contours
operator|<=
literal|0
condition|)
block|{
name|abbox
operator|->
name|xMin
operator|=
name|abbox
operator|->
name|xMax
operator|=
literal|0
expr_stmt|;
name|abbox
operator|->
name|yMin
operator|=
name|abbox
operator|->
name|yMax
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* We compute the control box as well as the bounding box of  */
comment|/* all `on' points in the outline.  Then, if the two boxes    */
comment|/* coincide, we exit immediately.                             */
name|vec
operator|=
name|outline
operator|->
name|points
expr_stmt|;
name|bbox
operator|.
name|xMin
operator|=
name|bbox
operator|.
name|xMax
operator|=
name|cbox
operator|.
name|xMin
operator|=
name|cbox
operator|.
name|xMax
operator|=
name|vec
operator|->
name|x
expr_stmt|;
name|bbox
operator|.
name|yMin
operator|=
name|bbox
operator|.
name|yMax
operator|=
name|cbox
operator|.
name|yMin
operator|=
name|cbox
operator|.
name|yMax
operator|=
name|vec
operator|->
name|y
expr_stmt|;
name|vec
operator|++
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|1
init|;
name|n
operator|<
name|outline
operator|->
name|n_points
condition|;
name|n
operator|++
control|)
block|{
name|FT_Pos
name|x
init|=
name|vec
operator|->
name|x
decl_stmt|;
name|FT_Pos
name|y
init|=
name|vec
operator|->
name|y
decl_stmt|;
comment|/* update control box */
if|if
condition|(
name|x
operator|<
name|cbox
operator|.
name|xMin
condition|)
name|cbox
operator|.
name|xMin
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|cbox
operator|.
name|xMax
condition|)
name|cbox
operator|.
name|xMax
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|<
name|cbox
operator|.
name|yMin
condition|)
name|cbox
operator|.
name|yMin
operator|=
name|y
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|cbox
operator|.
name|yMax
condition|)
name|cbox
operator|.
name|yMax
operator|=
name|y
expr_stmt|;
if|if
condition|(
name|FT_CURVE_TAG
argument_list|(
name|outline
operator|->
name|tags
index|[
name|n
index|]
argument_list|)
operator|==
name|FT_CURVE_TAG_ON
condition|)
block|{
comment|/* update bbox for `on' points only */
if|if
condition|(
name|x
operator|<
name|bbox
operator|.
name|xMin
condition|)
name|bbox
operator|.
name|xMin
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|bbox
operator|.
name|xMax
condition|)
name|bbox
operator|.
name|xMax
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|<
name|bbox
operator|.
name|yMin
condition|)
name|bbox
operator|.
name|yMin
operator|=
name|y
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|bbox
operator|.
name|yMax
condition|)
name|bbox
operator|.
name|yMax
operator|=
name|y
expr_stmt|;
block|}
name|vec
operator|++
expr_stmt|;
block|}
comment|/* test two boxes for equality */
if|if
condition|(
name|cbox
operator|.
name|xMin
operator|<
name|bbox
operator|.
name|xMin
operator|||
name|cbox
operator|.
name|xMax
operator|>
name|bbox
operator|.
name|xMax
operator|||
name|cbox
operator|.
name|yMin
operator|<
name|bbox
operator|.
name|yMin
operator|||
name|cbox
operator|.
name|yMax
operator|>
name|bbox
operator|.
name|yMax
condition|)
block|{
comment|/* the two boxes are different, now walk over the outline to */
comment|/* get the Bezier arc extrema.                               */
name|FT_Error
name|error
decl_stmt|;
name|TBBox_Rec
name|user
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
name|FT_Outline_Funcs
name|bbox_interface
decl_stmt|;
name|Init_Class_bbox_interface
argument_list|(
operator|&
name|bbox_interface
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|user
operator|.
name|bbox
operator|=
name|bbox
expr_stmt|;
name|error
operator|=
name|FT_Outline_Decompose
argument_list|(
name|outline
argument_list|,
operator|&
name|bbox_interface
argument_list|,
operator|&
name|user
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
name|error
return|;
operator|*
name|abbox
operator|=
name|user
operator|.
name|bbox
expr_stmt|;
block|}
else|else
operator|*
name|abbox
operator|=
name|bbox
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
