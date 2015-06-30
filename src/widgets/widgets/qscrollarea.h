begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLAREA_H
end_ifndef
begin_define
DECL|macro|QSCROLLAREA_H
define|#
directive|define
name|QSCROLLAREA_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
DECL|variable|QScrollAreaPrivate
name|class
name|QScrollAreaPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QScrollArea
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool widgetResizable READ widgetResizable WRITE setWidgetResizable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|public
operator|:
name|explicit
name|QScrollArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QScrollArea
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|void
name|setWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|takeWidget
argument_list|()
block|;
name|bool
name|widgetResizable
argument_list|()
specifier|const
block|;
name|void
name|setWidgetResizable
argument_list|(
argument|bool resizable
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|void
name|ensureWidgetVisible
argument_list|(
argument|QWidget *childWidget
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|protected
operator|:
name|QScrollArea
argument_list|(
name|QScrollAreaPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|eventFilter
argument_list|(
argument|QObject *
argument_list|,
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|viewportSizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScrollArea
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QScrollArea
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLAREA_H
end_comment
end_unit
