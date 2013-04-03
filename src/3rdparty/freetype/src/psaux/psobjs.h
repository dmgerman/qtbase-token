begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  psobjs.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auxiliary functions for PostScript fonts (specification).            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003 by                                     */
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
name|__PSOBJS_H__
end_ifndef
begin_define
DECL|macro|__PSOBJS_H__
define|#
directive|define
name|__PSOBJS_H__
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
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*****                                                               *****/
comment|/*****                             T1_TABLE                          *****/
comment|/*****                                                               *****/
comment|/*************************************************************************/
comment|/*************************************************************************/
name|FT_CALLBACK_TABLE
DECL|variable|ps_table_funcs
specifier|const
name|PS_Table_FuncsRec
name|ps_table_funcs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FT_CALLBACK_TABLE
DECL|variable|ps_parser_funcs
specifier|const
name|PS_Parser_FuncsRec
name|ps_parser_funcs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FT_CALLBACK_TABLE
DECL|variable|t1_builder_funcs
specifier|const
name|T1_Builder_FuncsRec
name|t1_builder_funcs
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ps_table_new
argument_list|(
argument|PS_Table   table
argument_list|,
argument|FT_Int     count
argument_list|,
argument|FT_Memory  memory
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
DECL|variable|ps_table_add
name|ps_table_add
argument_list|(
argument|PS_Table    table
argument_list|,
argument|FT_Int      idx
argument_list|,
argument|void*       object
argument_list|,
argument|FT_PtrDist  length
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
DECL|variable|table
name|ps_table_done
argument_list|(
argument|PS_Table  table
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|table
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|table
name|ps_table_release
argument_list|(
argument|PS_Table  table
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|table
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
comment|/*****                            T1 PARSER                          *****/
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
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|parser
name|ps_parser_skip_spaces
argument_list|(
argument|PS_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|parser
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|parser
name|ps_parser_skip_PS_token
argument_list|(
argument|PS_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|parser
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ps_parser_to_token
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|T1_Token   token
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
name|ps_parser_to_token_array
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|T1_Token   tokens
argument_list|,
argument|FT_UInt    max_tokens
argument_list|,
argument|FT_Int*    pnum_tokens
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
name|ps_parser_load_field
argument_list|(
argument|PS_Parser       parser
argument_list|,
argument|const T1_Field  field
argument_list|,
argument|void**          objects
argument_list|,
argument|FT_UInt         max_objects
argument_list|,
argument|FT_ULong*       pflags
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
DECL|variable|ps_parser_load_field_table
name|ps_parser_load_field_table
argument_list|(
argument|PS_Parser       parser
argument_list|,
argument|const T1_Field  field
argument_list|,
argument|void**          objects
argument_list|,
argument|FT_UInt         max_objects
argument_list|,
argument|FT_ULong*       pflags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|ps_parser_to_int
argument_list|(
argument|PS_Parser  parser
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
DECL|variable|ps_parser_to_bytes
name|ps_parser_to_bytes
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|FT_Byte*   bytes
argument_list|,
argument|FT_Offset  max_bytes
argument_list|,
argument|FT_Long*   pnum_bytes
argument_list|,
argument|FT_Bool    delimiters
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|ps_parser_to_fixed
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|FT_Int     power_ten
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
DECL|variable|ps_parser_to_coord_array
name|ps_parser_to_coord_array
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|FT_Int     max_coords
argument_list|,
argument|FT_Short*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|ps_parser_to_fixed_array
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|FT_Int     max_values
argument_list|,
argument|FT_Fixed*  values
argument_list|,
argument|FT_Int     power_ten
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
DECL|variable|ps_parser_init
name|ps_parser_init
argument_list|(
argument|PS_Parser  parser
argument_list|,
argument|FT_Byte*   base
argument_list|,
argument|FT_Byte*   limit
argument_list|,
argument|FT_Memory  memory
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
DECL|variable|parser
name|ps_parser_done
argument_list|(
argument|PS_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|parser
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
comment|/*****                            T1 BUILDER                         *****/
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
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|t1_builder_init
argument_list|(
argument|T1_Builder    builder
argument_list|,
argument|FT_Face       face
argument_list|,
argument|FT_Size       size
argument_list|,
argument|FT_GlyphSlot  glyph
argument_list|,
argument|FT_Bool       hinting
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
DECL|variable|builder
name|t1_builder_done
argument_list|(
argument|T1_Builder  builder
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|builder
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|t1_builder_check_points
argument_list|(
argument|T1_Builder  builder
argument_list|,
argument|FT_Int      count
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
DECL|variable|t1_builder_add_point
name|t1_builder_add_point
argument_list|(
argument|T1_Builder  builder
argument_list|,
argument|FT_Pos      x
argument_list|,
argument|FT_Pos      y
argument_list|,
argument|FT_Byte     flag
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
name|t1_builder_add_point1
argument_list|(
argument|T1_Builder  builder
argument_list|,
argument|FT_Pos      x
argument_list|,
argument|FT_Pos      y
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
DECL|variable|t1_builder_add_contour
name|t1_builder_add_contour
argument_list|(
argument|T1_Builder  builder
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|t1_builder_add_contour
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|t1_builder_start_point
argument_list|(
argument|T1_Builder  builder
argument_list|,
argument|FT_Pos      x
argument_list|,
argument|FT_Pos      y
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
DECL|variable|t1_builder_close_contour
name|t1_builder_close_contour
argument_list|(
argument|T1_Builder  builder
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|t1_builder_close_contour
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
comment|/*****                            OTHER                              *****/
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
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|t1_decrypt
argument_list|(
argument|FT_Byte*   buffer
argument_list|,
argument|FT_Offset  length
argument_list|,
argument|FT_UShort  seed
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
comment|/* __PSOBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
