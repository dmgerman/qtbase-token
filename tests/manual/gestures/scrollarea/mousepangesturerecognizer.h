begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MOUSEPANGESTURERECOGNIZER_H
end_ifndef
begin_define
DECL|macro|MOUSEPANGESTURERECOGNIZER_H
define|#
directive|define
name|MOUSEPANGESTURERECOGNIZER_H
end_define
begin_include
include|#
directive|include
file|<QGestureRecognizer>
end_include
begin_decl_stmt
name|class
name|MousePanGestureRecognizer
range|:
name|public
name|QGestureRecognizer
block|{
name|public
operator|:
name|MousePanGestureRecognizer
argument_list|()
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
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MOUSEPANGESTURERECOGNIZER_H
end_comment
end_unit
