begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svxf86nm.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType XFree86 services (specification only).                  */
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
name|__SVXF86NM_H__
end_ifndef
begin_define
DECL|macro|__SVXF86NM_H__
define|#
directive|define
name|__SVXF86NM_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/*    *  A trivial service used to return the name of a face's font driver,    *  according to the XFree86 nomenclature.  Note that the service data    *  is a simple constant string pointer.    */
DECL|macro|FT_SERVICE_ID_XF86_NAME
define|#
directive|define
name|FT_SERVICE_ID_XF86_NAME
value|"xf86-driver-name"
DECL|macro|FT_XF86_FORMAT_TRUETYPE
define|#
directive|define
name|FT_XF86_FORMAT_TRUETYPE
value|"TrueType"
DECL|macro|FT_XF86_FORMAT_TYPE_1
define|#
directive|define
name|FT_XF86_FORMAT_TYPE_1
value|"Type 1"
DECL|macro|FT_XF86_FORMAT_BDF
define|#
directive|define
name|FT_XF86_FORMAT_BDF
value|"BDF"
DECL|macro|FT_XF86_FORMAT_PCF
define|#
directive|define
name|FT_XF86_FORMAT_PCF
value|"PCF"
DECL|macro|FT_XF86_FORMAT_TYPE_42
define|#
directive|define
name|FT_XF86_FORMAT_TYPE_42
value|"Type 42"
DECL|macro|FT_XF86_FORMAT_CID
define|#
directive|define
name|FT_XF86_FORMAT_CID
value|"CID Type 1"
DECL|macro|FT_XF86_FORMAT_CFF
define|#
directive|define
name|FT_XF86_FORMAT_CFF
value|"CFF"
DECL|macro|FT_XF86_FORMAT_PFR
define|#
directive|define
name|FT_XF86_FORMAT_PFR
value|"PFR"
DECL|macro|FT_XF86_FORMAT_WINFNT
define|#
directive|define
name|FT_XF86_FORMAT_WINFNT
value|"Windows FNT"
comment|/* */
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __SVXF86NM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
