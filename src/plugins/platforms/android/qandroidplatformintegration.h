begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDPLATFORMINTERATION_H
end_ifndef
begin_define
DECL|macro|QANDROIDPLATFORMINTERATION_H
define|#
directive|define
name|QANDROIDPLATFORMINTERATION_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|"qandroidinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|<memory>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDesktopWidget
name|class
name|QDesktopWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAndroidPlatformServices
name|class
name|QAndroidPlatformServices
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAndroidSystemLocale
name|class
name|QAndroidSystemLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformAccessibility
name|class
name|QPlatformAccessibility
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|AndroidStyle
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QAndroidPlatformNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|public
operator|:
name|void
operator|*
name|nativeResourceForIntegration
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|)
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|AndroidStyle
operator|>
name|m_androidStyle
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAndroidPlatformIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|friend
name|class
name|QAndroidPlatformScreen
block|;
name|public
operator|:
name|QAndroidPlatformIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|)
block|;
operator|~
name|QAndroidPlatformIntegration
argument_list|()
block|;
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
block|;
name|QAndroidPlatformScreen
operator|*
name|screen
argument_list|()
block|{
return|return
name|m_primaryScreen
return|;
block|}
name|QPlatformOffscreenSurface
operator|*
name|createPlatformOffscreenSurface
argument_list|(
argument|QOffscreenSurface *surface
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setDesktopSize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|virtual
name|void
name|setDisplayMetrics
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|void
name|setScreenSize
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
name|bool
name|isVirtualDesktop
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|virtual
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QVariant
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|WindowState
name|defaultWindowState
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
specifier|const
block|;
name|QStringList
name|themeNames
argument_list|()
specifier|const
block|;
name|QPlatformTheme
operator|*
name|createPlatformTheme
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
specifier|static
name|void
name|setDefaultDisplayMetrics
argument_list|(
argument|int gw
argument_list|,
argument|int gh
argument_list|,
argument|int sw
argument_list|,
argument|int sh
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
block|;
specifier|static
name|void
name|setDefaultDesktopSize
argument_list|(
argument|int gw
argument_list|,
argument|int gh
argument_list|)
block|;
specifier|static
name|void
name|setScreenOrientation
argument_list|(
argument|Qt::ScreenOrientation currentOrientation
argument_list|,
argument|Qt::ScreenOrientation nativeOrientation
argument_list|)
block|;
specifier|static
name|QSize
name|defaultDesktopSize
argument_list|()
block|{
return|return
name|QSize
argument_list|(
name|m_defaultGeometryWidth
argument_list|,
name|m_defaultGeometryHeight
argument_list|)
return|;
block|}
name|QTouchDevice
operator|*
name|touchDevice
argument_list|()
specifier|const
block|{
return|return
name|m_touchDevice
return|;
block|}
name|void
name|setTouchDevice
argument_list|(
argument|QTouchDevice *touchDevice
argument_list|)
block|{
name|m_touchDevice
operator|=
name|touchDevice
block|; }
specifier|static
name|void
name|setDefaultApplicationState
argument_list|(
argument|Qt::ApplicationState applicationState
argument_list|)
block|{
name|m_defaultApplicationState
operator|=
name|applicationState
block|; }
name|private
operator|:
name|EGLDisplay
name|m_eglDisplay
block|;
name|QTouchDevice
operator|*
name|m_touchDevice
block|;
name|QAndroidPlatformScreen
operator|*
name|m_primaryScreen
block|;
name|QThread
operator|*
name|m_mainThread
block|;
specifier|static
name|int
name|m_defaultGeometryWidth
block|;
specifier|static
name|int
name|m_defaultGeometryHeight
block|;
specifier|static
name|int
name|m_defaultPhysicalSizeWidth
block|;
specifier|static
name|int
name|m_defaultPhysicalSizeHeight
block|;
specifier|static
name|int
name|m_defaultScreenWidth
block|;
specifier|static
name|int
name|m_defaultScreenHeight
block|;
specifier|static
name|Qt
operator|::
name|ScreenOrientation
name|m_orientation
block|;
specifier|static
name|Qt
operator|::
name|ScreenOrientation
name|m_nativeOrientation
block|;
specifier|static
name|Qt
operator|::
name|ApplicationState
name|m_defaultApplicationState
block|;
name|QPlatformFontDatabase
operator|*
name|m_androidFDB
block|;
name|QAndroidPlatformNativeInterface
operator|*
name|m_androidPlatformNativeInterface
block|;
name|QAndroidPlatformServices
operator|*
name|m_androidPlatformServices
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|QPlatformClipboard
operator|*
name|m_androidPlatformClipboard
block|;
endif|#
directive|endif
name|QAndroidSystemLocale
operator|*
name|m_androidSystemLocale
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|mutable
name|QPlatformAccessibility
operator|*
name|m_accessibility
block|;
endif|#
directive|endif
name|mutable
name|QAndroidInputContext
name|m_platformInputContext
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
