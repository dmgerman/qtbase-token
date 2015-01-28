begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//! [0]
name|QFileInfo
name|fileInfo1
argument_list|(
literal|"~/examples/191697/."
argument_list|)
decl_stmt|;
name|QFileInfo
name|fileInfo2
argument_list|(
literal|"~/examples/191697/.."
argument_list|)
decl_stmt|;
name|QFileInfo
name|fileInfo3
argument_list|(
literal|"~/examples/191697/main.cpp"
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|QFileInfo
name|fileInfo4
argument_list|(
literal|"."
argument_list|)
decl_stmt|;
name|QFileInfo
name|fileInfo5
argument_list|(
literal|".."
argument_list|)
decl_stmt|;
name|QFileInfo
name|fileInfo6
argument_list|(
literal|"main.cpp"
argument_list|)
decl_stmt|;
comment|//! [1]
name|qDebug
argument_list|()
operator|<<
name|fileInfo1
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|fileInfo2
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|fileInfo3
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|fileInfo4
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|fileInfo5
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|fileInfo6
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|QPushButton
modifier|*
name|button1
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo1
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button2
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo2
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button3
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo3
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button4
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo4
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button5
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo5
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|button6
init|=
operator|new
name|QPushButton
argument_list|(
name|fileInfo6
operator|.
name|dir
argument_list|()
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button1
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button2
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button3
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button4
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button5
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|button6
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
literal|"QFileInfo::dir() test"
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
name|groupBox
operator|->
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
end_unit
