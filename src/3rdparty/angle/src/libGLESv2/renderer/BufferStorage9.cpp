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
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// BufferStorage9.cpp Defines the BufferStorage9 class.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/BufferStorage9.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|BufferStorage9
name|BufferStorage9
operator|::
name|BufferStorage9
parameter_list|()
block|{
name|mMemory
operator|=
name|NULL
expr_stmt|;
name|mAllocatedSize
operator|=
literal|0
expr_stmt|;
name|mSize
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|~BufferStorage9
name|BufferStorage9
operator|::
name|~
name|BufferStorage9
parameter_list|()
block|{
operator|delete
index|[]
name|mMemory
expr_stmt|;
block|}
DECL|function|makeBufferStorage9
name|BufferStorage9
modifier|*
name|BufferStorage9
operator|::
name|makeBufferStorage9
parameter_list|(
name|BufferStorage
modifier|*
name|bufferStorage
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|HAS_DYNAMIC_TYPE
argument_list|(
name|BufferStorage9
operator|*
argument_list|,
name|bufferStorage
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|BufferStorage9
operator|*
argument_list|>
argument_list|(
name|bufferStorage
argument_list|)
return|;
block|}
DECL|function|getData
name|void
modifier|*
name|BufferStorage9
operator|::
name|getData
parameter_list|()
block|{
return|return
name|mMemory
return|;
block|}
DECL|function|setData
name|void
name|BufferStorage9
operator|::
name|setData
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mMemory
operator|||
name|offset
operator|+
name|size
operator|>
name|mAllocatedSize
condition|)
block|{
name|unsigned
name|int
name|newAllocatedSize
init|=
name|offset
operator|+
name|size
decl_stmt|;
name|void
modifier|*
name|newMemory
init|=
operator|new
name|char
index|[
name|newAllocatedSize
index|]
decl_stmt|;
if|if
condition|(
name|offset
operator|>
literal|0
operator|&&
name|mMemory
operator|&&
name|mAllocatedSize
operator|>
literal|0
condition|)
block|{
name|memcpy
argument_list|(
name|newMemory
argument_list|,
name|mMemory
argument_list|,
name|std
operator|::
name|min
argument_list|(
name|offset
argument_list|,
name|mAllocatedSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|delete
index|[]
name|mMemory
expr_stmt|;
name|mMemory
operator|=
name|newMemory
expr_stmt|;
name|mAllocatedSize
operator|=
name|newAllocatedSize
expr_stmt|;
block|}
name|mSize
operator|=
name|std
operator|::
name|max
argument_list|(
name|mSize
argument_list|,
name|offset
operator|+
name|size
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|mMemory
argument_list|)
operator|+
name|offset
argument_list|,
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
DECL|function|clear
name|void
name|BufferStorage9
operator|::
name|clear
parameter_list|()
block|{
name|mSize
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|getSize
name|unsigned
name|int
name|BufferStorage9
operator|::
name|getSize
parameter_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
DECL|function|supportsDirectBinding
name|bool
name|BufferStorage9
operator|::
name|supportsDirectBinding
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
block|}
end_namespace
end_unit
