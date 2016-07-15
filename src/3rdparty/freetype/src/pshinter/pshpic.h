begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pshpic.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for pshinter module. */
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
name|__PSHPIC_H__
end_ifndef
begin_define
DECL|macro|__PSHPIC_H__
define|#
directive|define
name|__PSHPIC_H__
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
DECL|macro|PSHINTER_INTERFACE_GET
define|#
directive|define
name|PSHINTER_INTERFACE_GET
value|pshinter_interface
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
include|FT_INTERNAL_POSTSCRIPT_HINTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|PSHinterPIC_
typedef|typedef
struct|struct
name|PSHinterPIC_
block|{
DECL|member|pshinter_interface
name|PSHinter_Interface
name|pshinter_interface
decl_stmt|;
block|}
DECL|typedef|PSHinterPIC
name|PSHinterPIC
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
value|( (PSHinterPIC*)( (lib)->pic_container.pshinter ) )
end_define
begin_define
DECL|macro|PSHINTER_INTERFACE_GET
define|#
directive|define
name|PSHINTER_INTERFACE_GET
value|( GET_PIC( library )->pshinter_interface )
end_define
begin_comment
comment|/* see pshpic.c for the implementation */
end_comment
begin_function_decl
name|void
name|pshinter_module_class_pic_free
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|FT_Error
name|pshinter_module_class_pic_init
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
comment|/* __PSHPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
