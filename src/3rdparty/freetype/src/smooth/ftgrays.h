begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgrays.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType smooth renderer declaration                                 */
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
name|__FTGRAYS_H__
end_ifndef
begin_define
DECL|macro|__FTGRAYS_H__
define|#
directive|define
name|__FTGRAYS_H__
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_STANDALONE_
include|#
directive|include
file|"ftimage.h"
else|#
directive|else
include|#
directive|include
file|<ft2build.h>
include|#
directive|include
include|FT_CONFIG_CONFIG_H
comment|/* for FT_CONFIG_OPTION_PIC */
include|#
directive|include
include|FT_IMAGE_H
endif|#
directive|endif
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* To make ftgrays.h independent from configuration files we check       */
comment|/* whether FT_EXPORT_VAR has been defined already.                       */
comment|/*                                                                       */
comment|/* On some systems and compilers (Win32 mostly), an extra keyword is     */
comment|/* necessary to compile the library as a DLL.                            */
comment|/*                                                                       */
ifndef|#
directive|ifndef
name|FT_EXPORT_VAR
DECL|macro|FT_EXPORT_VAR
define|#
directive|define
name|FT_EXPORT_VAR
parameter_list|(
name|x
parameter_list|)
value|extern  x
endif|#
directive|endif
name|FT_EXPORT_VAR
argument_list|(
argument|const FT_Raster_Funcs
argument_list|)
name|ft_grays_raster
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTGRAYS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
