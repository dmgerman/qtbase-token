begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"accessibilityscenemanager.h"
end_include
begin_constructor
DECL|function|AccessibilitySceneManager
name|AccessibilitySceneManager
operator|::
name|AccessibilitySceneManager
parameter_list|()
block|{
name|m_window
operator|=
literal|0
expr_stmt|;
name|m_view
operator|=
literal|0
expr_stmt|;
name|m_scene
operator|=
literal|0
expr_stmt|;
name|m_rootItem
operator|=
literal|0
expr_stmt|;
name|m_optionsWidget
operator|=
literal|0
expr_stmt|;
name|m_selectedObject
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|populateAccessibilityScene
name|void
name|AccessibilitySceneManager
operator|::
name|populateAccessibilityScene
parameter_list|()
block|{
name|m_scene
operator|->
name|clear
argument_list|()
expr_stmt|;
name|m_graphicsItems
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|rootInterface
init|=
name|m_window
operator|->
name|accessibleRoot
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rootInterface
condition|)
return|return;
name|populateAccessibilityScene
argument_list|(
name|rootInterface
argument_list|,
name|m_scene
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateAccessibilitySceneItemFlags
name|void
name|AccessibilitySceneManager
operator|::
name|updateAccessibilitySceneItemFlags
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"update"
expr_stmt|;
foreach|foreach
control|(
name|QObject
modifier|*
name|object
decl|,
name|m_graphicsItems
operator|.
name|keys
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|object
condition|)
continue|continue;
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|interface
condition|)
continue|continue;
name|updateItemFlags
argument_list|(
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|object
argument_list|)
argument_list|,
name|interface
argument_list|)
expr_stmt|;
operator|delete
name|interface
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|populateAccessibilityTreeScene
name|void
name|AccessibilitySceneManager
operator|::
name|populateAccessibilityTreeScene
parameter_list|()
block|{
name|m_treeScene
operator|->
name|clear
argument_list|()
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|rootInterface
init|=
name|m_window
operator|->
name|accessibleRoot
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rootInterface
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWindow::accessibleRoot returned 0"
argument_list|)
expr_stmt|;
return|return;
block|}
name|populateAccessibilityTreeScene
argument_list|(
name|rootInterface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleUpdate
name|void
name|AccessibilitySceneManager
operator|::
name|handleUpdate
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|QAccessible
operator|::
name|Event
name|reason
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|interface
condition|)
return|return;
name|QString
name|name
init|=
name|interface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|)
decl_stmt|;
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ObjectCreated
condition|)
block|{
comment|//      qDebug()<< "ObjectCreated"<< object<< name;
name|populateAccessibilityScene
argument_list|(
name|interface
argument_list|,
name|m_scene
argument_list|)
expr_stmt|;
block|}
name|QGraphicsRectItem
modifier|*
name|item
init|=
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
block|{
comment|//        qDebug()<< "populateAccessibilityScene failed for"<< object;
return|return;
block|}
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|LocationChanged
condition|)
block|{
comment|//if (name.startsWith("List"))
name|qDebug
argument_list|()
operator|<<
literal|"locationChange"
operator|<<
name|object
operator|<<
name|name
operator|<<
name|interface
operator|->
name|rect
argument_list|()
expr_stmt|;
name|updateItem
argument_list|(
name|item
argument_list|,
name|interface
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interface
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|child
init|=
name|interface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|child
condition|)
block|{
name|updateItem
argument_list|(
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
argument_list|,
name|child
argument_list|)
expr_stmt|;
operator|delete
name|child
expr_stmt|;
block|}
block|}
operator|delete
name|interface
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ObjectDestroyed
condition|)
block|{
comment|//        qDebug()<< "ObjectDestroyed"<< object<< name;
operator|delete
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|object
argument_list|)
expr_stmt|;
name|m_graphicsItems
operator|.
name|remove
argument_list|(
name|object
argument_list|)
expr_stmt|;
name|m_animatedObjects
operator|.
name|remove
argument_list|(
name|object
argument_list|)
expr_stmt|;
if|if
condition|(
name|object
operator|==
name|m_selectedObject
condition|)
block|{
name|m_selectedObject
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ObjectHide
condition|)
block|{
comment|//        qDebug()<< "ObjectCreated Hide"<< object;
name|updateItemFlags
argument_list|(
name|item
argument_list|,
name|interface
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ObjectShow
condition|)
block|{
comment|//        qDebug()<< "ObjectCreated Show"<< object;
name|updateItemFlags
argument_list|(
name|item
argument_list|,
name|interface
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ScrollingStart
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ObjectCreated ScrollingStart"
operator|<<
name|object
expr_stmt|;
name|QAccessibleInterface
modifier|*
name|child
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interface
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|child
init|=
name|interface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|child
condition|)
block|{
name|m_animatedObjects
operator|.
name|insert
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|child
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|reason
operator|==
name|QAccessible
operator|::
name|ScrollingEnd
condition|)
block|{
comment|// qDebug()<< "ObjectCreated ScrollingEnd"<< object;
foreach|foreach
control|(
name|QObject
modifier|*
name|object
decl|,
name|m_animatedObjects
control|)
block|{
name|updateItem
argument_list|(
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|object
argument_list|)
argument_list|,
name|interface
argument_list|)
expr_stmt|;
block|}
operator|delete
name|interface
expr_stmt|;
name|m_animatedObjects
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|//        qDebug()<< "other update"<< object;
block|}
block|}
end_function
begin_function
DECL|function|setSelected
name|void
name|AccessibilitySceneManager
operator|::
name|setSelected
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|m_scene
operator|->
name|update
argument_list|()
expr_stmt|;
comment|// scedule update
comment|// clear existing selection
if|if
condition|(
name|m_selectedObject
condition|)
block|{
name|QObject
modifier|*
name|previousSelectedObject
init|=
name|m_selectedObject
decl_stmt|;
name|m_selectedObject
operator|=
literal|0
expr_stmt|;
name|updateItem
argument_list|(
name|previousSelectedObject
argument_list|)
expr_stmt|;
block|}
name|m_selectedObject
operator|=
name|object
expr_stmt|;
name|updateItem
argument_list|(
name|object
argument_list|)
expr_stmt|;
name|populateAccessibilityTreeScene
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeScale
name|void
name|AccessibilitySceneManager
operator|::
name|changeScale
parameter_list|(
name|int
parameter_list|)
block|{
comment|// No QGraphicsView::setScale :(
comment|//m_view->scale(scale / 10.0, scale / 10.0);
comment|//if (m_rootItem)
comment|//    m_view->ensureVisible(m_rootItem);
block|}
end_function
begin_function
DECL|function|updateItems
name|void
name|AccessibilitySceneManager
operator|::
name|updateItems
parameter_list|(
name|QObject
modifier|*
name|root
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|root
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|interface
condition|)
return|return;
name|updateItem
argument_list|(
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|root
argument_list|)
argument_list|,
name|interface
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interface
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|child
init|=
name|interface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|updateItems
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|child
expr_stmt|;
block|}
operator|delete
name|interface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateItem
name|void
name|AccessibilitySceneManager
operator|::
name|updateItem
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|object
condition|)
return|return;
name|QAccessibleInterface
modifier|*
name|interface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|interface
condition|)
return|return;
name|updateItem
argument_list|(
name|m_graphicsItems
operator|.
name|value
argument_list|(
name|object
argument_list|)
argument_list|,
name|interface
argument_list|)
expr_stmt|;
operator|delete
name|interface
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateItem
name|void
name|AccessibilitySceneManager
operator|::
name|updateItem
parameter_list|(
name|QGraphicsRectItem
modifier|*
name|item
parameter_list|,
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
if|if
condition|(
operator|!
name|item
condition|)
return|return;
name|QRect
name|rect
init|=
name|interface
operator|->
name|rect
argument_list|()
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|rect
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|updateItemFlags
argument_list|(
name|item
argument_list|,
name|interface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateItemFlags
name|void
name|AccessibilitySceneManager
operator|::
name|updateItemFlags
parameter_list|(
name|QGraphicsRectItem
modifier|*
name|item
parameter_list|,
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
comment|//  qDebug()<< "udpateItemFlags"<< interface<< interface->object();
name|bool
name|shouldShow
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|m_optionsWidget
operator|->
name|hideInvisibleItems
argument_list|()
condition|)
block|{
if|if
condition|(
name|isHidden
argument_list|(
name|interface
argument_list|)
condition|)
block|{
name|shouldShow
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_optionsWidget
operator|->
name|hideOffscreenItems
argument_list|()
condition|)
block|{
if|if
condition|(
name|interface
operator|->
name|state
argument_list|()
operator|.
name|offscreen
condition|)
block|{
name|shouldShow
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_optionsWidget
operator|->
name|hidePaneItems
argument_list|()
condition|)
block|{
if|if
condition|(
name|interface
operator|->
name|role
argument_list|()
operator|&
name|QAccessible
operator|::
name|Pane
condition|)
block|{
name|shouldShow
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_optionsWidget
operator|->
name|hideNullObjectItems
argument_list|()
condition|)
block|{
if|if
condition|(
name|interface
operator|->
name|object
argument_list|()
operator|==
literal|0
condition|)
block|{
name|shouldShow
operator|=
literal|false
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_optionsWidget
operator|->
name|hideNullRectItems
argument_list|()
condition|)
block|{
if|if
condition|(
name|interface
operator|->
name|rect
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|shouldShow
operator|=
literal|false
expr_stmt|;
block|}
block|}
name|item
operator|->
name|setVisible
argument_list|(
name|shouldShow
argument_list|)
expr_stmt|;
if|if
condition|(
name|interface
operator|->
name|object
argument_list|()
operator|&&
name|interface
operator|->
name|object
argument_list|()
operator|==
name|m_selectedObject
condition|)
name|item
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|item
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|m_view
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processInterface
name|QGraphicsRectItem
modifier|*
name|AccessibilitySceneManager
operator|::
name|processInterface
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|,
name|QGraphicsScene
modifier|*
name|scene
parameter_list|)
block|{
comment|// Process this interface
name|QGraphicsRectItem
modifier|*
name|item
init|=
operator|new
name|QGraphicsRectItem
argument_list|()
decl_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_rootItem
condition|)
name|m_rootItem
operator|=
name|item
expr_stmt|;
name|QString
name|name
init|=
name|interface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|)
decl_stmt|;
name|QString
name|description
decl_stmt|;
comment|// = interface->text(QAccessibleInterface::Description, child);
name|QString
name|role
init|=
name|translateRole
argument_list|(
name|interface
operator|->
name|role
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|childCount
init|=
name|interface
operator|->
name|childCount
argument_list|()
decl_stmt|;
comment|/* qDebug()<< "name:"<< name<< "local pos"<<                interface->rect(0)<< "description"<< description<< "childCount"<< childCount; */
name|updateItem
argument_list|(
name|item
argument_list|,
name|interface
argument_list|)
expr_stmt|;
name|QGraphicsSimpleTextItem
modifier|*
name|textItem
init|=
operator|new
name|QGraphicsSimpleTextItem
argument_list|()
decl_stmt|;
name|textItem
operator|->
name|setParentItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setPos
argument_list|(
name|QPoint
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|text
decl_stmt|;
name|text
operator|.
name|append
argument_list|(
literal|"Name: "
operator|+
name|name
operator|+
literal|" "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|description
operator|.
name|isEmpty
argument_list|()
condition|)
name|text
operator|.
name|append
argument_list|(
literal|"Description: "
operator|+
name|description
operator|+
literal|" "
argument_list|)
expr_stmt|;
name|text
operator|.
name|append
argument_list|(
literal|"Role: "
operator|+
name|role
operator|+
literal|" "
argument_list|)
expr_stmt|;
if|if
condition|(
name|childCount
operator|>
literal|0
condition|)
name|text
operator|.
name|append
argument_list|(
literal|"ChildCount: "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|childCount
argument_list|)
operator|+
literal|" "
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|//   font.setPointSize(14);
name|textItem
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|populateAccessibilityScene
name|void
name|AccessibilitySceneManager
operator|::
name|populateAccessibilityScene
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|,
name|QGraphicsScene
modifier|*
name|scene
parameter_list|)
block|{
if|if
condition|(
operator|!
name|interface
condition|)
return|return;
name|QGraphicsRectItem
modifier|*
name|item
init|=
name|processInterface
argument_list|(
name|interface
argument_list|,
name|scene
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|object
init|=
name|interface
operator|->
name|object
argument_list|()
decl_stmt|;
if|if
condition|(
name|object
condition|)
block|{
name|m_graphicsItems
operator|.
name|insert
argument_list|(
name|object
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interface
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|child
init|=
name|interface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|updateItems
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
expr_stmt|;
name|populateAccessibilityScene
argument_list|(
name|child
argument_list|,
name|scene
argument_list|)
expr_stmt|;
operator|delete
name|child
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|computeLevels
name|AccessibilitySceneManager
operator|::
name|TreeItem
name|AccessibilitySceneManager
operator|::
name|computeLevels
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|,
name|int
name|level
parameter_list|)
block|{
if|if
condition|(
name|interface
operator|==
literal|0
condition|)
return|return
name|TreeItem
argument_list|()
return|;
name|TreeItem
name|currentLevel
decl_stmt|;
name|int
name|usedChildren
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|interface
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|child
init|=
name|interface
operator|->
name|child
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|child
operator|!=
literal|0
condition|)
block|{
operator|++
name|usedChildren
expr_stmt|;
name|TreeItem
name|childLevel
init|=
name|computeLevels
argument_list|(
name|child
argument_list|,
name|level
operator|+
literal|1
argument_list|)
decl_stmt|;
name|currentLevel
operator|.
name|children
operator|.
name|append
argument_list|(
name|childLevel
argument_list|)
expr_stmt|;
name|currentLevel
operator|.
name|width
operator|+=
name|childLevel
operator|.
name|width
operator|+
name|m_treeItemHorizontalPadding
expr_stmt|;
operator|delete
name|child
expr_stmt|;
block|}
block|}
comment|// leaf node case
if|if
condition|(
name|usedChildren
operator|==
literal|0
condition|)
block|{
name|currentLevel
operator|.
name|width
operator|=
name|m_treeItemWidth
operator|+
name|m_treeItemHorizontalPadding
expr_stmt|;
block|}
comment|// capture information:
name|currentLevel
operator|.
name|name
operator|=
name|interface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|)
expr_stmt|;
name|currentLevel
operator|.
name|description
operator|+=
name|interface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|DebugDescription
argument_list|)
expr_stmt|;
name|currentLevel
operator|.
name|role
operator|=
name|translateRole
argument_list|(
name|interface
operator|->
name|role
argument_list|()
argument_list|)
expr_stmt|;
name|currentLevel
operator|.
name|rect
operator|=
name|interface
operator|->
name|rect
argument_list|()
expr_stmt|;
name|currentLevel
operator|.
name|state
operator|=
name|interface
operator|->
name|state
argument_list|()
expr_stmt|;
name|currentLevel
operator|.
name|object
operator|=
name|interface
operator|->
name|object
argument_list|()
expr_stmt|;
return|return
name|currentLevel
return|;
block|}
end_function
begin_function
DECL|function|populateAccessibilityTreeScene
name|void
name|AccessibilitySceneManager
operator|::
name|populateAccessibilityTreeScene
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
if|if
condition|(
operator|!
name|interface
condition|)
return|return;
comment|// set some layout metrics:
name|m_treeItemWidth
operator|=
literal|90
expr_stmt|;
name|m_treeItemHorizontalPadding
operator|=
literal|10
expr_stmt|;
name|m_treeItemHeight
operator|=
literal|60
expr_stmt|;
name|m_treeItemVerticalPadding
operator|=
literal|30
expr_stmt|;
comment|// We want to draw the accessibility hiearchy as a vertical
comment|// tree, growing from the root node at the top.
comment|// First, figure out the number of levels and the width of each level:
name|m_rootTreeItem
operator|=
name|computeLevels
argument_list|(
name|interface
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// create graphics items for each tree item
name|addGraphicsItems
argument_list|(
name|m_rootTreeItem
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addGraphicsItems
name|void
name|AccessibilitySceneManager
operator|::
name|addGraphicsItems
parameter_list|(
name|AccessibilitySceneManager
operator|::
name|TreeItem
name|item
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|xPos
parameter_list|)
block|{
comment|//qDebug()<< "add graphics item"<< row<< item.name<< item.role<< xPos<< item.width<< item.children.count();
name|int
name|yPos
init|=
name|row
operator|*
operator|(
name|m_treeItemHeight
operator|+
name|m_treeItemVerticalPadding
operator|)
decl_stmt|;
comment|// Process this interface
name|QGraphicsRectItem
modifier|*
name|graphicsItem
init|=
operator|new
name|QGraphicsRectItem
argument_list|()
decl_stmt|;
name|graphicsItem
operator|->
name|setPos
argument_list|(
name|xPos
argument_list|,
name|yPos
argument_list|)
expr_stmt|;
name|graphicsItem
operator|->
name|setRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_treeItemWidth
argument_list|,
name|m_treeItemHeight
argument_list|)
expr_stmt|;
name|graphicsItem
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsChildrenToShape
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|.
name|object
operator|&&
name|item
operator|.
name|object
operator|==
name|m_selectedObject
condition|)
name|graphicsItem
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|graphicsItem
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|.
name|state
operator|.
name|offscreen
condition|)
block|{
name|QPen
name|linePen
decl_stmt|;
name|linePen
operator|.
name|setStyle
argument_list|(
name|Qt
operator|::
name|DashLine
argument_list|)
expr_stmt|;
name|graphicsItem
operator|->
name|setPen
argument_list|(
name|linePen
argument_list|)
expr_stmt|;
block|}
name|m_treeScene
operator|->
name|addItem
argument_list|(
name|graphicsItem
argument_list|)
expr_stmt|;
name|QGraphicsTextItem
modifier|*
name|textItem
init|=
operator|new
name|QGraphicsTextItem
argument_list|()
decl_stmt|;
name|textItem
operator|->
name|setParentItem
argument_list|(
name|graphicsItem
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setPos
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|textItem
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|QString
name|text
decl_stmt|;
name|text
operator|+=
name|item
operator|.
name|name
operator|+
literal|"\n"
expr_stmt|;
name|text
operator|+=
name|item
operator|.
name|role
operator|+
literal|"\n"
expr_stmt|;
name|text
operator|+=
name|item
operator|.
name|description
operator|.
name|split
argument_list|(
literal|" "
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
operator|.
name|join
argument_list|(
literal|"\n"
argument_list|)
operator|+
literal|"\n"
expr_stmt|;
name|text
operator|+=
literal|"P:"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|item
operator|.
name|rect
operator|.
name|x
argument_list|()
argument_list|)
operator|+
literal|" "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|item
operator|.
name|rect
operator|.
name|y
argument_list|()
argument_list|)
operator|+
literal|" "
expr_stmt|;
name|text
operator|+=
literal|"S:"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|item
operator|.
name|rect
operator|.
name|width
argument_list|()
argument_list|)
operator|+
literal|" "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|item
operator|.
name|rect
operator|.
name|height
argument_list|()
argument_list|)
operator|+
literal|"\n"
expr_stmt|;
name|textItem
operator|->
name|setPlainText
argument_list|(
name|text
argument_list|)
expr_stmt|;
comment|// recurse to children
name|int
name|childIndex
init|=
literal|0
decl_stmt|;
name|int
name|childCount
init|=
name|item
operator|.
name|children
operator|.
name|count
argument_list|()
decl_stmt|;
name|int
name|segmentSize
init|=
name|item
operator|.
name|width
operator|/
name|qMax
argument_list|(
literal|1
argument_list|,
name|childCount
argument_list|)
decl_stmt|;
name|int
name|segmentCenterOffset
init|=
name|segmentSize
operator|/
literal|2
decl_stmt|;
name|int
name|segmentsStart
init|=
name|xPos
operator|-
operator|(
name|item
operator|.
name|width
operator|/
literal|2
operator|)
decl_stmt|;
foreach|foreach
control|(
name|TreeItem
name|child
decl|,
name|item
operator|.
name|children
control|)
block|{
comment|// spread the children out, covering the width, centered on xPos
name|int
name|segmentPosition
init|=
name|segmentsStart
operator|+
operator|(
name|segmentSize
operator|*
name|childIndex
operator|)
operator|+
name|segmentCenterOffset
decl_stmt|;
name|addGraphicsItems
argument_list|(
name|child
argument_list|,
name|row
operator|+
literal|1
argument_list|,
name|segmentPosition
argument_list|)
expr_stmt|;
operator|++
name|childIndex
expr_stmt|;
block|}
comment|// add lines from parents to kids
name|int
name|boxBottom
init|=
name|yPos
operator|+
name|m_treeItemHeight
decl_stmt|;
name|int
name|boxMiddleX
init|=
name|xPos
operator|+
name|m_treeItemWidth
operator|/
literal|2
decl_stmt|;
name|int
name|yBottomMiddle
init|=
name|boxBottom
operator|+
name|m_treeItemVerticalPadding
operator|/
literal|2
decl_stmt|;
name|int
name|boxTop
init|=
name|yPos
decl_stmt|;
name|int
name|yTopMiddle
init|=
name|boxTop
operator|-
name|m_treeItemVerticalPadding
operator|/
literal|2
decl_stmt|;
if|if
condition|(
name|row
operator|>
literal|0
condition|)
block|{
name|QGraphicsLineItem
modifier|*
name|childVerticalStem
init|=
operator|new
name|QGraphicsLineItem
argument_list|()
decl_stmt|;
name|childVerticalStem
operator|->
name|setLine
argument_list|(
name|boxMiddleX
argument_list|,
name|yTopMiddle
argument_list|,
name|boxMiddleX
argument_list|,
name|boxTop
argument_list|)
expr_stmt|;
name|m_treeScene
operator|->
name|addItem
argument_list|(
name|childVerticalStem
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|childCount
operator|>
literal|0
condition|)
block|{
name|QGraphicsLineItem
modifier|*
name|parentVerticalStem
init|=
operator|new
name|QGraphicsLineItem
argument_list|()
decl_stmt|;
name|parentVerticalStem
operator|->
name|setLine
argument_list|(
name|boxMiddleX
argument_list|,
name|boxBottom
argument_list|,
name|boxMiddleX
argument_list|,
name|yBottomMiddle
argument_list|)
expr_stmt|;
name|m_treeScene
operator|->
name|addItem
argument_list|(
name|parentVerticalStem
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|childCount
operator|>
literal|1
condition|)
block|{
name|QGraphicsLineItem
modifier|*
name|horizontalStem
init|=
operator|new
name|QGraphicsLineItem
argument_list|()
decl_stmt|;
comment|// match the end points with the horizontal lines
name|int
name|lineStartX
init|=
name|segmentsStart
operator|+
name|segmentCenterOffset
operator|+
name|m_treeItemWidth
operator|/
literal|2
decl_stmt|;
name|int
name|lineStopX
init|=
name|segmentsStart
operator|+
name|segmentSize
operator|*
operator|(
name|childCount
operator|-
literal|1
operator|)
operator|+
name|segmentCenterOffset
operator|+
name|m_treeItemWidth
operator|/
literal|2
decl_stmt|;
name|horizontalStem
operator|->
name|setLine
argument_list|(
name|lineStartX
argument_list|,
name|yBottomMiddle
argument_list|,
name|lineStopX
argument_list|,
name|yBottomMiddle
argument_list|)
expr_stmt|;
name|m_treeScene
operator|->
name|addItem
argument_list|(
name|horizontalStem
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isHidden
name|bool
name|AccessibilitySceneManager
operator|::
name|isHidden
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
name|current
init|=
name|interface
decl_stmt|;
while|while
condition|(
name|current
condition|)
block|{
if|if
condition|(
name|current
operator|->
name|state
argument_list|()
operator|.
name|invisible
condition|)
block|{
return|return
literal|true
return|;
block|}
name|QAccessibleInterface
modifier|*
name|parent
init|=
name|current
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
name|current
operator|!=
name|interface
condition|)
operator|delete
name|current
expr_stmt|;
name|current
operator|=
name|parent
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
end_unit
