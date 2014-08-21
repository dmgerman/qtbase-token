begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|enterLoopMSecs
argument_list|(
argument|int ms
argument_list|)
block|;
specifier|inline
name|void
name|enterLoop
argument_list|(
argument|int secs
argument_list|)
block|{
name|enterLoopMSecs
argument_list|(
name|secs
operator|*
literal|1000
argument_list|)
block|; }
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
DECL|function|enterLoopMSecs
specifier|inline
name|void
name|QTestEventLoop
operator|::
name|enterLoopMSecs
argument_list|(
argument|int ms
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
name|ms
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
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
end_unit
