begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTREEWIDGETITEMITERATOR_P_H
end_ifndef
begin_define
DECL|macro|QTREEWIDGETITEMITERATOR_P_H
define|#
directive|define
name|QTREEWIDGETITEMITERATOR_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TREEWIDGET
end_ifndef
begin_include
include|#
directive|include
file|"qtreewidgetitemiterator.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTreeModel
name|class
name|QTreeModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItem
name|class
name|QTreeWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTreeWidgetItemIteratorPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTreeWidgetItemIterator
argument_list|)
name|public
label|:
name|QTreeWidgetItemIteratorPrivate
argument_list|(
name|QTreeWidgetItemIterator
operator|*
name|q
argument_list|,
name|QTreeModel
operator|*
name|model
argument_list|)
operator|:
name|m_currentIndex
argument_list|(
literal|0
argument_list|)
operator|,
name|m_model
argument_list|(
name|model
argument_list|)
operator|,
name|q_ptr
argument_list|(
argument|q
argument_list|)
block|{      }
name|QTreeWidgetItemIteratorPrivate
argument_list|(
specifier|const
name|QTreeWidgetItemIteratorPrivate
operator|&
name|other
argument_list|)
operator|:
name|m_currentIndex
argument_list|(
name|other
operator|.
name|m_currentIndex
argument_list|)
operator|,
name|m_model
argument_list|(
name|other
operator|.
name|m_model
argument_list|)
operator|,
name|m_parentIndex
argument_list|(
name|other
operator|.
name|m_parentIndex
argument_list|)
operator|,
name|q_ptr
argument_list|(
argument|other.q_ptr
argument_list|)
block|{      }
name|QTreeWidgetItemIteratorPrivate
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QTreeWidgetItemIteratorPrivate
operator|&
name|other
operator|)
block|{
name|m_currentIndex
operator|=
name|other
operator|.
name|m_currentIndex
block|;
name|m_parentIndex
operator|=
name|other
operator|.
name|m_parentIndex
block|;
name|m_model
operator|=
name|other
operator|.
name|m_model
block|;
return|return
operator|(
operator|*
name|this
operator|)
return|;
block|}
operator|~
name|QTreeWidgetItemIteratorPrivate
argument_list|()
block|{     }
name|QTreeWidgetItem
operator|*
name|nextSibling
argument_list|(
argument|const QTreeWidgetItem* item
argument_list|)
specifier|const
expr_stmt|;
name|void
name|ensureValidIterator
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|itemToBeRemoved
parameter_list|)
function_decl|;
name|QTreeWidgetItem
modifier|*
name|next
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
function_decl|;
name|QTreeWidgetItem
modifier|*
name|previous
parameter_list|(
specifier|const
name|QTreeWidgetItem
modifier|*
name|current
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_currentIndex
decl_stmt|;
name|QTreeModel
modifier|*
name|m_model
decl_stmt|;
comment|// This iterator class should not have ownership of the model.
name|QStack
operator|<
name|int
operator|>
name|m_parentIndex
expr_stmt|;
name|QTreeWidgetItemIterator
modifier|*
name|q_ptr
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TREEWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QTREEWIDGETITEMITERATOR_P_H
end_comment
end_unit
