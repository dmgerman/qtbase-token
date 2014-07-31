begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     Returns the clock type that this QElapsedTimer implementation uses.      \sa isMonotonic() */
name|QElapsedTimer
operator|::
name|ClockType
name|QElapsedTimer
operator|::
name|clockType
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
name|SystemTime
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this is a monotonic clock, false otherwise. See the     information on the different clock types to understand which ones are     monotonic.      \sa clockType(), QElapsedTimer::ClockType */
end_comment
begin_function
name|bool
name|QElapsedTimer
operator|::
name|isMonotonic
parameter_list|()
name|Q_DECL_NOTHROW
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Starts this timer. Once started, a timer value can be checked with elapsed() or msecsSinceReference().      Normally, a timer is started just before a lengthy operation, such as:     \snippet qelapsedtimer/main.cpp 0      Also, starting a timer makes it valid again.      \sa restart(), invalidate(), elapsed() */
end_comment
begin_function
name|void
name|QElapsedTimer
operator|::
name|start
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|restart
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Restarts the timer and returns the time elapsed since the previous start.     This function is equivalent to obtaining the elapsed time with elapsed()     and then starting the timer again with start(), but it does so in one     single operation, avoiding the need to obtain the clock value twice.      Restarting the timer makes it valid again.      The following example illustrates how to use this function to calibrate a     parameter to a slow operation (for example, an iteration count) so that     this operation takes at least 250 milliseconds:      \snippet qelapsedtimer/main.cpp 3      \sa start(), invalidate(), elapsed() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|restart
parameter_list|()
name|Q_DECL_NOTHROW
block|{
name|qint64
name|old
init|=
name|t1
decl_stmt|;
name|t1
operator|=
name|QDateTime
operator|::
name|currentMSecsSinceEpoch
argument_list|()
expr_stmt|;
name|t2
operator|=
literal|0
expr_stmt|;
return|return
name|t1
operator|-
name|old
return|;
block|}
end_function
begin_comment
comment|/*! \since 4.8      Returns the number of nanoseconds since this QElapsedTimer was last     started. Calling this function in a QElapsedTimer that was invalidated     will result in undefined results.      On platforms that do not provide nanosecond resolution, the value returned     will be the best estimate available.      \sa start(), restart(), hasExpired(), invalidate() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|nsecsElapsed
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|elapsed
argument_list|()
operator|*
literal|1000000
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of milliseconds since this QElapsedTimer was last     started. Calling this function in a QElapsedTimer that was invalidated     will result in undefined results.      \sa start(), restart(), hasExpired(), invalidate() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|elapsed
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|QDateTime
operator|::
name|currentMSecsSinceEpoch
argument_list|()
operator|-
name|t1
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of milliseconds between last time this QElapsedTimer     object was started and its reference clock's start.      This number is usually arbitrary for all clocks except the     QElapsedTimer::SystemTime clock. For that clock type, this number is the     number of milliseconds since January 1st, 1970 at 0:00 UTC (that is, it     is the Unix time expressed in milliseconds).      On Linux, Windows and OS X/iOS systems, this value is usually the time     since the system boot, though it usually does not include the time the     system has spent in sleep states.      \sa clockType(), elapsed() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|msecsSinceReference
parameter_list|()
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|t1
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of milliseconds between this QElapsedTimer and \a     other. If \a other was started before this object, the returned value     will be negative. If it was started later, the returned value will be     positive.      The return value is undefined if this object or \a other were invalidated.      \sa secsTo(), elapsed() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|msecsTo
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|other
parameter_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
name|qint64
name|diff
init|=
name|other
operator|.
name|t1
operator|-
name|t1
decl_stmt|;
return|return
name|diff
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of seconds between this QElapsedTimer and \a other. If     \a other was started before this object, the returned value will be     negative. If it was started later, the returned value will be positive.      The return value is undefined if this object or \a other were invalidated.      \sa msecsTo(), elapsed() */
end_comment
begin_function
name|qint64
name|QElapsedTimer
operator|::
name|secsTo
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|other
parameter_list|)
specifier|const
name|Q_DECL_NOTHROW
block|{
return|return
name|msecsTo
argument_list|(
name|other
argument_list|)
operator|/
literal|1000
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QElapsedTimer      Returns \c true if \a v1 was started before \a v2, false otherwise.      The returned value is undefined if one of the two parameters is invalid     and the other isn't. However, two invalid timers are equal and thus this     function will return false. */
end_comment
begin_function
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|QElapsedTimer
modifier|&
name|v1
parameter_list|,
specifier|const
name|QElapsedTimer
modifier|&
name|v2
parameter_list|)
name|Q_DECL_NOTHROW
block|{
return|return
name|v1
operator|.
name|t1
operator|<
name|v2
operator|.
name|t1
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
