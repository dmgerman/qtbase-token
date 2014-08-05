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
file|"compiler/translator/TranslatorESSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/TranslatorGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/TranslatorHLSL.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// This function must be provided to create the actual
end_comment
begin_comment
comment|// compile object used by higher level code.  It returns
end_comment
begin_comment
comment|// a subclass of TCompiler.
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|ConstructCompiler
name|TCompiler
modifier|*
name|ConstructCompiler
parameter_list|(
name|sh
operator|::
name|GLenum
name|type
parameter_list|,
name|ShShaderSpec
name|spec
parameter_list|,
name|ShShaderOutput
name|output
parameter_list|)
block|{
switch|switch
condition|(
name|output
condition|)
block|{
case|case
name|SH_ESSL_OUTPUT
case|:
return|return
operator|new
name|TranslatorESSL
argument_list|(
name|type
argument_list|,
name|spec
argument_list|)
return|;
case|case
name|SH_GLSL_OUTPUT
case|:
return|return
operator|new
name|TranslatorGLSL
argument_list|(
name|type
argument_list|,
name|spec
argument_list|)
return|;
case|case
name|SH_HLSL9_OUTPUT
case|:
case|case
name|SH_HLSL11_OUTPUT
case|:
return|return
operator|new
name|TranslatorHLSL
argument_list|(
name|type
argument_list|,
name|spec
argument_list|,
name|output
argument_list|)
return|;
default|default:
return|return
name|NULL
return|;
block|}
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// Delete the compiler made by ConstructCompiler
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|DeleteCompiler
name|void
name|DeleteCompiler
parameter_list|(
name|TCompiler
modifier|*
name|compiler
parameter_list|)
block|{
operator|delete
name|compiler
expr_stmt|;
block|}
end_function
end_unit
