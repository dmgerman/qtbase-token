begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ABSTRACTVIEWITEM_H
end_ifndef
begin_define
DECL|macro|ABSTRACTVIEWITEM_H
define|#
directive|define
name|ABSTRACTVIEWITEM_H
end_define
begin_include
include|#
directive|include
file|<QModelIndex>
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_include
include|#
directive|include
file|"abstractitemview.h"
end_include
begin_include
include|#
directive|include
file|"listitem.h"
end_include
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AbstractViewItem
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|AbstractViewItem
argument_list|(
name|QGraphicsWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|AbstractViewItem
argument_list|()
block|;
name|virtual
name|AbstractViewItem
operator|*
name|newItemInstance
argument_list|()
operator|=
literal|0
block|;
name|QModelIndex
name|modelIndex
argument_list|()
specifier|const
block|;
name|void
name|setModelIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|AbstractViewItem
operator|*
name|prototype
argument_list|()
specifier|const
block|;
name|AbstractItemView
operator|*
name|itemView
argument_list|()
specifier|const
block|;
name|void
name|setItemView
argument_list|(
name|AbstractItemView
operator|*
name|itemView
argument_list|)
block|;
name|virtual
name|void
name|updateItemContents
argument_list|()
block|;
name|virtual
name|void
name|themeChange
argument_list|()
block|;
name|virtual
name|void
name|setSubtreeCacheEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|virtual
name|QSizeF
name|effectiveSizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QVariant
name|data
argument_list|(
argument|int role
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setData
argument_list|(
argument|const QVariant&value
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setTwoColumns
argument_list|(
argument|const bool enabled
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|virtual
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|QPersistentModelIndex
name|m_index
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|AbstractViewItem
argument_list|)
name|AbstractItemView
operator|*
name|m_itemView
block|;
name|AbstractViewItem
operator|*
name|m_prototype
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ABSTRACTVIEWITEM_H
end_comment
end_unit
