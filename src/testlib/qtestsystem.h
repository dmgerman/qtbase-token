begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTSYSTEM_H
end_ifndef
begin_define
DECL|macro|QTESTSYSTEM_H
define|#
directive|define
name|QTESTSYSTEM_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QTest
block|{
specifier|inline
specifier|static
name|void
name|qWait
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|)
expr_stmt|;
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
do|do
block|{
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|,
name|ms
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|ms
condition|)
do|;
block|}
specifier|inline
specifier|static
name|bool
name|qWaitForWindowShown
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|qWait
argument_list|(
literal|200
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
specifier|inline
specifier|static
name|bool
name|qWaitForWindowActive
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|window
operator|->
name|isActive
argument_list|()
condition|)
block|{
name|int
name|remaining
init|=
name|timeout
operator|-
name|int
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|remaining
operator|<=
literal|0
condition|)
break|break;
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
comment|// Try ensuring the platform window receives the real position.
comment|// (i.e. that window->pos() reflects reality)
comment|// isActive() ( == FocusIn in case of X) does not guarantee this. It seems some WMs randomly
comment|// send the final ConfigureNotify (the one with the non-bogus 0,0 position) after the FocusIn.
comment|// If we just let things go, every mapTo/FromGlobal call the tests perform directly after
comment|// qWaitForWindowShown() will generate bogus results.
if|if
condition|(
name|window
operator|->
name|isActive
argument_list|()
condition|)
block|{
name|int
name|waitNo
init|=
literal|0
decl_stmt|;
comment|// 0, 0 might be a valid position after all, so do not wait for ever
while|while
condition|(
name|window
operator|->
name|pos
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|waitNo
operator|++
operator|>
name|timeout
operator|/
literal|10
condition|)
break|break;
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|window
operator|->
name|isActive
argument_list|()
return|;
block|}
specifier|inline
specifier|static
name|bool
name|qWaitForWindowExposed
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|window
operator|->
name|isExposed
argument_list|()
condition|)
block|{
name|int
name|remaining
init|=
name|timeout
operator|-
name|int
argument_list|(
name|timer
operator|.
name|elapsed
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|remaining
operator|<=
literal|0
condition|)
break|break;
name|QCoreApplication
operator|::
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qSleep
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
return|return
name|window
operator|->
name|isExposed
argument_list|()
return|;
block|}
specifier|inline
specifier|static
name|bool
name|qWaitForWindowShown
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
return|return
name|qWaitForWindowActive
argument_list|(
name|window
argument_list|,
name|timeout
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
