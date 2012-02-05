begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|Window
name|Window
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|button
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setContentsMargins
argument_list|(
literal|80
argument_list|,
literal|80
argument_list|,
literal|80
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QStateMachine
modifier|*
name|machine
init|=
operator|new
name|QStateMachine
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|s1
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Outside"
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s2
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|s2
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Inside"
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QEventTransition
modifier|*
name|enterTransition
init|=
operator|new
name|QEventTransition
argument_list|(
name|button
argument_list|,
name|QEvent
operator|::
name|Enter
argument_list|)
decl_stmt|;
name|enterTransition
operator|->
name|setTargetState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
name|enterTransition
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QEventTransition
modifier|*
name|leaveTransition
init|=
operator|new
name|QEventTransition
argument_list|(
name|button
argument_list|,
name|QEvent
operator|::
name|Leave
argument_list|)
decl_stmt|;
name|leaveTransition
operator|->
name|setTargetState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|s2
operator|->
name|addTransition
argument_list|(
name|leaveTransition
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|s3
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"text"
argument_list|,
literal|"Pressing..."
argument_list|)
expr_stmt|;
name|QEventTransition
modifier|*
name|pressTransition
init|=
operator|new
name|QEventTransition
argument_list|(
name|button
argument_list|,
name|QEvent
operator|::
name|MouseButtonPress
argument_list|)
decl_stmt|;
name|pressTransition
operator|->
name|setTargetState
argument_list|(
name|s3
argument_list|)
expr_stmt|;
name|s2
operator|->
name|addTransition
argument_list|(
name|pressTransition
argument_list|)
expr_stmt|;
name|QEventTransition
modifier|*
name|releaseTransition
init|=
operator|new
name|QEventTransition
argument_list|(
name|button
argument_list|,
name|QEvent
operator|::
name|MouseButtonRelease
argument_list|)
decl_stmt|;
name|releaseTransition
operator|->
name|setTargetState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|s3
operator|->
name|addTransition
argument_list|(
name|releaseTransition
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|machine
operator|->
name|addState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|machine
operator|->
name|addState
argument_list|(
name|s3
argument_list|)
expr_stmt|;
name|machine
operator|->
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
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
name|Window
name|window
decl_stmt|;
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
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
end_unit
