begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SUBMARINE_P_H
end_ifndef
begin_define
DECL|macro|SUBMARINE_P_H
define|#
directive|define
name|SUBMARINE_P_H
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
begin_comment
comment|//Own
end_comment
begin_include
include|#
directive|include
file|"animationmanager.h"
end_include
begin_include
include|#
directive|include
file|"submarine.h"
end_include
begin_include
include|#
directive|include
file|"qanimationstate.h"
end_include
begin_comment
comment|//Qt
end_comment
begin_include
include|#
directive|include
file|<QtCore/QPropertyAnimation>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QGraphicsScene>
end_include
begin_comment
comment|//This state is describing when the boat is moving right
end_comment
begin_decl_stmt
name|class
name|MovementState
range|:
name|public
name|QAnimationState
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|MovementState
argument_list|(
name|SubMarine
operator|*
name|submarine
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAnimationState
argument_list|(
argument|parent
argument_list|)
block|{
name|movementAnimation
operator|=
name|new
name|QPropertyAnimation
argument_list|(
name|submarine
argument_list|,
literal|"pos"
argument_list|)
block|;
name|connect
argument_list|(
name|movementAnimation
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
specifier|const
name|QVariant
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|onAnimationMovementValueChanged
argument_list|(
specifier|const
name|QVariant
operator|&
argument_list|)
argument_list|)
argument_list|)
block|;
name|setAnimation
argument_list|(
name|movementAnimation
argument_list|)
block|;
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|movementAnimation
argument_list|)
block|;
name|this
operator|->
name|submarine
operator|=
name|submarine
block|;     }
name|protected
name|slots
operator|:
name|void
name|onAnimationMovementValueChanged
argument_list|(
argument|const QVariant&
argument_list|)
block|{
if|if
condition|(
name|qrand
argument_list|()
operator|%
literal|200
operator|+
literal|1
operator|==
literal|3
condition|)
name|submarine
operator|->
name|launchTorpedo
argument_list|(
name|qrand
argument_list|()
operator|%
literal|3
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|protected
operator|:
name|void
name|onEntry
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|{
if|if
condition|(
name|submarine
operator|->
name|currentDirection
argument_list|()
operator|==
name|SubMarine
operator|::
name|Left
condition|)
block|{
name|movementAnimation
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|submarine
operator|->
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|movementAnimation
operator|->
name|setDuration
argument_list|(
name|submarine
operator|->
name|x
argument_list|()
operator|/
name|submarine
operator|->
name|currentSpeed
argument_list|()
operator|*
literal|12
argument_list|)
expr_stmt|;
block|}
else|else
comment|/*if (submarine->currentDirection() == SubMarine::Right)*/
block|{
name|movementAnimation
operator|->
name|setEndValue
argument_list|(
name|QPointF
argument_list|(
name|submarine
operator|->
name|scene
argument_list|()
operator|->
name|width
argument_list|()
operator|-
name|submarine
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|submarine
operator|->
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|movementAnimation
operator|->
name|setDuration
argument_list|(
operator|(
name|submarine
operator|->
name|scene
argument_list|()
operator|->
name|width
argument_list|()
operator|-
name|submarine
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|-
name|submarine
operator|->
name|x
argument_list|()
operator|)
operator|/
name|submarine
operator|->
name|currentSpeed
argument_list|()
operator|*
literal|12
argument_list|)
expr_stmt|;
block|}
name|QAnimationState
operator|::
name|onEntry
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
name|private
operator|:
name|SubMarine
operator|*
name|submarine
block|;
name|QPropertyAnimation
operator|*
name|movementAnimation
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//This state is describing when the boat is moving right
end_comment
begin_decl_stmt
name|class
name|ReturnState
range|:
name|public
name|QAnimationState
block|{
name|public
operator|:
name|explicit
name|ReturnState
argument_list|(
name|SubMarine
operator|*
name|submarine
argument_list|,
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAnimationState
argument_list|(
argument|parent
argument_list|)
block|{
name|returnAnimation
operator|=
name|new
name|QPropertyAnimation
argument_list|(
name|submarine
operator|->
name|rotation
argument_list|()
argument_list|,
literal|"angle"
argument_list|)
block|;
name|returnAnimation
operator|->
name|setDuration
argument_list|(
literal|500
argument_list|)
block|;
name|AnimationManager
operator|::
name|self
argument_list|()
operator|->
name|registerAnimation
argument_list|(
name|returnAnimation
argument_list|)
block|;
name|setAnimation
argument_list|(
name|returnAnimation
argument_list|)
block|;
name|this
operator|->
name|submarine
operator|=
name|submarine
block|;     }
name|protected
operator|:
name|void
name|onEntry
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|returnAnimation
operator|->
name|stop
argument_list|()
block|;
name|returnAnimation
operator|->
name|setEndValue
argument_list|(
name|submarine
operator|->
name|currentDirection
argument_list|()
operator|==
name|SubMarine
operator|::
name|Right
condition|?
literal|360.
else|:
literal|180.
argument_list|)
block|;
name|QAnimationState
operator|::
name|onEntry
argument_list|(
name|e
argument_list|)
block|;     }
name|void
name|onExit
argument_list|(
argument|QEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|submarine
operator|->
name|currentDirection
argument_list|()
operator|==
name|SubMarine
operator|::
name|Right
condition|?
name|submarine
operator|->
name|setCurrentDirection
argument_list|(
name|SubMarine
operator|::
name|Left
argument_list|)
else|:
name|submarine
operator|->
name|setCurrentDirection
argument_list|(
name|SubMarine
operator|::
name|Right
argument_list|)
block|;
name|QAnimationState
operator|::
name|onExit
argument_list|(
name|e
argument_list|)
block|;     }
name|private
operator|:
name|SubMarine
operator|*
name|submarine
block|;
name|QPropertyAnimation
operator|*
name|returnAnimation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SUBMARINE_P_H
end_comment
end_unit
