begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TREEITEM_H
end_ifndef
begin_define
DECL|macro|TREEITEM_H
define|#
directive|define
name|TREEITEM_H
end_define
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|TreeItem
block|{
name|public
label|:
name|explicit
name|TreeItem
argument_list|(
specifier|const
name|QVector
operator|<
name|QVariant
operator|>
operator|&
name|data
argument_list|,
name|TreeItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|TreeItem
argument_list|()
expr_stmt|;
name|TreeItem
modifier|*
name|child
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
name|int
name|childCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|columnCount
argument_list|()
specifier|const
expr_stmt|;
name|QVariant
name|data
argument_list|(
name|int
name|column
argument_list|)
decl|const
decl_stmt|;
name|bool
name|insertChildren
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|columns
parameter_list|)
function_decl|;
name|bool
name|insertColumns
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|columns
parameter_list|)
function_decl|;
name|TreeItem
modifier|*
name|parent
parameter_list|()
function_decl|;
name|bool
name|removeChildren
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|bool
name|removeColumns
parameter_list|(
name|int
name|position
parameter_list|,
name|int
name|columns
parameter_list|)
function_decl|;
name|int
name|childNumber
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|setData
parameter_list|(
name|int
name|column
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|private
label|:
name|QList
operator|<
name|TreeItem
operator|*
operator|>
name|childItems
expr_stmt|;
name|QVector
operator|<
name|QVariant
operator|>
name|itemData
expr_stmt|;
name|TreeItem
modifier|*
name|parentItem
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TREEITEM_H
end_comment
end_unit
