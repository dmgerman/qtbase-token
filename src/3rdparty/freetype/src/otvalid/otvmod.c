begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  otvmod.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType's OpenType validation module implementation (body).         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2006, 2007, 2008 by                              */
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
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TAGS_H
end_include
begin_include
include|#
directive|include
include|FT_OPENTYPE_VALIDATE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_OPENTYPE_VALIDATE_H
end_include
begin_include
include|#
directive|include
file|"otvmod.h"
end_include
begin_include
include|#
directive|include
file|"otvalid.h"
end_include
begin_include
include|#
directive|include
file|"otvcommn.h"
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
value|trace_otvmodule
end_define
begin_function
specifier|static
name|FT_Error
DECL|function|otv_load_table
name|otv_load_table
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Tag
name|tag
parameter_list|,
name|FT_Byte
modifier|*
specifier|volatile
modifier|*
name|table
parameter_list|,
name|FT_ULong
modifier|*
name|table_len
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
decl_stmt|;
name|error
operator|=
name|FT_Load_Sfnt_Table
argument_list|(
name|face
argument_list|,
name|tag
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
name|OTV_Err_Table_Missing
condition|)
return|return
name|OTV_Err_Ok
return|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|FT_ALLOC
argument_list|(
operator|*
name|table
argument_list|,
operator|*
name|table_len
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|error
operator|=
name|FT_Load_Sfnt_Table
argument_list|(
name|face
argument_list|,
name|tag
argument_list|,
literal|0
argument_list|,
operator|*
name|table
argument_list|,
name|table_len
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|otv_validate
name|otv_validate
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
name|ot_base
parameter_list|,
name|FT_Bytes
modifier|*
name|ot_gdef
parameter_list|,
name|FT_Bytes
modifier|*
name|ot_gpos
parameter_list|,
name|FT_Bytes
modifier|*
name|ot_gsub
parameter_list|,
name|FT_Bytes
modifier|*
name|ot_jstf
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|OTV_Err_Ok
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|base
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|gdef
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|gpos
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|gsub
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|jstf
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|math
decl_stmt|;
name|FT_ULong
name|len_base
decl_stmt|,
name|len_gdef
decl_stmt|,
name|len_gpos
decl_stmt|,
name|len_gsub
decl_stmt|,
name|len_jstf
decl_stmt|;
name|FT_ULong
name|len_math
decl_stmt|;
name|FT_UInt
name|num_glyphs
init|=
operator|(
name|FT_UInt
operator|)
name|face
operator|->
name|num_glyphs
decl_stmt|;
name|FT_ValidatorRec
specifier|volatile
name|valid
decl_stmt|;
name|base
operator|=
name|gdef
operator|=
name|gpos
operator|=
name|gsub
operator|=
name|jstf
operator|=
name|math
operator|=
name|NULL
expr_stmt|;
name|len_base
operator|=
name|len_gdef
operator|=
name|len_gpos
operator|=
name|len_gsub
operator|=
name|len_jstf
operator|=
name|len_math
operator|=
literal|0
expr_stmt|;
comment|/*      * XXX: OpenType tables cannot handle 32-bit glyph index,      *      although broken TrueType can have 32-bit glyph index.      */
if|if
condition|(
name|face
operator|->
name|num_glyphs
operator|>
literal|0xFFFFL
condition|)
block|{
name|FT_TRACE1
argument_list|(
operator|(
literal|"otv_validate: Invalid glyphs index (0x0000FFFF - 0x%08x) "
operator|,
name|face
operator|->
name|num_glyphs
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE1
argument_list|(
operator|(
literal|"are not handled by OpenType tables\n"
operator|)
argument_list|)
expr_stmt|;
name|num_glyphs
operator|=
literal|0xFFFF
expr_stmt|;
block|}
comment|/* load tables */
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_BASE
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_BASE
argument_list|,
operator|&
name|base
argument_list|,
operator|&
name|len_base
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_GDEF
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_GDEF
argument_list|,
operator|&
name|gdef
argument_list|,
operator|&
name|len_gdef
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_GPOS
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_GPOS
argument_list|,
operator|&
name|gpos
argument_list|,
operator|&
name|len_gpos
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_GSUB
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_GSUB
argument_list|,
operator|&
name|gsub
argument_list|,
operator|&
name|len_gsub
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_JSTF
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_JSTF
argument_list|,
operator|&
name|jstf
argument_list|,
operator|&
name|len_jstf
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|ot_flags
operator|&
name|FT_VALIDATE_MATH
condition|)
block|{
name|error
operator|=
name|otv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_MATH
argument_list|,
operator|&
name|math
argument_list|,
operator|&
name|len_math
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
comment|/* validate tables */
if|if
condition|(
name|base
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|base
argument_list|,
name|base
operator|+
name|len_base
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_BASE_validate
argument_list|(
name|base
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|gpos
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|gpos
argument_list|,
name|gpos
operator|+
name|len_gpos
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_GPOS_validate
argument_list|(
name|gpos
argument_list|,
name|num_glyphs
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|gsub
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|gsub
argument_list|,
name|gsub
operator|+
name|len_gsub
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_GSUB_validate
argument_list|(
name|gsub
argument_list|,
name|num_glyphs
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|gdef
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|gdef
argument_list|,
name|gdef
operator|+
name|len_gdef
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_GDEF_validate
argument_list|(
name|gdef
argument_list|,
name|gsub
argument_list|,
name|gpos
argument_list|,
name|num_glyphs
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|jstf
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|jstf
argument_list|,
name|jstf
operator|+
name|len_jstf
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_JSTF_validate
argument_list|(
name|jstf
argument_list|,
name|gsub
argument_list|,
name|gpos
argument_list|,
name|num_glyphs
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|math
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|math
argument_list|,
name|math
operator|+
name|len_math
argument_list|,
name|FT_VALIDATE_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft_setjmp
argument_list|(
name|valid
operator|.
name|jump_buffer
argument_list|)
operator|==
literal|0
condition|)
name|otv_MATH_validate
argument_list|(
name|math
argument_list|,
name|num_glyphs
argument_list|,
operator|&
name|valid
argument_list|)
expr_stmt|;
name|error
operator|=
name|valid
operator|.
name|error
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
operator|*
name|ot_base
operator|=
operator|(
name|FT_Bytes
operator|)
name|base
expr_stmt|;
operator|*
name|ot_gdef
operator|=
operator|(
name|FT_Bytes
operator|)
name|gdef
expr_stmt|;
operator|*
name|ot_gpos
operator|=
operator|(
name|FT_Bytes
operator|)
name|gpos
expr_stmt|;
operator|*
name|ot_gsub
operator|=
operator|(
name|FT_Bytes
operator|)
name|gsub
expr_stmt|;
operator|*
name|ot_jstf
operator|=
operator|(
name|FT_Bytes
operator|)
name|jstf
expr_stmt|;
name|Exit
label|:
if|if
condition|(
name|error
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
decl_stmt|;
name|FT_FREE
argument_list|(
name|base
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|gdef
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|gpos
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|gsub
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|jstf
argument_list|)
expr_stmt|;
block|}
block|{
name|FT_Memory
name|memory
init|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
decl_stmt|;
name|FT_FREE
argument_list|(
name|math
argument_list|)
expr_stmt|;
comment|/* Can't return this as API is frozen */
block|}
return|return
name|error
return|;
block|}
end_function
begin_decl_stmt
specifier|static
DECL|variable|otvalid_interface
specifier|const
name|FT_Service_OTvalidateRec
name|otvalid_interface
init|=
block|{
name|otv_validate
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
DECL|variable|otvalid_services
specifier|const
name|FT_ServiceDescRec
name|otvalid_services
index|[]
init|=
block|{
block|{
name|FT_SERVICE_ID_OPENTYPE_VALIDATE
block|,
operator|&
name|otvalid_interface
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|FT_Pointer
DECL|function|otvalid_get_service
name|otvalid_get_service
parameter_list|(
name|FT_Module
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|service_id
parameter_list|)
block|{
name|FT_UNUSED
argument_list|(
name|module
argument_list|)
expr_stmt|;
return|return
name|ft_service_list_lookup
argument_list|(
name|otvalid_services
argument_list|,
name|service_id
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|otv_module_class
specifier|const
name|FT_Module_Class
name|otv_module_class
init|=
block|{
literal|0
block|,
sizeof|sizeof
argument_list|(
name|FT_ModuleRec
argument_list|)
block|,
literal|"otvalid"
block|,
literal|0x10000L
block|,
literal|0x20000L
block|,
literal|0
block|,
comment|/* module-specific interface */
operator|(
name|FT_Module_Constructor
operator|)
literal|0
block|,
operator|(
name|FT_Module_Destructor
operator|)
literal|0
block|,
operator|(
name|FT_Module_Requester
operator|)
name|otvalid_get_service
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* END */
end_comment
end_unit
