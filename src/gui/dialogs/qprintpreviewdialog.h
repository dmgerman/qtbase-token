begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTPREVIEWDIALOG_H
end_ifndef
begin_define
DECL|macro|QPRINTPREVIEWDIALOG_H
define|#
directive|define
name|QPRINTPREVIEWDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qdialog.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTPREVIEWDIALOG
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QGraphicsView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintPreviewDialogPrivate
name|class
name|QPrintPreviewDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPrintPreviewDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPrintPreviewDialog
argument_list|)
name|public
operator|:
name|explicit
name|QPrintPreviewDialog
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|explicit
name|QPrintPreviewDialog
argument_list|(
argument|QPrinter *printer
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QPrintPreviewDialog
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|QPrinter
operator|*
name|printer
argument_list|()
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|paintRequested
argument_list|(
name|QPrinter
operator|*
name|printer
argument_list|)
block|;
name|private
operator|:
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_fit(QAction *action)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_zoomIn()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_zoomOut()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_navigate(QAction *action)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_setMode(QAction *action)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_pageNumEdited()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_print()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_pageSetup()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_previewChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_zoomFactorChanged()
argument_list|)
name|void
operator|*
name|dummy
block|;
comment|// ### Qt 5 - remove me
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
comment|// QT_NO_PRINTPREVIEWDIALOG
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTPREVIEWDIALOG_H
end_comment
end_unit
