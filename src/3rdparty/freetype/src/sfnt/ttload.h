begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttload.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Load the basic TrueType tables, i.e., tables that can be either in   */
end_comment
begin_comment
comment|/*    TTF or OTF fonts (specification).                                    */
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
name|__TTLOAD_H__
end_ifndef
begin_define
DECL|macro|__TTLOAD_H__
define|#
directive|define
name|__TTLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
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
name|TT_Table
parameter_list|)
function_decl|tt_face_lookup_table
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_ULong
name|tag
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_goto_table
name|tt_face_goto_table
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_ULong   tag
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong*  length
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
name|tt_face_load_font_dir
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
DECL|variable|tt_face_load_any
name|tt_face_load_any
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_ULong   tag
argument_list|,
argument|FT_Long    offset
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong*  length
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
name|tt_face_load_head
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
DECL|variable|tt_face_load_cmap
name|tt_face_load_cmap
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
name|tt_face_load_maxp
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
DECL|variable|tt_face_load_name
name|tt_face_load_name
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
name|tt_face_load_os2
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
DECL|variable|tt_face_load_post
name|tt_face_load_post
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
name|tt_face_load_pclt
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
DECL|variable|tt_face_free_name
name|tt_face_free_name
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_face_free_name
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_gasp
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_load_bhed
name|tt_face_load_bhed
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
