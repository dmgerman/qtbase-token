begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsmooth.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Anti-aliasing renderer interface (specification).                    */
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
name|__FTSMOOTH_H__
end_ifndef
begin_define
DECL|macro|__FTSMOOTH_H__
define|#
directive|define
name|__FTSMOOTH_H__
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
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_STD_RASTER
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_std_renderer_class
argument_list|)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_SMOOTH_RASTER
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_smooth_renderer_class
argument_list|)
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_smooth_lcd_renderer_class
argument_list|)
name|FT_DECLARE_RENDERER
argument_list|(
name|ft_smooth_lcd_v_renderer_class
argument_list|)
endif|#
directive|endif
name|FT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTSMOOTH_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
