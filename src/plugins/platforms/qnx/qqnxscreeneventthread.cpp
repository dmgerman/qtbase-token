begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxglobal.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreeneventthread.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreeneventhandler.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<cctype>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXSCREENEVENTTHREAD_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qScreenEventThreadDebug
define|#
directive|define
name|qScreenEventThreadDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qScreenEventThreadDebug
define|#
directive|define
name|qScreenEventThreadDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QQnxScreenEventThread
name|QQnxScreenEventThread
operator|::
name|QQnxScreenEventThread
parameter_list|(
name|screen_context_t
name|context
parameter_list|,
name|QQnxScreenEventHandler
modifier|*
name|screenEventHandler
parameter_list|)
member_init_list|:
name|QThread
argument_list|()
member_init_list|,
name|m_screenContext
argument_list|(
name|context
argument_list|)
member_init_list|,
name|m_screenEventHandler
argument_list|(
name|screenEventHandler
argument_list|)
member_init_list|,
name|m_quit
argument_list|(
literal|false
argument_list|)
block|{
name|screenEventHandler
operator|->
name|setScreenEventThread
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|eventPending
argument_list|()
argument_list|)
argument_list|,
name|screenEventHandler
argument_list|,
name|SLOT
argument_list|(
name|processEventsFromScreenThread
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|screenEventHandler
argument_list|,
name|SLOT
argument_list|(
name|processEventsFromScreenThread
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxScreenEventThread
name|QQnxScreenEventThread
operator|::
name|~
name|QQnxScreenEventThread
parameter_list|()
block|{
comment|// block until thread terminates
name|shutdown
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|injectKeyboardEvent
name|void
name|QQnxScreenEventThread
operator|::
name|injectKeyboardEvent
parameter_list|(
name|int
name|flags
parameter_list|,
name|int
name|sym
parameter_list|,
name|int
name|mod
parameter_list|,
name|int
name|scan
parameter_list|,
name|int
name|cap
parameter_list|)
block|{
name|QQnxScreenEventHandler
operator|::
name|injectKeyboardEvent
argument_list|(
name|flags
argument_list|,
name|sym
argument_list|,
name|mod
argument_list|,
name|scan
argument_list|,
name|cap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lock
name|QQnxScreenEventArray
modifier|*
name|QQnxScreenEventThread
operator|::
name|lock
parameter_list|()
block|{
name|m_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
return|return
operator|&
name|m_events
return|;
block|}
end_function
begin_function
DECL|function|unlock
name|void
name|QQnxScreenEventThread
operator|::
name|unlock
parameter_list|()
block|{
name|m_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|run
name|void
name|QQnxScreenEventThread
operator|::
name|run
parameter_list|()
block|{
name|qScreenEventThreadDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"screen event thread started"
expr_stmt|;
name|int
name|errorCounter
init|=
literal|0
decl_stmt|;
comment|// loop indefinitely
while|while
condition|(
operator|!
name|m_quit
condition|)
block|{
name|screen_event_t
name|event
decl_stmt|;
comment|// create screen event
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_create_event
argument_list|(
operator|&
name|event
argument_list|)
argument_list|,
literal|"Failed to create screen event"
argument_list|)
expr_stmt|;
comment|// block until screen event is available
specifier|const
name|int
name|error
init|=
name|screen_get_event
argument_list|(
name|m_screenContext
argument_list|,
name|event
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|error
argument_list|,
literal|"Failed to get screen event"
argument_list|)
expr_stmt|;
comment|// Only allow 50 consecutive errors before we exit the thread
if|if
condition|(
name|error
condition|)
block|{
name|errorCounter
operator|++
expr_stmt|;
if|if
condition|(
name|errorCounter
operator|>
literal|50
condition|)
name|m_quit
operator|=
literal|true
expr_stmt|;
name|screen_destroy_event
argument_list|(
name|event
argument_list|)
expr_stmt|;
continue|continue;
block|}
else|else
block|{
name|errorCounter
operator|=
literal|0
expr_stmt|;
block|}
comment|// process received event
comment|// get the event type
name|int
name|qnxType
decl_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_get_event_property_iv
argument_list|(
name|event
argument_list|,
name|SCREEN_PROPERTY_TYPE
argument_list|,
operator|&
name|qnxType
argument_list|)
argument_list|,
literal|"Failed to query screen event type"
argument_list|)
expr_stmt|;
if|if
condition|(
name|qnxType
operator|==
name|SCREEN_EVENT_USER
condition|)
block|{
comment|// treat all user events as shutdown requests
name|qScreenEventThreadDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"QNX user screen event"
expr_stmt|;
name|m_quit
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|m_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|m_events
operator|<<
name|event
expr_stmt|;
name|m_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
emit|emit
name|eventPending
argument_list|()
emit|;
block|}
block|}
name|qScreenEventThreadDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"screen event thread stopped"
expr_stmt|;
comment|// cleanup
name|m_mutex
operator|.
name|lock
argument_list|()
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|screen_event_t event
argument_list|,
argument|m_events
argument_list|)
block|{
name|screen_destroy_event
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
name|m_events
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_mutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|shutdown
name|void
name|QQnxScreenEventThread
operator|::
name|shutdown
parameter_list|()
block|{
name|screen_event_t
name|event
decl_stmt|;
comment|// create screen event
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_create_event
argument_list|(
operator|&
name|event
argument_list|)
argument_list|,
literal|"Failed to create screen event"
argument_list|)
expr_stmt|;
comment|// set the event type as user
name|int
name|type
init|=
name|SCREEN_EVENT_USER
decl_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_set_event_property_iv
argument_list|(
name|event
argument_list|,
name|SCREEN_PROPERTY_TYPE
argument_list|,
operator|&
name|type
argument_list|)
argument_list|,
literal|"Failed to set screen type"
argument_list|)
expr_stmt|;
comment|// NOTE: ignore SCREEN_PROPERTY_USER_DATA; treat all user events as shutdown events
comment|// post event to event loop so it will wake up and die
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_send_event
argument_list|(
name|m_screenContext
argument_list|,
name|event
argument_list|,
name|getpid
argument_list|()
argument_list|)
argument_list|,
literal|"Failed to set screen event type"
argument_list|)
expr_stmt|;
comment|// cleanup
name|screen_destroy_event
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|qScreenEventThreadDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"screen event thread shutdown begin"
expr_stmt|;
comment|// block until thread terminates
name|wait
argument_list|()
expr_stmt|;
name|qScreenEventThreadDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"screen event thread shutdown end"
expr_stmt|;
block|}
end_function
end_unit
