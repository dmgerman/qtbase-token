begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cidload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CID-keyed Type1 font loader (specification).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004 by                               */
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
name|__CIDLOAD_H__
end_ifndef
begin_define
DECL|macro|__CIDLOAD_H__
define|#
directive|define
name|__CIDLOAD_H__
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
file|"cidparse.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|CID_Loader_
typedef|typedef
struct|struct
name|CID_Loader_
block|{
DECL|member|parser
name|CID_Parser
name|parser
decl_stmt|;
comment|/* parser used to read the stream */
DECL|member|num_chars
name|FT_Int
name|num_chars
decl_stmt|;
comment|/* number of characters in encoding */
block|}
DECL|typedef|CID_Loader
name|CID_Loader
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|cid_get_offset
argument_list|(
argument|FT_Byte**  start
argument_list|,
argument|FT_Byte    offsize
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
DECL|variable|cid_face_open
name|cid_face_open
argument_list|(
argument|CID_Face  face
argument_list|,
argument|FT_Int    face_index
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
comment|/* __CIDLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
