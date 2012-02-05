begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|"bubble.h"
end_include
begin_include
include|#
directive|include
file|"qtlogo.h"
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_MULTISAMPLE
end_ifndef
begin_define
DECL|macro|GL_MULTISAMPLE
define|#
directive|define
name|GL_MULTISAMPLE
value|0x809D
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|GLWidget
name|GLWidget
operator|::
name|GLWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|QTime
name|midnight
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|qsrand
argument_list|(
name|midnight
operator|.
name|secsTo
argument_list|(
name|QTime
operator|::
name|currentTime
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|logo
operator|=
literal|0
expr_stmt|;
name|xRot
operator|=
literal|0
expr_stmt|;
name|yRot
operator|=
literal|0
expr_stmt|;
name|zRot
operator|=
literal|0
expr_stmt|;
name|qtGreen
operator|=
name|QColor
operator|::
name|fromCmykF
argument_list|(
literal|0.40
argument_list|,
literal|0.0
argument_list|,
literal|1.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|qtPurple
operator|=
name|QColor
operator|::
name|fromCmykF
argument_list|(
literal|0.39
argument_list|,
literal|0.39
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|animationTimer
operator|.
name|setSingleShot
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|animationTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|animate
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|animationTimer
operator|.
name|start
argument_list|(
literal|25
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Overpainting a Scene"
argument_list|)
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
begin_destructor
DECL|function|~GLWidget
name|GLWidget
operator|::
name|~
name|GLWidget
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|qNormalizeAngle
specifier|static
name|void
name|qNormalizeAngle
parameter_list|(
name|int
modifier|&
name|angle
parameter_list|)
block|{
while|while
condition|(
name|angle
operator|<
literal|0
condition|)
name|angle
operator|+=
literal|360
operator|*
literal|16
expr_stmt|;
while|while
condition|(
name|angle
operator|>
literal|360
operator|*
literal|16
condition|)
name|angle
operator|-=
literal|360
operator|*
literal|16
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setXRotation
name|void
name|GLWidget
operator|::
name|setXRotation
parameter_list|(
name|int
name|angle
parameter_list|)
block|{
name|qNormalizeAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
if|if
condition|(
name|angle
operator|!=
name|xRot
condition|)
name|xRot
operator|=
name|angle
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setYRotation
name|void
name|GLWidget
operator|::
name|setYRotation
parameter_list|(
name|int
name|angle
parameter_list|)
block|{
name|qNormalizeAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
if|if
condition|(
name|angle
operator|!=
name|yRot
condition|)
name|yRot
operator|=
name|angle
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setZRotation
name|void
name|GLWidget
operator|::
name|setZRotation
parameter_list|(
name|int
name|angle
parameter_list|)
block|{
name|qNormalizeAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
if|if
condition|(
name|angle
operator|!=
name|zRot
condition|)
name|zRot
operator|=
name|angle
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|initializeGL
name|void
name|GLWidget
operator|::
name|initializeGL
parameter_list|()
block|{
name|glEnable
argument_list|(
name|GL_MULTISAMPLE
argument_list|)
expr_stmt|;
name|logo
operator|=
operator|new
name|QtLogo
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|logo
operator|->
name|setColor
argument_list|(
name|qtGreen
operator|.
name|dark
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|GLWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|GLWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|dx
init|=
name|event
operator|->
name|x
argument_list|()
operator|-
name|lastPos
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|dy
init|=
name|event
operator|->
name|y
argument_list|()
operator|-
name|lastPos
operator|.
name|y
argument_list|()
decl_stmt|;
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
name|setXRotation
argument_list|(
name|xRot
operator|+
literal|8
operator|*
name|dy
argument_list|)
expr_stmt|;
name|setYRotation
argument_list|(
name|yRot
operator|+
literal|8
operator|*
name|dx
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|RightButton
condition|)
block|{
name|setXRotation
argument_list|(
name|xRot
operator|+
literal|8
operator|*
name|dy
argument_list|)
expr_stmt|;
name|setZRotation
argument_list|(
name|zRot
operator|+
literal|8
operator|*
name|dx
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|GLWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|makeCurrent
argument_list|()
expr_stmt|;
comment|//! [4]
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glPushMatrix
argument_list|()
expr_stmt|;
comment|//! [4]
comment|//! [6]
name|qglClearColor
argument_list|(
name|qtPurple
operator|.
name|dark
argument_list|()
argument_list|)
expr_stmt|;
name|glShadeModel
argument_list|(
name|GL_SMOOTH
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHT0
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_MULTISAMPLE
argument_list|)
expr_stmt|;
specifier|static
name|GLfloat
name|lightPosition
index|[
literal|4
index|]
init|=
block|{
literal|0.5
block|,
literal|5.0
block|,
literal|7.0
block|,
literal|1.0
block|}
decl_stmt|;
name|glLightfv
argument_list|(
name|GL_LIGHT0
argument_list|,
name|GL_POSITION
argument_list|,
name|lightPosition
argument_list|)
expr_stmt|;
name|setupViewport
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
operator|-
literal|10.0
argument_list|)
expr_stmt|;
name|glRotatef
argument_list|(
name|xRot
operator|/
literal|16.0
argument_list|,
literal|1.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|glRotatef
argument_list|(
name|yRot
operator|/
literal|16.0
argument_list|,
literal|0.0
argument_list|,
literal|1.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|glRotatef
argument_list|(
name|zRot
operator|/
literal|16.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
name|logo
operator|->
name|draw
argument_list|()
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|glShadeModel
argument_list|(
name|GL_FLAT
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
comment|//! [8]
comment|//! [10]
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|Bubble
modifier|*
name|bubble
decl|,
name|bubbles
control|)
block|{
if|if
condition|(
name|bubble
operator|->
name|rect
argument_list|()
operator|.
name|intersects
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|)
condition|)
name|bubble
operator|->
name|drawBubble
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
name|drawInstructions
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
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
DECL|function|resizeGL
name|void
name|GLWidget
operator|::
name|resizeGL
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|setupViewport
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|showEvent
name|void
name|GLWidget
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|createBubbles
argument_list|(
literal|20
operator|-
name|bubbles
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|GLWidget
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createBubbles
name|void
name|GLWidget
operator|::
name|createBubbles
parameter_list|(
name|int
name|number
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|number
condition|;
operator|++
name|i
control|)
block|{
name|QPointF
name|position
argument_list|(
name|width
argument_list|()
operator|*
operator|(
literal|0.1
operator|+
operator|(
literal|0.8
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
operator|)
operator|)
argument_list|,
name|height
argument_list|()
operator|*
operator|(
literal|0.1
operator|+
operator|(
literal|0.8
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
operator|)
operator|)
argument_list|)
decl_stmt|;
name|qreal
name|radius
init|=
name|qMin
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
operator|*
operator|(
literal|0.0125
operator|+
literal|0.0875
operator|*
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
operator|)
decl_stmt|;
name|QPointF
name|velocity
argument_list|(
name|width
argument_list|()
operator|*
literal|0.0125
operator|*
operator|(
operator|-
literal|0.5
operator|+
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
operator|)
argument_list|,
name|height
argument_list|()
operator|*
literal|0.0125
operator|*
operator|(
operator|-
literal|0.5
operator|+
name|qrand
argument_list|()
operator|/
operator|(
name|RAND_MAX
operator|+
literal|1.0
operator|)
operator|)
argument_list|)
decl_stmt|;
name|bubbles
operator|.
name|append
argument_list|(
operator|new
name|Bubble
argument_list|(
name|position
argument_list|,
name|radius
argument_list|,
name|velocity
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|animate
name|void
name|GLWidget
operator|::
name|animate
parameter_list|()
block|{
name|QMutableListIterator
argument_list|<
name|Bubble
modifier|*
argument_list|>
name|iter
argument_list|(
name|bubbles
argument_list|)
decl_stmt|;
while|while
condition|(
name|iter
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|Bubble
modifier|*
name|bubble
init|=
name|iter
operator|.
name|next
argument_list|()
decl_stmt|;
name|bubble
operator|->
name|move
argument_list|(
name|rect
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|update
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
DECL|function|setupViewport
name|void
name|GLWidget
operator|::
name|setupViewport
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|int
name|side
init|=
name|qMin
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|glViewport
argument_list|(
operator|(
name|width
operator|-
name|side
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|height
operator|-
name|side
operator|)
operator|/
literal|2
argument_list|,
name|side
argument_list|,
name|side
argument_list|)
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_ES
name|glOrthof
argument_list|(
operator|-
literal|0.5
argument_list|,
operator|+
literal|0.5
argument_list|,
operator|-
literal|0.5
argument_list|,
literal|0.5
argument_list|,
literal|4.0
argument_list|,
literal|15.0
argument_list|)
expr_stmt|;
else|#
directive|else
name|glOrtho
argument_list|(
operator|-
literal|0.5
argument_list|,
operator|+
literal|0.5
argument_list|,
operator|-
literal|0.5
argument_list|,
literal|0.5
argument_list|,
literal|4.0
argument_list|,
literal|15.0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_function
DECL|function|drawInstructions
name|void
name|GLWidget
operator|::
name|drawInstructions
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|QString
name|text
init|=
name|tr
argument_list|(
literal|"Click and drag with the left mouse button "
literal|"to rotate the Qt logo."
argument_list|)
decl_stmt|;
name|QFontMetrics
name|metrics
init|=
name|QFontMetrics
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|border
init|=
name|qMax
argument_list|(
literal|4
argument_list|,
name|metrics
operator|.
name|leading
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|metrics
operator|.
name|boundingRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
operator|-
literal|2
operator|*
name|border
argument_list|,
name|int
argument_list|(
name|height
argument_list|()
operator|*
literal|0.125
argument_list|)
argument_list|,
name|Qt
operator|::
name|AlignCenter
operator||
name|Qt
operator|::
name|TextWordWrap
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|TextAntialiasing
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|+
literal|2
operator|*
name|border
argument_list|)
argument_list|,
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
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|+
literal|2
operator|*
name|border
argument_list|)
argument_list|,
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
operator|->
name|drawText
argument_list|(
operator|(
name|width
argument_list|()
operator|-
name|rect
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
name|border
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignCenter
operator||
name|Qt
operator|::
name|TextWordWrap
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [15]
end_comment
end_unit
