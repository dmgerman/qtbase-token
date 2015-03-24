begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmorx.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT common definition for morx table (specification).     */
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
name|__GXVMORX_H__
end_ifndef
begin_define
DECL|macro|__GXVMORX_H__
define|#
directive|define
name|__GXVMORX_H__
end_define
begin_include
include|#
directive|include
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
file|"gxvcommn.h"
end_include
begin_include
include|#
directive|include
file|"gxvmort.h"
end_include
begin_include
include|#
directive|include
include|FT_SFNT_NAMES_H
end_include
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_morx_subtable_type0_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
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
name|gxv_morx_subtable_type1_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
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
name|gxv_morx_subtable_type2_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
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
name|gxv_morx_subtable_type4_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
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
name|gxv_morx_subtable_type5_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GXVMORX_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
