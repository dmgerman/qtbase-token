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
comment|// SwapChain.h: Defines a back-end specific class that hides the details of the
end_comment
begin_comment
comment|// implementation-specific swapchain.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_SWAPCHAIN_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_SWAPCHAIN_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_SWAPCHAIN_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|SwapChain
block|{
name|public
label|:
name|SwapChain
argument_list|(
argument|EGLNativeWindowType window
argument_list|,
argument|HANDLE shareHandle
argument_list|,
argument|GLenum backBufferFormat
argument_list|,
argument|GLenum depthBufferFormat
argument_list|)
block|:
name|mWindow
argument_list|(
name|window
argument_list|)
operator|,
name|mShareHandle
argument_list|(
name|shareHandle
argument_list|)
operator|,
name|mBackBufferFormat
argument_list|(
name|backBufferFormat
argument_list|)
operator|,
name|mDepthBufferFormat
argument_list|(
argument|depthBufferFormat
argument_list|)
block|{     }
name|virtual
operator|~
name|SwapChain
argument_list|()
block|{}
expr_stmt|;
name|virtual
name|EGLint
name|resize
parameter_list|(
name|EGLint
name|backbufferWidth
parameter_list|,
name|EGLint
name|backbufferSize
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|EGLint
name|reset
parameter_list|(
name|EGLint
name|backbufferWidth
parameter_list|,
name|EGLint
name|backbufferHeight
parameter_list|,
name|EGLint
name|swapInterval
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|EGLint
name|swapRect
parameter_list|(
name|EGLint
name|x
parameter_list|,
name|EGLint
name|y
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|recreate
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|HANDLE
name|getShareHandle
parameter_list|()
block|{
return|return
name|mShareHandle
return|;
block|}
empty_stmt|;
name|protected
label|:
specifier|const
name|EGLNativeWindowType
name|mWindow
decl_stmt|;
comment|// Window that the surface is created for.
specifier|const
name|GLenum
name|mBackBufferFormat
decl_stmt|;
specifier|const
name|GLenum
name|mDepthBufferFormat
decl_stmt|;
name|HANDLE
name|mShareHandle
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_SWAPCHAIN_H_
end_comment
end_unit
