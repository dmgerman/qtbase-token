begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// State.h: Defines the State class, encapsulating raw GL state
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_STATE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_STATE_H_
define|#
directive|define
name|LIBANGLE_STATE_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/VertexAttribute.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Renderbuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/TransformFeedback.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Program.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Sampler.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Query
decl_stmt|;
name|class
name|VertexArray
decl_stmt|;
name|class
name|Context
decl_stmt|;
struct_decl|struct
name|Caps
struct_decl|;
struct_decl|struct
name|Data
struct_decl|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GLenum
operator|,
name|BindingPointer
operator|<
name|Texture
operator|>
expr|>
name|TextureMap
expr_stmt|;
name|class
name|State
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|State
argument_list|()
block|;
operator|~
name|State
argument_list|()
block|;
name|void
name|initialize
argument_list|(
argument|const Caps& caps
argument_list|,
argument|GLuint clientVersion
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
comment|// State chunk getters
specifier|const
name|RasterizerState
operator|&
name|getRasterizerState
argument_list|()
specifier|const
block|;
specifier|const
name|BlendState
operator|&
name|getBlendState
argument_list|()
specifier|const
block|;
specifier|const
name|DepthStencilState
operator|&
name|getDepthStencilState
argument_list|()
specifier|const
block|;
comment|// Clear behavior setters& state parameter block generation function
name|void
name|setColorClearValue
argument_list|(
argument|float red
argument_list|,
argument|float green
argument_list|,
argument|float blue
argument_list|,
argument|float alpha
argument_list|)
block|;
name|void
name|setDepthClearValue
argument_list|(
argument|float depth
argument_list|)
block|;
name|void
name|setStencilClearValue
argument_list|(
argument|int stencil
argument_list|)
block|;
specifier|const
name|ColorF
operator|&
name|getColorClearValue
argument_list|()
specifier|const
block|{
return|return
name|mColorClearValue
return|;
block|}
name|float
name|getDepthClearValue
argument_list|()
specifier|const
block|{
return|return
name|mDepthClearValue
return|;
block|}
name|int
name|getStencilClearValue
argument_list|()
specifier|const
block|{
return|return
name|mStencilClearValue
return|;
block|}
comment|// Write mask manipulation
name|void
name|setColorMask
argument_list|(
argument|bool red
argument_list|,
argument|bool green
argument_list|,
argument|bool blue
argument_list|,
argument|bool alpha
argument_list|)
block|;
name|void
name|setDepthMask
argument_list|(
argument|bool mask
argument_list|)
block|;
comment|// Discard toggle& query
name|bool
name|isRasterizerDiscardEnabled
argument_list|()
specifier|const
block|;
name|void
name|setRasterizerDiscard
argument_list|(
argument|bool enabled
argument_list|)
block|;
comment|// Primitive restart
name|bool
name|isPrimitiveRestartEnabled
argument_list|()
specifier|const
block|;
name|void
name|setPrimitiveRestart
argument_list|(
argument|bool enabled
argument_list|)
block|;
comment|// Face culling state manipulation
name|bool
name|isCullFaceEnabled
argument_list|()
specifier|const
block|;
name|void
name|setCullFace
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setCullMode
argument_list|(
argument|GLenum mode
argument_list|)
block|;
name|void
name|setFrontFace
argument_list|(
argument|GLenum front
argument_list|)
block|;
comment|// Depth test state manipulation
name|bool
name|isDepthTestEnabled
argument_list|()
specifier|const
block|;
name|void
name|setDepthTest
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setDepthFunc
argument_list|(
argument|GLenum depthFunc
argument_list|)
block|;
name|void
name|setDepthRange
argument_list|(
argument|float zNear
argument_list|,
argument|float zFar
argument_list|)
block|;
name|void
name|getDepthRange
argument_list|(
argument|float *zNear
argument_list|,
argument|float *zFar
argument_list|)
specifier|const
block|;
comment|// Blend state manipulation
name|bool
name|isBlendEnabled
argument_list|()
specifier|const
block|;
name|void
name|setBlend
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setBlendFactors
argument_list|(
argument|GLenum sourceRGB
argument_list|,
argument|GLenum destRGB
argument_list|,
argument|GLenum sourceAlpha
argument_list|,
argument|GLenum destAlpha
argument_list|)
block|;
name|void
name|setBlendColor
argument_list|(
argument|float red
argument_list|,
argument|float green
argument_list|,
argument|float blue
argument_list|,
argument|float alpha
argument_list|)
block|;
name|void
name|setBlendEquation
argument_list|(
argument|GLenum rgbEquation
argument_list|,
argument|GLenum alphaEquation
argument_list|)
block|;
specifier|const
name|ColorF
operator|&
name|getBlendColor
argument_list|()
specifier|const
block|;
comment|// Stencil state maniupulation
name|bool
name|isStencilTestEnabled
argument_list|()
specifier|const
block|;
name|void
name|setStencilTest
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setStencilParams
argument_list|(
argument|GLenum stencilFunc
argument_list|,
argument|GLint stencilRef
argument_list|,
argument|GLuint stencilMask
argument_list|)
block|;
name|void
name|setStencilBackParams
argument_list|(
argument|GLenum stencilBackFunc
argument_list|,
argument|GLint stencilBackRef
argument_list|,
argument|GLuint stencilBackMask
argument_list|)
block|;
name|void
name|setStencilWritemask
argument_list|(
argument|GLuint stencilWritemask
argument_list|)
block|;
name|void
name|setStencilBackWritemask
argument_list|(
argument|GLuint stencilBackWritemask
argument_list|)
block|;
name|void
name|setStencilOperations
argument_list|(
argument|GLenum stencilFail
argument_list|,
argument|GLenum stencilPassDepthFail
argument_list|,
argument|GLenum stencilPassDepthPass
argument_list|)
block|;
name|void
name|setStencilBackOperations
argument_list|(
argument|GLenum stencilBackFail
argument_list|,
argument|GLenum stencilBackPassDepthFail
argument_list|,
argument|GLenum stencilBackPassDepthPass
argument_list|)
block|;
name|GLint
name|getStencilRef
argument_list|()
specifier|const
block|;
name|GLint
name|getStencilBackRef
argument_list|()
specifier|const
block|;
comment|// Depth bias/polygon offset state manipulation
name|bool
name|isPolygonOffsetFillEnabled
argument_list|()
specifier|const
block|;
name|void
name|setPolygonOffsetFill
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setPolygonOffsetParams
argument_list|(
argument|GLfloat factor
argument_list|,
argument|GLfloat units
argument_list|)
block|;
comment|// Multisample coverage state manipulation
name|bool
name|isSampleAlphaToCoverageEnabled
argument_list|()
specifier|const
block|;
name|void
name|setSampleAlphaToCoverage
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isSampleCoverageEnabled
argument_list|()
specifier|const
block|;
name|void
name|setSampleCoverage
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setSampleCoverageParams
argument_list|(
argument|GLclampf value
argument_list|,
argument|bool invert
argument_list|)
block|;
name|void
name|getSampleCoverageParams
argument_list|(
argument|GLclampf *value
argument_list|,
argument|bool *invert
argument_list|)
specifier|const
block|;
comment|// Scissor test state toggle& query
name|bool
name|isScissorTestEnabled
argument_list|()
specifier|const
block|;
name|void
name|setScissorTest
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|setScissorParams
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
specifier|const
name|Rectangle
operator|&
name|getScissor
argument_list|()
specifier|const
block|;
comment|// Dither state toggle& query
name|bool
name|isDitherEnabled
argument_list|()
specifier|const
block|;
name|void
name|setDither
argument_list|(
argument|bool enabled
argument_list|)
block|;
comment|// Generic state toggle& query
name|void
name|setEnableFeature
argument_list|(
argument|GLenum feature
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|bool
name|getEnableFeature
argument_list|(
argument|GLenum feature
argument_list|)
block|;
comment|// Line width state setter
name|void
name|setLineWidth
argument_list|(
argument|GLfloat width
argument_list|)
block|;
comment|// Hint setters
name|void
name|setGenerateMipmapHint
argument_list|(
argument|GLenum hint
argument_list|)
block|;
name|void
name|setFragmentShaderDerivativeHint
argument_list|(
argument|GLenum hint
argument_list|)
block|;
comment|// Viewport state setter/getter
name|void
name|setViewportParams
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
specifier|const
name|Rectangle
operator|&
name|getViewport
argument_list|()
specifier|const
block|;
comment|// Texture binding& active texture unit manipulation
name|void
name|setActiveSampler
argument_list|(
argument|unsigned int active
argument_list|)
block|;
name|unsigned
name|int
name|getActiveSampler
argument_list|()
specifier|const
block|;
name|void
name|setSamplerTexture
argument_list|(
argument|GLenum type
argument_list|,
argument|Texture *texture
argument_list|)
block|;
name|Texture
operator|*
name|getSamplerTexture
argument_list|(
argument|unsigned int sampler
argument_list|,
argument|GLenum type
argument_list|)
specifier|const
block|;
name|GLuint
name|getSamplerTextureId
argument_list|(
argument|unsigned int sampler
argument_list|,
argument|GLenum type
argument_list|)
specifier|const
block|;
name|void
name|detachTexture
argument_list|(
argument|const TextureMap&zeroTextures
argument_list|,
argument|GLuint texture
argument_list|)
block|;
name|void
name|initializeZeroTextures
argument_list|(
specifier|const
name|TextureMap
operator|&
name|zeroTextures
argument_list|)
block|;
comment|// Sampler object binding manipulation
name|void
name|setSamplerBinding
argument_list|(
argument|GLuint textureUnit
argument_list|,
argument|Sampler *sampler
argument_list|)
block|;
name|GLuint
name|getSamplerId
argument_list|(
argument|GLuint textureUnit
argument_list|)
specifier|const
block|;
name|Sampler
operator|*
name|getSampler
argument_list|(
argument|GLuint textureUnit
argument_list|)
specifier|const
block|;
name|void
name|detachSampler
argument_list|(
argument|GLuint sampler
argument_list|)
block|;
comment|// Renderbuffer binding manipulation
name|void
name|setRenderbufferBinding
argument_list|(
name|Renderbuffer
operator|*
name|renderbuffer
argument_list|)
block|;
name|GLuint
name|getRenderbufferId
argument_list|()
specifier|const
block|;
name|Renderbuffer
operator|*
name|getCurrentRenderbuffer
argument_list|()
block|;
name|void
name|detachRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|;
comment|// Framebuffer binding manipulation
name|void
name|setReadFramebufferBinding
argument_list|(
name|Framebuffer
operator|*
name|framebuffer
argument_list|)
block|;
name|void
name|setDrawFramebufferBinding
argument_list|(
name|Framebuffer
operator|*
name|framebuffer
argument_list|)
block|;
name|Framebuffer
operator|*
name|getTargetFramebuffer
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
name|Framebuffer
operator|*
name|getReadFramebuffer
argument_list|()
block|;
name|Framebuffer
operator|*
name|getDrawFramebuffer
argument_list|()
block|;
specifier|const
name|Framebuffer
operator|*
name|getReadFramebuffer
argument_list|()
specifier|const
block|;
specifier|const
name|Framebuffer
operator|*
name|getDrawFramebuffer
argument_list|()
specifier|const
block|;
name|bool
name|removeReadFramebufferBinding
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
name|bool
name|removeDrawFramebufferBinding
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
comment|// Vertex array object binding manipulation
name|void
name|setVertexArrayBinding
argument_list|(
name|VertexArray
operator|*
name|vertexArray
argument_list|)
block|;
name|GLuint
name|getVertexArrayId
argument_list|()
specifier|const
block|;
name|VertexArray
operator|*
name|getVertexArray
argument_list|()
specifier|const
block|;
name|bool
name|removeVertexArrayBinding
argument_list|(
argument|GLuint vertexArray
argument_list|)
block|;
comment|// Program binding manipulation
name|void
name|setProgram
argument_list|(
name|Program
operator|*
name|newProgram
argument_list|)
block|;
name|Program
operator|*
name|getProgram
argument_list|()
specifier|const
block|;
comment|// Transform feedback object (not buffer) binding manipulation
name|void
name|setTransformFeedbackBinding
argument_list|(
name|TransformFeedback
operator|*
name|transformFeedback
argument_list|)
block|;
name|TransformFeedback
operator|*
name|getCurrentTransformFeedback
argument_list|()
specifier|const
block|;
name|bool
name|isTransformFeedbackActiveUnpaused
argument_list|()
specifier|const
block|;
name|void
name|detachTransformFeedback
argument_list|(
argument|GLuint transformFeedback
argument_list|)
block|;
comment|// Query binding manipulation
name|bool
name|isQueryActive
argument_list|()
specifier|const
block|;
name|void
name|setActiveQuery
argument_list|(
argument|GLenum target
argument_list|,
argument|Query *query
argument_list|)
block|;
name|GLuint
name|getActiveQueryId
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
name|Query
operator|*
name|getActiveQuery
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
comment|//// Typed buffer binding point manipulation ////
comment|// GL_ARRAY_BUFFER
name|void
name|setArrayBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
name|GLuint
name|getArrayBufferId
argument_list|()
specifier|const
block|;
name|bool
name|removeArrayBufferBinding
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
comment|// GL_UNIFORM_BUFFER - Both indexed and generic targets
name|void
name|setGenericUniformBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
name|void
name|setIndexedUniformBufferBinding
argument_list|(
argument|GLuint index
argument_list|,
argument|Buffer *buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|GLuint
name|getIndexedUniformBufferId
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|Buffer
operator|*
name|getIndexedUniformBuffer
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|GLintptr
name|getIndexedUniformBufferOffset
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|GLsizeiptr
name|getIndexedUniformBufferSize
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
comment|// GL_TRANSFORM_FEEDBACK_BUFFER - Both indexed and generic targets
name|void
name|setGenericTransformFeedbackBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
name|void
name|setIndexedTransformFeedbackBufferBinding
argument_list|(
argument|GLuint index
argument_list|,
argument|Buffer *buffer
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|GLuint
name|getIndexedTransformFeedbackBufferId
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|Buffer
operator|*
name|getIndexedTransformFeedbackBuffer
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|GLuint
name|getIndexedTransformFeedbackBufferOffset
argument_list|(
argument|GLuint index
argument_list|)
specifier|const
block|;
name|size_t
name|getTransformFeedbackBufferIndexRange
argument_list|()
specifier|const
block|;
comment|// GL_COPY_[READ/WRITE]_BUFFER
name|void
name|setCopyReadBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
name|void
name|setCopyWriteBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
comment|// GL_PIXEL[PACK/UNPACK]_BUFFER
name|void
name|setPixelPackBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
name|void
name|setPixelUnpackBufferBinding
argument_list|(
name|Buffer
operator|*
name|buffer
argument_list|)
block|;
comment|// Retrieve typed buffer by target (non-indexed)
name|Buffer
operator|*
name|getTargetBuffer
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
comment|// Vertex attrib manipulation
name|void
name|setEnableVertexAttribArray
argument_list|(
argument|unsigned int attribNum
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|void
name|setVertexAttribf
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLfloat values[
literal|4
argument|]
argument_list|)
block|;
name|void
name|setVertexAttribu
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLuint values[
literal|4
argument|]
argument_list|)
block|;
name|void
name|setVertexAttribi
argument_list|(
argument|GLuint index
argument_list|,
argument|const GLint values[
literal|4
argument|]
argument_list|)
block|;
name|void
name|setVertexAttribState
argument_list|(
argument|unsigned int attribNum
argument_list|,
argument|Buffer *boundBuffer
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|bool normalized
argument_list|,
argument|bool pureInteger
argument_list|,
argument|GLsizei stride
argument_list|,
argument|const void *pointer
argument_list|)
block|;
specifier|const
name|VertexAttribCurrentValueData
operator|&
name|getVertexAttribCurrentValue
argument_list|(
argument|unsigned int attribNum
argument_list|)
specifier|const
block|;
specifier|const
name|void
operator|*
name|getVertexAttribPointer
argument_list|(
argument|unsigned int attribNum
argument_list|)
specifier|const
block|;
comment|// Pixel pack state manipulation
name|void
name|setPackAlignment
argument_list|(
argument|GLint alignment
argument_list|)
block|;
name|GLint
name|getPackAlignment
argument_list|()
specifier|const
block|;
name|void
name|setPackReverseRowOrder
argument_list|(
argument|bool reverseRowOrder
argument_list|)
block|;
name|bool
name|getPackReverseRowOrder
argument_list|()
specifier|const
block|;
specifier|const
name|PixelPackState
operator|&
name|getPackState
argument_list|()
specifier|const
block|;
name|PixelPackState
operator|&
name|getPackState
argument_list|()
block|;
comment|// Pixel unpack state manipulation
name|void
name|setUnpackAlignment
argument_list|(
argument|GLint alignment
argument_list|)
block|;
name|GLint
name|getUnpackAlignment
argument_list|()
specifier|const
block|;
name|void
name|setUnpackRowLength
argument_list|(
argument|GLint rowLength
argument_list|)
block|;
name|GLint
name|getUnpackRowLength
argument_list|()
specifier|const
block|;
specifier|const
name|PixelUnpackState
operator|&
name|getUnpackState
argument_list|()
specifier|const
block|;
name|PixelUnpackState
operator|&
name|getUnpackState
argument_list|()
block|;
comment|// State query functions
name|void
name|getBooleanv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLboolean *params
argument_list|)
block|;
name|void
name|getFloatv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLfloat *params
argument_list|)
block|;
name|void
name|getIntegerv
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|bool
name|getIndexedIntegerv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint *data
argument_list|)
block|;
name|bool
name|getIndexedInteger64v
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint index
argument_list|,
argument|GLint64 *data
argument_list|)
block|;
name|bool
name|hasMappedBuffer
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// Cached values from Context's caps
name|GLuint
name|mMaxDrawBuffers
block|;
name|GLuint
name|mMaxCombinedTextureImageUnits
block|;
name|ColorF
name|mColorClearValue
block|;
name|GLclampf
name|mDepthClearValue
block|;
name|int
name|mStencilClearValue
block|;
name|RasterizerState
name|mRasterizer
block|;
name|bool
name|mScissorTest
block|;
name|Rectangle
name|mScissor
block|;
name|BlendState
name|mBlend
block|;
name|ColorF
name|mBlendColor
block|;
name|bool
name|mSampleCoverage
block|;
name|GLclampf
name|mSampleCoverageValue
block|;
name|bool
name|mSampleCoverageInvert
block|;
name|DepthStencilState
name|mDepthStencil
block|;
name|GLint
name|mStencilRef
block|;
name|GLint
name|mStencilBackRef
block|;
name|GLfloat
name|mLineWidth
block|;
name|GLenum
name|mGenerateMipmapHint
block|;
name|GLenum
name|mFragmentShaderDerivativeHint
block|;
name|Rectangle
name|mViewport
block|;
name|float
name|mNearZ
block|;
name|float
name|mFarZ
block|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mArrayBuffer
block|;
name|Framebuffer
operator|*
name|mReadFramebuffer
block|;
name|Framebuffer
operator|*
name|mDrawFramebuffer
block|;
name|BindingPointer
operator|<
name|Renderbuffer
operator|>
name|mRenderbuffer
block|;
name|Program
operator|*
name|mProgram
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|VertexAttribCurrentValueData
operator|>
name|VertexAttribVector
expr_stmt|;
name|VertexAttribVector
name|mVertexAttribCurrentValues
decl_stmt|;
comment|// From glVertexAttrib
name|VertexArray
modifier|*
name|mVertexArray
decl_stmt|;
comment|// Texture and sampler bindings
name|size_t
name|mActiveSampler
decl_stmt|;
comment|// Active texture unit selector - GL_TEXTURE0
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BindingPointer
operator|<
name|Texture
operator|>
expr|>
name|TextureBindingVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GLenum
operator|,
name|TextureBindingVector
operator|>
name|TextureBindingMap
expr_stmt|;
name|TextureBindingMap
name|mSamplerTextures
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BindingPointer
operator|<
name|Sampler
operator|>
expr|>
name|SamplerBindingVector
expr_stmt|;
name|SamplerBindingVector
name|mSamplers
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GLenum
operator|,
name|BindingPointer
operator|<
name|Query
operator|>
expr|>
name|ActiveQueryMap
expr_stmt|;
name|ActiveQueryMap
name|mActiveQueries
decl_stmt|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mGenericUniformBuffer
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|OffsetBindingPointer
operator|<
name|Buffer
operator|>
expr|>
name|BufferVector
expr_stmt|;
name|BufferVector
name|mUniformBuffers
decl_stmt|;
name|BindingPointer
operator|<
name|TransformFeedback
operator|>
name|mTransformFeedback
expr_stmt|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mGenericTransformFeedbackBuffer
expr_stmt|;
name|BufferVector
name|mTransformFeedbackBuffers
decl_stmt|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mCopyReadBuffer
expr_stmt|;
name|BindingPointer
operator|<
name|Buffer
operator|>
name|mCopyWriteBuffer
expr_stmt|;
name|PixelUnpackState
name|mUnpack
decl_stmt|;
name|PixelPackState
name|mPack
decl_stmt|;
name|bool
name|mPrimitiveRestart
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_STATE_H_
end_comment
end_unit
