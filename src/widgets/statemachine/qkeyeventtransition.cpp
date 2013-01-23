begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qkeyeventtransition.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qbasickeyeventtransition_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qstatemachine.h>
end_include
begin_include
include|#
directive|include
file|<private/qeventtransition_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \class QKeyEventTransition    \brief The QKeyEventTransition class provides a transition for key events.    \since 4.6   \ingroup statemachine   \inmodule QtWidgets    QKeyEventTransition is part of \l{The State Machine Framework}.    \sa QState::addTransition() */
end_comment
begin_comment
comment|/*!     \property QKeyEventTransition::key      \brief the key that this key event transition is associated with */
end_comment
begin_comment
comment|/*!     \property QKeyEventTransition::modifierMask      \brief the keyboard modifier mask that this key event transition checks for */
end_comment
begin_class
DECL|class|QKeyEventTransitionPrivate
class|class
name|QKeyEventTransitionPrivate
super|:
specifier|public
name|QEventTransitionPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QKeyEventTransition
parameter_list|)
specifier|public
private|:
DECL|function|QKeyEventTransitionPrivate
name|QKeyEventTransitionPrivate
parameter_list|()
block|{}
DECL|member|transition
name|QBasicKeyEventTransition
modifier|*
name|transition
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!   Constructs a new key event transition with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QKeyEventTransition
name|QKeyEventTransition
operator|::
name|QKeyEventTransition
parameter_list|(
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QEventTransition
argument_list|(
operator|*
operator|new
name|QKeyEventTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{
name|Q_D
argument_list|(
name|QKeyEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|transition
operator|=
operator|new
name|QBasicKeyEventTransition
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Constructs a new key event transition for events of the given \a type for   the given \a object, with the given \a key and \a sourceState. */
end_comment
begin_constructor
DECL|function|QKeyEventTransition
name|QKeyEventTransition
operator|::
name|QKeyEventTransition
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
name|int
name|key
parameter_list|,
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QEventTransition
argument_list|(
operator|*
operator|new
name|QKeyEventTransitionPrivate
argument_list|,
name|object
argument_list|,
name|type
argument_list|,
name|sourceState
argument_list|)
block|{
name|Q_D
argument_list|(
name|QKeyEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|transition
operator|=
operator|new
name|QBasicKeyEventTransition
argument_list|(
name|type
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this key event transition. */
end_comment
begin_destructor
DECL|function|~QKeyEventTransition
name|QKeyEventTransition
operator|::
name|~
name|QKeyEventTransition
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QKeyEventTransition
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|transition
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Returns the key that this key event transition checks for. */
end_comment
begin_function
DECL|function|key
name|int
name|QKeyEventTransition
operator|::
name|key
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QKeyEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|transition
operator|->
name|key
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the key that this key event transition will check for. */
end_comment
begin_function
DECL|function|setKey
name|void
name|QKeyEventTransition
operator|::
name|setKey
parameter_list|(
name|int
name|key
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeyEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|transition
operator|->
name|setKey
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the keyboard modifier mask that this key event transition checks   for. */
end_comment
begin_function
DECL|function|modifierMask
name|Qt
operator|::
name|KeyboardModifiers
name|QKeyEventTransition
operator|::
name|modifierMask
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QKeyEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|transition
operator|->
name|modifierMask
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the keyboard modifier mask that this key event transition will   check for to \a modifierMask. */
end_comment
begin_function
DECL|function|setModifierMask
name|void
name|QKeyEventTransition
operator|::
name|setModifierMask
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifierMask
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QKeyEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|transition
operator|->
name|setModifierMask
argument_list|(
name|modifierMask
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|eventTest
name|bool
name|QKeyEventTransition
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
name|QKeyEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QEventTransition
operator|::
name|eventTest
argument_list|(
name|event
argument_list|)
condition|)
return|return
literal|false
return|;
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
name|d
operator|->
name|transition
operator|->
name|setEventType
argument_list|(
name|we
operator|->
name|event
argument_list|()
operator|->
name|type
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|QAbstractTransitionPrivate
operator|::
name|get
argument_list|(
name|d
operator|->
name|transition
argument_list|)
operator|->
name|callEventTest
argument_list|(
name|we
operator|->
name|event
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onTransition
name|void
name|QKeyEventTransition
operator|::
name|onTransition
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|QEventTransition
operator|::
name|onTransition
argument_list|(
name|event
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
comment|//QT_NO_STATEMACHINE
end_comment
end_unit
