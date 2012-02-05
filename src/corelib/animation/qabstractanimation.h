begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTANIMATION_H
end_ifndef
begin_define
DECL|macro|QABSTRACTANIMATION_H
define|#
directive|define
name|QABSTRACTANIMATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
DECL|variable|QAnimationGroup
name|class
name|QAnimationGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSequentialAnimationGroup
name|class
name|QSequentialAnimationGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAnimationDriver
name|class
name|QAnimationDriver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractAnimationPrivate
name|class
name|QAbstractAnimationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAbstractAnimation
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|State
argument_list|)
name|Q_ENUMS
argument_list|(
argument|Direction
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|State state READ state NOTIFY stateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int loopCount READ loopCount WRITE setLoopCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentTime READ currentTime WRITE setCurrentTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentLoop READ currentLoop NOTIFY currentLoopChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Direction direction READ direction WRITE setDirection NOTIFY directionChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int duration READ duration
argument_list|)
name|public
operator|:
expr|enum
name|Direction
block|{
name|Forward
block|,
name|Backward
block|}
block|;      enum
name|State
block|{
name|Stopped
block|,
name|Paused
block|,
name|Running
block|}
block|;      enum
name|DeletionPolicy
block|{
name|KeepWhenStopped
operator|=
literal|0
block|,
name|DeleteWhenStopped
block|}
block|;
name|QAbstractAnimation
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QAbstractAnimation
argument_list|()
block|;
name|State
name|state
argument_list|()
specifier|const
block|;
name|QAnimationGroup
operator|*
name|group
argument_list|()
specifier|const
block|;
name|Direction
name|direction
argument_list|()
specifier|const
block|;
name|void
name|setDirection
argument_list|(
argument|Direction direction
argument_list|)
block|;
name|int
name|currentTime
argument_list|()
specifier|const
block|;
name|int
name|currentLoopTime
argument_list|()
specifier|const
block|;
name|int
name|loopCount
argument_list|()
specifier|const
block|;
name|void
name|setLoopCount
argument_list|(
argument|int loopCount
argument_list|)
block|;
name|int
name|currentLoop
argument_list|()
specifier|const
block|;
name|virtual
name|int
name|duration
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|int
name|totalDuration
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|()
block|;
name|void
name|stateChanged
argument_list|(
argument|QAbstractAnimation::State newState
argument_list|,
argument|QAbstractAnimation::State oldState
argument_list|)
block|;
name|void
name|currentLoopChanged
argument_list|(
argument|int currentLoop
argument_list|)
block|;
name|void
name|directionChanged
argument_list|(
name|QAbstractAnimation
operator|::
name|Direction
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|(
argument|QAbstractAnimation::DeletionPolicy policy = KeepWhenStopped
argument_list|)
block|;
name|void
name|pause
argument_list|()
block|;
name|void
name|resume
argument_list|()
block|;
name|void
name|setPaused
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|setCurrentTime
argument_list|(
argument|int msecs
argument_list|)
block|;
name|protected
operator|:
name|QAbstractAnimation
argument_list|(
name|QAbstractAnimationPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|updateCurrentTime
argument_list|(
argument|int currentTime
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|updateState
argument_list|(
argument|QAbstractAnimation::State newState
argument_list|,
argument|QAbstractAnimation::State oldState
argument_list|)
block|;
name|virtual
name|void
name|updateDirection
argument_list|(
argument|QAbstractAnimation::Direction direction
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractAnimation
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractAnimation
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAnimationDriverPrivate
name|class
name|QAnimationDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAnimationDriver
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAnimationDriver
argument_list|)
name|public
operator|:
name|QAnimationDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAnimationDriver
argument_list|()
block|;
name|virtual
name|void
name|advance
argument_list|()
block|;
name|void
name|install
argument_list|()
block|;
name|void
name|uninstall
argument_list|()
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
name|qint64
name|elapsed
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|()
block|;
name|void
name|stopped
argument_list|()
block|;
name|protected
operator|:
name|void
name|advanceAnimation
argument_list|(
argument|qint64 timeStep = -
literal|1
argument_list|)
block|;
name|virtual
name|void
name|start
argument_list|()
block|;
name|virtual
name|void
name|stop
argument_list|()
block|;
name|QAnimationDriver
argument_list|(
name|QAnimationDriverPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QUnifiedTimer
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTANIMATION_H
end_comment
end_unit
