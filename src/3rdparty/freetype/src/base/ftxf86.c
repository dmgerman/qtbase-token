begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftxf86.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType utility file for X11 support (body).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004 by                                          */
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
include|FT_XFREE86_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_XFREE86_NAME_H
end_include
begin_comment
comment|/* documentation is in ftxf86.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|const char*
argument_list|)
end_macro
begin_macro
DECL|function|FT_Get_X11_Font_Format
name|FT_Get_X11_Font_Format
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_block
block|{
specifier|const
name|char
modifier|*
name|result
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|face
condition|)
name|FT_FACE_FIND_SERVICE
argument_list|(
name|face
argument_list|,
name|result
argument_list|,
name|XF86_NAME
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
