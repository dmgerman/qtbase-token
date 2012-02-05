begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qshortcut.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
end_ifndef
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qwhatsthis.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qshortcutmap_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qaction_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
DECL|macro|QAPP_CHECK
define|#
directive|define
name|QAPP_CHECK
parameter_list|(
name|functionName
parameter_list|)
define|\
value|if (!qApp) { \         qWarning("QShortcut: Initialize QApplication before calling '" functionName "'."); \         return; \     }
specifier|static
name|bool
name|correctWidgetContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_function_decl
specifier|static
name|bool
name|correctGraphicsWidgetContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QGraphicsWidget
modifier|*
name|w
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACTION
end_ifndef
begin_function_decl
specifier|static
name|bool
name|correctActionContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QAction
modifier|*
name|a
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*! \internal     Returns true if the widget \a w is a logical sub window of the current     top-level widget. */
end_comment
begin_function
DECL|function|qWidgetShortcutContextMatcher
name|bool
name|qWidgetShortcutContextMatcher
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|object
argument_list|,
literal|"QShortcutMap"
argument_list|,
literal|"Shortcut has no owner. Illegal map state!"
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|active_window
init|=
name|QApplication
operator|::
name|activeWindow
argument_list|()
decl_stmt|;
comment|// popups do not become the active window,
comment|// so we fake it here to get the correct context
comment|// for the shortcut system.
if|if
condition|(
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
condition|)
name|active_window
operator|=
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|active_window
condition|)
return|return
literal|false
return|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
if|if
condition|(
name|QAction
modifier|*
name|a
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
condition|)
return|return
name|correctActionContext
argument_list|(
name|context
argument_list|,
name|a
argument_list|,
name|active_window
argument_list|)
return|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
if|if
condition|(
name|QGraphicsWidget
modifier|*
name|gw
init|=
name|qobject_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
condition|)
return|return
name|correctGraphicsWidgetContext
argument_list|(
name|context
argument_list|,
name|gw
argument_list|,
name|active_window
argument_list|)
return|;
endif|#
directive|endif
name|QWidget
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
block|{
name|QShortcut
modifier|*
name|s
init|=
name|qobject_cast
argument_list|<
name|QShortcut
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
condition|)
name|w
operator|=
name|s
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|w
condition|)
return|return
literal|false
return|;
return|return
name|correctWidgetContext
argument_list|(
name|context
argument_list|,
name|w
argument_list|,
name|active_window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|correctWidgetContext
specifier|static
name|bool
name|correctWidgetContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
block|{
name|bool
name|visible
init|=
name|w
operator|->
name|isVisible
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
if|if
condition|(
operator|!
name|qApp
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_DontUseNativeMenuBar
argument_list|)
operator|&&
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
condition|)
name|visible
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|visible
operator|||
operator|!
name|w
operator|->
name|isEnabled
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|ApplicationShortcut
condition|)
return|return
name|QApplicationPrivate
operator|::
name|tryModalHelper
argument_list|(
name|w
argument_list|,
literal|0
argument_list|)
return|;
comment|// true, unless w is shadowed by a modal dialog
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|WidgetShortcut
condition|)
return|return
name|w
operator|==
name|QApplication
operator|::
name|focusWidget
argument_list|()
return|;
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|WidgetWithChildrenShortcut
condition|)
block|{
specifier|const
name|QWidget
modifier|*
name|tw
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
decl_stmt|;
while|while
condition|(
name|tw
operator|&&
name|tw
operator|!=
name|w
operator|&&
operator|(
name|tw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Widget
operator|||
name|tw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Popup
operator|)
condition|)
name|tw
operator|=
name|tw
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
return|return
name|tw
operator|==
name|w
return|;
block|}
comment|// Below is Qt::WindowShortcut context
name|QWidget
modifier|*
name|tlw
init|=
name|w
operator|->
name|window
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
if|if
condition|(
name|QWExtra
modifier|*
name|topData
init|=
cast|static_cast
argument_list|<
name|QWidgetPrivate
operator|*
argument_list|>
argument_list|(
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|tlw
argument_list|)
argument_list|)
operator|->
name|extra
condition|)
block|{
if|if
condition|(
name|topData
operator|->
name|proxyWidget
condition|)
block|{
name|bool
name|res
init|=
name|correctGraphicsWidgetContext
argument_list|(
name|context
argument_list|,
operator|(
name|QGraphicsWidget
operator|*
operator|)
name|topData
operator|->
name|proxyWidget
argument_list|,
name|active_window
argument_list|)
decl_stmt|;
return|return
name|res
return|;
block|}
block|}
endif|#
directive|endif
comment|/* if a floating tool window is active, keep shortcuts on the      * parent working */
if|if
condition|(
name|active_window
operator|!=
name|tlw
operator|&&
name|active_window
operator|&&
name|active_window
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Tool
operator|&&
name|active_window
operator|->
name|parentWidget
argument_list|()
condition|)
block|{
name|active_window
operator|=
name|active_window
operator|->
name|parentWidget
argument_list|()
operator|->
name|window
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|active_window
operator|!=
name|tlw
condition|)
return|return
literal|false
return|;
comment|/* if we live in a MDI subwindow, ignore the event if we are        not the active document window */
specifier|const
name|QWidget
modifier|*
name|sw
init|=
name|w
decl_stmt|;
while|while
condition|(
name|sw
operator|&&
operator|!
operator|(
name|sw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|SubWindow
operator|)
operator|&&
operator|!
name|sw
operator|->
name|isWindow
argument_list|()
condition|)
name|sw
operator|=
name|sw
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
if|if
condition|(
name|sw
operator|&&
operator|(
name|sw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|SubWindow
operator|)
condition|)
block|{
name|QWidget
modifier|*
name|focus_widget
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
decl_stmt|;
while|while
condition|(
name|focus_widget
operator|&&
name|focus_widget
operator|!=
name|sw
condition|)
name|focus_widget
operator|=
name|focus_widget
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
return|return
name|sw
operator|==
name|focus_widget
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_QSHORTCUTMAP
argument_list|)
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
operator|<<
literal|"..true [Pass-through]"
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_function
DECL|function|correctGraphicsWidgetContext
specifier|static
name|bool
name|correctGraphicsWidgetContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QGraphicsWidget
modifier|*
name|w
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
block|{
name|bool
name|visible
init|=
name|w
operator|->
name|isVisible
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
if|if
condition|(
operator|!
name|qApp
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_DontUseNativeMenuBar
argument_list|)
operator|&&
name|qobject_cast
argument_list|<
name|QMenuBar
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
condition|)
name|visible
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|visible
operator|||
operator|!
name|w
operator|->
name|isEnabled
argument_list|()
operator|||
operator|!
name|w
operator|->
name|scene
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|ApplicationShortcut
condition|)
block|{
comment|// Applicationwide shortcuts are always reachable unless their owner
comment|// is shadowed by modality. In QGV there's no modality concept, but we
comment|// must still check if all views are shadowed.
name|QList
argument_list|<
name|QGraphicsView
modifier|*
argument_list|>
name|views
init|=
name|w
operator|->
name|scene
argument_list|()
operator|->
name|views
argument_list|()
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
name|views
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QApplicationPrivate
operator|::
name|tryModalHelper
argument_list|(
name|views
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|WidgetShortcut
condition|)
return|return
cast|static_cast
argument_list|<
name|QGraphicsItem
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
operator|==
name|w
operator|->
name|scene
argument_list|()
operator|->
name|focusItem
argument_list|()
return|;
if|if
condition|(
name|context
operator|==
name|Qt
operator|::
name|WidgetWithChildrenShortcut
condition|)
block|{
specifier|const
name|QGraphicsItem
modifier|*
name|ti
init|=
name|w
operator|->
name|scene
argument_list|()
operator|->
name|focusItem
argument_list|()
decl_stmt|;
if|if
condition|(
name|ti
operator|&&
name|ti
operator|->
name|isWidget
argument_list|()
condition|)
block|{
specifier|const
name|QGraphicsWidget
modifier|*
name|tw
init|=
cast|static_cast
argument_list|<
specifier|const
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|ti
argument_list|)
decl_stmt|;
while|while
condition|(
name|tw
operator|&&
name|tw
operator|!=
name|w
operator|&&
operator|(
name|tw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Widget
operator|||
name|tw
operator|->
name|windowType
argument_list|()
operator|==
name|Qt
operator|::
name|Popup
operator|)
condition|)
name|tw
operator|=
name|tw
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
return|return
name|tw
operator|==
name|w
return|;
block|}
return|return
literal|false
return|;
block|}
comment|// Below is Qt::WindowShortcut context
comment|// Find the active view (if any).
name|QList
argument_list|<
name|QGraphicsView
modifier|*
argument_list|>
name|views
init|=
name|w
operator|->
name|scene
argument_list|()
operator|->
name|views
argument_list|()
decl_stmt|;
name|QGraphicsView
modifier|*
name|activeView
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
name|views
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsView
modifier|*
name|view
init|=
name|views
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|view
operator|->
name|window
argument_list|()
operator|==
name|active_window
condition|)
block|{
name|activeView
operator|=
name|view
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|activeView
condition|)
return|return
literal|false
return|;
comment|// The shortcut is reachable if owned by a windowless widget, or if the
comment|// widget's window is the same as the focus item's window.
name|QGraphicsWidget
modifier|*
name|a
init|=
name|w
operator|->
name|scene
argument_list|()
operator|->
name|activeWindow
argument_list|()
decl_stmt|;
return|return
operator|!
name|w
operator|->
name|window
argument_list|()
operator|||
name|a
operator|==
name|w
operator|->
name|window
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACTION
end_ifndef
begin_function
DECL|function|correctActionContext
specifier|static
name|bool
name|correctActionContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|,
name|QAction
modifier|*
name|a
parameter_list|,
name|QWidget
modifier|*
name|active_window
parameter_list|)
block|{
specifier|const
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
modifier|&
name|widgets
init|=
cast|static_cast
argument_list|<
name|QActionPrivate
operator|*
argument_list|>
argument_list|(
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|a
argument_list|)
argument_list|)
operator|->
name|widgets
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_QSHORTCUTMAP
argument_list|)
if|if
condition|(
name|widgets
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|a
operator|<<
literal|"not connected to any widgets; won't trigger"
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|widgets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|widgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
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
name|w
argument_list|)
condition|)
block|{
name|QAction
modifier|*
name|a
init|=
name|menu
operator|->
name|menuAction
argument_list|()
decl_stmt|;
if|if
condition|(
name|correctActionContext
argument_list|(
name|context
argument_list|,
name|a
argument_list|,
name|active_window
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
elseif|else
endif|#
directive|endif
if|if
condition|(
name|correctWidgetContext
argument_list|(
name|context
argument_list|,
name|w
argument_list|,
name|active_window
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
specifier|const
name|QList
argument_list|<
name|QGraphicsWidget
modifier|*
argument_list|>
modifier|&
name|graphicsWidgets
init|=
cast|static_cast
argument_list|<
name|QActionPrivate
operator|*
argument_list|>
argument_list|(
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|a
argument_list|)
argument_list|)
operator|->
name|graphicsWidgets
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DEBUG_QSHORTCUTMAP
argument_list|)
if|if
condition|(
name|graphicsWidgets
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
name|a
operator|<<
literal|"not connected to any widgets; won't trigger"
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|graphicsWidgets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsWidget
modifier|*
name|w
init|=
name|graphicsWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|correctGraphicsWidgetContext
argument_list|(
name|context
argument_list|,
name|w
argument_list|,
name|active_window
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
endif|#
directive|endif
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
comment|// QT_NO_ACTION
end_comment
begin_comment
comment|/*!     \class QShortcut     \brief The QShortcut class is used to create keyboard shortcuts.      \ingroup events     \inmodule QtWidgets      The QShortcut class provides a way of connecting keyboard     shortcuts to Qt's \l{signals and slots} mechanism, so that     objects can be informed when a shortcut is executed. The shortcut     can be set up to contain all the key presses necessary to     describe a keyboard shortcut, including the states of modifier     keys such as \gui Shift, \gui Ctrl, and \gui Alt.      \target mnemonic      On certain widgets, using '&' in front of a character will     automatically create a mnemonic (a shortcut) for that character,     e.g. "E&xit" will create the shortcut \gui Alt+X (use '&&' to     display an actual ampersand). The widget might consume and perform     an action on a given shortcut. On X11 the ampersand will not be     shown and the character will be underlined. On Windows, shortcuts     are normally not displayed until the user presses the \gui Alt     key, but this is a setting the user can change. On Mac, shortcuts     are disabled by default. Call qt_set_sequence_auto_mnemonic() to     enable them. However, because mnemonic shortcuts do not fit in     with Aqua's guidelines, Qt will not show the shortcut character     underlined.      For applications that use menus, it may be more convenient to     use the convenience functions provided in the QMenu class to     assign keyboard shortcuts to menu items as they are created.     Alternatively, shortcuts may be associated with other types of     actions in the QAction class.      The simplest way to create a shortcut for a particular widget is     to construct the shortcut with a key sequence. For example:      \snippet doc/src/snippets/code/src_gui_kernel_qshortcut.cpp 0      When the user types the \l{QKeySequence}{key sequence}     for a given shortcut, the shortcut's activated() signal is     emitted. (In the case of ambiguity, the activatedAmbiguously()     signal is emitted.) A shortcut is "listened for" by Qt's event     loop when the shortcut's parent widget is receiving events.      A shortcut's key sequence can be set with setKey() and retrieved     with key(). A shortcut can be enabled or disabled with     setEnabled(), and can have "What's This?" help text set with     setWhatsThis().      \sa QShortcutEvent, QKeySequence, QAction */
end_comment
begin_comment
comment|/*!     \fn QWidget *QShortcut::parentWidget() const      Returns the shortcut's parent widget. */
end_comment
begin_comment
comment|/*!     \fn void QShortcut::activated()      This signal is emitted when the user types the shortcut's key     sequence.      \sa activatedAmbiguously() */
end_comment
begin_comment
comment|/*!     \fn void QShortcut::activatedAmbiguously()      When a key sequence is being typed at the keyboard, it is said to     be ambiguous as long as it matches the start of more than one     shortcut.      When a shortcut's key sequence is completed,     activatedAmbiguously() is emitted if the key sequence is still     ambiguous (i.e., it is the start of one or more other shortcuts).     The activated() signal is not emitted in this case.      \sa activated() */
end_comment
begin_comment
comment|/*     \internal     Private data accessed through d-pointer. */
end_comment
begin_class
DECL|class|QShortcutPrivate
class|class
name|QShortcutPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QShortcut
parameter_list|)
specifier|public
private|:
DECL|function|QShortcutPrivate
name|QShortcutPrivate
parameter_list|()
member_init_list|:
name|sc_context
argument_list|(
name|Qt
operator|::
name|WindowShortcut
argument_list|)
member_init_list|,
name|sc_enabled
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|sc_autorepeat
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|sc_id
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|sc_sequence
name|QKeySequence
name|sc_sequence
decl_stmt|;
DECL|member|sc_context
name|Qt
operator|::
name|ShortcutContext
name|sc_context
decl_stmt|;
DECL|member|sc_enabled
name|bool
name|sc_enabled
decl_stmt|;
DECL|member|sc_autorepeat
name|bool
name|sc_autorepeat
decl_stmt|;
DECL|member|sc_id
name|int
name|sc_id
decl_stmt|;
DECL|member|sc_whatsthis
name|QString
name|sc_whatsthis
decl_stmt|;
name|void
name|redoGrab
parameter_list|(
name|QShortcutMap
modifier|&
name|map
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|redoGrab
name|void
name|QShortcutPrivate
operator|::
name|redoGrab
parameter_list|(
name|QShortcutMap
modifier|&
name|map
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|parent
condition|)
block|{
name|qWarning
argument_list|(
literal|"QShortcut: No widget parent defined"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|sc_id
condition|)
name|map
operator|.
name|removeShortcut
argument_list|(
name|sc_id
argument_list|,
name|q
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc_sequence
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|sc_id
operator|=
name|map
operator|.
name|addShortcut
argument_list|(
name|q
argument_list|,
name|sc_sequence
argument_list|,
name|sc_context
argument_list|,
name|qWidgetShortcutContextMatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sc_enabled
condition|)
name|map
operator|.
name|setShortcutEnabled
argument_list|(
literal|false
argument_list|,
name|sc_id
argument_list|,
name|q
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sc_autorepeat
condition|)
name|map
operator|.
name|setShortcutAutoRepeat
argument_list|(
literal|false
argument_list|,
name|sc_id
argument_list|,
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a QShortcut object for the \a parent widget. Since no     shortcut key sequence is specified, the shortcut will not emit any     signals.      \sa setKey() */
end_comment
begin_constructor
DECL|function|QShortcut
name|QShortcut
operator|::
name|QShortcut
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QShortcutPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|parent
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QShortcut object for the \a parent widget. The shortcut     operates on its parent, listening for \l{QShortcutEvent}s that     match the \a key sequence. Depending on the ambiguity of the     event, the shortcut will call the \a member function, or the \a     ambiguousMember function, if the key press was in the shortcut's     \a context. */
end_comment
begin_constructor
DECL|function|QShortcut
name|QShortcut
operator|::
name|QShortcut
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|key
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|,
specifier|const
name|char
modifier|*
name|ambiguousMember
parameter_list|,
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QShortcutPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|QAPP_CHECK
argument_list|(
literal|"QShortcut"
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|parent
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_context
operator|=
name|context
expr_stmt|;
name|d
operator|->
name|sc_sequence
operator|=
name|key
expr_stmt|;
name|d
operator|->
name|redoGrab
argument_list|(
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
argument_list|)
expr_stmt|;
if|if
condition|(
name|member
condition|)
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|()
argument_list|)
argument_list|,
name|parent
argument_list|,
name|member
argument_list|)
expr_stmt|;
if|if
condition|(
name|ambiguousMember
condition|)
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|activatedAmbiguously
argument_list|()
argument_list|)
argument_list|,
name|parent
argument_list|,
name|ambiguousMember
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the shortcut. */
end_comment
begin_destructor
DECL|function|~QShortcut
name|QShortcut
operator|::
name|~
name|QShortcut
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
name|qApp
condition|)
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
operator|.
name|removeShortcut
argument_list|(
name|d
operator|->
name|sc_id
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \property QShortcut::key     \brief the shortcut's key sequence      This is a key sequence with an optional combination of Shift, Ctrl,     and Alt. The key sequence may be supplied in a number of ways:      \snippet doc/src/snippets/code/src_gui_kernel_qshortcut.cpp 1      By default, this property contains an empty key sequence. */
end_comment
begin_function
DECL|function|setKey
name|void
name|QShortcut
operator|::
name|setKey
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|key
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sc_sequence
operator|==
name|key
condition|)
return|return;
name|QAPP_CHECK
argument_list|(
literal|"setKey"
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_sequence
operator|=
name|key
expr_stmt|;
name|d
operator|->
name|redoGrab
argument_list|(
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|key
name|QKeySequence
name|QShortcut
operator|::
name|key
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_sequence
return|;
block|}
end_function
begin_comment
comment|/*!     \property QShortcut::enabled     \brief whether the shortcut is enabled      An enabled shortcut emits the activated() or activatedAmbiguously()     signal when a QShortcutEvent occurs that matches the shortcut's     key() sequence.      If the application is in \c WhatsThis mode the shortcut will not emit     the signals, but will show the "What's This?" text instead.      By default, this property is true.      \sa whatsThis */
end_comment
begin_function
DECL|function|setEnabled
name|void
name|QShortcut
operator|::
name|setEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sc_enabled
operator|==
name|enable
condition|)
return|return;
name|QAPP_CHECK
argument_list|(
literal|"setEnabled"
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_enabled
operator|=
name|enable
expr_stmt|;
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
operator|.
name|setShortcutEnabled
argument_list|(
name|enable
argument_list|,
name|d
operator|->
name|sc_id
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isEnabled
name|bool
name|QShortcut
operator|::
name|isEnabled
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_enabled
return|;
block|}
end_function
begin_comment
comment|/*!     \property QShortcut::context     \brief the context in which the shortcut is valid      A shortcut's context decides in which circumstances a shortcut is     allowed to be triggered. The normal context is Qt::WindowShortcut,     which allows the shortcut to trigger if the parent (the widget     containing the shortcut) is a subwidget of the active top-level     window.      By default, this property is set to Qt::WindowShortcut. */
end_comment
begin_function
DECL|function|setContext
name|void
name|QShortcut
operator|::
name|setContext
parameter_list|(
name|Qt
operator|::
name|ShortcutContext
name|context
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sc_context
operator|==
name|context
condition|)
return|return;
name|QAPP_CHECK
argument_list|(
literal|"setContext"
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_context
operator|=
name|context
expr_stmt|;
name|d
operator|->
name|redoGrab
argument_list|(
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|context
name|Qt
operator|::
name|ShortcutContext
name|QShortcut
operator|::
name|context
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_context
return|;
block|}
end_function
begin_comment
comment|/*!     \property QShortcut::whatsThis     \brief the shortcut's "What's This?" help text      The text will be shown when the application is in "What's     This?" mode and the user types the shortcut key() sequence.      To set "What's This?" help on a menu item (with or without a     shortcut key), set the help on the item's action.      By default, this property contains an empty string.      \sa QWhatsThis::inWhatsThisMode(), QAction::setWhatsThis() */
end_comment
begin_function
DECL|function|setWhatsThis
name|void
name|QShortcut
operator|::
name|setWhatsThis
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_whatsthis
operator|=
name|text
expr_stmt|;
block|}
end_function
begin_function
DECL|function|whatsThis
name|QString
name|QShortcut
operator|::
name|whatsThis
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_whatsthis
return|;
block|}
end_function
begin_comment
comment|/*!     \property QShortcut::autoRepeat     \brief whether the shortcut can auto repeat     \since 4.2      If true, the shortcut will auto repeat when the keyboard shortcut     combination is held down, provided that keyboard auto repeat is     enabled on the system.     The default value is true. */
end_comment
begin_function
DECL|function|setAutoRepeat
name|void
name|QShortcut
operator|::
name|setAutoRepeat
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sc_autorepeat
operator|==
name|on
condition|)
return|return;
name|QAPP_CHECK
argument_list|(
literal|"setAutoRepeat"
argument_list|)
expr_stmt|;
name|d
operator|->
name|sc_autorepeat
operator|=
name|on
expr_stmt|;
name|qApp
operator|->
name|d_func
argument_list|()
operator|->
name|shortcutMap
operator|.
name|setShortcutAutoRepeat
argument_list|(
name|on
argument_list|,
name|d
operator|->
name|sc_id
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|autoRepeat
name|bool
name|QShortcut
operator|::
name|autoRepeat
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_autorepeat
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the shortcut's ID.      \sa QShortcutEvent::shortcutId() */
end_comment
begin_function
DECL|function|id
name|int
name|QShortcut
operator|::
name|id
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QShortcut
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sc_id
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|event
name|bool
name|QShortcut
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QShortcut
argument_list|)
expr_stmt|;
name|bool
name|handled
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|sc_enabled
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Shortcut
condition|)
block|{
name|QShortcutEvent
modifier|*
name|se
init|=
cast|static_cast
argument_list|<
name|QShortcutEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
name|se
operator|->
name|shortcutId
argument_list|()
operator|==
name|d
operator|->
name|sc_id
operator|&&
name|se
operator|->
name|key
argument_list|()
operator|==
name|d
operator|->
name|sc_sequence
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
if|if
condition|(
name|QWhatsThis
operator|::
name|inWhatsThisMode
argument_list|()
condition|)
block|{
name|QWhatsThis
operator|::
name|showText
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
argument_list|,
name|d
operator|->
name|sc_whatsthis
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
if|if
condition|(
name|se
operator|->
name|isAmbiguous
argument_list|()
condition|)
emit|emit
name|activatedAmbiguously
argument_list|()
emit|;
else|else
emit|emit
name|activated
argument_list|()
emit|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
block|}
return|return
name|handled
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHORTCUT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
