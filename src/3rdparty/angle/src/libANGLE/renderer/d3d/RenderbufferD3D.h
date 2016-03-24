begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderbufferD3d.h: Defines the RenderbufferD3D class which implements RenderbufferImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_RENDERBUFFERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_RENDERBUFFERD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_RENDERBUFFERD3D_H_
end_define
begin_include
include|#
directive|include
file|"angle_gl.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/RenderbufferImpl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|EGLImageD3D
decl_stmt|;
name|class
name|RendererD3D
decl_stmt|;
name|class
name|RenderTargetD3D
decl_stmt|;
name|class
name|SwapChainD3D
decl_stmt|;
name|class
name|RenderbufferD3D
range|:
name|public
name|RenderbufferImpl
block|{
name|public
operator|:
name|RenderbufferD3D
argument_list|(
name|RendererD3D
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|RenderbufferD3D
argument_list|()
block|;
name|gl
operator|::
name|Error
name|setStorage
argument_list|(
argument|GLenum internalformat
argument_list|,
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|setStorageMultisample
argument_list|(
argument|size_t samples
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|size_t width
argument_list|,
argument|size_t height
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|setStorageEGLImageTarget
argument_list|(
argument|egl::Image *image
argument_list|)
name|override
block|;
name|gl
operator|::
name|Error
name|getRenderTarget
argument_list|(
name|RenderTargetD3D
operator|*
operator|*
name|outRenderTarget
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getAttachmentRenderTarget
argument_list|(
argument|const gl::FramebufferAttachment::Target&target
argument_list|,
argument|FramebufferAttachmentRenderTarget **rtOut
argument_list|)
name|override
block|;
name|private
operator|:
name|RendererD3D
operator|*
name|mRenderer
block|;
name|RenderTargetD3D
operator|*
name|mRenderTarget
block|;
name|EGLImageD3D
operator|*
name|mImage
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_RENDERBUFFERD3D_H_
end_comment
end_unit
