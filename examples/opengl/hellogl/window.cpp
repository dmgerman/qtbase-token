begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|glWidget
operator|=
operator|new
name|GLWidget
expr_stmt|;
name|xSlider
operator|=
name|createSlider
argument_list|()
expr_stmt|;
name|ySlider
operator|=
name|createSlider
argument_list|()
expr_stmt|;
name|zSlider
operator|=
name|createSlider
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|xSlider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glWidget
argument_list|,
name|SLOT
argument_list|(
name|setXRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|glWidget
argument_list|,
name|SIGNAL
argument_list|(
name|xRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|xSlider
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ySlider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glWidget
argument_list|,
name|SLOT
argument_list|(
name|setYRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|glWidget
argument_list|,
name|SIGNAL
argument_list|(
name|yRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|ySlider
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zSlider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|glWidget
argument_list|,
name|SLOT
argument_list|(
name|setZRotation
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|glWidget
argument_list|,
name|SIGNAL
argument_list|(
name|zRotationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|zSlider
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|glWidget
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|xSlider
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|ySlider
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|zSlider
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|xSlider
operator|->
name|setValue
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|ySlider
operator|->
name|setValue
argument_list|(
literal|345
operator|*
literal|16
argument_list|)
expr_stmt|;
name|zSlider
operator|->
name|setValue
argument_list|(
literal|0
operator|*
literal|16
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Hello GL"
argument_list|)
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
DECL|function|createSlider
name|QSlider
modifier|*
name|Window
operator|::
name|createSlider
parameter_list|()
block|{
name|QSlider
modifier|*
name|slider
init|=
operator|new
name|QSlider
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|slider
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|360
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setSingleStep
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setPageStep
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickInterval
argument_list|(
literal|15
operator|*
literal|16
argument_list|)
expr_stmt|;
name|slider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksRight
argument_list|)
expr_stmt|;
return|return
name|slider
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|keyPressEvent
name|void
name|Window
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
condition|)
name|close
argument_list|()
expr_stmt|;
else|else
name|QWidget
operator|::
name|keyPressEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
