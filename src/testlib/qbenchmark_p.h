begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBENCHMARK_P_H
end_ifndef
begin_define
DECL|macro|QBENCHMARK_P_H
define|#
directive|define
name|QBENCHMARK_P_H
end_define
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
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
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
name|Q_OS_MAC
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PROCESS
argument_list|)
end_if
begin_define
DECL|macro|QTESTLIB_USE_VALGRIND
define|#
directive|define
name|QTESTLIB_USE_VALGRIND
end_define
begin_else
else|#
directive|else
end_else
begin_undef
DECL|macro|QTESTLIB_USE_VALGRIND
undef|#
directive|undef
name|QTESTLIB_USE_VALGRIND
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_LINUXBASE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_if
begin_define
DECL|macro|QTESTLIB_USE_PERF_EVENTS
define|#
directive|define
name|QTESTLIB_USE_PERF_EVENTS
end_define
begin_else
else|#
directive|else
end_else
begin_undef
DECL|macro|QTESTLIB_USE_PERF_EVENTS
undef|#
directive|undef
name|QTESTLIB_USE_PERF_EVENTS
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmeasurement_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtest_global.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QTESTLIB_USE_VALGRIND
end_ifdef
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkvalgrind_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QTESTLIB_USE_PERF_EVENTS
end_ifdef
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkperfevents_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkevent_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QBenchmarkContext
struct|struct
name|QBenchmarkContext
block|{
comment|// None of the strings below are assumed to contain commas (see toString() below)
DECL|member|slotName
name|QString
name|slotName
decl_stmt|;
DECL|member|tag
name|QString
name|tag
decl_stmt|;
comment|// from _data() function
DECL|member|checkpointIndex
name|int
name|checkpointIndex
decl_stmt|;
DECL|function|toString
name|QString
name|toString
argument_list|()
specifier|const
block|{
name|QString
name|s
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1,%2,%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|slotName
argument_list|)
operator|.
name|arg
argument_list|(
name|tag
argument_list|)
operator|.
name|arg
argument_list|(
name|checkpointIndex
argument_list|)
block|;
return|return
name|s
return|;
block|}
DECL|function|QBenchmarkContext
name|QBenchmarkContext
argument_list|()
operator|:
name|checkpointIndex
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QBenchmarkContext
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QBenchmarkResult
block|{
name|public
label|:
name|QBenchmarkContext
name|context
decl_stmt|;
name|qreal
name|value
decl_stmt|;
name|int
name|iterations
decl_stmt|;
name|QTest
operator|::
name|QBenchmarkMetric
name|metric
expr_stmt|;
name|bool
name|setByMacro
decl_stmt|;
name|bool
name|valid
decl_stmt|;
name|QBenchmarkResult
argument_list|()
operator|:
name|value
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|iterations
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|metric
argument_list|(
name|QTest
operator|::
name|FramesPerSecond
argument_list|)
operator|,
name|setByMacro
argument_list|(
name|true
argument_list|)
operator|,
name|valid
argument_list|(
argument|false
argument_list|)
block|{ }
name|QBenchmarkResult
argument_list|(
argument|const QBenchmarkContext&context
argument_list|,
argument|const qreal value
argument_list|,
argument|const int iterations
argument_list|,
argument|QTest::QBenchmarkMetric metric
argument_list|,
argument|bool setByMacro
argument_list|)
operator|:
name|context
argument_list|(
name|context
argument_list|)
operator|,
name|value
argument_list|(
name|value
argument_list|)
operator|,
name|iterations
argument_list|(
name|iterations
argument_list|)
operator|,
name|metric
argument_list|(
name|metric
argument_list|)
operator|,
name|setByMacro
argument_list|(
name|setByMacro
argument_list|)
operator|,
name|valid
argument_list|(
argument|true
argument_list|)
block|{ }
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QBenchmarkResult
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|value
operator|/
name|iterations
operator|)
operator|<
operator|(
name|other
operator|.
name|value
operator|/
name|other
operator|.
name|iterations
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QBenchmarkResult
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*     The QBenchmarkGlobalData class stores global benchmark-related data.     QBenchmarkGlobalData:current is created at the beginning of qExec()     and cleared at the end. */
end_comment
begin_decl_stmt
name|class
name|Q_TESTLIB_EXPORT
name|QBenchmarkGlobalData
block|{
name|public
label|:
specifier|static
name|QBenchmarkGlobalData
modifier|*
name|current
decl_stmt|;
name|QBenchmarkGlobalData
argument_list|()
expr_stmt|;
operator|~
name|QBenchmarkGlobalData
argument_list|()
expr_stmt|;
enum|enum
name|Mode
block|{
name|WallTime
block|,
name|CallgrindParentProcess
block|,
name|CallgrindChildProcess
block|,
name|PerfCounter
block|,
name|TickCounter
block|,
name|EventCounter
block|}
enum|;
name|void
name|setMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
function_decl|;
name|Mode
name|mode
argument_list|()
specifier|const
block|{
return|return
name|mode_
return|;
block|}
name|QBenchmarkMeasurerBase
modifier|*
name|createMeasurer
parameter_list|()
function_decl|;
name|int
name|adjustMedianIterationCount
parameter_list|()
function_decl|;
name|QBenchmarkMeasurerBase
modifier|*
name|measurer
decl_stmt|;
name|QBenchmarkContext
name|context
decl_stmt|;
name|int
name|walltimeMinimum
decl_stmt|;
name|int
name|iterationCount
decl_stmt|;
name|int
name|medianIterationCount
decl_stmt|;
name|bool
name|createChart
decl_stmt|;
name|bool
name|verboseOutput
decl_stmt|;
name|QString
name|callgrindOutFileBase
decl_stmt|;
name|int
name|minimumTotal
decl_stmt|;
name|private
label|:
name|Mode
name|mode_
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*     The QBenchmarkTestMethodData class stores all benchmark-related data     for the current test case. QBenchmarkTestMethodData:current is     created at the beginning of qInvokeTestMethod() and cleared at     the end. */
end_comment
begin_decl_stmt
name|class
name|Q_TESTLIB_EXPORT
name|QBenchmarkTestMethodData
block|{
name|public
label|:
specifier|static
name|QBenchmarkTestMethodData
modifier|*
name|current
decl_stmt|;
name|QBenchmarkTestMethodData
argument_list|()
expr_stmt|;
operator|~
name|QBenchmarkTestMethodData
argument_list|()
expr_stmt|;
comment|// Called once for each data row created by the _data function,
comment|// before and after calling the test function itself.
name|void
name|beginDataRun
parameter_list|()
function_decl|;
name|void
name|endDataRun
parameter_list|()
function_decl|;
name|bool
name|isBenchmark
argument_list|()
specifier|const
block|{
return|return
name|result
operator|.
name|valid
return|;
block|}
name|bool
name|resultsAccepted
argument_list|()
specifier|const
block|{
return|return
name|resultAccepted
return|;
block|}
name|int
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
function_decl|;
name|void
name|setResult
argument_list|(
name|qreal
name|value
argument_list|,
name|QTest
operator|::
name|QBenchmarkMetric
name|metric
argument_list|,
name|bool
name|setByMacro
operator|=
name|true
argument_list|)
decl_stmt|;
name|QBenchmarkResult
name|result
decl_stmt|;
name|bool
name|resultAccepted
decl_stmt|;
name|bool
name|runOnce
decl_stmt|;
name|int
name|iterationCount
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// low-level API:
end_comment
begin_decl_stmt
name|namespace
name|QTest
block|{
name|int
name|iterationCount
parameter_list|()
function_decl|;
name|void
name|setIterationCountHint
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|setIterationCount
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
name|Q_TESTLIB_EXPORT
name|void
name|beginBenchmarkMeasurement
parameter_list|()
function_decl|;
name|Q_TESTLIB_EXPORT
name|quint64
name|endBenchmarkMeasurement
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBENCHMARK_H
end_comment
end_unit
