begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvfeat.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT feat table validation (specification).                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005 by suzuki toshiya, Masatake YAMATO, Red Hat K.K., */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
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
name|__GXVFEAT_H__
end_ifndef
begin_define
DECL|macro|__GXVFEAT_H__
define|#
directive|define
name|__GXVFEAT_H__
end_define
begin_include
include|#
directive|include
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
file|"gxvcommn.h"
end_include
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
comment|/*****                Registry predefined by Apple                   *****/
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
comment|/* TODO: More compact format */
end_comment
begin_typedef
DECL|struct|GXV_Feature_RegistryRec_
typedef|typedef
struct|struct
name|GXV_Feature_RegistryRec_
block|{
DECL|member|existence
name|FT_Bool
name|existence
decl_stmt|;
DECL|member|apple_reserved
name|FT_Bool
name|apple_reserved
decl_stmt|;
DECL|member|exclusive
name|FT_Bool
name|exclusive
decl_stmt|;
DECL|member|nSettings
name|FT_Byte
name|nSettings
decl_stmt|;
block|}
DECL|typedef|GX_Feature_RegistryRec
name|GX_Feature_RegistryRec
typedef|;
end_typedef
begin_define
DECL|macro|gxv_feat_registry_length
define|#
directive|define
name|gxv_feat_registry_length
define|\
value|( sizeof ( gxv_feat_registry ) /        \               sizeof ( GX_Feature_RegistryRec ) )
end_define
begin_decl_stmt
DECL|variable|gxv_feat_registry
specifier|static
name|GX_Feature_RegistryRec
name|gxv_feat_registry
index|[]
init|=
block|{
comment|/* Generated from gxvfgen.c */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
comment|/* All Typographic Features */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|8
block|}
block|,
comment|/* Ligatures */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|3
block|}
block|,
comment|/* Cursive Connection */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|6
block|}
block|,
comment|/* Letter Case */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
comment|/* Vertical Substitution */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
comment|/* Linguistic Rearrangement */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Number Spacing */
block|{
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* Apple Reserved 1 */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|5
block|}
block|,
comment|/* Smart Swashes */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|3
block|}
block|,
comment|/* Diacritics */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|4
block|}
block|,
comment|/* Vertical Position */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|3
block|}
block|,
comment|/* Fractions */
block|{
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* Apple Reserved 2 */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
comment|/* Overlapping Characters */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|}
block|,
comment|/* Typographic Extras */
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|5
block|}
block|,
comment|/* Mathematical Extras */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|7
block|}
block|,
comment|/* Ornament Sets */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|}
block|,
comment|/* Character Alternatives */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|5
block|}
block|,
comment|/* Design Complexity */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|6
block|}
block|,
comment|/* Style Options */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|11
block|}
block|,
comment|/* Character Shape */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Number Case */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|4
block|}
block|,
comment|/* Text Spacing */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|10
block|}
block|,
comment|/* Transliteration */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|9
block|}
block|,
comment|/* Annotation */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Kana Spacing */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Ideographic Spacing */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* __EMPTY__ */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|4
block|}
block|,
comment|/* Text Spacing */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Kana Spacing */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|}
block|,
comment|/* Ideographic Spacing */
block|{
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|4
block|}
block|,
comment|/* CJK Roman Spacing */
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GXVFEAT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
