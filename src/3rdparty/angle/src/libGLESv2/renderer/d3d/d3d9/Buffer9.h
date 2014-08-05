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
comment|// Buffer9.h: Defines the rx::Buffer9 class which implements rx::BufferImpl via rx::BufferD3D.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_BUFFER9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_BUFFER9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_BUFFER9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/BufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/MemoryBuffer.h"
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
name|class
name|Renderer9
decl_stmt|;
name|class
name|Buffer9
range|:
name|public
name|BufferD3D
block|{
name|public
operator|:
name|Buffer9
argument_list|(
name|rx
operator|::
name|Renderer9
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|Buffer9
argument_list|()
block|;
specifier|static
name|Buffer9
operator|*
name|makeBuffer9
argument_list|(
name|BufferImpl
operator|*
name|buffer
argument_list|)
block|;
comment|// BufferD3D implementation
name|virtual
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|bool
name|supportsDirectBinding
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|Renderer
operator|*
name|getRenderer
argument_list|()
block|;
comment|// BufferImpl implementation
name|virtual
name|void
name|setData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|void
operator|*
name|getData
argument_list|()
block|;
name|virtual
name|void
name|setSubData
argument_list|(
argument|const void* data
argument_list|,
argument|size_t size
argument_list|,
argument|size_t offset
argument_list|)
block|;
name|virtual
name|void
name|copySubData
argument_list|(
argument|BufferImpl* source
argument_list|,
argument|GLintptr sourceOffset
argument_list|,
argument|GLintptr destOffset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|virtual
name|GLvoid
operator|*
name|map
argument_list|(
argument|size_t offset
argument_list|,
argument|size_t length
argument_list|,
argument|GLbitfield access
argument_list|)
block|;
name|virtual
name|void
name|unmap
argument_list|()
block|;
name|virtual
name|void
name|markTransformFeedbackUsage
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Buffer9
argument_list|)
block|;
name|rx
operator|::
name|Renderer9
operator|*
name|mRenderer
block|;
name|MemoryBuffer
name|mMemory
block|;
name|size_t
name|mSize
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_BUFFER9_H_
end_comment
end_unit
