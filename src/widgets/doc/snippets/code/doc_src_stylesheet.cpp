begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [21]
end_comment
begin_expr_stmt
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"QPushButton { color: white }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_expr_stmt
name|myPushButton
operator|->
name|setStyleSheet
argument_list|(
literal|"* { color: blue }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_expr_stmt
name|myPushButton
operator|->
name|setStyleSheet
argument_list|(
literal|"color: blue"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_expr_stmt
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"QGroupBox { color: red; } "
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_expr_stmt
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"QGroupBox, QGroupBox * { color: red; }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_class
DECL|class|MyPushButton
class|class
name|MyPushButton
super|:
specifier|public
name|QPushButton
block|{
comment|// ...
block|}
comment|// ...
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"MyPushButton { background: yellow; }"
argument_list|)
class|;
end_class
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_namespace
DECL|namespace|ns
namespace|namespace
name|ns
block|{
DECL|class|MyPushButton
class|class
name|MyPushButton
super|:
specifier|public
name|QPushButton
block|{
comment|// ...
block|}
block|}
end_namespace
begin_comment
comment|// ...
end_comment
begin_expr_stmt
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"ns--MyPushButton { background: yellow; }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|CustomWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|style
argument_list|()
operator|->
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_Widget
argument_list|,
operator|&
name|opt
argument_list|,
operator|&
name|p
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [32]
end_comment
begin_comment
comment|//! [88]
end_comment
begin_expr_stmt
name|qApp
operator|->
name|setStyleSheet
argument_list|(
literal|"QLineEdit { background-color: yellow }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [88]
end_comment
begin_comment
comment|//! [89]
end_comment
begin_expr_stmt
name|myDialog
operator|->
name|setStyleSheet
argument_list|(
literal|"QLineEdit { background-color: yellow }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [89]
end_comment
begin_comment
comment|//! [90]
end_comment
begin_expr_stmt
name|myDialog
operator|->
name|setStyleSheet
argument_list|(
literal|"QLineEdit#nameEdit { background-color: yellow }"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [90]
end_comment
begin_comment
comment|//! [91]
end_comment
begin_expr_stmt
name|nameEdit
operator|->
name|setStyleSheet
argument_list|(
literal|"background-color: yellow"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [91]
end_comment
begin_comment
comment|//! [92]
end_comment
begin_expr_stmt
name|nameEdit
operator|->
name|setStyleSheet
argument_list|(
literal|"color: blue; background-color: yellow"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [92]
end_comment
begin_comment
comment|//! [93]
end_comment
begin_expr_stmt
name|nameEdit
operator|->
name|setStyleSheet
argument_list|(
literal|"color: blue;"
literal|"background-color: yellow;"
literal|"selection-color: yellow;"
literal|"selection-background-color: blue;"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [93]
end_comment
begin_comment
comment|//! [95]
end_comment
begin_decl_stmt
DECL|variable|nameEdit
name|QLineEdit
modifier|*
name|nameEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|nameEdit
operator|->
name|setProperty
argument_list|(
literal|"mandatoryField"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|emailEdit
name|QLineEdit
modifier|*
name|emailEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|emailEdit
operator|->
name|setProperty
argument_list|(
literal|"mandatoryField"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|ageSpinBox
name|QSpinBox
modifier|*
name|ageSpinBox
init|=
operator|new
name|QSpinBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|ageSpinBox
operator|->
name|setProperty
argument_list|(
literal|"mandatoryField"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [95]
end_comment
end_unit
