begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 - 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventdispatcher_blackberry_p.h"
end_include
begin_include
include|#
directive|include
file|"qsocketnotifier.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qthread_p.h"
end_include
begin_include
include|#
directive|include
file|<bps/bps.h>
end_include
begin_include
include|#
directive|include
file|<bps/event.h>
end_include
begin_comment
comment|//#define QEVENTDISPATCHERBLACKBERRY_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QEVENTDISPATCHERBLACKBERRY_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_define
DECL|macro|qEventDispatcherDebug
define|#
directive|define
name|qEventDispatcherDebug
value|qDebug()<< QThread::currentThread()
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qEventDispatcherDebug
define|#
directive|define
name|qEventDispatcherDebug
value|QT_NO_QDEBUG_MACRO()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|BpsChannelScopeSwitcher
class|class
name|BpsChannelScopeSwitcher
block|{
public|public:
DECL|function|BpsChannelScopeSwitcher
name|BpsChannelScopeSwitcher
parameter_list|(
name|int
name|scopeChannel
parameter_list|)
member_init_list|:
name|innerChannel
argument_list|(
name|scopeChannel
argument_list|)
block|{
name|outerChannel
operator|=
name|bps_channel_get_active
argument_list|()
expr_stmt|;
if|if
condition|(
name|outerChannel
operator|!=
name|innerChannel
condition|)
name|bps_channel_set_active
argument_list|(
name|innerChannel
argument_list|)
expr_stmt|;
block|}
DECL|function|~BpsChannelScopeSwitcher
name|~
name|BpsChannelScopeSwitcher
parameter_list|()
block|{
if|if
condition|(
name|outerChannel
operator|!=
name|innerChannel
condition|)
name|bps_channel_set_active
argument_list|(
name|outerChannel
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|innerChannel
name|int
name|innerChannel
decl_stmt|;
DECL|member|outerChannel
name|int
name|outerChannel
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|BBScopedLoopLevelCounter
class|class
name|BBScopedLoopLevelCounter
block|{
DECL|member|d
name|QEventDispatcherBlackberryPrivate
modifier|*
name|d
decl_stmt|;
public|public:
DECL|function|BBScopedLoopLevelCounter
specifier|inline
name|BBScopedLoopLevelCounter
parameter_list|(
name|QEventDispatcherBlackberryPrivate
modifier|*
name|p
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|p
argument_list|)
block|{
operator|++
name|d
operator|->
name|loop_level
expr_stmt|;
block|}
DECL|function|~BBScopedLoopLevelCounter
specifier|inline
name|~
name|BBScopedLoopLevelCounter
parameter_list|()
block|{
operator|--
name|d
operator|->
name|loop_level
expr_stmt|;
block|}
block|}
class|;
end_class
begin_struct
DECL|struct|bpsIOHandlerData
struct|struct
name|bpsIOHandlerData
block|{
DECL|function|bpsIOHandlerData
name|bpsIOHandlerData
parameter_list|()
member_init_list|:
name|count
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|readfds
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|writefds
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|exceptfds
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|member|count
name|int
name|count
decl_stmt|;
DECL|member|readfds
name|fd_set
modifier|*
name|readfds
decl_stmt|;
DECL|member|writefds
name|fd_set
modifier|*
name|writefds
decl_stmt|;
DECL|member|exceptfds
name|fd_set
modifier|*
name|exceptfds
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|bpsUnblockDomain
specifier|static
name|int
name|bpsUnblockDomain
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|bpsIOHandler
specifier|static
name|int
name|bpsIOHandler
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|io_events
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|qEventDispatcherDebug
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// decode callback payload
name|bpsIOHandlerData
modifier|*
name|ioData
init|=
cast|static_cast
argument_list|<
name|bpsIOHandlerData
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
comment|// check if first file is ready
name|bool
name|firstReady
init|=
operator|(
name|ioData
operator|->
name|count
operator|==
literal|0
operator|)
decl_stmt|;
comment|// update ready state of file
if|if
condition|(
name|io_events
operator|&
name|BPS_IO_INPUT
condition|)
block|{
name|qEventDispatcherDebug
operator|<<
name|fd
operator|<<
literal|"ready for Read"
expr_stmt|;
name|FD_SET
argument_list|(
name|fd
argument_list|,
name|ioData
operator|->
name|readfds
argument_list|)
expr_stmt|;
name|ioData
operator|->
name|count
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|io_events
operator|&
name|BPS_IO_OUTPUT
condition|)
block|{
name|qEventDispatcherDebug
operator|<<
name|fd
operator|<<
literal|"ready for Write"
expr_stmt|;
name|FD_SET
argument_list|(
name|fd
argument_list|,
name|ioData
operator|->
name|writefds
argument_list|)
expr_stmt|;
name|ioData
operator|->
name|count
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|io_events
operator|&
name|BPS_IO_EXCEPT
condition|)
block|{
name|qEventDispatcherDebug
operator|<<
name|fd
operator|<<
literal|"ready for Exception"
expr_stmt|;
name|FD_SET
argument_list|(
name|fd
argument_list|,
name|ioData
operator|->
name|exceptfds
argument_list|)
expr_stmt|;
name|ioData
operator|->
name|count
operator|++
expr_stmt|;
block|}
comment|// force bps_get_event() to return immediately by posting an event to ourselves;
comment|// but this only needs to happen once if multiple files become ready at the same time
if|if
condition|(
name|firstReady
condition|)
block|{
name|qEventDispatcherDebug
operator|<<
literal|"Sending bpsIOReadyDomain event"
expr_stmt|;
comment|// create unblock event
name|bps_event_t
modifier|*
name|event
decl_stmt|;
name|int
name|result
init|=
name|bps_event_create
argument_list|(
operator|&
name|event
argument_list|,
name|bpsUnblockDomain
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_event_create failed"
argument_list|)
expr_stmt|;
return|return
name|BPS_FAILURE
return|;
block|}
comment|// post unblock event to our thread; in this callback the bps channel is
comment|// guaranteed to be the same that was active when bps_add_fd was called
name|result
operator|=
name|bps_push_event
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_push_event failed"
argument_list|)
expr_stmt|;
name|bps_event_destroy
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
name|BPS_FAILURE
return|;
block|}
block|}
return|return
name|BPS_SUCCESS
return|;
block|}
end_function
begin_constructor
DECL|function|QEventDispatcherBlackberryPrivate
name|QEventDispatcherBlackberryPrivate
operator|::
name|QEventDispatcherBlackberryPrivate
parameter_list|()
member_init_list|:
name|loop_level
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|ioData
argument_list|(
operator|new
name|bpsIOHandlerData
argument_list|)
block|{
comment|// prepare to use BPS
name|int
name|result
init|=
name|bps_initialize
argument_list|()
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QEventDispatcherBlackberry: bps_initialize failed"
argument_list|)
expr_stmt|;
name|bps_channel
operator|=
name|bps_channel_get_active
argument_list|()
expr_stmt|;
if|if
condition|(
name|bps_channel_create
argument_list|(
operator|&
name|holding_channel
argument_list|,
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_channel_create failed"
argument_list|)
expr_stmt|;
name|holding_channel
operator|=
operator|-
literal|1
expr_stmt|;
block|}
comment|// get domain for IO ready and wake up events - ignoring race condition here for now
if|if
condition|(
name|bpsUnblockDomain
operator|==
operator|-
literal|1
condition|)
block|{
name|bpsUnblockDomain
operator|=
name|bps_register_domain
argument_list|()
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bpsUnblockDomain
operator|==
operator|-
literal|1
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_register_domain failed"
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QEventDispatcherBlackberryPrivate
name|QEventDispatcherBlackberryPrivate
operator|::
name|~
name|QEventDispatcherBlackberryPrivate
parameter_list|()
block|{
if|if
condition|(
operator|(
name|holding_channel
operator|!=
operator|-
literal|1
operator|)
operator|&&
operator|(
name|bps_channel_destroy
argument_list|(
name|holding_channel
argument_list|)
operator|!=
name|BPS_SUCCESS
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_channel_destroy failed"
argument_list|)
expr_stmt|;
block|}
comment|// we're done using BPS
name|bps_shutdown
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initThreadWakeUp
name|int
name|QEventDispatcherBlackberryPrivate
operator|::
name|initThreadWakeUp
parameter_list|()
block|{
return|return
operator|-
literal|1
return|;
comment|// no fd's used
block|}
end_function
begin_function
DECL|function|processThreadWakeUp
name|int
name|QEventDispatcherBlackberryPrivate
operator|::
name|processThreadWakeUp
parameter_list|(
name|int
name|nsel
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|nsel
argument_list|)
expr_stmt|;
return|return
name|wakeUps
operator|.
name|fetchAndStoreRelaxed
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/////////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QEventDispatcherBlackberry
name|QEventDispatcherBlackberry
operator|::
name|QEventDispatcherBlackberry
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherUNIX
argument_list|(
operator|*
operator|new
name|QEventDispatcherBlackberryPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QEventDispatcherBlackberry
name|QEventDispatcherBlackberry
operator|::
name|QEventDispatcherBlackberry
parameter_list|(
name|QEventDispatcherBlackberryPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherUNIX
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QEventDispatcherBlackberry
name|QEventDispatcherBlackberry
operator|::
name|~
name|QEventDispatcherBlackberry
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|registerSocketNotifier
name|void
name|QEventDispatcherBlackberry
operator|::
name|registerSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QEventDispatcherBlackberry
argument_list|)
expr_stmt|;
name|int
name|sockfd
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|int
name|type
init|=
name|notifier
operator|->
name|type
argument_list|()
decl_stmt|;
name|qEventDispatcherDebug
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"fd ="
operator|<<
name|sockfd
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|sockfd
operator|>=
name|FD_SETSIZE
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QEventDispatcherBlackberry: cannot register QSocketNotifier (fd too high)"
operator|<<
name|sockfd
expr_stmt|;
return|return;
block|}
comment|// Register the fd with bps
name|BpsChannelScopeSwitcher
name|channelSwitcher
argument_list|(
name|d
operator|->
name|bps_channel
argument_list|)
decl_stmt|;
name|int
name|io_events
init|=
name|ioEvents
argument_list|(
name|sockfd
argument_list|)
decl_stmt|;
if|if
condition|(
name|io_events
condition|)
name|bps_remove_fd
argument_list|(
name|sockfd
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QSocketNotifier
operator|::
name|Read
case|:
name|qEventDispatcherDebug
operator|<<
literal|"Registering"
operator|<<
name|sockfd
operator|<<
literal|"for Reads"
expr_stmt|;
name|io_events
operator||=
name|BPS_IO_INPUT
expr_stmt|;
break|break;
case|case
name|QSocketNotifier
operator|::
name|Write
case|:
name|qEventDispatcherDebug
operator|<<
literal|"Registering"
operator|<<
name|sockfd
operator|<<
literal|"for Writes"
expr_stmt|;
name|io_events
operator||=
name|BPS_IO_OUTPUT
expr_stmt|;
break|break;
case|case
name|QSocketNotifier
operator|::
name|Exception
case|:
default|default:
name|qEventDispatcherDebug
operator|<<
literal|"Registering"
operator|<<
name|sockfd
operator|<<
literal|"for Exceptions"
expr_stmt|;
name|io_events
operator||=
name|BPS_IO_EXCEPT
expr_stmt|;
break|break;
block|}
specifier|const
name|int
name|result
init|=
name|bps_add_fd
argument_list|(
name|sockfd
argument_list|,
name|io_events
argument_list|,
operator|&
name|bpsIOHandler
argument_list|,
name|d
operator|->
name|ioData
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"QEventDispatcherBlackberry: bps_add_fd failed"
expr_stmt|;
comment|// Call the base Unix implementation. Needed to allow select() to be called correctly
name|QEventDispatcherUNIX
operator|::
name|registerSocketNotifier
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterSocketNotifier
name|void
name|QEventDispatcherBlackberry
operator|::
name|unregisterSocketNotifier
parameter_list|(
name|QSocketNotifier
modifier|*
name|notifier
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventDispatcherBlackberry
argument_list|)
expr_stmt|;
name|int
name|sockfd
init|=
name|notifier
operator|->
name|socket
argument_list|()
decl_stmt|;
name|qEventDispatcherDebug
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"fd ="
operator|<<
name|sockfd
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|sockfd
operator|>=
name|FD_SETSIZE
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QEventDispatcherBlackberry: cannot unregister QSocketNotifier"
operator|<<
name|sockfd
expr_stmt|;
return|return;
block|}
comment|// Allow the base Unix implementation to unregister the fd too (before call to ioEvents()!)
name|QEventDispatcherUNIX
operator|::
name|unregisterSocketNotifier
argument_list|(
name|notifier
argument_list|)
expr_stmt|;
comment|// Unregister the fd with bps
name|BpsChannelScopeSwitcher
name|channelSwitcher
argument_list|(
name|d
operator|->
name|bps_channel
argument_list|)
decl_stmt|;
name|int
name|result
init|=
name|bps_remove_fd
argument_list|(
name|sockfd
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"QEventDispatcherBlackberry: bps_remove_fd failed"
operator|<<
name|sockfd
expr_stmt|;
specifier|const
name|int
name|io_events
init|=
name|ioEvents
argument_list|(
name|sockfd
argument_list|)
decl_stmt|;
comment|// if other socket notifier is watching sockfd, readd it
if|if
condition|(
name|io_events
condition|)
block|{
name|result
operator|=
name|bps_add_fd
argument_list|(
name|sockfd
argument_list|,
name|io_events
argument_list|,
operator|&
name|bpsIOHandler
argument_list|,
name|d
operator|->
name|ioData
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_add_fd error"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|timespecToMillisecs
specifier|static
specifier|inline
name|int
name|timespecToMillisecs
parameter_list|(
specifier|const
name|timespec
modifier|&
name|tv
parameter_list|)
block|{
return|return
operator|(
name|tv
operator|.
name|tv_sec
operator|*
literal|1000
operator|)
operator|+
operator|(
name|tv
operator|.
name|tv_nsec
operator|/
literal|1000000
operator|)
return|;
block|}
end_function
begin_function
DECL|function|destroyHeldBpsEvent
specifier|static
specifier|inline
name|void
name|destroyHeldBpsEvent
parameter_list|(
name|int
name|holding_channel
parameter_list|)
block|{
comment|// Switch to the holding channel and use bps_get_event() to trigger its destruction.  We
comment|// don't care about the return value from this call to bps_get_event().
name|BpsChannelScopeSwitcher
name|holdingChannelSwitcher
argument_list|(
name|holding_channel
argument_list|)
decl_stmt|;
name|bps_event_t
modifier|*
name|held_event
init|=
literal|0
decl_stmt|;
operator|(
name|void
operator|)
name|bps_get_event
argument_list|(
operator|&
name|held_event
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|select
name|int
name|QEventDispatcherBlackberry
operator|::
name|select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|readfds
parameter_list|,
name|fd_set
modifier|*
name|writefds
parameter_list|,
name|fd_set
modifier|*
name|exceptfds
parameter_list|,
name|timespec
modifier|*
name|timeout
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|nfds
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QEventDispatcherBlackberry
argument_list|)
expr_stmt|;
specifier|const
name|BBScopedLoopLevelCounter
name|bbLoopCounter
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|BpsChannelScopeSwitcher
name|channelSwitcher
argument_list|(
name|d
operator|->
name|bps_channel
argument_list|)
decl_stmt|;
comment|// prepare file sets for bps callback
name|d
operator|->
name|ioData
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|ioData
operator|->
name|readfds
operator|=
name|readfds
expr_stmt|;
name|d
operator|->
name|ioData
operator|->
name|writefds
operator|=
name|writefds
expr_stmt|;
name|d
operator|->
name|ioData
operator|->
name|exceptfds
operator|=
name|exceptfds
expr_stmt|;
comment|// reset all file sets
if|if
condition|(
name|readfds
condition|)
name|FD_ZERO
argument_list|(
name|readfds
argument_list|)
expr_stmt|;
if|if
condition|(
name|writefds
condition|)
name|FD_ZERO
argument_list|(
name|writefds
argument_list|)
expr_stmt|;
if|if
condition|(
name|exceptfds
condition|)
name|FD_ZERO
argument_list|(
name|exceptfds
argument_list|)
expr_stmt|;
name|bps_event_t
modifier|*
name|event
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|eventCount
init|=
literal|0
decl_stmt|;
comment|// If an event handler called through filterEvent() starts a nested event loop by creating a
comment|// new QEventLoop, we will recursively enter this function again.  However, each time
comment|// bps_get_event() is called, it destroys the last event it handed out before returning the
comment|// next event.  We don't want it to destroy the event that triggered the nested event loop,
comment|// since there may still be more handlers that need to get that event, once the nested event
comment|// loop is done and control returns to the outer event loop.
comment|//
comment|// So we move an event to a holding channel, which takes ownership of the event.  Putting
comment|// the event on our own channel allows us to manage when it is destroyed, keeping it alive
comment|// until we know we are done with it.  Each recursive call of this function needs to have
comment|// it's own holding channel, since a channel is a queue, not a stack.
comment|//
comment|// However, a recursive call into this function happens very rarely compared to the many
comment|// times this function is called.  We don't want to create a holding channel for each time
comment|// this function is called, only when it is called recursively.  Thus we have the instance
comment|// variable d->holding_channel to use in the common case.  We keep track of recursive calls
comment|// with d->loop_level.  If we are in a recursive call, then we create a new holding channel
comment|// for this run.
name|int
name|holding_channel
init|=
name|d
operator|->
name|holding_channel
decl_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|loop_level
operator|>
literal|1
operator|)
operator|&&
name|Q_UNLIKELY
argument_list|(
name|bps_channel_create
argument_list|(
operator|&
name|holding_channel
argument_list|,
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_channel_create failed"
argument_list|)
expr_stmt|;
name|holding_channel
operator|=
operator|-
literal|1
expr_stmt|;
block|}
comment|// Convert timeout to milliseconds
name|int
name|timeoutTotal
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|timeout
condition|)
name|timeoutTotal
operator|=
name|timespecToMillisecs
argument_list|(
operator|*
name|timeout
argument_list|)
expr_stmt|;
name|int
name|timeoutLeft
init|=
name|timeoutTotal
decl_stmt|;
name|timespec
name|startTime
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
comment|// This loop exists such that we can drain the bps event queue of all native events
comment|// more efficiently than if we were to return control to Qt after each event. This
comment|// is important for handling touch events which can come in rapidly.
forever|forever
block|{
comment|// Only emit the awake() and aboutToBlock() signals in the second iteration. For the
comment|// first iteration, the UNIX event dispatcher will have taken care of that already.
comment|// Also native events are actually processed one loop iteration after they were
comment|// retrieved with bps_get_event().
comment|// Filtering the native event should happen between the awake() and aboutToBlock()
comment|// signal emissions. The calls awake() - filterNativeEvent() - aboutToBlock() -
comment|// bps_get_event() need not to be interrupted by a break or return statement.
if|if
condition|(
name|eventCount
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|event
condition|)
block|{
emit|emit
name|awake
argument_list|()
emit|;
name|filterNativeEvent
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"bps_event_t"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
emit|emit
name|aboutToBlock
argument_list|()
emit|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|holding_channel
operator|!=
operator|-
literal|1
argument_list|)
condition|)
block|{
comment|// We are now done with this BPS event.  Destroy it.
name|destroyHeldBpsEvent
argument_list|(
name|holding_channel
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Update the timeout
comment|// Clock source is monotonic, so we can recalculate how much timeout is left
if|if
condition|(
name|timeoutTotal
operator|!=
operator|-
literal|1
condition|)
block|{
name|timespec
name|t2
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
name|timeoutLeft
operator|=
name|timeoutTotal
operator|-
operator|(
name|timespecToMillisecs
argument_list|(
name|t2
argument_list|)
operator|-
name|timespecToMillisecs
argument_list|(
name|startTime
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|timeoutLeft
operator|<
literal|0
condition|)
name|timeoutLeft
operator|=
literal|0
expr_stmt|;
block|}
name|timespec
name|tnext
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|timerList
operator|.
name|timerWait
argument_list|(
name|tnext
argument_list|)
condition|)
block|{
name|int
name|timeoutNext
init|=
name|timespecToMillisecs
argument_list|(
name|tnext
argument_list|)
decl_stmt|;
if|if
condition|(
name|timeoutNext
operator|<
name|timeoutLeft
operator|||
name|timeoutTotal
operator|==
operator|-
literal|1
condition|)
block|{
name|timeoutTotal
operator|=
name|timeoutLeft
operator|=
name|timeoutNext
expr_stmt|;
name|startTime
operator|=
name|qt_gettime
argument_list|()
expr_stmt|;
block|}
block|}
block|}
name|event
operator|=
literal|0
expr_stmt|;
block|{
comment|// We need to increase loop level in this scope,
comment|// because bps_get_event can also invoke callbacks
name|QScopedLoopLevelCounter
name|loopLevelCounter
argument_list|(
name|d
operator|->
name|threadData
argument_list|)
decl_stmt|;
comment|// Wait for event or file to be ready
specifier|const
name|int
name|result
init|=
name|bps_get_event
argument_list|(
operator|&
name|event
argument_list|,
name|timeoutLeft
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|result
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_get_event failed"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|event
condition|)
comment|// In case of !event, we break out of the loop to let Qt process the timers
break|break;
comment|// (since timeout has expired) and socket notifiers that are now ready.
if|if
condition|(
name|bps_event_get_domain
argument_list|(
name|event
argument_list|)
operator|==
name|bpsUnblockDomain
condition|)
block|{
name|timeoutTotal
operator|=
literal|0
expr_stmt|;
comment|// in order to immediately drain the event queue of native events
name|event
operator|=
literal|0
expr_stmt|;
comment|// (especially touch move events) we don't break out here
block|}
else|else
block|{
comment|// Move the event to our holding channel so we can manage when it is destroyed.
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|holding_channel
operator|!=
literal|1
argument_list|)
operator|&&
name|Q_UNLIKELY
argument_list|(
name|bps_channel_push_event
argument_list|(
name|holding_channel
argument_list|,
name|event
argument_list|)
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_channel_push_event failed"
argument_list|)
expr_stmt|;
block|}
block|}
operator|++
name|eventCount
expr_stmt|;
comment|// Make sure we are not trapped in this loop due to continuous native events
comment|// also we cannot recalculate the timeout without a monotonic clock as the time may have changed
specifier|const
name|unsigned
name|int
name|maximumEventCount
init|=
literal|12
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|(
name|eventCount
operator|>
name|maximumEventCount
operator|&&
name|timeoutLeft
operator|==
literal|0
operator|)
operator|||
operator|!
name|QElapsedTimer
operator|::
name|isMonotonic
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|event
condition|)
block|{
name|filterNativeEvent
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"bps_event_t"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|holding_channel
operator|!=
operator|-
literal|1
argument_list|)
condition|)
block|{
comment|// We are now done with this BPS event.  Destroy it.
name|destroyHeldBpsEvent
argument_list|(
name|holding_channel
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
block|}
block|}
comment|// If this was a recursive call into this function, a new holding channel was created for
comment|// this run, so destroy it now.
if|if
condition|(
operator|(
name|holding_channel
operator|!=
name|d
operator|->
name|holding_channel
operator|)
operator|&&
name|Q_LIKELY
argument_list|(
name|holding_channel
operator|!=
operator|-
literal|1
argument_list|)
operator|&&
name|Q_UNLIKELY
argument_list|(
name|bps_channel_destroy
argument_list|(
name|holding_channel
argument_list|)
operator|!=
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: bps_channel_destroy failed"
argument_list|)
expr_stmt|;
block|}
comment|// the number of bits set in the file sets
return|return
name|d
operator|->
name|ioData
operator|->
name|count
return|;
block|}
end_function
begin_function
DECL|function|wakeUp
name|void
name|QEventDispatcherBlackberry
operator|::
name|wakeUp
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QEventDispatcherBlackberry
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|wakeUps
operator|.
name|testAndSetAcquire
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
condition|)
block|{
name|bps_event_t
modifier|*
name|event
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|bps_event_create
argument_list|(
operator|&
name|event
argument_list|,
name|bpsUnblockDomain
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
name|BPS_SUCCESS
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|bps_channel_push_event
argument_list|(
name|d
operator|->
name|bps_channel
argument_list|,
name|event
argument_list|)
operator|==
name|BPS_SUCCESS
argument_list|)
condition|)
return|return;
else|else
name|bps_event_destroy
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
name|qWarning
argument_list|(
literal|"QEventDispatcherBlackberry: wakeUp failed"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|ioEvents
name|int
name|QEventDispatcherBlackberry
operator|::
name|ioEvents
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|io_events
init|=
literal|0
decl_stmt|;
name|Q_D
argument_list|(
name|QEventDispatcherBlackberry
argument_list|)
expr_stmt|;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fd
argument_list|,
operator|&
name|d
operator|->
name|sn_vec
index|[
literal|0
index|]
operator|.
name|enabled_fds
argument_list|)
condition|)
name|io_events
operator||=
name|BPS_IO_INPUT
expr_stmt|;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fd
argument_list|,
operator|&
name|d
operator|->
name|sn_vec
index|[
literal|1
index|]
operator|.
name|enabled_fds
argument_list|)
condition|)
name|io_events
operator||=
name|BPS_IO_OUTPUT
expr_stmt|;
if|if
condition|(
name|FD_ISSET
argument_list|(
name|fd
argument_list|,
operator|&
name|d
operator|->
name|sn_vec
index|[
literal|2
index|]
operator|.
name|enabled_fds
argument_list|)
condition|)
name|io_events
operator||=
name|BPS_IO_EXCEPT
expr_stmt|;
return|return
name|io_events
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
