begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [0]
name|QWidget
modifier|*
name|firstPageWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|secondPageWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|thirdPageWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|QStackedLayout
modifier|*
name|stackedLayout
init|=
operator|new
name|QStackedLayout
decl_stmt|;
name|stackedLayout
operator|->
name|addWidget
argument_list|(
name|firstPageWidget
argument_list|)
expr_stmt|;
name|stackedLayout
operator|->
name|addWidget
argument_list|(
name|secondPageWidget
argument_list|)
expr_stmt|;
name|stackedLayout
operator|->
name|addWidget
argument_list|(
name|thirdPageWidget
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
name|QComboBox
modifier|*
name|pageComboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|pageComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Page 1"
argument_list|)
argument_list|)
expr_stmt|;
name|pageComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Page 2"
argument_list|)
argument_list|)
expr_stmt|;
name|pageComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Page 3"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pageComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|stackedLayout
argument_list|,
name|SLOT
argument_list|(
name|setCurrentIndex
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
comment|//! [2]
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|pageComboBox
argument_list|)
expr_stmt|;
comment|//! [3]
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|stackedLayout
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
comment|//! [3]
block|}
end_constructor
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
name|Widget
name|widget
decl_stmt|;
name|widget
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
end_unit
