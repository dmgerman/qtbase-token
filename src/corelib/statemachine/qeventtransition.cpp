begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeventtransition.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qeventtransition_p.h"
end_include
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qstate_p.h"
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
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QEventTransition   \inmodule QtCore    \brief The QEventTransition class provides a QObject-specific transition for Qt events.    \since 4.6   \ingroup statemachine    A QEventTransition object binds an event to a particular QObject.   QEventTransition is part of \l{The State Machine Framework}.    Example:    \code   QPushButton *button = ...;   QState *s1 = ...;   QState *s2 = ...;   // If in s1 and the button receives an Enter event, transition to s2   QEventTransition *enterTransition = new QEventTransition(button, QEvent::Enter);   enterTransition->setTargetState(s2);   s1->addTransition(enterTransition);   // If in s2 and the button receives an Exit event, transition back to s1   QEventTransition *leaveTransition = new QEventTransition(button, QEvent::Leave);   leaveTransition->setTargetState(s1);   s2->addTransition(leaveTransition);   \endcode    \section1 Subclassing    When reimplementing the eventTest() function, you should first call the base   implementation to verify that the event is a QStateMachine::WrappedEvent for   the proper object and event type. You may then cast the event to a   QStateMachine::WrappedEvent and get the original event by calling   QStateMachine::WrappedEvent::event(), and perform additional checks on that   object.    \sa QState::addTransition() */
comment|/*!     \property QEventTransition::eventSource      \brief the event source that this event transition is associated with */
comment|/*!     \property QEventTransition::eventType      \brief the type of event that this event transition is associated with */
DECL|function|QEventTransitionPrivate
name|QEventTransitionPrivate
operator|::
name|QEventTransitionPrivate
parameter_list|()
block|{
name|object
operator|=
literal|0
expr_stmt|;
name|eventType
operator|=
name|QEvent
operator|::
name|None
expr_stmt|;
name|registered
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|get
name|QEventTransitionPrivate
modifier|*
name|QEventTransitionPrivate
operator|::
name|get
parameter_list|(
name|QEventTransition
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|unregister
name|void
name|QEventTransitionPrivate
operator|::
name|unregister
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|registered
operator|||
operator|!
name|machine
argument_list|()
condition|)
return|return;
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|machine
argument_list|()
argument_list|)
operator|->
name|unregisterEventTransition
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maybeRegister
name|void
name|QEventTransitionPrivate
operator|::
name|maybeRegister
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|QStateMachine
modifier|*
name|mach
init|=
name|machine
argument_list|()
condition|)
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|mach
argument_list|)
operator|->
name|maybeRegisterEventTransition
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Constructs a new QEventTransition object with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QEventTransition
name|QEventTransition
operator|::
name|QEventTransition
parameter_list|(
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
operator|*
operator|new
name|QEventTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new QEventTransition object associated with events of the given   \a type for the given \a object, and with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QEventTransition
name|QEventTransition
operator|::
name|QEventTransition
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
operator|*
operator|new
name|QEventTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{
name|Q_D
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|registered
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|object
operator|=
name|object
expr_stmt|;
name|d
operator|->
name|eventType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QEventTransition
name|QEventTransition
operator|::
name|QEventTransition
parameter_list|(
name|QEventTransitionPrivate
modifier|&
name|dd
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QEventTransition
name|QEventTransition
operator|::
name|QEventTransition
parameter_list|(
name|QEventTransitionPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|,
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|QState
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|registered
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|object
operator|=
name|object
expr_stmt|;
name|d
operator|->
name|eventType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this QObject event transition. */
end_comment
begin_destructor
DECL|function|~QEventTransition
name|QEventTransition
operator|::
name|~
name|QEventTransition
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns the event type that this event transition is associated with. */
end_comment
begin_function
DECL|function|eventType
name|QEvent
operator|::
name|Type
name|QEventTransition
operator|::
name|eventType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|eventType
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the event \a type that this event transition is associated with. */
end_comment
begin_function
DECL|function|setEventType
name|void
name|QEventTransition
operator|::
name|setEventType
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|eventType
operator|==
name|type
condition|)
return|return;
name|d
operator|->
name|unregister
argument_list|()
expr_stmt|;
name|d
operator|->
name|eventType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the event source associated with this event transition. */
end_comment
begin_function
DECL|function|eventSource
name|QObject
modifier|*
name|QEventTransition
operator|::
name|eventSource
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|object
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the event source associated with this event transition to be the given   \a object. */
end_comment
begin_function
DECL|function|setEventSource
name|void
name|QEventTransition
operator|::
name|setEventSource
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|object
operator|==
name|object
condition|)
return|return;
name|d
operator|->
name|unregister
argument_list|()
expr_stmt|;
name|d
operator|->
name|object
operator|=
name|object
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|eventTest
name|bool
name|QEventTransition
operator|::
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StateMachineWrapped
condition|)
block|{
name|QStateMachine
operator|::
name|WrappedEvent
modifier|*
name|we
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|WrappedEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
return|return
operator|(
name|we
operator|->
name|object
argument_list|()
operator|==
name|d
operator|->
name|object
operator|)
operator|&&
operator|(
name|we
operator|->
name|event
argument_list|()
operator|->
name|type
argument_list|()
operator|==
name|d
operator|->
name|eventType
operator|)
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onTransition
name|void
name|QEventTransition
operator|::
name|onTransition
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
name|QEventTransition
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractTransition
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
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
comment|//QT_NO_STATEMACHINE
end_comment
end_unit
