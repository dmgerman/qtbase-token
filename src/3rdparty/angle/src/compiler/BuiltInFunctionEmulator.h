begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
name|COMPILIER_BUILT_IN_FUNCTION_EMULATOR_H_
end_ifndef
begin_define
DECL|macro|COMPILIER_BUILT_IN_FUNCTION_EMULATOR_H_
define|#
directive|define
name|COMPILIER_BUILT_IN_FUNCTION_EMULATOR_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"compiler/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/intermediate.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// This class decides which built-in functions need to be replaced with the
end_comment
begin_comment
comment|// emulated ones.
end_comment
begin_comment
comment|// It's only a workaround for OpenGL driver bugs, and isn't needed in general.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|BuiltInFunctionEmulator
block|{
name|public
label|:
name|BuiltInFunctionEmulator
argument_list|(
argument|ShShaderType shaderType
argument_list|)
empty_stmt|;
comment|// Records that a function is called by the shader and might needs to be
comment|// emulated.  If the function's group is not in mFunctionGroupFilter, this
comment|// becomes an no-op.
comment|// Returns true if the function call needs to be replaced with an emulated
comment|// one.
name|bool
name|SetFunctionCalled
parameter_list|(
name|TOperator
name|op
parameter_list|,
specifier|const
name|TType
modifier|&
name|param
parameter_list|)
function_decl|;
name|bool
name|SetFunctionCalled
parameter_list|(
name|TOperator
name|op
parameter_list|,
specifier|const
name|TType
modifier|&
name|param1
parameter_list|,
specifier|const
name|TType
modifier|&
name|param2
parameter_list|)
function_decl|;
comment|// Output function emulation definition.  This should be before any other
comment|// shader source.
name|void
name|OutputEmulatedFunctionDefinition
argument_list|(
name|TInfoSinkBase
operator|&
name|out
argument_list|,
name|bool
name|withPrecision
argument_list|)
decl|const
decl_stmt|;
name|void
name|MarkBuiltInFunctionsForEmulation
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
function_decl|;
name|void
name|Cleanup
parameter_list|()
function_decl|;
comment|// "name(" becomes "webgl_name_emu(".
specifier|static
name|TString
name|GetEmulatedFunctionName
parameter_list|(
specifier|const
name|TString
modifier|&
name|name
parameter_list|)
function_decl|;
name|private
label|:
comment|//
comment|// Built-in functions.
comment|//
enum|enum
name|TBuiltInFunction
block|{
name|TFunctionCos1
init|=
literal|0
block|,
comment|// float cos(float);
name|TFunctionCos2
block|,
comment|// vec2 cos(vec2);
name|TFunctionCos3
block|,
comment|// vec3 cos(vec3);
name|TFunctionCos4
block|,
comment|// vec4 cos(vec4);
name|TFunctionDistance1_1
block|,
comment|// float distance(float, float);
name|TFunctionDistance2_2
block|,
comment|// vec2 distance(vec2, vec2);
name|TFunctionDistance3_3
block|,
comment|// vec3 distance(vec3, vec3);
name|TFunctionDistance4_4
block|,
comment|// vec4 distance(vec4, vec4);
name|TFunctionDot1_1
block|,
comment|// float dot(float, float);
name|TFunctionDot2_2
block|,
comment|// vec2 dot(vec2, vec2);
name|TFunctionDot3_3
block|,
comment|// vec3 dot(vec3, vec3);
name|TFunctionDot4_4
block|,
comment|// vec4 dot(vec4, vec4);
name|TFunctionLength1
block|,
comment|// float length(float);
name|TFunctionLength2
block|,
comment|// float length(vec2);
name|TFunctionLength3
block|,
comment|// float length(vec3);
name|TFunctionLength4
block|,
comment|// float length(vec4);
name|TFunctionNormalize1
block|,
comment|// float normalize(float);
name|TFunctionNormalize2
block|,
comment|// vec2 normalize(vec2);
name|TFunctionNormalize3
block|,
comment|// vec3 normalize(vec3);
name|TFunctionNormalize4
block|,
comment|// vec4 normalize(vec4);
name|TFunctionReflect1_1
block|,
comment|// float reflect(float, float);
name|TFunctionReflect2_2
block|,
comment|// vec2 reflect(vec2, vec2);
name|TFunctionReflect3_3
block|,
comment|// vec3 reflect(vec3, vec3);
name|TFunctionReflect4_4
block|,
comment|// vec4 reflect(vec4, vec4);
name|TFunctionUnknown
block|}
enum|;
name|TBuiltInFunction
name|IdentifyFunction
parameter_list|(
name|TOperator
name|op
parameter_list|,
specifier|const
name|TType
modifier|&
name|param
parameter_list|)
function_decl|;
name|TBuiltInFunction
name|IdentifyFunction
parameter_list|(
name|TOperator
name|op
parameter_list|,
specifier|const
name|TType
modifier|&
name|param1
parameter_list|,
specifier|const
name|TType
modifier|&
name|param2
parameter_list|)
function_decl|;
name|bool
name|SetFunctionCalled
parameter_list|(
name|TBuiltInFunction
name|function
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|TBuiltInFunction
operator|>
name|mFunctions
expr_stmt|;
specifier|const
name|bool
modifier|*
name|mFunctionMask
decl_stmt|;
comment|// a boolean flag for each function.
specifier|const
name|char
modifier|*
modifier|*
name|mFunctionSource
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILIER_BUILT_IN_FUNCTION_EMULATOR_H_
end_comment
end_unit
