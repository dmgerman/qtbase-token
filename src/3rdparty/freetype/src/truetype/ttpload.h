begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttpload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType-specific tables loader (specification).                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2005, 2006 by                               */
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
name|__TTPLOAD_H__
end_ifndef
begin_define
DECL|macro|__TTPLOAD_H__
define|#
directive|define
name|__TTPLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|tt_face_load_loca
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_get_location
name|tt_face_get_location
argument_list|(
argument|TT_Face   face
argument_list|,
argument|FT_UInt   gindex
argument_list|,
argument|FT_UInt  *asize
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|face
name|tt_face_done_loca
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_cvt
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_load_fpgm
name|tt_face_load_fpgm
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_prep
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_load_hdmx
name|tt_face_load_hdmx
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|face
name|tt_face_free_hdmx
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Byte*
argument_list|)
end_macro
begin_macro
name|tt_face_get_device_metrics
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_UInt    ppem
argument_list|,
argument|FT_UInt    gindex
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTPLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
