begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWSEMBEDWIDGET_H
end_ifndef
begin_define
DECL|macro|QWSEMBEDWIDGET_H
define|#
directive|define
name|QWSEMBEDWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwidget.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWSEMBEDWIDGET
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWSEmbedWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QWSEmbedWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|QWSEmbedWidget
argument_list|(
argument|WId winId
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
operator|~
name|QWSEmbedWidget
argument_list|()
block|;
name|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|moveEvent
argument_list|(
name|QMoveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWSEmbedWidget
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWSEMBEDWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWSEMBEDWIDGET_H
end_comment
end_unit
