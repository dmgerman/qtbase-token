begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
