begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svpsinfo.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType PostScript info service (specification).                */
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
name|__SVPSINFO_H__
end_ifndef
begin_define
DECL|macro|__SVPSINFO_H__
define|#
directive|define
name|__SVPSINFO_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_POSTSCRIPT_INFO
define|#
directive|define
name|FT_SERVICE_ID_POSTSCRIPT_INFO
value|"postscript-info"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PS_GetFontInfoFunc
modifier|*
name|PS_GetFontInfoFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontInfoRec
modifier|*
name|afont_info
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PS_GetFontExtraFunc
modifier|*
name|PS_GetFontExtraFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontExtraRec
modifier|*
name|afont_extra
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Int
function_decl|(
DECL|typedef|PS_HasGlyphNamesFunc
modifier|*
name|PS_HasGlyphNamesFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PS_GetFontPrivateFunc
modifier|*
name|PS_GetFontPrivateFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_PrivateRec
modifier|*
name|afont_private
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Long
function_decl|(
DECL|typedef|PS_GetFontValueFunc
modifier|*
name|PS_GetFontValueFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_Dict_Keys
name|key
parameter_list|,
name|FT_UInt
name|idx
parameter_list|,
name|void
modifier|*
name|value
parameter_list|,
name|FT_Long
name|value_len
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|PsInfo
argument_list|)
end_macro
begin_block
block|{
name|PS_GetFontInfoFunc
name|ps_get_font_info
decl_stmt|;
name|PS_GetFontExtraFunc
name|ps_get_font_extra
decl_stmt|;
name|PS_HasGlyphNamesFunc
name|ps_has_glyph_names
decl_stmt|;
name|PS_GetFontPrivateFunc
name|ps_get_font_private
decl_stmt|;
name|PS_GetFontValueFunc
name|ps_get_font_value
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
DECL|macro|FT_DEFINE_SERVICE_PSINFOREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSINFOREC
parameter_list|(
name|class_
parameter_list|,                     \
name|get_font_info_
parameter_list|,             \
name|ps_get_font_extra_
parameter_list|,         \
name|has_glyph_names_
parameter_list|,           \
name|get_font_private_
parameter_list|,          \
name|get_font_value_
parameter_list|)
define|\
value|static const FT_Service_PsInfoRec  class_ =                    \   {                                                              \     get_font_info_, ps_get_font_extra_, has_glyph_names_,        \     get_font_private_, get_font_value_                           \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_PSINFOREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSINFOREC
parameter_list|(
name|class_
parameter_list|,                     \
name|get_font_info_
parameter_list|,             \
name|ps_get_font_extra_
parameter_list|,         \
name|has_glyph_names_
parameter_list|,           \
name|get_font_private_
parameter_list|,          \
name|get_font_value_
parameter_list|)
define|\
value|void                                                           \   FT_Init_Class_ ## class_( FT_Library             library,      \                             FT_Service_PsInfoRec*  clazz )       \   {                                                              \     FT_UNUSED( library );                                        \                                                                  \     clazz->ps_get_font_info    = get_font_info_;                 \     clazz->ps_get_font_extra   = ps_get_font_extra_;             \     clazz->ps_has_glyph_names  = has_glyph_names_;               \     clazz->ps_get_font_private = get_font_private_;              \     clazz->ps_get_font_value   = get_font_value_;                \   }
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
comment|/* __SVPSINFO_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
