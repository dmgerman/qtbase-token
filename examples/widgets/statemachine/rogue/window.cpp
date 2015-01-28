begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|"movementtransition.h"
end_include
begin_comment
comment|//![0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|pX
operator|=
literal|5
expr_stmt|;
name|pY
operator|=
literal|5
expr_stmt|;
comment|//![0]
name|QFontDatabase
name|database
decl_stmt|;
name|QFont
name|font
decl_stmt|;
if|if
condition|(
name|database
operator|.
name|families
argument_list|()
operator|.
name|contains
argument_list|(
literal|"Monospace"
argument_list|)
condition|)
block|{
name|font
operator|=
name|QFont
argument_list|(
literal|"Monospace"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
foreach|foreach
control|(
name|QString
name|family
decl|,
name|database
operator|.
name|families
argument_list|()
control|)
block|{
if|if
condition|(
name|database
operator|.
name|isFixedPitch
argument_list|(
name|family
argument_list|)
condition|)
block|{
name|font
operator|=
name|QFont
argument_list|(
name|family
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
name|font
operator|.
name|setPointSize
argument_list|(
literal|12
argument_list|)
expr_stmt|;
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
comment|//![1]
name|setupMap
argument_list|()
expr_stmt|;
name|buildMachine
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//![1]
end_comment
begin_function
DECL|function|setStatus
name|void
name|Window
operator|::
name|setStatus
parameter_list|(
specifier|const
name|QString
modifier|&
name|status
parameter_list|)
block|{
name|myStatus
operator|=
name|status
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|status
name|QString
name|Window
operator|::
name|status
parameter_list|()
specifier|const
block|{
return|return
name|myStatus
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|Window
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|QFontMetrics
name|metrics
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|int
name|fontHeight
init|=
name|metrics
operator|.
name|height
argument_list|()
decl_stmt|;
name|int
name|fontWidth
init|=
name|metrics
operator|.
name|width
argument_list|(
literal|'X'
argument_list|)
decl_stmt|;
name|int
name|yPos
init|=
name|fontHeight
decl_stmt|;
name|int
name|xPos
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
name|QPoint
argument_list|(
literal|0
argument_list|,
name|yPos
argument_list|)
argument_list|,
name|status
argument_list|()
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
name|HEIGHT
condition|;
operator|++
name|y
control|)
block|{
name|yPos
operator|+=
name|fontHeight
expr_stmt|;
name|xPos
operator|=
literal|0
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
name|WIDTH
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
name|y
operator|==
name|pY
operator|&&
name|x
operator|==
name|pX
condition|)
block|{
name|xPos
operator|+=
name|fontWidth
expr_stmt|;
continue|continue;
block|}
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|double
name|x1
init|=
cast|static_cast
argument_list|<
name|double
argument_list|>
argument_list|(
name|pX
argument_list|)
decl_stmt|;
name|double
name|y1
init|=
cast|static_cast
argument_list|<
name|double
argument_list|>
argument_list|(
name|pY
argument_list|)
decl_stmt|;
name|double
name|x2
init|=
cast|static_cast
argument_list|<
name|double
argument_list|>
argument_list|(
name|x
argument_list|)
decl_stmt|;
name|double
name|y2
init|=
cast|static_cast
argument_list|<
name|double
argument_list|>
argument_list|(
name|y
argument_list|)
decl_stmt|;
if|if
condition|(
name|x2
operator|<
name|x1
condition|)
block|{
name|x2
operator|+=
literal|0.5
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|x2
operator|>
name|x1
condition|)
block|{
name|x2
operator|-=
literal|0.5
expr_stmt|;
block|}
if|if
condition|(
name|y2
operator|<
name|y1
condition|)
block|{
name|y2
operator|+=
literal|0.5
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|y2
operator|>
name|y1
condition|)
block|{
name|y2
operator|-=
literal|0.5
expr_stmt|;
block|}
name|double
name|dx
init|=
name|x2
operator|-
name|x1
decl_stmt|;
name|double
name|dy
init|=
name|y2
operator|-
name|y1
decl_stmt|;
name|double
name|length
init|=
name|qSqrt
argument_list|(
name|dx
operator|*
name|dx
operator|+
name|dy
operator|*
name|dy
argument_list|)
decl_stmt|;
name|dx
operator|/=
name|length
expr_stmt|;
name|dy
operator|/=
name|length
expr_stmt|;
name|double
name|xi
init|=
name|x1
decl_stmt|;
name|double
name|yi
init|=
name|y1
decl_stmt|;
while|while
condition|(
name|length
operator|>
literal|0
condition|)
block|{
name|int
name|cx
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|xi
operator|+
literal|0.5
argument_list|)
decl_stmt|;
name|int
name|cy
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|yi
operator|+
literal|0.5
argument_list|)
decl_stmt|;
if|if
condition|(
name|x2
operator|==
name|cx
operator|&&
name|y2
operator|==
name|cy
condition|)
break|break;
if|if
condition|(
operator|!
operator|(
name|x1
operator|==
name|cx
operator|&&
name|y1
operator|==
name|cy
operator|)
operator|&&
operator|(
name|map
index|[
name|cx
index|]
index|[
name|cy
index|]
operator|==
literal|'#'
operator|||
operator|(
name|length
operator|-
literal|10
operator|)
operator|>
literal|0
operator|)
condition|)
block|{
name|painter
operator|.
name|setPen
argument_list|(
name|QColor
argument_list|(
literal|60
argument_list|,
literal|60
argument_list|,
literal|60
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|xi
operator|+=
name|dx
expr_stmt|;
name|yi
operator|+=
name|dy
expr_stmt|;
operator|--
name|length
expr_stmt|;
block|}
name|painter
operator|.
name|drawText
argument_list|(
name|QPoint
argument_list|(
name|xPos
argument_list|,
name|yPos
argument_list|)
argument_list|,
name|map
index|[
name|x
index|]
index|[
name|y
index|]
argument_list|)
expr_stmt|;
name|xPos
operator|+=
name|fontWidth
expr_stmt|;
block|}
block|}
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
name|QPoint
argument_list|(
name|pX
operator|*
name|fontWidth
argument_list|,
operator|(
name|pY
operator|+
literal|2
operator|)
operator|*
name|fontHeight
argument_list|)
argument_list|,
name|QChar
argument_list|(
literal|'@'
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSize
name|Window
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|QFontMetrics
name|metrics
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QSize
argument_list|(
name|metrics
operator|.
name|width
argument_list|(
literal|'X'
argument_list|)
operator|*
name|WIDTH
argument_list|,
name|metrics
operator|.
name|height
argument_list|()
operator|*
operator|(
name|HEIGHT
operator|+
literal|1
operator|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//![2]
end_comment
begin_function
DECL|function|buildMachine
name|void
name|Window
operator|::
name|buildMachine
parameter_list|()
block|{
name|machine
operator|=
operator|new
name|QStateMachine
expr_stmt|;
name|QState
modifier|*
name|inputState
init|=
operator|new
name|QState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|inputState
operator|->
name|assignProperty
argument_list|(
name|this
argument_list|,
literal|"status"
argument_list|,
literal|"Move the rogue with 2, 4, 6, and 8"
argument_list|)
expr_stmt|;
name|MovementTransition
modifier|*
name|transition
init|=
operator|new
name|MovementTransition
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|inputState
operator|->
name|addTransition
argument_list|(
name|transition
argument_list|)
expr_stmt|;
comment|//![2]
comment|//![3]
name|QState
modifier|*
name|quitState
init|=
operator|new
name|QState
argument_list|(
name|machine
argument_list|)
decl_stmt|;
name|quitState
operator|->
name|assignProperty
argument_list|(
name|this
argument_list|,
literal|"status"
argument_list|,
literal|"Really quit(y/n)?"
argument_list|)
expr_stmt|;
name|QKeyEventTransition
modifier|*
name|yesTransition
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
name|Key_Y
argument_list|)
decl_stmt|;
name|yesTransition
operator|->
name|setTargetState
argument_list|(
operator|new
name|QFinalState
argument_list|(
name|machine
argument_list|)
argument_list|)
expr_stmt|;
name|quitState
operator|->
name|addTransition
argument_list|(
name|yesTransition
argument_list|)
expr_stmt|;
name|QKeyEventTransition
modifier|*
name|noTransition
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
name|Key_N
argument_list|)
decl_stmt|;
name|noTransition
operator|->
name|setTargetState
argument_list|(
name|inputState
argument_list|)
expr_stmt|;
name|quitState
operator|->
name|addTransition
argument_list|(
name|noTransition
argument_list|)
expr_stmt|;
comment|//![3]
comment|//![4]
name|QKeyEventTransition
modifier|*
name|quitTransition
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
name|Key_Q
argument_list|)
decl_stmt|;
name|quitTransition
operator|->
name|setTargetState
argument_list|(
name|quitState
argument_list|)
expr_stmt|;
name|inputState
operator|->
name|addTransition
argument_list|(
name|quitTransition
argument_list|)
expr_stmt|;
comment|//![4]
comment|//![5]
name|machine
operator|->
name|setInitialState
argument_list|(
name|inputState
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|machine
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//![5]
end_comment
begin_function
DECL|function|movePlayer
name|void
name|Window
operator|::
name|movePlayer
parameter_list|(
name|Direction
name|direction
parameter_list|)
block|{
switch|switch
condition|(
name|direction
condition|)
block|{
case|case
name|Left
case|:
if|if
condition|(
name|map
index|[
name|pX
operator|-
literal|1
index|]
index|[
name|pY
index|]
operator|!=
literal|'#'
condition|)
operator|--
name|pX
expr_stmt|;
break|break;
case|case
name|Right
case|:
if|if
condition|(
name|map
index|[
name|pX
operator|+
literal|1
index|]
index|[
name|pY
index|]
operator|!=
literal|'#'
condition|)
operator|++
name|pX
expr_stmt|;
break|break;
case|case
name|Up
case|:
if|if
condition|(
name|map
index|[
name|pX
index|]
index|[
name|pY
operator|-
literal|1
index|]
operator|!=
literal|'#'
condition|)
operator|--
name|pY
expr_stmt|;
break|break;
case|case
name|Down
case|:
if|if
condition|(
name|map
index|[
name|pX
index|]
index|[
name|pY
operator|+
literal|1
index|]
operator|!=
literal|'#'
condition|)
operator|++
name|pY
expr_stmt|;
break|break;
block|}
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupMap
name|void
name|Window
operator|::
name|setupMap
parameter_list|()
block|{
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
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|WIDTH
condition|;
operator|++
name|x
control|)
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|HEIGHT
condition|;
operator|++
name|y
control|)
block|{
if|if
condition|(
name|x
operator|==
literal|0
operator|||
name|x
operator|==
name|WIDTH
operator|-
literal|1
operator|||
name|y
operator|==
literal|0
operator|||
name|y
operator|==
name|HEIGHT
operator|-
literal|1
operator|||
name|qrand
argument_list|()
operator|%
literal|40
operator|==
literal|0
condition|)
name|map
index|[
name|x
index|]
index|[
name|y
index|]
operator|=
literal|'#'
expr_stmt|;
else|else
name|map
index|[
name|x
index|]
index|[
name|y
index|]
operator|=
literal|'.'
expr_stmt|;
block|}
block|}
end_function
end_unit
