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
begin_comment
comment|// Context.h: Defines the gl::Context class, managing all GL state and performing
end_comment
begin_comment
comment|// rendering operations. It is the GLES2 specific implementation of EGLContext.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_CONTEXT_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_CONTEXT_H_
define|#
directive|define
name|LIBGLESV2_CONTEXT_H_
end_define
begin_define
DECL|macro|GL_APICALL
define|#
directive|define
name|GL_APICALL
end_define
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_define
DECL|macro|EGLAPI
define|#
directive|define
name|EGLAPI
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef
begin_include
include|#
directive|include
file|<hash_map>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<unordered_map>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"common/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/HandleAllocator.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Constants.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Display
decl_stmt|;
name|class
name|Surface
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Shader
decl_stmt|;
name|class
name|Program
decl_stmt|;
name|class
name|ProgramBinary
decl_stmt|;
name|class
name|Texture
decl_stmt|;
name|class
name|Texture2D
decl_stmt|;
name|class
name|TextureCubeMap
decl_stmt|;
name|class
name|Framebuffer
decl_stmt|;
name|class
name|Renderbuffer
decl_stmt|;
name|class
name|RenderbufferStorage
decl_stmt|;
name|class
name|Colorbuffer
decl_stmt|;
name|class
name|Depthbuffer
decl_stmt|;
name|class
name|Stencilbuffer
decl_stmt|;
name|class
name|DepthStencilbuffer
decl_stmt|;
name|class
name|Fence
decl_stmt|;
name|class
name|Query
decl_stmt|;
name|class
name|ResourceManager
decl_stmt|;
name|class
name|Buffer
decl_stmt|;
enum|enum
name|QueryType
block|{
name|QUERY_ANY_SAMPLES_PASSED
block|,
name|QUERY_ANY_SAMPLES_PASSED_CONSERVATIVE
block|,
name|QUERY_TYPE_COUNT
block|}
enum|;
comment|// Helper structure describing a single vertex attribute
name|class
name|VertexAttribute
block|{
name|public
label|:
name|VertexAttribute
argument_list|()
operator|:
name|mType
argument_list|(
name|GL_FLOAT
argument_list|)
operator|,
name|mSize
argument_list|(
literal|0
argument_list|)
operator|,
name|mNormalized
argument_list|(
name|false
argument_list|)
operator|,
name|mStride
argument_list|(
literal|0
argument_list|)
operator|,
name|mPointer
argument_list|(
name|NULL
argument_list|)
operator|,
name|mArrayEnabled
argument_list|(
name|false
argument_list|)
operator|,
name|mDivisor
argument_list|(
literal|0
argument_list|)
block|{
name|mCurrentValue
index|[
literal|0
index|]
operator|=
literal|0.0f
block|;
name|mCurrentValue
index|[
literal|1
index|]
operator|=
literal|0.0f
block|;
name|mCurrentValue
index|[
literal|2
index|]
operator|=
literal|0.0f
block|;
name|mCurrentValue
index|[
literal|3
index|]
operator|=
literal|1.0f
block|;     }
name|int
name|typeSize
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|mType
condition|)
block|{
case|case
name|GL_BYTE
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLbyte
argument_list|)
return|;
case|case
name|GL_UNSIGNED_BYTE
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLubyte
argument_list|)
return|;
case|case
name|GL_SHORT
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLshort
argument_list|)
return|;
case|case
name|GL_UNSIGNED_SHORT
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLushort
argument_list|)
return|;
case|case
name|GL_FIXED
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLfixed
argument_list|)
return|;
case|case
name|GL_FLOAT
case|:
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
return|;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|mSize
operator|*
sizeof|sizeof
argument_list|(
name|GLfloat
argument_list|)
return|;
block|}
block|}
name|GLsizei
name|stride
argument_list|()
specifier|const
block|{
return|return
name|mStride
operator|?
name|mStride
operator|:
name|typeSize
argument_list|()
return|;
block|}
comment|// From glVertexAttribPointer
name|GLenum
name|mType
decl_stmt|;
name|GLint
name|mSize
decl_stmt|;
name|bool
name|mNormalized
decl_stmt|;
name|GLsizei
name|mStride
decl_stmt|;
comment|// 0 means natural stride
union|union
block|{
specifier|const
name|void
modifier|*
name|mPointer
decl_stmt|;
name|intptr_t
name|mOffset
decl_stmt|;
block|}
union|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mBoundBuffer
expr_stmt|;
comment|// Captured when glVertexAttribPointer is called.
name|bool
name|mArrayEnabled
decl_stmt|;
comment|// From glEnable/DisableVertexAttribArray
name|float
name|mCurrentValue
index|[
literal|4
index|]
decl_stmt|;
comment|// From glVertexAttrib
name|unsigned
name|int
name|mDivisor
decl_stmt|;
block|}
empty_stmt|;
comment|// Helper structure to store all raw state
struct|struct
name|State
block|{
name|Color
name|colorClearValue
decl_stmt|;
name|GLclampf
name|depthClearValue
decl_stmt|;
name|int
name|stencilClearValue
decl_stmt|;
name|RasterizerState
name|rasterizer
decl_stmt|;
name|bool
name|scissorTest
decl_stmt|;
name|Rectangle
name|scissor
decl_stmt|;
name|BlendState
name|blend
decl_stmt|;
name|Color
name|blendColor
decl_stmt|;
name|bool
name|sampleCoverage
decl_stmt|;
name|GLclampf
name|sampleCoverageValue
decl_stmt|;
name|bool
name|sampleCoverageInvert
decl_stmt|;
name|DepthStencilState
name|depthStencil
decl_stmt|;
name|GLint
name|stencilRef
decl_stmt|;
name|GLint
name|stencilBackRef
decl_stmt|;
name|GLfloat
name|lineWidth
decl_stmt|;
name|GLenum
name|generateMipmapHint
decl_stmt|;
name|GLenum
name|fragmentShaderDerivativeHint
decl_stmt|;
name|Rectangle
name|viewport
decl_stmt|;
name|float
name|zNear
decl_stmt|;
name|float
name|zFar
decl_stmt|;
name|unsigned
name|int
name|activeSampler
decl_stmt|;
comment|// Active texture unit selector - GL_TEXTURE0
name|BindingPointer
operator|<
name|Buffer
operator|>
name|arrayBuffer
expr_stmt|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|elementArrayBuffer
expr_stmt|;
name|GLuint
name|readFramebuffer
decl_stmt|;
name|GLuint
name|drawFramebuffer
decl_stmt|;
name|BindingPointer
operator|<
name|Renderbuffer
operator|>
name|renderbuffer
expr_stmt|;
name|GLuint
name|currentProgram
decl_stmt|;
name|VertexAttribute
name|vertexAttribute
index|[
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
name|BindingPointer
operator|<
name|Texture
operator|>
name|samplerTexture
index|[
name|TEXTURE_TYPE_COUNT
index|]
index|[
name|IMPLEMENTATION_MAX_COMBINED_TEXTURE_IMAGE_UNITS
index|]
expr_stmt|;
name|BindingPointer
operator|<
name|Query
operator|>
name|activeQuery
index|[
name|QUERY_TYPE_COUNT
index|]
expr_stmt|;
name|GLint
name|unpackAlignment
decl_stmt|;
name|GLint
name|packAlignment
decl_stmt|;
name|bool
name|packReverseRowOrder
decl_stmt|;
block|}
struct|;
name|class
name|Context
block|{
name|public
label|:
name|Context
argument_list|(
argument|const gl::Context *shareContext
argument_list|,
argument|rx::Renderer *renderer
argument_list|,
argument|bool notifyResets
argument_list|,
argument|bool robustAccess
argument_list|)
empty_stmt|;
operator|~
name|Context
argument_list|()
expr_stmt|;
name|void
name|makeCurrent
argument_list|(
name|egl
operator|::
name|Surface
operator|*
name|surface
argument_list|)
decl_stmt|;
name|virtual
name|void
name|markContextLost
parameter_list|()
function_decl|;
name|bool
name|isContextLost
parameter_list|()
function_decl|;
comment|// State manipulation
name|void
name|setClearColor
parameter_list|(
name|float
name|red
parameter_list|,
name|float
name|green
parameter_list|,
name|float
name|blue
parameter_list|,
name|float
name|alpha
parameter_list|)
function_decl|;
name|void
name|setClearDepth
parameter_list|(
name|float
name|depth
parameter_list|)
function_decl|;
name|void
name|setClearStencil
parameter_list|(
name|int
name|stencil
parameter_list|)
function_decl|;
name|void
name|setCullFace
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isCullFaceEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCullMode
parameter_list|(
name|GLenum
name|mode
parameter_list|)
function_decl|;
name|void
name|setFrontFace
parameter_list|(
name|GLenum
name|front
parameter_list|)
function_decl|;
name|void
name|setDepthTest
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isDepthTestEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDepthFunc
parameter_list|(
name|GLenum
name|depthFunc
parameter_list|)
function_decl|;
name|void
name|setDepthRange
parameter_list|(
name|float
name|zNear
parameter_list|,
name|float
name|zFar
parameter_list|)
function_decl|;
name|void
name|setBlend
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isBlendEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBlendFactors
parameter_list|(
name|GLenum
name|sourceRGB
parameter_list|,
name|GLenum
name|destRGB
parameter_list|,
name|GLenum
name|sourceAlpha
parameter_list|,
name|GLenum
name|destAlpha
parameter_list|)
function_decl|;
name|void
name|setBlendColor
parameter_list|(
name|float
name|red
parameter_list|,
name|float
name|green
parameter_list|,
name|float
name|blue
parameter_list|,
name|float
name|alpha
parameter_list|)
function_decl|;
name|void
name|setBlendEquation
parameter_list|(
name|GLenum
name|rgbEquation
parameter_list|,
name|GLenum
name|alphaEquation
parameter_list|)
function_decl|;
name|void
name|setStencilTest
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isStencilTestEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStencilParams
parameter_list|(
name|GLenum
name|stencilFunc
parameter_list|,
name|GLint
name|stencilRef
parameter_list|,
name|GLuint
name|stencilMask
parameter_list|)
function_decl|;
name|void
name|setStencilBackParams
parameter_list|(
name|GLenum
name|stencilBackFunc
parameter_list|,
name|GLint
name|stencilBackRef
parameter_list|,
name|GLuint
name|stencilBackMask
parameter_list|)
function_decl|;
name|void
name|setStencilWritemask
parameter_list|(
name|GLuint
name|stencilWritemask
parameter_list|)
function_decl|;
name|void
name|setStencilBackWritemask
parameter_list|(
name|GLuint
name|stencilBackWritemask
parameter_list|)
function_decl|;
name|void
name|setStencilOperations
parameter_list|(
name|GLenum
name|stencilFail
parameter_list|,
name|GLenum
name|stencilPassDepthFail
parameter_list|,
name|GLenum
name|stencilPassDepthPass
parameter_list|)
function_decl|;
name|void
name|setStencilBackOperations
parameter_list|(
name|GLenum
name|stencilBackFail
parameter_list|,
name|GLenum
name|stencilBackPassDepthFail
parameter_list|,
name|GLenum
name|stencilBackPassDepthPass
parameter_list|)
function_decl|;
name|void
name|setPolygonOffsetFill
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isPolygonOffsetFillEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPolygonOffsetParams
parameter_list|(
name|GLfloat
name|factor
parameter_list|,
name|GLfloat
name|units
parameter_list|)
function_decl|;
name|void
name|setSampleAlphaToCoverage
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isSampleAlphaToCoverageEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSampleCoverage
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isSampleCoverageEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSampleCoverageParams
parameter_list|(
name|GLclampf
name|value
parameter_list|,
name|bool
name|invert
parameter_list|)
function_decl|;
name|void
name|setScissorTest
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isScissorTestEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDither
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isDitherEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLineWidth
parameter_list|(
name|GLfloat
name|width
parameter_list|)
function_decl|;
name|void
name|setGenerateMipmapHint
parameter_list|(
name|GLenum
name|hint
parameter_list|)
function_decl|;
name|void
name|setFragmentShaderDerivativeHint
parameter_list|(
name|GLenum
name|hint
parameter_list|)
function_decl|;
name|void
name|setViewportParams
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|void
name|setScissorParams
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|void
name|setColorMask
parameter_list|(
name|bool
name|red
parameter_list|,
name|bool
name|green
parameter_list|,
name|bool
name|blue
parameter_list|,
name|bool
name|alpha
parameter_list|)
function_decl|;
name|void
name|setDepthMask
parameter_list|(
name|bool
name|mask
parameter_list|)
function_decl|;
name|void
name|setActiveSampler
parameter_list|(
name|unsigned
name|int
name|active
parameter_list|)
function_decl|;
name|GLuint
name|getReadFramebufferHandle
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getDrawFramebufferHandle
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getRenderbufferHandle
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getArrayBufferHandle
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|getActiveQuery
argument_list|(
name|GLenum
name|target
argument_list|)
decl|const
decl_stmt|;
name|void
name|setEnableVertexAttribArray
parameter_list|(
name|unsigned
name|int
name|attribNum
parameter_list|,
name|bool
name|enabled
parameter_list|)
function_decl|;
specifier|const
name|VertexAttribute
modifier|&
name|getVertexAttribState
parameter_list|(
name|unsigned
name|int
name|attribNum
parameter_list|)
function_decl|;
name|void
name|setVertexAttribState
parameter_list|(
name|unsigned
name|int
name|attribNum
parameter_list|,
name|Buffer
modifier|*
name|boundBuffer
parameter_list|,
name|GLint
name|size
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|bool
name|normalized
parameter_list|,
name|GLsizei
name|stride
parameter_list|,
specifier|const
name|void
modifier|*
name|pointer
parameter_list|)
function_decl|;
specifier|const
name|void
modifier|*
name|getVertexAttribPointer
argument_list|(
name|unsigned
name|int
name|attribNum
argument_list|)
decl|const
decl_stmt|;
name|void
name|setUnpackAlignment
parameter_list|(
name|GLint
name|alignment
parameter_list|)
function_decl|;
name|GLint
name|getUnpackAlignment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPackAlignment
parameter_list|(
name|GLint
name|alignment
parameter_list|)
function_decl|;
name|GLint
name|getPackAlignment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPackReverseRowOrder
parameter_list|(
name|bool
name|reverseRowOrder
parameter_list|)
function_decl|;
name|bool
name|getPackReverseRowOrder
argument_list|()
specifier|const
expr_stmt|;
comment|// These create  and destroy methods are merely pass-throughs to
comment|// ResourceManager, which owns these object types
name|GLuint
name|createBuffer
parameter_list|()
function_decl|;
name|GLuint
name|createShader
parameter_list|(
name|GLenum
name|type
parameter_list|)
function_decl|;
name|GLuint
name|createProgram
parameter_list|()
function_decl|;
name|GLuint
name|createTexture
parameter_list|()
function_decl|;
name|GLuint
name|createRenderbuffer
parameter_list|()
function_decl|;
name|void
name|deleteBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|void
name|deleteShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
function_decl|;
name|void
name|deleteProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|void
name|deleteTexture
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|void
name|deleteRenderbuffer
parameter_list|(
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
comment|// Framebuffers are owned by the Context, so these methods do not pass through
name|GLuint
name|createFramebuffer
parameter_list|()
function_decl|;
name|void
name|deleteFramebuffer
parameter_list|(
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
comment|// Fences are owned by the Context.
name|GLuint
name|createFence
parameter_list|()
function_decl|;
name|void
name|deleteFence
parameter_list|(
name|GLuint
name|fence
parameter_list|)
function_decl|;
comment|// Queries are owned by the Context;
name|GLuint
name|createQuery
parameter_list|()
function_decl|;
name|void
name|deleteQuery
parameter_list|(
name|GLuint
name|query
parameter_list|)
function_decl|;
name|void
name|bindArrayBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|void
name|bindElementArrayBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|void
name|bindTexture2D
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|void
name|bindTextureCubeMap
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|void
name|bindReadFramebuffer
parameter_list|(
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
name|void
name|bindDrawFramebuffer
parameter_list|(
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
name|void
name|bindRenderbuffer
parameter_list|(
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|void
name|useProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|void
name|linkProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
function_decl|;
name|void
name|setProgramBinary
parameter_list|(
name|GLuint
name|program
parameter_list|,
specifier|const
name|void
modifier|*
name|binary
parameter_list|,
name|GLint
name|length
parameter_list|)
function_decl|;
name|void
name|beginQuery
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLuint
name|query
parameter_list|)
function_decl|;
name|void
name|endQuery
parameter_list|(
name|GLenum
name|target
parameter_list|)
function_decl|;
name|void
name|setFramebufferZero
parameter_list|(
name|Framebuffer
modifier|*
name|framebuffer
parameter_list|)
function_decl|;
name|void
name|setRenderbufferStorage
parameter_list|(
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLsizei
name|samples
parameter_list|)
function_decl|;
name|void
name|setVertexAttrib
parameter_list|(
name|GLuint
name|index
parameter_list|,
specifier|const
name|GLfloat
modifier|*
name|values
parameter_list|)
function_decl|;
name|void
name|setVertexAttribDivisor
parameter_list|(
name|GLuint
name|index
parameter_list|,
name|GLuint
name|divisor
parameter_list|)
function_decl|;
name|Buffer
modifier|*
name|getBuffer
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Fence
modifier|*
name|getFence
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Shader
modifier|*
name|getShader
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Program
modifier|*
name|getProgram
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Texture
modifier|*
name|getTexture
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Framebuffer
modifier|*
name|getFramebuffer
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Renderbuffer
modifier|*
name|getRenderbuffer
parameter_list|(
name|GLuint
name|handle
parameter_list|)
function_decl|;
name|Query
modifier|*
name|getQuery
parameter_list|(
name|GLuint
name|handle
parameter_list|,
name|bool
name|create
parameter_list|,
name|GLenum
name|type
parameter_list|)
function_decl|;
name|Buffer
modifier|*
name|getArrayBuffer
parameter_list|()
function_decl|;
name|Buffer
modifier|*
name|getElementArrayBuffer
parameter_list|()
function_decl|;
name|ProgramBinary
modifier|*
name|getCurrentProgramBinary
parameter_list|()
function_decl|;
name|Texture2D
modifier|*
name|getTexture2D
parameter_list|()
function_decl|;
name|TextureCubeMap
modifier|*
name|getTextureCubeMap
parameter_list|()
function_decl|;
name|Texture
modifier|*
name|getSamplerTexture
parameter_list|(
name|unsigned
name|int
name|sampler
parameter_list|,
name|TextureType
name|type
parameter_list|)
function_decl|;
name|Framebuffer
modifier|*
name|getReadFramebuffer
parameter_list|()
function_decl|;
name|Framebuffer
modifier|*
name|getDrawFramebuffer
parameter_list|()
function_decl|;
name|bool
name|getFloatv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLfloat
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|getIntegerv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLint
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|getBooleanv
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLboolean
modifier|*
name|params
parameter_list|)
function_decl|;
name|bool
name|getQueryParameterInfo
parameter_list|(
name|GLenum
name|pname
parameter_list|,
name|GLenum
modifier|*
name|type
parameter_list|,
name|unsigned
name|int
modifier|*
name|numParams
parameter_list|)
function_decl|;
name|void
name|readPixels
parameter_list|(
name|GLint
name|x
parameter_list|,
name|GLint
name|y
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|GLsizei
modifier|*
name|bufSize
parameter_list|,
name|void
modifier|*
name|pixels
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|(
name|GLbitfield
name|mask
parameter_list|)
function_decl|;
name|void
name|drawArrays
parameter_list|(
name|GLenum
name|mode
parameter_list|,
name|GLint
name|first
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLsizei
name|instances
parameter_list|)
function_decl|;
name|void
name|drawElements
parameter_list|(
name|GLenum
name|mode
parameter_list|,
name|GLsizei
name|count
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|indices
parameter_list|,
name|GLsizei
name|instances
parameter_list|)
function_decl|;
name|void
name|sync
parameter_list|(
name|bool
name|block
parameter_list|)
function_decl|;
comment|// flush/finish
name|void
name|recordInvalidEnum
parameter_list|()
function_decl|;
name|void
name|recordInvalidValue
parameter_list|()
function_decl|;
name|void
name|recordInvalidOperation
parameter_list|()
function_decl|;
name|void
name|recordOutOfMemory
parameter_list|()
function_decl|;
name|void
name|recordInvalidFramebufferOperation
parameter_list|()
function_decl|;
name|GLenum
name|getError
parameter_list|()
function_decl|;
name|GLenum
name|getResetStatus
parameter_list|()
function_decl|;
name|virtual
name|bool
name|isResetNotificationEnabled
parameter_list|()
function_decl|;
name|int
name|getMajorShaderModel
argument_list|()
specifier|const
expr_stmt|;
name|float
name|getMaximumPointSize
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|getMaximumCombinedTextureImageUnits
argument_list|()
specifier|const
expr_stmt|;
name|int
name|getMaximumRenderbufferDimension
argument_list|()
specifier|const
expr_stmt|;
name|int
name|getMaximumTextureDimension
argument_list|()
specifier|const
expr_stmt|;
name|int
name|getMaximumCubeTextureDimension
argument_list|()
specifier|const
expr_stmt|;
name|int
name|getMaximumTextureLevel
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|getMaximumRenderTargets
argument_list|()
specifier|const
expr_stmt|;
name|GLsizei
name|getMaxSupportedSamples
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|getExtensionString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|getRendererString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsEventQueries
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsOcclusionQueries
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsBGRATextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsDXT1Textures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsDXT3Textures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsDXT5Textures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat32Textures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat32LinearFilter
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat32RenderableTextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat16Textures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat16LinearFilter
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsFloat16RenderableTextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsLuminanceTextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsLuminanceAlphaTextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsDepthTextures
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supports32bitIndices
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsNonPower2Texture
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsInstancing
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|supportsTextureFilterAnisotropy
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|getCurrentReadFormatType
parameter_list|(
name|GLenum
modifier|*
name|format
parameter_list|,
name|GLenum
modifier|*
name|type
parameter_list|)
function_decl|;
name|float
name|getTextureMaxAnisotropy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|blitFramebuffer
parameter_list|(
name|GLint
name|srcX0
parameter_list|,
name|GLint
name|srcY0
parameter_list|,
name|GLint
name|srcX1
parameter_list|,
name|GLint
name|srcY1
parameter_list|,
name|GLint
name|dstX0
parameter_list|,
name|GLint
name|dstY0
parameter_list|,
name|GLint
name|dstX1
parameter_list|,
name|GLint
name|dstY1
parameter_list|,
name|GLbitfield
name|mask
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Context
argument_list|)
expr_stmt|;
name|bool
name|applyRenderTarget
parameter_list|(
name|GLenum
name|drawMode
parameter_list|,
name|bool
name|ignoreViewport
parameter_list|)
function_decl|;
name|void
name|applyState
parameter_list|(
name|GLenum
name|drawMode
parameter_list|)
function_decl|;
name|void
name|applyShaders
parameter_list|()
function_decl|;
name|void
name|applyTextures
parameter_list|()
function_decl|;
name|void
name|applyTextures
parameter_list|(
name|SamplerType
name|type
parameter_list|)
function_decl|;
name|void
name|detachBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
function_decl|;
name|void
name|detachTexture
parameter_list|(
name|GLuint
name|texture
parameter_list|)
function_decl|;
name|void
name|detachFramebuffer
parameter_list|(
name|GLuint
name|framebuffer
parameter_list|)
function_decl|;
name|void
name|detachRenderbuffer
parameter_list|(
name|GLuint
name|renderbuffer
parameter_list|)
function_decl|;
name|Texture
modifier|*
name|getIncompleteTexture
parameter_list|(
name|TextureType
name|type
parameter_list|)
function_decl|;
name|bool
name|skipDraw
parameter_list|(
name|GLenum
name|drawMode
parameter_list|)
function_decl|;
name|void
name|initExtensionString
parameter_list|()
function_decl|;
name|void
name|initRendererString
parameter_list|()
function_decl|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
expr_stmt|;
name|State
name|mState
decl_stmt|;
name|BindingPointer
operator|<
name|Texture2D
operator|>
name|mTexture2DZero
expr_stmt|;
name|BindingPointer
operator|<
name|TextureCubeMap
operator|>
name|mTextureCubeMapZero
expr_stmt|;
ifndef|#
directive|ifndef
name|HASH_MAP
ifdef|#
directive|ifdef
name|_MSC_VER
DECL|macro|HASH_MAP
define|#
directive|define
name|HASH_MAP
value|stdext::hash_map
else|#
directive|else
define|#
directive|define
name|HASH_MAP
value|std::unordered_map
endif|#
directive|endif
endif|#
directive|endif
typedef|typedef
name|HASH_MAP
operator|<
name|GLuint
operator|,
name|Framebuffer
operator|*
operator|>
name|FramebufferMap
expr_stmt|;
name|FramebufferMap
name|mFramebufferMap
decl_stmt|;
name|HandleAllocator
name|mFramebufferHandleAllocator
decl_stmt|;
typedef|typedef
name|HASH_MAP
operator|<
name|GLuint
operator|,
name|Fence
operator|*
operator|>
name|FenceMap
expr_stmt|;
name|FenceMap
name|mFenceMap
decl_stmt|;
name|HandleAllocator
name|mFenceHandleAllocator
decl_stmt|;
typedef|typedef
name|HASH_MAP
operator|<
name|GLuint
operator|,
name|Query
operator|*
operator|>
name|QueryMap
expr_stmt|;
name|QueryMap
name|mQueryMap
decl_stmt|;
name|HandleAllocator
name|mQueryHandleAllocator
decl_stmt|;
specifier|const
name|char
modifier|*
name|mExtensionString
decl_stmt|;
specifier|const
name|char
modifier|*
name|mRendererString
decl_stmt|;
name|BindingPointer
operator|<
name|Texture
operator|>
name|mIncompleteTextures
index|[
name|TEXTURE_TYPE_COUNT
index|]
expr_stmt|;
comment|// Recorded errors
name|bool
name|mInvalidEnum
decl_stmt|;
name|bool
name|mInvalidValue
decl_stmt|;
name|bool
name|mInvalidOperation
decl_stmt|;
name|bool
name|mOutOfMemory
decl_stmt|;
name|bool
name|mInvalidFramebufferOperation
decl_stmt|;
comment|// Current/lost context flags
name|bool
name|mHasBeenCurrent
decl_stmt|;
name|bool
name|mContextLost
decl_stmt|;
name|GLenum
name|mResetStatus
decl_stmt|;
name|GLenum
name|mResetStrategy
decl_stmt|;
name|bool
name|mRobustAccess
decl_stmt|;
name|BindingPointer
operator|<
name|ProgramBinary
operator|>
name|mCurrentProgramBinary
expr_stmt|;
name|Framebuffer
modifier|*
name|mBoundDrawFramebuffer
decl_stmt|;
name|int
name|mMajorShaderModel
decl_stmt|;
name|float
name|mMaximumPointSize
decl_stmt|;
name|bool
name|mSupportsVertexTexture
decl_stmt|;
name|bool
name|mSupportsNonPower2Texture
decl_stmt|;
name|bool
name|mSupportsInstancing
decl_stmt|;
name|int
name|mMaxViewportDimension
decl_stmt|;
name|int
name|mMaxRenderbufferDimension
decl_stmt|;
name|int
name|mMaxTextureDimension
decl_stmt|;
name|int
name|mMaxCubeTextureDimension
decl_stmt|;
name|int
name|mMaxTextureLevel
decl_stmt|;
name|float
name|mMaxTextureAnisotropy
decl_stmt|;
name|bool
name|mSupportsEventQueries
decl_stmt|;
name|bool
name|mSupportsOcclusionQueries
decl_stmt|;
name|bool
name|mSupportsBGRATextures
decl_stmt|;
name|bool
name|mSupportsDXT1Textures
decl_stmt|;
name|bool
name|mSupportsDXT3Textures
decl_stmt|;
name|bool
name|mSupportsDXT5Textures
decl_stmt|;
name|bool
name|mSupportsFloat32Textures
decl_stmt|;
name|bool
name|mSupportsFloat32LinearFilter
decl_stmt|;
name|bool
name|mSupportsFloat32RenderableTextures
decl_stmt|;
name|bool
name|mSupportsFloat16Textures
decl_stmt|;
name|bool
name|mSupportsFloat16LinearFilter
decl_stmt|;
name|bool
name|mSupportsFloat16RenderableTextures
decl_stmt|;
name|bool
name|mSupportsLuminanceTextures
decl_stmt|;
name|bool
name|mSupportsLuminanceAlphaTextures
decl_stmt|;
name|bool
name|mSupportsDepthTextures
decl_stmt|;
name|bool
name|mSupports32bitIndices
decl_stmt|;
name|bool
name|mSupportsTextureFilterAnisotropy
decl_stmt|;
name|int
name|mNumCompressedTextureFormats
decl_stmt|;
name|ResourceManager
modifier|*
name|mResourceManager
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// INCLUDE_CONTEXT_H_
end_comment
end_unit
