begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svpostnm.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType PostScript name services (specification).               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2007 by                                                */
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
name|__SVPOSTNM_H__
end_ifndef
begin_define
DECL|macro|__SVPOSTNM_H__
define|#
directive|define
name|__SVPOSTNM_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*    *  A trivial service used to retrieve the PostScript name of a given    *  font when available.  The `get_name' field should never be NULL.    *    *  The corresponding function can return NULL to indicate that the    *  PostScript name is not available.    *    *  The name is owned by the face and will be destroyed with it.    */
end_comment
begin_define
DECL|macro|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
define|#
directive|define
name|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
value|"postscript-font-name"
end_define
begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
DECL|typedef|FT_PsName_GetFunc
modifier|*
name|FT_PsName_GetFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|PsFontName
argument_list|)
end_macro
begin_block
block|{
name|FT_PsName_GetFunc
name|get_ps_font_name
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_SERVICE_PSFONTNAMEREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSFONTNAMEREC
parameter_list|(
name|class_
parameter_list|,
name|get_ps_font_name_
parameter_list|)
define|\
value|static const FT_Service_PsFontNameRec class_ =                   \   {                                                                \     get_ps_font_name_                                              \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_PSFONTNAMEREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSFONTNAMEREC
parameter_list|(
name|class_
parameter_list|,
name|get_ps_font_name_
parameter_list|)
define|\
value|void                                                             \   FT_Init_Class_##class_( FT_Library library,                      \                           FT_Service_PsFontNameRec* clazz)         \   {                                                                \     FT_UNUSED(library);                                            \     clazz->get_ps_font_name = get_ps_font_name_;                   \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
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
comment|/* __SVPOSTNM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
