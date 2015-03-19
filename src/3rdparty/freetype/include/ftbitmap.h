begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbitmap.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType utility functions for bitmaps (specification).              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004-2006, 2008, 2013, 2014 by                               */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__FTBITMAP_H__
end_ifndef
begin_define
DECL|macro|__FTBITMAP_H__
define|#
directive|define
name|__FTBITMAP_H__
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
comment|/*    bitmap_handling                                                    */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    Bitmap Handling                                                    */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Handling FT_Bitmap objects.                                        */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains functions for handling @FT_Bitmap objects.   */
comment|/*    Note that none of the functions changes the bitmap's `flow' (as    */
comment|/*    indicated by the sign of the `pitch' field in `FT_Bitmap').        */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_Bitmap_New                                                      */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Initialize a pointer to an @FT_Bitmap structure.                   */
comment|/*                                                                       */
comment|/*<InOut>                                                               */
comment|/*    abitmap :: A pointer to the bitmap structure.                      */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|void
parameter_list|)
function_decl|FT_Bitmap_New
DECL|variable|abitmap
parameter_list|(
name|FT_Bitmap
modifier|*
name|abitmap
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
comment|/*    FT_Bitmap_Copy                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Copy a bitmap into another one.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a library object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    source  :: A handle to the source bitmap.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    target  :: A handle to the target bitmap.                          */
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
name|FT_Bitmap_Copy
argument_list|(
argument|FT_Library        library
argument_list|,
argument|const FT_Bitmap  *source
argument_list|,
argument|FT_Bitmap        *target
argument_list|)
end_macro
begin_empty_stmt
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
comment|/*    FT_Bitmap_Embolden                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Embolden a bitmap.  The new bitmap will be about `xStrength'       */
end_comment
begin_comment
comment|/*    pixels wider and `yStrength' pixels higher.  The left and bottom   */
end_comment
begin_comment
comment|/*    borders are kept unchanged.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library   :: A handle to a library object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    xStrength :: How strong the glyph is emboldened horizontally.      */
end_comment
begin_comment
comment|/*                 Expressed in 26.6 pixel format.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yStrength :: How strong the glyph is emboldened vertically.        */
end_comment
begin_comment
comment|/*                 Expressed in 26.6 pixel format.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    bitmap    :: A handle to the target bitmap.                        */
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
comment|/*    The current implementation restricts `xStrength' to be less than   */
end_comment
begin_comment
comment|/*    or equal to~8 if bitmap is of pixel_mode @FT_PIXEL_MODE_MONO.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If you want to embolden the bitmap owned by a @FT_GlyphSlotRec,    */
end_comment
begin_comment
comment|/*    you should call @FT_GlyphSlot_Own_Bitmap on the slot first.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Bitmaps in @FT_PIXEL_MODE_GRAY2 and @FT_PIXEL_MODE_GRAY@ format    */
end_comment
begin_comment
comment|/*    are converted to @FT_PIXEL_MODE_GRAY format (i.e., 8bpp).          */
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
DECL|variable|FT_Bitmap_Embolden
name|FT_Bitmap_Embolden
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Bitmap*  bitmap
argument_list|,
argument|FT_Pos      xStrength
argument_list|,
argument|FT_Pos      yStrength
argument_list|)
end_macro
begin_empty_stmt
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
comment|/*    FT_Bitmap_Convert                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Convert a bitmap object with depth 1bpp, 2bpp, 4bpp, 8bpp or 32bpp */
end_comment
begin_comment
comment|/*    to a bitmap object with depth 8bpp, making the number of used      */
end_comment
begin_comment
comment|/*    bytes line (a.k.a. the `pitch') a multiple of `alignment'.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library   :: A handle to a library object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    source    :: The source bitmap.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    alignment :: The pitch of the bitmap is a multiple of this         */
end_comment
begin_comment
comment|/*                 parameter.  Common values are 1, 2, or 4.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    target    :: The target bitmap.                                    */
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
comment|/*    It is possible to call @FT_Bitmap_Convert multiple times without   */
end_comment
begin_comment
comment|/*    calling @FT_Bitmap_Done (the memory is simply reallocated).        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Use @FT_Bitmap_Done to finally remove the bitmap object.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The `library' argument is taken to have access to FreeType's       */
end_comment
begin_comment
comment|/*    memory handling functions.                                         */
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
name|FT_Bitmap_Convert
argument_list|(
argument|FT_Library        library
argument_list|,
argument|const FT_Bitmap  *source
argument_list|,
argument|FT_Bitmap        *target
argument_list|,
argument|FT_Int            alignment
argument_list|)
end_macro
begin_empty_stmt
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
comment|/*    FT_GlyphSlot_Own_Bitmap                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Make sure that a glyph slot owns `slot->bitmap'.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    slot :: The glyph slot.                                            */
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
comment|/*    This function is to be used in combination with                    */
end_comment
begin_comment
comment|/*    @FT_Bitmap_Embolden.                                               */
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
DECL|variable|FT_GlyphSlot_Own_Bitmap
name|FT_GlyphSlot_Own_Bitmap
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_GlyphSlot_Own_Bitmap
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
comment|/*    FT_Bitmap_Done                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy a bitmap object created with @FT_Bitmap_New.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a library object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bitmap  :: The bitmap object to be freed.                          */
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
comment|/*    The `library' argument is taken to have access to FreeType's       */
end_comment
begin_comment
comment|/*    memory handling functions.                                         */
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
name|FT_Bitmap_Done
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Bitmap  *bitmap
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
comment|/* __FTBITMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
