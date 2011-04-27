begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svgxval.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for validating TrueTypeGX/AAT tables (specification).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005 by                                                */
end_comment
begin_comment
comment|/*  Masatake YAMATO, Red Hat K.K.,                                         */
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
name|__SVGXVAL_H__
end_ifndef
begin_define
DECL|macro|__SVGXVAL_H__
define|#
directive|define
name|__SVGXVAL_H__
end_define
begin_include
include|#
directive|include
include|FT_GX_VALIDATE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_VALIDATE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_GX_VALIDATE
define|#
directive|define
name|FT_SERVICE_ID_GX_VALIDATE
value|"truetypegx-validate"
end_define
begin_define
DECL|macro|FT_SERVICE_ID_CLASSICKERN_VALIDATE
define|#
directive|define
name|FT_SERVICE_ID_CLASSICKERN_VALIDATE
value|"classickern-validate"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|gxv_validate_func
modifier|*
name|gxv_validate_func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|gx_flags
parameter_list|,
name|FT_Bytes
name|tables
index|[
name|FT_VALIDATE_GX_LENGTH
index|]
parameter_list|,
name|FT_UInt
name|table_length
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|ckern_validate_func
modifier|*
name|ckern_validate_func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|ckern_flags
parameter_list|,
name|FT_Bytes
modifier|*
name|ckern_table
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|GXvalidate
argument_list|)
end_macro
begin_block
block|{
name|gxv_validate_func
name|validate
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|CKERNvalidate
argument_list|)
end_macro
begin_block
block|{
name|ckern_validate_func
name|validate
decl_stmt|;
block|}
end_block
begin_empty_stmt
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
comment|/* __SVGXVAL_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
