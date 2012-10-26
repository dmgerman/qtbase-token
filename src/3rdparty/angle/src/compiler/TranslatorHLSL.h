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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATORHLSL_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATORHLSL_H_
define|#
directive|define
name|COMPILER_TRANSLATORHLSL_H_
end_define
begin_include
include|#
directive|include
file|"compiler/ShHandle.h"
end_include
begin_decl_stmt
name|class
name|TranslatorHLSL
range|:
name|public
name|TCompiler
block|{
name|public
operator|:
name|TranslatorHLSL
argument_list|(
argument|ShShaderType type
argument_list|,
argument|ShShaderSpec spec
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|translate
argument_list|(
name|TIntermNode
operator|*
name|root
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATORHLSL_H_
end_comment
end_unit
