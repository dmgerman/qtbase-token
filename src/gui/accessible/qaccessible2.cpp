begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|/*!     \namespace QAccessible2     \ingroup accessibility     \internal     \preliminary      \brief The QAccessible2 namespace defines constants relating to     IAccessible2-based interfaces      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleTextInterface      \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleTextInterface class implements support for     the IAccessibleText interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleEditableTextInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleEditableTextInterface class implements support for     the IAccessibleEditableText interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleSimpleEditableTextInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleSimpleEditableTextInterface class is a convenience class for     text-based widgets.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleValueInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleValueInterface class implements support for     the IAccessibleValue interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleImageInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleImageInterface class implements support for     the IAccessibleImage interface.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \class QAccessibleActionInterface     \ingroup accessibility     \internal     \preliminary      \brief The QAccessibleActionInterface class implements support for     invocable actions in the interface.      Each accessible should implement the action interface if it supports any actions.     The supported actions should adhere to the naming scheme inside the QAccessible2 namespace.     Custom actions can be added.      When subclassing QAccessibleActionInterface you need to provide a list of actionNames which     is the primary means to discover the available actions. Action names are never localized.     In order to present actions to the user there are two functions that need to return localized versions     of the name and give a description of the action.      In order to invoke the action, doAction is called with an action name.      Most widgets will simply implement the PressAction. This is what happens when the widget is activated by     being clicked on, space pressed or similar.      \link http://www.linux-foundation.org/en/Accessibility/IAccessible2 IAccessible2 Specification \endlink */
end_comment
begin_comment
comment|/*!     \fn QStringList QAccessibleActionInterface::actionNames() const      Returns a list of valid actions. The actions returned should be in preferred order,     i.e. the action that the user most likely wants to trigger should be returned first,     while the least likely action should be returned last.      The list does only contain actions that *can* be invoked. Therefore it,     won't return disabled actions, or actions associated with disabled UI     controls.      The list can also be empty.      \sa localizedActionName(), doAction() */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleActionInterface::localizedActionName(const QString&name) const      Returns a localized action name of \a name.      \sa actionNames(), localizedActionDescription() */
end_comment
begin_comment
comment|/*!     \fn QString QAccessibleActionInterface::localizedActionDescription(const QString&name) const      Returns a localized action description of \a name.      This is what should be presented to the user. The actionNames should always     be untranslated to make them consistent for screen readers.      \sa actionNames(), localizedActionName() */
end_comment
begin_comment
comment|/*!     \fn void QAccessibleActionInterface::doAction(const QString&actionName)      Invokes the action specified by \a actionName      \sa actionNames() */
end_comment
begin_comment
comment|/*!     \fn QStringList QAccessibleActionInterface::keyBindingsForAction(const QString&actionName) const      Returns a list of the keyboard shortcuts available for invoking the action named \a actionName      \sa actionNames() */
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
