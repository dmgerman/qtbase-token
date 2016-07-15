begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftraster.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType glyph rasterizer (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used        */
end_comment
begin_comment
comment|/*  modified and distributed under the terms of the FreeType project       */
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
name|__FTRASTER_H__
end_ifndef
begin_define
DECL|macro|__FTRASTER_H__
define|#
directive|define
name|__FTRASTER_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_IMAGE_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Uncomment the following line if you are using ftraster.c as a         */
comment|/* standalone module, fully independent of FreeType.                     */
comment|/*                                                                       */
comment|/* #define _STANDALONE_ */
name|FT_EXPORT_VAR
argument_list|(
specifier|const
name|FT_Raster_Funcs
argument_list|)
name|ft_standard_raster
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTRASTER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
