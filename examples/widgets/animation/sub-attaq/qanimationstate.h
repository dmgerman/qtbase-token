begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANIMATIONSTATE_H
end_ifndef
begin_define
DECL|macro|QANIMATIONSTATE_H
define|#
directive|define
name|QANIMATIONSTATE_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_STATEMACHINE_SOLUTION
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qstate.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractanimation.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qabstractanimation.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAnimationState
range|:
name|public
name|QState
block|{
name|Q_OBJECT
name|public
operator|:
name|QAnimationState
argument_list|(
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAnimationState
argument_list|()
block|;
name|void
name|setAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|QAbstractAnimation
operator|*
name|animation
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|animationFinished
argument_list|()
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|onExit
argument_list|(
argument|QEvent *
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
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAnimationState
argument_list|)
name|QAbstractAnimation
operator|*
name|m_animation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANIMATIONSTATE_H
end_comment
end_unit
