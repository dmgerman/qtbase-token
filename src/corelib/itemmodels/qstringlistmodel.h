begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGLISTMODEL_H
end_ifndef
begin_define
DECL|macro|QSTRINGLISTMODEL_H
define|#
directive|define
name|QSTRINGLISTMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STRINGLISTMODEL
name|class
name|Q_CORE_EXPORT
name|QStringListModel
range|:
name|public
name|QAbstractListModel
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QStringListModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QStringListModel
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
name|Q_NULLPTR
argument_list|)
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|sibling
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&idx
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|setData
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QVariant&value
argument_list|,
argument|int role = Qt::EditRole
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|insertRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|removeRows
argument_list|(
argument|int row
argument_list|,
argument|int count
argument_list|,
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|sort
argument_list|(
argument|int column
argument_list|,
argument|Qt::SortOrder order = Qt::AscendingOrder
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|stringList
argument_list|()
specifier|const
block|;
name|void
name|setStringList
argument_list|(
specifier|const
name|QStringList
operator|&
name|strings
argument_list|)
block|;
name|Qt
operator|::
name|DropActions
name|supportedDropActions
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QStringListModel
argument_list|)
name|QStringList
name|lst
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STRINGLISTMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGLISTMODEL_H
end_comment
end_unit
