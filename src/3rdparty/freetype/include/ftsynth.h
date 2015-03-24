begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsynth.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType synthesizing code for emboldening and slanting              */
end_comment
begin_comment
comment|/*    (specification).                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2001, 2003, 2006, 2008, 2012, 2013 by                   */
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
comment|/*************************************************************************/
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
comment|/*********                                                       *********/
end_comment
begin_comment
comment|/*********        WARNING, THIS IS ALPHA CODE!  THIS API         *********/
end_comment
begin_comment
comment|/*********    IS DUE TO CHANGE UNTIL STRICTLY NOTIFIED BY THE    *********/
end_comment
begin_comment
comment|/*********            FREETYPE DEVELOPMENT TEAM                  *********/
end_comment
begin_comment
comment|/*********                                                       *********/
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* Main reason for not lifting the functions in this module to a  */
end_comment
begin_comment
comment|/* `standard' API is that the used parameters for emboldening and */
end_comment
begin_comment
comment|/* slanting are not configurable.  Consider the functions as a    */
end_comment
begin_comment
comment|/* code resource that should be copied into the application and   */
end_comment
begin_comment
comment|/* adapted to the particular needs.                               */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTSYNTH_H__
end_ifndef
begin_define
DECL|macro|__FTSYNTH_H__
define|#
directive|define
name|__FTSYNTH_H__
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
comment|/* Embolden a glyph by a `reasonable' value (which is highly a matter of */
comment|/* taste).  This function is actually a convenience function, providing  */
comment|/* a wrapper for @FT_Outline_Embolden and @FT_Bitmap_Embolden.           */
comment|/*                                                                       */
comment|/* For emboldened outlines the height, width, and advance metrics are    */
comment|/* increased by the strength of the emboldening.  You can also call      */
comment|/* @FT_Outline_Get_CBox to get precise values.                           */
name|FT_EXPORT
parameter_list|(
name|void
parameter_list|)
function_decl|FT_GlyphSlot_Embolden
DECL|variable|slot
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Slant an outline glyph to the right by about 12 degrees. */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|FT_GlyphSlot_Oblique
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|slot
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
comment|/* __FTSYNTH_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
