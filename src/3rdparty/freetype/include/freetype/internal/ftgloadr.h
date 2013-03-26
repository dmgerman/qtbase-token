begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgloadr.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType glyph loader (specification).                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2005, 2006 by                                    */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg                       */
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
name|__FTGLOADR_H__
end_ifndef
begin_define
DECL|macro|__FTGLOADR_H__
define|#
directive|define
name|__FTGLOADR_H__
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
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_GlyphLoader                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The glyph loader is an internal object used to load several glyphs */
end_comment
begin_comment
comment|/*    together (for example, in the case of composites).                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The glyph loader implementation is not part of the high-level API, */
end_comment
begin_comment
comment|/*    hence the forward structure declaration.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_GlyphLoader
typedef|typedef
name|struct
name|FT_GlyphLoaderRec_
modifier|*
name|FT_GlyphLoader
typedef|;
end_typedef
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* moved to freetype.h in version 2.2 */
end_comment
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ARGS_ARE_WORDS
value|1
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ARGS_ARE_XY_VALUES
value|2
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ROUND_XY_TO_GRID
value|4
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_SCALE
value|8
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_XY_SCALE
value|0x40
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_2X2
value|0x80
end_define
begin_define
define|#
directive|define
name|FT_SUBGLYPH_FLAG_USE_MY_METRICS
value|0x200
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|struct|FT_SubGlyphRec_
typedef|typedef
struct|struct
name|FT_SubGlyphRec_
block|{
DECL|member|index
name|FT_Int
name|index
decl_stmt|;
DECL|member|flags
name|FT_UShort
name|flags
decl_stmt|;
DECL|member|arg1
name|FT_Int
name|arg1
decl_stmt|;
DECL|member|arg2
name|FT_Int
name|arg2
decl_stmt|;
DECL|member|transform
name|FT_Matrix
name|transform
decl_stmt|;
block|}
DECL|typedef|FT_SubGlyphRec
name|FT_SubGlyphRec
typedef|;
end_typedef
begin_typedef
DECL|struct|FT_GlyphLoadRec_
typedef|typedef
struct|struct
name|FT_GlyphLoadRec_
block|{
DECL|member|outline
name|FT_Outline
name|outline
decl_stmt|;
comment|/* outline                   */
DECL|member|extra_points
name|FT_Vector
modifier|*
name|extra_points
decl_stmt|;
comment|/* extra points table        */
DECL|member|extra_points2
name|FT_Vector
modifier|*
name|extra_points2
decl_stmt|;
comment|/* second extra points table */
DECL|member|num_subglyphs
name|FT_UInt
name|num_subglyphs
decl_stmt|;
comment|/* number of subglyphs       */
DECL|member|subglyphs
name|FT_SubGlyph
name|subglyphs
decl_stmt|;
comment|/* subglyphs                 */
block|}
DECL|typedef|FT_GlyphLoadRec
DECL|typedef|FT_GlyphLoad
name|FT_GlyphLoadRec
operator|,
typedef|*
name|FT_GlyphLoad
typedef|;
end_typedef
begin_typedef
DECL|struct|FT_GlyphLoaderRec_
typedef|typedef
struct|struct
name|FT_GlyphLoaderRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|max_points
name|FT_UInt
name|max_points
decl_stmt|;
DECL|member|max_contours
name|FT_UInt
name|max_contours
decl_stmt|;
DECL|member|max_subglyphs
name|FT_UInt
name|max_subglyphs
decl_stmt|;
DECL|member|use_extra
name|FT_Bool
name|use_extra
decl_stmt|;
DECL|member|base
name|FT_GlyphLoadRec
name|base
decl_stmt|;
DECL|member|current
name|FT_GlyphLoadRec
name|current
decl_stmt|;
DECL|member|other
name|void
modifier|*
name|other
decl_stmt|;
comment|/* for possible future extension? */
block|}
DECL|typedef|FT_GlyphLoaderRec
name|FT_GlyphLoaderRec
typedef|;
end_typedef
begin_comment
comment|/* create new empty glyph loader */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_New
argument_list|(
argument|FT_Memory        memory
argument_list|,
argument|FT_GlyphLoader  *aloader
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* add an extra points table to a glyph loader */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_GlyphLoader_CreateExtra
name|FT_GlyphLoader_CreateExtra
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_GlyphLoader_CreateExtra
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* destroy a glyph loader */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|loader
name|FT_GlyphLoader_Done
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* reset a glyph loader (frees everything int it) */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|loader
name|FT_GlyphLoader_Reset
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* rewind a glyph loader */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|loader
name|FT_GlyphLoader_Rewind
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* check that there is enough space to add `n_points' and `n_contours' */
end_comment
begin_comment
comment|/* to the glyph loader                                                 */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CheckPoints
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|,
argument|FT_UInt         n_points
argument_list|,
argument|FT_UInt         n_contours
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FT_GLYPHLOADER_CHECK_P
define|#
directive|define
name|FT_GLYPHLOADER_CHECK_P
parameter_list|(
name|_loader
parameter_list|,
name|_count
parameter_list|)
define|\
value|( (_count) == 0 || ((_loader)->base.outline.n_points    +              \                        (_loader)->current.outline.n_points +              \                        (unsigned long)(_count))<= (_loader)->max_points )
end_define
begin_define
DECL|macro|FT_GLYPHLOADER_CHECK_C
define|#
directive|define
name|FT_GLYPHLOADER_CHECK_C
parameter_list|(
name|_loader
parameter_list|,
name|_count
parameter_list|)
define|\
value|( (_count) == 0 || ((_loader)->base.outline.n_contours    +              \                       (_loader)->current.outline.n_contours +              \                       (unsigned long)(_count))<= (_loader)->max_contours )
end_define
begin_define
DECL|macro|FT_GLYPHLOADER_CHECK_POINTS
define|#
directive|define
name|FT_GLYPHLOADER_CHECK_POINTS
parameter_list|(
name|_loader
parameter_list|,
name|_points
parameter_list|,
name|_contours
parameter_list|)
define|\
value|( ( FT_GLYPHLOADER_CHECK_P( _loader, _points )&&                  \       FT_GLYPHLOADER_CHECK_C( _loader, _contours ) )                   \     ? 0                                                                \     : FT_GlyphLoader_CheckPoints( (_loader), (_points), (_contours) ) )
end_define
begin_comment
comment|/* check that there is enough space to add `n_subs' sub-glyphs to */
end_comment
begin_comment
comment|/* a glyph loader                                                 */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_GlyphLoader_CheckSubGlyphs
name|FT_GlyphLoader_CheckSubGlyphs
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|,
argument|FT_UInt         n_subs
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* prepare a glyph loader, i.e. empty the current glyph */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|loader
name|FT_GlyphLoader_Prepare
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* add the current glyph to the base glyph */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|loader
name|FT_GlyphLoader_Add
argument_list|(
argument|FT_GlyphLoader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* copy points from one glyph loader to another */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_GlyphLoader_CopyPoints
argument_list|(
argument|FT_GlyphLoader  target
argument_list|,
argument|FT_GlyphLoader  source
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
comment|/* __FTGLOADR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
