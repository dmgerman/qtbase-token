begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|createApplication
name|QCoreApplication
modifier|*
name|createApplication
parameter_list|(
name|int
modifier|&
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
literal|"-no-gui"
argument_list|)
condition|)
return|return
operator|new
name|QCoreApplication
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
return|return
operator|new
name|QApplication
argument_list|(
name|argc
argument_list|,
name|argv
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
name|QScopedPointer
argument_list|<
name|QCoreApplication
argument_list|>
name|app
argument_list|(
name|createApplication
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|qobject_cast
argument_list|<
name|QApplication
operator|*
argument_list|>
argument_list|(
name|app
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
comment|// start GUI version...
block|}
else|else
block|{
comment|// start non-GUI version...
block|}
return|return
name|app
operator|->
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|QApplication
operator|::
name|setStyle
argument_list|(
name|QStyleFactory
operator|::
name|create
argument_list|(
literal|"fusion"
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
operator|::
name|setColorSpec
argument_list|(
name|QApplication
operator|::
name|ManyColor
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
operator|...
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|MyWidget
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|80
argument_list|,
literal|25
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|showAllHiddenTopLevelWidgets
name|void
name|showAllHiddenTopLevelWidgets
parameter_list|()
block|{
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
block|{
if|if
condition|(
name|widget
operator|->
name|isHidden
argument_list|()
condition|)
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|updateAllWidgets
name|void
name|updateAllWidgets
parameter_list|()
block|{
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|QApplication
operator|::
name|allWidgets
argument_list|()
control|)
name|widget
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_if
if|if
condition|(
operator|(
name|startPos
operator|-
name|currentPos
operator|)
operator|.
name|manhattanLength
argument_list|()
operator|>=
name|QApplication
operator|::
name|startDragDistance
argument_list|()
condition|)
name|startTheDrag
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|widget
name|QWidget
modifier|*
name|widget
init|=
name|qApp
operator|->
name|widgetAt
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|widget
condition|)
name|widget
operator|=
name|widget
operator|->
name|window
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|widget
name|QWidget
modifier|*
name|widget
init|=
name|qApp
operator|->
name|widgetAt
argument_list|(
name|point
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|widget
condition|)
name|widget
operator|=
name|widget
operator|->
name|window
argument_list|()
expr_stmt|;
end_if
begin_comment
comment|//! [8]
end_comment
end_unit
