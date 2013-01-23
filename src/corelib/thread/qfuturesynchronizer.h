begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUTURESYNCHRONIZER_H
end_ifndef
begin_define
DECL|macro|QFUTURESYNCHRONIZER_H
define|#
directive|define
name|QFUTURESYNCHRONIZER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qfuture.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QFUTURE
end_ifndef
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFutureSynchronizer
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QFutureSynchronizer
argument_list|)
name|public
operator|:
name|QFutureSynchronizer
argument_list|()
operator|:
name|m_cancelOnWait
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|QFutureSynchronizer
argument_list|(
specifier|const
name|QFuture
operator|<
name|T
operator|>
operator|&
name|future
argument_list|)
operator|:
name|m_cancelOnWait
argument_list|(
argument|false
argument_list|)
block|{
name|addFuture
argument_list|(
name|future
argument_list|)
block|; }
operator|~
name|QFutureSynchronizer
argument_list|()
block|{
name|waitForFinished
argument_list|()
block|; }
name|void
name|setFuture
argument_list|(
argument|const QFuture<T>&future
argument_list|)
block|{
name|waitForFinished
argument_list|()
block|;
name|m_futures
operator|.
name|clear
argument_list|()
block|;
name|addFuture
argument_list|(
name|future
argument_list|)
block|;     }
name|void
name|addFuture
argument_list|(
argument|const QFuture<T>&future
argument_list|)
block|{
name|m_futures
operator|.
name|append
argument_list|(
name|future
argument_list|)
block|;     }
name|void
name|waitForFinished
argument_list|()
block|{
if|if
condition|(
name|m_cancelOnWait
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_futures
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_futures
index|[
name|i
index|]
operator|.
name|cancel
argument_list|()
expr_stmt|;
block|}
block|}
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_futures
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_futures
index|[
name|i
index|]
operator|.
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_for
begin_macro
unit|}      void
name|clearFutures
argument_list|()
end_macro
begin_block
block|{
name|m_futures
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_block
begin_expr_stmt
name|QList
operator|<
name|QFuture
operator|<
name|T
operator|>
expr|>
name|futures
argument_list|()
specifier|const
block|{
return|return
name|m_futures
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setCancelOnWait
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_cancelOnWait
operator|=
name|enabled
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|cancelOnWait
argument_list|()
specifier|const
block|{
return|return
name|m_cancelOnWait
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QList
operator|<
name|QFuture
operator|<
name|T
operator|>
expr|>
name|m_futures
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|m_cancelOnWait
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QFUTURE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUTURESYNCHRONIZER_H
end_comment
end_unit
