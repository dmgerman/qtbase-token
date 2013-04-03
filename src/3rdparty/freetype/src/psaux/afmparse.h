begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afmparse.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    AFM parser (specification).                                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006 by                                                      */
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
name|__AFMPARSE_H__
end_ifndef
begin_define
DECL|macro|__AFMPARSE_H__
define|#
directive|define
name|__AFMPARSE_H__
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
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|afm_parser_init
parameter_list|(
name|AFM_Parser
name|parser
parameter_list|,
name|FT_Memory
name|memory
parameter_list|,
name|FT_Byte
modifier|*
name|base
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|afm_parser_done
name|afm_parser_done
argument_list|(
argument|AFM_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|afm_parser_done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|afm_parser_parse
argument_list|(
argument|AFM_Parser  parser
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
DECL|enum|AFM_ValueType_
enum|enum
name|AFM_ValueType_
block|{
DECL|enumerator|AFM_VALUE_TYPE_STRING
name|AFM_VALUE_TYPE_STRING
block|,
DECL|enumerator|AFM_VALUE_TYPE_NAME
name|AFM_VALUE_TYPE_NAME
block|,
DECL|enumerator|AFM_VALUE_TYPE_FIXED
name|AFM_VALUE_TYPE_FIXED
block|,
comment|/* real number */
DECL|enumerator|AFM_VALUE_TYPE_INTEGER
name|AFM_VALUE_TYPE_INTEGER
block|,
DECL|enumerator|AFM_VALUE_TYPE_BOOL
name|AFM_VALUE_TYPE_BOOL
block|,
DECL|enumerator|AFM_VALUE_TYPE_INDEX
name|AFM_VALUE_TYPE_INDEX
comment|/* glyph index */
block|}
enum|;
end_enum
begin_typedef
DECL|struct|AFM_ValueRec_
typedef|typedef
struct|struct
name|AFM_ValueRec_
block|{
DECL|member|type
name|enum
name|AFM_ValueType_
name|type
decl_stmt|;
union|union
block|{
DECL|member|s
name|char
modifier|*
name|s
decl_stmt|;
DECL|member|f
name|FT_Fixed
name|f
decl_stmt|;
DECL|member|i
name|FT_Int
name|i
decl_stmt|;
DECL|member|b
name|FT_Bool
name|b
decl_stmt|;
block|}
DECL|member|u
name|u
union|;
block|}
DECL|typedef|AFM_ValueRec
DECL|typedef|AFM_Value
name|AFM_ValueRec
operator|,
typedef|*
name|AFM_Value
typedef|;
end_typedef
begin_define
DECL|macro|AFM_MAX_ARGUMENTS
define|#
directive|define
name|AFM_MAX_ARGUMENTS
value|5
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|afm_parser_read_vals
argument_list|(
argument|AFM_Parser  parser
argument_list|,
argument|AFM_Value   vals
argument_list|,
argument|FT_UInt     n
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* read the next key from the next line or column */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|char*
argument_list|)
end_macro
begin_macro
DECL|variable|afm_parser_next_key
name|afm_parser_next_key
argument_list|(
argument|AFM_Parser  parser
argument_list|,
argument|FT_Bool     line
argument_list|,
argument|FT_Offset*  len
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
comment|/* __AFMPARSE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
