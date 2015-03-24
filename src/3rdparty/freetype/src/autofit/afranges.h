begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afranges.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter Unicode script ranges (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013, 2014 by                                                */
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
name|__AFRANGES_H__
end_ifndef
begin_define
DECL|macro|__AFRANGES_H__
define|#
directive|define
name|__AFRANGES_H__
end_define
begin_include
include|#
directive|include
file|"aftypes.h"
end_include
begin_expr_stmt
name|FT_BEGIN_HEADER
DECL|macro|SCRIPT
undef|#
directive|undef
name|SCRIPT
DECL|macro|SCRIPT
define|#
directive|define
name|SCRIPT
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|,
name|sc1
parameter_list|,
name|sc2
parameter_list|,
name|sc3
parameter_list|)
define|\
value|extern const AF_Script_UniRangeRec  af_ ## s ## _uniranges[];
include|#
directive|include
file|"afscript.h"
comment|/* */
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFRANGES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
