begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhistorystate.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qhistorystate_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QHistoryState   \inmodule QtCore    \brief The QHistoryState class provides a means of returning to a previously active substate.    \since 4.6   \ingroup statemachine    A history state is a pseudo-state that represents the child state that the   parent state was in the last time the parent state was exited. A transition   with a history state as its target is in fact a transition to one or more   other child states of the parent state. QHistoryState is part of \l{The   State Machine Framework}.    Use the setDefaultState() function to set the state that should be entered   if the parent state has never been entered.  Example:    \code   QStateMachine machine;    QState *s1 = new QState();   QState *s11 = new QState(s1);   QState *s12 = new QState(s1);    QHistoryState *s1h = new QHistoryState(s1);   s1h->setDefaultState(s11);    machine.addState(s1);    QState *s2 = new QState();   machine.addState(s2);    QPushButton *button = new QPushButton();   // Clicking the button will cause the state machine to enter the child state   // that s1 was in the last time s1 was exited, or the history state's default   // state if s1 has never been entered.   s1->addTransition(button, SIGNAL(clicked()), s1h);   \endcode    If more than one default state has to be entered, or if the transition to the default state(s)   has to be acted upon, the defaultTransition should be set instead. Note that the eventTest()   method of that transition will never be called: the selection and execution of the transition is   done automatically when entering the history state.    By default a history state is shallow, meaning that it won't remember nested   states. This can be configured through the historyType property. */
end_comment
begin_comment
comment|/*!   \property QHistoryState::defaultTransition    \brief the default transition of this history state */
end_comment
begin_comment
comment|/*!   \property QHistoryState::defaultState    \brief the default state of this history state */
end_comment
begin_comment
comment|/*!   \property QHistoryState::historyType    \brief the type of history that this history state records    The default value of this property is QHistoryState::ShallowHistory. */
end_comment
begin_comment
comment|/*!   \enum QHistoryState::HistoryType    This enum specifies the type of history that a QHistoryState records.    \value ShallowHistory Only the immediate child states of the parent state   are recorded. In this case a transition with the history state as its   target will end up in the immediate child state that the parent was in the   last time it was exited. This is the default.    \value DeepHistory Nested states are recorded. In this case a transition   with the history state as its target will end up in the most deeply nested   descendant state the parent was in the last time it was exited. */
end_comment
begin_constructor
DECL|function|QHistoryStatePrivate
name|QHistoryStatePrivate
operator|::
name|QHistoryStatePrivate
parameter_list|()
member_init_list|:
name|QAbstractStatePrivate
argument_list|(
name|HistoryState
argument_list|)
member_init_list|,
name|defaultTransition
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|historyType
argument_list|(
name|QHistoryState
operator|::
name|ShallowHistory
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|DefaultStateTransition
name|DefaultStateTransition
operator|::
name|DefaultStateTransition
parameter_list|(
name|QHistoryState
modifier|*
name|source
parameter_list|,
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|()
block|{
name|setParent
argument_list|(
name|source
argument_list|)
expr_stmt|;
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Constructs a new shallow history state with the given \a parent state. */
end_comment
begin_constructor
DECL|function|QHistoryState
name|QHistoryState
operator|::
name|QHistoryState
parameter_list|(
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractState
argument_list|(
operator|*
operator|new
name|QHistoryStatePrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new history state of the given \a type, with the given \a   parent state. */
end_comment
begin_constructor
DECL|function|QHistoryState
name|QHistoryState
operator|::
name|QHistoryState
parameter_list|(
name|HistoryType
name|type
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractState
argument_list|(
operator|*
operator|new
name|QHistoryStatePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
name|d
operator|->
name|historyType
operator|=
name|type
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this history state. */
end_comment
begin_destructor
DECL|function|~QHistoryState
name|QHistoryState
operator|::
name|~
name|QHistoryState
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns this history state's default transition. The default transition is   taken when the history state has never been entered before. The target states   of the default transition therefore make up the default state.    \since 5.6 */
end_comment
begin_function
DECL|function|defaultTransition
name|QAbstractTransition
modifier|*
name|QHistoryState
operator|::
name|defaultTransition
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QHistoryState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|defaultTransition
return|;
block|}
end_function
begin_comment
comment|/*!   Sets this history state's default transition to be the given \a transition.   This will set the source state of the \a transition to the history state.    Note that the eventTest method of the \a transition will never be called.    \since 5.6 */
end_comment
begin_function
DECL|function|setDefaultTransition
name|void
name|QHistoryState
operator|::
name|setDefaultTransition
parameter_list|(
name|QAbstractTransition
modifier|*
name|transition
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|defaultTransition
operator|!=
name|transition
condition|)
block|{
name|d
operator|->
name|defaultTransition
operator|=
name|transition
expr_stmt|;
name|transition
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
emit|emit
name|defaultTransitionChanged
argument_list|(
name|QHistoryState
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!   Returns this history state's default state.  The default state indicates the   state to transition to if the parent state has never been entered before. */
end_comment
begin_function
DECL|function|defaultState
name|QAbstractState
modifier|*
name|QHistoryState
operator|::
name|defaultState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QHistoryState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|defaultTransition
condition|?
name|d
operator|->
name|defaultTransition
operator|->
name|targetState
argument_list|()
else|:
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|isSoleEntry
specifier|static
specifier|inline
name|bool
name|isSoleEntry
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QAbstractState
modifier|*
argument_list|>
modifier|&
name|states
parameter_list|,
specifier|const
name|QAbstractState
modifier|*
name|state
parameter_list|)
block|{
return|return
name|states
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|states
operator|.
name|first
argument_list|()
operator|==
name|state
return|;
block|}
end_function
begin_comment
comment|/*!   Sets this history state's default state to be the given \a state.   \a state must be a sibling of this history state.    Note that this function does not set \a state as the initial state   of its parent. */
end_comment
begin_function
DECL|function|setDefaultState
name|void
name|QHistoryState
operator|::
name|setDefaultState
parameter_list|(
name|QAbstractState
modifier|*
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|&&
name|state
operator|->
name|parentState
argument_list|()
operator|!=
name|parentState
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QHistoryState::setDefaultState: state %p does not belong "
literal|"to this history state's group (%p)"
argument_list|,
name|state
argument_list|,
name|parentState
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|defaultTransition
operator|||
operator|!
name|isSoleEntry
argument_list|(
name|d
operator|->
name|defaultTransition
operator|->
name|targetStates
argument_list|()
argument_list|,
name|state
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|defaultTransition
operator|||
operator|!
name|qobject_cast
argument_list|<
name|DefaultStateTransition
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|defaultTransition
argument_list|)
condition|)
block|{
name|d
operator|->
name|defaultTransition
operator|=
operator|new
name|DefaultStateTransition
argument_list|(
name|this
argument_list|,
name|state
argument_list|)
expr_stmt|;
emit|emit
name|defaultTransitionChanged
argument_list|(
name|QHistoryState
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
else|else
block|{
name|d
operator|->
name|defaultTransition
operator|->
name|setTargetState
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
emit|emit
name|defaultStateChanged
argument_list|(
name|QHistoryState
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!   Returns the type of history that this history state records. */
end_comment
begin_function
DECL|function|historyType
name|QHistoryState
operator|::
name|HistoryType
name|QHistoryState
operator|::
name|historyType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QHistoryState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|historyType
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a type of history that this history state records. */
end_comment
begin_function
DECL|function|setHistoryType
name|void
name|QHistoryState
operator|::
name|setHistoryType
parameter_list|(
name|HistoryType
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QHistoryState
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|historyType
operator|!=
name|type
condition|)
block|{
name|d
operator|->
name|historyType
operator|=
name|type
expr_stmt|;
emit|emit
name|historyTypeChanged
argument_list|(
name|QHistoryState
operator|::
name|QPrivateSignal
argument_list|()
argument_list|)
emit|;
block|}
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onEntry
name|void
name|QHistoryState
operator|::
name|onEntry
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onExit
name|void
name|QHistoryState
operator|::
name|onExit
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QHistoryState
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractState
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \fn QHistoryState::defaultStateChanged()   \since 5.4    This signal is emitted when the defaultState property is changed.    \sa QHistoryState::defaultState */
end_comment
begin_comment
comment|/*!   \fn QHistoryState::historyTypeChanged()   \since 5.4    This signal is emitted when the historyType property is changed.    \sa QHistoryState::historyType */
end_comment
begin_comment
comment|/*!   \fn QHistoryState::defaultTransitionChanged()   \since 5.6    This signal is emitted when the defaultTransition property is changed.    \sa QHistoryState::defaultTransition */
end_comment
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
