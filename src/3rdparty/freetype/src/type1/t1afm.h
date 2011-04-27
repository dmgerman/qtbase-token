begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1afm.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    AFM support for Type 1 fonts (specification).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2006 by                                     */
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
name|__T1AFM_H__
end_ifndef
begin_define
DECL|macro|__T1AFM_H__
define|#
directive|define
name|__T1AFM_H__
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
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|T1_Read_Metrics
parameter_list|(
name|FT_Face
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
DECL|variable|T1_Done_Metrics
name|T1_Done_Metrics
argument_list|(
argument|FT_Memory     memory
argument_list|,
argument|AFM_FontInfo  fi
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
name|T1_Get_Kerning
argument_list|(
argument|AFM_FontInfo  fi
argument_list|,
argument|FT_UInt       glyph1
argument_list|,
argument|FT_UInt       glyph2
argument_list|,
argument|FT_Vector*    kerning
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
name|T1_Get_Track_Kerning
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_Fixed   ptsize
argument_list|,
argument|FT_Int     degree
argument_list|,
argument|FT_Fixed*  kerning
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
comment|/* __T1AFM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
