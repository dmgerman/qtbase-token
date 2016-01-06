begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsdeviceintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QRegularExpression>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<linux/fb.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<private/qfactoryloader_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|qLcEglDevDebug
argument_list|,
literal|"qt.qpa.egldeviceintegration"
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QEGLDeviceIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/egldeviceintegrations"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|directLoader
argument_list|,
operator|(
name|QEGLDeviceIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
comment|// QT_NO_LIBRARY
DECL|function|keys
name|QStringList
name|QEGLDeviceIntegrationFactory
operator|::
name|keys
argument_list|(
specifier|const
name|QString
operator|&
name|pluginPath
argument_list|)
argument_list|{
name|QStringList
name|list
argument_list|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
argument_list|if
operator|(
operator|!
name|pluginPath
operator|.
name|isEmpty
argument_list|()
operator|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|pluginPath
argument_list|)
block|;
name|list
operator|=
name|directLoader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
block|;
if|if
condition|(
operator|!
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|postFix
operator|=
name|QStringLiteral
argument_list|(
literal|" (from "
argument_list|)
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|pluginPath
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
block|;
specifier|const
name|QStringList
operator|::
name|iterator
name|end
operator|=
name|list
operator|.
name|end
argument_list|()
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|iterator
name|it
type|=
name|list
operator|.
name|begin
type|(
control|)
empty_stmt|;
end_decl_stmt
begin_expr_stmt
name|it
operator|!=
name|end
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|++
name|it
end_expr_stmt
begin_expr_stmt
unit|)
operator|(
operator|*
name|it
operator|)
operator|.
name|append
argument_list|(
name|postFix
argument_list|)
expr_stmt|;
end_expr_stmt
begin_else
unit|}     }
else|#
directive|else
end_else
begin_expr_stmt
name|Q_UNUSED
argument_list|(
name|pluginPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qCDebug
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"EGL device integration plugin keys:"
operator|<<
name|list
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|list
return|;
end_return
begin_expr_stmt
unit|}  QEGLDeviceIntegration
DECL|function|create
operator|*
name|QEGLDeviceIntegrationFactory
operator|::
name|create
operator|(
specifier|const
name|QString
operator|&
name|key
operator|,
specifier|const
name|QString
operator|&
name|pluginPath
operator|)
block|{
name|QEGLDeviceIntegration
operator|*
name|integration
operator|=
name|Q_NULLPTR
block|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
if|if
condition|(
operator|!
name|pluginPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|pluginPath
argument_list|)
expr_stmt|;
name|integration
operator|=
name|qLoadPlugin
argument_list|<
name|QEGLDeviceIntegration
argument_list|,
name|QEGLDeviceIntegrationPlugin
argument_list|>
argument_list|(
name|directLoader
argument_list|()
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|pluginPath
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|if
condition|(
operator|!
name|integration
condition|)
name|integration
operator|=
name|qLoadPlugin
argument_list|<
name|QEGLDeviceIntegration
argument_list|,
name|QEGLDeviceIntegrationPlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|key
argument_list|)
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|integration
condition|)
name|qCDebug
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"Using EGL device integration"
operator|<<
name|key
expr_stmt|;
else|else
name|qCWarning
argument_list|(
name|qLcEglDevDebug
argument_list|)
operator|<<
literal|"Failed to load EGL device integration"
operator|<<
name|key
expr_stmt|;
end_if
begin_return
return|return
name|integration
return|;
end_return
begin_decl_stmt
unit|}  static
DECL|variable|framebuffer
name|int
name|framebuffer
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|fbDeviceName
name|QByteArray
name|QEGLDeviceIntegration
operator|::
name|fbDeviceName
parameter_list|()
specifier|const
block|{
name|QByteArray
name|fbDev
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_FB"
argument_list|)
decl_stmt|;
if|if
condition|(
name|fbDev
operator|.
name|isEmpty
argument_list|()
condition|)
name|fbDev
operator|=
name|QByteArrayLiteral
argument_list|(
literal|"/dev/fb0"
argument_list|)
expr_stmt|;
return|return
name|fbDev
return|;
block|}
end_function
begin_function
DECL|function|framebufferIndex
name|int
name|QEGLDeviceIntegration
operator|::
name|framebufferIndex
parameter_list|()
specifier|const
block|{
name|int
name|fbIndex
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
name|QRegularExpression
name|fbIndexRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"fb(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|fbIndexRx
operator|.
name|match
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|fbDeviceName
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
name|fbIndex
operator|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|fbIndex
return|;
block|}
end_function
begin_function
DECL|function|platformInit
name|void
name|QEGLDeviceIntegration
operator|::
name|platformInit
parameter_list|()
block|{
name|QByteArray
name|fbDev
init|=
name|fbDeviceName
argument_list|()
decl_stmt|;
name|framebuffer
operator|=
name|qt_safe_open
argument_list|(
name|fbDev
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|framebuffer
operator|==
operator|-
literal|1
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"EGLFS: Failed to open %s"
argument_list|,
name|fbDev
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGLFS: Can't continue without a display"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|FBIOBLANK
name|ioctl
argument_list|(
name|framebuffer
argument_list|,
name|FBIOBLANK
argument_list|,
name|VESA_NO_BLANKING
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEGLDeviceIntegration
operator|::
name|platformDestroy
parameter_list|()
block|{
if|if
condition|(
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
name|close
argument_list|(
name|framebuffer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEGLDeviceIntegration
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
end_function
begin_function
DECL|function|createDisplay
name|EGLDisplay
name|QEGLDeviceIntegration
operator|::
name|createDisplay
parameter_list|(
name|EGLNativeDisplayType
name|nativeDisplay
parameter_list|)
block|{
return|return
name|eglGetDisplay
argument_list|(
name|nativeDisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|usesDefaultScreen
name|bool
name|QEGLDeviceIntegration
operator|::
name|usesDefaultScreen
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|screenInit
name|void
name|QEGLDeviceIntegration
operator|::
name|screenInit
parameter_list|()
block|{
comment|// Nothing to do here. Called only when usesDefaultScreen is false.
block|}
end_function
begin_function
DECL|function|screenDestroy
name|void
name|QEGLDeviceIntegration
operator|::
name|screenDestroy
parameter_list|()
block|{
name|QGuiApplication
modifier|*
name|app
init|=
name|qGuiApp
decl_stmt|;
name|QEglFSIntegration
modifier|*
name|platformIntegration
init|=
cast|static_cast
argument_list|<
name|QEglFSIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|app
operator|->
name|screens
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|platformIntegration
operator|->
name|removeScreen
argument_list|(
name|app
operator|->
name|screens
argument_list|()
operator|.
name|last
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|physicalScreenSize
name|QSizeF
name|QEGLDeviceIntegration
operator|::
name|physicalScreenSize
parameter_list|()
specifier|const
block|{
return|return
name|q_physicalScreenSizeFromFb
argument_list|(
name|framebuffer
argument_list|,
name|screenSize
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEGLDeviceIntegration
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
return|return
name|q_screenSizeFromFb
argument_list|(
name|framebuffer
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QEGLDeviceIntegration
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
specifier|const
name|QSizeF
name|ps
init|=
name|physicalScreenSize
argument_list|()
decl_stmt|;
specifier|const
name|QSize
name|s
init|=
name|screenSize
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|s
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QDpi
argument_list|(
literal|25.4
operator|*
name|s
operator|.
name|width
argument_list|()
operator|/
name|ps
operator|.
name|width
argument_list|()
argument_list|,
literal|25.4
operator|*
name|s
operator|.
name|height
argument_list|()
operator|/
name|ps
operator|.
name|height
argument_list|()
argument_list|)
return|;
else|else
return|return
name|QDpi
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pixelDensity
name|qreal
name|QEGLDeviceIntegration
operator|::
name|pixelDensity
parameter_list|()
specifier|const
block|{
return|return
name|qRound
argument_list|(
name|logicalDpi
argument_list|()
operator|.
name|first
operator|/
name|qreal
argument_list|(
literal|100
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QEGLDeviceIntegration
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QEGLDeviceIntegration
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_function
DECL|function|screenDepth
name|int
name|QEGLDeviceIntegration
operator|::
name|screenDepth
parameter_list|()
specifier|const
block|{
return|return
name|q_screenDepthFromFb
argument_list|(
name|framebuffer
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenFormat
name|QImage
operator|::
name|Format
name|QEGLDeviceIntegration
operator|::
name|screenFormat
parameter_list|()
specifier|const
block|{
return|return
name|screenDepth
argument_list|()
operator|==
literal|16
condition|?
name|QImage
operator|::
name|Format_RGB16
else|:
name|QImage
operator|::
name|Format_RGB32
return|;
block|}
end_function
begin_function
DECL|function|refreshRate
name|qreal
name|QEGLDeviceIntegration
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
return|return
name|q_refreshRateFromFb
argument_list|(
name|framebuffer
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|surfaceType
name|EGLint
name|QEGLDeviceIntegration
operator|::
name|surfaceType
parameter_list|()
specifier|const
block|{
return|return
name|EGL_WINDOW_BIT
return|;
block|}
end_function
begin_function
DECL|function|surfaceFormatFor
name|QSurfaceFormat
name|QEGLDeviceIntegration
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
init|=
name|inputFormat
decl_stmt|;
specifier|static
specifier|const
name|bool
name|force888
init|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_FORCE888"
argument_list|)
decl_stmt|;
if|if
condition|(
name|force888
condition|)
block|{
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
block|}
return|return
name|format
return|;
block|}
end_function
begin_function
DECL|function|filterConfig
name|bool
name|QEGLDeviceIntegration
operator|::
name|filterConfig
parameter_list|(
name|EGLDisplay
parameter_list|,
name|EGLConfig
parameter_list|)
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|createWindow
name|QEglFSWindow
modifier|*
name|QEGLDeviceIntegration
operator|::
name|createWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEGLDeviceIntegration
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
name|platformWindow
argument_list|)
expr_stmt|;
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
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createNativeOffscreenWindow
name|EGLNativeWindowType
name|QEGLDeviceIntegration
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
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEGLDeviceIntegration
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEGLDeviceIntegration
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
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createCursor
name|QPlatformCursor
modifier|*
name|QEGLDeviceIntegration
operator|::
name|createCursor
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSCursor
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|waitForVSync
name|void
name|QEGLDeviceIntegration
operator|::
name|waitForVSync
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|surface
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|FBIO_WAITFORVSYNC
argument_list|)
specifier|static
specifier|const
name|bool
name|forceSync
init|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_FORCEVSYNC"
argument_list|)
decl_stmt|;
if|if
condition|(
name|forceSync
operator|&&
name|framebuffer
operator|!=
operator|-
literal|1
condition|)
block|{
name|int
name|arg
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|framebuffer
argument_list|,
name|FBIO_WAITFORVSYNC
argument_list|,
operator|&
name|arg
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Could not wait for vsync."
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|presentBuffer
name|void
name|QEGLDeviceIntegration
operator|::
name|presentBuffer
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsPBuffers
name|bool
name|QEGLDeviceIntegration
operator|::
name|supportsPBuffers
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|supportsSurfacelessContexts
name|bool
name|QEGLDeviceIntegration
operator|::
name|supportsSurfacelessContexts
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|wlDisplay
name|void
modifier|*
name|QEGLDeviceIntegration
operator|::
name|wlDisplay
parameter_list|()
specifier|const
block|{
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
