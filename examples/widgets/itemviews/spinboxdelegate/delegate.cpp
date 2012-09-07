begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*     delegate.cpp      A delegate that allows the user to change integer values from the model     using a spin box widget. */
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"delegate.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|SpinBoxDelegate
name|SpinBoxDelegate
operator|::
name|SpinBoxDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QStyledItemDelegate
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|SpinBoxDelegate
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
comment|/* option */
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
comment|/* index */
parameter_list|)
specifier|const
block|{
name|QSpinBox
modifier|*
name|editor
init|=
operator|new
name|QSpinBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|editor
operator|->
name|setFrame
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|editor
operator|->
name|setMaximum
argument_list|(
literal|100
argument_list|)
expr_stmt|;
return|return
name|editor
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
DECL|function|setEditorData
name|void
name|SpinBoxDelegate
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
name|int
name|value
init|=
name|index
operator|.
name|model
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|QSpinBox
modifier|*
name|spinBox
init|=
cast|static_cast
argument_list|<
name|QSpinBox
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
name|spinBox
operator|->
name|setValue
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|setModelData
name|void
name|SpinBoxDelegate
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
name|QSpinBox
modifier|*
name|spinBox
init|=
cast|static_cast
argument_list|<
name|QSpinBox
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
decl_stmt|;
name|spinBox
operator|->
name|interpretText
argument_list|()
expr_stmt|;
name|int
name|value
init|=
name|spinBox
operator|->
name|value
argument_list|()
decl_stmt|;
name|model
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|value
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|updateEditorGeometry
name|void
name|SpinBoxDelegate
operator|::
name|updateEditorGeometry
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
comment|/* index */
parameter_list|)
specifier|const
block|{
name|editor
operator|->
name|setGeometry
argument_list|(
name|option
operator|.
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
end_unit
