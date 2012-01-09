begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROGRESSDIALOG_H
end_ifndef
begin_define
DECL|macro|QPROGRESSDIALOG_H
define|#
directive|define
name|QPROGRESSDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSDIALOG
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProgressBar
name|class
name|QProgressBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProgressDialogPrivate
name|class
name|QProgressDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QProgressDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QProgressDialog
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wasCanceled READ wasCanceled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int minimum READ minimum WRITE setMinimum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int maximum READ maximum WRITE setMaximum
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int value READ value WRITE setValue
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool autoReset READ autoReset WRITE setAutoReset
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool autoClose READ autoClose WRITE setAutoClose
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int minimumDuration READ minimumDuration WRITE setMinimumDuration
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString labelText READ labelText WRITE setLabelText
argument_list|)
name|public
operator|:
name|explicit
name|QProgressDialog
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|QProgressDialog
argument_list|(
argument|const QString&labelText
argument_list|,
argument|const QString&cancelButtonText
argument_list|,
argument|int minimum
argument_list|,
argument|int maximum
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QProgressDialog
argument_list|()
block|;
name|void
name|setLabel
argument_list|(
name|QLabel
operator|*
name|label
argument_list|)
block|;
name|void
name|setCancelButton
argument_list|(
name|QPushButton
operator|*
name|button
argument_list|)
block|;
name|void
name|setBar
argument_list|(
name|QProgressBar
operator|*
name|bar
argument_list|)
block|;
name|bool
name|wasCanceled
argument_list|()
specifier|const
block|;
name|int
name|minimum
argument_list|()
specifier|const
block|;
name|int
name|maximum
argument_list|()
specifier|const
block|;
name|int
name|value
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QString
name|labelText
argument_list|()
specifier|const
block|;
name|int
name|minimumDuration
argument_list|()
specifier|const
block|;
name|void
name|setAutoReset
argument_list|(
argument|bool reset
argument_list|)
block|;
name|bool
name|autoReset
argument_list|()
specifier|const
block|;
name|void
name|setAutoClose
argument_list|(
argument|bool close
argument_list|)
block|;
name|bool
name|autoClose
argument_list|()
specifier|const
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
name|public
name|Q_SLOTS
operator|:
name|void
name|cancel
argument_list|()
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|setMaximum
argument_list|(
argument|int maximum
argument_list|)
block|;
name|void
name|setMinimum
argument_list|(
argument|int minimum
argument_list|)
block|;
name|void
name|setRange
argument_list|(
argument|int minimum
argument_list|,
argument|int maximum
argument_list|)
block|;
name|void
name|setValue
argument_list|(
argument|int progress
argument_list|)
block|;
name|void
name|setLabelText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setCancelButtonText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|setMinimumDuration
argument_list|(
argument|int ms
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|canceled
argument_list|()
block|;
name|protected
operator|:
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
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
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|event
argument_list|)
block|;
name|protected
name|Q_SLOTS
operator|:
name|void
name|forceShow
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QProgressDialog
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_disconnectOnClose()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROGRESSDIALOG
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
comment|// QPROGRESSDIALOG_H
end_comment
end_unit
