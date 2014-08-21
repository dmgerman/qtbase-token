begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFLICKGESTURE_P_H
end_ifndef
begin_define
DECL|macro|QFLICKGESTURE_P_H
define|#
directive|define
name|QFLICKGESTURE_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qgesturerecognizer.h"
end_include
begin_include
include|#
directive|include
file|"private/qgesture_p.h"
end_include
begin_include
include|#
directive|include
file|"qscroller.h"
end_include
begin_include
include|#
directive|include
file|"qscopedpointer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFlickGesturePrivate
name|class
name|QFlickGesturePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsItem
name|class
name|QGraphicsItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFlickGesture
range|:
name|public
name|QGesture
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFlickGesture
argument_list|)
name|public
operator|:
name|QFlickGesture
argument_list|(
argument|QObject *receiver
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QFlickGesture
argument_list|()
block|;
name|friend
name|class
name|QFlickGestureRecognizer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|PressDelayHandler
name|class
name|PressDelayHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFlickGesturePrivate
range|:
name|public
name|QGesturePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFlickGesture
argument_list|)
name|public
operator|:
name|QFlickGesturePrivate
argument_list|()
block|;
name|QPointer
operator|<
name|QObject
operator|>
name|receiver
block|;
name|QScroller
operator|*
name|receiverScroller
block|;
name|Qt
operator|::
name|MouseButton
name|button
block|;
comment|// NoButton == Touch
name|bool
name|macIgnoreWheel
block|;
specifier|static
name|PressDelayHandler
operator|*
name|pressDelayHandler
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFlickGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QFlickGestureRecognizer
argument_list|(
argument|Qt::MouseButton button
argument_list|)
block|;
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
block|;
name|private
operator|:
name|Qt
operator|::
name|MouseButton
name|button
block|;
comment|// NoButton == Touch
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
begin_comment
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFLICKGESTURE_P_H
end_comment
end_unit
