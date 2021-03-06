begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_class
DECL|class|QTestAliveEvent
class|class
name|QTestAliveEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|enumerator|AliveEventType
enum|enum
block|{
name|AliveEventType
init|=
name|QEvent
operator|::
name|User
operator|+
literal|422
block|}
enum|;
DECL|function|QTestAliveEvent
specifier|explicit
specifier|inline
name|QTestAliveEvent
parameter_list|(
name|int
name|aSequenceId
parameter_list|)
member_init_list|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|AliveEventType
argument_list|)
argument_list|)
member_init_list|,
name|seqId
argument_list|(
name|aSequenceId
argument_list|)
block|{}
DECL|function|sequenceId
specifier|inline
name|int
name|sequenceId
parameter_list|()
specifier|const
block|{
return|return
name|seqId
return|;
block|}
private|private:
DECL|member|seqId
name|int
name|seqId
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QTestAlivePinger
class|class
name|QTestAlivePinger
super|:
specifier|public
name|QObject
block|{
public|public:
name|QTestAlivePinger
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
protected|protected:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
function_decl|;
private|private:
DECL|member|rec
name|QObject
modifier|*
name|rec
decl_stmt|;
DECL|member|timerId
name|int
name|timerId
decl_stmt|;
DECL|member|currentSequenceId
name|int
name|currentSequenceId
decl_stmt|;
DECL|member|lastSequenceId
name|int
name|lastSequenceId
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTestAlivePinger
name|QTestAlivePinger
operator|::
name|QTestAlivePinger
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|rec
argument_list|(
name|receiver
argument_list|)
member_init_list|,
name|currentSequenceId
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|lastSequenceId
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|rec
condition|)
name|qFatal
argument_list|(
literal|"Null receiver object passed to QTestAlivePinger::QTestAlivePinger()"
argument_list|)
expr_stmt|;
name|timerId
operator|=
name|startTimer
argument_list|(
literal|850
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|event
name|bool
name|QTestAlivePinger
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
comment|// pong received
if|if
condition|(
name|int
argument_list|(
name|event
operator|->
name|type
argument_list|()
argument_list|)
operator|==
name|QTestAliveEvent
operator|::
name|AliveEventType
condition|)
block|{
name|QTestAliveEvent
modifier|*
name|e
init|=
cast|static_cast
argument_list|<
name|QTestAliveEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
comment|//qDebug("PONG %d received", e->sequenceId());
comment|// if the events are not delivered in order, we don't care.
if|if
condition|(
name|e
operator|->
name|sequenceId
argument_list|()
operator|>
name|lastSequenceId
condition|)
name|lastSequenceId
operator|=
name|e
operator|->
name|sequenceId
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|QTestAlivePinger
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|timerId
argument_list|()
operator|!=
name|timerId
condition|)
return|return;
if|if
condition|(
name|lastSequenceId
operator|<
name|currentSequenceId
operator|-
literal|2
condition|)
block|{
name|qWarning
argument_list|(
literal|"TEST LAGS %d PINGS behind!"
argument_list|,
name|currentSequenceId
operator|-
name|lastSequenceId
argument_list|)
expr_stmt|;
block|}
operator|++
name|currentSequenceId
expr_stmt|;
comment|//qDebug("PING %d", currentSequenceId);
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|rec
argument_list|,
operator|new
name|QTestAliveEvent
argument_list|(
name|currentSequenceId
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QTestAlive
class|class
name|QTestAlive
super|:
specifier|public
name|QThread
block|{
public|public:
name|QTestAlive
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|QTestAlive
parameter_list|()
destructor_decl|;
name|void
name|run
parameter_list|()
function_decl|;
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
private|private:
DECL|member|pinger
name|QTestAlivePinger
modifier|*
name|pinger
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTestAlive
name|QTestAlive
operator|::
name|QTestAlive
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|pinger
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTestAlive
name|QTestAlive
operator|::
name|~
name|QTestAlive
parameter_list|()
block|{
name|quit
argument_list|()
expr_stmt|;
while|while
condition|(
name|isRunning
argument_list|()
condition|)
empty_stmt|;
block|}
end_destructor
begin_function
DECL|function|event
name|bool
name|QTestAlive
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|int
argument_list|(
name|e
operator|->
name|type
argument_list|()
argument_list|)
operator|==
name|QTestAliveEvent
operator|::
name|AliveEventType
operator|&&
name|pinger
condition|)
block|{
comment|// ping received, send back the pong
comment|//qDebug("PONG %d", static_cast<QTestAliveEvent *>(e)->sequenceId());
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|pinger
argument_list|,
operator|new
name|QTestAliveEvent
argument_list|(
cast|static_cast
argument_list|<
name|QTestAliveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|sequenceId
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|QThread
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|run
name|void
name|QTestAlive
operator|::
name|run
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QCoreApplication
operator|::
name|instance
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"QTestAlive::run(): Cannot start QTestAlive without a QCoreApplication instance."
argument_list|)
expr_stmt|;
name|QTestAlivePinger
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|pinger
operator|=
operator|&
name|p
expr_stmt|;
name|exec
argument_list|()
expr_stmt|;
name|pinger
operator|=
literal|0
expr_stmt|;
block|}
end_function
end_unit
