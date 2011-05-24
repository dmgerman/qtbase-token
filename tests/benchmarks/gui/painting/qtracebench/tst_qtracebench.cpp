begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<private/qpaintengineex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpaintbuffer_p.h>
end_include
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|ReplayWidget
class|class
name|ReplayWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|ReplayWidget
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
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
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
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
public|public
name|slots
public|:
name|void
name|updateRect
parameter_list|()
function_decl|;
public|public:
DECL|member|updates
name|QList
argument_list|<
name|QRegion
argument_list|>
name|updates
decl_stmt|;
DECL|member|buffer
name|QPaintBuffer
name|buffer
decl_stmt|;
DECL|member|currentFrame
name|int
name|currentFrame
decl_stmt|;
DECL|member|currentIteration
name|int
name|currentIteration
decl_stmt|;
DECL|member|timer
name|QTime
name|timer
decl_stmt|;
DECL|member|visibleUpdates
name|QList
argument_list|<
name|uint
argument_list|>
name|visibleUpdates
decl_stmt|;
DECL|member|iterationTimes
name|QList
argument_list|<
name|uint
argument_list|>
name|iterationTimes
decl_stmt|;
DECL|member|filename
name|QString
name|filename
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
block|}
class|;
end_class
begin_function
DECL|function|updateRect
name|void
name|ReplayWidget
operator|::
name|updateRect
parameter_list|()
block|{
if|if
condition|(
operator|!
name|visibleUpdates
operator|.
name|isEmpty
argument_list|()
condition|)
name|update
argument_list|(
name|updates
operator|.
name|at
argument_list|(
name|visibleUpdates
operator|.
name|at
argument_list|(
name|currentFrame
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|ReplayWidget
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
comment|// if partial updates don't work
comment|// p.setClipRegion(frames.at(currentFrame).updateRegion);
name|buffer
operator|.
name|draw
argument_list|(
operator|&
name|p
argument_list|,
name|visibleUpdates
operator|.
name|at
argument_list|(
name|currentFrame
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|currentFrame
expr_stmt|;
if|if
condition|(
name|currentFrame
operator|>=
name|visibleUpdates
operator|.
name|size
argument_list|()
condition|)
block|{
name|currentFrame
operator|=
literal|0
expr_stmt|;
operator|++
name|currentIteration
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
name|currentIteration
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
name|qSort
argument_list|(
name|iterationTimes
operator|.
name|begin
argument_list|()
argument_list|,
name|iterationTimes
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|uint
name|median
init|=
name|iterationTimes
operator|.
name|at
argument_list|(
name|iterationTimes
operator|.
name|size
argument_list|()
operator|/
literal|2
argument_list|)
decl_stmt|;
name|stddev
operator|=
literal|100
operator|*
name|stddev
operator|/
name|mean
expr_stmt|;
comment|// do 100 iterations, break earlier if we spend more than 5 seconds or have a low std deviation after 2 seconds
if|if
condition|(
name|iterationTimes
operator|.
name|size
argument_list|()
operator|>=
literal|100
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
name|printf
argument_list|(
literal|"%s, iterations: %d, frames: %d, min(ms): %d, median(ms): %d, stddev: %f %%, max(fps): %f\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename
argument_list|)
argument_list|,
name|iterationTimes
operator|.
name|size
argument_list|()
argument_list|,
name|visibleUpdates
operator|.
name|size
argument_list|()
argument_list|,
name|min
argument_list|,
name|median
argument_list|,
name|stddev
argument_list|,
literal|1000.
operator|*
name|visibleUpdates
operator|.
name|size
argument_list|()
operator|/
name|min
argument_list|)
expr_stmt|;
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
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|ReplayWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
comment|/* event */
parameter_list|)
block|{
name|visibleUpdates
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QRect
name|bounds
init|=
name|rect
argument_list|()
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
name|updates
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|updates
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|intersects
argument_list|(
name|bounds
argument_list|)
condition|)
name|visibleUpdates
operator|<<
name|i
expr_stmt|;
block|}
if|if
condition|(
name|visibleUpdates
operator|.
name|size
argument_list|()
operator|!=
name|updates
operator|.
name|size
argument_list|()
condition|)
name|printf
argument_list|(
literal|"Warning: skipped %d frames due to limited resolution\n"
argument_list|,
name|updates
operator|.
name|size
argument_list|()
operator|-
name|visibleUpdates
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|ReplayWidget
name|ReplayWidget
operator|::
name|ReplayWidget
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename_
parameter_list|)
member_init_list|:
name|currentFrame
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentIteration
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|filename
argument_list|(
name|filename_
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
block|{
name|setWindowTitle
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"Failed to load input file '%s'\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename_
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|QDataStream
name|in
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|uint
name|size
decl_stmt|;
name|in
operator|.
name|readBytes
argument_list|(
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|bool
name|isTraceFile
init|=
name|size
operator|>=
literal|7
operator|&&
name|qstrncmp
argument_list|(
name|data
argument_list|,
literal|"qttrace"
argument_list|,
literal|7
argument_list|)
operator|==
literal|0
decl_stmt|;
name|uint
name|version
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|size
operator|==
literal|9
operator|&&
name|qstrncmp
argument_list|(
name|data
argument_list|,
literal|"qttraceV2"
argument_list|,
literal|9
argument_list|)
operator|==
literal|0
condition|)
block|{
name|in
operator|.
name|setFloatingPointPrecision
argument_list|(
name|QDataStream
operator|::
name|SinglePrecision
argument_list|)
expr_stmt|;
name|in
operator|>>
name|version
expr_stmt|;
block|}
operator|delete
index|[]
name|data
expr_stmt|;
if|if
condition|(
operator|!
name|isTraceFile
condition|)
block|{
name|printf
argument_list|(
literal|"File '%s' is not a trace file\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename_
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|in
operator|>>
name|buffer
operator|>>
name|updates
expr_stmt|;
name|resize
argument_list|(
name|buffer
operator|.
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|tst_QTraceBench
class|class
name|tst_QTraceBench
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|trace
parameter_list|()
function_decl|;
name|void
name|trace_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|prefix
argument_list|(
literal|":/traces/"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|trace_data
name|void
name|tst_QTraceBench
operator|::
name|trace_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"basicdrawing"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"basicdrawing.trace"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"webkit"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"webkit.trace"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"creator"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"creator.trace"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"textedit"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"textedit.trace"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"qmlphoneconcept"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"qmlphoneconcept.trace"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"qmlsamegame"
argument_list|)
operator|<<
operator|(
name|prefix
operator|+
literal|"qmlsamegame.trace"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|trace
name|void
name|tst_QTraceBench
operator|::
name|trace
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|exists
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Missing file"
operator|<<
name|filename
expr_stmt|;
return|return;
block|}
name|ReplayWidget
name|widget
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
operator|.
name|updates
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"No trace updates"
operator|<<
name|filename
expr_stmt|;
return|return;
block|}
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
name|updateRect
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
argument|tst_QTraceBench
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtracebench.moc"
end_include
end_unit
