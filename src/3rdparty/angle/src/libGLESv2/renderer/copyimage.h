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
comment|// copyimage.h: Defines image copying functions
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_COPYIMAGE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_COPYIMAGE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_COPYIMAGE_H_
end_define
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|template
operator|<
name|typename
name|sourceType
operator|,
name|typename
name|colorDataType
operator|>
name|void
name|ReadColor
argument_list|(
argument|const void *source
argument_list|,
argument|void *dest
argument_list|)
block|{
name|sourceType
operator|::
name|readColor
argument_list|(
name|reinterpret_cast
operator|<
name|gl
operator|::
name|Color
operator|<
name|colorDataType
operator|>
operator|*
operator|>
operator|(
name|dest
operator|)
argument_list|,
name|reinterpret_cast
operator|<
specifier|const
name|sourceType
operator|*
operator|>
operator|(
name|source
operator|)
argument_list|)
block|; }
name|template
operator|<
name|typename
name|destType
operator|,
name|typename
name|colorDataType
operator|>
name|void
name|WriteColor
argument_list|(
argument|const void *source
argument_list|,
argument|void *dest
argument_list|)
block|{
name|destType
operator|::
name|writeColor
argument_list|(
name|reinterpret_cast
operator|<
name|destType
operator|*
operator|>
operator|(
name|dest
operator|)
argument_list|,
name|reinterpret_cast
operator|<
specifier|const
name|gl
operator|::
name|Color
operator|<
name|colorDataType
operator|>
operator|*
operator|>
operator|(
name|source
operator|)
argument_list|)
block|; }
name|template
operator|<
name|typename
name|sourceType
operator|,
name|typename
name|destType
operator|,
name|typename
name|colorDataType
operator|>
name|void
name|CopyPixel
argument_list|(
argument|const void *source
argument_list|,
argument|void *dest
argument_list|)
block|{
name|colorDataType
name|temp
block|;
name|ReadColor
operator|<
name|sourceType
block|,
name|colorDataType
operator|>
operator|(
name|source
operator|,
operator|&
name|temp
operator|)
block|;
name|WriteColor
operator|<
name|destType
block|,
name|colorDataType
operator|>
operator|(
operator|&
name|temp
operator|,
name|dest
operator|)
block|; }
name|void
name|CopyBGRAUByteToRGBAUByte
argument_list|(
specifier|const
name|void
operator|*
name|source
argument_list|,
name|void
operator|*
name|dest
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_COPYIMAGE_H_
end_comment
end_unit
