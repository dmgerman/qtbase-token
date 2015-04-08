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
comment|// [EGL 1.5] section 3.4 page 19.
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
begin_include
include|#
directive|include
file|"libANGLE/AttributeMap.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
struct|struct
name|Config
block|{
name|Config
argument_list|()
expr_stmt|;
name|GLenum
name|renderTargetFormat
decl_stmt|;
comment|// TODO(geofflang): remove this
name|GLenum
name|depthStencilFormat
decl_stmt|;
comment|// TODO(geofflang): remove this
name|EGLint
name|bufferSize
decl_stmt|;
comment|// Depth of the color buffer
name|EGLint
name|redSize
decl_stmt|;
comment|// Bits of Red in the color buffer
name|EGLint
name|greenSize
decl_stmt|;
comment|// Bits of Green in the color buffer
name|EGLint
name|blueSize
decl_stmt|;
comment|// Bits of Blue in the color buffer
name|EGLint
name|luminanceSize
decl_stmt|;
comment|// Bits of Luminance in the color buffer
name|EGLint
name|alphaSize
decl_stmt|;
comment|// Bits of Alpha in the color buffer
name|EGLint
name|alphaMaskSize
decl_stmt|;
comment|// Bits of Alpha Mask in the mask buffer
name|EGLBoolean
name|bindToTextureRGB
decl_stmt|;
comment|// True if bindable to RGB textures.
name|EGLBoolean
name|bindToTextureRGBA
decl_stmt|;
comment|// True if bindable to RGBA textures.
name|EGLenum
name|colorBufferType
decl_stmt|;
comment|// Color buffer type
name|EGLenum
name|configCaveat
decl_stmt|;
comment|// Any caveats for the configuration
name|EGLint
name|configID
decl_stmt|;
comment|// Unique EGLConfig identifier
name|EGLint
name|conformant
decl_stmt|;
comment|// Whether contexts created with this config are conformant
name|EGLint
name|depthSize
decl_stmt|;
comment|// Bits of Z in the depth buffer
name|EGLint
name|level
decl_stmt|;
comment|// Frame buffer level
name|EGLBoolean
name|matchNativePixmap
decl_stmt|;
comment|// Match the native pixmap format
name|EGLint
name|maxPBufferWidth
decl_stmt|;
comment|// Maximum width of pbuffer
name|EGLint
name|maxPBufferHeight
decl_stmt|;
comment|// Maximum height of pbuffer
name|EGLint
name|maxPBufferPixels
decl_stmt|;
comment|// Maximum size of pbuffer
name|EGLint
name|maxSwapInterval
decl_stmt|;
comment|// Maximum swap interval
name|EGLint
name|minSwapInterval
decl_stmt|;
comment|// Minimum swap interval
name|EGLBoolean
name|nativeRenderable
decl_stmt|;
comment|// EGL_TRUE if native rendering APIs can render to surface
name|EGLint
name|nativeVisualID
decl_stmt|;
comment|// Handle of corresponding native visual
name|EGLint
name|nativeVisualType
decl_stmt|;
comment|// Native visual type of the associated visual
name|EGLint
name|renderableType
decl_stmt|;
comment|// Which client rendering APIs are supported.
name|EGLint
name|sampleBuffers
decl_stmt|;
comment|// Number of multisample buffers
name|EGLint
name|samples
decl_stmt|;
comment|// Number of samples per pixel
name|EGLint
name|stencilSize
decl_stmt|;
comment|// Bits of Stencil in the stencil buffer
name|EGLint
name|surfaceType
decl_stmt|;
comment|// Which types of EGL surfaces are supported.
name|EGLenum
name|transparentType
decl_stmt|;
comment|// Type of transparency supported
name|EGLint
name|transparentRedValue
decl_stmt|;
comment|// Transparent red value
name|EGLint
name|transparentGreenValue
decl_stmt|;
comment|// Transparent green value
name|EGLint
name|transparentBlueValue
decl_stmt|;
comment|// Transparent blue value
block|}
struct|;
name|class
name|ConfigSet
block|{
name|public
label|:
name|EGLint
name|add
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|const
name|Config
modifier|&
name|get
argument_list|(
name|EGLint
name|id
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|size_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|Config
operator|*
name|config
argument_list|)
decl|const
decl_stmt|;
comment|// Filter configurations based on the table in [EGL 1.5] section 3.4.1.2 page 29
name|std
operator|::
name|vector
operator|<
specifier|const
name|Config
operator|*
operator|>
name|filter
argument_list|(
argument|const AttributeMap&attributeMap
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|EGLint
operator|,
specifier|const
name|Config
operator|>
name|ConfigMap
expr_stmt|;
name|ConfigMap
name|mConfigs
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
