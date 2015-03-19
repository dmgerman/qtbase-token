begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svprop.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType property service (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2012 by                                                      */
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
name|__SVPROP_H__
end_ifndef
begin_define
DECL|macro|__SVPROP_H__
define|#
directive|define
name|__SVPROP_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_PROPERTIES
define|#
directive|define
name|FT_SERVICE_ID_PROPERTIES
value|"properties"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Properties_SetFunc
modifier|*
name|FT_Properties_SetFunc
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|property_name
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Properties_GetFunc
modifier|*
name|FT_Properties_GetFunc
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|property_name
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|Properties
argument_list|)
end_macro
begin_block
block|{
name|FT_Properties_SetFunc
name|set_property
decl_stmt|;
name|FT_Properties_GetFunc
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
DECL|macro|FT_DEFINE_SERVICE_PROPERTIESREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PROPERTIESREC
parameter_list|(
name|class_
parameter_list|,          \
name|set_property_
parameter_list|,   \
name|get_property_
parameter_list|)
define|\
value|static const FT_Service_PropertiesRec  class_ =         \   {                                                       \     set_property_,                                        \     get_property_                                         \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_PROPERTIESREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PROPERTIESREC
parameter_list|(
name|class_
parameter_list|,                \
name|set_property_
parameter_list|,         \
name|get_property_
parameter_list|)
define|\
value|void                                                          \   FT_Init_Class_ ## class_( FT_Service_PropertiesRec*  clazz )  \   {                                                             \     clazz->set_property = set_property_;                        \     clazz->get_property = get_property_;                        \   }
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
comment|/* __SVPROP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
