begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmort4.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT mort table validation                                 */
end_comment
begin_comment
comment|/*    body for type4 (Non-Contextual Glyph Substitution) subtable.         */
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
file|"gxvmort.h"
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
value|trace_gxvmort
end_define
begin_function
specifier|static
name|void
DECL|function|gxv_mort_subtable_type4_lookupval_validate
name|gxv_mort_subtable_type4_lookupval_validate
parameter_list|(
name|FT_UShort
name|glyph
parameter_list|,
name|GXV_LookupValueCPtr
name|value_p
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_UNUSED
argument_list|(
name|glyph
argument_list|)
expr_stmt|;
name|gxv_glyphid_validate
argument_list|(
name|value_p
operator|->
name|u
argument_list|,
name|valid
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     +===============+ --------+     | lookup header |         |     +===============+         |     | BinSrchHeader |         |     +===============+         |     | lastGlyph[0]  |         |     +---------------+         |     | firstGlyph[0] |         |    head of lookup table     +---------------+         |             +     | offset[0]     |    ->   |          offset            [byte]     +===============+         |             +     | lastGlyph[1]  |         | (glyphID - firstGlyph) * 2 [byte]     +---------------+         |     | firstGlyph[1] |         |     +---------------+         |     | offset[1]     |         |     +===============+         |                               |      ....                     |                               |     16bit value array         |     +===============+         |     |     value     |<-------+      ....   */
end_comment
begin_function
specifier|static
name|GXV_LookupValueDesc
DECL|function|gxv_mort_subtable_type4_lookupfmt4_transit
name|gxv_mort_subtable_type4_lookupfmt4_transit
parameter_list|(
name|FT_UShort
name|relative_gindex
parameter_list|,
name|GXV_LookupValueCPtr
name|base_value_p
parameter_list|,
name|FT_Bytes
name|lookuptbl_limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_Bytes
name|p
decl_stmt|;
name|FT_Bytes
name|limit
decl_stmt|;
name|FT_UShort
name|offset
decl_stmt|;
name|GXV_LookupValueDesc
name|value
decl_stmt|;
comment|/* XXX: check range? */
name|offset
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|base_value_p
operator|->
name|u
operator|+
name|relative_gindex
operator|*
sizeof|sizeof
argument_list|(
name|FT_UShort
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|=
name|valid
operator|->
name|lookuptbl_head
operator|+
name|offset
expr_stmt|;
name|limit
operator|=
name|lookuptbl_limit
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|value
operator|.
name|u
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_mort_subtable_type4_validate
name|gxv_mort_subtable_type4_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_block
block|{
name|FT_Bytes
name|p
init|=
name|table
decl_stmt|;
name|GXV_NAME_ENTER
argument_list|(
literal|"mort chain subtable type4 "
literal|"(Non-Contextual Glyph Substitution)"
argument_list|)
expr_stmt|;
name|valid
operator|->
name|lookupval_sign
operator|=
name|GXV_LOOKUPVALUE_UNSIGNED
expr_stmt|;
name|valid
operator|->
name|lookupval_func
operator|=
name|gxv_mort_subtable_type4_lookupval_validate
expr_stmt|;
name|valid
operator|->
name|lookupfmt4_trans
operator|=
name|gxv_mort_subtable_type4_lookupfmt4_transit
expr_stmt|;
name|gxv_LookupTable_validate
argument_list|(
name|p
argument_list|,
name|limit
argument_list|,
name|valid
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
