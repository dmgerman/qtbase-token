begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftrend1.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType glyph rasterizer interface (specification).             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001 by                                                 */
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
name|__FTREND1_H__
end_ifndef
begin_define
DECL|macro|__FTREND1_H__
define|#
directive|define
name|__FTREND1_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_RENDER_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_raster1_renderer_class
argument_list|)
comment|/* this renderer is _NOT_ part of the default modules, you'll need */
comment|/* to register it by hand in your application.  It should only be  */
comment|/* used for backwards-compatibility with FT 1.x anyway.            */
comment|/*                                                                 */
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_raster5_renderer_class
argument_list|)
name|FT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTREND1_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
