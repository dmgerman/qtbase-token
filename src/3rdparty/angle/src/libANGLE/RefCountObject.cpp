begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
comment|// RefCountObject.cpp: Defines the gl::RefCountObject base class that provides
end_comment
begin_comment
comment|// lifecycle support for GL objects using the traditional BindObject scheme, but
end_comment
begin_comment
comment|// that need to be reference counted for correct cross-context deletion.
end_comment
begin_comment
comment|// (Concretely, textures, buffers and renderbuffers.)
end_comment
begin_include
include|#
directive|include
file|"RefCountObject.h"
end_include
begin_constructor
DECL|function|RefCountObject
name|RefCountObject
operator|::
name|RefCountObject
parameter_list|(
name|GLuint
name|id
parameter_list|)
member_init_list|:
name|mId
argument_list|(
name|id
argument_list|)
member_init_list|,
name|mRefCount
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~RefCountObject
name|RefCountObject
operator|::
name|~
name|RefCountObject
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mRefCount
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addRef
name|void
name|RefCountObject
operator|::
name|addRef
parameter_list|()
specifier|const
block|{
name|mRefCount
operator|++
expr_stmt|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|RefCountObject
operator|::
name|release
parameter_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|mRefCount
operator|>
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|mRefCount
operator|==
literal|0
condition|)
block|{
operator|delete
name|this
expr_stmt|;
block|}
block|}
end_function
end_unit
