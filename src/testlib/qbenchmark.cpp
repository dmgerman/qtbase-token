begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/qbenchmark.h>
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
file|<QtCore/qprocess.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|current
name|QBenchmarkGlobalData
modifier|*
name|QBenchmarkGlobalData
operator|::
name|current
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QBenchmarkGlobalData
name|QBenchmarkGlobalData
operator|::
name|QBenchmarkGlobalData
parameter_list|()
member_init_list|:
name|measurer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|walltimeMinimum
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|iterationCount
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|medianIterationCount
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|createChart
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|verboseOutput
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|minimumTotal
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|mode_
argument_list|(
name|WallTime
argument_list|)
block|{
name|setMode
argument_list|(
name|mode_
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QBenchmarkGlobalData
name|QBenchmarkGlobalData
operator|::
name|~
name|QBenchmarkGlobalData
parameter_list|()
block|{
operator|delete
name|measurer
expr_stmt|;
name|QBenchmarkGlobalData
operator|::
name|current
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setMode
name|void
name|QBenchmarkGlobalData
operator|::
name|setMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
block|{
name|mode_
operator|=
name|mode
expr_stmt|;
if|if
condition|(
name|measurer
condition|)
operator|delete
name|measurer
expr_stmt|;
name|measurer
operator|=
name|createMeasurer
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createMeasurer
name|QBenchmarkMeasurerBase
modifier|*
name|QBenchmarkGlobalData
operator|::
name|createMeasurer
parameter_list|()
block|{
name|QBenchmarkMeasurerBase
modifier|*
name|measurer
init|=
literal|0
decl_stmt|;
if|if
condition|(
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|QTESTLIB_USE_VALGRIND
block|}
elseif|else
if|if
condition|(
name|mode_
operator|==
name|CallgrindChildProcess
operator|||
name|mode_
operator|==
name|CallgrindParentProcess
condition|)
block|{
name|measurer
operator|=
operator|new
name|QBenchmarkCallgrindMeasurer
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QTESTLIB_USE_PERF_EVENTS
block|}
elseif|else
if|if
condition|(
name|mode_
operator|==
name|PerfCounter
condition|)
block|{
name|measurer
operator|=
operator|new
name|QBenchmarkPerfEventsMeasurer
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_TICK_COUNTER
block|}
elseif|else
if|if
condition|(
name|mode_
operator|==
name|TickCounter
condition|)
block|{
name|measurer
operator|=
operator|new
name|QBenchmarkTickMeasurer
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|mode_
operator|==
name|EventCounter
condition|)
block|{
name|measurer
operator|=
operator|new
name|QBenchmarkEvent
expr_stmt|;
block|}
else|else
block|{
name|measurer
operator|=
operator|new
name|QBenchmarkTimeMeasurer
expr_stmt|;
block|}
name|measurer
operator|->
name|init
argument_list|()
expr_stmt|;
return|return
name|measurer
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianIterationCount
name|int
name|QBenchmarkGlobalData
operator|::
name|adjustMedianIterationCount
parameter_list|()
block|{
if|if
condition|(
name|medianIterationCount
operator|!=
operator|-
literal|1
condition|)
block|{
return|return
name|medianIterationCount
return|;
block|}
else|else
block|{
return|return
name|measurer
operator|->
name|adjustMedianCount
argument_list|(
literal|1
argument_list|)
return|;
block|}
block|}
end_function
begin_decl_stmt
DECL|member|current
name|QBenchmarkTestMethodData
modifier|*
name|QBenchmarkTestMethodData
operator|::
name|current
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QBenchmarkTestMethodData
name|QBenchmarkTestMethodData
operator|::
name|QBenchmarkTestMethodData
parameter_list|()
member_init_list|:
name|resultAccepted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|runOnce
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|iterationCount
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBenchmarkTestMethodData
name|QBenchmarkTestMethodData
operator|::
name|~
name|QBenchmarkTestMethodData
parameter_list|()
block|{
name|QBenchmarkTestMethodData
operator|::
name|current
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|beginDataRun
name|void
name|QBenchmarkTestMethodData
operator|::
name|beginDataRun
parameter_list|()
block|{
name|iterationCount
operator|=
name|adjustIterationCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endDataRun
name|void
name|QBenchmarkTestMethodData
operator|::
name|endDataRun
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkTestMethodData
operator|::
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
comment|// Let the -iterations option override the measurer.
if|if
condition|(
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|iterationCount
operator|!=
operator|-
literal|1
condition|)
block|{
name|iterationCount
operator|=
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|iterationCount
expr_stmt|;
block|}
else|else
block|{
name|iterationCount
operator|=
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|measurer
operator|->
name|adjustIterationCount
argument_list|(
name|suggestion
argument_list|)
expr_stmt|;
block|}
return|return
name|iterationCount
return|;
block|}
end_function
begin_function
DECL|function|setResult
name|void
name|QBenchmarkTestMethodData
operator|::
name|setResult
parameter_list|(
name|qreal
name|value
parameter_list|,
name|QTest
operator|::
name|QBenchmarkMetric
name|metric
parameter_list|,
name|bool
name|setByMacro
parameter_list|)
block|{
name|bool
name|accepted
init|=
literal|false
decl_stmt|;
comment|// Always accept the result if the iteration count has been
comment|// specified on the command line with -iterations.
if|if
condition|(
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|iterationCount
operator|!=
operator|-
literal|1
condition|)
name|accepted
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|runOnce
operator|||
operator|!
name|setByMacro
condition|)
block|{
name|iterationCount
operator|=
literal|1
expr_stmt|;
name|accepted
operator|=
literal|true
expr_stmt|;
block|}
comment|// Test the result directly without calling the measurer if the minimum time
comment|// has been specified on the command line with -minimumvalue.
elseif|else
if|if
condition|(
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|walltimeMinimum
operator|!=
operator|-
literal|1
condition|)
name|accepted
operator|=
operator|(
name|value
operator|>
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|walltimeMinimum
operator|)
expr_stmt|;
else|else
name|accepted
operator|=
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|measurer
operator|->
name|isMeasurementAccepted
argument_list|(
name|value
argument_list|)
expr_stmt|;
comment|// Accept the result or double the number of iterations.
if|if
condition|(
name|accepted
condition|)
name|resultAccepted
operator|=
literal|true
expr_stmt|;
else|else
name|iterationCount
operator|*=
literal|2
expr_stmt|;
name|this
operator|->
name|result
operator|=
name|QBenchmarkResult
argument_list|(
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|context
argument_list|,
name|value
argument_list|,
name|iterationCount
argument_list|,
name|metric
argument_list|,
name|setByMacro
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QTest::QBenchmarkIterationController     \internal      The QBenchmarkIterationController class is used by the QBENCHMARK macro to     drive the benchmarking loop. It is repsonsible for starting and stopping     the timing measurements as well as calling the result reporting functions. */
end_comment
begin_comment
comment|/*! \internal */
end_comment
begin_constructor
DECL|function|QBenchmarkIterationController
name|QTest
operator|::
name|QBenchmarkIterationController
operator|::
name|QBenchmarkIterationController
parameter_list|(
name|RunMode
name|runMode
parameter_list|)
block|{
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|runMode
operator|==
name|RunOnce
condition|)
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|runOnce
operator|=
literal|true
expr_stmt|;
name|QTest
operator|::
name|beginBenchmarkMeasurement
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QBenchmarkIterationController
name|QTest
operator|::
name|QBenchmarkIterationController
operator|::
name|QBenchmarkIterationController
parameter_list|()
block|{
name|i
operator|=
literal|0
expr_stmt|;
name|QTest
operator|::
name|beginBenchmarkMeasurement
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \internal */
end_comment
begin_destructor
DECL|function|~QBenchmarkIterationController
name|QTest
operator|::
name|QBenchmarkIterationController
operator|::
name|~
name|QBenchmarkIterationController
parameter_list|()
block|{
specifier|const
name|qreal
name|result
init|=
name|QTest
operator|::
name|endBenchmarkMeasurement
argument_list|()
decl_stmt|;
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|setResult
argument_list|(
name|result
argument_list|,
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|measurer
operator|->
name|metricType
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|isDone
name|bool
name|QTest
operator|::
name|QBenchmarkIterationController
operator|::
name|isDone
parameter_list|()
block|{
if|if
condition|(
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|runOnce
condition|)
return|return
name|i
operator|>
literal|0
return|;
return|return
name|i
operator|>=
name|QTest
operator|::
name|iterationCount
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|next
name|void
name|QTest
operator|::
name|QBenchmarkIterationController
operator|::
name|next
parameter_list|()
block|{
operator|++
name|i
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|iterationCount
name|int
name|QTest
operator|::
name|iterationCount
parameter_list|()
block|{
return|return
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|iterationCount
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|setIterationCountHint
name|void
name|QTest
operator|::
name|setIterationCountHint
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|adjustIterationCount
argument_list|(
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|setIterationCount
name|void
name|QTest
operator|::
name|setIterationCount
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|iterationCount
operator|=
name|count
expr_stmt|;
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|resultAccepted
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|beginBenchmarkMeasurement
name|void
name|QTest
operator|::
name|beginBenchmarkMeasurement
parameter_list|()
block|{
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|measurer
operator|->
name|start
argument_list|()
expr_stmt|;
comment|// the clock is ticking after the line above, don't add code here.
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|endBenchmarkMeasurement
name|quint64
name|QTest
operator|::
name|endBenchmarkMeasurement
parameter_list|()
block|{
comment|// the clock is ticking before the line below, don't add code here.
return|return
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|measurer
operator|->
name|stop
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the benchmark result for this test function to \a result.      Use this function if you want to report benchmark results without     using the QBENCHMARK macro. Use \a metric to specify how Qt Test     should interpret the results.      The context for the result will be the test function name and any     data tag from the _data function. This function can only be called     once in each test function, subsequent calls will replace the     earlier reported results.      Note that the -iterations command line argument has no effect     on test functions without the QBENCHMARK macro.      \since 4.7 */
end_comment
begin_function
DECL|function|setBenchmarkResult
name|void
name|QTest
operator|::
name|setBenchmarkResult
parameter_list|(
name|qreal
name|result
parameter_list|,
name|QTest
operator|::
name|QBenchmarkMetric
name|metric
parameter_list|)
block|{
name|QBenchmarkTestMethodData
operator|::
name|current
operator|->
name|setResult
argument_list|(
name|result
argument_list|,
name|metric
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|qAverage
typename|typename
name|T
operator|::
name|value_type
name|qAverage
parameter_list|(
specifier|const
name|T
modifier|&
name|container
parameter_list|)
block|{
typename|typename
name|T
operator|::
name|const_iterator
name|it
init|=
name|container
operator|.
name|constBegin
argument_list|()
decl_stmt|;
typename|typename
name|T
operator|::
name|const_iterator
name|end
init|=
name|container
operator|.
name|constEnd
argument_list|()
decl_stmt|;
typename|typename
name|T
operator|::
name|value_type
name|acc
init|=
typename|typename
name|T
operator|::
name|value_type
argument_list|()
decl_stmt|;
name|int
name|count
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|end
condition|)
block|{
name|acc
operator|+=
operator|*
name|it
expr_stmt|;
operator|++
name|it
expr_stmt|;
operator|++
name|count
expr_stmt|;
block|}
return|return
name|acc
operator|/
name|count
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
