begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MOUSESTATWIDGET_H
end_ifndef
begin_define
DECL|macro|MOUSESTATWIDGET_H
define|#
directive|define
name|MOUSESTATWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
DECL|variable|QTabletEvent
name|class
name|QTabletEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPaintEvent
name|class
name|QPaintEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MouseStatWidget
range|:
name|public
name|QWidget
block|{
name|public
operator|:
name|MouseStatWidget
argument_list|(
argument|bool acceptTabletEvent = true
argument_list|)
block|;
name|protected
operator|:
name|void
name|tabletEvent
argument_list|(
name|QTabletEvent
operator|*
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|private
operator|:
specifier|const
name|bool
name|acceptTabletEvent
block|;
name|int
name|receivedMouseEventCount
block|;
name|int
name|receivedMouseEventCountToPaint
block|;
name|int
name|receivedTabletEventCount
block|;
name|int
name|receivedTabletEventCountToPaint
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MOUSESTATWIDGET_H
end_comment
end_unit
