begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pngshim.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    PNG Bitmap glyph support.                                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013 by Google, Inc.                                         */
end_comment
begin_comment
comment|/*  Written by Stuart Gill and Behdad Esfahbod.                            */
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
name|__PNGSHIM_H__
end_ifndef
begin_define
DECL|macro|__PNGSHIM_H__
define|#
directive|define
name|__PNGSHIM_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttload.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_PNG
name|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|Load_SBit_Png
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Int
name|x_offset
parameter_list|,
name|FT_Int
name|y_offset
parameter_list|,
name|FT_Int
name|pix_bits
parameter_list|,
name|TT_SBit_Metrics
name|metrics
parameter_list|,
name|FT_Memory
name|memory
parameter_list|,
name|FT_Byte
modifier|*
name|data
parameter_list|,
name|FT_UInt
name|png_len
parameter_list|,
name|FT_Bool
name|populate_map_and_metrics
parameter_list|)
function_decl|;
end_function_decl
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
comment|/* __PNGSHIM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
