begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ITEMRECYCLINGLISTVIEW_H
end_ifndef
begin_define
DECL|macro|ITEMRECYCLINGLISTVIEW_H
define|#
directive|define
name|ITEMRECYCLINGLISTVIEW_H
end_define
begin_include
include|#
directive|include
file|"abstractitemview.h"
end_include
begin_decl_stmt
name|class
name|ItemRecyclingListView
range|:
name|public
name|AbstractItemView
block|{
name|public
operator|:
name|ItemRecyclingListView
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
name|ItemRecyclingListView
argument_list|()
block|;
name|void
name|setCurrentRow
argument_list|(
argument|const int row
argument_list|)
block|;
name|int
name|rows
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|listItemCaching
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setListItemCaching
argument_list|(
argument|bool enabled
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|void
name|rowsInserted
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
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|private
operator|:
name|QModelIndex
name|m_rootIndex
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ITEMRECYCLINGLISTVIEW_H
end_comment
end_unit
