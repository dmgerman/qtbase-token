begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"flippablepad.h"
end_include
begin_include
include|#
directive|include
file|"padnavigator.h"
end_include
begin_include
include|#
directive|include
file|"splashitem.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtOpenGL/QtOpenGL>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|PadNavigator
name|PadNavigator
operator|::
name|PadNavigator
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [0]
comment|//! [1]
comment|// Splash item
name|SplashItem
modifier|*
name|splash
init|=
operator|new
name|SplashItem
decl_stmt|;
name|splash
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
comment|// Pad item
name|FlippablePad
modifier|*
name|pad
init|=
operator|new
name|FlippablePad
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|QGraphicsRotation
modifier|*
name|flipRotation
init|=
operator|new
name|QGraphicsRotation
argument_list|(
name|pad
argument_list|)
decl_stmt|;
name|QGraphicsRotation
modifier|*
name|xRotation
init|=
operator|new
name|QGraphicsRotation
argument_list|(
name|pad
argument_list|)
decl_stmt|;
name|QGraphicsRotation
modifier|*
name|yRotation
init|=
operator|new
name|QGraphicsRotation
argument_list|(
name|pad
argument_list|)
decl_stmt|;
name|flipRotation
operator|->
name|setAxis
argument_list|(
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|xRotation
operator|->
name|setAxis
argument_list|(
name|Qt
operator|::
name|YAxis
argument_list|)
expr_stmt|;
name|yRotation
operator|->
name|setAxis
argument_list|(
name|Qt
operator|::
name|XAxis
argument_list|)
expr_stmt|;
name|pad
operator|->
name|setTransformations
argument_list|(
name|QList
argument_list|<
name|QGraphicsTransform
operator|*
argument_list|>
argument_list|()
operator|<<
name|flipRotation
operator|<<
name|xRotation
operator|<<
name|yRotation
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
comment|// Back (proxy widget) item
name|QGraphicsProxyWidget
modifier|*
name|backItem
init|=
operator|new
name|QGraphicsProxyWidget
argument_list|(
name|pad
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
decl_stmt|;
name|form
operator|.
name|setupUi
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|form
operator|.
name|hostName
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|backItem
operator|->
name|setWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|backItem
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|backItem
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|backItem
operator|->
name|setCacheMode
argument_list|(
name|QGraphicsItem
operator|::
name|ItemCoordinateCache
argument_list|)
expr_stmt|;
specifier|const
name|QRectF
name|r
init|=
name|backItem
operator|->
name|rect
argument_list|()
decl_stmt|;
name|backItem
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|180
argument_list|,
name|Qt
operator|::
name|YAxis
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
comment|//! [3]
comment|//! [4]
comment|// Selection item
name|RoundRectItem
modifier|*
name|selectionItem
init|=
operator|new
name|RoundRectItem
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|60
argument_list|,
operator|-
literal|60
argument_list|,
literal|120
argument_list|,
literal|120
argument_list|)
argument_list|,
name|Qt
operator|::
name|gray
argument_list|,
name|pad
argument_list|)
decl_stmt|;
name|selectionItem
operator|->
name|setZValue
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
comment|// Splash animations
name|QPropertyAnimation
modifier|*
name|smoothSplashMove
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|splash
argument_list|,
literal|"y"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothSplashOpacity
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|splash
argument_list|,
literal|"opacity"
argument_list|)
decl_stmt|;
name|smoothSplashMove
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InQuad
argument_list|)
expr_stmt|;
name|smoothSplashMove
operator|->
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|smoothSplashOpacity
operator|->
name|setDuration
argument_list|(
literal|250
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
comment|// Selection animation
name|QPropertyAnimation
modifier|*
name|smoothXSelection
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|selectionItem
argument_list|,
literal|"x"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothYSelection
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|selectionItem
argument_list|,
literal|"y"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothXRotation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|xRotation
argument_list|,
literal|"angle"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothYRotation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|yRotation
argument_list|,
literal|"angle"
argument_list|)
decl_stmt|;
name|smoothXSelection
operator|->
name|setDuration
argument_list|(
literal|125
argument_list|)
expr_stmt|;
name|smoothYSelection
operator|->
name|setDuration
argument_list|(
literal|125
argument_list|)
expr_stmt|;
name|smoothXRotation
operator|->
name|setDuration
argument_list|(
literal|125
argument_list|)
expr_stmt|;
name|smoothYRotation
operator|->
name|setDuration
argument_list|(
literal|125
argument_list|)
expr_stmt|;
name|smoothXSelection
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothYSelection
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothXRotation
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothYRotation
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
comment|// Flip animation setup
name|QPropertyAnimation
modifier|*
name|smoothFlipRotation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|flipRotation
argument_list|,
literal|"angle"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothFlipScale
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|pad
argument_list|,
literal|"scale"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothFlipXRotation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|xRotation
argument_list|,
literal|"angle"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|smoothFlipYRotation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|yRotation
argument_list|,
literal|"angle"
argument_list|)
decl_stmt|;
name|QParallelAnimationGroup
modifier|*
name|flipAnimation
init|=
operator|new
name|QParallelAnimationGroup
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|smoothFlipScale
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|smoothFlipRotation
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|smoothFlipXRotation
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|smoothFlipYRotation
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|smoothFlipScale
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothFlipRotation
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothFlipXRotation
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothFlipYRotation
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InOutQuad
argument_list|)
expr_stmt|;
name|smoothFlipScale
operator|->
name|setKeyValueAt
argument_list|(
literal|0
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|1.0
argument_list|)
argument_list|)
expr_stmt|;
name|smoothFlipScale
operator|->
name|setKeyValueAt
argument_list|(
literal|0.5
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|0.7
argument_list|)
argument_list|)
expr_stmt|;
name|smoothFlipScale
operator|->
name|setKeyValueAt
argument_list|(
literal|1
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|1.0
argument_list|)
argument_list|)
expr_stmt|;
name|flipAnimation
operator|->
name|addAnimation
argument_list|(
name|smoothFlipRotation
argument_list|)
expr_stmt|;
name|flipAnimation
operator|->
name|addAnimation
argument_list|(
name|smoothFlipScale
argument_list|)
expr_stmt|;
name|flipAnimation
operator|->
name|addAnimation
argument_list|(
name|smoothFlipXRotation
argument_list|)
expr_stmt|;
name|flipAnimation
operator|->
name|addAnimation
argument_list|(
name|smoothFlipYRotation
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
comment|// Flip animation delayed property assignment
name|QSequentialAnimationGroup
modifier|*
name|setVariablesSequence
init|=
operator|new
name|QSequentialAnimationGroup
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|setFillAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|pad
argument_list|,
literal|"fill"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|setBackItemVisibleAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|backItem
argument_list|,
literal|"visible"
argument_list|)
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|setSelectionItemVisibleAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|selectionItem
argument_list|,
literal|"visible"
argument_list|)
decl_stmt|;
name|setFillAnimation
operator|->
name|setDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setBackItemVisibleAnimation
operator|->
name|setDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setSelectionItemVisibleAnimation
operator|->
name|setDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setVariablesSequence
operator|->
name|addPause
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|setVariablesSequence
operator|->
name|addAnimation
argument_list|(
name|setBackItemVisibleAnimation
argument_list|)
expr_stmt|;
name|setVariablesSequence
operator|->
name|addAnimation
argument_list|(
name|setSelectionItemVisibleAnimation
argument_list|)
expr_stmt|;
name|setVariablesSequence
operator|->
name|addAnimation
argument_list|(
name|setFillAnimation
argument_list|)
expr_stmt|;
name|flipAnimation
operator|->
name|addAnimation
argument_list|(
name|setVariablesSequence
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
comment|// Build the state machine
name|QStateMachine
modifier|*
name|stateMachine
init|=
operator|new
name|QStateMachine
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|splashState
init|=
operator|new
name|QState
argument_list|(
name|stateMachine
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|frontState
init|=
operator|new
name|QState
argument_list|(
name|stateMachine
argument_list|)
decl_stmt|;
name|QHistoryState
modifier|*
name|historyState
init|=
operator|new
name|QHistoryState
argument_list|(
name|frontState
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|backState
init|=
operator|new
name|QState
argument_list|(
name|stateMachine
argument_list|)
decl_stmt|;
comment|//! [9]
comment|//! [10]
name|frontState
operator|->
name|assignProperty
argument_list|(
name|pad
argument_list|,
literal|"fill"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|splash
argument_list|,
literal|"opacity"
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|backItem
argument_list|,
literal|"visible"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|flipRotation
argument_list|,
literal|"angle"
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|selectionItem
argument_list|,
literal|"visible"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|pad
argument_list|,
literal|"fill"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|backItem
argument_list|,
literal|"visible"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|xRotation
argument_list|,
literal|"angle"
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|yRotation
argument_list|,
literal|"angle"
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|flipRotation
argument_list|,
literal|"angle"
argument_list|,
name|qvariant_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|180.0
argument_list|)
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|selectionItem
argument_list|,
literal|"visible"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|stateMachine
operator|->
name|addDefaultAnimation
argument_list|(
name|smoothXRotation
argument_list|)
expr_stmt|;
name|stateMachine
operator|->
name|addDefaultAnimation
argument_list|(
name|smoothYRotation
argument_list|)
expr_stmt|;
name|stateMachine
operator|->
name|addDefaultAnimation
argument_list|(
name|smoothXSelection
argument_list|)
expr_stmt|;
name|stateMachine
operator|->
name|addDefaultAnimation
argument_list|(
name|smoothYSelection
argument_list|)
expr_stmt|;
name|stateMachine
operator|->
name|setInitialState
argument_list|(
name|splashState
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
comment|// Transitions
name|QEventTransition
modifier|*
name|anyKeyTransition
init|=
operator|new
name|QEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|splashState
argument_list|)
decl_stmt|;
name|anyKeyTransition
operator|->
name|setTargetState
argument_list|(
name|frontState
argument_list|)
expr_stmt|;
name|anyKeyTransition
operator|->
name|addAnimation
argument_list|(
name|smoothSplashMove
argument_list|)
expr_stmt|;
name|anyKeyTransition
operator|->
name|addAnimation
argument_list|(
name|smoothSplashOpacity
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|QKeyEventTransition
modifier|*
name|enterTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Enter
argument_list|,
name|backState
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|returnTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|,
name|backState
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|backEnterTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Enter
argument_list|,
name|frontState
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|backReturnTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Return
argument_list|,
name|frontState
argument_list|)
decl_stmt|;
name|enterTransition
operator|->
name|setTargetState
argument_list|(
name|historyState
argument_list|)
expr_stmt|;
name|returnTransition
operator|->
name|setTargetState
argument_list|(
name|historyState
argument_list|)
expr_stmt|;
name|backEnterTransition
operator|->
name|setTargetState
argument_list|(
name|backState
argument_list|)
expr_stmt|;
name|backReturnTransition
operator|->
name|setTargetState
argument_list|(
name|backState
argument_list|)
expr_stmt|;
name|enterTransition
operator|->
name|addAnimation
argument_list|(
name|flipAnimation
argument_list|)
expr_stmt|;
name|returnTransition
operator|->
name|addAnimation
argument_list|(
name|flipAnimation
argument_list|)
expr_stmt|;
name|backEnterTransition
operator|->
name|addAnimation
argument_list|(
name|flipAnimation
argument_list|)
expr_stmt|;
name|backReturnTransition
operator|->
name|addAnimation
argument_list|(
name|flipAnimation
argument_list|)
expr_stmt|;
comment|//! [12]
comment|//! [13]
comment|// Create substates for each icon; store in temporary grid.
name|int
name|columns
init|=
name|size
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|rows
init|=
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
name|QVector
argument_list|<
name|QVector
argument_list|<
name|QState
modifier|*
argument_list|>
argument_list|>
name|stateGrid
decl_stmt|;
name|stateGrid
operator|.
name|resize
argument_list|(
name|rows
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|rows
condition|;
operator|++
name|y
control|)
block|{
name|stateGrid
index|[
name|y
index|]
operator|.
name|resize
argument_list|(
name|columns
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|columns
condition|;
operator|++
name|x
control|)
name|stateGrid
index|[
name|y
index|]
index|[
name|x
index|]
operator|=
operator|new
name|QState
argument_list|(
name|frontState
argument_list|)
expr_stmt|;
block|}
name|frontState
operator|->
name|setInitialState
argument_list|(
name|stateGrid
index|[
literal|0
index|]
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|selectionItem
operator|->
name|setPos
argument_list|(
name|pad
operator|->
name|iconAt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [13]
comment|//! [14]
comment|// Enable key navigation using state transitions
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|rows
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|columns
condition|;
operator|++
name|x
control|)
block|{
name|QState
modifier|*
name|state
init|=
name|stateGrid
index|[
name|y
index|]
index|[
name|x
index|]
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|rightTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Right
argument_list|,
name|state
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|leftTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Left
argument_list|,
name|state
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|downTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Down
argument_list|,
name|state
argument_list|)
decl_stmt|;
name|QKeyEventTransition
modifier|*
name|upTransition
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Up
argument_list|,
name|state
argument_list|)
decl_stmt|;
name|rightTransition
operator|->
name|setTargetState
argument_list|(
name|stateGrid
index|[
name|y
index|]
index|[
operator|(
name|x
operator|+
literal|1
operator|)
operator|%
name|columns
index|]
argument_list|)
expr_stmt|;
name|leftTransition
operator|->
name|setTargetState
argument_list|(
name|stateGrid
index|[
name|y
index|]
index|[
operator|(
operator|(
name|x
operator|-
literal|1
operator|)
operator|+
name|columns
operator|)
operator|%
name|columns
index|]
argument_list|)
expr_stmt|;
name|downTransition
operator|->
name|setTargetState
argument_list|(
name|stateGrid
index|[
operator|(
name|y
operator|+
literal|1
operator|)
operator|%
name|rows
index|]
index|[
name|x
index|]
argument_list|)
expr_stmt|;
name|upTransition
operator|->
name|setTargetState
argument_list|(
name|stateGrid
index|[
operator|(
operator|(
name|y
operator|-
literal|1
operator|)
operator|+
name|rows
operator|)
operator|%
name|rows
index|]
index|[
name|x
index|]
argument_list|)
expr_stmt|;
comment|//! [14]
comment|//! [15]
name|RoundRectItem
modifier|*
name|icon
init|=
name|pad
operator|->
name|iconAt
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|state
operator|->
name|assignProperty
argument_list|(
name|xRotation
argument_list|,
literal|"angle"
argument_list|,
operator|-
name|icon
operator|->
name|x
argument_list|()
operator|/
literal|6.0
argument_list|)
expr_stmt|;
name|state
operator|->
name|assignProperty
argument_list|(
name|yRotation
argument_list|,
literal|"angle"
argument_list|,
name|icon
operator|->
name|y
argument_list|()
operator|/
literal|6.0
argument_list|)
expr_stmt|;
name|state
operator|->
name|assignProperty
argument_list|(
name|selectionItem
argument_list|,
literal|"x"
argument_list|,
name|icon
operator|->
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|state
operator|->
name|assignProperty
argument_list|(
name|selectionItem
argument_list|,
literal|"y"
argument_list|,
name|icon
operator|->
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|icon
argument_list|,
literal|"visible"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|backState
operator|->
name|assignProperty
argument_list|(
name|icon
argument_list|,
literal|"visible"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QPropertyAnimation
modifier|*
name|setIconVisibleAnimation
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|icon
argument_list|,
literal|"visible"
argument_list|)
decl_stmt|;
name|setIconVisibleAnimation
operator|->
name|setDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setVariablesSequence
operator|->
name|addAnimation
argument_list|(
name|setIconVisibleAnimation
argument_list|)
expr_stmt|;
block|}
block|}
comment|//! [15]
comment|//! [16]
comment|// Scene
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|scene
operator|->
name|setBackgroundBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/blue_angle_swirl.jpg"
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|pad
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
name|scene
operator|->
name|itemsBoundingRect
argument_list|()
argument_list|)
expr_stmt|;
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
comment|//! [16]
comment|//! [17]
comment|// Adjust splash item to scene contents
specifier|const
name|QRectF
name|sbr
init|=
name|splash
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|splash
operator|->
name|setPos
argument_list|(
operator|-
name|sbr
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|scene
operator|->
name|sceneRect
argument_list|()
operator|.
name|top
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
name|frontState
operator|->
name|assignProperty
argument_list|(
name|splash
argument_list|,
literal|"y"
argument_list|,
name|splash
operator|->
name|y
argument_list|()
operator|-
literal|100.0
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|splash
argument_list|)
expr_stmt|;
comment|//! [17]
comment|//! [18]
comment|// View
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|setViewportUpdateMode
argument_list|(
name|FullViewportUpdate
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|CacheBackground
argument_list|)
expr_stmt|;
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|Antialiasing
operator||
name|QPainter
operator|::
name|SmoothPixmapTransform
operator||
name|QPainter
operator|::
name|TextAntialiasing
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|setViewport
argument_list|(
operator|new
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|stateMachine
operator|->
name|start
argument_list|()
expr_stmt|;
comment|//! [18]
block|}
end_constructor
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|PadNavigator
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QGraphicsView
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|fitInView
argument_list|(
name|scene
argument_list|()
operator|->
name|sceneRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [19]
end_comment
end_unit
