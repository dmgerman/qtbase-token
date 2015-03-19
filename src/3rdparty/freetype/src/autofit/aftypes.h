begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  aftypes.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter types (specification only).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003-2009, 2011-2014 by                                      */
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
begin_comment
comment|/*************************************************************************    *    *  The auto-fitter is a complete rewrite of the old auto-hinter.    *  Its main feature is the ability to differentiate between different    *  writing systems and scripts in order to apply specific rules.    *    *  The code has also been compartmentized into several entities that    *  should make algorithmic experimentation easier than with the old    *  code.    *    *************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__AFTYPES_H__
end_ifndef
begin_define
DECL|macro|__AFTYPES_H__
define|#
directive|define
name|__AFTYPES_H__
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
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
file|"afblue.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*****                                                               *****/
comment|/*****                    D E B U G G I N G                          *****/
comment|/*****                                                               *****/
comment|/*************************************************************************/
comment|/*************************************************************************/
ifdef|#
directive|ifdef
name|FT_DEBUG_AUTOFIT
include|#
directive|include
include|FT_CONFIG_STANDARD_LIBRARY_H
specifier|extern
name|int
name|_af_debug_disable_horz_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|int
name|_af_debug_disable_vert_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|int
name|_af_debug_disable_blue_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_af_debug_hints
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_DEBUG_AUTOFIT */
end_comment
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
comment|/*****                 U T I L I T Y   S T U F F                     *****/
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
begin_typedef
DECL|struct|AF_WidthRec_
typedef|typedef
struct|struct
name|AF_WidthRec_
block|{
DECL|member|org
name|FT_Pos
name|org
decl_stmt|;
comment|/* original position/width in font units              */
DECL|member|cur
name|FT_Pos
name|cur
decl_stmt|;
comment|/* current/scaled position/width in device sub-pixels */
DECL|member|fit
name|FT_Pos
name|fit
decl_stmt|;
comment|/* current/fitted position/width in device sub-pixels */
block|}
DECL|typedef|AF_WidthRec
DECL|typedef|AF_Width
name|AF_WidthRec
operator|,
typedef|*
name|AF_Width
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_sort_pos
argument_list|(
argument|FT_UInt  count
argument_list|,
argument|FT_Pos*  table
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
name|af_sort_and_quantize_widths
argument_list|(
argument|FT_UInt*  count
argument_list|,
argument|AF_Width  widths
argument_list|,
argument|FT_Pos    threshold
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
comment|/*****                   A N G L E   T Y P E S                       *****/
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
begin_comment
comment|/*    *  The auto-fitter doesn't need a very high angular accuracy;    *  this allows us to speed up some computations considerably with a    *  light Cordic algorithm (see afangles.c).    */
end_comment
begin_typedef
DECL|typedef|AF_Angle
typedef|typedef
name|FT_Int
name|AF_Angle
typedef|;
end_typedef
begin_define
DECL|macro|AF_ANGLE_PI
define|#
directive|define
name|AF_ANGLE_PI
value|256
end_define
begin_define
DECL|macro|AF_ANGLE_2PI
define|#
directive|define
name|AF_ANGLE_2PI
value|( AF_ANGLE_PI * 2 )
end_define
begin_define
DECL|macro|AF_ANGLE_PI2
define|#
directive|define
name|AF_ANGLE_PI2
value|( AF_ANGLE_PI / 2 )
end_define
begin_define
DECL|macro|AF_ANGLE_PI4
define|#
directive|define
name|AF_ANGLE_PI4
value|( AF_ANGLE_PI / 4 )
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/*    *  compute the angle of a given 2-D vector    */
end_comment
begin_comment
unit|FT_LOCAL( AF_Angle )   af_angle_atan( FT_Pos  dx,                  FT_Pos  dy );
comment|/*    *  compute `angle2 - angle1'; the result is always within    *  the range [-AF_ANGLE_PI .. AF_ANGLE_PI - 1]    */
end_comment
begin_endif
unit|FT_LOCAL( AF_Angle )   af_angle_diff( AF_Angle  angle1,                  AF_Angle  angle2 );
endif|#
directive|endif
end_endif
begin_comment
comment|/* 0 */
end_comment
begin_define
DECL|macro|AF_ANGLE_DIFF
define|#
directive|define
name|AF_ANGLE_DIFF
parameter_list|(
name|result
parameter_list|,
name|angle1
parameter_list|,
name|angle2
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                \     AF_Angle  _delta = (angle2) - (angle1);     \                                                 \                                                 \     _delta %= AF_ANGLE_2PI;                     \     if ( _delta< 0 )                           \       _delta += AF_ANGLE_2PI;                   \                                                 \     if ( _delta> AF_ANGLE_PI )                 \       _delta -= AF_ANGLE_2PI;                   \                                                 \     result = _delta;                            \   FT_END_STMNT
end_define
begin_comment
comment|/*  opaque handle to glyph-specific hints -- see `afhints.h' for more    *  details    */
end_comment
begin_typedef
DECL|typedef|AF_GlyphHints
typedef|typedef
name|struct
name|AF_GlyphHintsRec_
modifier|*
name|AF_GlyphHints
typedef|;
end_typedef
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
comment|/*****                       S C A L E R S                           *****/
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
begin_comment
comment|/*    *  A scaler models the target pixel device that will receive the    *  auto-hinted glyph image.    */
end_comment
begin_typedef
DECL|enum|AF_ScalerFlags_
typedef|typedef
enum|enum
name|AF_ScalerFlags_
block|{
DECL|enumerator|AF_SCALER_FLAG_NO_HORIZONTAL
name|AF_SCALER_FLAG_NO_HORIZONTAL
init|=
literal|1
block|,
comment|/* disable horizontal hinting */
DECL|enumerator|AF_SCALER_FLAG_NO_VERTICAL
name|AF_SCALER_FLAG_NO_VERTICAL
init|=
literal|2
block|,
comment|/* disable vertical hinting   */
DECL|enumerator|AF_SCALER_FLAG_NO_ADVANCE
name|AF_SCALER_FLAG_NO_ADVANCE
init|=
literal|4
comment|/* disable advance hinting    */
block|}
DECL|typedef|AF_ScalerFlags
name|AF_ScalerFlags
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_ScalerRec_
typedef|typedef
struct|struct
name|AF_ScalerRec_
block|{
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
comment|/* source font face                        */
DECL|member|x_scale
name|FT_Fixed
name|x_scale
decl_stmt|;
comment|/* from font units to 1/64th device pixels */
DECL|member|y_scale
name|FT_Fixed
name|y_scale
decl_stmt|;
comment|/* from font units to 1/64th device pixels */
DECL|member|x_delta
name|FT_Pos
name|x_delta
decl_stmt|;
comment|/* in 1/64th device pixels                 */
DECL|member|y_delta
name|FT_Pos
name|y_delta
decl_stmt|;
comment|/* in 1/64th device pixels                 */
DECL|member|render_mode
name|FT_Render_Mode
name|render_mode
decl_stmt|;
comment|/* monochrome, anti-aliased, LCD, etc.     */
DECL|member|flags
name|FT_UInt32
name|flags
decl_stmt|;
comment|/* additional control flags, see above     */
block|}
DECL|typedef|AF_ScalerRec
DECL|typedef|AF_Scaler
name|AF_ScalerRec
operator|,
typedef|*
name|AF_Scaler
typedef|;
end_typedef
begin_define
DECL|macro|AF_SCALER_EQUAL_SCALES
define|#
directive|define
name|AF_SCALER_EQUAL_SCALES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|( (a)->x_scale == (b)->x_scale&& \             (a)->y_scale == (b)->y_scale&& \             (a)->x_delta == (b)->x_delta&& \             (a)->y_delta == (b)->y_delta )
end_define
begin_typedef
DECL|typedef|AF_StyleMetrics
typedef|typedef
name|struct
name|AF_StyleMetricsRec_
modifier|*
name|AF_StyleMetrics
typedef|;
end_typedef
begin_comment
comment|/*  This function parses an FT_Face to compute global metrics for    *  a specific style.    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|AF_WritingSystem_InitMetricsFunc
modifier|*
name|AF_WritingSystem_InitMetricsFunc
function_decl|)
parameter_list|(
name|AF_StyleMetrics
name|metrics
parameter_list|,
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|AF_WritingSystem_ScaleMetricsFunc
modifier|*
name|AF_WritingSystem_ScaleMetricsFunc
function_decl|)
parameter_list|(
name|AF_StyleMetrics
name|metrics
parameter_list|,
name|AF_Scaler
name|scaler
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|AF_WritingSystem_DoneMetricsFunc
modifier|*
name|AF_WritingSystem_DoneMetricsFunc
function_decl|)
parameter_list|(
name|AF_StyleMetrics
name|metrics
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|AF_WritingSystem_InitHintsFunc
modifier|*
name|AF_WritingSystem_InitHintsFunc
function_decl|)
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|AF_StyleMetrics
name|metrics
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|AF_WritingSystem_ApplyHintsFunc
modifier|*
name|AF_WritingSystem_ApplyHintsFunc
function_decl|)
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|FT_Outline
modifier|*
name|outline
parameter_list|,
name|AF_StyleMetrics
name|metrics
parameter_list|)
function_decl|;
end_typedef
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
comment|/*****                W R I T I N G   S Y S T E M S                  *****/
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
begin_comment
comment|/*    *  For the auto-hinter, a writing system consists of multiple scripts that    *  can be handled similarly *in a typographical way*; the relationship is    *  not based on history.  For example, both the Greek and the unrelated    *  Armenian scripts share the same features like ascender, descender,    *  x-height, etc.  Essentially, a writing system is covered by a    *  submodule of the auto-fitter; it contains    *    *  - a specific global analyzer that computes global metrics specific to    *    the script (based on script-specific characters to identify ascender    *    height, x-height, etc.),    *    *  - a specific glyph analyzer that computes segments and edges for each    *    glyph covered by the script,    *    *  - a specific grid-fitting algorithm that distorts the scaled glyph    *    outline according to the results of the glyph analyzer.    */
end_comment
begin_define
DECL|macro|__AFWRTSYS_H__
define|#
directive|define
name|__AFWRTSYS_H__
end_define
begin_comment
DECL|macro|__AFWRTSYS_H__
comment|/* don't load header files */
end_comment
begin_undef
DECL|macro|WRITING_SYSTEM
undef|#
directive|undef
name|WRITING_SYSTEM
end_undef
begin_define
DECL|macro|WRITING_SYSTEM
define|#
directive|define
name|WRITING_SYSTEM
parameter_list|(
name|ws
parameter_list|,
name|WS
parameter_list|)
define|\
value|AF_WRITING_SYSTEM_ ## WS,
end_define
begin_comment
comment|/* The list of known writing systems. */
end_comment
begin_typedef
DECL|enum|AF_WritingSystem_
typedef|typedef
enum|enum
name|AF_WritingSystem_
block|{
include|#
directive|include
file|"afwrtsys.h"
DECL|enumerator|AF_WRITING_SYSTEM_MAX
name|AF_WRITING_SYSTEM_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_WritingSystem
name|AF_WritingSystem
typedef|;
end_typedef
begin_undef
DECL|macro|__AFWRTSYS_H__
undef|#
directive|undef
name|__AFWRTSYS_H__
end_undef
begin_typedef
DECL|struct|AF_WritingSystemClassRec_
typedef|typedef
struct|struct
name|AF_WritingSystemClassRec_
block|{
DECL|member|writing_system
name|AF_WritingSystem
name|writing_system
decl_stmt|;
DECL|member|style_metrics_size
name|FT_Offset
name|style_metrics_size
decl_stmt|;
DECL|member|style_metrics_init
name|AF_WritingSystem_InitMetricsFunc
name|style_metrics_init
decl_stmt|;
DECL|member|style_metrics_scale
name|AF_WritingSystem_ScaleMetricsFunc
name|style_metrics_scale
decl_stmt|;
DECL|member|style_metrics_done
name|AF_WritingSystem_DoneMetricsFunc
name|style_metrics_done
decl_stmt|;
DECL|member|style_hints_init
name|AF_WritingSystem_InitHintsFunc
name|style_hints_init
decl_stmt|;
DECL|member|style_hints_apply
name|AF_WritingSystem_ApplyHintsFunc
name|style_hints_apply
decl_stmt|;
block|}
DECL|typedef|AF_WritingSystemClassRec
name|AF_WritingSystemClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_WritingSystemClass
typedef|typedef
specifier|const
name|AF_WritingSystemClassRec
modifier|*
name|AF_WritingSystemClass
typedef|;
end_typedef
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
comment|/*****                        S C R I P T S                          *****/
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
begin_comment
comment|/*    *  Each script is associated with a set of Unicode ranges that gets used    *  to test whether the font face supports the script.    *    *  We use four-letter script tags from the OpenType specification,    *  extended by `NONE', which indicates `no script'.    */
end_comment
begin_undef
DECL|macro|SCRIPT
undef|#
directive|undef
name|SCRIPT
end_undef
begin_define
DECL|macro|SCRIPT
define|#
directive|define
name|SCRIPT
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|,
name|sc1
parameter_list|,
name|sc2
parameter_list|,
name|sc3
parameter_list|)
define|\
value|AF_SCRIPT_ ## S,
end_define
begin_comment
comment|/* The list of known scripts. */
end_comment
begin_typedef
DECL|enum|AF_Script_
typedef|typedef
enum|enum
name|AF_Script_
block|{
include|#
directive|include
file|"afscript.h"
DECL|enumerator|AF_SCRIPT_MAX
name|AF_SCRIPT_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_Script
name|AF_Script
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_Script_UniRangeRec_
typedef|typedef
struct|struct
name|AF_Script_UniRangeRec_
block|{
DECL|member|first
name|FT_UInt32
name|first
decl_stmt|;
DECL|member|last
name|FT_UInt32
name|last
decl_stmt|;
block|}
DECL|typedef|AF_Script_UniRangeRec
name|AF_Script_UniRangeRec
typedef|;
end_typedef
begin_define
DECL|macro|AF_UNIRANGE_REC
define|#
directive|define
name|AF_UNIRANGE_REC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ (FT_UInt32)(a), (FT_UInt32)(b) }
end_define
begin_typedef
DECL|typedef|AF_Script_UniRange
typedef|typedef
specifier|const
name|AF_Script_UniRangeRec
modifier|*
name|AF_Script_UniRange
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_ScriptClassRec_
typedef|typedef
struct|struct
name|AF_ScriptClassRec_
block|{
DECL|member|script
name|AF_Script
name|script
decl_stmt|;
DECL|member|script_uni_ranges
name|AF_Script_UniRange
name|script_uni_ranges
decl_stmt|;
comment|/* last must be { 0, 0 }        */
DECL|member|standard_char1
name|FT_UInt32
name|standard_char1
decl_stmt|;
comment|/* for default width and height */
DECL|member|standard_char2
name|FT_UInt32
name|standard_char2
decl_stmt|;
comment|/* ditto                        */
DECL|member|standard_char3
name|FT_UInt32
name|standard_char3
decl_stmt|;
comment|/* ditto                        */
block|}
DECL|typedef|AF_ScriptClassRec
name|AF_ScriptClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_ScriptClass
typedef|typedef
specifier|const
name|AF_ScriptClassRec
modifier|*
name|AF_ScriptClass
typedef|;
end_typedef
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
comment|/*****                      C O V E R A G E S                        *****/
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
begin_comment
comment|/*    *  Usually, a font contains more glyphs than can be addressed by its    *  character map.    *    *  In the PostScript font world, encoding vectors specific to a given    *  task are used to select such glyphs, and these glyphs can be often    *  recognized by having a suffix in its glyph names.  For example, a    *  superscript glyph `A' might be called `A.sup'.  Unfortunately, this    *  naming scheme is not standardized and thus unusable for us.    *    *  In the OpenType world, a better solution was invented, namely    *  `features', which cleanly separate a character's input encoding from    *  the corresponding glyph's appearance, and which don't use glyph names    *  at all.  For our purposes, and slightly generalized, an OpenType    *  feature is a name of a mapping that maps character codes to    *  non-standard glyph indices (features get used for other things also).    *  For example, the `sups' feature provides superscript glyphs, thus    *  mapping character codes like `A' or `B' to superscript glyph    *  representation forms.  How this mapping happens is completely    *  uninteresting to us.    *    *  For the auto-hinter, a `coverage' represents all glyphs of an OpenType    *  feature collected in a set (as listed below) that can be hinted    *  together.  To continue the above example, superscript glyphs must not    *  be hinted together with normal glyphs because the blue zones    *  completely differ.    *    *  Note that FreeType itself doesn't compute coverages; it only provides    *  the glyphs addressable by the default Unicode character map.  Instead,    *  we use the HarfBuzz library (if available), which has many functions    *  exactly for this purpose.    *    *  AF_COVERAGE_DEFAULT is special: It should cover everything that isn't    *  listed separately (including the glyphs addressable by the character    *  map).  In case HarfBuzz isn't available, it exactly covers the glyphs    *  addressable by the character map.    *    */
end_comment
begin_undef
DECL|macro|COVERAGE
undef|#
directive|undef
name|COVERAGE
end_undef
begin_define
DECL|macro|COVERAGE
define|#
directive|define
name|COVERAGE
parameter_list|(
name|name
parameter_list|,
name|NAME
parameter_list|,
name|description
parameter_list|, \
name|tag1
parameter_list|,
name|tag2
parameter_list|,
name|tag3
parameter_list|,
name|tag4
parameter_list|)
define|\
value|AF_COVERAGE_ ## NAME,
end_define
begin_typedef
DECL|enum|AF_Coverage_
typedef|typedef
enum|enum
name|AF_Coverage_
block|{
include|#
directive|include
file|"afcover.h"
DECL|enumerator|AF_COVERAGE_DEFAULT
name|AF_COVERAGE_DEFAULT
block|}
DECL|typedef|AF_Coverage
name|AF_Coverage
typedef|;
end_typedef
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
comment|/*****                         S T Y L E S                           *****/
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
begin_comment
comment|/*    *  The topmost structure for modelling the auto-hinter glyph input data    *  is a `style class', grouping everything together.    */
end_comment
begin_undef
DECL|macro|STYLE
undef|#
directive|undef
name|STYLE
end_undef
begin_define
DECL|macro|STYLE
define|#
directive|define
name|STYLE
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|ws
parameter_list|,
name|sc
parameter_list|,
name|ss
parameter_list|,
name|c
parameter_list|)
define|\
value|AF_STYLE_ ## S,
end_define
begin_comment
comment|/* The list of known styles. */
end_comment
begin_typedef
DECL|enum|AF_Style_
typedef|typedef
enum|enum
name|AF_Style_
block|{
include|#
directive|include
file|"afstyles.h"
DECL|enumerator|AF_STYLE_MAX
name|AF_STYLE_MAX
comment|/* do not remove */
block|}
DECL|typedef|AF_Style
name|AF_Style
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_StyleClassRec_
typedef|typedef
struct|struct
name|AF_StyleClassRec_
block|{
DECL|member|style
name|AF_Style
name|style
decl_stmt|;
DECL|member|writing_system
name|AF_WritingSystem
name|writing_system
decl_stmt|;
DECL|member|script
name|AF_Script
name|script
decl_stmt|;
DECL|member|blue_stringset
name|AF_Blue_Stringset
name|blue_stringset
decl_stmt|;
DECL|member|coverage
name|AF_Coverage
name|coverage
decl_stmt|;
block|}
DECL|typedef|AF_StyleClassRec
name|AF_StyleClassRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|AF_StyleClass
typedef|typedef
specifier|const
name|AF_StyleClassRec
modifier|*
name|AF_StyleClass
typedef|;
end_typedef
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
comment|/*****                   S T Y L E   M E T R I C S                   *****/
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
begin_typedef
DECL|typedef|AF_FaceGlobals
typedef|typedef
name|struct
name|AF_FaceGlobalsRec_
modifier|*
name|AF_FaceGlobals
typedef|;
end_typedef
begin_comment
comment|/* This is the main structure that combines everything.  Autofit modules */
end_comment
begin_comment
comment|/* specific to writing systems derive their structures from it, for      */
end_comment
begin_comment
comment|/* example `AF_LatinMetrics'.                                            */
end_comment
begin_typedef
DECL|struct|AF_StyleMetricsRec_
typedef|typedef
struct|struct
name|AF_StyleMetricsRec_
block|{
DECL|member|style_class
name|AF_StyleClass
name|style_class
decl_stmt|;
DECL|member|scaler
name|AF_ScalerRec
name|scaler
decl_stmt|;
DECL|member|digits_have_same_width
name|FT_Bool
name|digits_have_same_width
decl_stmt|;
DECL|member|globals
name|AF_FaceGlobals
name|globals
decl_stmt|;
comment|/* to access properties */
block|}
DECL|typedef|AF_StyleMetricsRec
name|AF_StyleMetricsRec
typedef|;
end_typedef
begin_comment
comment|/* Declare and define vtables for classes */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|AF_DECLARE_WRITING_SYSTEM_CLASS
define|#
directive|define
name|AF_DECLARE_WRITING_SYSTEM_CLASS
parameter_list|(
name|writing_system_class
parameter_list|)
define|\
value|FT_CALLBACK_TABLE const AF_WritingSystemClassRec              \   writing_system_class;
end_define
begin_define
DECL|macro|AF_DEFINE_WRITING_SYSTEM_CLASS
define|#
directive|define
name|AF_DEFINE_WRITING_SYSTEM_CLASS
parameter_list|(                  \
name|writing_system_class
parameter_list|,                          \
name|system
parameter_list|,                                        \
name|m_size
parameter_list|,                                        \
name|m_init
parameter_list|,                                        \
name|m_scale
parameter_list|,                                       \
name|m_done
parameter_list|,                                        \
name|h_init
parameter_list|,                                        \
name|h_apply
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                  \   const AF_WritingSystemClassRec  writing_system_class = \   {                                                      \     system,                                              \                                                          \     m_size,                                              \                                                          \     m_init,                                              \     m_scale,                                             \     m_done,                                              \                                                          \     h_init,                                              \     h_apply                                              \   };
end_define
begin_define
DECL|macro|AF_DECLARE_SCRIPT_CLASS
define|#
directive|define
name|AF_DECLARE_SCRIPT_CLASS
parameter_list|(
name|script_class
parameter_list|)
define|\
value|FT_CALLBACK_TABLE const AF_ScriptClassRec     \   script_class;
end_define
begin_define
DECL|macro|AF_DEFINE_SCRIPT_CLASS
define|#
directive|define
name|AF_DEFINE_SCRIPT_CLASS
parameter_list|(           \
name|script_class
parameter_list|,                   \
name|script
parameter_list|,                         \
name|ranges
parameter_list|,                         \
name|std_char1
parameter_list|,                      \
name|std_char2
parameter_list|,                      \
name|std_char3
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                   \   const AF_ScriptClassRec  script_class = \   {                                       \     script,                               \     ranges,                               \     std_char1,                            \     std_char2,                            \     std_char3                             \   };
end_define
begin_define
DECL|macro|AF_DECLARE_STYLE_CLASS
define|#
directive|define
name|AF_DECLARE_STYLE_CLASS
parameter_list|(
name|style_class
parameter_list|)
define|\
value|FT_CALLBACK_TABLE const AF_StyleClassRec    \   style_class;
end_define
begin_define
DECL|macro|AF_DEFINE_STYLE_CLASS
define|#
directive|define
name|AF_DEFINE_STYLE_CLASS
parameter_list|(          \
name|style_class
parameter_list|,                  \
name|style
parameter_list|,                        \
name|writing_system
parameter_list|,               \
name|script
parameter_list|,                       \
name|blue_stringset
parameter_list|,               \
name|coverage
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                 \   const AF_StyleClassRec  style_class = \   {                                     \     style,                              \     writing_system,                     \     script,                             \     blue_stringset,                     \     coverage                            \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|AF_DECLARE_WRITING_SYSTEM_CLASS
define|#
directive|define
name|AF_DECLARE_WRITING_SYSTEM_CLASS
parameter_list|(
name|writing_system_class
parameter_list|)
define|\
value|FT_LOCAL( void )                                                         \   FT_Init_Class_ ## writing_system_class( AF_WritingSystemClassRec*  ac );
end_define
begin_define
DECL|macro|AF_DEFINE_WRITING_SYSTEM_CLASS
define|#
directive|define
name|AF_DEFINE_WRITING_SYSTEM_CLASS
parameter_list|(                                   \
name|writing_system_class
parameter_list|,                                           \
name|system
parameter_list|,                                                         \
name|m_size
parameter_list|,                                                         \
name|m_init
parameter_list|,                                                         \
name|m_scale
parameter_list|,                                                        \
name|m_done
parameter_list|,                                                         \
name|h_init
parameter_list|,                                                         \
name|h_apply
parameter_list|)
define|\
value|FT_LOCAL_DEF( void )                                                    \   FT_Init_Class_ ## writing_system_class( AF_WritingSystemClassRec*  ac ) \   {                                                                       \     ac->writing_system      = system;                                     \                                                                           \     ac->style_metrics_size  = m_size;                                     \                                                                           \     ac->style_metrics_init  = m_init;                                     \     ac->style_metrics_scale = m_scale;                                    \     ac->style_metrics_done  = m_done;                                     \                                                                           \     ac->style_hints_init    = h_init;                                     \     ac->style_hints_apply   = h_apply;                                    \   }
end_define
begin_define
DECL|macro|AF_DECLARE_SCRIPT_CLASS
define|#
directive|define
name|AF_DECLARE_SCRIPT_CLASS
parameter_list|(
name|script_class
parameter_list|)
define|\
value|FT_LOCAL( void )                                          \   FT_Init_Class_ ## script_class( AF_ScriptClassRec*  ac );
end_define
begin_define
DECL|macro|AF_DEFINE_SCRIPT_CLASS
define|#
directive|define
name|AF_DEFINE_SCRIPT_CLASS
parameter_list|(                            \
name|script_class
parameter_list|,                                    \
name|script_
parameter_list|,                                         \
name|ranges
parameter_list|,                                          \
name|std_char1
parameter_list|,                                       \
name|std_char2
parameter_list|,                                       \
name|std_char3
parameter_list|)
define|\
value|FT_LOCAL_DEF( void )                                     \   FT_Init_Class_ ## script_class( AF_ScriptClassRec*  ac ) \   {                                                        \     ac->script            = script_;                       \     ac->script_uni_ranges = ranges;                        \     ac->standard_char1    = std_char1;                     \     ac->standard_char2    = std_char2;                     \     ac->standard_char3    = std_char3;                     \   }
end_define
begin_define
DECL|macro|AF_DECLARE_STYLE_CLASS
define|#
directive|define
name|AF_DECLARE_STYLE_CLASS
parameter_list|(
name|style_class
parameter_list|)
define|\
value|FT_LOCAL( void )                                        \   FT_Init_Class_ ## style_class( AF_StyleClassRec*  ac );
end_define
begin_define
DECL|macro|AF_DEFINE_STYLE_CLASS
define|#
directive|define
name|AF_DEFINE_STYLE_CLASS
parameter_list|(                           \
name|style_class
parameter_list|,                                   \
name|style_
parameter_list|,                                        \
name|writing_system_
parameter_list|,                               \
name|script_
parameter_list|,                                       \
name|blue_stringset_
parameter_list|,                               \
name|coverage_
parameter_list|)
define|\
value|FT_LOCAL_DEF( void )                                   \   FT_Init_Class_ ## style_class( AF_StyleClassRec*  ac ) \   {                                                      \     ac->style          = style_;                         \     ac->writing_system = writing_system_;                \     ac->script         = script_;                        \     ac->blue_stringset = blue_stringset_;                \     ac->coverage       = coverage_;                      \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
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
comment|/* __AFTYPES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
