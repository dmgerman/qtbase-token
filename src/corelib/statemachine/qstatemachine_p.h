begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QState
operator|*
name|startState
argument_list|()
block|;
name|void
name|removeStartState
argument_list|()
block|;
name|void
name|clearHistory
argument_list|()
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
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|exitStates
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
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|enterStates
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
name|enabledTransitions
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
name|applyProperties
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
operator|&
name|transitionList
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|exitedStates
argument_list|,
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|enteredStates
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
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
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
typedef|typedef
name|QPair
operator|<
name|QObject
operator|*
operator|,
name|QByteArray
operator|>
name|RestorableId
expr_stmt|;
name|QHash
operator|<
name|RestorableId
block|,
name|QVariant
operator|>
name|registeredRestorables
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|registerRestorable
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|propertyName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unregisterRestorable
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|propertyName
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|hasRestorable
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
specifier|const
name|QByteArray
operator|&
name|propertyName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QVariant
name|restorableValue
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
specifier|const
name|QByteArray
operator|&
name|propertyName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|State
name|state
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QState
modifier|*
name|_startState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|processing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|processingScheduled
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|stop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|StopProcessingReason
name|stopProcessingReason
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|configuration
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QEvent
operator|*
operator|>
name|internalEventQueue
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QEvent
operator|*
operator|>
name|externalEventQueue
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMutex
name|internalEventMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMutex
name|externalEventMutex
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QStateMachine
operator|::
name|Error
name|error
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStateMachine
operator|::
name|RestorePolicy
name|globalRestorePolicy
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|errorString
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|pendingErrorStates
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|pendingErrorStatesForDefaultEntry
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
name|bool
name|animated
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPair
operator|<
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
operator|,
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
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QAbstractState
operator|*
operator|,
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
expr|>
name|animationsForState
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QAbstractAnimation
operator|*
operator|,
name|QPropertyAssignment
operator|>
name|propertyForAnimation
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|QAbstractAnimation
operator|*
operator|,
name|QAbstractState
operator|*
operator|>
name|stateForAnimation
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSet
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|resetAnimationEndValues
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimations
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMultiHash
operator|<
name|QAbstractState
operator|*
operator|,
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimationsForSource
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMultiHash
operator|<
name|QAbstractState
operator|*
operator|,
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimationsForTarget
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ANIMATION
end_comment
begin_decl_stmt
name|QSignalEventGenerator
modifier|*
name|signalEventGenerator
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
specifier|const
name|QObject
operator|*
operator|,
name|QVector
operator|<
name|int
operator|>
expr|>
name|connections
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
end_ifndef
begin_expr_stmt
name|QHash
operator|<
name|QObject
operator|*
operator|,
name|QHash
operator|<
name|QEvent
operator|::
name|Type
operator|,
name|int
operator|>
expr|>
name|qobjectEvents
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QFreeList
operator|<
name|void
operator|>
name|delayedEventIdFreeList
expr_stmt|;
end_expr_stmt
begin_struct
struct|struct
name|DelayedEvent
block|{
name|QEvent
modifier|*
name|event
decl_stmt|;
name|int
name|timerId
decl_stmt|;
name|DelayedEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|int tid
argument_list|)
block|:
name|event
argument_list|(
name|e
argument_list|)
operator|,
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
operator|,
name|timerId
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_expr_stmt
name|QHash
operator|<
name|int
operator|,
name|DelayedEvent
operator|>
name|delayedEvents
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
name|int
operator|,
name|int
operator|>
name|timerIdToDelayedEventId
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMutex
name|delayedEventsMutex
decl_stmt|;
end_decl_stmt
begin_typedef
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
end_typedef
begin_struct
struct|struct
name|Handler
block|{
name|f_cloneEvent
name|cloneEvent
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
specifier|static
specifier|const
name|Handler
modifier|*
name|handler
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
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
