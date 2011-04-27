begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t42parse.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 42 font parser (specification).                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003 by Roberto Alameda.                               */
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
name|__T42PARSE_H__
end_ifndef
begin_define
DECL|macro|__T42PARSE_H__
define|#
directive|define
name|__T42PARSE_H__
end_define
begin_include
include|#
directive|include
file|"t42objs.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_AUX_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|T42_ParserRec_
typedef|typedef
struct|struct
name|T42_ParserRec_
block|{
DECL|member|root
name|PS_ParserRec
name|root
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
DECL|member|base_dict
name|FT_Byte
modifier|*
name|base_dict
decl_stmt|;
DECL|member|base_len
name|FT_Long
name|base_len
decl_stmt|;
DECL|member|in_memory
name|FT_Bool
name|in_memory
decl_stmt|;
block|}
DECL|typedef|T42_ParserRec
DECL|typedef|T42_Parser
name|T42_ParserRec
operator|,
typedef|*
name|T42_Parser
typedef|;
end_typedef
begin_typedef
DECL|struct|T42_Loader_
typedef|typedef
struct|struct
name|T42_Loader_
block|{
DECL|member|parser
name|T42_ParserRec
name|parser
decl_stmt|;
comment|/* parser used to read the stream */
DECL|member|num_chars
name|FT_UInt
name|num_chars
decl_stmt|;
comment|/* number of characters in encoding */
DECL|member|encoding_table
name|PS_TableRec
name|encoding_table
decl_stmt|;
comment|/* PS_Table used to store the       */
comment|/* encoding character names         */
DECL|member|num_glyphs
name|FT_UInt
name|num_glyphs
decl_stmt|;
DECL|member|glyph_names
name|PS_TableRec
name|glyph_names
decl_stmt|;
DECL|member|charstrings
name|PS_TableRec
name|charstrings
decl_stmt|;
DECL|member|swap_table
name|PS_TableRec
name|swap_table
decl_stmt|;
comment|/* For moving .notdef glyph to index 0. */
block|}
DECL|typedef|T42_LoaderRec
DECL|typedef|T42_Loader
name|T42_LoaderRec
operator|,
typedef|*
name|T42_Loader
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|t42_parser_init
argument_list|(
argument|T42_Parser     parser
argument_list|,
argument|FT_Stream      stream
argument_list|,
argument|FT_Memory      memory
argument_list|,
argument|PSAux_Service  psaux
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
DECL|variable|t42_parser_done
name|t42_parser_done
argument_list|(
argument|T42_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|t42_parser_done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|t42_parse_dict
argument_list|(
argument|T42_Face    face
argument_list|,
argument|T42_Loader  loader
argument_list|,
argument|FT_Byte*    base
argument_list|,
argument|FT_Long     size
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
DECL|variable|t42_loader_init
name|t42_loader_init
argument_list|(
argument|T42_Loader  loader
argument_list|,
argument|T42_Face    face
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
DECL|variable|loader
name|t42_loader_done
argument_list|(
argument|T42_Loader  loader
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|loader
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
comment|/* __T42PARSE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
