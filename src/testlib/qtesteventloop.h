begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTEVENTLOOP_H
end_ifndef
begin_define
DECL|macro|QTESTEVENTLOOP_H
define|#
directive|define
name|QTESTEVENTLOOP_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qeventloop.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_TESTLIB_EXPORT
name|QTestEventLoop
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|inline
name|QTestEventLoop
argument_list|(
name|QObject
operator|*
name|aParent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
name|aParent
argument_list|)
block|,
name|inLoop
argument_list|(
name|false
argument_list|)
block|,
name|_timeout
argument_list|(
name|false
argument_list|)
block|,
name|timerId
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|loop
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|void
name|enterLoop
argument_list|(
argument|int secs
argument_list|)
block|;
specifier|inline
name|void
name|changeInterval
argument_list|(
argument|int secs
argument_list|)
block|{
name|killTimer
argument_list|(
name|timerId
argument_list|)
block|;
name|timerId
operator|=
name|startTimer
argument_list|(
name|secs
operator|*
literal|1000
argument_list|)
block|; }
specifier|inline
name|bool
name|timeout
argument_list|()
specifier|const
block|{
return|return
name|_timeout
return|;
block|}
specifier|inline
specifier|static
name|QTestEventLoop
operator|&
name|instance
argument_list|()
block|{
specifier|static
name|QPointer
operator|<
name|QTestEventLoop
operator|>
name|testLoop
block|;
if|if
condition|(
name|testLoop
operator|.
name|isNull
argument_list|()
condition|)
name|testLoop
operator|=
name|new
name|QTestEventLoop
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|static_cast
operator|<
name|QTestEventLoop
operator|*
operator|>
operator|(
name|testLoop
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
specifier|inline
name|void
name|exitLoop
argument_list|()
decl_stmt|;
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
specifier|inline
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|bool
name|inLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|_timeout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|timerId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QEventLoop
modifier|*
name|loop
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|enterLoop
specifier|inline
name|void
name|QTestEventLoop
operator|::
name|enterLoop
argument_list|(
argument|int secs
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|loop
argument_list|)
block|;
name|QEventLoop
name|l
block|;
name|inLoop
operator|=
name|true
block|;
name|_timeout
operator|=
name|false
block|;
name|timerId
operator|=
name|startTimer
argument_list|(
name|secs
operator|*
literal|1000
argument_list|)
block|;
name|loop
operator|=
operator|&
name|l
block|;
name|l
operator|.
name|exec
argument_list|()
block|;
name|loop
operator|=
literal|0
block|; }
DECL|function|exitLoop
specifier|inline
name|void
name|QTestEventLoop
operator|::
name|exitLoop
argument_list|()
block|{
if|if
condition|(
name|timerId
operator|!=
operator|-
literal|1
condition|)
name|killTimer
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
name|timerId
operator|=
operator|-
literal|1
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|loop
condition|)
name|loop
operator|->
name|exit
argument_list|()
expr_stmt|;
end_if
begin_expr_stmt
name|inLoop
operator|=
name|false
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|timerEvent
name|void
name|QTestEventLoop
operator|::
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|!=
name|timerId
condition|)
return|return;
name|_timeout
operator|=
name|true
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|exitLoop
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
