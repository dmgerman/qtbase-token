begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__BOAT__H__
end_ifndef
begin_define
DECL|macro|__BOAT__H__
define|#
directive|define
name|__BOAT__H__
end_define
begin_include
include|#
directive|include
file|"pixmapitem.h"
end_include
begin_decl_stmt
DECL|variable|Bomb
name|class
name|Bomb
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariantAnimation
name|class
name|QVariantAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStateMachine
name|class
name|QStateMachine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Boat
range|:
name|public
name|PixmapItem
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Movement
block|{
name|None
operator|=
literal|0
block|,
name|Left
block|,
name|Right
block|}
block|;     enum
block|{
name|Type
operator|=
name|UserType
operator|+
literal|2
block|}
block|;
name|Boat
argument_list|()
block|;
name|void
name|destroy
argument_list|()
block|;
name|void
name|run
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
name|int
name|bombsLaunched
argument_list|()
specifier|const
block|;
name|void
name|setBombsLaunched
argument_list|(
argument|int number
argument_list|)
block|;
name|int
name|currentSpeed
argument_list|()
specifier|const
block|;
name|void
name|setCurrentSpeed
argument_list|(
argument|int speed
argument_list|)
block|;      enum
name|Movement
name|currentDirection
argument_list|()
specifier|const
block|;
name|void
name|setCurrentDirection
argument_list|(
argument|Movement direction
argument_list|)
block|;
name|void
name|updateBoatMovement
argument_list|()
block|;
name|virtual
name|int
name|type
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|boatDestroyed
argument_list|()
block|;
name|void
name|boatExecutionFinished
argument_list|()
block|;
name|private
operator|:
name|int
name|speed
block|;
name|int
name|bombsAlreadyLaunched
block|;
name|Movement
name|direction
block|;
name|QVariantAnimation
operator|*
name|movementAnimation
block|;
name|QAbstractAnimation
operator|*
name|destroyAnimation
block|;
name|QStateMachine
operator|*
name|machine
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__BOAT__H__
end_comment
end_unit
