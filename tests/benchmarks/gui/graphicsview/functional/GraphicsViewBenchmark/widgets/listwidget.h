begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LISTWIDGET_H
end_ifndef
begin_define
DECL|macro|LISTWIDGET_H
define|#
directive|define
name|LISTWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsWidget>
end_include
begin_include
include|#
directive|include
file|"simplelistview.h"
end_include
begin_include
include|#
directive|include
file|"scroller.h"
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_decl_stmt
DECL|variable|AbstractViewItem
name|class
name|AbstractViewItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneResizeEvent
name|class
name|QGraphicsSceneResizeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsGridLayout
name|class
name|QGraphicsGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsLinearLayout
name|class
name|QGraphicsLinearLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ListWidget
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ListWidget
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
name|ListWidget
argument_list|()
block|;
name|void
name|addItem
argument_list|(
name|QGraphicsWidget
operator|*
name|item
argument_list|)
block|;
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QGraphicsWidget *item
argument_list|)
block|;
name|QGraphicsWidget
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|)
block|;
name|QGraphicsWidget
operator|*
name|itemAt
argument_list|(
argument|int row
argument_list|)
block|;
name|int
name|itemCount
argument_list|()
specifier|const
block|;
name|bool
name|listItemCaching
argument_list|()
specifier|const
block|;
name|void
name|setListItemCaching
argument_list|(
argument|bool enable
argument_list|)
block|;
name|ScrollBar
operator|*
name|verticalScrollBar
argument_list|()
specifier|const
block|;
name|void
name|setTwoColumns
argument_list|(
argument|const bool twoColumns
argument_list|)
block|;
name|bool
name|twoColumns
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QGraphicsSceneResizeEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|ListWidget
argument_list|)
name|QGraphicsLinearLayout
operator|*
name|m_layout
block|;
name|SimpleListView
operator|*
name|m_listView
block|;
name|Scroller
name|m_scroller
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
