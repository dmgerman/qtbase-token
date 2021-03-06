begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_function
DECL|function|setGeometry
name|void
name|SlowWidget
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|bool
name|reiterate
init|=
literal|false
decl_stmt|;
name|Statistics
modifier|&
name|stats
init|=
operator|*
name|m_stats
decl_stmt|;
if|if
condition|(
name|stats
operator|.
name|relayoutClicked
condition|)
block|{
operator|++
operator|(
name|stats
operator|.
name|setGeometryTracker
index|[
name|this
index|]
operator|)
expr_stmt|;
operator|++
name|stats
operator|.
name|setGeometryCount
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"setGeometryCount:"
operator|<<
name|stats
operator|.
name|setGeometryCount
expr_stmt|;
if|if
condition|(
name|stats
operator|.
name|setGeometryTracker
operator|.
name|count
argument_list|()
operator|==
name|m_window
operator|->
name|m_depthSpinBox
operator|->
name|value
argument_list|()
condition|)
block|{
operator|++
name|stats
operator|.
name|currentBenchmarkIteration
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"currentBenchmarkIteration:"
operator|<<
name|stats
operator|.
name|currentBenchmarkIteration
expr_stmt|;
if|if
condition|(
name|stats
operator|.
name|currentBenchmarkIteration
operator|==
name|m_window
operator|->
name|m_benchmarkIterationsSpinBox
operator|->
name|value
argument_list|()
condition|)
block|{
if|if
condition|(
name|stats
operator|.
name|output
condition|)
name|stats
operator|.
name|output
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"DONE. Elapsed: %1, setGeometryCount: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|stats
operator|.
name|time
operator|.
name|elapsed
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|stats
operator|.
name|setGeometryCount
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|reiterate
operator|=
literal|true
expr_stmt|;
block|}
name|stats
operator|.
name|setGeometryTracker
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
name|QGraphicsWidget
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|reiterate
condition|)
block|{
name|m_window
operator|->
name|doAgain
argument_list|()
expr_stmt|;
comment|//QTimer::singleShot(0, m_window, SLOT(doAgain()));
block|}
block|}
end_function
end_unit
