begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2011 The ANGLE Project Authors. All rights reserved.
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
file|"compiler/BuiltInFunctionEmulator.h"
end_include
begin_include
include|#
directive|include
file|"compiler/SymbolTable.h"
end_include
begin_namespace
namespace|namespace
block|{
comment|// we use macros here instead of function definitions to work around more GLSL
comment|// compiler bugs, in particular on NVIDIA hardware on Mac OSX. Macros are
comment|// problematic because if the argument has side-effects they will be repeatedly
comment|// evaluated. This is unlikely to show up in real shaders, but is something to
comment|// consider.
DECL|member|kFunctionEmulationVertexSource
specifier|const
name|char
modifier|*
name|kFunctionEmulationVertexSource
index|[]
init|=
block|{
literal|"#error no emulation for cos(float)"
block|,
literal|"#error no emulation for cos(vec2)"
block|,
literal|"#error no emulation for cos(vec3)"
block|,
literal|"#error no emulation for cos(vec4)"
block|,
literal|"#define webgl_distance_emu(x, y) ((x)>= (y) ? (x) - (y) : (y) - (x))"
block|,
literal|"#error no emulation for distance(vec2, vec2)"
block|,
literal|"#error no emulation for distance(vec3, vec3)"
block|,
literal|"#error no emulation for distance(vec4, vec4)"
block|,
literal|"#define webgl_dot_emu(x, y) ((x) * (y))"
block|,
literal|"#error no emulation for dot(vec2, vec2)"
block|,
literal|"#error no emulation for dot(vec3, vec3)"
block|,
literal|"#error no emulation for dot(vec4, vec4)"
block|,
literal|"#define webgl_length_emu(x) ((x)>= 0.0 ? (x) : -(x))"
block|,
literal|"#error no emulation for length(vec2)"
block|,
literal|"#error no emulation for length(vec3)"
block|,
literal|"#error no emulation for length(vec4)"
block|,
literal|"#define webgl_normalize_emu(x) ((x) == 0.0 ? 0.0 : ((x)> 0.0 ? 1.0 : -1.0))"
block|,
literal|"#error no emulation for normalize(vec2)"
block|,
literal|"#error no emulation for normalize(vec3)"
block|,
literal|"#error no emulation for normalize(vec4)"
block|,
literal|"#define webgl_reflect_emu(I, N) ((I) - 2.0 * (N) * (I) * (N))"
block|,
literal|"#error no emulation for reflect(vec2, vec2)"
block|,
literal|"#error no emulation for reflect(vec3, vec3)"
block|,
literal|"#error no emulation for reflect(vec4, vec4)"
block|}
decl_stmt|;
DECL|member|kFunctionEmulationFragmentSource
specifier|const
name|char
modifier|*
name|kFunctionEmulationFragmentSource
index|[]
init|=
block|{
literal|"webgl_emu_precision float webgl_cos_emu(webgl_emu_precision float a) { return cos(a); }"
block|,
literal|"webgl_emu_precision vec2 webgl_cos_emu(webgl_emu_precision vec2 a) { return cos(a); }"
block|,
literal|"webgl_emu_precision vec3 webgl_cos_emu(webgl_emu_precision vec3 a) { return cos(a); }"
block|,
literal|"webgl_emu_precision vec4 webgl_cos_emu(webgl_emu_precision vec4 a) { return cos(a); }"
block|,
literal|"#define webgl_distance_emu(x, y) ((x)>= (y) ? (x) - (y) : (y) - (x))"
block|,
literal|"#error no emulation for distance(vec2, vec2)"
block|,
literal|"#error no emulation for distance(vec3, vec3)"
block|,
literal|"#error no emulation for distance(vec4, vec4)"
block|,
literal|"#define webgl_dot_emu(x, y) ((x) * (y))"
block|,
literal|"#error no emulation for dot(vec2, vec2)"
block|,
literal|"#error no emulation for dot(vec3, vec3)"
block|,
literal|"#error no emulation for dot(vec4, vec4)"
block|,
literal|"#define webgl_length_emu(x) ((x)>= 0.0 ? (x) : -(x))"
block|,
literal|"#error no emulation for length(vec2)"
block|,
literal|"#error no emulation for length(vec3)"
block|,
literal|"#error no emulation for length(vec4)"
block|,
literal|"#define webgl_normalize_emu(x) ((x) == 0.0 ? 0.0 : ((x)> 0.0 ? 1.0 : -1.0))"
block|,
literal|"#error no emulation for normalize(vec2)"
block|,
literal|"#error no emulation for normalize(vec3)"
block|,
literal|"#error no emulation for normalize(vec4)"
block|,
literal|"#define webgl_reflect_emu(I, N) ((I) - 2.0 * (N) * (I) * (N))"
block|,
literal|"#error no emulation for reflect(vec2, vec2)"
block|,
literal|"#error no emulation for reflect(vec3, vec3)"
block|,
literal|"#error no emulation for reflect(vec4, vec4)"
block|}
decl_stmt|;
DECL|member|kFunctionEmulationVertexMask
specifier|const
name|bool
name|kFunctionEmulationVertexMask
index|[]
init|=
block|{
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
comment|// Work around ATI driver bugs in Mac.
literal|false
block|,
comment|// TFunctionCos1
literal|false
block|,
comment|// TFunctionCos2
literal|false
block|,
comment|// TFunctionCos3
literal|false
block|,
comment|// TFunctionCos4
literal|true
block|,
comment|// TFunctionDistance1_1
literal|false
block|,
comment|// TFunctionDistance2_2
literal|false
block|,
comment|// TFunctionDistance3_3
literal|false
block|,
comment|// TFunctionDistance4_4
literal|true
block|,
comment|// TFunctionDot1_1
literal|false
block|,
comment|// TFunctionDot2_2
literal|false
block|,
comment|// TFunctionDot3_3
literal|false
block|,
comment|// TFunctionDot4_4
literal|true
block|,
comment|// TFunctionLength1
literal|false
block|,
comment|// TFunctionLength2
literal|false
block|,
comment|// TFunctionLength3
literal|false
block|,
comment|// TFunctionLength4
literal|true
block|,
comment|// TFunctionNormalize1
literal|false
block|,
comment|// TFunctionNormalize2
literal|false
block|,
comment|// TFunctionNormalize3
literal|false
block|,
comment|// TFunctionNormalize4
literal|true
block|,
comment|// TFunctionReflect1_1
literal|false
block|,
comment|// TFunctionReflect2_2
literal|false
block|,
comment|// TFunctionReflect3_3
literal|false
block|,
comment|// TFunctionReflect4_4
else|#
directive|else
comment|// Work around D3D driver bug in Win.
literal|false
block|,
comment|// TFunctionCos1
literal|false
block|,
comment|// TFunctionCos2
literal|false
block|,
comment|// TFunctionCos3
literal|false
block|,
comment|// TFunctionCos4
literal|false
block|,
comment|// TFunctionDistance1_1
literal|false
block|,
comment|// TFunctionDistance2_2
literal|false
block|,
comment|// TFunctionDistance3_3
literal|false
block|,
comment|// TFunctionDistance4_4
literal|false
block|,
comment|// TFunctionDot1_1
literal|false
block|,
comment|// TFunctionDot2_2
literal|false
block|,
comment|// TFunctionDot3_3
literal|false
block|,
comment|// TFunctionDot4_4
literal|false
block|,
comment|// TFunctionLength1
literal|false
block|,
comment|// TFunctionLength2
literal|false
block|,
comment|// TFunctionLength3
literal|false
block|,
comment|// TFunctionLength4
literal|false
block|,
comment|// TFunctionNormalize1
literal|false
block|,
comment|// TFunctionNormalize2
literal|false
block|,
comment|// TFunctionNormalize3
literal|false
block|,
comment|// TFunctionNormalize4
literal|false
block|,
comment|// TFunctionReflect1_1
literal|false
block|,
comment|// TFunctionReflect2_2
literal|false
block|,
comment|// TFunctionReflect3_3
literal|false
block|,
comment|// TFunctionReflect4_4
endif|#
directive|endif
literal|false
comment|// TFunctionUnknown
block|}
decl_stmt|;
DECL|member|kFunctionEmulationFragmentMask
specifier|const
name|bool
name|kFunctionEmulationFragmentMask
index|[]
init|=
block|{
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
comment|// Work around ATI driver bugs in Mac.
literal|true
block|,
comment|// TFunctionCos1
literal|true
block|,
comment|// TFunctionCos2
literal|true
block|,
comment|// TFunctionCos3
literal|true
block|,
comment|// TFunctionCos4
literal|true
block|,
comment|// TFunctionDistance1_1
literal|false
block|,
comment|// TFunctionDistance2_2
literal|false
block|,
comment|// TFunctionDistance3_3
literal|false
block|,
comment|// TFunctionDistance4_4
literal|true
block|,
comment|// TFunctionDot1_1
literal|false
block|,
comment|// TFunctionDot2_2
literal|false
block|,
comment|// TFunctionDot3_3
literal|false
block|,
comment|// TFunctionDot4_4
literal|true
block|,
comment|// TFunctionLength1
literal|false
block|,
comment|// TFunctionLength2
literal|false
block|,
comment|// TFunctionLength3
literal|false
block|,
comment|// TFunctionLength4
literal|true
block|,
comment|// TFunctionNormalize1
literal|false
block|,
comment|// TFunctionNormalize2
literal|false
block|,
comment|// TFunctionNormalize3
literal|false
block|,
comment|// TFunctionNormalize4
literal|true
block|,
comment|// TFunctionReflect1_1
literal|false
block|,
comment|// TFunctionReflect2_2
literal|false
block|,
comment|// TFunctionReflect3_3
literal|false
block|,
comment|// TFunctionReflect4_4
else|#
directive|else
comment|// Work around D3D driver bug in Win.
literal|false
block|,
comment|// TFunctionCos1
literal|false
block|,
comment|// TFunctionCos2
literal|false
block|,
comment|// TFunctionCos3
literal|false
block|,
comment|// TFunctionCos4
literal|false
block|,
comment|// TFunctionDistance1_1
literal|false
block|,
comment|// TFunctionDistance2_2
literal|false
block|,
comment|// TFunctionDistance3_3
literal|false
block|,
comment|// TFunctionDistance4_4
literal|false
block|,
comment|// TFunctionDot1_1
literal|false
block|,
comment|// TFunctionDot2_2
literal|false
block|,
comment|// TFunctionDot3_3
literal|false
block|,
comment|// TFunctionDot4_4
literal|false
block|,
comment|// TFunctionLength1
literal|false
block|,
comment|// TFunctionLength2
literal|false
block|,
comment|// TFunctionLength3
literal|false
block|,
comment|// TFunctionLength4
literal|false
block|,
comment|// TFunctionNormalize1
literal|false
block|,
comment|// TFunctionNormalize2
literal|false
block|,
comment|// TFunctionNormalize3
literal|false
block|,
comment|// TFunctionNormalize4
literal|false
block|,
comment|// TFunctionReflect1_1
literal|false
block|,
comment|// TFunctionReflect2_2
literal|false
block|,
comment|// TFunctionReflect3_3
literal|false
block|,
comment|// TFunctionReflect4_4
endif|#
directive|endif
literal|false
comment|// TFunctionUnknown
block|}
decl_stmt|;
DECL|class|BuiltInFunctionEmulationMarker
class|class
name|BuiltInFunctionEmulationMarker
super|:
specifier|public
name|TIntermTraverser
block|{
public|public:
DECL|function|BuiltInFunctionEmulationMarker
name|BuiltInFunctionEmulationMarker
parameter_list|(
name|BuiltInFunctionEmulator
modifier|&
name|emulator
parameter_list|)
member_init_list|:
name|mEmulator
argument_list|(
name|emulator
argument_list|)
block|{     }
DECL|function|visitUnary
specifier|virtual
name|bool
name|visitUnary
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermUnary
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
name|bool
name|needToEmulate
init|=
name|mEmulator
operator|.
name|SetFunctionCalled
argument_list|(
name|node
operator|->
name|getOp
argument_list|()
argument_list|,
name|node
operator|->
name|getOperand
argument_list|()
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|needToEmulate
condition|)
name|node
operator|->
name|setUseEmulatedFunction
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|visitAggregate
specifier|virtual
name|bool
name|visitAggregate
parameter_list|(
name|Visit
name|visit
parameter_list|,
name|TIntermAggregate
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|visit
operator|==
name|PreVisit
condition|)
block|{
comment|// Here we handle all the built-in functions instead of the ones we
comment|// currently identified as problematic.
switch|switch
condition|(
name|node
operator|->
name|getOp
argument_list|()
condition|)
block|{
case|case
name|EOpLessThan
case|:
case|case
name|EOpGreaterThan
case|:
case|case
name|EOpLessThanEqual
case|:
case|case
name|EOpGreaterThanEqual
case|:
case|case
name|EOpVectorEqual
case|:
case|case
name|EOpVectorNotEqual
case|:
case|case
name|EOpMod
case|:
case|case
name|EOpPow
case|:
case|case
name|EOpAtan
case|:
case|case
name|EOpMin
case|:
case|case
name|EOpMax
case|:
case|case
name|EOpClamp
case|:
case|case
name|EOpMix
case|:
case|case
name|EOpStep
case|:
case|case
name|EOpSmoothStep
case|:
case|case
name|EOpDistance
case|:
case|case
name|EOpDot
case|:
case|case
name|EOpCross
case|:
case|case
name|EOpFaceForward
case|:
case|case
name|EOpReflect
case|:
case|case
name|EOpRefract
case|:
case|case
name|EOpMul
case|:
break|break;
default|default:
return|return
literal|true
return|;
block|}
empty_stmt|;
specifier|const
name|TIntermSequence
modifier|&
name|sequence
init|=
name|node
operator|->
name|getSequence
argument_list|()
decl_stmt|;
comment|// Right now we only handle built-in functions with two parameters.
if|if
condition|(
name|sequence
operator|.
name|size
argument_list|()
operator|!=
literal|2
condition|)
return|return
literal|true
return|;
name|TIntermTyped
modifier|*
name|param1
init|=
name|sequence
index|[
literal|0
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
name|TIntermTyped
modifier|*
name|param2
init|=
name|sequence
index|[
literal|1
index|]
operator|->
name|getAsTyped
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|param1
operator|||
operator|!
name|param2
condition|)
return|return
literal|true
return|;
name|bool
name|needToEmulate
init|=
name|mEmulator
operator|.
name|SetFunctionCalled
argument_list|(
name|node
operator|->
name|getOp
argument_list|()
argument_list|,
name|param1
operator|->
name|getType
argument_list|()
argument_list|,
name|param2
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|needToEmulate
condition|)
name|node
operator|->
name|setUseEmulatedFunction
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
private|private:
DECL|member|mEmulator
name|BuiltInFunctionEmulator
modifier|&
name|mEmulator
decl_stmt|;
block|}
class|;
block|}
end_namespace
begin_comment
comment|// anonymous namepsace
end_comment
begin_constructor
DECL|function|BuiltInFunctionEmulator
name|BuiltInFunctionEmulator
operator|::
name|BuiltInFunctionEmulator
parameter_list|(
name|ShShaderType
name|shaderType
parameter_list|)
block|{
if|if
condition|(
name|shaderType
operator|==
name|SH_FRAGMENT_SHADER
condition|)
block|{
name|mFunctionMask
operator|=
name|kFunctionEmulationFragmentMask
expr_stmt|;
name|mFunctionSource
operator|=
name|kFunctionEmulationFragmentSource
expr_stmt|;
block|}
else|else
block|{
name|mFunctionMask
operator|=
name|kFunctionEmulationVertexMask
expr_stmt|;
name|mFunctionSource
operator|=
name|kFunctionEmulationVertexSource
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|SetFunctionCalled
name|bool
name|BuiltInFunctionEmulator
operator|::
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
block|{
name|TBuiltInFunction
name|function
init|=
name|IdentifyFunction
argument_list|(
name|op
argument_list|,
name|param
argument_list|)
decl_stmt|;
return|return
name|SetFunctionCalled
argument_list|(
name|function
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|SetFunctionCalled
name|bool
name|BuiltInFunctionEmulator
operator|::
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
block|{
name|TBuiltInFunction
name|function
init|=
name|IdentifyFunction
argument_list|(
name|op
argument_list|,
name|param1
argument_list|,
name|param2
argument_list|)
decl_stmt|;
return|return
name|SetFunctionCalled
argument_list|(
name|function
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|SetFunctionCalled
name|bool
name|BuiltInFunctionEmulator
operator|::
name|SetFunctionCalled
parameter_list|(
name|BuiltInFunctionEmulator
operator|::
name|TBuiltInFunction
name|function
parameter_list|)
block|{
if|if
condition|(
name|function
operator|==
name|TFunctionUnknown
operator|||
name|mFunctionMask
index|[
name|function
index|]
operator|==
literal|false
condition|)
return|return
literal|false
return|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFunctions
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|mFunctions
index|[
name|i
index|]
operator|==
name|function
condition|)
return|return
literal|true
return|;
block|}
name|mFunctions
operator|.
name|push_back
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|OutputEmulatedFunctionDefinition
name|void
name|BuiltInFunctionEmulator
operator|::
name|OutputEmulatedFunctionDefinition
parameter_list|(
name|TInfoSinkBase
modifier|&
name|out
parameter_list|,
name|bool
name|withPrecision
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mFunctions
operator|.
name|size
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|out
operator|<<
literal|"// BEGIN: Generated code for built-in function emulation\n\n"
expr_stmt|;
if|if
condition|(
name|withPrecision
condition|)
block|{
name|out
operator|<<
literal|"#if defined(GL_FRAGMENT_PRECISION_HIGH)\n"
operator|<<
literal|"#define webgl_emu_precision highp\n"
operator|<<
literal|"#else\n"
operator|<<
literal|"#define webgl_emu_precision mediump\n"
operator|<<
literal|"#endif\n\n"
expr_stmt|;
block|}
else|else
block|{
name|out
operator|<<
literal|"#define webgl_emu_precision\n\n"
expr_stmt|;
block|}
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mFunctions
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|out
operator|<<
name|mFunctionSource
index|[
name|mFunctions
index|[
name|i
index|]
index|]
operator|<<
literal|"\n\n"
expr_stmt|;
block|}
name|out
operator|<<
literal|"// END: Generated code for built-in function emulation\n\n"
expr_stmt|;
block|}
end_function
begin_function
name|BuiltInFunctionEmulator
operator|::
name|TBuiltInFunction
DECL|function|IdentifyFunction
name|BuiltInFunctionEmulator
operator|::
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
block|{
if|if
condition|(
name|param
operator|.
name|getNominalSize
argument_list|()
operator|>
literal|4
condition|)
return|return
name|TFunctionUnknown
return|;
name|unsigned
name|int
name|function
init|=
name|TFunctionUnknown
decl_stmt|;
switch|switch
condition|(
name|op
condition|)
block|{
case|case
name|EOpCos
case|:
name|function
operator|=
name|TFunctionCos1
expr_stmt|;
break|break;
case|case
name|EOpLength
case|:
name|function
operator|=
name|TFunctionLength1
expr_stmt|;
break|break;
case|case
name|EOpNormalize
case|:
name|function
operator|=
name|TFunctionNormalize1
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|function
operator|==
name|TFunctionUnknown
condition|)
return|return
name|TFunctionUnknown
return|;
if|if
condition|(
name|param
operator|.
name|isVector
argument_list|()
condition|)
name|function
operator|+=
name|param
operator|.
name|getNominalSize
argument_list|()
operator|-
literal|1
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|TBuiltInFunction
argument_list|>
argument_list|(
name|function
argument_list|)
return|;
block|}
end_function
begin_function
name|BuiltInFunctionEmulator
operator|::
name|TBuiltInFunction
DECL|function|IdentifyFunction
name|BuiltInFunctionEmulator
operator|::
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
block|{
comment|// Right now for all the emulated functions with two parameters, the two
comment|// parameters have the same type.
if|if
condition|(
name|param1
operator|.
name|isVector
argument_list|()
operator|!=
name|param2
operator|.
name|isVector
argument_list|()
operator|||
name|param1
operator|.
name|getNominalSize
argument_list|()
operator|!=
name|param2
operator|.
name|getNominalSize
argument_list|()
operator|||
name|param1
operator|.
name|getNominalSize
argument_list|()
operator|>
literal|4
condition|)
return|return
name|TFunctionUnknown
return|;
name|unsigned
name|int
name|function
init|=
name|TFunctionUnknown
decl_stmt|;
switch|switch
condition|(
name|op
condition|)
block|{
case|case
name|EOpDistance
case|:
name|function
operator|=
name|TFunctionDistance1_1
expr_stmt|;
break|break;
case|case
name|EOpDot
case|:
name|function
operator|=
name|TFunctionDot1_1
expr_stmt|;
break|break;
case|case
name|EOpReflect
case|:
name|function
operator|=
name|TFunctionReflect1_1
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|function
operator|==
name|TFunctionUnknown
condition|)
return|return
name|TFunctionUnknown
return|;
if|if
condition|(
name|param1
operator|.
name|isVector
argument_list|()
condition|)
name|function
operator|+=
name|param1
operator|.
name|getNominalSize
argument_list|()
operator|-
literal|1
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|TBuiltInFunction
argument_list|>
argument_list|(
name|function
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|MarkBuiltInFunctionsForEmulation
name|void
name|BuiltInFunctionEmulator
operator|::
name|MarkBuiltInFunctionsForEmulation
parameter_list|(
name|TIntermNode
modifier|*
name|root
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|root
argument_list|)
expr_stmt|;
name|BuiltInFunctionEmulationMarker
name|marker
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|root
operator|->
name|traverse
argument_list|(
operator|&
name|marker
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|Cleanup
name|void
name|BuiltInFunctionEmulator
operator|::
name|Cleanup
parameter_list|()
block|{
name|mFunctions
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//static
end_comment
begin_function
DECL|function|GetEmulatedFunctionName
name|TString
name|BuiltInFunctionEmulator
operator|::
name|GetEmulatedFunctionName
parameter_list|(
specifier|const
name|TString
modifier|&
name|name
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|name
index|[
name|name
operator|.
name|length
argument_list|()
operator|-
literal|1
index|]
operator|==
literal|'('
argument_list|)
expr_stmt|;
return|return
literal|"webgl_"
operator|+
name|name
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|name
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
operator|+
literal|"_emu("
return|;
block|}
end_function
end_unit
