begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1gload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 Glyph Loader (specification).                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2008, 2011 by                         */
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
name|__T1GLOAD_H__
end_ifndef
begin_define
DECL|macro|__T1GLOAD_H__
define|#
directive|define
name|__T1GLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"t1objs.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|T1_Compute_Max_Advance
parameter_list|(
name|T1_Face
name|face
parameter_list|,
name|FT_Pos
modifier|*
name|max_advance
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
DECL|variable|T1_Get_Advances
name|T1_Get_Advances
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    first
argument_list|,
argument|FT_UInt    count
argument_list|,
argument|FT_Int32   load_flags
argument_list|,
argument|FT_Fixed*  advances
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
name|T1_Load_Glyph
argument_list|(
argument|FT_GlyphSlot  glyph
argument_list|,
argument|FT_Size       size
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
comment|/* __T1GLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
