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
comment|// Buffer.h: Defines the gl::Buffer class, representing storage of vertex and/or
end_comment
begin_comment
comment|// index data. Implements GL buffer objects and related functionality.
end_comment
begin_comment
comment|// [OpenGL ES 2.0.24] section 2.9 page 21.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_BUFFER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_BUFFER_H_
define|#
directive|define
name|LIBANGLE_BUFFER_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Debug.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/IndexRangeCache.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/RefCountObject.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|BufferImpl
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Buffer
name|final
range|:
name|public
name|RefCountObject
decl_stmt|,
name|public
name|LabeledObject
block|{
name|public
label|:
name|Buffer
argument_list|(
argument|rx::BufferImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Buffer
argument_list|()
expr_stmt|;
name|void
name|setLabel
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|label
argument_list|)
name|override
decl_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getLabel
argument_list|()
specifier|const
name|override
expr_stmt|;
name|Error
name|bufferData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
name|GLenum
name|usage
parameter_list|)
function_decl|;
name|Error
name|bufferSubData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|,
name|GLintptr
name|offset
parameter_list|)
function_decl|;
name|Error
name|copyBufferSubData
parameter_list|(
name|Buffer
modifier|*
name|source
parameter_list|,
name|GLintptr
name|sourceOffset
parameter_list|,
name|GLintptr
name|destOffset
parameter_list|,
name|GLsizeiptr
name|size
parameter_list|)
function_decl|;
name|Error
name|map
parameter_list|(
name|GLenum
name|access
parameter_list|)
function_decl|;
name|Error
name|mapRange
parameter_list|(
name|GLintptr
name|offset
parameter_list|,
name|GLsizeiptr
name|length
parameter_list|,
name|GLbitfield
name|access
parameter_list|)
function_decl|;
name|Error
name|unmap
parameter_list|(
name|GLboolean
modifier|*
name|result
parameter_list|)
function_decl|;
name|void
name|onTransformFeedback
parameter_list|()
function_decl|;
name|void
name|onPixelUnpack
parameter_list|()
function_decl|;
name|Error
name|getIndexRange
argument_list|(
name|GLenum
name|type
argument_list|,
name|size_t
name|offset
argument_list|,
name|size_t
name|count
argument_list|,
name|bool
name|primitiveRestartEnabled
argument_list|,
name|IndexRange
operator|*
name|outRange
argument_list|)
decl|const
decl_stmt|;
name|GLenum
name|getUsage
argument_list|()
specifier|const
block|{
return|return
name|mUsage
return|;
block|}
name|GLbitfield
name|getAccessFlags
argument_list|()
specifier|const
block|{
return|return
name|mAccessFlags
return|;
block|}
name|GLenum
name|getAccess
argument_list|()
specifier|const
block|{
return|return
name|mAccess
return|;
block|}
name|GLboolean
name|isMapped
argument_list|()
specifier|const
block|{
return|return
name|mMapped
return|;
block|}
name|GLvoid
operator|*
name|getMapPointer
argument_list|()
specifier|const
block|{
return|return
name|mMapPointer
return|;
block|}
name|GLint64
name|getMapOffset
argument_list|()
specifier|const
block|{
return|return
name|mMapOffset
return|;
block|}
name|GLint64
name|getMapLength
argument_list|()
specifier|const
block|{
return|return
name|mMapLength
return|;
block|}
name|GLint64
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
name|rx
operator|::
name|BufferImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|{
return|return
name|mBuffer
return|;
block|}
name|private
label|:
name|rx
operator|::
name|BufferImpl
operator|*
name|mBuffer
expr_stmt|;
name|std
operator|::
name|string
name|mLabel
expr_stmt|;
name|GLenum
name|mUsage
decl_stmt|;
name|GLint64
name|mSize
decl_stmt|;
name|GLbitfield
name|mAccessFlags
decl_stmt|;
name|GLenum
name|mAccess
decl_stmt|;
name|GLboolean
name|mMapped
decl_stmt|;
name|GLvoid
modifier|*
name|mMapPointer
decl_stmt|;
name|GLint64
name|mMapOffset
decl_stmt|;
name|GLint64
name|mMapLength
decl_stmt|;
name|mutable
name|IndexRangeCache
name|mIndexRangeCache
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_BUFFER_H_
end_comment
end_unit
