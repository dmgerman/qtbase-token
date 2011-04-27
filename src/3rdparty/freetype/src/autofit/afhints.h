begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afhints.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines (specification).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2006, 2007, 2008 by                        */
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
name|__AFHINTS_H__
end_ifndef
begin_define
DECL|macro|__AFHINTS_H__
define|#
directive|define
name|__AFHINTS_H__
end_define
begin_include
include|#
directive|include
file|"aftypes.h"
end_include
begin_define
DECL|macro|xxAF_SORT_SEGMENTS
define|#
directive|define
name|xxAF_SORT_SEGMENTS
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*   *  The definition of outline glyph hints.  These are shared by all   *  script analysis routines (until now).   */
end_comment
begin_typedef
DECL|enum|AF_Dimension_
typedef|typedef
enum|enum
name|AF_Dimension_
block|{
DECL|enumerator|AF_DIMENSION_HORZ
name|AF_DIMENSION_HORZ
init|=
literal|0
block|,
comment|/* x coordinates,                    */
comment|/* i.e., vertical segments& edges   */
DECL|enumerator|AF_DIMENSION_VERT
name|AF_DIMENSION_VERT
init|=
literal|1
block|,
comment|/* y coordinates,                    */
comment|/* i.e., horizontal segments& edges */
DECL|enumerator|AF_DIMENSION_MAX
name|AF_DIMENSION_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_Dimension
name|AF_Dimension
typedef|;
end_typedef
begin_comment
comment|/* hint directions -- the values are computed so that two vectors are */
end_comment
begin_comment
comment|/* in opposite directions iff `dir1 + dir2 == 0'                      */
end_comment
begin_typedef
DECL|enum|AF_Direction_
typedef|typedef
enum|enum
name|AF_Direction_
block|{
DECL|enumerator|AF_DIR_NONE
name|AF_DIR_NONE
init|=
literal|4
block|,
DECL|enumerator|AF_DIR_RIGHT
name|AF_DIR_RIGHT
init|=
literal|1
block|,
DECL|enumerator|AF_DIR_LEFT
name|AF_DIR_LEFT
init|=
operator|-
literal|1
block|,
DECL|enumerator|AF_DIR_UP
name|AF_DIR_UP
init|=
literal|2
block|,
DECL|enumerator|AF_DIR_DOWN
name|AF_DIR_DOWN
init|=
operator|-
literal|2
block|}
DECL|typedef|AF_Direction
name|AF_Direction
typedef|;
end_typedef
begin_comment
comment|/* point hint flags */
end_comment
begin_typedef
DECL|enum|AF_Flags_
typedef|typedef
enum|enum
name|AF_Flags_
block|{
DECL|enumerator|AF_FLAG_NONE
name|AF_FLAG_NONE
init|=
literal|0
block|,
comment|/* point type flags */
DECL|enumerator|AF_FLAG_CONIC
name|AF_FLAG_CONIC
init|=
literal|1
operator|<<
literal|0
block|,
DECL|enumerator|AF_FLAG_CUBIC
name|AF_FLAG_CUBIC
init|=
literal|1
operator|<<
literal|1
block|,
DECL|enumerator|AF_FLAG_CONTROL
name|AF_FLAG_CONTROL
init|=
name|AF_FLAG_CONIC
operator||
name|AF_FLAG_CUBIC
block|,
comment|/* point extremum flags */
DECL|enumerator|AF_FLAG_EXTREMA_X
name|AF_FLAG_EXTREMA_X
init|=
literal|1
operator|<<
literal|2
block|,
DECL|enumerator|AF_FLAG_EXTREMA_Y
name|AF_FLAG_EXTREMA_Y
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* point roundness flags */
DECL|enumerator|AF_FLAG_ROUND_X
name|AF_FLAG_ROUND_X
init|=
literal|1
operator|<<
literal|4
block|,
DECL|enumerator|AF_FLAG_ROUND_Y
name|AF_FLAG_ROUND_Y
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* point touch flags */
DECL|enumerator|AF_FLAG_TOUCH_X
name|AF_FLAG_TOUCH_X
init|=
literal|1
operator|<<
literal|6
block|,
DECL|enumerator|AF_FLAG_TOUCH_Y
name|AF_FLAG_TOUCH_Y
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* candidates for weak interpolation have this flag set */
DECL|enumerator|AF_FLAG_WEAK_INTERPOLATION
name|AF_FLAG_WEAK_INTERPOLATION
init|=
literal|1
operator|<<
literal|8
block|,
comment|/* all inflection points in the outline have this flag set */
DECL|enumerator|AF_FLAG_INFLECTION
name|AF_FLAG_INFLECTION
init|=
literal|1
operator|<<
literal|9
block|}
DECL|typedef|AF_Flags
name|AF_Flags
typedef|;
end_typedef
begin_comment
comment|/* edge hint flags */
end_comment
begin_typedef
DECL|enum|AF_Edge_Flags_
typedef|typedef
enum|enum
name|AF_Edge_Flags_
block|{
DECL|enumerator|AF_EDGE_NORMAL
name|AF_EDGE_NORMAL
init|=
literal|0
block|,
DECL|enumerator|AF_EDGE_ROUND
name|AF_EDGE_ROUND
init|=
literal|1
operator|<<
literal|0
block|,
DECL|enumerator|AF_EDGE_SERIF
name|AF_EDGE_SERIF
init|=
literal|1
operator|<<
literal|1
block|,
DECL|enumerator|AF_EDGE_DONE
name|AF_EDGE_DONE
init|=
literal|1
operator|<<
literal|2
block|}
DECL|typedef|AF_Edge_Flags
name|AF_Edge_Flags
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_Point
typedef|typedef
name|struct
name|AF_PointRec_
modifier|*
name|AF_Point
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_Segment
typedef|typedef
name|struct
name|AF_SegmentRec_
modifier|*
name|AF_Segment
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_Edge
typedef|typedef
name|struct
name|AF_EdgeRec_
modifier|*
name|AF_Edge
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_PointRec_
typedef|typedef
struct|struct
name|AF_PointRec_
block|{
DECL|member|flags
name|FT_UShort
name|flags
decl_stmt|;
comment|/* point flags used by hinter   */
DECL|member|in_dir
name|FT_Char
name|in_dir
decl_stmt|;
comment|/* direction of inwards vector  */
DECL|member|out_dir
name|FT_Char
name|out_dir
decl_stmt|;
comment|/* direction of outwards vector */
DECL|member|ox
DECL|member|oy
name|FT_Pos
name|ox
decl_stmt|,
name|oy
decl_stmt|;
comment|/* original, scaled position                   */
DECL|member|fx
DECL|member|fy
name|FT_Short
name|fx
decl_stmt|,
name|fy
decl_stmt|;
comment|/* original, unscaled position (font units)    */
DECL|member|x
DECL|member|y
name|FT_Pos
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* current position                            */
DECL|member|u
DECL|member|v
name|FT_Pos
name|u
decl_stmt|,
name|v
decl_stmt|;
comment|/* current (x,y) or (y,x) depending on context */
DECL|member|next
name|AF_Point
name|next
decl_stmt|;
comment|/* next point in contour     */
DECL|member|prev
name|AF_Point
name|prev
decl_stmt|;
comment|/* previous point in contour */
block|}
DECL|typedef|AF_PointRec
name|AF_PointRec
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_SegmentRec_
typedef|typedef
struct|struct
name|AF_SegmentRec_
block|{
DECL|member|flags
name|FT_Byte
name|flags
decl_stmt|;
comment|/* edge/segment flags for this segment */
DECL|member|dir
name|FT_Char
name|dir
decl_stmt|;
comment|/* segment direction                   */
DECL|member|pos
name|FT_Short
name|pos
decl_stmt|;
comment|/* position of segment                 */
DECL|member|min_coord
name|FT_Short
name|min_coord
decl_stmt|;
comment|/* minimum coordinate of segment       */
DECL|member|max_coord
name|FT_Short
name|max_coord
decl_stmt|;
comment|/* maximum coordinate of segment       */
DECL|member|height
name|FT_Short
name|height
decl_stmt|;
comment|/* the hinted segment height           */
DECL|member|edge
name|AF_Edge
name|edge
decl_stmt|;
comment|/* the segment's parent edge           */
DECL|member|edge_next
name|AF_Segment
name|edge_next
decl_stmt|;
comment|/* link to next segment in parent edge */
DECL|member|link
name|AF_Segment
name|link
decl_stmt|;
comment|/* (stem) link segment        */
DECL|member|serif
name|AF_Segment
name|serif
decl_stmt|;
comment|/* primary segment for serifs */
DECL|member|num_linked
name|FT_Pos
name|num_linked
decl_stmt|;
comment|/* number of linked segments  */
DECL|member|score
name|FT_Pos
name|score
decl_stmt|;
comment|/* used during stem matching  */
DECL|member|len
name|FT_Pos
name|len
decl_stmt|;
comment|/* used during stem matching  */
DECL|member|first
name|AF_Point
name|first
decl_stmt|;
comment|/* first point in edge segment             */
DECL|member|last
name|AF_Point
name|last
decl_stmt|;
comment|/* last point in edge segment              */
DECL|member|contour
name|AF_Point
modifier|*
name|contour
decl_stmt|;
comment|/* ptr to first point of segment's contour */
block|}
DECL|typedef|AF_SegmentRec
name|AF_SegmentRec
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_EdgeRec_
typedef|typedef
struct|struct
name|AF_EdgeRec_
block|{
DECL|member|fpos
name|FT_Short
name|fpos
decl_stmt|;
comment|/* original, unscaled position (font units) */
DECL|member|opos
name|FT_Pos
name|opos
decl_stmt|;
comment|/* original, scaled position                */
DECL|member|pos
name|FT_Pos
name|pos
decl_stmt|;
comment|/* current position                         */
DECL|member|flags
name|FT_Byte
name|flags
decl_stmt|;
comment|/* edge flags                                   */
DECL|member|dir
name|FT_Char
name|dir
decl_stmt|;
comment|/* edge direction                               */
DECL|member|scale
name|FT_Fixed
name|scale
decl_stmt|;
comment|/* used to speed up interpolation between edges */
DECL|member|blue_edge
name|AF_Width
name|blue_edge
decl_stmt|;
comment|/* non-NULL if this is a blue edge              */
DECL|member|link
name|AF_Edge
name|link
decl_stmt|;
DECL|member|serif
name|AF_Edge
name|serif
decl_stmt|;
DECL|member|num_linked
name|FT_Short
name|num_linked
decl_stmt|;
DECL|member|score
name|FT_Int
name|score
decl_stmt|;
DECL|member|first
name|AF_Segment
name|first
decl_stmt|;
DECL|member|last
name|AF_Segment
name|last
decl_stmt|;
block|}
DECL|typedef|AF_EdgeRec
name|AF_EdgeRec
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_AxisHintsRec_
typedef|typedef
struct|struct
name|AF_AxisHintsRec_
block|{
DECL|member|num_segments
name|FT_Int
name|num_segments
decl_stmt|;
DECL|member|max_segments
name|FT_Int
name|max_segments
decl_stmt|;
DECL|member|segments
name|AF_Segment
name|segments
decl_stmt|;
ifdef|#
directive|ifdef
name|AF_SORT_SEGMENTS
DECL|member|mid_segments
name|FT_Int
name|mid_segments
decl_stmt|;
endif|#
directive|endif
DECL|member|num_edges
name|FT_Int
name|num_edges
decl_stmt|;
DECL|member|max_edges
name|FT_Int
name|max_edges
decl_stmt|;
DECL|member|edges
name|AF_Edge
name|edges
decl_stmt|;
DECL|member|major_dir
name|AF_Direction
name|major_dir
decl_stmt|;
block|}
DECL|typedef|AF_AxisHintsRec
DECL|typedef|AF_AxisHints
name|AF_AxisHintsRec
operator|,
typedef|*
name|AF_AxisHints
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_GlyphHintsRec_
typedef|typedef
struct|struct
name|AF_GlyphHintsRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|x_scale
name|FT_Fixed
name|x_scale
decl_stmt|;
DECL|member|x_delta
name|FT_Pos
name|x_delta
decl_stmt|;
DECL|member|y_scale
name|FT_Fixed
name|y_scale
decl_stmt|;
DECL|member|y_delta
name|FT_Pos
name|y_delta
decl_stmt|;
DECL|member|edge_distance_threshold
name|FT_Pos
name|edge_distance_threshold
decl_stmt|;
DECL|member|max_points
name|FT_Int
name|max_points
decl_stmt|;
DECL|member|num_points
name|FT_Int
name|num_points
decl_stmt|;
DECL|member|points
name|AF_Point
name|points
decl_stmt|;
DECL|member|max_contours
name|FT_Int
name|max_contours
decl_stmt|;
DECL|member|num_contours
name|FT_Int
name|num_contours
decl_stmt|;
DECL|member|contours
name|AF_Point
modifier|*
name|contours
decl_stmt|;
DECL|member|axis
name|AF_AxisHintsRec
name|axis
index|[
name|AF_DIMENSION_MAX
index|]
decl_stmt|;
DECL|member|scaler_flags
name|FT_UInt32
name|scaler_flags
decl_stmt|;
comment|/* copy of scaler flags     */
DECL|member|other_flags
name|FT_UInt32
name|other_flags
decl_stmt|;
comment|/* free for script-specific */
comment|/* implementations          */
DECL|member|metrics
name|AF_ScriptMetrics
name|metrics
decl_stmt|;
DECL|member|xmin_delta
name|FT_Pos
name|xmin_delta
decl_stmt|;
comment|/* used for warping */
DECL|member|xmax_delta
name|FT_Pos
name|xmax_delta
decl_stmt|;
block|}
DECL|typedef|AF_GlyphHintsRec
name|AF_GlyphHintsRec
typedef|;
end_typedef
begin_define
DECL|macro|AF_HINTS_TEST_SCALER
define|#
directive|define
name|AF_HINTS_TEST_SCALER
parameter_list|(
name|h
parameter_list|,
name|f
parameter_list|)
value|( (h)->scaler_flags& (f) )
end_define
begin_define
DECL|macro|AF_HINTS_TEST_OTHER
define|#
directive|define
name|AF_HINTS_TEST_OTHER
parameter_list|(
name|h
parameter_list|,
name|f
parameter_list|)
value|( (h)->other_flags& (f) )
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|AF_DEBUG
end_ifdef
begin_define
DECL|macro|AF_HINTS_DO_HORIZONTAL
define|#
directive|define
name|AF_HINTS_DO_HORIZONTAL
parameter_list|(
name|h
parameter_list|)
define|\
value|( !_af_debug_disable_horz_hints&& \             !AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_HORIZONTAL ) )
end_define
begin_define
DECL|macro|AF_HINTS_DO_VERTICAL
define|#
directive|define
name|AF_HINTS_DO_VERTICAL
parameter_list|(
name|h
parameter_list|)
define|\
value|( !_af_debug_disable_vert_hints&& \             !AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_VERTICAL ) )
end_define
begin_define
DECL|macro|AF_HINTS_DO_ADVANCE
define|#
directive|define
name|AF_HINTS_DO_ADVANCE
parameter_list|(
name|h
parameter_list|)
define|\
value|!AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_ADVANCE )
end_define
begin_define
DECL|macro|AF_HINTS_DO_BLUES
define|#
directive|define
name|AF_HINTS_DO_BLUES
parameter_list|(
name|h
parameter_list|)
value|( !_af_debug_disable_blue_hints )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !AF_DEBUG */
end_comment
begin_define
DECL|macro|AF_HINTS_DO_HORIZONTAL
define|#
directive|define
name|AF_HINTS_DO_HORIZONTAL
parameter_list|(
name|h
parameter_list|)
define|\
value|!AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_HORIZONTAL )
end_define
begin_define
DECL|macro|AF_HINTS_DO_VERTICAL
define|#
directive|define
name|AF_HINTS_DO_VERTICAL
parameter_list|(
name|h
parameter_list|)
define|\
value|!AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_VERTICAL )
end_define
begin_define
DECL|macro|AF_HINTS_DO_ADVANCE
define|#
directive|define
name|AF_HINTS_DO_ADVANCE
parameter_list|(
name|h
parameter_list|)
define|\
value|!AF_HINTS_TEST_SCALER( h, AF_SCALER_FLAG_NO_ADVANCE )
end_define
begin_define
DECL|macro|AF_HINTS_DO_BLUES
define|#
directive|define
name|AF_HINTS_DO_BLUES
parameter_list|(
name|h
parameter_list|)
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !AF_DEBUG */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|AF_Direction
argument_list|)
end_macro
begin_macro
name|af_direction_compute
argument_list|(
argument|FT_Pos  dx
argument_list|,
argument|FT_Pos  dy
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|af_axis_hints_new_segment
name|af_axis_hints_new_segment
argument_list|(
argument|AF_AxisHints  axis
argument_list|,
argument|FT_Memory     memory
argument_list|,
argument|AF_Segment   *asegment
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_axis_hints_new_edge
argument_list|(
argument|AF_AxisHints  axis
argument_list|,
argument|FT_Int        fpos
argument_list|,
argument|AF_Direction  dir
argument_list|,
argument|FT_Memory     memory
argument_list|,
argument|AF_Edge      *edge
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|af_glyph_hints_init
name|af_glyph_hints_init
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|FT_Memory      memory
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  recompute all AF_Point in a AF_GlyphHints from the definitions    *  in a source outline    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_rescale
argument_list|(
argument|AF_GlyphHints     hints
argument_list|,
argument|AF_ScriptMetrics  metrics
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_reload
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|FT_Outline*    outline
argument_list|,
argument|FT_Bool        get_inflections
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|af_glyph_hints_save
name|af_glyph_hints_save
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|FT_Outline*    outline
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_align_edge_points
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_align_strong_points
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_align_weak_points
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|AF_USE_WARPER
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_scale_dim
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|,
argument|FT_Fixed       scale
argument_list|,
argument|FT_Pos         delta
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|hints
name|af_glyph_hints_done
argument_list|(
argument|AF_GlyphHints  hints
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|hints
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|AF_SEGMENT_LEN
define|#
directive|define
name|AF_SEGMENT_LEN
parameter_list|(
name|seg
parameter_list|)
value|( (seg)->max_coord - (seg)->min_coord )
end_define
begin_define
DECL|macro|AF_SEGMENT_DIST
define|#
directive|define
name|AF_SEGMENT_DIST
parameter_list|(
name|seg1
parameter_list|,
name|seg2
parameter_list|)
value|( ( (seg1)->pos> (seg2)->pos )   \                                            ? (seg1)->pos - (seg2)->pos   \                                            : (seg2)->pos - (seg1)->pos )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFHINTS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
