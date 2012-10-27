begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qstatemachine.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|<private/qstatemachine_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicssceneevent.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_CORE_EXPORT
specifier|const
name|QStateMachinePrivate
operator|::
name|Handler
modifier|*
name|qcoreStateMachineHandler
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|cloneEvent
specifier|static
name|QEvent
modifier|*
name|cloneEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseButtonDblClick
case|:
case|case
name|QEvent
operator|::
name|MouseMove
case|:
return|return
operator|new
name|QMouseEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|KeyPress
case|:
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
return|return
operator|new
name|QKeyEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|FocusIn
case|:
case|case
name|QEvent
operator|::
name|FocusOut
case|:
return|return
operator|new
name|QFocusEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QFocusEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Enter
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Leave
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Paint
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Move
case|:
return|return
operator|new
name|QMoveEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QMoveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Resize
case|:
return|return
operator|new
name|QResizeEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QResizeEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Create
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Destroy
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Show
case|:
return|return
operator|new
name|QShowEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QShowEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Hide
case|:
return|return
operator|new
name|QHideEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHideEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Close
case|:
return|return
operator|new
name|QCloseEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QCloseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Quit
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ParentChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ParentAboutToChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ThreadChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WindowActivate
case|:
case|case
name|QEvent
operator|::
name|WindowDeactivate
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ShowToParent
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|HideToParent
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
case|case
name|QEvent
operator|::
name|Wheel
case|:
return|return
operator|new
name|QWheelEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QWheelEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_WHEELEVENT
case|case
name|QEvent
operator|::
name|WindowTitleChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WindowIconChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ApplicationWindowIconChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ApplicationFontChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ApplicationLayoutDirectionChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ApplicationPaletteChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|PaletteChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Clipboard
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Speech
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MetaCall
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|SockAct
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WinEventAct
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|DeferredDelete
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
case|case
name|QEvent
operator|::
name|DragEnter
case|:
return|return
operator|new
name|QDragEnterEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QDragEnterEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|DragMove
case|:
return|return
operator|new
name|QDragMoveEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QDragMoveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|DragLeave
case|:
return|return
operator|new
name|QDragLeaveEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QDragLeaveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Drop
case|:
return|return
operator|new
name|QDropEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QDragMoveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|ChildAdded
case|:
return|return
operator|new
name|QChildEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QChildEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ChildPolished
case|:
return|return
operator|new
name|QChildEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QChildEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ChildRemoved
case|:
return|return
operator|new
name|QChildEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QChildEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ShowWindowRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|PolishRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Polish
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LayoutRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|UpdateRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|UpdateLater
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|EmbeddingControl
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ActivateControl
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|DeactivateControl
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
case|case
name|QEvent
operator|::
name|ContextMenu
case|:
return|return
operator|new
name|QContextMenuEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QContextMenuEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|InputMethod
case|:
return|return
operator|new
name|QInputMethodEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QInputMethodEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LocaleChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LanguageChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LayoutDirectionChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|Style
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
case|case
name|QEvent
operator|::
name|TabletMove
case|:
case|case
name|QEvent
operator|::
name|TabletPress
case|:
case|case
name|QEvent
operator|::
name|TabletRelease
case|:
return|return
operator|new
name|QTabletEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QTabletEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_TABLETEVENT
case|case
name|QEvent
operator|::
name|OkRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|HelpRequest
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|IconDrag
case|:
return|return
operator|new
name|QIconDragEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QIconDragEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|FontChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|EnabledChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ActivationChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|StyleChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|IconTextChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ModifiedChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|MouseTrackingChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WindowBlocked
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WindowUnblocked
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WindowStateChange
case|:
return|return
operator|new
name|QWindowStateChangeEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QWindowStateChangeEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ToolTip
case|:
return|return
operator|new
name|QHelpEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|WhatsThis
case|:
return|return
operator|new
name|QHelpEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_STATUSTIP
case|case
name|QEvent
operator|::
name|StatusTip
case|:
return|return
operator|new
name|QStatusTipEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QStatusTipEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_STATUSTIP
ifndef|#
directive|ifndef
name|QT_NO_ACTION
case|case
name|QEvent
operator|::
name|ActionChanged
case|:
case|case
name|QEvent
operator|::
name|ActionAdded
case|:
case|case
name|QEvent
operator|::
name|ActionRemoved
case|:
return|return
operator|new
name|QActionEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QActionEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|FileOpen
case|:
return|return
operator|new
name|QFileOpenEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QFileOpenEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
case|case
name|QEvent
operator|::
name|Shortcut
case|:
return|return
operator|new
name|QShortcutEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QShortcutEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_SHORTCUT
case|case
name|QEvent
operator|::
name|ShortcutOverride
case|:
return|return
operator|new
name|QKeyEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
case|case
name|QEvent
operator|::
name|WhatsThisClicked
case|:
return|return
operator|new
name|QWhatsThisClickedEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QWhatsThisClickedEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_WHATSTHIS
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
case|case
name|QEvent
operator|::
name|ToolBarChange
case|:
return|return
operator|new
name|QToolBarChangeEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QToolBarChangeEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_TOOLBAR
case|case
name|QEvent
operator|::
name|ApplicationActivate
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ApplicationDeactivate
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|QueryWhatsThis
case|:
return|return
operator|new
name|QHelpEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|EnterWhatsThisMode
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LeaveWhatsThisMode
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ZOrderChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|HoverEnter
case|:
case|case
name|QEvent
operator|::
name|HoverLeave
case|:
case|case
name|QEvent
operator|::
name|HoverMove
case|:
return|return
operator|new
name|QHoverEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHoverEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
case|case
name|QEvent
operator|::
name|EnterEditFocus
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|LeaveEditFocus
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|AcceptDropsChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ZeroTimerEvent
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseMove
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMousePress
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseRelease
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneMouseDoubleClick
case|:
block|{
name|QGraphicsSceneMouseEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneMouseEvent
modifier|*
name|me2
init|=
operator|new
name|QGraphicsSceneMouseEvent
argument_list|(
name|me
operator|->
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|me2
operator|->
name|setWidget
argument_list|(
name|me
operator|->
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setPos
argument_list|(
name|me
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setScenePos
argument_list|(
name|me
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setScreenPos
argument_list|(
name|me
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
comment|// ### for all buttons
name|me2
operator|->
name|setButtonDownPos
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|,
name|me
operator|->
name|buttonDownPos
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setButtonDownPos
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|,
name|me
operator|->
name|buttonDownPos
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|)
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setButtonDownScreenPos
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|,
name|me
operator|->
name|buttonDownScreenPos
argument_list|(
name|Qt
operator|::
name|LeftButton
argument_list|)
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setButtonDownScreenPos
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|,
name|me
operator|->
name|buttonDownScreenPos
argument_list|(
name|Qt
operator|::
name|RightButton
argument_list|)
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setLastPos
argument_list|(
name|me
operator|->
name|lastPos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setLastScenePos
argument_list|(
name|me
operator|->
name|lastScenePos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setLastScreenPos
argument_list|(
name|me
operator|->
name|lastScreenPos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setButtons
argument_list|(
name|me
operator|->
name|buttons
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setButton
argument_list|(
name|me
operator|->
name|button
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setModifiers
argument_list|(
name|me
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|me2
return|;
block|}
case|case
name|QEvent
operator|::
name|GraphicsSceneContextMenu
case|:
block|{
name|QGraphicsSceneContextMenuEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneContextMenuEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneContextMenuEvent
modifier|*
name|me2
init|=
operator|new
name|QGraphicsSceneContextMenuEvent
argument_list|(
name|me
operator|->
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|me2
operator|->
name|setWidget
argument_list|(
name|me
operator|->
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setPos
argument_list|(
name|me
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setScenePos
argument_list|(
name|me
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setScreenPos
argument_list|(
name|me
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setModifiers
argument_list|(
name|me
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setReason
argument_list|(
name|me
operator|->
name|reason
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|me2
return|;
block|}
case|case
name|QEvent
operator|::
name|GraphicsSceneHoverEnter
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneHoverMove
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneHoverLeave
case|:
block|{
name|QGraphicsSceneHoverEvent
modifier|*
name|he
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneHoverEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneHoverEvent
modifier|*
name|he2
init|=
operator|new
name|QGraphicsSceneHoverEvent
argument_list|(
name|he
operator|->
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|he2
operator|->
name|setPos
argument_list|(
name|he
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setScenePos
argument_list|(
name|he
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setScreenPos
argument_list|(
name|he
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setLastPos
argument_list|(
name|he
operator|->
name|lastPos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setLastScenePos
argument_list|(
name|he
operator|->
name|lastScenePos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setLastScreenPos
argument_list|(
name|he
operator|->
name|lastScreenPos
argument_list|()
argument_list|)
expr_stmt|;
name|he2
operator|->
name|setModifiers
argument_list|(
name|he
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|he2
return|;
block|}
case|case
name|QEvent
operator|::
name|GraphicsSceneHelp
case|:
return|return
operator|new
name|QHelpEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|GraphicsSceneDragEnter
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneDragMove
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneDragLeave
case|:
case|case
name|QEvent
operator|::
name|GraphicsSceneDrop
case|:
block|{
name|QGraphicsSceneDragDropEvent
modifier|*
name|dde
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneDragDropEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneDragDropEvent
modifier|*
name|dde2
init|=
operator|new
name|QGraphicsSceneDragDropEvent
argument_list|(
name|dde
operator|->
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|dde2
operator|->
name|setPos
argument_list|(
name|dde
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|dde2
operator|->
name|setScenePos
argument_list|(
name|dde
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
name|dde2
operator|->
name|setScreenPos
argument_list|(
name|dde
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
name|dde2
operator|->
name|setButtons
argument_list|(
name|dde
operator|->
name|buttons
argument_list|()
argument_list|)
expr_stmt|;
name|dde2
operator|->
name|setModifiers
argument_list|(
name|dde
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|dde2
return|;
block|}
case|case
name|QEvent
operator|::
name|GraphicsSceneWheel
case|:
block|{
name|QGraphicsSceneWheelEvent
modifier|*
name|we
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneWheelEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneWheelEvent
modifier|*
name|we2
init|=
operator|new
name|QGraphicsSceneWheelEvent
argument_list|(
name|we
operator|->
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|we2
operator|->
name|setPos
argument_list|(
name|we
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setScenePos
argument_list|(
name|we
operator|->
name|scenePos
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setScreenPos
argument_list|(
name|we
operator|->
name|screenPos
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setButtons
argument_list|(
name|we
operator|->
name|buttons
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setModifiers
argument_list|(
name|we
operator|->
name|modifiers
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setOrientation
argument_list|(
name|we
operator|->
name|orientation
argument_list|()
argument_list|)
expr_stmt|;
name|we2
operator|->
name|setDelta
argument_list|(
name|we
operator|->
name|delta
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|we2
return|;
block|}
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|KeyboardLayoutChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|DynamicPropertyChange
case|:
return|return
operator|new
name|QDynamicPropertyChangeEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QDynamicPropertyChangeEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_TABLETEVENT
case|case
name|QEvent
operator|::
name|TabletEnterProximity
case|:
case|case
name|QEvent
operator|::
name|TabletLeaveProximity
case|:
return|return
operator|new
name|QTabletEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QTabletEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
comment|//QT_NO_TABLETEVENT
case|case
name|QEvent
operator|::
name|NonClientAreaMouseMove
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|NonClientAreaMouseButtonDblClick
case|:
return|return
operator|new
name|QMouseEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|MacSizeChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ContentsRectChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|MacGLWindowChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|FutureCallOut
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
case|case
name|QEvent
operator|::
name|GraphicsSceneResize
case|:
block|{
name|QGraphicsSceneResizeEvent
modifier|*
name|re
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneResizeEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneResizeEvent
modifier|*
name|re2
init|=
operator|new
name|QGraphicsSceneResizeEvent
argument_list|()
decl_stmt|;
name|re2
operator|->
name|setOldSize
argument_list|(
name|re
operator|->
name|oldSize
argument_list|()
argument_list|)
expr_stmt|;
name|re2
operator|->
name|setNewSize
argument_list|(
name|re
operator|->
name|newSize
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|re2
return|;
block|}
case|case
name|QEvent
operator|::
name|GraphicsSceneMove
case|:
block|{
name|QGraphicsSceneMoveEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
name|QGraphicsSceneMoveEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QGraphicsSceneMoveEvent
modifier|*
name|me2
init|=
operator|new
name|QGraphicsSceneMoveEvent
argument_list|()
decl_stmt|;
name|me2
operator|->
name|setWidget
argument_list|(
name|me
operator|->
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setNewPos
argument_list|(
name|me
operator|->
name|newPos
argument_list|()
argument_list|)
expr_stmt|;
name|me2
operator|->
name|setOldPos
argument_list|(
name|me
operator|->
name|oldPos
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|me2
return|;
block|}
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|CursorChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|ToolTipChange
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|NetworkReplyUpdated
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|GrabMouse
case|:
case|case
name|QEvent
operator|::
name|UngrabMouse
case|:
case|case
name|QEvent
operator|::
name|GrabKeyboard
case|:
case|case
name|QEvent
operator|::
name|UngrabKeyboard
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
return|return
operator|new
name|QTouchEvent
argument_list|(
operator|*
cast|static_cast
argument_list|<
name|QTouchEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
case|case
name|QEvent
operator|::
name|NativeGesture
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|UpdateSoftKeys
case|:
return|return
operator|new
name|QEvent
argument_list|(
operator|*
name|e
argument_list|)
return|;
case|case
name|QEvent
operator|::
name|User
case|:
case|case
name|QEvent
operator|::
name|MaxUser
case|:
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"cloneEvent()"
argument_list|,
literal|"not implemented"
argument_list|)
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
return|return
name|qcoreStateMachineHandler
argument_list|()
operator|->
name|cloneEvent
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|qt_gui_statemachine_handler
specifier|const
name|QStateMachinePrivate
operator|::
name|Handler
name|qt_gui_statemachine_handler
init|=
block|{
name|cloneEvent
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_guistatemachine_last_handler
specifier|static
specifier|const
name|QStateMachinePrivate
operator|::
name|Handler
modifier|*
name|qt_guistatemachine_last_handler
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qRegisterGuiStateMachine
name|void
name|qRegisterGuiStateMachine
parameter_list|()
block|{
name|qt_guistatemachine_last_handler
operator|=
name|QStateMachinePrivate
operator|::
name|handler
expr_stmt|;
name|QStateMachinePrivate
operator|::
name|handler
operator|=
operator|&
name|qt_gui_statemachine_handler
expr_stmt|;
block|}
end_function
begin_macro
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
argument|qRegisterGuiStateMachine
argument_list|)
end_macro
begin_function
DECL|function|qUnregisterGuiStateMachine
name|void
name|qUnregisterGuiStateMachine
parameter_list|()
block|{
name|QStateMachinePrivate
operator|::
name|handler
operator|=
name|qt_guistatemachine_last_handler
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DESTRUCTOR_FUNCTION
argument_list|(
argument|qUnregisterGuiStateMachine
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
end_unit
