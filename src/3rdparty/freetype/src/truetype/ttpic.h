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
comment|/*  Copyright 2009 by                                                      */
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
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_TT_SERVICES_GET
define|#
directive|define
name|FT_TT_SERVICES_GET
value|tt_services
end_define
begin_define
DECL|macro|FT_TT_SERVICE_GX_MULTI_MASTERS_GET
define|#
directive|define
name|FT_TT_SERVICE_GX_MULTI_MASTERS_GET
value|tt_service_gx_multi_masters
end_define
begin_define
DECL|macro|FT_TT_SERVICE_TRUETYPE_GLYF_GET
define|#
directive|define
name|FT_TT_SERVICE_TRUETYPE_GLYF_GET
value|tt_service_truetype_glyf
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
begin_typedef
typedef|typedef
struct|struct
name|TTModulePIC_
block|{
name|FT_ServiceDescRec
modifier|*
name|tt_services
decl_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
name|FT_Service_MultiMastersRec
name|tt_service_gx_multi_masters
decl_stmt|;
endif|#
directive|endif
name|FT_Service_TTGlyfRec
name|tt_service_truetype_glyf
decl_stmt|;
block|}
name|TTModulePIC
typedef|;
end_typedef
begin_define
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
value|((TTModulePIC*)((lib)->pic_container.truetype))
end_define
begin_define
define|#
directive|define
name|FT_TT_SERVICES_GET
value|(GET_PIC(library)->tt_services)
end_define
begin_define
define|#
directive|define
name|FT_TT_SERVICE_GX_MULTI_MASTERS_GET
value|(GET_PIC(library)->tt_service_gx_multi_masters)
end_define
begin_define
define|#
directive|define
name|FT_TT_SERVICE_TRUETYPE_GLYF_GET
value|(GET_PIC(library)->tt_service_truetype_glyf)
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
comment|/* __TTPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
