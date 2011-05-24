begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANIMATIONMANAGER_H
end_ifndef
begin_define
DECL|macro|ANIMATIONMANAGER_H
define|#
directive|define
name|ANIMATIONMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|AnimationManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|AnimationManager
argument_list|()
block|;
name|void
name|registerAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|anim
argument_list|)
block|;
name|void
name|unregisterAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|anim
argument_list|)
block|;
name|void
name|unregisterAllAnimations
argument_list|()
block|;
specifier|static
name|AnimationManager
operator|*
name|self
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|pauseAll
argument_list|()
block|;
name|void
name|resumeAll
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|unregisterAnimation_helper
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
block|;
name|private
operator|:
specifier|static
name|AnimationManager
operator|*
name|instance
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANIMATIONMANAGER_H
end_comment
end_unit
