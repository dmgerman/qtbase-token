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
name|LIBGLESV2_RENDERER_IMAGE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_IMAGE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_IMAGE_H_
end_define
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
struct_decl|struct
name|Rectangle
struct_decl|;
struct_decl|struct
name|ImageIndex
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RendererD3D
decl_stmt|;
name|class
name|RenderTarget
decl_stmt|;
name|class
name|TextureStorage
decl_stmt|;
name|class
name|Image
block|{
name|public
label|:
name|Image
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Image
argument_list|()
block|{}
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
name|GLsizei
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|mDepth
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
name|GLenum
name|getActualFormat
argument_list|()
specifier|const
block|{
return|return
name|mActualFormat
return|;
block|}
name|GLenum
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|mTarget
return|;
block|}
name|bool
name|isRenderableFormat
argument_list|()
specifier|const
block|{
return|return
name|mRenderable
return|;
block|}
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
name|virtual
name|bool
name|isDirty
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|redefine
parameter_list|(
name|RendererD3D
modifier|*
name|renderer
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLenum
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|bool
name|forceRelease
parameter_list|)
init|=
literal|0
function_decl|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
argument|gl::Framebuffer *source
argument_list|)
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
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
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|GLsizei
name|mWidth
decl_stmt|;
name|GLsizei
name|mHeight
decl_stmt|;
name|GLsizei
name|mDepth
decl_stmt|;
name|GLenum
name|mInternalFormat
decl_stmt|;
name|GLenum
name|mActualFormat
decl_stmt|;
name|bool
name|mRenderable
decl_stmt|;
name|GLenum
name|mTarget
decl_stmt|;
name|bool
name|mDirty
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Image
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_IMAGE_H_
end_comment
end_unit
