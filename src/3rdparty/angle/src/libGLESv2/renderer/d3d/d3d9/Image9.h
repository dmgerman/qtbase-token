begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Image9.h: Defines the rx::Image9 class, which acts as the interface to
end_comment
begin_comment
comment|// the actual underlying surfaces of a Texture.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_IMAGE9_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_IMAGE9_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_IMAGE9_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/ImageD3D.h"
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
name|Renderer9
decl_stmt|;
name|class
name|Image9
range|:
name|public
name|ImageD3D
block|{
name|public
operator|:
name|Image9
argument_list|()
block|;
operator|~
name|Image9
argument_list|()
block|;
specifier|static
name|Image9
operator|*
name|makeImage9
argument_list|(
name|Image
operator|*
name|img
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|generateMipmap
argument_list|(
name|Image9
operator|*
name|dest
argument_list|,
name|Image9
operator|*
name|source
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|generateMip
argument_list|(
name|IDirect3DSurface9
operator|*
name|destSurface
argument_list|,
name|IDirect3DSurface9
operator|*
name|sourceSurface
argument_list|)
block|;
specifier|static
name|gl
operator|::
name|Error
name|copyLockableSurfaces
argument_list|(
name|IDirect3DSurface9
operator|*
name|dest
argument_list|,
name|IDirect3DSurface9
operator|*
name|source
argument_list|)
block|;
name|bool
name|redefine
argument_list|(
argument|RendererD3D *renderer
argument_list|,
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|bool forceRelease
argument_list|)
name|override
block|;
name|D3DFORMAT
name|getD3DFormat
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
block|;
name|virtual
name|gl
operator|::
name|Error
name|setManagedSurface2D
argument_list|(
argument|TextureStorage *storage
argument_list|,
argument|int level
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|setManagedSurfaceCube
argument_list|(
argument|TextureStorage *storage
argument_list|,
argument|int face
argument_list|,
argument|int level
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyToStorage
argument_list|(
name|TextureStorage
operator|*
name|storage
argument_list|,
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|,
specifier|const
name|gl
operator|::
name|Box
operator|&
name|region
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadData
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
argument|GLint unpackAlignment
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *input
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|loadCompressedData
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
argument|const void *input
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|RenderTarget *source
argument_list|)
block|;
name|virtual
name|gl
operator|::
name|Error
name|copy
argument_list|(
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint zoffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::ImageIndex&sourceIndex
argument_list|,
argument|TextureStorage *source
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Image9
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getSurface
argument_list|(
name|IDirect3DSurface9
operator|*
operator|*
name|outSurface
argument_list|)
block|;
name|gl
operator|::
name|Error
name|createSurface
argument_list|()
block|;
name|gl
operator|::
name|Error
name|setManagedSurface
argument_list|(
name|IDirect3DSurface9
operator|*
name|surface
argument_list|)
block|;
name|gl
operator|::
name|Error
name|copyToSurface
argument_list|(
argument|IDirect3DSurface9 *dest
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
name|gl
operator|::
name|Error
name|lock
argument_list|(
name|D3DLOCKED_RECT
operator|*
name|lockedRect
argument_list|,
specifier|const
name|RECT
operator|&
name|rect
argument_list|)
block|;
name|void
name|unlock
argument_list|()
block|;
name|Renderer9
operator|*
name|mRenderer
block|;
name|D3DPOOL
name|mD3DPool
block|;
comment|// can only be D3DPOOL_SYSTEMMEM or D3DPOOL_MANAGED since it needs to be lockable.
name|D3DFORMAT
name|mD3DFormat
block|;
name|IDirect3DSurface9
operator|*
name|mSurface
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_IMAGE9_H_
end_comment
end_unit
