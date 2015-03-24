begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftwinfnt.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing Windows FNT specific info (body).         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2014 by                                          */
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
include|FT_WINFONTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_WINFNT_H
end_include
begin_comment
comment|/* documentation is in ftwinfnt.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_WinFNT_Header
argument_list|(
argument|FT_Face               face
argument_list|,
argument|FT_WinFNT_HeaderRec  *header
argument_list|)
end_macro
begin_block
block|{
name|FT_Service_WinFnt
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
return|return
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
return|;
if|if
condition|(
operator|!
name|header
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
name|FT_FACE_LOOKUP_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|WINFNT
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
name|get_header
argument_list|(
name|face
argument_list|,
name|header
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
