begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  otvalid.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType table validation (specification only).                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2008 by                                                */
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
name|__OTVALID_H__
end_ifndef
begin_define
DECL|macro|__OTVALID_H__
define|#
directive|define
name|__OTVALID_H__
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
file|"otverror.h"
end_include
begin_comment
comment|/* must come before FT_INTERNAL_VALIDATE_H */
end_comment
begin_include
include|#
directive|include
include|FT_INTERNAL_VALIDATE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|otv_BASE_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|FT_Validator
name|valid
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* GSUB and GPOS tables should already be validated; */
end_comment
begin_comment
comment|/* if missing, set corresponding argument to 0       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|otv_GDEF_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Bytes      gsub
argument_list|,
argument|FT_Bytes      gpos
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  valid
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
name|otv_GPOS_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  valid
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
name|otv_GSUB_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* GSUB and GPOS tables should already be validated; */
end_comment
begin_comment
comment|/* if missing, set corresponding argument to 0       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|otv_JSTF_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Bytes      gsub
argument_list|,
argument|FT_Bytes      gpos
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  valid
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
name|otv_MATH_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_UInt       glyph_count
argument_list|,
argument|FT_Validator  ftvalid
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
comment|/* __OTVALID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
