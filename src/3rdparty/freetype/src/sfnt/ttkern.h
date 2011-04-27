begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttkern.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Load the basic TrueType kerning table.  This doesn't handle          */
end_comment
begin_comment
comment|/*    kerning data within the GPOS table at the moment.                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2005, 2007 by                               */
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
name|__TTKERN_H__
end_ifndef
begin_define
DECL|macro|__TTKERN_H__
define|#
directive|define
name|__TTKERN_H__
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
name|FT_Error
parameter_list|)
function_decl|tt_face_load_kern
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
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_done_kern
name|tt_face_done_kern
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_face_done_kern
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|tt_face_get_kerning
argument_list|(
argument|TT_Face     face
argument_list|,
argument|FT_UInt     left_glyph
argument_list|,
argument|FT_UInt     right_glyph
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|TT_FACE_HAS_KERNING
define|#
directive|define
name|TT_FACE_HAS_KERNING
parameter_list|(
name|face
parameter_list|)
value|( (face)->kern_avail_bits != 0 )
end_define
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTKERN_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
