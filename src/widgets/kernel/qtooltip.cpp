begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qstyle.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qstylepainter.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qtooltip.h>
end_include
begin_include
include|#
directive|include
file|<private/qeffects_p.h>
end_include
begin_include
include|#
directive|include
file|<qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qstylesheetstyle_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qcore_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QToolTip      \brief The QToolTip class provides tool tips (balloon help) for any     widget.      \ingroup helpsystem     \inmodule QtWidgets      The tip is a short piece of text reminding the user of the     widget's function. It is drawn immediately below the given     position in a distinctive black-on-yellow color combination. The     tip can be any \l{QTextEdit}{rich text} formatted string.      Rich text displayed in a tool tip is implicitly word-wrapped unless     specified differently with \c{<p style='white-space:pre'>}.      The simplest and most common way to set a widget's tool tip is by     calling its QWidget::setToolTip() function.      It is also possible to show different tool tips for different     regions of a widget, by using a QHelpEvent of type     QEvent::ToolTip. Intercept the help event in your widget's \l     {QWidget::}{event()} function and call QToolTip::showText() with     the text you want to display. The \l{widgets/tooltips}{Tooltips}     example illustrates this technique.      If you are calling QToolTip::hideText(), or QToolTip::showText()     with an empty string, as a result of a \l{QEvent::}{ToolTip}-event you     should also call \l{QEvent::}{ignore()} on the event, to signal     that you don't want to start any tooltip specific modes.      Note that, if you want to show tooltips in an item view, the     model/view architecture provides functionality to set an item's     tool tip; e.g., the QTableWidgetItem::setToolTip() function.     However, if you want to provide custom tool tips in an item view,     you must intercept the help event in the     QAbstractItemView::viewportEvent() function and handle it yourself.      The default tool tip color and font can be customized with     setPalette() and setFont(). When a tooltip is currently on     display, isVisible() returns \c true and text() the currently visible     text.      \note Tool tips use the inactive color group of QPalette, because tool     tips are not active windows.      \sa QWidget::toolTip, QAction::toolTip, {Tool Tips Example} */
end_comment
begin_class
DECL|class|QTipLabel
class|class
name|QTipLabel
super|:
specifier|public
name|QLabel
block|{
name|Q_OBJECT
public|public:
name|QTipLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
name|int
name|msecDisplayTime
parameter_list|)
constructor_decl|;
name|~
name|QTipLabel
parameter_list|()
destructor_decl|;
DECL|member|instance
specifier|static
name|QTipLabel
modifier|*
name|instance
decl_stmt|;
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
DECL|member|hideTimer
DECL|member|expireTimer
name|QBasicTimer
name|hideTimer
decl_stmt|,
name|expireTimer
decl_stmt|;
DECL|member|fadingOut
name|bool
name|fadingOut
decl_stmt|;
name|void
name|reuseTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|msecDisplayTime
parameter_list|)
function_decl|;
name|void
name|hideTip
parameter_list|()
function_decl|;
name|void
name|hideTipImmediately
parameter_list|()
function_decl|;
name|void
name|setTipRect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
function_decl|;
name|void
name|restartExpireTimer
parameter_list|(
name|int
name|msecDisplayTime
parameter_list|)
function_decl|;
name|bool
name|tipChanged
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QObject
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
name|placeTip
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
specifier|static
name|int
name|getTipScreen
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
protected|protected:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
public|public
name|slots
public|:
comment|/** \internal       Cleanup the _q_stylesheet_parent propery.      */
DECL|function|styleSheetParentDestroyed
name|void
name|styleSheetParentDestroyed
parameter_list|()
block|{
name|setProperty
argument_list|(
literal|"_q_stylesheet_parent"
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
name|styleSheetParent
operator|=
literal|0
expr_stmt|;
block|}
private|private:
DECL|member|styleSheetParent
name|QWidget
modifier|*
name|styleSheetParent
decl_stmt|;
endif|#
directive|endif
private|private:
DECL|member|widget
name|QWidget
modifier|*
name|widget
decl_stmt|;
DECL|member|rect
name|QRect
name|rect
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|instance
name|QTipLabel
modifier|*
name|QTipLabel
operator|::
name|instance
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QTipLabel
name|QTipLabel
operator|::
name|QTipLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
name|int
name|msecDisplayTime
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
member_init_list|:
name|QLabel
argument_list|(
name|w
argument_list|,
name|Qt
operator|::
name|ToolTip
operator||
name|Qt
operator|::
name|BypassGraphicsProxyWidget
argument_list|)
member_init_list|,
name|styleSheetParent
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|widget
argument_list|(
literal|0
argument_list|)
else|#
directive|else
member_init_list|:
name|QLabel
argument_list|(
name|w
argument_list|,
name|Qt
operator|::
name|ToolTip
operator||
name|Qt
operator|::
name|BypassGraphicsProxyWidget
argument_list|)
member_init_list|,
name|widget
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
operator|delete
name|instance
expr_stmt|;
name|instance
operator|=
name|this
expr_stmt|;
name|setForegroundRole
argument_list|(
name|QPalette
operator|::
name|ToolTipText
argument_list|)
expr_stmt|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|ToolTipBase
argument_list|)
expr_stmt|;
name|setPalette
argument_list|(
name|QToolTip
operator|::
name|palette
argument_list|()
argument_list|)
expr_stmt|;
name|ensurePolished
argument_list|()
expr_stmt|;
name|setMargin
argument_list|(
literal|1
operator|+
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ToolTipLabelFrameWidth
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
expr_stmt|;
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
name|setIndent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|setWindowOpacity
argument_list|(
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_ToolTipLabel_Opacity
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
operator|/
literal|255.0
argument_list|)
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fadingOut
operator|=
literal|false
expr_stmt|;
name|reuseTip
argument_list|(
name|text
argument_list|,
name|msecDisplayTime
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|restartExpireTimer
name|void
name|QTipLabel
operator|::
name|restartExpireTimer
parameter_list|(
name|int
name|msecDisplayTime
parameter_list|)
block|{
name|int
name|time
init|=
literal|10000
operator|+
literal|40
operator|*
name|qMax
argument_list|(
literal|0
argument_list|,
name|text
argument_list|()
operator|.
name|length
argument_list|()
operator|-
literal|100
argument_list|)
decl_stmt|;
if|if
condition|(
name|msecDisplayTime
operator|>
literal|0
condition|)
name|time
operator|=
name|msecDisplayTime
expr_stmt|;
name|expireTimer
operator|.
name|start
argument_list|(
name|time
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|hideTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reuseTip
name|void
name|QTipLabel
operator|::
name|reuseTip
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|msecDisplayTime
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
if|if
condition|(
name|styleSheetParent
condition|)
block|{
name|disconnect
argument_list|(
name|styleSheetParent
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|QTipLabel
operator|::
name|instance
argument_list|,
name|SLOT
argument_list|(
name|styleSheetParentDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|styleSheetParent
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
name|setWordWrap
argument_list|(
name|Qt
operator|::
name|mightBeRichText
argument_list|(
name|text
argument_list|)
argument_list|)
expr_stmt|;
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|QSize
name|extra
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// Make it look good with the default ToolTip font on Mac, which has a small descent.
if|if
condition|(
name|fm
operator|.
name|descent
argument_list|()
operator|==
literal|2
operator|&&
name|fm
operator|.
name|ascent
argument_list|()
operator|>=
literal|11
condition|)
operator|++
name|extra
operator|.
name|rheight
argument_list|()
expr_stmt|;
name|resize
argument_list|(
name|sizeHint
argument_list|()
operator|+
name|extra
argument_list|)
expr_stmt|;
name|restartExpireTimer
argument_list|(
name|msecDisplayTime
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QTipLabel
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|ev
parameter_list|)
block|{
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionFrame
name|opt
decl_stmt|;
name|opt
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPrimitive
argument_list|(
name|QStyle
operator|::
name|PE_PanelTipLabel
argument_list|,
name|opt
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QLabel
operator|::
name|paintEvent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QTipLabel
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
name|QStyleHintReturnMask
name|frameMask
decl_stmt|;
name|QStyleOption
name|option
decl_stmt|;
name|option
operator|.
name|init
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_ToolTip_Mask
argument_list|,
operator|&
name|option
argument_list|,
name|this
argument_list|,
operator|&
name|frameMask
argument_list|)
condition|)
name|setMask
argument_list|(
name|frameMask
operator|.
name|region
argument_list|)
expr_stmt|;
name|QLabel
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|QTipLabel
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|QPoint
name|pos
init|=
name|e
operator|->
name|globalPos
argument_list|()
decl_stmt|;
if|if
condition|(
name|widget
condition|)
name|pos
operator|=
name|widget
operator|->
name|mapFromGlobal
argument_list|(
name|pos
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rect
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
name|hideTip
argument_list|()
expr_stmt|;
name|QLabel
operator|::
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QTipLabel
name|QTipLabel
operator|::
name|~
name|QTipLabel
parameter_list|()
block|{
name|instance
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hideTip
name|void
name|QTipLabel
operator|::
name|hideTip
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hideTimer
operator|.
name|isActive
argument_list|()
condition|)
name|hideTimer
operator|.
name|start
argument_list|(
literal|300
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideTipImmediately
name|void
name|QTipLabel
operator|::
name|hideTipImmediately
parameter_list|()
block|{
name|close
argument_list|()
expr_stmt|;
comment|// to trigger QEvent::Close which stops the animation
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTipRect
name|void
name|QTipLabel
operator|::
name|setTipRect
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
if|if
condition|(
operator|!
name|rect
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|w
condition|)
name|qWarning
argument_list|(
literal|"QToolTip::setTipRect: Cannot pass null widget if rect is set"
argument_list|)
expr_stmt|;
else|else
block|{
name|widget
operator|=
name|w
expr_stmt|;
name|rect
operator|=
name|r
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|QTipLabel
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|hideTimer
operator|.
name|timerId
argument_list|()
operator|||
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|expireTimer
operator|.
name|timerId
argument_list|()
condition|)
block|{
name|hideTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|expireTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_EFFECTS
argument_list|)
if|if
condition|(
name|QApplication
operator|::
name|isEffectEnabled
argument_list|(
name|Qt
operator|::
name|UI_FadeTooltip
argument_list|)
condition|)
block|{
comment|// Fade out tip on mac (makes it invisible).
comment|// The tip will not be deleted until a new tip is shown.
comment|// DRSWAT - Cocoa
name|macWindowFade
argument_list|(
name|qt_mac_window_for
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QTipLabel
operator|::
name|instance
operator|->
name|fadingOut
operator|=
literal|true
expr_stmt|;
comment|// will never be false again.
block|}
else|else
name|hideTipImmediately
argument_list|()
expr_stmt|;
else|#
directive|else
name|hideTipImmediately
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|eventFilter
name|bool
name|QTipLabel
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
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
ifdef|#
directive|ifdef
name|Q_WS_MAC
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
block|{
name|int
name|key
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|key
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|KeyboardModifiers
name|mody
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|modifiers
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|mody
operator|&
name|Qt
operator|::
name|KeyboardModifierMask
operator|)
operator|&&
name|key
operator|!=
name|Qt
operator|::
name|Key_Shift
operator|&&
name|key
operator|!=
name|Qt
operator|::
name|Key_Control
operator|&&
name|key
operator|!=
name|Qt
operator|::
name|Key_Alt
operator|&&
name|key
operator|!=
name|Qt
operator|::
name|Key_Meta
condition|)
name|hideTip
argument_list|()
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|Leave
case|:
name|hideTip
argument_list|()
expr_stmt|;
break|break;
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
name|FocusIn
case|:
case|case
name|QEvent
operator|::
name|FocusOut
case|:
case|case
name|QEvent
operator|::
name|Wheel
case|:
name|hideTipImmediately
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
if|if
condition|(
name|o
operator|==
name|widget
operator|&&
operator|!
name|rect
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|rect
operator|.
name|contains
argument_list|(
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|pos
argument_list|()
argument_list|)
condition|)
name|hideTip
argument_list|()
expr_stmt|;
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|getTipScreen
name|int
name|QTipLabel
operator|::
name|getTipScreen
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
if|if
condition|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|isVirtualDesktop
argument_list|()
condition|)
return|return
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenNumber
argument_list|(
name|pos
argument_list|)
return|;
else|else
return|return
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenNumber
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|placeTip
name|void
name|QTipLabel
operator|::
name|placeTip
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_StyleSheet
argument_list|)
operator|||
operator|(
name|w
operator|&&
name|qobject_cast
argument_list|<
name|QStyleSheetStyle
operator|*
argument_list|>
argument_list|(
name|w
operator|->
name|style
argument_list|()
argument_list|)
operator|)
condition|)
block|{
comment|//the stylesheet need to know the real parent
name|QTipLabel
operator|::
name|instance
operator|->
name|setProperty
argument_list|(
literal|"_q_stylesheet_parent"
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|w
argument_list|)
argument_list|)
expr_stmt|;
comment|//we force the style to be the QStyleSheetStyle, and force to clear the cache as well.
name|QTipLabel
operator|::
name|instance
operator|->
name|setStyleSheet
argument_list|(
name|QLatin1String
argument_list|(
literal|"/* */"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Set up for cleaning up this later...
name|QTipLabel
operator|::
name|instance
operator|->
name|styleSheetParent
operator|=
name|w
expr_stmt|;
if|if
condition|(
name|w
condition|)
block|{
name|connect
argument_list|(
name|w
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|QTipLabel
operator|::
name|instance
argument_list|,
name|SLOT
argument_list|(
name|styleSheetParentDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|//QT_NO_STYLE_STYLESHEET
ifdef|#
directive|ifdef
name|Q_WS_MAC
comment|// When in full screen mode, there is no Dock nor Menu so we can use
comment|// the whole screen for displaying the tooltip. However when not in
comment|// full screen mode we need to save space for the dock, so we use
comment|// availableGeometry instead.
specifier|extern
name|bool
name|qt_mac_app_fullscreen
decl_stmt|;
comment|//qapplication_mac.mm
name|QRect
name|screen
decl_stmt|;
if|if
condition|(
name|qt_mac_app_fullscreen
condition|)
name|screen
operator|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|(
name|getTipScreen
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|screen
operator|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|getTipScreen
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QRect
name|screen
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|(
name|getTipScreen
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QPoint
name|p
init|=
name|pos
decl_stmt|;
name|p
operator|+=
name|QPoint
argument_list|(
literal|2
argument_list|,
ifdef|#
directive|ifdef
name|Q_WS_WIN
literal|21
else|#
directive|else
literal|16
endif|#
directive|endif
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|x
argument_list|()
operator|+
name|this
operator|->
name|width
argument_list|()
operator|>
name|screen
operator|.
name|x
argument_list|()
operator|+
name|screen
operator|.
name|width
argument_list|()
condition|)
name|p
operator|.
name|rx
argument_list|()
operator|-=
literal|4
operator|+
name|this
operator|->
name|width
argument_list|()
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|y
argument_list|()
operator|+
name|this
operator|->
name|height
argument_list|()
operator|>
name|screen
operator|.
name|y
argument_list|()
operator|+
name|screen
operator|.
name|height
argument_list|()
condition|)
name|p
operator|.
name|ry
argument_list|()
operator|-=
literal|24
operator|+
name|this
operator|->
name|height
argument_list|()
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|y
argument_list|()
operator|<
name|screen
operator|.
name|y
argument_list|()
condition|)
name|p
operator|.
name|setY
argument_list|(
name|screen
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|x
argument_list|()
operator|+
name|this
operator|->
name|width
argument_list|()
operator|>
name|screen
operator|.
name|x
argument_list|()
operator|+
name|screen
operator|.
name|width
argument_list|()
condition|)
name|p
operator|.
name|setX
argument_list|(
name|screen
operator|.
name|x
argument_list|()
operator|+
name|screen
operator|.
name|width
argument_list|()
operator|-
name|this
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|x
argument_list|()
operator|<
name|screen
operator|.
name|x
argument_list|()
condition|)
name|p
operator|.
name|setX
argument_list|(
name|screen
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|.
name|y
argument_list|()
operator|+
name|this
operator|->
name|height
argument_list|()
operator|>
name|screen
operator|.
name|y
argument_list|()
operator|+
name|screen
operator|.
name|height
argument_list|()
condition|)
name|p
operator|.
name|setY
argument_list|(
name|screen
operator|.
name|y
argument_list|()
operator|+
name|screen
operator|.
name|height
argument_list|()
operator|-
name|this
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|this
operator|->
name|move
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tipChanged
name|bool
name|QTipLabel
operator|::
name|tipChanged
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QObject
modifier|*
name|o
parameter_list|)
block|{
if|if
condition|(
name|QTipLabel
operator|::
name|instance
operator|->
name|text
argument_list|()
operator|!=
name|text
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|o
operator|!=
name|widget
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|!
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
operator|!
name|rect
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Shows \a text as a tool tip, with the global position \a pos as     the point of interest. The tool tip will be shown with a platform     specific offset from this point of interest.      If you specify a non-empty rect the tip will be hidden as soon     as you move your cursor out of this area.      The \a rect is in the coordinates of the widget you specify with     \a w. If the \a rect is not empty you must specify a widget.     Otherwise this argument can be 0 but it is used to determine the     appropriate screen on multi-head systems.      If \a text is empty the tool tip is hidden. If the text is the     same as the currently shown tooltip, the tip will \e not move.     You can force moving by first hiding the tip with an empty text,     and then showing the new tip at the new position. */
end_comment
begin_function
DECL|function|showText
name|void
name|QToolTip
operator|::
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|showText
argument_list|(
name|pos
argument_list|,
name|text
argument_list|,
name|w
argument_list|,
name|rect
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    \since 5.2    \overload    This is similar to QToolTip::showText(\a pos, \a text, \a w, \a rect) but with an extra parameter \a msecDisplayTime    that specifies how long the tool tip will be displayed, in milliseconds. */
end_comment
begin_function
DECL|function|showText
name|void
name|QToolTip
operator|::
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|msecDisplayTime
parameter_list|)
block|{
if|if
condition|(
name|QTipLabel
operator|::
name|instance
operator|&&
name|QTipLabel
operator|::
name|instance
operator|->
name|isVisible
argument_list|()
condition|)
block|{
comment|// a tip does already exist
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// empty text means hide current tip
name|QTipLabel
operator|::
name|instance
operator|->
name|hideTip
argument_list|()
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
operator|!
name|QTipLabel
operator|::
name|instance
operator|->
name|fadingOut
condition|)
block|{
comment|// If the tip has changed, reuse the one
comment|// that is showing (removes flickering)
name|QPoint
name|localPos
init|=
name|pos
decl_stmt|;
if|if
condition|(
name|w
condition|)
name|localPos
operator|=
name|w
operator|->
name|mapFromGlobal
argument_list|(
name|pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|QTipLabel
operator|::
name|instance
operator|->
name|tipChanged
argument_list|(
name|localPos
argument_list|,
name|text
argument_list|,
name|w
argument_list|)
condition|)
block|{
name|QTipLabel
operator|::
name|instance
operator|->
name|reuseTip
argument_list|(
name|text
argument_list|,
name|msecDisplayTime
argument_list|)
expr_stmt|;
name|QTipLabel
operator|::
name|instance
operator|->
name|setTipRect
argument_list|(
name|w
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QTipLabel
operator|::
name|instance
operator|->
name|placeTip
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
block|}
if|if
condition|(
operator|!
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// no tip can be reused, create new tip:
ifndef|#
directive|ifndef
name|Q_WS_WIN
operator|new
name|QTipLabel
argument_list|(
name|text
argument_list|,
name|w
argument_list|,
name|msecDisplayTime
argument_list|)
expr_stmt|;
comment|// sets QTipLabel::instance to itself
else|#
directive|else
comment|// On windows, we can't use the widget as parent otherwise the window will be
comment|// raised when the tooltip will be shown
operator|new
name|QTipLabel
argument_list|(
name|text
argument_list|,
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screen
argument_list|(
name|QTipLabel
operator|::
name|getTipScreen
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
argument_list|)
argument_list|,
name|msecDisplayTime
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QTipLabel
operator|::
name|instance
operator|->
name|setTipRect
argument_list|(
name|w
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QTipLabel
operator|::
name|instance
operator|->
name|placeTip
argument_list|(
name|pos
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|QTipLabel
operator|::
name|instance
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"qtooltip_label"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_EFFECTS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
if|if
condition|(
name|QApplication
operator|::
name|isEffectEnabled
argument_list|(
name|Qt
operator|::
name|UI_FadeTooltip
argument_list|)
condition|)
name|qFadeEffect
argument_list|(
name|QTipLabel
operator|::
name|instance
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|QApplication
operator|::
name|isEffectEnabled
argument_list|(
name|Qt
operator|::
name|UI_AnimateTooltip
argument_list|)
condition|)
name|qScrollEffect
argument_list|(
name|QTipLabel
operator|::
name|instance
argument_list|)
expr_stmt|;
else|else
name|QTipLabel
operator|::
name|instance
operator|->
name|show
argument_list|()
expr_stmt|;
else|#
directive|else
name|QTipLabel
operator|::
name|instance
operator|->
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/*!     \overload      This is analogous to calling QToolTip::showText(\a pos, \a text, \a w, QRect()) */
end_comment
begin_function
DECL|function|showText
name|void
name|QToolTip
operator|::
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|QToolTip
operator|::
name|showText
argument_list|(
name|pos
argument_list|,
name|text
argument_list|,
name|w
argument_list|,
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QToolTip::hideText()     \since 4.2      Hides the tool tip. This is the same as calling showText() with an     empty string.      \sa showText() */
end_comment
begin_comment
comment|/*!   \since 4.4    Returns \c true if this tooltip is currently shown.    \sa showText()  */
end_comment
begin_function
DECL|function|isVisible
name|bool
name|QToolTip
operator|::
name|isVisible
parameter_list|()
block|{
return|return
operator|(
name|QTipLabel
operator|::
name|instance
operator|!=
literal|0
operator|&&
name|QTipLabel
operator|::
name|instance
operator|->
name|isVisible
argument_list|()
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!   \since 4.4    Returns the tooltip text, if a tooltip is visible, or an   empty string if a tooltip is not visible.  */
end_comment
begin_function
DECL|function|text
name|QString
name|QToolTip
operator|::
name|text
parameter_list|()
block|{
if|if
condition|(
name|QTipLabel
operator|::
name|instance
condition|)
return|return
name|QTipLabel
operator|::
name|instance
operator|->
name|text
argument_list|()
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QPalette
argument_list|,
argument|tooltip_palette
argument_list|)
end_macro
begin_comment
comment|/*!     Returns the palette used to render tooltips.      \note Tool tips use the inactive color group of QPalette, because tool     tips are not active windows. */
end_comment
begin_function
DECL|function|palette
name|QPalette
name|QToolTip
operator|::
name|palette
parameter_list|()
block|{
return|return
operator|*
name|tooltip_palette
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Returns the font used to render tooltips. */
end_comment
begin_function
DECL|function|font
name|QFont
name|QToolTip
operator|::
name|font
parameter_list|()
block|{
return|return
name|QApplication
operator|::
name|font
argument_list|(
literal|"QTipLabel"
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Sets the \a palette used to render tooltips.      \note Tool tips use the inactive color group of QPalette, because tool     tips are not active windows. */
end_comment
begin_function
DECL|function|setPalette
name|void
name|QToolTip
operator|::
name|setPalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
block|{
operator|*
name|tooltip_palette
argument_list|()
operator|=
name|palette
expr_stmt|;
if|if
condition|(
name|QTipLabel
operator|::
name|instance
condition|)
name|QTipLabel
operator|::
name|instance
operator|->
name|setPalette
argument_list|(
name|palette
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Sets the \a font used to render tooltips. */
end_comment
begin_function
DECL|function|setFont
name|void
name|QToolTip
operator|::
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|QApplication
operator|::
name|setFont
argument_list|(
name|font
argument_list|,
literal|"QTipLabel"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qtooltip.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLTIP
end_comment
end_unit
