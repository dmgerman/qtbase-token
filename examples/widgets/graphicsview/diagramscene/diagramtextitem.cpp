begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"diagramtextitem.h"
end_include
begin_include
include|#
directive|include
file|"diagramscene.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DiagramTextItem
name|DiagramTextItem
operator|::
name|DiagramTextItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsTextItem
argument_list|(
name|parent
argument_list|)
block|{
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|itemChange
name|QVariant
name|DiagramTextItem
operator|::
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|change
operator|==
name|QGraphicsItem
operator|::
name|ItemSelectedHasChanged
condition|)
emit|emit
name|selectedChange
argument_list|(
name|this
argument_list|)
emit|;
return|return
name|value
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|focusOutEvent
name|void
name|DiagramTextItem
operator|::
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
name|event
parameter_list|)
block|{
name|setTextInteractionFlags
argument_list|(
name|Qt
operator|::
name|NoTextInteraction
argument_list|)
expr_stmt|;
emit|emit
name|lostFocus
argument_list|(
name|this
argument_list|)
emit|;
name|QGraphicsTextItem
operator|::
name|focusOutEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|DiagramTextItem
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|textInteractionFlags
argument_list|()
operator|==
name|Qt
operator|::
name|NoTextInteraction
condition|)
name|setTextInteractionFlags
argument_list|(
name|Qt
operator|::
name|TextEditorInteraction
argument_list|)
expr_stmt|;
name|QGraphicsTextItem
operator|::
name|mouseDoubleClickEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
