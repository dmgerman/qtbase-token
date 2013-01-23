begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLEANIMATION_P_H
end_ifndef
begin_define
DECL|macro|QSTYLEANIMATION_P_H
define|#
directive|define
name|QSTYLEANIMATION_P_H
end_define
begin_include
include|#
directive|include
file|"qabstractanimation.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API. It exists for the convenience of
comment|// qcommonstyle.cpp.  This header file may change from version to version
comment|// without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
name|class
name|QStyleAnimation
range|:
name|public
name|QAbstractAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QStyleAnimation
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|virtual
operator|~
name|QStyleAnimation
argument_list|()
block|;
name|QObject
operator|*
name|target
argument_list|()
specifier|const
block|;
name|int
name|duration
argument_list|()
specifier|const
block|;
name|void
name|setDuration
argument_list|(
argument|int duration
argument_list|)
block|;
name|int
name|delay
argument_list|()
specifier|const
block|;
name|void
name|setDelay
argument_list|(
argument|int delay
argument_list|)
block|;
name|QTime
name|startTime
argument_list|()
specifier|const
block|;
name|void
name|setStartTime
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|)
block|;
name|void
name|updateTarget
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|bool
name|isUpdateNeeded
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|updateCurrentTime
argument_list|(
argument|int time
argument_list|)
block|;
name|private
operator|:
name|int
name|_delay
block|;
name|int
name|_duration
block|;
name|QTime
name|_startTime
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QProgressStyleAnimation
range|:
name|public
name|QStyleAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QProgressStyleAnimation
argument_list|(
argument|int speed
argument_list|,
argument|QObject *target
argument_list|)
block|;
name|int
name|animationStep
argument_list|()
specifier|const
block|;
name|int
name|progressStep
argument_list|(
argument|int width
argument_list|)
specifier|const
block|;
name|int
name|speed
argument_list|()
specifier|const
block|;
name|void
name|setSpeed
argument_list|(
argument|int speed
argument_list|)
block|;
name|protected
operator|:
name|bool
name|isUpdateNeeded
argument_list|()
specifier|const
block|;
name|private
operator|:
name|int
name|_speed
block|;
name|mutable
name|int
name|_step
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNumberStyleAnimation
range|:
name|public
name|QStyleAnimation
block|{
name|Q_OBJECT
name|public
operator|:
name|QNumberStyleAnimation
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|qreal
name|startValue
argument_list|()
specifier|const
block|;
name|void
name|setStartValue
argument_list|(
argument|qreal value
argument_list|)
block|;
name|qreal
name|endValue
argument_list|()
specifier|const
block|;
name|void
name|setEndValue
argument_list|(
argument|qreal value
argument_list|)
block|;
name|qreal
name|currentValue
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|isUpdateNeeded
argument_list|()
specifier|const
block|;
name|private
operator|:
name|qreal
name|_start
block|;
name|qreal
name|_end
block|;
name|mutable
name|qreal
name|_prev
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QBlendStyleAnimation
range|:
name|public
name|QStyleAnimation
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Type
block|{
name|Transition
block|,
name|Pulse
block|}
block|;
name|QBlendStyleAnimation
argument_list|(
argument|Type type
argument_list|,
argument|QObject *target
argument_list|)
block|;
name|QImage
name|startImage
argument_list|()
specifier|const
block|;
name|void
name|setStartImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|QImage
name|endImage
argument_list|()
specifier|const
block|;
name|void
name|setEndImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|QImage
name|currentImage
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|void
name|updateCurrentTime
argument_list|(
argument|int time
argument_list|)
block|;
name|private
operator|:
name|Type
name|_type
block|;
name|QImage
name|_start
block|;
name|QImage
name|_end
block|;
name|QImage
name|_current
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
comment|// QSTYLEANIMATION_P_H
end_comment
end_unit
