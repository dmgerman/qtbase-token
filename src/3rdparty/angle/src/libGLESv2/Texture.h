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
begin_include
include|#
directive|include
file|"angle_gl.h"
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
begin_include
include|#
directive|include
file|"libGLESv2/constants.h"
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
name|Texture2DImpl
decl_stmt|;
name|class
name|TextureCubeImpl
decl_stmt|;
name|class
name|Texture3DImpl
decl_stmt|;
name|class
name|Texture2DArrayImpl
decl_stmt|;
name|class
name|TextureStorageInterface
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
name|FramebufferAttachment
decl_stmt|;
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
argument|GLuint id
argument_list|,
argument|GLenum target
argument_list|)
block|;
name|virtual
operator|~
name|Texture
argument_list|()
block|;
name|GLenum
name|getTarget
argument_list|()
specifier|const
block|;
specifier|const
name|SamplerState
operator|&
name|getSamplerState
argument_list|()
specifier|const
block|{
return|return
name|mSamplerState
return|;
block|}
name|SamplerState
operator|&
name|getSamplerState
argument_list|()
block|{
return|return
name|mSamplerState
return|;
block|}
name|void
name|getSamplerStateWithNativeOffset
argument_list|(
name|SamplerState
operator|*
name|sampler
argument_list|)
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|GLenum
name|getUsage
argument_list|()
specifier|const
block|;
name|GLint
name|getBaseLevelWidth
argument_list|()
specifier|const
block|;
name|GLint
name|getBaseLevelHeight
argument_list|()
specifier|const
block|;
name|GLint
name|getBaseLevelDepth
argument_list|()
specifier|const
block|;
name|GLenum
name|getBaseLevelInternalFormat
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isSamplerComplete
argument_list|(
argument|const SamplerState&samplerState
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
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
argument|GLint zoffset
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
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|resetDirty
argument_list|()
operator|=
literal|0
block|;
name|unsigned
name|int
name|getTextureSerial
argument_list|()
block|;
name|bool
name|isImmutable
argument_list|()
specifier|const
block|;
name|int
name|immutableLevelCount
argument_list|()
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
name|int
name|mipLevels
argument_list|()
specifier|const
block|;
name|SamplerState
name|mSamplerState
block|;
name|GLenum
name|mUsage
block|;
name|bool
name|mImmutable
block|;
name|GLenum
name|mTarget
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture
argument_list|)
block|;
name|virtual
specifier|const
name|rx
operator|::
name|Image
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
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
argument|rx::Texture2DImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|Texture2D
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|resetDirty
argument_list|()
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|const PixelUnpackState&unpack
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
argument|GLint zoffset
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
argument_list|(
argument|const SamplerState&samplerState
argument_list|)
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
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|Texture2DAttachment
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|)
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getDepthSencil
argument_list|(
argument|GLint level
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture2D
argument_list|)
block|;
name|virtual
specifier|const
name|rx
operator|::
name|Image
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|void
name|redefineImage
argument_list|(
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|rx
operator|::
name|Texture2DImpl
operator|*
name|mTexture
block|;
name|egl
operator|::
name|Surface
operator|*
name|mSurface
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
argument|rx::TextureCubeImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|TextureCubeMap
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|resetDirty
argument_list|()
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
name|bool
name|isDepth
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|void
name|setCompressedImage
argument_list|(
argument|GLenum target
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
argument|const PixelUnpackState&unpack
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
argument|GLint zoffset
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
argument_list|(
argument|const SamplerState&samplerState
argument_list|)
specifier|const
block|;
name|bool
name|isCubeComplete
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|TextureCubeMapAttachment
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getDepthStencil
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureCubeMap
argument_list|)
block|;
name|virtual
specifier|const
name|rx
operator|::
name|Image
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|rx
operator|::
name|TextureCubeImpl
operator|*
name|mTexture
block|; }
decl_stmt|;
name|class
name|Texture3D
range|:
name|public
name|Texture
block|{
name|public
operator|:
name|Texture3D
argument_list|(
argument|rx::Texture3DImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|Texture3D
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|resetDirty
argument_list|()
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
name|GLsizei
name|getDepth
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
argument|GLsizei depth
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLsizei depth
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
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
argument_list|,
argument|GLsizei depth
argument_list|)
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
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
argument|GLint zoffset
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
name|bool
name|isSamplerComplete
argument_list|(
argument|const SamplerState&samplerState
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isMipmapComplete
argument_list|()
specifier|const
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|Texture3DAttachment
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|)
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getDepthStencil
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture3D
argument_list|)
block|;
name|virtual
specifier|const
name|rx
operator|::
name|Image
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|rx
operator|::
name|Texture3DImpl
operator|*
name|mTexture
block|; }
decl_stmt|;
name|class
name|Texture2DArray
range|:
name|public
name|Texture
block|{
name|public
operator|:
name|Texture2DArray
argument_list|(
argument|rx::Texture2DArrayImpl *impl
argument_list|,
argument|GLuint id
argument_list|)
block|;
operator|~
name|Texture2DArray
argument_list|()
block|;
name|virtual
name|rx
operator|::
name|TextureStorageInterface
operator|*
name|getNativeTexture
argument_list|()
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|;
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|resetDirty
argument_list|()
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
name|GLsizei
name|getLayers
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
argument|GLsizei depth
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLsizei depth
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
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
argument_list|,
argument|GLsizei depth
argument_list|)
block|;
name|virtual
name|void
name|generateMipmaps
argument_list|()
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
argument|GLint zoffset
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
name|bool
name|isSamplerComplete
argument_list|(
argument|const SamplerState&samplerState
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isMipmapComplete
argument_list|()
specifier|const
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|protected
operator|:
name|friend
name|class
name|Texture2DArrayAttachment
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|rx
operator|::
name|RenderTarget
operator|*
name|getDepthStencil
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Texture2DArray
argument_list|)
block|;
name|virtual
specifier|const
name|rx
operator|::
name|Image
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|rx
operator|::
name|Texture2DArrayImpl
operator|*
name|mTexture
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
