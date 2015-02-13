begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"robot.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|RobotPart
name|RobotPart
operator|::
name|RobotPart
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|color
argument_list|(
name|Qt
operator|::
name|lightGray
argument_list|)
member_init_list|,
name|dragOver
argument_list|(
literal|false
argument_list|)
block|{
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|dragEnterEvent
name|void
name|RobotPart
operator|::
name|dragEnterEvent
parameter_list|(
name|QGraphicsSceneDragDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasColor
argument_list|()
condition|)
block|{
name|event
operator|->
name|setAccepted
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|dragOver
operator|=
literal|true
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|event
operator|->
name|setAccepted
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|dragLeaveEvent
name|void
name|RobotPart
operator|::
name|dragLeaveEvent
parameter_list|(
name|QGraphicsSceneDragDropEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|dragOver
operator|=
literal|false
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|dropEvent
name|void
name|RobotPart
operator|::
name|dropEvent
parameter_list|(
name|QGraphicsSceneDragDropEvent
modifier|*
name|event
parameter_list|)
block|{
name|dragOver
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasColor
argument_list|()
condition|)
name|color
operator|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|colorData
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_constructor
DECL|function|RobotHead
name|RobotHead
operator|::
name|RobotHead
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|RobotPart
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|RobotHead
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|15
argument_list|,
operator|-
literal|50
argument_list|,
literal|30
argument_list|,
literal|50
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|paint
name|void
name|RobotHead
operator|::
name|paint
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
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
if|if
condition|(
name|pixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|painter
operator|->
name|setBrush
argument_list|(
name|dragOver
condition|?
name|color
operator|.
name|light
argument_list|(
literal|130
argument_list|)
else|:
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|30
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|25
argument_list|,
literal|25
argument_list|,
name|Qt
operator|::
name|RelativeSize
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|7
argument_list|,
operator|-
literal|3
operator|-
literal|20
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|0
argument_list|,
operator|-
literal|3
operator|-
literal|20
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|5
argument_list|,
operator|-
literal|1
operator|-
literal|20
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|2
argument_list|,
operator|-
literal|1
operator|-
literal|20
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawArc
argument_list|(
operator|-
literal|6
argument_list|,
operator|-
literal|2
operator|-
literal|20
argument_list|,
literal|12
argument_list|,
literal|15
argument_list|,
literal|190
operator|*
literal|16
argument_list|,
literal|160
operator|*
literal|16
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|painter
operator|->
name|scale
argument_list|(
literal|.2272
argument_list|,
literal|.2824
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|15
operator|*
literal|4.4
argument_list|,
operator|-
literal|50
operator|*
literal|3.54
argument_list|)
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|dragEnterEvent
name|void
name|RobotHead
operator|::
name|dragEnterEvent
parameter_list|(
name|QGraphicsSceneDragDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|event
operator|->
name|setAccepted
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|dragOver
operator|=
literal|true
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|RobotPart
operator|::
name|dragEnterEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|dropEvent
name|void
name|RobotHead
operator|::
name|dropEvent
parameter_list|(
name|QGraphicsSceneDragDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|dragOver
operator|=
literal|false
expr_stmt|;
name|pixmap
operator|=
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|imageData
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|RobotPart
operator|::
name|dropEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_constructor
DECL|function|RobotTorso
name|RobotTorso
operator|::
name|RobotTorso
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|RobotPart
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|boundingRect
name|QRectF
name|RobotTorso
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|30
argument_list|,
operator|-
literal|20
argument_list|,
literal|60
argument_list|,
literal|60
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|RobotTorso
operator|::
name|paint
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
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|dragOver
condition|?
name|color
operator|.
name|light
argument_list|(
literal|130
argument_list|)
else|:
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
operator|-
literal|20
argument_list|,
operator|-
literal|20
argument_list|,
literal|40
argument_list|,
literal|60
argument_list|,
literal|25
argument_list|,
literal|25
argument_list|,
name|Qt
operator|::
name|RelativeSize
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|25
argument_list|,
operator|-
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|5
argument_list|,
operator|-
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|20
argument_list|,
literal|22
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
literal|0
argument_list|,
literal|22
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|RobotLimb
name|RobotLimb
operator|::
name|RobotLimb
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|RobotPart
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|boundingRect
name|QRectF
name|RobotLimb
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
literal|40
argument_list|,
literal|10
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|RobotLimb
operator|::
name|paint
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
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|dragOver
condition|?
name|color
operator|.
name|light
argument_list|(
literal|130
argument_list|)
else|:
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
name|Qt
operator|::
name|RelativeSize
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_constructor
DECL|function|Robot
name|Robot
operator|::
name|Robot
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|RobotPart
argument_list|(
name|parent
argument_list|)
block|{
name|setFlag
argument_list|(
name|ItemHasNoContents
argument_list|)
expr_stmt|;
name|QGraphicsObject
modifier|*
name|torsoItem
init|=
operator|new
name|RobotTorso
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|headItem
init|=
operator|new
name|RobotHead
argument_list|(
name|torsoItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|upperLeftArmItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|torsoItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|lowerLeftArmItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|upperLeftArmItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|upperRightArmItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|torsoItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|lowerRightArmItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|upperRightArmItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|upperRightLegItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|torsoItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|lowerRightLegItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|upperRightLegItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|upperLeftLegItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|torsoItem
argument_list|)
decl_stmt|;
name|QGraphicsObject
modifier|*
name|lowerLeftLegItem
init|=
operator|new
name|RobotLimb
argument_list|(
name|upperLeftLegItem
argument_list|)
decl_stmt|;
comment|//! [10]
comment|//! [11]
name|headItem
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
operator|-
literal|18
argument_list|)
expr_stmt|;
name|upperLeftArmItem
operator|->
name|setPos
argument_list|(
operator|-
literal|15
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|lowerLeftArmItem
operator|->
name|setPos
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|upperRightArmItem
operator|->
name|setPos
argument_list|(
literal|15
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|lowerRightArmItem
operator|->
name|setPos
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|upperRightLegItem
operator|->
name|setPos
argument_list|(
literal|10
argument_list|,
literal|32
argument_list|)
expr_stmt|;
name|lowerRightLegItem
operator|->
name|setPos
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|upperLeftLegItem
operator|->
name|setPos
argument_list|(
operator|-
literal|10
argument_list|,
literal|32
argument_list|)
expr_stmt|;
name|lowerLeftLegItem
operator|->
name|setPos
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|QParallelAnimationGroup
modifier|*
name|animation
init|=
operator|new
name|QParallelAnimationGroup
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|headAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|headItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|headAnimation
operator|->
name|setStartValue
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|headAnimation
operator|->
name|setEndValue
argument_list|(
operator|-
literal|20
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|headScaleAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|headItem
argument_list|,
literal|"scale"
argument_list|)
decl_stmt|;
name|headScaleAnimation
operator|->
name|setEndValue
argument_list|(
literal|1.1
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|headAnimation
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|headScaleAnimation
argument_list|)
expr_stmt|;
comment|//! [12]
name|QPropertyAnimation
modifier|*
name|upperLeftArmAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|upperLeftArmItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|upperLeftArmAnimation
operator|->
name|setStartValue
argument_list|(
literal|190
argument_list|)
expr_stmt|;
name|upperLeftArmAnimation
operator|->
name|setEndValue
argument_list|(
literal|180
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|upperLeftArmAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|lowerLeftArmAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|lowerLeftArmItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|lowerLeftArmAnimation
operator|->
name|setStartValue
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|lowerLeftArmAnimation
operator|->
name|setEndValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|lowerLeftArmAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|upperRightArmAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|upperRightArmItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|upperRightArmAnimation
operator|->
name|setStartValue
argument_list|(
literal|300
argument_list|)
expr_stmt|;
name|upperRightArmAnimation
operator|->
name|setEndValue
argument_list|(
literal|310
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|upperRightArmAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|lowerRightArmAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|lowerRightArmItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|lowerRightArmAnimation
operator|->
name|setStartValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|lowerRightArmAnimation
operator|->
name|setEndValue
argument_list|(
operator|-
literal|70
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|lowerRightArmAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|upperLeftLegAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|upperLeftLegItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|upperLeftLegAnimation
operator|->
name|setStartValue
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|upperLeftLegAnimation
operator|->
name|setEndValue
argument_list|(
literal|80
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|upperLeftLegAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|lowerLeftLegAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|lowerLeftLegItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|lowerLeftLegAnimation
operator|->
name|setStartValue
argument_list|(
literal|70
argument_list|)
expr_stmt|;
name|lowerLeftLegAnimation
operator|->
name|setEndValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|lowerLeftLegAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|upperRightLegAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|upperRightLegItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|upperRightLegAnimation
operator|->
name|setStartValue
argument_list|(
literal|40
argument_list|)
expr_stmt|;
name|upperRightLegAnimation
operator|->
name|setEndValue
argument_list|(
literal|120
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|upperRightLegAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|lowerRightLegAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|lowerRightLegItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|lowerRightLegAnimation
operator|->
name|setStartValue
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|lowerRightLegAnimation
operator|->
name|setEndValue
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|lowerRightLegAnimation
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|torsoAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|torsoItem
argument_list|,
literal|"rotation"
argument_list|)
decl_stmt|;
name|torsoAnimation
operator|->
name|setStartValue
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|torsoAnimation
operator|->
name|setEndValue
argument_list|(
operator|-
literal|20
argument_list|)
expr_stmt|;
name|animation
operator|->
name|addAnimation
argument_list|(
name|torsoAnimation
argument_list|)
expr_stmt|;
comment|//! [13]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|animation
operator|->
name|animationCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPropertyAnimation
modifier|*
name|anim
init|=
name|qobject_cast
argument_list|<
name|QPropertyAnimation
operator|*
argument_list|>
argument_list|(
name|animation
operator|->
name|animationAt
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|SineCurve
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|2000
argument_list|)
expr_stmt|;
block|}
name|animation
operator|->
name|setLoopCount
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|animation
operator|->
name|start
argument_list|()
expr_stmt|;
comment|//! [13]
block|}
end_constructor
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|Robot
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|Robot
operator|::
name|paint
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
name|Q_UNUSED
argument_list|(
name|painter
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
end_unit
