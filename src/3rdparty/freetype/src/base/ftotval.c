begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftotval.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for validating OpenType tables (body).                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2006, 2008, 2010, 2013 by                              */
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
include|FT_INTERNAL_DEBUG_H
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
include|FT_OPENTYPE_VALIDATE_H
end_include
begin_comment
comment|/* documentation is in ftotval.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_OpenType_Validate
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    validation_flags
argument_list|,
argument|FT_Bytes  *BASE_table
argument_list|,
argument|FT_Bytes  *GDEF_table
argument_list|,
argument|FT_Bytes  *GPOS_table
argument_list|,
argument|FT_Bytes  *GSUB_table
argument_list|,
argument|FT_Bytes  *JSTF_table
argument_list|)
end_macro
begin_block
block|{
name|FT_Service_OTvalidate
name|service
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
operator|!
operator|(
name|BASE_table
operator|&&
name|GDEF_table
operator|&&
name|GPOS_table
operator|&&
name|GSUB_table
operator|&&
name|JSTF_table
operator|)
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|FT_FACE_FIND_GLOBAL_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|OPENTYPE_VALIDATE
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
condition|)
name|error
operator|=
name|service
operator|->
name|validate
argument_list|(
name|face
argument_list|,
name|validation_flags
argument_list|,
name|BASE_table
argument_list|,
name|GDEF_table
argument_list|,
name|GPOS_table
argument_list|,
name|GSUB_table
argument_list|,
name|JSTF_table
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|FT_THROW
argument_list|(
name|Unimplemented_Feature
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_OpenType_Free
name|FT_OpenType_Free
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_Bytes  table
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
return|return;
name|memory
operator|=
name|FT_FACE_MEMORY
argument_list|(
name|face
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|table
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
