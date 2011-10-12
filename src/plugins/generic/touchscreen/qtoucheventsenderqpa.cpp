begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtoucheventsenderqpa.h"
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|//#define POINT_DEBUG
DECL|function|QTouchEventSenderQPA
name|QTouchEventSenderQPA
operator|::
name|QTouchEventSenderQPA
parameter_list|(
specifier|const
name|QString
modifier|&
name|spec
parameter_list|)
block|{
name|m_forceToActiveWindow
operator|=
name|spec
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"force_window"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|touch_configure
name|void
name|QTouchEventSenderQPA
operator|::
name|touch_configure
parameter_list|(
name|int
name|x_min
parameter_list|,
name|int
name|x_max
parameter_list|,
name|int
name|y_min
parameter_list|,
name|int
name|y_max
parameter_list|)
block|{
name|hw_range_x_min
operator|=
name|x_min
expr_stmt|;
name|hw_range_x_max
operator|=
name|x_max
expr_stmt|;
name|hw_range_y_min
operator|=
name|y_min
expr_stmt|;
name|hw_range_y_max
operator|=
name|y_max
expr_stmt|;
block|}
end_function
begin_function
DECL|function|touch_point
name|void
name|QTouchEventSenderQPA
operator|::
name|touch_point
parameter_list|(
name|QEvent
operator|::
name|Type
name|state
parameter_list|,
specifier|const
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
modifier|&
name|points
parameter_list|)
block|{
name|QRect
name|winRect
decl_stmt|;
if|if
condition|(
name|m_forceToActiveWindow
condition|)
block|{
name|QWindow
modifier|*
name|win
init|=
name|QGuiApplication
operator|::
name|activeWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|win
condition|)
return|return;
name|winRect
operator|=
name|win
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|winRect
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|POINT_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"QPA: Mapping"
operator|<<
name|points
operator|.
name|size
argument_list|()
operator|<<
literal|"points to"
operator|<<
name|winRect
operator|<<
name|state
expr_stmt|;
endif|#
directive|endif
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
init|=
name|points
decl_stmt|;
comment|// Translate the coordinates and set the normalized position. QPA expects
comment|// 'area' to be in screen coordinates, while the device reports them in its
comment|// own system with (0, 0) being the center point of the device.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|touchPoints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
modifier|&
name|tp
argument_list|(
name|touchPoints
index|[
name|i
index|]
argument_list|)
decl_stmt|;
comment|// Translate so that (0, 0) is the top-left corner.
specifier|const
name|int
name|hw_x
init|=
name|qBound
argument_list|(
name|hw_range_x_min
argument_list|,
name|int
argument_list|(
name|tp
operator|.
name|area
operator|.
name|left
argument_list|()
argument_list|)
argument_list|,
name|hw_range_x_max
argument_list|)
operator|-
name|hw_range_x_min
decl_stmt|;
specifier|const
name|int
name|hw_y
init|=
name|qBound
argument_list|(
name|hw_range_y_min
argument_list|,
name|int
argument_list|(
name|tp
operator|.
name|area
operator|.
name|top
argument_list|()
argument_list|)
argument_list|,
name|hw_range_y_max
argument_list|)
operator|-
name|hw_range_y_min
decl_stmt|;
comment|// Get a normalized position in range 0..1.
specifier|const
name|int
name|hw_w
init|=
name|hw_range_x_max
operator|-
name|hw_range_x_min
decl_stmt|;
specifier|const
name|int
name|hw_h
init|=
name|hw_range_y_max
operator|-
name|hw_range_y_min
decl_stmt|;
name|tp
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|hw_x
operator|/
name|qreal
argument_list|(
name|hw_w
argument_list|)
argument_list|,
name|hw_y
operator|/
name|qreal
argument_list|(
name|hw_h
argument_list|)
argument_list|)
expr_stmt|;
name|qreal
name|nx
init|=
name|tp
operator|.
name|normalPosition
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|ny
init|=
name|tp
operator|.
name|normalPosition
operator|.
name|y
argument_list|()
decl_stmt|;
comment|// Generate a screen position that is always inside the active window or the default screen.
specifier|const
name|int
name|wx
init|=
name|winRect
operator|.
name|left
argument_list|()
operator|+
name|int
argument_list|(
name|nx
operator|*
name|winRect
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
name|wy
init|=
name|winRect
operator|.
name|top
argument_list|()
operator|+
name|int
argument_list|(
name|ny
operator|*
name|winRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|tp
operator|.
name|area
operator|.
name|moveTopLeft
argument_list|(
name|QPoint
argument_list|(
name|wx
argument_list|,
name|wy
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|POINT_DEBUG
name|qDebug
argument_list|()
operator|<<
literal|"    "
operator|<<
name|i
operator|<<
name|tp
operator|.
name|area
operator|<<
name|tp
operator|.
name|state
operator|<<
name|tp
operator|.
name|id
operator|<<
name|tp
operator|.
name|isPrimary
operator|<<
name|tp
operator|.
name|pressure
expr_stmt|;
endif|#
directive|endif
block|}
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
literal|0
argument_list|,
name|state
argument_list|,
name|QTouchEvent
operator|::
name|TouchScreen
argument_list|,
name|touchPoints
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
