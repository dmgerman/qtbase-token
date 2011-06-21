begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Implementation of QInputContext class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_comment
comment|//#define QT_NO_IM_PREEDIT_RELOCATION
end_comment
begin_include
include|#
directive|include
file|"qinputcontext.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformintegration_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qplatforminputcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qmenu.h"
end_include
begin_include
include|#
directive|include
file|"qtextformat.h"
end_include
begin_include
include|#
directive|include
file|"qpalette.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QInputContext     \brief The QInputContext class abstracts the input method dependent data and composing state.      \ingroup i18n      An input method is responsible for inputting complex text that cannot     be inputted via simple keymap. It converts a sequence of input     events (typically key events) into a text string through the input     method specific converting process. The class of the processes are     widely ranging from simple finite state machine to complex text     translator that pools a whole paragraph of a text with text     editing capability to perform grammar and semantic analysis.      To abstract such different input method specific intermediate     information, Qt offers the QInputContext as base class. The     concept is well known as 'input context' in the input method     domain. An input context is created for a text widget in response     to a demand. It is ensured that an input context is prepared for     an input method before input to a text widget.      Multiple input contexts that belong to a single input method     may concurrently coexist. Suppose multi-window text editor. Each     text widget of window A and B holds different QInputContext     instance which contains different state information such as     partially composed text.      \section1 Groups of Functions      \table     \header \o Context \o Functions      \row \o Receiving information \o         x11FilterEvent(),         filterEvent(),         mouseHandler()      \row \o Sending back composed text \o         sendEvent()      \row \o State change notification \o         setFocusWidget(),         reset()      \row \o Context information \o         identifierName(),         language(),         font(),         isComposing()      \endtable      \section1 Licensing Information      \legalese     Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved.      This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own     license. You may use this file under your Qt license. Following     description is copied from their original file headers. Contact     immodule-qt@freedesktop.org if any conditions of this licensing are     not clear to you.     \endlegalese      \sa QInputContextPlugin, QInputContextFactory, QApplication::setInputContext() */
end_comment
begin_comment
comment|/*!     Constructs an input context with the given \a parent. */
end_comment
begin_constructor
DECL|function|QInputContext
name|QInputContext
operator|::
name|QInputContext
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the input context. */
end_comment
begin_destructor
DECL|function|~QInputContext
name|QInputContext
operator|::
name|~
name|QInputContext
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the widget that has an input focus for this input     context.      The return value may differ from holderWidget() if the input     context is shared between several text widgets.      \warning To ensure platform independence and support flexible     configuration of widgets, ordinary input methods should not call     this function directly.      \sa setFocusWidget() */
end_comment
begin_function
DECL|function|focusWidget
name|QWidget
modifier|*
name|QInputContext
operator|::
name|focusWidget
parameter_list|()
specifier|const
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|ic
operator|->
name|focusObject
argument_list|()
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the \a widget that has an input focus for this input context.      \warning Ordinary input methods must not call this function     directly.      \sa focusWidget() */
end_comment
begin_function
DECL|function|setFocusWidget
name|void
name|QInputContext
operator|::
name|setFocusWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|widget
operator|||
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|setFocusObject
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QInputContext::isComposing() const     \obsolete      This function indicates whether InputMethodStart event had been     sent to the current focus widget. It is ensured that an input     context can send InputMethodCompose or InputMethodEnd event safely     if this function returned true.      The state is automatically being tracked through sendEvent().      \sa sendEvent() */
end_comment
begin_comment
comment|/*!     This function can be reimplemented in a subclass to filter input     events.      Return true if the \a event has been consumed. Otherwise, the     unfiltered \a event will be forwarded to widgets as ordinary     way. Although the input events have accept() and ignore()     methods, leave it untouched.      \a event is currently restricted to events of these types:      \list         \i CloseSoftwareInputPanel         \i KeyPress         \i KeyRelease         \i MouseButtonDblClick         \i MouseButtonPress         \i MouseButtonRelease         \i MouseMove         \i RequestSoftwareInputPanel     \endlist      But some input method related events such as QWheelEvent or     QTabletEvent may be added in future.      The filtering opportunity is always given to the input context as     soon as possible. It has to be taken place before any other key     event consumers such as eventfilters and accelerators because some     input methods require quite various key combination and     sequences. It often conflicts with accelerators and so on, so we     must give the input context the filtering opportunity first to     ensure all input methods work properly regardless of application     design.      Ordinary input methods require discrete key events to work     properly, so Qt's key compression is always disabled for any input     contexts.      \sa QKeyEvent, x11FilterEvent() */
end_comment
begin_function
DECL|function|filterEvent
name|bool
name|QInputContext
operator|::
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   Sends an input method event specified by \a event to the current focus   widget. Implementations of QInputContext should call this method to   send the generated input method events and not   QApplication::sendEvent(), as the events might have to get dispatched   to a different application on some platforms.    Some complex input methods route the handling to several child   contexts (e.g. to enable language switching). To account for this,   QInputContext will check if the parent object is a QInputContext. If   yes, it will call the parents sendEvent() implementation instead of   sending the event directly.    \sa QInputMethodEvent */
end_comment
begin_function
DECL|function|sendEvent
name|void
name|QInputContext
operator|::
name|sendEvent
parameter_list|(
specifier|const
name|QInputMethodEvent
modifier|&
name|event
parameter_list|)
block|{
comment|// route events over input context parents to make chaining possible.
name|QInputContext
modifier|*
name|p
init|=
name|qobject_cast
argument_list|<
name|QInputContext
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
condition|)
block|{
name|p
operator|->
name|sendEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return;
block|}
name|QWidget
modifier|*
name|focus
init|=
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|focus
condition|)
return|return;
name|QInputMethodEvent
name|e
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|focus
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented in a subclass to handle mouse     press, release, double-click, and move events within the preedit     text. You can use the function to implement mouse-oriented user     interface such as text selection or popup menu for candidate     selection.      The \a x parameter is the offset within the string that was sent     with the InputMethodCompose event. The alteration boundary of \a     x is ensured as character boundary of preedit string accurately.      The \a event parameter is the event that was sent to the editor     widget. The event type is QEvent::MouseButtonPress,     QEvent::MouseButtonRelease, QEvent::MouseButtonDblClick or     QEvent::MouseMove. The event's button and state indicate     the kind of operation that was performed. */
end_comment
begin_function
DECL|function|mouseHandler
name|void
name|QInputContext
operator|::
name|mouseHandler
parameter_list|(
name|int
name|x
parameter_list|,
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|mouseHandler
argument_list|(
name|x
argument_list|,
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the font of the current input widget */
end_comment
begin_function
DECL|function|font
name|QFont
name|QInputContext
operator|::
name|font
parameter_list|()
specifier|const
block|{
name|QWidget
modifier|*
name|focus
init|=
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|focus
condition|)
return|return
name|QApplication
operator|::
name|font
argument_list|()
return|;
return|return
name|qvariant_cast
argument_list|<
name|QFont
argument_list|>
argument_list|(
name|focus
operator|->
name|inputMethodQuery
argument_list|(
name|Qt
operator|::
name|ImFont
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     This virtual function is called when a state in the focus widget     has changed. QInputContext can then use     QWidget::inputMethodQuery() to query the new state of the widget. */
end_comment
begin_function
DECL|function|update
name|void
name|QInputContext
operator|::
name|update
parameter_list|()
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     This virtual function is called when the specified \a widget is     destroyed. The \a widget is a widget on which this input context     is installed. */
end_comment
begin_function
DECL|function|widgetDestroyed
name|void
name|QInputContext
operator|::
name|widgetDestroyed
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
name|widget
operator|==
name|focusWidget
argument_list|()
condition|)
name|setFocusWidget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QInputContext::reset()      This function can be reimplemented in a subclass to reset the     state of the input method.      This function is called by several widgets to reset input     state. For example, a text widget call this function before     inserting a text to make widget ready to accept a text.      Default implementation is sufficient for simple input method. You     can override this function to reset external input method engines     in complex input method. In the case, call QInputContext::reset()     to ensure proper termination of inputting.      In a reimplementation of reset(), you must not send any     QInputMethodEvent containing preedit text. You can only commit     string and attributes; otherwise, you risk breaking input state     consistency. */
end_comment
begin_function
DECL|function|reset
name|void
name|QInputContext
operator|::
name|reset
parameter_list|()
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \fn QString QInputContext::identifierName()      This function must be implemented in any subclasses to return the     identifier name of the input method.      Return value is the name to identify and specify input methods for     the input method switching mechanism and so on. The name has to be     consistent with QInputContextPlugin::keys(). The name has to     consist of ASCII characters only.      There are two different names with different responsibility in the     input method domain. This function returns one of them. Another     name is called 'display name' that stands for the name for     endusers appeared in a menu and so on.      \sa QInputContextPlugin::keys(), QInputContextPlugin::displayName() */
end_comment
begin_function
DECL|function|identifierName
name|QString
name|QInputContext
operator|::
name|identifierName
parameter_list|()
block|{
return|return
name|QLatin1String
argument_list|(
literal|"qpa"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QInputContext::language()      This function must be implemented in any subclasses to return a     language code (e.g. "zh_CN", "zh_TW", "zh_HK", "ja", "ko", ...)     of the input context. If the input context can handle multiple     languages, return the currently used one. The name has to be     consistent with QInputContextPlugin::language().      This information will be used by language tagging feature in     QInputMethodEvent. It is required to distinguish unified han characters     correctly. It enables proper font and character code     handling. Suppose CJK-awared multilingual web browser     (that automatically modifies fonts in CJK-mixed text) and XML editor     (that automatically inserts lang attr). */
end_comment
begin_function
DECL|function|language
name|QString
name|QInputContext
operator|::
name|language
parameter_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     This is a preliminary interface for Qt 4. */
end_comment
begin_function
DECL|function|actions
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|QInputContext
operator|::
name|actions
parameter_list|()
block|{
return|return
name|QList
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QInputContext::StandardFormat      \value PreeditFormat  The preedit text.     \value SelectionFormat  The selection text.      \sa standardFormat() */
end_comment
begin_comment
comment|/*!     Returns a QTextFormat object that specifies the format for     component \a s. */
end_comment
begin_function
DECL|function|standardFormat
name|QTextFormat
name|QInputContext
operator|::
name|standardFormat
parameter_list|(
name|StandardFormat
name|s
parameter_list|)
specifier|const
block|{
name|QWidget
modifier|*
name|focus
init|=
name|focusWidget
argument_list|()
decl_stmt|;
specifier|const
name|QPalette
modifier|&
name|pal
init|=
name|focus
condition|?
name|focus
operator|->
name|palette
argument_list|()
else|:
name|QApplication
operator|::
name|palette
argument_list|()
decl_stmt|;
name|QTextCharFormat
name|fmt
decl_stmt|;
name|QColor
name|bg
decl_stmt|;
switch|switch
condition|(
name|s
condition|)
block|{
case|case
name|QInputContext
operator|::
name|PreeditFormat
case|:
block|{
name|fmt
operator|.
name|setUnderlineStyle
argument_list|(
name|QTextCharFormat
operator|::
name|DashUnderline
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|QInputContext
operator|::
name|SelectionFormat
case|:
block|{
name|bg
operator|=
name|pal
operator|.
name|text
argument_list|()
operator|.
name|color
argument_list|()
expr_stmt|;
name|fmt
operator|.
name|setBackground
argument_list|(
name|QBrush
argument_list|(
name|bg
argument_list|)
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setForeground
argument_list|(
name|pal
operator|.
name|background
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
return|return
name|fmt
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_comment
comment|/*!     This function may be overridden only if input method is depending     on X11 and you need raw XEvent. Otherwise, this function must not.      This function is designed to filter raw key events for XIM, but     other input methods may use this to implement some special     features such as distinguishing Shift_L and Shift_R.      Return true if the \a event has been consumed. Otherwise, the     unfiltered \a event will be translated into QEvent and forwarded     to filterEvent(). Filtering at both x11FilterEvent() and     filterEvent() in single input method is allowed.      \a keywidget is a client widget into which a text is inputted. \a     event is inputted XEvent.      \sa filterEvent() */
end_comment
begin_function
DECL|function|x11FilterEvent
name|bool
name|QInputContext
operator|::
name|x11FilterEvent
parameter_list|(
name|QWidget
modifier|*
comment|/*keywidget*/
parameter_list|,
name|XEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
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
comment|// Q_WS_X11
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_comment
comment|/*!     \since 4.6      This function may be overridden only if input method is depending     on Symbian and you need raw Symbian events. Otherwise, this function must not.      This function is designed to filter raw key events on Symbian, but     other input methods may use this to implement some special     features.      Return true if the \a event has been consumed. Otherwise, the     unfiltered \a event will be translated into QEvent and forwarded     to filterEvent(). Filtering at both symbianFilterEvent() and     filterEvent() in single input method is allowed.      \a keywidget is a client widget into which a text is inputted. \a     event is inputted QSymbianEvent.      \sa filterEvent() */
end_comment
begin_function
DECL|function|symbianFilterEvent
name|bool
name|QInputContext
operator|::
name|symbianFilterEvent
parameter_list|(
name|QWidget
modifier|*
comment|/*keywidget*/
parameter_list|,
specifier|const
name|QSymbianEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
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
comment|// Q_OS_SYMBIAN
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_NO_IM
end_comment
end_unit
