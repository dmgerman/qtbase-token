begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svttglyf.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType TrueType glyph service.                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007 by David Turner.                                        */
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
name|__SVTTGLYF_H__
end_ifndef
begin_define
DECL|macro|__SVTTGLYF_H__
define|#
directive|define
name|__SVTTGLYF_H__
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
DECL|macro|FT_SERVICE_ID_TT_GLYF
define|#
directive|define
name|FT_SERVICE_ID_TT_GLYF
value|"tt-glyf"
end_define
begin_typedef
typedef|typedef
name|FT_ULong
function_decl|(
DECL|typedef|TT_Glyf_GetLocationFunc
modifier|*
name|TT_Glyf_GetLocationFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|gindex
parameter_list|,
name|FT_ULong
modifier|*
name|psize
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|TTGlyf
argument_list|)
end_macro
begin_block
block|{
name|TT_Glyf_GetLocationFunc
name|get_location
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
DECL|macro|FT_DEFINE_SERVICE_TTGLYFREC
define|#
directive|define
name|FT_DEFINE_SERVICE_TTGLYFREC
parameter_list|(
name|class_
parameter_list|,
name|get_location_
parameter_list|)
define|\
value|static const FT_Service_TTGlyfRec class_ =                  \   {                                                           \     get_location_                                             \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_TTGLYFREC
define|#
directive|define
name|FT_DEFINE_SERVICE_TTGLYFREC
parameter_list|(
name|class_
parameter_list|,
name|get_location_
parameter_list|)
define|\
value|void                                                        \   FT_Init_Class_##class_( FT_Service_TTGlyfRec*  clazz )      \   {                                                           \     clazz->get_location = get_location_;                      \   }
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
comment|/* __SVTTGLYF_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
