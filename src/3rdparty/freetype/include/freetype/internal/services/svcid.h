begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svcid.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType CID font services (specification).                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007-2015 by                                                 */
end_comment
begin_comment
comment|/*  Derek Clegg and Michael Toftdal.                                       */
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
name|__SVCID_H__
end_ifndef
begin_define
DECL|macro|__SVCID_H__
define|#
directive|define
name|__SVCID_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|FT_SERVICE_ID_CID
define|#
directive|define
name|FT_SERVICE_ID_CID
value|"CID"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_CID_GetRegistryOrderingSupplementFunc
modifier|*
name|FT_CID_GetRegistryOrderingSupplementFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|registry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|ordering
parameter_list|,
name|FT_Int
modifier|*
name|supplement
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_CID_GetIsInternallyCIDKeyedFunc
modifier|*
name|FT_CID_GetIsInternallyCIDKeyedFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Bool
modifier|*
name|is_cid
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_CID_GetCIDFromGlyphIndexFunc
modifier|*
name|FT_CID_GetCIDFromGlyphIndexFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_UInt
modifier|*
name|cid
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|CID
argument_list|)
end_macro
begin_block
block|{
name|FT_CID_GetRegistryOrderingSupplementFunc
name|get_ros
decl_stmt|;
name|FT_CID_GetIsInternallyCIDKeyedFunc
name|get_is_cid
decl_stmt|;
name|FT_CID_GetCIDFromGlyphIndexFunc
name|get_cid_from_glyph_index
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
DECL|macro|FT_DEFINE_SERVICE_CIDREC
define|#
directive|define
name|FT_DEFINE_SERVICE_CIDREC
parameter_list|(
name|class_
parameter_list|,                                   \
name|get_ros_
parameter_list|,                                 \
name|get_is_cid_
parameter_list|,                              \
name|get_cid_from_glyph_index_
parameter_list|)
define|\
value|static const FT_Service_CIDRec class_ =                                   \   {                                                                         \     get_ros_, get_is_cid_, get_cid_from_glyph_index_                        \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_CIDREC
define|#
directive|define
name|FT_DEFINE_SERVICE_CIDREC
parameter_list|(
name|class_
parameter_list|,                                   \
name|get_ros_
parameter_list|,                                 \
name|get_is_cid_
parameter_list|,                              \
name|get_cid_from_glyph_index_
parameter_list|)
define|\
value|void                                                                      \   FT_Init_Class_ ## class_( FT_Library          library,                    \                             FT_Service_CIDRec*  clazz )                     \   {                                                                         \     FT_UNUSED( library );                                                   \                                                                             \     clazz->get_ros                  = get_ros_;                             \     clazz->get_is_cid               = get_is_cid_;                          \     clazz->get_cid_from_glyph_index = get_cid_from_glyph_index_;            \   }
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
comment|/* __SVCID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
