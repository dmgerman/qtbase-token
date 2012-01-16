begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTHREADPOOL_P_H
end_ifndef
begin_define
DECL|macro|QTHREADPOOL_P_H
define|#
directive|define
name|QTHREADPOOL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qset.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qqueue.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QThreadPoolThread
name|class
name|QThreadPoolThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QThreadPoolPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QThreadPool
argument_list|)
name|friend
name|class
name|QThreadPoolThread
block|;
name|public
operator|:
name|QThreadPoolPrivate
argument_list|()
block|;
name|bool
name|tryStart
argument_list|(
name|QRunnable
operator|*
name|task
argument_list|)
block|;
name|void
name|enqueueTask
argument_list|(
argument|QRunnable *task
argument_list|,
argument|int priority =
literal|0
argument_list|)
block|;
name|int
name|activeThreadCount
argument_list|()
specifier|const
block|;
name|void
name|tryToStartMoreThreads
argument_list|()
block|;
name|bool
name|tooManyThreadsActive
argument_list|()
specifier|const
block|;
name|void
name|startThread
argument_list|(
name|QRunnable
operator|*
name|runnable
operator|=
literal|0
argument_list|)
block|;
name|void
name|reset
argument_list|()
block|;
name|bool
name|waitForDone
argument_list|(
argument|int msecs = -
literal|1
argument_list|)
block|;
name|bool
name|startFrontRunnable
argument_list|()
block|;
name|void
name|stealRunnable
argument_list|(
name|QRunnable
operator|*
argument_list|)
block|;
name|mutable
name|QMutex
name|mutex
block|;
name|QWaitCondition
name|runnableReady
block|;
name|QSet
operator|<
name|QThreadPoolThread
operator|*
operator|>
name|allThreads
block|;
name|QQueue
operator|<
name|QThreadPoolThread
operator|*
operator|>
name|expiredThreads
block|;
name|QList
operator|<
name|QPair
operator|<
name|QRunnable
operator|*
block|,
name|int
operator|>
expr|>
name|queue
block|;
name|QWaitCondition
name|noActiveThreads
block|;
name|bool
name|isExiting
block|;
name|int
name|expiryTimeout
block|;
name|int
name|maxThreadCount
block|;
name|int
name|reservedThreads
block|;
name|int
name|waitingThreads
block|;
name|int
name|activeThreads
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
comment|// QT_NO_THREAD
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
