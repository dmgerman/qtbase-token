begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afmodule.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter module implementation (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003-2015 by                                                 */
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
name|__AFMODULE_H__
end_ifndef
begin_define
DECL|macro|__AFMODULE_H__
define|#
directive|define
name|__AFMODULE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*    *  This is the `extended' FT_Module structure that holds the    *  autofitter's global data.    */
end_comment
begin_typedef
DECL|struct|AF_ModuleRec_
typedef|typedef
struct|struct
name|AF_ModuleRec_
block|{
DECL|member|root
name|FT_ModuleRec
name|root
decl_stmt|;
DECL|member|fallback_style
name|FT_UInt
name|fallback_style
decl_stmt|;
DECL|member|default_script
name|FT_UInt
name|default_script
decl_stmt|;
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_USE_WARPER
DECL|member|warping
name|FT_Bool
name|warping
decl_stmt|;
endif|#
directive|endif
block|}
DECL|typedef|AF_ModuleRec
DECL|typedef|AF_Module
name|AF_ModuleRec
operator|,
typedef|*
name|AF_Module
typedef|;
end_typedef
begin_macro
name|FT_DECLARE_MODULE
argument_list|(
argument|autofit_module_class
argument_list|)
end_macro
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFMODULE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
