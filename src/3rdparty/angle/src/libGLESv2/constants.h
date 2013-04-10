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
name|MAX_TEXTURE_IMAGE_UNITS
init|=
literal|16
block|,
comment|// Implementation upper limits, real maximums depend on the hardware
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
init|=
literal|16
block|,
name|IMPLEMENTATION_MAX_COMBINED_TEXTURE_IMAGE_UNITS
init|=
name|MAX_TEXTURE_IMAGE_UNITS
operator|+
name|IMPLEMENTATION_MAX_VERTEX_TEXTURE_IMAGE_UNITS
block|,
name|IMPLEMENTATION_MAX_VARYING_VECTORS
init|=
literal|32
block|,
name|IMPLEMENTATION_MAX_DRAW_BUFFERS
init|=
literal|8
block|}
enum|;
specifier|const
name|float
name|ALIASED_LINE_WIDTH_RANGE_MIN
init|=
literal|1.0f
decl_stmt|;
specifier|const
name|float
name|ALIASED_LINE_WIDTH_RANGE_MAX
init|=
literal|1.0f
decl_stmt|;
specifier|const
name|float
name|ALIASED_POINT_SIZE_RANGE_MIN
init|=
literal|1.0f
decl_stmt|;
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
