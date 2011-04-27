begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1decode.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    PostScript Type 1 decoding routines (specification).                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2002, 2003 by                                     */
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
name|__T1DECODE_H__
end_ifndef
begin_define
DECL|macro|__T1DECODE_H__
define|#
directive|define
name|__T1DECODE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_AUX_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
name|FT_CALLBACK_TABLE
DECL|variable|t1_decoder_funcs
specifier|const
name|T1_Decoder_FuncsRec
name|t1_decoder_funcs
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|t1_decoder_parse_glyph
argument_list|(
argument|T1_Decoder  decoder
argument_list|,
argument|FT_UInt     glyph_index
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
DECL|variable|t1_decoder_parse_charstrings
name|t1_decoder_parse_charstrings
argument_list|(
argument|T1_Decoder  decoder
argument_list|,
argument|FT_Byte*    base
argument_list|,
argument|FT_UInt     len
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
name|t1_decoder_init
argument_list|(
argument|T1_Decoder           decoder
argument_list|,
argument|FT_Face              face
argument_list|,
argument|FT_Size              size
argument_list|,
argument|FT_GlyphSlot         slot
argument_list|,
argument|FT_Byte**            glyph_names
argument_list|,
argument|PS_Blend             blend
argument_list|,
argument|FT_Bool              hinting
argument_list|,
argument|FT_Render_Mode       hint_mode
argument_list|,
argument|T1_Decoder_Callback  parse_glyph
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
DECL|variable|t1_decoder_done
name|t1_decoder_done
argument_list|(
argument|T1_Decoder  decoder
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|t1_decoder_done
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
comment|/* __T1DECODE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
