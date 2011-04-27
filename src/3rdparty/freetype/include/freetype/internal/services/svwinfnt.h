begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svwinfnt.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType Windows FNT/FONT service (specification).               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003 by                                                      */
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
name|__SVWINFNT_H__
end_ifndef
begin_define
DECL|macro|__SVWINFNT_H__
define|#
directive|define
name|__SVWINFNT_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_WINFONTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_WINFNT
define|#
directive|define
name|FT_SERVICE_ID_WINFNT
value|"winfonts"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_WinFnt_GetHeaderFunc
modifier|*
name|FT_WinFnt_GetHeaderFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_WinFNT_HeaderRec
modifier|*
name|aheader
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|WinFnt
argument_list|)
end_macro
begin_block
block|{
name|FT_WinFnt_GetHeaderFunc
name|get_header
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __SVWINFNT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
