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
comment|/*  Copyright 2003-2008, 2010-2012, 2014 by                                */
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
comment|/*    *  The definition of outline glyph hints.  These are shared by all    *  writing system analysis routines (until now).    */
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
comment|/*    *  The following explanations are mostly taken from the article    *    *    Real-Time Grid Fitting of Typographic Outlines    *    *  by David Turner and Werner Lemberg    *    *    http://www.tug.org/TUGboat/Articles/tb24-3/lemberg.pdf    *    *  with appropriate updates.    *    *    *  Segments    *    *    `af_{cjk,latin,...}_hints_compute_segments' are the functions to    *    find segments in an outline.    *    *    A segment is a series of at least two consecutive points that are    *    approximately aligned along a coordinate axis.  The analysis to do    *    so is specific to a writing system.    *    *    *  Edges    *    *    `af_{cjk,latin,...}_hints_compute_edges' are the functions to find    *    edges.    *    *    As soon as segments are defined, the auto-hinter groups them into    *    edges.  An edge corresponds to a single position on the main    *    dimension that collects one or more segments (allowing for a small    *    threshold).    *    *    As an example, the `latin' writing system first tries to grid-fit    *    edges, then to align segments on the edges unless it detects that    *    they form a serif.    *    *    *                      A          H    *                       |        |    *                       |        |    *                       |        |    *                       |        |    *         C             |        |             F    *          +------<-----+        +-----<------+    *          |             B      G             |    *          |                                  |    *          |                                  |    *          +--------------->------------------+    *         D                                    E    *    *    *  Stems    *    *    Stems are detected by `af_{cjk,latin,...}_hint_edges'.    *    *    Segments need to be `linked' to other ones in order to detect stems.    *    A stem is made of two segments that face each other in opposite    *    directions and that are sufficiently close to each other.  Using    *    vocabulary from the TrueType specification, stem segments form a    *    `black distance'.    *    *    In the above ASCII drawing, the horizontal segments are BC, DE, and    *    FG; the vertical segments are AB, CD, EF, and GH.    *    *    Each segment has at most one `best' candidate to form a black    *    distance, or no candidate at all.  Notice that two distinct segments    *    can have the same candidate, which frequently means a serif.    *    *    A stem is recognized by the following condition:    *    *      best segment_1 = segment_2&& best segment_2 = segment_1    *    *    The best candidate is stored in field `link' in structure    *    `AF_Segment'.    *    *    In the above ASCII drawing, the best candidate for both AB and CD is    *    GH, while the best candidate for GH is AB.  Similarly, the best    *    candidate for EF and GH is AB, while the best candidate for AB is    *    GH.    *    *    The detection and handling of stems is dependent on the writing    *    system.    *    *    *  Serifs    *    *    Serifs are detected by `af_{cjk,latin,...}_hint_edges'.    *    *    In comparison to a stem, a serif (as handled by the auto-hinter    *    module that takes care of the `latin' writing system) has    *    *      best segment_1 = segment_2&& best segment_2 != segment_1    *    *    where segment_1 corresponds to the serif segment (CD and EF in the    *    above ASCII drawing).    *    *    The best candidate is stored in field `serif' in structure    *    `AF_Segment' (and `link' is set to NULL).    *    *    *  Touched points    *    *    A point is called `touched' if it has been processed somehow by the    *    auto-hinter.  It basically means that it shouldn't be moved again    *    (or moved only under certain constraints to preserve the already    *    applied processing).    *    *    *  Flat and round segments    *    *    Segments are `round' or `flat', depending on the series of points    *    that define them.  A segment is round if the next and previous point    *    of an extremum (which can be either a single point or sequence of    *    points) are both conic or cubic control points.  Otherwise, a    *    segment with an extremum is flat.    *    *    *  Strong Points    *    *    Experience has shown that points not part of an edge need to be    *    interpolated linearly between their two closest edges, even if these    *    are not part of the contour of those particular points.  Typical    *    candidates for this are    *    *    - angle points (i.e., points where the `in' and `out' direction    *      differ greatly)    *    *    - inflection points (i.e., where the `in' and `out' angles are the    *      same, but the curvature changes sign) [currently, such points    *      aren't handled specially in the auto-hinter]    *    *    `af_glyph_hints_align_strong_points' is the function that takes    *    care of such situations; it is equivalent to the TrueType `IP'    *    hinting instruction.    *    *    *  Weak Points    *    *    Other points in the outline must be interpolated using the    *    coordinates of their previous and next unfitted contour neighbours.    *    These are called `weak points' and are touched by the function    *    `af_glyph_hints_align_weak_points', equivalent to the TrueType `IUP'    *    hinting instruction.  Typical candidates are control points and    *    points on the contour without a major direction.    *    *    The major effect is to reduce possible distortion caused by    *    alignment of edges and strong points, thus weak points are processed    *    after strong points.    */
end_comment
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
comment|/* point touch flags */
DECL|enumerator|AF_FLAG_TOUCH_X
name|AF_FLAG_TOUCH_X
init|=
literal|1
operator|<<
literal|2
block|,
DECL|enumerator|AF_FLAG_TOUCH_Y
name|AF_FLAG_TOUCH_Y
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* candidates for weak interpolation have this flag set */
DECL|enumerator|AF_FLAG_WEAK_INTERPOLATION
name|AF_FLAG_WEAK_INTERPOLATION
init|=
literal|1
operator|<<
literal|4
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
block|,
DECL|enumerator|AF_EDGE_NEUTRAL
name|AF_EDGE_NEUTRAL
init|=
literal|1
operator|<<
literal|3
comment|/* set if edge aligns to a neutral blue zone */
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
comment|/* original, unscaled position (in font units) */
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
comment|/* first point in edge segment */
DECL|member|last
name|AF_Point
name|last
decl_stmt|;
comment|/* last point in edge segment  */
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
comment|/* original, unscaled position (in font units) */
DECL|member|opos
name|FT_Pos
name|opos
decl_stmt|;
comment|/* original, scaled position                   */
DECL|member|pos
name|FT_Pos
name|pos
decl_stmt|;
comment|/* current position                            */
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
comment|/* non-NULL if this is a blue edge */
DECL|member|link
name|AF_Edge
name|link
decl_stmt|;
comment|/* link edge                       */
DECL|member|serif
name|AF_Edge
name|serif
decl_stmt|;
comment|/* primary edge for serifs         */
DECL|member|num_linked
name|FT_Short
name|num_linked
decl_stmt|;
comment|/* number of linked edges          */
DECL|member|score
name|FT_Int
name|score
decl_stmt|;
comment|/* used during stem matching       */
DECL|member|first
name|AF_Segment
name|first
decl_stmt|;
comment|/* first segment in edge */
DECL|member|last
name|AF_Segment
name|last
decl_stmt|;
comment|/* last segment in edge  */
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
comment|/* number of used segments      */
DECL|member|max_segments
name|FT_Int
name|max_segments
decl_stmt|;
comment|/* number of allocated segments */
DECL|member|segments
name|AF_Segment
name|segments
decl_stmt|;
comment|/* segments array               */
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
comment|/* number of used edges      */
DECL|member|max_edges
name|FT_Int
name|max_edges
decl_stmt|;
comment|/* number of allocated edges */
DECL|member|edges
name|AF_Edge
name|edges
decl_stmt|;
comment|/* edges array               */
DECL|member|major_dir
name|AF_Direction
name|major_dir
decl_stmt|;
comment|/* either vertical or horizontal */
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
DECL|member|max_points
name|FT_Int
name|max_points
decl_stmt|;
comment|/* number of allocated points */
DECL|member|num_points
name|FT_Int
name|num_points
decl_stmt|;
comment|/* number of used points      */
DECL|member|points
name|AF_Point
name|points
decl_stmt|;
comment|/* points array               */
DECL|member|max_contours
name|FT_Int
name|max_contours
decl_stmt|;
comment|/* number of allocated contours */
DECL|member|num_contours
name|FT_Int
name|num_contours
decl_stmt|;
comment|/* number of used contours      */
DECL|member|contours
name|AF_Point
modifier|*
name|contours
decl_stmt|;
comment|/* contours array               */
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
comment|/* copy of scaler flags    */
DECL|member|other_flags
name|FT_UInt32
name|other_flags
decl_stmt|;
comment|/* free for style-specific */
comment|/* implementations         */
DECL|member|metrics
name|AF_StyleMetrics
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
name|FT_DEBUG_AUTOFIT
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
comment|/* !FT_DEBUG_AUTOFIT */
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
comment|/* !FT_DEBUG_AUTOFIT */
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
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_glyph_hints_rescale
argument_list|(
argument|AF_GlyphHints    hints
argument_list|,
argument|AF_StyleMetrics  metrics
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
name|AF_CONFIG_OPTION_USE_WARPER
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
