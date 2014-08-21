begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmscursor.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qkmscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaScreen
argument_list|,
literal|"qt.qpa.kms.screen"
argument_list|)
comment|//Fallback mode (taken from Wayland DRM demo compositor)
decl|static
DECL|variable|builtin_1024x768
name|drmModeModeInfo
name|builtin_1024x768
init|=
block|{
literal|63500
block|,
comment|//clock
literal|1024
block|,
literal|1072
block|,
literal|1176
block|,
literal|1328
block|,
literal|0
block|,
literal|768
block|,
literal|771
block|,
literal|775
block|,
literal|798
block|,
literal|0
block|,
literal|59920
block|,
name|DRM_MODE_FLAG_NHSYNC
operator||
name|DRM_MODE_FLAG_PVSYNC
block|,
literal|0
block|,
literal|"1024x768"
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QKmsScreen
name|QKmsScreen
operator|::
name|QKmsScreen
parameter_list|(
name|QKmsDevice
modifier|*
name|device
parameter_list|,
specifier|const
name|drmModeRes
modifier|*
name|resources
parameter_list|,
specifier|const
name|drmModeConnector
modifier|*
name|connector
parameter_list|)
member_init_list|:
name|m_device
argument_list|(
name|device
argument_list|)
member_init_list|,
name|m_current_bo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_next_bo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_connectorId
argument_list|(
name|connector
operator|->
name|connector_id
argument_list|)
member_init_list|,
name|m_depth
argument_list|(
literal|32
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|QImage
operator|::
name|Format_Invalid
argument_list|)
member_init_list|,
name|m_eglWindowSurface
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
member_init_list|,
name|m_modeSet
argument_list|(
literal|false
argument_list|)
block|{
name|m_cursor
operator|=
operator|new
name|QKmsCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|initializeScreenMode
argument_list|(
name|resources
argument_list|,
name|connector
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QKmsScreen
name|QKmsScreen
operator|::
name|~
name|QKmsScreen
parameter_list|()
block|{
operator|delete
name|m_cursor
expr_stmt|;
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_oldCrtc
operator|->
name|crtc_id
argument_list|,
name|m_oldCrtc
operator|->
name|buffer_id
argument_list|,
name|m_oldCrtc
operator|->
name|x
argument_list|,
name|m_oldCrtc
operator|->
name|y
argument_list|,
operator|&
name|m_connectorId
argument_list|,
literal|1
argument_list|,
operator|&
name|m_oldCrtc
operator|->
name|mode
argument_list|)
expr_stmt|;
name|drmModeFreeCrtc
argument_list|(
name|m_oldCrtc
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglWindowSurface
operator|!=
name|EGL_NO_SURFACE
condition|)
name|eglDestroySurface
argument_list|(
name|m_device
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|m_eglWindowSurface
argument_list|)
expr_stmt|;
name|gbm_surface_destroy
argument_list|(
name|m_gbmSurface
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|geometry
name|QRect
name|QKmsScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
return|return
name|m_geometry
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QKmsScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
end_function
begin_function
DECL|function|format
name|QImage
operator|::
name|Format
name|QKmsScreen
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|physicalSize
name|QSizeF
name|QKmsScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
return|return
name|m_physicalSize
return|;
block|}
end_function
begin_function
DECL|function|cursor
name|QPlatformCursor
modifier|*
name|QKmsScreen
operator|::
name|cursor
parameter_list|()
specifier|const
block|{
return|return
name|m_cursor
return|;
block|}
end_function
begin_function
DECL|function|initializeScreenMode
name|void
name|QKmsScreen
operator|::
name|initializeScreenMode
parameter_list|(
specifier|const
name|drmModeRes
modifier|*
name|resources
parameter_list|,
specifier|const
name|drmModeConnector
modifier|*
name|connector
parameter_list|)
block|{
comment|//Determine optimal mode for screen
name|drmModeModeInfo
modifier|*
name|mode
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connector
operator|->
name|count_modes
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|connector
operator|->
name|modes
index|[
name|i
index|]
operator|.
name|type
operator|&
name|DRM_MODE_TYPE_PREFERRED
condition|)
block|{
name|mode
operator|=
operator|&
name|connector
operator|->
name|modes
index|[
name|i
index|]
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|mode
condition|)
block|{
if|if
condition|(
name|connector
operator|->
name|count_modes
operator|>
literal|0
condition|)
name|mode
operator|=
operator|&
name|connector
operator|->
name|modes
index|[
literal|0
index|]
expr_stmt|;
else|else
name|mode
operator|=
operator|&
name|builtin_1024x768
expr_stmt|;
block|}
name|drmModeEncoder
modifier|*
name|encoder
init|=
name|drmModeGetEncoder
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|connector
operator|->
name|encoders
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|encoder
operator|==
literal|0
condition|)
name|qFatal
argument_list|(
literal|"No encoder for connector."
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
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
name|count_crtcs
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|encoder
operator|->
name|possible_crtcs
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
break|break;
block|}
if|if
condition|(
name|i
operator|==
name|resources
operator|->
name|count_crtcs
condition|)
name|qFatal
argument_list|(
literal|"No usable crtc for encoder."
argument_list|)
expr_stmt|;
name|m_oldCrtc
operator|=
name|drmModeGetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|encoder
operator|->
name|crtc_id
argument_list|)
expr_stmt|;
name|m_crtcId
operator|=
name|resources
operator|->
name|crtcs
index|[
name|i
index|]
expr_stmt|;
name|m_mode
operator|=
operator|*
name|mode
expr_stmt|;
name|m_geometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_mode
operator|.
name|hdisplay
argument_list|,
name|m_mode
operator|.
name|vdisplay
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaScreen
argument_list|)
operator|<<
literal|"kms initialized with geometry"
operator|<<
name|m_geometry
expr_stmt|;
name|m_depth
operator|=
literal|32
expr_stmt|;
name|m_format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
name|m_physicalSize
operator|=
name|QSizeF
argument_list|(
name|connector
operator|->
name|mmWidth
argument_list|,
name|connector
operator|->
name|mmHeight
argument_list|)
expr_stmt|;
name|m_gbmSurface
operator|=
name|gbm_surface_create
argument_list|(
name|m_device
operator|->
name|gbmDevice
argument_list|()
argument_list|,
name|m_mode
operator|.
name|hdisplay
argument_list|,
name|m_mode
operator|.
name|vdisplay
argument_list|,
name|GBM_BO_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_SCANOUT
operator||
name|GBM_BO_USE_RENDERING
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaScreen
argument_list|)
operator|<<
literal|"created gbm surface"
operator|<<
name|m_gbmSurface
operator|<<
name|m_mode
operator|.
name|hdisplay
operator|<<
name|m_mode
operator|.
name|vdisplay
expr_stmt|;
comment|//Cleanup
name|drmModeFreeEncoder
argument_list|(
name|encoder
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tweakFormat
name|QSurfaceFormat
name|QKmsScreen
operator|::
name|tweakFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|QSurfaceFormat
name|fmt
init|=
name|format
decl_stmt|;
name|fmt
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
if|if
condition|(
name|fmt
operator|.
name|alphaBufferSize
argument_list|()
operator|!=
operator|-
literal|1
condition|)
name|fmt
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
return|return
name|fmt
return|;
block|}
end_function
begin_function
DECL|function|initializeWithFormat
name|void
name|QKmsScreen
operator|::
name|initializeWithFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|EGLDisplay
name|display
init|=
name|m_device
operator|->
name|eglDisplay
argument_list|()
decl_stmt|;
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|display
argument_list|,
name|tweakFormat
argument_list|(
name|format
argument_list|)
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|m_eglWindowSurface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
operator|(
name|EGLNativeWindowType
operator|)
name|m_gbmSurface
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaScreen
argument_list|)
operator|<<
literal|"created window surface"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QKmsScreen
operator|::
name|swapBuffers
parameter_list|()
block|{
name|eglSwapBuffers
argument_list|(
name|m_device
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|m_eglWindowSurface
argument_list|)
expr_stmt|;
name|m_next_bo
operator|=
name|gbm_surface_lock_front_buffer
argument_list|(
name|m_gbmSurface
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_next_bo
condition|)
name|qFatal
argument_list|(
literal|"kms: Failed to lock front buffer"
argument_list|)
expr_stmt|;
name|performPageFlip
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|performPageFlip
name|void
name|QKmsScreen
operator|::
name|performPageFlip
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_next_bo
condition|)
return|return;
name|uint32_t
name|width
init|=
name|gbm_bo_get_width
argument_list|(
name|m_next_bo
argument_list|)
decl_stmt|;
name|uint32_t
name|height
init|=
name|gbm_bo_get_height
argument_list|(
name|m_next_bo
argument_list|)
decl_stmt|;
name|uint32_t
name|stride
init|=
name|gbm_bo_get_stride
argument_list|(
name|m_next_bo
argument_list|)
decl_stmt|;
name|uint32_t
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|m_next_bo
argument_list|)
operator|.
name|u32
decl_stmt|;
name|uint32_t
name|fb_id
decl_stmt|;
name|int
name|ret
init|=
name|drmModeAddFB
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|24
argument_list|,
literal|32
argument_list|,
name|stride
argument_list|,
name|handle
argument_list|,
operator|&
name|fb_id
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|qFatal
argument_list|(
literal|"kms: Failed to create fb: fd %d, w %d, h %d, stride %d, handle %d, ret %d"
argument_list|,
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|stride
argument_list|,
name|handle
argument_list|,
name|ret
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_modeSet
condition|)
block|{
comment|//Set the Mode of the screen.
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_crtcId
argument_list|,
name|fb_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|m_connectorId
argument_list|,
literal|1
argument_list|,
operator|&
name|m_mode
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
name|qFatal
argument_list|(
literal|"failed to set mode"
argument_list|)
expr_stmt|;
name|m_modeSet
operator|=
literal|true
expr_stmt|;
comment|// Initialize cursor
specifier|static
name|int
name|hideCursor
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_KMS_HIDECURSOR"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hideCursor
condition|)
block|{
name|QCursor
name|cursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
decl_stmt|;
name|m_cursor
operator|->
name|changeCursor
argument_list|(
operator|&
name|cursor
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|int
name|pageFlipStatus
init|=
name|drmModePageFlip
argument_list|(
name|m_device
operator|->
name|fd
argument_list|()
argument_list|,
name|m_crtcId
argument_list|,
name|fb_id
argument_list|,
name|DRM_MODE_PAGE_FLIP_EVENT
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|pageFlipStatus
condition|)
block|{
name|qWarning
argument_list|(
literal|"Pageflip status: %d"
argument_list|,
name|pageFlipStatus
argument_list|)
expr_stmt|;
name|gbm_surface_release_buffer
argument_list|(
name|m_gbmSurface
argument_list|,
name|m_next_bo
argument_list|)
expr_stmt|;
name|m_next_bo
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handlePageFlipped
name|void
name|QKmsScreen
operator|::
name|handlePageFlipped
parameter_list|()
block|{
if|if
condition|(
name|m_current_bo
condition|)
name|gbm_surface_release_buffer
argument_list|(
name|m_gbmSurface
argument_list|,
name|m_current_bo
argument_list|)
expr_stmt|;
name|m_current_bo
operator|=
name|m_next_bo
expr_stmt|;
name|m_next_bo
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|device
name|QKmsDevice
modifier|*
name|QKmsScreen
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|m_device
return|;
block|}
end_function
begin_function
DECL|function|waitForPageFlipComplete
name|void
name|QKmsScreen
operator|::
name|waitForPageFlipComplete
parameter_list|()
block|{
while|while
condition|(
name|m_next_bo
condition|)
block|{
if|#
directive|if
literal|0
comment|//Check manually if there is something to be read on the device
comment|//as there are senarios where the signal is not received (starvation)
block|fd_set fdSet;         timeval timeValue;         int returnValue;          FD_ZERO(&fdSet);         FD_SET(m_device->fd(),&fdSet);         timeValue.tv_sec = 0;         timeValue.tv_usec = 1000;          returnValue = select(1,&fdSet, 0, 0,&timeValue);         printf("select returns %d\n", returnValue);
endif|#
directive|endif
name|m_device
operator|->
name|handlePageFlipCompleted
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
