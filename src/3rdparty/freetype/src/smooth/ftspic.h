begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftspic.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services for smooth module.   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2009 by                                                      */
end_comment
begin_comment
comment|/*  Oran Agra and Mickey Gabel.                                            */
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
name|__FTSPIC_H__
end_ifndef
begin_define
DECL|macro|__FTSPIC_H__
define|#
directive|define
name|__FTSPIC_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_include
include|#
directive|include
include|FT_INTERNAL_PIC_H
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_GRAYS_RASTER_GET
define|#
directive|define
name|FT_GRAYS_RASTER_GET
value|ft_grays_raster
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_typedef
typedef|typedef
struct|struct
name|SmoothPIC_
block|{
name|int
name|ref_count
decl_stmt|;
name|FT_Raster_Funcs
name|ft_grays_raster
decl_stmt|;
block|}
name|SmoothPIC
typedef|;
end_typedef
begin_define
define|#
directive|define
name|GET_PIC
parameter_list|(
name|lib
parameter_list|)
value|((SmoothPIC*)((lib)->pic_container.smooth))
end_define
begin_define
define|#
directive|define
name|FT_GRAYS_RASTER_GET
value|(GET_PIC(library)->ft_grays_raster)
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
comment|/* __FTSPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
