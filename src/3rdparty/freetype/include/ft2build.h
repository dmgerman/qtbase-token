begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ft2build.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType 2 build and setup macros.                                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2006, 2013 by                                     */
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
comment|/* This is the `entry point' for FreeType header file inclusions.  It is */
end_comment
begin_comment
comment|/* the only header file which should be included directly; all other     */
end_comment
begin_comment
comment|/* FreeType header files should be accessed with macro names (after      */
end_comment
begin_comment
comment|/* including `ft2build.h').                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A typical example is                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   #include<ft2build.h>                                               */
end_comment
begin_comment
comment|/*   #include FT_FREETYPE_H                                              */
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
name|__FT2BUILD_H__
end_ifndef
begin_define
DECL|macro|__FT2BUILD_H__
define|#
directive|define
name|__FT2BUILD_H__
end_define
begin_include
include|#
directive|include
file|<config/ftheader.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FT2BUILD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
