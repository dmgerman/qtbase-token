begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Pixmap
class|class
name|Pixmap
super|:
specifier|public
name|QGraphicsObject
block|{
name|Q_OBJECT
public|public:
DECL|function|Pixmap
name|Pixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pix
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|()
member_init_list|,
name|p
argument_list|(
name|pix
argument_list|)
block|{     }
DECL|function|paint
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QPointF
argument_list|()
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
DECL|function|boundingRect
name|QRectF
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|p
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
private|private:
DECL|member|p
name|QPixmap
name|p
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|GraphicsView
class|class
name|GraphicsView
super|:
specifier|public
name|QGraphicsView
block|{
public|public:
DECL|function|GraphicsView
name|GraphicsView
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|scene
argument_list|)
block|{     }
DECL|function|resizeEvent
specifier|virtual
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|fitInView
argument_list|(
name|sceneRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|states
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|// Text edit and button
name|QTextEdit
modifier|*
name|edit
init|=
operator|new
name|QTextEdit
decl_stmt|;
name|edit
operator|->
name|setText
argument_list|(
literal|"asdf lkjha yuoiqwe asd iuaysd u iasyd uiy "
literal|"asdf lkjha yuoiqwe asd iuaysd u iasyd uiy "
literal|"asdf lkjha yuoiqwe asd iuaysd u iasyd uiy "
literal|"asdf lkjha yuoiqwe asd iuaysd u iasyd uiy!"
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
decl_stmt|;
name|QGraphicsProxyWidget
modifier|*
name|buttonProxy
init|=
operator|new
name|QGraphicsProxyWidget
decl_stmt|;
name|buttonProxy
operator|->
name|setWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|QGraphicsProxyWidget
modifier|*
name|editProxy
init|=
operator|new
name|QGraphicsProxyWidget
decl_stmt|;
name|editProxy
operator|->
name|setWidget
argument_list|(
name|edit
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|box
init|=
operator|new
name|QGroupBox
decl_stmt|;
name|box
operator|->
name|setFlat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|box
operator|->
name|setTitle
argument_list|(
literal|"Options"
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout2
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|box
operator|->
name|setLayout
argument_list|(
name|layout2
argument_list|)
expr_stmt|;
name|layout2
operator|->
name|addWidget
argument_list|(
operator|new
name|QRadioButton
argument_list|(
literal|"Herring"
argument_list|)
argument_list|)
expr_stmt|;
name|layout2
operator|->
name|addWidget
argument_list|(
operator|new
name|QRadioButton
argument_list|(
literal|"Blue Parrot"
argument_list|)
argument_list|)
expr_stmt|;
name|layout2
operator|->
name|addWidget
argument_list|(
operator|new
name|QRadioButton
argument_list|(
literal|"Petunias"
argument_list|)
argument_list|)
expr_stmt|;
name|layout2
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QGraphicsProxyWidget
modifier|*
name|boxProxy
init|=
operator|new
name|QGraphicsProxyWidget
decl_stmt|;
name|boxProxy
operator|->
name|setWidget
argument_list|(
name|box
argument_list|)
expr_stmt|;
comment|// Parent widget
name|QGraphicsWidget
modifier|*
name|widget
init|=
operator|new
name|QGraphicsWidget
decl_stmt|;
name|QGraphicsLinearLayout
modifier|*
name|layout
init|=
operator|new
name|QGraphicsLinearLayout
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addItem
argument_list|(
name|editProxy
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addItem
argument_list|(
name|buttonProxy
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|Pixmap
modifier|*
name|p1
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/digikam.png"
argument_list|)
argument_list|)
decl_stmt|;
name|Pixmap
modifier|*
name|p2
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/akregator.png"
argument_list|)
argument_list|)
decl_stmt|;
name|Pixmap
modifier|*
name|p3
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/accessories-dictionary.png"
argument_list|)
argument_list|)
decl_stmt|;
name|Pixmap
modifier|*
name|p4
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/k3b.png"
argument_list|)
argument_list|)
decl_stmt|;
name|Pixmap
modifier|*
name|p5
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/help-browser.png"
argument_list|)
argument_list|)
decl_stmt|;
name|Pixmap
modifier|*
name|p6
init|=
operator|new
name|Pixmap
argument_list|(
name|QPixmap
argument_list|(
literal|":/kchart.png"
argument_list|)
argument_list|)
decl_stmt|;
name|QGraphicsScene
name|scene
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|400
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|scene
operator|.
name|setBackgroundBrush
argument_list|(
name|scene
operator|.
name|palette
argument_list|()
operator|.
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|boxProxy
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p3
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p4
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p5
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|p6
argument_list|)
expr_stmt|;
name|QStateMachine
name|machine
decl_stmt|;
name|QState
modifier|*
name|state1
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|state2
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|state3
init|=
operator|new
name|QState
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|state1
argument_list|)
expr_stmt|;
comment|// State 1
name|state1
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Switch to state 2"
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|400
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|,
name|QRect
argument_list|(
operator|-
literal|200
argument_list|,
literal|150
argument_list|,
literal|200
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|68
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|// 185));
name|state1
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|168
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|// 185));
name|state1
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|268
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
comment|// 185));
name|state1
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|68
operator|-
literal|150
argument_list|,
literal|48
operator|-
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|168
argument_list|,
literal|48
operator|-
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|268
operator|+
literal|150
argument_list|,
literal|48
operator|-
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
operator|-
literal|270
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
operator|-
literal|90
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|270
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|boxProxy
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state1
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// State 2
name|state2
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Switch to state 3"
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|200
argument_list|,
literal|150
argument_list|,
literal|200
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|,
name|QRect
argument_list|(
literal|9
argument_list|,
literal|150
argument_list|,
literal|190
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|68
operator|-
literal|150
argument_list|,
literal|185
operator|+
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|168
argument_list|,
literal|185
operator|+
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|268
operator|+
literal|150
argument_list|,
literal|185
operator|+
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|64
argument_list|,
literal|48
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|168
argument_list|,
literal|48
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|268
argument_list|,
literal|48
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
operator|-
literal|270
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|90
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|270
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"rotation"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|boxProxy
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state2
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
comment|// State 3
name|state3
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Switch to state 1"
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|5
operator|+
literal|64
operator|+
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|5
argument_list|,
literal|5
operator|+
operator|(
literal|64
operator|+
literal|5
operator|)
operator|+
literal|64
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|5
operator|+
literal|64
operator|+
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|5
operator|+
literal|64
operator|+
literal|5
argument_list|,
literal|5
operator|+
literal|64
operator|+
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|,
name|QPointF
argument_list|(
literal|5
operator|+
literal|64
operator|+
literal|5
argument_list|,
literal|5
operator|+
operator|(
literal|64
operator|+
literal|5
operator|)
operator|+
literal|64
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|138
argument_list|,
literal|5
argument_list|,
literal|400
operator|-
literal|138
argument_list|,
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|,
name|QRect
argument_list|(
literal|5
argument_list|,
literal|205
argument_list|,
literal|400
argument_list|,
literal|90
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|state3
operator|->
name|assignProperty
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t1
init|=
name|state1
operator|->
name|addTransition
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|state2
argument_list|)
decl_stmt|;
name|QSequentialAnimationGroup
modifier|*
name|animation1SubGroup
init|=
operator|new
name|QSequentialAnimationGroup
decl_stmt|;
name|animation1SubGroup
operator|->
name|addPause
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|animation1SubGroup
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
name|animation1SubGroup
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t1
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t2
init|=
name|state2
operator|->
name|addTransition
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|state3
argument_list|)
decl_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t2
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|QAbstractTransition
modifier|*
name|t3
init|=
name|state3
operator|->
name|addTransition
argument_list|(
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|state1
argument_list|)
decl_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|box
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|widget
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"pos"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"rotation"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p1
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p2
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p3
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p4
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p5
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|t3
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|p6
argument_list|,
literal|"opacity"
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
name|GraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
