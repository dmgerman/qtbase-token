begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ABSTRACTSCROLLAREA_H
end_ifndef
begin_define
DECL|macro|ABSTRACTSCROLLAREA_H
define|#
directive|define
name|ABSTRACTSCROLLAREA_H
end_define
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_decl_stmt
DECL|variable|ScrollBar
name|class
name|ScrollBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsGridLayout
name|class
name|QGraphicsGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AbstractScrollArea
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|AbstractScrollArea
argument_list|(
name|QGraphicsWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|AbstractScrollArea
argument_list|()
block|;
name|public
operator|:
name|void
name|setHorizontalScrollBarPolicy
argument_list|(
argument|Qt::ScrollBarPolicy policy
argument_list|)
block|;
name|void
name|setVerticalScrollBarPolicy
argument_list|(
argument|Qt::ScrollBarPolicy policy
argument_list|)
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|verticalScrollBarPolicy
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|horizontalScrollBarPolicy
argument_list|()
specifier|const
block|;
name|QGraphicsWidget
operator|*
name|viewport
argument_list|()
specifier|const
block|;
name|void
name|setViewport
argument_list|(
name|QGraphicsWidget
operator|*
name|viewport
argument_list|)
block|;
name|ScrollBar
operator|*
name|verticalScrollBar
argument_list|()
specifier|const
block|;
name|ScrollBar
operator|*
name|horizontalScrollBar
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|viewportChanged
argument_list|(
name|QGraphicsWidget
operator|*
name|viewport
argument_list|)
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
name|virtual
name|void
name|scrollContentsBy
argument_list|(
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|verticalScrollStart
argument_list|()
block|;
name|void
name|verticalScroll
argument_list|(
name|qreal
argument_list|)
block|;
name|void
name|horizontalScrollStart
argument_list|()
block|;
name|void
name|horizontalScroll
argument_list|(
name|qreal
argument_list|)
block|;
name|private
operator|:
name|void
name|adjustScrollBars
argument_list|()
block|;
name|QGraphicsWidget
operator|*
name|m_viewport
block|;
name|ScrollBar
operator|*
name|m_horizontalScrollBar
block|;
name|ScrollBar
operator|*
name|m_verticalScrollBar
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|m_verticalScrollBarPolicy
block|;
name|Qt
operator|::
name|ScrollBarPolicy
name|m_horizontalScrollBarPolicy
block|;
name|qreal
name|m_prevHorizontalValue
block|;
name|qreal
name|m_prevVerticalValue
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ABSTRACTSCROLLAREA_H
end_comment
end_unit
