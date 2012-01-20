begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|dragEnterEvent
name|void
name|MyWidget
operator|::
name|dragEnterEvent
parameter_list|(
name|QDragEnterEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasUrls
argument_list|()
condition|)
name|event
operator|->
name|acceptProposedAction
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dropEvent
name|void
name|MyWidget
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasUrls
argument_list|()
condition|)
block|{
foreach|foreach
control|(
name|QUrl
name|url
decl|,
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|urls
argument_list|()
control|)
block|{
operator|...
block|}
block|}
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|csvData
name|QByteArray
name|csvData
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|mimeData
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|mimeData
operator|->
name|setData
argument_list|(
literal|"text/csv"
argument_list|,
name|csvData
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
DECL|function|dropEvent
name|void
name|MyWidget
operator|::
name|dropEvent
parameter_list|(
name|QDropEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|MyMimeData
modifier|*
name|myData
init|=
name|qobject_cast
argument_list|<
specifier|const
name|MyMimeData
operator|*
argument_list|>
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|myData
condition|)
block|{
comment|// access myData's data directly (not through QMimeData's API)
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|application
operator|/
name|x
operator|-
name|qt
operator|-
name|windows
operator|-
name|mime
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|value
operator|=
literal|"<custom type>"
comment|//! [3]
comment|//! [4]
name|application
operator|/
name|x
operator|-
name|qt
operator|-
name|windows
operator|-
name|mime
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|value
operator|=
literal|"FileGroupDescriptor"
name|application
operator|/
name|x
operator|-
name|qt
operator|-
name|windows
operator|-
name|mime
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|value
operator|=
literal|"FileContents"
end_expr_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_if
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|QImage
name|image
init|=
name|qvariant_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|imageData
argument_list|()
argument_list|)
decl_stmt|;
operator|...
block|}
end_if
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_expr_stmt
name|mimeData
operator|->
name|setImageData
argument_list|(
name|QImage
argument_list|(
literal|"beautifulfjord.png"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_if
if|if
condition|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|hasColor
argument_list|()
condition|)
block|{
name|QColor
name|color
init|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|event
operator|->
name|mimeData
argument_list|()
operator|->
name|colorData
argument_list|()
argument_list|)
decl_stmt|;
operator|...
block|}
end_if
begin_comment
comment|//! [7]
end_comment
end_unit
