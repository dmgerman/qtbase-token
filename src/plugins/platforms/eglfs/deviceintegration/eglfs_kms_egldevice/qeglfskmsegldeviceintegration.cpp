begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsegldeviceintegration.h"
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"qt.qpa.eglfs.kms"
argument_list|)
DECL|function|QEglFSKmsEglDeviceIntegration
name|QEglFSKmsEglDeviceIntegration
operator|::
name|QEglFSKmsEglDeviceIntegration
argument_list|()
range|:
name|m_dri_fd
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|,
name|m_egl_device
argument_list|(
name|EGL_NO_DEVICE_EXT
argument_list|)
decl_stmt|,
name|m_egl_display
argument_list|(
name|EGL_NO_DISPLAY
argument_list|)
decl_stmt|,
name|m_drm_connector
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_drm_encoder
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_drm_crtc
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|m_funcs
argument_list|(
name|Q_NULLPTR
argument_list|)
argument_list|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"New DRM/KMS on EGLDevice integration created"
argument_list|)
argument_list|; }
DECL|function|platformInit
name|void
name|QEglFSKmsEglDeviceIntegration
operator|::
name|platformInit
argument_list|()
argument_list|{     if
operator|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|query_egl_device
argument_list|()
argument_list|)
operator|)
name|qFatal
argument_list|(
literal|"Could not set up EGL device!"
argument_list|)
argument_list|;
specifier|const
name|char
operator|*
name|deviceName
operator|=
name|m_funcs
operator|->
name|query_device_string
argument_list|(
name|m_egl_device
argument_list|,
name|EGL_DRM_DEVICE_FILE_EXT
argument_list|)
argument_list|;     if
operator|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|deviceName
argument_list|)
operator|)
name|qFatal
argument_list|(
literal|"Failed to query device name from EGLDevice"
argument_list|)
argument_list|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Opening %s"
argument_list|,
name|deviceName
argument_list|)
argument_list|;
name|m_dri_fd
operator|=
name|drmOpen
argument_list|(
name|deviceName
argument_list|,
name|Q_NULLPTR
argument_list|)
argument_list|;     if
operator|(
name|Q_UNLIKELY
argument_list|(
name|m_dri_fd
operator|<
literal|0
argument_list|)
operator|)
name|qFatal
argument_list|(
literal|"Could not open DRM device"
argument_list|)
argument_list|;      if
operator|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|setup_kms
argument_list|()
argument_list|)
operator|)
name|qFatal
argument_list|(
literal|"Could not set up KMS on device %s!"
argument_list|,
name|m_device
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"DRM/KMS initialized"
argument_list|)
argument_list|; }
DECL|function|platformDestroy
name|void
name|QEglFSKmsEglDeviceIntegration
operator|::
name|platformDestroy
argument_list|()
argument_list|{     if
operator|(
name|qt_safe_close
argument_list|(
name|m_dri_fd
argument_list|)
operator|==
operator|-
literal|1
operator|)
name|qErrnoWarning
argument_list|(
literal|"Could not close DRM device"
argument_list|)
argument_list|;
name|m_dri_fd
operator|=
operator|-
literal|1
argument_list|;
operator|delete
name|m_funcs
argument_list|;
name|m_funcs
operator|=
name|Q_NULLPTR
argument_list|; }
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSKmsEglDeviceIntegration
operator|::
name|platformDisplay
argument_list|()
decl|const
argument_list|{     return
cast|static_cast
argument_list|<
name|EGLNativeDisplayType
argument_list|>
argument_list|(
name|m_egl_device
argument_list|)
argument_list|; }
DECL|function|createDisplay
name|EGLDisplay
name|QEglFSKmsEglDeviceIntegration
operator|::
name|createDisplay
argument_list|(
name|EGLNativeDisplayType
name|nativeDisplay
argument_list|)
argument_list|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Creating display"
argument_list|)
argument_list|;
name|EGLDisplay
name|display
argument_list|;      if
operator|(
name|m_funcs
operator|->
name|has_egl_platform_device
operator|)
block|{
name|display
operator|=
name|m_funcs
operator|->
name|get_platform_display
argument_list|(
name|EGL_PLATFORM_DEVICE_EXT
argument_list|,
name|nativeDisplay
argument_list|,
name|Q_NULLPTR
argument_list|)
block|;     }
else|else
block|{
name|qWarning
argument_list|(
literal|"EGL_EXT_platform_device not available, falling back to legacy path!"
argument_list|)
block|;
name|display
operator|=
name|eglGetDisplay
argument_list|(
name|nativeDisplay
argument_list|)
block|;     }
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|display
operator|==
name|EGL_NO_DISPLAY
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not get EGL display"
argument_list|)
expr_stmt|;
end_decl_stmt
begin_decl_stmt
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|eglInitialize
argument_list|(
name|display
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize egl display"
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Failed to bind EGL_OPENGL_ES_API\n"
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|display
return|;
end_return
begin_macro
unit|}  QSizeF
DECL|function|physicalScreenSize
name|QEglFSKmsEglDeviceIntegration
end_macro
begin_expr_stmt
DECL|function|physicalScreenSize
operator|::
name|physicalScreenSize
operator|(
operator|)
specifier|const
block|{
specifier|const
name|int
name|defaultPhysicalDpi
operator|=
literal|100
block|;
specifier|static
specifier|const
name|int
name|width
operator|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_PHYSICAL_WIDTH"
argument_list|)
block|;
specifier|static
specifier|const
name|int
name|height
operator|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_PHYSICAL_HEIGHT"
argument_list|)
block|;
name|QSizeF
name|size
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
block|;
if|if
condition|(
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|size
operator|=
name|QSizeF
argument_list|(
name|m_drm_connector
operator|->
name|mmWidth
argument_list|,
name|m_drm_connector
operator|->
name|mmHeight
argument_list|)
expr_stmt|;
if|if
condition|(
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|float
name|pixelsPerMm
init|=
name|Q_MM_PER_INCH
operator|/
name|defaultPhysicalDpi
decl_stmt|;
name|size
operator|=
name|QSizeF
argument_list|(
name|screenSize
argument_list|()
operator|.
name|width
argument_list|()
operator|*
name|pixelsPerMm
argument_list|,
name|screenSize
argument_list|()
operator|.
name|height
argument_list|()
operator|*
name|pixelsPerMm
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     return
name|size
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  QSize
DECL|function|screenSize
name|QEglFSKmsEglDeviceIntegration
end_macro
begin_expr_stmt
DECL|function|screenSize
operator|::
name|screenSize
operator|(
operator|)
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|m_drm_mode
operator|.
name|hdisplay
argument_list|,
name|m_drm_mode
operator|.
name|vdisplay
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|screenDepth
name|int
name|QEglFSKmsEglDeviceIntegration
operator|::
name|screenDepth
parameter_list|()
specifier|const
block|{
return|return
literal|32
return|;
block|}
end_function
begin_function
DECL|function|surfaceFormatFor
name|QSurfaceFormat
name|QEglFSKmsEglDeviceIntegration
operator|::
name|surfaceFormatFor
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|inputFormat
parameter_list|)
specifier|const
block|{
name|QSurfaceFormat
name|format
argument_list|(
name|inputFormat
argument_list|)
decl_stmt|;
name|format
operator|.
name|setRenderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|OpenGLES
argument_list|)
expr_stmt|;
name|format
operator|.
name|setSwapBehavior
argument_list|(
name|QSurfaceFormat
operator|::
name|DoubleBuffer
argument_list|)
expr_stmt|;
name|format
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|format
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|format
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
return|return
name|format
return|;
block|}
end_function
begin_function
DECL|function|surfaceType
name|EGLint
name|QEglFSKmsEglDeviceIntegration
operator|::
name|surfaceType
parameter_list|()
specifier|const
block|{
return|return
name|EGL_STREAM_BIT_KHR
return|;
block|}
end_function
begin_class
DECL|class|QEglJetsonTK1Window
class|class
name|QEglJetsonTK1Window
super|:
specifier|public
name|QEglFSWindow
block|{
public|public:
DECL|function|QEglJetsonTK1Window
name|QEglJetsonTK1Window
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QEglFSKmsEglDeviceIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|QEglFSWindow
argument_list|(
name|w
argument_list|)
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_egl_stream
argument_list|(
name|EGL_NO_STREAM_KHR
argument_list|)
block|{ }
DECL|member|Q_DECL_OVERRIDE
name|void
name|invalidateSurface
parameter_list|()
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|resetSurface
parameter_list|()
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|m_integration
specifier|const
name|QEglFSKmsEglDeviceIntegration
modifier|*
name|m_integration
decl_stmt|;
DECL|member|m_egl_stream
name|EGLStreamKHR
name|m_egl_stream
decl_stmt|;
DECL|member|m_latency
name|EGLint
name|m_latency
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|invalidateSurface
name|void
name|QEglJetsonTK1Window
operator|::
name|invalidateSurface
parameter_list|()
block|{
name|QEglFSWindow
operator|::
name|invalidateSurface
argument_list|()
expr_stmt|;
name|m_integration
operator|->
name|m_funcs
operator|->
name|destroy_stream
argument_list|(
name|screen
argument_list|()
operator|->
name|display
argument_list|()
argument_list|,
name|m_egl_stream
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetSurface
name|void
name|QEglJetsonTK1Window
operator|::
name|resetSurface
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Creating stream"
argument_list|)
expr_stmt|;
name|EGLDisplay
name|display
init|=
name|screen
argument_list|()
operator|->
name|display
argument_list|()
decl_stmt|;
name|EGLOutputLayerEXT
name|layer
init|=
name|EGL_NO_OUTPUT_LAYER_EXT
decl_stmt|;
name|EGLint
name|count
decl_stmt|;
name|m_egl_stream
operator|=
name|m_integration
operator|->
name|m_funcs
operator|->
name|create_stream
argument_list|(
name|display
argument_list|,
name|Q_NULLPTR
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_egl_stream
operator|==
name|EGL_NO_STREAM_KHR
condition|)
block|{
name|qWarning
argument_list|(
literal|"resetSurface: Couldn't create EGLStream for native window"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Created stream %p on display %p"
argument_list|,
name|m_egl_stream
argument_list|,
name|display
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_integration
operator|->
name|m_funcs
operator|->
name|get_output_layers
argument_list|(
name|display
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
literal|0
argument_list|,
operator|&
name|count
argument_list|)
operator|||
name|count
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"No output layers found"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Output has %d layers"
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|EGLOutputLayerEXT
argument_list|>
name|layers
decl_stmt|;
name|layers
operator|.
name|resize
argument_list|(
name|count
argument_list|)
expr_stmt|;
name|EGLint
name|actualCount
decl_stmt|;
if|if
condition|(
operator|!
name|m_integration
operator|->
name|m_funcs
operator|->
name|get_output_layers
argument_list|(
name|display
argument_list|,
name|Q_NULLPTR
argument_list|,
name|layers
operator|.
name|data
argument_list|()
argument_list|,
name|count
argument_list|,
operator|&
name|actualCount
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to get layers"
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actualCount
condition|;
operator|++
name|i
control|)
block|{
name|EGLAttrib
name|id
decl_stmt|;
if|if
condition|(
name|m_integration
operator|->
name|m_funcs
operator|->
name|query_output_layer_attrib
argument_list|(
name|display
argument_list|,
name|layers
index|[
name|i
index|]
argument_list|,
name|EGL_DRM_CRTC_EXT
argument_list|,
operator|&
name|id
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"  [%d] layer %p - crtc %d"
argument_list|,
name|i
argument_list|,
name|layers
index|[
name|i
index|]
argument_list|,
operator|(
name|int
operator|)
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|id
operator|==
name|EGLAttrib
argument_list|(
name|m_integration
operator|->
name|m_drm_crtc
argument_list|)
condition|)
name|layer
operator|=
name|layers
index|[
name|i
index|]
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|m_integration
operator|->
name|m_funcs
operator|->
name|query_output_layer_attrib
argument_list|(
name|display
argument_list|,
name|layers
index|[
name|i
index|]
argument_list|,
name|EGL_DRM_PLANE_EXT
argument_list|,
operator|&
name|id
argument_list|)
condition|)
block|{
comment|// Not used yet, just for debugging.
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"  [%d] layer %p - plane %d"
argument_list|,
name|i
argument_list|,
name|layers
index|[
name|i
index|]
argument_list|,
operator|(
name|int
operator|)
name|id
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"  [%d] layer %p - unknown"
argument_list|,
name|i
argument_list|,
name|layers
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|QByteArray
name|reqLayerIndex
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_LAYER_INDEX"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reqLayerIndex
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|int
name|idx
init|=
name|reqLayerIndex
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|idx
operator|>=
literal|0
operator|&&
name|idx
operator|<
name|layers
operator|.
name|count
argument_list|()
condition|)
name|layer
operator|=
name|layers
index|[
name|idx
index|]
expr_stmt|;
block|}
if|if
condition|(
name|layer
operator|==
name|EGL_NO_OUTPUT_LAYER_EXT
condition|)
block|{
name|qWarning
argument_list|(
literal|"resetSurface: Couldn't get EGLOutputLayer for native window"
argument_list|)
expr_stmt|;
return|return;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Using layer %p"
argument_list|,
name|layer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_integration
operator|->
name|m_funcs
operator|->
name|stream_consumer_output
argument_list|(
name|display
argument_list|,
name|m_egl_stream
argument_list|,
name|layer
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"resetSurface: Unable to connect stream"
argument_list|)
expr_stmt|;
name|m_config
operator|=
name|QEglFSIntegration
operator|::
name|chooseConfig
argument_list|(
name|display
argument_list|,
name|m_integration
operator|->
name|surfaceFormatFor
argument_list|(
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Stream producer format is"
operator|<<
name|m_format
expr_stmt|;
specifier|const
name|int
name|w
init|=
name|m_integration
operator|->
name|screenSize
argument_list|()
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|h
init|=
name|m_integration
operator|->
name|screenSize
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Creating stream producer surface of size %dx%d"
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
specifier|const
name|EGLint
name|stream_producer_attribs
index|[]
init|=
block|{
name|EGL_WIDTH
block|,
name|w
block|,
name|EGL_HEIGHT
block|,
name|h
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|m_surface
operator|=
name|m_integration
operator|->
name|m_funcs
operator|->
name|create_stream_producer_surface
argument_list|(
name|display
argument_list|,
name|m_config
argument_list|,
name|m_egl_stream
argument_list|,
name|stream_producer_attribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_surface
operator|==
name|EGL_NO_SURFACE
condition|)
return|return;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Created stream producer surface %p"
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createWindow
name|QEglFSWindow
modifier|*
name|QEglFSKmsEglDeviceIntegration
operator|::
name|createWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QEglJetsonTK1Window
modifier|*
name|eglWindow
init|=
operator|new
name|QEglJetsonTK1Window
argument_list|(
name|window
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|m_funcs
operator|->
name|initialize
argument_list|(
name|eglWindow
operator|->
name|screen
argument_list|()
operator|->
name|display
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
operator|(
name|m_funcs
operator|->
name|has_egl_output_base
operator|&&
name|m_funcs
operator|->
name|has_egl_output_drm
operator|&&
name|m_funcs
operator|->
name|has_egl_stream
operator|&&
name|m_funcs
operator|->
name|has_egl_stream_producer_eglsurface
operator|&&
name|m_funcs
operator|->
name|has_egl_stream_consumer_egloutput
operator|)
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Required extensions missing!"
argument_list|)
expr_stmt|;
return|return
name|eglWindow
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSKmsEglDeviceIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|ThreadedPixmaps
case|:
case|case
name|QPlatformIntegration
operator|::
name|OpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|ThreadedOpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|BufferQueueingOpenGL
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_function
DECL|function|waitForVSync
name|void
name|QEglFSKmsEglDeviceIntegration
operator|::
name|waitForVSync
parameter_list|(
name|QPlatformSurface
modifier|*
parameter_list|)
specifier|const
block|{
specifier|static
name|bool
name|mode_set
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|mode_set
condition|)
block|{
name|mode_set
operator|=
literal|true
expr_stmt|;
name|drmModeCrtcPtr
name|currentMode
init|=
name|drmModeGetCrtc
argument_list|(
name|m_dri_fd
argument_list|,
name|m_drm_crtc
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|alreadySet
init|=
name|currentMode
operator|&&
name|currentMode
operator|->
name|width
operator|==
name|m_drm_mode
operator|.
name|hdisplay
operator|&&
name|currentMode
operator|->
name|height
operator|==
name|m_drm_mode
operator|.
name|vdisplay
decl_stmt|;
if|if
condition|(
name|currentMode
condition|)
name|drmModeFreeCrtc
argument_list|(
name|currentMode
argument_list|)
expr_stmt|;
if|if
condition|(
name|alreadySet
condition|)
block|{
comment|// Maybe detecting the DPMS mode could help here, but there are no properties
comment|// exposed on the connector apparently. So rely on an env var for now.
specifier|static
name|bool
name|alwaysDoSet
init|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_ALWAYS_SET_MODE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|alwaysDoSet
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Mode already set"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Setting mode"
argument_list|)
expr_stmt|;
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|m_dri_fd
argument_list|,
name|m_drm_crtc
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|m_drm_connector
operator|->
name|connector_id
argument_list|,
literal|1
argument_list|,
cast|const_cast
argument_list|<
specifier|const
name|drmModeModeInfoPtr
argument_list|>
argument_list|(
operator|&
name|m_drm_mode
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|ret
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"drmModeSetCrtc failed"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|refreshRate
name|qreal
name|QEglFSKmsEglDeviceIntegration
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
name|quint32
name|refresh
init|=
name|m_drm_mode
operator|.
name|vrefresh
decl_stmt|;
return|return
name|refresh
operator|>
literal|0
condition|?
name|refresh
else|:
literal|60
return|;
block|}
end_function
begin_function
DECL|function|supportsSurfacelessContexts
name|bool
name|QEglFSKmsEglDeviceIntegration
operator|::
name|supportsSurfacelessContexts
parameter_list|()
specifier|const
block|{
comment|// Returning false disables the usage of EGL_KHR_surfaceless_context even when the
comment|// extension is available. This is just what we need since, at least with NVIDIA
comment|// 352.00 making a null surface current with a context breaks.
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setup_kms
name|bool
name|QEglFSKmsEglDeviceIntegration
operator|::
name|setup_kms
parameter_list|()
block|{
name|drmModeRes
modifier|*
name|resources
decl_stmt|;
name|drmModeConnector
modifier|*
name|connector
decl_stmt|;
name|drmModeEncoder
modifier|*
name|encoder
decl_stmt|;
name|quint32
name|crtc
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|resources
operator|=
name|drmModeGetResources
argument_list|(
name|m_dri_fd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|resources
condition|)
block|{
name|qWarning
argument_list|(
literal|"drmModeGetResources failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|resources
operator|->
name|count_connectors
condition|;
name|i
operator|++
control|)
block|{
name|connector
operator|=
name|drmModeGetConnector
argument_list|(
name|m_dri_fd
argument_list|,
name|resources
operator|->
name|connectors
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|connector
condition|)
continue|continue;
if|if
condition|(
name|connector
operator|->
name|connection
operator|==
name|DRM_MODE_CONNECTED
operator|&&
name|connector
operator|->
name|count_modes
operator|>
literal|0
condition|)
break|break;
name|drmModeFreeConnector
argument_list|(
name|connector
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|==
name|resources
operator|->
name|count_connectors
condition|)
block|{
name|qWarning
argument_list|(
literal|"No currently active connector found."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Using connector with type %d"
argument_list|,
name|connector
operator|->
name|connector_type
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|resources
operator|->
name|count_encoders
condition|;
name|i
operator|++
control|)
block|{
name|encoder
operator|=
name|drmModeGetEncoder
argument_list|(
name|m_dri_fd
argument_list|,
name|resources
operator|->
name|encoders
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|encoder
condition|)
continue|continue;
if|if
condition|(
name|encoder
operator|->
name|encoder_id
operator|==
name|connector
operator|->
name|encoder_id
condition|)
break|break;
name|drmModeFreeEncoder
argument_list|(
name|encoder
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|resources
operator|->
name|count_crtcs
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|encoder
operator|->
name|possible_crtcs
operator|&
operator|(
literal|1
operator|<<
name|j
operator|)
operator|)
condition|)
block|{
name|crtc
operator|=
name|resources
operator|->
name|crtcs
index|[
name|j
index|]
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|crtc
operator|==
literal|0
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"No suitable CRTC available"
argument_list|)
expr_stmt|;
name|m_drm_connector
operator|=
name|connector
expr_stmt|;
name|m_drm_encoder
operator|=
name|encoder
expr_stmt|;
name|m_drm_mode
operator|=
name|connector
operator|->
name|modes
index|[
literal|0
index|]
expr_stmt|;
name|m_drm_crtc
operator|=
name|crtc
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|.
name|noquote
argument_list|()
operator|<<
literal|"Using crtc"
operator|<<
name|m_drm_crtc
operator|<<
literal|"with mode"
operator|<<
name|m_drm_mode
operator|.
name|hdisplay
operator|<<
literal|"x"
operator|<<
name|m_drm_mode
operator|.
name|vdisplay
operator|<<
literal|"@"
operator|<<
name|m_drm_mode
operator|.
name|vrefresh
expr_stmt|;
name|drmModeFreeResources
argument_list|(
name|resources
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|query_egl_device
name|bool
name|QEglFSKmsEglDeviceIntegration
operator|::
name|query_egl_device
parameter_list|()
block|{
name|m_funcs
operator|=
operator|new
name|QEGLStreamConvenience
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|m_funcs
operator|->
name|has_egl_device_base
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"EGL_EXT_device_base missing"
argument_list|)
expr_stmt|;
name|EGLint
name|num_devices
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|m_funcs
operator|->
name|query_devices
argument_list|(
literal|1
argument_list|,
operator|&
name|m_egl_device
argument_list|,
operator|&
name|num_devices
argument_list|)
operator|!=
name|EGL_TRUE
condition|)
block|{
name|qWarning
argument_list|(
literal|"eglQueryDevicesEXT failed: eglError: %x"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Found %d EGL devices"
argument_list|,
name|num_devices
argument_list|)
expr_stmt|;
if|if
condition|(
name|num_devices
operator|<
literal|1
operator|||
name|m_egl_device
operator|==
name|EGL_NO_DEVICE_EXT
condition|)
block|{
name|qWarning
argument_list|(
literal|"eglQueryDevicesEXT could not find any EGL devices"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
