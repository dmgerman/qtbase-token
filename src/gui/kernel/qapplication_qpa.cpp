begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qpixmapcache.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GLIB
argument_list|)
end_if
begin_include
include|#
directive|include
file|"private/qeventdispatcher_glib_qpa_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qeventdispatcher_qpa_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_include
include|#
directive|include
file|"private/qcursor_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qevent_p.h"
end_include
begin_include
include|#
directive|include
file|"qgenericpluginfactory_qpa.h"
end_include
begin_include
include|#
directive|include
file|"private/qplatformintegrationfactory_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qinputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformCursor>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|"private/qwindowsysteminterface_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|<QPlatformIntegration>
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"qwidgetwindow_qpa_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|appName
specifier|static
name|QString
name|appName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|appFont
specifier|static
name|QString
name|appFont
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|appName
name|QString
name|QApplicationPrivate
operator|::
name|appName
parameter_list|()
specifier|const
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|appName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|void
name|QApplicationPrivate
operator|::
name|createEventDispatcher
parameter_list|()
block|{
name|QGuiApplicationPrivate
operator|::
name|createEventDispatcher
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_try_modal
specifier|static
name|bool
name|qt_try_modal
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|)
block|{
name|QWidget
modifier|*
name|top
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QApplicationPrivate
operator|::
name|tryModalHelper
argument_list|(
name|widget
argument_list|,
operator|&
name|top
argument_list|)
condition|)
return|return
literal|true
return|;
name|bool
name|block_event
init|=
literal|false
decl_stmt|;
name|bool
name|paint_event
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
if|#
directive|if
literal|0
block|case QEvent::Focus:         if (!static_cast<QWSFocusEvent*>(event)->simpleData.get_focus)             break;
comment|// drop through
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
comment|// disallow mouse/key events
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
case|case
name|QEvent
operator|::
name|MouseMove
case|:
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
name|block_event
operator|=
literal|true
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
operator|(
name|block_event
operator|||
name|paint_event
operator|)
operator|&&
name|top
operator|->
name|parentWidget
argument_list|()
operator|==
literal|0
condition|)
name|top
operator|->
name|raise
argument_list|()
expr_stmt|;
return|return
operator|!
name|block_event
return|;
block|}
end_function
begin_function
DECL|function|enterModal_sys
name|void
name|QApplicationPrivate
operator|::
name|enterModal_sys
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
block|{
if|#
directive|if
literal|0
block|if (!qt_modal_stack)         qt_modal_stack = new QWidgetList;     qt_modal_stack->insert(0, widget);     app_do_modal = true;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|leaveModal_sys
name|void
name|QApplicationPrivate
operator|::
name|leaveModal_sys
parameter_list|(
name|QWidget
modifier|*
parameter_list|)
block|{
if|#
directive|if
literal|0
block|if (qt_modal_stack&& qt_modal_stack->removeAll(widget)) {         if (qt_modal_stack->isEmpty()) {             delete qt_modal_stack;             qt_modal_stack = 0;         }     }     app_do_modal = qt_modal_stack != 0;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|modalState
name|bool
name|QApplicationPrivate
operator|::
name|modalState
parameter_list|()
block|{
return|return
literal|false
return|;
if|#
directive|if
literal|0
block|return app_do_modal;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|closePopup
name|void
name|QApplicationPrivate
operator|::
name|closePopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QApplication
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|popupWidgets
condition|)
return|return;
name|popupWidgets
operator|->
name|removeAll
argument_list|(
name|popup
argument_list|)
expr_stmt|;
comment|//###
comment|//     if (popup == qt_popup_down) {
comment|//         qt_button_down = 0;
comment|//         qt_popup_down = 0;
comment|//     }
if|if
condition|(
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// this was the last popup
operator|delete
name|QApplicationPrivate
operator|::
name|popupWidgets
expr_stmt|;
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|=
literal|0
expr_stmt|;
comment|//### replay mouse event?
comment|//### transfer/release mouse grab
comment|//### transfer/release keyboard grab
comment|//give back focus
if|if
condition|(
name|active_window
condition|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|active_window
operator|->
name|focusWidget
argument_list|()
condition|)
block|{
if|if
condition|(
name|fw
operator|!=
name|QApplication
operator|::
name|focusWidget
argument_list|()
condition|)
block|{
name|fw
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFocusEvent
name|e
argument_list|(
name|QEvent
operator|::
name|FocusIn
argument_list|,
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
decl_stmt|;
name|q
operator|->
name|sendEvent
argument_list|(
name|fw
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
comment|// A popup was closed, so the previous popup gets the focus.
name|QWidget
modifier|*
name|aw
init|=
name|QApplicationPrivate
operator|::
name|popupWidgets
operator|->
name|last
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|aw
operator|->
name|focusWidget
argument_list|()
condition|)
name|fw
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
comment|//### regrab the keyboard and mouse in case 'popup' lost the grab
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|openPopupCount
specifier|static
name|int
name|openPopupCount
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|openPopup
name|void
name|QApplicationPrivate
operator|::
name|openPopup
parameter_list|(
name|QWidget
modifier|*
name|popup
parameter_list|)
block|{
name|openPopupCount
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|popupWidgets
condition|)
block|{
comment|// create list
name|popupWidgets
operator|=
operator|new
name|QWidgetList
expr_stmt|;
comment|/* only grab if you are the first/parent popup */
comment|//####   ->grabMouse(popup,true);
comment|//####   ->grabKeyboard(popup,true);
comment|//### popupGrabOk = true;
block|}
name|popupWidgets
operator|->
name|append
argument_list|(
name|popup
argument_list|)
expr_stmt|;
comment|// add to end of list
comment|// popups are not focus-handled by the window system (the first
comment|// popup grabbed the keyboard), so we have to do that manually: A
comment|// new popup gets the focus
if|if
condition|(
name|popup
operator|->
name|focusWidget
argument_list|()
condition|)
block|{
name|popup
operator|->
name|focusWidget
argument_list|()
operator|->
name|setFocus
argument_list|(
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|popupWidgets
operator|->
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// this was the first popup
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
condition|)
block|{
name|QFocusEvent
name|e
argument_list|(
name|QEvent
operator|::
name|FocusOut
argument_list|,
name|Qt
operator|::
name|PopupFocusReason
argument_list|)
decl_stmt|;
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|fw
argument_list|,
operator|&
name|e
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|initializeMultitouch_sys
name|void
name|QApplicationPrivate
operator|::
name|initializeMultitouch_sys
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupMultitouch_sys
name|void
name|QApplicationPrivate
operator|::
name|cleanupMultitouch_sys
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|initializeWidgetPaletteHash
name|void
name|QApplicationPrivate
operator|::
name|initializeWidgetPaletteHash
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setCursorFlashTime
name|void
name|QApplication
operator|::
name|setCursorFlashTime
parameter_list|(
name|int
name|msecs
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|cursor_flash_time
operator|=
name|msecs
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorFlashTime
name|int
name|QApplication
operator|::
name|cursorFlashTime
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|cursor_flash_time
return|;
block|}
end_function
begin_function
DECL|function|setDoubleClickInterval
name|void
name|QApplication
operator|::
name|setDoubleClickInterval
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|mouse_double_click_time
operator|=
name|ms
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doubleClickInterval
name|int
name|QApplication
operator|::
name|doubleClickInterval
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|mouse_double_click_time
return|;
block|}
end_function
begin_function
DECL|function|setKeyboardInputInterval
name|void
name|QApplication
operator|::
name|setKeyboardInputInterval
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|keyboard_input_time
operator|=
name|ms
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardInputInterval
name|int
name|QApplication
operator|::
name|keyboardInputInterval
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|keyboard_input_time
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_function
DECL|function|setWheelScrollLines
name|void
name|QApplication
operator|::
name|setWheelScrollLines
parameter_list|(
name|int
name|lines
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|wheel_scroll_lines
operator|=
name|lines
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wheelScrollLines
name|int
name|QApplication
operator|::
name|wheelScrollLines
parameter_list|()
block|{
return|return
name|QApplicationPrivate
operator|::
name|wheel_scroll_lines
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setEffectEnabled
name|void
name|QApplication
operator|::
name|setEffectEnabled
parameter_list|(
name|Qt
operator|::
name|UIEffect
name|effect
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
switch|switch
condition|(
name|effect
condition|)
block|{
case|case
name|Qt
operator|::
name|UI_AnimateMenu
case|:
name|QApplicationPrivate
operator|::
name|animate_menu
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_FadeMenu
case|:
if|if
condition|(
name|enable
condition|)
name|QApplicationPrivate
operator|::
name|animate_menu
operator|=
literal|true
expr_stmt|;
name|QApplicationPrivate
operator|::
name|fade_menu
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateCombo
case|:
name|QApplicationPrivate
operator|::
name|animate_combo
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateTooltip
case|:
name|QApplicationPrivate
operator|::
name|animate_tooltip
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_FadeTooltip
case|:
if|if
condition|(
name|enable
condition|)
name|QApplicationPrivate
operator|::
name|animate_tooltip
operator|=
literal|true
expr_stmt|;
name|QApplicationPrivate
operator|::
name|fade_tooltip
operator|=
name|enable
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UI_AnimateToolBox
case|:
name|QApplicationPrivate
operator|::
name|animate_toolbox
operator|=
name|enable
expr_stmt|;
break|break;
default|default:
name|QApplicationPrivate
operator|::
name|animate_ui
operator|=
name|enable
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
DECL|function|isEffectEnabled
name|bool
name|QApplication
operator|::
name|isEffectEnabled
parameter_list|(
name|Qt
operator|::
name|UIEffect
name|effect
parameter_list|)
block|{
if|if
condition|(
name|QColormap
operator|::
name|instance
argument_list|()
operator|.
name|depth
argument_list|()
operator|<
literal|16
operator|||
operator|!
name|QApplicationPrivate
operator|::
name|animate_ui
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|effect
condition|)
block|{
case|case
name|Qt
operator|::
name|UI_AnimateMenu
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_menu
return|;
case|case
name|Qt
operator|::
name|UI_FadeMenu
case|:
return|return
name|QApplicationPrivate
operator|::
name|fade_menu
return|;
case|case
name|Qt
operator|::
name|UI_AnimateCombo
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_combo
return|;
case|case
name|Qt
operator|::
name|UI_AnimateTooltip
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_tooltip
return|;
case|case
name|Qt
operator|::
name|UI_FadeTooltip
case|:
return|return
name|QApplicationPrivate
operator|::
name|fade_tooltip
return|;
case|case
name|Qt
operator|::
name|UI_AnimateToolBox
case|:
return|return
name|QApplicationPrivate
operator|::
name|animate_toolbox
return|;
default|default:
return|return
name|QApplicationPrivate
operator|::
name|animate_ui
return|;
block|}
block|}
end_function
begin_function
DECL|function|topLevelAt
name|QWidget
modifier|*
name|QApplication
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QPlatformIntegration
modifier|*
name|pi
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|screens
init|=
name|pi
operator|->
name|screens
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|screen
init|=
name|screens
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|screens
operator|.
name|constEnd
argument_list|()
decl_stmt|;
comment|// The first screen in a virtual environment should know about all top levels
if|if
condition|(
name|pi
operator|->
name|isVirtualDesktop
argument_list|()
condition|)
block|{
name|QWidgetWindow
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidgetWindow
operator|*
argument_list|>
argument_list|(
operator|(
operator|*
name|screen
operator|)
operator|->
name|topLevelAt
argument_list|(
name|pos
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|w
condition|?
name|w
operator|->
name|widget
argument_list|()
else|:
literal|0
return|;
block|}
while|while
condition|(
name|screen
operator|!=
name|end
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|screen
operator|)
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|QWidgetWindow
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidgetWindow
operator|*
argument_list|>
argument_list|(
operator|(
operator|*
name|screen
operator|)
operator|->
name|topLevelAt
argument_list|(
name|pos
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|w
condition|?
name|w
operator|->
name|widget
argument_list|()
else|:
literal|0
return|;
block|}
operator|++
name|screen
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|beep
name|void
name|QApplication
operator|::
name|beep
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|alert
name|void
name|QApplication
operator|::
name|alert
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|int
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|platformNativeInterface
name|QPlatformNativeInterface
modifier|*
name|QApplication
operator|::
name|platformNativeInterface
parameter_list|()
block|{
name|QPlatformIntegration
modifier|*
name|pi
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
decl_stmt|;
return|return
name|pi
operator|->
name|nativeInterface
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
end_ifndef
begin_class
DECL|class|QDummyInputContext
class|class
name|QDummyInputContext
super|:
specifier|public
name|QInputContext
block|{
public|public:
DECL|function|QDummyInputContext
specifier|explicit
name|QDummyInputContext
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QInputContext
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|~QDummyInputContext
name|~
name|QDummyInputContext
parameter_list|()
block|{}
DECL|function|identifierName
name|QString
name|identifierName
parameter_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|language
name|QString
name|language
parameter_list|()
block|{
return|return
name|QString
argument_list|()
return|;
block|}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{}
DECL|function|isComposing
name|bool
name|isComposing
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QWS_INPUTMETHODS
end_comment
begin_function
DECL|function|qt_init
name|void
name|qt_init
parameter_list|(
name|QApplicationPrivate
modifier|*
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_DontCreateNativeWidgetSiblings
argument_list|)
expr_stmt|;
name|QColormap
operator|::
name|initialize
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
comment|//    QCursorData::initialize();
endif|#
directive|endif
name|qApp
operator|->
name|setObjectName
argument_list|(
name|appName
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
name|qApp
operator|->
name|setInputContext
argument_list|(
operator|new
name|QDummyInputContext
argument_list|(
name|qApp
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qt_cleanup
name|void
name|qt_cleanup
parameter_list|()
block|{
name|QPixmapCache
operator|::
name|clear
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QCursorData
operator|::
name|cleanup
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|QColormap
operator|::
name|cleanup
argument_list|()
expr_stmt|;
operator|delete
name|QApplicationPrivate
operator|::
name|inputContext
expr_stmt|;
name|QApplicationPrivate
operator|::
name|inputContext
operator|=
literal|0
expr_stmt|;
name|QApplicationPrivate
operator|::
name|active_window
operator|=
literal|0
expr_stmt|;
comment|//### this should not be necessary
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_function
DECL|function|setMainWidget
name|void
name|QApplication
operator|::
name|setMainWidget
parameter_list|(
name|QWidget
modifier|*
name|mainWidget
parameter_list|)
block|{
name|QApplicationPrivate
operator|::
name|main_widget
operator|=
name|mainWidget
expr_stmt|;
if|if
condition|(
name|QApplicationPrivate
operator|::
name|main_widget
operator|&&
name|windowIcon
argument_list|()
operator|.
name|isNull
argument_list|()
operator|&&
name|QApplicationPrivate
operator|::
name|main_widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_SetWindowIcon
argument_list|)
condition|)
name|setWindowIcon
argument_list|(
name|QApplicationPrivate
operator|::
name|main_widget
operator|->
name|windowIcon
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
