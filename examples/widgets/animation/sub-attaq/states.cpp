begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"states.h"
end_include
begin_include
include|#
directive|include
file|"graphicsscene.h"
end_include
begin_include
include|#
directive|include
file|"boat.h"
end_include
begin_include
include|#
directive|include
file|"submarine.h"
end_include
begin_include
include|#
directive|include
file|"torpedo.h"
end_include
begin_include
include|#
directive|include
file|"animationmanager.h"
end_include
begin_include
include|#
directive|include
file|"progressitem.h"
end_include
begin_include
include|#
directive|include
file|"textinformationitem.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStateMachine>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QKeyEventTransition>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFinalState>
end_include
begin_constructor
DECL|function|PlayState
name|PlayState
operator|::
name|PlayState
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
member_init_list|,
name|machine
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentLevel
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|score
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~PlayState
name|PlayState
operator|::
name|~
name|PlayState
parameter_list|()
block|{
operator|delete
name|machine
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|onEntry
name|void
name|PlayState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
comment|//We are now playing?
if|if
condition|(
name|machine
condition|)
block|{
name|machine
operator|->
name|stop
argument_list|()
expr_stmt|;
comment|//we hide the information
name|scene
operator|->
name|textInformationItem
operator|->
name|hide
argument_list|()
expr_stmt|;
name|scene
operator|->
name|clearScene
argument_list|()
expr_stmt|;
name|currentLevel
operator|=
literal|0
expr_stmt|;
name|score
operator|=
literal|0
expr_stmt|;
operator|delete
name|machine
expr_stmt|;
block|}
name|machine
operator|=
operator|new
name|QStateMachine
expr_stmt|;
comment|//This state is when player is playing
name|LevelState
modifier|*
name|levelState
init|=
operator|new
name|LevelState
argument_list|(
name|scene
argument_list|,
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
comment|//This state is when the player is actually playing but the game is not paused
name|QState
modifier|*
name|playingState
init|=
operator|new
name|QState
argument_list|(
name|levelState
argument_list|)
decl_stmt|;
name|levelState
operator|->
name|setInitialState
argument_list|(
name|playingState
argument_list|)
expr_stmt|;
comment|//This state is when the game is paused
name|PauseState
modifier|*
name|pauseState
init|=
operator|new
name|PauseState
argument_list|(
name|scene
argument_list|,
name|levelState
argument_list|)
decl_stmt|;
comment|//We have one view, it receive the key press event
name|QKeyEventTransition
modifier|*
name|pressPplay
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|scene
operator|->
name|views
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_P
argument_list|)
decl_stmt|;
name|pressPplay
operator|->
name|setTargetState
argument_list|(
name|pauseState
argument_list|)
expr_stmt|;
name|QKeyEventTransition
modifier|*
name|pressPpause
init|=
operator|new
name|QKeyEventTransition
argument_list|(
name|scene
operator|->
name|views
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_P
argument_list|)
decl_stmt|;
name|pressPpause
operator|->
name|setTargetState
argument_list|(
name|playingState
argument_list|)
expr_stmt|;
comment|//Pause "P" is triggered, the player pause the game
name|playingState
operator|->
name|addTransition
argument_list|(
name|pressPplay
argument_list|)
expr_stmt|;
comment|//To get back playing when the game has been paused
name|pauseState
operator|->
name|addTransition
argument_list|(
name|pressPpause
argument_list|)
expr_stmt|;
comment|//This state is when player have lost
name|LostState
modifier|*
name|lostState
init|=
operator|new
name|LostState
argument_list|(
name|scene
argument_list|,
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
comment|//This state is when player have won
name|WinState
modifier|*
name|winState
init|=
operator|new
name|WinState
argument_list|(
name|scene
argument_list|,
name|this
argument_list|,
name|machine
argument_list|)
decl_stmt|;
comment|//The boat has been destroyed then the game is finished
name|levelState
operator|->
name|addTransition
argument_list|(
name|scene
operator|->
name|boat
argument_list|,
name|SIGNAL
argument_list|(
name|boatExecutionFinished
argument_list|()
argument_list|)
argument_list|,
name|lostState
argument_list|)
expr_stmt|;
comment|//This transition check if we won or not
name|WinTransition
modifier|*
name|winTransition
init|=
operator|new
name|WinTransition
argument_list|(
name|scene
argument_list|,
name|this
argument_list|,
name|winState
argument_list|)
decl_stmt|;
comment|//The boat has been destroyed then the game is finished
name|levelState
operator|->
name|addTransition
argument_list|(
name|winTransition
argument_list|)
expr_stmt|;
comment|//This state is an animation when the score changed
name|UpdateScoreState
modifier|*
name|scoreState
init|=
operator|new
name|UpdateScoreState
argument_list|(
name|this
argument_list|,
name|levelState
argument_list|)
decl_stmt|;
comment|//This transition update the score when a submarine die
name|UpdateScoreTransition
modifier|*
name|scoreTransition
init|=
operator|new
name|UpdateScoreTransition
argument_list|(
name|scene
argument_list|,
name|this
argument_list|,
name|levelState
argument_list|)
decl_stmt|;
name|scoreTransition
operator|->
name|setTargetState
argument_list|(
name|scoreState
argument_list|)
expr_stmt|;
comment|//The boat has been destroyed then the game is finished
name|playingState
operator|->
name|addTransition
argument_list|(
name|scoreTransition
argument_list|)
expr_stmt|;
comment|//We go back to play state
name|scoreState
operator|->
name|addTransition
argument_list|(
name|playingState
argument_list|)
expr_stmt|;
comment|//We start playing!!!
name|machine
operator|->
name|setInitialState
argument_list|(
name|levelState
argument_list|)
expr_stmt|;
comment|//Final state
name|QFinalState
modifier|*
name|final
init|=
operator|new
name|QFinalState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
comment|//This transition is triggered when the player press space after completing a level
name|CustomSpaceTransition
modifier|*
name|spaceTransition
init|=
operator|new
name|CustomSpaceTransition
argument_list|(
name|scene
operator|->
name|views
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|this
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Space
argument_list|)
decl_stmt|;
name|spaceTransition
operator|->
name|setTargetState
argument_list|(
name|levelState
argument_list|)
expr_stmt|;
name|winState
operator|->
name|addTransition
argument_list|(
name|spaceTransition
argument_list|)
expr_stmt|;
comment|//We lost we should reach the final state
name|lostState
operator|->
name|addTransition
argument_list|(
name|lostState
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|final
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|LevelState
name|LevelState
operator|::
name|LevelState
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|onEntry
name|void
name|LevelState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
name|initializeLevel
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeLevel
name|void
name|LevelState
operator|::
name|initializeLevel
parameter_list|()
block|{
comment|//we re-init the boat
name|scene
operator|->
name|boat
operator|->
name|setPos
argument_list|(
name|scene
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|scene
operator|->
name|sealLevel
argument_list|()
operator|-
name|scene
operator|->
name|boat
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setCurrentSpeed
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setCurrentDirection
argument_list|(
name|Boat
operator|::
name|None
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setBombsLaunched
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|show
argument_list|()
expr_stmt|;
name|scene
operator|->
name|setFocusItem
argument_list|(
name|scene
operator|->
name|boat
argument_list|,
name|Qt
operator|::
name|OtherFocusReason
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|run
argument_list|()
expr_stmt|;
name|scene
operator|->
name|progressItem
operator|->
name|setScore
argument_list|(
name|game
operator|->
name|score
argument_list|)
expr_stmt|;
name|scene
operator|->
name|progressItem
operator|->
name|setLevel
argument_list|(
name|game
operator|->
name|currentLevel
operator|+
literal|1
argument_list|)
expr_stmt|;
name|GraphicsScene
operator|::
name|LevelDescription
name|currentLevelDescription
init|=
name|scene
operator|->
name|levelsData
operator|.
name|value
argument_list|(
name|game
operator|->
name|currentLevel
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currentLevelDescription
operator|.
name|submarines
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|subContent
init|=
name|currentLevelDescription
operator|.
name|submarines
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|GraphicsScene
operator|::
name|SubmarineDescription
name|submarineDesc
init|=
name|scene
operator|->
name|submarinesData
operator|.
name|at
argument_list|(
name|subContent
operator|.
name|first
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|subContent
operator|.
name|second
condition|;
operator|++
name|j
control|)
block|{
name|SubMarine
modifier|*
name|sub
init|=
operator|new
name|SubMarine
argument_list|(
name|submarineDesc
operator|.
name|type
argument_list|,
name|submarineDesc
operator|.
name|name
argument_list|,
name|submarineDesc
operator|.
name|points
argument_list|)
decl_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|sub
argument_list|)
expr_stmt|;
name|int
name|random
init|=
operator|(
name|qrand
argument_list|()
operator|%
literal|15
operator|+
literal|1
operator|)
decl_stmt|;
name|qreal
name|x
init|=
name|random
operator|==
literal|13
operator|||
name|random
operator|==
literal|5
condition|?
literal|0
else|:
name|scene
operator|->
name|width
argument_list|()
operator|-
name|sub
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
decl_stmt|;
name|qreal
name|y
init|=
name|scene
operator|->
name|height
argument_list|()
operator|-
operator|(
name|qrand
argument_list|()
operator|%
literal|150
operator|+
literal|1
operator|)
operator|-
name|sub
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
name|sub
operator|->
name|setPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|sub
operator|->
name|setCurrentDirection
argument_list|(
name|x
operator|==
literal|0
condition|?
name|SubMarine
operator|::
name|Right
else|:
name|SubMarine
operator|::
name|Left
argument_list|)
expr_stmt|;
name|sub
operator|->
name|setCurrentSpeed
argument_list|(
name|qrand
argument_list|()
operator|%
literal|3
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/** Pause State */
end_comment
begin_constructor
DECL|function|PauseState
name|PauseState
operator|::
name|PauseState
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|onEntry
name|void
name|PauseState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|pauseAll
argument_list|()
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onExit
name|void
name|PauseState
operator|::
name|onExit
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|resumeAll
argument_list|()
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|scene
operator|->
name|boat
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/** Lost State */
end_comment
begin_constructor
DECL|function|LostState
name|LostState
operator|::
name|LostState
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|onEntry
name|void
name|LostState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
comment|//The message to display
name|QString
name|message
init|=
name|QString
argument_list|(
literal|"You lose on level %1. Your score is %2."
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|currentLevel
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|score
argument_list|)
decl_stmt|;
comment|//We set the level back to 0
name|game
operator|->
name|currentLevel
operator|=
literal|0
expr_stmt|;
comment|//We set the score back to 0
name|game
operator|->
name|score
operator|=
literal|0
expr_stmt|;
comment|//We clear the scene
name|scene
operator|->
name|clearScene
argument_list|()
expr_stmt|;
comment|//We inform the player
name|scene
operator|->
name|textInformationItem
operator|->
name|setMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|scene
operator|->
name|textInformationItem
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onExit
name|void
name|LostState
operator|::
name|onExit
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
comment|//we hide the information
name|scene
operator|->
name|textInformationItem
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/** Win State */
end_comment
begin_constructor
DECL|function|WinState
name|WinState
operator|::
name|WinState
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|onEntry
name|void
name|WinState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
comment|//We clear the scene
name|scene
operator|->
name|clearScene
argument_list|()
expr_stmt|;
name|QString
name|message
decl_stmt|;
if|if
condition|(
name|scene
operator|->
name|levelsData
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|!=
name|game
operator|->
name|currentLevel
condition|)
block|{
name|message
operator|=
name|QString
argument_list|(
literal|"You win the level %1. Your score is %2.\nPress Space to continue."
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|currentLevel
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|score
argument_list|)
expr_stmt|;
comment|//We increment the level number
name|game
operator|->
name|currentLevel
operator|++
expr_stmt|;
block|}
else|else
block|{
name|message
operator|=
name|QString
argument_list|(
literal|"You finish the game on level %1. Your score is %2."
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|currentLevel
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|game
operator|->
name|score
argument_list|)
expr_stmt|;
comment|//We set the level back to 0
name|game
operator|->
name|currentLevel
operator|=
literal|0
expr_stmt|;
comment|//We set the score back to 0
name|game
operator|->
name|score
operator|=
literal|0
expr_stmt|;
block|}
comment|//We inform the player
name|scene
operator|->
name|textInformationItem
operator|->
name|setMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|scene
operator|->
name|textInformationItem
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onExit
name|void
name|WinState
operator|::
name|onExit
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
comment|//we hide the information
name|scene
operator|->
name|textInformationItem
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/** UpdateScore State */
end_comment
begin_constructor
DECL|function|UpdateScoreState
name|UpdateScoreState
operator|::
name|UpdateScoreState
parameter_list|(
name|PlayState
modifier|*
name|g
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QState
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|game
argument_list|(
name|g
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/** Win transition */
end_comment
begin_constructor
DECL|function|UpdateScoreTransition
name|UpdateScoreTransition
operator|::
name|UpdateScoreTransition
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QSignalTransition
argument_list|(
name|scene
argument_list|,
name|SIGNAL
argument_list|(
name|subMarineDestroyed
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
block|{
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|eventTest
name|bool
name|UpdateScoreTransition
operator|::
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QSignalTransition
operator|::
name|eventTest
argument_list|(
name|event
argument_list|)
condition|)
return|return
literal|false
return|;
name|QStateMachine
operator|::
name|SignalEvent
modifier|*
name|se
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|SignalEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|game
operator|->
name|score
operator|+=
name|se
operator|->
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|scene
operator|->
name|progressItem
operator|->
name|setScore
argument_list|(
name|game
operator|->
name|score
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/** Win transition */
end_comment
begin_constructor
DECL|function|WinTransition
name|WinTransition
operator|::
name|WinTransition
parameter_list|(
name|GraphicsScene
modifier|*
name|scene
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QSignalTransition
argument_list|(
name|scene
argument_list|,
name|SIGNAL
argument_list|(
name|allSubMarineDestroyed
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
member_init_list|,
name|scene
argument_list|(
name|scene
argument_list|)
block|{
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|eventTest
name|bool
name|WinTransition
operator|::
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QSignalTransition
operator|::
name|eventTest
argument_list|(
name|event
argument_list|)
condition|)
return|return
literal|false
return|;
name|QStateMachine
operator|::
name|SignalEvent
modifier|*
name|se
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|SignalEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|game
operator|->
name|score
operator|+=
name|se
operator|->
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|scene
operator|->
name|progressItem
operator|->
name|setScore
argument_list|(
name|game
operator|->
name|score
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/** Space transition */
end_comment
begin_constructor
DECL|function|CustomSpaceTransition
name|CustomSpaceTransition
operator|::
name|CustomSpaceTransition
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|PlayState
modifier|*
name|game
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|int
name|key
parameter_list|)
member_init_list|:
name|QKeyEventTransition
argument_list|(
name|widget
argument_list|,
name|type
argument_list|,
name|key
argument_list|)
member_init_list|,
name|game
argument_list|(
name|game
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|eventTest
name|bool
name|CustomSpaceTransition
operator|::
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QKeyEventTransition
operator|::
name|eventTest
argument_list|(
name|event
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
operator|(
name|game
operator|->
name|currentLevel
operator|!=
literal|0
operator|)
return|;
block|}
end_function
end_unit
