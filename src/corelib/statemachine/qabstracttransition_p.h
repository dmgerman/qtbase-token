begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTRANSITION_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTRANSITION_P_H
define|#
directive|define
name|QABSTRACTTRANSITION_P_H
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
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
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
begin_decl_stmt
DECL|variable|QAbstractTransition
name|class
name|QAbstractTransition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractTransitionPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractTransition
argument_list|)
name|public
operator|:
name|QAbstractTransitionPrivate
argument_list|()
block|;
specifier|static
name|QAbstractTransitionPrivate
operator|*
name|get
argument_list|(
name|QAbstractTransition
operator|*
name|q
argument_list|)
block|;
name|bool
name|callEventTest
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|virtual
name|void
name|callOnTransition
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|QState
operator|*
name|sourceState
argument_list|()
specifier|const
block|;
name|QStateMachine
operator|*
name|machine
argument_list|()
specifier|const
block|;
name|void
name|emitTriggered
argument_list|()
block|;
name|QList
operator|<
name|QWeakPointer
operator|<
name|QAbstractState
operator|>
expr|>
name|targetStates
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
