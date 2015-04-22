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
comment|// Surface.h: Defines the egl::Surface class, representing a drawing surface
end_comment
begin_comment
comment|// such as the client area of a window, including any back buffers.
end_comment
begin_comment
comment|// Implements EGLSurface and related functionality. [EGL 1.4] section 2.2 page 3.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_SURFACE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_SURFACE_H_
define|#
directive|define
name|LIBANGLE_SURFACE_H_
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/RefCountObject.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Texture
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|SurfaceImpl
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|AttributeMap
decl_stmt|;
name|class
name|Display
decl_stmt|;
struct_decl|struct
name|Config
struct_decl|;
name|class
name|Surface
name|final
range|:
name|public
name|RefCountObject
block|{
name|public
operator|:
name|Surface
argument_list|(
argument|rx::SurfaceImpl *impl
argument_list|,
argument|EGLint surfaceType
argument_list|,
argument|const egl::Config *config
argument_list|,
argument|const AttributeMap&attributes
argument_list|)
block|;
name|rx
operator|::
name|SurfaceImpl
operator|*
name|getImplementation
argument_list|()
block|{
return|return
name|mImplementation
return|;
block|}
specifier|const
name|rx
operator|::
name|SurfaceImpl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|{
return|return
name|mImplementation
return|;
block|}
name|EGLint
name|getType
argument_list|()
specifier|const
block|;
name|Error
name|swap
argument_list|()
block|;
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
block|;
name|Error
name|querySurfacePointerANGLE
argument_list|(
argument|EGLint attribute
argument_list|,
argument|void **value
argument_list|)
block|;
name|Error
name|bindTexImage
argument_list|(
argument|gl::Texture *texture
argument_list|,
argument|EGLint buffer
argument_list|)
block|;
name|Error
name|releaseTexImage
argument_list|(
argument|EGLint buffer
argument_list|)
block|;
name|EGLint
name|isPostSubBufferSupported
argument_list|()
specifier|const
block|;
name|void
name|setSwapInterval
argument_list|(
argument|EGLint interval
argument_list|)
block|;
specifier|const
name|Config
operator|*
name|getConfig
argument_list|()
specifier|const
block|;
comment|// width and height can change with client window resizing
name|EGLint
name|getWidth
argument_list|()
specifier|const
block|;
name|EGLint
name|getHeight
argument_list|()
specifier|const
block|;
name|EGLint
name|getPixelAspectRatio
argument_list|()
specifier|const
block|;
name|EGLenum
name|getRenderBuffer
argument_list|()
specifier|const
block|;
name|EGLenum
name|getSwapBehavior
argument_list|()
specifier|const
block|;
name|EGLenum
name|getTextureFormat
argument_list|()
specifier|const
block|;
name|EGLenum
name|getTextureTarget
argument_list|()
specifier|const
block|;
name|gl
operator|::
name|Texture
operator|*
name|getBoundTexture
argument_list|()
specifier|const
block|{
return|return
name|mTexture
return|;
block|}
name|EGLint
name|isFixedSize
argument_list|()
specifier|const
block|;
name|private
operator|:
name|virtual
operator|~
name|Surface
argument_list|()
block|;
name|rx
operator|::
name|SurfaceImpl
operator|*
name|mImplementation
block|;
name|EGLint
name|mType
block|;
specifier|const
name|egl
operator|::
name|Config
operator|*
name|mConfig
block|;
name|bool
name|mPostSubBufferRequested
block|;
name|bool
name|mFixedSize
block|;
name|size_t
name|mFixedWidth
block|;
name|size_t
name|mFixedHeight
block|;
name|EGLenum
name|mTextureFormat
block|;
name|EGLenum
name|mTextureTarget
block|;
name|EGLint
name|mPixelAspectRatio
block|;
comment|// Display aspect ratio
name|EGLenum
name|mRenderBuffer
block|;
comment|// Render buffer
name|EGLenum
name|mSwapBehavior
block|;
comment|// Buffer swap behavior
name|gl
operator|::
name|Texture
operator|*
name|mTexture
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_SURFACE_H_
end_comment
end_unit
