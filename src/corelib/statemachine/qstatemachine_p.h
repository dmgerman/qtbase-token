begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATEMACHINE_P_H
end_ifndef
begin_define
DECL|macro|QSTATEMACHINE_P_H
define|#
directive|define
name|QSTATEMACHINE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qstate_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<private/qfreelist_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
end_ifndef
begin_decl_stmt
DECL|variable|QEventTransition
name|class
name|QEventTransition
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QSignalEventGenerator
name|class
name|QSignalEventGenerator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSignalTransition
name|class
name|QSignalTransition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractState
name|class
name|QAbstractState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractTransition
name|class
name|QAbstractTransition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFinalState
name|class
name|QFinalState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHistoryState
name|class
name|QHistoryState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QState
name|class
name|QState
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QStateMachine
name|class
name|QStateMachine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QStateMachinePrivate
range|:
name|public
name|QStatePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QStateMachine
argument_list|)
name|public
operator|:
expr|enum
name|State
block|{
name|NotRunning
block|,
name|Starting
block|,
name|Running
block|}
block|;     enum
name|EventProcessingMode
block|{
name|DirectProcessing
block|,
name|QueuedProcessing
block|}
block|;     enum
name|StopProcessingReason
block|{
name|EventQueueEmpty
block|,
name|Finished
block|,
name|Stopped
block|}
block|;
name|QStateMachinePrivate
argument_list|()
block|;
operator|~
name|QStateMachinePrivate
argument_list|()
block|;
specifier|static
name|QStateMachinePrivate
operator|*
name|get
argument_list|(
name|QStateMachine
operator|*
name|q
argument_list|)
block|;
name|QState
operator|*
name|findLCA
argument_list|(
argument|const QList<QAbstractState*>&states
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|stateEntryLessThan
argument_list|(
name|QAbstractState
operator|*
name|s1
argument_list|,
name|QAbstractState
operator|*
name|s2
argument_list|)
block|;
specifier|static
name|bool
name|stateExitLessThan
argument_list|(
name|QAbstractState
operator|*
name|s1
argument_list|,
name|QAbstractState
operator|*
name|s2
argument_list|)
block|;
name|QAbstractState
operator|*
name|findErrorState
argument_list|(
name|QAbstractState
operator|*
name|context
argument_list|)
block|;
name|void
name|setError
argument_list|(
argument|QStateMachine::Error error
argument_list|,
argument|QAbstractState *currentContext
argument_list|)
block|;
comment|// private slots
name|void
name|_q_start
argument_list|()
block|;
name|void
name|_q_process
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|void
name|_q_animationFinished
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_startDelayedEventTimer
argument_list|(
argument|int id
argument_list|,
argument|int delay
argument_list|)
block|;
name|void
name|_q_killDelayedEventTimer
argument_list|(
argument|int id
argument_list|,
argument|int timerId
argument_list|)
block|;
name|QState
operator|*
name|rootState
argument_list|()
specifier|const
block|;
name|void
name|clearHistory
argument_list|()
block|;
name|QAbstractTransition
operator|*
name|createInitialTransition
argument_list|()
specifier|const
block|;
name|void
name|microstep
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
operator|&
name|transitionList
argument_list|)
block|;
name|bool
name|isPreempted
argument_list|(
argument|const QAbstractState *s
argument_list|,
argument|const QSet<QAbstractTransition*>&transitions
argument_list|)
specifier|const
block|;
name|QSet
operator|<
name|QAbstractTransition
operator|*
operator|>
name|selectTransitions
argument_list|(
argument|QEvent *event
argument_list|)
specifier|const
block|;
name|void
name|exitStates
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesToExit_sorted
argument_list|,
specifier|const
name|QHash
operator|<
name|QAbstractState
operator|*
argument_list|,
name|QList
operator|<
name|QPropertyAssignment
operator|>
expr|>
operator|&
name|assignmentsForEnteredStates
argument_list|)
block|;
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|computeStatesToExit
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
operator|&
name|enabledTransitions
argument_list|)
block|;
name|void
name|executeTransitionContent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
operator|&
name|transitionList
argument_list|)
block|;
name|void
name|enterStates
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|exitedStates_sorted
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesToEnter_sorted
argument_list|,
specifier|const
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesForDefaultEntry
argument_list|,
name|QHash
operator|<
name|QAbstractState
operator|*
argument_list|,
name|QList
operator|<
name|QPropertyAssignment
operator|>
expr|>
operator|&
name|propertyAssignmentsForState
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
operator|&
name|selectedAnimations
endif|#
directive|endif
argument_list|)
block|;
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|computeStatesToEnter
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
operator|&
name|enabledTransitions
argument_list|,
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesForDefaultEntry
argument_list|)
block|;
name|void
name|addStatesToEnter
argument_list|(
name|QAbstractState
operator|*
name|s
argument_list|,
name|QState
operator|*
name|root
argument_list|,
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesToEnter
argument_list|,
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesForDefaultEntry
argument_list|)
block|;
name|void
name|addAncestorStatesToEnter
argument_list|(
name|QAbstractState
operator|*
name|s
argument_list|,
name|QState
operator|*
name|root
argument_list|,
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesToEnter
argument_list|,
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|statesForDefaultEntry
argument_list|)
block|;
specifier|static
name|QState
operator|*
name|toStandardState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
specifier|static
specifier|const
name|QState
operator|*
name|toStandardState
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
specifier|static
name|QFinalState
operator|*
name|toFinalState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
specifier|static
name|QHistoryState
operator|*
name|toHistoryState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|bool
name|isInFinalState
argument_list|(
argument|QAbstractState *s
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|isFinal
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|s
argument_list|)
block|;
specifier|static
name|bool
name|isParallel
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|s
argument_list|)
block|;
name|bool
name|isCompound
argument_list|(
argument|const QAbstractState *s
argument_list|)
specifier|const
block|;
name|bool
name|isAtomic
argument_list|(
argument|const QAbstractState *s
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|isDescendantOf
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|s
argument_list|,
specifier|const
name|QAbstractState
operator|*
name|other
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QState
operator|*
operator|>
name|properAncestors
argument_list|(
specifier|const
name|QAbstractState
operator|*
name|s
argument_list|,
specifier|const
name|QState
operator|*
name|upperBound
argument_list|)
block|;
name|void
name|goToState
argument_list|(
name|QAbstractState
operator|*
name|targetState
argument_list|)
block|;
name|void
name|registerTransitions
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|void
name|maybeRegisterTransition
argument_list|(
name|QAbstractTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|registerTransition
argument_list|(
name|QAbstractTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|maybeRegisterSignalTransition
argument_list|(
name|QSignalTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|registerSignalTransition
argument_list|(
name|QSignalTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|unregisterSignalTransition
argument_list|(
name|QSignalTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|registerMultiThreadedSignalTransitions
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
name|void
name|maybeRegisterEventTransition
argument_list|(
name|QEventTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|registerEventTransition
argument_list|(
name|QEventTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|unregisterEventTransition
argument_list|(
name|QEventTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|handleFilteredEvent
argument_list|(
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|unregisterTransition
argument_list|(
name|QAbstractTransition
operator|*
name|transition
argument_list|)
block|;
name|void
name|unregisterAllTransitions
argument_list|()
block|;
name|void
name|handleTransitionSignal
argument_list|(
argument|QObject *sender
argument_list|,
argument|int signalIndex
argument_list|,
argument|void **args
argument_list|)
block|;
name|void
name|postInternalEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|postExternalEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|QEvent
operator|*
name|dequeueInternalEvent
argument_list|()
block|;
name|QEvent
operator|*
name|dequeueExternalEvent
argument_list|()
block|;
name|bool
name|isInternalEventQueueEmpty
argument_list|()
block|;
name|bool
name|isExternalEventQueueEmpty
argument_list|()
block|;
name|void
name|processEvents
argument_list|(
argument|EventProcessingMode processingMode
argument_list|)
block|;
name|void
name|cancelAllDelayedEvents
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_PROPERTIES
name|class
name|RestorableId
block|{
name|QPointer
operator|<
name|QObject
operator|>
name|guard
block|;
name|QObject
operator|*
name|obj
block|;
name|QByteArray
name|prop
block|;
comment|// two overloads because friends can't have default arguments
name|friend
name|uint
name|qHash
argument_list|(
argument|const RestorableId&key
argument_list|,
argument|uint seed
argument_list|)
name|Q_DECL_NOEXCEPT_EXPR
argument_list|(
argument|noexcept(std::declval<QByteArray>())
argument_list|)
block|{
return|return
name|qHash
argument_list|(
name|qMakePair
argument_list|(
name|key
operator|.
name|obj
argument_list|,
name|key
operator|.
name|prop
argument_list|)
argument_list|,
name|seed
argument_list|)
return|;
block|}
name|friend
name|uint
name|qHash
argument_list|(
argument|const RestorableId&key
argument_list|)
name|Q_DECL_NOEXCEPT_EXPR
argument_list|(
argument|noexcept(qHash(key,
literal|0U
argument|))
argument_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
argument_list|,
literal|0U
argument_list|)
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RestorableId
operator|&
name|lhs
expr|,
specifier|const
name|RestorableId
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|lhs
operator|.
name|obj
operator|==
name|rhs
operator|.
name|obj
operator|&&
name|lhs
operator|.
name|prop
operator|==
name|rhs
operator|.
name|prop
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|RestorableId
operator|&
name|lhs
expr|,
specifier|const
name|RestorableId
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|lhs
expr|,
name|rhs
operator|)
return|;
block|}
name|public
operator|:
name|explicit
name|RestorableId
argument_list|(
argument|QObject *o
argument_list|,
argument|QByteArray p
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|guard
argument_list|(
name|o
argument_list|)
block|,
name|obj
argument_list|(
name|o
argument_list|)
block|,
name|prop
argument_list|(
argument|qMove(p)
argument_list|)
block|{}
name|QObject
operator|*
name|object
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|guard
return|;
block|}
name|QByteArray
name|propertyName
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|prop
return|;
block|}
expr|}
block|;
name|QHash
operator|<
name|QAbstractState
operator|*
block|,
name|QHash
operator|<
name|RestorableId
block|,
name|QVariant
operator|>
expr|>
name|registeredRestorablesForState
block|;
name|bool
name|hasRestorable
argument_list|(
argument|QAbstractState *state
argument_list|,
argument|QObject *object
argument_list|,
argument|const QByteArray&propertyName
argument_list|)
specifier|const
block|;
name|QVariant
name|savedValueForRestorable
argument_list|(
argument|const QList<QAbstractState*>&exitedStates_sorted
argument_list|,
argument|QObject *object
argument_list|,
argument|const QByteArray&propertyName
argument_list|)
specifier|const
block|;
name|void
name|registerRestorable
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|object
argument_list|,
specifier|const
name|QByteArray
operator|&
name|propertyName
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
name|void
name|unregisterRestorables
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|states
argument_list|,
name|QObject
operator|*
name|object
argument_list|,
specifier|const
name|QByteArray
operator|&
name|propertyName
argument_list|)
block|;
name|QList
operator|<
name|QPropertyAssignment
operator|>
name|restorablesToPropertyList
argument_list|(
argument|const QHash<RestorableId
argument_list|,
argument|QVariant>&restorables
argument_list|)
specifier|const
block|;
name|QHash
operator|<
name|RestorableId
block|,
name|QVariant
operator|>
name|computePendingRestorables
argument_list|(
argument|const QList<QAbstractState*>&statesToExit_sorted
argument_list|)
specifier|const
block|;
name|QHash
operator|<
name|QAbstractState
operator|*
block|,
name|QList
operator|<
name|QPropertyAssignment
operator|>
expr|>
name|computePropertyAssignments
argument_list|(
argument|const QList<QAbstractState*>&statesToEnter_sorted
argument_list|,
argument|QHash<RestorableId
argument_list|,
argument|QVariant>&pendingRestorables
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|State
name|state
block|;
name|bool
name|processing
block|;
name|bool
name|processingScheduled
block|;
name|bool
name|stop
block|;
name|StopProcessingReason
name|stopProcessingReason
block|;
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|configuration
block|;
name|QList
operator|<
name|QEvent
operator|*
operator|>
name|internalEventQueue
block|;
name|QList
operator|<
name|QEvent
operator|*
operator|>
name|externalEventQueue
block|;
name|QMutex
name|internalEventMutex
block|;
name|QMutex
name|externalEventMutex
block|;
name|QStateMachine
operator|::
name|Error
name|error
block|;
name|QState
operator|::
name|RestorePolicy
name|globalRestorePolicy
block|;
name|QString
name|errorString
block|;
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|pendingErrorStates
block|;
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|pendingErrorStatesForDefaultEntry
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|bool
name|animated
block|;
name|QPair
operator|<
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
block|,
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
expr|>
name|initializeAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|abstractAnimation
argument_list|,
specifier|const
name|QPropertyAssignment
operator|&
name|prop
argument_list|)
block|;
name|QHash
operator|<
name|QAbstractState
operator|*
block|,
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
expr|>
name|animationsForState
block|;
name|QHash
operator|<
name|QAbstractAnimation
operator|*
block|,
name|QPropertyAssignment
operator|>
name|propertyForAnimation
block|;
name|QHash
operator|<
name|QAbstractAnimation
operator|*
block|,
name|QAbstractState
operator|*
operator|>
name|stateForAnimation
block|;
name|QSet
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|resetAnimationEndValues
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimations
block|;
name|QMultiHash
operator|<
name|QAbstractState
operator|*
block|,
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimationsForSource
block|;
name|QMultiHash
operator|<
name|QAbstractState
operator|*
block|,
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimationsForTarget
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|selectAnimations
argument_list|(
argument|const QList<QAbstractTransition *>&transitionList
argument_list|)
specifier|const
block|;
name|void
name|terminateActiveAnimations
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|,
specifier|const
name|QHash
operator|<
name|QAbstractState
operator|*
argument_list|,
name|QList
operator|<
name|QPropertyAssignment
operator|>
expr|>
operator|&
name|assignmentsForEnteredStates
argument_list|)
block|;
name|void
name|initializeAnimations
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
operator|&
name|selectedAnimations
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|exitedStates_sorted
argument_list|,
name|QHash
operator|<
name|QAbstractState
operator|*
argument_list|,
name|QList
operator|<
name|QPropertyAssignment
operator|>
expr|>
operator|&
name|assignmentsForEnteredStates
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_ANIMATION
name|QSignalEventGenerator
operator|*
name|signalEventGenerator
block|;
name|QHash
operator|<
specifier|const
name|QObject
operator|*
block|,
name|QVector
operator|<
name|int
operator|>
expr|>
name|connections
block|;
name|QMutex
name|connectionsMutex
block|;
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
name|QHash
operator|<
name|QObject
operator|*
block|,
name|QHash
operator|<
name|QEvent
operator|::
name|Type
block|,
name|int
operator|>
expr|>
name|qobjectEvents
block|;
endif|#
directive|endif
name|QFreeList
operator|<
name|void
operator|>
name|delayedEventIdFreeList
block|;     struct
name|DelayedEvent
block|{
name|QEvent
operator|*
name|event
block|;
name|int
name|timerId
block|;
name|DelayedEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|int tid
argument_list|)
operator|:
name|event
argument_list|(
name|e
argument_list|)
block|,
name|timerId
argument_list|(
argument|tid
argument_list|)
block|{}
name|DelayedEvent
argument_list|()
operator|:
name|event
argument_list|(
literal|0
argument_list|)
block|,
name|timerId
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
name|QHash
operator|<
name|int
block|,
name|DelayedEvent
operator|>
name|delayedEvents
block|;
name|QHash
operator|<
name|int
block|,
name|int
operator|>
name|timerIdToDelayedEventId
block|;
name|QMutex
name|delayedEventsMutex
block|;
typedef|typedef
name|QEvent
modifier|*
function_decl|(
modifier|*
name|f_cloneEvent
function_decl|)
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
block|struct
name|Handler
block|{
name|f_cloneEvent
name|cloneEvent
block|;     }
block|;
specifier|static
specifier|const
name|Handler
operator|*
name|handler
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
specifier|const
name|QStateMachinePrivate
operator|::
name|Handler
operator|*
name|qcoreStateMachineHandler
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
