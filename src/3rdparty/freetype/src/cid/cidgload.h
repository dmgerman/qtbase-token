begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cidgload.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType Glyph Loader (specification).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004 by                                     */
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
name|__CIDGLOAD_H__
end_ifndef
begin_define
DECL|macro|__CIDGLOAD_H__
define|#
directive|define
name|__CIDGLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"cidobjs.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
if|#
directive|if
literal|0
comment|/* Compute the maximum advance width of a font through quick parsing */
function_decl|FT_LOCAL( FT_Error )   cid_face_compute_max_advance( CID_Face  face,                                 FT_Int*   max_advance );
endif|#
directive|endif
comment|/* 0 */
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|cid_slot_load_glyph
parameter_list|(
name|FT_GlyphSlot
name|glyph
parameter_list|,
comment|/* CID_Glyph_Slot */
name|FT_Size
name|size
parameter_list|,
comment|/* CID_Size       */
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Int32
name|load_flags
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CIDGLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
