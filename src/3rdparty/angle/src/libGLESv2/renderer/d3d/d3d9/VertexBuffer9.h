begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexBuffer9.h: Defines the D3D9 VertexBuffer implementation.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/VertexBuffer.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|VertexBuffer9
range|:
name|public
name|VertexBuffer
block|{
name|public
operator|:
name|explicit
name|VertexBuffer9
argument_list|(
name|rx
operator|::
name|Renderer9
operator|*
specifier|const
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|VertexBuffer9
argument_list|()
block|;
name|virtual
name|bool
name|initialize
argument_list|(
argument|unsigned int size
argument_list|,
argument|bool dynamicUsage
argument_list|)
block|;
specifier|static
name|VertexBuffer9
operator|*
name|makeVertexBuffer9
argument_list|(
name|VertexBuffer
operator|*
name|vertexBuffer
argument_list|)
block|;
name|virtual
name|bool
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
name|bool
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
name|bool
name|setBufferSize
argument_list|(
argument|unsigned int size
argument_list|)
block|;
name|virtual
name|bool
name|discard
argument_list|()
block|;
name|IDirect3DVertexBuffer9
operator|*
name|getBuffer
argument_list|()
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexBuffer9
argument_list|)
block|;
name|rx
operator|::
name|Renderer9
operator|*
specifier|const
name|mRenderer
block|;
name|IDirect3DVertexBuffer9
operator|*
name|mVertexBuffer
block|;
name|unsigned
name|int
name|mBufferSize
block|;
name|bool
name|mDynamicUsage
block|;
specifier|static
name|bool
name|spaceRequired
argument_list|(
argument|const gl::VertexAttribute&attrib
argument_list|,
argument|std::size_t count
argument_list|,
argument|GLsizei instances
argument_list|,
argument|unsigned int *outSpaceRequired
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_VERTEXBUFFER9_H_
end_comment
end_unit
