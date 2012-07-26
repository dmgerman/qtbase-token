begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXSCREENEVENTHANDLER_H
end_ifndef
begin_define
DECL|macro|QQNXSCREENEVENTHANDLER_H
define|#
directive|define
name|QQNXSCREENEVENTHANDLER_H
end_define
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxScreenEventHandler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QQnxScreenEventHandler
argument_list|()
block|;
name|bool
name|handleEvent
argument_list|(
argument|screen_event_t event
argument_list|)
block|;
name|bool
name|handleEvent
argument_list|(
argument|screen_event_t event
argument_list|,
argument|int qnxType
argument_list|)
block|;
specifier|static
name|void
name|injectKeyboardEvent
argument_list|(
argument|int flags
argument_list|,
argument|int sym
argument_list|,
argument|int mod
argument_list|,
argument|int scan
argument_list|,
argument|int cap
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|newWindowCreated
argument_list|(
name|void
operator|*
name|window
argument_list|)
block|;
name|void
name|windowClosed
argument_list|(
name|void
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
name|void
name|handleKeyboardEvent
argument_list|(
argument|screen_event_t event
argument_list|)
block|;
name|void
name|handlePointerEvent
argument_list|(
argument|screen_event_t event
argument_list|)
block|;
name|void
name|handleTouchEvent
argument_list|(
argument|screen_event_t event
argument_list|,
argument|int qnxType
argument_list|)
block|;
name|void
name|handleCloseEvent
argument_list|(
argument|screen_event_t event
argument_list|)
block|;
name|void
name|handleCreateEvent
argument_list|(
argument|screen_event_t event
argument_list|)
block|;
name|private
operator|:
expr|enum
block|{
name|MaximumTouchPoints
operator|=
literal|10
block|}
block|;
name|QPoint
name|m_lastGlobalMousePoint
block|;
name|QPoint
name|m_lastLocalMousePoint
block|;
name|Qt
operator|::
name|MouseButtons
name|m_lastButtonState
block|;
name|screen_window_t
name|m_lastMouseWindow
block|;
name|QTouchDevice
operator|*
name|m_touchDevice
block|;
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|m_touchPoints
index|[
name|MaximumTouchPoints
index|]
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
comment|// QQNXSCREENEVENTHANDLER_H
end_comment
end_unit
