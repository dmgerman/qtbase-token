begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  otvmod.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType's OpenType validation module implementation                 */
end_comment
begin_comment
comment|/*    (specification).                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004 by                                                      */
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
name|__OTVMOD_H__
end_ifndef
begin_define
DECL|macro|__OTVMOD_H__
define|#
directive|define
name|__OTVMOD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
error|#
directive|error
literal|"this module does not support PIC yet"
endif|#
directive|endif
name|FT_EXPORT_VAR
argument_list|(
specifier|const
name|FT_Module_Class
argument_list|)
name|otv_module_class
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __OTVMOD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
