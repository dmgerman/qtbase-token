begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
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
comment|// Shader.cpp: Implements the gl::Shader class and its  derived classes
end_comment
begin_comment
comment|// VertexShader and FragmentShader. Implements GL shader objects and related
end_comment
begin_comment
comment|// functionality. [OpenGL ES 2.0.24] section 2.10 page 24 and section 3.8 page 84.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/Shader.h"
end_include
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/utilities.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ResourceManager.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|member|mFragmentCompiler
name|void
modifier|*
name|Shader
operator|::
name|mFragmentCompiler
init|=
name|NULL
decl_stmt|;
DECL|member|mVertexCompiler
name|void
modifier|*
name|Shader
operator|::
name|mVertexCompiler
init|=
name|NULL
decl_stmt|;
DECL|function|Shader
name|Shader
operator|::
name|Shader
parameter_list|(
name|ResourceManager
modifier|*
name|manager
parameter_list|,
specifier|const
name|rx
operator|::
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|GLuint
name|handle
parameter_list|)
member_init_list|:
name|mHandle
argument_list|(
name|handle
argument_list|)
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mResourceManager
argument_list|(
name|manager
argument_list|)
block|{
name|mSource
operator|=
name|NULL
expr_stmt|;
name|mHlsl
operator|=
name|NULL
expr_stmt|;
name|mInfoLog
operator|=
name|NULL
expr_stmt|;
name|uncompile
argument_list|()
expr_stmt|;
name|initializeCompiler
argument_list|()
expr_stmt|;
name|mRefCount
operator|=
literal|0
expr_stmt|;
name|mDeleteStatus
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|~Shader
name|Shader
operator|::
name|~
name|Shader
parameter_list|()
block|{
operator|delete
index|[]
name|mSource
expr_stmt|;
operator|delete
index|[]
name|mHlsl
expr_stmt|;
operator|delete
index|[]
name|mInfoLog
expr_stmt|;
block|}
DECL|function|getHandle
name|GLuint
name|Shader
operator|::
name|getHandle
parameter_list|()
specifier|const
block|{
return|return
name|mHandle
return|;
block|}
DECL|function|setSource
name|void
name|Shader
operator|::
name|setSource
parameter_list|(
name|GLsizei
name|count
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|string
parameter_list|,
specifier|const
name|GLint
modifier|*
name|length
parameter_list|)
block|{
operator|delete
index|[]
name|mSource
expr_stmt|;
name|int
name|totalLength
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|length
operator|&&
name|length
index|[
name|i
index|]
operator|>=
literal|0
condition|)
block|{
name|totalLength
operator|+=
name|length
index|[
name|i
index|]
expr_stmt|;
block|}
else|else
block|{
name|totalLength
operator|+=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|string
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|mSource
operator|=
operator|new
name|char
index|[
name|totalLength
operator|+
literal|1
index|]
expr_stmt|;
name|char
modifier|*
name|code
init|=
name|mSource
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|int
name|stringLength
decl_stmt|;
if|if
condition|(
name|length
operator|&&
name|length
index|[
name|i
index|]
operator|>=
literal|0
condition|)
block|{
name|stringLength
operator|=
name|length
index|[
name|i
index|]
expr_stmt|;
block|}
else|else
block|{
name|stringLength
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|string
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|strncpy
argument_list|(
name|code
argument_list|,
name|string
index|[
name|i
index|]
argument_list|,
name|stringLength
argument_list|)
expr_stmt|;
name|code
operator|+=
name|stringLength
expr_stmt|;
block|}
name|mSource
index|[
name|totalLength
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
DECL|function|getInfoLogLength
name|int
name|Shader
operator|::
name|getInfoLogLength
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mInfoLog
condition|)
block|{
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|strlen
argument_list|(
name|mInfoLog
argument_list|)
operator|+
literal|1
return|;
block|}
block|}
DECL|function|getInfoLog
name|void
name|Shader
operator|::
name|getInfoLog
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|infoLog
parameter_list|)
block|{
name|int
name|index
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bufSize
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|mInfoLog
condition|)
block|{
name|index
operator|=
name|std
operator|::
name|min
argument_list|(
name|bufSize
operator|-
literal|1
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|mInfoLog
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|infoLog
argument_list|,
name|mInfoLog
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
name|infoLog
index|[
name|index
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|length
condition|)
block|{
operator|*
name|length
operator|=
name|index
expr_stmt|;
block|}
block|}
DECL|function|getSourceLength
name|int
name|Shader
operator|::
name|getSourceLength
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mSource
condition|)
block|{
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|strlen
argument_list|(
name|mSource
argument_list|)
operator|+
literal|1
return|;
block|}
block|}
DECL|function|getTranslatedSourceLength
name|int
name|Shader
operator|::
name|getTranslatedSourceLength
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mHlsl
condition|)
block|{
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|strlen
argument_list|(
name|mHlsl
argument_list|)
operator|+
literal|1
return|;
block|}
block|}
DECL|function|getSourceImpl
name|void
name|Shader
operator|::
name|getSourceImpl
parameter_list|(
name|char
modifier|*
name|source
parameter_list|,
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|int
name|index
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bufSize
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|source
condition|)
block|{
name|index
operator|=
name|std
operator|::
name|min
argument_list|(
name|bufSize
operator|-
literal|1
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|source
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|buffer
argument_list|,
name|source
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
name|buffer
index|[
name|index
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|length
condition|)
block|{
operator|*
name|length
operator|=
name|index
expr_stmt|;
block|}
block|}
DECL|function|getSource
name|void
name|Shader
operator|::
name|getSource
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|getSourceImpl
argument_list|(
name|mSource
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
DECL|function|getTranslatedSource
name|void
name|Shader
operator|::
name|getTranslatedSource
parameter_list|(
name|GLsizei
name|bufSize
parameter_list|,
name|GLsizei
modifier|*
name|length
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|getSourceImpl
argument_list|(
name|mHlsl
argument_list|,
name|bufSize
argument_list|,
name|length
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
DECL|function|getUniforms
specifier|const
name|sh
operator|::
name|ActiveUniforms
modifier|&
name|Shader
operator|::
name|getUniforms
parameter_list|()
block|{
return|return
name|mActiveUniforms
return|;
block|}
DECL|function|isCompiled
name|bool
name|Shader
operator|::
name|isCompiled
parameter_list|()
block|{
return|return
name|mHlsl
operator|!=
name|NULL
return|;
block|}
DECL|function|getHLSL
specifier|const
name|char
modifier|*
name|Shader
operator|::
name|getHLSL
parameter_list|()
block|{
return|return
name|mHlsl
return|;
block|}
DECL|function|addRef
name|void
name|Shader
operator|::
name|addRef
parameter_list|()
block|{
name|mRefCount
operator|++
expr_stmt|;
block|}
DECL|function|release
name|void
name|Shader
operator|::
name|release
parameter_list|()
block|{
name|mRefCount
operator|--
expr_stmt|;
if|if
condition|(
name|mRefCount
operator|==
literal|0
operator|&&
name|mDeleteStatus
condition|)
block|{
name|mResourceManager
operator|->
name|deleteShader
argument_list|(
name|mHandle
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getRefCount
name|unsigned
name|int
name|Shader
operator|::
name|getRefCount
parameter_list|()
specifier|const
block|{
return|return
name|mRefCount
return|;
block|}
DECL|function|isFlaggedForDeletion
name|bool
name|Shader
operator|::
name|isFlaggedForDeletion
parameter_list|()
specifier|const
block|{
return|return
name|mDeleteStatus
return|;
block|}
DECL|function|flagForDeletion
name|void
name|Shader
operator|::
name|flagForDeletion
parameter_list|()
block|{
name|mDeleteStatus
operator|=
literal|true
expr_stmt|;
block|}
comment|// Perform a one-time initialization of the shader compiler (or after being destructed by releaseCompiler)
DECL|function|initializeCompiler
name|void
name|Shader
operator|::
name|initializeCompiler
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mFragmentCompiler
condition|)
block|{
name|int
name|result
init|=
name|ShInitialize
argument_list|()
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
name|ShShaderOutput
name|hlslVersion
init|=
operator|(
name|mRenderer
operator|->
name|getMajorShaderModel
argument_list|()
operator|>=
literal|4
operator|)
condition|?
name|SH_HLSL11_OUTPUT
else|:
name|SH_HLSL9_OUTPUT
decl_stmt|;
name|ShBuiltInResources
name|resources
decl_stmt|;
name|ShInitBuiltInResources
argument_list|(
operator|&
name|resources
argument_list|)
expr_stmt|;
name|resources
operator|.
name|MaxVertexAttribs
operator|=
name|MAX_VERTEX_ATTRIBS
expr_stmt|;
name|resources
operator|.
name|MaxVertexUniformVectors
operator|=
name|mRenderer
operator|->
name|getMaxVertexUniformVectors
argument_list|()
expr_stmt|;
name|resources
operator|.
name|MaxVaryingVectors
operator|=
name|mRenderer
operator|->
name|getMaxVaryingVectors
argument_list|()
expr_stmt|;
name|resources
operator|.
name|MaxVertexTextureImageUnits
operator|=
name|mRenderer
operator|->
name|getMaxVertexTextureImageUnits
argument_list|()
expr_stmt|;
name|resources
operator|.
name|MaxCombinedTextureImageUnits
operator|=
name|mRenderer
operator|->
name|getMaxCombinedTextureImageUnits
argument_list|()
expr_stmt|;
name|resources
operator|.
name|MaxTextureImageUnits
operator|=
name|MAX_TEXTURE_IMAGE_UNITS
expr_stmt|;
name|resources
operator|.
name|MaxFragmentUniformVectors
operator|=
name|mRenderer
operator|->
name|getMaxFragmentUniformVectors
argument_list|()
expr_stmt|;
name|resources
operator|.
name|MaxDrawBuffers
operator|=
name|mRenderer
operator|->
name|getMaxRenderTargets
argument_list|()
expr_stmt|;
name|resources
operator|.
name|OES_standard_derivatives
operator|=
name|mRenderer
operator|->
name|getDerivativeInstructionSupport
argument_list|()
expr_stmt|;
name|resources
operator|.
name|EXT_draw_buffers
operator|=
name|mRenderer
operator|->
name|getMaxRenderTargets
argument_list|()
operator|>
literal|1
expr_stmt|;
comment|// resources.OES_EGL_image_external = mRenderer->getShareHandleSupport() ? 1 : 0; // TODO: commented out until the extension is actually supported.
name|resources
operator|.
name|FragmentPrecisionHigh
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports FP24 (s16e7) which corresponds to highp
name|resources
operator|.
name|EXT_frag_depth
operator|=
literal|1
expr_stmt|;
comment|// Shader Model 2+ always supports explicit depth output
name|mFragmentCompiler
operator|=
name|ShConstructCompiler
argument_list|(
name|SH_FRAGMENT_SHADER
argument_list|,
name|SH_GLES2_SPEC
argument_list|,
name|hlslVersion
argument_list|,
operator|&
name|resources
argument_list|)
expr_stmt|;
name|mVertexCompiler
operator|=
name|ShConstructCompiler
argument_list|(
name|SH_VERTEX_SHADER
argument_list|,
name|SH_GLES2_SPEC
argument_list|,
name|hlslVersion
argument_list|,
operator|&
name|resources
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|releaseCompiler
name|void
name|Shader
operator|::
name|releaseCompiler
parameter_list|()
block|{
name|ShDestruct
argument_list|(
name|mFragmentCompiler
argument_list|)
expr_stmt|;
name|ShDestruct
argument_list|(
name|mVertexCompiler
argument_list|)
expr_stmt|;
name|mFragmentCompiler
operator|=
name|NULL
expr_stmt|;
name|mVertexCompiler
operator|=
name|NULL
expr_stmt|;
name|ShFinalize
argument_list|()
expr_stmt|;
block|}
DECL|function|parseVaryings
name|void
name|Shader
operator|::
name|parseVaryings
parameter_list|()
block|{
if|if
condition|(
name|mHlsl
condition|)
block|{
specifier|const
name|char
modifier|*
name|input
init|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"// Varyings"
argument_list|)
operator|+
literal|12
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|char
name|varyingType
index|[
literal|256
index|]
decl_stmt|;
name|char
name|varyingName
index|[
literal|256
index|]
decl_stmt|;
name|int
name|matches
init|=
name|sscanf
argument_list|(
name|input
argument_list|,
literal|"static %255s %255s"
argument_list|,
name|varyingType
argument_list|,
name|varyingName
argument_list|)
decl_stmt|;
if|if
condition|(
name|matches
operator|!=
literal|2
condition|)
block|{
break|break;
block|}
name|char
modifier|*
name|array
init|=
name|strstr
argument_list|(
name|varyingName
argument_list|,
literal|"["
argument_list|)
decl_stmt|;
name|int
name|size
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|array
condition|)
block|{
name|size
operator|=
name|atoi
argument_list|(
name|array
operator|+
literal|1
argument_list|)
expr_stmt|;
operator|*
name|array
operator|=
literal|'\0'
expr_stmt|;
block|}
name|mVaryings
operator|.
name|push_back
argument_list|(
name|Varying
argument_list|(
name|parseType
argument_list|(
name|varyingType
argument_list|)
argument_list|,
name|varyingName
argument_list|,
name|size
argument_list|,
name|array
operator|!=
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
name|input
operator|=
name|strstr
argument_list|(
name|input
argument_list|,
literal|";"
argument_list|)
operator|+
literal|2
expr_stmt|;
block|}
name|mUsesMultipleRenderTargets
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_MRT"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesFragColor
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_FRAG_COLOR"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesFragData
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_FRAG_DATA"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesFragCoord
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_FRAG_COORD"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesFrontFacing
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_FRONT_FACING"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesPointSize
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_POINT_SIZE"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesPointCoord
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_POINT_COORD"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesDepthRange
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_DEPTH_RANGE"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesFragDepth
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"GL_USES_FRAG_DEPTH"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
name|mUsesDiscardRewriting
operator|=
name|strstr
argument_list|(
name|mHlsl
argument_list|,
literal|"ANGLE_USES_DISCARD_REWRITING"
argument_list|)
operator|!=
name|NULL
expr_stmt|;
block|}
block|}
DECL|function|resetVaryingsRegisterAssignment
name|void
name|Shader
operator|::
name|resetVaryingsRegisterAssignment
parameter_list|()
block|{
for|for
control|(
name|VaryingList
operator|::
name|iterator
name|var
init|=
name|mVaryings
operator|.
name|begin
argument_list|()
init|;
name|var
operator|!=
name|mVaryings
operator|.
name|end
argument_list|()
condition|;
name|var
operator|++
control|)
block|{
name|var
operator|->
name|reg
operator|=
operator|-
literal|1
expr_stmt|;
name|var
operator|->
name|col
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
comment|// initialize/clean up previous state
DECL|function|uncompile
name|void
name|Shader
operator|::
name|uncompile
parameter_list|()
block|{
comment|// set by compileToHLSL
operator|delete
index|[]
name|mHlsl
expr_stmt|;
name|mHlsl
operator|=
name|NULL
expr_stmt|;
operator|delete
index|[]
name|mInfoLog
expr_stmt|;
name|mInfoLog
operator|=
name|NULL
expr_stmt|;
comment|// set by parseVaryings
name|mVaryings
operator|.
name|clear
argument_list|()
expr_stmt|;
name|mUsesMultipleRenderTargets
operator|=
literal|false
expr_stmt|;
name|mUsesFragColor
operator|=
literal|false
expr_stmt|;
name|mUsesFragData
operator|=
literal|false
expr_stmt|;
name|mUsesFragCoord
operator|=
literal|false
expr_stmt|;
name|mUsesFrontFacing
operator|=
literal|false
expr_stmt|;
name|mUsesPointSize
operator|=
literal|false
expr_stmt|;
name|mUsesPointCoord
operator|=
literal|false
expr_stmt|;
name|mUsesDepthRange
operator|=
literal|false
expr_stmt|;
name|mUsesFragDepth
operator|=
literal|false
expr_stmt|;
name|mUsesDiscardRewriting
operator|=
literal|false
expr_stmt|;
name|mActiveUniforms
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|compileToHLSL
name|void
name|Shader
operator|::
name|compileToHLSL
parameter_list|(
name|void
modifier|*
name|compiler
parameter_list|)
block|{
comment|// ensure we don't pass a NULL source to the compiler
specifier|const
name|char
modifier|*
name|source
init|=
literal|"\0"
decl_stmt|;
if|if
condition|(
name|mSource
condition|)
block|{
name|source
operator|=
name|mSource
expr_stmt|;
block|}
comment|// ensure the compiler is loaded
name|initializeCompiler
argument_list|()
expr_stmt|;
name|int
name|compileOptions
init|=
name|SH_OBJECT_CODE
decl_stmt|;
name|std
operator|::
name|string
name|sourcePath
decl_stmt|;
if|if
condition|(
name|perfActive
argument_list|()
condition|)
block|{
name|sourcePath
operator|=
name|getTempPath
argument_list|()
expr_stmt|;
name|writeFile
argument_list|(
name|sourcePath
operator|.
name|c_str
argument_list|()
argument_list|,
name|source
argument_list|,
name|strlen
argument_list|(
name|source
argument_list|)
argument_list|)
expr_stmt|;
name|compileOptions
operator||=
name|SH_LINE_DIRECTIVES
expr_stmt|;
block|}
name|int
name|result
decl_stmt|;
if|if
condition|(
name|sourcePath
operator|.
name|empty
argument_list|()
condition|)
block|{
name|result
operator|=
name|ShCompile
argument_list|(
name|compiler
argument_list|,
operator|&
name|source
argument_list|,
literal|1
argument_list|,
name|compileOptions
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|char
modifier|*
name|sourceStrings
index|[
literal|2
index|]
init|=
block|{
name|sourcePath
operator|.
name|c_str
argument_list|()
block|,
name|source
block|}
decl_stmt|;
name|result
operator|=
name|ShCompile
argument_list|(
name|compiler
argument_list|,
name|sourceStrings
argument_list|,
literal|2
argument_list|,
name|compileOptions
operator||
name|SH_SOURCE_PATH
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|result
condition|)
block|{
name|size_t
name|objCodeLen
init|=
literal|0
decl_stmt|;
name|ShGetInfo
argument_list|(
name|compiler
argument_list|,
name|SH_OBJECT_CODE_LENGTH
argument_list|,
operator|&
name|objCodeLen
argument_list|)
expr_stmt|;
name|mHlsl
operator|=
operator|new
name|char
index|[
name|objCodeLen
index|]
expr_stmt|;
name|ShGetObjectCode
argument_list|(
name|compiler
argument_list|,
name|mHlsl
argument_list|)
expr_stmt|;
name|void
modifier|*
name|activeUniforms
decl_stmt|;
name|ShGetInfoPointer
argument_list|(
name|compiler
argument_list|,
name|SH_ACTIVE_UNIFORMS_ARRAY
argument_list|,
operator|&
name|activeUniforms
argument_list|)
expr_stmt|;
name|mActiveUniforms
operator|=
operator|*
operator|(
name|sh
operator|::
name|ActiveUniforms
operator|*
operator|)
name|activeUniforms
expr_stmt|;
block|}
else|else
block|{
name|size_t
name|infoLogLen
init|=
literal|0
decl_stmt|;
name|ShGetInfo
argument_list|(
name|compiler
argument_list|,
name|SH_INFO_LOG_LENGTH
argument_list|,
operator|&
name|infoLogLen
argument_list|)
expr_stmt|;
name|mInfoLog
operator|=
operator|new
name|char
index|[
name|infoLogLen
index|]
expr_stmt|;
name|ShGetInfoLog
argument_list|(
name|compiler
argument_list|,
name|mInfoLog
argument_list|)
expr_stmt|;
name|TRACE
argument_list|(
literal|"\n%s"
argument_list|,
name|mInfoLog
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|parseType
name|GLenum
name|Shader
operator|::
name|parseType
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
literal|"float"
condition|)
block|{
return|return
name|GL_FLOAT
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float2"
condition|)
block|{
return|return
name|GL_FLOAT_VEC2
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float3"
condition|)
block|{
return|return
name|GL_FLOAT_VEC3
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float4"
condition|)
block|{
return|return
name|GL_FLOAT_VEC4
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float2x2"
condition|)
block|{
return|return
name|GL_FLOAT_MAT2
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float3x3"
condition|)
block|{
return|return
name|GL_FLOAT_MAT3
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
literal|"float4x4"
condition|)
block|{
return|return
name|GL_FLOAT_MAT4
return|;
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|GL_NONE
return|;
block|}
comment|// true if varying x has a higher priority in packing than y
DECL|function|compareVarying
name|bool
name|Shader
operator|::
name|compareVarying
parameter_list|(
specifier|const
name|Varying
modifier|&
name|x
parameter_list|,
specifier|const
name|Varying
modifier|&
name|y
parameter_list|)
block|{
if|if
condition|(
name|x
operator|.
name|type
operator|==
name|y
operator|.
name|type
condition|)
block|{
return|return
name|x
operator|.
name|size
operator|>
name|y
operator|.
name|size
return|;
block|}
switch|switch
condition|(
name|x
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_MAT2
case|:
switch|switch
condition|(
name|y
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC4
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT
case|:
return|return
literal|true
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|GL_FLOAT_VEC4
case|:
switch|switch
condition|(
name|y
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC4
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT
case|:
return|return
literal|true
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|GL_FLOAT_MAT3
case|:
switch|switch
condition|(
name|y
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT
case|:
return|return
literal|true
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|GL_FLOAT_VEC3
case|:
switch|switch
condition|(
name|y
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC3
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT_VEC2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT
case|:
return|return
literal|true
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|GL_FLOAT_VEC2
case|:
switch|switch
condition|(
name|y
operator|.
name|type
condition|)
block|{
case|case
name|GL_FLOAT_MAT4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT2
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC4
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_MAT3
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC3
case|:
return|return
literal|false
return|;
case|case
name|GL_FLOAT_VEC2
case|:
return|return
literal|true
return|;
case|case
name|GL_FLOAT
case|:
return|return
literal|true
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|GL_FLOAT
case|:
return|return
literal|false
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|VertexShader
name|VertexShader
operator|::
name|VertexShader
parameter_list|(
name|ResourceManager
modifier|*
name|manager
parameter_list|,
specifier|const
name|rx
operator|::
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|GLuint
name|handle
parameter_list|)
member_init_list|:
name|Shader
argument_list|(
name|manager
argument_list|,
name|renderer
argument_list|,
name|handle
argument_list|)
block|{ }
DECL|function|~VertexShader
name|VertexShader
operator|::
name|~
name|VertexShader
parameter_list|()
block|{ }
DECL|function|getType
name|GLenum
name|VertexShader
operator|::
name|getType
parameter_list|()
block|{
return|return
name|GL_VERTEX_SHADER
return|;
block|}
DECL|function|uncompile
name|void
name|VertexShader
operator|::
name|uncompile
parameter_list|()
block|{
name|Shader
operator|::
name|uncompile
argument_list|()
expr_stmt|;
comment|// set by ParseAttributes
name|mAttributes
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|compile
name|void
name|VertexShader
operator|::
name|compile
parameter_list|()
block|{
name|uncompile
argument_list|()
expr_stmt|;
name|compileToHLSL
argument_list|(
name|mVertexCompiler
argument_list|)
expr_stmt|;
name|parseAttributes
argument_list|()
expr_stmt|;
name|parseVaryings
argument_list|()
expr_stmt|;
block|}
DECL|function|getSemanticIndex
name|int
name|VertexShader
operator|::
name|getSemanticIndex
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|attributeName
parameter_list|)
block|{
if|if
condition|(
operator|!
name|attributeName
operator|.
name|empty
argument_list|()
condition|)
block|{
name|int
name|semanticIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
name|AttributeArray
operator|::
name|iterator
name|attribute
init|=
name|mAttributes
operator|.
name|begin
argument_list|()
init|;
name|attribute
operator|!=
name|mAttributes
operator|.
name|end
argument_list|()
condition|;
name|attribute
operator|++
control|)
block|{
if|if
condition|(
name|attribute
operator|->
name|name
operator|==
name|attributeName
condition|)
block|{
return|return
name|semanticIndex
return|;
block|}
name|semanticIndex
operator|+=
name|VariableRowCount
argument_list|(
name|attribute
operator|->
name|type
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
DECL|function|parseAttributes
name|void
name|VertexShader
operator|::
name|parseAttributes
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|hlsl
init|=
name|getHLSL
argument_list|()
decl_stmt|;
if|if
condition|(
name|hlsl
condition|)
block|{
specifier|const
name|char
modifier|*
name|input
init|=
name|strstr
argument_list|(
name|hlsl
argument_list|,
literal|"// Attributes"
argument_list|)
operator|+
literal|14
decl_stmt|;
while|while
condition|(
literal|true
condition|)
block|{
name|char
name|attributeType
index|[
literal|256
index|]
decl_stmt|;
name|char
name|attributeName
index|[
literal|256
index|]
decl_stmt|;
name|int
name|matches
init|=
name|sscanf
argument_list|(
name|input
argument_list|,
literal|"static %255s _%255s"
argument_list|,
name|attributeType
argument_list|,
name|attributeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|matches
operator|!=
literal|2
condition|)
block|{
break|break;
block|}
name|mAttributes
operator|.
name|push_back
argument_list|(
name|Attribute
argument_list|(
name|parseType
argument_list|(
name|attributeType
argument_list|)
argument_list|,
name|attributeName
argument_list|)
argument_list|)
expr_stmt|;
name|input
operator|=
name|strstr
argument_list|(
name|input
argument_list|,
literal|";"
argument_list|)
operator|+
literal|2
expr_stmt|;
block|}
block|}
block|}
DECL|function|FragmentShader
name|FragmentShader
operator|::
name|FragmentShader
parameter_list|(
name|ResourceManager
modifier|*
name|manager
parameter_list|,
specifier|const
name|rx
operator|::
name|Renderer
modifier|*
name|renderer
parameter_list|,
name|GLuint
name|handle
parameter_list|)
member_init_list|:
name|Shader
argument_list|(
name|manager
argument_list|,
name|renderer
argument_list|,
name|handle
argument_list|)
block|{ }
DECL|function|~FragmentShader
name|FragmentShader
operator|::
name|~
name|FragmentShader
parameter_list|()
block|{ }
DECL|function|getType
name|GLenum
name|FragmentShader
operator|::
name|getType
parameter_list|()
block|{
return|return
name|GL_FRAGMENT_SHADER
return|;
block|}
DECL|function|compile
name|void
name|FragmentShader
operator|::
name|compile
parameter_list|()
block|{
name|uncompile
argument_list|()
expr_stmt|;
name|compileToHLSL
argument_list|(
name|mFragmentCompiler
argument_list|)
expr_stmt|;
name|parseVaryings
argument_list|()
expr_stmt|;
name|mVaryings
operator|.
name|sort
argument_list|(
name|compareVarying
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
end_unit
