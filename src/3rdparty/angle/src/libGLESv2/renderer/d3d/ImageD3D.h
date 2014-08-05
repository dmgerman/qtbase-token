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
comment|// Image.h: Defines the rx::Image class, an abstract base class for the
end_comment
begin_comment
comment|// renderer-specific classes which will define the interface to the underlying
end_comment
begin_comment
comment|// surfaces or resources.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_IMAGED3D_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_IMAGED3D_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_IMAGED3D_H_
end_define
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Image.h"
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
name|TextureStorageInterface2D
decl_stmt|;
name|class
name|TextureStorageInterfaceCube
decl_stmt|;
name|class
name|TextureStorageInterface3D
decl_stmt|;
name|class
name|TextureStorageInterface2DArray
decl_stmt|;
name|class
name|ImageD3D
range|:
name|public
name|Image
block|{
name|public
operator|:
name|ImageD3D
argument_list|()
block|;
name|virtual
operator|~
name|ImageD3D
argument_list|()
block|{}
block|;
specifier|static
name|ImageD3D
operator|*
name|makeImageD3D
argument_list|(
name|Image
operator|*
name|img
argument_list|)
block|;
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setManagedSurface
argument_list|(
argument|TextureStorageInterface2D *storage
argument_list|,
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|void
name|setManagedSurface
argument_list|(
argument|TextureStorageInterfaceCube *storage
argument_list|,
argument|int face
argument_list|,
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|void
name|setManagedSurface
argument_list|(
argument|TextureStorageInterface3D *storage
argument_list|,
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|void
name|setManagedSurface
argument_list|(
argument|TextureStorageInterface2DArray *storage
argument_list|,
argument|int layer
argument_list|,
argument|int level
argument_list|)
block|{}
block|;
name|virtual
name|bool
name|copyToStorage
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
operator|=
literal|0
block|;
name|virtual
name|bool
name|copyToStorage
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
operator|=
literal|0
block|;
name|virtual
name|bool
name|copyToStorage
argument_list|(
argument|TextureStorageInterface3D *storage
argument_list|,
argument|int level
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
operator|=
literal|0
block|;
name|virtual
name|bool
name|copyToStorage
argument_list|(
argument|TextureStorageInterface2DArray *storage
argument_list|,
argument|int level
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
argument_list|)
operator|=
literal|0
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ImageD3D
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_IMAGED3D_H_
end_comment
end_unit
