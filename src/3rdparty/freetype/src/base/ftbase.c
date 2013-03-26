begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbase.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Single object library component (body only).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2006, 2007, 2008, 2009 by       */
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
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_define
DECL|macro|FT_MAKE_OPTION_SINGLE_OBJECT
define|#
directive|define
name|FT_MAKE_OPTION_SINGLE_OBJECT
end_define
begin_include
include|#
directive|include
file|"ftpic.c"
end_include
begin_include
include|#
directive|include
file|"basepic.c"
end_include
begin_include
include|#
directive|include
file|"ftadvanc.c"
end_include
begin_include
include|#
directive|include
file|"ftcalc.c"
end_include
begin_include
include|#
directive|include
file|"ftdbgmem.c"
end_include
begin_include
include|#
directive|include
file|"ftgloadr.c"
end_include
begin_include
include|#
directive|include
file|"ftobjs.c"
end_include
begin_include
include|#
directive|include
file|"ftoutln.c"
end_include
begin_include
include|#
directive|include
file|"ftrfork.c"
end_include
begin_include
include|#
directive|include
file|"ftsnames.c"
end_include
begin_include
include|#
directive|include
file|"ftstream.c"
end_include
begin_include
include|#
directive|include
file|"fttrigon.c"
end_include
begin_include
include|#
directive|include
file|"ftutil.c"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|FT_MACINTOSH
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DARWIN_NO_CARBON
argument_list|)
end_if
begin_include
include|#
directive|include
file|"ftmac.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
