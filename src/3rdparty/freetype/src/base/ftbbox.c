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
comment|/*  Copyright 1996-2002, 2004, 2006, 2010, 2013, 2014 by                   */
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
include|FT_INTERNAL_DEBUG_H
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
begin_define
DECL|macro|FT_UPDATE_BBOX
define|#
directive|define
name|FT_UPDATE_BBOX
parameter_list|(
name|p
parameter_list|,
name|bbox
parameter_list|)
define|\
value|FT_BEGIN_STMNT                  \     if ( p->x< bbox.xMin )       \       bbox.xMin = p->x;           \     if ( p->x> bbox.xMax )       \       bbox.xMax = p->x;           \     if ( p->y< bbox.yMin )       \       bbox.yMin = p->y;           \     if ( p->y> bbox.yMax )       \       bbox.yMax = p->y;           \   FT_END_STMNT
end_define
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
comment|/*    BBox_Move_To                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used as a `move_to' emitter during                */
end_comment
begin_comment
comment|/*    FT_Outline_Decompose().  It simply records the destination point   */
end_comment
begin_comment
comment|/*    in `user->last'. We also update bbox in case contour starts with   */
end_comment
begin_comment
comment|/*    an implicit `on' point.                                            */
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
name|FT_UPDATE_BBOX
argument_list|(
name|to
argument_list|,
name|user
operator|->
name|bbox
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
comment|/*    BBox_Line_To                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used as a `line_to' emitter during                */
end_comment
begin_comment
comment|/*    FT_Outline_Decompose().  It simply records the destination point   */
end_comment
begin_comment
comment|/*    in `user->last'; no further computations are necessary because     */
end_comment
begin_comment
comment|/*    bbox already contains both explicit ends of the line segment.      */
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
DECL|function|BBox_Line_To
name|BBox_Line_To
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
comment|/*    Find the extrema of a 1-dimensional conic Bezier curve and update  */
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
comment|/* This function is only called when a control off-point is outside */
comment|/* the bbox that contains all on-points.  It finds a local extremum */
comment|/* within the segment, equal to (y1*y3 - y2*y2)/(y1 - 2*y2 + y3).   */
comment|/* Or, offsetting from y2, we get                                   */
name|y1
operator|-=
name|y2
expr_stmt|;
name|y3
operator|-=
name|y2
expr_stmt|;
name|y2
operator|+=
name|FT_MulDiv
argument_list|(
name|y1
argument_list|,
name|y3
argument_list|,
name|y1
operator|+
name|y3
argument_list|)
expr_stmt|;
if|if
condition|(
name|y2
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|=
name|y2
expr_stmt|;
if|if
condition|(
name|y2
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|=
name|y2
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
comment|/* in case `to' is implicit and not included in bbox yet */
name|FT_UPDATE_BBOX
argument_list|(
name|to
argument_list|,
name|user
operator|->
name|bbox
argument_list|)
expr_stmt|;
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
comment|/*    Find the extrema of a 1-dimensional cubic Bezier curve and         */
end_comment
begin_comment
comment|/*    update a bounding range.  This version uses iterative splitting    */
end_comment
begin_comment
comment|/*    because it is faster than the exact solution with square roots.    */
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
begin_function
specifier|static
name|FT_Pos
DECL|function|cubic_peak
name|cubic_peak
parameter_list|(
name|FT_Pos
name|q1
parameter_list|,
name|FT_Pos
name|q2
parameter_list|,
name|FT_Pos
name|q3
parameter_list|,
name|FT_Pos
name|q4
parameter_list|)
block|{
name|FT_Pos
name|peak
init|=
literal|0
decl_stmt|;
name|FT_Int
name|shift
decl_stmt|;
comment|/* This function finds a peak of a cubic segment if it is above 0    */
comment|/* using iterative bisection of the segment, or returns 0.           */
comment|/* The fixed-point arithmetic of bisection is inherently stable      */
comment|/* but may loose accuracy in the two lowest bits.  To compensate,    */
comment|/* we upscale the segment if there is room.  Large values may need   */
comment|/* to be downscaled to avoid overflows during bisection.             */
comment|/* It is called with either q2 or q3 positive, which is necessary    */
comment|/* for the peak to exist and avoids undefined FT_MSB.                */
name|shift
operator|=
literal|27
operator|-
name|FT_MSB
argument_list|(
name|FT_ABS
argument_list|(
name|q1
argument_list|)
operator||
name|FT_ABS
argument_list|(
name|q2
argument_list|)
operator||
name|FT_ABS
argument_list|(
name|q3
argument_list|)
operator||
name|FT_ABS
argument_list|(
name|q4
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|shift
operator|>
literal|0
condition|)
block|{
comment|/* upscaling too much just wastes time */
if|if
condition|(
name|shift
operator|>
literal|2
condition|)
name|shift
operator|=
literal|2
expr_stmt|;
name|q1
operator|<<=
name|shift
expr_stmt|;
name|q2
operator|<<=
name|shift
expr_stmt|;
name|q3
operator|<<=
name|shift
expr_stmt|;
name|q4
operator|<<=
name|shift
expr_stmt|;
block|}
else|else
block|{
name|q1
operator|>>=
operator|-
name|shift
expr_stmt|;
name|q2
operator|>>=
operator|-
name|shift
expr_stmt|;
name|q3
operator|>>=
operator|-
name|shift
expr_stmt|;
name|q4
operator|>>=
operator|-
name|shift
expr_stmt|;
block|}
comment|/* for a peak to exist above 0, the cubic segment must have */
comment|/* at least one of its control off-points above 0.          */
while|while
condition|(
name|q2
operator|>
literal|0
operator|||
name|q3
operator|>
literal|0
condition|)
block|{
comment|/* determine which half contains the maximum and split */
if|if
condition|(
name|q1
operator|+
name|q2
operator|>
name|q3
operator|+
name|q4
condition|)
comment|/* first half */
block|{
name|q4
operator|=
name|q4
operator|+
name|q3
expr_stmt|;
name|q3
operator|=
name|q3
operator|+
name|q2
expr_stmt|;
name|q2
operator|=
name|q2
operator|+
name|q1
expr_stmt|;
name|q4
operator|=
name|q4
operator|+
name|q3
expr_stmt|;
name|q3
operator|=
name|q3
operator|+
name|q2
expr_stmt|;
name|q4
operator|=
operator|(
name|q4
operator|+
name|q3
operator|)
operator|/
literal|8
expr_stmt|;
name|q3
operator|=
name|q3
operator|/
literal|4
expr_stmt|;
name|q2
operator|=
name|q2
operator|/
literal|2
expr_stmt|;
block|}
else|else
comment|/* second half */
block|{
name|q1
operator|=
name|q1
operator|+
name|q2
expr_stmt|;
name|q2
operator|=
name|q2
operator|+
name|q3
expr_stmt|;
name|q3
operator|=
name|q3
operator|+
name|q4
expr_stmt|;
name|q1
operator|=
name|q1
operator|+
name|q2
expr_stmt|;
name|q2
operator|=
name|q2
operator|+
name|q3
expr_stmt|;
name|q1
operator|=
operator|(
name|q1
operator|+
name|q2
operator|)
operator|/
literal|8
expr_stmt|;
name|q2
operator|=
name|q2
operator|/
literal|4
expr_stmt|;
name|q3
operator|=
name|q3
operator|/
literal|2
expr_stmt|;
block|}
comment|/* check whether either end reached the maximum */
if|if
condition|(
name|q1
operator|==
name|q2
operator|&&
name|q1
operator|>=
name|q3
condition|)
block|{
name|peak
operator|=
name|q1
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|q3
operator|==
name|q4
operator|&&
name|q2
operator|<=
name|q4
condition|)
block|{
name|peak
operator|=
name|q4
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|shift
operator|>
literal|0
condition|)
name|peak
operator|>>=
name|shift
expr_stmt|;
else|else
name|peak
operator|<<=
operator|-
name|shift
expr_stmt|;
return|return
name|peak
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|BBox_Cubic_Check
name|BBox_Cubic_Check
parameter_list|(
name|FT_Pos
name|p1
parameter_list|,
name|FT_Pos
name|p2
parameter_list|,
name|FT_Pos
name|p3
parameter_list|,
name|FT_Pos
name|p4
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
comment|/* This function is only called when a control off-point is outside  */
comment|/* the bbox that contains all on-points.  So at least one of the     */
comment|/* conditions below holds and cubic_peak is called with at least one */
comment|/* non-zero argument.                                                */
if|if
condition|(
name|p2
operator|>
operator|*
name|max
operator|||
name|p3
operator|>
operator|*
name|max
condition|)
operator|*
name|max
operator|+=
name|cubic_peak
argument_list|(
name|p1
operator|-
operator|*
name|max
argument_list|,
name|p2
operator|-
operator|*
name|max
argument_list|,
name|p3
operator|-
operator|*
name|max
argument_list|,
name|p4
operator|-
operator|*
name|max
argument_list|)
expr_stmt|;
comment|/* now flip the signs to update the minimum */
if|if
condition|(
name|p2
operator|<
operator|*
name|min
operator|||
name|p3
operator|<
operator|*
name|min
condition|)
operator|*
name|min
operator|-=
name|cubic_peak
argument_list|(
operator|*
name|min
operator|-
name|p1
argument_list|,
operator|*
name|min
operator|-
name|p2
argument_list|,
operator|*
name|min
operator|-
name|p3
argument_list|,
operator|*
name|min
operator|-
name|p4
argument_list|)
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
comment|/* We don't need to check `to' since it is always an on-point,    */
comment|/* thus within the bbox.  Only segments with an off-point outside */
comment|/* the bbox can possibly reach new extreme values.                */
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
DECL|variable|BBox_Line_To
argument|(FT_Outline_LineTo_Func) BBox_Line_To
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
init|=
block|{
literal|0x7FFFFFFFL
block|,
literal|0x7FFFFFFFL
block|,
operator|-
literal|0x7FFFFFFFL
block|,
operator|-
literal|0x7FFFFFFFL
block|}
decl_stmt|;
name|FT_BBox
name|bbox
init|=
block|{
literal|0x7FFFFFFFL
block|,
literal|0x7FFFFFFFL
block|,
operator|-
literal|0x7FFFFFFFL
block|,
operator|-
literal|0x7FFFFFFFL
block|}
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
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
if|if
condition|(
operator|!
name|outline
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Outline
argument_list|)
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
for|for
control|(
name|n
operator|=
literal|0
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
name|FT_UPDATE_BBOX
argument_list|(
name|vec
argument_list|,
name|cbox
argument_list|)
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
name|FT_UPDATE_BBOX
argument_list|(
name|vec
argument_list|,
name|bbox
argument_list|)
expr_stmt|;
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
