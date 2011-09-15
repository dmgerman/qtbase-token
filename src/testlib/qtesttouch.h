begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Test
argument_list|)
decl|extern
name|Q_GUI_EXPORT
name|void
name|qt_translateRawTouchEvent
argument_list|(
name|QWidget
operator|*
name|window
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
name|deviceType
argument_list|,
specifier|const
name|QList
operator|<
name|QTouchEvent
operator|::
name|TouchPoint
operator|>
operator|&
name|touchPoints
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
block|;
name|points
operator|.
name|clear
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
argument|QWidget *widget =
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
name|widget
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
name|point
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
name|private
label|:
name|QTouchEventSequence
argument_list|(
argument|QWidget *widget
argument_list|,
argument|QTouchEvent::DeviceType aDeviceType
argument_list|)
block|:
name|targetWidget
argument_list|(
name|widget
argument_list|)
operator|,
name|deviceType
argument_list|(
argument|aDeviceType
argument_list|)
block|{         }
name|QTouchEventSequence
argument_list|(
argument|QWindow *window
argument_list|,
argument|QTouchEvent::DeviceType aDeviceType
argument_list|)
operator|:
name|targetWindow
argument_list|(
name|window
argument_list|)
operator|,
name|deviceType
argument_list|(
argument|aDeviceType
argument_list|)
block|{         }
name|QTouchEventSequence
argument_list|(
specifier|const
name|QTouchEventSequence
operator|&
name|v
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|QTouchEventSequence
operator|&
operator|)
decl_stmt|;
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
name|isPrimary
operator|=
name|pt
operator|.
name|isPrimary
argument_list|()
block|;
name|p
operator|.
name|normalPosition
operator|=
name|pt
operator|.
name|screenRect
argument_list|()
operator|.
name|topLeft
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
return|return
name|p
return|;
block|}
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
name|foreach
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
name|void
name|commit
parameter_list|()
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
name|QEvent
operator|::
name|None
argument_list|,
name|deviceType
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
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|targetWindow
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|targetWidget
condition|)
block|{
name|qt_translateRawTouchEvent
argument_list|(
name|targetWidget
argument_list|,
name|deviceType
argument_list|,
name|points
operator|.
name|values
argument_list|()
argument_list|)
expr_stmt|;
name|targetWidget
operator|=
literal|0
expr_stmt|;
block|}
block|}
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
name|QWidget
modifier|*
name|targetWidget
decl_stmt|;
name|QWindow
modifier|*
name|targetWindow
decl_stmt|;
name|QTouchEvent
operator|::
name|DeviceType
name|deviceType
expr_stmt|;
name|friend
name|QTouchEventSequence
name|touchEvent
argument_list|(
name|QWidget
operator|*
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
argument_list|)
decl_stmt|;
name|friend
name|QTouchEventSequence
name|touchEvent
argument_list|(
name|QWindow
operator|*
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
specifier|inline
name|QTouchEventSequence
name|touchEvent
argument_list|(
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
name|deviceType
operator|=
name|QTouchEvent
operator|::
name|TouchScreen
argument_list|)
block|{
return|return
name|QTouchEventSequence
argument_list|(
name|widget
argument_list|,
name|deviceType
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QTouchEventSequence
name|touchEvent
argument_list|(
name|QWindow
operator|*
name|window
operator|=
literal|0
argument_list|,
name|QTouchEvent
operator|::
name|DeviceType
name|deviceType
operator|=
name|QTouchEvent
operator|::
name|TouchScreen
argument_list|)
block|{
return|return
name|QTouchEventSequence
argument_list|(
name|window
argument_list|,
name|deviceType
argument_list|)
return|;
block|}
end_decl_stmt
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
