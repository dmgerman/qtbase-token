begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmorx4.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT morx table validation                                 */
end_comment
begin_comment
comment|/*    body for "morx" type4 (Non-Contextual Glyph Substitution) subtable.  */
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
begin_include
include|#
directive|include
file|"gxvmorx.h"
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_gxvmorx
end_define
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_morx_subtable_type4_validate
name|gxv_morx_subtable_type4_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  gxvalid
argument_list|)
end_macro
begin_block
block|{
name|GXV_NAME_ENTER
argument_list|(
literal|"morx chain subtable type4 "
literal|"(Non-Contextual Glyph Substitution)"
argument_list|)
expr_stmt|;
name|gxv_mort_subtable_type4_validate
argument_list|(
name|table
argument_list|,
name|limit
argument_list|,
name|gxvalid
argument_list|)
expr_stmt|;
name|GXV_EXIT
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
