begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttgload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType Glyph Loader (specification).                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2006, 2008, 2011 by                                     */
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
name|__TTGLOAD_H__
end_ifndef
begin_define
DECL|macro|__TTGLOAD_H__
define|#
directive|define
name|__TTGLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttobjs.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
end_ifdef
begin_include
include|#
directive|include
file|"ttinterp.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|TT_Init_Glyph_Loading
DECL|variable|face
parameter_list|(
name|TT_Face
name|face
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
name|TT_Get_HMetrics
argument_list|(
argument|TT_Face     face
argument_list|,
argument|FT_UInt     idx
argument_list|,
argument|FT_Short*   lsb
argument_list|,
argument|FT_UShort*  aw
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
name|TT_Get_VMetrics
argument_list|(
argument|TT_Face     face
argument_list|,
argument|FT_UInt     idx
argument_list|,
argument|FT_Pos      yMax
argument_list|,
argument|FT_Short*   tsb
argument_list|,
argument|FT_UShort*  ah
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
name|TT_Load_Glyph
argument_list|(
argument|TT_Size       size
argument_list|,
argument|TT_GlyphSlot  glyph
argument_list|,
argument|FT_UInt       glyph_index
argument_list|,
argument|FT_Int32      load_flags
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
comment|/* __TTGLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
