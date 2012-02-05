begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSLAYOUT_P_H
define|#
directive|define
name|QGRAPHICSLAYOUT_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qgraphicslayout.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayoutitem_p.h"
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
file|<QtWidgets/qstyleoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGraphicsLayoutItem
name|class
name|QGraphicsLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsWidget
name|class
name|QGraphicsWidget
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEBUG
end_ifdef
begin_function
DECL|function|qt_graphicsLayoutDebug
specifier|inline
name|bool
name|qt_graphicsLayoutDebug
parameter_list|()
block|{
specifier|static
name|int
name|checked_env
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|checked_env
operator|==
operator|-
literal|1
condition|)
name|checked_env
operator|=
operator|!
operator|!
name|qgetenv
argument_list|(
literal|"QT_GRAPHICSLAYOUT_DEBUG"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
return|return
name|checked_env
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QLayoutStyleInfo
block|{
name|public
label|:
specifier|inline
name|QLayoutStyleInfo
argument_list|()
block|{
name|invalidate
argument_list|()
block|; }
specifier|inline
name|QLayoutStyleInfo
argument_list|(
name|QStyle
operator|*
name|style
argument_list|,
name|QWidget
operator|*
name|widget
argument_list|)
operator|:
name|m_valid
argument_list|(
name|true
argument_list|)
operator|,
name|m_style
argument_list|(
name|style
argument_list|)
operator|,
name|m_widget
argument_list|(
argument|widget
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|style
argument_list|)
block|;
if|if
condition|(
name|widget
condition|)
comment|//###
name|m_styleOption
operator|.
name|initFrom
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|m_defaultSpacing
index|[
literal|0
index|]
operator|=
name|style
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_LayoutHorizontalSpacing
argument_list|)
expr_stmt|;
name|m_defaultSpacing
index|[
literal|1
index|]
operator|=
name|style
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_LayoutVerticalSpacing
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|void
name|invalidate
parameter_list|()
block|{
name|m_valid
operator|=
name|false
expr_stmt|;
name|m_style
operator|=
literal|0
expr_stmt|;
name|m_widget
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|QStyle
operator|*
name|style
argument_list|()
specifier|const
block|{
return|return
name|m_style
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|{
return|return
name|m_widget
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|m_style
operator|==
name|other
operator|.
name|m_style
operator|&&
name|m_widget
operator|==
name|other
operator|.
name|m_widget
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QLayoutStyleInfo
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
name|void
name|setDefaultSpacing
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|qreal
name|spacing
argument_list|)
block|{
if|if
condition|(
name|spacing
operator|>=
literal|0
condition|)
name|m_defaultSpacing
index|[
name|o
operator|-
literal|1
index|]
operator|=
name|spacing
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|qreal
name|defaultSpacing
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|)
decl|const
block|{
return|return
name|m_defaultSpacing
index|[
name|o
operator|-
literal|1
index|]
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|qreal
name|perItemSpacing
argument_list|(
name|QSizePolicy
operator|::
name|ControlType
name|control1
argument_list|,
name|QSizePolicy
operator|::
name|ControlType
name|control2
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|)
decl|const
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
name|control1
argument_list|,
name|control2
argument_list|,
name|orientation
argument_list|,
operator|&
name|m_styleOption
argument_list|,
name|widget
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|bool
name|m_valid
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStyle
modifier|*
name|m_style
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWidget
modifier|*
name|m_widget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStyleOption
name|m_styleOption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|m_defaultSpacing
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsLayoutPrivate
range|:
name|public
name|QGraphicsLayoutItemPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsLayout
argument_list|)
name|public
operator|:
name|QGraphicsLayoutPrivate
argument_list|()
operator|:
name|QGraphicsLayoutItemPrivate
argument_list|(
literal|0
argument_list|,
name|true
argument_list|)
block|,
name|left
argument_list|(
operator|-
literal|1.0
argument_list|)
block|,
name|top
argument_list|(
operator|-
literal|1.0
argument_list|)
block|,
name|right
argument_list|(
operator|-
literal|1.0
argument_list|)
block|,
name|bottom
argument_list|(
operator|-
literal|1.0
argument_list|)
block|,
name|activated
argument_list|(
argument|true
argument_list|)
block|{ }
name|void
name|reparentChildItems
argument_list|(
name|QGraphicsItem
operator|*
name|newParent
argument_list|)
block|;
name|void
name|getMargin
argument_list|(
argument|qreal *result
argument_list|,
argument|qreal userMargin
argument_list|,
argument|QStyle::PixelMetric pm
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|LayoutDirection
name|visualDirection
argument_list|()
specifier|const
block|;
name|void
name|addChildLayoutItem
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|activateRecursive
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|qreal
name|left
block|,
name|top
block|,
name|right
block|,
name|bottom
block|;
name|bool
name|activated
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_GRAPHICSVIEW
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
