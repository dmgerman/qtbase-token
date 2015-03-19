begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  hbshim.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    HarfBuzz interface for accessing OpenType features (specification).  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013 by                                                      */
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
name|__HBSHIM_H__
end_ifndef
begin_define
DECL|macro|__HBSHIM_H__
define|#
directive|define
name|__HBSHIM_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_HARFBUZZ
end_ifdef
begin_include
include|#
directive|include
file|<hb.h>
end_include
begin_include
include|#
directive|include
file|<hb-ot.h>
end_include
begin_include
include|#
directive|include
file|<hb-ft.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_Error
name|af_get_coverage
parameter_list|(
name|AF_FaceGlobals
name|globals
parameter_list|,
name|AF_StyleClass
name|style_class
parameter_list|,
name|FT_Byte
modifier|*
name|gstyles
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|FT_Error
name|af_get_char_index
parameter_list|(
name|AF_StyleMetrics
name|metrics
parameter_list|,
name|FT_ULong
name|charcode
parameter_list|,
name|FT_ULong
modifier|*
name|codepoint
parameter_list|,
name|FT_Long
modifier|*
name|y_offset
parameter_list|)
function_decl|;
end_function_decl
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
comment|/* __HBSHIM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
