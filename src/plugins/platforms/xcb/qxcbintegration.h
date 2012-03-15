begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QXCBINTEGRATION_H
define|#
directive|define
name|QXCBINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformIntegration>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbNativeInterface
name|class
name|QXcbNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QXcbIntegration
argument_list|(
specifier|const
name|QStringList
operator|&
name|parameters
argument_list|)
block|;
operator|~
name|QXcbIntegration
argument_list|()
block|;
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
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
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
block|;
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
block|;
name|void
name|moveToScreen
argument_list|(
argument|QWindow *window
argument_list|,
argument|int screen
argument_list|)
block|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
block|;
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|;
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
block|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_USE_XCB_SHARED_GRAPHICS_CACHE
argument_list|)
name|QPlatformSharedGraphicsCache
operator|*
name|createPlatformSharedGraphicsCache
argument_list|(
argument|const char *cacheId
argument_list|)
specifier|const
block|;
endif|#
directive|endif
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
name|private
operator|:
name|QList
operator|<
name|QXcbConnection
operator|*
operator|>
name|m_connections
block|;
name|QScopedPointer
operator|<
name|QPlatformFontDatabase
operator|>
name|m_fontDatabase
block|;
name|QScopedPointer
operator|<
name|QXcbNativeInterface
operator|>
name|m_nativeInterface
block|;
name|QScopedPointer
operator|<
name|QPlatformInputContext
operator|>
name|m_inputContext
block|;
name|QAbstractEventDispatcher
operator|*
name|m_eventDispatcher
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|QScopedPointer
operator|<
name|QPlatformAccessibility
operator|>
name|m_accessibility
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QT_USE_XCB_SHARED_GRAPHICS_CACHE
argument_list|)
name|QScopedPointer
operator|<
name|QPlatformSharedGraphicsCache
operator|>
name|m_sharedGraphicsCache
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QPlatformServices
operator|>
name|m_services
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
