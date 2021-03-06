begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttcmap.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType character mapping table (cmap) support (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
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
name|__TTCMAP_H__
end_ifndef
begin_define
DECL|macro|__TTCMAP_H__
define|#
directive|define
name|__TTCMAP_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_VALIDATE_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_TT_CMAP_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|TT_CMAP_FLAG_UNSORTED
define|#
directive|define
name|TT_CMAP_FLAG_UNSORTED
value|1
end_define
begin_define
DECL|macro|TT_CMAP_FLAG_OVERLAPPING
define|#
directive|define
name|TT_CMAP_FLAG_OVERLAPPING
value|2
end_define
begin_typedef
DECL|struct|TT_CMapRec_
typedef|typedef
struct|struct
name|TT_CMapRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|data
name|FT_Byte
modifier|*
name|data
decl_stmt|;
comment|/* pointer to in-memory cmap table */
DECL|member|flags
name|FT_Int
name|flags
decl_stmt|;
comment|/* for format 4 only               */
block|}
DECL|typedef|TT_CMapRec
DECL|typedef|TT_CMap
name|TT_CMapRec
operator|,
typedef|*
name|TT_CMap
typedef|;
end_typedef
begin_typedef
DECL|typedef|TT_CMap_Class
typedef|typedef
specifier|const
name|struct
name|TT_CMap_ClassRec_
modifier|*
name|TT_CMap_Class
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_CMap_ValidateFunc
modifier|*
name|TT_CMap_ValidateFunc
function_decl|)
parameter_list|(
name|FT_Byte
modifier|*
name|data
parameter_list|,
name|FT_Validator
name|valid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|TT_CMap_ClassRec_
typedef|typedef
struct|struct
name|TT_CMap_ClassRec_
block|{
DECL|member|clazz
name|FT_CMap_ClassRec
name|clazz
decl_stmt|;
DECL|member|format
name|FT_UInt
name|format
decl_stmt|;
DECL|member|validate
name|TT_CMap_ValidateFunc
name|validate
decl_stmt|;
DECL|member|get_cmap_info
name|TT_CMap_Info_GetFunc
name|get_cmap_info
decl_stmt|;
block|}
DECL|typedef|TT_CMap_ClassRec
name|TT_CMap_ClassRec
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_TT_CMAP
define|#
directive|define
name|FT_DEFINE_TT_CMAP
parameter_list|(
name|class_
parameter_list|,             \
name|size_
parameter_list|,              \
name|init_
parameter_list|,              \
name|done_
parameter_list|,              \
name|char_index_
parameter_list|,        \
name|char_next_
parameter_list|,         \
name|char_var_index_
parameter_list|,    \
name|char_var_default_
parameter_list|,  \
name|variant_list_
parameter_list|,      \
name|charvariant_list_
parameter_list|,  \
name|variantchar_list_
parameter_list|,  \
name|format_
parameter_list|,            \
name|validate_
parameter_list|,          \
name|get_cmap_info_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                        \   const TT_CMap_ClassRec  class_ =             \   {                                            \     { size_,                                   \       init_,                                   \       done_,                                   \       char_index_,                             \       char_next_,                              \       char_var_index_,                         \       char_var_default_,                       \       variant_list_,                           \       charvariant_list_,                       \       variantchar_list_                        \     },                                         \                                                \     format_,                                   \     validate_,                                 \     get_cmap_info_                             \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_TT_CMAP
define|#
directive|define
name|FT_DEFINE_TT_CMAP
parameter_list|(
name|class_
parameter_list|,                      \
name|size_
parameter_list|,                       \
name|init_
parameter_list|,                       \
name|done_
parameter_list|,                       \
name|char_index_
parameter_list|,                 \
name|char_next_
parameter_list|,                  \
name|char_var_index_
parameter_list|,             \
name|char_var_default_
parameter_list|,           \
name|variant_list_
parameter_list|,               \
name|charvariant_list_
parameter_list|,           \
name|variantchar_list_
parameter_list|,           \
name|format_
parameter_list|,                     \
name|validate_
parameter_list|,                   \
name|get_cmap_info_
parameter_list|)
define|\
value|void                                                  \   FT_Init_Class_ ## class_( TT_CMap_ClassRec*  clazz )  \   {                                                     \     clazz->clazz.size             = size_;              \     clazz->clazz.init             = init_;              \     clazz->clazz.done             = done_;              \     clazz->clazz.char_index       = char_index_;        \     clazz->clazz.char_next        = char_next_;         \     clazz->clazz.char_var_index   = char_var_index_;    \     clazz->clazz.char_var_default = char_var_default_;  \     clazz->clazz.variant_list     = variant_list_;      \     clazz->clazz.charvariant_list = charvariant_list_;  \     clazz->clazz.variantchar_list = variantchar_list_;  \     clazz->format                 = format_;            \     clazz->validate               = validate_;          \     clazz->get_cmap_info          = get_cmap_info_;     \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_typedef
DECL|struct|TT_ValidatorRec_
typedef|typedef
struct|struct
name|TT_ValidatorRec_
block|{
DECL|member|validator
name|FT_ValidatorRec
name|validator
decl_stmt|;
DECL|member|num_glyphs
name|FT_UInt
name|num_glyphs
decl_stmt|;
block|}
DECL|typedef|TT_ValidatorRec
DECL|typedef|TT_Validator
name|TT_ValidatorRec
operator|,
typedef|*
name|TT_Validator
typedef|;
end_typedef
begin_define
DECL|macro|TT_VALIDATOR
define|#
directive|define
name|TT_VALIDATOR
parameter_list|(
name|x
parameter_list|)
value|( (TT_Validator)( x ) )
end_define
begin_define
DECL|macro|TT_VALID_GLYPH_COUNT
define|#
directive|define
name|TT_VALID_GLYPH_COUNT
parameter_list|(
name|x
parameter_list|)
value|TT_VALIDATOR( x )->num_glyphs
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_build_cmaps
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* used in tt-cmaps service */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_get_cmap_info
name|tt_get_cmap_info
argument_list|(
argument|FT_CharMap    charmap
argument_list|,
argument|TT_CMapInfo  *cmap_info
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTCMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
