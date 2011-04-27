begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1cmap.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 character map support (specification).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2006 by                                          */
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
name|__T1CMAP_H__
end_ifndef
begin_define
DECL|macro|__T1CMAP_H__
define|#
directive|define
name|__T1CMAP_H__
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
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****          TYPE1 STANDARD (AND EXPERT) ENCODING CMAPS           *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* standard (and expert) encoding cmaps */
end_comment
begin_typedef
DECL|typedef|T1_CMapStd
typedef|typedef
name|struct
name|T1_CMapStdRec_
modifier|*
name|T1_CMapStd
typedef|;
end_typedef
begin_typedef
DECL|struct|T1_CMapStdRec_
typedef|typedef
struct|struct
name|T1_CMapStdRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|code_to_sid
specifier|const
name|FT_UShort
modifier|*
name|code_to_sid
decl_stmt|;
DECL|member|sid_to_string
name|PS_Adobe_Std_StringsFunc
name|sid_to_string
decl_stmt|;
DECL|member|num_glyphs
name|FT_UInt
name|num_glyphs
decl_stmt|;
DECL|member|glyph_names
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|glyph_names
decl_stmt|;
block|}
DECL|typedef|T1_CMapStdRec
name|T1_CMapStdRec
typedef|;
end_typedef
begin_decl_stmt
name|FT_CALLBACK_TABLE
specifier|const
name|FT_CMap_ClassRec
DECL|variable|t1_cmap_standard_class_rec
name|t1_cmap_standard_class_rec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|FT_CALLBACK_TABLE
specifier|const
name|FT_CMap_ClassRec
DECL|variable|t1_cmap_expert_class_rec
name|t1_cmap_expert_class_rec
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                  TYPE1 CUSTOM ENCODING CMAP                   *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_typedef
DECL|typedef|T1_CMapCustom
typedef|typedef
name|struct
name|T1_CMapCustomRec_
modifier|*
name|T1_CMapCustom
typedef|;
end_typedef
begin_typedef
DECL|struct|T1_CMapCustomRec_
typedef|typedef
struct|struct
name|T1_CMapCustomRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|first
name|FT_UInt
name|first
decl_stmt|;
DECL|member|count
name|FT_UInt
name|count
decl_stmt|;
DECL|member|indices
name|FT_UShort
modifier|*
name|indices
decl_stmt|;
block|}
DECL|typedef|T1_CMapCustomRec
name|T1_CMapCustomRec
typedef|;
end_typedef
begin_decl_stmt
name|FT_CALLBACK_TABLE
specifier|const
name|FT_CMap_ClassRec
DECL|variable|t1_cmap_custom_class_rec
name|t1_cmap_custom_class_rec
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****             TYPE1 SYNTHETIC UNICODE ENCODING CMAP             *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* unicode (synthetic) cmaps */
end_comment
begin_decl_stmt
name|FT_CALLBACK_TABLE
specifier|const
name|FT_CMap_ClassRec
DECL|variable|t1_cmap_unicode_class_rec
name|t1_cmap_unicode_class_rec
decl_stmt|;
end_decl_stmt
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
comment|/* __T1CMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
