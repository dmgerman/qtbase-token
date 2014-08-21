begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TOOLBAR_H
end_ifndef
begin_define
DECL|macro|TOOLBAR_H
define|#
directive|define
name|TOOLBAR_H
end_define
begin_include
include|#
directive|include
file|<QToolBar>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QAction
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QActionGroup
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QMenu
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QSpinBox
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QLabel
argument_list|)
end_macro
begin_decl_stmt
name|class
name|ToolBar
range|:
name|public
name|QToolBar
block|{
name|Q_OBJECT
name|QSpinBox
operator|*
name|spinbox
block|;
name|QAction
operator|*
name|spinboxAction
block|;
name|QAction
operator|*
name|orderAction
block|;
name|QAction
operator|*
name|randomizeAction
block|;
name|QAction
operator|*
name|addSpinBoxAction
block|;
name|QAction
operator|*
name|removeSpinBoxAction
block|;
name|QAction
operator|*
name|movableAction
block|;
name|QActionGroup
operator|*
name|allowedAreasActions
block|;
name|QAction
operator|*
name|allowLeftAction
block|;
name|QAction
operator|*
name|allowRightAction
block|;
name|QAction
operator|*
name|allowTopAction
block|;
name|QAction
operator|*
name|allowBottomAction
block|;
name|QActionGroup
operator|*
name|areaActions
block|;
name|QAction
operator|*
name|leftAction
block|;
name|QAction
operator|*
name|rightAction
block|;
name|QAction
operator|*
name|topAction
block|;
name|QAction
operator|*
name|bottomAction
block|;
name|QAction
operator|*
name|toolBarBreakAction
block|;
name|public
operator|:
name|ToolBar
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|QMenu
operator|*
name|menu
block|;
name|protected
operator|:
name|void
name|enterEvent
argument_list|(
argument|QEvent*
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|leaveEvent
argument_list|(
argument|QEvent*
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|allow
argument_list|(
argument|Qt::ToolBarArea area
argument_list|,
argument|bool allow
argument_list|)
block|;
name|void
name|place
argument_list|(
argument|Qt::ToolBarArea area
argument_list|,
argument|bool place
argument_list|)
block|;
name|QLabel
operator|*
name|tip
block|;
name|private
name|slots
operator|:
name|void
name|order
argument_list|()
block|;
name|void
name|randomize
argument_list|()
block|;
name|void
name|addSpinBox
argument_list|()
block|;
name|void
name|removeSpinBox
argument_list|()
block|;
name|void
name|changeMovable
argument_list|(
argument|bool movable
argument_list|)
block|;
name|void
name|allowLeft
argument_list|(
argument|bool a
argument_list|)
block|;
name|void
name|allowRight
argument_list|(
argument|bool a
argument_list|)
block|;
name|void
name|allowTop
argument_list|(
argument|bool a
argument_list|)
block|;
name|void
name|allowBottom
argument_list|(
argument|bool a
argument_list|)
block|;
name|void
name|placeLeft
argument_list|(
argument|bool p
argument_list|)
block|;
name|void
name|placeRight
argument_list|(
argument|bool p
argument_list|)
block|;
name|void
name|placeTop
argument_list|(
argument|bool p
argument_list|)
block|;
name|void
name|placeBottom
argument_list|(
argument|bool p
argument_list|)
block|;
name|void
name|updateMenu
argument_list|()
block|;
name|void
name|insertToolBarBreak
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
