begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GESTURE_H
end_ifndef
begin_define
DECL|macro|GESTURE_H
define|#
directive|define
name|GESTURE_H
end_define
begin_include
include|#
directive|include
file|<QGestureRecognizer>
end_include
begin_include
include|#
directive|include
file|<QGesture>
end_include
begin_decl_stmt
name|class
name|ThreeFingerSlideGesture
range|:
name|public
name|QGesture
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
name|Qt
operator|::
name|GestureType
name|Type
block|;
name|ThreeFingerSlideGesture
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QGesture
argument_list|(
argument|parent
argument_list|)
block|{ }
name|bool
name|gestureFired
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ThreeFingerSlideGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|private
operator|:
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|RotateGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|RotateGestureRecognizer
argument_list|()
block|;
name|private
operator|:
name|QGesture
operator|*
name|create
argument_list|(
name|QObject
operator|*
name|target
argument_list|)
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
name|QGesture
operator|*
name|state
argument_list|,
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|reset
argument_list|(
name|QGesture
operator|*
name|state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GESTURE_H
end_comment
end_unit
