begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|AppendText
class|class
name|AppendText
super|:
specifier|public
name|QUndoCommand
block|{
public|public:
DECL|function|AppendText
name|AppendText
parameter_list|(
name|QString
modifier|*
name|doc
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
member_init_list|:
name|m_document
argument_list|(
name|doc
argument_list|)
member_init_list|,
name|m_text
argument_list|(
name|text
argument_list|)
block|{
name|setText
argument_list|(
literal|"append text"
argument_list|)
expr_stmt|;
block|}
DECL|function|undo
specifier|virtual
name|void
name|undo
parameter_list|()
block|{
name|m_document
operator|->
name|chop
argument_list|(
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|redo
specifier|virtual
name|void
name|redo
parameter_list|()
block|{
name|m_document
operator|->
name|append
argument_list|(
name|m_text
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|m_document
name|QString
modifier|*
name|m_document
decl_stmt|;
DECL|member|m_text
name|QString
name|m_text
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|command1
name|MyCommand
modifier|*
name|command1
init|=
operator|new
name|MyCommand
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|stack
operator|->
name|push
argument_list|(
name|command1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|command2
name|MyCommand
modifier|*
name|command2
init|=
operator|new
name|MyCommand
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|stack
operator|->
name|push
argument_list|(
name|command2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|->
name|undo
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|command3
name|MyCommand
modifier|*
name|command3
init|=
operator|new
name|MyCommand
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|stack
operator|->
name|push
argument_list|(
name|command3
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// command2 gets deleted
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|insertRed
name|QUndoCommand
modifier|*
name|insertRed
init|=
operator|new
name|QUndoCommand
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|insertRed
comment|// an empty command
end_comment
begin_expr_stmt
name|insertRed
operator|->
name|setText
argument_list|(
literal|"insert red text"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|new
name|InsertText
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
argument_list|,
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// becomes child of insertRed
end_comment
begin_expr_stmt
operator|new
name|SetColor
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
name|Qt
operator|::
name|red
argument_list|,
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|.
name|push
argument_list|(
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|mergeWith
name|bool
name|AppendText
operator|::
name|mergeWith
parameter_list|(
specifier|const
name|QUndoCommand
modifier|*
name|other
parameter_list|)
block|{
if|if
condition|(
name|other
operator|->
name|id
argument_list|()
operator|!=
name|id
argument_list|()
condition|)
comment|// make sure other is also an AppendText command
return|return
literal|false
return|;
name|m_text
operator|+=
cast|static_cast
argument_list|<
specifier|const
name|AppendText
operator|*
argument_list|>
argument_list|(
name|other
argument_list|)
operator|->
name|m_text
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"insert red text"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertText
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|.
name|push
argument_list|(
operator|new
name|SetColor
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// indexChanged() is emitted
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|insertRed
name|QUndoCommand
modifier|*
name|insertRed
init|=
operator|new
name|QUndoCommand
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|insertRed
comment|// an empty command
end_comment
begin_expr_stmt
name|insertRed
operator|->
name|setText
argument_list|(
literal|"insert red text"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|new
name|InsertText
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
argument_list|,
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// becomes child of insertRed
end_comment
begin_expr_stmt
operator|new
name|SetColor
argument_list|(
name|document
argument_list|,
name|idx
argument_list|,
name|text
operator|.
name|length
argument_list|()
argument_list|,
name|Qt
operator|::
name|red
argument_list|,
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|stack
operator|.
name|push
argument_list|(
name|insertRed
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
