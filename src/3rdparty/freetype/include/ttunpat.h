begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttunpat.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Definitions for the unpatented TrueType hinting system               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2006 by                                                */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Written by Graham Asher<graham.asher@btinternet.com>                  */
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
name|__TTUNPAT_H__
end_ifndef
begin_define
DECL|macro|__TTUNPAT_H__
define|#
directive|define
name|__TTUNPAT_H__
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
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/***************************************************************************   *   * @constant:   *   FT_PARAM_TAG_UNPATENTED_HINTING   *   * @description:   *   A constant used as the tag of an @FT_Parameter structure to indicate   *   that unpatented methods only should be used by the TrueType bytecode   *   interpreter for a typeface opened by @FT_Open_Face.   *   */
DECL|macro|FT_PARAM_TAG_UNPATENTED_HINTING
define|#
directive|define
name|FT_PARAM_TAG_UNPATENTED_HINTING
value|FT_MAKE_TAG( 'u', 'n', 'p', 'a' )
comment|/* */
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTUNPAT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
