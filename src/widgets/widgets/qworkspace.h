begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWORKSPACE_H
end_ifndef
begin_define
DECL|macro|QWORKSPACE_H
define|#
directive|define
name|QWORKSPACE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
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
name|QT_NO_WORKSPACE
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWorkspaceChild
name|class
name|QWorkspaceChild
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QShowEvent
name|class
name|QShowEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWorkspacePrivate
name|class
name|QWorkspacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWorkspace
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool scrollBarsEnabled READ scrollBarsEnabled WRITE setScrollBarsEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QBrush background READ background WRITE setBackground
argument_list|)
name|public
operator|:
name|explicit
name|QWorkspace
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWorkspace
argument_list|()
block|;      enum
name|WindowOrder
block|{
name|CreationOrder
block|,
name|StackingOrder
block|}
block|;
name|QWidget
operator|*
name|activeWindow
argument_list|()
specifier|const
block|;
name|QWidgetList
name|windowList
argument_list|(
argument|WindowOrder order = CreationOrder
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|addWindow
argument_list|(
argument|QWidget *w
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|bool
name|scrollBarsEnabled
argument_list|()
specifier|const
block|;
name|void
name|setScrollBarsEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|setBackground
argument_list|(
specifier|const
name|QBrush
operator|&
name|background
argument_list|)
block|;
name|QBrush
name|background
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|windowActivated
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setActiveWindow
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|cascade
argument_list|()
block|;
name|void
name|tile
argument_list|()
block|;
name|void
name|arrangeIcons
argument_list|()
block|;
name|void
name|closeActiveWindow
argument_list|()
block|;
name|void
name|closeAllWindows
argument_list|()
block|;
name|void
name|activateNextWindow
argument_list|()
block|;
name|void
name|activatePreviousWindow
argument_list|()
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
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|e
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
name|childEvent
argument_list|(
name|QChildEvent
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
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWorkspace
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QWorkspace
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_normalizeActiveWindow()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_minimizeActiveWindow()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showOperationMenu()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_popupOperationMenu(const QPoint&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_operationMenuActivated(QAction *)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateActions()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_scrollBarChanged()
argument_list|)
name|friend
name|class
name|QWorkspaceChild
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_WORKSPACE
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
comment|// QWORKSPACE_H
end_comment
end_unit
