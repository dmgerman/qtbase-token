begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  aflatin2.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines for latin script (specification).       */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__AFLATIN2_H__
end_ifndef
begin_define
DECL|macro|__AFLATIN2_H__
define|#
directive|define
name|__AFLATIN2_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/* the latin-specific script class */
name|AF_DECLARE_SCRIPT_CLASS
argument_list|(
name|af_latin2_script_class
argument_list|)
comment|/* */
name|FT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFLATIN_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
