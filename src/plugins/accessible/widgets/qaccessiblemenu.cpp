begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblemenu.h"
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qmenubar.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QAction>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|QString
name|Q_GUI_EXPORT
name|qt_accStripAmp
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QString
name|Q_GUI_EXPORT
name|qt_accHotKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_constructor
DECL|function|QAccessibleMenu
name|QAccessibleMenu
operator|::
name|QAccessibleMenu
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|menu
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|menu
name|QMenu
modifier|*
name|QAccessibleMenu
operator|::
name|menu
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleMenu
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|QAccessibleMenu
operator|::
name|rect
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|QAccessibleWidget
operator|::
name|rect
argument_list|(
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|int
name|QAccessibleMenu
operator|::
name|childAt
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
specifier|const
block|{
name|QAction
modifier|*
name|act
init|=
name|menu
argument_list|()
operator|->
name|actionAt
argument_list|(
name|menu
argument_list|()
operator|->
name|mapFromGlobal
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|act
operator|&&
name|act
operator|->
name|isSeparator
argument_list|()
condition|)
name|act
operator|=
literal|0
expr_stmt|;
return|return
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|act
argument_list|)
operator|+
literal|1
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleMenu
operator|::
name|text
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QString
name|tx
init|=
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|,
name|child
argument_list|)
decl_stmt|;
if|if
condition|(
name|tx
operator|.
name|size
argument_list|()
condition|)
return|return
name|tx
return|;
if|if
condition|(
name|t
operator|==
name|Name
condition|)
return|return
name|menu
argument_list|()
operator|->
name|windowTitle
argument_list|()
return|;
return|return
name|tx
return|;
block|}
end_function
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleMenu
operator|::
name|role
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|PopupMenu
return|;
block|}
end_function
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleMenu
operator|::
name|state
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|State
name|s
init|=
name|QAccessibleWidget
operator|::
name|state
argument_list|(
name|child
argument_list|)
decl_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|actionText
name|QString
name|QAccessibleMenu
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|QAccessible
operator|::
name|Text
name|text
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|QAccessibleWidget
operator|::
name|actionText
argument_list|(
name|action
argument_list|,
name|text
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|bool
name|QAccessibleMenu
operator|::
name|doAction
parameter_list|(
name|int
name|act
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
parameter_list|)
block|{
comment|//    Q_ASSERT(child == 0);
if|if
condition|(
operator|!
name|child
operator|||
name|act
operator|!=
name|QAccessible
operator|::
name|DefaultAction
condition|)
return|return
literal|false
return|;
name|QAction
modifier|*
name|action
init|=
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|child
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|action
operator|||
operator|!
name|action
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|action
operator|->
name|menu
argument_list|()
operator|&&
name|action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
name|action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
else|else
name|menu
argument_list|()
operator|->
name|setActiveAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenu
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|<
name|childCount
argument_list|()
condition|)
return|return
operator|new
name|QAccessibleMenuItem
argument_list|(
name|menu
argument_list|()
argument_list|,
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|QAccessibleMenu
operator|::
name|parent
parameter_list|()
specifier|const
block|{
name|QWidget
modifier|*
name|parent
init|=
name|menu
argument_list|()
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
operator|||
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
condition|)
block|{
return|return
operator|new
name|QAccessibleMenuItem
argument_list|(
name|parent
argument_list|,
name|menu
argument_list|()
operator|->
name|menuAction
argument_list|()
argument_list|)
return|;
block|}
return|return
name|QAccessibleWidget
operator|::
name|parent
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|navigate
name|int
name|QAccessibleMenu
operator|::
name|navigate
parameter_list|(
name|RelationFlag
name|relation
parameter_list|,
name|int
name|entry
parameter_list|,
name|QAccessibleInterface
modifier|*
modifier|*
name|target
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|entry
operator|>=
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|relation
condition|)
block|{
case|case
name|Child
case|:
operator|*
name|target
operator|=
name|child
argument_list|(
name|entry
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
operator|*
name|target
condition|?
literal|0
else|:
operator|-
literal|1
return|;
case|case
name|Ancestor
case|:
operator|*
name|target
operator|=
name|parent
argument_list|()
expr_stmt|;
return|return
operator|*
name|target
condition|?
literal|0
else|:
operator|-
literal|1
return|;
default|default:
return|return
name|QAccessibleWidget
operator|::
name|navigate
argument_list|(
name|relation
argument_list|,
name|entry
argument_list|,
name|target
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenu
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
name|int
name|index
init|=
operator|-
literal|1
decl_stmt|;
name|Role
name|r
init|=
name|child
operator|->
name|role
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|==
name|MenuItem
operator|||
name|r
operator|==
name|Separator
operator|)
operator|&&
name|menu
argument_list|()
condition|)
block|{
name|index
operator|=
name|menu
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
operator|++
name|index
expr_stmt|;
block|}
return|return
name|index
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
end_ifndef
begin_constructor
DECL|function|QAccessibleMenuBar
name|QAccessibleMenuBar
operator|::
name|QAccessibleMenuBar
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|QAccessibleWidget
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|menuBar
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|menuBar
name|QMenuBar
modifier|*
name|QAccessibleMenuBar
operator|::
name|menuBar
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleMenuBar
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|QAccessibleMenuBar
operator|::
name|rect
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|QAccessibleWidget
operator|::
name|rect
argument_list|(
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|childAt
name|int
name|QAccessibleMenuBar
operator|::
name|childAt
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
name|childCount
argument_list|()
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|rect
argument_list|(
name|i
argument_list|)
operator|.
name|contains
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuBar
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|<
name|childCount
argument_list|()
condition|)
return|return
operator|new
name|QAccessibleMenuItem
argument_list|(
name|menuBar
argument_list|()
argument_list|,
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|navigate
name|int
name|QAccessibleMenuBar
operator|::
name|navigate
parameter_list|(
name|RelationFlag
name|relation
parameter_list|,
name|int
name|entry
parameter_list|,
name|QAccessibleInterface
modifier|*
modifier|*
name|target
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|relation
operator|==
name|Child
condition|)
block|{
operator|*
name|target
operator|=
name|child
argument_list|(
name|entry
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
operator|*
name|target
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
return|return
name|QAccessibleWidget
operator|::
name|navigate
argument_list|(
name|relation
argument_list|,
name|entry
argument_list|,
name|target
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenuBar
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
name|int
name|index
init|=
operator|-
literal|1
decl_stmt|;
name|Role
name|r
init|=
name|child
operator|->
name|role
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|==
name|MenuItem
operator|||
name|r
operator|==
name|Separator
operator|)
operator|&&
name|menuBar
argument_list|()
condition|)
block|{
name|index
operator|=
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
operator|++
name|index
expr_stmt|;
block|}
return|return
name|index
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleMenuBar
operator|::
name|text
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|QAccessibleWidget
operator|::
name|text
argument_list|(
name|t
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleMenuBar
operator|::
name|role
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|MenuBar
return|;
block|}
end_function
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleMenuBar
operator|::
name|state
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|State
name|s
init|=
name|QAccessibleWidget
operator|::
name|state
argument_list|(
name|child
argument_list|)
decl_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|actionText
name|QString
name|QAccessibleMenuBar
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|QAccessible
operator|::
name|Text
name|text
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
name|QAccessibleWidget
operator|::
name|actionText
argument_list|(
name|action
argument_list|,
name|text
argument_list|,
name|child
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|doAction
name|bool
name|QAccessibleMenuBar
operator|::
name|doAction
parameter_list|(
name|int
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
parameter_list|)
block|{
comment|//    Q_ASSERT(child == 0);
name|QAction
modifier|*
name|action
init|=
name|menuBar
argument_list|()
operator|->
name|actions
argument_list|()
operator|.
name|value
argument_list|(
name|child
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|action
operator|||
operator|!
name|action
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|action
operator|->
name|menu
argument_list|()
operator|&&
name|action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
name|action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
else|else
block|{
name|menuBar
argument_list|()
operator|->
name|setActiveAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENUBAR
end_comment
begin_constructor
DECL|function|QAccessibleMenuItem
name|QAccessibleMenuItem
operator|::
name|QAccessibleMenuItem
parameter_list|(
name|QWidget
modifier|*
name|owner
parameter_list|,
name|QAction
modifier|*
name|action
parameter_list|)
member_init_list|:
name|m_action
argument_list|(
name|action
argument_list|)
member_init_list|,
name|m_owner
argument_list|(
name|owner
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QAccessibleMenuItem
name|QAccessibleMenuItem
operator|::
name|~
name|QAccessibleMenuItem
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|childAt
name|int
name|QAccessibleMenuItem
operator|::
name|childAt
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
name|childCount
argument_list|()
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|rect
argument_list|(
name|i
argument_list|)
operator|.
name|contains
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|childCount
name|int
name|QAccessibleMenuItem
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
return|return
name|m_action
operator|->
name|menu
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|actionText
name|QString
name|QAccessibleMenuItem
operator|::
name|actionText
parameter_list|(
name|int
name|action
parameter_list|,
name|Text
name|text
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_action
operator|||
name|m_action
operator|->
name|isSeparator
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|text
operator|==
name|Name
operator|&&
operator|(
operator|(
name|action
operator|==
name|Press
operator|)
operator|||
operator|(
name|action
operator|==
name|DefaultAction
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
condition|)
block|{
return|return
name|QMenu
operator|::
name|tr
argument_list|(
literal|"Open"
argument_list|)
return|;
block|}
return|return
name|QMenu
operator|::
name|tr
argument_list|(
literal|"Execute"
argument_list|)
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//QAction *action = menuBar()->actions().value(child-1, 0);
end_comment
begin_comment
comment|//if (!action || !action->isEnabled())
end_comment
begin_comment
comment|//    return false;
end_comment
begin_comment
comment|//if (action->menu()&& action->menu()->isVisible())
end_comment
begin_comment
comment|//    action->menu()->hide();
end_comment
begin_comment
comment|//else
end_comment
begin_comment
comment|//    menuBar()->setActiveAction(action);
end_comment
begin_comment
comment|//return true;
end_comment
begin_function
DECL|function|doAction
name|bool
name|QAccessibleMenuItem
operator|::
name|doAction
parameter_list|(
name|int
name|action
parameter_list|,
name|int
name|child
parameter_list|,
specifier|const
name|QVariantList
modifier|&
comment|/*params = QVariantList()*/
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|action
operator|!=
name|Press
operator|)
operator|&&
operator|(
name|action
operator|!=
name|DefaultAction
operator|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|m_action
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|QMenuBar
modifier|*
name|bar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|owner
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
operator|&&
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
name|bar
operator|->
name|setActiveAction
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
elseif|else
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|owner
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_action
operator|->
name|menu
argument_list|()
operator|&&
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|m_action
operator|->
name|menu
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
name|menu
operator|->
name|setActiveAction
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
else|else
block|{
comment|// no menu
name|m_action
operator|->
name|trigger
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleMenuItem
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|child
operator|->
name|role
argument_list|(
literal|0
argument_list|)
operator|==
name|PopupMenu
operator|&&
name|child
operator|->
name|object
argument_list|()
operator|==
name|m_action
operator|->
name|menu
argument_list|()
condition|)
return|return
literal|1
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QAccessibleMenuItem
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|m_action
condition|?
literal|true
else|:
literal|false
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuItem
operator|::
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|owner
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleMenuItem
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|index
operator|==
literal|0
operator|&&
name|action
argument_list|()
operator|->
name|menu
argument_list|()
condition|)
return|return
operator|new
name|QAccessibleMenu
argument_list|(
name|action
argument_list|()
operator|->
name|menu
argument_list|()
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|navigate
name|int
name|QAccessibleMenuItem
operator|::
name|navigate
parameter_list|(
name|RelationFlag
name|relation
parameter_list|,
name|int
name|entry
parameter_list|,
name|QAccessibleInterface
modifier|*
modifier|*
name|target
parameter_list|)
specifier|const
block|{
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|entry
operator|<
literal|0
condition|)
block|{
operator|*
name|target
operator|=
literal|0
expr_stmt|;
return|return
name|ret
return|;
block|}
switch|switch
condition|(
name|relation
condition|)
block|{
case|case
name|Child
case|:
operator|*
name|target
operator|=
name|child
argument_list|(
name|entry
operator|-
literal|1
argument_list|)
expr_stmt|;
name|ret
operator|=
operator|*
name|target
condition|?
literal|0
else|:
operator|-
literal|1
expr_stmt|;
break|break;
case|case
name|Ancestor
case|:
operator|*
name|target
operator|=
name|parent
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
case|case
name|Up
case|:
case|case
name|Down
case|:
block|{
name|QAccessibleInterface
modifier|*
name|parent
init|=
literal|0
decl_stmt|;
name|int
name|ent
init|=
name|navigate
argument_list|(
name|Ancestor
argument_list|,
literal|1
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|ent
operator|==
literal|0
condition|)
block|{
name|int
name|index
init|=
name|parent
operator|->
name|indexOfChild
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|index
operator|+=
operator|(
name|relation
operator|==
name|Down
condition|?
operator|+
literal|1
else|:
operator|-
literal|1
operator|)
expr_stmt|;
name|ret
operator|=
name|parent
operator|->
name|navigate
argument_list|(
name|Child
argument_list|,
name|index
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
block|}
operator|delete
name|parent
expr_stmt|;
break|break;
block|}
case|case
name|Sibling
case|:
block|{
name|QAccessibleInterface
modifier|*
name|parent
init|=
literal|0
decl_stmt|;
name|int
name|ent
init|=
name|navigate
argument_list|(
name|Ancestor
argument_list|,
literal|1
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|ent
operator|==
literal|0
condition|)
block|{
name|ret
operator|=
name|parent
operator|->
name|navigate
argument_list|(
name|Child
argument_list|,
name|entry
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
operator|delete
name|parent
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
operator|*
name|target
operator|=
literal|0
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|object
name|QObject
modifier|*
name|QAccessibleMenuItem
operator|::
name|object
parameter_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|QAccessibleMenuItem
operator|::
name|rect
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QRect
name|rect
decl_stmt|;
name|QWidget
modifier|*
name|own
init|=
name|owner
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
if|if
condition|(
name|QMenuBar
modifier|*
name|menuBar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
name|rect
operator|=
name|menuBar
operator|->
name|actionGeometry
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
name|QPoint
name|globalPos
init|=
name|menuBar
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|rect
operator|=
name|rect
operator|.
name|translated
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
comment|// QT_NO_MENUBAR
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
name|rect
operator|=
name|menu
operator|->
name|actionGeometry
argument_list|(
name|m_action
argument_list|)
expr_stmt|;
name|QPoint
name|globalPos
init|=
name|menu
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|rect
operator|=
name|rect
operator|.
name|translated
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
block|}
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|relationTo
name|QAccessible
operator|::
name|Relation
name|QAccessibleMenuItem
operator|::
name|relationTo
parameter_list|(
name|int
name|child
parameter_list|,
specifier|const
name|QAccessibleInterface
modifier|*
name|other
parameter_list|,
name|int
name|otherChild
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|other
operator|->
name|object
argument_list|()
operator|==
name|owner
argument_list|()
condition|)
block|{
return|return
name|Child
return|;
block|}
name|Q_UNUSED
argument_list|(
argument|child
argument_list|)
name|Q_UNUSED
argument_list|(
argument|other
argument_list|)
name|Q_UNUSED
argument_list|(
argument|otherChild
argument_list|)
comment|// ###
return|return
name|Unrelated
return|;
block|}
end_function
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleMenuItem
operator|::
name|role
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|//    if (m_action->menu())
comment|//        return PopupMenu;
return|return
name|m_action
operator|->
name|isSeparator
argument_list|()
condition|?
name|Separator
else|:
name|MenuItem
return|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|QAccessibleMenuItem
operator|::
name|setText
parameter_list|(
name|Text
comment|/*t*/
parameter_list|,
name|int
comment|/*child*/
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/*text */
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleMenuItem
operator|::
name|state
parameter_list|(
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QAccessible
operator|::
name|State
name|s
init|=
name|Normal
decl_stmt|;
name|QWidget
modifier|*
name|own
init|=
name|owner
argument_list|()
decl_stmt|;
if|if
condition|(
name|own
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Visible
argument_list|)
operator|==
literal|false
operator|||
name|m_action
operator|->
name|isVisible
argument_list|()
operator|==
literal|false
condition|)
block|{
name|s
operator||=
name|Invisible
expr_stmt|;
block|}
if|if
condition|(
name|QMenu
modifier|*
name|menu
init|=
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
if|if
condition|(
name|menu
operator|->
name|activeAction
argument_list|()
operator|==
name|m_action
condition|)
name|s
operator||=
name|Focused
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
block|}
elseif|else
if|if
condition|(
name|QMenuBar
modifier|*
name|menuBar
init|=
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|own
argument_list|)
condition|)
block|{
if|if
condition|(
name|menuBar
operator|->
name|activeAction
argument_list|()
operator|==
name|m_action
condition|)
name|s
operator||=
name|Focused
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|own
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Menu_MouseTracking
argument_list|)
condition|)
name|s
operator||=
name|HotTracked
expr_stmt|;
if|if
condition|(
name|m_action
operator|->
name|isSeparator
argument_list|()
operator|||
operator|!
name|m_action
operator|->
name|isEnabled
argument_list|()
condition|)
name|s
operator||=
name|Unavailable
expr_stmt|;
if|if
condition|(
name|m_action
operator|->
name|isChecked
argument_list|()
condition|)
name|s
operator||=
name|Checked
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|text
name|QString
name|QAccessibleMenuItem
operator|::
name|text
parameter_list|(
name|Text
name|t
parameter_list|,
name|int
name|child
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|child
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QString
name|str
decl_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Name
case|:
name|str
operator|=
name|m_action
operator|->
name|text
argument_list|()
expr_stmt|;
name|str
operator|=
name|qt_accStripAmp
argument_list|(
name|str
argument_list|)
expr_stmt|;
break|break;
case|case
name|Accelerator
case|:
block|{
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QKeySequence
name|key
init|=
name|m_action
operator|->
name|shortcut
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|=
name|key
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|str
operator|=
name|qt_accHotKey
argument_list|(
name|m_action
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
default|default:
break|break;
block|}
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|userActionCount
name|int
name|QAccessibleMenuItem
operator|::
name|userActionCount
parameter_list|(
name|int
comment|/*child*/
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|action
name|QAction
modifier|*
name|QAccessibleMenuItem
operator|::
name|action
parameter_list|()
specifier|const
block|{
return|return
name|m_action
return|;
block|}
end_function
begin_function
DECL|function|owner
name|QWidget
modifier|*
name|QAccessibleMenuItem
operator|::
name|owner
parameter_list|()
specifier|const
block|{
return|return
name|m_owner
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MENU
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
end_unit
