begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cffgload.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType Glyph Loader (specification).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2006, 2007, 2008, 2009 by       */
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
name|__CFFGLOAD_H__
end_ifndef
begin_define
DECL|macro|__CFFGLOAD_H__
define|#
directive|define
name|__CFFGLOAD_H__
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
file|"cffobjs.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|CFF_MAX_OPERANDS
define|#
directive|define
name|CFF_MAX_OPERANDS
value|48
end_define
begin_define
DECL|macro|CFF_MAX_SUBRS_CALLS
define|#
directive|define
name|CFF_MAX_SUBRS_CALLS
value|32
end_define
begin_define
DECL|macro|CFF_MAX_TRANS_ELEMENTS
define|#
directive|define
name|CFF_MAX_TRANS_ELEMENTS
value|32
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Structure>                                                           */
end_comment
begin_comment
comment|/*    CFF_Builder                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*     A structure used during glyph loading to store its outline.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    memory        :: The current memory object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face          :: The current face object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph         :: The current glyph slot.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    loader        :: The current glyph loader.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    base          :: The base glyph outline.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    current       :: The current glyph outline.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pos_x         :: The horizontal translation (if composite glyph).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pos_y         :: The vertical translation (if composite glyph).    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    left_bearing  :: The left side bearing point.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance       :: The horizontal advance vector.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bbox          :: Unused.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    path_begun    :: A flag which indicates that a new path has begun. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_points   :: If this flag is not set, no points are loaded.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    no_recurse    :: Set but not used.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    metrics_only  :: A boolean indicating that we only want to compute */
end_comment
begin_comment
comment|/*                     the metrics of a given glyph, not load all of its */
end_comment
begin_comment
comment|/*                     points.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    hints_funcs   :: Auxiliary pointer for hinting.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    hints_globals :: Auxiliary pointer for hinting.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CFF_Builder_
typedef|typedef
struct|struct
name|CFF_Builder_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|face
name|TT_Face
name|face
decl_stmt|;
DECL|member|glyph
name|CFF_GlyphSlot
name|glyph
decl_stmt|;
DECL|member|loader
name|FT_GlyphLoader
name|loader
decl_stmt|;
DECL|member|base
name|FT_Outline
modifier|*
name|base
decl_stmt|;
DECL|member|current
name|FT_Outline
modifier|*
name|current
decl_stmt|;
DECL|member|pos_x
name|FT_Pos
name|pos_x
decl_stmt|;
DECL|member|pos_y
name|FT_Pos
name|pos_y
decl_stmt|;
DECL|member|left_bearing
name|FT_Vector
name|left_bearing
decl_stmt|;
DECL|member|advance
name|FT_Vector
name|advance
decl_stmt|;
DECL|member|bbox
name|FT_BBox
name|bbox
decl_stmt|;
comment|/* bounding box */
DECL|member|path_begun
name|FT_Bool
name|path_begun
decl_stmt|;
DECL|member|load_points
name|FT_Bool
name|load_points
decl_stmt|;
DECL|member|no_recurse
name|FT_Bool
name|no_recurse
decl_stmt|;
DECL|member|metrics_only
name|FT_Bool
name|metrics_only
decl_stmt|;
DECL|member|hints_funcs
name|void
modifier|*
name|hints_funcs
decl_stmt|;
comment|/* hinter-specific */
DECL|member|hints_globals
name|void
modifier|*
name|hints_globals
decl_stmt|;
comment|/* hinter-specific */
block|}
DECL|typedef|CFF_Builder
name|CFF_Builder
typedef|;
end_typedef
begin_comment
comment|/* execution context charstring zone */
end_comment
begin_typedef
DECL|struct|CFF_Decoder_Zone_
typedef|typedef
struct|struct
name|CFF_Decoder_Zone_
block|{
DECL|member|base
name|FT_Byte
modifier|*
name|base
decl_stmt|;
DECL|member|limit
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
DECL|member|cursor
name|FT_Byte
modifier|*
name|cursor
decl_stmt|;
block|}
DECL|typedef|CFF_Decoder_Zone
name|CFF_Decoder_Zone
typedef|;
end_typedef
begin_typedef
DECL|struct|CFF_Decoder_
typedef|typedef
struct|struct
name|CFF_Decoder_
block|{
DECL|member|builder
name|CFF_Builder
name|builder
decl_stmt|;
DECL|member|cff
name|CFF_Font
name|cff
decl_stmt|;
DECL|member|stack
name|FT_Fixed
name|stack
index|[
name|CFF_MAX_OPERANDS
operator|+
literal|1
index|]
decl_stmt|;
DECL|member|top
name|FT_Fixed
modifier|*
name|top
decl_stmt|;
DECL|member|zones
name|CFF_Decoder_Zone
name|zones
index|[
name|CFF_MAX_SUBRS_CALLS
operator|+
literal|1
index|]
decl_stmt|;
DECL|member|zone
name|CFF_Decoder_Zone
modifier|*
name|zone
decl_stmt|;
DECL|member|flex_state
name|FT_Int
name|flex_state
decl_stmt|;
DECL|member|num_flex_vectors
name|FT_Int
name|num_flex_vectors
decl_stmt|;
DECL|member|flex_vectors
name|FT_Vector
name|flex_vectors
index|[
literal|7
index|]
decl_stmt|;
DECL|member|glyph_width
name|FT_Pos
name|glyph_width
decl_stmt|;
DECL|member|nominal_width
name|FT_Pos
name|nominal_width
decl_stmt|;
DECL|member|read_width
name|FT_Bool
name|read_width
decl_stmt|;
DECL|member|width_only
name|FT_Bool
name|width_only
decl_stmt|;
DECL|member|num_hints
name|FT_Int
name|num_hints
decl_stmt|;
DECL|member|buildchar
name|FT_Fixed
name|buildchar
index|[
name|CFF_MAX_TRANS_ELEMENTS
index|]
decl_stmt|;
DECL|member|num_locals
name|FT_UInt
name|num_locals
decl_stmt|;
DECL|member|num_globals
name|FT_UInt
name|num_globals
decl_stmt|;
DECL|member|locals_bias
name|FT_Int
name|locals_bias
decl_stmt|;
DECL|member|globals_bias
name|FT_Int
name|globals_bias
decl_stmt|;
DECL|member|locals
name|FT_Byte
modifier|*
modifier|*
name|locals
decl_stmt|;
DECL|member|globals
name|FT_Byte
modifier|*
modifier|*
name|globals
decl_stmt|;
DECL|member|glyph_names
name|FT_Byte
modifier|*
modifier|*
name|glyph_names
decl_stmt|;
comment|/* for pure CFF fonts only  */
DECL|member|num_glyphs
name|FT_UInt
name|num_glyphs
decl_stmt|;
comment|/* number of glyphs in font */
DECL|member|hint_mode
name|FT_Render_Mode
name|hint_mode
decl_stmt|;
DECL|member|seac
name|FT_Bool
name|seac
decl_stmt|;
block|}
DECL|typedef|CFF_Decoder
name|CFF_Decoder
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cff_decoder_init
argument_list|(
argument|CFF_Decoder*    decoder
argument_list|,
argument|TT_Face         face
argument_list|,
argument|CFF_Size        size
argument_list|,
argument|CFF_GlyphSlot   slot
argument_list|,
argument|FT_Bool         hinting
argument_list|,
argument|FT_Render_Mode  hint_mode
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
name|cff_decoder_prepare
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|CFF_Size      size
argument_list|,
argument|FT_UInt       glyph_index
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* unused until we support pure CFF fonts */
end_comment
begin_comment
comment|/* Compute the maximum advance width of a font through quick parsing */
end_comment
begin_endif
unit|FT_LOCAL( FT_Error )   cff_compute_max_advance( TT_Face  face,                            FT_Int*  max_advance );
endif|#
directive|endif
end_endif
begin_comment
comment|/* 0 */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|cff_decoder_parse_charstrings
name|cff_decoder_parse_charstrings
argument_list|(
argument|CFF_Decoder*  decoder
argument_list|,
argument|FT_Byte*      charstring_base
argument_list|,
argument|FT_ULong      charstring_len
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
name|cff_slot_load
argument_list|(
argument|CFF_GlyphSlot  glyph
argument_list|,
argument|CFF_Size       size
argument_list|,
argument|FT_UInt        glyph_index
argument_list|,
argument|FT_Int32       load_flags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CFFGLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
