begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afcjk.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines for CJK writing system (specification). */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006, 2007, 2011-2014 by                                     */
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
name|__AFCJK_H__
end_ifndef
begin_define
DECL|macro|__AFCJK_H__
define|#
directive|define
name|__AFCJK_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_include
include|#
directive|include
file|"aflatin.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/* the CJK-specific writing system */
DECL|function|AF_DECLARE_WRITING_SYSTEM_CLASS
name|AF_DECLARE_WRITING_SYSTEM_CLASS
argument_list|(
name|af_cjk_writing_system_class
argument_list|)
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*****                                                               *****/
comment|/*****              C J K   G L O B A L   M E T R I C S              *****/
comment|/*****                                                               *****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*    *  CJK glyphs tend to fill the square.  So we have both vertical and    *  horizontal blue zones.  But some glyphs have flat bounding strokes that    *  leave some space between neighbour glyphs.    */
DECL|macro|AF_CJK_IS_TOP_BLUE
define|#
directive|define
name|AF_CJK_IS_TOP_BLUE
parameter_list|(
name|b
parameter_list|)
define|\
value|( (b)->properties& AF_BLUE_PROPERTY_CJK_TOP )
DECL|macro|AF_CJK_IS_HORIZ_BLUE
define|#
directive|define
name|AF_CJK_IS_HORIZ_BLUE
parameter_list|(
name|b
parameter_list|)
define|\
value|( (b)->properties& AF_BLUE_PROPERTY_CJK_HORIZ )
DECL|macro|AF_CJK_IS_RIGHT_BLUE
define|#
directive|define
name|AF_CJK_IS_RIGHT_BLUE
value|AF_CJK_IS_TOP_BLUE
DECL|macro|AF_CJK_MAX_WIDTHS
define|#
directive|define
name|AF_CJK_MAX_WIDTHS
value|16
decl|enum
block|{
name|AF_CJK_BLUE_ACTIVE
operator|=
literal|1
operator|<<
literal|0
operator|,
comment|/* set if zone height is<= 3/4px */
name|AF_CJK_BLUE_TOP
operator|=
literal|1
operator|<<
literal|1
operator|,
comment|/* result of AF_CJK_IS_TOP_BLUE   */
name|AF_CJK_BLUE_ADJUSTMENT
operator|=
literal|1
operator|<<
literal|2
operator|,
comment|/* used for scale adjustment      */
comment|/* optimization                   */
name|AF_CJK_BLUE_FLAG_MAX
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|struct|AF_CJKBlueRec_
typedef|typedef
struct|struct
name|AF_CJKBlueRec_
block|{
DECL|member|ref
name|AF_WidthRec
name|ref
decl_stmt|;
DECL|member|shoot
name|AF_WidthRec
name|shoot
decl_stmt|;
comment|/* undershoot */
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
block|}
DECL|typedef|AF_CJKBlueRec
DECL|typedef|AF_CJKBlue
name|AF_CJKBlueRec
operator|,
typedef|*
name|AF_CJKBlue
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_CJKAxisRec_
typedef|typedef
struct|struct
name|AF_CJKAxisRec_
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
comment|/* number of used widths */
DECL|member|widths
name|AF_WidthRec
name|widths
index|[
name|AF_CJK_MAX_WIDTHS
index|]
decl_stmt|;
comment|/* widths array          */
DECL|member|edge_distance_threshold
name|FT_Pos
name|edge_distance_threshold
decl_stmt|;
comment|/* used for creating edges */
DECL|member|standard_width
name|FT_Pos
name|standard_width
decl_stmt|;
comment|/* the default stem thickness */
DECL|member|extra_light
name|FT_Bool
name|extra_light
decl_stmt|;
comment|/* is standard width very light? */
comment|/* used for horizontal metrics too for CJK */
DECL|member|control_overshoot
name|FT_Bool
name|control_overshoot
decl_stmt|;
DECL|member|blue_count
name|FT_UInt
name|blue_count
decl_stmt|;
DECL|member|blues
name|AF_CJKBlueRec
name|blues
index|[
name|AF_BLUE_STRINGSET_MAX
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
DECL|typedef|AF_CJKAxisRec
DECL|typedef|AF_CJKAxis
name|AF_CJKAxisRec
operator|,
typedef|*
name|AF_CJKAxis
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_CJKMetricsRec_
typedef|typedef
struct|struct
name|AF_CJKMetricsRec_
block|{
DECL|member|root
name|AF_StyleMetricsRec
name|root
decl_stmt|;
DECL|member|units_per_em
name|FT_UInt
name|units_per_em
decl_stmt|;
DECL|member|axis
name|AF_CJKAxisRec
name|axis
index|[
name|AF_DIMENSION_MAX
index|]
decl_stmt|;
block|}
DECL|typedef|AF_CJKMetricsRec
DECL|typedef|AF_CJKMetrics
name|AF_CJKMetricsRec
operator|,
typedef|*
name|AF_CJKMetrics
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_CJK
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_cjk_metrics_init
argument_list|(
argument|AF_CJKMetrics  metrics
argument_list|,
argument|FT_Face        face
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
DECL|variable|af_cjk_metrics_scale
name|af_cjk_metrics_scale
argument_list|(
argument|AF_CJKMetrics  metrics
argument_list|,
argument|AF_Scaler      scaler
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
name|af_cjk_hints_init
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_CJKMetrics  metrics
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
DECL|variable|af_cjk_hints_apply
name|af_cjk_hints_apply
argument_list|(
argument|AF_GlyphHints  hints
argument_list|,
argument|FT_Outline*    outline
argument_list|,
argument|AF_CJKMetrics  metrics
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* shared; called from afindic.c */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_cjk_metrics_check_digits
argument_list|(
argument|AF_CJKMetrics  metrics
argument_list|,
argument|FT_Face        face
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
name|af_cjk_metrics_init_widths
argument_list|(
argument|AF_CJKMetrics  metrics
argument_list|,
argument|FT_Face        face
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
comment|/* AF_CONFIG_OPTION_CJK */
end_comment
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
comment|/* __AFCJK_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
