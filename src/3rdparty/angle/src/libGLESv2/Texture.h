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
comment|// Texture.h: Defines the abstract gl::Texture class and its concrete derived
end_comment
begin_comment
comment|// classes Texture2D and TextureCubeMap. Implements GL texture objects and
end_comment
begin_comment
comment|// related functionality. [OpenGL ES 2.0.24] section 3.7 page 63.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_TEXTURE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_TEXTURE_H_
define|#
directive|define
name|LIBGLESV2_TEXTURE_H_
end_define
begin_include
include|#
directive|include
file|<vector>
end_include
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
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/RefCountObject.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/angletypes.h"
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Surface
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer
decl_stmt|;
name|class
name|TextureStorageInterface
decl_stmt|;
name|class
name|TextureStorageInterface2D
decl_stmt|;
name|class
name|TextureStorageInterfaceCube
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|Image
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
name|class
name|Renderbuffer
decl_stmt|;
enum|enum
block|{
comment|// These are the maximums the implementation can support
comment|// The actual GL caps are limited by the device caps
comment|// and should be queried from the Context
name|IMPLEMENTATION_MAX_TEXTURE_SIZE
init|=
literal|16384
block|,
name|IMPLEMENTATION_MAX_CUBE_MAP_TEXTURE_SIZE
init|=
literal|16384
block|,
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
init|=
literal|15
comment|// 1+log2 of MAX_TEXTURE_SIZE
block|}
enum|;
name|class
name|Texture
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|Texture
argument_list|(
argument|rx::Renderer *renderer
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|virtual
operator|~
name|Texture
argument_list|()
block|;
name|virtual
name|void
name|addProxyRef
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|releaseProxy
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|GLenum
name|getTarget
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|bool
name|setMinFilter
argument_list|(
argument|GLenum filter
argument_list|)
block|;
name|bool
name|setMagFilter
argument_list|(
argument|GLenum filter
argument_list|)
block|;
name|bool
name|setWrapS
argument_list|(
argument|GLenum wrap
argument_list|)
block|;
name|bool
name|setWrapT
argument_list|(
argument|GLenum wrap
argument_list|)
block|;
name|bool
name|setMaxAnisotropy
argument_list|(
argument|float textureMaxAnisotropy
argument_list|,
argument|float contextMaxAnisotropy
argument_list|)
block|;
name|bool
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|GLenum
name|getMinFilter
argument_list|()
specifier|const
block|;
name|GLenum
name|getMagFilter
argument_list|()
specifier|const
block|;
name|GLenum
name|getWrapS
argument_list|()
specifier|const
block|;
name|GLenum
name|getWrapT
argument_list|()
specifier|const
block|;
name|float
name|getMaxAnisotropy
argument_list|()
specifier|const
block|;
name|int
name|getLodOffset
argument_list|()
block|;
name|void
name|getSamplerState
argument_list|(
name|SamplerState
operator|*
name|sampler
argument_list|)
block|;
name|GLenum
name|getUsage
argument_list|()
specifier|const
block|;
name|bool
name|isMipmapFiltered
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isSamplerComplete
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
block|;
name|virtual
name|Renderbuffer
operator|*
name|getRenderbuffer
argument_list|(
argument|GLenum target
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|copySubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|Framebuffer *source
argument_list|)
operator|=
literal|0
block|;
name|bool
name|hasDirtyParameters
argument_list|()
specifier|const
block|;
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|;
name|void
name|resetDirty
argument_list|()
block|;
name|unsigned
name|int
name|getTextureSerial
argument_list|()
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|bool
name|isImmutable
argument_list|()
specifier|const
block|;
specifier|static
specifier|const
name|GLuint
name|INCOMPLETE_TEXTURE_ID
operator|=
name|static_cast
operator|<
name|GLuint
operator|>
operator|(
operator|-
literal|1
operator|)
block|;
comment|// Every texture takes an id at creation time. The value is arbitrary because it is never registered with the resource manager.
name|protected
operator|:
name|void
name|setImage
argument_list|(
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|,
argument|rx::Image *image
argument_list|)
block|;
name|bool
name|subImage
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|,
argument|rx::Image *image
argument_list|)
block|;
name|void
name|setCompressedImage
argument_list|(
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|,
argument|rx::Image *image
argument_list|)
block|;
name|bool
name|subImageCompressed
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|,
argument|rx::Image *image
argument_list|)
block|;
name|GLint
name|creationLevels
argument_list|(
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
specifier|const
block|;
name|GLint
name|creationLevels
argument_list|(
argument|GLsizei size
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|createTexture
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|updateTexture
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|convertToRenderTarget
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|levelCount
argument_list|()
operator|=
literal|0
block|;
name|rx
operator|::
name|Renderer
operator|*
name|mRenderer
block|;
name|SamplerState
name|mSamplerState
block|;
name|GLenum
name|mUsage
block|;
name|bool
name|mDirtyImages
block|;
name|bool
name|mImmutable
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture
argument_list|)
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getStorage
argument_list|(
argument|bool renderTarget
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|Texture2D
range|:
name|public
name|Texture
block|{
name|public
operator|:
name|Texture2D
argument_list|(
argument|rx::Renderer *renderer
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|Texture2D
argument_list|()
block|;
name|void
name|addProxyRef
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
block|;
name|void
name|releaseProxy
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
block|;
name|virtual
name|GLenum
name|getTarget
argument_list|()
specifier|const
block|;
name|GLsizei
name|getWidth
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLsizei
name|getHeight
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLenum
name|getInternalFormat
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLenum
name|getActualFormat
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|bool
name|isCompressed
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|bool
name|isDepth
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|void
name|setImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setCompressedImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|subImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|subImageCompressed
argument_list|(
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|copyImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLenum format
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|copySubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|Framebuffer *source
argument_list|)
block|;
name|void
name|storage
argument_list|(
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|virtual
name|bool
name|isSamplerComplete
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|bindTexImage
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
name|releaseTexImage
argument_list|()
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
block|;
name|virtual
name|Renderbuffer
operator|*
name|getRenderbuffer
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|RenderbufferTexture2D
block|;
name|virtual
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|virtual
name|rx
operator|::
name|RenderTarget
operator|*
name|getDepthStencil
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|virtual
name|int
name|levelCount
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture2D
argument_list|)
block|;
name|virtual
name|void
name|createTexture
argument_list|()
block|;
name|virtual
name|void
name|updateTexture
argument_list|()
block|;
name|virtual
name|void
name|convertToRenderTarget
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|bool
name|isMipmapComplete
argument_list|()
specifier|const
block|;
name|void
name|redefineImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|commitRect
argument_list|(
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|rx
operator|::
name|Image
operator|*
name|mImageArray
index|[
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|rx
operator|::
name|TextureStorageInterface2D
operator|*
name|mTexStorage
block|;
name|egl
operator|::
name|Surface
operator|*
name|mSurface
block|;
comment|// A specific internal reference count is kept for colorbuffer proxy references,
comment|// because, as the renderbuffer acting as proxy will maintain a binding pointer
comment|// back to this texture, there would be a circular reference if we used a binding
comment|// pointer here. This reference count will cause the pointer to be set to NULL if
comment|// the count drops to zero, but will not cause deletion of the Renderbuffer.
name|Renderbuffer
operator|*
name|mColorbufferProxy
block|;
name|unsigned
name|int
name|mProxyRefs
block|; }
decl_stmt|;
name|class
name|TextureCubeMap
range|:
name|public
name|Texture
block|{
name|public
operator|:
name|TextureCubeMap
argument_list|(
argument|rx::Renderer *renderer
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|TextureCubeMap
argument_list|()
block|;
name|void
name|addProxyRef
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
block|;
name|void
name|releaseProxy
argument_list|(
specifier|const
name|Renderbuffer
operator|*
name|proxy
argument_list|)
block|;
name|virtual
name|GLenum
name|getTarget
argument_list|()
specifier|const
block|;
name|GLsizei
name|getWidth
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLsizei
name|getHeight
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLenum
name|getInternalFormat
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|GLenum
name|getActualFormat
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|bool
name|isCompressed
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|void
name|setImagePosX
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setImageNegX
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setImagePosY
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setImageNegY
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setImagePosZ
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setImageNegZ
argument_list|(
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setCompressedImage
argument_list|(
argument|GLenum face
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|subImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|subImageCompressed
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|copyImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum format
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|copySubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|Framebuffer *source
argument_list|)
block|;
name|void
name|storage
argument_list|(
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei size
argument_list|)
block|;
name|virtual
name|bool
name|isSamplerComplete
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
block|;
name|virtual
name|Renderbuffer
operator|*
name|getRenderbuffer
argument_list|(
argument|GLenum target
argument_list|)
block|;
specifier|static
name|unsigned
name|int
name|faceIndex
argument_list|(
argument|GLenum face
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|RenderbufferTextureCubeMap
block|;
name|virtual
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|virtual
name|int
name|levelCount
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureCubeMap
argument_list|)
block|;
name|virtual
name|void
name|createTexture
argument_list|()
block|;
name|virtual
name|void
name|updateTexture
argument_list|()
block|;
name|virtual
name|void
name|convertToRenderTarget
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|bool
name|isCubeComplete
argument_list|()
specifier|const
block|;
name|bool
name|isMipmapCubeComplete
argument_list|()
specifier|const
block|;
name|void
name|setImage
argument_list|(
argument|int faceIndex
argument_list|,
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|commitRect
argument_list|(
argument|int faceIndex
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|redefineImage
argument_list|(
argument|int faceIndex
argument_list|,
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|rx
operator|::
name|Image
operator|*
name|mImageArray
index|[
literal|6
index|]
index|[
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|rx
operator|::
name|TextureStorageInterfaceCube
operator|*
name|mTexStorage
block|;
comment|// A specific internal reference count is kept for colorbuffer proxy references,
comment|// because, as the renderbuffer acting as proxy will maintain a binding pointer
comment|// back to this texture, there would be a circular reference if we used a binding
comment|// pointer here. This reference count will cause the pointer to be set to NULL if
comment|// the count drops to zero, but will not cause deletion of the Renderbuffer.
name|Renderbuffer
operator|*
name|mFaceProxies
index|[
literal|6
index|]
block|;
name|unsigned
name|int
operator|*
name|mFaceProxyRefs
index|[
literal|6
index|]
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_TEXTURE_H_
end_comment
end_unit
