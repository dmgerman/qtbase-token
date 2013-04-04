begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svttcmap.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType TrueType/sfnt cmap extra information service.           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003 by                                                      */
end_comment
begin_comment
comment|/*  Masatake YAMATO, Redhat K.K.                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2008 by                                                */
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
begin_comment
comment|/* Development of this service is support of    Information-technology Promotion Agency, Japan. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SVTTCMAP_H__
end_ifndef
begin_define
DECL|macro|__SVTTCMAP_H__
define|#
directive|define
name|__SVTTCMAP_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_TT_CMAP
define|#
directive|define
name|FT_SERVICE_ID_TT_CMAP
value|"tt-cmaps"
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    TT_CMapInfo                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to store TrueType/sfnt specific cmap information  */
end_comment
begin_comment
comment|/*    which is not covered by the generic @FT_CharMap structure.  This   */
end_comment
begin_comment
comment|/*    structure can be accessed with the @FT_Get_TT_CMap_Info function.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    language ::                                                        */
end_comment
begin_comment
comment|/*      The language ID used in Mac fonts.  Definitions of values are in */
end_comment
begin_comment
comment|/*      freetype/ttnameid.h.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format ::                                                          */
end_comment
begin_comment
comment|/*      The cmap format.  OpenType 1.5 defines the formats 0 (byte       */
end_comment
begin_comment
comment|/*      encoding table), 2~(high-byte mapping through table), 4~(segment */
end_comment
begin_comment
comment|/*      mapping to delta values), 6~(trimmed table mapping), 8~(mixed    */
end_comment
begin_comment
comment|/*      16-bit and 32-bit coverage), 10~(trimmed array), 12~(segmented   */
end_comment
begin_comment
comment|/*      coverage), and 14 (Unicode Variation Sequences).                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_CMapInfo_
typedef|typedef
struct|struct
name|TT_CMapInfo_
block|{
DECL|member|language
name|FT_ULong
name|language
decl_stmt|;
DECL|member|format
name|FT_Long
name|format
decl_stmt|;
block|}
DECL|typedef|TT_CMapInfo
name|TT_CMapInfo
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_CMap_Info_GetFunc
modifier|*
name|TT_CMap_Info_GetFunc
function_decl|)
parameter_list|(
name|FT_CharMap
name|charmap
parameter_list|,
name|TT_CMapInfo
modifier|*
name|cmap_info
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|TTCMaps
argument_list|)
end_macro
begin_block
block|{
name|TT_CMap_Info_GetFunc
name|get_cmap_info
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
DECL|macro|FT_DEFINE_SERVICE_TTCMAPSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_TTCMAPSREC
parameter_list|(
name|class_
parameter_list|,
name|get_cmap_info_
parameter_list|)
define|\
value|static const FT_Service_TTCMapsRec class_ =                 \   {                                                           \     get_cmap_info_                                            \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_TTCMAPSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_TTCMAPSREC
parameter_list|(
name|class_
parameter_list|,
name|get_cmap_info_
parameter_list|)
define|\
value|void                                                       \   FT_Init_Class_##class_( FT_Library library,                \                           FT_Service_TTCMapsRec*  clazz)     \   {                                                          \     FT_UNUSED(library);                                      \     clazz->get_cmap_info = get_cmap_info_;                   \   }
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
comment|/* __SVTTCMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
