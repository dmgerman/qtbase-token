begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAINWINDOW_H
end_ifndef
begin_define
DECL|macro|MAINWINDOW_H
define|#
directive|define
name|MAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|"diagramitem.h"
end_include
begin_decl_stmt
DECL|variable|DiagramScene
name|class
name|DiagramScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolBox
name|class
name|QToolBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpinBox
name|class
name|QSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontComboBox
name|class
name|QFontComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QButtonGroup
name|class
name|QButtonGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsTextItem
name|class
name|QGraphicsTextItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsView
name|class
name|QGraphicsView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|MainWindow
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|MainWindow
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|backgroundButtonGroupClicked
argument_list|(
name|QAbstractButton
operator|*
name|button
argument_list|)
block|;
name|void
name|buttonGroupClicked
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|deleteItem
argument_list|()
block|;
name|void
name|pointerGroupClicked
argument_list|(
argument|int id
argument_list|)
block|;
name|void
name|bringToFront
argument_list|()
block|;
name|void
name|sendToBack
argument_list|()
block|;
name|void
name|itemInserted
argument_list|(
name|DiagramItem
operator|*
name|item
argument_list|)
block|;
name|void
name|textInserted
argument_list|(
name|QGraphicsTextItem
operator|*
name|item
argument_list|)
block|;
name|void
name|currentFontChanged
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|void
name|fontSizeChanged
argument_list|(
specifier|const
name|QString
operator|&
name|size
argument_list|)
block|;
name|void
name|sceneScaleChanged
argument_list|(
specifier|const
name|QString
operator|&
name|scale
argument_list|)
block|;
name|void
name|textColorChanged
argument_list|()
block|;
name|void
name|itemColorChanged
argument_list|()
block|;
name|void
name|lineColorChanged
argument_list|()
block|;
name|void
name|textButtonTriggered
argument_list|()
block|;
name|void
name|fillButtonTriggered
argument_list|()
block|;
name|void
name|lineButtonTriggered
argument_list|()
block|;
name|void
name|handleFontChange
argument_list|()
block|;
name|void
name|itemSelected
argument_list|(
name|QGraphicsItem
operator|*
name|item
argument_list|)
block|;
name|void
name|about
argument_list|()
block|;
name|private
operator|:
name|void
name|createToolBox
argument_list|()
block|;
name|void
name|createActions
argument_list|()
block|;
name|void
name|createMenus
argument_list|()
block|;
name|void
name|createToolbars
argument_list|()
block|;
name|QWidget
operator|*
name|createBackgroundCellWidget
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QString
operator|&
name|image
argument_list|)
block|;
name|QWidget
operator|*
name|createCellWidget
argument_list|(
argument|const QString&text
argument_list|,
argument|DiagramItem::DiagramType type
argument_list|)
block|;
name|QMenu
operator|*
name|createColorMenu
argument_list|(
argument|const char *slot
argument_list|,
argument|QColor defaultColor
argument_list|)
block|;
name|QIcon
name|createColorToolButtonIcon
argument_list|(
argument|const QString&image
argument_list|,
argument|QColor color
argument_list|)
block|;
name|QIcon
name|createColorIcon
argument_list|(
argument|QColor color
argument_list|)
block|;
name|DiagramScene
operator|*
name|scene
block|;
name|QGraphicsView
operator|*
name|view
block|;
name|QAction
operator|*
name|exitAction
block|;
name|QAction
operator|*
name|addAction
block|;
name|QAction
operator|*
name|deleteAction
block|;
name|QAction
operator|*
name|toFrontAction
block|;
name|QAction
operator|*
name|sendBackAction
block|;
name|QAction
operator|*
name|aboutAction
block|;
name|QMenu
operator|*
name|fileMenu
block|;
name|QMenu
operator|*
name|itemMenu
block|;
name|QMenu
operator|*
name|aboutMenu
block|;
name|QToolBar
operator|*
name|textToolBar
block|;
name|QToolBar
operator|*
name|editToolBar
block|;
name|QToolBar
operator|*
name|colorToolBar
block|;
name|QToolBar
operator|*
name|pointerToolbar
block|;
name|QComboBox
operator|*
name|sceneScaleCombo
block|;
name|QComboBox
operator|*
name|itemColorCombo
block|;
name|QComboBox
operator|*
name|textColorCombo
block|;
name|QComboBox
operator|*
name|fontSizeCombo
block|;
name|QFontComboBox
operator|*
name|fontCombo
block|;
name|QToolBox
operator|*
name|toolBox
block|;
name|QButtonGroup
operator|*
name|buttonGroup
block|;
name|QButtonGroup
operator|*
name|pointerTypeGroup
block|;
name|QButtonGroup
operator|*
name|backgroundButtonGroup
block|;
name|QToolButton
operator|*
name|fontColorToolButton
block|;
name|QToolButton
operator|*
name|fillColorToolButton
block|;
name|QToolButton
operator|*
name|lineColorToolButton
block|;
name|QAction
operator|*
name|boldAction
block|;
name|QAction
operator|*
name|underlineAction
block|;
name|QAction
operator|*
name|italicAction
block|;
name|QAction
operator|*
name|textAction
block|;
name|QAction
operator|*
name|fillAction
block|;
name|QAction
operator|*
name|lineAction
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
