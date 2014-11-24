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
file|<stddef.h>
end_include
begin_include
include|#
directive|include
file|"KHR/khrplatform.h"
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<vector>
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
begin_comment
comment|// Must be included after GLenum proxy typedef
end_comment
begin_comment
comment|// Note: make sure to increment ANGLE_SH_VERSION when changing ShaderVars.h
end_comment
begin_include
include|#
directive|include
file|"ShaderVars.h"
end_include
begin_comment
comment|// Version number for shader translation API.
end_comment
begin_comment
comment|// It is incremented every time the API changes.
end_comment
begin_define
DECL|macro|ANGLE_SH_VERSION
define|#
directive|define
name|ANGLE_SH_VERSION
value|132
end_define
begin_typedef
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
DECL|enumerator|SH_GLES3_SPEC
name|SH_GLES3_SPEC
init|=
literal|0x8B86
block|,
DECL|enumerator|SH_WEBGL2_SPEC
name|SH_WEBGL2_SPEC
init|=
literal|0x8B87
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
end_typedef
begin_typedef
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
end_typedef
begin_comment
comment|// Compile options.
end_comment
begin_typedef
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
block|,
comment|// This flag overwrites a struct name with a unique prefix.
comment|// It is intended as a workaround for drivers that do not handle
comment|// struct scopes correctly, including all Mac drivers and Linux AMD.
DECL|enumerator|SH_REGENERATE_STRUCT_NAMES
name|SH_REGENERATE_STRUCT_NAMES
init|=
literal|0x80000
block|, }
DECL|typedef|ShCompileOptions
name|ShCompileOptions
typedef|;
end_typedef
begin_comment
comment|// Defines alternate strategies for implementing array index clamping.
end_comment
begin_typedef
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
end_typedef
begin_comment
comment|//
end_comment
begin_comment
comment|// Driver must call this first, once, before doing any other
end_comment
begin_comment
comment|// compiler operations.
end_comment
begin_comment
comment|// If the function succeeds, the return value is true, else false.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|bool
name|ShInitialize
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_comment
comment|// Driver should call this at shutdown.
end_comment
begin_comment
comment|// If the function succeeds, the return value is true, else false.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|bool
name|ShFinalize
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// The 64 bits hash function. The first parameter is the input string; the
end_comment
begin_comment
comment|// second parameter is the string length.
end_comment
begin_typedef
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
end_typedef
begin_comment
comment|//
end_comment
begin_comment
comment|// Implementation dependent built-in resources (constants and extensions).
end_comment
begin_comment
comment|// The names for these resources has been obtained by stripping gl_/GL_.
end_comment
begin_comment
comment|//
end_comment
begin_typedef
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
comment|// Set to 1 to enable replacing GL_EXT_draw_buffers #extension directives
comment|// with GL_NV_draw_buffers in ESSL output. This flag can be used to emulate
comment|// EXT_draw_buffers by using it in combination with GLES3.0 glDrawBuffers
comment|// function. This applies to Tegra K1 devices.
DECL|member|NV_draw_buffers
name|int
name|NV_draw_buffers
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
end_typedef
begin_comment
comment|//
end_comment
begin_comment
comment|// Initialize built-in resources with minimum expected values.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// resources: The object to initialize. Will be comparable with memcmp.
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|void
name|ShInitBuiltInResources
parameter_list|(
name|ShBuiltInResources
modifier|*
name|resources
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_comment
comment|// ShHandle held by but opaque to the driver.  It is allocated,
end_comment
begin_comment
comment|// managed, and de-allocated by the compiler. Its contents
end_comment
begin_comment
comment|// are defined by and used by the compiler.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// If handle creation fails, 0 will be returned.
end_comment
begin_comment
comment|//
end_comment
begin_typedef
DECL|typedef|ShHandle
typedef|typedef
name|void
modifier|*
name|ShHandle
typedef|;
end_typedef
begin_comment
comment|//
end_comment
begin_comment
comment|// Returns the a concatenated list of the items in ShBuiltInResources as a
end_comment
begin_comment
comment|// null-terminated string.
end_comment
begin_comment
comment|// This function must be updated whenever ShBuiltInResources is changed.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the handle of the compiler to be used.
end_comment
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|string
operator|&
name|ShGetBuiltInResourcesString
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Driver calls these to create and destroy compiler objects.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Returns the handle of constructed compiler, null if the requested compiler is
end_comment
begin_comment
comment|// not supported.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// type: Specifies the type of shader - GL_FRAGMENT_SHADER or GL_VERTEX_SHADER.
end_comment
begin_comment
comment|// spec: Specifies the language spec the compiler must conform to -
end_comment
begin_comment
comment|//       SH_GLES2_SPEC or SH_WEBGL_SPEC.
end_comment
begin_comment
comment|// output: Specifies the output code type - SH_ESSL_OUTPUT, SH_GLSL_OUTPUT,
end_comment
begin_comment
comment|//         SH_HLSL9_OUTPUT or SH_HLSL11_OUTPUT.
end_comment
begin_comment
comment|// resources: Specifies the built-in resources.
end_comment
begin_decl_stmt
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
end_decl_stmt
begin_function_decl
name|COMPILER_EXPORT
name|void
name|ShDestruct
parameter_list|(
name|ShHandle
name|handle
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_comment
comment|// Compiles the given shader source.
end_comment
begin_comment
comment|// If the function succeeds, the return value is true, else false.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the handle of compiler to be used.
end_comment
begin_comment
comment|// shaderStrings: Specifies an array of pointers to null-terminated strings
end_comment
begin_comment
comment|//                containing the shader source code.
end_comment
begin_comment
comment|// numStrings: Specifies the number of elements in shaderStrings array.
end_comment
begin_comment
comment|// compileOptions: A mask containing the following parameters:
end_comment
begin_comment
comment|// SH_VALIDATE: Validates shader to ensure that it conforms to the spec
end_comment
begin_comment
comment|//              specified during compiler construction.
end_comment
begin_comment
comment|// SH_VALIDATE_LOOP_INDEXING: Validates loop and indexing in the shader to
end_comment
begin_comment
comment|//                            ensure that they do not exceed the minimum
end_comment
begin_comment
comment|//                            functionality mandated in GLSL 1.0 spec,
end_comment
begin_comment
comment|//                            Appendix A, Section 4 and 5.
end_comment
begin_comment
comment|//                            There is no need to specify this parameter when
end_comment
begin_comment
comment|//                            compiling for WebGL - it is implied.
end_comment
begin_comment
comment|// SH_INTERMEDIATE_TREE: Writes intermediate tree to info log.
end_comment
begin_comment
comment|//                       Can be queried by calling ShGetInfoLog().
end_comment
begin_comment
comment|// SH_OBJECT_CODE: Translates intermediate tree to glsl or hlsl shader.
end_comment
begin_comment
comment|//                 Can be queried by calling ShGetObjectCode().
end_comment
begin_comment
comment|// SH_VARIABLES: Extracts attributes, uniforms, and varyings.
end_comment
begin_comment
comment|//               Can be queried by calling ShGetVariableInfo().
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|bool
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
end_function_decl
begin_comment
comment|// Return the version of the shader language.
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|int
name|ShGetShaderVersion
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Return the currently set language output type.
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|ShShaderOutput
name|ShGetShaderOutputType
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// Returns null-terminated information log for a compiled shader.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|string
operator|&
name|ShGetInfoLog
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns null-terminated object code for a compiled shader.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|string
operator|&
name|ShGetObjectCode
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Returns a (original_name, hash) map containing all the user defined
end_comment
begin_comment
comment|// names in the shader, including variable names, function names, struct
end_comment
begin_comment
comment|// names, and struct field names.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_expr_stmt
DECL|member|string
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
operator|*
name|ShGetNameHashingMap
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Shader variable inspection.
end_comment
begin_comment
comment|// Returns a pointer to a list of variables of the designated type.
end_comment
begin_comment
comment|// (See ShaderVars.h for type definitions, included above)
end_comment
begin_comment
comment|// Returns NULL on failure.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Uniform
operator|>
operator|*
name|ShGetUniforms
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Varying
operator|>
operator|*
name|ShGetVaryings
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|*
name|ShGetAttributes
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|Attribute
operator|>
operator|*
name|ShGetOutputVariables
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|COMPILER_EXPORT
specifier|const
name|std
operator|::
name|vector
operator|<
name|sh
operator|::
name|InterfaceBlock
operator|>
operator|*
name|ShGetInterfaceBlocks
argument_list|(
argument|const ShHandle handle
argument_list|)
expr_stmt|;
end_expr_stmt
begin_typedef
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
end_typedef
begin_comment
comment|// Returns true if the passed in variables pack in maxVectors following
end_comment
begin_comment
comment|// the packing rules from the GLSL 1.017 spec, Appendix A, section 7.
end_comment
begin_comment
comment|// Returns false otherwise. Also look at the SH_ENFORCE_PACKING_RESTRICTIONS
end_comment
begin_comment
comment|// flag above.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// maxVectors: the available rows of registers.
end_comment
begin_comment
comment|// varInfoArray: an array of variable info (types and sizes).
end_comment
begin_comment
comment|// varInfoArraySize: the size of the variable array.
end_comment
begin_function_decl
name|COMPILER_EXPORT
name|bool
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
end_function_decl
begin_comment
comment|// Gives the compiler-assigned register for an interface block.
end_comment
begin_comment
comment|// The method writes the value to the output variable "indexOut".
end_comment
begin_comment
comment|// Returns true if it found a valid interface block, false otherwise.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_comment
comment|// interfaceBlockName: Specifies the interface block
end_comment
begin_comment
comment|// indexOut: output variable that stores the assigned register
end_comment
begin_decl_stmt
name|COMPILER_EXPORT
name|bool
name|ShGetInterfaceBlockRegister
argument_list|(
specifier|const
name|ShHandle
name|handle
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|interfaceBlockName
argument_list|,
name|unsigned
name|int
operator|*
name|indexOut
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Gives the compiler-assigned register for uniforms in the default
end_comment
begin_comment
comment|// interface block.
end_comment
begin_comment
comment|// The method writes the value to the output variable "indexOut".
end_comment
begin_comment
comment|// Returns true if it found a valid default uniform, false otherwise.
end_comment
begin_comment
comment|// Parameters:
end_comment
begin_comment
comment|// handle: Specifies the compiler
end_comment
begin_comment
comment|// interfaceBlockName: Specifies the uniform
end_comment
begin_comment
comment|// indexOut: output variable that stores the assigned register
end_comment
begin_decl_stmt
name|COMPILER_EXPORT
name|bool
name|ShGetUniformRegister
argument_list|(
specifier|const
name|ShHandle
name|handle
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|uniformName
argument_list|,
name|unsigned
name|int
operator|*
name|indexOut
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _COMPILER_INTERFACE_INCLUDED_
end_comment
end_unit
