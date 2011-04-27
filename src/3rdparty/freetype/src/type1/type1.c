begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  type1.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Type 1 driver component (body only).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001 by                                                 */
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
file|"t1parse.c"
end_include
begin_include
include|#
directive|include
file|"t1load.c"
end_include
begin_include
include|#
directive|include
file|"t1objs.c"
end_include
begin_include
include|#
directive|include
file|"t1driver.c"
end_include
begin_include
include|#
directive|include
file|"t1gload.c"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_AFM
end_ifndef
begin_include
include|#
directive|include
file|"t1afm.c"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* END */
end_comment
end_unit
