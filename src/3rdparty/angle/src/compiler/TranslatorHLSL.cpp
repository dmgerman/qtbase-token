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
begin_include
include|#
directive|include
file|"compiler/TranslatorHLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/InitializeParseContext.h"
end_include
begin_include
include|#
directive|include
file|"compiler/OutputHLSL.h"
end_include
begin_constructor
DECL|function|TranslatorHLSL
name|TranslatorHLSL
operator|::
name|TranslatorHLSL
parameter_list|(
name|ShShaderType
name|type
parameter_list|,
name|ShShaderSpec
name|spec
parameter_list|)
member_init_list|:
name|TCompiler
argument_list|(
name|type
argument_list|,
name|spec
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|translate
name|void
name|TranslatorHLSL
operator|::
name|translate
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|TParseContext
modifier|&
name|parseContext
init|=
operator|*
name|GetGlobalParseContext
argument_list|()
decl_stmt|;
name|sh
operator|::
name|OutputHLSL
name|outputHLSL
argument_list|(
name|parseContext
argument_list|)
decl_stmt|;
name|outputHLSL
operator|.
name|output
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
