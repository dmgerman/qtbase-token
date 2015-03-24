begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afloader.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter glyph loading routines (specification).                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003-2005, 2011-2013 by                                      */
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
name|__AFLOADER_H__
end_ifndef
begin_define
DECL|macro|__AFLOADER_H__
define|#
directive|define
name|__AFLOADER_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_include
include|#
directive|include
file|"afglobal.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|AF_Module
typedef|typedef
name|struct
name|AF_ModuleRec_
modifier|*
name|AF_Module
typedef|;
end_typedef
begin_comment
comment|/*    *  The autofitter module's (global) data structure to communicate with    *  actual fonts.  If necessary, `local' data like the current face, the    *  current face's auto-hint data, or the current glyph's parameters    *  relevant to auto-hinting are `swapped in'.  Cf. functions like    *  `af_loader_reset' and `af_loader_load_g'.    */
end_comment
begin_typedef
DECL|struct|AF_LoaderRec_
typedef|typedef
struct|struct
name|AF_LoaderRec_
block|{
comment|/* current face data */
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|globals
name|AF_FaceGlobals
name|globals
decl_stmt|;
comment|/* current glyph data */
DECL|member|gloader
name|FT_GlyphLoader
name|gloader
decl_stmt|;
DECL|member|hints
name|AF_GlyphHintsRec
name|hints
decl_stmt|;
DECL|member|metrics
name|AF_StyleMetrics
name|metrics
decl_stmt|;
DECL|member|transformed
name|FT_Bool
name|transformed
decl_stmt|;
DECL|member|trans_matrix
name|FT_Matrix
name|trans_matrix
decl_stmt|;
DECL|member|trans_delta
name|FT_Vector
name|trans_delta
decl_stmt|;
DECL|member|pp1
name|FT_Vector
name|pp1
decl_stmt|;
DECL|member|pp2
name|FT_Vector
name|pp2
decl_stmt|;
comment|/* we don't handle vertical phantom points */
block|}
DECL|typedef|AF_LoaderRec
DECL|typedef|AF_Loader
name|AF_LoaderRec
operator|,
typedef|*
name|AF_Loader
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_loader_init
argument_list|(
argument|AF_Module  module
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
DECL|variable|af_loader_reset
name|af_loader_reset
argument_list|(
argument|AF_Module  module
argument_list|,
argument|FT_Face    face
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
DECL|variable|module
name|af_loader_done
argument_list|(
argument|AF_Module  module
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|module
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_loader_load_glyph
argument_list|(
argument|AF_Module  module
argument_list|,
argument|FT_Face    face
argument_list|,
argument|FT_UInt    gindex
argument_list|,
argument|FT_Int32   load_flags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/* __AFLOADER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
