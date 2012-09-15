begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COLORSWATCH_H
end_ifndef
begin_define
DECL|macro|COLORSWATCH_H
define|#
directive|define
name|COLORSWATCH_H
end_define
begin_include
include|#
directive|include
file|<QDockWidget>
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
begin_decl_stmt
name|class
name|ColorSwatch
range|:
name|public
name|QDockWidget
block|{
name|Q_OBJECT
name|QAction
operator|*
name|closableAction
block|;
name|QAction
operator|*
name|movableAction
block|;
name|QAction
operator|*
name|floatableAction
block|;
name|QAction
operator|*
name|floatingAction
block|;
name|QAction
operator|*
name|verticalTitleBarAction
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
name|changeSizeHintsAction
block|;
name|QMenu
operator|*
name|tabMenu
block|;
name|QMenu
operator|*
name|splitHMenu
block|;
name|QMenu
operator|*
name|splitVMenu
block|;
name|QAction
operator|*
name|windowModifiedAction
block|;
name|public
operator|:
name|explicit
name|ColorSwatch
argument_list|(
argument|const QString&colorName
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
name|QMenu
operator|*
name|menu
block|;
name|void
name|setCustomSizeHint
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|contextMenuEvent
argument_list|(
name|QContextMenuEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|void
name|allow
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|,
argument|bool allow
argument_list|)
block|;
name|void
name|place
argument_list|(
argument|Qt::DockWidgetArea area
argument_list|,
argument|bool place
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|changeClosable
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|changeMovable
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|changeFloatable
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|changeFloating
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|changeVerticalTitleBar
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|updateContextMenu
argument_list|()
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
name|splitInto
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|;
name|void
name|tabInto
argument_list|(
name|QAction
operator|*
name|action
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|BlueTitleBar
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|BlueTitleBar
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|minimumSizeHint
argument_list|()
return|;
block|}
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|updateMask
argument_list|()
block|;
name|private
operator|:
name|QPixmap
name|leftPm
block|,
name|centerPm
block|,
name|rightPm
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
