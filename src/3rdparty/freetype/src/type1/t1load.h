begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1load.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 font loader (specification).                                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004, 2006, 2007 by                         */
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
name|__T1LOAD_H__
end_ifndef
begin_define
DECL|macro|__T1LOAD_H__
define|#
directive|define
name|__T1LOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_AUX_H
end_include
begin_include
include|#
directive|include
include|FT_MULTIPLE_MASTERS_H
end_include
begin_include
include|#
directive|include
file|"t1parse.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|T1_Loader_
typedef|typedef
struct|struct
name|T1_Loader_
block|{
DECL|member|parser
name|T1_ParserRec
name|parser
decl_stmt|;
comment|/* parser used to read the stream */
DECL|member|num_chars
name|FT_Int
name|num_chars
decl_stmt|;
comment|/* number of characters in encoding */
DECL|member|encoding_table
name|PS_TableRec
name|encoding_table
decl_stmt|;
comment|/* PS_Table used to store the       */
comment|/* encoding character names         */
DECL|member|num_glyphs
name|FT_Int
name|num_glyphs
decl_stmt|;
DECL|member|glyph_names
name|PS_TableRec
name|glyph_names
decl_stmt|;
DECL|member|charstrings
name|PS_TableRec
name|charstrings
decl_stmt|;
DECL|member|swap_table
name|PS_TableRec
name|swap_table
decl_stmt|;
comment|/* For moving .notdef glyph to index 0. */
DECL|member|num_subrs
name|FT_Int
name|num_subrs
decl_stmt|;
DECL|member|subrs
name|PS_TableRec
name|subrs
decl_stmt|;
DECL|member|fontdata
name|FT_Bool
name|fontdata
decl_stmt|;
DECL|member|keywords_encountered
name|FT_UInt
name|keywords_encountered
decl_stmt|;
comment|/* T1_LOADER_ENCOUNTERED_XXX */
block|}
DECL|typedef|T1_LoaderRec
DECL|typedef|T1_Loader
name|T1_LoaderRec
operator|,
typedef|*
name|T1_Loader
typedef|;
end_typedef
begin_comment
comment|/* treatment of some keywords differs depending on whether */
end_comment
begin_comment
comment|/* they precede or follow certain other keywords           */
end_comment
begin_define
DECL|macro|T1_PRIVATE
define|#
directive|define
name|T1_PRIVATE
value|( 1<< 0 )
end_define
begin_define
DECL|macro|T1_FONTDIR_AFTER_PRIVATE
define|#
directive|define
name|T1_FONTDIR_AFTER_PRIVATE
value|( 1<< 1 )
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Open_Face
argument_list|(
argument|T1_Face  face
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|T1_CONFIG_OPTION_NO_MM_SUPPORT
end_ifndef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|T1_Get_Multi_Master
name|T1_Get_Multi_Master
argument_list|(
argument|T1_Face           face
argument_list|,
argument|FT_Multi_Master*  master
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Get_MM_Var
argument_list|(
argument|T1_Face      face
argument_list|,
argument|FT_MM_Var*  *master
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|T1_Set_MM_Blend
name|T1_Set_MM_Blend
argument_list|(
argument|T1_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Set_MM_Design
argument_list|(
argument|T1_Face   face
argument_list|,
argument|FT_UInt   num_coords
argument_list|,
argument|FT_Long*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|T1_Set_Var_Design
name|T1_Set_Var_Design
argument_list|(
argument|T1_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|face
name|T1_Done_Blend
argument_list|(
argument|T1_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !T1_CONFIG_OPTION_NO_MM_SUPPORT */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __T1LOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
