begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
comment|// Config.h: Defines the egl::Config class, describing the format, type
end_comment
begin_comment
comment|// and size for an egl::Surface. Implements EGLConfig and related functionality.
end_comment
begin_comment
comment|// [EGL 1.4] section 3.4 page 15.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDE_CONFIG_H_
end_ifndef
begin_define
DECL|macro|INCLUDE_CONFIG_H_
define|#
directive|define
name|INCLUDE_CONFIG_H_
end_define
begin_define
DECL|macro|EGLAPI
define|#
directive|define
name|EGLAPI
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<d3d9.h>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Display
decl_stmt|;
name|class
name|Config
block|{
name|public
label|:
name|Config
argument_list|(
argument|D3DDISPLAYMODE displayMode
argument_list|,
argument|EGLint minSwapInterval
argument_list|,
argument|EGLint maxSwapInterval
argument_list|,
argument|D3DFORMAT renderTargetFormat
argument_list|,
argument|D3DFORMAT depthStencilFormat
argument_list|,
argument|EGLint multiSample
argument_list|,
argument|EGLint texWidth
argument_list|,
argument|EGLint texHeight
argument_list|)
empty_stmt|;
name|void
name|setDefaults
parameter_list|()
function_decl|;
name|void
name|set
parameter_list|(
name|D3DDISPLAYMODE
name|displayMode
parameter_list|,
name|EGLint
name|minSwapInterval
parameter_list|,
name|EGLint
name|maxSwapInterval
parameter_list|,
name|D3DFORMAT
name|renderTargetFormat
parameter_list|,
name|D3DFORMAT
name|depthStencilFormat
parameter_list|,
name|EGLint
name|multiSample
parameter_list|,
name|EGLint
name|texWidth
parameter_list|,
name|EGLint
name|texHeight
parameter_list|)
function_decl|;
name|EGLConfig
name|getHandle
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|D3DDISPLAYMODE
name|mDisplayMode
decl_stmt|;
specifier|const
name|D3DFORMAT
name|mRenderTargetFormat
decl_stmt|;
specifier|const
name|D3DFORMAT
name|mDepthStencilFormat
decl_stmt|;
specifier|const
name|EGLint
name|mMultiSample
decl_stmt|;
name|EGLint
name|mBufferSize
decl_stmt|;
comment|// Depth of the color buffer
name|EGLint
name|mRedSize
decl_stmt|;
comment|// Bits of Red in the color buffer
name|EGLint
name|mGreenSize
decl_stmt|;
comment|// Bits of Green in the color buffer
name|EGLint
name|mBlueSize
decl_stmt|;
comment|// Bits of Blue in the color buffer
name|EGLint
name|mLuminanceSize
decl_stmt|;
comment|// Bits of Luminance in the color buffer
name|EGLint
name|mAlphaSize
decl_stmt|;
comment|// Bits of Alpha in the color buffer
name|EGLint
name|mAlphaMaskSize
decl_stmt|;
comment|// Bits of Alpha Mask in the mask buffer
name|EGLBoolean
name|mBindToTextureRGB
decl_stmt|;
comment|// True if bindable to RGB textures.
name|EGLBoolean
name|mBindToTextureRGBA
decl_stmt|;
comment|// True if bindable to RGBA textures.
name|EGLenum
name|mColorBufferType
decl_stmt|;
comment|// Color buffer type
name|EGLenum
name|mConfigCaveat
decl_stmt|;
comment|// Any caveats for the configuration
name|EGLint
name|mConfigID
decl_stmt|;
comment|// Unique EGLConfig identifier
name|EGLint
name|mConformant
decl_stmt|;
comment|// Whether contexts created with this config are conformant
name|EGLint
name|mDepthSize
decl_stmt|;
comment|// Bits of Z in the depth buffer
name|EGLint
name|mLevel
decl_stmt|;
comment|// Frame buffer level
name|EGLBoolean
name|mMatchNativePixmap
decl_stmt|;
comment|// Match the native pixmap format
name|EGLint
name|mMaxPBufferWidth
decl_stmt|;
comment|// Maximum width of pbuffer
name|EGLint
name|mMaxPBufferHeight
decl_stmt|;
comment|// Maximum height of pbuffer
name|EGLint
name|mMaxPBufferPixels
decl_stmt|;
comment|// Maximum size of pbuffer
name|EGLint
name|mMaxSwapInterval
decl_stmt|;
comment|// Maximum swap interval
name|EGLint
name|mMinSwapInterval
decl_stmt|;
comment|// Minimum swap interval
name|EGLBoolean
name|mNativeRenderable
decl_stmt|;
comment|// EGL_TRUE if native rendering APIs can render to surface
name|EGLint
name|mNativeVisualID
decl_stmt|;
comment|// Handle of corresponding native visual
name|EGLint
name|mNativeVisualType
decl_stmt|;
comment|// Native visual type of the associated visual
name|EGLint
name|mRenderableType
decl_stmt|;
comment|// Which client rendering APIs are supported.
name|EGLint
name|mSampleBuffers
decl_stmt|;
comment|// Number of multisample buffers
name|EGLint
name|mSamples
decl_stmt|;
comment|// Number of samples per pixel
name|EGLint
name|mStencilSize
decl_stmt|;
comment|// Bits of Stencil in the stencil buffer
name|EGLint
name|mSurfaceType
decl_stmt|;
comment|// Which types of EGL surfaces are supported.
name|EGLenum
name|mTransparentType
decl_stmt|;
comment|// Type of transparency supported
name|EGLint
name|mTransparentRedValue
decl_stmt|;
comment|// Transparent red value
name|EGLint
name|mTransparentGreenValue
decl_stmt|;
comment|// Transparent green value
name|EGLint
name|mTransparentBlueValue
decl_stmt|;
comment|// Transparent blue value
block|}
empty_stmt|;
comment|// Function object used by STL sorting routines for ordering Configs according to [EGL] section 3.4.1 page 24.
name|class
name|SortConfig
block|{
name|public
label|:
name|explicit
name|SortConfig
parameter_list|(
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|)
function_decl|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Config
operator|*
name|x
operator|,
specifier|const
name|Config
operator|*
name|y
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Config
operator|&
name|x
operator|,
specifier|const
name|Config
operator|&
name|y
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|scanForWantedComponents
parameter_list|(
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|)
function_decl|;
name|EGLint
name|wantedComponentsSize
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|)
decl|const
decl_stmt|;
name|bool
name|mWantRed
decl_stmt|;
name|bool
name|mWantGreen
decl_stmt|;
name|bool
name|mWantBlue
decl_stmt|;
name|bool
name|mWantAlpha
decl_stmt|;
name|bool
name|mWantLuminance
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ConfigSet
block|{
name|friend
name|Display
decl_stmt|;
name|public
label|:
name|ConfigSet
argument_list|()
expr_stmt|;
name|void
name|add
parameter_list|(
name|D3DDISPLAYMODE
name|displayMode
parameter_list|,
name|EGLint
name|minSwapInterval
parameter_list|,
name|EGLint
name|maxSwapInterval
parameter_list|,
name|D3DFORMAT
name|renderTargetFormat
parameter_list|,
name|D3DFORMAT
name|depthStencilFormat
parameter_list|,
name|EGLint
name|multiSample
parameter_list|,
name|EGLint
name|texWidth
parameter_list|,
name|EGLint
name|texHeight
parameter_list|)
function_decl|;
name|size_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|getConfigs
parameter_list|(
name|EGLConfig
modifier|*
name|configs
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|,
name|EGLint
name|configSize
parameter_list|,
name|EGLint
modifier|*
name|numConfig
parameter_list|)
function_decl|;
specifier|const
name|egl
operator|::
name|Config
operator|*
name|get
argument_list|(
argument|EGLConfig configHandle
argument_list|)
expr_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConfigSet
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|Config
operator|,
name|SortConfig
operator|>
name|Set
expr_stmt|;
typedef|typedef
name|Set
operator|::
name|iterator
name|Iterator
expr_stmt|;
name|Set
name|mSet
decl_stmt|;
specifier|static
specifier|const
name|EGLint
name|mSortAttribs
index|[]
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
comment|// INCLUDE_CONFIG_H_
end_comment
end_unit
