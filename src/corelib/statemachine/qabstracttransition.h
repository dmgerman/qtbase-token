begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTRANSITION_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTRANSITION_H
define|#
directive|define
name|QABSTRACTTRANSITION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractState
name|class
name|QAbstractState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QState
name|class
name|QState
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStateMachine
name|class
name|QStateMachine
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
DECL|variable|QAbstractTransitionPrivate
name|class
name|QAbstractTransitionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractTransition
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QState* sourceState READ sourceState
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QAbstractState* targetState READ targetState WRITE setTargetState
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QList<QAbstractState*> targetStates READ targetStates WRITE setTargetStates
argument_list|)
name|public
operator|:
name|QAbstractTransition
argument_list|(
name|QState
operator|*
name|sourceState
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QAbstractTransition
argument_list|()
block|;
name|QState
operator|*
name|sourceState
argument_list|()
specifier|const
block|;
name|QAbstractState
operator|*
name|targetState
argument_list|()
specifier|const
block|;
name|void
name|setTargetState
argument_list|(
name|QAbstractState
operator|*
name|target
argument_list|)
block|;
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
name|targetStates
argument_list|()
specifier|const
block|;
name|void
name|setTargetStates
argument_list|(
specifier|const
name|QList
operator|<
name|QAbstractState
operator|*
operator|>
operator|&
name|targets
argument_list|)
block|;
name|QStateMachine
operator|*
name|machine
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|void
name|addAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|void
name|removeAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_MOC_RUN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|qdoc
argument_list|)
name|private
operator|:
comment|// can only be emitted by QAbstractTransition
endif|#
directive|endif
name|void
name|triggered
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|onTransition
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
operator|=
literal|0
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|protected
operator|:
name|QAbstractTransition
argument_list|(
name|QAbstractTransitionPrivate
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
argument|QAbstractTransition
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractTransition
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
