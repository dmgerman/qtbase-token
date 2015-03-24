begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxverror.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT validation module error codes (specification only).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2012-2013                                        */
end_comment
begin_comment
comment|/*    by suzuki toshiya, Masatake YAMATO, Red Hat K.K.,                    */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
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
comment|/* This file is used to define the OpenType validation module error      */
end_comment
begin_comment
comment|/* enumeration constants.                                                */
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
name|__GXVERROR_H__
end_ifndef
begin_define
DECL|macro|__GXVERROR_H__
define|#
directive|define
name|__GXVERROR_H__
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
value|GXV_Err_
end_define
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|FT_Mod_Err_GXvalid
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
comment|/* __GXVERROR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
