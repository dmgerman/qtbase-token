begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// ShaderExecutable.h: Defines a renderer-agnostic class to contain shader
end_comment
begin_comment
comment|// executable implementation details.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_SHADEREXECUTABLE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_SHADEREXECUTABLE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_SHADEREXECUTABLE_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|ShaderExecutable
block|{
name|public
label|:
name|ShaderExecutable
argument_list|(
argument|const void *function
argument_list|,
argument|size_t length
argument_list|)
block|:
name|mLength
argument_list|(
argument|length
argument_list|)
block|{
name|mFunction
operator|=
name|new
name|char
index|[
name|length
index|]
expr_stmt|;
name|memcpy
argument_list|(
name|mFunction
argument_list|,
name|function
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|ShaderExecutable
argument_list|()
block|{
name|delete
name|mFunction
block|;     }
name|void
operator|*
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|mFunction
return|;
block|}
name|size_t
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|mLength
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ShaderExecutable
argument_list|)
expr_stmt|;
name|void
modifier|*
name|mFunction
decl_stmt|;
specifier|const
name|size_t
name|mLength
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
comment|// LIBGLESV2_RENDERER_SHADEREXECUTABLE9_H_
end_comment
end_unit
