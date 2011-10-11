begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).  ** All rights reserved.  ** Contact: Nokia Corporation (qt-info@nokia.com)  **  ** This file is part of the tools applications of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** GNU Lesser General Public License Usage  ** This file may be used under the terms of the GNU Lesser General Public  ** License version 2.1 as published by the Free Software Foundation and  ** appearing in the file LICENSE.LGPL included in the packaging of this  ** file. Please review the following information to ensure the GNU Lesser  ** General Public License version 2.1 requirements will be met:  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** In addition, as a special exception, Nokia gives you certain additional  ** rights. These rights are described in the Nokia Qt LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU General  ** Public License version 3.0 as published by the Free Software Foundation  ** and appearing in the file LICENSE.GPL included in the packaging of this  ** file. Please review the following information to ensure the GNU General  ** Public License version 3.0 requirements will be met:  ** http://www.gnu.org/copyleft/gpl.html.  **  ** Other Usage  ** Alternatively, this file may be used in accordance with the terms and  ** conditions contained in a signed written agreement between you and Nokia.  **  **  **  **  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ACCESSIBILITYSCENEMANAGER_H
end_ifndef
begin_define
DECL|macro|ACCESSIBILITYSCENEMANAGER_H
define|#
directive|define
name|ACCESSIBILITYSCENEMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"optionswidget.h"
end_include
begin_decl_stmt
name|QString
name|translateRole
argument_list|(
name|QAccessible
operator|::
name|Role
name|role
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AccessibilitySceneManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|AccessibilitySceneManager
argument_list|()
block|;
name|void
name|setRootWindow
argument_list|(
argument|QWindow * window
argument_list|)
block|{
name|m_window
operator|=
name|window
block|; }
name|void
name|setView
argument_list|(
argument|QGraphicsView *view
argument_list|)
block|{
name|m_view
operator|=
name|view
block|; }
name|void
name|setScene
argument_list|(
argument|QGraphicsScene *scene
argument_list|)
block|{
name|m_scene
operator|=
name|scene
block|; }
name|void
name|setTreeView
argument_list|(
argument|QGraphicsView *treeView
argument_list|)
block|{
name|m_treeView
operator|=
name|treeView
block|; }
name|void
name|setTreeScene
argument_list|(
argument|QGraphicsScene *treeScene
argument_list|)
block|{
name|m_treeScene
operator|=
name|treeScene
block|; }
name|void
name|setOptionsWidget
argument_list|(
argument|OptionsWidget *optionsWidget
argument_list|)
block|{
name|m_optionsWidget
operator|=
name|optionsWidget
block|; }
name|public
name|slots
operator|:
name|void
name|populateAccessibilityScene
argument_list|()
block|;
name|void
name|updateAccessibilitySceneItemFlags
argument_list|()
block|;
name|void
name|populateAccessibilityTreeScene
argument_list|()
block|;
name|void
name|handleUpdate
argument_list|(
argument|QObject *object
argument_list|,
argument|QAccessible::Event reason
argument_list|)
block|;
name|void
name|setSelected
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|void
name|changeScale
argument_list|(
argument|int scale
argument_list|)
block|;
name|private
operator|:
name|void
name|updateItems
argument_list|(
name|QObject
operator|*
name|root
argument_list|)
block|;
name|void
name|updateItem
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|void
name|updateItem
argument_list|(
name|QGraphicsRectItem
operator|*
name|item
argument_list|,
name|QAccessibleInterface
operator|*
name|interface
argument_list|)
block|;
name|void
name|updateItemFlags
argument_list|(
name|QGraphicsRectItem
operator|*
name|item
argument_list|,
name|QAccessibleInterface
operator|*
name|interface
argument_list|)
block|;
name|void
name|populateAccessibilityScene
argument_list|(
argument|QAccessibleInterface * interface
argument_list|,
argument|int child
argument_list|,
argument|QGraphicsScene *scene
argument_list|)
block|;
name|QGraphicsRectItem
operator|*
name|processInterface
argument_list|(
argument|QAccessibleInterface * interface
argument_list|,
argument|int child
argument_list|,
argument|QGraphicsScene *scene
argument_list|)
block|;      struct
name|TreeItem
block|;
name|TreeItem
name|computeLevels
argument_list|(
argument|QAccessibleInterface * interface
argument_list|,
argument|int level
argument_list|)
block|;
name|void
name|populateAccessibilityTreeScene
argument_list|(
argument|QAccessibleInterface * interface
argument_list|,
argument|int child
argument_list|)
block|;
name|void
name|addGraphicsItems
argument_list|(
argument|TreeItem item
argument_list|,
argument|int row
argument_list|,
argument|int xPos
argument_list|)
block|;
name|bool
name|isHidden
argument_list|(
name|QAccessibleInterface
operator|*
name|interface
argument_list|)
block|;
name|QWindow
operator|*
name|m_window
block|;
name|QGraphicsView
operator|*
name|m_view
block|;
name|QGraphicsScene
operator|*
name|m_scene
block|;
name|QGraphicsView
operator|*
name|m_treeView
block|;
name|QGraphicsScene
operator|*
name|m_treeScene
block|;
name|QGraphicsItem
operator|*
name|m_rootItem
block|;
name|OptionsWidget
operator|*
name|m_optionsWidget
block|;
name|QObject
operator|*
name|m_selectedObject
block|;
name|QHash
operator|<
name|QObject
operator|*
block|,
name|QGraphicsRectItem
operator|*
operator|>
name|m_graphicsItems
block|;
name|QSet
operator|<
name|QObject
operator|*
operator|>
name|m_animatedObjects
block|;      struct
name|TreeItem
block|{
name|QList
operator|<
name|TreeItem
operator|>
name|children
block|;
name|int
name|width
block|;
name|QString
name|name
block|;
name|QString
name|role
block|;
name|QString
name|description
block|;
name|QRect
name|rect
block|;
name|QAccessible
operator|::
name|State
name|state
block|;
name|QObject
operator|*
name|object
block|;
name|TreeItem
argument_list|()
operator|:
name|width
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
name|TreeItem
name|m_rootTreeItem
block|;
name|int
name|m_treeItemWidth
block|;
name|int
name|m_treeItemHorizontalPadding
block|;
name|int
name|m_treeItemHeight
block|;
name|int
name|m_treeItemVerticalPadding
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ACCESSIBILITYSCENEMANAGER_H
end_comment
end_unit
