begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"lightmaps.h"
end_include
begin_include
include|#
directive|include
file|"slippymap.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef
begin_define
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// how long (milliseconds) the user need to hold (after a tap on the screen)
end_comment
begin_comment
comment|// before triggering the magnifying glass feature
end_comment
begin_comment
comment|// 701, a prime number, is the sum of 229, 233, 239
end_comment
begin_comment
comment|// (all three are also prime numbers, consecutive!)
end_comment
begin_define
DECL|macro|HOLD_TIME
define|#
directive|define
name|HOLD_TIME
value|701
end_define
begin_comment
comment|// maximum size of the magnifier
end_comment
begin_comment
comment|// Hint: see above to find why I picked this one :)
end_comment
begin_define
DECL|macro|MAX_MAGNIFIER
define|#
directive|define
name|MAX_MAGNIFIER
value|229
end_define
begin_constructor
DECL|function|LightMaps
name|LightMaps
operator|::
name|LightMaps
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|pressed
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|snapped
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|zoomed
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|invert
argument_list|(
literal|false
argument_list|)
block|{
name|m_normalMap
operator|=
operator|new
name|SlippyMap
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_largeMap
operator|=
operator|new
name|SlippyMap
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_normalMap
argument_list|,
name|SIGNAL
argument_list|(
name|updated
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|updateMap
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_largeMap
argument_list|,
name|SIGNAL
argument_list|(
name|updated
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setCenter
name|void
name|LightMaps
operator|::
name|setCenter
parameter_list|(
name|qreal
name|lat
parameter_list|,
name|qreal
name|lng
parameter_list|)
block|{
name|m_normalMap
operator|->
name|latitude
operator|=
name|lat
expr_stmt|;
name|m_normalMap
operator|->
name|longitude
operator|=
name|lng
expr_stmt|;
name|m_normalMap
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|m_largeMap
operator|->
name|latitude
operator|=
name|lat
expr_stmt|;
name|m_largeMap
operator|->
name|longitude
operator|=
name|lng
expr_stmt|;
name|m_largeMap
operator|->
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toggleNightMode
name|void
name|LightMaps
operator|::
name|toggleNightMode
parameter_list|()
block|{
name|invert
operator|=
operator|!
name|invert
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMap
name|void
name|LightMaps
operator|::
name|updateMap
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
name|update
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activateZoom
name|void
name|LightMaps
operator|::
name|activateZoom
parameter_list|()
block|{
name|zoomed
operator|=
literal|true
expr_stmt|;
name|tapTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|m_largeMap
operator|->
name|zoom
operator|=
name|m_normalMap
operator|->
name|zoom
operator|+
literal|1
expr_stmt|;
name|m_largeMap
operator|->
name|width
operator|=
name|m_normalMap
operator|->
name|width
operator|*
literal|2
expr_stmt|;
name|m_largeMap
operator|->
name|height
operator|=
name|m_normalMap
operator|->
name|height
operator|*
literal|2
expr_stmt|;
name|m_largeMap
operator|->
name|latitude
operator|=
name|m_normalMap
operator|->
name|latitude
expr_stmt|;
name|m_largeMap
operator|->
name|longitude
operator|=
name|m_normalMap
operator|->
name|longitude
expr_stmt|;
name|m_largeMap
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|LightMaps
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|m_normalMap
operator|->
name|width
operator|=
name|width
argument_list|()
expr_stmt|;
name|m_normalMap
operator|->
name|height
operator|=
name|height
argument_list|()
expr_stmt|;
name|m_normalMap
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|m_largeMap
operator|->
name|width
operator|=
name|m_normalMap
operator|->
name|width
operator|*
literal|2
expr_stmt|;
name|m_largeMap
operator|->
name|height
operator|=
name|m_normalMap
operator|->
name|height
operator|*
literal|2
expr_stmt|;
name|m_largeMap
operator|->
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|LightMaps
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|p
decl_stmt|;
name|p
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_normalMap
operator|->
name|render
argument_list|(
operator|&
name|p
argument_list|,
name|event
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignBottom
operator||
name|Qt
operator|::
name|TextWordWrap
argument_list|,
literal|"Map data CCBYSA 2009 OpenStreetMap.org contributors"
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
if|if
condition|(
name|zoomed
condition|)
block|{
name|int
name|dim
init|=
name|qMin
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|magnifierSize
init|=
name|qMin
argument_list|(
name|MAX_MAGNIFIER
argument_list|,
name|dim
operator|*
literal|2
operator|/
literal|3
argument_list|)
decl_stmt|;
name|int
name|radius
init|=
name|magnifierSize
operator|/
literal|2
decl_stmt|;
name|int
name|ring
init|=
name|radius
operator|-
literal|15
decl_stmt|;
name|QSize
name|box
init|=
name|QSize
argument_list|(
name|magnifierSize
argument_list|,
name|magnifierSize
argument_list|)
decl_stmt|;
comment|// reupdate our mask
if|if
condition|(
name|maskPixmap
operator|.
name|size
argument_list|()
operator|!=
name|box
condition|)
block|{
name|maskPixmap
operator|=
name|QPixmap
argument_list|(
name|box
argument_list|)
expr_stmt|;
name|maskPixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QRadialGradient
name|g
decl_stmt|;
name|g
operator|.
name|setCenter
argument_list|(
name|radius
argument_list|,
name|radius
argument_list|)
expr_stmt|;
name|g
operator|.
name|setFocalPoint
argument_list|(
name|radius
argument_list|,
name|radius
argument_list|)
expr_stmt|;
name|g
operator|.
name|setRadius
argument_list|(
name|radius
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|g
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|QColor
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|QPainter
name|mask
argument_list|(
operator|&
name|maskPixmap
argument_list|)
decl_stmt|;
name|mask
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setBrush
argument_list|(
name|g
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|mask
operator|.
name|drawRect
argument_list|(
name|maskPixmap
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|mask
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
argument_list|)
expr_stmt|;
name|mask
operator|.
name|drawEllipse
argument_list|(
name|g
operator|.
name|center
argument_list|()
argument_list|,
name|ring
argument_list|,
name|ring
argument_list|)
expr_stmt|;
name|mask
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
name|QPoint
name|center
init|=
name|dragPos
operator|-
name|QPoint
argument_list|(
literal|0
argument_list|,
name|radius
argument_list|)
decl_stmt|;
name|center
operator|=
name|center
operator|+
name|QPoint
argument_list|(
literal|0
argument_list|,
name|radius
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QPoint
name|corner
init|=
name|center
operator|-
name|QPoint
argument_list|(
name|radius
argument_list|,
name|radius
argument_list|)
decl_stmt|;
name|QPoint
name|xy
init|=
name|center
operator|*
literal|2
operator|-
name|QPoint
argument_list|(
name|radius
argument_list|,
name|radius
argument_list|)
decl_stmt|;
comment|// only set the dimension to the magnified portion
if|if
condition|(
name|zoomPixmap
operator|.
name|size
argument_list|()
operator|!=
name|box
condition|)
block|{
name|zoomPixmap
operator|=
name|QPixmap
argument_list|(
name|box
argument_list|)
expr_stmt|;
name|zoomPixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|lightGray
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
literal|true
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|zoomPixmap
argument_list|)
decl_stmt|;
name|p
operator|.
name|translate
argument_list|(
operator|-
name|xy
argument_list|)
expr_stmt|;
name|m_largeMap
operator|->
name|render
argument_list|(
operator|&
name|p
argument_list|,
name|QRect
argument_list|(
name|xy
argument_list|,
name|box
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
name|QPainterPath
name|clipPath
decl_stmt|;
name|clipPath
operator|.
name|addEllipse
argument_list|(
name|center
argument_list|,
name|ring
argument_list|,
name|ring
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|p
operator|.
name|setClipPath
argument_list|(
name|clipPath
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|corner
argument_list|,
name|zoomPixmap
argument_list|)
expr_stmt|;
name|p
operator|.
name|setClipping
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|corner
argument_list|,
name|maskPixmap
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|clipPath
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|invert
condition|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Difference
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|LightMaps
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
operator|!
name|zoomed
condition|)
name|activateZoom
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|LightMaps
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|buttons
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftButton
condition|)
return|return;
name|pressed
operator|=
name|snapped
operator|=
literal|true
expr_stmt|;
name|pressPos
operator|=
name|dragPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|tapTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|tapTimer
operator|.
name|start
argument_list|(
name|HOLD_TIME
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|LightMaps
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|event
operator|->
name|buttons
argument_list|()
condition|)
return|return;
if|if
condition|(
operator|!
name|zoomed
condition|)
block|{
if|if
condition|(
operator|!
name|pressed
operator|||
operator|!
name|snapped
condition|)
block|{
name|QPoint
name|delta
init|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|pressPos
decl_stmt|;
name|pressPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|m_normalMap
operator|->
name|pan
argument_list|(
name|delta
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
specifier|const
name|int
name|threshold
init|=
literal|10
decl_stmt|;
name|QPoint
name|delta
init|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|pressPos
decl_stmt|;
if|if
condition|(
name|snapped
condition|)
block|{
name|snapped
operator|&=
name|delta
operator|.
name|x
argument_list|()
operator|<
name|threshold
expr_stmt|;
name|snapped
operator|&=
name|delta
operator|.
name|y
argument_list|()
operator|<
name|threshold
expr_stmt|;
name|snapped
operator|&=
name|delta
operator|.
name|x
argument_list|()
operator|>
operator|-
name|threshold
expr_stmt|;
name|snapped
operator|&=
name|delta
operator|.
name|y
argument_list|()
operator|>
operator|-
name|threshold
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|snapped
condition|)
name|tapTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|dragPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|LightMaps
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|zoomed
operator|=
literal|false
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyPressEvent
name|void
name|LightMaps
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|zoomed
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Left
condition|)
name|m_normalMap
operator|->
name|pan
argument_list|(
name|QPoint
argument_list|(
literal|20
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Right
condition|)
name|m_normalMap
operator|->
name|pan
argument_list|(
name|QPoint
argument_list|(
operator|-
literal|20
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
name|m_normalMap
operator|->
name|pan
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
name|m_normalMap
operator|->
name|pan
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|20
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Z
operator|||
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Select
condition|)
block|{
name|dragPos
operator|=
name|QPoint
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|activateZoom
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Z
operator|||
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Select
condition|)
block|{
name|zoomed
operator|=
literal|false
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
name|QPoint
name|delta
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Left
condition|)
name|delta
operator|=
name|QPoint
argument_list|(
operator|-
literal|15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Right
condition|)
name|delta
operator|=
name|QPoint
argument_list|(
literal|15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
name|delta
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|15
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
name|delta
operator|=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|15
argument_list|)
expr_stmt|;
if|if
condition|(
name|delta
operator|!=
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|dragPos
operator|+=
name|delta
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
