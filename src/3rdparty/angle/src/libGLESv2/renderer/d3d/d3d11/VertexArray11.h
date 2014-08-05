begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexArray11.h: Defines the rx::VertexArray11 class which implements rx::VertexArrayImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_VERTEXARRAY11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXARRAY11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXARRAY11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/VertexArrayImpl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|VertexArray11
range|:
name|public
name|VertexArrayImpl
block|{
name|public
operator|:
name|VertexArray11
argument_list|(
name|rx
operator|::
name|Renderer11
operator|*
name|renderer
argument_list|)
operator|:
name|VertexArrayImpl
argument_list|()
block|,
name|mRenderer
argument_list|(
argument|renderer
argument_list|)
block|{     }
name|virtual
operator|~
name|VertexArray11
argument_list|()
block|{ }
name|virtual
name|void
name|setElementArrayBuffer
argument_list|(
argument|const gl::Buffer *buffer
argument_list|)
block|{ }
name|virtual
name|void
name|setAttribute
argument_list|(
argument|size_t idx
argument_list|,
argument|const gl::VertexAttribute&attr
argument_list|)
block|{ }
name|virtual
name|void
name|setAttributeDivisor
argument_list|(
argument|size_t idx
argument_list|,
argument|GLuint divisor
argument_list|)
block|{ }
name|virtual
name|void
name|enableAttribute
argument_list|(
argument|size_t idx
argument_list|,
argument|bool enabledState
argument_list|)
block|{ }
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|VertexArray11
argument_list|)
block|;
name|rx
operator|::
name|Renderer11
operator|*
name|mRenderer
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_VERTEXARRAY11_H_
end_comment
end_unit
