begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMENUBAR_H
end_ifndef
begin_define
DECL|macro|QMENUBAR_H
define|#
directive|define
name|QMENUBAR_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qmenu.h>
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
name|QT_NO_MENUBAR
name|class
name|QMenuBarPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionMenuItem
name|class
name|QStyleOptionMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsStyle
name|class
name|QWindowsStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMenuBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool defaultUp READ isDefaultUp WRITE setDefaultUp
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool nativeMenuBar READ isNativeMenuBar WRITE setNativeMenuBar
argument_list|)
name|public
operator|:
name|explicit
name|QMenuBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QMenuBar
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
name|void
name|addAction
argument_list|(
argument|QAction *action
argument_list|)
block|{
name|QWidget
operator|::
name|addAction
argument_list|(
name|action
argument_list|)
block|; }
else|#
directive|else
name|using
name|QWidget
operator|::
name|addAction
block|;
endif|#
directive|endif
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
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
name|QAction
operator|*
name|addMenu
argument_list|(
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QMenu
operator|*
name|addMenu
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|QAction
operator|*
name|addSeparator
argument_list|()
block|;
name|QAction
operator|*
name|insertSeparator
argument_list|(
name|QAction
operator|*
name|before
argument_list|)
block|;
name|QAction
operator|*
name|insertMenu
argument_list|(
name|QAction
operator|*
name|before
argument_list|,
name|QMenu
operator|*
name|menu
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|QAction
operator|*
name|activeAction
argument_list|()
specifier|const
block|;
name|void
name|setActiveAction
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|setDefaultUp
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|isDefaultUp
argument_list|()
specifier|const
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
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|QRect
name|actionGeometry
argument_list|(
argument|QAction *
argument_list|)
specifier|const
block|;
name|QAction
operator|*
name|actionAt
argument_list|(
argument|const QPoint&
argument_list|)
specifier|const
block|;
name|void
name|setCornerWidget
argument_list|(
argument|QWidget *w
argument_list|,
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
block|;
name|QWidget
operator|*
name|cornerWidget
argument_list|(
argument|Qt::Corner corner = Qt::TopRightCorner
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|void
name|setDefaultAction
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|QAction
operator|*
name|defaultAction
argument_list|()
specifier|const
block|;
specifier|static
name|void
name|wceCommands
argument_list|(
argument|uint command
argument_list|)
block|;
specifier|static
name|void
name|wceRefresh
argument_list|()
block|;
endif|#
directive|endif
name|bool
name|isNativeMenuBar
argument_list|()
specifier|const
block|;
name|void
name|setNativeMenuBar
argument_list|(
argument|bool nativeMenuBar
argument_list|)
block|;
name|QPlatformMenuBar
operator|*
name|platformMenuBar
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
name|virtual
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|triggered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|hovered
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
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
name|mousePressEvent
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
name|leaveEvent
argument_list|(
name|QEvent
operator|*
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
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|actionEvent
argument_list|(
name|QActionEvent
operator|*
argument_list|)
block|;
name|void
name|focusOutEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionMenuItem *option
argument_list|,
argument|const QAction *action
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMenuBar
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QMenuBar
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionTriggered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionHovered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_internalShortcutActivated(int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateLayout()
argument_list|)
ifdef|#
directive|ifdef
name|Q_WS_WINCE
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateDefaultAction()
argument_list|)
endif|#
directive|endif
name|friend
name|class
name|QMenu
block|;
name|friend
name|class
name|QMenuPrivate
block|;
name|friend
name|class
name|QWindowsStyle
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENUBAR
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
comment|// QMENUBAR_H
end_comment
end_unit
