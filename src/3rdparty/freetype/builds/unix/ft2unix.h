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
comment|/*    Build macros of the FreeType 2 library.                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2003, 2006 by                                     */
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
comment|/* This is a Unix-specific version of<ft2build.h> that should be used   */
end_comment
begin_comment
comment|/* exclusively *after* installation of the library.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* It assumes that `/usr/local/include/freetype2' (or whatever is        */
end_comment
begin_comment
comment|/* returned by the `freetype-config --cflags' or `pkg-config --cflags'   */
end_comment
begin_comment
comment|/* command) is in your compilation include path.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* We don't need to do anything special in this release.  However, for   */
end_comment
begin_comment
comment|/* a future FreeType 2 release, the following installation changes will  */
end_comment
begin_comment
comment|/* be performed:                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - The contents of `freetype-2.x/include/freetype' will be installed */
end_comment
begin_comment
comment|/*     to `/usr/local/include/freetype2' instead of                      */
end_comment
begin_comment
comment|/*     `/usr/local/include/freetype2/freetype'.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - This file will #include<freetype2/config/ftheader.h>, instead    */
end_comment
begin_comment
comment|/*     of<freetype/config/ftheader.h>.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - The contents of `ftheader.h' will be processed with `sed' to      */
end_comment
begin_comment
comment|/*     replace all `<freetype/xxx>' with `<freetype2/xxx>'.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - Adding `/usr/local/include/freetype2' to your compilation include */
end_comment
begin_comment
comment|/*     path will not be necessary anymore.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These changes will be transparent to client applications which use    */
end_comment
begin_comment
comment|/* freetype-config (or pkg-config).  No modifications will be necessary  */
end_comment
begin_comment
comment|/* to compile with the new scheme.                                       */
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
name|__FT2_BUILD_UNIX_H__
end_ifndef
begin_define
DECL|macro|__FT2_BUILD_UNIX_H__
define|#
directive|define
name|__FT2_BUILD_UNIX_H__
end_define
begin_comment
comment|/* `<prefix>/include/freetype2' must be in your current inclusion path */
end_comment
begin_include
include|#
directive|include
file|<freetype/config/ftheader.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FT2_BUILD_UNIX_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
