begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cidparse.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CID-keyed Type1 parser (specification).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2004, 2014 by                                           */
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
name|__CIDPARSE_H__
end_ifndef
begin_define
DECL|macro|__CIDPARSE_H__
define|#
directive|define
name|__CIDPARSE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_AUX_H
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
comment|/*    CID_Parser                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A CID_Parser is an object used to parse a Type 1 fonts very        */
end_comment
begin_comment
comment|/*    quickly.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root           :: The root PS_ParserRec fields.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream         :: The current input stream.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    postscript     :: A pointer to the data to be parsed.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    postscript_len :: The length of the data to be parsed.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    data_offset    :: The start position of the binary data (i.e., the */
end_comment
begin_comment
comment|/*                      end of the data to be parsed.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    binary_length  :: The length of the data after the `StartData'     */
end_comment
begin_comment
comment|/*                      command if the data format is hexadecimal.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cid            :: A structure which holds the information about    */
end_comment
begin_comment
comment|/*                      the current font.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_dict       :: The number of font dictionaries.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CID_Parser_
typedef|typedef
struct|struct
name|CID_Parser_
block|{
DECL|member|root
name|PS_ParserRec
name|root
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
DECL|member|postscript
name|FT_Byte
modifier|*
name|postscript
decl_stmt|;
DECL|member|postscript_len
name|FT_Long
name|postscript_len
decl_stmt|;
DECL|member|data_offset
name|FT_ULong
name|data_offset
decl_stmt|;
DECL|member|binary_length
name|FT_Long
name|binary_length
decl_stmt|;
DECL|member|cid
name|CID_FaceInfo
name|cid
decl_stmt|;
DECL|member|num_dict
name|FT_Int
name|num_dict
decl_stmt|;
block|}
DECL|typedef|CID_Parser
name|CID_Parser
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cid_parser_new
argument_list|(
argument|CID_Parser*    parser
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
begin_expr_stmt
DECL|variable|cid_parser_done
name|cid_parser_done
argument_list|(
name|CID_Parser
operator|*
name|parser
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                            PARSING ROUTINES                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|cid_parser_skip_spaces
define|#
directive|define
name|cid_parser_skip_spaces
parameter_list|(
name|p
parameter_list|)
define|\
value|(p)->root.funcs.skip_spaces(&(p)->root )
end_define
begin_define
DECL|macro|cid_parser_skip_PS_token
define|#
directive|define
name|cid_parser_skip_PS_token
parameter_list|(
name|p
parameter_list|)
define|\
value|(p)->root.funcs.skip_PS_token(&(p)->root )
end_define
begin_define
DECL|macro|cid_parser_to_int
define|#
directive|define
name|cid_parser_to_int
parameter_list|(
name|p
parameter_list|)
value|(p)->root.funcs.to_int(&(p)->root )
end_define
begin_define
DECL|macro|cid_parser_to_fixed
define|#
directive|define
name|cid_parser_to_fixed
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|(p)->root.funcs.to_fixed(&(p)->root, t )
end_define
begin_define
DECL|macro|cid_parser_to_coord_array
define|#
directive|define
name|cid_parser_to_coord_array
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
define|\
value|(p)->root.funcs.to_coord_array(&(p)->root, m, c )
end_define
begin_define
DECL|macro|cid_parser_to_fixed_array
define|#
directive|define
name|cid_parser_to_fixed_array
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|(p)->root.funcs.to_fixed_array(&(p)->root, m, f, t )
end_define
begin_define
DECL|macro|cid_parser_to_token
define|#
directive|define
name|cid_parser_to_token
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
define|\
value|(p)->root.funcs.to_token(&(p)->root, t )
end_define
begin_define
DECL|macro|cid_parser_to_token_array
define|#
directive|define
name|cid_parser_to_token_array
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
define|\
value|(p)->root.funcs.to_token_array(&(p)->root, t, m, c )
end_define
begin_define
DECL|macro|cid_parser_load_field
define|#
directive|define
name|cid_parser_load_field
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|o
parameter_list|)
define|\
value|(p)->root.funcs.load_field(&(p)->root, f, o, 0, 0 )
end_define
begin_define
DECL|macro|cid_parser_load_field_table
define|#
directive|define
name|cid_parser_load_field_table
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|o
parameter_list|)
define|\
value|(p)->root.funcs.load_field_table(&(p)->root, f, o, 0, 0 )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CIDPARSE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
