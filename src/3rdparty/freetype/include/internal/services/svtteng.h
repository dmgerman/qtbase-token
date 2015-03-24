begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svtteng.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType TrueType engine query service (specification).          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006 by                                                      */
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
name|__SVTTENG_H__
end_ifndef
begin_define
DECL|macro|__SVTTENG_H__
define|#
directive|define
name|__SVTTENG_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_function
name|FT_BEGIN_HEADER
comment|/*    *  SFNT table loading service.    */
DECL|macro|FT_SERVICE_ID_TRUETYPE_ENGINE
define|#
directive|define
name|FT_SERVICE_ID_TRUETYPE_ENGINE
value|"truetype-engine"
comment|/*    * Used to implement FT_Get_TrueType_Engine_Type    */
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
parameter_list|(
name|TrueTypeEngine
parameter_list|)
block|{
name|FT_TrueTypeEngineType
name|engine_type
decl_stmt|;
block|}
end_function
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
comment|/* __SVTTENG_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
