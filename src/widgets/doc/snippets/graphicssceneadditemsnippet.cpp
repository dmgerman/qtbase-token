begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_class
DECL|class|CustomScene
class|class
name|CustomScene
super|:
specifier|public
name|QGraphicsScene
block|{
public|public:
DECL|function|CustomScene
name|CustomScene
parameter_list|()
block|{
name|addItem
argument_list|(
operator|new
name|QGraphicsEllipseItem
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|30
argument_list|,
literal|30
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|drawItems
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|int
name|numItems
parameter_list|,
name|QGraphicsItem
modifier|*
name|items
index|[]
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
name|options
index|[]
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|drawItems
name|void
name|CustomScene
operator|::
name|drawItems
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|int
name|numItems
parameter_list|,
name|QGraphicsItem
modifier|*
name|items
index|[]
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
name|options
index|[]
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numItems
condition|;
operator|++
name|i
control|)
block|{
comment|// Draw the item
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setMatrix
argument_list|(
name|items
index|[
name|i
index|]
operator|->
name|sceneMatrix
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|items
index|[
name|i
index|]
operator|->
name|paint
argument_list|(
name|painter
argument_list|,
operator|&
name|options
index|[
name|i
index|]
argument_list|,
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argv
argument_list|,
name|args
argument_list|)
decl_stmt|;
name|CustomScene
name|scene
decl_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
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
