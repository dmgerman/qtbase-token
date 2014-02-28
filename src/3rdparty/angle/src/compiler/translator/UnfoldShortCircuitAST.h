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
begin_comment
comment|// UnfoldShortCircuitAST is an AST traverser to replace short-circuiting
end_comment
begin_comment
comment|// operations with ternary operations.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_UNFOLD_SHORT_CIRCUIT_AST_H_
end_ifndef
begin_define
DECL|macro|COMPILER_UNFOLD_SHORT_CIRCUIT_AST_H_
define|#
directive|define
name|COMPILER_UNFOLD_SHORT_CIRCUIT_AST_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_comment
comment|// This traverser identifies all the short circuit binary  nodes that need to
end_comment
begin_comment
comment|// be replaced, and creates the corresponding replacement nodes. However,
end_comment
begin_comment
comment|// the actual replacements happen after the traverse through updateTree().
end_comment
begin_decl_stmt
name|class
name|UnfoldShortCircuitAST
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|UnfoldShortCircuitAST
argument_list|()
block|{ }
name|virtual
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *
argument_list|)
block|;
name|void
name|updateTree
argument_list|()
block|;
name|private
operator|:
expr|struct
name|NodeUpdateEntry
block|{
name|NodeUpdateEntry
argument_list|(
name|TIntermNode
operator|*
name|_parent
argument_list|,
name|TIntermNode
operator|*
name|_original
argument_list|,
name|TIntermNode
operator|*
name|_replacement
argument_list|)
operator|:
name|parent
argument_list|(
name|_parent
argument_list|)
block|,
name|original
argument_list|(
name|_original
argument_list|)
block|,
name|replacement
argument_list|(
argument|_replacement
argument_list|)
block|{}
name|TIntermNode
operator|*
name|parent
block|;
name|TIntermNode
operator|*
name|original
block|;
name|TIntermNode
operator|*
name|replacement
block|;     }
block|;
comment|// During traversing, save all the replacements that need to happen;
comment|// then replace them by calling updateNodes().
name|std
operator|::
name|vector
operator|<
name|NodeUpdateEntry
operator|>
name|replacements
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnfoldShortCircuitAST
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_UNFOLD_SHORT_CIRCUIT_AST_H_
end_comment
end_unit
