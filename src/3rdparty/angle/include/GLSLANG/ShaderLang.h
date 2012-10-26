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
name|COMPILER_IMPLEMENTATION
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
comment|// defined(COMPILER_IMPLEMENTATION)
end_comment
begin_else
else|#
directive|else
end_else
begin_comment
comment|// defined(WIN32)
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
comment|// defined(COMPONENT_BUILD)
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
comment|// It is incremented everytime the API changes.
DECL|macro|SH_VERSION
define|#
directive|define
name|SH_VERSION
value|107
comment|//
comment|// The names of the following enums have been derived by replacing GL prefix
comment|// with SH. For example, SH_INFO_LOG_LENGTH is equivalent to GL_INFO_LOG_LENGTH.
comment|// The enum values are also equal to the values of their GL counterpart. This
comment|// is done to make it easier for applications to use the shader library.
comment|//
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_FRAGMENT_SHADER
name|SH_FRAGMENT_SHADER
init|=
literal|0x8B30
block|,
DECL|enumerator|SH_VERTEX_SHADER
name|SH_VERTEX_SHADER
init|=
literal|0x8B31
block|}
DECL|typedef|ShShaderType
name|ShShaderType
typedef|;
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
block|}
DECL|typedef|ShShaderOutput
name|ShShaderOutput
typedef|;
typedef|typedef
enum|enum
block|{
DECL|enumerator|SH_NONE
name|SH_NONE
init|=
literal|0
block|,
DECL|enumerator|SH_INT
name|SH_INT
init|=
literal|0x1404
block|,
DECL|enumerator|SH_FLOAT
name|SH_FLOAT
init|=
literal|0x1406
block|,
DECL|enumerator|SH_FLOAT_VEC2
name|SH_FLOAT_VEC2
init|=
literal|0x8B50
block|,
DECL|enumerator|SH_FLOAT_VEC3
name|SH_FLOAT_VEC3
init|=
literal|0x8B51
block|,
DECL|enumerator|SH_FLOAT_VEC4
name|SH_FLOAT_VEC4
init|=
literal|0x8B52
block|,
DECL|enumerator|SH_INT_VEC2
name|SH_INT_VEC2
init|=
literal|0x8B53
block|,
DECL|enumerator|SH_INT_VEC3
name|SH_INT_VEC3
init|=
literal|0x8B54
block|,
DECL|enumerator|SH_INT_VEC4
name|SH_INT_VEC4
init|=
literal|0x8B55
block|,
DECL|enumerator|SH_BOOL
name|SH_BOOL
init|=
literal|0x8B56
block|,
DECL|enumerator|SH_BOOL_VEC2
name|SH_BOOL_VEC2
init|=
literal|0x8B57
block|,
DECL|enumerator|SH_BOOL_VEC3
name|SH_BOOL_VEC3
init|=
literal|0x8B58
block|,
DECL|enumerator|SH_BOOL_VEC4
name|SH_BOOL_VEC4
init|=
literal|0x8B59
block|,
DECL|enumerator|SH_FLOAT_MAT2
name|SH_FLOAT_MAT2
init|=
literal|0x8B5A
block|,
DECL|enumerator|SH_FLOAT_MAT3
name|SH_FLOAT_MAT3
init|=
literal|0x8B5B
block|,
DECL|enumerator|SH_FLOAT_MAT4
name|SH_FLOAT_MAT4
init|=
literal|0x8B5C
block|,
DECL|enumerator|SH_SAMPLER_2D
name|SH_SAMPLER_2D
init|=
literal|0x8B5E
block|,
DECL|enumerator|SH_SAMPLER_CUBE
name|SH_SAMPLER_CUBE
init|=
literal|0x8B60
block|,
DECL|enumerator|SH_SAMPLER_2D_RECT_ARB
name|SH_SAMPLER_2D_RECT_ARB
init|=
literal|0x8B63
block|,
DECL|enumerator|SH_SAMPLER_EXTERNAL_OES
name|SH_SAMPLER_EXTERNAL_OES
init|=
literal|0x8D66
block|}
DECL|typedef|ShDataType
name|ShDataType
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
DECL|enumerator|SH_MAPPED_NAME_MAX_LENGTH
name|SH_MAPPED_NAME_MAX_LENGTH
init|=
literal|0x8B8B
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
DECL|enumerator|SH_ATTRIBUTES_UNIFORMS
name|SH_ATTRIBUTES_UNIFORMS
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
DECL|enumerator|SH_MAP_LONG_VARIABLE_NAMES
name|SH_MAP_LONG_VARIABLE_NAMES
init|=
literal|0x0040
block|,
DECL|enumerator|SH_UNROLL_FOR_LOOP_WITH_INTEGER_INDEX
name|SH_UNROLL_FOR_LOOP_WITH_INTEGER_INDEX
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
comment|// - The shader type is SH_FRAGMENT_SHADER.
DECL|enumerator|SH_DEPENDENCY_GRAPH
name|SH_DEPENDENCY_GRAPH
init|=
literal|0x0400
block|,
comment|// Enforce the GLSL 1.017 Appendix A section 7 packing restrictions.
DECL|enumerator|SH_ENFORCE_PACKING_RESTRICTIONS
name|SH_ENFORCE_PACKING_RESTRICTIONS
init|=
literal|0x0800
block|, }
DECL|typedef|ShCompileOptions
name|ShCompileOptions
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
comment|// managed, and de-allocated by the compiler. It's contents
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
comment|// Driver calls these to create and destroy compiler objects.
comment|//
comment|// Returns the handle of constructed compiler, null if the requested compiler is
comment|// not supported.
comment|// Parameters:
comment|// type: Specifies the type of shader - SH_FRAGMENT_SHADER or SH_VERTEX_SHADER.
comment|// spec: Specifies the language spec the compiler must conform to -
comment|//       SH_GLES2_SPEC or SH_WEBGL_SPEC.
comment|// output: Specifies the output code type - SH_ESSL_OUTPUT, SH_GLSL_OUTPUT,
comment|//         or SH_HLSL_OUTPUT.
comment|// resources: Specifies the built-in resources.
name|COMPILER_EXPORT
name|ShHandle
name|ShConstructCompiler
parameter_list|(
name|ShShaderType
name|type
parameter_list|,
name|ShShaderSpec
name|spec
parameter_list|,
name|ShShaderOutput
name|output
parameter_list|,
specifier|const
name|ShBuiltInResources
modifier|*
name|resources
parameter_list|)
function_decl|;
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
comment|// SH_ATTRIBUTES_UNIFORMS: Extracts attributes and uniforms.
comment|//                         Can be queried by calling ShGetActiveAttrib() and
comment|//                         ShGetActiveUniform().
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
specifier|const
name|int
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
comment|// SH_MAPPED_NAME_MAX_LENGTH: the length of the mapped variable name including
comment|//                            the null termination character.
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
name|int
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
comment|// Returns information about an active attribute variable.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// index: Specifies the index of the attribute variable to be queried.
comment|// length: Returns the number of characters actually written in the string
comment|//         indicated by name (excluding the null terminator) if a value other
comment|//         than NULL is passed.
comment|// size: Returns the size of the attribute variable.
comment|// type: Returns the data type of the attribute variable.
comment|// name: Returns a null terminated string containing the name of the
comment|//       attribute variable. It is assumed that name has enough memory to
comment|//       accomodate the attribute variable name. The size of the buffer
comment|//       required to store the attribute variable name can be obtained by
comment|//       calling ShGetInfo with SH_ACTIVE_ATTRIBUTE_MAX_LENGTH.
comment|// mappedName: Returns a null terminated string containing the mapped name of
comment|//             the attribute variable, It is assumed that mappedName has enough
comment|//             memory (SH_MAPPED_NAME_MAX_LENGTH), or NULL if don't care
comment|//             about the mapped name. If the name is not mapped, then name and
comment|//             mappedName are the same.
name|COMPILER_EXPORT
name|void
name|ShGetActiveAttrib
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|int
name|index
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|ShDataType
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|mappedName
parameter_list|)
function_decl|;
comment|// Returns information about an active uniform variable.
comment|// Parameters:
comment|// handle: Specifies the compiler
comment|// index: Specifies the index of the uniform variable to be queried.
comment|// length: Returns the number of characters actually written in the string
comment|//         indicated by name (excluding the null terminator) if a value
comment|//         other than NULL is passed.
comment|// size: Returns the size of the uniform variable.
comment|// type: Returns the data type of the uniform variable.
comment|// name: Returns a null terminated string containing the name of the
comment|//       uniform variable. It is assumed that name has enough memory to
comment|//       accomodate the uniform variable name. The size of the buffer required
comment|//       to store the uniform variable name can be obtained by calling
comment|//       ShGetInfo with SH_ACTIVE_UNIFORMS_MAX_LENGTH.
comment|// mappedName: Returns a null terminated string containing the mapped name of
comment|//             the uniform variable, It is assumed that mappedName has enough
comment|//             memory (SH_MAPPED_NAME_MAX_LENGTH), or NULL if don't care
comment|//             about the mapped name. If the name is not mapped, then name and
comment|//             mappedName are the same.
name|COMPILER_EXPORT
name|void
name|ShGetActiveUniform
parameter_list|(
specifier|const
name|ShHandle
name|handle
parameter_list|,
name|int
name|index
parameter_list|,
name|int
modifier|*
name|length
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|ShDataType
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|mappedName
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
