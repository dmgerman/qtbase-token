begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsizes.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType size objects management (specification).                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2003, 2004, 2006, 2009, 2013 by                   */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Typical application would normally not need to use these functions.   */
end_comment
begin_comment
comment|/* However, they have been placed in a public API for the rare cases     */
end_comment
begin_comment
comment|/* where they are needed.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTSIZES_H__
end_ifndef
begin_define
DECL|macro|__FTSIZES_H__
define|#
directive|define
name|__FTSIZES_H__
end_define
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
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    sizes_management                                                   */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    Size Management                                                    */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Managing multiple sizes per face.                                  */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    When creating a new face object (e.g., with @FT_New_Face), an      */
comment|/*    @FT_Size object is automatically created and used to store all     */
comment|/*    pixel-size dependent information, available in the `face->size'    */
comment|/*    field.                                                             */
comment|/*                                                                       */
comment|/*    It is however possible to create more sizes for a given face,      */
comment|/*    mostly in order to manage several character pixel sizes of the     */
comment|/*    same font family and style.  See @FT_New_Size and @FT_Done_Size.   */
comment|/*                                                                       */
comment|/*    Note that @FT_Set_Pixel_Sizes and @FT_Set_Char_Size only           */
comment|/*    modify the contents of the current `active' size; you thus need    */
comment|/*    to use @FT_Activate_Size to change it.                             */
comment|/*                                                                       */
comment|/*    99% of applications won't need the functions provided here,        */
comment|/*    especially if they use the caching sub-system, so be cautious      */
comment|/*    when using these.                                                  */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_New_Size                                                        */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Create a new size object from a given face object.                 */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    face :: A handle to a parent face object.                          */
comment|/*                                                                       */
comment|/*<Output>                                                              */
comment|/*    asize :: A handle to a new size object.                            */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    FreeType error code.  0~means success.                             */
comment|/*                                                                       */
comment|/*<Note>                                                                */
comment|/*    You need to call @FT_Activate_Size in order to select the new size */
comment|/*    for upcoming calls to @FT_Set_Pixel_Sizes, @FT_Set_Char_Size,      */
comment|/*    @FT_Load_Glyph, @FT_Load_Char, etc.                                */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_New_Size
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Size
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Done_Size                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Discard a given size object.  Note that @FT_Done_Face              */
end_comment
begin_comment
comment|/*    automatically discards all size objects allocated with             */
end_comment
begin_comment
comment|/*    @FT_New_Size.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    size :: A handle to a target size object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Done_Size
name|FT_Done_Size
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Done_Size
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Activate_Size                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Even though it is possible to create several size objects for a    */
end_comment
begin_comment
comment|/*    given face (see @FT_New_Size for details), functions like          */
end_comment
begin_comment
comment|/*    @FT_Load_Glyph or @FT_Load_Char only use the one that has been     */
end_comment
begin_comment
comment|/*    activated last to determine the `current character pixel size'.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function can be used to `activate' a previously created size  */
end_comment
begin_comment
comment|/*    object.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    size :: A handle to a target size object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If `face' is the size's parent face object, this function changes  */
end_comment
begin_comment
comment|/*    the value of `face->size' to the input size handle.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Activate_Size
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTSIZES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
