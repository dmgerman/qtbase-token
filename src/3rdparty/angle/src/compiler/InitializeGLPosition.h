begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_INITIALIZE_GL_POSITION_H_
end_ifndef
begin_define
DECL|macro|COMPILER_INITIALIZE_GL_POSITION_H_
define|#
directive|define
name|COMPILER_INITIALIZE_GL_POSITION_H_
end_define
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_decl_stmt
name|class
name|InitializeGLPosition
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|InitializeGLPosition
argument_list|()
operator|:
name|mCodeInserted
argument_list|(
argument|false
argument_list|)
block|{ }
name|protected
operator|:
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary* node
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|visitUnary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermUnary* node
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|visitSelection
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermSelection* node
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|visitLoop
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermLoop* node
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|visitBranch
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBranch* node
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|visitAggregate
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermAggregate* node
argument_list|)
block|;
name|private
operator|:
comment|// Insert AST node in the beginning of main() for "gl_Position = vec4(0.0, 0.0, 0.0, 1.0);".
name|void
name|insertCode
argument_list|(
name|TIntermSequence
operator|&
name|sequence
argument_list|)
block|;
name|bool
name|mCodeInserted
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_INITIALIZE_GL_POSITION_H_
end_comment
end_unit
