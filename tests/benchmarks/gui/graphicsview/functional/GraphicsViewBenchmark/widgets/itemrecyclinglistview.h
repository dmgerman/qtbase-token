begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
