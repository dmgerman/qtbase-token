begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglplatformcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qdevicediscovery_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<xf86drm.h>
end_include
begin_include
include|#
directive|include
file|<xf86drmMode.h>
end_include
begin_include
include|#
directive|include
file|<gbm.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"qt.qpa.eglfs.kms"
argument_list|)
DECL|member|m_waitForFlipMutex
name|QMutex
name|QEglFSKmsScreen
operator|::
name|m_waitForFlipMutex
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QEglFSKmsIntegration
name|QEglFSKmsIntegration
operator|::
name|QEglFSKmsIntegration
parameter_list|()
member_init_list|:
name|m_device
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_hwCursor
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|m_pbuffers
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_separateScreens
argument_list|(
literal|false
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|platformInit
name|void
name|QEglFSKmsIntegration
operator|::
name|platformInit
parameter_list|()
block|{
name|loadConfig
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_devicePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Using DRM device"
operator|<<
name|m_devicePath
operator|<<
literal|"specified in config file"
expr_stmt|;
block|}
else|else
block|{
name|QDeviceDiscovery
modifier|*
name|d
init|=
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_VideoMask
argument_list|)
decl_stmt|;
name|QStringList
name|devices
init|=
name|d
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Found the following video devices:"
operator|<<
name|devices
expr_stmt|;
name|d
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
if|if
condition|(
name|devices
operator|.
name|isEmpty
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Could not find DRM device!"
argument_list|)
expr_stmt|;
name|m_devicePath
operator|=
name|devices
operator|.
name|first
argument_list|()
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Using"
operator|<<
name|m_devicePath
expr_stmt|;
block|}
name|m_device
operator|=
operator|new
name|QEglFSKmsDevice
argument_list|(
name|this
argument_list|,
name|m_devicePath
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_device
operator|->
name|open
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Could not open device %s - aborting!"
argument_list|,
name|qPrintable
argument_list|(
name|m_devicePath
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSKmsIntegration
operator|::
name|platformDestroy
parameter_list|()
block|{
name|m_device
operator|->
name|close
argument_list|()
expr_stmt|;
operator|delete
name|m_device
expr_stmt|;
name|m_device
operator|=
name|Q_NULLPTR
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSKmsIntegration
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|m_device
argument_list|)
expr_stmt|;
return|return
cast|reinterpret_cast
argument_list|<
name|EGLNativeDisplayType
argument_list|>
argument_list|(
name|m_device
operator|->
name|device
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|usesDefaultScreen
name|bool
name|QEglFSKmsIntegration
operator|::
name|usesDefaultScreen
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|screenInit
name|void
name|QEglFSKmsIntegration
operator|::
name|screenInit
parameter_list|()
block|{
name|m_device
operator|->
name|createScreens
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|surfaceFormatFor
name|QSurfaceFormat
name|QEglFSKmsIntegration
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
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSKmsIntegration
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|platformWindow
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|platformWindow
operator|->
name|screen
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|surface
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Only single window per screen supported!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|screen
operator|->
name|createSurface
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeOffscreenWindow
name|EGLNativeWindowType
name|QEglFSKmsIntegration
operator|::
name|createNativeOffscreenWindow
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|m_device
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Creating native off screen window"
expr_stmt|;
name|gbm_surface
modifier|*
name|surface
init|=
name|gbm_surface_create
argument_list|(
name|m_device
operator|->
name|device
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|GBM_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_RENDERING
argument_list|)
decl_stmt|;
return|return
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|surface
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSKmsIntegration
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|gbm_surface
modifier|*
name|surface
init|=
cast|reinterpret_cast
argument_list|<
name|gbm_surface
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|gbm_surface_destroy
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSKmsIntegration
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
DECL|function|createCursor
name|QPlatformCursor
modifier|*
name|QEglFSKmsIntegration
operator|::
name|createCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|m_hwCursor
condition|)
return|return
name|Q_NULLPTR
return|;
else|else
return|return
operator|new
name|QEGLPlatformCursor
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waitForVSync
name|void
name|QEglFSKmsIntegration
operator|::
name|waitForVSync
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
argument_list|)
decl_stmt|;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|screen
operator|->
name|waitForFlip
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|presentBuffer
name|void
name|QEglFSKmsIntegration
operator|::
name|presentBuffer
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QWindow
modifier|*
name|window
init|=
cast|static_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
argument_list|)
decl_stmt|;
name|QEglFSKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|screen
operator|->
name|flip
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsPBuffers
name|bool
name|QEglFSKmsIntegration
operator|::
name|supportsPBuffers
parameter_list|()
specifier|const
block|{
return|return
name|m_pbuffers
return|;
block|}
end_function
begin_function
DECL|function|hwCursor
name|bool
name|QEglFSKmsIntegration
operator|::
name|hwCursor
parameter_list|()
specifier|const
block|{
return|return
name|m_hwCursor
return|;
block|}
end_function
begin_function
DECL|function|separateScreens
name|bool
name|QEglFSKmsIntegration
operator|::
name|separateScreens
parameter_list|()
specifier|const
block|{
return|return
name|m_separateScreens
return|;
block|}
end_function
begin_function
DECL|function|outputSettings
name|QMap
argument_list|<
name|QString
argument_list|,
name|QVariantMap
argument_list|>
name|QEglFSKmsIntegration
operator|::
name|outputSettings
parameter_list|()
specifier|const
block|{
return|return
name|m_outputSettings
return|;
block|}
end_function
begin_function
DECL|function|loadConfig
name|void
name|QEglFSKmsIntegration
operator|::
name|loadConfig
parameter_list|()
block|{
specifier|static
name|QByteArray
name|json
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_KMS_CONFIG"
argument_list|)
decl_stmt|;
if|if
condition|(
name|json
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Loading KMS setup from"
operator|<<
name|json
expr_stmt|;
name|QFile
name|file
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|json
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Could not open config file"
operator|<<
name|json
operator|<<
literal|"for reading"
expr_stmt|;
return|return;
block|}
specifier|const
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|doc
operator|.
name|isObject
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Invalid config file"
operator|<<
name|json
operator|<<
literal|"- no top-level JSON object"
expr_stmt|;
return|return;
block|}
specifier|const
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
name|m_hwCursor
operator|=
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"hwcursor"
argument_list|)
argument_list|)
operator|.
name|toBool
argument_list|(
name|m_hwCursor
argument_list|)
expr_stmt|;
name|m_pbuffers
operator|=
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pbuffers"
argument_list|)
argument_list|)
operator|.
name|toBool
argument_list|(
name|m_pbuffers
argument_list|)
expr_stmt|;
name|m_devicePath
operator|=
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"device"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|m_separateScreens
operator|=
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"separateScreens"
argument_list|)
argument_list|)
operator|.
name|toBool
argument_list|(
name|m_separateScreens
argument_list|)
expr_stmt|;
specifier|const
name|QJsonArray
name|outputs
init|=
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"outputs"
argument_list|)
argument_list|)
operator|.
name|toArray
argument_list|()
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
name|outputs
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QVariantMap
name|outputSettings
init|=
name|outputs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toObject
argument_list|()
operator|.
name|toVariantMap
argument_list|()
decl_stmt|;
if|if
condition|(
name|outputSettings
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"name"
argument_list|)
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|name
init|=
name|outputSettings
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"name"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_outputSettings
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Output"
operator|<<
name|name
operator|<<
literal|"configured multiple times!"
expr_stmt|;
block|}
name|m_outputSettings
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|outputSettings
argument_list|)
expr_stmt|;
block|}
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Configuration:\n"
operator|<<
literal|"\thwcursor:"
operator|<<
name|m_hwCursor
operator|<<
literal|"\n"
operator|<<
literal|"\tpbuffers:"
operator|<<
name|m_pbuffers
operator|<<
literal|"\n"
operator|<<
literal|"\tseparateScreens:"
operator|<<
name|m_separateScreens
operator|<<
literal|"\n"
operator|<<
literal|"\toutputs:"
operator|<<
name|m_outputSettings
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
