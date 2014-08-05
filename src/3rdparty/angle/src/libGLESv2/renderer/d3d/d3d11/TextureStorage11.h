begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// TextureStorage11.h: Defines the abstract rx::TextureStorage11 class and its concrete derived
end_comment
begin_comment
comment|// classes TextureStorage11_2D and TextureStorage11_Cube, which act as the interface to the D3D11 texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTURESTORAGE11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTURESTORAGE11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTURESTORAGE11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/TextureStorage.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RenderTarget
decl_stmt|;
name|class
name|RenderTarget11
decl_stmt|;
name|class
name|Renderer
decl_stmt|;
name|class
name|Renderer11
decl_stmt|;
name|class
name|SwapChain11
decl_stmt|;
name|class
name|TextureStorage11
range|:
name|public
name|TextureStorage
block|{
name|public
operator|:
name|virtual
operator|~
name|TextureStorage11
argument_list|()
block|;
specifier|static
name|TextureStorage11
operator|*
name|makeTextureStorage11
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
specifier|static
name|DWORD
name|GetTextureBindFlags
argument_list|(
argument|GLenum internalFormat
argument_list|,
argument|bool renderTarget
argument_list|)
block|;
name|UINT
name|getBindFlags
argument_list|()
specifier|const
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getResource
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|getSRV
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|samplerState
argument_list|)
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|int level
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|RenderTarget
operator|*
name|getRenderTargetFace
argument_list|(
argument|GLenum faceTarget
argument_list|,
argument|int level
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|RenderTarget
operator|*
name|getRenderTargetLayer
argument_list|(
argument|int mipLevel
argument_list|,
argument|int layer
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int face
argument_list|,
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|int
name|getTopLevel
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isRenderTarget
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isManaged
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|getLevelCount
argument_list|()
specifier|const
block|;
name|UINT
name|getSubresourceIndex
argument_list|(
argument|int mipLevel
argument_list|,
argument|int layerTarget
argument_list|)
specifier|const
block|;
name|void
name|generateSwizzles
argument_list|(
argument|GLenum swizzleRed
argument_list|,
argument|GLenum swizzleGreen
argument_list|,
argument|GLenum swizzleBlue
argument_list|,
argument|GLenum swizzleAlpha
argument_list|)
block|;
name|void
name|invalidateSwizzleCacheLevel
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|void
name|invalidateSwizzleCache
argument_list|()
block|;
name|bool
name|updateSubresourceLevel
argument_list|(
argument|ID3D11Resource *texture
argument_list|,
argument|unsigned int sourceSubresource
argument_list|,
argument|int level
argument_list|,
argument|int layerTarget
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
name|protected
operator|:
name|TextureStorage11
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|UINT bindFlags
argument_list|)
block|;
name|void
name|generateMipmapLayer
argument_list|(
name|RenderTarget11
operator|*
name|source
argument_list|,
name|RenderTarget11
operator|*
name|dest
argument_list|)
block|;
name|int
name|getLevelWidth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|int
name|getLevelHeight
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|int
name|getLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getSwizzleTexture
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getSwizzleRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
operator|=
literal|0
block|;
name|ID3D11ShaderResourceView
operator|*
name|getSRVLevel
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|createSRV
argument_list|(
argument|int baseLevel
argument_list|,
argument|int mipLevels
argument_list|,
argument|DXGI_FORMAT format
argument_list|,
argument|ID3D11Resource *texture
argument_list|)
operator|=
literal|0
block|;
name|void
name|verifySwizzleExists
argument_list|(
argument|GLenum swizzleRed
argument_list|,
argument|GLenum swizzleGreen
argument_list|,
argument|GLenum swizzleBlue
argument_list|,
argument|GLenum swizzleAlpha
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getTextureLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|Renderer11
operator|*
name|mRenderer
block|;
name|int
name|mTopLevel
block|;
name|unsigned
name|int
name|mMipLevels
block|;
name|DXGI_FORMAT
name|mTextureFormat
block|;
name|DXGI_FORMAT
name|mShaderResourceFormat
block|;
name|DXGI_FORMAT
name|mRenderTargetFormat
block|;
name|DXGI_FORMAT
name|mDepthStencilFormat
block|;
name|DXGI_FORMAT
name|mSwizzleTextureFormat
block|;
name|DXGI_FORMAT
name|mSwizzleShaderResourceFormat
block|;
name|DXGI_FORMAT
name|mSwizzleRenderTargetFormat
block|;
name|unsigned
name|int
name|mTextureWidth
block|;
name|unsigned
name|int
name|mTextureHeight
block|;
name|unsigned
name|int
name|mTextureDepth
block|;      struct
name|SwizzleCacheValue
block|{
name|GLenum
name|swizzleRed
block|;
name|GLenum
name|swizzleGreen
block|;
name|GLenum
name|swizzleBlue
block|;
name|GLenum
name|swizzleAlpha
block|;
name|SwizzleCacheValue
argument_list|()
block|;
name|SwizzleCacheValue
argument_list|(
argument|GLenum red
argument_list|,
argument|GLenum green
argument_list|,
argument|GLenum blue
argument_list|,
argument|GLenum alpha
argument_list|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SwizzleCacheValue
operator|&
name|other
operator|)
specifier|const
block|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SwizzleCacheValue
operator|&
name|other
operator|)
specifier|const
block|;     }
block|;
name|SwizzleCacheValue
name|mSwizzleCache
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;      struct
name|SRVKey
block|{
name|SRVKey
argument_list|(
argument|int baseLevel =
literal|0
argument_list|,
argument|int mipLevels =
literal|0
argument_list|,
argument|bool swizzle = false
argument_list|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SRVKey
operator|&
name|rhs
operator|)
specifier|const
block|;
name|int
name|baseLevel
block|;
name|int
name|mipLevels
block|;
name|bool
name|swizzle
block|;     }
block|;      struct
name|SRVPair
block|{
name|SRVKey
name|key
block|;
name|ID3D11ShaderResourceView
operator|*
name|srv
block|;     }
block|;      struct
name|SRVCache
block|{
operator|~
name|SRVCache
argument_list|()
block|;
name|ID3D11ShaderResourceView
operator|*
name|find
argument_list|(
argument|const SRVKey&key
argument_list|)
specifier|const
block|;
name|ID3D11ShaderResourceView
operator|*
name|add
argument_list|(
specifier|const
name|SRVKey
operator|&
name|key
argument_list|,
name|ID3D11ShaderResourceView
operator|*
name|srv
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|SRVPair
operator|>
name|cache
block|;     }
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11
argument_list|)
block|;
specifier|const
name|UINT
name|mBindFlags
block|;
name|SRVCache
name|srvCache
block|;
name|ID3D11ShaderResourceView
operator|*
name|mLevelSRVs
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|; }
decl_stmt|;
name|class
name|TextureStorage11_2D
range|:
name|public
name|TextureStorage11
block|{
name|public
operator|:
name|TextureStorage11_2D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|,
name|SwapChain11
operator|*
name|swapchain
argument_list|)
block|;
name|TextureStorage11_2D
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|int levels
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage11_2D
argument_list|()
block|;
specifier|static
name|TextureStorage11_2D
operator|*
name|makeTextureStorage11_2D
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getResource
argument_list|()
specifier|const
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|int level
argument_list|)
block|;
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|ID3D11Resource
operator|*
name|getSwizzleTexture
argument_list|()
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getSwizzleRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getTextureLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_2D
argument_list|)
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|createSRV
argument_list|(
argument|int baseLevel
argument_list|,
argument|int mipLevels
argument_list|,
argument|DXGI_FORMAT format
argument_list|,
argument|ID3D11Resource *texture
argument_list|)
block|;
name|ID3D11Texture2D
operator|*
name|mTexture
block|;
name|RenderTarget11
operator|*
name|mRenderTarget
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|ID3D11Texture2D
operator|*
name|mSwizzleTexture
block|;
name|ID3D11RenderTargetView
operator|*
name|mSwizzleRenderTargets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|; }
decl_stmt|;
name|class
name|TextureStorage11_Cube
range|:
name|public
name|TextureStorage11
block|{
name|public
operator|:
name|TextureStorage11_Cube
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|int size
argument_list|,
argument|int levels
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage11_Cube
argument_list|()
block|;
specifier|static
name|TextureStorage11_Cube
operator|*
name|makeTextureStorage11_Cube
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getResource
argument_list|()
specifier|const
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTargetFace
argument_list|(
argument|GLenum faceTarget
argument_list|,
argument|int level
argument_list|)
block|;
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int faceIndex
argument_list|,
argument|int level
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|ID3D11Resource
operator|*
name|getSwizzleTexture
argument_list|()
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getSwizzleRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getTextureLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_Cube
argument_list|)
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|createSRV
argument_list|(
argument|int baseLevel
argument_list|,
argument|int mipLevels
argument_list|,
argument|DXGI_FORMAT format
argument_list|,
argument|ID3D11Resource *texture
argument_list|)
block|;
name|ID3D11Texture2D
operator|*
name|mTexture
block|;
name|RenderTarget11
operator|*
name|mRenderTarget
index|[
literal|6
index|]
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|;
name|ID3D11Texture2D
operator|*
name|mSwizzleTexture
block|;
name|ID3D11RenderTargetView
operator|*
name|mSwizzleRenderTargets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
block|; }
decl_stmt|;
name|class
name|TextureStorage11_3D
range|:
name|public
name|TextureStorage11
block|{
name|public
operator|:
name|TextureStorage11_3D
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|int levels
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage11_3D
argument_list|()
block|;
specifier|static
name|TextureStorage11_3D
operator|*
name|makeTextureStorage11_3D
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getResource
argument_list|()
specifier|const
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTargetLayer
argument_list|(
argument|int mipLevel
argument_list|,
argument|int layer
argument_list|)
block|;
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|ID3D11Resource
operator|*
name|getSwizzleTexture
argument_list|()
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getSwizzleRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getTextureLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_3D
argument_list|)
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|createSRV
argument_list|(
argument|int baseLevel
argument_list|,
argument|int mipLevels
argument_list|,
argument|DXGI_FORMAT format
argument_list|,
argument|ID3D11Resource *texture
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|LevelLayerKey
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|LevelLayerKey
operator|,
name|RenderTarget11
operator|*
operator|>
name|RenderTargetMap
expr_stmt|;
name|RenderTargetMap
name|mLevelLayerRenderTargets
decl_stmt|;
name|RenderTarget11
modifier|*
name|mLevelRenderTargets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
decl_stmt|;
name|ID3D11Texture3D
modifier|*
name|mTexture
decl_stmt|;
name|ID3D11Texture3D
modifier|*
name|mSwizzleTexture
decl_stmt|;
name|ID3D11RenderTargetView
modifier|*
name|mSwizzleRenderTargets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|TextureStorage11_2DArray
range|:
name|public
name|TextureStorage11
block|{
name|public
operator|:
name|TextureStorage11_2DArray
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|bool renderTarget
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|int levels
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage11_2DArray
argument_list|()
block|;
specifier|static
name|TextureStorage11_2DArray
operator|*
name|makeTextureStorage11_2DArray
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
name|virtual
name|ID3D11Resource
operator|*
name|getResource
argument_list|()
specifier|const
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTargetLayer
argument_list|(
argument|int mipLevel
argument_list|,
argument|int layer
argument_list|)
block|;
name|virtual
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|ID3D11Resource
operator|*
name|getSwizzleTexture
argument_list|()
block|;
name|virtual
name|ID3D11RenderTargetView
operator|*
name|getSwizzleRenderTarget
argument_list|(
argument|int mipLevel
argument_list|)
block|;
name|virtual
name|unsigned
name|int
name|getTextureLevelDepth
argument_list|(
argument|int mipLevel
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_2DArray
argument_list|)
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|createSRV
argument_list|(
argument|int baseLevel
argument_list|,
argument|int mipLevels
argument_list|,
argument|DXGI_FORMAT format
argument_list|,
argument|ID3D11Resource *texture
argument_list|)
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|LevelLayerKey
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|LevelLayerKey
operator|,
name|RenderTarget11
operator|*
operator|>
name|RenderTargetMap
expr_stmt|;
end_typedef
begin_decl_stmt
name|RenderTargetMap
name|mRenderTargets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ID3D11Texture2D
modifier|*
name|mTexture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ID3D11Texture2D
modifier|*
name|mSwizzleTexture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ID3D11RenderTargetView
modifier|*
name|mSwizzleRenderTargets
index|[
name|gl
operator|::
name|IMPLEMENTATION_MAX_TEXTURE_LEVELS
index|]
decl_stmt|;
end_decl_stmt
begin_endif
unit|};  }
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTURESTORAGE11_H_
end_comment
end_unit
