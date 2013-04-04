begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svbdf.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType BDF services (specification).                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003 by                                                      */
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
name|__SVBDF_H__
end_ifndef
begin_define
DECL|macro|__SVBDF_H__
define|#
directive|define
name|__SVBDF_H__
end_define
begin_include
include|#
directive|include
include|FT_BDF_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_BDF
define|#
directive|define
name|FT_SERVICE_ID_BDF
value|"bdf"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_BDF_GetCharsetIdFunc
modifier|*
name|FT_BDF_GetCharsetIdFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|acharset_encoding
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|acharset_registry
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_BDF_GetPropertyFunc
modifier|*
name|FT_BDF_GetPropertyFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
specifier|const
name|char
modifier|*
name|prop_name
parameter_list|,
name|BDF_PropertyRec
modifier|*
name|aproperty
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|BDF
argument_list|)
end_macro
begin_block
block|{
name|FT_BDF_GetCharsetIdFunc
name|get_charset_id
decl_stmt|;
name|FT_BDF_GetPropertyFunc
name|get_property
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
DECL|macro|FT_DEFINE_SERVICE_BDFRec
define|#
directive|define
name|FT_DEFINE_SERVICE_BDFRec
parameter_list|(
name|class_
parameter_list|,
name|get_charset_id_
parameter_list|,
name|get_property_
parameter_list|)
define|\
value|static const FT_Service_BDFRec class_ =                                \   {                                                                      \     get_charset_id_, get_property_                                       \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_BDFRec
define|#
directive|define
name|FT_DEFINE_SERVICE_BDFRec
parameter_list|(
name|class_
parameter_list|,
name|get_charset_id_
parameter_list|,
name|get_property_
parameter_list|)
define|\
value|void                                                                   \   FT_Init_Class_##class_( FT_Service_BDFRec*  clazz )                    \   {                                                                      \     clazz->get_charset_id = get_charset_id_;                             \     clazz->get_property = get_property_;                                 \   }
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
comment|/* __SVBDF_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
