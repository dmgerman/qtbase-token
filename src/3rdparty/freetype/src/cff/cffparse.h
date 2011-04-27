begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cffparse.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CFF token stream parser (specification)                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003 by                                     */
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
name|__CFF_PARSE_H__
end_ifndef
begin_define
DECL|macro|__CFF_PARSE_H__
define|#
directive|define
name|__CFF_PARSE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"cfftypes.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|CFF_MAX_STACK_DEPTH
define|#
directive|define
name|CFF_MAX_STACK_DEPTH
value|96
end_define
begin_define
DECL|macro|CFF_CODE_TOPDICT
define|#
directive|define
name|CFF_CODE_TOPDICT
value|0x1000
end_define
begin_define
DECL|macro|CFF_CODE_PRIVATE
define|#
directive|define
name|CFF_CODE_PRIVATE
value|0x2000
end_define
begin_typedef
DECL|struct|CFF_ParserRec_
typedef|typedef
struct|struct
name|CFF_ParserRec_
block|{
DECL|member|start
name|FT_Byte
modifier|*
name|start
decl_stmt|;
DECL|member|limit
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
DECL|member|cursor
name|FT_Byte
modifier|*
name|cursor
decl_stmt|;
DECL|member|stack
name|FT_Byte
modifier|*
name|stack
index|[
name|CFF_MAX_STACK_DEPTH
operator|+
literal|1
index|]
decl_stmt|;
DECL|member|top
name|FT_Byte
modifier|*
modifier|*
name|top
decl_stmt|;
DECL|member|object_code
name|FT_UInt
name|object_code
decl_stmt|;
DECL|member|object
name|void
modifier|*
name|object
decl_stmt|;
block|}
DECL|typedef|CFF_ParserRec
DECL|typedef|CFF_Parser
name|CFF_ParserRec
operator|,
typedef|*
name|CFF_Parser
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cff_parser_init
argument_list|(
argument|CFF_Parser  parser
argument_list|,
argument|FT_UInt     code
argument_list|,
argument|void*       object
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
name|cff_parser_run
argument_list|(
argument|CFF_Parser  parser
argument_list|,
argument|FT_Byte*    start
argument_list|,
argument|FT_Byte*    limit
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
comment|/* __CFF_PARSE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
