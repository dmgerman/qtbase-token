begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svgldict.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType glyph dictionary services (specification).              */
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
name|__SVGLDICT_H__
end_ifndef
begin_define
DECL|macro|__SVGLDICT_H__
define|#
directive|define
name|__SVGLDICT_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*    *  A service used to retrieve glyph names, as well as to find the    *  index of a given glyph name in a font.    *    */
end_comment
begin_define
DECL|macro|FT_SERVICE_ID_GLYPH_DICT
define|#
directive|define
name|FT_SERVICE_ID_GLYPH_DICT
value|"glyph-dict"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_GlyphDict_GetNameFunc
modifier|*
name|FT_GlyphDict_GetNameFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Pointer
name|buffer
parameter_list|,
name|FT_UInt
name|buffer_max
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_GlyphDict_NameIndexFunc
modifier|*
name|FT_GlyphDict_NameIndexFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_String
modifier|*
name|glyph_name
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|GlyphDict
argument_list|)
end_macro
begin_block
block|{
name|FT_GlyphDict_GetNameFunc
name|get_name
decl_stmt|;
name|FT_GlyphDict_NameIndexFunc
name|name_index
decl_stmt|;
comment|/* optional */
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
DECL|macro|FT_DEFINE_SERVICE_GLYPHDICTREC
define|#
directive|define
name|FT_DEFINE_SERVICE_GLYPHDICTREC
parameter_list|(
name|class_
parameter_list|,
name|get_name_
parameter_list|,
name|name_index_
parameter_list|)
define|\
value|static const FT_Service_GlyphDictRec class_ =                        \   {                                                                    \     get_name_, name_index_                                             \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_GLYPHDICTREC
define|#
directive|define
name|FT_DEFINE_SERVICE_GLYPHDICTREC
parameter_list|(
name|class_
parameter_list|,
name|get_name_
parameter_list|,
name|name_index_
parameter_list|)
define|\
value|void                                                                 \   FT_Init_Class_##class_( FT_Library library,                          \                           FT_Service_GlyphDictRec* clazz)              \   {                                                                    \     FT_UNUSED(library);                                                \     clazz->get_name = get_name_;                                       \     clazz->name_index = name_index_;                                   \   }
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
comment|/* __SVGLDICT_H__ */
end_comment
end_unit
