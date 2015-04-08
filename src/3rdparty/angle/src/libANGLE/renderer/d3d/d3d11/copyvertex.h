begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// copyvertex.h: Defines D3D11 vertex buffer copying and conversion functions
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_COPYVERTEX_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_COPYVERTEX_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_COPYVERTEX_H_
end_define
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
comment|// 'alphaDefaultValueBits' gives the default value for the alpha channel (4th component)
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|inputComponentCount
operator|,
name|size_t
name|outputComponentCount
operator|,
name|uint32_t
name|alphaDefaultValueBits
operator|>
specifier|inline
name|void
name|CopyNativeVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
name|template
operator|<
name|size_t
name|inputComponentCount
operator|,
name|size_t
name|outputComponentCount
operator|>
specifier|inline
name|void
name|Copy8SintTo16SintVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
name|template
operator|<
name|size_t
name|componentCount
operator|>
specifier|inline
name|void
name|Copy8SnormTo16SnormVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
name|template
operator|<
name|size_t
name|inputComponentCount
operator|,
name|size_t
name|outputComponentCount
operator|>
specifier|inline
name|void
name|Copy32FixedTo32FVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|inputComponentCount
operator|,
name|size_t
name|outputComponentCount
operator|,
name|bool
name|normalized
operator|>
specifier|inline
name|void
name|CopyTo32FVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
name|template
operator|<
name|bool
name|isSigned
operator|,
name|bool
name|normalized
operator|,
name|bool
name|toFloat
operator|>
specifier|inline
name|void
name|CopyXYZ10W2ToXYZW32FVertexData
argument_list|(
argument|const uint8_t *input
argument_list|,
argument|size_t stride
argument_list|,
argument|size_t count
argument_list|,
argument|uint8_t *output
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_include
include|#
directive|include
file|"copyvertex.inl"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_COPYVERTEX_H_
end_comment
end_unit
