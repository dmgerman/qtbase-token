begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Copyright (c) 2007-2008, Apple, Inc. ** ** All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are met: ** **   * Redistributions of source code must retain the above copyright notice, **     this list of conditions and the following disclaimer. ** **   * Redistributions in binary form must reproduce the above copyright notice, **     this list of conditions and the following disclaimer in the documentation **     and/or other materials provided with the distribution. ** **   * Neither the name of Apple, Inc. nor the names of its contributors **     may be used to endorse or promote products derived from this software **     without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR ** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTDISPATCHER_CF_P_H
end_ifndef
begin_define
DECL|macro|QEVENTDISPATCHER_CF_P_H
define|#
directive|define
name|QEVENTDISPATCHER_CF_P_H
end_define
begin_define
DECL|macro|DEBUG_EVENT_DISPATCHER
define|#
directive|define
name|DEBUG_EVENT_DISPATCHER
value|0
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstracteventdispatcher.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qtimerinfo_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qcfsocketnotifier_p.h>
end_include
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventDispatcherCoreFoundation
name|class
name|QEventDispatcherCoreFoundation
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|=
name|QEventDispatcherCoreFoundation
operator|>
name|class
name|RunLoopSource
block|{
name|public
operator|:
typedef|typedef
name|void
argument_list|(
name|T
operator|::
operator|*
name|CallbackFunction
argument_list|)
argument_list|()
expr_stmt|;
block|enum
block|{
name|kHighestPriority
operator|=
literal|0
block|}
name|RunLoopSourcePriority
expr_stmt|;
end_expr_stmt
begin_macro
name|RunLoopSource
argument_list|(
argument|T *delegate
argument_list|,
argument|CallbackFunction callback
argument_list|)
end_macro
begin_expr_stmt
unit|:
name|m_delegate
argument_list|(
name|delegate
argument_list|)
operator|,
name|m_callback
argument_list|(
argument|callback
argument_list|)
block|{
name|CFRunLoopSourceContext
name|context
operator|=
block|{}
block|;
name|context
operator|.
name|info
operator|=
name|this
block|;
name|context
operator|.
name|perform
operator|=
name|RunLoopSource
operator|::
name|process
block|;
name|m_source
operator|=
name|CFRunLoopSourceCreate
argument_list|(
name|kCFAllocatorDefault
argument_list|,
name|kHighestPriority
argument_list|,
operator|&
name|context
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|m_source
argument_list|)
block|;     }
operator|~
name|RunLoopSource
argument_list|()
block|{
name|CFRunLoopSourceInvalidate
argument_list|(
name|m_source
argument_list|)
block|;
name|CFRelease
argument_list|(
name|m_source
argument_list|)
block|;     }
name|void
name|addToMode
argument_list|(
argument|CFStringRef mode
argument_list|,
argument|CFRunLoopRef runLoop =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|runLoop
condition|)
name|runLoop
operator|=
name|CFRunLoopGetCurrent
argument_list|()
expr_stmt|;
name|CFRunLoopAddSource
argument_list|(
name|runLoop
argument_list|,
name|m_source
argument_list|,
name|mode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
unit|}      void
name|signal
argument_list|()
end_macro
begin_block
block|{
name|CFRunLoopSourceSignal
argument_list|(
name|m_source
argument_list|)
expr_stmt|;
block|}
end_block
begin_label
name|private
label|:
end_label
begin_function
specifier|static
name|void
name|process
parameter_list|(
name|void
modifier|*
name|info
parameter_list|)
block|{
name|RunLoopSource
modifier|*
name|self
init|=
name|static_cast
operator|<
name|RunLoopSource
operator|*
operator|>
operator|(
name|info
operator|)
decl_stmt|;
operator|(
operator|(
name|self
operator|->
name|m_delegate
operator|)
operator|->*
operator|(
name|self
operator|->
name|m_callback
operator|)
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|T
modifier|*
name|m_delegate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|CallbackFunction
name|m_callback
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|CFRunLoopSourceRef
name|m_source
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|variable|T
name|template
operator|<
name|class
name|T
operator|=
name|QEventDispatcherCoreFoundation
operator|>
name|class
name|RunLoopObserver
block|{
name|public
operator|:
typedef|typedef
name|void
argument_list|(
argument|T::*CallbackFunction
argument_list|)
operator|(
name|CFRunLoopActivity
name|activity
operator|)
expr_stmt|;
name|RunLoopObserver
argument_list|(
argument|T *delegate
argument_list|,
argument|CallbackFunction callback
argument_list|,
argument|CFOptionFlags activities
argument_list|)
operator|:
name|m_delegate
argument_list|(
name|delegate
argument_list|)
operator|,
name|m_callback
argument_list|(
argument|callback
argument_list|)
block|{
name|CFRunLoopObserverContext
name|context
operator|=
block|{}
block|;
name|context
operator|.
name|info
operator|=
name|this
block|;
name|m_observer
operator|=
name|CFRunLoopObserverCreate
argument_list|(
name|kCFAllocatorDefault
argument_list|,
name|activities
argument_list|,
name|true
argument_list|,
literal|0
argument_list|,
name|process
argument_list|,
operator|&
name|context
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|m_observer
argument_list|)
block|;     }
operator|~
name|RunLoopObserver
argument_list|()
block|{
name|CFRunLoopObserverInvalidate
argument_list|(
name|m_observer
argument_list|)
block|;
name|CFRelease
argument_list|(
name|m_observer
argument_list|)
block|;     }
name|void
name|addToMode
argument_list|(
argument|CFStringRef mode
argument_list|,
argument|CFRunLoopRef runLoop =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|runLoop
condition|)
name|runLoop
operator|=
name|CFRunLoopGetCurrent
argument_list|()
expr_stmt|;
name|CFRunLoopAddObserver
argument_list|(
name|runLoop
argument_list|,
name|m_observer
argument_list|,
name|mode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
unit|}  private:
specifier|static
name|void
name|process
parameter_list|(
name|CFRunLoopObserverRef
parameter_list|,
name|CFRunLoopActivity
name|activity
parameter_list|,
name|void
modifier|*
name|info
parameter_list|)
block|{
name|RunLoopObserver
modifier|*
name|self
init|=
name|static_cast
operator|<
name|RunLoopObserver
operator|*
operator|>
operator|(
name|info
operator|)
decl_stmt|;
operator|(
operator|(
name|self
operator|->
name|m_delegate
operator|)
operator|->*
operator|(
name|self
operator|->
name|m_callback
operator|)
operator|)
operator|(
name|activity
operator|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|T
modifier|*
name|m_delegate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|CallbackFunction
name|m_callback
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|CFRunLoopObserverRef
name|m_observer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|QEventDispatcherCoreFoundation
range|:
name|public
name|QAbstractEventDispatcher
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QEventDispatcherCoreFoundation
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QEventDispatcherCoreFoundation
argument_list|()
block|;
name|bool
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|)
block|;
name|bool
name|hasPendingEvents
argument_list|()
block|;
name|void
name|registerSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
name|void
name|unregisterSocketNotifier
argument_list|(
name|QSocketNotifier
operator|*
name|notifier
argument_list|)
block|;
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
block|;
name|bool
name|unregisterTimer
argument_list|(
argument|int timerId
argument_list|)
block|;
name|bool
name|unregisterTimers
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QList
operator|<
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
operator|>
name|registeredTimers
argument_list|(
argument|QObject *object
argument_list|)
specifier|const
block|;
name|int
name|remainingTime
argument_list|(
argument|int timerId
argument_list|)
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|void
name|interrupt
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|;
name|private
operator|:
name|RunLoopSource
operator|<
operator|>
name|m_postedEventsRunLoopSource
block|;
name|RunLoopObserver
operator|<
operator|>
name|m_runLoopActivityObserver
block|;
name|QTimerInfoList
name|m_timerInfoList
block|;
name|CFRunLoopTimerRef
name|m_runLoopTimer
block|;
name|CFRunLoopTimerRef
name|m_blockedRunLoopTimer
block|;
name|bool
name|m_overdueTimerScheduled
block|;
name|QCFSocketNotifier
name|m_cfSocketNotifier
block|;      struct
name|ProcessEventsState
block|{
name|ProcessEventsState
argument_list|(
argument|QEventLoop::ProcessEventsFlags f
argument_list|)
operator|:
name|flags
argument_list|(
name|f
argument_list|)
block|,
name|wasInterrupted
argument_list|(
name|false
argument_list|)
block|,
name|processedPostedEvents
argument_list|(
name|false
argument_list|)
block|,
name|processedTimers
argument_list|(
name|false
argument_list|)
block|,
name|deferredWakeUp
argument_list|(
name|false
argument_list|)
block|,
name|deferredUpdateTimers
argument_list|(
argument|false
argument_list|)
block|{}
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
block|;
name|bool
name|wasInterrupted
block|;
name|bool
name|processedPostedEvents
block|;
name|bool
name|processedTimers
block|;
name|bool
name|deferredWakeUp
block|;
name|bool
name|deferredUpdateTimers
block|;     }
block|;
name|ProcessEventsState
name|m_processEvents
block|;
name|void
name|processPostedEvents
argument_list|()
block|;
name|void
name|processTimers
argument_list|(
name|CFRunLoopTimerRef
argument_list|)
block|;
name|void
name|handleRunLoopActivity
argument_list|(
argument|CFRunLoopActivity activity
argument_list|)
block|;
name|void
name|updateTimers
argument_list|()
block|;
name|void
name|invalidateTimer
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
if|#
directive|if
name|DEBUG_EVENT_DISPATCHER
specifier|extern
name|uint
name|g_eventDispatcherIndentationLevel
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|qEventDispatcherDebug
define|#
directive|define
name|qEventDispatcherDebug
parameter_list|()
value|qDebug().nospace() \<< qPrintable(QString(QLatin1String("| ")).repeated(g_eventDispatcherIndentationLevel)) \<< __FUNCTION__<< "(): "
end_define
begin_define
DECL|macro|qIndent
define|#
directive|define
name|qIndent
parameter_list|()
value|++g_eventDispatcherIndentationLevel
end_define
begin_define
DECL|macro|qUnIndent
define|#
directive|define
name|qUnIndent
parameter_list|()
value|--g_eventDispatcherIndentationLevel
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|qEventDispatcherDebug
parameter_list|()
value|QT_NO_QDEBUG_MACRO()
end_define
begin_define
define|#
directive|define
name|qIndent
parameter_list|()
end_define
begin_define
define|#
directive|define
name|qUnIndent
parameter_list|()
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEVENTDISPATCHER_CF_P_H
end_comment
end_unit
