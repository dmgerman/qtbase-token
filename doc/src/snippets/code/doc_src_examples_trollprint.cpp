begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|twoSidedEnabledRadio
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Enabled"
argument_list|,
literal|"two-sided"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|twoSidedDisabledRadio
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Disabled"
argument_list|,
literal|"two-sided"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|colorsEnabledRadio
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Enabled"
argument_list|,
literal|"colors"
argument_list|)
argument_list|,
name|colors
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|colorsDisabledRadio
operator|=
operator|new
name|QRadioButton
argument_list|(
name|tr
argument_list|(
literal|"Disabled"
argument_list|,
literal|"colors"
argument_list|)
argument_list|,
name|colors
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|/*    TRANSLATOR MainWindow     In this application the whole application is a MainWindow.    Choose Help|About from the menu bar to see some text    belonging to MainWindow.     ... */
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|/*    TRANSLATOR ZClientErrorDialog     Choose Client|Edit to reach the Client Edit dialog, then choose    Client Specification from the drop down list at the top and pick    client Bartel Leendert van der Waerden. Now check the Profile    checkbox and then click the Start Processing button. You should    now see a pop up window with the text "Error: Name too long!".    This window is a ZClientErrorDialog. */
end_comment
begin_comment
comment|//! [3]
end_comment
end_unit
