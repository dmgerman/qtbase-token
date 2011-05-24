begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLBAR_H
end_ifndef
begin_define
DECL|macro|QSCROLLBAR_H
define|#
directive|define
name|QSCROLLBAR_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qabstractslider.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
name|class
name|QScrollBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionSlider
name|class
name|QStyleOptionSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QScrollBar
range|:
name|public
name|QAbstractSlider
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QScrollBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QScrollBar
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QScrollBar
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
argument_list|)
block|;
name|void
name|sliderChange
argument_list|(
argument|SliderChange change
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionSlider *option
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QScrollBar
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QScrollBar
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QScrollBar
argument_list|(
argument|int minValue
argument_list|,
argument|int maxValue
argument_list|,
argument|int lineStep
argument_list|,
argument|int pageStep
argument_list|,
argument|int value
argument_list|,
argument|Qt::Orientation
argument_list|,
argument|QWidget *parent=
literal|0
argument_list|,
argument|const char* name =
literal|0
argument_list|)
block|;
specifier|inline
name|QT3_SUPPORT
name|bool
name|draggingSlider
argument_list|()
block|{
return|return
name|isSliderDown
argument_list|()
return|;
block|}
endif|#
directive|endif
name|private
operator|:
name|friend
name|Q_GUI_EXPORT
name|QStyleOptionSlider
name|qt_qscrollbarStyleOption
argument_list|(
name|QScrollBar
operator|*
name|scrollBar
argument_list|)
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QScrollBar
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScrollBar
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLBAR
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLBAR_H
end_comment
end_unit
