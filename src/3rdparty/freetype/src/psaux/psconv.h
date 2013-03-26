begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  psconv.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Some convenience conversions (specification).                        */
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
name|__PSCONV_H__
end_ifndef
begin_define
DECL|macro|__PSCONV_H__
define|#
directive|define
name|__PSCONV_H__
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
name|FT_Int
parameter_list|)
function_decl|PS_Conv_Strtol
parameter_list|(
name|FT_Byte
modifier|*
modifier|*
name|cursor
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|,
name|FT_Int
name|base
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|PS_Conv_ToInt
name|PS_Conv_ToInt
argument_list|(
name|FT_Byte
operator|*
operator|*
name|cursor
argument_list|,
name|FT_Byte
operator|*
name|limit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|PS_Conv_ToFixed
argument_list|(
argument|FT_Byte**  cursor
argument_list|,
argument|FT_Byte*   limit
argument_list|,
argument|FT_Int     power_ten
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
begin_endif
unit|FT_LOCAL( FT_UInt )   PS_Conv_StringDecode( FT_Byte**  cursor,                         FT_Byte*   limit,                         FT_Byte*   buffer,                         FT_Offset  n );
endif|#
directive|endif
end_endif
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
DECL|variable|PS_Conv_ASCIIHexDecode
name|PS_Conv_ASCIIHexDecode
argument_list|(
argument|FT_Byte**  cursor
argument_list|,
argument|FT_Byte*   limit
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_Offset  n
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|PS_Conv_EexecDecode
argument_list|(
argument|FT_Byte**   cursor
argument_list|,
argument|FT_Byte*    limit
argument_list|,
argument|FT_Byte*    buffer
argument_list|,
argument|FT_Offset   n
argument_list|,
argument|FT_UShort*  seed
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
comment|/* __PSCONV_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
