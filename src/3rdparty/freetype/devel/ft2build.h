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
comment|/*    (Generic version)                                                    */
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
comment|/*   *  This is a development version of<ft2build.h> that is used   *  to build the library in debug mode.  Its only difference with   *  the reference is that it forces the use of the local `ftoption.h'   *  which contains different settings for all configuration macros.   *   *  To use it, you must define the environment variable FT2_BUILD_INCLUDE   *  to point to the directory containing these two files (`ft2build.h' and   *  `ftoption.h'), then invoke Jam as usual.   */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FT2_BUILD_DEVEL_H__
end_ifndef
begin_define
DECL|macro|__FT2_BUILD_DEVEL_H__
define|#
directive|define
name|__FT2_BUILD_DEVEL_H__
end_define
begin_define
DECL|macro|FT_CONFIG_OPTIONS_H
define|#
directive|define
name|FT_CONFIG_OPTIONS_H
value|<ftoption.h>
end_define
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
comment|/* __FT2_BUILD_DEVEL_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
