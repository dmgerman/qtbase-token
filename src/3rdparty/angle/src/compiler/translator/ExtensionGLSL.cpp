begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
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
comment|// ExtensionGLSL.cpp: Implements the TExtensionGLSL class that tracks GLSL extension requirements
end_comment
begin_comment
comment|// of shaders.
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/ExtensionGLSL.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VersionGLSL.h"
end_include
begin_constructor
DECL|function|TExtensionGLSL
name|TExtensionGLSL
operator|::
name|TExtensionGLSL
parameter_list|(
name|ShShaderOutput
name|output
parameter_list|)
member_init_list|:
name|TIntermTraverser
argument_list|(
literal|true
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|)
member_init_list|,
name|mTargetVersion
argument_list|(
name|ShaderOutputTypeToGLSLVersion
argument_list|(
name|output
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|getEnabledExtensions
specifier|const
name|std
operator|::
name|set
argument_list|<
name|std
operator|::
name|string
argument_list|>
modifier|&
name|TExtensionGLSL
operator|::
name|getEnabledExtensions
parameter_list|()
specifier|const
block|{
return|return
name|mEnabledExtensions
return|;
block|}
end_function
begin_function
DECL|function|getRequiredExtensions
specifier|const
name|std
operator|::
name|set
argument_list|<
name|std
operator|::
name|string
argument_list|>
modifier|&
name|TExtensionGLSL
operator|::
name|getRequiredExtensions
parameter_list|()
specifier|const
block|{
return|return
name|mRequiredExtensions
return|;
block|}
end_function
begin_function
DECL|function|visitUnary
name|bool
name|TExtensionGLSL
operator|::
name|visitUnary
parameter_list|(
name|Visit
parameter_list|,
name|TIntermUnary
modifier|*
name|node
parameter_list|)
block|{
name|checkOperator
argument_list|(
name|node
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|visitAggregate
name|bool
name|TExtensionGLSL
operator|::
name|visitAggregate
parameter_list|(
name|Visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
name|checkOperator
argument_list|(
name|node
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|checkOperator
name|void
name|TExtensionGLSL
operator|::
name|checkOperator
parameter_list|(
name|TIntermOperator
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|mTargetVersion
operator|<
name|GLSL_VERSION_130
condition|)
block|{
return|return;
block|}
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpAbs
case|:
break|break;
case|case
name|EOpSign
case|:
break|break;
case|case
name|EOpMix
case|:
break|break;
case|case
name|EOpFloatBitsToInt
case|:
case|case
name|EOpFloatBitsToUint
case|:
case|case
name|EOpIntBitsToFloat
case|:
case|case
name|EOpUintBitsToFloat
case|:
if|if
condition|(
name|mTargetVersion
operator|<
name|GLSL_VERSION_330
condition|)
block|{
comment|// Bit conversion functions cannot be emulated.
name|mRequiredExtensions
operator|.
name|insert
argument_list|(
literal|"GL_ARB_shader_bit_encoding"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|EOpPackSnorm2x16
case|:
case|case
name|EOpPackHalf2x16
case|:
case|case
name|EOpUnpackSnorm2x16
case|:
case|case
name|EOpUnpackHalf2x16
case|:
if|if
condition|(
name|mTargetVersion
operator|<
name|GLSL_VERSION_420
condition|)
block|{
name|mEnabledExtensions
operator|.
name|insert
argument_list|(
literal|"GL_ARB_shading_language_packing"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mTargetVersion
operator|<
name|GLSL_VERSION_330
condition|)
block|{
comment|// floatBitsToUint and uintBitsToFloat are needed to emulate
comment|// packHalf2x16 and unpackHalf2x16 respectively and cannot be
comment|// emulated themselves.
name|mRequiredExtensions
operator|.
name|insert
argument_list|(
literal|"GL_ARB_shader_bit_encoding"
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|EOpPackUnorm2x16
case|:
case|case
name|EOpUnpackUnorm2x16
case|:
if|if
condition|(
name|mTargetVersion
operator|<
name|GLSL_VERSION_410
condition|)
block|{
name|mEnabledExtensions
operator|.
name|insert
argument_list|(
literal|"GL_ARB_shading_language_packing"
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
end_function
end_unit
