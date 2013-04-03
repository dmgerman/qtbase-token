begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pshmod.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    PostScript hinter module interface (specification).                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001 by                                                      */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__PSHMOD_H__
end_ifndef
begin_define
DECL|macro|__PSHMOD_H__
define|#
directive|define
name|__PSHMOD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
name|FT_DECLARE_MODULE
argument_list|(
name|pshinter_module_class
argument_list|)
name|FT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PSHMOD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
