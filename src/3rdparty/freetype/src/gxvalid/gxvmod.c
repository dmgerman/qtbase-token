begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmod.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType's TrueTypeGX/AAT validation module implementation (body).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004-2015 by                                                 */
end_comment
begin_comment
comment|/*  suzuki toshiya, Masatake YAMATO, Red Hat K.K.,                         */
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
include|FT_GX_VALIDATE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_GX_VALIDATE_H
end_include
begin_include
include|#
directive|include
file|"gxvmod.h"
end_include
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
value|trace_gxvmodule
end_define
begin_function
specifier|static
name|FT_Error
DECL|function|gxv_load_table
name|gxv_load_table
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
name|FT_ERR_EQ
argument_list|(
name|error
argument_list|,
name|Table_Missing
argument_list|)
condition|)
return|return
name|FT_Err_Ok
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
begin_define
DECL|macro|GXV_TABLE_DECL
define|#
directive|define
name|GXV_TABLE_DECL
parameter_list|(
name|_sfnt
parameter_list|)
define|\
value|FT_Byte* volatile  _sfnt          = NULL; \           FT_ULong            len_ ## _sfnt = 0
end_define
begin_define
DECL|macro|GXV_TABLE_LOAD
define|#
directive|define
name|GXV_TABLE_LOAD
parameter_list|(
name|_sfnt
parameter_list|)
define|\
value|if ( ( FT_VALIDATE_ ## _sfnt ## _INDEX< table_count )&& \                ( gx_flags& FT_VALIDATE_ ## _sfnt )            )    \           {                                                         \             error = gxv_load_table( face, TTAG_ ## _sfnt,           \&_sfnt,&len_ ## _sfnt );       \             if ( error )                                            \               goto Exit;                                            \           }
end_define
begin_define
DECL|macro|GXV_TABLE_VALIDATE
define|#
directive|define
name|GXV_TABLE_VALIDATE
parameter_list|(
name|_sfnt
parameter_list|)
define|\
value|if ( _sfnt )                                               \           {                                                          \             ft_validator_init(&valid, _sfnt, _sfnt + len_ ## _sfnt, \                                FT_VALIDATE_DEFAULT );                \             if ( ft_setjmp( valid.jump_buffer ) == 0 )               \               gxv_ ## _sfnt ## _validate( _sfnt, face,&valid );     \             error = valid.error;                                     \             if ( error )                                             \               goto Exit;                                             \           }
end_define
begin_define
DECL|macro|GXV_TABLE_SET
define|#
directive|define
name|GXV_TABLE_SET
parameter_list|(
name|_sfnt
parameter_list|)
define|\
value|if ( FT_VALIDATE_ ## _sfnt ## _INDEX< table_count )        \             tables[FT_VALIDATE_ ## _sfnt ## _INDEX] = (FT_Bytes)_sfnt
end_define
begin_function
specifier|static
name|FT_Error
DECL|function|gxv_validate
name|gxv_validate
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
name|table_count
parameter_list|)
block|{
name|FT_Memory
specifier|volatile
name|memory
init|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_ValidatorRec
specifier|volatile
name|valid
decl_stmt|;
name|FT_UInt
name|i
decl_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|feat
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|bsln
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|trak
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|just
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|mort
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|morx
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|kern
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|opbd
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|prop
argument_list|)
expr_stmt|;
name|GXV_TABLE_DECL
argument_list|(
name|lcar
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|table_count
condition|;
name|i
operator|++
control|)
name|tables
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
comment|/* load tables */
name|GXV_TABLE_LOAD
argument_list|(
name|feat
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|bsln
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|trak
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|just
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|mort
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|morx
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|kern
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|opbd
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|prop
argument_list|)
expr_stmt|;
name|GXV_TABLE_LOAD
argument_list|(
name|lcar
argument_list|)
expr_stmt|;
comment|/* validate tables */
name|GXV_TABLE_VALIDATE
argument_list|(
name|feat
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|bsln
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|trak
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|just
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|mort
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|morx
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|kern
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|opbd
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|prop
argument_list|)
expr_stmt|;
name|GXV_TABLE_VALIDATE
argument_list|(
name|lcar
argument_list|)
expr_stmt|;
comment|/* Set results */
name|GXV_TABLE_SET
argument_list|(
name|feat
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|mort
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|morx
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|bsln
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|just
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|kern
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|opbd
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|trak
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|prop
argument_list|)
expr_stmt|;
name|GXV_TABLE_SET
argument_list|(
name|lcar
argument_list|)
expr_stmt|;
name|Exit
label|:
if|if
condition|(
name|error
condition|)
block|{
name|FT_FREE
argument_list|(
name|feat
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|bsln
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|trak
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|just
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|mort
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|morx
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|kern
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|opbd
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|prop
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|lcar
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|classic_kern_validate
name|classic_kern_validate
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
block|{
name|FT_Memory
specifier|volatile
name|memory
init|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
decl_stmt|;
name|FT_Byte
modifier|*
specifier|volatile
name|ckern
init|=
name|NULL
decl_stmt|;
name|FT_ULong
name|len_ckern
init|=
literal|0
decl_stmt|;
comment|/* without volatile on `error' GCC 4.1.1. emits:                         */
comment|/*  warning: variable 'error' might be clobbered by 'longjmp' or 'vfork' */
comment|/* this warning seems spurious but ---                                   */
name|FT_Error
specifier|volatile
name|error
decl_stmt|;
name|FT_ValidatorRec
specifier|volatile
name|valid
decl_stmt|;
operator|*
name|ckern_table
operator|=
name|NULL
expr_stmt|;
name|error
operator|=
name|gxv_load_table
argument_list|(
name|face
argument_list|,
name|TTAG_kern
argument_list|,
operator|&
name|ckern
argument_list|,
operator|&
name|len_ckern
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|ckern
condition|)
block|{
name|ft_validator_init
argument_list|(
operator|&
name|valid
argument_list|,
name|ckern
argument_list|,
name|ckern
operator|+
name|len_ckern
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
name|gxv_kern_validate_classic
argument_list|(
name|ckern
argument_list|,
name|face
argument_list|,
name|ckern_flags
operator|&
name|FT_VALIDATE_CKERN
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
name|ckern_table
operator|=
name|ckern
expr_stmt|;
name|Exit
label|:
if|if
condition|(
name|error
condition|)
name|FT_FREE
argument_list|(
name|ckern
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_decl_stmt
specifier|static
DECL|variable|gxvalid_interface
specifier|const
name|FT_Service_GXvalidateRec
name|gxvalid_interface
init|=
block|{
name|gxv_validate
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
DECL|variable|ckernvalid_interface
specifier|const
name|FT_Service_CKERNvalidateRec
name|ckernvalid_interface
init|=
block|{
name|classic_kern_validate
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
DECL|variable|gxvalid_services
specifier|const
name|FT_ServiceDescRec
name|gxvalid_services
index|[]
init|=
block|{
block|{
name|FT_SERVICE_ID_GX_VALIDATE
block|,
operator|&
name|gxvalid_interface
block|}
block|,
block|{
name|FT_SERVICE_ID_CLASSICKERN_VALIDATE
block|,
operator|&
name|ckernvalid_interface
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
DECL|function|gxvalid_get_service
name|gxvalid_get_service
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
name|gxvalid_services
argument_list|,
name|service_id
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|gxv_module_class
specifier|const
name|FT_Module_Class
name|gxv_module_class
init|=
block|{
literal|0
block|,
sizeof|sizeof
argument_list|(
name|FT_ModuleRec
argument_list|)
block|,
literal|"gxvalid"
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
name|gxvalid_get_service
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* END */
end_comment
end_unit
