begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftadvanc.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Quick computation of advance widths (specification only).            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2008, 2013, 2014 by                                          */
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
name|__FTADVANC_H__
end_ifndef
begin_define
DECL|macro|__FTADVANC_H__
define|#
directive|define
name|__FTADVANC_H__
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
comment|/**************************************************************************    *    * @section:    *   quick_advance    *    * @title:    *   Quick retrieval of advance values    *    * @abstract:    *   Retrieve horizontal and vertical advance values without processing    *   glyph outlines, if possible.    *    * @description:    *   This section contains functions to quickly extract advance values    *   without handling glyph outlines, if possible.    *    * @order:    *   FT_Get_Advance    *   FT_Get_Advances    *    */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Const>                                                               */
comment|/*    FT_ADVANCE_FLAG_FAST_ONLY                                          */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    A bit-flag to be OR-ed with the `flags' parameter of the           */
comment|/*    @FT_Get_Advance and @FT_Get_Advances functions.                    */
comment|/*                                                                       */
comment|/*    If set, it indicates that you want these functions to fail if the  */
comment|/*    corresponding hinting mode or font driver doesn't allow for very   */
comment|/*    quick advance computation.                                         */
comment|/*                                                                       */
comment|/*    Typically, glyphs that are either unscaled, unhinted, bitmapped,   */
comment|/*    or light-hinted can have their advance width computed very         */
comment|/*    quickly.                                                           */
comment|/*                                                                       */
comment|/*    Normal and bytecode hinted modes that require loading, scaling,    */
comment|/*    and hinting of the glyph outline, are extremely slow by            */
comment|/*    comparison.                                                        */
comment|/*                                                                       */
DECL|macro|FT_ADVANCE_FLAG_FAST_ONLY
define|#
directive|define
name|FT_ADVANCE_FLAG_FAST_ONLY
value|0x20000000UL
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_Get_Advance                                                     */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Retrieve the advance value of a given glyph outline in an          */
comment|/*    @FT_Face.                                                          */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    face       :: The source @FT_Face handle.                          */
comment|/*                                                                       */
comment|/*    gindex     :: The glyph index.                                     */
comment|/*                                                                       */
comment|/*    load_flags :: A set of bit flags similar to those used when        */
comment|/*                  calling @FT_Load_Glyph, used to determine what kind  */
comment|/*                  of advances you need.                                */
comment|/*<Output>                                                              */
comment|/*    padvance :: The advance value.  If scaling is performed (based on  */
comment|/*                the value of `load_flags'), the advance value is in    */
comment|/*                16.16 format.  Otherwise, it is in font units.         */
comment|/*                                                                       */
comment|/*                If @FT_LOAD_VERTICAL_LAYOUT is set, this is the        */
comment|/*                vertical advance corresponding to a vertical layout.   */
comment|/*                Otherwise, it is the horizontal advance in a           */
comment|/*                horizontal layout.                                     */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    FreeType error code.  0 means success.                             */
comment|/*                                                                       */
comment|/*<Note>                                                                */
comment|/*    This function may fail if you use @FT_ADVANCE_FLAG_FAST_ONLY and   */
comment|/*    if the corresponding font backend doesn't have a quick way to      */
comment|/*    retrieve the advances.                                             */
comment|/*                                                                       */
comment|/*    A scaled advance is returned in 16.16 format but isn't transformed */
comment|/*    by the affine transformation specified by @FT_Set_Transform.       */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Get_Advance
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|gindex
parameter_list|,
name|FT_Int32
name|load_flags
parameter_list|,
name|FT_Fixed
modifier|*
name|padvance
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
comment|/*    FT_Get_Advances                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the advance values of several glyph outlines in an        */
end_comment
begin_comment
comment|/*    @FT_Face.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face        :: The source @FT_Face handle.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    start       :: The first glyph index.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    count       :: The number of advance values you want to retrieve.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags  :: A set of bit flags similar to those used when       */
end_comment
begin_comment
comment|/*                   calling @FT_Load_Glyph.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    padvance :: The advance values.  This array, to be provided by the */
end_comment
begin_comment
comment|/*                caller, must contain at least `count' elements.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                If scaling is performed (based on the value of         */
end_comment
begin_comment
comment|/*                `load_flags'), the advance values are in 16.16 format. */
end_comment
begin_comment
comment|/*                Otherwise, they are in font units.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                If @FT_LOAD_VERTICAL_LAYOUT is set, these are the      */
end_comment
begin_comment
comment|/*                vertical advances corresponding to a vertical layout.  */
end_comment
begin_comment
comment|/*                Otherwise, they are the horizontal advances in a       */
end_comment
begin_comment
comment|/*                horizontal layout.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function may fail if you use @FT_ADVANCE_FLAG_FAST_ONLY and   */
end_comment
begin_comment
comment|/*    if the corresponding font backend doesn't have a quick way to      */
end_comment
begin_comment
comment|/*    retrieve the advances.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Scaled advances are returned in 16.16 format but aren't            */
end_comment
begin_comment
comment|/*    transformed by the affine transformation specified by              */
end_comment
begin_comment
comment|/*    @FT_Set_Transform.                                                 */
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
DECL|variable|FT_Get_Advances
name|FT_Get_Advances
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    start
argument_list|,
argument|FT_UInt    count
argument_list|,
argument|FT_Int32   load_flags
argument_list|,
argument|FT_Fixed  *padvances
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
comment|/* __FTADVANC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
