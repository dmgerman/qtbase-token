begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1parse.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 parser (specification).                                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2008 by                               */
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
name|__T1PARSE_H__
end_ifndef
begin_define
DECL|macro|__T1PARSE_H__
define|#
directive|define
name|__T1PARSE_H__
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
comment|/*    T1_ParserRec                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A PS_ParserRec is an object used to parse a Type 1 fonts very      */
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
comment|/*    root         :: The root parser.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream       :: The current input stream.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    base_dict    :: A pointer to the top-level dictionary.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    base_len     :: The length in bytes of the top dictionary.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    private_dict :: A pointer to the private dictionary.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    private_len  :: The length in bytes of the private dictionary.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    in_pfb       :: A boolean.  Indicates that we are handling a PFB   */
end_comment
begin_comment
comment|/*                    file.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    in_memory    :: A boolean.  Indicates a memory-based stream.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    single_block :: A boolean.  Indicates that the private dictionary  */
end_comment
begin_comment
comment|/*                    is stored in lieu of the base dictionary.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|T1_ParserRec_
typedef|typedef
struct|struct
name|T1_ParserRec_
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
name|FT_ULong
name|base_len
decl_stmt|;
DECL|member|private_dict
name|FT_Byte
modifier|*
name|private_dict
decl_stmt|;
DECL|member|private_len
name|FT_ULong
name|private_len
decl_stmt|;
DECL|member|in_pfb
name|FT_Bool
name|in_pfb
decl_stmt|;
DECL|member|in_memory
name|FT_Bool
name|in_memory
decl_stmt|;
DECL|member|single_block
name|FT_Bool
name|single_block
decl_stmt|;
block|}
DECL|typedef|T1_ParserRec
DECL|typedef|T1_Parser
name|T1_ParserRec
operator|,
typedef|*
name|T1_Parser
typedef|;
end_typedef
begin_define
DECL|macro|T1_Add_Table
define|#
directive|define
name|T1_Add_Table
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|)
value|(p)->funcs.add( (p), i, o, l )
end_define
begin_define
DECL|macro|T1_Done_Table
define|#
directive|define
name|T1_Done_Table
parameter_list|(
name|p
parameter_list|)
define|\
value|do                        \           {                         \             if ( (p)->funcs.done )  \               (p)->funcs.done( p ); \           } while ( 0 )
end_define
begin_define
DECL|macro|T1_Release_Table
define|#
directive|define
name|T1_Release_Table
parameter_list|(
name|p
parameter_list|)
define|\
value|do                           \           {                            \             if ( (p)->funcs.release )  \               (p)->funcs.release( p ); \           } while ( 0 )
end_define
begin_define
DECL|macro|T1_Skip_Spaces
define|#
directive|define
name|T1_Skip_Spaces
parameter_list|(
name|p
parameter_list|)
value|(p)->root.funcs.skip_spaces(&(p)->root )
end_define
begin_define
DECL|macro|T1_Skip_PS_Token
define|#
directive|define
name|T1_Skip_PS_Token
parameter_list|(
name|p
parameter_list|)
value|(p)->root.funcs.skip_PS_token(&(p)->root )
end_define
begin_define
DECL|macro|T1_ToInt
define|#
directive|define
name|T1_ToInt
parameter_list|(
name|p
parameter_list|)
value|(p)->root.funcs.to_int(&(p)->root )
end_define
begin_define
DECL|macro|T1_ToFixed
define|#
directive|define
name|T1_ToFixed
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|(p)->root.funcs.to_fixed(&(p)->root, t )
end_define
begin_define
DECL|macro|T1_ToCoordArray
define|#
directive|define
name|T1_ToCoordArray
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
DECL|macro|T1_ToFixedArray
define|#
directive|define
name|T1_ToFixedArray
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
DECL|macro|T1_ToToken
define|#
directive|define
name|T1_ToToken
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
define|\
value|(p)->root.funcs.to_token(&(p)->root, t )
end_define
begin_define
DECL|macro|T1_ToTokenArray
define|#
directive|define
name|T1_ToTokenArray
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
DECL|macro|T1_Load_Field
define|#
directive|define
name|T1_Load_Field
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|o
parameter_list|,
name|m
parameter_list|,
name|pf
parameter_list|)
define|\
value|(p)->root.funcs.load_field(&(p)->root, f, o, m, pf )
end_define
begin_define
DECL|macro|T1_Load_Field_Table
define|#
directive|define
name|T1_Load_Field_Table
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|o
parameter_list|,
name|m
parameter_list|,
name|pf
parameter_list|)
define|\
value|(p)->root.funcs.load_field_table(&(p)->root, f, o, m, pf )
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_New_Parser
argument_list|(
argument|T1_Parser      parser
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|T1_Get_Private_Dict
name|T1_Get_Private_Dict
argument_list|(
argument|T1_Parser      parser
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
DECL|variable|parser
name|T1_Finalize_Parser
argument_list|(
argument|T1_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|parser
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
comment|/* __T1PARSE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
