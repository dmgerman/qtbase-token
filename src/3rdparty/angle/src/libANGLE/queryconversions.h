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
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_QUERY_CONVERSIONS_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_QUERY_CONVERSIONS_H_
define|#
directive|define
name|LIBANGLE_QUERY_CONVERSIONS_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Context
decl_stmt|;
comment|// Helper class for converting a GL type to a GLenum:
comment|// We can't use CastStateValueEnum generally, because of GLboolean + GLubyte overlap.
comment|// We restrict our use to CastStateValue, where it eliminates duplicate parameters.
name|template
operator|<
name|typename
name|GLType
operator|>
expr|struct
name|GLTypeToGLenum
block|{
specifier|static
name|GLenum
name|value
block|; }
expr_stmt|;
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_QUERY_CONVERSIONS_H_
end_comment
end_unit
