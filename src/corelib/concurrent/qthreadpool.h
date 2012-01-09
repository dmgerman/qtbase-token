begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTHREADPOOL_H
end_ifndef
begin_define
DECL|macro|QTHREADPOOL_H
define|#
directive|define
name|QTHREADPOOL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrunnable.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QThreadPoolPrivate
name|class
name|QThreadPoolPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QThreadPool
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QThreadPool
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int expiryTimeout READ expiryTimeout WRITE setExpiryTimeout
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maxThreadCount READ maxThreadCount WRITE setMaxThreadCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int activeThreadCount READ activeThreadCount
argument_list|)
name|friend
name|class
name|QFutureInterfaceBase
block|;
name|public
operator|:
name|QThreadPool
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QThreadPool
argument_list|()
block|;
specifier|static
name|QThreadPool
operator|*
name|globalInstance
argument_list|()
block|;
name|void
name|start
argument_list|(
argument|QRunnable *runnable
argument_list|,
argument|int priority =
literal|0
argument_list|)
block|;
name|bool
name|tryStart
argument_list|(
name|QRunnable
operator|*
name|runnable
argument_list|)
block|;
name|int
name|expiryTimeout
argument_list|()
specifier|const
block|;
name|void
name|setExpiryTimeout
argument_list|(
argument|int expiryTimeout
argument_list|)
block|;
name|int
name|maxThreadCount
argument_list|()
specifier|const
block|;
name|void
name|setMaxThreadCount
argument_list|(
argument|int maxThreadCount
argument_list|)
block|;
name|int
name|activeThreadCount
argument_list|()
specifier|const
block|;
name|void
name|reserveThread
argument_list|()
block|;
name|void
name|releaseThread
argument_list|()
block|;
name|void
name|waitForDone
argument_list|()
block|;
name|bool
name|waitForDone
argument_list|(
argument|int msecs
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
