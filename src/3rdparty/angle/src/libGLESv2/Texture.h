begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
file|<d3d9.h>
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
file|"libGLESv2/Renderbuffer.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/utilities.h"
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
name|gl
block|{
name|class
name|Blit
decl_stmt|;
name|class
name|Framebuffer
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
name|Image
block|{
name|public
label|:
name|Image
argument_list|()
expr_stmt|;
operator|~
name|Image
argument_list|()
expr_stmt|;
name|bool
name|redefine
parameter_list|(
name|GLint
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|bool
name|forceRelease
parameter_list|)
function_decl|;
name|void
name|markDirty
parameter_list|()
block|{
name|mDirty
operator|=
name|true
expr_stmt|;
block|}
name|void
name|markClean
parameter_list|()
block|{
name|mDirty
operator|=
name|false
expr_stmt|;
block|}
name|bool
name|isRenderableFormat
argument_list|()
specifier|const
expr_stmt|;
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
expr_stmt|;
name|GLsizei
name|getWidth
argument_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
name|GLsizei
name|getHeight
argument_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
name|GLenum
name|getInternalFormat
argument_list|()
specifier|const
block|{
return|return
name|mInternalFormat
return|;
block|}
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
name|mSurface
operator|&&
name|mDirty
return|;
block|}
name|IDirect3DSurface9
modifier|*
name|getSurface
parameter_list|()
function_decl|;
name|void
name|setManagedSurface
parameter_list|(
name|IDirect3DSurface9
modifier|*
name|surface
parameter_list|)
function_decl|;
name|void
name|updateSurface
parameter_list|(
name|IDirect3DSurface9
modifier|*
name|dest
parameter_list|,
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|)
function_decl|;
name|void
name|loadData
parameter_list|(
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLint
name|unpackAlignment
parameter_list|,
specifier|const
name|void
modifier|*
name|input
parameter_list|)
function_decl|;
name|void
name|loadAlphaData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadAlphaDataSSE2
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadAlphaFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadAlphaHalfFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|,
name|bool
name|native
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceHalfFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceAlphaData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|,
name|bool
name|native
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceAlphaFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadLuminanceAlphaHalfFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBUByteData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGB565Data
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBHalfFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBAUByteDataSSE2
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBAUByteData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBA4444Data
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBA5551Data
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBAFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadRGBAHalfFloatData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadBGRAData
argument_list|(
name|GLsizei
name|width
argument_list|,
name|GLsizei
name|height
argument_list|,
name|int
name|inputPitch
argument_list|,
specifier|const
name|void
operator|*
name|input
argument_list|,
name|size_t
name|outputPitch
argument_list|,
name|void
operator|*
name|output
argument_list|)
decl|const
decl_stmt|;
name|void
name|loadCompressedData
parameter_list|(
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
specifier|const
name|void
modifier|*
name|input
parameter_list|)
function_decl|;
name|void
name|copy
parameter_list|(
name|GLint
name|xoffset
parameter_list|,
name|GLint
name|yoffset
parameter_list|,
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
name|IDirect3DSurface9
modifier|*
name|renderTarget
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Image
argument_list|)
expr_stmt|;
name|void
name|createSurface
parameter_list|()
function_decl|;
name|HRESULT
name|lock
parameter_list|(
name|D3DLOCKED_RECT
modifier|*
name|lockedRect
parameter_list|,
specifier|const
name|RECT
modifier|*
name|rect
parameter_list|)
function_decl|;
name|void
name|unlock
parameter_list|()
function_decl|;
name|GLsizei
name|mWidth
decl_stmt|;
name|GLsizei
name|mHeight
decl_stmt|;
name|GLint
name|mInternalFormat
decl_stmt|;
name|bool
name|mDirty
decl_stmt|;
name|D3DPOOL
name|mD3DPool
decl_stmt|;
comment|// can only be D3DPOOL_SYSTEMMEM or D3DPOOL_MANAGED since it needs to be lockable.
name|D3DFORMAT
name|mD3DFormat
decl_stmt|;
name|IDirect3DSurface9
modifier|*
name|mSurface
decl_stmt|;
block|}
empty_stmt|;
name|class
name|TextureStorage
block|{
name|public
label|:
name|explicit
name|TextureStorage
parameter_list|(
name|DWORD
name|usage
parameter_list|)
function_decl|;
name|virtual
operator|~
name|TextureStorage
argument_list|()
expr_stmt|;
name|bool
name|isRenderTarget
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isManaged
argument_list|()
specifier|const
expr_stmt|;
name|D3DPOOL
name|getPool
argument_list|()
specifier|const
expr_stmt|;
name|DWORD
name|getUsage
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|int
name|getTextureSerial
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
name|GLenum
name|target
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|int
name|getLodOffset
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|int
name|mLodOffset
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage
argument_list|)
expr_stmt|;
specifier|const
name|DWORD
name|mD3DUsage
decl_stmt|;
specifier|const
name|D3DPOOL
name|mD3DPool
decl_stmt|;
specifier|const
name|unsigned
name|int
name|mTextureSerial
decl_stmt|;
specifier|static
name|unsigned
name|int
name|issueTextureSerial
parameter_list|()
function_decl|;
specifier|static
name|unsigned
name|int
name|mCurrentTextureSerial
decl_stmt|;
block|}
empty_stmt|;
name|class
name|Texture
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|explicit
name|Texture
argument_list|(
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
name|GLenum
name|getUsage
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
name|IDirect3DBaseTexture9
operator|*
name|getTexture
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
name|int
name|getLodOffset
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
name|void
name|setImage
argument_list|(
argument|GLint unpackAlignment
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
argument|Image *image
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
argument|Image *image
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
name|IDirect3DBaseTexture9
operator|*
name|getBaseTexture
argument_list|()
specifier|const
operator|=
literal|0
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
name|IDirect3DSurface9
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|)
operator|=
literal|0
block|;
name|int
name|levelCount
argument_list|()
block|;
specifier|static
name|Blit
operator|*
name|getBlitter
argument_list|()
block|;
specifier|static
name|bool
name|copyToRenderTarget
argument_list|(
argument|IDirect3DSurface9 *dest
argument_list|,
argument|IDirect3DSurface9 *source
argument_list|,
argument|bool fromManaged
argument_list|)
block|;
name|GLenum
name|mMinFilter
block|;
name|GLenum
name|mMagFilter
block|;
name|GLenum
name|mWrapS
block|;
name|GLenum
name|mWrapT
block|;
name|float
name|mMaxAnisotropy
block|;
name|bool
name|mDirtyParameters
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
name|TextureStorage
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
name|TextureStorage2D
range|:
name|public
name|TextureStorage
block|{
name|public
operator|:
name|explicit
name|TextureStorage2D
argument_list|(
name|IDirect3DTexture9
operator|*
name|surfaceTexture
argument_list|)
block|;
name|TextureStorage2D
argument_list|(
argument|int levels
argument_list|,
argument|D3DFORMAT format
argument_list|,
argument|DWORD usage
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage2D
argument_list|()
block|;
name|IDirect3DSurface9
operator|*
name|getSurfaceLevel
argument_list|(
argument|int level
argument_list|,
argument|bool dirty
argument_list|)
block|;
name|IDirect3DBaseTexture9
operator|*
name|getBaseTexture
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage2D
argument_list|)
block|;
name|IDirect3DTexture9
operator|*
name|mTexture
block|;
specifier|const
name|unsigned
name|int
name|mRenderTargetSerial
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
name|explicit
name|Texture2D
argument_list|(
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
name|D3DFORMAT
name|getD3DFormat
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
name|IDirect3DSurface9
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|virtual
name|IDirect3DSurface9
operator|*
name|getDepthStencil
argument_list|(
argument|GLenum target
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
name|IDirect3DBaseTexture9
operator|*
name|getBaseTexture
argument_list|()
specifier|const
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
name|TextureStorage
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
name|Image
name|mImageArray
index|[
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|TextureStorage2D
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
name|TextureStorageCubeMap
range|:
name|public
name|TextureStorage
block|{
name|public
operator|:
name|TextureStorageCubeMap
argument_list|(
argument|int levels
argument_list|,
argument|D3DFORMAT format
argument_list|,
argument|DWORD usage
argument_list|,
argument|int size
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorageCubeMap
argument_list|()
block|;
name|IDirect3DSurface9
operator|*
name|getCubeMapSurface
argument_list|(
argument|GLenum faceTarget
argument_list|,
argument|int level
argument_list|,
argument|bool dirty
argument_list|)
block|;
name|IDirect3DBaseTexture9
operator|*
name|getBaseTexture
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLenum target
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageCubeMap
argument_list|)
block|;
name|IDirect3DCubeTexture9
operator|*
name|mTexture
block|;
specifier|const
name|unsigned
name|int
name|mFirstRenderTargetSerial
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
name|explicit
name|TextureCubeMap
argument_list|(
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
name|D3DFORMAT
name|getD3DFormat
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
name|IDirect3DSurface9
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum target
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
name|IDirect3DBaseTexture9
operator|*
name|getBaseTexture
argument_list|()
specifier|const
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
name|TextureStorage
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
name|Image
name|mImageArray
index|[
literal|6
index|]
index|[
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|TextureStorageCubeMap
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
