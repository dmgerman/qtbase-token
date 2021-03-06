begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTEVENTDISPATCHER_H
end_ifndef
begin_define
DECL|macro|QABSTRACTEVENTDISPATCHER_H
define|#
directive|define
name|QABSTRACTEVENTDISPATCHER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qeventloop.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractNativeEventFilter
name|class
name|QAbstractNativeEventFilter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcherPrivate
name|class
name|QAbstractEventDispatcherPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_decl_stmt
DECL|variable|QWinEventNotifier
name|class
name|QWinEventNotifier
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractEventDispatcher
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractEventDispatcher
argument_list|)
name|public
operator|:
expr|struct
name|TimerInfo
block|{
name|int
name|timerId
block|;
name|int
name|interval
block|;
name|Qt
operator|::
name|TimerType
name|timerType
block|;
specifier|inline
name|TimerInfo
argument_list|(
argument|int id
argument_list|,
argument|int i
argument_list|,
argument|Qt::TimerType t
argument_list|)
operator|:
name|timerId
argument_list|(
name|id
argument_list|)
block|,
name|interval
argument_list|(
name|i
argument_list|)
block|,
name|timerType
argument_list|(
argument|t
argument_list|)
block|{ }
block|}
block|;
name|explicit
name|QAbstractEventDispatcher
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QAbstractEventDispatcher
argument_list|()
block|;
specifier|static
name|QAbstractEventDispatcher
operator|*
name|instance
argument_list|(
name|QThread
operator|*
name|thread
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
name|bool
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|hasPendingEvents
argument_list|()
operator|=
literal|0
block|;
comment|// ### Qt6: remove, mark final or make protected
name|virtual
name|void
name|registerSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|unregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
operator|=
literal|0
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|int
name|registerTimer
argument_list|(
argument|int interval
argument_list|,
argument|QObject *object
argument_list|)
block|{
return|return
name|registerTimer
argument_list|(
name|interval
argument_list|,
name|Qt
operator|::
name|CoarseTimer
argument_list|,
name|object
argument_list|)
return|;
block|}
name|QT_DEPRECATED
specifier|inline
name|void
name|registerTimer
argument_list|(
argument|int timerId
argument_list|,
argument|int interval
argument_list|,
argument|QObject *object
argument_list|)
block|{
name|registerTimer
argument_list|(
name|timerId
argument_list|,
name|interval
argument_list|,
name|Qt
operator|::
name|CoarseTimer
argument_list|,
name|object
argument_list|)
block|; }
endif|#
directive|endif
name|int
name|registerTimer
argument_list|(
argument|int interval
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|QObject *object
argument_list|)
block|;
name|virtual
name|void
name|registerTimer
argument_list|(
argument|int timerId
argument_list|,
argument|int interval
argument_list|,
argument|Qt::TimerType timerType
argument_list|,
argument|QObject *object
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|unregisterTimers
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QList
operator|<
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|remainingTime
argument_list|(
argument|int timerId
argument_list|)
operator|=
literal|0
block|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|virtual
name|bool
name|registerEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|unregisterEventNotifier
argument_list|(
name|QWinEventNotifier
operator|*
name|notifier
argument_list|)
operator|=
literal|0
block|;
endif|#
directive|endif
name|virtual
name|void
name|wakeUp
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|interrupt
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|flush
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|startingUp
argument_list|()
block|;
name|virtual
name|void
name|closingDown
argument_list|()
block|;
name|void
name|installNativeEventFilter
argument_list|(
name|QAbstractNativeEventFilter
operator|*
name|filterObj
argument_list|)
block|;
name|void
name|removeNativeEventFilter
argument_list|(
name|QAbstractNativeEventFilter
operator|*
name|filterObj
argument_list|)
block|;
name|bool
name|filterNativeEvent
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
name|bool
name|filterEvent
argument_list|(
argument|void *message
argument_list|)
block|{
return|return
name|filterNativeEvent
argument_list|(
literal|""
argument_list|,
name|message
argument_list|,
name|Q_NULLPTR
argument_list|)
return|;
block|}
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|aboutToBlock
argument_list|()
block|;
name|void
name|awake
argument_list|()
block|;
name|protected
operator|:
name|QAbstractEventDispatcher
argument_list|(
name|QAbstractEventDispatcherPrivate
operator|&
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
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
comment|// QABSTRACTEVENTDISPATCHER_H
end_comment
end_unit
