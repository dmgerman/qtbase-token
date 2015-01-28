begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
name|QWidget
modifier|*
name|button
decl_stmt|;
block|{
comment|//![0]
name|QStateMachine
name|machine
decl_stmt|;
name|machine
operator|.
name|setGlobalRestorePolicy
argument_list|(
name|QStateMachine
operator|::
name|RestoreProperties
argument_list|)
expr_stmt|;
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
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
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
name|machine
operator|.
name|addState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|//![0]
block|}
block|{
comment|//![2]
name|QStateMachine
name|machine
decl_stmt|;
name|machine
operator|.
name|setGlobalRestorePolicy
argument_list|(
name|QStateMachine
operator|::
name|RestoreProperties
argument_list|)
expr_stmt|;
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
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s2
init|=
operator|new
name|QState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
name|s2
operator|->
name|assignProperty
argument_list|(
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|2.0
argument_list|)
expr_stmt|;
name|s1
operator|->
name|setInitialState
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|(
name|s1
argument_list|)
decl_stmt|;
comment|//![2]
block|}
block|{
comment|//![3]
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|QState
modifier|*
name|s2
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
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|s2
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|s1
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
name|s2
argument_list|)
expr_stmt|;
comment|//![3]
block|}
block|{
comment|//![4]
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|QState
modifier|*
name|s2
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
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|s2
operator|->
name|assignProperty
argument_list|(
name|button
argument_list|,
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QSignalTransition
modifier|*
name|transition
init|=
name|s1
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
name|s2
argument_list|)
decl_stmt|;
name|transition
operator|->
name|addAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|button
argument_list|,
literal|"geometry"
argument_list|)
argument_list|)
expr_stmt|;
comment|//![4]
block|}
block|{
name|QMainWindow
modifier|*
name|mainWindow
init|=
literal|0
decl_stmt|;
comment|//![5]
name|QMessageBox
modifier|*
name|messageBox
init|=
operator|new
name|QMessageBox
argument_list|(
name|mainWindow
argument_list|)
decl_stmt|;
name|messageBox
operator|->
name|addButton
argument_list|(
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|messageBox
operator|->
name|setText
argument_list|(
literal|"Button geometry has been set!"
argument_list|)
expr_stmt|;
name|messageBox
operator|->
name|setIcon
argument_list|(
name|QMessageBox
operator|::
name|Information
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
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
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|s2
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
name|messageBox
argument_list|,
name|SLOT
argument_list|(
name|exec
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|s1
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
name|s2
argument_list|)
expr_stmt|;
comment|//![5]
block|}
block|{
name|QMainWindow
modifier|*
name|mainWindow
init|=
literal|0
decl_stmt|;
comment|//![6]
name|QMessageBox
modifier|*
name|messageBox
init|=
operator|new
name|QMessageBox
argument_list|(
name|mainWindow
argument_list|)
decl_stmt|;
name|messageBox
operator|->
name|addButton
argument_list|(
name|QMessageBox
operator|::
name|Ok
argument_list|)
expr_stmt|;
name|messageBox
operator|->
name|setText
argument_list|(
literal|"Button geometry has been set!"
argument_list|)
expr_stmt|;
name|messageBox
operator|->
name|setIcon
argument_list|(
name|QMessageBox
operator|::
name|Information
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
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
literal|"geometry"
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QState
modifier|*
name|s3
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|s3
argument_list|,
name|SIGNAL
argument_list|(
name|entered
argument_list|()
argument_list|)
argument_list|,
name|messageBox
argument_list|,
name|SLOT
argument_list|(
name|exec
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|s1
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
name|s2
argument_list|)
expr_stmt|;
name|s2
operator|->
name|addTransition
argument_list|(
name|s2
argument_list|,
name|SIGNAL
argument_list|(
name|propertiesAssigned
argument_list|()
argument_list|)
argument_list|,
name|s3
argument_list|)
expr_stmt|;
comment|//![6]
block|}
block|{
comment|//![7]
name|QState
modifier|*
name|s1
init|=
operator|new
name|QState
argument_list|()
decl_stmt|;
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
name|object
argument_list|,
literal|"fooBar"
argument_list|,
literal|2.0
argument_list|)
expr_stmt|;
name|s1
operator|->
name|addTransition
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|QStateMachine
name|machine
decl_stmt|;
name|machine
operator|.
name|setInitialState
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|machine
operator|.
name|addDefaultAnimation
argument_list|(
operator|new
name|QPropertyAnimation
argument_list|(
name|object
argument_list|,
literal|"fooBar"
argument_list|)
argument_list|)
expr_stmt|;
comment|//![7]
block|}
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
