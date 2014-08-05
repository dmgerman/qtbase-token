begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// generatemip.h: Defines the GenerateMip function, templated on the format
end_comment
begin_comment
comment|// type of the image for which mip levels are being generated.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_GENERATEMIP_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_GENERATEMIP_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_GENERATEMIP_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/imageformats.h"
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
name|T
operator|>
specifier|inline
name|void
name|GenerateMip
argument_list|(
argument|size_t sourceWidth
argument_list|,
argument|size_t sourceHeight
argument_list|,
argument|size_t sourceDepth
argument_list|,
argument|const uint8_t *sourceData
argument_list|,
argument|size_t sourceRowPitch
argument_list|,
argument|size_t sourceDepthPitch
argument_list|,
argument|uint8_t *destData
argument_list|,
argument|size_t destRowPitch
argument_list|,
argument|size_t destDepthPitch
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_include
include|#
directive|include
file|"generatemip.inl"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_GENERATEMIP_H_
end_comment
end_unit
