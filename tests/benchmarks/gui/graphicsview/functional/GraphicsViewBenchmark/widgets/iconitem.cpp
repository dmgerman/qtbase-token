begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QSvgRenderer>
end_include
begin_include
include|#
directive|include
file|<QGraphicsEffect>
end_include
begin_include
include|#
directive|include
file|"iconitem.h"
end_include
begin_constructor
DECL|function|IconItem
name|IconItem
operator|::
name|IconItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_filename
argument_list|(
name|filename
argument_list|)
member_init_list|,
name|m_rotation
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|m_opacityEffect
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_smoothTransformation
argument_list|(
literal|false
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|)
expr_stmt|;
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
name|setPreferredSize
argument_list|(
literal|58
argument_list|,
literal|58
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~IconItem
name|IconItem
operator|::
name|~
name|IconItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|paint
name|void
name|IconItem
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
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|reload
argument_list|()
expr_stmt|;
specifier|const
name|QPointF
name|c
init|=
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
decl_stmt|;
name|painter
operator|->
name|translate
argument_list|(
name|c
operator|.
name|x
argument_list|()
argument_list|,
name|c
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|rotate
argument_list|(
name|m_rotation
argument_list|)
expr_stmt|;
name|painter
operator|->
name|translate
argument_list|(
operator|-
name|c
operator|.
name|x
argument_list|()
argument_list|,
operator|-
name|c
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_smoothTransformation
condition|)
name|painter
operator|->
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_pixmap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|IconItem
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
case|case
name|Qt
operator|::
name|PreferredSize
case|:
case|case
name|Qt
operator|::
name|MaximumSize
case|:
return|return
name|m_pixmap
operator|.
name|size
argument_list|()
return|;
default|default:
return|return
name|GvbWidget
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|reload
name|void
name|IconItem
operator|::
name|reload
parameter_list|()
block|{
specifier|const
name|QSize
name|iconSize
init|=
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|iconSize
operator|.
name|width
argument_list|()
operator|==
literal|0
operator|||
name|iconSize
operator|.
name|height
argument_list|()
operator|==
literal|0
condition|)
return|return;
specifier|const
name|QString
name|key
init|=
name|m_filename
operator|+
name|QString
operator|::
name|number
argument_list|(
name|iconSize
operator|.
name|width
argument_list|()
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|iconSize
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
argument_list|,
name|m_pixmap
argument_list|)
condition|)
return|return;
if|if
condition|(
name|m_filename
operator|.
name|endsWith
argument_list|(
literal|".svg"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
name|m_pixmap
operator|=
name|QPixmap
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|m_pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QSvgRenderer
name|doc
argument_list|(
name|m_filename
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|m_pixmap
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|iconSize
operator|.
name|width
argument_list|()
argument_list|,
name|iconSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|doc
operator|.
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_pixmap
operator|=
name|QPixmap
argument_list|(
name|m_filename
argument_list|)
operator|.
name|scaled
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
block|}
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|key
argument_list|,
name|m_pixmap
argument_list|)
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileName
name|QString
name|IconItem
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
return|return
name|m_filename
return|;
block|}
end_function
begin_function
DECL|function|setFileName
name|void
name|IconItem
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
block|{
if|if
condition|(
name|m_filename
operator|!=
name|filename
condition|)
block|{
name|m_filename
operator|=
name|filename
expr_stmt|;
name|reload
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setOpacityEffectEnabled
name|void
name|IconItem
operator|::
name|setOpacityEffectEnabled
parameter_list|(
specifier|const
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_opacityEffect
condition|)
block|{
name|QRadialGradient
name|gradient
argument_list|(
literal|0.5
argument_list|,
literal|0.5
argument_list|,
literal|1.0
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setCoordinateMode
argument_list|(
name|QGradient
operator|::
name|ObjectBoundingMode
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.46
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.62
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|m_opacityEffect
operator|=
operator|new
name|QGraphicsOpacityEffect
expr_stmt|;
name|m_opacityEffect
operator|->
name|setOpacityMask
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
name|m_opacityEffect
operator|->
name|setOpacity
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|this
operator|->
name|setGraphicsEffect
argument_list|(
name|m_opacityEffect
argument_list|)
expr_stmt|;
block|}
name|m_opacityEffect
operator|->
name|setEnabled
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isOpacityEffectEnabled
name|bool
name|IconItem
operator|::
name|isOpacityEffectEnabled
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_opacityEffect
condition|)
return|return
name|m_opacityEffect
operator|->
name|isEnabled
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
end_unit
