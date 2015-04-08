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
comment|// Texture.h: Defines the gl::Texture class [OpenGL ES 2.0.24] section 3.7 page 63.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_TEXTURE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_TEXTURE_H_
define|#
directive|define
name|LIBANGLE_TEXTURE_H_
end_define
begin_include
include|#
directive|include
file|"common/debug.h"
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
file|"libANGLE/Constants.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/TextureImpl.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|<map>
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
name|Framebuffer
decl_stmt|;
struct_decl|struct
name|Data
struct_decl|;
name|bool
name|IsMipmapFiltered
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|samplerState
argument_list|)
decl_stmt|;
name|class
name|Texture
name|final
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|Texture
argument_list|(
argument|rx::TextureImpl *impl
argument_list|,
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
name|size_t
name|getWidth
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
specifier|const
block|;
name|size_t
name|getHeight
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
specifier|const
block|;
name|size_t
name|getDepth
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
specifier|const
block|;
name|GLenum
name|getInternalFormat
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
specifier|const
block|;
name|bool
name|isSamplerComplete
argument_list|(
argument|const SamplerState&samplerState
argument_list|,
argument|const Data&data
argument_list|)
specifier|const
block|;
name|bool
name|isCubeComplete
argument_list|()
specifier|const
block|;
name|virtual
name|Error
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const Extents&size
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
block|;
name|virtual
name|Error
name|setSubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const Box&area
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
block|;
name|virtual
name|Error
name|setCompressedImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const Extents&size
argument_list|,
argument|const PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
block|;
name|virtual
name|Error
name|setCompressedSubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const Box&area
argument_list|,
argument|GLenum format
argument_list|,
argument|const PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
block|;
name|virtual
name|Error
name|copyImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const Rectangle&sourceArea
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const Framebuffer *source
argument_list|)
block|;
name|virtual
name|Error
name|copySubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const Offset&destOffset
argument_list|,
argument|const Rectangle&sourceArea
argument_list|,
argument|const Framebuffer *source
argument_list|)
block|;
name|virtual
name|Error
name|setStorage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t levels
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const Extents&size
argument_list|)
block|;
name|virtual
name|Error
name|generateMipmaps
argument_list|()
block|;
comment|// Texture serials provide a unique way of identifying a Texture that isn't a raw pointer.
comment|// "id" is not good enough, as Textures can be deleted, then re-allocated with the same id.
name|unsigned
name|int
name|getTextureSerial
argument_list|()
specifier|const
block|;
name|bool
name|isImmutable
argument_list|()
specifier|const
block|;
name|GLsizei
name|immutableLevelCount
argument_list|()
block|;
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
name|void
name|releaseTexImage
argument_list|()
block|;
name|rx
operator|::
name|TextureImpl
operator|*
name|getImplementation
argument_list|()
block|{
return|return
name|mTexture
return|;
block|}
specifier|const
name|rx
operator|::
name|TextureImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|{
return|return
name|mTexture
return|;
block|}
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
name|private
operator|:
specifier|static
name|unsigned
name|int
name|issueTextureSerial
argument_list|()
block|;
name|rx
operator|::
name|TextureImpl
operator|*
name|mTexture
block|;
name|SamplerState
name|mSamplerState
block|;
name|GLenum
name|mUsage
block|;
name|GLsizei
name|mImmutableLevelCount
block|;
name|GLenum
name|mTarget
block|;       struct
name|ImageDesc
block|{
name|Extents
name|size
block|;
name|GLenum
name|internalFormat
block|;
name|ImageDesc
argument_list|()
block|;
name|ImageDesc
argument_list|(
argument|const Extents&size
argument_list|,
argument|GLenum internalFormat
argument_list|)
block|;     }
block|;
specifier|const
name|unsigned
name|int
name|mTextureSerial
block|;
specifier|static
name|unsigned
name|int
name|mCurrentTextureSerial
block|;
name|GLenum
name|getBaseImageTarget
argument_list|()
specifier|const
block|;
name|size_t
name|getExpectedMipLevels
argument_list|()
specifier|const
block|;
name|bool
name|computeSamplerCompleteness
argument_list|(
argument|const SamplerState&samplerState
argument_list|,
argument|const Data&data
argument_list|)
specifier|const
block|;
name|bool
name|computeMipmapCompleteness
argument_list|(
argument|const gl::SamplerState&samplerState
argument_list|)
specifier|const
block|;
name|bool
name|computeLevelCompleteness
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const gl::SamplerState&samplerState
argument_list|)
specifier|const
block|;
specifier|const
name|ImageDesc
operator|&
name|getImageDesc
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
specifier|const
block|;
name|void
name|setImageDesc
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const ImageDesc&desc
argument_list|)
block|;
name|void
name|setImageDescChain
argument_list|(
argument|size_t levels
argument_list|,
argument|Extents baseSize
argument_list|,
argument|GLenum sizedInternalFormat
argument_list|)
block|;
name|void
name|clearImageDesc
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|)
block|;
name|void
name|clearImageDescs
argument_list|()
block|;
name|std
operator|::
name|vector
operator|<
name|ImageDesc
operator|>
name|mImageDescs
block|;      struct
name|SamplerCompletenessCache
block|{
name|SamplerCompletenessCache
argument_list|()
block|;
name|bool
name|cacheValid
block|;
comment|// All values that affect sampler completeness that are not stored within
comment|// the texture itself
name|SamplerState
name|samplerState
block|;
name|bool
name|filterable
block|;
name|GLint
name|clientVersion
block|;
name|bool
name|supportsNPOT
block|;
comment|// Result of the sampler completeness with the above parameters
name|bool
name|samplerComplete
block|;     }
block|;
name|mutable
name|SamplerCompletenessCache
name|mCompletenessCache
block|;
name|egl
operator|::
name|Surface
operator|*
name|mBoundSurface
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_TEXTURE_H_
end_comment
end_unit
