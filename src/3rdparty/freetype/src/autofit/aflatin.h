begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  aflatin.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines for latin script (specification).       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2006, 2007, 2009 by                        */
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
name|__AFLATIN_H__
end_ifndef
begin_define
DECL|macro|__AFLATIN_H__
define|#
directive|define
name|__AFLATIN_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/* the latin-specific script class */
DECL|function|AF_DECLARE_SCRIPT_CLASS
name|AF_DECLARE_SCRIPT_CLASS
argument_list|(
name|af_latin_script_class
argument_list|)
comment|/* constants are given with units_per_em == 2048 in mind */
DECL|macro|AF_LATIN_CONSTANT
define|#
directive|define
name|AF_LATIN_CONSTANT
parameter_list|(
name|metrics
parameter_list|,
name|c
parameter_list|)
define|\
value|( ( (c) * (FT_Long)( (AF_LatinMetrics)(metrics) )->units_per_em ) / 2048 )
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*****                                                               *****/
comment|/*****            L A T I N   G L O B A L   M E T R I C S            *****/
comment|/*****                                                               *****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*    *  The following declarations could be embedded in the file `aflatin.c';    *  they have been made semi-public to allow alternate script hinters to    *  re-use some of them.    */
comment|/* Latin (global) metrics management */
decl|enum
block|{
name|AF_LATIN_BLUE_CAPITAL_TOP
operator|,
name|AF_LATIN_BLUE_CAPITAL_BOTTOM
operator|,
name|AF_LATIN_BLUE_SMALL_F_TOP
operator|,
name|AF_LATIN_BLUE_SMALL_TOP
operator|,
name|AF_LATIN_BLUE_SMALL_BOTTOM
operator|,
name|AF_LATIN_BLUE_SMALL_MINOR
operator|,
name|AF_LATIN_BLUE_MAX
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|AF_LATIN_IS_TOP_BLUE
define|#
directive|define
name|AF_LATIN_IS_TOP_BLUE
parameter_list|(
name|b
parameter_list|)
value|( (b) == AF_LATIN_BLUE_CAPITAL_TOP || \                                      (b) == AF_LATIN_BLUE_SMALL_F_TOP || \                                      (b) == AF_LATIN_BLUE_SMALL_TOP   )
end_define
begin_define
DECL|macro|AF_LATIN_MAX_WIDTHS
define|#
directive|define
name|AF_LATIN_MAX_WIDTHS
value|16
end_define
begin_define
DECL|macro|AF_LATIN_MAX_BLUES
define|#
directive|define
name|AF_LATIN_MAX_BLUES
value|AF_LATIN_BLUE_MAX
end_define
begin_enum
enum|enum
block|{
DECL|enumerator|AF_LATIN_BLUE_ACTIVE
name|AF_LATIN_BLUE_ACTIVE
init|=
literal|1
operator|<<
literal|0
block|,
DECL|enumerator|AF_LATIN_BLUE_TOP
name|AF_LATIN_BLUE_TOP
init|=
literal|1
operator|<<
literal|1
block|,
DECL|enumerator|AF_LATIN_BLUE_ADJUSTMENT
name|AF_LATIN_BLUE_ADJUSTMENT
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* used for scale adjustment */
comment|/* optimization              */
DECL|enumerator|AF_LATIN_BLUE_FLAG_MAX
name|AF_LATIN_BLUE_FLAG_MAX
block|}
enum|;
end_enum
begin_typedef
DECL|struct|AF_LatinBlueRec_
typedef|typedef
struct|struct
name|AF_LatinBlueRec_
block|{
DECL|member|ref
name|AF_WidthRec
name|ref
decl_stmt|;
DECL|member|shoot
name|AF_WidthRec
name|shoot
decl_stmt|;
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
block|}
DECL|typedef|AF_LatinBlueRec
DECL|typedef|AF_LatinBlue
name|AF_LatinBlueRec
operator|,
typedef|*
name|AF_LatinBlue
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_LatinAxisRec_
typedef|typedef
struct|struct
name|AF_LatinAxisRec_
block|{
DECL|member|scale
name|FT_Fixed
name|scale
decl_stmt|;
DECL|member|delta
name|FT_Pos
name|delta
decl_stmt|;
DECL|member|width_count
name|FT_UInt
name|width_count
decl_stmt|;
DECL|member|widths
name|AF_WidthRec
name|widths
index|[
name|AF_LATIN_MAX_WIDTHS
index|]
decl_stmt|;
DECL|member|edge_distance_threshold
name|FT_Pos
name|edge_distance_threshold
decl_stmt|;
DECL|member|standard_width
name|FT_Pos
name|standard_width
decl_stmt|;
DECL|member|extra_light
name|FT_Bool
name|extra_light
decl_stmt|;
comment|/* ignored for horizontal metrics */
DECL|member|control_overshoot
name|FT_Bool
name|control_overshoot
decl_stmt|;
DECL|member|blue_count
name|FT_UInt
name|blue_count
decl_stmt|;
DECL|member|blues
name|AF_LatinBlueRec
name|blues
index|[
name|AF_LATIN_BLUE_MAX
index|]
decl_stmt|;
DECL|member|org_scale
name|FT_Fixed
name|org_scale
decl_stmt|;
DECL|member|org_delta
name|FT_Pos
name|org_delta
decl_stmt|;
block|}
DECL|typedef|AF_LatinAxisRec
DECL|typedef|AF_LatinAxis
name|AF_LatinAxisRec
operator|,
typedef|*
name|AF_LatinAxis
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_LatinMetricsRec_
typedef|typedef
struct|struct
name|AF_LatinMetricsRec_
block|{
DECL|member|root
name|AF_ScriptMetricsRec
name|root
decl_stmt|;
DECL|member|units_per_em
name|FT_UInt
name|units_per_em
decl_stmt|;
DECL|member|axis
name|AF_LatinAxisRec
name|axis
index|[
name|AF_DIMENSION_MAX
index|]
decl_stmt|;
block|}
DECL|typedef|AF_LatinMetricsRec
DECL|typedef|AF_LatinMetrics
name|AF_LatinMetricsRec
operator|,
typedef|*
name|AF_LatinMetrics
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_latin_metrics_init
argument_list|(
argument|AF_LatinMetrics  metrics
argument_list|,
argument|FT_Face          face
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
DECL|variable|af_latin_metrics_scale
name|af_latin_metrics_scale
argument_list|(
argument|AF_LatinMetrics  metrics
argument_list|,
argument|AF_Scaler        scaler
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
name|af_latin_metrics_init_widths
argument_list|(
argument|AF_LatinMetrics  metrics
argument_list|,
argument|FT_Face          face
argument_list|,
argument|FT_ULong         charcode
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
name|af_latin_metrics_check_digits
argument_list|(
argument|AF_LatinMetrics  metrics
argument_list|,
argument|FT_Face          face
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****           L A T I N   G L Y P H   A N A L Y S I S             *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_enum
enum|enum
block|{
DECL|enumerator|AF_LATIN_HINTS_HORZ_SNAP
name|AF_LATIN_HINTS_HORZ_SNAP
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* enable stem width snapping  */
DECL|enumerator|AF_LATIN_HINTS_VERT_SNAP
name|AF_LATIN_HINTS_VERT_SNAP
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* enable stem height snapping */
DECL|enumerator|AF_LATIN_HINTS_STEM_ADJUST
name|AF_LATIN_HINTS_STEM_ADJUST
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* enable stem width/height    */
comment|/* adjustment                  */
DECL|enumerator|AF_LATIN_HINTS_MONO
name|AF_LATIN_HINTS_MONO
init|=
literal|1
operator|<<
literal|3
comment|/* indicate monochrome         */
comment|/* rendering                   */
block|}
enum|;
end_enum
begin_define
DECL|macro|AF_LATIN_HINTS_DO_HORZ_SNAP
define|#
directive|define
name|AF_LATIN_HINTS_DO_HORZ_SNAP
parameter_list|(
name|h
parameter_list|)
define|\
value|AF_HINTS_TEST_OTHER( h, AF_LATIN_HINTS_HORZ_SNAP )
end_define
begin_define
DECL|macro|AF_LATIN_HINTS_DO_VERT_SNAP
define|#
directive|define
name|AF_LATIN_HINTS_DO_VERT_SNAP
parameter_list|(
name|h
parameter_list|)
define|\
value|AF_HINTS_TEST_OTHER( h, AF_LATIN_HINTS_VERT_SNAP )
end_define
begin_define
DECL|macro|AF_LATIN_HINTS_DO_STEM_ADJUST
define|#
directive|define
name|AF_LATIN_HINTS_DO_STEM_ADJUST
parameter_list|(
name|h
parameter_list|)
define|\
value|AF_HINTS_TEST_OTHER( h, AF_LATIN_HINTS_STEM_ADJUST )
end_define
begin_define
DECL|macro|AF_LATIN_HINTS_DO_MONO
define|#
directive|define
name|AF_LATIN_HINTS_DO_MONO
parameter_list|(
name|h
parameter_list|)
define|\
value|AF_HINTS_TEST_OTHER( h, AF_LATIN_HINTS_MONO )
end_define
begin_comment
comment|/*    *  This shouldn't normally be exported.  However, other scripts might    *  like to use this function as-is.    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_latin_hints_compute_segments
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  This shouldn't normally be exported.  However, other scripts might    *  want to use this function as-is.    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|af_latin_hints_link_segments
name|af_latin_hints_link_segments
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*    *  This shouldn't normally be exported.  However, other scripts might    *  want to use this function as-is.    */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_latin_hints_compute_edges
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|af_latin_hints_detect_features
name|af_latin_hints_detect_features
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
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
comment|/* __AFLATIN_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
