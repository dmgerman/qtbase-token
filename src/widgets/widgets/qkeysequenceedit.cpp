begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2013 Ivan Komissarov. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkeysequenceedit.h"
end_include
begin_include
include|#
directive|include
file|"qkeysequenceedit_p.h"
end_include
begin_include
include|#
directive|include
file|"qboxlayout.h"
end_include
begin_include
include|#
directive|include
file|"qlineedit.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_KEYSEQUENCEEDIT
name|Q_STATIC_ASSERT
argument_list|(
name|QKeySequencePrivate
operator|::
name|MaxKeyCount
operator|==
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// assumed by the code around here
end_comment
begin_function
DECL|function|init
name|void
name|QKeySequenceEditPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qt_keysequenceedit_lineedit"
argument_list|)
argument_list|)
expr_stmt|;
name|keyNum
operator|=
literal|0
expr_stmt|;
name|prevKey
operator|=
operator|-
literal|1
expr_stmt|;
name|releaseTimer
operator|=
literal|0
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|q
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|key
index|[
literal|0
index|]
operator|=
name|key
index|[
literal|1
index|]
operator|=
name|key
index|[
literal|2
index|]
operator|=
name|key
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|lineEdit
operator|->
name|setFocusProxy
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|installEventFilter
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|resetState
argument_list|()
expr_stmt|;
name|q
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|q
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// TODO: add clear button
block|}
end_function
begin_function
DECL|function|translateModifiers
name|int
name|QKeySequenceEditPrivate
operator|::
name|translateModifiers
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|state
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|int
name|result
init|=
literal|0
decl_stmt|;
comment|// The shift modifier only counts when it is not used to type a symbol
comment|// that is only reachable using the shift key anyway
if|if
condition|(
operator|(
name|state
operator|&
name|Qt
operator|::
name|ShiftModifier
operator|)
operator|&&
operator|(
name|text
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|text
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isPrint
argument_list|()
operator|||
name|text
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isLetterOrNumber
argument_list|()
operator|||
name|text
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isSpace
argument_list|()
operator|)
condition|)
name|result
operator||=
name|Qt
operator|::
name|SHIFT
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|result
operator||=
name|Qt
operator|::
name|CTRL
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|result
operator||=
name|Qt
operator|::
name|META
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|result
operator||=
name|Qt
operator|::
name|ALT
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|resetState
name|void
name|QKeySequenceEditPrivate
operator|::
name|resetState
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|releaseTimer
condition|)
block|{
name|q
operator|->
name|killTimer
argument_list|(
name|releaseTimer
argument_list|)
expr_stmt|;
name|releaseTimer
operator|=
literal|0
expr_stmt|;
block|}
name|prevKey
operator|=
operator|-
literal|1
expr_stmt|;
name|lineEdit
operator|->
name|setText
argument_list|(
name|keySequence
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setPlaceholderText
argument_list|(
name|QKeySequenceEdit
operator|::
name|tr
argument_list|(
literal|"Press shortcut"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|finishEditing
name|void
name|QKeySequenceEditPrivate
operator|::
name|finishEditing
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|resetState
argument_list|()
expr_stmt|;
emit|emit
name|q
operator|->
name|keySequenceChanged
argument_list|(
name|keySequence
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|editingFinished
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     \class QKeySequenceEdit     \brief The QKeySequenceEdit widget allows to input a QKeySequence.      \inmodule QtWidgets      \since 5.2      This widget lets the user choose a QKeySequence, which is usually used as     a shortcut. The recording is initiated when the widget receives the focus     and ends one second after the user releases the last key.      \sa QKeySequenceEdit::keySequence */
end_comment
begin_comment
comment|/*!     Constructs a QKeySequenceEdit widget with the given \a parent. */
end_comment
begin_constructor
DECL|function|QKeySequenceEdit
name|QKeySequenceEdit
operator|::
name|QKeySequenceEdit
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QKeySequenceEditPrivate
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QKeySequenceEdit widget with the given \a keySequence and \a parent. */
end_comment
begin_constructor
DECL|function|QKeySequenceEdit
name|QKeySequenceEdit
operator|::
name|QKeySequenceEdit
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|keySequence
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QKeySequenceEditPrivate
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|setKeySequence
argument_list|(
name|keySequence
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QKeySequenceEdit
name|QKeySequenceEdit
operator|::
name|QKeySequenceEdit
parameter_list|(
name|QKeySequenceEditPrivate
modifier|&
name|dd
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|,
name|f
argument_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QKeySequenceEdit object. */
end_comment
begin_destructor
DECL|function|~QKeySequenceEdit
name|QKeySequenceEdit
operator|::
name|~
name|QKeySequenceEdit
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \property QKeySequenceEdit::keySequence      \brief This property contains the currently chosen key sequence.      The shortcut can be changed by the user or via setter function. */
end_comment
begin_function
DECL|function|keySequence
name|QKeySequence
name|QKeySequenceEdit
operator|::
name|keySequence
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|keySequence
return|;
block|}
end_function
begin_function
DECL|function|setKeySequence
name|void
name|QKeySequenceEdit
operator|::
name|setKeySequence
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|keySequence
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|d
operator|->
name|resetState
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|keySequence
operator|==
name|keySequence
condition|)
return|return;
name|d
operator|->
name|keySequence
operator|=
name|keySequence
expr_stmt|;
name|d
operator|->
name|key
index|[
literal|0
index|]
operator|=
name|d
operator|->
name|key
index|[
literal|1
index|]
operator|=
name|d
operator|->
name|key
index|[
literal|2
index|]
operator|=
name|d
operator|->
name|key
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|keyNum
operator|=
name|keySequence
operator|.
name|count
argument_list|()
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
name|d
operator|->
name|keyNum
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|key
index|[
name|i
index|]
operator|=
name|keySequence
index|[
name|i
index|]
expr_stmt|;
name|d
operator|->
name|lineEdit
operator|->
name|setText
argument_list|(
name|keySequence
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
argument_list|)
expr_stmt|;
emit|emit
name|keySequenceChanged
argument_list|(
name|keySequence
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     \fn void QKeySequenceEdit::editingFinished()      This signal is emitted when the user finishes entering the shortcut.      \note there is a one second delay before releasing the last key and     emitting this signal. */
end_comment
begin_comment
comment|/*!     \brief Clears the current key sequence. */
end_comment
begin_function
DECL|function|clear
name|void
name|QKeySequenceEdit
operator|::
name|clear
parameter_list|()
block|{
name|setKeySequence
argument_list|(
name|QKeySequence
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QKeySequenceEdit
operator|::
name|event
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
name|Shortcut
case|:
return|return
literal|true
return|;
case|case
name|QEvent
operator|::
name|ShortcutOverride
case|:
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
default|default :
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|keyPressEvent
name|void
name|QKeySequenceEdit
operator|::
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
name|int
name|nextKey
init|=
name|e
operator|->
name|key
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|prevKey
operator|==
operator|-
literal|1
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|prevKey
operator|=
name|nextKey
expr_stmt|;
block|}
name|d
operator|->
name|lineEdit
operator|->
name|setPlaceholderText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|nextKey
operator|==
name|Qt
operator|::
name|Key_Control
operator|||
name|nextKey
operator|==
name|Qt
operator|::
name|Key_Shift
operator|||
name|nextKey
operator|==
name|Qt
operator|::
name|Key_Meta
operator|||
name|nextKey
operator|==
name|Qt
operator|::
name|Key_Alt
condition|)
block|{
return|return;
block|}
name|QString
name|selectedText
init|=
name|d
operator|->
name|lineEdit
operator|->
name|selectedText
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|selectedText
operator|.
name|isEmpty
argument_list|()
operator|&&
name|selectedText
operator|==
name|d
operator|->
name|lineEdit
operator|->
name|text
argument_list|()
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|nextKey
operator|==
name|Qt
operator|::
name|Key_Backspace
condition|)
return|return;
block|}
if|if
condition|(
name|d
operator|->
name|keyNum
operator|>=
name|QKeySequencePrivate
operator|::
name|MaxKeyCount
condition|)
return|return;
name|nextKey
operator||=
name|d
operator|->
name|translateModifiers
argument_list|(
name|e
operator|->
name|modifiers
argument_list|()
argument_list|,
name|e
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|key
index|[
name|d
operator|->
name|keyNum
index|]
operator|=
name|nextKey
expr_stmt|;
name|d
operator|->
name|keyNum
operator|++
expr_stmt|;
name|QKeySequence
name|key
argument_list|(
name|d
operator|->
name|key
index|[
literal|0
index|]
argument_list|,
name|d
operator|->
name|key
index|[
literal|1
index|]
argument_list|,
name|d
operator|->
name|key
index|[
literal|2
index|]
argument_list|,
name|d
operator|->
name|key
index|[
literal|3
index|]
argument_list|)
decl_stmt|;
name|d
operator|->
name|keySequence
operator|=
name|key
expr_stmt|;
name|QString
name|text
init|=
name|key
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|keyNum
operator|<
name|QKeySequencePrivate
operator|::
name|MaxKeyCount
condition|)
block|{
comment|//: This text is an "unfinished" shortcut, expands like "Ctrl+A, ..."
name|text
operator|=
name|tr
argument_list|(
literal|"%1, ..."
argument_list|)
operator|.
name|arg
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|lineEdit
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|keyReleaseEvent
name|void
name|QKeySequenceEdit
operator|::
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|prevKey
operator|==
name|e
operator|->
name|key
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|keyNum
operator|<
name|QKeySequencePrivate
operator|::
name|MaxKeyCount
condition|)
name|d
operator|->
name|releaseTimer
operator|=
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|finishEditing
argument_list|()
expr_stmt|;
block|}
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|timerEvent
name|void
name|QKeySequenceEdit
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeySequenceEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|d
operator|->
name|releaseTimer
condition|)
block|{
name|d
operator|->
name|finishEditing
argument_list|()
expr_stmt|;
return|return;
block|}
name|QWidget
operator|::
name|timerEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_KEYSEQUENCEEDIT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qkeysequenceedit.cpp"
end_include
end_unit
