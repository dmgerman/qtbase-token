begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  sfobjs.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    SFNT object management (specification).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002 by                                           */
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
name|__SFOBJS_H__
end_ifndef
begin_define
DECL|macro|__SFOBJS_H__
define|#
directive|define
name|__SFOBJS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SFNT_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|sfnt_init_face
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|TT_Face
name|face
parameter_list|,
name|FT_Int
name|face_index
parameter_list|,
name|FT_Int
name|num_params
parameter_list|,
name|FT_Parameter
modifier|*
name|params
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
DECL|variable|sfnt_load_face
name|sfnt_load_face
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|TT_Face        face
argument_list|,
argument|FT_Int         face_index
argument_list|,
argument|FT_Int         num_params
argument_list|,
argument|FT_Parameter*  params
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
name|sfnt_done_face
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
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
comment|/* __SFDRIVER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
