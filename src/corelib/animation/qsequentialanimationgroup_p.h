begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSEQUENTIALANIMATIONGROUP_P_H
end_ifndef
begin_define
DECL|macro|QSEQUENTIALANIMATIONGROUP_P_H
define|#
directive|define
name|QSEQUENTIALANIMATIONGROUP_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QIODevice. This header file may change from version to
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
file|"qsequentialanimationgroup.h"
end_include
begin_include
include|#
directive|include
file|"private/qanimationgroup_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSequentialAnimationGroupPrivate
range|:
name|public
name|QAnimationGroupPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QSequentialAnimationGroup
argument_list|)
name|public
operator|:
name|QSequentialAnimationGroupPrivate
argument_list|()
operator|:
name|currentAnimation
argument_list|(
literal|0
argument_list|)
block|,
name|currentAnimationIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|lastLoop
argument_list|(
literal|0
argument_list|)
block|{ }
expr|struct
name|AnimationIndex
block|{
name|AnimationIndex
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
block|,
name|timeOffset
argument_list|(
literal|0
argument_list|)
block|{}
comment|// index points to the animation at timeOffset, skipping 0 duration animations.
comment|// Note that the index semantic is slightly different depending on the direction.
name|int
name|index
block|;
comment|// the index of the animation in timeOffset
name|int
name|timeOffset
block|;
comment|// time offset when the animation at index starts.
block|}
block|;
name|int
name|animationActualTotalDuration
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|AnimationIndex
name|indexForCurrentTime
argument_list|()
specifier|const
block|;
name|void
name|setCurrentAnimation
argument_list|(
argument|int index
argument_list|,
argument|bool intermediate = false
argument_list|)
block|;
name|void
name|activateCurrentAnimation
argument_list|(
argument|bool intermediate = false
argument_list|)
block|;
name|void
name|animationInsertedAt
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|animationRemoved
argument_list|(
argument|int index
argument_list|,
argument|QAbstractAnimation *anim
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|QAbstractAnimation
operator|*
name|currentAnimation
block|;
name|int
name|currentAnimationIndex
block|;
comment|// this is the actual duration of uncontrolled animations
comment|// it helps seeking and even going forward
name|QList
operator|<
name|int
operator|>
name|actualDuration
block|;
name|void
name|restart
argument_list|()
block|;
name|int
name|lastLoop
block|;
comment|// handle time changes
name|void
name|rewindForwards
argument_list|(
specifier|const
name|AnimationIndex
operator|&
name|newAnimationIndex
argument_list|)
block|;
name|void
name|advanceForwards
argument_list|(
specifier|const
name|AnimationIndex
operator|&
name|newAnimationIndex
argument_list|)
block|;
comment|// private slot
name|void
name|_q_uncontrolledAnimationFinished
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSEQUENTIALANIMATIONGROUP_P_H
end_comment
end_unit
