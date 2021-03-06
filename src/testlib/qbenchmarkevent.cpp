begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkevent_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QBenchmarkEvent
name|QBenchmarkEvent
operator|::
name|QBenchmarkEvent
parameter_list|()
member_init_list|:
name|eventCounter
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBenchmarkEvent
name|QBenchmarkEvent
operator|::
name|~
name|QBenchmarkEvent
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|start
name|void
name|QBenchmarkEvent
operator|::
name|start
parameter_list|()
block|{
name|eventCounter
operator|=
literal|0
expr_stmt|;
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
operator|->
name|installNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkpoint
name|qint64
name|QBenchmarkEvent
operator|::
name|checkpoint
parameter_list|()
block|{
return|return
name|eventCounter
return|;
block|}
end_function
begin_function
DECL|function|stop
name|qint64
name|QBenchmarkEvent
operator|::
name|stop
parameter_list|()
block|{
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
operator|->
name|removeNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
name|eventCounter
return|;
block|}
end_function
begin_comment
comment|// It's very tempting to simply reject a measurement if 0 events
end_comment
begin_comment
comment|// where counted, however that is a possible situation and returning
end_comment
begin_comment
comment|// false here will create a infinite loop. Do not change this.
end_comment
begin_function
DECL|function|isMeasurementAccepted
name|bool
name|QBenchmarkEvent
operator|::
name|isMeasurementAccepted
parameter_list|(
name|qint64
name|measurement
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|measurement
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkEvent
operator|::
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
return|return
name|suggestion
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianCount
name|int
name|QBenchmarkEvent
operator|::
name|adjustMedianCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|suggestion
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|metricType
name|QTest
operator|::
name|QBenchmarkMetric
name|QBenchmarkEvent
operator|::
name|metricType
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|Events
return|;
block|}
end_function
begin_comment
comment|// This could be done in a much better way, this is just the beginning.
end_comment
begin_function
DECL|function|nativeEventFilter
name|bool
name|QBenchmarkEvent
operator|::
name|nativeEventFilter
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|eventType
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|eventCounter
operator|++
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
