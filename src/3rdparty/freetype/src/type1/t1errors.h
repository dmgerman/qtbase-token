begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1errors.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 error codes (specification only).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001-2015 by                                                 */
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
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This file is used to define the Type 1 error enumeration constants.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__T1ERRORS_H__
end_ifndef
begin_define
DECL|macro|__T1ERRORS_H__
define|#
directive|define
name|__T1ERRORS_H__
end_define
begin_include
include|#
directive|include
include|FT_MODULE_ERRORS_H
end_include
begin_undef
DECL|macro|__FTERRORS_H__
undef|#
directive|undef
name|__FTERRORS_H__
end_undef
begin_undef
DECL|macro|FT_ERR_PREFIX
undef|#
directive|undef
name|FT_ERR_PREFIX
end_undef
begin_define
DECL|macro|FT_ERR_PREFIX
define|#
directive|define
name|FT_ERR_PREFIX
value|T1_Err_
end_define
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|FT_Mod_Err_Type1
end_define
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __T1ERRORS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
