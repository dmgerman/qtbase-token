begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftapi.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType compatibility functions (body).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002 by                                                      */
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
include|FT_LIST_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                 C O M P A T I B I L I T Y                       ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* backwards compatibility API */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_New_Memory_Stream
name|FT_New_Memory_Stream
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Byte*    base
argument_list|,
argument|FT_ULong    size
argument_list|,
argument|FT_Stream   stream
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|library
argument_list|)
expr_stmt|;
name|FT_Stream_OpenMemory
argument_list|(
name|stream
argument_list|,
name|base
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Seek_Stream
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   pos
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_Seek
argument_list|(
name|stream
argument_list|,
name|pos
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Skip_Stream
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Long    distance
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_Skip
argument_list|(
name|stream
argument_list|,
name|distance
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Read_Stream
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_Read
argument_list|(
name|stream
argument_list|,
name|buffer
argument_list|,
name|count
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Read_Stream_At
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   pos
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_ReadAt
argument_list|(
name|stream
argument_list|,
name|pos
argument_list|,
name|buffer
argument_list|,
name|count
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Extract_Frame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   count
argument_list|,
argument|FT_Byte**  pbytes
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_ExtractFrame
argument_list|(
name|stream
argument_list|,
name|count
argument_list|,
name|pbytes
argument_list|)
return|;
block|}
end_block
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_Release_Frame
name|FT_Release_Frame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Byte**  pbytes
argument_list|)
end_macro
begin_block
block|{
name|FT_Stream_ReleaseFrame
argument_list|(
name|stream
argument_list|,
name|pbytes
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Access_Frame
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   count
argument_list|)
end_macro
begin_block
block|{
return|return
name|FT_Stream_EnterFrame
argument_list|(
name|stream
argument_list|,
name|count
argument_list|)
return|;
block|}
end_block
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_Forget_Frame
name|FT_Forget_Frame
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
name|FT_Stream_ExitFrame
argument_list|(
name|stream
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
