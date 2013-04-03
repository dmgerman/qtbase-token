begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pspic.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for psnames module.  */
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
name|__PSPIC_H__
end_ifndef
begin_define
DECL|macro|__PSPIC_H__
define|#
directive|define
name|__PSPIC_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
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
DECL|macro|FT_PSCMAPS_SERVICES_GET
define|#
directive|define
name|FT_PSCMAPS_SERVICES_GET
value|pscmaps_services
end_define
begin_define
DECL|macro|FT_PSCMAPS_INTERFACE_GET
define|#
directive|define
name|FT_PSCMAPS_INTERFACE_GET
value|pscmaps_interface
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
include|FT_SERVICE_POSTSCRIPT_CMAPS_H
end_include
begin_typedef
typedef|typedef
struct|struct
name|PSModulePIC_
block|{
name|FT_ServiceDescRec
modifier|*
name|pscmaps_services
decl_stmt|;
name|FT_Service_PsCMapsRec
name|pscmaps_interface
decl_stmt|;
block|}
name|PSModulePIC
typedef|;
end_typedef
begin_define
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
value|((PSModulePIC*)((lib)->pic_container.psnames))
end_define
begin_define
define|#
directive|define
name|FT_PSCMAPS_SERVICES_GET
value|(GET_PIC(library)->pscmaps_services)
end_define
begin_define
define|#
directive|define
name|FT_PSCMAPS_INTERFACE_GET
value|(GET_PIC(library)->pscmaps_interface)
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
comment|/* __PSPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
