begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftpic.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType position independent code services (declaration).       */
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
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  Modules that ordinarily have const global data that need address     */
end_comment
begin_comment
comment|/*  can instead define pointers here.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTPIC_H__
end_ifndef
begin_define
DECL|macro|__FTPIC_H__
define|#
directive|define
name|__FTPIC_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_typedef
DECL|struct|FT_PIC_Container_
typedef|typedef
struct|struct
name|FT_PIC_Container_
block|{
comment|/* pic containers for base */
DECL|member|base
name|void
modifier|*
name|base
decl_stmt|;
comment|/* pic containers for modules */
DECL|member|autofit
name|void
modifier|*
name|autofit
decl_stmt|;
DECL|member|cff
name|void
modifier|*
name|cff
decl_stmt|;
DECL|member|pshinter
name|void
modifier|*
name|pshinter
decl_stmt|;
DECL|member|psnames
name|void
modifier|*
name|psnames
decl_stmt|;
DECL|member|raster
name|void
modifier|*
name|raster
decl_stmt|;
DECL|member|sfnt
name|void
modifier|*
name|sfnt
decl_stmt|;
DECL|member|smooth
name|void
modifier|*
name|smooth
decl_stmt|;
DECL|member|truetype
name|void
modifier|*
name|truetype
decl_stmt|;
block|}
DECL|typedef|FT_PIC_Container
name|FT_PIC_Container
typedef|;
end_typedef
begin_comment
comment|/* Initialize the various function tables, structs, etc. stored in the container. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ft_pic_container_init
argument_list|(
argument|FT_Library library
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Destroy the contents of the container. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|ft_pic_container_destroy
name|ft_pic_container_destroy
argument_list|(
argument|FT_Library library
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|ft_pic_container_destroy
empty_stmt|;
end_empty_stmt
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
comment|/* __FTPIC_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
