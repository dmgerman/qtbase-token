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
comment|// SurfaceD3D.h: D3D implementation of an EGL surface
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_SURFACED3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_SURFACED3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_SURFACED3D_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/SurfaceImpl.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/NativeWindow.h"
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
name|rx
block|{
name|class
name|SwapChainD3D
decl_stmt|;
name|class
name|RendererD3D
decl_stmt|;
name|class
name|SurfaceD3D
range|:
name|public
name|SurfaceImpl
block|{
name|public
operator|:
specifier|static
name|SurfaceD3D
operator|*
name|createFromWindow
argument_list|(
argument|RendererD3D *renderer
argument_list|,
argument|egl::Display *display
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|EGLNativeWindowType window
argument_list|,
argument|EGLint fixedSize
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
block|;
specifier|static
name|SurfaceD3D
operator|*
name|createOffscreen
argument_list|(
argument|RendererD3D *renderer
argument_list|,
argument|egl::Display *display
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|EGLClientBuffer shareHandle
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
block|;
operator|~
name|SurfaceD3D
argument_list|()
name|override
block|;
name|void
name|releaseSwapChain
argument_list|()
block|;
name|egl
operator|::
name|Error
name|initialize
argument_list|()
name|override
block|;
name|egl
operator|::
name|Error
name|swap
argument_list|()
name|override
block|;
name|egl
operator|::
name|Error
name|postSubBuffer
argument_list|(
argument|EGLint x
argument_list|,
argument|EGLint y
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|querySurfacePointerANGLE
argument_list|(
argument|EGLint attribute
argument_list|,
argument|void **value
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|bindTexImage
argument_list|(
argument|EGLint buffer
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|releaseTexImage
argument_list|(
argument|EGLint buffer
argument_list|)
name|override
block|;
name|void
name|setSwapInterval
argument_list|(
argument|EGLint interval
argument_list|)
name|override
block|;
name|EGLint
name|getWidth
argument_list|()
specifier|const
name|override
block|;
name|EGLint
name|getHeight
argument_list|()
specifier|const
name|override
block|;
name|EGLint
name|isPostSubBufferSupported
argument_list|()
specifier|const
name|override
block|;
comment|// D3D implementations
name|SwapChainD3D
operator|*
name|getSwapChain
argument_list|()
specifier|const
block|;
name|egl
operator|::
name|Error
name|resetSwapChain
argument_list|()
block|;
comment|// Returns true if swapchain changed due to resize or interval update
name|bool
name|checkForOutOfDateSwapChain
argument_list|()
block|;
name|private
operator|:
name|SurfaceD3D
argument_list|(
argument|RendererD3D *renderer
argument_list|,
argument|egl::Display *display
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|,
argument|EGLint fixedSize
argument_list|,
argument|EGLClientBuffer shareHandle
argument_list|,
argument|EGLNativeWindowType window
argument_list|)
block|;
name|egl
operator|::
name|Error
name|swapRect
argument_list|(
argument|EGLint x
argument_list|,
argument|EGLint y
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
block|;
name|egl
operator|::
name|Error
name|resetSwapChain
argument_list|(
argument|int backbufferWidth
argument_list|,
argument|int backbufferHeight
argument_list|)
block|;
name|egl
operator|::
name|Error
name|resizeSwapChain
argument_list|(
argument|int backbufferWidth
argument_list|,
argument|int backbufferHeight
argument_list|)
block|;
name|void
name|subclassWindow
argument_list|()
block|;
name|void
name|unsubclassWindow
argument_list|()
block|;
name|RendererD3D
operator|*
name|mRenderer
block|;
name|egl
operator|::
name|Display
operator|*
name|mDisplay
block|;
name|bool
name|mFixedSize
block|;
name|GLenum
name|mRenderTargetFormat
block|;
name|GLenum
name|mDepthStencilFormat
block|;
name|SwapChainD3D
operator|*
name|mSwapChain
block|;
name|bool
name|mSwapIntervalDirty
block|;
name|bool
name|mWindowSubclassed
block|;
comment|// Indicates whether we successfully subclassed mWindow for WM_RESIZE hooking
name|NativeWindow
name|mNativeWindow
block|;
comment|// Handler for the Window that the surface is created for.
name|EGLint
name|mWidth
block|;
name|EGLint
name|mHeight
block|;
name|EGLint
name|mSwapInterval
block|;
name|HANDLE
name|mShareHandle
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_SURFACED3D_H_
end_comment
end_unit
