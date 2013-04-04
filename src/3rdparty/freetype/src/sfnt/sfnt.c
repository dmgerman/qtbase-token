begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  sfnt.c                                                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Single object library component.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006 by                   */
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
file|"sfntpic.c"
end_include
begin_include
include|#
directive|include
file|"ttload.c"
end_include
begin_include
include|#
directive|include
file|"ttmtx.c"
end_include
begin_include
include|#
directive|include
file|"ttcmap.c"
end_include
begin_include
include|#
directive|include
file|"ttkern.c"
end_include
begin_include
include|#
directive|include
file|"sfobjs.c"
end_include
begin_include
include|#
directive|include
file|"sfdriver.c"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
end_ifdef
begin_include
include|#
directive|include
file|"ttsbit.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_ifdef
begin_include
include|#
directive|include
file|"ttpost.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BDF
end_ifdef
begin_include
include|#
directive|include
file|"ttbdf.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
