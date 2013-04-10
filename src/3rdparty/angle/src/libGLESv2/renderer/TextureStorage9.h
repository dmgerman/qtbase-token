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
comment|// TextureStorage9.h: Defines the abstract rx::TextureStorage9 class and its concrete derived
end_comment
begin_comment
comment|// classes TextureStorage9_2D and TextureStorage9_Cube, which act as the interface to the
end_comment
begin_comment
comment|// D3D9 texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTURESTORAGE9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTURESTORAGE9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTURESTORAGE9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/TextureStorage.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer9
decl_stmt|;
name|class
name|SwapChain9
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|RenderTarget9
decl_stmt|;
name|class
name|Blit
decl_stmt|;
name|class
name|TextureStorage9
range|:
name|public
name|TextureStorage
block|{
name|public
operator|:
name|TextureStorage9
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|DWORD usage
argument_list|)
block|;
name|virtual
operator|~
name|TextureStorage9
argument_list|()
block|;
specifier|static
name|TextureStorage9
operator|*
name|makeTextureStorage9
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
block|;
specifier|static
name|DWORD
name|GetTextureUsage
argument_list|(
argument|D3DFORMAT d3dfmt
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
argument|D3DFORMAT format
argument_list|)
block|;
name|D3DPOOL
name|getPool
argument_list|()
specifier|const
block|;
name|DWORD
name|getUsage
argument_list|()
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
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|()
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
name|protected
operator|:
name|int
name|mLodOffset
block|;
name|Renderer9
operator|*
name|mRenderer
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage9
argument_list|)
block|;
specifier|const
name|DWORD
name|mD3DUsage
block|;
specifier|const
name|D3DPOOL
name|mD3DPool
block|; }
decl_stmt|;
name|class
name|TextureStorage9_2D
range|:
name|public
name|TextureStorage9
block|{
name|public
operator|:
name|TextureStorage9_2D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|,
name|SwapChain9
operator|*
name|swapchain
argument_list|)
block|;
name|TextureStorage9_2D
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
name|TextureStorage9_2D
argument_list|()
block|;
specifier|static
name|TextureStorage9_2D
operator|*
name|makeTextureStorage9_2D
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
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
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|()
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
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage9_2D
argument_list|)
block|;
name|void
name|initializeRenderTarget
argument_list|()
block|;
name|IDirect3DTexture9
operator|*
name|mTexture
block|;
name|RenderTarget9
operator|*
name|mRenderTarget
block|; }
decl_stmt|;
name|class
name|TextureStorage9_Cube
range|:
name|public
name|TextureStorage9
block|{
name|public
operator|:
name|TextureStorage9_Cube
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
name|TextureStorage9_Cube
argument_list|()
block|;
specifier|static
name|TextureStorage9_Cube
operator|*
name|makeTextureStorage9_Cube
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|)
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
name|virtual
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum faceTarget
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
name|TextureStorage9_Cube
argument_list|)
block|;
name|void
name|initializeRenderTarget
argument_list|()
block|;
name|IDirect3DCubeTexture9
operator|*
name|mTexture
block|;
name|RenderTarget9
operator|*
name|mRenderTarget
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
comment|// LIBGLESV2_RENDERER_TEXTURESTORAGE9_H_
end_comment
end_unit
