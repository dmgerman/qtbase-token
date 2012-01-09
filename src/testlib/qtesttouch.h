begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTTOUCH_H
end_ifndef
begin_define
DECL|macro|QTESTTOUCH_H
define|#
directive|define
name|QTESTTOUCH_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestsystem.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestspontaneevent.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|namespace
name|QTest
block|{
name|class
name|QTouchEventSequence
block|{
name|public
label|:
operator|~
name|QTouchEventSequence
argument_list|()
block|{
name|commit
argument_list|()
block|;         }
name|QTouchEventSequence
operator|&
name|press
argument_list|(
argument|int touchId
argument_list|,
argument|const QPoint&pt
argument_list|,
argument|QWindow *window =
literal|0
argument_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
block|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|window
argument_list|,
name|pt
argument_list|)
argument_list|)
block|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointPressed
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|QTouchEventSequence
modifier|&
name|move
parameter_list|(
name|int
name|touchId
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|,
name|QWindow
modifier|*
name|window
init|=
literal|0
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|window
argument_list|,
name|pt
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointMoved
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|QTouchEventSequence
modifier|&
name|release
parameter_list|(
name|int
name|touchId
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|,
name|QWindow
modifier|*
name|window
init|=
literal|0
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|window
argument_list|,
name|pt
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointReleased
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|QTouchEventSequence
modifier|&
name|stationary
parameter_list|(
name|int
name|touchId
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|pointOrPreviousPoint
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointStationary
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|QTouchEventSequence
modifier|&
name|press
parameter_list|(
name|int
name|touchId
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|widget
argument_list|,
name|pt
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointPressed
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|QTouchEventSequence
modifier|&
name|move
parameter_list|(
name|int
name|touchId
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|widget
argument_list|,
name|pt
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointMoved
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|QTouchEventSequence
modifier|&
name|release
parameter_list|(
name|int
name|touchId
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
block|{
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|p
operator|=
name|point
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
name|p
operator|.
name|setScreenPos
argument_list|(
name|mapToScreen
argument_list|(
name|widget
argument_list|,
name|pt
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointReleased
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|commit
parameter_list|()
block|{
if|if
condition|(
operator|!
name|points
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|targetWindow
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|targetWindow
argument_list|,
name|device
argument_list|,
name|touchPointList
argument_list|(
name|points
operator|.
name|values
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
elseif|else
if|if
condition|(
name|targetWidget
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|targetWidget
operator|->
name|windowHandle
argument_list|()
argument_list|,
name|device
argument_list|,
name|touchPointList
argument_list|(
name|points
operator|.
name|values
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|previousPoints
operator|=
name|points
expr_stmt|;
name|points
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
specifier|static
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|touchPoint
argument_list|(
argument|const QTouchEvent::TouchPoint& pt
argument_list|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|p
block|;
name|p
operator|.
name|id
operator|=
name|pt
operator|.
name|id
argument_list|()
block|;
name|p
operator|.
name|flags
operator|=
name|pt
operator|.
name|flags
argument_list|()
block|;
name|p
operator|.
name|normalPosition
operator|=
name|pt
operator|.
name|normalizedPos
argument_list|()
block|;
name|p
operator|.
name|area
operator|=
name|pt
operator|.
name|screenRect
argument_list|()
block|;
name|p
operator|.
name|pressure
operator|=
name|pt
operator|.
name|pressure
argument_list|()
block|;
name|p
operator|.
name|state
operator|=
name|pt
operator|.
name|state
argument_list|()
block|;
name|p
operator|.
name|velocity
operator|=
name|pt
operator|.
name|velocity
argument_list|()
block|;
name|p
operator|.
name|rawPositions
operator|=
name|pt
operator|.
name|rawScreenPositions
argument_list|()
block|;
return|return
name|p
return|;
block|}
specifier|static
name|QList
operator|<
expr|struct
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|touchPointList
argument_list|(
argument|const QList<QTouchEvent::TouchPoint>& pointList
argument_list|)
block|{
name|QList
operator|<
expr|struct
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|newList
block|;
name|Q_FOREACH
argument_list|(
argument|QTouchEvent::TouchPoint p
argument_list|,
argument|pointList
argument_list|)
block|{
name|newList
operator|.
name|append
argument_list|(
name|touchPoint
argument_list|(
name|p
argument_list|)
argument_list|)
block|;             }
return|return
name|newList
return|;
block|}
name|private
label|:
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|QTouchEventSequence
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|QTouchDevice
operator|*
name|aDevice
argument_list|)
operator|:
name|targetWidget
argument_list|(
name|widget
argument_list|)
operator|,
name|targetWindow
argument_list|(
literal|0
argument_list|)
operator|,
name|device
argument_list|(
argument|aDevice
argument_list|)
block|{         }
endif|#
directive|endif
name|QTouchEventSequence
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|QTouchDevice
operator|*
name|aDevice
argument_list|)
operator|:
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|targetWidget
argument_list|(
literal|0
argument_list|)
operator|,
endif|#
directive|endif
name|targetWindow
argument_list|(
name|window
argument_list|)
operator|,
name|device
argument_list|(
argument|aDevice
argument_list|)
block|{         }
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|point
argument_list|(
argument|int touchId
argument_list|)
block|{
if|if
condition|(
operator|!
name|points
operator|.
name|contains
argument_list|(
name|touchId
argument_list|)
condition|)
name|points
index|[
name|touchId
index|]
operator|=
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
return|return
name|points
index|[
name|touchId
index|]
return|;
block|}
name|QTouchEvent
operator|::
name|TouchPoint
operator|&
name|pointOrPreviousPoint
argument_list|(
argument|int touchId
argument_list|)
block|{
if|if
condition|(
operator|!
name|points
operator|.
name|contains
argument_list|(
name|touchId
argument_list|)
condition|)
block|{
if|if
condition|(
name|previousPoints
operator|.
name|contains
argument_list|(
name|touchId
argument_list|)
condition|)
name|points
index|[
name|touchId
index|]
operator|=
name|previousPoints
operator|.
name|value
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
else|else
name|points
index|[
name|touchId
index|]
operator|=
name|QTouchEvent
operator|::
name|TouchPoint
argument_list|(
name|touchId
argument_list|)
expr_stmt|;
block|}
return|return
name|points
index|[
name|touchId
index|]
return|;
block|}
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|QPoint
name|mapToScreen
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
block|{
if|if
condition|(
name|widget
condition|)
return|return
name|widget
operator|->
name|mapToGlobal
argument_list|(
name|pt
argument_list|)
return|;
return|return
name|targetWidget
condition|?
name|targetWidget
operator|->
name|mapToGlobal
argument_list|(
name|pt
argument_list|)
else|:
name|pt
return|;
block|}
endif|#
directive|endif
name|QPoint
name|mapToScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
block|{
if|if
condition|(
name|window
condition|)
return|return
name|window
operator|->
name|mapToGlobal
argument_list|(
name|pt
argument_list|)
return|;
return|return
name|targetWindow
condition|?
name|targetWindow
operator|->
name|mapToGlobal
argument_list|(
name|pt
argument_list|)
else|:
name|pt
return|;
block|}
name|QMap
operator|<
name|int
operator|,
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|previousPoints
expr_stmt|;
name|QMap
operator|<
name|int
operator|,
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
name|points
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|QWidget
modifier|*
name|targetWidget
decl_stmt|;
endif|#
directive|endif
name|QWindow
modifier|*
name|targetWindow
decl_stmt|;
name|QTouchDevice
modifier|*
name|device
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
name|friend
name|QTouchEventSequence
name|touchEvent
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|QTouchDevice
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|friend
name|QTouchEventSequence
name|touchEvent
parameter_list|(
name|QWindow
modifier|*
parameter_list|,
name|QTouchDevice
modifier|*
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_function
specifier|inline
name|QTouchEventSequence
name|touchEvent
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QTouchDevice
modifier|*
name|device
parameter_list|)
block|{
return|return
name|QTouchEventSequence
argument_list|(
name|widget
argument_list|,
name|device
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|inline
name|QTouchEventSequence
name|touchEvent
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|QTouchDevice
modifier|*
name|device
parameter_list|)
block|{
return|return
name|QTouchEventSequence
argument_list|(
name|window
argument_list|,
name|device
argument_list|)
return|;
block|}
end_function
begin_macro
unit|}  QT_END_NAMESPACE
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTTOUCH_H
end_comment
end_unit
