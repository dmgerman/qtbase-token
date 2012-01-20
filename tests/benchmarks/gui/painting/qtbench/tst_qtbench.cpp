begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|"benchmarktests.h"
end_include
begin_class
DECL|class|BenchWidget
class|class
name|BenchWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|BenchWidget
parameter_list|(
name|Benchmark
modifier|*
name|benchmark
parameter_list|)
constructor_decl|;
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
function_decl|;
DECL|function|done
name|bool
name|done
parameter_list|()
specifier|const
block|{
return|return
name|m_done
return|;
block|}
DECL|function|result
name|qreal
name|result
parameter_list|()
specifier|const
block|{
return|return
name|m_result
return|;
block|}
public|public:
DECL|member|timer
name|QTime
name|timer
decl_stmt|;
DECL|member|m_benchmark
name|Benchmark
modifier|*
name|m_benchmark
decl_stmt|;
DECL|member|m_done
name|bool
name|m_done
decl_stmt|;
DECL|member|m_result
name|qreal
name|m_result
decl_stmt|;
DECL|member|m_total
name|uint
name|m_total
decl_stmt|;
DECL|member|m_iteration
name|uint
name|m_iteration
decl_stmt|;
DECL|member|iterationTimes
name|QVector
argument_list|<
name|uint
argument_list|>
name|iterationTimes
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|paintEvent
name|void
name|BenchWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|m_done
condition|)
return|return;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_benchmark
operator|->
name|begin
argument_list|(
operator|&
name|p
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|PaintingRectAdjuster
name|adjuster
decl_stmt|;
name|adjuster
operator|.
name|setNewBenchmark
argument_list|(
name|m_benchmark
argument_list|)
expr_stmt|;
name|adjuster
operator|.
name|reset
argument_list|(
name|rect
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
operator|++
name|i
control|)
name|m_benchmark
operator|->
name|draw
argument_list|(
operator|&
name|p
argument_list|,
name|adjuster
operator|.
name|newPaintingRect
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|m_benchmark
operator|->
name|end
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
operator|++
name|m_iteration
expr_stmt|;
name|uint
name|currentElapsed
init|=
name|timer
operator|.
name|isNull
argument_list|()
condition|?
literal|0
else|:
name|timer
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|timer
operator|.
name|restart
argument_list|()
expr_stmt|;
name|m_total
operator|+=
name|currentElapsed
expr_stmt|;
comment|// warm up for at most 5 iterations or half a second
if|if
condition|(
name|m_iteration
operator|>=
literal|5
operator|||
name|m_total
operator|>=
literal|500
condition|)
block|{
name|iterationTimes
operator|<<
name|currentElapsed
expr_stmt|;
if|if
condition|(
name|iterationTimes
operator|.
name|size
argument_list|()
operator|>=
literal|5
condition|)
block|{
name|qreal
name|mean
init|=
literal|0
decl_stmt|;
name|qreal
name|stddev
init|=
literal|0
decl_stmt|;
name|uint
name|min
init|=
name|INT_MAX
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterationTimes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|mean
operator|+=
name|iterationTimes
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|min
operator|=
name|qMin
argument_list|(
name|min
argument_list|,
name|iterationTimes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|mean
operator|/=
name|qreal
argument_list|(
name|iterationTimes
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterationTimes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|delta
init|=
name|iterationTimes
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|-
name|mean
decl_stmt|;
name|stddev
operator|+=
name|delta
operator|*
name|delta
expr_stmt|;
block|}
name|stddev
operator|=
name|qSqrt
argument_list|(
name|stddev
operator|/
name|iterationTimes
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|stddev
operator|=
literal|100
operator|*
name|stddev
operator|/
name|mean
expr_stmt|;
comment|// do 50 iterations, break earlier if we spend more than 5 seconds or have a low std deviation after 2 seconds
if|if
condition|(
name|iterationTimes
operator|.
name|size
argument_list|()
operator|>=
literal|50
operator|||
name|m_total
operator|>=
literal|5000
operator|||
operator|(
name|m_total
operator|>=
literal|2000
operator|&&
name|stddev
operator|<
literal|4
operator|)
condition|)
block|{
name|m_result
operator|=
name|min
expr_stmt|;
name|m_done
operator|=
literal|true
expr_stmt|;
return|return;
block|}
block|}
block|}
block|}
end_function
begin_constructor
DECL|function|BenchWidget
name|BenchWidget
operator|::
name|BenchWidget
parameter_list|(
name|Benchmark
modifier|*
name|benchmark
parameter_list|)
member_init_list|:
name|m_benchmark
argument_list|(
name|benchmark
argument_list|)
member_init_list|,
name|m_done
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_result
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_total
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_iteration
argument_list|(
literal|0
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|benchmark
operator|->
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|tst_QtBench
class|class
name|tst_QtBench
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qtBench
parameter_list|()
function_decl|;
name|void
name|qtBench_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|makeString
name|QString
name|makeString
parameter_list|(
name|int
name|length
parameter_list|)
block|{
specifier|const
name|char
name|chars
index|[]
init|=
literal|"abcd efgh ijkl mnop qrst uvwx yz!$. ABCD 1234"
decl_stmt|;
name|int
name|len
init|=
name|strlen
argument_list|(
name|chars
argument_list|)
decl_stmt|;
name|QString
name|ret
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|length
condition|;
name|j
operator|++
control|)
block|{
name|ret
operator|+=
name|QChar
argument_list|(
name|chars
index|[
operator|(
name|j
operator|*
literal|97
operator|)
operator|%
name|len
index|]
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|qtBench_data
name|void
name|tst_QtBench
operator|::
name|qtBench_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
literal|"benchmark"
argument_list|)
expr_stmt|;
name|QString
name|shortString
init|=
name|makeString
argument_list|(
literal|5
argument_list|)
decl_stmt|;
name|QString
name|middleString
init|=
name|makeString
argument_list|(
literal|50
argument_list|)
decl_stmt|;
name|QString
name|longString
init|=
name|makeString
argument_list|(
literal|35
argument_list|)
operator|+
literal|"\n"
operator|+
name|makeString
argument_list|(
literal|45
argument_list|)
operator|+
literal|"\n"
operator|+
name|makeString
argument_list|(
literal|75
argument_list|)
decl_stmt|;
name|QString
name|superLongString
init|=
literal|"Lorem ipsum dolor sit am\n"
literal|"et, consectetur adipisci\n"
literal|"ng elit. Integer mi leo,\n"
literal|"interdum ut congue at, p\n"
literal|"ulvinar et tellus. Quisq\n"
literal|"ue pretium eleifend laci\n"
literal|"nia. Ut semper gravida l\n"
literal|"ectus in commodo. Vestib\n"
literal|"ulum pharetra arcu in en\n"
literal|"im ultrices hendrerit. P\n"
literal|"ellentesque habitant mor\n"
literal|"bi tristique senectus et\n"
literal|"netus et malesuada fames\n"
literal|"ac turpis egestas. Ut er\n"
literal|"os sem, feugiat in eleme\n"
literal|"ntum in, porta sit amet \n"
literal|"neque. Fusce mi tellus, \n"
literal|"congue non dapibus eget,\n"
literal|"pharetra quis quam. Duis\n"
literal|"dui massa, pulvinar ac s\n"
literal|"odales pharetra, dictum \n"
literal|"in enim. Phasellus a nis\n"
literal|"i erat, sed pellentesque\n"
literal|"mi. Curabitur sed."
decl_stmt|;
name|QList
argument_list|<
name|Benchmark
modifier|*
argument_list|>
name|benchmarks
decl_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|PainterMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|PainterMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|PainterMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|PainterMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|PainterQPointMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|PainterQPointMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|PainterQPointMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|PainterQPointMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|PixmapMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|PixmapMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|PixmapMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|PixmapMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|StaticTextMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|StaticTextMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|StaticTextMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|StaticTextMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|StaticTextWithMaximumSizeMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|StaticTextWithMaximumSizeMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|StaticTextWithMaximumSizeMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|StaticTextWithMaximumSizeMode
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|shortString
argument_list|,
name|DrawText
operator|::
name|StaticTextBackendOptimizations
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|middleString
argument_list|,
name|DrawText
operator|::
name|StaticTextBackendOptimizations
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|longString
argument_list|,
name|DrawText
operator|::
name|StaticTextBackendOptimizations
argument_list|)
operator|)
expr_stmt|;
name|benchmarks
operator|<<
operator|(
operator|new
name|DrawText
argument_list|(
name|superLongString
argument_list|,
name|DrawText
operator|::
name|StaticTextBackendOptimizations
argument_list|)
operator|)
expr_stmt|;
foreach|foreach
control|(
name|Benchmark
modifier|*
name|benchmark
decl|,
name|benchmarks
control|)
name|QTest
operator|::
name|newRow
argument_list|(
name|qPrintable
argument_list|(
name|benchmark
operator|->
name|name
argument_list|()
argument_list|)
argument_list|)
operator|<<
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
name|benchmark
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qtBench
name|void
name|tst_QtBench
operator|::
name|qtBench
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|void
operator|*
argument_list|,
name|benchmark
argument_list|)
expr_stmt|;
name|BenchWidget
name|widget
argument_list|(
cast|reinterpret_cast
argument_list|<
name|Benchmark
operator|*
argument_list|>
argument_list|(
name|benchmark
argument_list|)
argument_list|)
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|widget
operator|.
name|done
argument_list|()
condition|)
block|{
name|widget
operator|.
name|update
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
name|QTest
operator|::
name|setBenchmarkResult
argument_list|(
name|widget
operator|.
name|result
argument_list|()
argument_list|,
name|QTest
operator|::
name|WalltimeMilliseconds
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QtBench
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtbench.moc"
end_include
end_unit
