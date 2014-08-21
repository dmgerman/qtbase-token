begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SIMPLELIST_H_
end_ifndef
begin_define
DECL|macro|SIMPLELIST_H_
define|#
directive|define
name|SIMPLELIST_H_
end_define
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_include
include|#
directive|include
file|"listitem.h"
end_include
begin_include
include|#
directive|include
file|"listwidget.h"
end_include
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SimpleList
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|SimpleList
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
name|SimpleList
argument_list|()
block|;
name|void
name|addItem
argument_list|(
name|ListItem
operator|*
name|item
argument_list|)
block|;
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|ListItem *item
argument_list|)
block|;
name|ListItem
operator|*
name|takeItem
argument_list|(
argument|int row
argument_list|)
block|;
name|ListItem
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
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
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
name|public
name|slots
operator|:
name|ScrollBar
operator|*
name|verticalScrollBar
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|SimpleList
argument_list|)
name|ListWidget
operator|*
name|m_list
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* LISTTEST_H_ */
end_comment
end_unit
