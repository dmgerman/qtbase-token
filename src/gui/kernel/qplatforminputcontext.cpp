begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatforminputcontext.h"
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|"private/qkeymapper_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPlatformInputContext     \since 5.0     \internal     \preliminary     \ingroup qpa     \brief The QPlatformInputContext class abstracts the input method dependent data and composing state.      An input method is responsible for inputting complex text that cannot     be inputted via simple keymap. It converts a sequence of input     events (typically key events) into a text string through the input     method specific converting process. The class of the processes are     widely ranging from simple finite state machine to complex text     translator that pools a whole paragraph of a text with text     editing capability to perform grammar and semantic analysis.      To abstract such different input method specific intermediate     information, Qt offers the QPlatformInputContext as base class. The     concept is well known as 'input context' in the input method     domain. An input context is created for a text widget in response     to a demand. It is ensured that an input context is prepared for     an input method before input to a text widget.      QPlatformInputContext provides an interface the actual input methods     can derive from by reimplementing methods.      \sa QInputMethod */
end_comment
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QPlatformInputContext
name|QPlatformInputContext
operator|::
name|QPlatformInputContext
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QPlatformInputContextPrivate
operator|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QPlatformInputContext
name|QPlatformInputContext
operator|::
name|~
name|QPlatformInputContext
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns input context validity. Deriving implementations should return true.  */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QPlatformInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Returns whether the implementation supports \a capability.     \internal     \since 5.4  */
end_comment
begin_function
DECL|function|hasCapability
name|bool
name|QPlatformInputContext
operator|::
name|hasCapability
parameter_list|(
name|Capability
name|capability
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|capability
argument_list|)
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Method to be called when input method needs to be reset. Called by QInputMethod::reset().     No further QInputMethodEvents should be sent as response.  */
end_comment
begin_function
DECL|function|reset
name|void
name|QPlatformInputContext
operator|::
name|reset
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|commit
name|void
name|QPlatformInputContext
operator|::
name|commit
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Notification on editor updates. Called by QInputMethod::update().  */
end_comment
begin_function
DECL|function|update
name|void
name|QPlatformInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!     Called when when the word currently being composed in input item is tapped by     the user. Input methods often use this information to offer more word     suggestions to the user.  */
end_comment
begin_function
DECL|function|invokeAction
name|void
name|QPlatformInputContext
operator|::
name|invokeAction
parameter_list|(
name|QInputMethod
operator|::
name|Action
name|action
parameter_list|,
name|int
name|cursorPosition
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|cursorPosition
argument_list|)
comment|// Default behavior for simple ephemeral input contexts. Some
comment|// complex input contexts should not be reset here.
if|if
condition|(
name|action
operator|==
name|QInputMethod
operator|::
name|Click
condition|)
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to filter input events.     Return true if the event has been consumed. Otherwise, the unfiltered event will     be forwarded to widgets as ordinary way. Although the input events have accept()     and ignore() methods, leave it untouched. */
end_comment
begin_function
DECL|function|filterEvent
name|bool
name|QPlatformInputContext
operator|::
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|event
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to return virtual keyboard rectangle in currently active     window coordinates. Default implementation returns invalid rectangle.  */
end_comment
begin_function
DECL|function|keyboardRect
name|QRectF
name|QPlatformInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing keyboardRectangle property to QInputMethod.     In addition of providing the value in keyboardRect function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitKeyboardRectChanged
name|void
name|QPlatformInputContext
operator|::
name|emitKeyboardRectChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|keyboardRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to return true whenever input method is animating     shown or hidden. Default implementation returns \c false.  */
end_comment
begin_function
DECL|function|isAnimating
name|bool
name|QPlatformInputContext
operator|::
name|isAnimating
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing animating property to QInputMethod.     In addition of providing the value in isAnimation function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitAnimatingChanged
name|void
name|QPlatformInputContext
operator|::
name|emitAnimatingChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|animatingChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     Request to show input panel.  */
end_comment
begin_function
DECL|function|showInputPanel
name|void
name|QPlatformInputContext
operator|::
name|showInputPanel
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Request to hide input panel.  */
end_comment
begin_function
DECL|function|hideInputPanel
name|void
name|QPlatformInputContext
operator|::
name|hideInputPanel
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Returns input panel visibility status. Default implementation returns \c false.  */
end_comment
begin_function
DECL|function|isInputPanelVisible
name|bool
name|QPlatformInputContext
operator|::
name|isInputPanelVisible
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing visible property to QInputMethod.     In addition of providing the value in isInputPanelVisible function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitInputPanelVisibleChanged
name|void
name|QPlatformInputContext
operator|::
name|emitInputPanelVisibleChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|visibleChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|locale
name|QLocale
name|QPlatformInputContext
operator|::
name|locale
parameter_list|()
specifier|const
block|{
return|return
name|qt_keymapper_private
argument_list|()
operator|->
name|keyboardInputLocale
return|;
block|}
end_function
begin_function
DECL|function|emitLocaleChanged
name|void
name|QPlatformInputContext
operator|::
name|emitLocaleChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|localeChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|inputDirection
name|Qt
operator|::
name|LayoutDirection
name|QPlatformInputContext
operator|::
name|inputDirection
parameter_list|()
specifier|const
block|{
return|return
name|qt_keymapper_private
argument_list|()
operator|->
name|keyboardInputDirection
return|;
block|}
end_function
begin_function
DECL|function|emitInputDirectionChanged
name|void
name|QPlatformInputContext
operator|::
name|emitInputDirectionChanged
parameter_list|(
name|Qt
operator|::
name|LayoutDirection
name|newDirection
parameter_list|)
block|{
emit|emit
name|qApp
operator|->
name|inputMethod
argument_list|()
operator|->
name|inputDirectionChanged
argument_list|(
name|newDirection
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     This virtual method gets called to notify updated focus to \a object.     \warning Input methods must not call this function directly.  */
end_comment
begin_function
DECL|function|setFocusObject
name|void
name|QPlatformInputContext
operator|::
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|object
argument_list|)
block|}
end_function
begin_comment
comment|/*!     Returns \c true if current focus object supports input method events.  */
end_comment
begin_function
DECL|function|inputMethodAccepted
name|bool
name|QPlatformInputContext
operator|::
name|inputMethodAccepted
parameter_list|()
specifier|const
block|{
return|return
name|QPlatformInputContextPrivate
operator|::
name|s_inputMethodAccepted
return|;
block|}
end_function
begin_decl_stmt
DECL|member|s_inputMethodAccepted
name|bool
name|QPlatformInputContextPrivate
operator|::
name|s_inputMethodAccepted
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|setInputMethodAccepted
name|void
name|QPlatformInputContextPrivate
operator|::
name|setInputMethodAccepted
parameter_list|(
name|bool
name|accepted
parameter_list|)
block|{
name|QPlatformInputContextPrivate
operator|::
name|s_inputMethodAccepted
operator|=
name|accepted
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
