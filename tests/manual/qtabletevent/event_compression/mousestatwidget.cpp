begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mousestatwidget.h"
end_include
begin_include
include|#
directive|include
file|<QTabletEvent>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QTextOption>
end_include
begin_include
include|#
directive|include
file|<QTest>
end_include
begin_constructor
DECL|function|MouseStatWidget
name|MouseStatWidget
operator|::
name|MouseStatWidget
parameter_list|(
name|bool
name|acceptTabletEvent
parameter_list|)
member_init_list|:
name|acceptTabletEvent
argument_list|(
name|acceptTabletEvent
argument_list|)
member_init_list|,
name|receivedMouseEventCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|receivedMouseEventCountToPaint
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|receivedTabletEventCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|receivedTabletEventCountToPaint
argument_list|(
literal|0
argument_list|)
block|{
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|tabletEvent
name|void
name|MouseStatWidget
operator|::
name|tabletEvent
parameter_list|(
name|QTabletEvent
modifier|*
name|event
parameter_list|)
block|{
operator|++
name|receivedTabletEventCount
expr_stmt|;
if|if
condition|(
name|acceptTabletEvent
condition|)
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
else|else
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
comment|// make sure the event loop is slow
name|QTest
operator|::
name|qSleep
argument_list|(
literal|15
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|MouseStatWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
operator|++
name|receivedMouseEventCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|MouseStatWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|receivedMouseEventCountToPaint
operator|=
name|receivedMouseEventCount
expr_stmt|;
name|receivedTabletEventCountToPaint
operator|=
name|receivedTabletEventCount
expr_stmt|;
name|receivedMouseEventCount
operator|=
literal|0
expr_stmt|;
name|receivedTabletEventCount
operator|=
literal|0
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|MouseStatWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|text
decl_stmt|;
name|text
operator|<<
operator|(
operator|(
name|acceptTabletEvent
operator|)
condition|?
literal|" - tablet events accepted - "
else|:
literal|" - tablet events ignored - "
operator|)
expr_stmt|;
name|text
operator|<<
name|QString
argument_list|(
literal|"Number of tablet events received in the last second: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|receivedTabletEventCountToPaint
argument_list|)
argument_list|)
expr_stmt|;
name|text
operator|<<
name|QString
argument_list|(
literal|"Number of mouse events received in the last second: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|receivedMouseEventCountToPaint
argument_list|)
argument_list|)
expr_stmt|;
name|QTextOption
name|textOption
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
decl_stmt|;
name|textOption
operator|.
name|setWrapMode
argument_list|(
name|QTextOption
operator|::
name|WrapAtWordBoundaryOrAnywhere
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|rect
argument_list|()
argument_list|,
name|text
operator|.
name|join
argument_list|(
literal|"\n"
argument_list|)
argument_list|,
name|textOption
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
