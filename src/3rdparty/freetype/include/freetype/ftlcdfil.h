begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftlcdfil.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for color filtering of subpixel bitmap glyphs           */
end_comment
begin_comment
comment|/*    (specification).                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006, 2007, 2008 by                                          */
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
name|__FT_LCD_FILTER_H__
end_ifndef
begin_define
DECL|macro|__FT_LCD_FILTER_H__
define|#
directive|define
name|__FT_LCD_FILTER_H__
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
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/***************************************************************************    *    * @section:    *   lcd_filtering    *    * @title:    *   LCD Filtering    *    * @abstract:    *   Reduce color fringes of LCD-optimized bitmaps.    *    * @description:    *   The @FT_Library_SetLcdFilter API can be used to specify a low-pass    *   filter which is then applied to LCD-optimized bitmaps generated    *   through @FT_Render_Glyph.  This is useful to reduce color fringes    *   which would occur with unfiltered rendering.    *    *   Note that no filter is active by default, and that this function is    *   *not* implemented in default builds of the library.  You need to    *   #define FT_CONFIG_OPTION_SUBPIXEL_RENDERING in your `ftoption.h' file    *   in order to activate it.    */
end_comment
begin_comment
comment|/****************************************************************************    *    * @func:    *   FT_LcdFilter    *    * @description:    *   A list of values to identify various types of LCD filters.    *    * @values:    *   FT_LCD_FILTER_NONE ::    *     Do not perform filtering.  When used with subpixel rendering, this    *     results in sometimes severe color fringes.    *    *   FT_LCD_FILTER_DEFAULT ::    *     The default filter reduces color fringes considerably, at the cost    *     of a slight blurriness in the output.    *    *   FT_LCD_FILTER_LIGHT ::    *     The light filter is a variant that produces less blurriness at the    *     cost of slightly more color fringes than the default one.  It might    *     be better, depending on taste, your monitor, or your personal vision.    *    *   FT_LCD_FILTER_LEGACY ::    *     This filter corresponds to the original libXft color filter.  It    *     provides high contrast output but can exhibit really bad color    *     fringes if glyphs are not extremely well hinted to the pixel grid.    *     In other words, it only works well if the TrueType bytecode    *     interpreter is enabled *and* high-quality hinted fonts are used.    *    *     This filter is only provided for comparison purposes, and might be    *     disabled or stay unsupported in the future.    *    * @since:    *   2.3.0    */
end_comment
begin_typedef
DECL|enum|FT_LcdFilter_
typedef|typedef
enum|enum
name|FT_LcdFilter_
block|{
DECL|enumerator|FT_LCD_FILTER_NONE
name|FT_LCD_FILTER_NONE
init|=
literal|0
block|,
DECL|enumerator|FT_LCD_FILTER_DEFAULT
name|FT_LCD_FILTER_DEFAULT
init|=
literal|1
block|,
DECL|enumerator|FT_LCD_FILTER_LIGHT
name|FT_LCD_FILTER_LIGHT
init|=
literal|2
block|,
DECL|enumerator|FT_LCD_FILTER_LEGACY
name|FT_LCD_FILTER_LEGACY
init|=
literal|16
block|,
DECL|enumerator|FT_LCD_FILTER_MAX
name|FT_LCD_FILTER_MAX
comment|/* do not remove */
block|}
DECL|typedef|FT_LcdFilter
name|FT_LcdFilter
typedef|;
end_typedef
begin_comment
comment|/**************************************************************************    *    * @func:    *   FT_Library_SetLcdFilter    *    * @description:    *   This function is used to apply color filtering to LCD decimated    *   bitmaps, like the ones used when calling @FT_Render_Glyph with    *   @FT_RENDER_MODE_LCD or @FT_RENDER_MODE_LCD_V.    *    * @input:    *   library ::    *     A handle to the target library instance.    *    *   filter ::    *     The filter type.    *    *     You can use @FT_LCD_FILTER_NONE here to disable this feature, or    *     @FT_LCD_FILTER_DEFAULT to use a default filter that should work    *     well on most LCD screens.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   This feature is always disabled by default.  Clients must make an    *   explicit call to this function with a `filter' value other than    *   @FT_LCD_FILTER_NONE in order to enable it.    *    *   Due to *PATENTS* covering subpixel rendering, this function doesn't    *   do anything except returning `FT_Err_Unimplemented_Feature' if the    *   configuration macro FT_CONFIG_OPTION_SUBPIXEL_RENDERING is not    *   defined in your build of the library, which should correspond to all    *   default builds of FreeType.    *    *   The filter affects glyph bitmaps rendered through @FT_Render_Glyph,    *   @FT_Outline_Get_Bitmap, @FT_Load_Glyph, and @FT_Load_Char.    *    *   It does _not_ affect the output of @FT_Outline_Render and    *   @FT_Outline_Get_Bitmap.    *    *   If this feature is activated, the dimensions of LCD glyph bitmaps are    *   either larger or taller than the dimensions of the corresponding    *   outline with regards to the pixel grid.  For example, for    *   @FT_RENDER_MODE_LCD, the filter adds up to 3~pixels to the left, and    *   up to 3~pixels to the right.    *    *   The bitmap offset values are adjusted correctly, so clients shouldn't    *   need to modify their layout and glyph positioning code when enabling    *   the filter.    *    * @since:    *   2.3.0    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Library_SetLcdFilter
argument_list|(
argument|FT_Library    library
argument_list|,
argument|FT_LcdFilter  filter
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
comment|/* __FT_LCD_FILTER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
