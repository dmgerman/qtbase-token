begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_comment
comment|//! [Dialog constructor part1]
end_comment
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
parameter_list|()
block|{
name|desktopGeometry
operator|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"SIP Dialog Example"
argument_list|)
argument_list|)
expr_stmt|;
name|QScrollArea
modifier|*
name|scrollArea
init|=
operator|new
name|QScrollArea
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|scrollArea
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setTitle
argument_list|(
name|tr
argument_list|(
literal|"SIP Dialog Example"
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|gridLayout
init|=
operator|new
name|QGridLayout
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|gridLayout
argument_list|)
expr_stmt|;
comment|//! [Dialog constructor part1]
comment|//! [Dialog constructor part2]
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
name|lineEdit
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Open and close the SIP"
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setMinimumWidth
argument_list|(
literal|220
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"This dialog resizes if the SIP is opened"
argument_list|)
argument_list|)
expr_stmt|;
name|label
operator|->
name|setMinimumWidth
argument_list|(
literal|220
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|groupBox
argument_list|)
decl_stmt|;
name|button
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Close Dialog"
argument_list|)
argument_list|)
expr_stmt|;
name|button
operator|->
name|setMinimumWidth
argument_list|(
literal|220
argument_list|)
expr_stmt|;
comment|//! [Dialog constructor part2]
comment|//! [Dialog constructor part3]
if|if
condition|(
name|desktopGeometry
operator|.
name|height
argument_list|()
operator|<
literal|400
condition|)
name|gridLayout
operator|->
name|setVerticalSpacing
argument_list|(
literal|80
argument_list|)
expr_stmt|;
else|else
name|gridLayout
operator|->
name|setVerticalSpacing
argument_list|(
literal|150
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
comment|//! [Dialog constructor part3]
comment|//! [Dialog constructor part4]
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|()
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
comment|//! [Dialog constructor part4]
comment|//! [Dialog constructor part5]
name|connect
argument_list|(
name|button
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|clicked
argument_list|,
name|qApp
argument_list|,
operator|&
name|QApplication
operator|::
name|closeAllWindows
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
argument_list|,
operator|&
name|QDesktopWidget
operator|::
name|workAreaResized
argument_list|,
name|this
argument_list|,
operator|&
name|Dialog
operator|::
name|desktopResized
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [Dialog constructor part5]
end_comment
begin_comment
comment|//! [desktopResized() function]
end_comment
begin_function
DECL|function|desktopResized
name|void
name|Dialog
operator|::
name|desktopResized
parameter_list|(
name|int
name|screen
parameter_list|)
block|{
if|if
condition|(
name|screen
operator|!=
literal|0
condition|)
return|return;
name|reactToSIP
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [desktopResized() function]
end_comment
begin_comment
comment|//! [reactToSIP() function]
end_comment
begin_function
DECL|function|reactToSIP
name|void
name|Dialog
operator|::
name|reactToSIP
parameter_list|()
block|{
name|QRect
name|availableGeometry
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|desktopGeometry
operator|!=
name|availableGeometry
condition|)
block|{
if|if
condition|(
name|windowState
argument_list|()
operator||
name|Qt
operator|::
name|WindowMaximized
condition|)
name|setWindowState
argument_list|(
name|windowState
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|WindowMaximized
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|availableGeometry
argument_list|)
expr_stmt|;
block|}
name|desktopGeometry
operator|=
name|availableGeometry
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [reactToSIP() function]
end_comment
end_unit
