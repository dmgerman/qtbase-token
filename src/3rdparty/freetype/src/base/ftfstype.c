begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftfstype.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType utility file to access FSType data (body).                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2008, 2009, 2014 by                                          */
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
include|FT_TYPE1_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_INFO_H
end_include
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
name|FT_Get_FSType_Flags
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_block
block|{
name|TT_OS2
modifier|*
name|os2
decl_stmt|;
comment|/* first, try to get the fs_type directly from the font */
if|if
condition|(
name|face
condition|)
block|{
name|FT_Service_PsInfo
name|service
init|=
name|NULL
decl_stmt|;
name|FT_FACE_FIND_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|POSTSCRIPT_INFO
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
operator|&&
name|service
operator|->
name|ps_get_font_extra
condition|)
block|{
name|PS_FontExtraRec
name|extra
decl_stmt|;
if|if
condition|(
operator|!
name|service
operator|->
name|ps_get_font_extra
argument_list|(
name|face
argument_list|,
operator|&
name|extra
argument_list|)
operator|&&
name|extra
operator|.
name|fs_type
operator|!=
literal|0
condition|)
return|return
name|extra
operator|.
name|fs_type
return|;
block|}
block|}
comment|/* look at FSType before fsType for Type42 */
if|if
condition|(
operator|(
name|os2
operator|=
operator|(
name|TT_OS2
operator|*
operator|)
name|FT_Get_Sfnt_Table
argument_list|(
name|face
argument_list|,
name|FT_SFNT_OS2
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
name|os2
operator|->
name|version
operator|!=
literal|0xFFFFU
condition|)
return|return
name|os2
operator|->
name|fsType
return|;
return|return
literal|0
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
