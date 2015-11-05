begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttpic.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for truetype module. */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009-2015 by                                                 */
end_comment
begin_comment
comment|/*  Oran Agra and Mickey Gabel.                                            */
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
name|__TTPIC_H__
end_ifndef
begin_define
DECL|macro|__TTPIC_H__
define|#
directive|define
name|__TTPIC_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_PIC_H
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|TT_SERVICES_GET
define|#
directive|define
name|TT_SERVICES_GET
value|tt_services
end_define
begin_define
DECL|macro|TT_SERVICE_GX_MULTI_MASTERS_GET
define|#
directive|define
name|TT_SERVICE_GX_MULTI_MASTERS_GET
value|tt_service_gx_multi_masters
end_define
begin_define
DECL|macro|TT_SERVICE_TRUETYPE_GLYF_GET
define|#
directive|define
name|TT_SERVICE_TRUETYPE_GLYF_GET
value|tt_service_truetype_glyf
end_define
begin_define
DECL|macro|TT_SERVICE_PROPERTIES_GET
define|#
directive|define
name|TT_SERVICE_PROPERTIES_GET
value|tt_service_properties
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_include
include|#
directive|include
include|FT_MULTIPLE_MASTERS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_MULTIPLE_MASTERS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_TRUETYPE_GLYF_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_PROPERTIES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|TTModulePIC_
typedef|typedef
struct|struct
name|TTModulePIC_
block|{
DECL|member|tt_services
name|FT_ServiceDescRec
modifier|*
name|tt_services
decl_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
DECL|member|tt_service_gx_multi_masters
name|FT_Service_MultiMastersRec
name|tt_service_gx_multi_masters
decl_stmt|;
endif|#
directive|endif
DECL|member|tt_service_truetype_glyf
name|FT_Service_TTGlyfRec
name|tt_service_truetype_glyf
decl_stmt|;
DECL|member|tt_service_properties
name|FT_Service_PropertiesRec
name|tt_service_properties
decl_stmt|;
block|}
DECL|typedef|TTModulePIC
name|TTModulePIC
typedef|;
end_typedef
begin_define
DECL|macro|GET_PIC
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
define|\
value|( (TTModulePIC*)((lib)->pic_container.truetype) )
end_define
begin_define
DECL|macro|TT_SERVICES_GET
define|#
directive|define
name|TT_SERVICES_GET
define|\
value|( GET_PIC( library )->tt_services )
end_define
begin_define
DECL|macro|TT_SERVICE_GX_MULTI_MASTERS_GET
define|#
directive|define
name|TT_SERVICE_GX_MULTI_MASTERS_GET
define|\
value|( GET_PIC( library )->tt_service_gx_multi_masters )
end_define
begin_define
DECL|macro|TT_SERVICE_TRUETYPE_GLYF_GET
define|#
directive|define
name|TT_SERVICE_TRUETYPE_GLYF_GET
define|\
value|( GET_PIC( library )->tt_service_truetype_glyf )
end_define
begin_define
DECL|macro|TT_SERVICE_PROPERTIES_GET
define|#
directive|define
name|TT_SERVICE_PROPERTIES_GET
define|\
value|( GET_PIC( library )->tt_service_properties )
end_define
begin_comment
comment|/* see ttpic.c for the implementation */
end_comment
begin_function_decl
name|void
name|tt_driver_class_pic_free
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|FT_Error
name|tt_driver_class_pic_init
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_END_HEADER
end_macro
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
