begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsmooth.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Anti-aliasing renderer interface (body).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2015 by                                                 */
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
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_OUTLINE_H
end_include
begin_include
include|#
directive|include
file|"ftsmooth.h"
end_include
begin_include
include|#
directive|include
file|"ftgrays.h"
end_include
begin_include
include|#
directive|include
file|"ftspic.h"
end_include
begin_include
include|#
directive|include
file|"ftsmerrs.h"
end_include
begin_comment
comment|/* initialize renderer -- init its raster */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_init
name|ft_smooth_init
parameter_list|(
name|FT_Renderer
name|render
parameter_list|)
block|{
name|FT_Library
name|library
init|=
name|FT_MODULE_LIBRARY
argument_list|(
name|render
argument_list|)
decl_stmt|;
name|render
operator|->
name|clazz
operator|->
name|raster_class
operator|->
name|raster_reset
argument_list|(
name|render
operator|->
name|raster
argument_list|,
name|library
operator|->
name|raster_pool
argument_list|,
name|library
operator|->
name|raster_pool_size
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/* sets render-specific mode */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_set_mode
name|ft_smooth_set_mode
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_ULong
name|mode_tag
parameter_list|,
name|FT_Pointer
name|data
parameter_list|)
block|{
comment|/* we simply pass it to the raster */
return|return
name|render
operator|->
name|clazz
operator|->
name|raster_class
operator|->
name|raster_set_mode
argument_list|(
name|render
operator|->
name|raster
argument_list|,
name|mode_tag
argument_list|,
name|data
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* transform a given glyph image */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_transform
name|ft_smooth_transform
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
specifier|const
name|FT_Matrix
modifier|*
name|matrix
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|delta
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
if|if
condition|(
name|slot
operator|->
name|format
operator|!=
name|render
operator|->
name|glyph_format
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|matrix
condition|)
name|FT_Outline_Transform
argument_list|(
operator|&
name|slot
operator|->
name|outline
argument_list|,
name|matrix
argument_list|)
expr_stmt|;
if|if
condition|(
name|delta
condition|)
name|FT_Outline_Translate
argument_list|(
operator|&
name|slot
operator|->
name|outline
argument_list|,
name|delta
operator|->
name|x
argument_list|,
name|delta
operator|->
name|y
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/* return the glyph's control box */
end_comment
begin_function
specifier|static
name|void
DECL|function|ft_smooth_get_cbox
name|ft_smooth_get_cbox
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_BBox
modifier|*
name|cbox
parameter_list|)
block|{
name|FT_MEM_ZERO
argument_list|(
name|cbox
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|cbox
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|slot
operator|->
name|format
operator|==
name|render
operator|->
name|glyph_format
condition|)
name|FT_Outline_Get_CBox
argument_list|(
operator|&
name|slot
operator|->
name|outline
argument_list|,
name|cbox
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* convert a slot's glyph image into a bitmap */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_render_generic
name|ft_smooth_render_generic
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Render_Mode
name|mode
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|origin
parameter_list|,
name|FT_Render_Mode
name|required_mode
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Outline
modifier|*
name|outline
init|=
operator|&
name|slot
operator|->
name|outline
decl_stmt|;
name|FT_Bitmap
modifier|*
name|bitmap
init|=
operator|&
name|slot
operator|->
name|bitmap
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|render
operator|->
name|root
operator|.
name|memory
decl_stmt|;
name|FT_BBox
name|cbox
decl_stmt|;
name|FT_Pos
name|x_shift
init|=
literal|0
decl_stmt|;
name|FT_Pos
name|y_shift
init|=
literal|0
decl_stmt|;
name|FT_Pos
name|x_left
decl_stmt|,
name|y_top
decl_stmt|;
name|FT_Pos
name|width
decl_stmt|,
name|height
decl_stmt|,
name|pitch
decl_stmt|;
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_SUBPIXEL_RENDERING
name|FT_Pos
name|height_org
decl_stmt|,
name|width_org
decl_stmt|;
endif|#
directive|endif
name|FT_Int
name|hmul
init|=
name|mode
operator|==
name|FT_RENDER_MODE_LCD
decl_stmt|;
name|FT_Int
name|vmul
init|=
name|mode
operator|==
name|FT_RENDER_MODE_LCD_V
decl_stmt|;
name|FT_Raster_Params
name|params
decl_stmt|;
name|FT_Bool
name|have_outline_shifted
init|=
name|FALSE
decl_stmt|;
name|FT_Bool
name|have_buffer
init|=
name|FALSE
decl_stmt|;
comment|/* check glyph image format */
if|if
condition|(
name|slot
operator|->
name|format
operator|!=
name|render
operator|->
name|glyph_format
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* check mode */
if|if
condition|(
name|mode
operator|!=
name|required_mode
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Cannot_Render_Glyph
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|origin
condition|)
block|{
name|x_shift
operator|=
name|origin
operator|->
name|x
expr_stmt|;
name|y_shift
operator|=
name|origin
operator|->
name|y
expr_stmt|;
block|}
comment|/* compute the control box, and grid fit it */
comment|/* taking into account the origin shift     */
name|FT_Outline_Get_CBox
argument_list|(
name|outline
argument_list|,
operator|&
name|cbox
argument_list|)
expr_stmt|;
name|cbox
operator|.
name|xMin
operator|=
name|FT_PIX_FLOOR
argument_list|(
name|cbox
operator|.
name|xMin
operator|+
name|x_shift
argument_list|)
expr_stmt|;
name|cbox
operator|.
name|yMin
operator|=
name|FT_PIX_FLOOR
argument_list|(
name|cbox
operator|.
name|yMin
operator|+
name|y_shift
argument_list|)
expr_stmt|;
name|cbox
operator|.
name|xMax
operator|=
name|FT_PIX_CEIL
argument_list|(
name|cbox
operator|.
name|xMax
operator|+
name|x_shift
argument_list|)
expr_stmt|;
name|cbox
operator|.
name|yMax
operator|=
name|FT_PIX_CEIL
argument_list|(
name|cbox
operator|.
name|yMax
operator|+
name|y_shift
argument_list|)
expr_stmt|;
name|x_shift
operator|-=
name|cbox
operator|.
name|xMin
expr_stmt|;
name|y_shift
operator|-=
name|cbox
operator|.
name|yMin
expr_stmt|;
name|x_left
operator|=
name|cbox
operator|.
name|xMin
operator|>>
literal|6
expr_stmt|;
name|y_top
operator|=
name|cbox
operator|.
name|yMax
operator|>>
literal|6
expr_stmt|;
name|width
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
name|cbox
operator|.
name|xMax
operator|-
name|cbox
operator|.
name|xMin
argument_list|)
operator|>>
literal|6
expr_stmt|;
name|height
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
name|cbox
operator|.
name|yMax
operator|-
name|cbox
operator|.
name|yMin
argument_list|)
operator|>>
literal|6
expr_stmt|;
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_SUBPIXEL_RENDERING
name|width_org
operator|=
name|width
expr_stmt|;
name|height_org
operator|=
name|height
expr_stmt|;
endif|#
directive|endif
name|pitch
operator|=
name|width
expr_stmt|;
if|if
condition|(
name|hmul
condition|)
block|{
name|width
operator|*=
literal|3
expr_stmt|;
name|pitch
operator|=
name|FT_PAD_CEIL
argument_list|(
name|width
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|vmul
condition|)
name|height
operator|*=
literal|3
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_SUBPIXEL_RENDERING
if|if
condition|(
name|slot
operator|->
name|library
operator|->
name|lcd_filter_func
condition|)
block|{
name|FT_Int
name|extra
init|=
name|slot
operator|->
name|library
operator|->
name|lcd_extra
decl_stmt|;
if|if
condition|(
name|hmul
condition|)
block|{
name|x_shift
operator|+=
literal|64
operator|*
operator|(
name|extra
operator|>>
literal|1
operator|)
expr_stmt|;
name|x_left
operator|-=
name|extra
operator|>>
literal|1
expr_stmt|;
name|width
operator|+=
literal|3
operator|*
name|extra
expr_stmt|;
name|pitch
operator|=
name|FT_PAD_CEIL
argument_list|(
name|width
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|vmul
condition|)
block|{
name|y_shift
operator|+=
literal|64
operator|*
operator|(
name|extra
operator|>>
literal|1
operator|)
expr_stmt|;
name|y_top
operator|+=
name|extra
operator|>>
literal|1
expr_stmt|;
name|height
operator|+=
literal|3
operator|*
name|extra
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/*      * XXX: on 16bit system, we return an error for huge bitmap      * to prevent an overflow.      */
if|if
condition|(
name|x_left
operator|>
name|FT_INT_MAX
operator|||
name|y_top
operator|>
name|FT_INT_MAX
operator|||
name|x_left
operator|<
name|FT_INT_MIN
operator|||
name|y_top
operator|<
name|FT_INT_MIN
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Pixel_Size
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* Required check is (pitch * height< FT_ULONG_MAX),        */
comment|/* but we care realistic cases only.  Always pitch<= width. */
if|if
condition|(
name|width
operator|>
literal|0x7FFF
operator|||
name|height
operator|>
literal|0x7FFF
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"ft_smooth_render_generic: glyph too large: %u x %u\n"
operator|,
name|width
operator|,
name|height
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Raster_Overflow
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* release old bitmap buffer */
if|if
condition|(
name|slot
operator|->
name|internal
operator|->
name|flags
operator|&
name|FT_GLYPH_OWN_BITMAP
condition|)
block|{
name|FT_FREE
argument_list|(
name|bitmap
operator|->
name|buffer
argument_list|)
expr_stmt|;
name|slot
operator|->
name|internal
operator|->
name|flags
operator|&=
operator|~
name|FT_GLYPH_OWN_BITMAP
expr_stmt|;
block|}
comment|/* allocate new one */
if|if
condition|(
name|FT_ALLOC
argument_list|(
name|bitmap
operator|->
name|buffer
argument_list|,
call|(
name|FT_ULong
call|)
argument_list|(
name|pitch
operator|*
name|height
argument_list|)
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
else|else
name|have_buffer
operator|=
name|TRUE
expr_stmt|;
name|slot
operator|->
name|internal
operator|->
name|flags
operator||=
name|FT_GLYPH_OWN_BITMAP
expr_stmt|;
name|slot
operator|->
name|format
operator|=
name|FT_GLYPH_FORMAT_BITMAP
expr_stmt|;
name|slot
operator|->
name|bitmap_left
operator|=
operator|(
name|FT_Int
operator|)
name|x_left
expr_stmt|;
name|slot
operator|->
name|bitmap_top
operator|=
operator|(
name|FT_Int
operator|)
name|y_top
expr_stmt|;
name|bitmap
operator|->
name|pixel_mode
operator|=
name|FT_PIXEL_MODE_GRAY
expr_stmt|;
name|bitmap
operator|->
name|num_grays
operator|=
literal|256
expr_stmt|;
name|bitmap
operator|->
name|width
operator|=
operator|(
name|unsigned
name|int
operator|)
name|width
expr_stmt|;
name|bitmap
operator|->
name|rows
operator|=
operator|(
name|unsigned
name|int
operator|)
name|height
expr_stmt|;
name|bitmap
operator|->
name|pitch
operator|=
name|pitch
expr_stmt|;
comment|/* translate outline to render it into the bitmap */
if|if
condition|(
name|x_shift
operator|||
name|y_shift
condition|)
block|{
name|FT_Outline_Translate
argument_list|(
name|outline
argument_list|,
name|x_shift
argument_list|,
name|y_shift
argument_list|)
expr_stmt|;
name|have_outline_shifted
operator|=
name|TRUE
expr_stmt|;
block|}
comment|/* set up parameters */
name|params
operator|.
name|target
operator|=
name|bitmap
expr_stmt|;
name|params
operator|.
name|source
operator|=
name|outline
expr_stmt|;
name|params
operator|.
name|flags
operator|=
name|FT_RASTER_FLAG_AA
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_SUBPIXEL_RENDERING
comment|/* implode outline if needed */
block|{
name|FT_Vector
modifier|*
name|points
init|=
name|outline
operator|->
name|points
decl_stmt|;
name|FT_Vector
modifier|*
name|points_end
init|=
name|points
operator|+
name|outline
operator|->
name|n_points
decl_stmt|;
name|FT_Vector
modifier|*
name|vec
decl_stmt|;
if|if
condition|(
name|hmul
condition|)
for|for
control|(
name|vec
operator|=
name|points
init|;
name|vec
operator|<
name|points_end
condition|;
name|vec
operator|++
control|)
name|vec
operator|->
name|x
operator|*=
literal|3
expr_stmt|;
if|if
condition|(
name|vmul
condition|)
for|for
control|(
name|vec
operator|=
name|points
init|;
name|vec
operator|<
name|points_end
condition|;
name|vec
operator|++
control|)
name|vec
operator|->
name|y
operator|*=
literal|3
expr_stmt|;
block|}
comment|/* render outline into the bitmap */
name|error
operator|=
name|render
operator|->
name|raster_render
argument_list|(
name|render
operator|->
name|raster
argument_list|,
operator|&
name|params
argument_list|)
expr_stmt|;
comment|/* deflate outline if needed */
block|{
name|FT_Vector
modifier|*
name|points
init|=
name|outline
operator|->
name|points
decl_stmt|;
name|FT_Vector
modifier|*
name|points_end
init|=
name|points
operator|+
name|outline
operator|->
name|n_points
decl_stmt|;
name|FT_Vector
modifier|*
name|vec
decl_stmt|;
if|if
condition|(
name|hmul
condition|)
for|for
control|(
name|vec
operator|=
name|points
init|;
name|vec
operator|<
name|points_end
condition|;
name|vec
operator|++
control|)
name|vec
operator|->
name|x
operator|/=
literal|3
expr_stmt|;
if|if
condition|(
name|vmul
condition|)
for|for
control|(
name|vec
operator|=
name|points
init|;
name|vec
operator|<
name|points_end
condition|;
name|vec
operator|++
control|)
name|vec
operator|->
name|y
operator|/=
literal|3
expr_stmt|;
block|}
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|slot
operator|->
name|library
operator|->
name|lcd_filter_func
condition|)
name|slot
operator|->
name|library
operator|->
name|lcd_filter_func
argument_list|(
name|bitmap
argument_list|,
name|mode
argument_list|,
name|slot
operator|->
name|library
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
comment|/* render outline into bitmap */
name|error
operator|=
name|render
operator|->
name|raster_render
argument_list|(
name|render
operator|->
name|raster
argument_list|,
operator|&
name|params
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
comment|/* expand it horizontally */
if|if
condition|(
name|hmul
condition|)
block|{
name|FT_Byte
modifier|*
name|line
init|=
name|bitmap
operator|->
name|buffer
decl_stmt|;
name|FT_UInt
name|hh
decl_stmt|;
for|for
control|(
name|hh
operator|=
name|height_org
init|;
name|hh
operator|>
literal|0
condition|;
name|hh
operator|--
operator|,
name|line
operator|+=
name|pitch
control|)
block|{
name|FT_UInt
name|xx
decl_stmt|;
name|FT_Byte
modifier|*
name|end
init|=
name|line
operator|+
name|width
decl_stmt|;
for|for
control|(
name|xx
operator|=
name|width_org
init|;
name|xx
operator|>
literal|0
condition|;
name|xx
operator|--
control|)
block|{
name|FT_UInt
name|pixel
init|=
name|line
index|[
name|xx
operator|-
literal|1
index|]
decl_stmt|;
name|end
index|[
operator|-
literal|3
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|pixel
expr_stmt|;
name|end
index|[
operator|-
literal|2
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|pixel
expr_stmt|;
name|end
index|[
operator|-
literal|1
index|]
operator|=
operator|(
name|FT_Byte
operator|)
name|pixel
expr_stmt|;
name|end
operator|-=
literal|3
expr_stmt|;
block|}
block|}
block|}
comment|/* expand it vertically */
if|if
condition|(
name|vmul
condition|)
block|{
name|FT_Byte
modifier|*
name|read
init|=
name|bitmap
operator|->
name|buffer
operator|+
operator|(
name|height
operator|-
name|height_org
operator|)
operator|*
name|pitch
decl_stmt|;
name|FT_Byte
modifier|*
name|write
init|=
name|bitmap
operator|->
name|buffer
decl_stmt|;
name|FT_UInt
name|hh
decl_stmt|;
for|for
control|(
name|hh
operator|=
name|height_org
init|;
name|hh
operator|>
literal|0
condition|;
name|hh
operator|--
control|)
block|{
name|ft_memcpy
argument_list|(
name|write
argument_list|,
name|read
argument_list|,
name|pitch
argument_list|)
expr_stmt|;
name|write
operator|+=
name|pitch
expr_stmt|;
name|ft_memcpy
argument_list|(
name|write
argument_list|,
name|read
argument_list|,
name|pitch
argument_list|)
expr_stmt|;
name|write
operator|+=
name|pitch
expr_stmt|;
name|ft_memcpy
argument_list|(
name|write
argument_list|,
name|read
argument_list|,
name|pitch
argument_list|)
expr_stmt|;
name|write
operator|+=
name|pitch
expr_stmt|;
name|read
operator|+=
name|pitch
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
comment|/* everything is fine; don't deallocate buffer */
name|have_buffer
operator|=
name|FALSE
expr_stmt|;
name|error
operator|=
name|FT_Err_Ok
expr_stmt|;
name|Exit
label|:
if|if
condition|(
name|have_outline_shifted
condition|)
name|FT_Outline_Translate
argument_list|(
name|outline
argument_list|,
operator|-
name|x_shift
argument_list|,
operator|-
name|y_shift
argument_list|)
expr_stmt|;
if|if
condition|(
name|have_buffer
condition|)
block|{
name|FT_FREE
argument_list|(
name|bitmap
operator|->
name|buffer
argument_list|)
expr_stmt|;
name|slot
operator|->
name|internal
operator|->
name|flags
operator|&=
operator|~
name|FT_GLYPH_OWN_BITMAP
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/* convert a slot's glyph image into a bitmap */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_render
name|ft_smooth_render
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Render_Mode
name|mode
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|origin
parameter_list|)
block|{
if|if
condition|(
name|mode
operator|==
name|FT_RENDER_MODE_LIGHT
condition|)
name|mode
operator|=
name|FT_RENDER_MODE_NORMAL
expr_stmt|;
return|return
name|ft_smooth_render_generic
argument_list|(
name|render
argument_list|,
name|slot
argument_list|,
name|mode
argument_list|,
name|origin
argument_list|,
name|FT_RENDER_MODE_NORMAL
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* convert a slot's glyph image into a horizontal LCD bitmap */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_render_lcd
name|ft_smooth_render_lcd
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Render_Mode
name|mode
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|origin
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|error
operator|=
name|ft_smooth_render_generic
argument_list|(
name|render
argument_list|,
name|slot
argument_list|,
name|mode
argument_list|,
name|origin
argument_list|,
name|FT_RENDER_MODE_LCD
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|slot
operator|->
name|bitmap
operator|.
name|pixel_mode
operator|=
name|FT_PIXEL_MODE_LCD
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/* convert a slot's glyph image into a vertical LCD bitmap */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_smooth_render_lcd_v
name|ft_smooth_render_lcd_v
parameter_list|(
name|FT_Renderer
name|render
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Render_Mode
name|mode
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|origin
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|error
operator|=
name|ft_smooth_render_generic
argument_list|(
name|render
argument_list|,
name|slot
argument_list|,
name|mode
argument_list|,
name|origin
argument_list|,
name|FT_RENDER_MODE_LCD_V
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|slot
operator|->
name|bitmap
operator|.
name|pixel_mode
operator|=
name|FT_PIXEL_MODE_LCD_V
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_RENDERER
argument_list|(
argument|ft_smooth_renderer_class
argument_list|,
argument|FT_MODULE_RENDERER
argument_list|,
argument|sizeof ( FT_RendererRec )
argument_list|,
literal|"smooth"
argument_list|,
literal|0x10000L
argument_list|,
literal|0x20000L
argument_list|,
literal|0
argument_list|,
comment|/* module specific interface */
argument|(FT_Module_Constructor)ft_smooth_init
argument_list|,
argument|(FT_Module_Destructor)
literal|0
argument_list|,
argument|(FT_Module_Requester)
literal|0
argument_list|,
argument|FT_GLYPH_FORMAT_OUTLINE
argument_list|,
argument|(FT_Renderer_RenderFunc)   ft_smooth_render
argument_list|,
argument|(FT_Renderer_TransformFunc)ft_smooth_transform
argument_list|,
argument|(FT_Renderer_GetCBoxFunc)  ft_smooth_get_cbox
argument_list|,
argument|(FT_Renderer_SetModeFunc)  ft_smooth_set_mode
argument_list|,
argument|(FT_Raster_Funcs*)&FT_GRAYS_RASTER_GET
argument_list|)
end_macro
begin_macro
name|FT_DEFINE_RENDERER
argument_list|(
argument|ft_smooth_lcd_renderer_class
argument_list|,
argument|FT_MODULE_RENDERER
argument_list|,
argument|sizeof ( FT_RendererRec )
argument_list|,
literal|"smooth-lcd"
argument_list|,
literal|0x10000L
argument_list|,
literal|0x20000L
argument_list|,
literal|0
argument_list|,
comment|/* module specific interface */
argument|(FT_Module_Constructor)ft_smooth_init
argument_list|,
argument|(FT_Module_Destructor)
literal|0
argument_list|,
argument|(FT_Module_Requester)
literal|0
argument_list|,
argument|FT_GLYPH_FORMAT_OUTLINE
argument_list|,
argument|(FT_Renderer_RenderFunc)   ft_smooth_render_lcd
argument_list|,
argument|(FT_Renderer_TransformFunc)ft_smooth_transform
argument_list|,
argument|(FT_Renderer_GetCBoxFunc)  ft_smooth_get_cbox
argument_list|,
argument|(FT_Renderer_SetModeFunc)  ft_smooth_set_mode
argument_list|,
argument|(FT_Raster_Funcs*)&FT_GRAYS_RASTER_GET
argument_list|)
end_macro
begin_macro
name|FT_DEFINE_RENDERER
argument_list|(
argument|ft_smooth_lcdv_renderer_class
argument_list|,
argument|FT_MODULE_RENDERER
argument_list|,
argument|sizeof ( FT_RendererRec )
argument_list|,
literal|"smooth-lcdv"
argument_list|,
literal|0x10000L
argument_list|,
literal|0x20000L
argument_list|,
literal|0
argument_list|,
comment|/* module specific interface */
argument|(FT_Module_Constructor)ft_smooth_init
argument_list|,
argument|(FT_Module_Destructor)
literal|0
argument_list|,
argument|(FT_Module_Requester)
literal|0
argument_list|,
argument|FT_GLYPH_FORMAT_OUTLINE
argument_list|,
argument|(FT_Renderer_RenderFunc)   ft_smooth_render_lcd_v
argument_list|,
argument|(FT_Renderer_TransformFunc)ft_smooth_transform
argument_list|,
argument|(FT_Renderer_GetCBoxFunc)  ft_smooth_get_cbox
argument_list|,
argument|(FT_Renderer_SetModeFunc)  ft_smooth_set_mode
argument_list|,
argument|(FT_Raster_Funcs*)&FT_GRAYS_RASTER_GET
argument_list|)
end_macro
begin_comment
comment|/* END */
end_comment
end_unit
