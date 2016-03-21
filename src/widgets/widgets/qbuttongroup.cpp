begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"private/qbuttongroup_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BUTTONGROUP
end_ifndef
begin_include
include|#
directive|include
file|"private/qabstractbutton_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// detect a checked button other than the current one
DECL|function|detectCheckedButton
name|void
name|QButtonGroupPrivate
operator|::
name|detectCheckedButton
parameter_list|()
block|{
name|QAbstractButton
modifier|*
name|previous
init|=
name|checkedButton
decl_stmt|;
name|checkedButton
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|exclusive
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|buttonList
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|buttonList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|previous
operator|&&
name|buttonList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|checkedButton
operator|=
name|buttonList
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \class QButtonGroup     \brief The QButtonGroup class provides a container to organize groups of     button widgets.      \ingroup organizers     \ingroup geomanagement     \inmodule QtWidgets      QButtonGroup provides an abstract container into which button widgets can     be placed. It does not provide a visual representation of this container     (see QGroupBox for a container widget), but instead manages the states of     each of the buttons in the group.      An \l {QButtonGroup::exclusive} {exclusive} button group switches     off all checkable (toggle) buttons except the one that has been     clicked. By default, a button group is exclusive. The buttons in a     button group are usually checkable \l{QPushButton}s, \l{QCheckBox}es     (normally for non-exclusive button groups), or \l{QRadioButton}s.     If you create an exclusive button group, you should ensure that     one of the buttons in the group is initially checked; otherwise,     the group will initially be in a state where no buttons are     checked.      A button can be added to the group with addButton() and removed     with removeButton(). If the group is exclusive, the     currently checked button is available with checkedButton(). If a     button is clicked, the buttonClicked() signal is emitted; for a     checkable button in an exclusive group this means that the button     has been checked. The list of buttons in the group is returned by     buttons().      In addition, QButtonGroup can map between integers and buttons.     You can assign an integer id to a button with setId(), and     retrieve it with id(). The id of the currently checked button is     available with checkedId(), and there is an overloaded signal     buttonClicked() which emits the id of the button. The id \c {-1}     is reserved by QButtonGroup to mean "no such button". The purpose     of the mapping mechanism is to simplify the representation of enum     values in a user interface.      \sa QGroupBox, QPushButton, QCheckBox, QRadioButton */
end_comment
begin_comment
comment|/*!     Constructs a new, empty button group with the given \a parent.      \sa addButton(), setExclusive() */
end_comment
begin_constructor
DECL|function|QButtonGroup
name|QButtonGroup
operator|::
name|QButtonGroup
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QButtonGroupPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the button group. */
end_comment
begin_destructor
DECL|function|~QButtonGroup
name|QButtonGroup
operator|::
name|~
name|QButtonGroup
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QButtonGroup
argument_list|)
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
name|buttonList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|buttonList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \property QButtonGroup::exclusive     \brief whether the button group is exclusive      If this property is \c true, then only one button in the group can be checked     at any given time. The user can click on any button to check it, and that     button will replace the existing one as the checked button in the group.      In an exclusive group, the user cannot uncheck the currently checked button     by clicking on it; instead, another button in the group must be clicked     to set the new checked button for that group.      By default, this property is \c true. */
end_comment
begin_function
DECL|function|exclusive
name|bool
name|QButtonGroup
operator|::
name|exclusive
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|exclusive
return|;
block|}
end_function
begin_function
DECL|function|setExclusive
name|void
name|QButtonGroup
operator|::
name|setExclusive
parameter_list|(
name|bool
name|exclusive
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QButtonGroup
argument_list|)
expr_stmt|;
name|d
operator|->
name|exclusive
operator|=
name|exclusive
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QButtonGroup::buttonClicked(QAbstractButton *button)      This signal is emitted when the given \a button is clicked. A     button is clicked when it is first pressed and then released, when     its shortcut key is typed, or when QAbstractButton::click()     or QAbstractButton::animateClick() is programmatically called.       \sa checkedButton(), QAbstractButton::clicked() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonClicked(int id)      This signal is emitted when a button with the given \a id is     clicked.      \sa checkedButton(), QAbstractButton::clicked() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonPressed(QAbstractButton *button)     \since 4.2      This signal is emitted when the given \a button is pressed down.      \sa QAbstractButton::pressed() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonPressed(int id)     \since 4.2      This signal is emitted when a button with the given \a id is     pressed down.      \sa QAbstractButton::pressed() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonReleased(QAbstractButton *button)     \since 4.2      This signal is emitted when the given \a button is released.      \sa QAbstractButton::released() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonReleased(int id)     \since 4.2      This signal is emitted when a button with the given \a id is     released.      \sa QAbstractButton::released() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonToggled(QAbstractButton *button, bool checked)     \since 5.2      This signal is emitted when the given \a button is toggled.     \a checked is true if the button is checked, or false if the button is unchecked.      \sa QAbstractButton::toggled() */
end_comment
begin_comment
comment|/*!     \fn void QButtonGroup::buttonToggled(int id, bool checked)     \since 5.2      This signal is emitted when a button with the given \a id is toggled.     \a checked is true if the button is checked, or false if the button is unchecked.      \sa QAbstractButton::toggled() */
end_comment
begin_comment
comment|/*!     Adds the given \a button to the button group. If \a id is -1,     an id will be assigned to the button.     Automatically assigned ids are guaranteed to be negative,     starting with -2. If you are assigning your own ids, use     positive values to avoid conflicts.      \sa removeButton(), buttons() */
end_comment
begin_function
DECL|function|addButton
name|void
name|QButtonGroup
operator|::
name|addButton
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|,
name|int
name|id
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QButtonGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|QButtonGroup
modifier|*
name|previous
init|=
name|button
operator|->
name|d_func
argument_list|()
operator|->
name|group
condition|)
name|previous
operator|->
name|removeButton
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|button
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
name|this
expr_stmt|;
name|d
operator|->
name|buttonList
operator|.
name|append
argument_list|(
name|button
argument_list|)
expr_stmt|;
if|if
condition|(
name|id
operator|==
operator|-
literal|1
condition|)
block|{
specifier|const
name|QHash
argument_list|<
name|QAbstractButton
modifier|*
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|std
operator|::
name|min_element
argument_list|(
name|d
operator|->
name|mapping
operator|.
name|cbegin
argument_list|()
argument_list|,
name|d
operator|->
name|mapping
operator|.
name|cend
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|d
operator|->
name|mapping
operator|.
name|cend
argument_list|()
condition|)
name|d
operator|->
name|mapping
index|[
name|button
index|]
operator|=
operator|-
literal|2
expr_stmt|;
else|else
name|d
operator|->
name|mapping
index|[
name|button
index|]
operator|=
operator|*
name|it
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|mapping
index|[
name|button
index|]
operator|=
name|id
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|exclusive
operator|&&
name|button
operator|->
name|isChecked
argument_list|()
condition|)
name|button
operator|->
name|d_func
argument_list|()
operator|->
name|notifyChecked
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the given \a button from the button group.      \sa addButton(), buttons() */
end_comment
begin_function
DECL|function|removeButton
name|void
name|QButtonGroup
operator|::
name|removeButton
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QButtonGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|checkedButton
operator|==
name|button
condition|)
block|{
name|d
operator|->
name|detectCheckedButton
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|button
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|==
name|this
condition|)
block|{
name|button
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|buttonList
operator|.
name|removeAll
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|d
operator|->
name|mapping
operator|.
name|remove
argument_list|(
name|button
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the button group's list of buttons. This may be empty.      \sa addButton(), removeButton() */
end_comment
begin_function
DECL|function|buttons
name|QList
argument_list|<
name|QAbstractButton
modifier|*
argument_list|>
name|QButtonGroup
operator|::
name|buttons
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|buttonList
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the button group's checked button, or 0 if no buttons are     checked.      \sa buttonClicked() */
end_comment
begin_function
DECL|function|checkedButton
name|QAbstractButton
modifier|*
name|QButtonGroup
operator|::
name|checkedButton
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|checkedButton
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1      Returns the button with the specified \a id, or 0 if no such button     exists. */
end_comment
begin_function
DECL|function|button
name|QAbstractButton
modifier|*
name|QButtonGroup
operator|::
name|button
parameter_list|(
name|int
name|id
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|mapping
operator|.
name|key
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1      Sets the \a id for the specified \a button. Note that \a id cannot     be -1.      \sa id() */
end_comment
begin_function
DECL|function|setId
name|void
name|QButtonGroup
operator|::
name|setId
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|,
name|int
name|id
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QButtonGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|button
operator|&&
name|id
operator|!=
operator|-
literal|1
condition|)
name|d
operator|->
name|mapping
index|[
name|button
index|]
operator|=
name|id
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1      Returns the id for the specified \a button, or -1 if no such button     exists.       \sa setId() */
end_comment
begin_function
DECL|function|id
name|int
name|QButtonGroup
operator|::
name|id
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|mapping
operator|.
name|value
argument_list|(
name|button
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1      Returns the id of the checkedButton(), or -1 if no button is checked.      \sa setId() */
end_comment
begin_function
DECL|function|checkedId
name|int
name|QButtonGroup
operator|::
name|checkedId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QButtonGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|mapping
operator|.
name|value
argument_list|(
name|d
operator|->
name|checkedButton
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qbuttongroup.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BUTTONGROUP
end_comment
end_unit
