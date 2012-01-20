begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"customproxy.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_constructor
DECL|function|CustomProxy
name|CustomProxy
operator|::
name|CustomProxy
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|wFlags
parameter_list|)
member_init_list|:
name|QGraphicsProxyWidget
argument_list|(
name|parent
argument_list|,
name|wFlags
argument_list|)
member_init_list|,
name|popupShown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|currentPopup
argument_list|(
literal|0
argument_list|)
block|{
name|timeLine
operator|=
operator|new
name|QTimeLine
argument_list|(
literal|250
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timeLine
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|qreal
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateStep
argument_list|(
name|qreal
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timeLine
argument_list|,
name|SIGNAL
argument_list|(
name|stateChanged
argument_list|(
name|QTimeLine
operator|::
name|State
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stateChanged
argument_list|(
name|QTimeLine
operator|::
name|State
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|boundingRect
name|QRectF
name|CustomProxy
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QGraphicsProxyWidget
operator|::
name|boundingRect
argument_list|()
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintWindowFrame
name|void
name|CustomProxy
operator|::
name|paintWindowFrame
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
specifier|const
name|QColor
name|color
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
decl_stmt|;
name|QRectF
name|r
init|=
name|windowFrameRect
argument_list|()
decl_stmt|;
name|QRectF
name|right
argument_list|(
name|r
operator|.
name|right
argument_list|()
argument_list|,
name|r
operator|.
name|top
argument_list|()
operator|+
literal|10
argument_list|,
literal|10
argument_list|,
name|r
operator|.
name|height
argument_list|()
operator|-
literal|10
argument_list|)
decl_stmt|;
name|QRectF
name|bottom
argument_list|(
name|r
operator|.
name|left
argument_list|()
operator|+
literal|10
argument_list|,
name|r
operator|.
name|bottom
argument_list|()
argument_list|,
name|r
operator|.
name|width
argument_list|()
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|bool
name|intersectsRight
init|=
name|right
operator|.
name|intersects
argument_list|(
name|option
operator|->
name|exposedRect
argument_list|)
decl_stmt|;
name|bool
name|intersectsBottom
init|=
name|bottom
operator|.
name|intersects
argument_list|(
name|option
operator|->
name|exposedRect
argument_list|)
decl_stmt|;
if|if
condition|(
name|intersectsRight
operator|&&
name|intersectsBottom
condition|)
block|{
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
name|right
argument_list|)
expr_stmt|;
name|path
operator|.
name|addRect
argument_list|(
name|bottom
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|intersectsBottom
condition|)
block|{
name|painter
operator|->
name|fillRect
argument_list|(
name|bottom
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|intersectsRight
condition|)
block|{
name|painter
operator|->
name|fillRect
argument_list|(
name|right
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
name|QGraphicsProxyWidget
operator|::
name|paintWindowFrame
argument_list|(
name|painter
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hoverEnterEvent
name|void
name|CustomProxy
operator|::
name|hoverEnterEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsProxyWidget
operator|::
name|hoverEnterEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|scene
argument_list|()
operator|->
name|setActiveWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|timeLine
operator|->
name|currentValue
argument_list|()
operator|!=
literal|1
condition|)
name|zoomIn
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hoverLeaveEvent
name|void
name|CustomProxy
operator|::
name|hoverLeaveEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsProxyWidget
operator|::
name|hoverLeaveEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|popupShown
operator|&&
operator|(
name|timeLine
operator|->
name|direction
argument_list|()
operator|!=
name|QTimeLine
operator|::
name|Backward
operator|||
name|timeLine
operator|->
name|currentValue
argument_list|()
operator|!=
literal|0
operator|)
condition|)
name|zoomOut
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sceneEventFilter
name|bool
name|CustomProxy
operator|::
name|sceneEventFilter
parameter_list|(
name|QGraphicsItem
modifier|*
name|watched
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|watched
operator|->
name|isWindow
argument_list|()
operator|&&
operator|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|UngrabMouse
operator|||
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|GrabMouse
operator|)
condition|)
block|{
name|popupShown
operator|=
name|watched
operator|->
name|isVisible
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|popupShown
operator|&&
operator|!
name|isUnderMouse
argument_list|()
condition|)
name|zoomOut
argument_list|()
expr_stmt|;
block|}
return|return
name|QGraphicsProxyWidget
operator|::
name|sceneEventFilter
argument_list|(
name|watched
argument_list|,
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|itemChange
name|QVariant
name|CustomProxy
operator|::
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|change
operator|==
name|ItemChildAddedChange
operator|||
name|change
operator|==
name|ItemChildRemovedChange
condition|)
block|{
if|if
condition|(
name|change
operator|==
name|ItemChildAddedChange
condition|)
block|{
name|currentPopup
operator|=
name|qvariant_cast
argument_list|<
name|QGraphicsItem
operator|*
argument_list|>
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|currentPopup
operator|->
name|setCacheMode
argument_list|(
name|ItemCoordinateCache
argument_list|)
expr_stmt|;
if|if
condition|(
name|scene
argument_list|()
condition|)
name|currentPopup
operator|->
name|installSceneEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|scene
argument_list|()
condition|)
block|{
name|currentPopup
operator|->
name|removeSceneEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|currentPopup
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|currentPopup
operator|&&
name|change
operator|==
name|ItemSceneHasChanged
condition|)
block|{
name|currentPopup
operator|->
name|installSceneEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
return|return
name|QGraphicsProxyWidget
operator|::
name|itemChange
argument_list|(
name|change
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|updateStep
name|void
name|CustomProxy
operator|::
name|updateStep
parameter_list|(
name|qreal
name|step
parameter_list|)
block|{
name|QRectF
name|r
init|=
name|boundingRect
argument_list|()
decl_stmt|;
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|translate
argument_list|(
name|r
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|r
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
operator|.
name|rotate
argument_list|(
name|step
operator|*
literal|30
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
operator|.
name|rotate
argument_list|(
name|step
operator|*
literal|10
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
operator|.
name|rotate
argument_list|(
name|step
operator|*
literal|5
argument_list|,
name|Qt
operator|::
name|ZAxis
argument_list|)
operator|.
name|scale
argument_list|(
literal|1
operator|+
literal|1.5
operator|*
name|step
argument_list|,
literal|1
operator|+
literal|1.5
operator|*
name|step
argument_list|)
operator|.
name|translate
argument_list|(
operator|-
name|r
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
operator|-
name|r
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stateChanged
name|void
name|CustomProxy
operator|::
name|stateChanged
parameter_list|(
name|QTimeLine
operator|::
name|State
name|state
parameter_list|)
block|{
if|if
condition|(
name|state
operator|==
name|QTimeLine
operator|::
name|Running
condition|)
block|{
if|if
condition|(
name|timeLine
operator|->
name|direction
argument_list|()
operator|==
name|QTimeLine
operator|::
name|Forward
condition|)
name|setCacheMode
argument_list|(
name|ItemCoordinateCache
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|state
operator|==
name|QTimeLine
operator|::
name|NotRunning
condition|)
block|{
if|if
condition|(
name|timeLine
operator|->
name|direction
argument_list|()
operator|==
name|QTimeLine
operator|::
name|Backward
condition|)
name|setCacheMode
argument_list|(
name|DeviceCoordinateCache
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|zoomIn
name|void
name|CustomProxy
operator|::
name|zoomIn
parameter_list|()
block|{
if|if
condition|(
name|timeLine
operator|->
name|direction
argument_list|()
operator|!=
name|QTimeLine
operator|::
name|Forward
condition|)
name|timeLine
operator|->
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Forward
argument_list|)
expr_stmt|;
if|if
condition|(
name|timeLine
operator|->
name|state
argument_list|()
operator|==
name|QTimeLine
operator|::
name|NotRunning
condition|)
name|timeLine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zoomOut
name|void
name|CustomProxy
operator|::
name|zoomOut
parameter_list|()
block|{
if|if
condition|(
name|timeLine
operator|->
name|direction
argument_list|()
operator|!=
name|QTimeLine
operator|::
name|Backward
condition|)
name|timeLine
operator|->
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Backward
argument_list|)
expr_stmt|;
if|if
condition|(
name|timeLine
operator|->
name|state
argument_list|()
operator|==
name|QTimeLine
operator|::
name|NotRunning
condition|)
name|timeLine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
