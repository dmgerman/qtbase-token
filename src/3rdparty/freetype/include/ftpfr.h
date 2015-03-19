begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftpfr.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing PFR-specific data (specification only).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2006, 2008, 2009 by                        */
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
name|__FTPFR_H__
end_ifndef
begin_define
DECL|macro|__FTPFR_H__
define|#
directive|define
name|__FTPFR_H__
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
comment|/*    pfr_fonts                                                          */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    PFR Fonts                                                          */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    PFR/TrueDoc specific API.                                          */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of PFR-specific functions.   */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/**********************************************************************   *   * @function:   *    FT_Get_PFR_Metrics   *   * @description:   *    Return the outline and metrics resolutions of a given PFR face.   *   * @input:   *    face :: Handle to the input face.  It can be a non-PFR face.   *   * @output:   *    aoutline_resolution ::   *      Outline resolution.  This is equivalent to `face->units_per_EM'   *      for non-PFR fonts.  Optional (parameter can be NULL).   *   *    ametrics_resolution ::   *      Metrics resolution.  This is equivalent to `outline_resolution'   *      for non-PFR fonts.  Optional (parameter can be NULL).   *   *    ametrics_x_scale ::   *      A 16.16 fixed-point number used to scale distance expressed   *      in metrics units to device sub-pixels.  This is equivalent to   *      `face->size->x_scale', but for metrics only.  Optional (parameter   *      can be NULL).   *   *    ametrics_y_scale ::   *      Same as `ametrics_x_scale' but for the vertical direction.   *      optional (parameter can be NULL).   *   * @return:   *    FreeType error code.  0~means success.   *   * @note:   *   If the input face is not a PFR, this function will return an error.   *   However, in all cases, it will return valid values.   */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Get_PFR_Metrics
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
modifier|*
name|aoutline_resolution
parameter_list|,
name|FT_UInt
modifier|*
name|ametrics_resolution
parameter_list|,
name|FT_Fixed
modifier|*
name|ametrics_x_scale
parameter_list|,
name|FT_Fixed
modifier|*
name|ametrics_y_scale
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_Get_PFR_Kerning   *   * @description:   *    Return the kerning pair corresponding to two glyphs in a PFR face.   *    The distance is expressed in metrics units, unlike the result of   *    @FT_Get_Kerning.   *   * @input:   *    face  :: A handle to the input face.   *   *    left  :: Index of the left glyph.   *   *    right :: Index of the right glyph.   *   * @output:   *    avector :: A kerning vector.   *   * @return:   *    FreeType error code.  0~means success.   *   * @note:   *    This function always return distances in original PFR metrics   *    units.  This is unlike @FT_Get_Kerning with the @FT_KERNING_UNSCALED   *    mode, which always returns distances converted to outline units.   *   *    You can use the value of the `x_scale' and `y_scale' parameters   *    returned by @FT_Get_PFR_Metrics to scale these to device sub-pixels.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_PFR_Kerning
name|FT_Get_PFR_Kerning
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_UInt     left
argument_list|,
argument|FT_UInt     right
argument_list|,
argument|FT_Vector  *avector
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**********************************************************************   *   * @function:   *    FT_Get_PFR_Advance   *   * @description:   *    Return a given glyph advance, expressed in original metrics units,   *    from a PFR font.   *   * @input:   *    face   :: A handle to the input face.   *   *    gindex :: The glyph index.   *   * @output:   *    aadvance :: The glyph advance in metrics units.   *   * @return:   *    FreeType error code.  0~means success.   *   * @note:   *    You can use the `x_scale' or `y_scale' results of @FT_Get_PFR_Metrics   *    to convert the advance to device sub-pixels (i.e., 1/64th of pixels).   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_PFR_Advance
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   gindex
argument_list|,
argument|FT_Pos   *aadvance
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
comment|/* __FTPFR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
