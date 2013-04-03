begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftpic.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services (body).              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009 by                                                      */
end_comment
begin_comment
comment|/*  Oran Agra and Mickey Gabel.                                            */
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
include|FT_FREETYPE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
file|"basepic.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_comment
comment|/* documentation is in ftpic.h */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ft_pic_container_init
argument_list|(
argument|FT_Library library
argument_list|)
end_macro
begin_block
block|{
name|FT_PIC_Container
modifier|*
name|pic_container
init|=
operator|&
name|library
operator|->
name|pic_container
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_MEM_SET
argument_list|(
name|pic_container
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pic_container
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|ft_base_pic_init
argument_list|(
name|library
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
name|error
return|;
return|return
name|FT_Err_Ok
return|;
block|}
end_block
begin_comment
comment|/* Destroy the contents of the container. */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_pic_container_destroy
name|ft_pic_container_destroy
argument_list|(
argument|FT_Library library
argument_list|)
end_macro
begin_block
block|{
name|ft_base_pic_free
argument_list|(
name|library
argument_list|)
expr_stmt|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
