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
comment|// BufferD3D.cpp Defines common functionality between the Buffer9 and Buffer11 classes.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/BufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/IndexBuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/VertexBuffer.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|member|mNextSerial
name|unsigned
name|int
name|BufferD3D
operator|::
name|mNextSerial
init|=
literal|1
decl_stmt|;
DECL|function|BufferD3D
name|BufferD3D
operator|::
name|BufferD3D
parameter_list|(
name|BufferFactoryD3D
modifier|*
name|factory
parameter_list|)
member_init_list|:
name|BufferImpl
argument_list|()
member_init_list|,
name|mFactory
argument_list|(
name|factory
argument_list|)
member_init_list|,
name|mStaticVertexBuffer
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mStaticIndexBuffer
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mStaticBufferCache
argument_list|(
literal|nullptr
argument_list|)
member_init_list|,
name|mStaticBufferCacheTotalSize
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mStaticVertexBufferOutOfDate
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mUnmodifiedDataUse
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mUsage
argument_list|(
name|D3D_BUFFER_USAGE_STATIC
argument_list|)
block|{
name|updateSerial
argument_list|()
expr_stmt|;
block|}
DECL|function|~BufferD3D
name|BufferD3D
operator|::
name|~
name|BufferD3D
parameter_list|()
block|{
name|SafeDelete
argument_list|(
name|mStaticVertexBuffer
argument_list|)
expr_stmt|;
name|SafeDelete
argument_list|(
name|mStaticIndexBuffer
argument_list|)
expr_stmt|;
name|emptyStaticBufferCache
argument_list|()
expr_stmt|;
block|}
DECL|function|emptyStaticBufferCache
name|void
name|BufferD3D
operator|::
name|emptyStaticBufferCache
parameter_list|()
block|{
if|if
condition|(
name|mStaticBufferCache
operator|!=
literal|nullptr
condition|)
block|{
name|SafeDeleteContainer
argument_list|(
operator|*
name|mStaticBufferCache
argument_list|)
expr_stmt|;
name|SafeDelete
argument_list|(
name|mStaticBufferCache
argument_list|)
expr_stmt|;
block|}
name|mStaticBufferCacheTotalSize
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|updateSerial
name|void
name|BufferD3D
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
DECL|function|updateD3DBufferUsage
name|void
name|BufferD3D
operator|::
name|updateD3DBufferUsage
parameter_list|(
name|GLenum
name|usage
parameter_list|)
block|{
switch|switch
condition|(
name|usage
condition|)
block|{
case|case
name|GL_STATIC_DRAW
case|:
case|case
name|GL_STATIC_READ
case|:
case|case
name|GL_STATIC_COPY
case|:
name|mUsage
operator|=
name|D3D_BUFFER_USAGE_STATIC
expr_stmt|;
name|initializeStaticData
argument_list|()
expr_stmt|;
break|break;
case|case
name|GL_STREAM_DRAW
case|:
case|case
name|GL_STREAM_READ
case|:
case|case
name|GL_STREAM_COPY
case|:
case|case
name|GL_DYNAMIC_READ
case|:
case|case
name|GL_DYNAMIC_COPY
case|:
case|case
name|GL_DYNAMIC_DRAW
case|:
name|mUsage
operator|=
name|D3D_BUFFER_USAGE_DYNAMIC
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|initializeStaticData
name|void
name|BufferD3D
operator|::
name|initializeStaticData
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mStaticVertexBuffer
condition|)
block|{
name|mStaticVertexBuffer
operator|=
operator|new
name|StaticVertexBufferInterface
argument_list|(
name|mFactory
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|mStaticIndexBuffer
condition|)
block|{
name|mStaticIndexBuffer
operator|=
operator|new
name|StaticIndexBufferInterface
argument_list|(
name|mFactory
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getStaticIndexBuffer
name|StaticIndexBufferInterface
modifier|*
name|BufferD3D
operator|::
name|getStaticIndexBuffer
parameter_list|()
block|{
return|return
name|mStaticIndexBuffer
return|;
block|}
DECL|function|getStaticVertexBuffer
name|StaticVertexBufferInterface
modifier|*
name|BufferD3D
operator|::
name|getStaticVertexBuffer
parameter_list|(
specifier|const
name|gl
operator|::
name|VertexAttribute
modifier|&
name|attribute
parameter_list|,
name|D3DStaticBufferCreationType
name|creationType
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mStaticVertexBuffer
condition|)
block|{
comment|// Early out if there aren't any static buffers at all
name|ASSERT
argument_list|(
name|mStaticBufferCache
operator|==
literal|nullptr
argument_list|)
expr_stmt|;
return|return
literal|nullptr
return|;
block|}
if|if
condition|(
name|mStaticBufferCache
operator|==
literal|nullptr
operator|&&
operator|!
name|mStaticVertexBuffer
operator|->
name|isCommitted
argument_list|()
condition|)
block|{
comment|// Early out, the attribute can be added to mStaticVertexBuffer or is already in there
return|return
name|mStaticVertexBuffer
return|;
block|}
comment|// At this point, see if any of the existing static buffers contains the attribute data
comment|// If the default static vertex buffer contains the attribute, then return it
if|if
condition|(
name|mStaticVertexBuffer
operator|->
name|lookupAttribute
argument_list|(
name|attribute
argument_list|,
literal|nullptr
argument_list|)
condition|)
block|{
return|return
name|mStaticVertexBuffer
return|;
block|}
if|if
condition|(
name|mStaticBufferCache
operator|!=
literal|nullptr
condition|)
block|{
comment|// If there is a cached static buffer that already contains the attribute, then return it
for|for
control|(
name|StaticVertexBufferInterface
modifier|*
name|staticBuffer
range|:
operator|*
name|mStaticBufferCache
control|)
block|{
if|if
condition|(
name|staticBuffer
operator|->
name|lookupAttribute
argument_list|(
name|attribute
argument_list|,
literal|nullptr
argument_list|)
condition|)
block|{
return|return
name|staticBuffer
return|;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|mStaticVertexBuffer
operator|->
name|isCommitted
argument_list|()
condition|)
block|{
comment|// None of the existing static buffers contain the attribute data and we are able to add
comment|// the data to mStaticVertexBuffer, so we should just do so
return|return
name|mStaticVertexBuffer
return|;
block|}
comment|// At this point, we must create a new static buffer for the attribute data
if|if
condition|(
name|creationType
operator|!=
name|D3D_BUFFER_CREATE_IF_NECESSARY
condition|)
block|{
return|return
literal|nullptr
return|;
block|}
name|ASSERT
argument_list|(
name|mStaticVertexBuffer
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mStaticVertexBuffer
operator|->
name|isCommitted
argument_list|()
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|staticVertexBufferSize
init|=
name|mStaticVertexBuffer
operator|->
name|getBufferSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|IsUnsignedAdditionSafe
argument_list|(
name|staticVertexBufferSize
argument_list|,
name|mStaticBufferCacheTotalSize
argument_list|)
condition|)
block|{
comment|// Ensure that the total size of the static buffer cache remains less than 4x the
comment|// size of the original buffer
name|unsigned
name|int
name|maxStaticCacheSize
init|=
name|IsUnsignedMultiplicationSafe
argument_list|(
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|getSize
argument_list|()
argument_list|)
argument_list|,
literal|4u
argument_list|)
condition|?
literal|4u
operator|*
cast|static_cast
argument_list|<
name|unsigned
name|int
argument_list|>
argument_list|(
name|getSize
argument_list|()
argument_list|)
else|:
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|max
argument_list|()
decl_stmt|;
comment|// We can't reuse the default static vertex buffer, so we add it to the cache
if|if
condition|(
name|staticVertexBufferSize
operator|+
name|mStaticBufferCacheTotalSize
operator|<=
name|maxStaticCacheSize
condition|)
block|{
if|if
condition|(
name|mStaticBufferCache
operator|==
literal|nullptr
condition|)
block|{
name|mStaticBufferCache
operator|=
operator|new
name|std
operator|::
name|vector
argument_list|<
name|StaticVertexBufferInterface
operator|*
argument_list|>
argument_list|()
expr_stmt|;
block|}
name|mStaticBufferCacheTotalSize
operator|+=
name|staticVertexBufferSize
expr_stmt|;
operator|(
operator|*
name|mStaticBufferCache
operator|)
operator|.
name|push_back
argument_list|(
name|mStaticVertexBuffer
argument_list|)
expr_stmt|;
name|mStaticVertexBuffer
operator|=
literal|nullptr
expr_stmt|;
comment|// Then reinitialize the static buffers to create a new static vertex buffer
name|initializeStaticData
argument_list|()
expr_stmt|;
comment|// Return the default static vertex buffer
return|return
name|mStaticVertexBuffer
return|;
block|}
block|}
comment|// At this point:
comment|//   - mStaticVertexBuffer is committed and can't be altered
comment|//   - mStaticBufferCache is full (or nearly overflowing)
comment|// The inputted attribute should be put in some static buffer at some point, but it can't
comment|// go in one right now, since mStaticBufferCache is full and we can't delete mStaticVertexBuffer
comment|// in case another attribute is relying upon it for the current draw.
comment|// We therefore mark mStaticVertexBuffer for deletion at the next possible time.
name|mStaticVertexBufferOutOfDate
operator|=
literal|true
expr_stmt|;
return|return
literal|nullptr
return|;
block|}
DECL|function|reinitOutOfDateStaticData
name|void
name|BufferD3D
operator|::
name|reinitOutOfDateStaticData
parameter_list|()
block|{
if|if
condition|(
name|mStaticVertexBufferOutOfDate
condition|)
block|{
comment|// During the last draw the caller tried to use some attribute with static data, but neither
comment|// the static buffer cache nor mStaticVertexBuffer contained that data.
comment|// Therefore, invalidate mStaticVertexBuffer so that if the caller tries to use that
comment|// attribute in the next draw, it'll successfully get put into mStaticVertexBuffer.
name|invalidateStaticData
argument_list|(
name|D3D_BUFFER_INVALIDATE_DEFAULT_BUFFER_ONLY
argument_list|)
expr_stmt|;
name|mStaticVertexBufferOutOfDate
operator|=
literal|false
expr_stmt|;
block|}
block|}
DECL|function|invalidateStaticData
name|void
name|BufferD3D
operator|::
name|invalidateStaticData
parameter_list|(
name|D3DBufferInvalidationType
name|invalidationType
parameter_list|)
block|{
if|if
condition|(
name|invalidationType
operator|==
name|D3D_BUFFER_INVALIDATE_WHOLE_CACHE
operator|&&
name|mStaticBufferCache
operator|!=
literal|nullptr
condition|)
block|{
name|emptyStaticBufferCache
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|mStaticVertexBuffer
operator|&&
name|mStaticVertexBuffer
operator|->
name|getBufferSize
argument_list|()
operator|!=
literal|0
operator|)
operator|||
operator|(
name|mStaticIndexBuffer
operator|&&
name|mStaticIndexBuffer
operator|->
name|getBufferSize
argument_list|()
operator|!=
literal|0
operator|)
condition|)
block|{
name|SafeDelete
argument_list|(
name|mStaticVertexBuffer
argument_list|)
expr_stmt|;
name|SafeDelete
argument_list|(
name|mStaticIndexBuffer
argument_list|)
expr_stmt|;
comment|// If the buffer was created with a static usage then we recreate the static
comment|// buffers so that they are populated the next time we use this buffer.
if|if
condition|(
name|mUsage
operator|==
name|D3D_BUFFER_USAGE_STATIC
condition|)
block|{
name|initializeStaticData
argument_list|()
expr_stmt|;
block|}
block|}
name|mUnmodifiedDataUse
operator|=
literal|0
expr_stmt|;
block|}
comment|// Creates static buffers if sufficient used data has been left unmodified
DECL|function|promoteStaticUsage
name|void
name|BufferD3D
operator|::
name|promoteStaticUsage
parameter_list|(
name|int
name|dataSize
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mStaticVertexBuffer
operator|&&
operator|!
name|mStaticIndexBuffer
condition|)
block|{
comment|// There isn't any scenario that involves promoting static usage and the static buffer cache
comment|// being non-empty
name|ASSERT
argument_list|(
name|mStaticBufferCache
operator|==
literal|nullptr
argument_list|)
expr_stmt|;
name|mUnmodifiedDataUse
operator|+=
name|dataSize
expr_stmt|;
if|if
condition|(
name|mUnmodifiedDataUse
operator|>
literal|3
operator|*
name|getSize
argument_list|()
condition|)
block|{
name|initializeStaticData
argument_list|()
expr_stmt|;
block|}
block|}
block|}
DECL|function|getIndexRange
name|gl
operator|::
name|Error
name|BufferD3D
operator|::
name|getIndexRange
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|count
parameter_list|,
name|bool
name|primitiveRestartEnabled
parameter_list|,
name|gl
operator|::
name|IndexRange
modifier|*
name|outRange
parameter_list|)
block|{
specifier|const
name|uint8_t
modifier|*
name|data
init|=
literal|nullptr
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|getData
argument_list|(
operator|&
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
operator|*
name|outRange
operator|=
name|gl
operator|::
name|ComputeIndexRange
argument_list|(
name|type
argument_list|,
name|data
operator|+
name|offset
argument_list|,
name|count
argument_list|,
name|primitiveRestartEnabled
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit
