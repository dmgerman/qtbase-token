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
name|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUITAST_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUITAST_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUITAST_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
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
operator|:
name|TIntermTraverser
argument_list|(
argument|true
argument_list|,
argument|false
argument_list|,
argument|false
argument_list|)
block|{     }
name|bool
name|visitBinary
argument_list|(
argument|Visit visit
argument_list|,
argument|TIntermBinary *
argument_list|)
name|override
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_UNFOLDSHORTCIRCUITAST_H_
end_comment
end_unit
