begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afpic.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for autofit module.  */
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
name|__AFPIC_H__
end_ifndef
begin_define
DECL|macro|__AFPIC_H__
define|#
directive|define
name|__AFPIC_H__
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
DECL|macro|AF_SCRIPT_CLASSES_GET
define|#
directive|define
name|AF_SCRIPT_CLASSES_GET
value|af_script_classes
end_define
begin_define
DECL|macro|AF_AF_AUTOFITTER_SERVICE_GET
define|#
directive|define
name|AF_AF_AUTOFITTER_SERVICE_GET
value|af_autofitter_service
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
file|"aftypes.h"
end_include
begin_comment
comment|/* increase these when you add new scripts, and update autofit_module_class_pic_init */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_OPTION_AUTOFIT2
end_ifdef
begin_define
define|#
directive|define
name|AF_SCRIPT_CLASSES_COUNT
value|6
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|AF_SCRIPT_CLASSES_COUNT
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
define|#
directive|define
name|AF_SCRIPT_CLASSES_REC_COUNT
value|(AF_SCRIPT_CLASSES_COUNT-1)
end_define
begin_typedef
typedef|typedef
struct|struct
name|AFModulePIC_
block|{
name|AF_ScriptClass
name|af_script_classes
index|[
name|AF_SCRIPT_CLASSES_COUNT
index|]
decl_stmt|;
name|AF_ScriptClassRec
name|af_script_classes_rec
index|[
name|AF_SCRIPT_CLASSES_REC_COUNT
index|]
decl_stmt|;
name|FT_AutoHinter_ServiceRec
name|af_autofitter_service
decl_stmt|;
block|}
name|AFModulePIC
typedef|;
end_typedef
begin_define
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
value|((AFModulePIC*)((lib)->pic_container.autofit))
end_define
begin_define
define|#
directive|define
name|AF_SCRIPT_CLASSES_GET
value|(GET_PIC(FT_FACE_LIBRARY(globals->face))->af_script_classes)
end_define
begin_define
define|#
directive|define
name|AF_AF_AUTOFITTER_SERVICE_GET
value|(GET_PIC(library)->af_autofitter_service)
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
comment|/* __AFPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
