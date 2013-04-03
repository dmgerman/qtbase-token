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
comment|// Image11.h: Defines the rx::Image11 class, which acts as the interface to
end_comment
begin_comment
comment|// the actual underlying resources of a Texture
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_IMAGE11_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_IMAGE11_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_IMAGE11_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Image.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
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
name|Renderer
decl_stmt|;
name|class
name|Renderer11
decl_stmt|;
name|class
name|TextureStorageInterface2D
decl_stmt|;
name|class
name|TextureStorageInterfaceCube
decl_stmt|;
name|class
name|Image11
range|:
name|public
name|Image
block|{
name|public
operator|:
name|Image11
argument_list|()
block|;
name|virtual
operator|~
name|Image11
argument_list|()
block|;
specifier|static
name|Image11
operator|*
name|makeImage11
argument_list|(
name|Image
operator|*
name|img
argument_list|)
block|;
specifier|static
name|void
name|generateMipmap
argument_list|(
name|Image11
operator|*
name|dest
argument_list|,
name|Image11
operator|*
name|src
argument_list|)
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|updateSurface
argument_list|(
argument|TextureStorageInterface2D *storage
argument_list|,
argument|int level
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
name|virtual
name|bool
name|updateSurface
argument_list|(
argument|TextureStorageInterfaceCube *storage
argument_list|,
argument|int face
argument_list|,
argument|int level
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
name|virtual
name|bool
name|redefine
argument_list|(
argument|Renderer *renderer
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|bool forceRelease
argument_list|)
block|;
name|virtual
name|bool
name|isRenderableFormat
argument_list|()
specifier|const
block|;
name|DXGI_FORMAT
name|getDXGIFormat
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|loadData
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint unpackAlignment
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|void
name|loadCompressedData
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|void
name|copy
argument_list|(
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
argument|gl::Framebuffer *source
argument_list|)
block|;
name|protected
operator|:
name|HRESULT
name|map
argument_list|(
name|D3D11_MAPPED_SUBRESOURCE
operator|*
name|map
argument_list|)
block|;
name|void
name|unmap
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Image11
argument_list|)
block|;
name|ID3D11Texture2D
operator|*
name|getStagingTexture
argument_list|()
block|;
name|unsigned
name|int
name|getStagingSubresource
argument_list|()
block|;
name|void
name|createStagingTexture
argument_list|()
block|;
name|Renderer11
operator|*
name|mRenderer
block|;
name|DXGI_FORMAT
name|mDXGIFormat
block|;
name|ID3D11Texture2D
operator|*
name|mStagingTexture
block|;
name|unsigned
name|int
name|mStagingSubresource
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_IMAGE11_H_
end_comment
end_unit
