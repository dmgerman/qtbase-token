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
name|LIBANGLE_RENDERER_TEXTUREIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_TEXTUREIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_TEXTUREIMPL_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/ImageIndex.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|<stdint.h>
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
struct_decl|struct
name|Box
struct_decl|;
struct_decl|struct
name|Extents
struct_decl|;
struct_decl|struct
name|Offset
struct_decl|;
struct_decl|struct
name|Rectangle
struct_decl|;
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
name|TextureImpl
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|virtual
operator|~
name|TextureImpl
argument_list|()
block|{}
block|;
name|virtual
name|void
name|setUsage
argument_list|(
argument|GLenum usage
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const gl::Extents&size
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setSubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const gl::Box&area
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setCompressedImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const gl::Extents&size
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setCompressedSubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const gl::Box&area
argument_list|,
argument|GLenum format
argument_list|,
argument|const gl::PixelUnpackState&unpack
argument_list|,
argument|const uint8_t *pixels
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|copyImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const gl::Framebuffer *source
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|copySubImage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t level
argument_list|,
argument|const gl::Offset&destOffset
argument_list|,
argument|const gl::Rectangle&sourceArea
argument_list|,
argument|const gl::Framebuffer *source
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|GLenum target
argument_list|,
argument|size_t levels
argument_list|,
argument|GLenum internalFormat
argument_list|,
argument|const gl::Extents&size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|generateMipmaps
argument_list|()
operator|=
literal|0
block|;
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
operator|=
literal|0
block|;
name|virtual
name|void
name|releaseTexImage
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_TEXTUREIMPL_H_
end_comment
end_unit
