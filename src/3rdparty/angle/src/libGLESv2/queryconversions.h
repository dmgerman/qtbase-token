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
begin_comment
comment|// queryconversions.h: Declaration of state query cast conversions
end_comment
begin_decl_stmt
name|namespace
name|gl
block|{
comment|// The GL state query API types are: bool, int, uint, float, int64
name|template
operator|<
name|typename
name|QueryT
operator|>
name|void
name|CastStateValues
argument_list|(
argument|Context *context
argument_list|,
argument|GLenum nativeType
argument_list|,
argument|GLenum pname
argument_list|,
argument|unsigned int numParams
argument_list|,
argument|QueryT *outParams
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
end_unit
