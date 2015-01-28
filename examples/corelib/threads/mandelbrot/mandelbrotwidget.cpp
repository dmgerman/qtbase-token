begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QKeyEvent>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"mandelbrotwidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|DefaultCenterX
specifier|const
name|double
name|DefaultCenterX
init|=
operator|-
literal|0.637011f
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DefaultCenterY
specifier|const
name|double
name|DefaultCenterY
init|=
operator|-
literal|0.0395159f
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DefaultScale
specifier|const
name|double
name|DefaultScale
init|=
literal|0.00403897f
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ZoomInFactor
specifier|const
name|double
name|ZoomInFactor
init|=
literal|0.8f
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ZoomOutFactor
specifier|const
name|double
name|ZoomOutFactor
init|=
literal|1
operator|/
name|ZoomInFactor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ScrollStep
specifier|const
name|int
name|ScrollStep
init|=
literal|20
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|MandelbrotWidget
name|MandelbrotWidget
operator|::
name|MandelbrotWidget
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
block|{
name|centerX
operator|=
name|DefaultCenterX
expr_stmt|;
name|centerY
operator|=
name|DefaultCenterY
expr_stmt|;
name|pixmapScale
operator|=
name|DefaultScale
expr_stmt|;
name|curScale
operator|=
name|DefaultScale
expr_stmt|;
name|connect
argument_list|(
operator|&
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|renderedImage
argument_list|(
name|QImage
argument_list|,
name|double
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updatePixmap
argument_list|(
name|QImage
argument_list|,
name|double
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Mandelbrot"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|CrossCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|resize
argument_list|(
literal|550
argument_list|,
literal|400
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|MandelbrotWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|black
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
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|tr
argument_list|(
literal|"Rendering initial image, please wait..."
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [2] //! [3]
return|return;
comment|//! [3] //! [4]
block|}
comment|//! [4]
comment|//! [5]
if|if
condition|(
name|curScale
operator|==
name|pixmapScale
condition|)
block|{
comment|//! [5] //! [6]
name|painter
operator|.
name|drawPixmap
argument_list|(
name|pixmapOffset
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
block|}
else|else
block|{
comment|//! [7] //! [8]
name|double
name|scaleFactor
init|=
name|pixmapScale
operator|/
name|curScale
decl_stmt|;
name|int
name|newWidth
init|=
name|int
argument_list|(
name|pixmap
operator|.
name|width
argument_list|()
operator|*
name|scaleFactor
argument_list|)
decl_stmt|;
name|int
name|newHeight
init|=
name|int
argument_list|(
name|pixmap
operator|.
name|height
argument_list|()
operator|*
name|scaleFactor
argument_list|)
decl_stmt|;
name|int
name|newX
init|=
name|pixmapOffset
operator|.
name|x
argument_list|()
operator|+
operator|(
name|pixmap
operator|.
name|width
argument_list|()
operator|-
name|newWidth
operator|)
operator|/
literal|2
decl_stmt|;
name|int
name|newY
init|=
name|pixmapOffset
operator|.
name|y
argument_list|()
operator|+
operator|(
name|pixmap
operator|.
name|height
argument_list|()
operator|-
name|newHeight
operator|)
operator|/
literal|2
decl_stmt|;
name|painter
operator|.
name|save
argument_list|()
expr_stmt|;
name|painter
operator|.
name|translate
argument_list|(
name|newX
argument_list|,
name|newY
argument_list|)
expr_stmt|;
name|painter
operator|.
name|scale
argument_list|(
name|scaleFactor
argument_list|,
name|scaleFactor
argument_list|)
expr_stmt|;
name|QRectF
name|exposed
init|=
name|painter
operator|.
name|matrix
argument_list|()
operator|.
name|inverted
argument_list|()
operator|.
name|mapRect
argument_list|(
name|rect
argument_list|()
argument_list|)
operator|.
name|adjusted
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
name|exposed
argument_list|,
name|pixmap
argument_list|,
name|exposed
argument_list|)
expr_stmt|;
name|painter
operator|.
name|restore
argument_list|()
expr_stmt|;
block|}
comment|//! [8] //! [9]
name|QString
name|text
init|=
name|tr
argument_list|(
literal|"Use mouse wheel or the '+' and '-' keys to zoom. "
literal|"Press and hold left mouse button to scroll."
argument_list|)
decl_stmt|;
name|QFontMetrics
name|metrics
init|=
name|painter
operator|.
name|fontMetrics
argument_list|()
decl_stmt|;
name|int
name|textWidth
init|=
name|metrics
operator|.
name|width
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
operator|(
name|width
argument_list|()
operator|-
name|textWidth
operator|)
operator|/
literal|2
operator|-
literal|5
argument_list|,
literal|0
argument_list|,
name|textWidth
operator|+
literal|10
argument_list|,
name|metrics
operator|.
name|lineSpacing
argument_list|()
operator|+
literal|5
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
operator|(
name|width
argument_list|()
operator|-
name|textWidth
operator|)
operator|/
literal|2
argument_list|,
name|metrics
operator|.
name|leading
argument_list|()
operator|+
name|metrics
operator|.
name|ascent
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|MandelbrotWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|thread
operator|.
name|render
argument_list|(
name|centerX
argument_list|,
name|centerY
argument_list|,
name|curScale
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|keyPressEvent
name|void
name|MandelbrotWidget
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Plus
case|:
name|zoom
argument_list|(
name|ZoomInFactor
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Minus
case|:
name|zoom
argument_list|(
name|ZoomOutFactor
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Left
case|:
name|scroll
argument_list|(
operator|-
name|ScrollStep
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Right
case|:
name|scroll
argument_list|(
operator|+
name|ScrollStep
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Down
case|:
name|scroll
argument_list|(
literal|0
argument_list|,
operator|-
name|ScrollStep
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|Key_Up
case|:
name|scroll
argument_list|(
literal|0
argument_list|,
operator|+
name|ScrollStep
argument_list|)
expr_stmt|;
break|break;
default|default:
name|QWidget
operator|::
name|keyPressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|wheelEvent
name|void
name|MandelbrotWidget
operator|::
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|numDegrees
init|=
name|event
operator|->
name|delta
argument_list|()
operator|/
literal|8
decl_stmt|;
name|double
name|numSteps
init|=
name|numDegrees
operator|/
literal|15.0f
decl_stmt|;
name|zoom
argument_list|(
name|pow
argument_list|(
name|ZoomInFactor
argument_list|,
name|numSteps
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|MandelbrotWidget
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
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|lastDragPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|MandelbrotWidget
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
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|pixmapOffset
operator|+=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|lastDragPos
expr_stmt|;
name|lastDragPos
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
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|MandelbrotWidget
operator|::
name|mouseReleaseEvent
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
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|pixmapOffset
operator|+=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|lastDragPos
expr_stmt|;
name|lastDragPos
operator|=
name|QPoint
argument_list|()
expr_stmt|;
name|int
name|deltaX
init|=
operator|(
name|width
argument_list|()
operator|-
name|pixmap
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
operator|-
name|pixmapOffset
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|deltaY
init|=
operator|(
name|height
argument_list|()
operator|-
name|pixmap
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
operator|-
name|pixmapOffset
operator|.
name|y
argument_list|()
decl_stmt|;
name|scroll
argument_list|(
name|deltaX
argument_list|,
name|deltaY
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_function
DECL|function|updatePixmap
name|void
name|MandelbrotWidget
operator|::
name|updatePixmap
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|double
name|scaleFactor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|lastDragPos
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|pixmap
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|pixmapOffset
operator|=
name|QPoint
argument_list|()
expr_stmt|;
name|lastDragPos
operator|=
name|QPoint
argument_list|()
expr_stmt|;
name|pixmapScale
operator|=
name|scaleFactor
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_function
DECL|function|zoom
name|void
name|MandelbrotWidget
operator|::
name|zoom
parameter_list|(
name|double
name|zoomFactor
parameter_list|)
block|{
name|curScale
operator|*=
name|zoomFactor
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|thread
operator|.
name|render
argument_list|(
name|centerX
argument_list|,
name|centerY
argument_list|,
name|curScale
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_function
DECL|function|scroll
name|void
name|MandelbrotWidget
operator|::
name|scroll
parameter_list|(
name|int
name|deltaX
parameter_list|,
name|int
name|deltaY
parameter_list|)
block|{
name|centerX
operator|+=
name|deltaX
operator|*
name|curScale
expr_stmt|;
name|centerY
operator|+=
name|deltaY
operator|*
name|curScale
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|thread
operator|.
name|render
argument_list|(
name|centerX
argument_list|,
name|centerY
argument_list|,
name|curScale
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [18]
end_comment
end_unit
