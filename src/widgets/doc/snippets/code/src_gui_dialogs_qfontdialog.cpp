begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|ok
name|bool
name|ok
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|font
name|QFont
name|font
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|,
name|QFont
argument_list|(
literal|"Helvetica [Cronyx]"
argument_list|,
literal|10
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|ok
condition|)
block|{
comment|// the user clicked OK and font is set to the font the user selected
block|}
else|else
block|{
comment|// the user canceled the dialog; font is set to the initial
comment|// value, in this case Helvetica [Cronyx], 10
block|}
end_if
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|myWidget
operator|.
name|setFont
argument_list|(
name|QFontDialog
operator|::
name|getFont
argument_list|(
literal|0
argument_list|,
name|myWidget
operator|.
name|font
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|ok
name|bool
name|ok
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|font
name|QFont
name|font
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|,
name|QFont
argument_list|(
literal|"Times"
argument_list|,
literal|12
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|ok
condition|)
block|{
comment|// font is set to the font the user selected
block|}
else|else
block|{
comment|// the user canceled the dialog; font is set to the initial
comment|// value, in this case Times, 12.
block|}
end_if
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|myWidget
operator|.
name|setFont
argument_list|(
name|QFontDialog
operator|::
name|getFont
argument_list|(
literal|0
argument_list|,
name|myWidget
operator|.
name|font
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|ok
name|bool
name|ok
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|font
name|QFont
name|font
init|=
name|QFontDialog
operator|::
name|getFont
argument_list|(
operator|&
name|ok
argument_list|,
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|ok
condition|)
block|{
comment|// font is set to the font the user selected
block|}
else|else
block|{
comment|// the user canceled the dialog; font is set to the default
comment|// application font, QApplication::font()
block|}
end_if
begin_comment
comment|//! [4]
end_comment
end_unit
