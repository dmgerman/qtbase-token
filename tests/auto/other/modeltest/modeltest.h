begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MODELTEST_H
end_ifndef
begin_define
DECL|macro|MODELTEST_H
define|#
directive|define
name|MODELTEST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStack>
end_include
begin_decl_stmt
name|class
name|ModelTest
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|ModelTest
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|nonDestructiveBasicTest
argument_list|()
block|;
name|void
name|rowCount
argument_list|()
block|;
name|void
name|columnCount
argument_list|()
block|;
name|void
name|hasIndex
argument_list|()
block|;
name|void
name|index
argument_list|()
block|;
name|void
name|parent
argument_list|()
block|;
name|void
name|data
argument_list|()
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|runAllTests
argument_list|()
block|;
name|void
name|layoutAboutToBeChanged
argument_list|()
block|;
name|void
name|layoutChanged
argument_list|()
block|;
name|void
name|rowsAboutToBeInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|rowsInserted
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|rowsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|rowsRemoved
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|dataChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|topLeft
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|bottomRight
argument_list|)
block|;
name|void
name|headerDataChanged
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|private
operator|:
name|void
name|checkChildren
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int currentDepth =
literal|0
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|model
block|;    struct
name|Changing
block|{
name|QModelIndex
name|parent
block|;
name|int
name|oldSize
block|;
name|QVariant
name|last
block|;
name|QVariant
name|next
block|;   }
block|;
name|QStack
operator|<
name|Changing
operator|>
name|insert
block|;
name|QStack
operator|<
name|Changing
operator|>
name|remove
block|;
name|bool
name|fetchingMore
block|;
name|QList
operator|<
name|QPersistentModelIndex
operator|>
name|changing
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
