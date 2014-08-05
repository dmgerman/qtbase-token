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
name|_COMPILER_INTERFACE_INCLUDED_
end_ifndef
begin_define
DECL|macro|_COMPILER_INTERFACE_INCLUDED_
define|#
directive|define
name|_COMPILER_INTERFACE_INCLUDED_
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPONENT_BUILD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ANGLE_TRANSLATOR_STATIC
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_TRANSLATOR_IMPLEMENTATION
argument_list|)
end_if
begin_define
DECL|macro|COMPILER_EXPORT
define|#
directive|define
name|COMPILER_EXPORT
value|__declspec(dllexport)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|COMPILER_EXPORT
define|#
directive|define
name|COMPILER_EXPORT
value|__declspec(dllimport)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// defined(ANGLE_TRANSLATOR_IMPLEMENTATION)
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// defined(_WIN32) || defined(_WIN64)
end_comment
begin_define
DECL|macro|COMPILER_EXPORT
define|#
directive|define
name|COMPILER_EXPORT
value|__attribute__((visibility("default")))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// defined(COMPONENT_BUILD)&& !defined(ANGLE_TRANSLATOR_STATIC)
end_comment
begin_define
DECL|macro|COMPILER_EXPORT
define|#
directive|define
name|COMPILER_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"KHR/khrplatform.h"
end_include
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// This is the platform independent interface between an OGL driver
end_comment
begin_comment
comment|// and the shading language compiler.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|namespace
name|sh
block|{
comment|// GLenum alias
typedef|typedef
name|unsigned
name|int
name|GLenum
typedef|;
block|}
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// Version number for shader translation API.
comment|// It is incremented every time the API changes.
DECL|macro|ANGLE_SH_VERSION
define|#
directive|define
name|ANGLE_SH_VERSION
value|128
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_GLES2_SPEC
name|SH_GLES2_SPEC
init|=
literal|0x8B40
block|,
DECL|enumerator|SH_WEBGL_SPEC
name|SH_WEBGL_SPEC
init|=
literal|0x8B41
block|,
comment|// The CSS Shaders spec is a subset of the WebGL spec.
comment|//
comment|// In both CSS vertex and fragment shaders, ANGLE:
comment|// (1) Reserves the "css_" prefix.
comment|// (2) Renames the main function to css_main.
comment|// (3) Disables the gl_MaxDrawBuffers built-in.
comment|//
comment|// In CSS fragment shaders, ANGLE:
comment|// (1) Disables the gl_FragColor built-in.
comment|// (2) Disables the gl_FragData built-in.
comment|// (3) Enables the css_MixColor built-in.
comment|// (4) Enables the css_ColorMatrix built-in.
comment|//
comment|// After passing a CSS shader through ANGLE, the browser is expected to append
comment|// a new main function to it.
comment|// This new main function will call the css_main function.
comment|// It may also perform additional operations like varying assignment, texture
comment|// access, and gl_FragColor assignment in order to implement the CSS Shaders
comment|// blend modes.
comment|//
DECL|enumerator|SH_CSS_SHADERS_SPEC
name|SH_CSS_SHADERS_SPEC
init|=
literal|0x8B42
block|}
DECL|typedef|ShShaderSpec
name|ShShaderSpec
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_ESSL_OUTPUT
name|SH_ESSL_OUTPUT
init|=
literal|0x8B45
block|,
DECL|enumerator|SH_GLSL_OUTPUT
name|SH_GLSL_OUTPUT
init|=
literal|0x8B46
block|,
DECL|enumerator|SH_HLSL_OUTPUT
name|SH_HLSL_OUTPUT
init|=
literal|0x8B47
block|,
DECL|enumerator|SH_HLSL9_OUTPUT
name|SH_HLSL9_OUTPUT
init|=
literal|0x8B47
block|,
DECL|enumerator|SH_HLSL11_OUTPUT
name|SH_HLSL11_OUTPUT
init|=
literal|0x8B48
block|}
DECL|typedef|ShShaderOutput
name|ShShaderOutput
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_PRECISION_HIGHP
name|SH_PRECISION_HIGHP
init|=
literal|0x5001
block|,
DECL|enumerator|SH_PRECISION_MEDIUMP
name|SH_PRECISION_MEDIUMP
init|=
literal|0x5002
block|,
DECL|enumerator|SH_PRECISION_LOWP
name|SH_PRECISION_LOWP
init|=
literal|0x5003
block|,
DECL|enumerator|SH_PRECISION_UNDEFINED
name|SH_PRECISION_UNDEFINED
init|=
literal|0
block|}
DECL|typedef|ShPrecisionType
name|ShPrecisionType
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_INFO_LOG_LENGTH
name|SH_INFO_LOG_LENGTH
init|=
literal|0x8B84
block|,
DECL|enumerator|SH_OBJECT_CODE_LENGTH
name|SH_OBJECT_CODE_LENGTH
init|=
literal|0x8B88
block|,
comment|// GL_SHADER_SOURCE_LENGTH
DECL|enumerator|SH_ACTIVE_UNIFORMS
name|SH_ACTIVE_UNIFORMS
init|=
literal|0x8B86
block|,
DECL|enumerator|SH_ACTIVE_UNIFORM_MAX_LENGTH
name|SH_ACTIVE_UNIFORM_MAX_LENGTH
init|=
literal|0x8B87
block|,
DECL|enumerator|SH_ACTIVE_ATTRIBUTES
name|SH_ACTIVE_ATTRIBUTES
init|=
literal|0x8B89
block|,
DECL|enumerator|SH_ACTIVE_ATTRIBUTE_MAX_LENGTH
name|SH_ACTIVE_ATTRIBUTE_MAX_LENGTH
init|=
literal|0x8B8A
block|,
DECL|enumerator|SH_VARYINGS
name|SH_VARYINGS
init|=
literal|0x8BBB
block|,
DECL|enumerator|SH_VARYING_MAX_LENGTH
name|SH_VARYING_MAX_LENGTH
init|=
literal|0x8BBC
block|,
DECL|enumerator|SH_MAPPED_NAME_MAX_LENGTH
name|SH_MAPPED_NAME_MAX_LENGTH
init|=
literal|0x6000
block|,
DECL|enumerator|SH_NAME_MAX_LENGTH
name|SH_NAME_MAX_LENGTH
init|=
literal|0x6001
block|,
DECL|enumerator|SH_HASHED_NAME_MAX_LENGTH
name|SH_HASHED_NAME_MAX_LENGTH
init|=
literal|0x6002
block|,
DECL|enumerator|SH_HASHED_NAMES_COUNT
name|SH_HASHED_NAMES_COUNT
init|=
literal|0x6003
block|,
DECL|enumerator|SH_ACTIVE_UNIFORMS_ARRAY
name|SH_ACTIVE_UNIFORMS_ARRAY
init|=
literal|0x6004
block|,
DECL|enumerator|SH_SHADER_VERSION
name|SH_SHADER_VERSION
init|=
literal|0x6005
block|,
DECL|enumerator|SH_ACTIVE_INTERFACE_BLOCKS_ARRAY
name|SH_ACTIVE_INTERFACE_BLOCKS_ARRAY
init|=
literal|0x6006
block|,
DECL|enumerator|SH_ACTIVE_OUTPUT_VARIABLES_ARRAY
name|SH_ACTIVE_OUTPUT_VARIABLES_ARRAY
init|=
literal|0x6007
block|,
DECL|enumerator|SH_ACTIVE_ATTRIBUTES_ARRAY
name|SH_ACTIVE_ATTRIBUTES_ARRAY
init|=
literal|0x6008
block|,
DECL|enumerator|SH_ACTIVE_VARYINGS_ARRAY
name|SH_ACTIVE_VARYINGS_ARRAY
init|=
literal|0x6009
block|,
DECL|enumerator|SH_RESOURCES_STRING_LENGTH
name|SH_RESOURCES_STRING_LENGTH
init|=
literal|0x600A
block|,
DECL|enumerator|SH_OUTPUT_TYPE
name|SH_OUTPUT_TYPE
init|=
literal|0x600B
block|}
DECL|typedef|ShShaderInfo
name|ShShaderInfo
typedef|;
comment|// Compile options.
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_VALIDATE
name|SH_VALIDATE
init|=
literal|0
block|,
DECL|enumerator|SH_VALIDATE_LOOP_INDEXING
name|SH_VALIDATE_LOOP_INDEXING
init|=
literal|0x0001
block|,
DECL|enumerator|SH_INTERMEDIATE_TREE
name|SH_INTERMEDIATE_TREE
init|=
literal|0x0002
block|,
DECL|enumerator|SH_OBJECT_CODE
name|SH_OBJECT_CODE
init|=
literal|0x0004
block|,
DECL|enumerator|SH_VARIABLES
name|SH_VARIABLES
init|=
literal|0x0008
block|,
DECL|enumerator|SH_LINE_DIRECTIVES
name|SH_LINE_DIRECTIVES
init|=
literal|0x0010
block|,
DECL|enumerator|SH_SOURCE_PATH
name|SH_SOURCE_PATH
init|=
literal|0x0020
block|,
DECL|enumerator|SH_UNROLL_FOR_LOOP_WITH_INTEGER_INDEX
name|SH_UNROLL_FOR_LOOP_WITH_INTEGER_INDEX
init|=
literal|0x0040
block|,
comment|// If a sampler array index happens to be a loop index,
comment|//   1) if its type is integer, unroll the loop.
comment|//   2) if its type is float, fail the shader compile.
comment|// This is to work around a mac driver bug.
DECL|enumerator|SH_UNROLL_FOR_LOOP_WITH_SAMPLER_ARRAY_INDEX
name|SH_UNROLL_FOR_LOOP_WITH_SAMPLER_ARRAY_INDEX
init|=
literal|0x0080
block|,
comment|// This is needed only as a workaround for certain OpenGL driver bugs.
DECL|enumerator|SH_EMULATE_BUILT_IN_FUNCTIONS
name|SH_EMULATE_BUILT_IN_FUNCTIONS
init|=
literal|0x0100
block|,
comment|// This is an experimental flag to enforce restrictions that aim to prevent
comment|// timing attacks.
comment|// It generates compilation errors for shaders that could expose sensitive
comment|// texture information via the timing channel.
comment|// To use this flag, you must compile the shader under the WebGL spec
comment|// (using the SH_WEBGL_SPEC flag).
DECL|enumerator|SH_TIMING_RESTRICTIONS
name|SH_TIMING_RESTRICTIONS
init|=
literal|0x0200
block|,
comment|// This flag prints the dependency graph that is used to enforce timing
comment|// restrictions on fragment shaders.
comment|// This flag only has an effect if all of the following are true:
comment|// - The shader spec is SH_WEBGL_SPEC.
comment|// - The compile options contain the SH_TIMING_RESTRICTIONS flag.
comment|// - The shader type is GL_FRAGMENT_SHADER.
DECL|enumerator|SH_DEPENDENCY_GRAPH
name|SH_DEPENDENCY_GRAPH
init|=
literal|0x0400
block|,
comment|// Enforce the GLSL 1.017 Appendix A section 7 packing restrictions.
comment|// This flag only enforces (and can only enforce) the packing
comment|// restrictions for uniform variables in both vertex and fragment
comment|// shaders. ShCheckVariablesWithinPackingLimits() lets embedders
comment|// enforce the packing restrictions for varying variables during
comment|// program link time.
DECL|enumerator|SH_ENFORCE_PACKING_RESTRICTIONS
name|SH_ENFORCE_PACKING_RESTRICTIONS
init|=
literal|0x0800
block|,
comment|// This flag ensures all indirect (expression-based) array indexing
comment|// is clamped to the bounds of the array. This ensures, for example,
comment|// that you cannot read off the end of a uniform, whether an array
comment|// vec234, or mat234 type. The ShArrayIndexClampingStrategy enum,
comment|// specified in the ShBuiltInResources when constructing the
comment|// compiler, selects the strategy for the clamping implementation.
DECL|enumerator|SH_CLAMP_INDIRECT_ARRAY_BOUNDS
name|SH_CLAMP_INDIRECT_ARRAY_BOUNDS
init|=
literal|0x1000
block|,
comment|// This flag limits the complexity of an expression.
DECL|enumerator|SH_LIMIT_EXPRESSION_COMPLEXITY
name|SH_LIMIT_EXPRESSION_COMPLEXITY
init|=
literal|0x2000
block|,
comment|// This flag limits the depth of the call stack.
DECL|enumerator|SH_LIMIT_CALL_STACK_DEPTH
name|SH_LIMIT_CALL_STACK_DEPTH
init|=
literal|0x4000
block|,
comment|// This flag initializes gl_Position to vec4(0,0,0,0) at the
comment|// beginning of the vertex shader's main(), and has no effect in the
comment|// fragment shader. It is intended as a workaround for drivers which
comment|// incorrectly fail to link programs if gl_Position is not written.
DECL|enumerator|SH_INIT_GL_POSITION
name|SH_INIT_GL_POSITION
init|=
literal|0x8000
block|,
comment|// This flag replaces
comment|//   "a&& b" with "a ? b : false",
comment|//   "a || b" with "a ? true : b".
comment|// This is to work around a MacOSX driver bug that |b| is executed
comment|// independent of |a|'s value.
DECL|enumerator|SH_UNFOLD_SHORT_CIRCUIT
name|SH_UNFOLD_SHORT_CIRCUIT
init|=
literal|0x10000
block|,
comment|// This flag initializes varyings without static use in vertex shader
comment|// at the beginning of main(), and has no effects in the fragment shader.
comment|// It is intended as a workaround for drivers which incorrectly optimize
comment|// out such varyings and cause a link failure.
DECL|enumerator|SH_INIT_VARYINGS_WITHOUT_STATIC_USE
name|SH_INIT_VARYINGS_WITHOUT_STATIC_USE
init|=
literal|0x20000
block|,
comment|// This flag scalarizes vec/ivec/bvec/mat constructor args.
comment|// It is intended as a workaround for Linux/Mac driver bugs.
DECL|enumerator|SH_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS
name|SH_SCALARIZE_VEC_AND_MAT_CONSTRUCTOR_ARGS
init|=
literal|0x40000
block|, }
DECL|typedef|ShCompileOptions
name|ShCompileOptions
typedef|;
comment|// Defines alternate strategies for implementing array index clamping.
typedef|typedef
enum|enum
block|{
comment|// Use the clamp intrinsic for array index clamping.
DECL|enumerator|SH_CLAMP_WITH_CLAMP_INTRINSIC
name|SH_CLAMP_WITH_CLAMP_INTRINSIC
init|=
literal|1
block|,
comment|// Use a user-defined function for array index clamping.
DECL|enumerator|SH_CLAMP_WITH_USER_DEFINED_INT_CLAMP_FUNCTION
name|SH_CLAMP_WITH_USER_DEFINED_INT_CLAMP_FUNCTION
block|}
DECL|typedef|ShArrayIndexClampingStrategy
name|ShArrayIndexClampingStrategy
typedef|;
comment|//
comment|// Driver must call this first, once, before doing any other
comment|// compiler operations.
comment|// If the function succeeds, the return value is nonzero, else zero.
comment|//
name|COMPILER_EXPORT
name|int
name|ShInitialize
parameter_list|()
function_decl|;
comment|//
comment|// Driver should call this at shutdown.
comment|// If the function succeeds, the return value is nonzero, else zero.
comment|//
name|COMPILER_EXPORT
name|int
name|ShFinalize
parameter_list|()
function_decl|;
comment|// The 64 bits hash function. The first parameter is the input string; the
comment|// second parameter is the string length.
DECL|typedef|ShHashFunction64
typedef|typedef
name|khronos_uint64_t
function_decl|(
modifier|*
name|ShHashFunction64
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|//
comment|// Implementation dependent built-in resources (constants and extensions).
comment|// The names for these resources has been obtained by stripping gl_/GL_.
comment|//
typedef|typedef
struct|struct
block|{
comment|// Constants.
DECL|member|MaxVertexAttribs
name|int
name|MaxVertexAttribs
decl_stmt|;
DECL|member|MaxVertexUniformVectors
name|int
name|MaxVertexUniformVectors
decl_stmt|;
DECL|member|MaxVaryingVectors
name|int
name|MaxVaryingVectors
decl_stmt|;
DECL|member|MaxVertexTextureImageUnits
name|int
name|MaxVertexTextureImageUnits
decl_stmt|;
DECL|member|MaxCombinedTextureImageUnits
name|int
name|MaxCombinedTextureImageUnits
decl_stmt|;
DECL|member|MaxTextureImageUnits
name|int
name|MaxTextureImageUnits
decl_stmt|;
DECL|member|MaxFragmentUniformVectors
name|int
name|MaxFragmentUniformVectors
decl_stmt|;
DECL|member|MaxDrawBuffers
name|int
name|MaxDrawBuffers
decl_stmt|;
comment|// Extensions.
comment|// Set to 1 to enable the extension, else 0.
DECL|member|OES_standard_derivatives
name|int
name|OES_standard_derivatives
decl_stmt|;
DECL|member|OES_EGL_image_external
name|int
name|OES_EGL_image_external
decl_stmt|;
DECL|member|ARB_texture_rectangle
name|int
name|ARB_texture_rectangle
decl_stmt|;
DECL|member|EXT_draw_buffers
name|int
name|EXT_draw_buffers
decl_stmt|;
DECL|member|EXT_frag_depth
name|int
name|EXT_frag_depth
decl_stmt|;
DECL|member|EXT_shader_texture_lod
name|int
name|EXT_shader_texture_lod
decl_stmt|;
comment|// Set to 1 if highp precision is supported in the fragment language.
comment|// Default is 0.
DECL|member|FragmentPrecisionHigh
name|int
name|FragmentPrecisionHigh
decl_stmt|;
comment|// GLSL ES 3.0 constants.
DECL|member|MaxVertexOutputVectors
name|int
name|MaxVertexOutputVectors
decl_stmt|;
DECL|member|MaxFragmentInputVectors
name|int
name|MaxFragmentInputVectors
decl_stmt|;
DECL|member|MinProgramTexelOffset
name|int
name|MinProgramTexelOffset
decl_stmt|;
DECL|member|MaxProgramTexelOffset
name|int
name|MaxProgramTexelOffset
decl_stmt|;
comment|// Name Hashing.
comment|// Set a 64 bit hash function to enable user-defined name hashing.
comment|// Default is NULL.
DECL|member|HashFunction
name|ShHashFunction64
name|HashFunction
decl_stmt|;
comment|// Selects a strategy to use when implementing array index clamping.
comment|// Default is SH_CLAMP_WITH_CLAMP_INTRINSIC.
DECL|member|ArrayIndexClampingStrategy
name|ShArrayIndexClampingStrategy
name|ArrayIndexClampingStrategy
decl_stmt|;
comment|// The maximum complexity an expression can be.
DECL|member|MaxExpressionComplexity
name|int
name|MaxExpressionComplexity
decl_stmt|;
comment|// The maximum depth a call stack can be.
DECL|member|MaxCallStackDepth
name|int
name|MaxCallStackDepth
decl_stmt|;
block|}
DECL|typedef|ShBuiltInResources
name|ShBuiltInResources
typedef|;
comment|//
comment|// Initialize built-in resources with minimum expected values.
comment|//
name|COMPILER_EXPORT
name|void
name|ShInitBuiltInResources
parameter_list|(
name|ShBuiltInResources
modifier|*
name|resources
parameter_list|)
function_decl|;
comment|//
comment|// ShHandle held by but opaque to the driver.  It is allocated,
comment|// managed, and de-allocated by the compiler. Its contents
comment|// are defined by and used by the compiler.
comment|//
comment|// If handle creation fails, 0 will be returned.
comment|//
DECL|typedef|ShHandle
typedef|typedef
name|void
modifier|*
name|ShHandle
typedef|;
comment|//
comment|// Returns the a concatenated list of the items in ShBuiltInResources as a string.
comment|// This function must be updated whenever ShBuiltInResources is changed.
comment|// Parameters:
comment|// handle: Specifies the handle of the compiler to be used.
comment|// outStringLen: Specifies the size of the buffer, in number of characters. The size
comment|//               of the buffer required to store the resources string can be obtained
comment|//               by calling ShGetInfo with SH_RESOURCES_STRING_LENGTH.
comment|// outStr: Returns a null-terminated string representing all the built-in resources.
name|COMPILER_EXPORT
name|void
name|ShGetBuiltInResourcesString
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|size_t
name|outStringLen
parameter_list|,
name|char
modifier|*
name|outStr
parameter_list|)
function_decl|;
comment|//
comment|// Driver calls these to create and destroy compiler objects.
comment|//
comment|// Returns the handle of constructed compiler, null if the requested compiler is
comment|// not supported.
comment|// Parameters:
comment|// type: Specifies the type of shader - GL_FRAGMENT_SHADER or GL_VERTEX_SHADER.
comment|// spec: Specifies the language spec the compiler must conform to -
comment|//       SH_GLES2_SPEC or SH_WEBGL_SPEC.
comment|// output: Specifies the output code type - SH_ESSL_OUTPUT, SH_GLSL_OUTPUT,
comment|//         SH_HLSL9_OUTPUT or SH_HLSL11_OUTPUT.
comment|// resources: Specifies the built-in resources.
name|COMPILER_EXPORT
name|ShHandle
name|ShConstructCompiler
argument_list|(
name|sh
operator|::
name|GLenum
name|type
argument_list|,
name|ShShaderSpec
name|spec
argument_list|,
name|ShShaderOutput
name|output
argument_list|,
specifier|const
name|ShBuiltInResources
operator|*
name|resources
argument_list|)
decl_stmt|;
name|COMPILER_EXPORT
name|void
name|ShDestruct
parameter_list|(
name|ShHandle
name|handle
parameter_list|)
function_decl|;
comment|//
comment|// Compiles the given shader source.
comment|// If the function succeeds, the return value is nonzero, else zero.
comment|// Parameters:
comment|// handle: Specifies the handle of compiler to be used.
comment|// shaderStrings: Specifies an array of pointers to null-terminated strings
comment|//                containing the shader source code.
comment|// numStrings: Specifies the number of elements in shaderStrings array.
comment|// compileOptions: A mask containing the following parameters:
comment|// SH_VALIDATE: Validates shader to ensure that it conforms to the spec
comment|//              specified during compiler construction.
comment|// SH_VALIDATE_LOOP_INDEXING: Validates loop and indexing in the shader to
comment|//                            ensure that they do not exceed the minimum
comment|//                            functionality mandated in GLSL 1.0 spec,
comment|//                            Appendix A, Section 4 and 5.
comment|//                            There is no need to specify this parameter when
comment|//                            compiling for WebGL - it is implied.
comment|// SH_INTERMEDIATE_TREE: Writes intermediate tree to info log.
comment|//                       Can be queried by calling ShGetInfoLog().
comment|// SH_OBJECT_CODE: Translates intermediate tree to glsl or hlsl shader.
comment|//                 Can be queried by calling ShGetObjectCode().
comment|// SH_VARIABLES: Extracts attributes, uniforms, and varyings.
comment|//               Can be queried by calling ShGetVariableInfo().
comment|//
name|COMPILER_EXPORT
name|int
name|ShCompile
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|shaderStrings
index|[]
parameter_list|,
name|size_t
name|numStrings
parameter_list|,
name|int
name|compileOptions
parameter_list|)
function_decl|;
comment|// Returns a parameter from a compiled shader.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// pname: Specifies the parameter to query.
comment|// The following parameters are defined:
comment|// SH_INFO_LOG_LENGTH: the number of characters in the information log
comment|//                     including the null termination character.
comment|// SH_OBJECT_CODE_LENGTH: the number of characters in the object code
comment|//                        including the null termination character.
comment|// SH_ACTIVE_ATTRIBUTES: the number of active attribute variables.
comment|// SH_ACTIVE_ATTRIBUTE_MAX_LENGTH: the length of the longest active attribute
comment|//                                 variable name including the null
comment|//                                 termination character.
comment|// SH_ACTIVE_UNIFORMS: the number of active uniform variables.
comment|// SH_ACTIVE_UNIFORM_MAX_LENGTH: the length of the longest active uniform
comment|//                               variable name including the null
comment|//                               termination character.
comment|// SH_VARYINGS: the number of varying variables.
comment|// SH_VARYING_MAX_LENGTH: the length of the longest varying variable name
comment|//                        including the null termination character.
comment|// SH_MAPPED_NAME_MAX_LENGTH: the length of the mapped variable name including
comment|//                            the null termination character.
comment|// SH_NAME_MAX_LENGTH: the max length of a user-defined name including the
comment|//                     null termination character.
comment|// SH_HASHED_NAME_MAX_LENGTH: the max length of a hashed name including the
comment|//                            null termination character.
comment|// SH_HASHED_NAMES_COUNT: the number of hashed names from the latest compile.
comment|// SH_SHADER_VERSION: the version of the shader language
comment|// SH_OUTPUT_TYPE: the currently set language output type
comment|//
comment|// params: Requested parameter
name|COMPILER_EXPORT
name|void
name|ShGetInfo
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|ShShaderInfo
name|pname
parameter_list|,
name|size_t
modifier|*
name|params
parameter_list|)
function_decl|;
comment|// Returns nul-terminated information log for a compiled shader.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// infoLog: Specifies an array of characters that is used to return
comment|//          the information log. It is assumed that infoLog has enough memory
comment|//          to accomodate the information log. The size of the buffer required
comment|//          to store the returned information log can be obtained by calling
comment|//          ShGetInfo with SH_INFO_LOG_LENGTH.
name|COMPILER_EXPORT
name|void
name|ShGetInfoLog
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|char
modifier|*
name|infoLog
parameter_list|)
function_decl|;
comment|// Returns null-terminated object code for a compiled shader.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// infoLog: Specifies an array of characters that is used to return
comment|//          the object code. It is assumed that infoLog has enough memory to
comment|//          accomodate the object code. The size of the buffer required to
comment|//          store the returned object code can be obtained by calling
comment|//          ShGetInfo with SH_OBJECT_CODE_LENGTH.
name|COMPILER_EXPORT
name|void
name|ShGetObjectCode
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|char
modifier|*
name|objCode
parameter_list|)
function_decl|;
comment|// Returns information about a shader variable.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// variableType: Specifies the variable type; options include
comment|//               SH_ACTIVE_ATTRIBUTES, SH_ACTIVE_UNIFORMS, SH_VARYINGS.
comment|// index: Specifies the index of the variable to be queried.
comment|// length: Returns the number of characters actually written in the string
comment|//         indicated by name (excluding the null terminator) if a value other
comment|//         than NULL is passed.
comment|// size: Returns the size of the variable.
comment|// type: Returns the data type of the variable.
comment|// precision: Returns the precision of the variable.
comment|// staticUse: Returns 1 if the variable is accessed in a statement after
comment|//            pre-processing, whether or not run-time flow of control will
comment|//            cause that statement to be executed.
comment|//            Returns 0 otherwise.
comment|// name: Returns a null terminated string containing the name of the
comment|//       variable. It is assumed that name has enough memory to accormodate
comment|//       the variable name. The size of the buffer required to store the
comment|//       variable name can be obtained by calling ShGetInfo with
comment|//       SH_ACTIVE_ATTRIBUTE_MAX_LENGTH, SH_ACTIVE_UNIFORM_MAX_LENGTH,
comment|//       SH_VARYING_MAX_LENGTH.
comment|// mappedName: Returns a null terminated string containing the mapped name of
comment|//             the variable, It is assumed that mappedName has enough memory
comment|//             (SH_MAPPED_NAME_MAX_LENGTH), or NULL if don't care about the
comment|//             mapped name. If the name is not mapped, then name and mappedName
comment|//             are the same.
name|COMPILER_EXPORT
name|void
name|ShGetVariableInfo
argument_list|(
specifier|const
name|ShHandle
name|handle
argument_list|,
name|ShShaderInfo
name|variableType
argument_list|,
name|int
name|index
argument_list|,
name|size_t
operator|*
name|length
argument_list|,
name|int
operator|*
name|size
argument_list|,
name|sh
operator|::
name|GLenum
operator|*
name|type
argument_list|,
name|ShPrecisionType
operator|*
name|precision
argument_list|,
name|int
operator|*
name|staticUse
argument_list|,
name|char
operator|*
name|name
argument_list|,
name|char
operator|*
name|mappedName
argument_list|)
decl_stmt|;
comment|// Returns information about a name hashing entry from the latest compile.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// index: Specifies the index of the name hashing entry to be queried.
comment|// name: Returns a null terminated string containing the user defined name.
comment|//       It is assumed that name has enough memory to accomodate the name.
comment|//       The size of the buffer required to store the user defined name can
comment|//       be obtained by calling ShGetInfo with SH_NAME_MAX_LENGTH.
comment|// hashedName: Returns a null terminated string containing the hashed name of
comment|//             the uniform variable, It is assumed that hashedName has enough
comment|//             memory to accomodate the name. The size of the buffer required
comment|//             to store the name can be obtained by calling ShGetInfo with
comment|//             SH_HASHED_NAME_MAX_LENGTH.
name|COMPILER_EXPORT
name|void
name|ShGetNameHashingEntry
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|int
name|index
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|hashedName
parameter_list|)
function_decl|;
comment|// Returns a parameter from a compiled shader.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// pname: Specifies the parameter to query.
comment|// The following parameters are defined:
comment|// SH_ACTIVE_UNIFORMS_ARRAY: an STL vector of active uniforms. Valid only for
comment|//                           HLSL output.
comment|// params: Requested parameter
name|COMPILER_EXPORT
name|void
name|ShGetInfoPointer
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|ShShaderInfo
name|pname
parameter_list|,
name|void
modifier|*
modifier|*
name|params
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
block|{
DECL|member|type
name|sh
operator|::
name|GLenum
name|type
expr_stmt|;
DECL|member|size
name|int
name|size
decl_stmt|;
block|}
DECL|typedef|ShVariableInfo
name|ShVariableInfo
typedef|;
comment|// Returns 1 if the passed in variables pack in maxVectors following
comment|// the packing rules from the GLSL 1.017 spec, Appendix A, section 7.
comment|// Returns 0 otherwise. Also look at the SH_ENFORCE_PACKING_RESTRICTIONS
comment|// flag above.
comment|// Parameters:
comment|// maxVectors: the available rows of registers.
comment|// varInfoArray: an array of variable info (types and sizes).
comment|// varInfoArraySize: the size of the variable array.
name|COMPILER_EXPORT
name|int
name|ShCheckVariablesWithinPackingLimits
parameter_list|(
name|int
name|maxVectors
parameter_list|,
name|ShVariableInfo
modifier|*
name|varInfoArray
parameter_list|,
name|size_t
name|varInfoArraySize
parameter_list|)
function_decl|;
comment|// Gives the compiler-assigned register for an interface block.
comment|// The method writes the value to the output variable "indexOut".
comment|// Returns true if it found a valid interface block, false otherwise.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// interfaceBlockName: Specifies the interface block
comment|// indexOut: output variable that stores the assigned register
name|COMPILER_EXPORT
name|bool
name|ShGetInterfaceBlockRegister
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|interfaceBlockName
parameter_list|,
name|unsigned
name|int
modifier|*
name|indexOut
parameter_list|)
function_decl|;
comment|// Gives the compiler-assigned register for uniforms in the default
comment|// interface block.
comment|// The method writes the value to the output variable "indexOut".
comment|// Returns true if it found a valid default uniform, false otherwise.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// interfaceBlockName: Specifies the uniform
comment|// indexOut: output variable that stores the assigned register
name|COMPILER_EXPORT
name|bool
name|ShGetUniformRegister
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|uniformName
parameter_list|,
name|unsigned
name|int
modifier|*
name|indexOut
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _COMPILER_INTERFACE_INCLUDED_
end_comment
end_unit
