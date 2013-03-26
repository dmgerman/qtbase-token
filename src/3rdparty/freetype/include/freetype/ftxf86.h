begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftxf86.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Support functions for X11.                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2006, 2007 by                              */
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
name|__FTXF86_H__
end_ifndef
begin_define
DECL|macro|__FTXF86_H__
define|#
directive|define
name|__FTXF86_H__
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
comment|/*   font_formats                                                        */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*   Font Formats                                                        */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*   Getting the font format.                                            */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*   The single function in this section can be used to get the font     */
comment|/*   format.  Note that this information is not needed normally;         */
comment|/*   however, there are special cases (like in PDF devices) where it is  */
comment|/*   important to differentiate, in spite of FreeType's uniform API.     */
comment|/*                                                                       */
comment|/*   This function is in the X11/xf86 namespace for historical reasons   */
comment|/*   and in no way depends on that windowing system.                     */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*   FT_Get_X11_Font_Format                                              */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*   Return a string describing the format of a given face, using values */
comment|/*   which can be used as an X11 FONT_PROPERTY.  Possible values are     */
comment|/*   `TrueType', `Type~1', `BDF', `PCF', `Type~42', `CID~Type~1', `CFF', */
comment|/*   `PFR', and `Windows~FNT'.                                           */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*   face ::                                                             */
comment|/*     Input face handle.                                                */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*   Font format string.  NULL in case of error.                         */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|FT_Get_X11_Font_Format
DECL|variable|face
parameter_list|(
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
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
comment|/* __FTXF86_H__ */
end_comment
end_unit
