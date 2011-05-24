begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qstate_p.h"
end_include
begin_include
include|#
directive|include
file|"qhistorystate.h"
end_include
begin_include
include|#
directive|include
file|"qhistorystate_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstracttransition.h"
end_include
begin_include
include|#
directive|include
file|"qabstracttransition_p.h"
end_include
begin_include
include|#
directive|include
file|"qsignaltransition.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QState    \brief The QState class provides a general-purpose state for QStateMachine.    \since 4.6   \ingroup statemachine    QState objects can have child states, and can have transitions to other   states. QState is part of \l{The State Machine Framework}.    The addTransition() function adds a transition. The removeTransition()   function removes a transition. The transitions() function returns the   state's outgoing transitions.    The assignProperty() function is used for defining property assignments that   should be performed when a state is entered.    Top-level states must be passed a QStateMachine object as their parent   state, or added to a state machine using QStateMachine::addState().    \section1 States with Child States    The childMode property determines how child states are treated. For   non-parallel state groups, the setInitialState() function must be called to   set the initial state. The child states are mutually exclusive states, and   the state machine needs to know which child state to enter when the parent   state is the target of a transition.    The state emits the QState::finished() signal when a final child state   (QFinalState) is entered.    The setErrorState() sets the state's error state. The error state is the   state that the state machine will transition to if an error is detected when   attempting to enter the state (e.g. because no initial state has been set).  */
end_comment
begin_comment
comment|/*!     \property QState::initialState      \brief the initial state of this state (one of its child states) */
end_comment
begin_comment
comment|/*!     \property QState::errorState      \brief the error state of this state */
end_comment
begin_comment
comment|/*!     \property QState::childMode      \brief the child mode of this state      The default value of this property is QState::ExclusiveStates. */
end_comment
begin_comment
comment|/*!   \enum QState::ChildMode    This enum specifies how a state's child states are treated.    \value ExclusiveStates The child states are mutually exclusive and an   initial state must be set by calling QState::setInitialState().    \value ParallelStates The child states are parallel. When the parent state   is entered, all its child states are entered in parallel. */
end_comment
begin_constructor
DECL|function|QStatePrivate
name|QStatePrivate
operator|::
name|QStatePrivate
parameter_list|()
member_init_list|:
name|QAbstractStatePrivate
argument_list|(
name|StandardState
argument_list|)
member_init_list|,
name|errorState
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|initialState
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|childMode
argument_list|(
name|QState
operator|::
name|ExclusiveStates
argument_list|)
member_init_list|,
name|childStatesListNeedsRefresh
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|transitionsListNeedsRefresh
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QStatePrivate
name|QStatePrivate
operator|::
name|~
name|QStatePrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|emitFinished
name|void
name|QStatePrivate
operator|::
name|emitFinished
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QState
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|finished
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|emitPropertiesAssigned
name|void
name|QStatePrivate
operator|::
name|emitPropertiesAssigned
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QState
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|propertiesAssigned
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!   Constructs a new state with the given \a parent state. */
end_comment
begin_constructor
DECL|function|QState
name|QState
operator|::
name|QState
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
name|QStatePrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new state with the given \a childMode and the given \a parent   state. */
end_comment
begin_constructor
DECL|function|QState
name|QState
operator|::
name|QState
parameter_list|(
name|ChildMode
name|childMode
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
name|QStatePrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
name|d
operator|->
name|childMode
operator|=
name|childMode
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QState
name|QState
operator|::
name|QState
parameter_list|(
name|QStatePrivate
modifier|&
name|dd
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractState
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys this state. */
end_comment
begin_destructor
DECL|function|~QState
name|QState
operator|::
name|~
name|QState
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|childStates
name|QList
argument_list|<
name|QAbstractState
modifier|*
argument_list|>
name|QStatePrivate
operator|::
name|childStates
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|childStatesListNeedsRefresh
condition|)
block|{
name|childStatesList
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|children
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractState
modifier|*
name|s
init|=
name|qobject_cast
argument_list|<
name|QAbstractState
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|s
operator|||
name|qobject_cast
argument_list|<
name|QHistoryState
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
condition|)
continue|continue;
name|childStatesList
operator|.
name|append
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|childStatesListNeedsRefresh
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|childStatesList
return|;
block|}
end_function
begin_function
DECL|function|historyStates
name|QList
argument_list|<
name|QHistoryState
modifier|*
argument_list|>
name|QStatePrivate
operator|::
name|historyStates
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QHistoryState
modifier|*
argument_list|>
name|result
decl_stmt|;
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|children
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QHistoryState
modifier|*
name|h
init|=
name|qobject_cast
argument_list|<
name|QHistoryState
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
name|h
condition|)
name|result
operator|.
name|append
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|transitions
name|QList
argument_list|<
name|QAbstractTransition
modifier|*
argument_list|>
name|QStatePrivate
operator|::
name|transitions
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|transitionsListNeedsRefresh
condition|)
block|{
name|transitionsList
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
operator|::
name|const_iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|children
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QAbstractTransition
modifier|*
name|t
init|=
name|qobject_cast
argument_list|<
name|QAbstractTransition
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
name|t
condition|)
name|transitionsList
operator|.
name|append
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
name|transitionsListNeedsRefresh
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|transitionsList
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROPERTIES
end_ifndef
begin_comment
comment|/*!   Instructs this state to set the property with the given \a name of the given   \a object to the given \a value when the state is entered.    \sa propertiesAssigned() */
end_comment
begin_function
DECL|function|assignProperty
name|void
name|QState
operator|::
name|assignProperty
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|object
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::assignProperty: cannot assign property '%s' of null object"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
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
name|propertyAssignments
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QPropertyAssignment
modifier|&
name|assn
init|=
name|d
operator|->
name|propertyAssignments
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|assn
operator|.
name|object
operator|==
name|object
operator|)
operator|&&
operator|(
name|assn
operator|.
name|propertyName
operator|==
name|name
operator|)
condition|)
block|{
name|assn
operator|.
name|value
operator|=
name|value
expr_stmt|;
return|return;
block|}
block|}
name|d
operator|->
name|propertyAssignments
operator|.
name|append
argument_list|(
name|QPropertyAssignment
argument_list|(
name|object
argument_list|,
name|name
argument_list|,
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROPERTIES
end_comment
begin_comment
comment|/*!   Returns this state's error state.     \sa QStateMachine::error() */
end_comment
begin_function
DECL|function|errorState
name|QAbstractState
modifier|*
name|QState
operator|::
name|errorState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|errorState
return|;
block|}
end_function
begin_comment
comment|/*!   Sets this state's error state to be the given \a state. If the error state   is not set, or if it is set to 0, the state will inherit its parent's error   state recursively. If no error state is set for the state itself or any of    its ancestors, an error will cause the machine to stop executing and an error   will be printed to the console. */
end_comment
begin_function
DECL|function|setErrorState
name|void
name|QState
operator|::
name|setErrorState
parameter_list|(
name|QAbstractState
modifier|*
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|!=
literal|0
operator|&&
name|qobject_cast
argument_list|<
name|QStateMachine
operator|*
argument_list|>
argument_list|(
name|state
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStateMachine::setErrorState: root state cannot be error state"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|state
operator|!=
literal|0
operator|&&
operator|(
operator|!
name|state
operator|->
name|machine
argument_list|()
operator|||
operator|(
operator|(
name|state
operator|->
name|machine
argument_list|()
operator|!=
name|machine
argument_list|()
operator|)
operator|&&
operator|!
name|qobject_cast
argument_list|<
name|QStateMachine
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|)
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::setErrorState: error state cannot belong "
literal|"to a different state machine"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|errorState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Adds the given \a transition. The transition has this state as the source.   This state takes ownership of the transition.  */
end_comment
begin_function
DECL|function|addTransition
name|void
name|QState
operator|::
name|addTransition
parameter_list|(
name|QAbstractTransition
modifier|*
name|transition
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|transition
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: cannot add null transition"
argument_list|)
expr_stmt|;
return|return ;
block|}
name|transition
operator|->
name|setParent
argument_list|(
name|this
argument_list|)
expr_stmt|;
specifier|const
name|QList
argument_list|<
name|QWeakPointer
argument_list|<
name|QAbstractState
argument_list|>
argument_list|>
modifier|&
name|targets
init|=
name|QAbstractTransitionPrivate
operator|::
name|get
argument_list|(
name|transition
argument_list|)
operator|->
name|targetStates
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
name|targets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAbstractState
modifier|*
name|t
init|=
name|targets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|t
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: cannot add transition to null state"
argument_list|)
expr_stmt|;
return|return ;
block|}
if|if
condition|(
operator|(
name|QAbstractStatePrivate
operator|::
name|get
argument_list|(
name|t
argument_list|)
operator|->
name|machine
argument_list|()
operator|!=
name|d
operator|->
name|machine
argument_list|()
operator|)
operator|&&
name|QAbstractStatePrivate
operator|::
name|get
argument_list|(
name|t
argument_list|)
operator|->
name|machine
argument_list|()
operator|&&
name|d
operator|->
name|machine
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: cannot add transition "
literal|"to a state in a different state machine"
argument_list|)
expr_stmt|;
return|return ;
block|}
block|}
if|if
condition|(
name|machine
argument_list|()
operator|!=
literal|0
operator|&&
name|machine
argument_list|()
operator|->
name|configuration
argument_list|()
operator|.
name|contains
argument_list|(
name|this
argument_list|)
condition|)
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|machine
argument_list|()
argument_list|)
operator|->
name|registerTransitions
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Adds a transition associated with the given \a signal of the given \a sender   object, and returns the new QSignalTransition object. The transition has   this state as the source, and the given \a target as the target state. */
end_comment
begin_function
DECL|function|addTransition
name|QSignalTransition
modifier|*
name|QState
operator|::
name|addTransition
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
name|QAbstractState
modifier|*
name|target
parameter_list|)
block|{
if|if
condition|(
operator|!
name|sender
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: sender cannot be null"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|!
name|signal
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: signal cannot be null"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|!
name|target
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: cannot add transition to null state"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|int
name|offset
init|=
operator|(
operator|*
name|signal
operator|==
literal|'0'
operator|+
name|QSIGNAL_CODE
operator|)
condition|?
literal|1
else|:
literal|0
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|meta
init|=
name|sender
operator|->
name|metaObject
argument_list|()
decl_stmt|;
if|if
condition|(
name|meta
operator|->
name|indexOfSignal
argument_list|(
name|signal
operator|+
name|offset
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|meta
operator|->
name|indexOfSignal
argument_list|(
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|signal
operator|+
name|offset
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: no such signal %s::%s"
argument_list|,
name|meta
operator|->
name|className
argument_list|()
argument_list|,
name|signal
operator|+
name|offset
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
name|QSignalTransition
modifier|*
name|trans
init|=
operator|new
name|QSignalTransition
argument_list|(
name|sender
argument_list|,
name|signal
argument_list|)
decl_stmt|;
name|trans
operator|->
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
name|addTransition
argument_list|(
name|trans
argument_list|)
expr_stmt|;
return|return
name|trans
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
comment|// ### Make public?
DECL|class|UnconditionalTransition
class|class
name|UnconditionalTransition
super|:
specifier|public
name|QAbstractTransition
block|{
public|public:
DECL|function|UnconditionalTransition
name|UnconditionalTransition
parameter_list|(
name|QAbstractState
modifier|*
name|target
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|()
block|{
name|setTargetState
argument_list|(
name|target
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|onTransition
name|void
name|onTransition
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{}
DECL|function|eventTest
name|bool
name|eventTest
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{
return|return
literal|true
return|;
block|}
block|}
class|;
block|}
end_namespace
begin_comment
comment|// namespace
end_comment
begin_comment
comment|/*!   Adds an unconditional transition from this state to the given \a target   state, and returns then new transition object. */
end_comment
begin_function
DECL|function|addTransition
name|QAbstractTransition
modifier|*
name|QState
operator|::
name|addTransition
parameter_list|(
name|QAbstractState
modifier|*
name|target
parameter_list|)
block|{
if|if
condition|(
operator|!
name|target
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::addTransition: cannot add transition to null state"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|UnconditionalTransition
modifier|*
name|trans
init|=
operator|new
name|UnconditionalTransition
argument_list|(
name|target
argument_list|)
decl_stmt|;
name|addTransition
argument_list|(
name|trans
argument_list|)
expr_stmt|;
return|return
name|trans
return|;
block|}
end_function
begin_comment
comment|/*!   Removes the given \a transition from this state.  The state releases   ownership of the transition.    \sa addTransition() */
end_comment
begin_function
DECL|function|removeTransition
name|void
name|QState
operator|::
name|removeTransition
parameter_list|(
name|QAbstractTransition
modifier|*
name|transition
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|transition
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::removeTransition: cannot remove null transition"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|transition
operator|->
name|sourceState
argument_list|()
operator|!=
name|this
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::removeTransition: transition %p's source state (%p)"
literal|" is different from this state (%p)"
argument_list|,
name|transition
argument_list|,
name|transition
operator|->
name|sourceState
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
name|QStateMachinePrivate
modifier|*
name|mach
init|=
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|d
operator|->
name|machine
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|mach
condition|)
name|mach
operator|->
name|unregisterTransition
argument_list|(
name|transition
argument_list|)
expr_stmt|;
name|transition
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \since 4.7    Returns this state's outgoing transitions (i.e. transitions where   this state is the \l{QAbstractTransition::sourceState()}{source   state}), or an empty list if this state has no outgoing transitions.    \sa addTransition() */
end_comment
begin_function
DECL|function|transitions
name|QList
argument_list|<
name|QAbstractTransition
modifier|*
argument_list|>
name|QState
operator|::
name|transitions
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|transitions
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onEntry
name|void
name|QState
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
name|QState
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
comment|/*!   Returns this state's initial state, or 0 if the state has no initial state. */
end_comment
begin_function
DECL|function|initialState
name|QAbstractState
modifier|*
name|QState
operator|::
name|initialState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|initialState
return|;
block|}
end_function
begin_comment
comment|/*!   Sets this state's initial state to be the given \a state.   \a state has to be a child of this state. */
end_comment
begin_function
DECL|function|setInitialState
name|void
name|QState
operator|::
name|setInitialState
parameter_list|(
name|QAbstractState
modifier|*
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|childMode
operator|==
name|QState
operator|::
name|ParallelStates
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::setInitialState: ignoring attempt to set initial state "
literal|"of parallel state group %p"
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|state
operator|&&
operator|(
name|state
operator|->
name|parentState
argument_list|()
operator|!=
name|this
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QState::setInitialState: state %p is not a child of this state (%p)"
argument_list|,
name|state
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|initialState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the child mode of this state. */
end_comment
begin_function
DECL|function|childMode
name|QState
operator|::
name|ChildMode
name|QState
operator|::
name|childMode
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QState
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|childMode
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the child \a mode of this state. */
end_comment
begin_function
DECL|function|setChildMode
name|void
name|QState
operator|::
name|setChildMode
parameter_list|(
name|ChildMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QState
argument_list|)
expr_stmt|;
name|d
operator|->
name|childMode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QState
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
name|QState
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ChildAdded
operator|)
operator|||
operator|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ChildRemoved
operator|)
condition|)
block|{
name|d
operator|->
name|childStatesListNeedsRefresh
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|transitionsListNeedsRefresh
operator|=
literal|true
expr_stmt|;
block|}
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
comment|/*!   \fn QState::finished()    This signal is emitted when a final child state of this state is entered.    \sa QFinalState */
end_comment
begin_comment
comment|/*!   \fn QState::propertiesAssigned()    This signal is emitted when all properties have been assigned their final value. If the state   assigns a value to one or more properties for which an animation exists (either set on the   transition or as a default animation on the state machine), then the signal will not be emitted   until all such animations have finished playing.    If there are no relevant animations, or no property assignments defined for the state, then   the signal will be emitted immediately before the state is entered.    \sa QState::assignProperty(), QAbstractTransition::addAnimation() */
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
