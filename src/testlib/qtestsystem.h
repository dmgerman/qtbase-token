begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QTest
block|{
name|Q_DECL_UNUSED
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
ifdef|#
directive|ifdef
name|QT_GUI_LIB
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
literal|5000
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
name|position
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
literal|5000
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
specifier|inline
specifier|static
name|bool
name|qWaitForWindowActive
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
if|if
condition|(
name|QWindow
modifier|*
name|window
init|=
name|widget
operator|->
name|windowHandle
argument_list|()
condition|)
return|return
name|qWaitForWindowActive
argument_list|(
name|window
argument_list|,
name|timeout
argument_list|)
return|;
return|return
name|false
return|;
block|}
specifier|inline
specifier|static
name|bool
name|qWaitForWindowExposed
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
if|if
condition|(
name|QWindow
modifier|*
name|window
init|=
name|widget
operator|->
name|windowHandle
argument_list|()
condition|)
return|return
name|qWaitForWindowExposed
argument_list|(
name|window
argument_list|,
name|timeout
argument_list|)
return|;
return|return
name|false
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|QT_DEPRECATED
specifier|inline
specifier|static
name|bool
name|qWaitForWindowShown
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|int
name|timeout
init|=
literal|1000
parameter_list|)
block|{
return|return
name|qWaitForWindowExposed
argument_list|(
name|widget
argument_list|,
name|timeout
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// QT_WIDGETS_LIB
endif|#
directive|endif
comment|// QT_DEPRECATED_SINCE(5, 0)
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
