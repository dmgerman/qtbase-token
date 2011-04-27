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
name|FT_EXPORT_VAR
argument_list|(
specifier|const
name|FT_Renderer_Class
argument_list|)
name|ft_std_renderer_class
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_SMOOTH_RASTER
end_ifndef
begin_macro
name|FT_EXPORT_VAR
argument_list|(
argument|const FT_Renderer_Class
argument_list|)
end_macro
begin_expr_stmt
name|ft_smooth_renderer_class
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_EXPORT_VAR
argument_list|(
argument|const FT_Renderer_Class
argument_list|)
end_macro
begin_expr_stmt
name|ft_smooth_lcd_renderer_class
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_EXPORT_VAR
argument_list|(
argument|const FT_Renderer_Class
argument_list|)
end_macro
begin_expr_stmt
name|ft_smooth_lcd_v_renderer_class
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_END_HEADER
end_macro
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
