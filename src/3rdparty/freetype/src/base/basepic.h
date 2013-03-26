begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  basepic.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for base.            */
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
name|__BASEPIC_H__
end_ifndef
begin_define
DECL|macro|__BASEPIC_H__
define|#
directive|define
name|__BASEPIC_H__
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
DECL|macro|FT_OUTLINE_GLYPH_CLASS_GET
define|#
directive|define
name|FT_OUTLINE_GLYPH_CLASS_GET
value|&ft_outline_glyph_class
end_define
begin_define
DECL|macro|FT_BITMAP_GLYPH_CLASS_GET
define|#
directive|define
name|FT_BITMAP_GLYPH_CLASS_GET
value|&ft_bitmap_glyph_class
end_define
begin_define
DECL|macro|FT_DEFAULT_MODULES_GET
define|#
directive|define
name|FT_DEFAULT_MODULES_GET
value|ft_default_modules
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
include|FT_GLYPH_H
end_include
begin_typedef
typedef|typedef
struct|struct
name|BasePIC_
block|{
name|FT_Module_Class
modifier|*
modifier|*
name|default_module_classes
decl_stmt|;
name|FT_Glyph_Class
name|ft_outline_glyph_class
decl_stmt|;
name|FT_Glyph_Class
name|ft_bitmap_glyph_class
decl_stmt|;
block|}
name|BasePIC
typedef|;
end_typedef
begin_define
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
value|((BasePIC*)((lib)->pic_container.base))
end_define
begin_define
define|#
directive|define
name|FT_OUTLINE_GLYPH_CLASS_GET
value|(&GET_PIC(library)->ft_outline_glyph_class)
end_define
begin_define
define|#
directive|define
name|FT_BITMAP_GLYPH_CLASS_GET
value|(&GET_PIC(library)->ft_bitmap_glyph_class)
end_define
begin_define
define|#
directive|define
name|FT_DEFAULT_MODULES_GET
value|(GET_PIC(library)->default_module_classes)
end_define
begin_function_decl
name|void
name|ft_base_pic_free
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|FT_Error
name|ft_base_pic_init
parameter_list|(
name|FT_Library
name|library
parameter_list|)
function_decl|;
end_function_decl
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
comment|/* __BASEPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
