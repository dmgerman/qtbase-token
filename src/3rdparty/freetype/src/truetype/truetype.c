begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  truetype.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType TrueType driver component (body only).                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2004, 2006 by                                     */
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
begin_define
DECL|macro|FT_MAKE_OPTION_SINGLE_OBJECT
define|#
directive|define
name|FT_MAKE_OPTION_SINGLE_OBJECT
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttpic.c"
end_include
begin_include
include|#
directive|include
file|"ttdriver.c"
end_include
begin_comment
comment|/* driver interface    */
end_comment
begin_include
include|#
directive|include
file|"ttpload.c"
end_include
begin_comment
comment|/* tables loader       */
end_comment
begin_include
include|#
directive|include
file|"ttgload.c"
end_include
begin_comment
comment|/* glyph loader        */
end_comment
begin_include
include|#
directive|include
file|"ttobjs.c"
end_include
begin_comment
comment|/* object manager      */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
end_ifdef
begin_include
include|#
directive|include
file|"ttinterp.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"ttgxvar.c"
end_include
begin_comment
comment|/* gx distortable font */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
