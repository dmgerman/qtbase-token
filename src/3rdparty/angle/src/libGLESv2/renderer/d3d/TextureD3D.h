begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// TextureD3D.h: Implementations of the Texture interfaces shared betweeen the D3D backends.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTURED3D_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTURED3D_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTURED3D_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/TextureImpl.h"
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
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Image
decl_stmt|;
name|class
name|ImageD3D
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|TextureD3D
range|:
name|public
name|TextureImpl
block|{
name|public
operator|:
name|TextureD3D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|TextureD3D
argument_list|()
block|;
specifier|static
name|TextureD3D
operator|*
name|makeTextureD3D
argument_list|(
name|TextureImpl
operator|*
name|texture
argument_list|)
block|;
name|virtual
name|TextureStorage
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
block|{
name|mUsage
operator|=
name|usage
block|; }
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|{
return|return
name|mDirtyImages
return|;
block|}
name|void
name|resetDirty
argument_list|()
block|{
name|mDirtyImages
operator|=
name|false
block|; }
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
name|bool
name|isImmutable
argument_list|()
specifier|const
block|{
return|return
name|mImmutable
return|;
block|}
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|void
name|setImage
argument_list|(
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *pixels
argument_list|,
argument|Image *image
argument_list|)
block|;
name|bool
name|subImage
argument_list|(
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|,
argument|const gl::ImageIndex&index
argument_list|)
block|;
name|void
name|setCompressedImage
argument_list|(
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|,
argument|Image *image
argument_list|)
block|;
name|bool
name|subImageCompressed
argument_list|(
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
argument_list|,
argument|Image *image
argument_list|)
block|;
name|bool
name|isFastUnpackable
argument_list|(
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|GLenum sizedInternalFormat
argument_list|)
block|;
name|bool
name|fastUnpackPixels
argument_list|(
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|,
argument|const gl::Box&destArea
argument_list|,
argument|GLenum sizedInternalFormat
argument_list|,
argument|GLenum type
argument_list|,
argument|RenderTarget *destRenderTarget
argument_list|)
block|;
name|GLint
name|creationLevels
argument_list|(
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|)
specifier|const
block|;
name|int
name|mipLevels
argument_list|()
specifier|const
block|;
name|Renderer
operator|*
name|mRenderer
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
name|TextureD3D
argument_list|)
block|;
name|virtual
name|void
name|initializeStorage
argument_list|(
argument|bool renderTarget
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|updateStorage
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|TextureStorage
operator|*
name|getBaseLevelStorage
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|ImageD3D
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
name|class
name|TextureD3D_2D
range|:
name|public
name|TextureD3D
block|{
name|public
operator|:
name|TextureD3D_2D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|TextureD3D_2D
argument_list|()
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|int level
argument_list|,
argument|int layer
argument_list|)
specifier|const
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|const gl::ImageIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
argument|int level
argument_list|)
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
name|isDepth
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|GLsizei depth
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
name|virtual
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
argument|gl::Framebuffer *source
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
argument|gl::Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|storage
argument_list|(
argument|GLenum target
argument_list|,
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
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureD3D_2D
argument_list|)
block|;
name|virtual
name|void
name|initializeStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|TextureStorage
operator|*
name|createCompleteStorage
argument_list|(
argument|bool renderTarget
argument_list|)
specifier|const
block|;
name|void
name|setCompleteTexStorage
argument_list|(
name|TextureStorage
operator|*
name|newCompleteTexStorage
argument_list|)
block|;
name|virtual
name|void
name|updateStorage
argument_list|()
block|;
name|bool
name|ensureRenderTarget
argument_list|()
block|;
name|virtual
name|TextureStorage
operator|*
name|getBaseLevelStorage
argument_list|()
block|;
name|virtual
specifier|const
name|ImageD3D
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|bool
name|isValidLevel
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|bool
name|isLevelComplete
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|void
name|updateStorageLevel
argument_list|(
argument|int level
argument_list|)
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
name|TextureStorage
operator|*
name|mTexStorage
block|;
name|ImageD3D
operator|*
name|mImageArray
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|; }
decl_stmt|;
name|class
name|TextureD3D_Cube
range|:
name|public
name|TextureD3D
block|{
name|public
operator|:
name|TextureD3D_Cube
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|TextureD3D_Cube
argument_list|()
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|int level
argument_list|,
argument|int layer
argument_list|)
specifier|const
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|const gl::ImageIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasDirtyImages
argument_list|()
specifier|const
block|{
return|return
name|mDirtyImages
return|;
block|}
name|virtual
name|void
name|resetDirty
argument_list|()
block|{
name|mDirtyImages
operator|=
name|false
block|; }
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
block|{
name|mUsage
operator|=
name|usage
block|; }
name|GLenum
name|getInternalFormat
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|bool
name|isDepth
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|GLsizei depth
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
name|virtual
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
argument|gl::Framebuffer *source
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
argument|gl::Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|storage
argument_list|(
argument|GLenum target
argument_list|,
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
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureD3D_Cube
argument_list|)
block|;
name|virtual
name|void
name|initializeStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|TextureStorage
operator|*
name|createCompleteStorage
argument_list|(
argument|bool renderTarget
argument_list|)
specifier|const
block|;
name|void
name|setCompleteTexStorage
argument_list|(
name|TextureStorage
operator|*
name|newCompleteTexStorage
argument_list|)
block|;
name|virtual
name|void
name|updateStorage
argument_list|()
block|;
name|bool
name|ensureRenderTarget
argument_list|()
block|;
name|virtual
name|TextureStorage
operator|*
name|getBaseLevelStorage
argument_list|()
block|;
name|virtual
specifier|const
name|ImageD3D
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|bool
name|isValidFaceLevel
argument_list|(
argument|int faceIndex
argument_list|,
argument|int level
argument_list|)
specifier|const
block|;
name|bool
name|isFaceLevelComplete
argument_list|(
argument|int faceIndex
argument_list|,
argument|int level
argument_list|)
specifier|const
block|;
name|bool
name|isCubeComplete
argument_list|()
specifier|const
block|;
name|void
name|updateStorageFaceLevel
argument_list|(
argument|int faceIndex
argument_list|,
argument|int level
argument_list|)
block|;
name|void
name|redefineImage
argument_list|(
argument|int faceIndex
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
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
name|ImageD3D
operator|*
name|mImageArray
index|[
literal|6
index|]
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|TextureStorage
operator|*
name|mTexStorage
block|; }
decl_stmt|;
name|class
name|TextureD3D_3D
range|:
name|public
name|TextureD3D
block|{
name|public
operator|:
name|TextureD3D_3D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|TextureD3D_3D
argument_list|()
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|int level
argument_list|,
argument|int layer
argument_list|)
specifier|const
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|const gl::ImageIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
argument|int level
argument_list|)
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
name|bool
name|isDepth
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|GLsizei depth
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
name|virtual
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
argument|gl::Framebuffer *source
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
argument|gl::Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|storage
argument_list|(
argument|GLenum target
argument_list|,
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
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureD3D_3D
argument_list|)
block|;
name|virtual
name|void
name|initializeStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|TextureStorage
operator|*
name|createCompleteStorage
argument_list|(
argument|bool renderTarget
argument_list|)
specifier|const
block|;
name|void
name|setCompleteTexStorage
argument_list|(
name|TextureStorage
operator|*
name|newCompleteTexStorage
argument_list|)
block|;
name|virtual
name|void
name|updateStorage
argument_list|()
block|;
name|bool
name|ensureRenderTarget
argument_list|()
block|;
name|virtual
name|TextureStorage
operator|*
name|getBaseLevelStorage
argument_list|()
block|;
name|virtual
specifier|const
name|ImageD3D
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|bool
name|isValidLevel
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|bool
name|isLevelComplete
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|void
name|updateStorageLevel
argument_list|(
argument|int level
argument_list|)
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
argument_list|,
argument|GLsizei depth
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|)
block|;
name|ImageD3D
operator|*
name|mImageArray
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|TextureStorage
operator|*
name|mTexStorage
block|; }
decl_stmt|;
name|class
name|TextureD3D_2DArray
range|:
name|public
name|TextureD3D
block|{
name|public
operator|:
name|TextureD3D_2DArray
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|TextureD3D_2DArray
argument_list|()
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|int level
argument_list|,
argument|int layer
argument_list|)
specifier|const
block|;
name|virtual
name|Image
operator|*
name|getImage
argument_list|(
argument|const gl::ImageIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
argument|int level
argument_list|)
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
name|bool
name|isDepth
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|GLsizei depth
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
block|;
name|virtual
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
name|virtual
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
argument|gl::Framebuffer *source
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
argument|gl::Framebuffer *source
argument_list|)
block|;
name|virtual
name|void
name|storage
argument_list|(
argument|GLenum target
argument_list|,
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
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureD3D_2DArray
argument_list|)
block|;
name|virtual
name|void
name|initializeStorage
argument_list|(
argument|bool renderTarget
argument_list|)
block|;
name|TextureStorage
operator|*
name|createCompleteStorage
argument_list|(
argument|bool renderTarget
argument_list|)
specifier|const
block|;
name|void
name|setCompleteTexStorage
argument_list|(
name|TextureStorage
operator|*
name|newCompleteTexStorage
argument_list|)
block|;
name|virtual
name|void
name|updateStorage
argument_list|()
block|;
name|bool
name|ensureRenderTarget
argument_list|()
block|;
name|virtual
name|TextureStorage
operator|*
name|getBaseLevelStorage
argument_list|()
block|;
name|virtual
specifier|const
name|ImageD3D
operator|*
name|getBaseLevelImage
argument_list|()
specifier|const
block|;
name|bool
name|isValidLevel
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|bool
name|isLevelComplete
argument_list|(
argument|int level
argument_list|)
specifier|const
block|;
name|void
name|updateStorageLevel
argument_list|(
argument|int level
argument_list|)
block|;
name|void
name|deleteImages
argument_list|()
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
argument_list|,
argument|GLsizei depth
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
argument|GLint layerTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
comment|// Storing images as an array of single depth textures since D3D11 treats each array level of a
comment|// Texture2D object as a separate subresource.  Each layer would have to be looped over
comment|// to update all the texture layers since they cannot all be updated at once and it makes the most
comment|// sense for the Image class to not have to worry about layer subresource as well as mip subresources.
name|GLsizei
name|mLayerCounts
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|ImageD3D
operator|*
operator|*
name|mImageArray
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|TextureStorage
operator|*
name|mTexStorage
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTURED3D_H_
end_comment
end_unit
