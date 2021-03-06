begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgraphicslayoutstyleinfo_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_include
include|#
directive|include
file|"qgraphicslayout_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicswidget.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qapplication.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QGraphicsLayoutStyleInfo
name|QGraphicsLayoutStyleInfo
operator|::
name|QGraphicsLayoutStyleInfo
parameter_list|(
specifier|const
name|QGraphicsLayoutPrivate
modifier|*
name|layout
parameter_list|)
member_init_list|:
name|m_layout
argument_list|(
name|layout
argument_list|)
member_init_list|,
name|m_style
argument_list|(
literal|0
argument_list|)
block|{
name|m_widget
operator|=
operator|new
name|QWidget
expr_stmt|;
comment|// pixelMetric might need a widget ptr
if|if
condition|(
name|m_widget
condition|)
name|m_styleOption
operator|.
name|initFrom
argument_list|(
name|m_widget
argument_list|)
expr_stmt|;
name|m_isWindow
operator|=
name|m_styleOption
operator|.
name|state
operator|&
name|QStyle
operator|::
name|State_Window
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGraphicsLayoutStyleInfo
name|QGraphicsLayoutStyleInfo
operator|::
name|~
name|QGraphicsLayoutStyleInfo
parameter_list|()
block|{
operator|delete
name|m_widget
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|combinedLayoutSpacing
name|qreal
name|QGraphicsLayoutStyleInfo
operator|::
name|combinedLayoutSpacing
parameter_list|(
name|QLayoutPolicy
operator|::
name|ControlTypes
name|controls1
parameter_list|,
name|QLayoutPolicy
operator|::
name|ControlTypes
name|controls2
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|style
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|combinedLayoutSpacing
argument_list|(
name|QSizePolicy
operator|::
name|ControlTypes
argument_list|(
name|int
argument_list|(
name|controls1
argument_list|)
argument_list|)
argument_list|,
name|QSizePolicy
operator|::
name|ControlTypes
argument_list|(
name|int
argument_list|(
name|controls2
argument_list|)
argument_list|)
argument_list|,
name|orientation
argument_list|,
cast|const_cast
argument_list|<
name|QStyleOption
operator|*
argument_list|>
argument_list|(
operator|&
name|m_styleOption
argument_list|)
argument_list|,
name|widget
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|perItemSpacing
name|qreal
name|QGraphicsLayoutStyleInfo
operator|::
name|perItemSpacing
parameter_list|(
name|QLayoutPolicy
operator|::
name|ControlType
name|control1
parameter_list|,
name|QLayoutPolicy
operator|::
name|ControlType
name|control2
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|style
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|layoutSpacing
argument_list|(
name|QSizePolicy
operator|::
name|ControlType
argument_list|(
name|control1
argument_list|)
argument_list|,
name|QSizePolicy
operator|::
name|ControlType
argument_list|(
name|control2
argument_list|)
argument_list|,
name|orientation
argument_list|,
cast|const_cast
argument_list|<
name|QStyleOption
operator|*
argument_list|>
argument_list|(
operator|&
name|m_styleOption
argument_list|)
argument_list|,
name|widget
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|spacing
name|qreal
name|QGraphicsLayoutStyleInfo
operator|::
name|spacing
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|style
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|QStyle
operator|::
name|PM_LayoutHorizontalSpacing
else|:
name|QStyle
operator|::
name|PM_LayoutVerticalSpacing
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|windowMargin
name|qreal
name|QGraphicsLayoutStyleInfo
operator|::
name|windowMargin
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
specifier|const
block|{
return|return
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|orientation
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|QStyle
operator|::
name|PM_LayoutBottomMargin
else|:
name|QStyle
operator|::
name|PM_LayoutRightMargin
argument_list|,
cast|const_cast
argument_list|<
name|QStyleOption
operator|*
argument_list|>
argument_list|(
operator|&
name|m_styleOption
argument_list|)
argument_list|,
name|widget
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QGraphicsLayoutStyleInfo
operator|::
name|widget
parameter_list|()
specifier|const
block|{
return|return
name|m_widget
return|;
block|}
end_function
begin_function
DECL|function|style
name|QStyle
modifier|*
name|QGraphicsLayoutStyleInfo
operator|::
name|style
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_style
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
name|m_layout
operator|->
name|parentItem
argument_list|()
decl_stmt|;
name|m_style
operator|=
operator|(
name|item
operator|&&
name|item
operator|->
name|isWidget
argument_list|()
operator|)
condition|?
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|item
argument_list|)
operator|->
name|style
argument_list|()
else|:
name|QApplication
operator|::
name|style
argument_list|()
expr_stmt|;
block|}
return|return
name|m_style
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GRAPHICSVIEW
end_comment
end_unit
