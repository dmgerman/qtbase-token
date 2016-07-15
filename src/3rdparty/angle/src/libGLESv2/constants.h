begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Contants.h: Defines some implementation specific and gl constants
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_CONSTANTS_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_CONSTANTS_H_
define|#
directive|define
name|LIBGLESV2_CONSTANTS_H_
end_define
begin_decl_stmt
name|namespace
name|gl
block|{
enum|enum
block|{
name|MAX_VERTEX_ATTRIBS
init|=
literal|16
block|,
comment|// Implementation upper limits, real maximums depend on the hardware
name|IMPLEMENTATION_MAX_VARYING_VECTORS
init|=
literal|32
block|,
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
init|=
literal|8
block|,
name|IMPLEMENTATION_MAX_FRAMEBUFFER_ATTACHMENTS
init|=
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
operator|+
literal|2
block|,
comment|// 2 extra for depth and/or stencil buffers
name|IMPLEMENTATION_MAX_VERTEX_SHADER_UNIFORM_BUFFERS
init|=
literal|16
block|,
name|IMPLEMENTATION_MAX_FRAGMENT_SHADER_UNIFORM_BUFFERS
init|=
literal|16
block|,
name|IMPLEMENTATION_MAX_COMBINED_SHADER_UNIFORM_BUFFERS
init|=
name|IMPLEMENTATION_MAX_VERTEX_SHADER_UNIFORM_BUFFERS
operator|+
name|IMPLEMENTATION_MAX_FRAGMENT_SHADER_UNIFORM_BUFFERS
block|,
name|IMPLEMENTATION_MAX_TRANSFORM_FEEDBACK_BUFFERS
init|=
literal|4
block|,
comment|// These are the maximums the implementation can support
comment|// The actual GL caps are limited by the device caps
comment|// and should be queried from the Context
name|IMPLEMENTATION_MAX_2D_TEXTURE_SIZE
init|=
literal|16384
block|,
name|IMPLEMENTATION_MAX_CUBE_MAP_TEXTURE_SIZE
init|=
literal|16384
block|,
name|IMPLEMENTATION_MAX_3D_TEXTURE_SIZE
init|=
literal|2048
block|,
name|IMPLEMENTATION_MAX_2D_ARRAY_TEXTURE_LAYERS
init|=
literal|2048
block|,
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
init|=
literal|15
comment|// 1+log2 of MAX_TEXTURE_SIZE
block|}
enum|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_CONSTANTS_H_
end_comment
end_unit
