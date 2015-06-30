begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtWidgets/qwidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractslider.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
DECL|variable|QScrollBarPrivate
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
name|Q_WIDGETS_EXPORT
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
name|Q_NULLPTR
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
name|Q_NULLPTR
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
name|Q_DECL_OVERRIDE
block|;
name|bool
name|event
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
argument|QWheelEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|hideEvent
argument_list|(
argument|QHideEvent*
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|sliderChange
argument_list|(
argument|SliderChange change
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|void
name|contextMenuEvent
argument_list|(
argument|QContextMenuEvent *
argument_list|)
name|Q_DECL_OVERRIDE
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
name|private
operator|:
name|friend
name|class
name|QAbstractScrollAreaPrivate
block|;
name|friend
name|Q_WIDGETS_EXPORT
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLBAR_H
end_comment
end_unit
