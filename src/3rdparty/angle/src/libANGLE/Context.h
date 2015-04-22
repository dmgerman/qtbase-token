begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
name|LIBANGLE_CONTEXT_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_CONTEXT_H_
define|#
directive|define
name|LIBANGLE_CONTEXT_H_
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
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Data.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/HandleAllocator.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/VertexAttribute.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<map>
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
name|Surface
decl_stmt|;
struct_decl|struct
name|Config
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Compiler
decl_stmt|;
name|class
name|Shader
decl_stmt|;
name|class
name|Program
decl_stmt|;
name|class
name|Texture
decl_stmt|;
name|class
name|Framebuffer
decl_stmt|;
name|class
name|Renderbuffer
decl_stmt|;
name|class
name|FenceNV
decl_stmt|;
name|class
name|FenceSync
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
struct_decl|struct
name|VertexAttribute
struct_decl|;
name|class
name|VertexArray
decl_stmt|;
name|class
name|Sampler
decl_stmt|;
name|class
name|TransformFeedback
decl_stmt|;
name|class
name|Context
name|final
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|Context
argument_list|(
argument|const egl::Config *config
argument_list|,
argument|int clientVersion
argument_list|,
argument|const Context *shareContext
argument_list|,
argument|rx::Renderer *renderer
argument_list|,
argument|bool notifyResets
argument_list|,
argument|bool robustAccess
argument_list|)
block|;
name|virtual
operator|~
name|Context
argument_list|()
block|;
name|void
name|makeCurrent
argument_list|(
name|egl
operator|::
name|Surface
operator|*
name|surface
argument_list|)
block|;
name|virtual
name|void
name|markContextLost
argument_list|()
block|;
name|bool
name|isContextLost
argument_list|()
block|;
comment|// These create  and destroy methods are merely pass-throughs to
comment|// ResourceManager, which owns these object types
name|GLuint
name|createBuffer
argument_list|()
block|;
name|GLuint
name|createShader
argument_list|(
argument|GLenum type
argument_list|)
block|;
name|GLuint
name|createProgram
argument_list|()
block|;
name|GLuint
name|createTexture
argument_list|()
block|;
name|GLuint
name|createRenderbuffer
argument_list|()
block|;
name|GLuint
name|createSampler
argument_list|()
block|;
name|GLuint
name|createTransformFeedback
argument_list|()
block|;
name|GLsync
name|createFenceSync
argument_list|()
block|;
name|void
name|deleteBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|deleteShader
argument_list|(
argument|GLuint shader
argument_list|)
block|;
name|void
name|deleteProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|deleteTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|;
name|void
name|deleteRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|;
name|void
name|deleteSampler
argument_list|(
argument|GLuint sampler
argument_list|)
block|;
name|void
name|deleteTransformFeedback
argument_list|(
argument|GLuint transformFeedback
argument_list|)
block|;
name|void
name|deleteFenceSync
argument_list|(
argument|GLsync fenceSync
argument_list|)
block|;
comment|// Framebuffers are owned by the Context, so these methods do not pass through
name|GLuint
name|createFramebuffer
argument_list|()
block|;
name|void
name|deleteFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
comment|// NV Fences are owned by the Context.
name|GLuint
name|createFenceNV
argument_list|()
block|;
name|void
name|deleteFenceNV
argument_list|(
argument|GLuint fence
argument_list|)
block|;
comment|// Queries are owned by the Context;
name|GLuint
name|createQuery
argument_list|()
block|;
name|void
name|deleteQuery
argument_list|(
argument|GLuint query
argument_list|)
block|;
comment|// Vertex arrays are owned by the Context
name|GLuint
name|createVertexArray
argument_list|()
block|;
name|void
name|deleteVertexArray
argument_list|(
argument|GLuint vertexArray
argument_list|)
block|;
name|void
name|bindArrayBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindElementArrayBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindTexture
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint handle
argument_list|)
block|;
name|void
name|bindReadFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
name|void
name|bindDrawFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
name|void
name|bindRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|;
name|void
name|bindVertexArray
argument_list|(
argument|GLuint vertexArray
argument_list|)
block|;
name|void
name|bindSampler
argument_list|(
argument|GLuint textureUnit
argument_list|,
argument|GLuint sampler
argument_list|)
block|;
name|void
name|bindGenericUniformBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindIndexedUniformBuffer
argument_list|(
argument|GLuint buffer
argument_list|,
argument|GLuint index
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|void
name|bindGenericTransformFeedbackBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindIndexedTransformFeedbackBuffer
argument_list|(
argument|GLuint buffer
argument_list|,
argument|GLuint index
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|)
block|;
name|void
name|bindCopyReadBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindCopyWriteBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindPixelPackBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|bindPixelUnpackBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|useProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|bindTransformFeedback
argument_list|(
argument|GLuint transformFeedback
argument_list|)
block|;
name|Error
name|beginQuery
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint query
argument_list|)
block|;
name|Error
name|endQuery
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|setFramebufferZero
argument_list|(
name|Framebuffer
operator|*
name|framebuffer
argument_list|)
block|;
name|void
name|setVertexAttribDivisor
argument_list|(
argument|GLuint index
argument_list|,
argument|GLuint divisor
argument_list|)
block|;
name|void
name|samplerParameteri
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|;
name|void
name|samplerParameterf
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat param
argument_list|)
block|;
name|GLint
name|getSamplerParameteri
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|)
block|;
name|GLfloat
name|getSamplerParameterf
argument_list|(
argument|GLuint sampler
argument_list|,
argument|GLenum pname
argument_list|)
block|;
name|Buffer
operator|*
name|getBuffer
argument_list|(
argument|GLuint handle
argument_list|)
block|;
name|FenceNV
operator|*
name|getFenceNV
argument_list|(
argument|GLuint handle
argument_list|)
block|;
name|FenceSync
operator|*
name|getFenceSync
argument_list|(
argument|GLsync handle
argument_list|)
specifier|const
block|;
name|Shader
operator|*
name|getShader
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Program
operator|*
name|getProgram
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Texture
operator|*
name|getTexture
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Framebuffer
operator|*
name|getFramebuffer
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Renderbuffer
operator|*
name|getRenderbuffer
argument_list|(
argument|GLuint handle
argument_list|)
block|;
name|VertexArray
operator|*
name|getVertexArray
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Sampler
operator|*
name|getSampler
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Query
operator|*
name|getQuery
argument_list|(
argument|GLuint handle
argument_list|,
argument|bool create
argument_list|,
argument|GLenum type
argument_list|)
block|;
name|TransformFeedback
operator|*
name|getTransformFeedback
argument_list|(
argument|GLuint handle
argument_list|)
specifier|const
block|;
name|Texture
operator|*
name|getTargetTexture
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
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
name|Compiler
operator|*
name|getCompiler
argument_list|()
specifier|const
block|;
name|bool
name|isSampler
argument_list|(
argument|GLuint samplerName
argument_list|)
specifier|const
block|;
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
argument|GLenum pname
argument_list|,
argument|GLint *params
argument_list|)
block|;
name|void
name|getInteger64v
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint64 *params
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
name|getQueryParameterInfo
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLenum *type
argument_list|,
argument|unsigned int *numParams
argument_list|)
block|;
name|bool
name|getIndexedQueryParameterInfo
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum *type
argument_list|,
argument|unsigned int *numParams
argument_list|)
block|;
name|Error
name|drawArrays
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instances
argument_list|)
block|;
name|Error
name|drawElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|GLsizei instances
argument_list|,
argument|const rx::RangeUI&indexRange
argument_list|)
block|;
name|Error
name|flush
argument_list|()
block|;
name|Error
name|finish
argument_list|()
block|;
name|void
name|recordError
argument_list|(
specifier|const
name|Error
operator|&
name|error
argument_list|)
block|;
name|GLenum
name|getError
argument_list|()
block|;
name|GLenum
name|getResetStatus
argument_list|()
block|;
name|virtual
name|bool
name|isResetNotificationEnabled
argument_list|()
block|;
name|virtual
name|int
name|getClientVersion
argument_list|()
specifier|const
block|;
name|EGLint
name|getConfigID
argument_list|()
specifier|const
block|;
name|EGLenum
name|getClientType
argument_list|()
specifier|const
block|;
name|EGLenum
name|getRenderBuffer
argument_list|()
specifier|const
block|;
specifier|const
name|Caps
operator|&
name|getCaps
argument_list|()
specifier|const
block|;
specifier|const
name|TextureCapsMap
operator|&
name|getTextureCaps
argument_list|()
specifier|const
block|;
specifier|const
name|Extensions
operator|&
name|getExtensions
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getRendererString
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getExtensionString
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getExtensionString
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
block|;
name|size_t
name|getExtensionStringCount
argument_list|()
specifier|const
block|;
name|rx
operator|::
name|Renderer
operator|*
name|getRenderer
argument_list|()
block|{
return|return
name|mRenderer
return|;
block|}
name|State
operator|&
name|getState
argument_list|()
block|{
return|return
name|mState
return|;
block|}
specifier|const
name|State
operator|&
name|getState
argument_list|()
specifier|const
block|{
return|return
name|mState
return|;
block|}
name|Data
name|getData
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|detachBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|void
name|detachTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|;
name|void
name|detachFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
name|void
name|detachRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|;
name|void
name|detachVertexArray
argument_list|(
argument|GLuint vertexArray
argument_list|)
block|;
name|void
name|detachTransformFeedback
argument_list|(
argument|GLuint transformFeedback
argument_list|)
block|;
name|void
name|detachSampler
argument_list|(
argument|GLuint sampler
argument_list|)
block|;
name|void
name|initRendererString
argument_list|()
block|;
name|void
name|initExtensionStrings
argument_list|()
block|;
name|void
name|initCaps
argument_list|(
argument|GLuint clientVersion
argument_list|)
block|;
comment|// Caps to use for validation
name|Caps
name|mCaps
block|;
name|TextureCapsMap
name|mTextureCaps
block|;
name|Extensions
name|mExtensions
block|;
comment|// Shader compiler
name|Compiler
operator|*
name|mCompiler
block|;
name|rx
operator|::
name|Renderer
operator|*
specifier|const
name|mRenderer
block|;
name|State
name|mState
block|;
name|int
name|mClientVersion
block|;
name|EGLint
name|mConfigID
block|;
name|EGLenum
name|mClientType
block|;
name|EGLenum
name|mRenderBuffer
block|;
name|TextureMap
name|mZeroTextures
block|;
typedef|typedef
name|std
operator|::
name|map
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
name|std
operator|::
name|map
operator|<
name|GLuint
operator|,
name|FenceNV
operator|*
operator|>
name|FenceNVMap
expr_stmt|;
name|FenceNVMap
name|mFenceNVMap
decl_stmt|;
name|HandleAllocator
name|mFenceNVHandleAllocator
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
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
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GLuint
operator|,
name|VertexArray
operator|*
operator|>
name|VertexArrayMap
expr_stmt|;
name|VertexArrayMap
name|mVertexArrayMap
decl_stmt|;
name|HandleAllocator
name|mVertexArrayHandleAllocator
decl_stmt|;
name|BindingPointer
operator|<
name|TransformFeedback
operator|>
name|mTransformFeedbackZero
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GLuint
operator|,
name|TransformFeedback
operator|*
operator|>
name|TransformFeedbackMap
expr_stmt|;
name|TransformFeedbackMap
name|mTransformFeedbackMap
decl_stmt|;
name|HandleAllocator
name|mTransformFeedbackAllocator
decl_stmt|;
name|std
operator|::
name|string
name|mRendererString
expr_stmt|;
name|std
operator|::
name|string
name|mExtensionString
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|mExtensionStrings
expr_stmt|;
comment|// Recorded errors
typedef|typedef
name|std
operator|::
name|set
operator|<
name|GLenum
operator|>
name|ErrorSet
expr_stmt|;
name|ErrorSet
name|mErrors
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
name|ResourceManager
modifier|*
name|mResourceManager
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
comment|// LIBANGLE_CONTEXT_H_
end_comment
end_unit
