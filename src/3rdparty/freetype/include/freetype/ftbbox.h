begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbbox.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType exact bbox computation (specification).                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2003, 2007 by                                     */
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
comment|/* This component has a _single_ role: to compute exact outline bounding */
end_comment
begin_comment
comment|/* boxes.                                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* It is separated from the rest of the engine for various technical     */
end_comment
begin_comment
comment|/* reasons.  It may well be integrated in `ftoutln' later.               */
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
name|__FTBBOX_H__
end_ifndef
begin_define
DECL|macro|__FTBBOX_H__
define|#
directive|define
name|__FTBBOX_H__
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
comment|/*    outline_processing                                                 */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_Outline_Get_BBox                                                */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Compute the exact bounding box of an outline.  This is slower      */
comment|/*    than computing the control box.  However, it uses an advanced      */
comment|/*    algorithm which returns _very_ quickly when the two boxes          */
comment|/*    coincide.  Otherwise, the outline BÃ©zier arcs are traversed to     */
comment|/*    extract their extrema.                                             */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    outline :: A pointer to the source outline.                        */
comment|/*                                                                       */
comment|/*<Output>                                                              */
comment|/*    abbox   :: The outline's exact bounding box.                       */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    FreeType error code.  0~means success.                             */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Outline_Get_BBox
parameter_list|(
name|FT_Outline
modifier|*
name|outline
parameter_list|,
name|FT_BBox
modifier|*
name|abbox
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
comment|/* __FTBBOX_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
begin_comment
comment|/* Local Variables: */
end_comment
begin_comment
comment|/* coding: utf-8    */
end_comment
begin_comment
comment|/* End:             */
end_comment
end_unit
