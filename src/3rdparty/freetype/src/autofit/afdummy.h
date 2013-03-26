begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afdummy.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter dummy routines to be used if no hinting should be        */
end_comment
begin_comment
comment|/*    performed (specification).                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005 by                                          */
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
name|__AFDUMMY_H__
end_ifndef
begin_define
DECL|macro|__AFDUMMY_H__
define|#
directive|define
name|__AFDUMMY_H__
end_define
begin_include
include|#
directive|include
file|"aftypes.h"
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/*  A dummy script metrics class used when no hinting should   *  be performed.  This is the default for non-latin glyphs!   */
name|AF_DECLARE_SCRIPT_CLASS
argument_list|(
name|af_dummy_script_class
argument_list|)
comment|/* */
name|FT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFDUMMY_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
