begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// TextureImpl.h: Defines the abstract rx::TextureImpl classes.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Error.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/ImageIndex.h"
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
name|PixelUnpackState
struct_decl|;
struct_decl|struct
name|SamplerState
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Image
decl_stmt|;
name|class
name|TextureImpl
block|{
name|public
label|:
name|virtual
operator|~
name|TextureImpl
argument_list|()
block|{}
expr_stmt|;
comment|// Deprecated in favour of the ImageIndex method
name|virtual
name|Image
modifier|*
name|getImage
argument_list|(
name|int
name|level
argument_list|,
name|int
name|layer
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|Image
modifier|*
name|getImage
argument_list|(
specifier|const
name|gl
operator|::
name|ImageIndex
operator|&
name|index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|GLsizei
name|getLayerCount
argument_list|(
name|int
name|level
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setUsage
parameter_list|(
name|GLenum
name|usage
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|gl
operator|::
name|Error
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|setCompressedImage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
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
argument|GLint zoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const void *pixels
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
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
argument|gl::Framebuffer *source
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
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
argument|GLint zoffset
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|storage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizei levels
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLsizei depth
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmaps
argument_list|()
operator|=
literal|0
expr_stmt|;
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
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|releaseTexImage
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_TEXTUREIMPL_H_
end_comment
end_unit
