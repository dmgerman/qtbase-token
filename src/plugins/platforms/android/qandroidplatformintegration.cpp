begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformaccessibility.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformforeignwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformopenglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformrasterwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformservices.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformtheme.h"
end_include
begin_include
include|#
directive|include
file|"qandroidsystemlocale.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|m_defaultGeometryWidth
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryWidth
init|=
literal|320
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultGeometryHeight
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultGeometryHeight
init|=
literal|455
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultPhysicalSizeWidth
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeWidth
init|=
literal|50
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_defaultPhysicalSizeHeight
name|int
name|QAndroidPlatformIntegration
operator|::
name|m_defaultPhysicalSizeHeight
init|=
literal|71
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_orientation
name|Qt
operator|::
name|ScreenOrientation
name|QAndroidPlatformIntegration
operator|::
name|m_orientation
init|=
name|Qt
operator|::
name|PrimaryOrientation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QAndroidPlatformIntegration
operator|::
name|m_nativeOrientation
init|=
name|Qt
operator|::
name|PrimaryOrientation
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QAndroidPlatformNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"JavaVM"
condition|)
return|return
name|QtAndroid
operator|::
name|javaVM
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"QtActivity"
condition|)
return|return
name|QtAndroid
operator|::
name|activity
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"AndroidStylePalettes"
condition|)
return|return
operator|&
name|m_palettes
return|;
if|if
condition|(
name|resource
operator|==
literal|"AndroidStyleFonts"
condition|)
return|return
operator|&
name|m_fonts
return|;
if|if
condition|(
name|resource
operator|==
literal|"AndroidDeviceName"
condition|)
block|{
specifier|static
name|QString
name|deviceName
init|=
name|QtAndroid
operator|::
name|deviceName
argument_list|()
decl_stmt|;
return|return
operator|&
name|deviceName
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_constructor
DECL|function|QAndroidPlatformIntegration
name|QAndroidPlatformIntegration
operator|::
name|QAndroidPlatformIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|m_touchDevice
argument_list|(
literal|0
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
member_init_list|,
name|m_accessibility
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
name|Q_UNUSED
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
name|m_androidPlatformNativeInterface
operator|=
operator|new
name|QAndroidPlatformNativeInterface
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not bind GL_ES API"
argument_list|)
expr_stmt|;
name|m_eglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|EGL_DEFAULT_DISPLAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
name|qFatal
argument_list|(
literal|"Could not open egl display"
argument_list|)
expr_stmt|;
name|EGLint
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_eglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Could not initialize egl display"
argument_list|)
expr_stmt|;
name|m_primaryScreen
operator|=
operator|new
name|QAndroidPlatformScreen
argument_list|()
expr_stmt|;
name|screenAdded
argument_list|(
name|m_primaryScreen
argument_list|)
expr_stmt|;
name|m_primaryScreen
operator|->
name|setPhysicalSize
argument_list|(
name|QSize
argument_list|(
name|m_defaultPhysicalSizeWidth
argument_list|,
name|m_defaultPhysicalSizeHeight
argument_list|)
argument_list|)
expr_stmt|;
name|m_primaryScreen
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_defaultGeometryWidth
argument_list|,
name|m_defaultGeometryHeight
argument_list|)
argument_list|)
expr_stmt|;
name|m_mainThread
operator|=
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
name|QtAndroid
operator|::
name|setAndroidPlatformIntegration
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_androidFDB
operator|=
operator|new
name|QAndroidPlatformFontDatabase
argument_list|()
expr_stmt|;
name|m_androidPlatformServices
operator|=
operator|new
name|QAndroidPlatformServices
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|m_androidPlatformClipboard
operator|=
operator|new
name|QAndroidPlatformClipboard
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|m_androidSystemLocale
operator|=
operator|new
name|QAndroidSystemLocale
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|needsWorkaround
name|bool
name|QAndroidPlatformIntegration
operator|::
name|needsWorkaround
parameter_list|()
block|{
specifier|static
name|bool
name|needsWorkaround
init|=
name|QtAndroid
operator|::
name|deviceName
argument_list|()
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"samsung SM-T211"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
operator|||
name|QtAndroid
operator|::
name|deviceName
argument_list|()
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"samsung SM-T210"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
operator|||
name|QtAndroid
operator|::
name|deviceName
argument_list|()
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"samsung SM-T215"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
decl_stmt|;
return|return
name|needsWorkaround
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QAndroidPlatformIntegration
operator|::
name|hasCapability
parameter_list|(
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
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
case|case
name|ApplicationState
case|:
return|return
literal|true
return|;
case|case
name|NativeWidgets
case|:
return|return
literal|true
return|;
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
case|case
name|ForeignWindows
case|:
return|return
literal|true
return|;
case|case
name|ThreadedOpenGL
case|:
if|if
condition|(
name|needsWorkaround
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// fall through
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QAndroidPlatformBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QSurfaceFormat
name|format
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
decl_stmt|;
name|format
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
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
operator|new
name|QAndroidPlatformOpenGLContext
argument_list|(
name|format
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|m_eglDisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|window
operator|->
name|type
argument_list|()
operator|==
name|Qt
operator|::
name|ForeignWindow
condition|)
return|return
operator|new
name|QAndroidPlatformForeignWindow
argument_list|(
name|window
argument_list|)
return|;
elseif|else
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
condition|)
return|return
operator|new
name|QAndroidPlatformRasterWindow
argument_list|(
name|window
argument_list|)
return|;
else|else
return|return
operator|new
name|QAndroidPlatformOpenGLWindow
argument_list|(
name|window
argument_list|,
name|m_eglDisplay
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_destructor
DECL|function|~QAndroidPlatformIntegration
name|QAndroidPlatformIntegration
operator|::
name|~
name|QAndroidPlatformIntegration
parameter_list|()
block|{
if|if
condition|(
name|m_eglDisplay
operator|!=
name|EGL_NO_DISPLAY
condition|)
name|eglTerminate
argument_list|(
name|m_eglDisplay
argument_list|)
expr_stmt|;
operator|delete
name|m_androidPlatformNativeInterface
expr_stmt|;
operator|delete
name|m_androidFDB
expr_stmt|;
operator|delete
name|m_androidSystemLocale
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
operator|delete
name|m_androidPlatformClipboard
expr_stmt|;
endif|#
directive|endif
name|QtAndroid
operator|::
name|setAndroidPlatformIntegration
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_androidFDB
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_androidPlatformClipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|m_platformInputContext
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
name|m_androidPlatformNativeInterface
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_androidPlatformServices
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QAndroidPlatformIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|ShowIsMaximized
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|defaultWindowState
name|Qt
operator|::
name|WindowState
name|QAndroidPlatformIntegration
operator|::
name|defaultWindowState
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
specifier|const
block|{
comment|// Don't maximize dialogs on Android
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|Dialog
operator|&
operator|~
name|Qt
operator|::
name|Window
condition|)
return|return
name|Qt
operator|::
name|WindowNoState
return|;
return|return
name|QPlatformIntegration
operator|::
name|defaultWindowState
argument_list|(
name|flags
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|androidThemeName
argument_list|(
literal|"android"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|themeNames
name|QStringList
name|QAndroidPlatformIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QString
argument_list|(
name|androidThemeName
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|androidThemeName
operator|==
name|name
condition|)
return|return
operator|new
name|QAndroidPlatformTheme
argument_list|(
name|m_androidPlatformNativeInterface
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|setDefaultDisplayMetrics
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDefaultDisplayMetrics
parameter_list|(
name|int
name|gw
parameter_list|,
name|int
name|gh
parameter_list|,
name|int
name|sw
parameter_list|,
name|int
name|sh
parameter_list|)
block|{
name|m_defaultGeometryWidth
operator|=
name|gw
expr_stmt|;
name|m_defaultGeometryHeight
operator|=
name|gh
expr_stmt|;
name|m_defaultPhysicalSizeWidth
operator|=
name|sw
expr_stmt|;
name|m_defaultPhysicalSizeHeight
operator|=
name|sh
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDefaultDesktopSize
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDefaultDesktopSize
parameter_list|(
name|int
name|gw
parameter_list|,
name|int
name|gh
parameter_list|)
block|{
name|m_defaultGeometryWidth
operator|=
name|gw
expr_stmt|;
name|m_defaultGeometryHeight
operator|=
name|gh
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setScreenOrientation
name|void
name|QAndroidPlatformIntegration
operator|::
name|setScreenOrientation
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|currentOrientation
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
parameter_list|)
block|{
name|m_orientation
operator|=
name|currentOrientation
expr_stmt|;
name|m_nativeOrientation
operator|=
name|nativeOrientation
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function
DECL|function|accessibility
name|QPlatformAccessibility
modifier|*
name|QAndroidPlatformIntegration
operator|::
name|accessibility
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_accessibility
condition|)
name|m_accessibility
operator|=
operator|new
name|QAndroidPlatformAccessibility
argument_list|()
expr_stmt|;
return|return
name|m_accessibility
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setDesktopSize
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDesktopSize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|m_primaryScreen
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_primaryScreen
argument_list|,
literal|"setGeometry"
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QRect
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDisplayMetrics
name|void
name|QAndroidPlatformIntegration
operator|::
name|setDisplayMetrics
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
if|if
condition|(
name|m_primaryScreen
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|m_primaryScreen
argument_list|,
literal|"setPhysicalSize"
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QSize
argument_list|,
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
