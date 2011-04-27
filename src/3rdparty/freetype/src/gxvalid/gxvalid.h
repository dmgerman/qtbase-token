begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvalid.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTyeeGX/AAT table validation (specification only).                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2005 by suzuki toshiya, Masatake YAMATO, Red Hat K.K.,       */
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
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
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
name|__GXVALID_H__
end_ifndef
begin_define
DECL|macro|__GXVALID_H__
define|#
directive|define
name|__GXVALID_H__
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
file|"gxverror.h"
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
function_decl|gxv_feat_validate
parameter_list|(
name|FT_Bytes
name|table
parameter_list|,
name|FT_Face
name|face
parameter_list|,
name|FT_Validator
name|valid
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
name|gxv_bsln_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_trak_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_just_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_mort_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_morx_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_kern_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_kern_validate_classic
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
argument_list|,
argument|FT_Int        dialect_flags
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
name|gxv_opbd_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_prop_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
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
name|gxv_lcar_validate
argument_list|(
argument|FT_Bytes      table
argument_list|,
argument|FT_Face       face
argument_list|,
argument|FT_Validator  valid
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
comment|/* __GXVALID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
