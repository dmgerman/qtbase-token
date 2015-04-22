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
comment|// DisplayD3D.h: D3D implementation of egl::Display
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/DisplayImpl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|RendererD3D
decl_stmt|;
name|class
name|DisplayD3D
range|:
name|public
name|DisplayImpl
block|{
name|public
operator|:
name|DisplayD3D
argument_list|()
block|;
name|egl
operator|::
name|Error
name|initialize
argument_list|(
argument|egl::Display *display
argument_list|)
name|override
block|;
name|virtual
name|void
name|terminate
argument_list|()
name|override
block|;
name|egl
operator|::
name|Error
name|createWindowSurface
argument_list|(
argument|const egl::Config *configuration
argument_list|,
argument|EGLNativeWindowType window
argument_list|,
argument|const egl::AttributeMap&attribs
argument_list|,
argument|SurfaceImpl **outSurface
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|createPbufferSurface
argument_list|(
argument|const egl::Config *configuration
argument_list|,
argument|const egl::AttributeMap&attribs
argument_list|,
argument|SurfaceImpl **outSurface
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|createPbufferFromClientBuffer
argument_list|(
argument|const egl::Config *configuration
argument_list|,
argument|EGLClientBuffer shareHandle
argument_list|,
argument|const egl::AttributeMap&attribs
argument_list|,
argument|SurfaceImpl **outSurface
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|createPixmapSurface
argument_list|(
argument|const egl::Config *configuration
argument_list|,
argument|NativePixmapType nativePixmap
argument_list|,
argument|const egl::AttributeMap&attribs
argument_list|,
argument|SurfaceImpl **outSurface
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|createContext
argument_list|(
argument|const egl::Config *config
argument_list|,
argument|const gl::Context *shareContext
argument_list|,
argument|const egl::AttributeMap&attribs
argument_list|,
argument|gl::Context **outContext
argument_list|)
name|override
block|;
name|egl
operator|::
name|Error
name|makeCurrent
argument_list|(
argument|egl::Surface *drawSurface
argument_list|,
argument|egl::Surface *readSurface
argument_list|,
argument|gl::Context *context
argument_list|)
name|override
block|;
name|egl
operator|::
name|ConfigSet
name|generateConfigs
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isDeviceLost
argument_list|()
specifier|const
name|override
block|;
name|bool
name|testDeviceLost
argument_list|()
name|override
block|;
name|egl
operator|::
name|Error
name|restoreLostDevice
argument_list|()
name|override
block|;
name|bool
name|isValidNativeWindow
argument_list|(
argument|EGLNativeWindowType window
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getVendorString
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|void
name|generateExtensions
argument_list|(
argument|egl::DisplayExtensions *outExtensions
argument_list|)
specifier|const
name|override
block|;
name|void
name|generateCaps
argument_list|(
argument|egl::Caps *outCaps
argument_list|)
specifier|const
name|override
block|;
name|egl
operator|::
name|Display
operator|*
name|mDisplay
block|;
name|rx
operator|::
name|RendererD3D
operator|*
name|mRenderer
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_
end_comment
end_unit
