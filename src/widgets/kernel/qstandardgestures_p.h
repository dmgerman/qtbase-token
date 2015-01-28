begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTANDARDGESTURES_P_H
end_ifndef
begin_define
DECL|macro|QSTANDARDGESTURES_P_H
define|#
directive|define
name|QSTANDARDGESTURES_P_H
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
file|"qgesturerecognizer.h"
end_include
begin_include
include|#
directive|include
file|"private/qgesture_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPanGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|explicit
name|QPanGestureRecognizer
argument_list|(
argument|int pointCount =
literal|2
argument_list|)
operator|:
name|m_pointCount
argument_list|(
argument|pointCount
argument_list|)
block|{}
name|QGesture
operator|*
name|create
argument_list|(
argument|QObject *target
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
argument|QGesture *state
argument_list|,
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|(
argument|QGesture *state
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
specifier|const
name|int
name|m_pointCount
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPinchGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QPinchGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
argument|QObject *target
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
argument|QGesture *state
argument_list|,
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|(
argument|QGesture *state
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QSwipeGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QSwipeGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
argument|QObject *target
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
argument|QGesture *state
argument_list|,
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|(
argument|QGesture *state
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QTapGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
argument|QObject *target
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
argument|QGesture *state
argument_list|,
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|(
argument|QGesture *state
argument_list|)
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTapAndHoldGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|QTapAndHoldGestureRecognizer
argument_list|()
block|;
name|QGesture
operator|*
name|create
argument_list|(
argument|QObject *target
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QGestureRecognizer
operator|::
name|Result
name|recognize
argument_list|(
argument|QGesture *state
argument_list|,
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|(
argument|QGesture *state
argument_list|)
name|Q_DECL_OVERRIDE
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
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTANDARDGESTURES_P_H
end_comment
end_unit
