begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_comment
comment|//![15]
end_comment
begin_class
DECL|class|StateSwitchEvent
class|class
name|StateSwitchEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|function|StateSwitchEvent
name|StateSwitchEvent
parameter_list|()
member_init_list|:
name|QEvent
argument_list|(
name|Type
argument_list|(
name|StateSwitchType
argument_list|)
argument_list|)
block|{     }
DECL|function|StateSwitchEvent
specifier|explicit
name|StateSwitchEvent
parameter_list|(
name|int
name|rand
parameter_list|)
member_init_list|:
name|QEvent
argument_list|(
name|Type
argument_list|(
name|StateSwitchType
argument_list|)
argument_list|)
member_init_list|,
name|m_rand
argument_list|(
name|rand
argument_list|)
block|{     }
DECL|enumerator|StateSwitchType
enum|enum
block|{
name|StateSwitchType
init|=
name|QEvent
operator|::
name|User
operator|+
literal|256
block|}
enum|;
DECL|function|rand
name|int
name|rand
parameter_list|()
specifier|const
block|{
return|return
name|m_rand
return|;
block|}
private|private:
DECL|member|m_rand
name|int
name|m_rand
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//![15]
end_comment
begin_comment
comment|//![16]
end_comment
begin_class
DECL|class|QGraphicsRectWidget
class|class
name|QGraphicsRectWidget
super|:
specifier|public
name|QGraphicsWidget
block|{
public|public:
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
name|Q_DECL_OVERRIDE
block|{
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|//![16]
end_comment
begin_class
DECL|class|StateSwitchTransition
class|class
name|StateSwitchTransition
super|:
specifier|public
name|QAbstractTransition
block|{
public|public:
DECL|function|StateSwitchTransition
name|StateSwitchTransition
parameter_list|(
name|int
name|rand
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|()
member_init_list|,
name|m_rand
argument_list|(
name|rand
argument_list|)
block|{     }
protected|protected:
comment|//![14]
specifier|virtual
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
operator|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Type
argument_list|(
name|StateSwitchEvent
operator|::
name|StateSwitchType
argument_list|)
operator|)
operator|&&
operator|(
cast|static_cast
argument_list|<
name|StateSwitchEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|rand
argument_list|()
operator|==
name|m_rand
operator|)
return|;
block|}
comment|//![14]
specifier|virtual
name|void
name|onTransition
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{}
private|private:
DECL|member|m_rand
name|int
name|m_rand
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//![10]
end_comment
begin_class
DECL|class|StateSwitcher
class|class
name|StateSwitcher
super|:
specifier|public
name|QState
block|{
name|Q_OBJECT
public|public:
DECL|function|StateSwitcher
name|StateSwitcher
parameter_list|(
name|QStateMachine
modifier|*
name|machine
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|machine
argument_list|)
member_init_list|,
name|m_stateCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_lastIndex
argument_list|(
literal|0
argument_list|)
block|{ }
comment|//![10]
comment|//![11]
specifier|virtual
name|void
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|int
name|n
decl_stmt|;
while|while
condition|(
operator|(
name|n
operator|=
operator|(
name|qrand
argument_list|()
operator|%
name|m_stateCount
operator|+
literal|1
operator|)
operator|)
operator|==
name|m_lastIndex
condition|)
block|{ }
name|m_lastIndex
operator|=
name|n
expr_stmt|;
name|machine
argument_list|()
operator|->
name|postEvent
argument_list|(
operator|new
name|StateSwitchEvent
argument_list|(
name|n
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|virtual
name|void
name|onExit
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{}
comment|//![11]
comment|//![12]
DECL|function|addState
name|void
name|addState
parameter_list|(
name|QState
modifier|*
name|state
parameter_list|,
name|QAbstractAnimation
modifier|*
name|animation
parameter_list|)
block|{
name|StateSwitchTransition
modifier|*
name|trans
init|=
operator|new
name|StateSwitchTransition
argument_list|(
operator|++
name|m_stateCount
argument_list|)
decl_stmt|;
name|trans
operator|->
name|setTargetState
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|addTransition
argument_list|(
name|trans
argument_list|)
expr_stmt|;
name|trans
operator|->
name|addAnimation
argument_list|(
name|animation
argument_list|)
expr_stmt|;
block|}
comment|//![12]
private|private:
DECL|member|m_stateCount
name|int
name|m_stateCount
decl_stmt|;
DECL|member|m_lastIndex
name|int
name|m_lastIndex
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//![13]
end_comment
begin_function
DECL|function|createGeometryState
name|QState
modifier|*
name|createGeometryState
parameter_list|(
name|QObject
modifier|*
name|w1
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect1
parameter_list|,
name|QObject
modifier|*
name|w2
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect2
parameter_list|,
name|QObject
modifier|*
name|w3
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect3
parameter_list|,
name|QObject
modifier|*
name|w4
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect4
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
block|{
name|QState
modifier|*
name|result
init|=
operator|new
name|QState
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|result
operator|->
name|assignProperty
argument_list|(
name|w1
argument_list|,
literal|"geometry"
argument_list|,
name|rect1
argument_list|)
expr_stmt|;
name|result
operator|->
name|assignProperty
argument_list|(
name|w2
argument_list|,
literal|"geometry"
argument_list|,
name|rect2
argument_list|)
expr_stmt|;
name|result
operator|->
name|assignProperty
argument_list|(
name|w3
argument_list|,
literal|"geometry"
argument_list|,
name|rect3
argument_list|)
expr_stmt|;
name|result
operator|->
name|assignProperty
argument_list|(
name|w4
argument_list|,
literal|"geometry"
argument_list|,
name|rect4
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|//![13]
end_comment
begin_class
DECL|class|GraphicsView
class|class
name|GraphicsView
super|:
specifier|public
name|QGraphicsView
block|{
name|Q_OBJECT
public|public:
DECL|function|GraphicsView
name|GraphicsView
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
name|NULL
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|scene
argument_list|,
name|parent
argument_list|)
block|{     }
protected|protected:
specifier|virtual
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|fitInView
argument_list|(
name|scene
argument_list|()
operator|->
name|sceneRect
argument_list|()
argument_list|)
expr_stmt|;
name|QGraphicsView
operator|::
name|resizeEvent
argument_list|(
name|event
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
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//![1]
name|QGraphicsRectWidget
modifier|*
name|button1
init|=
operator|new
name|QGraphicsRectWidget
decl_stmt|;
name|QGraphicsRectWidget
modifier|*
name|button2
init|=
operator|new
name|QGraphicsRectWidget
decl_stmt|;
name|QGraphicsRectWidget
modifier|*
name|button3
init|=
operator|new
name|QGraphicsRectWidget
decl_stmt|;
name|QGraphicsRectWidget
modifier|*
name|button4
init|=
operator|new
name|QGraphicsRectWidget
decl_stmt|;
name|button2
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|button3
operator|->
name|setZValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|button4
operator|->
name|setZValue
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|scene
operator|.
name|setBackgroundBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|button1
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|button2
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|button3
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|button4
argument_list|)
expr_stmt|;
comment|//![1]
name|GraphicsView
name|window
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|window
operator|.
name|setFrameStyle
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|window
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|window
operator|.
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|window
operator|.
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
comment|//![2]
name|QStateMachine
name|machine
decl_stmt|;
name|QState
modifier|*
name|group
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|group
operator|->
name|setObjectName
argument_list|(
literal|"group"
argument_list|)
expr_stmt|;
name|QTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|setInterval
argument_list|(
literal|1250
argument_list|)
expr_stmt|;
name|timer
operator|.
name|setSingleShot
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|group
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|timer
argument_list|,
name|SLOT
argument_list|(
name|start
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//![2]
comment|//![3]
name|QState
modifier|*
name|state1
decl_stmt|;
name|QState
modifier|*
name|state2
decl_stmt|;
name|QState
modifier|*
name|state3
decl_stmt|;
name|QState
modifier|*
name|state4
decl_stmt|;
name|QState
modifier|*
name|state5
decl_stmt|;
name|QState
modifier|*
name|state6
decl_stmt|;
name|QState
modifier|*
name|state7
decl_stmt|;
name|state1
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|150
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|200
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
comment|//![3]
name|state2
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|150
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|200
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
name|state3
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|150
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|50
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
name|state4
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|150
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
name|state5
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|150
argument_list|,
literal|100
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|100
argument_list|,
literal|150
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|150
argument_list|,
literal|150
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
name|state6
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|200
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|50
argument_list|,
literal|200
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
comment|//![4]
name|state7
operator|=
name|createGeometryState
argument_list|(
name|button1
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button2
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button3
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|button4
argument_list|,
name|QRect
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|,
name|group
argument_list|)
expr_stmt|;
name|group
operator|->
name|setInitialState
argument_list|(
name|state1
argument_list|)
expr_stmt|;
comment|//![4]
comment|//![5]
name|QParallelAnimationGroup
name|animationGroup
decl_stmt|;
name|QSequentialAnimationGroup
modifier|*
name|subGroup
decl_stmt|;
name|QPropertyAnimation
modifier|*
name|anim
init|=
operator|new
name|QPropertyAnimation
argument_list|(
name|button4
argument_list|,
literal|"geometry"
argument_list|)
decl_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutElastic
argument_list|)
expr_stmt|;
name|animationGroup
operator|.
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
comment|//![5]
comment|//![6]
name|subGroup
operator|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addPause
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|anim
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|button3
argument_list|,
literal|"geometry"
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutElastic
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
comment|//![6]
name|subGroup
operator|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addPause
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|anim
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|button2
argument_list|,
literal|"geometry"
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutElastic
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
name|subGroup
operator|=
operator|new
name|QSequentialAnimationGroup
argument_list|(
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addPause
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|anim
operator|=
operator|new
name|QPropertyAnimation
argument_list|(
name|button1
argument_list|,
literal|"geometry"
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setDuration
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|OutElastic
argument_list|)
expr_stmt|;
name|subGroup
operator|->
name|addAnimation
argument_list|(
name|anim
argument_list|)
expr_stmt|;
comment|//![7]
name|StateSwitcher
modifier|*
name|stateSwitcher
init|=
operator|new
name|StateSwitcher
argument_list|(
operator|&
name|machine
argument_list|)
decl_stmt|;
name|stateSwitcher
operator|->
name|setObjectName
argument_list|(
literal|"stateSwitcher"
argument_list|)
expr_stmt|;
name|group
operator|->
name|addTransition
argument_list|(
operator|&
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|stateSwitcher
argument_list|)
expr_stmt|;
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state1
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state2
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
comment|//![7]
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state3
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state4
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state5
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state6
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
comment|//![8]
name|stateSwitcher
operator|->
name|addState
argument_list|(
name|state7
argument_list|,
operator|&
name|animationGroup
argument_list|)
expr_stmt|;
comment|//![8]
comment|//![9]
name|machine
operator|.
name|addState
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|machine
operator|.
name|start
argument_list|()
expr_stmt|;
comment|//![9]
name|window
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
name|qsrand
argument_list|(
name|QTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
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
