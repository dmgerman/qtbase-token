begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLABEL_H
end_ifndef
begin_define
DECL|macro|QLABEL_H
define|#
directive|define
name|QLABEL_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qframe.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLabelPrivate
name|class
name|QLabelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QLabel
range|:
name|public
name|QFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextFormat textFormat READ textFormat WRITE setTextFormat
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QPixmap pixmap READ pixmap WRITE setPixmap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool scaledContents READ hasScaledContents WRITE setScaledContents
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool wordWrap READ wordWrap WRITE setWordWrap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int margin READ margin WRITE setMargin
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int indent READ indent WRITE setIndent
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool openExternalLinks READ openExternalLinks WRITE setOpenExternalLinks
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextInteractionFlags textInteractionFlags READ textInteractionFlags WRITE setTextInteractionFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool hasSelectedText READ hasSelectedText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString selectedText READ selectedText
argument_list|)
name|public
operator|:
name|explicit
name|QLabel
argument_list|(
argument|QWidget *parent=
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
name|explicit
name|QLabel
argument_list|(
argument|const QString&text
argument_list|,
argument|QWidget *parent=
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
operator|~
name|QLabel
argument_list|()
block|;
name|QString
name|text
argument_list|()
specifier|const
block|;
specifier|const
name|QPixmap
operator|*
name|pixmap
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
specifier|const
name|QPicture
operator|*
name|picture
argument_list|()
specifier|const
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
name|QMovie
operator|*
name|movie
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Qt
operator|::
name|TextFormat
name|textFormat
argument_list|()
specifier|const
block|;
name|void
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|TextFormat
argument_list|)
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
name|setWordWrap
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|wordWrap
argument_list|()
specifier|const
block|;
name|int
name|indent
argument_list|()
specifier|const
block|;
name|void
name|setIndent
argument_list|(
name|int
argument_list|)
block|;
name|int
name|margin
argument_list|()
specifier|const
block|;
name|void
name|setMargin
argument_list|(
name|int
argument_list|)
block|;
name|bool
name|hasScaledContents
argument_list|()
specifier|const
block|;
name|void
name|setScaledContents
argument_list|(
name|bool
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|void
name|setBuddy
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|QWidget
operator|*
name|buddy
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|bool
name|openExternalLinks
argument_list|()
specifier|const
block|;
name|void
name|setOpenExternalLinks
argument_list|(
argument|bool open
argument_list|)
block|;
name|void
name|setTextInteractionFlags
argument_list|(
argument|Qt::TextInteractionFlags flags
argument_list|)
block|;
name|Qt
operator|::
name|TextInteractionFlags
name|textInteractionFlags
argument_list|()
specifier|const
block|;
name|void
name|setSelection
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
name|bool
name|hasSelectedText
argument_list|()
specifier|const
block|;
name|QString
name|selectedText
argument_list|()
specifier|const
block|;
name|int
name|selectionStart
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|setPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
name|void
name|setPicture
argument_list|(
specifier|const
name|QPicture
operator|&
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
name|void
name|setMovie
argument_list|(
name|QMovie
operator|*
name|movie
argument_list|)
block|;
endif|#
directive|endif
name|void
name|setNum
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setNum
argument_list|(
name|double
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|linkActivated
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|)
block|;
name|void
name|linkHovered
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|ev
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
name|ev
argument_list|)
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QLabel
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLabel
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_movieUpdated(const QRect&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_movieResized(const QSize&)
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_linkHovered(const QString&)
argument_list|)
name|friend
name|class
name|QTipLabel
block|;
name|friend
name|class
name|QMessageBoxPrivate
block|;
name|friend
name|class
name|QBalloonTip
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
comment|// QLABEL_H
end_comment
end_unit
