begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"stardelegate.h"
end_include
begin_include
include|#
directive|include
file|"stareditor.h"
end_include
begin_include
include|#
directive|include
file|"starrating.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|paint
name|void
name|StarDelegate
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|()
operator|.
name|canConvert
argument_list|<
name|StarRating
argument_list|>
argument_list|()
condition|)
block|{
name|StarRating
name|starRating
init|=
name|qvariant_cast
argument_list|<
name|StarRating
argument_list|>
argument_list|(
name|index
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|option
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Selected
condition|)
name|painter
operator|->
name|fillRect
argument_list|(
name|option
operator|.
name|rect
argument_list|,
name|option
operator|.
name|palette
operator|.
name|highlight
argument_list|()
argument_list|)
expr_stmt|;
name|starRating
operator|.
name|paint
argument_list|(
name|painter
argument_list|,
name|option
operator|.
name|rect
argument_list|,
name|option
operator|.
name|palette
argument_list|,
name|StarRating
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QStyledItemDelegate
operator|::
name|paint
argument_list|(
name|painter
argument_list|,
name|option
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
comment|//! [0]
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|StarDelegate
operator|::
name|sizeHint
parameter_list|(
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|()
operator|.
name|canConvert
argument_list|<
name|StarRating
argument_list|>
argument_list|()
condition|)
block|{
name|StarRating
name|starRating
init|=
name|qvariant_cast
argument_list|<
name|StarRating
argument_list|>
argument_list|(
name|index
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|starRating
operator|.
name|sizeHint
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|QStyledItemDelegate
operator|::
name|sizeHint
argument_list|(
name|option
argument_list|,
name|index
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|StarDelegate
operator|::
name|createEditor
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|()
operator|.
name|canConvert
argument_list|<
name|StarRating
argument_list|>
argument_list|()
condition|)
block|{
name|StarEditor
modifier|*
name|editor
init|=
operator|new
name|StarEditor
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|editor
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|commitAndCloseEditor
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|editor
return|;
block|}
else|else
block|{
return|return
name|QStyledItemDelegate
operator|::
name|createEditor
argument_list|(
name|parent
argument_list|,
name|option
argument_list|,
name|index
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|setEditorData
name|void
name|StarDelegate
operator|::
name|setEditorData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|()
operator|.
name|canConvert
argument_list|<
name|StarRating
argument_list|>
argument_list|()
condition|)
block|{
name|StarRating
name|starRating
init|=
name|qvariant_cast
argument_list|<
name|StarRating
argument_list|>
argument_list|(
name|index
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|StarEditor
modifier|*
name|starEditor
init|=
name|qobject_cast
argument_list|<
name|StarEditor
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
name|starEditor
operator|->
name|setStarRating
argument_list|(
name|starRating
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QStyledItemDelegate
operator|::
name|setEditorData
argument_list|(
name|editor
argument_list|,
name|index
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|setModelData
name|void
name|StarDelegate
operator|::
name|setModelData
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|()
operator|.
name|canConvert
argument_list|<
name|StarRating
argument_list|>
argument_list|()
condition|)
block|{
name|StarEditor
modifier|*
name|starEditor
init|=
name|qobject_cast
argument_list|<
name|StarEditor
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|starEditor
operator|->
name|starRating
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QStyledItemDelegate
operator|::
name|setModelData
argument_list|(
name|editor
argument_list|,
name|model
argument_list|,
name|index
argument_list|)
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
DECL|function|commitAndCloseEditor
name|void
name|StarDelegate
operator|::
name|commitAndCloseEditor
parameter_list|()
block|{
name|StarEditor
modifier|*
name|editor
init|=
name|qobject_cast
argument_list|<
name|StarEditor
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
emit|emit
name|commitData
argument_list|(
name|editor
argument_list|)
emit|;
emit|emit
name|closeEditor
argument_list|(
name|editor
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
end_unit
