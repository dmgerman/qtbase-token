begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
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
name|QLabel
modifier|*
name|textLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Data:"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|textBrowser
operator|=
operator|new
name|QTextBrowser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|mimeTypeLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"MIME types:"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|mimeTypeCombo
operator|=
operator|new
name|QComboBox
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|dropFrame
operator|=
operator|new
name|QFrame
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|dropFrame
operator|->
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|StyledPanel
operator||
name|QFrame
operator|::
name|Sunken
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|dropLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Drop items here"
argument_list|)
argument_list|,
name|dropFrame
argument_list|)
decl_stmt|;
name|dropLabel
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignHCenter
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|dropFrameLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|dropFrame
argument_list|)
decl_stmt|;
name|dropFrameLayout
operator|->
name|addWidget
argument_list|(
name|dropLabel
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|dropLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|dropLayout
operator|->
name|addStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dropLayout
operator|->
name|addWidget
argument_list|(
name|dropFrame
argument_list|)
expr_stmt|;
name|dropLayout
operator|->
name|addStretch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|textLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|textBrowser
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|mimeTypeLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|mimeTypeCombo
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addSpacing
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|dropLayout
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Drop Rectangle"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|dragMoveEvent
name|void
name|Window
operator|::
name|dragMoveEvent
parameter_list|(
name|QDragMoveEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
operator|&&
name|event
operator|->
name|answerRect
argument_list|()
operator|.
name|intersects
argument_list|(
name|dropFrame
operator|->
name|geometry
argument_list|()
argument_list|)
condition|)
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|dropEvent
name|void
name|Window
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
name|textBrowser
operator|->
name|setPlainText
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|mimeTypeCombo
operator|->
name|clear
argument_list|()
expr_stmt|;
name|mimeTypeCombo
operator|->
name|addItems
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|formats
argument_list|()
argument_list|)
expr_stmt|;
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
