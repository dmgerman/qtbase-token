begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MODEL_H
end_ifndef
begin_define
DECL|macro|MODEL_H
define|#
directive|define
name|MODEL_H
end_define
begin_include
include|#
directive|include
file|<QAbstractListModel>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|StringListModel
range|:
name|public
name|QAbstractListModel
block|{
name|Q_OBJECT
name|public
operator|:
name|StringListModel
argument_list|(
specifier|const
name|QStringList
operator|&
name|strings
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAbstractListModel
argument_list|(
name|parent
argument_list|)
block|,
name|stringList
argument_list|(
argument|strings
argument_list|)
block|{}
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
comment|//! [0] //! [1]
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
comment|//! [1]
comment|//! [2]
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
comment|//! [2] //! [3]
argument|int role = Qt::EditRole
argument_list|)
block|;
comment|//! [3]
comment|//! [4]
name|bool
name|insertRows
argument_list|(
argument|int position
argument_list|,
argument|int rows
argument_list|,
argument|const QModelIndex&index = QModelIndex()
argument_list|)
block|;
name|bool
name|removeRows
argument_list|(
argument|int position
argument_list|,
argument|int rows
argument_list|,
argument|const QModelIndex&index = QModelIndex()
argument_list|)
block|;
comment|//! [4]
comment|//! [5]
name|private
operator|:
name|QStringList
name|stringList
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
