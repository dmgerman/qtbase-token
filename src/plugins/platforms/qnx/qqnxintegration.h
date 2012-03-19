begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QQNXINTEGRATION_H
define|#
directive|define
name|QQNXINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qplatformintegration_qpa.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxEventThread
name|class
name|QQnxEventThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxInputContext
name|class
name|QQnxInputContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxNavigatorEventHandler
name|class
name|QQnxNavigatorEventHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxWindow
name|class
name|QQnxWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxServices
name|class
name|QQnxServices
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_decl_stmt
DECL|variable|QQnxClipboard
name|class
name|QQnxClipboard
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|variable|K
DECL|variable|QHash
name|template
operator|<
name|class
name|K
operator|,
name|class
name|V
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|screen_window_t
DECL|typedef|QQnxWindowMapper
typedef|typedef
name|QHash
operator|<
name|screen_window_t
operator|,
name|QWindow
operator|*
operator|>
name|QQnxWindowMapper
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QQnxIntegration
range|:
name|public
name|QPlatformIntegration
block|{
name|public
operator|:
name|QQnxIntegration
argument_list|()
block|;
name|virtual
operator|~
name|QQnxIntegration
argument_list|()
block|;
name|virtual
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformWindow
operator|*
name|createPlatformWindow
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformBackingStore
operator|*
name|createPlatformBackingStore
argument_list|(
argument|QWindow *window
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
block|;
name|virtual
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
name|virtual
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|screens
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|moveToScreen
argument_list|(
argument|QWindow *window
argument_list|,
argument|int screen
argument_list|)
block|;
name|virtual
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
block|;
name|virtual
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
block|{
return|return
name|m_fontDatabase
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|virtual
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|virtual
name|QVariant
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|)
specifier|const
block|;
name|bool
name|paintUsingOpenGL
argument_list|()
specifier|const
block|{
return|return
name|m_paintUsingOpenGL
return|;
block|}
name|virtual
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
block|;
specifier|static
name|QWindow
operator|*
name|window
argument_list|(
argument|screen_window_t qnxWindow
argument_list|)
block|;
name|private
operator|:
specifier|static
name|void
name|addWindow
argument_list|(
argument|screen_window_t qnxWindow
argument_list|,
argument|QWindow *window
argument_list|)
block|;
specifier|static
name|void
name|removeWindow
argument_list|(
argument|screen_window_t qnxWindow
argument_list|)
block|;
name|screen_context_t
name|m_screenContext
block|;
name|QQnxEventThread
operator|*
name|m_eventThread
block|;
name|QQnxNavigatorEventHandler
operator|*
name|m_navigatorEventHandler
block|;
name|QQnxInputContext
operator|*
name|m_inputContext
block|;
name|QPlatformFontDatabase
operator|*
name|m_fontDatabase
block|;
name|bool
name|m_paintUsingOpenGL
block|;
name|QAbstractEventDispatcher
operator|*
name|m_eventDispatcher
block|;
name|QQnxServices
operator|*
name|m_services
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|mutable
name|QQnxClipboard
operator|*
name|m_clipboard
block|;
endif|#
directive|endif
specifier|static
name|QQnxWindowMapper
name|ms_windowMapper
block|;
specifier|static
name|QMutex
name|ms_windowMapperMutex
block|;
name|friend
name|class
name|QQnxWindow
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
begin_comment
comment|// QQNXINTEGRATION_H
end_comment
end_unit
