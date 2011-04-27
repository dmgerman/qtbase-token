begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svotval.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType OpenType validation service (specification).            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2006 by                                                */
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
name|__SVOTVAL_H__
end_ifndef
begin_define
DECL|macro|__SVOTVAL_H__
define|#
directive|define
name|__SVOTVAL_H__
end_define
begin_include
include|#
directive|include
include|FT_OPENTYPE_VALIDATE_H
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
DECL|macro|FT_SERVICE_ID_OPENTYPE_VALIDATE
define|#
directive|define
name|FT_SERVICE_ID_OPENTYPE_VALIDATE
value|"opentype-validate"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|otv_validate_func
modifier|*
name|otv_validate_func
function_decl|)
parameter_list|(
name|FT_Face
specifier|volatile
name|face
parameter_list|,
name|FT_UInt
name|ot_flags
parameter_list|,
name|FT_Bytes
modifier|*
name|base
parameter_list|,
name|FT_Bytes
modifier|*
name|gdef
parameter_list|,
name|FT_Bytes
modifier|*
name|gpos
parameter_list|,
name|FT_Bytes
modifier|*
name|gsub
parameter_list|,
name|FT_Bytes
modifier|*
name|jstf
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|OTvalidate
argument_list|)
end_macro
begin_block
block|{
name|otv_validate_func
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
comment|/* __SVOTVAL_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
