begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftbase.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType private functions used in base module (specification).  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2008, 2010 by                                                */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, Werner Lemberg, and suzuki toshiya.      */
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
name|__FTBASE_H__
end_ifndef
begin_define
DECL|macro|__FTBASE_H__
define|#
directive|define
name|__FTBASE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
comment|/* Assume the stream is sfnt-wrapped PS Type1 or sfnt-wrapped CID-keyed */
comment|/* font, and try to load a face specified by the face_index.            */
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|open_face_PS_from_sfnt_stream
parameter_list|(
name|FT_Library
name|library
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_Long
name|face_index
parameter_list|,
name|FT_Int
name|num_params
parameter_list|,
name|FT_Parameter
modifier|*
name|params
parameter_list|,
name|FT_Face
modifier|*
name|aface
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Create a new FT_Face given a buffer and a driver name. */
end_comment
begin_comment
comment|/* From ftmac.c.                                          */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|open_face_from_buffer
name|open_face_from_buffer
argument_list|(
argument|FT_Library   library
argument_list|,
argument|FT_Byte*     base
argument_list|,
argument|FT_ULong     size
argument_list|,
argument|FT_Long      face_index
argument_list|,
argument|const char*  driver_name
argument_list|,
argument|FT_Face     *aface
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
comment|/* __FTBASE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
