begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  fttrigon.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType trigonometric functions (specification).                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001, 2003, 2005, 2007, 2013 by                              */
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
name|__FTTRIGON_H__
end_ifndef
begin_define
DECL|macro|__FTTRIGON_H__
define|#
directive|define
name|__FTTRIGON_H__
end_define
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*   computations                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   FT_Angle    *    * @description:    *   This type is used to model angle values in FreeType.  Note that the    *   angle is a 16.16 fixed-point value expressed in degrees.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Angle
typedef|typedef
name|FT_Fixed
name|FT_Angle
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ANGLE_PI    *    * @description:    *   The angle pi expressed in @FT_Angle units.    *    */
end_comment
begin_define
DECL|macro|FT_ANGLE_PI
define|#
directive|define
name|FT_ANGLE_PI
value|( 180L<< 16 )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ANGLE_2PI    *    * @description:    *   The angle 2*pi expressed in @FT_Angle units.    *    */
end_comment
begin_define
DECL|macro|FT_ANGLE_2PI
define|#
directive|define
name|FT_ANGLE_2PI
value|( FT_ANGLE_PI * 2 )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ANGLE_PI2    *    * @description:    *   The angle pi/2 expressed in @FT_Angle units.    *    */
end_comment
begin_define
DECL|macro|FT_ANGLE_PI2
define|#
directive|define
name|FT_ANGLE_PI2
value|( FT_ANGLE_PI / 2 )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ANGLE_PI4    *    * @description:    *   The angle pi/4 expressed in @FT_Angle units.    *    */
end_comment
begin_define
DECL|macro|FT_ANGLE_PI4
define|#
directive|define
name|FT_ANGLE_PI4
value|( FT_ANGLE_PI / 4 )
end_define
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Sin    *    * @description:    *   Return the sinus of a given angle in fixed-point format.    *    * @input:    *   angle ::    *     The input angle.    *    * @return:    *   The sinus value.    *    * @note:    *   If you need both the sinus and cosinus for a given angle, use the    *   function @FT_Vector_Unit.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|FT_Sin
argument_list|(
argument|FT_Angle  angle
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Cos    *    * @description:    *   Return the cosinus of a given angle in fixed-point format.    *    * @input:    *   angle ::    *     The input angle.    *    * @return:    *   The cosinus value.    *    * @note:    *   If you need both the sinus and cosinus for a given angle, use the    *   function @FT_Vector_Unit.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Cos
name|FT_Cos
argument_list|(
argument|FT_Angle  angle
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Cos
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Tan    *    * @description:    *   Return the tangent of a given angle in fixed-point format.    *    * @input:    *   angle ::    *     The input angle.    *    * @return:    *   The tangent value.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|FT_Tan
argument_list|(
argument|FT_Angle  angle
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Atan2    *    * @description:    *   Return the arc-tangent corresponding to a given vector (x,y) in    *   the 2d plane.    *    * @input:    *   x ::    *     The horizontal vector coordinate.    *    *   y ::    *     The vertical vector coordinate.    *    * @return:    *   The arc-tangent value (i.e. angle).    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Angle
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Atan2
name|FT_Atan2
argument_list|(
argument|FT_Fixed  x
argument_list|,
argument|FT_Fixed  y
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Angle_Diff    *    * @description:    *   Return the difference between two angles.  The result is always    *   constrained to the ]-PI..PI] interval.    *    * @input:    *   angle1 ::    *     First angle.    *    *   angle2 ::    *     Second angle.    *    * @return:    *   Constrained value of `value2-value1'.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Angle
argument_list|)
end_macro
begin_macro
name|FT_Angle_Diff
argument_list|(
argument|FT_Angle  angle1
argument_list|,
argument|FT_Angle  angle2
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Vector_Unit    *    * @description:    *   Return the unit vector corresponding to a given angle.  After the    *   call, the value of `vec.x' will be `sin(angle)', and the value of    *   `vec.y' will be `cos(angle)'.    *    *   This function is useful to retrieve both the sinus and cosinus of a    *   given angle quickly.    *    * @output:    *   vec ::    *     The address of target vector.    *    * @input:    *   angle ::    *     The input angle.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Vector_Unit
name|FT_Vector_Unit
argument_list|(
argument|FT_Vector*  vec
argument_list|,
argument|FT_Angle    angle
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Vector_Rotate    *    * @description:    *   Rotate a vector by a given angle.    *    * @inout:    *   vec ::    *     The address of target vector.    *    * @input:    *   angle ::    *     The input angle.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Vector_Rotate
argument_list|(
argument|FT_Vector*  vec
argument_list|,
argument|FT_Angle    angle
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Vector_Length    *    * @description:    *   Return the length of a given vector.    *    * @input:    *   vec ::    *     The address of target vector.    *    * @return:    *   The vector length, expressed in the same units that the original    *   vector coordinates.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_expr_stmt
name|FT_Vector_Length
argument_list|(
name|FT_Vector
operator|*
name|vec
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Vector_Polarize    *    * @description:    *   Compute both the length and angle of a given vector.    *    * @input:    *   vec ::    *     The address of source vector.    *    * @output:    *   length ::    *     The vector length.    *    *   angle ::    *     The vector angle.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_Vector_Polarize
name|FT_Vector_Polarize
argument_list|(
name|FT_Vector
operator|*
name|vec
argument_list|,
name|FT_Fixed
operator|*
name|length
argument_list|,
name|FT_Angle
operator|*
name|angle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Vector_From_Polar    *    * @description:    *   Compute vector coordinates from a length and angle.    *    * @output:    *   vec ::    *     The address of source vector.    *    * @input:    *   length ::    *     The vector length.    *    *   angle ::    *     The vector angle.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Vector_From_Polar
argument_list|(
argument|FT_Vector*  vec
argument_list|,
argument|FT_Fixed    length
argument_list|,
argument|FT_Angle    angle
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTTRIGON_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
