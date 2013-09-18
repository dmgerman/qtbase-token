begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
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
comment|// IndexBuffer.cpp: Defines the abstract IndexBuffer class and IndexBufferInterface
end_comment
begin_comment
comment|// class with derivations, classes that perform graphics API agnostic index buffer operations.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/IndexBuffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|member|mNextSerial
name|unsigned
name|int
name|IndexBuffer
operator|::
name|mNextSerial
init|=
literal|1
decl_stmt|;
DECL|function|IndexBuffer
name|IndexBuffer
operator|::
name|IndexBuffer
parameter_list|()
block|{
name|updateSerial
argument_list|()
expr_stmt|;
block|}
DECL|function|~IndexBuffer
name|IndexBuffer
operator|::
name|~
name|IndexBuffer
parameter_list|()
block|{ }
DECL|function|getSerial
name|unsigned
name|int
name|IndexBuffer
operator|::
name|getSerial
parameter_list|()
specifier|const
block|{
return|return
name|mSerial
return|;
block|}
DECL|function|updateSerial
name|void
name|IndexBuffer
operator|::
name|updateSerial
parameter_list|()
block|{
name|mSerial
operator|=
name|mNextSerial
operator|++
expr_stmt|;
block|}
DECL|function|IndexBufferInterface
name|IndexBufferInterface
operator|::
name|IndexBufferInterface
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|bool
name|dynamic
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
block|{
name|mIndexBuffer
operator|=
name|renderer
operator|->
name|createIndexBuffer
argument_list|()
expr_stmt|;
name|mDynamic
operator|=
name|dynamic
expr_stmt|;
name|mWritePosition
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|~IndexBufferInterface
name|IndexBufferInterface
operator|::
name|~
name|IndexBufferInterface
parameter_list|()
block|{
if|if
condition|(
name|mIndexBuffer
condition|)
block|{
operator|delete
name|mIndexBuffer
expr_stmt|;
block|}
block|}
DECL|function|getIndexType
name|GLenum
name|IndexBufferInterface
operator|::
name|getIndexType
parameter_list|()
specifier|const
block|{
return|return
name|mIndexBuffer
operator|->
name|getIndexType
argument_list|()
return|;
block|}
DECL|function|getBufferSize
name|unsigned
name|int
name|IndexBufferInterface
operator|::
name|getBufferSize
parameter_list|()
specifier|const
block|{
return|return
name|mIndexBuffer
operator|->
name|getBufferSize
argument_list|()
return|;
block|}
DECL|function|getSerial
name|unsigned
name|int
name|IndexBufferInterface
operator|::
name|getSerial
parameter_list|()
specifier|const
block|{
return|return
name|mIndexBuffer
operator|->
name|getSerial
argument_list|()
return|;
block|}
DECL|function|mapBuffer
name|bool
name|IndexBufferInterface
operator|::
name|mapBuffer
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|void
modifier|*
modifier|*
name|outMappedMemory
parameter_list|,
name|unsigned
name|int
modifier|*
name|streamOffset
parameter_list|)
block|{
comment|// Protect against integer overflow
if|if
condition|(
name|mWritePosition
operator|+
name|size
operator|<
name|mWritePosition
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|mIndexBuffer
operator|->
name|mapBuffer
argument_list|(
name|mWritePosition
argument_list|,
name|size
argument_list|,
name|outMappedMemory
argument_list|)
condition|)
block|{
if|if
condition|(
name|outMappedMemory
condition|)
block|{
operator|*
name|outMappedMemory
operator|=
name|NULL
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
if|if
condition|(
name|streamOffset
condition|)
block|{
operator|*
name|streamOffset
operator|=
name|mWritePosition
expr_stmt|;
block|}
name|mWritePosition
operator|+=
name|size
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|unmapBuffer
name|bool
name|IndexBufferInterface
operator|::
name|unmapBuffer
parameter_list|()
block|{
return|return
name|mIndexBuffer
operator|->
name|unmapBuffer
argument_list|()
return|;
block|}
DECL|function|getIndexBuffer
name|IndexBuffer
modifier|*
name|IndexBufferInterface
operator|::
name|getIndexBuffer
parameter_list|()
specifier|const
block|{
return|return
name|mIndexBuffer
return|;
block|}
DECL|function|getWritePosition
name|unsigned
name|int
name|IndexBufferInterface
operator|::
name|getWritePosition
parameter_list|()
specifier|const
block|{
return|return
name|mWritePosition
return|;
block|}
DECL|function|setWritePosition
name|void
name|IndexBufferInterface
operator|::
name|setWritePosition
parameter_list|(
name|unsigned
name|int
name|writePosition
parameter_list|)
block|{
name|mWritePosition
operator|=
name|writePosition
expr_stmt|;
block|}
DECL|function|discard
name|bool
name|IndexBufferInterface
operator|::
name|discard
parameter_list|()
block|{
return|return
name|mIndexBuffer
operator|->
name|discard
argument_list|()
return|;
block|}
DECL|function|setBufferSize
name|bool
name|IndexBufferInterface
operator|::
name|setBufferSize
parameter_list|(
name|unsigned
name|int
name|bufferSize
parameter_list|,
name|GLenum
name|indexType
parameter_list|)
block|{
if|if
condition|(
name|mIndexBuffer
operator|->
name|getBufferSize
argument_list|()
operator|==
literal|0
condition|)
block|{
return|return
name|mIndexBuffer
operator|->
name|initialize
argument_list|(
name|bufferSize
argument_list|,
name|indexType
argument_list|,
name|mDynamic
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|mIndexBuffer
operator|->
name|setSize
argument_list|(
name|bufferSize
argument_list|,
name|indexType
argument_list|)
return|;
block|}
block|}
DECL|function|StreamingIndexBufferInterface
name|StreamingIndexBufferInterface
operator|::
name|StreamingIndexBufferInterface
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|IndexBufferInterface
argument_list|(
name|renderer
argument_list|,
literal|true
argument_list|)
block|{ }
DECL|function|~StreamingIndexBufferInterface
name|StreamingIndexBufferInterface
operator|::
name|~
name|StreamingIndexBufferInterface
parameter_list|()
block|{ }
DECL|function|reserveBufferSpace
name|bool
name|StreamingIndexBufferInterface
operator|::
name|reserveBufferSpace
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|GLenum
name|indexType
parameter_list|)
block|{
name|bool
name|result
init|=
literal|true
decl_stmt|;
name|unsigned
name|int
name|curBufferSize
init|=
name|getBufferSize
argument_list|()
decl_stmt|;
name|unsigned
name|int
name|writePos
init|=
name|getWritePosition
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|>
name|curBufferSize
condition|)
block|{
name|result
operator|=
name|setBufferSize
argument_list|(
name|std
operator|::
name|max
argument_list|(
name|size
argument_list|,
literal|2
operator|*
name|curBufferSize
argument_list|)
argument_list|,
name|indexType
argument_list|)
expr_stmt|;
name|setWritePosition
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|writePos
operator|+
name|size
operator|>
name|curBufferSize
operator|||
name|writePos
operator|+
name|size
operator|<
name|writePos
condition|)
block|{
if|if
condition|(
operator|!
name|discard
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
name|setWritePosition
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
DECL|function|StaticIndexBufferInterface
name|StaticIndexBufferInterface
operator|::
name|StaticIndexBufferInterface
parameter_list|(
name|Renderer
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|IndexBufferInterface
argument_list|(
name|renderer
argument_list|,
literal|false
argument_list|)
block|{ }
DECL|function|~StaticIndexBufferInterface
name|StaticIndexBufferInterface
operator|::
name|~
name|StaticIndexBufferInterface
parameter_list|()
block|{ }
DECL|function|reserveBufferSpace
name|bool
name|StaticIndexBufferInterface
operator|::
name|reserveBufferSpace
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|,
name|GLenum
name|indexType
parameter_list|)
block|{
name|unsigned
name|int
name|curSize
init|=
name|getBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|curSize
operator|==
literal|0
condition|)
block|{
return|return
name|setBufferSize
argument_list|(
name|size
argument_list|,
name|indexType
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|curSize
operator|>=
name|size
operator|&&
name|indexType
operator|==
name|getIndexType
argument_list|()
condition|)
block|{
return|return
literal|true
return|;
block|}
else|else
block|{
name|ERR
argument_list|(
literal|"Static index buffers can't be resized"
argument_list|)
expr_stmt|;
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
DECL|function|getIndexRangeCache
name|IndexRangeCache
modifier|*
name|StaticIndexBufferInterface
operator|::
name|getIndexRangeCache
parameter_list|()
block|{
return|return
operator|&
name|mIndexRangeCache
return|;
block|}
block|}
end_namespace
end_unit
