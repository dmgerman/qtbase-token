begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmort0.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT mort table validation                                 */
end_comment
begin_comment
comment|/*    body for type0 (Indic Script Rearrangement) subtable.                */
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
begin_decl_stmt
DECL|variable|GXV_Mort_IndicScript_Msg
specifier|static
specifier|const
name|char
modifier|*
name|GXV_Mort_IndicScript_Msg
index|[]
init|=
block|{
literal|"no change"
block|,
literal|"Ax => xA"
block|,
literal|"xD => Dx"
block|,
literal|"AxD => DxA"
block|,
literal|"ABx => xAB"
block|,
literal|"ABx => xBA"
block|,
literal|"xCD => CDx"
block|,
literal|"xCD => DCx"
block|,
literal|"AxCD => CDxA"
block|,
literal|"AxCD => DCxA"
block|,
literal|"ABxD => DxAB"
block|,
literal|"ABxD => DxBA"
block|,
literal|"ABxCD => CDxAB"
block|,
literal|"ABxCD => CDxBA"
block|,
literal|"ABxCD => DCxAB"
block|,
literal|"ABxCD => DCxBA"
block|,    }
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|void
DECL|function|gxv_mort_subtable_type0_entry_validate
name|gxv_mort_subtable_type0_entry_validate
parameter_list|(
name|FT_Byte
name|state
parameter_list|,
name|FT_UShort
name|flags
parameter_list|,
name|GXV_StateTable_GlyphOffsetCPtr
name|glyphOffset_p
parameter_list|,
name|FT_Bytes
name|table
parameter_list|,
name|FT_Bytes
name|limit
parameter_list|,
name|GXV_Validator
name|valid
parameter_list|)
block|{
name|FT_UShort
name|markFirst
decl_stmt|;
name|FT_UShort
name|dontAdvance
decl_stmt|;
name|FT_UShort
name|markLast
decl_stmt|;
name|FT_UShort
name|reserved
decl_stmt|;
name|FT_UShort
name|verb
init|=
literal|0
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|table
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|limit
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|GXV_Mort_IndicScript_Msg
index|[
name|verb
index|]
argument_list|)
expr_stmt|;
comment|/* for the non-debugging */
name|FT_UNUSED
argument_list|(
name|glyphOffset_p
argument_list|)
expr_stmt|;
comment|/* case                  */
name|markFirst
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|15
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|dontAdvance
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|14
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|markLast
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
operator|(
name|flags
operator|>>
literal|13
operator|)
operator|&
literal|1
argument_list|)
expr_stmt|;
name|reserved
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|flags
operator|&
literal|0x1FF0
argument_list|)
expr_stmt|;
name|verb
operator|=
call|(
name|FT_UShort
call|)
argument_list|(
name|flags
operator|&
literal|0x000F
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|"  IndicScript MorphRule for glyphOffset 0x%04x"
operator|,
name|glyphOffset_p
operator|->
name|u
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" markFirst=%01d"
operator|,
name|markFirst
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" dontAdvance=%01d"
operator|,
name|dontAdvance
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" markLast=%01d"
operator|,
name|markLast
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" %02d"
operator|,
name|verb
operator|)
argument_list|)
expr_stmt|;
name|GXV_TRACE
argument_list|(
operator|(
literal|" %s\n"
operator|,
name|GXV_Mort_IndicScript_Msg
index|[
name|verb
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|<
name|reserved
condition|)
block|{
name|GXV_TRACE
argument_list|(
operator|(
literal|" non-zero bits found in reserved range\n"
operator|)
argument_list|)
expr_stmt|;
name|FT_INVALID_DATA
expr_stmt|;
block|}
else|else
name|GXV_TRACE
argument_list|(
operator|(
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|gxv_mort_subtable_type0_validate
name|gxv_mort_subtable_type0_validate
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
literal|"mort chain subtable type0 (Indic-Script Rearrangement)"
argument_list|)
expr_stmt|;
name|GXV_LIMIT_CHECK
argument_list|(
name|GXV_STATETABLE_HEADER_SIZE
argument_list|)
expr_stmt|;
name|valid
operator|->
name|statetable
operator|.
name|optdata
operator|=
name|NULL
expr_stmt|;
name|valid
operator|->
name|statetable
operator|.
name|optdata_load_func
operator|=
name|NULL
expr_stmt|;
name|valid
operator|->
name|statetable
operator|.
name|subtable_setup_func
operator|=
name|NULL
expr_stmt|;
name|valid
operator|->
name|statetable
operator|.
name|entry_glyphoffset_fmt
operator|=
name|GXV_GLYPHOFFSET_NONE
expr_stmt|;
name|valid
operator|->
name|statetable
operator|.
name|entry_validate_func
operator|=
name|gxv_mort_subtable_type0_entry_validate
expr_stmt|;
name|gxv_StateTable_validate
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
