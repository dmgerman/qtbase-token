begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexBuffer11.h: Defines the D3D11 VertexBuffer implementation.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_VERTEXBUFFER11_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_VERTEXBUFFER11_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_VERTEXBUFFER11_H_
end_define
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/VertexBuffer.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|VertexBuffer11
range|:
name|public
name|VertexBuffer
block|{
name|public
operator|:
name|explicit
name|VertexBuffer11
argument_list|(
name|Renderer11
operator|*
specifier|const
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|VertexBuffer11
argument_list|()
block|;
name|virtual
name|gl
operator|::
name|Error
name|initialize
argument_list|(
argument|unsigned int size
argument_list|,
argument|bool dynamicUsage
argument_list|)
block|;
specifier|static
name|VertexBuffer11
operator|*
name|makeVertexBuffer11
argument_list|(
name|VertexBuffer
operator|*
name|vetexBuffer
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|storeVertexAttributes
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|const gl::VertexAttribCurrentValueData&currentValue
argument_list|,
argument|GLint start
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int offset
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|getSpaceRequired
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int *outSpaceRequired
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getBufferSize
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|setBufferSize
argument_list|(
argument|unsigned int size
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|discard
argument_list|()
block|;
name|virtual
name|void
name|hintUnmapResource
argument_list|()
block|;
name|ID3D11Buffer
operator|*
name|getBuffer
argument_list|()
specifier|const
block|;
name|private
operator|:
name|gl
operator|::
name|Error
name|mapResource
argument_list|()
block|;
name|Renderer11
operator|*
specifier|const
name|mRenderer
block|;
name|ID3D11Buffer
operator|*
name|mBuffer
block|;
name|unsigned
name|int
name|mBufferSize
block|;
name|bool
name|mDynamicUsage
block|;
name|uint8_t
operator|*
name|mMappedResourceData
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_VERTEXBUFFER11_H_
end_comment
end_unit
