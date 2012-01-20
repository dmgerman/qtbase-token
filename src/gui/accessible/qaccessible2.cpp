begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessible2.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|"qclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qtextboundaryfinder.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \namespace QAccessible2     \ingroup accessibility      \brief The QAccessible2 namespace defines constants relating to     IAccessible2-based interfaces      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleTextInterface      \ingroup accessibility      \brief The QAccessibleTextInterface class implements support for text handling.      This interface corresponds to the IAccessibleText interface.     It should be implemented for widgets that display more text than a plain label.     Labels should be represented by only \l QAccessibleInterface     and return their text as name (\l QAccessibleInterface::text() with \l QAccessible::Name as type).     The QAccessibleTextInterface is typically for text that a screen reader     might want to read line by line, and for widgets that support text selection and input.     This interface is, for example, implemented for QLineEdit.      Editable text objects should also implement \l QAccessibleEditableTextInterface.     \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \fn QAccessibleTextInterface::~QAccessibleTextInterface()     Destructor. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::addSelection(int startOffset, int endOffset)     Select the text from \a startOffset to \a endOffset.     The \a startOffset is the first character that will be selected.     The \a endOffset is the first character that will not be selected.      When the object supports multiple selections (e.g. in a word processor),     this adds a new selection, otherwise it replaces the previous selection.      The selection will be \a endOffset - \a startOffset characters long. */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleTextInterface::attributes(int offset, int *startOffset, int *endOffset) const */
end_comment
begin_comment
comment|/*!     \fn int QAccessibleTextInterface::cursorPosition() const      Returns the current cursor position. */
end_comment
begin_comment
comment|/*!     \fn QRect QAccessibleTextInterface::characterRect(int offset, QAccessible2::CoordinateType coordType) const */
end_comment
begin_comment
comment|/*!     \fn int QAccessibleTextInterface::selectionCount() const      Returns the number of selections in this text. */
end_comment
begin_comment
comment|/*!     \fn int QAccessibleTextInterface::offsetAtPoint(const QPoint&point, QAccessible2::CoordinateType coordType) const */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::selection(int selectionIndex, int *startOffset, int *endOffset) const */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleTextInterface::text(int startOffset, int endOffset) const      Returns the text from \a startOffset to \a endOffset.     The \a startOffset is the first character that will be returned.     The \a endOffset is the first character that will not be returned. */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleTextInterface::textBeforeOffset (int offset, QAccessible2::BoundaryType boundaryType,                       int *startOffset, int *endOffset) const */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleTextInterface::textAfterOffset(int offset, QAccessible2::BoundaryType boundaryType,                     int *startOffset, int *endOffset) const */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleTextInterface::textAtOffset(int offset, QAccessible2::BoundaryType boundaryType,                  int *startOffset, int *endOffset) const */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::removeSelection(int selectionIndex)      Clears the selection with \a index selectionIndex. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::setCursorPosition(int position)      Moves the cursor to \a position. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::setSelection(int selectionIndex, int startOffset, int endOffset)      Set the selection \a selectionIndex to the range from \a startOffset to \a endOffset.      \sa addSelection(), removeSelection() */
end_comment
begin_comment
comment|/*!     \fn int QAccessibleTextInterface::characterCount() const      Returns the lenght of the text (total size including spaces). */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleTextInterface::scrollToSubstring(int startIndex, int endIndex)      Ensures that the text between \a startIndex and \a endIndex is visible. */
end_comment
begin_comment
comment|/*!     \class QAccessibleEditableTextInterface     \ingroup accessibility      \brief The QAccessibleEditableTextInterface class implements support for objects with editable text.      When implementing this interface you will almost certainly also want to implement \l QAccessibleTextInterface.      Since this interface can be implemented by means of the normal \l QAccessibleTextInterface,     \l QAccessibleSimpleEditableTextInterface provides a convenience implementation of this interface.     Consider inheriting \l QAccessibleSimpleEditableTextInterface instead.      \sa QAccessibleInterface      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \fn QAccessibleEditableTextInterface::~QAccessibleEditableTextInterface()   */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::copyText(int startOffset, int endOffset) const      Copies the text from \a startOffset to \a endOffset to the system clip board.     The \a startOffset is the first character that will be copied.     The \a endOffset is the first character that will not be copied. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::deleteText(int startOffset, int endOffset)      Deletes the text from \a startOffset to \a endOffset. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::insertText(int offset, const QString&text)      Inserts \a text at position \a offset. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::cutText(int startOffset, int endOffset)      Removes the text from \a startOffset to \a endOffset and puts it in the system clip board. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::pasteText(int offset)      Pastes text from the system clip board at the position \a offset. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::replaceText(int startOffset, int endOffset, const QString&text)      Removes the text from \a startOffset to \a endOffset and instead inserts \a text. */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleEditableTextInterface::setAttributes(int startOffset, int endOffset, const QString&attributes)      \sa QAccessibleTextInterface::attributes() */
end_comment
begin_comment
comment|/*!     \class QAccessibleSimpleEditableTextInterface     \ingroup accessibility      \brief The QAccessibleSimpleEditableTextInterface class is a convenience class for     text-based widgets. It can be inherited instead of \l QAccessibleEditableTextInterface.      \sa QAccessibleInterface, QAccessibleEditableTextInterface      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleValueInterface     \ingroup accessibility      \brief The QAccessibleValueInterface class implements support for objects that manipulate a value.      This interface should be implemented by accessible objects that represent a value.     Examples are spinner, slider, dial and scroll bar.      Instead of forcing the user to deal with the individual parts of the widgets, this interface     gives an easier approach to the kind of widget it represents.      Usually this interface is implemented by classes that also implement \l QAccessibleInterface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \fn QAccessibleValueInterface::~QAccessibleValueInterface()     Destructor. */
end_comment
begin_comment
comment|/*!     \fn QVariant QAccessibleValueInterface::currentValue() const      Returns the current value of the widget. This is usually a double or int.     \sa setCurrentValue() */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleValueInterface::setCurrentValue(const QVariant&value)      Sets the \a value. If the desired \a value is out of the range of permissible values,     this call will be ignored.      \sa currentValue(), minimumValue(), maximumValue() */
end_comment
begin_comment
comment|/*!     \fn QVariant QAccessibleValueInterface::maximumValue() const      Returns the maximum value this object accepts.     \sa minimumValue(), currentValue() */
end_comment
begin_comment
comment|/*!     \fn QVariant QAccessibleValueInterface::minimumValue() const      Returns the minimum value this object accepts.     \sa maximumValue(), currentValue() */
end_comment
begin_comment
comment|/*!     \class QAccessibleImageInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleImageInterface class implements support for     the IAccessibleImage interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleTableCellInterface     \ingroup accessibility      \brief The QAccessibleTableCellInterface class implements support for     the IAccessibleTable2 Cell interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleTableInterface     \ingroup accessibility      \brief The QAccessibleTableInterface class implements support for     the IAccessibleTable2 interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleActionInterface     \ingroup accessibility      \brief The QAccessibleActionInterface class implements support for     invocable actions in the interface.      Accessible objects should implement the action interface if they support user interaction.     Usually this interface is implemented by classes that also implement \l QAccessibleInterface.      The supported actions should use the predefined actions offered in this class unless they do not     fit a predefined action. In that case a custom action can be added.      When subclassing QAccessibleActionInterface you need to provide a list of actionNames which     is the primary means to discover the available actions. Action names are never localized.     In order to present actions to the user there are two functions that need to return localized versions     of the name and give a description of the action. For the predefined action names use     \l QAccessibleActionInterface::localizedActionName() and \l QAccessibleActionInterface::localizedActionDescription()     to return their localized counterparts.      In general you should use one of the predefined action names, unless describing an action that does not fit these:     \table     \header \o Action name         \o Description     \row    \o \l checkAction()    \o checks the item (checkbox, radio button, ...)     \row    \o \l decreaseAction() \o decrease the value of the accessible (e.g. spinbox)     \row    \o \l increaseAction() \o increase the value of the accessible (e.g. spinbox)     \row    \o \l pressAction()    \o press or click or activate the accessible (should correspont to clicking the object with the mouse)     \row    \o \l setFocusAction() \o set the focus to this accessible     \row    \o \l showMenuAction() \o show a context menu, corresponds to right-clicks     \row    \o \l uncheckAction()  \o uncheck the item (checkbox, radio button, ...)     \endtable      In order to invoke the action, \l doAction() is called with an action name.      Most widgets will simply implement \l pressAction(). This is what happens when the widget is activated by     being clicked, space pressed or similar.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \fn QStringList QAccessibleActionInterface::actionNames() const      Returns the list of actions supported by this accessible object.     The actions returned should be in preferred order,     i.e. the action that the user most likely wants to trigger should be returned first,     while the least likely action should be returned last.      The list does only contain actions that can be invoked.     It won't return disabled actions, or actions associated with disabled UI controls.      The list can be empty.      Note that this list is not localized. For a localized representation re-implement \l localizedActionName()     and \l localizedActionDescription()      \sa doAction(), localizedActionName(), localizedActionDescription() */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleActionInterface::localizedActionName(const QString&actionName) const      Returns a localized action name of \a actionName.      For custom actions this function has to be re-implemented.     When using one of the default names, you can call this function in QAccessibleActionInterface     to get the localized string.      \sa actionNames(), localizedActionDescription() */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleActionInterface::localizedActionDescription(const QString&actionName) const      Returns a localized action description of the action \a actionName.      When using one of the default names, you can call this function in QAccessibleActionInterface     to get the localized string.      \sa actionNames(), localizedActionName() */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleActionInterface::doAction(const QString&actionName)      Invokes the action specified by \a actionName.     Note that \a actionName is the non-localized name as returned by \l actionNames()     This function is usually implemented by calling the same functions     that other user interaction, such as clicking the object, would trigger.      \sa actionNames() */
end_comment
begin_comment
comment|/*!     \fn QStringList QAccessibleActionInterface::keyBindingsForAction(const QString&actionName) const      Returns a list of the keyboard shortcuts available for invoking the action named \a actionName.      This is important to let users learn alternative ways of using the application by emphasizing the keyboard.      \sa actionNames() */
end_comment
begin_struct
DECL|struct|QAccessibleActionStrings
struct|struct
name|QAccessibleActionStrings
block|{
DECL|function|QAccessibleActionStrings
name|QAccessibleActionStrings
parameter_list|()
member_init_list|:
name|pressAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"Press"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|increaseAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"Increase"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|decreaseAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"Decrease"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|showMenuAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"ShowMenu"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|setFocusAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"SetFocus"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|checkAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"Check"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|uncheckAction
argument_list|(
name|QStringLiteral
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QAccessibleActionInterface"
argument_list|,
literal|"Uncheck"
argument_list|)
argument_list|)
argument_list|)
block|{}
DECL|member|pressAction
specifier|const
name|QString
name|pressAction
decl_stmt|;
DECL|member|increaseAction
specifier|const
name|QString
name|increaseAction
decl_stmt|;
DECL|member|decreaseAction
specifier|const
name|QString
name|decreaseAction
decl_stmt|;
DECL|member|showMenuAction
specifier|const
name|QString
name|showMenuAction
decl_stmt|;
DECL|member|setFocusAction
specifier|const
name|QString
name|setFocusAction
decl_stmt|;
DECL|member|checkAction
specifier|const
name|QString
name|checkAction
decl_stmt|;
DECL|member|uncheckAction
specifier|const
name|QString
name|uncheckAction
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QAccessibleActionStrings
argument_list|,
argument|accessibleActionStrings
argument_list|)
end_macro
begin_function
DECL|function|localizedActionName
name|QString
name|QAccessibleActionInterface
operator|::
name|localizedActionName
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
specifier|const
block|{
return|return
name|QAccessibleActionInterface
operator|::
name|tr
argument_list|(
name|qPrintable
argument_list|(
name|actionName
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|localizedActionDescription
name|QString
name|QAccessibleActionInterface
operator|::
name|localizedActionDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
specifier|const
block|{
specifier|const
name|QAccessibleActionStrings
modifier|*
name|strings
init|=
name|accessibleActionStrings
argument_list|()
decl_stmt|;
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|pressAction
condition|)
return|return
name|tr
argument_list|(
literal|"Triggers the action"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|increaseAction
condition|)
return|return
name|tr
argument_list|(
literal|"Increase the value"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|decreaseAction
condition|)
return|return
name|tr
argument_list|(
literal|"Decrease the value"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|showMenuAction
condition|)
return|return
name|tr
argument_list|(
literal|"Shows the menu"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|setFocusAction
condition|)
return|return
name|tr
argument_list|(
literal|"Sets the focus"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|checkAction
condition|)
return|return
name|tr
argument_list|(
literal|"Checks the checkbox"
argument_list|)
return|;
elseif|else
if|if
condition|(
name|actionName
operator|==
name|strings
operator|->
name|uncheckAction
condition|)
return|return
name|tr
argument_list|(
literal|"Unchecks the checkbox"
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the press default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|pressAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|pressAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|pressAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the increase default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|increaseAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|increaseAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|increaseAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the decrease default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|decreaseAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|decreaseAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|decreaseAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the show menu default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|showMenuAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|showMenuAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|showMenuAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the set focus default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|setFocusAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|setFocusAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|setFocusAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the check default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|checkAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|checkAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|checkAction
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the uncheck default action.     \sa actionNames(), localizedActionName()   */
end_comment
begin_function
DECL|function|uncheckAction
specifier|const
name|QString
modifier|&
name|QAccessibleActionInterface
operator|::
name|uncheckAction
parameter_list|()
block|{
return|return
name|accessibleActionStrings
argument_list|()
operator|->
name|uncheckAction
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|qTextBeforeOffsetFromString
name|QString
name|Q_GUI_EXPORT
name|qTextBeforeOffsetFromString
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextBoundaryFinder
operator|::
name|BoundaryType
name|type
decl_stmt|;
switch|switch
condition|(
name|boundaryType
condition|)
block|{
case|case
name|QAccessible2
operator|::
name|CharBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Grapheme
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|WordBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Word
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|SentenceBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Sentence
expr_stmt|;
break|break;
default|default:
comment|// in any other case return the whole line
operator|*
name|startOffset
operator|=
literal|0
expr_stmt|;
operator|*
name|endOffset
operator|=
name|text
operator|.
name|length
argument_list|()
expr_stmt|;
return|return
name|text
return|;
block|}
name|QTextBoundaryFinder
name|boundary
argument_list|(
name|type
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|boundary
operator|.
name|setPosition
argument_list|(
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|boundary
operator|.
name|isAtBoundary
argument_list|()
condition|)
block|{
name|boundary
operator|.
name|toPreviousBoundary
argument_list|()
expr_stmt|;
block|}
name|boundary
operator|.
name|toPreviousBoundary
argument_list|()
expr_stmt|;
operator|*
name|startOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
name|boundary
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
operator|*
name|endOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
return|return
name|text
operator|.
name|mid
argument_list|(
operator|*
name|startOffset
argument_list|,
operator|*
name|endOffset
operator|-
operator|*
name|startOffset
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|qTextAfterOffsetFromString
name|QString
name|Q_GUI_EXPORT
name|qTextAfterOffsetFromString
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextBoundaryFinder
operator|::
name|BoundaryType
name|type
decl_stmt|;
switch|switch
condition|(
name|boundaryType
condition|)
block|{
case|case
name|QAccessible2
operator|::
name|CharBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Grapheme
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|WordBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Word
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|SentenceBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Sentence
expr_stmt|;
break|break;
default|default:
comment|// in any other case return the whole line
operator|*
name|startOffset
operator|=
literal|0
expr_stmt|;
operator|*
name|endOffset
operator|=
name|text
operator|.
name|length
argument_list|()
expr_stmt|;
return|return
name|text
return|;
block|}
name|QTextBoundaryFinder
name|boundary
argument_list|(
name|type
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|boundary
operator|.
name|setPosition
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|boundary
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
operator|*
name|startOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
name|boundary
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
operator|*
name|endOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
return|return
name|text
operator|.
name|mid
argument_list|(
operator|*
name|startOffset
argument_list|,
operator|*
name|endOffset
operator|-
operator|*
name|startOffset
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|qTextAtOffsetFromString
name|QString
name|Q_GUI_EXPORT
name|qTextAtOffsetFromString
parameter_list|(
name|int
name|offset
parameter_list|,
name|QAccessible2
operator|::
name|BoundaryType
name|boundaryType
parameter_list|,
name|int
modifier|*
name|startOffset
parameter_list|,
name|int
modifier|*
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextBoundaryFinder
operator|::
name|BoundaryType
name|type
decl_stmt|;
switch|switch
condition|(
name|boundaryType
condition|)
block|{
case|case
name|QAccessible2
operator|::
name|CharBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Grapheme
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|WordBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Word
expr_stmt|;
break|break;
case|case
name|QAccessible2
operator|::
name|SentenceBoundary
case|:
name|type
operator|=
name|QTextBoundaryFinder
operator|::
name|Sentence
expr_stmt|;
break|break;
default|default:
comment|// in any other case return the whole line
operator|*
name|startOffset
operator|=
literal|0
expr_stmt|;
operator|*
name|endOffset
operator|=
name|text
operator|.
name|length
argument_list|()
expr_stmt|;
return|return
name|text
return|;
block|}
name|QTextBoundaryFinder
name|boundary
argument_list|(
name|type
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|boundary
operator|.
name|setPosition
argument_list|(
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|boundary
operator|.
name|isAtBoundary
argument_list|()
condition|)
block|{
name|boundary
operator|.
name|toPreviousBoundary
argument_list|()
expr_stmt|;
block|}
operator|*
name|startOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
name|boundary
operator|.
name|toNextBoundary
argument_list|()
expr_stmt|;
operator|*
name|endOffset
operator|=
name|boundary
operator|.
name|position
argument_list|()
expr_stmt|;
return|return
name|text
operator|.
name|mid
argument_list|(
operator|*
name|startOffset
argument_list|,
operator|*
name|endOffset
operator|-
operator|*
name|startOffset
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QAccessibleSimpleEditableTextInterface
name|QAccessibleSimpleEditableTextInterface
operator|::
name|QAccessibleSimpleEditableTextInterface
parameter_list|(
name|QAccessibleInterface
modifier|*
name|accessibleInterface
parameter_list|)
member_init_list|:
name|iface
argument_list|(
name|accessibleInterface
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|textForRange
specifier|static
name|QString
name|textForRange
parameter_list|(
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|,
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
block|{
return|return
name|iface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|)
operator|.
name|mid
argument_list|(
name|startOffset
argument_list|,
name|endOffset
operator|-
name|startOffset
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|copyText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|copyText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_NO_CLIPBOARD
name|Q_UNUSED
argument_list|(
name|startOffset
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|endOffset
argument_list|)
expr_stmt|;
else|#
directive|else
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|textForRange
argument_list|(
name|iface
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|deleteText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|deleteText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
block|{
name|QString
name|txt
init|=
name|iface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|)
decl_stmt|;
name|txt
operator|.
name|remove
argument_list|(
name|startOffset
argument_list|,
name|endOffset
operator|-
name|startOffset
argument_list|)
expr_stmt|;
name|iface
operator|->
name|setText
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|,
name|txt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|insertText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|insertText
parameter_list|(
name|int
name|offset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QString
name|txt
init|=
name|iface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|)
decl_stmt|;
name|txt
operator|.
name|insert
argument_list|(
name|offset
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|iface
operator|->
name|setText
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|,
name|txt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|cutText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|cutText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_CLIPBOARD
name|Q_UNUSED
argument_list|(
name|startOffset
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|endOffset
argument_list|)
expr_stmt|;
else|#
directive|else
name|QString
name|sub
init|=
name|textForRange
argument_list|(
name|iface
argument_list|,
name|startOffset
argument_list|,
name|endOffset
argument_list|)
decl_stmt|;
name|deleteText
argument_list|(
name|startOffset
argument_list|,
name|endOffset
argument_list|)
expr_stmt|;
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|setText
argument_list|(
name|sub
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|pasteText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|pasteText
parameter_list|(
name|int
name|offset
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_CLIPBOARD
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
else|#
directive|else
name|QString
name|txt
init|=
name|iface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|)
decl_stmt|;
name|txt
operator|.
name|insert
argument_list|(
name|offset
argument_list|,
name|QGuiApplication
operator|::
name|clipboard
argument_list|()
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|iface
operator|->
name|setText
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|,
name|txt
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|replaceText
name|void
name|QAccessibleSimpleEditableTextInterface
operator|::
name|replaceText
parameter_list|(
name|int
name|startOffset
parameter_list|,
name|int
name|endOffset
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QString
name|txt
init|=
name|iface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|)
decl_stmt|;
name|txt
operator|.
name|replace
argument_list|(
name|startOffset
argument_list|,
name|endOffset
operator|-
name|startOffset
argument_list|,
name|text
argument_list|)
expr_stmt|;
name|iface
operator|->
name|setText
argument_list|(
name|QAccessible
operator|::
name|Value
argument_list|,
name|txt
argument_list|)
expr_stmt|;
block|}
end_function
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
