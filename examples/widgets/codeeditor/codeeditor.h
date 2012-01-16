begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CODEEDITOR_H
end_ifndef
begin_define
DECL|macro|CODEEDITOR_H
define|#
directive|define
name|CODEEDITOR_H
end_define
begin_include
include|#
directive|include
file|<QPlainTextEdit>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QResizeEvent
name|class
name|QResizeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|LineNumberArea
name|class
name|LineNumberArea
decl_stmt|;
end_decl_stmt
begin_comment
comment|//![codeeditordefinition]
end_comment
begin_decl_stmt
name|class
name|CodeEditor
range|:
name|public
name|QPlainTextEdit
block|{
name|Q_OBJECT
name|public
operator|:
name|CodeEditor
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|lineNumberAreaPaintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|int
name|lineNumberAreaWidth
argument_list|()
block|;
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|updateLineNumberAreaWidth
argument_list|(
argument|int newBlockCount
argument_list|)
block|;
name|void
name|highlightCurrentLine
argument_list|()
block|;
name|void
name|updateLineNumberArea
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|,
name|int
argument_list|)
block|;
name|private
operator|:
name|QWidget
operator|*
name|lineNumberArea
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//![codeeditordefinition]
end_comment
begin_comment
comment|//![extraarea]
end_comment
begin_decl_stmt
name|class
name|LineNumberArea
range|:
name|public
name|QWidget
block|{
name|public
operator|:
name|LineNumberArea
argument_list|(
name|CodeEditor
operator|*
name|editor
argument_list|)
operator|:
name|QWidget
argument_list|(
argument|editor
argument_list|)
block|{
name|codeEditor
operator|=
name|editor
block|;     }
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|codeEditor
operator|->
name|lineNumberAreaWidth
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
block|{
name|codeEditor
operator|->
name|lineNumberAreaPaintEvent
argument_list|(
name|event
argument_list|)
block|;     }
name|private
operator|:
name|CodeEditor
operator|*
name|codeEditor
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//![extraarea]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
