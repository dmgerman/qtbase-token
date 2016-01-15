begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QStyleOptionGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneResizeEvent>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QRectF>
end_include
begin_include
include|#
directive|include
file|"backgrounditem.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_constructor
DECL|function|BackgroundItem
name|BackgroundItem
operator|::
name|BackgroundItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_background
argument_list|()
member_init_list|,
name|m_fileName
argument_list|(
name|filename
argument_list|)
block|{
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|themeChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|themeChange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~BackgroundItem
name|BackgroundItem
operator|::
name|~
name|BackgroundItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|resizeEvent
name|void
name|BackgroundItem
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|GvbWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|m_background
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
name|m_fileName
argument_list|,
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|BackgroundItem
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|widget
argument_list|)
name|painter
operator|->
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|option
operator|->
name|exposedRect
argument_list|,
name|m_background
argument_list|,
name|option
operator|->
name|exposedRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|themeChange
name|void
name|BackgroundItem
operator|::
name|themeChange
parameter_list|()
block|{
name|m_background
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
name|m_fileName
argument_list|,
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
