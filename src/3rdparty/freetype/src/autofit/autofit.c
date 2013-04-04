begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  autofit.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter module (body).                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2006, 2007 by                              */
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
file|"afpic.c"
end_include
begin_include
include|#
directive|include
file|"afangles.c"
end_include
begin_include
include|#
directive|include
file|"afglobal.c"
end_include
begin_include
include|#
directive|include
file|"afhints.c"
end_include
begin_include
include|#
directive|include
file|"afdummy.c"
end_include
begin_include
include|#
directive|include
file|"aflatin.c"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_OPTION_AUTOFIT2
end_ifdef
begin_include
include|#
directive|include
file|"aflatin2.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"afcjk.c"
end_include
begin_include
include|#
directive|include
file|"afindic.c"
end_include
begin_include
include|#
directive|include
file|"afloader.c"
end_include
begin_include
include|#
directive|include
file|"afmodule.c"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|AF_USE_WARPER
end_ifdef
begin_include
include|#
directive|include
file|"afwarp.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
