begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtWidgets/QAction>
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
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qeglfsintegration.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
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
begin_ifdef
ifdef|#
directive|ifdef
name|ANDROID_PLUGIN_OPENGL
end_ifdef
begin_decl_stmt
DECL|variable|QAndroidOpenGLPlatformWindow
name|class
name|QAndroidOpenGLPlatformWindow
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
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
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAndroidPlatformIntegration
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
range|:
name|public
name|QPlatformIntegration
else|#
directive|else
operator|:
name|public
name|QEglFSIntegration
endif|#
directive|endif
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
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
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
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
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
else|#
directive|else
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|void
name|invalidateNativeSurface
argument_list|()
block|;
name|void
name|surfaceChanged
argument_list|()
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
endif|#
directive|endif
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
name|void
name|pauseApp
argument_list|()
block|;
name|void
name|resumeApp
argument_list|()
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
name|private
operator|:
name|friend
name|class
name|QEglFSAndroidHooks
block|;
name|QTouchDevice
operator|*
name|m_touchDevice
block|;
ifndef|#
directive|ifndef
name|ANDROID_PLUGIN_OPENGL
name|QAbstractEventDispatcher
operator|*
name|m_eventDispatcher
block|;
name|QAndroidPlatformScreen
operator|*
name|m_primaryScreen
block|;
endif|#
directive|endif
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
name|QPlatformFontDatabase
operator|*
name|m_androidFDB
block|;
name|QImage
operator|*
name|m_FbScreenImage
block|;
name|QPainter
operator|*
name|m_compositePainter
block|;
name|QAndroidPlatformNativeInterface
operator|*
name|m_androidPlatformNativeInterface
block|;
name|QAndroidPlatformServices
operator|*
name|m_androidPlatformServices
block|;
name|QPlatformClipboard
operator|*
name|m_androidPlatformClipboard
block|;
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
