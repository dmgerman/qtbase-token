begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBENCHMARKMEASUREMENT_P_H
end_ifndef
begin_define
DECL|macro|QBENCHMARKMEASUREMENT_P_H
define|#
directive|define
name|QBENCHMARKMEASUREMENT_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/cycle_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qbenchmark.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QBenchmarkMeasurerBase
block|{
name|public
label|:
name|virtual
operator|~
name|QBenchmarkMeasurerBase
argument_list|()
block|{}
name|virtual
name|void
name|init
argument_list|()
block|{}
name|virtual
name|void
name|start
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|qint64
name|checkpoint
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|qint64
name|stop
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|isMeasurementAccepted
parameter_list|(
name|qint64
name|measurement
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|int
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|int
name|adjustMedianCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|repeatCount
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
name|virtual
name|bool
name|needsWarmupIteration
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|QTest
operator|::
name|QBenchmarkMetric
name|metricType
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QBenchmarkTimeMeasurer
range|:
name|public
name|QBenchmarkMeasurerBase
block|{
name|public
operator|:
name|void
name|start
argument_list|()
block|;
name|qint64
name|checkpoint
argument_list|()
block|;
name|qint64
name|stop
argument_list|()
block|;
name|bool
name|isMeasurementAccepted
argument_list|(
argument|qint64 measurement
argument_list|)
block|;
name|int
name|adjustIterationCount
argument_list|(
argument|int sugestion
argument_list|)
block|;
name|int
name|adjustMedianCount
argument_list|(
argument|int suggestion
argument_list|)
block|;
name|bool
name|needsWarmupIteration
argument_list|()
block|;
name|QTest
operator|::
name|QBenchmarkMetric
name|metricType
argument_list|()
block|;
name|private
operator|:
name|QElapsedTimer
name|time
block|; }
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TICK_COUNTER
end_ifdef
begin_comment
comment|// defined in 3rdparty/cycle_p.h
end_comment
begin_decl_stmt
name|class
name|QBenchmarkTickMeasurer
range|:
name|public
name|QBenchmarkMeasurerBase
block|{
name|public
operator|:
name|void
name|start
argument_list|()
block|;
name|qint64
name|checkpoint
argument_list|()
block|;
name|qint64
name|stop
argument_list|()
block|;
name|bool
name|isMeasurementAccepted
argument_list|(
argument|qint64 measurement
argument_list|)
block|;
name|int
name|adjustIterationCount
argument_list|(
name|int
argument_list|)
block|;
name|int
name|adjustMedianCount
argument_list|(
argument|int suggestion
argument_list|)
block|;
name|bool
name|needsWarmupIteration
argument_list|()
block|;
name|QTest
operator|::
name|QBenchmarkMetric
name|metricType
argument_list|()
block|;
name|private
operator|:
name|CycleCounterTicks
name|startTicks
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
comment|// QBENCHMARKMEASUREMENT_P_H
end_comment
end_unit
