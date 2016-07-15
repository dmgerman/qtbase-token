begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svsfnt.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType SFNT table loading service (specification).             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004 by                                                */
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
name|__SVSFNT_H__
end_ifndef
begin_define
DECL|macro|__SVSFNT_H__
define|#
directive|define
name|__SVSFNT_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*    *  SFNT table loading service.    */
end_comment
begin_define
DECL|macro|FT_SERVICE_ID_SFNT_TABLE
define|#
directive|define
name|FT_SERVICE_ID_SFNT_TABLE
value|"sfnt-table"
end_define
begin_comment
comment|/*    * Used to implement FT_Load_Sfnt_Table().    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_SFNT_TableLoadFunc
modifier|*
name|FT_SFNT_TableLoadFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_ULong
name|tag
parameter_list|,
name|FT_Long
name|offset
parameter_list|,
name|FT_Byte
modifier|*
name|buffer
parameter_list|,
name|FT_ULong
modifier|*
name|length
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    * Used to implement FT_Get_Sfnt_Table().    */
end_comment
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
DECL|typedef|FT_SFNT_TableGetFunc
modifier|*
name|FT_SFNT_TableGetFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Sfnt_Tag
name|tag
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    * Used to implement FT_Sfnt_Table_Info().    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_SFNT_TableInfoFunc
modifier|*
name|FT_SFNT_TableInfoFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|idx
parameter_list|,
name|FT_ULong
modifier|*
name|tag
parameter_list|,
name|FT_ULong
modifier|*
name|length
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|SFNT_Table
argument_list|)
end_macro
begin_block
block|{
name|FT_SFNT_TableLoadFunc
name|load_table
decl_stmt|;
name|FT_SFNT_TableGetFunc
name|get_table
decl_stmt|;
name|FT_SFNT_TableInfoFunc
name|table_info
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __SVSFNT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
