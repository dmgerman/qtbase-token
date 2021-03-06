begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
begin_include
include|#
directive|include
file|"libANGLE/TransformFeedback.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/TransformFeedbackImpl.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|TransformFeedback
name|TransformFeedback
operator|::
name|TransformFeedback
parameter_list|(
name|rx
operator|::
name|TransformFeedbackImpl
modifier|*
name|impl
parameter_list|,
name|GLuint
name|id
parameter_list|,
specifier|const
name|Caps
modifier|&
name|caps
parameter_list|)
member_init_list|:
name|RefCountObject
argument_list|(
name|id
argument_list|)
member_init_list|,
name|mImplementation
argument_list|(
name|impl
argument_list|)
member_init_list|,
name|mLabel
argument_list|()
member_init_list|,
name|mActive
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mPrimitiveMode
argument_list|(
name|GL_NONE
argument_list|)
member_init_list|,
name|mPaused
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mGenericBuffer
argument_list|()
member_init_list|,
name|mIndexedBuffers
argument_list|(
name|caps
operator|.
name|maxTransformFeedbackSeparateAttributes
argument_list|)
block|{
name|ASSERT
argument_list|(
name|impl
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
DECL|function|~TransformFeedback
name|TransformFeedback
operator|::
name|~
name|TransformFeedback
parameter_list|()
block|{
name|mGenericBuffer
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mIndexedBuffers
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|mIndexedBuffers
index|[
name|i
index|]
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
block|}
name|SafeDelete
argument_list|(
name|mImplementation
argument_list|)
expr_stmt|;
block|}
DECL|function|setLabel
name|void
name|TransformFeedback
operator|::
name|setLabel
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|label
parameter_list|)
block|{
name|mLabel
operator|=
name|label
expr_stmt|;
block|}
DECL|function|getLabel
specifier|const
name|std
operator|::
name|string
modifier|&
name|TransformFeedback
operator|::
name|getLabel
parameter_list|()
specifier|const
block|{
return|return
name|mLabel
return|;
block|}
DECL|function|begin
name|void
name|TransformFeedback
operator|::
name|begin
parameter_list|(
name|GLenum
name|primitiveMode
parameter_list|)
block|{
name|mActive
operator|=
literal|true
expr_stmt|;
name|mPrimitiveMode
operator|=
name|primitiveMode
expr_stmt|;
name|mPaused
operator|=
literal|false
expr_stmt|;
name|mImplementation
operator|->
name|begin
argument_list|(
name|primitiveMode
argument_list|)
expr_stmt|;
block|}
DECL|function|end
name|void
name|TransformFeedback
operator|::
name|end
parameter_list|()
block|{
name|mActive
operator|=
literal|false
expr_stmt|;
name|mPrimitiveMode
operator|=
name|GL_NONE
expr_stmt|;
name|mPaused
operator|=
literal|false
expr_stmt|;
name|mImplementation
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
DECL|function|pause
name|void
name|TransformFeedback
operator|::
name|pause
parameter_list|()
block|{
name|mPaused
operator|=
literal|true
expr_stmt|;
name|mImplementation
operator|->
name|pause
argument_list|()
expr_stmt|;
block|}
DECL|function|resume
name|void
name|TransformFeedback
operator|::
name|resume
parameter_list|()
block|{
name|mPaused
operator|=
literal|false
expr_stmt|;
name|mImplementation
operator|->
name|resume
argument_list|()
expr_stmt|;
block|}
DECL|function|isActive
name|bool
name|TransformFeedback
operator|::
name|isActive
parameter_list|()
specifier|const
block|{
return|return
name|mActive
return|;
block|}
DECL|function|isPaused
name|bool
name|TransformFeedback
operator|::
name|isPaused
parameter_list|()
specifier|const
block|{
return|return
name|mPaused
return|;
block|}
DECL|function|getPrimitiveMode
name|GLenum
name|TransformFeedback
operator|::
name|getPrimitiveMode
parameter_list|()
specifier|const
block|{
return|return
name|mPrimitiveMode
return|;
block|}
DECL|function|bindGenericBuffer
name|void
name|TransformFeedback
operator|::
name|bindGenericBuffer
parameter_list|(
name|Buffer
modifier|*
name|buffer
parameter_list|)
block|{
name|mGenericBuffer
operator|.
name|set
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|mImplementation
operator|->
name|bindGenericBuffer
argument_list|(
name|mGenericBuffer
argument_list|)
expr_stmt|;
block|}
DECL|function|detachBuffer
name|void
name|TransformFeedback
operator|::
name|detachBuffer
parameter_list|(
name|GLuint
name|bufferName
parameter_list|)
block|{
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|;
name|index
operator|<
name|mIndexedBuffers
operator|.
name|size
argument_list|()
condition|;
name|index
operator|++
control|)
block|{
if|if
condition|(
name|mIndexedBuffers
index|[
name|index
index|]
operator|.
name|id
argument_list|()
operator|==
name|bufferName
condition|)
block|{
name|mIndexedBuffers
index|[
name|index
index|]
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
name|mImplementation
operator|->
name|bindIndexedBuffer
argument_list|(
name|index
argument_list|,
name|mIndexedBuffers
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|mGenericBuffer
operator|.
name|id
argument_list|()
operator|==
name|bufferName
condition|)
block|{
name|mGenericBuffer
operator|.
name|set
argument_list|(
literal|nullptr
argument_list|)
expr_stmt|;
name|mImplementation
operator|->
name|bindGenericBuffer
argument_list|(
name|mGenericBuffer
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getGenericBuffer
specifier|const
name|BindingPointer
argument_list|<
name|Buffer
argument_list|>
modifier|&
name|TransformFeedback
operator|::
name|getGenericBuffer
parameter_list|()
specifier|const
block|{
return|return
name|mGenericBuffer
return|;
block|}
DECL|function|bindIndexedBuffer
name|void
name|TransformFeedback
operator|::
name|bindIndexedBuffer
parameter_list|(
name|size_t
name|index
parameter_list|,
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|index
operator|<
name|mIndexedBuffers
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|mIndexedBuffers
index|[
name|index
index|]
operator|.
name|set
argument_list|(
name|buffer
argument_list|,
name|offset
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|mImplementation
operator|->
name|bindIndexedBuffer
argument_list|(
name|index
argument_list|,
name|mIndexedBuffers
index|[
name|index
index|]
argument_list|)
expr_stmt|;
block|}
DECL|function|getIndexedBuffer
specifier|const
name|OffsetBindingPointer
argument_list|<
name|Buffer
argument_list|>
modifier|&
name|TransformFeedback
operator|::
name|getIndexedBuffer
parameter_list|(
name|size_t
name|index
parameter_list|)
specifier|const
block|{
name|ASSERT
argument_list|(
name|index
operator|<
name|mIndexedBuffers
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|mIndexedBuffers
index|[
name|index
index|]
return|;
block|}
DECL|function|getIndexedBufferCount
name|size_t
name|TransformFeedback
operator|::
name|getIndexedBufferCount
parameter_list|()
specifier|const
block|{
return|return
name|mIndexedBuffers
operator|.
name|size
argument_list|()
return|;
block|}
DECL|function|getImplementation
name|rx
operator|::
name|TransformFeedbackImpl
modifier|*
name|TransformFeedback
operator|::
name|getImplementation
parameter_list|()
block|{
return|return
name|mImplementation
return|;
block|}
DECL|function|getImplementation
specifier|const
name|rx
operator|::
name|TransformFeedbackImpl
modifier|*
name|TransformFeedback
operator|::
name|getImplementation
parameter_list|()
specifier|const
block|{
return|return
name|mImplementation
return|;
block|}
block|}
end_namespace
end_unit
