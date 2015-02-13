begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|tr
name|QString
name|tr
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|)
block|{
return|return
name|QApplication
operator|::
name|translate
argument_list|(
name|text
argument_list|,
name|text
argument_list|)
return|;
block|}
end_function
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
name|QTextEdit
modifier|*
name|editor
init|=
operator|new
name|QTextEdit
argument_list|()
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|editor
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
comment|//! [0]
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextBlockFormat
name|blockFormat
init|=
name|cursor
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
name|blockFormat
operator|.
name|setTopMargin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|blockFormat
operator|.
name|setLeftMargin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|blockFormat
operator|.
name|setRightMargin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|blockFormat
operator|.
name|setBottomMargin
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|blockFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"This contains plain text inside a "
literal|"text block with margins to keep it separate "
literal|"from other parts of the document."
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
comment|//! [1]
name|QTextBlockFormat
name|backgroundFormat
init|=
name|blockFormat
decl_stmt|;
name|backgroundFormat
operator|.
name|setBackground
argument_list|(
name|QColor
argument_list|(
literal|"lightGray"
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|backgroundFormat
argument_list|)
expr_stmt|;
comment|//! [1]
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"The background color of a text block can be "
literal|"changed to highlight text."
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QTextBlockFormat
name|rightAlignedFormat
init|=
name|blockFormat
decl_stmt|;
name|rightAlignedFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|rightAlignedFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"The alignment of the text within a block is "
literal|"controlled by the alignment properties of "
literal|"the block itself. This text block is "
literal|"right-aligned."
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QTextBlockFormat
name|paragraphFormat
init|=
name|blockFormat
decl_stmt|;
name|paragraphFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignJustify
argument_list|)
expr_stmt|;
name|paragraphFormat
operator|.
name|setTextIndent
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|paragraphFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"Text can be formatted so that the first "
literal|"line in a paragraph has its own margin. "
literal|"This makes the text more readable."
argument_list|)
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QTextBlockFormat
name|reverseFormat
init|=
name|blockFormat
decl_stmt|;
name|reverseFormat
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignJustify
argument_list|)
expr_stmt|;
name|reverseFormat
operator|.
name|setTextIndent
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|reverseFormat
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
name|tr
argument_list|(
literal|"The direction of the text can be reversed. "
literal|"This is useful for right-to-left "
literal|"languages."
argument_list|)
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Block Formats"
argument_list|)
argument_list|)
expr_stmt|;
name|editor
operator|->
name|resize
argument_list|(
literal|480
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|editor
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
