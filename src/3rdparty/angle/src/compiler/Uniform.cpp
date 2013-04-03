begin_unit
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
begin_include
include|#
directive|include
file|"compiler/Uniform.h"
end_include
begin_namespace
DECL|namespace|sh
namespace|namespace
name|sh
block|{
DECL|function|Uniform
name|Uniform
operator|::
name|Uniform
parameter_list|(
name|GLenum
name|type
parameter_list|,
name|GLenum
name|precision
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|arraySize
parameter_list|,
name|int
name|registerIndex
parameter_list|)
block|{
name|this
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|this
operator|->
name|precision
operator|=
name|precision
expr_stmt|;
name|this
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|this
operator|->
name|arraySize
operator|=
name|arraySize
expr_stmt|;
name|this
operator|->
name|registerIndex
operator|=
name|registerIndex
expr_stmt|;
block|}
block|}
end_namespace
end_unit
