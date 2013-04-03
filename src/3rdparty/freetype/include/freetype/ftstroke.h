begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftstroke.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType path stroker (specification).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2005, 2006, 2008, 2009 by                  */
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
name|__FT_STROKE_H__
end_ifndef
begin_define
DECL|macro|__FT_STROKE_H__
define|#
directive|define
name|__FT_STROKE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_GLYPH_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/************************************************************************   *   * @section:   *    glyph_stroker   *   * @title:   *    Glyph Stroker   *   * @abstract:   *    Generating bordered and stroked glyphs.   *   * @description:   *    This component generates stroked outlines of a given vectorial   *    glyph.  It also allows you to retrieve the `outside' and/or the   *    `inside' borders of the stroke.   *   *    This can be useful to generate `bordered' glyph, i.e., glyphs   *    displayed with a coloured (and anti-aliased) border around their   *    shape.   */
end_comment
begin_comment
comment|/**************************************************************   *   * @type:   *   FT_Stroker   *   * @description:   *   Opaque handler to a path stroker object.   */
end_comment
begin_typedef
DECL|typedef|FT_Stroker
typedef|typedef
name|struct
name|FT_StrokerRec_
modifier|*
name|FT_Stroker
typedef|;
end_typedef
begin_comment
comment|/**************************************************************    *    * @enum:    *   FT_Stroker_LineJoin    *    * @description:    *   These values determine how two joining lines are rendered    *   in a stroker.    *    * @values:    *   FT_STROKER_LINEJOIN_ROUND ::    *     Used to render rounded line joins.  Circular arcs are used    *     to join two lines smoothly.    *    *   FT_STROKER_LINEJOIN_BEVEL ::    *     Used to render beveled line joins; i.e., the two joining lines    *     are extended until they intersect.    *    *   FT_STROKER_LINEJOIN_MITER ::    *     Same as beveled rendering, except that an additional line    *     break is added if the angle between the two joining lines    *     is too closed (this is useful to avoid unpleasant spikes    *     in beveled rendering).    */
end_comment
begin_typedef
DECL|enum|FT_Stroker_LineJoin_
typedef|typedef
enum|enum
name|FT_Stroker_LineJoin_
block|{
DECL|enumerator|FT_STROKER_LINEJOIN_ROUND
name|FT_STROKER_LINEJOIN_ROUND
init|=
literal|0
block|,
DECL|enumerator|FT_STROKER_LINEJOIN_BEVEL
name|FT_STROKER_LINEJOIN_BEVEL
block|,
DECL|enumerator|FT_STROKER_LINEJOIN_MITER
name|FT_STROKER_LINEJOIN_MITER
block|}
DECL|typedef|FT_Stroker_LineJoin
name|FT_Stroker_LineJoin
typedef|;
end_typedef
begin_comment
comment|/**************************************************************    *    * @enum:    *   FT_Stroker_LineCap    *    * @description:    *   These values determine how the end of opened sub-paths are    *   rendered in a stroke.    *    * @values:    *   FT_STROKER_LINECAP_BUTT ::    *     The end of lines is rendered as a full stop on the last    *     point itself.    *    *   FT_STROKER_LINECAP_ROUND ::    *     The end of lines is rendered as a half-circle around the    *     last point.    *    *   FT_STROKER_LINECAP_SQUARE ::    *     The end of lines is rendered as a square around the    *     last point.    */
end_comment
begin_typedef
DECL|enum|FT_Stroker_LineCap_
typedef|typedef
enum|enum
name|FT_Stroker_LineCap_
block|{
DECL|enumerator|FT_STROKER_LINECAP_BUTT
name|FT_STROKER_LINECAP_BUTT
init|=
literal|0
block|,
DECL|enumerator|FT_STROKER_LINECAP_ROUND
name|FT_STROKER_LINECAP_ROUND
block|,
DECL|enumerator|FT_STROKER_LINECAP_SQUARE
name|FT_STROKER_LINECAP_SQUARE
block|}
DECL|typedef|FT_Stroker_LineCap
name|FT_Stroker_LineCap
typedef|;
end_typedef
begin_comment
comment|/**************************************************************    *    * @enum:    *   FT_StrokerBorder    *    * @description:    *   These values are used to select a given stroke border    *   in @FT_Stroker_GetBorderCounts and @FT_Stroker_ExportBorder.    *    * @values:    *   FT_STROKER_BORDER_LEFT ::    *     Select the left border, relative to the drawing direction.    *    *   FT_STROKER_BORDER_RIGHT ::    *     Select the right border, relative to the drawing direction.    *    * @note:    *   Applications are generally interested in the `inside' and `outside'    *   borders.  However, there is no direct mapping between these and the    *   `left' and `right' ones, since this really depends on the glyph's    *   drawing orientation, which varies between font formats.    *    *   You can however use @FT_Outline_GetInsideBorder and    *   @FT_Outline_GetOutsideBorder to get these.    */
end_comment
begin_typedef
DECL|enum|FT_StrokerBorder_
typedef|typedef
enum|enum
name|FT_StrokerBorder_
block|{
DECL|enumerator|FT_STROKER_BORDER_LEFT
name|FT_STROKER_BORDER_LEFT
init|=
literal|0
block|,
DECL|enumerator|FT_STROKER_BORDER_RIGHT
name|FT_STROKER_BORDER_RIGHT
block|}
DECL|typedef|FT_StrokerBorder
name|FT_StrokerBorder
typedef|;
end_typedef
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Outline_GetInsideBorder    *    * @description:    *   Retrieve the @FT_StrokerBorder value corresponding to the    *   `inside' borders of a given outline.    *    * @input:    *   outline ::    *     The source outline handle.    *    * @return:    *   The border index.  @FT_STROKER_BORDER_RIGHT for empty or invalid    *   outlines.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_StrokerBorder
argument_list|)
end_macro
begin_expr_stmt
name|FT_Outline_GetInsideBorder
argument_list|(
name|FT_Outline
operator|*
name|outline
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Outline_GetOutsideBorder    *    * @description:    *   Retrieve the @FT_StrokerBorder value corresponding to the    *   `outside' borders of a given outline.    *    * @input:    *   outline ::    *     The source outline handle.    *    * @return:    *   The border index.  @FT_STROKER_BORDER_LEFT for empty or invalid    *   outlines.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_StrokerBorder
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_Outline_GetOutsideBorder
name|FT_Outline_GetOutsideBorder
argument_list|(
name|FT_Outline
operator|*
name|outline
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_New    *    * @description:    *   Create a new stroker object.    *    * @input:    *   library ::    *     FreeType library handle.    *    * @output:    *   astroker ::    *     A new stroker object handle.  NULL in case of error.    *    * @return:    *    FreeType error code.  0~means success.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_New
argument_list|(
argument|FT_Library   library
argument_list|,
argument|FT_Stroker  *astroker
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_Set    *    * @description:    *   Reset a stroker object's attributes.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   radius ::    *     The border radius.    *    *   line_cap ::    *     The line cap style.    *    *   line_join ::    *     The line join style.    *    *   miter_limit ::    *     The miter limit for the FT_STROKER_LINEJOIN_MITER style,    *     expressed as 16.16 fixed point value.    *    * @note:    *   The radius is expressed in the same units as the outline    *   coordinates.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_Set
name|FT_Stroker_Set
argument_list|(
argument|FT_Stroker           stroker
argument_list|,
argument|FT_Fixed             radius
argument_list|,
argument|FT_Stroker_LineCap   line_cap
argument_list|,
argument|FT_Stroker_LineJoin  line_join
argument_list|,
argument|FT_Fixed             miter_limit
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_Rewind    *    * @description:    *   Reset a stroker object without changing its attributes.    *   You should call this function before beginning a new    *   series of calls to @FT_Stroker_BeginSubPath or    *   @FT_Stroker_EndSubPath.    *    * @input:    *   stroker ::    *     The target stroker handle.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|stroker
name|FT_Stroker_Rewind
argument_list|(
argument|FT_Stroker  stroker
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|stroker
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_ParseOutline    *    * @description:    *   A convenience function used to parse a whole outline with    *   the stroker.  The resulting outline(s) can be retrieved    *   later by functions like @FT_Stroker_GetCounts and @FT_Stroker_Export.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   outline ::    *     The source outline.    *    *   opened ::    *     A boolean.  If~1, the outline is treated as an open path instead    *     of a closed one.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   If `opened' is~0 (the default), the outline is treated as a closed    *   path, and the stroker generates two distinct `border' outlines.    *    *   If `opened' is~1, the outline is processed as an open path, and the    *   stroker generates a single `stroke' outline.    *    *   This function calls @FT_Stroker_Rewind automatically.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_ParseOutline
argument_list|(
argument|FT_Stroker   stroker
argument_list|,
argument|FT_Outline*  outline
argument_list|,
argument|FT_Bool      opened
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_BeginSubPath    *    * @description:    *   Start a new sub-path in the stroker.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   to ::    *     A pointer to the start vector.    *    *   open ::    *     A boolean.  If~1, the sub-path is treated as an open one.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   This function is useful when you need to stroke a path that is    *   not stored as an @FT_Outline object.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_BeginSubPath
name|FT_Stroker_BeginSubPath
argument_list|(
argument|FT_Stroker  stroker
argument_list|,
argument|FT_Vector*  to
argument_list|,
argument|FT_Bool     open
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_EndSubPath    *    * @description:    *   Close the current sub-path in the stroker.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   You should call this function after @FT_Stroker_BeginSubPath.    *   If the subpath was not `opened', this function `draws' a    *   single line segment to the start position when needed.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_EndSubPath
argument_list|(
argument|FT_Stroker  stroker
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_LineTo    *    * @description:    *   `Draw' a single line segment in the stroker's current sub-path,    *   from the last position.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   to ::    *     A pointer to the destination point.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   You should call this function between @FT_Stroker_BeginSubPath and    *   @FT_Stroker_EndSubPath.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_LineTo
name|FT_Stroker_LineTo
argument_list|(
argument|FT_Stroker  stroker
argument_list|,
argument|FT_Vector*  to
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_ConicTo    *    * @description:    *   `Draw' a single quadratic BÃ©zier in the stroker's current sub-path,    *   from the last position.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   control ::    *     A pointer to a BÃ©zier control point.    *    *   to ::    *     A pointer to the destination point.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   You should call this function between @FT_Stroker_BeginSubPath and    *   @FT_Stroker_EndSubPath.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_ConicTo
argument_list|(
argument|FT_Stroker  stroker
argument_list|,
argument|FT_Vector*  control
argument_list|,
argument|FT_Vector*  to
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_CubicTo    *    * @description:    *   `Draw' a single cubic BÃ©zier in the stroker's current sub-path,    *   from the last position.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   control1 ::    *     A pointer to the first BÃ©zier control point.    *    *   control2 ::    *     A pointer to second BÃ©zier control point.    *    *   to ::    *     A pointer to the destination point.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   You should call this function between @FT_Stroker_BeginSubPath and    *   @FT_Stroker_EndSubPath.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_CubicTo
name|FT_Stroker_CubicTo
argument_list|(
argument|FT_Stroker  stroker
argument_list|,
argument|FT_Vector*  control1
argument_list|,
argument|FT_Vector*  control2
argument_list|,
argument|FT_Vector*  to
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_GetBorderCounts    *    * @description:    *   Call this function once you have finished parsing your paths    *   with the stroker.  It returns the number of points and    *   contours necessary to export one of the `border' or `stroke'    *   outlines generated by the stroker.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   border ::    *     The border index.    *    * @output:    *   anum_points ::    *     The number of points.    *    *   anum_contours ::    *     The number of contours.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   When an outline, or a sub-path, is `closed', the stroker generates    *   two independent `border' outlines, named `left' and `right'.    *    *   When the outline, or a sub-path, is `opened', the stroker merges    *   the `border' outlines with caps.  The `left' border receives all    *   points, while the `right' border becomes empty.    *    *   Use the function @FT_Stroker_GetCounts instead if you want to    *   retrieve the counts associated to both borders.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_GetBorderCounts
argument_list|(
argument|FT_Stroker        stroker
argument_list|,
argument|FT_StrokerBorder  border
argument_list|,
argument|FT_UInt          *anum_points
argument_list|,
argument|FT_UInt          *anum_contours
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_ExportBorder    *    * @description:    *   Call this function after @FT_Stroker_GetBorderCounts to    *   export the corresponding border to your own @FT_Outline    *   structure.    *    *   Note that this function appends the border points and    *   contours to your outline, but does not try to resize its    *   arrays.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   border ::    *     The border index.    *    *   outline ::    *     The target outline handle.    *    * @note:    *   Always call this function after @FT_Stroker_GetBorderCounts to    *   get sure that there is enough room in your @FT_Outline object to    *   receive all new data.    *    *   When an outline, or a sub-path, is `closed', the stroker generates    *   two independent `border' outlines, named `left' and `right'    *    *   When the outline, or a sub-path, is `opened', the stroker merges    *   the `border' outlines with caps. The `left' border receives all    *   points, while the `right' border becomes empty.    *    *   Use the function @FT_Stroker_Export instead if you want to    *   retrieve all borders at once.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_ExportBorder
name|FT_Stroker_ExportBorder
argument_list|(
argument|FT_Stroker        stroker
argument_list|,
argument|FT_StrokerBorder  border
argument_list|,
argument|FT_Outline*       outline
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_GetCounts    *    * @description:    *   Call this function once you have finished parsing your paths    *   with the stroker.  It returns the number of points and    *   contours necessary to export all points/borders from the stroked    *   outline/path.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    * @output:    *   anum_points ::    *     The number of points.    *    *   anum_contours ::    *     The number of contours.    *    * @return:    *   FreeType error code.  0~means success.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stroker_GetCounts
argument_list|(
argument|FT_Stroker  stroker
argument_list|,
argument|FT_UInt    *anum_points
argument_list|,
argument|FT_UInt    *anum_contours
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_Export    *    * @description:    *   Call this function after @FT_Stroker_GetBorderCounts to    *   export all borders to your own @FT_Outline structure.    *    *   Note that this function appends the border points and    *   contours to your outline, but does not try to resize its    *   arrays.    *    * @input:    *   stroker ::    *     The target stroker handle.    *    *   outline ::    *     The target outline handle.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Stroker_Export
name|FT_Stroker_Export
argument_list|(
argument|FT_Stroker   stroker
argument_list|,
argument|FT_Outline*  outline
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Stroker_Done    *    * @description:    *   Destroy a stroker object.    *    * @input:    *   stroker ::    *     A stroker handle.  Can be NULL.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|stroker
name|FT_Stroker_Done
argument_list|(
argument|FT_Stroker  stroker
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|stroker
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Glyph_Stroke    *    * @description:    *   Stroke a given outline glyph object with a given stroker.    *    * @inout:    *   pglyph ::    *     Source glyph handle on input, new glyph handle on output.    *    * @input:    *   stroker ::    *     A stroker handle.    *    *   destroy ::    *     A Boolean.  If~1, the source glyph object is destroyed    *     on success.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *   The source glyph is untouched in case of error.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Glyph_Stroke
argument_list|(
argument|FT_Glyph    *pglyph
argument_list|,
argument|FT_Stroker   stroker
argument_list|,
argument|FT_Bool      destroy
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************    *    * @function:    *   FT_Glyph_StrokeBorder    *    * @description:    *   Stroke a given outline glyph object with a given stroker, but    *   only return either its inside or outside border.    *    * @inout:    *   pglyph ::    *     Source glyph handle on input, new glyph handle on output.    *    * @input:    *   stroker ::    *     A stroker handle.    *    *   inside ::    *     A Boolean.  If~1, return the inside border, otherwise    *     the outside border.    *    *   destroy ::    *     A Boolean.  If~1, the source glyph object is destroyed    *     on success.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *   The source glyph is untouched in case of error.    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Glyph_StrokeBorder
name|FT_Glyph_StrokeBorder
argument_list|(
argument|FT_Glyph    *pglyph
argument_list|,
argument|FT_Stroker   stroker
argument_list|,
argument|FT_Bool      inside
argument_list|,
argument|FT_Bool      destroy
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
comment|/* __FT_STROKE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
begin_comment
comment|/* Local Variables: */
end_comment
begin_comment
comment|/* coding: utf-8    */
end_comment
begin_comment
comment|/* End:             */
end_comment
end_unit
