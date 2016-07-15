begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svpscmap.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType PostScript charmap service (specification).             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2006, 2009, 2012 by                                    */
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
name|__SVPSCMAP_H__
end_ifndef
begin_define
DECL|macro|__SVPSCMAP_H__
define|#
directive|define
name|__SVPSCMAP_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_POSTSCRIPT_CMAPS
define|#
directive|define
name|FT_SERVICE_ID_POSTSCRIPT_CMAPS
value|"postscript-cmaps"
end_define
begin_comment
comment|/*    *  Adobe glyph name to unicode value.    */
end_comment
begin_typedef
typedef|typedef
name|FT_UInt32
function_decl|(
DECL|typedef|PS_Unicode_ValueFunc
modifier|*
name|PS_Unicode_ValueFunc
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|glyph_name
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    *  Macintosh name id to glyph name.  NULL if invalid index.    */
end_comment
begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
DECL|typedef|PS_Macintosh_NameFunc
modifier|*
name|PS_Macintosh_NameFunc
function_decl|)
parameter_list|(
name|FT_UInt
name|name_index
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    *  Adobe standard string ID to glyph name.  NULL if invalid index.    */
end_comment
begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
DECL|typedef|PS_Adobe_Std_StringsFunc
modifier|*
name|PS_Adobe_Std_StringsFunc
function_decl|)
parameter_list|(
name|FT_UInt
name|string_index
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    *  Simple unicode -> glyph index charmap built from font glyph names    *  table.    */
end_comment
begin_typedef
DECL|struct|PS_UniMap_
typedef|typedef
struct|struct
name|PS_UniMap_
block|{
DECL|member|unicode
name|FT_UInt32
name|unicode
decl_stmt|;
comment|/* bit 31 set: is glyph variant */
DECL|member|glyph_index
name|FT_UInt
name|glyph_index
decl_stmt|;
block|}
DECL|typedef|PS_UniMap
name|PS_UniMap
typedef|;
end_typedef
begin_typedef
DECL|typedef|PS_Unicodes
typedef|typedef
name|struct
name|PS_UnicodesRec_
modifier|*
name|PS_Unicodes
typedef|;
end_typedef
begin_typedef
DECL|struct|PS_UnicodesRec_
typedef|typedef
struct|struct
name|PS_UnicodesRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|num_maps
name|FT_UInt
name|num_maps
decl_stmt|;
DECL|member|maps
name|PS_UniMap
modifier|*
name|maps
decl_stmt|;
block|}
DECL|typedef|PS_UnicodesRec
name|PS_UnicodesRec
typedef|;
end_typedef
begin_comment
comment|/*    *  A function which returns a glyph name for a given index.  Returns    *  NULL if invalid index.    */
end_comment
begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
DECL|typedef|PS_GetGlyphNameFunc
modifier|*
name|PS_GetGlyphNameFunc
function_decl|)
parameter_list|(
name|FT_Pointer
name|data
parameter_list|,
name|FT_UInt
name|string_index
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    *  A function used to release the glyph name returned by    *  PS_GetGlyphNameFunc, when needed    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|PS_FreeGlyphNameFunc
modifier|*
name|PS_FreeGlyphNameFunc
function_decl|)
parameter_list|(
name|FT_Pointer
name|data
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PS_Unicodes_InitFunc
modifier|*
name|PS_Unicodes_InitFunc
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|PS_Unicodes
name|unicodes
parameter_list|,
name|FT_UInt
name|num_glyphs
parameter_list|,
name|PS_GetGlyphNameFunc
name|get_glyph_name
parameter_list|,
name|PS_FreeGlyphNameFunc
name|free_glyph_name
parameter_list|,
name|FT_Pointer
name|glyph_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|PS_Unicodes_CharIndexFunc
modifier|*
name|PS_Unicodes_CharIndexFunc
function_decl|)
parameter_list|(
name|PS_Unicodes
name|unicodes
parameter_list|,
name|FT_UInt32
name|unicode
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt32
function_decl|(
DECL|typedef|PS_Unicodes_CharNextFunc
modifier|*
name|PS_Unicodes_CharNextFunc
function_decl|)
parameter_list|(
name|PS_Unicodes
name|unicodes
parameter_list|,
name|FT_UInt32
modifier|*
name|unicode
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|PsCMaps
argument_list|)
end_macro
begin_block
block|{
name|PS_Unicode_ValueFunc
name|unicode_value
decl_stmt|;
name|PS_Unicodes_InitFunc
name|unicodes_init
decl_stmt|;
name|PS_Unicodes_CharIndexFunc
name|unicodes_char_index
decl_stmt|;
name|PS_Unicodes_CharNextFunc
name|unicodes_char_next
decl_stmt|;
name|PS_Macintosh_NameFunc
name|macintosh_name
decl_stmt|;
name|PS_Adobe_Std_StringsFunc
name|adobe_std_strings
decl_stmt|;
specifier|const
name|unsigned
name|short
modifier|*
name|adobe_std_encoding
decl_stmt|;
specifier|const
name|unsigned
name|short
modifier|*
name|adobe_expert_encoding
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
DECL|macro|FT_DEFINE_SERVICE_PSCMAPSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSCMAPSREC
parameter_list|(
name|class_
parameter_list|,                               \
name|unicode_value_
parameter_list|,                       \
name|unicodes_init_
parameter_list|,                       \
name|unicodes_char_index_
parameter_list|,                 \
name|unicodes_char_next_
parameter_list|,                  \
name|macintosh_name_
parameter_list|,                      \
name|adobe_std_strings_
parameter_list|,                   \
name|adobe_std_encoding_
parameter_list|,                  \
name|adobe_expert_encoding_
parameter_list|)
define|\
value|static const FT_Service_PsCMapsRec  class_ =                              \   {                                                                         \     unicode_value_, unicodes_init_,                                         \     unicodes_char_index_, unicodes_char_next_, macintosh_name_,             \     adobe_std_strings_, adobe_std_encoding_, adobe_expert_encoding_         \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_PSCMAPSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_PSCMAPSREC
parameter_list|(
name|class_
parameter_list|,                               \
name|unicode_value_
parameter_list|,                       \
name|unicodes_init_
parameter_list|,                       \
name|unicodes_char_index_
parameter_list|,                 \
name|unicodes_char_next_
parameter_list|,                  \
name|macintosh_name_
parameter_list|,                      \
name|adobe_std_strings_
parameter_list|,                   \
name|adobe_std_encoding_
parameter_list|,                  \
name|adobe_expert_encoding_
parameter_list|)
define|\
value|void                                                                      \   FT_Init_Class_ ## class_( FT_Library              library,                \                             FT_Service_PsCMapsRec*  clazz )                 \   {                                                                         \     FT_UNUSED( library );                                                   \                                                                             \     clazz->unicode_value         = unicode_value_;                          \     clazz->unicodes_init         = unicodes_init_;                          \     clazz->unicodes_char_index   = unicodes_char_index_;                    \     clazz->unicodes_char_next    = unicodes_char_next_;                     \     clazz->macintosh_name        = macintosh_name_;                         \     clazz->adobe_std_strings     = adobe_std_strings_;                      \     clazz->adobe_std_encoding    = adobe_std_encoding_;                     \     clazz->adobe_expert_encoding = adobe_expert_encoding_;                  \   }
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
comment|/* __SVPSCMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
