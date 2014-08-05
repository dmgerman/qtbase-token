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
comment|// TextureStorage.h: Defines the abstract rx::TextureStorageInterface class and its concrete derived
end_comment
begin_comment
comment|// classes TextureStorageInterface2D and TextureStorageInterfaceCube, which act as the interface to the
end_comment
begin_comment
comment|// GPU-side texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTURESTORAGE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTURESTORAGE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTURESTORAGE_H_
end_define
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
name|Renderer
decl_stmt|;
name|class
name|SwapChain
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|TextureStorage
block|{
name|public
label|:
name|TextureStorage
argument_list|()
block|{}
empty_stmt|;
name|virtual
operator|~
name|TextureStorage
argument_list|()
block|{}
expr_stmt|;
name|virtual
name|int
name|getTopLevel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isRenderTarget
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isManaged
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|getLevelCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|RenderTarget
modifier|*
name|getRenderTarget
parameter_list|(
name|int
name|level
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|RenderTarget
modifier|*
name|getRenderTargetFace
parameter_list|(
name|GLenum
name|faceTarget
parameter_list|,
name|int
name|level
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|RenderTarget
modifier|*
name|getRenderTargetLayer
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|layer
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|generateMipmap
parameter_list|(
name|int
name|level
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|generateMipmap
parameter_list|(
name|int
name|face
parameter_list|,
name|int
name|level
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorage
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|class
name|TextureStorageInterface
block|{
name|public
label|:
name|TextureStorageInterface
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|TextureStorageInterface
argument_list|()
expr_stmt|;
name|TextureStorage
modifier|*
name|getStorageInstance
parameter_list|()
block|{
return|return
name|mInstance
return|;
block|}
name|unsigned
name|int
name|getTextureSerial
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|getTopLevel
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|isRenderTarget
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|isManaged
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|getLevelCount
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|TextureStorage
modifier|*
name|mInstance
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageInterface
argument_list|)
expr_stmt|;
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
name|TextureStorageInterface2D
range|:
name|public
name|TextureStorageInterface
block|{
name|public
operator|:
name|TextureStorageInterface2D
argument_list|(
name|Renderer
operator|*
name|renderer
argument_list|,
name|SwapChain
operator|*
name|swapchain
argument_list|)
block|;
name|TextureStorageInterface2D
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
name|TextureStorageInterface2D
argument_list|()
block|;
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageInterface2D
argument_list|)
block|;
name|unsigned
name|int
name|mFirstRenderTargetSerial
block|; }
decl_stmt|;
name|class
name|TextureStorageInterfaceCube
range|:
name|public
name|TextureStorageInterface
block|{
name|public
operator|:
name|TextureStorageInterfaceCube
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
name|TextureStorageInterfaceCube
argument_list|()
block|;
name|void
name|generateMipmap
argument_list|(
argument|int faceIndex
argument_list|,
argument|int level
argument_list|)
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLenum faceTarget
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageInterfaceCube
argument_list|)
block|;
name|unsigned
name|int
name|mFirstRenderTargetSerial
block|; }
decl_stmt|;
name|class
name|TextureStorageInterface3D
range|:
name|public
name|TextureStorageInterface
block|{
name|public
operator|:
name|TextureStorageInterface3D
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
name|TextureStorageInterface3D
argument_list|()
block|;
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|)
specifier|const
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageInterface3D
argument_list|)
block|;
name|unsigned
name|int
name|mFirstRenderTargetSerial
block|; }
decl_stmt|;
name|class
name|TextureStorageInterface2DArray
range|:
name|public
name|TextureStorageInterface
block|{
name|public
operator|:
name|TextureStorageInterface2DArray
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
name|TextureStorageInterface2DArray
argument_list|()
block|;
name|void
name|generateMipmap
argument_list|(
argument|int level
argument_list|)
block|;
name|RenderTarget
operator|*
name|getRenderTarget
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|int
name|getRenderTargetSerial
argument_list|(
argument|GLint level
argument_list|,
argument|GLint layer
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TextureStorageInterface2DArray
argument_list|)
block|;
name|unsigned
name|int
name|mFirstRenderTargetSerial
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTURESTORAGE_H_
end_comment
end_unit
