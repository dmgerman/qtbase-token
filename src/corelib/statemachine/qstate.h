begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATE_H
end_ifndef
begin_define
DECL|macro|QSTATE_H
define|#
directive|define
name|QSTATE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractstate.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QAbstractTransition
name|class
name|QAbstractTransition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSignalTransition
name|class
name|QSignalTransition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStatePrivate
name|class
name|QStatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QState
range|:
name|public
name|QAbstractState
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QAbstractState* initialState READ initialState WRITE setInitialState NOTIFY initialStateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QAbstractState* errorState READ errorState WRITE setErrorState NOTIFY errorStateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ChildMode childMode READ childMode WRITE setChildMode NOTIFY childModeChanged
argument_list|)
name|public
operator|:
expr|enum
name|ChildMode
block|{
name|ExclusiveStates
block|,
name|ParallelStates
block|}
block|;
name|Q_ENUM
argument_list|(
name|ChildMode
argument_list|)
expr|enum
name|RestorePolicy
block|{
name|DontRestoreProperties
block|,
name|RestoreProperties
block|}
block|;
name|Q_ENUM
argument_list|(
argument|RestorePolicy
argument_list|)
name|QState
argument_list|(
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QState
argument_list|(
argument|ChildMode childMode
argument_list|,
argument|QState *parent =
literal|0
argument_list|)
block|;
operator|~
name|QState
argument_list|()
block|;
name|QAbstractState
operator|*
name|errorState
argument_list|()
specifier|const
block|;
name|void
name|setErrorState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|void
name|addTransition
argument_list|(
name|QAbstractTransition
operator|*
name|transition
argument_list|)
block|;
name|QSignalTransition
operator|*
name|addTransition
argument_list|(
specifier|const
name|QObject
operator|*
name|sender
argument_list|,
specifier|const
name|char
operator|*
name|signal
argument_list|,
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_QDOC
name|QSignalTransition
operator|*
name|addTransition
argument_list|(
argument|const QObject *sender
argument_list|,
argument|PointerToMemberFunction signal
argument_list|,
argument|QAbstractState *target
argument_list|)
block|;
else|#
directive|else
name|template
operator|<
name|typename
name|Func
operator|>
name|QSignalTransition
operator|*
name|addTransition
argument_list|(
argument|const typename QtPrivate::FunctionPointer<Func>::Object *obj
argument_list|,
argument|Func signal
argument_list|,
argument|QAbstractState *target
argument_list|)
block|{
specifier|const
name|QMetaMethod
name|signalMetaMethod
operator|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
name|signal
argument_list|)
block|;
return|return
name|addTransition
argument_list|(
name|obj
argument_list|,
name|signalMetaMethod
operator|.
name|methodSignature
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|target
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// Q_QDOC
name|QAbstractTransition
operator|*
name|addTransition
argument_list|(
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
name|void
name|removeTransition
argument_list|(
name|QAbstractTransition
operator|*
name|transition
argument_list|)
block|;
name|QList
operator|<
name|QAbstractTransition
operator|*
operator|>
name|transitions
argument_list|()
specifier|const
block|;
name|QAbstractState
operator|*
name|initialState
argument_list|()
specifier|const
block|;
name|void
name|setInitialState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|ChildMode
name|childMode
argument_list|()
specifier|const
block|;
name|void
name|setChildMode
argument_list|(
argument|ChildMode mode
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_PROPERTIES
name|void
name|assignProperty
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVariant
operator|&
name|value
argument_list|)
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|void
name|propertiesAssigned
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|void
name|childModeChanged
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|void
name|initialStateChanged
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|void
name|errorStateChanged
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|onExit
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|QState
argument_list|(
name|QStatePrivate
operator|&
name|dd
argument_list|,
name|QState
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QState
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QState
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
