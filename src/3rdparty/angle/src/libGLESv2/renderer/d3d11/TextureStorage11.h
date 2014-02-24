begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
file|"libGLESv2/renderer/TextureStorage.h"
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
name|TextureStorage11
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|UINT bindFlags
argument_list|)
block|;
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
argument|DXGI_FORMAT d3dfmt
argument_list|,
argument|GLenum glusage
argument_list|,
argument|bool forceRenderable
argument_list|)
block|;
specifier|static
name|bool
name|IsTextureFormatRenderable
argument_list|(
argument|DXGI_FORMAT format
argument_list|)
block|;
name|UINT
name|getBindFlags
argument_list|()
specifier|const
block|;
name|virtual
name|ID3D11Texture2D
operator|*
name|getBaseTexture
argument_list|()
specifier|const
block|;
name|virtual
name|ID3D11ShaderResourceView
operator|*
name|getSRV
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|()
block|{
return|return
name|getRenderTarget
argument_list|(
literal|0
argument_list|)
return|;
block|}
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
name|getRenderTarget
argument_list|(
argument|GLenum faceTarget
argument_list|)
block|{
return|return
name|getRenderTarget
argument_list|(
name|faceTarget
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
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
name|getLodOffset
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
name|levelCount
argument_list|()
block|;
name|UINT
name|getSubresourceIndex
argument_list|(
argument|int level
argument_list|,
argument|int faceTarget
argument_list|)
block|;
name|bool
name|updateSubresourceLevel
argument_list|(
argument|ID3D11Texture2D *texture
argument_list|,
argument|unsigned int sourceSubresource
argument_list|,
argument|int level
argument_list|,
argument|int faceTarget
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
name|protected
operator|:
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
name|Renderer11
operator|*
name|mRenderer
block|;
name|int
name|mLodOffset
block|;
name|unsigned
name|int
name|mMipLevels
block|;
name|ID3D11Texture2D
operator|*
name|mTexture
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
name|unsigned
name|int
name|mTextureWidth
block|;
name|unsigned
name|int
name|mTextureHeight
block|;
name|ID3D11ShaderResourceView
operator|*
name|mSRV
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
argument|int levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum usage
argument_list|,
argument|bool forceRenderable
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
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
name|ID3D11ShaderResourceView
operator|*
name|getSRV
argument_list|()
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
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_2D
argument_list|)
block|;
name|RenderTarget11
operator|*
name|mRenderTarget
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
argument|int levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLenum usage
argument_list|,
argument|bool forceRenderable
argument_list|,
argument|int size
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
name|ID3D11ShaderResourceView
operator|*
name|getSRV
argument_list|()
block|;
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
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
argument|int face
argument_list|,
argument|int level
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage11_Cube
argument_list|)
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
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTURESTORAGE11_H_
end_comment
end_unit
