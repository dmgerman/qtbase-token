begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QDate
name|d1
argument_list|(
literal|1995
argument_list|,
literal|5
argument_list|,
literal|17
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// May 17, 1995
end_comment
begin_decl_stmt
name|QDate
name|d2
argument_list|(
literal|1995
argument_list|,
literal|5
argument_list|,
literal|20
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// May 20, 1995
end_comment
begin_expr_stmt
name|d1
operator|.
name|daysTo
argument_list|(
name|d2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 3
end_comment
begin_expr_stmt
name|d2
operator|.
name|daysTo
argument_list|(
name|d1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns -3
end_comment
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|date
name|QDate
name|date
init|=
name|QDate
operator|::
name|fromString
argument_list|(
literal|"1MM12car2003"
argument_list|,
literal|"d'MM'MMcaryyyy"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// date is 1 December 2003
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|date
name|QDate
name|date
init|=
name|QDate
operator|::
name|fromString
argument_list|(
literal|"130"
argument_list|,
literal|"Md"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|date
comment|// invalid
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|QDate
operator|::
name|fromString
argument_list|(
literal|"1.30"
argument_list|,
literal|"M.d"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// January 30 1900
end_comment
begin_expr_stmt
name|QDate
operator|::
name|fromString
argument_list|(
literal|"20000110"
argument_list|,
literal|"yyyyMMdd"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// January 10, 2000
end_comment
begin_expr_stmt
name|QDate
operator|::
name|fromString
argument_list|(
literal|"20000110"
argument_list|,
literal|"yyyyMd"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// January 10, 2000
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2002
argument_list|,
literal|5
argument_list|,
literal|17
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// true
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2002
argument_list|,
literal|2
argument_list|,
literal|30
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// false (Feb 30 does not exist)
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2004
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// true (2004 is a leap year)
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2000
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// true (2000 is a leap year)
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2006
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// false (2006 is not a leap year)
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|2100
argument_list|,
literal|2
argument_list|,
literal|29
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// false (2100 is not a leap year)
end_comment
begin_expr_stmt
name|QDate
operator|::
name|isValid
argument_list|(
literal|1202
argument_list|,
literal|6
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// true (even though 1202 is pre-Gregorian)
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
name|QTime
name|n
argument_list|(
literal|14
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// n == 14:00:00
end_comment
begin_decl_stmt
DECL|variable|t
name|QTime
name|t
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|t
operator|=
name|n
operator|.
name|addSecs
argument_list|(
literal|70
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// t == 14:01:10
end_comment
begin_expr_stmt
name|t
operator|=
name|n
operator|.
name|addSecs
argument_list|(
operator|-
literal|70
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// t == 13:58:50
end_comment
begin_expr_stmt
name|t
operator|=
name|n
operator|.
name|addSecs
argument_list|(
literal|10
operator|*
literal|60
operator|*
literal|60
operator|+
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// t == 00:00:05
end_comment
begin_expr_stmt
name|t
operator|=
name|n
operator|.
name|addSecs
argument_list|(
operator|-
literal|15
operator|*
literal|60
operator|*
literal|60
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// t == 23:00:00
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|time
name|QTime
name|time
init|=
name|QTime
operator|::
name|fromString
argument_list|(
literal|"1mm12car00"
argument_list|,
literal|"m'mm'hcarss"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// time is 12:01.00
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|time
name|QTime
name|time
init|=
name|QTime
operator|::
name|fromString
argument_list|(
literal|"00:710"
argument_list|,
literal|"hh:ms"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|time
comment|// invalid
end_comment
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|time
name|QTime
name|time
init|=
name|QTime
operator|::
name|fromString
argument_list|(
literal|"1.30"
argument_list|,
literal|"m.s"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// time is 00:01:30.000
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_expr_stmt
name|QTime
operator|::
name|isValid
argument_list|(
literal|21
argument_list|,
literal|10
argument_list|,
literal|30
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|QTime
operator|::
name|isValid
argument_list|(
literal|22
argument_list|,
literal|5
argument_list|,
literal|62
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|t
name|QTime
name|t
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|some_lengthy_task
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|(
literal|"Time elapsed: %d ms"
argument_list|,
name|t
operator|.
name|elapsed
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|now
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
name|xmas
argument_list|(
name|QDate
argument_list|(
name|now
operator|.
name|date
argument_list|()
operator|.
name|year
argument_list|()
argument_list|,
literal|12
argument_list|,
literal|25
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|(
literal|"There are %d seconds to Christmas"
argument_list|,
name|now
operator|.
name|secsTo
argument_list|(
name|xmas
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|time1
name|QTime
name|time1
init|=
name|QTime
operator|::
name|fromString
argument_list|(
literal|"131"
argument_list|,
literal|"HHh"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// time1 is 13:00:00
end_comment
begin_decl_stmt
DECL|variable|time1
name|QTime
name|time1
init|=
name|QTime
operator|::
name|fromString
argument_list|(
literal|"1apA"
argument_list|,
literal|"1amAM"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// time1 is 01:00:00
end_comment
begin_decl_stmt
DECL|variable|dateTime2
name|QDateTime
name|dateTime2
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"M1d1y9800:01:02"
argument_list|,
literal|"'M'M'd'd'y'yyhh:mm:ss"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// dateTime is 1 January 1998 00:01:02
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|dateTime
name|QDateTime
name|dateTime
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"130"
argument_list|,
literal|"Mm"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|dateTime
comment|// invalid
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|dateTime
name|QDateTime
name|dateTime
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"1.30.1"
argument_list|,
literal|"M.d.s"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// dateTime is January 30 in 1900 at 00:00:01.
end_comment
begin_expr_stmt
name|dateTime
operator|=
name|QDateTime
operator|::
name|fromString
argument_list|(
literal|"12"
argument_list|,
literal|"yy"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// dateTime is January 1 in 1912 at 00:00:00.
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
name|QDateTime
name|startDate
argument_list|(
name|QDate
argument_list|(
literal|2012
argument_list|,
literal|7
argument_list|,
literal|6
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|8
argument_list|,
literal|30
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
name|endDate
argument_list|(
name|QDate
argument_list|(
literal|2012
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|16
argument_list|,
literal|30
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Days from startDate to endDate: "
operator|<<
name|startDate
operator|.
name|daysTo
argument_list|(
name|endDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|startDate
operator|=
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2012
argument_list|,
literal|7
argument_list|,
literal|6
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|23
argument_list|,
literal|55
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|endDate
operator|=
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2012
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Days from startDate to endDate: "
operator|<<
name|startDate
operator|.
name|daysTo
argument_list|(
name|endDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qSwap
argument_list|(
name|startDate
argument_list|,
name|endDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Make endDate before startDate.
end_comment
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Days from startDate to endDate: "
operator|<<
name|startDate
operator|.
name|daysTo
argument_list|(
name|endDate
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
name|QDateTime
name|local
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
name|UTC
argument_list|(
name|local
operator|.
name|toTimeSpec
argument_list|(
name|Qt
operator|::
name|UTC
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Local time is:"
operator|<<
name|local
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"UTC time is:"
operator|<<
name|UTC
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"No difference between times:"
operator|<<
name|local
operator|.
name|secsTo
argument_list|(
name|UTC
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
name|QDateTime
name|UTC
argument_list|(
name|QDateTime
operator|::
name|currentDateTimeUtc
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
name|local
argument_list|(
name|UTC
operator|.
name|toLocalTime
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"UTC time is:"
operator|<<
name|UTC
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Local time is:"
operator|<<
name|local
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"No difference between times:"
operator|<<
name|UTC
operator|.
name|secsTo
argument_list|(
name|local
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_decl_stmt
name|QDateTime
name|local
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDateTime
name|UTC
argument_list|(
name|local
operator|.
name|toUTC
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Local time is:"
operator|<<
name|local
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"UTC time is:"
operator|<<
name|UTC
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"No difference between times:"
operator|<<
name|local
operator|.
name|secsTo
argument_list|(
name|UTC
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_decl_stmt
name|QDateTime
name|local
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"Local time is:"
operator|<<
name|local
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QDateTime
name|UTC
parameter_list|(
name|local
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|UTC
operator|.
name|setTimeSpec
argument_list|(
name|Qt
operator|::
name|UTC
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"UTC time is:"
operator|<<
name|UTC
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"There are"
operator|<<
name|local
operator|.
name|secsTo
argument_list|(
name|UTC
argument_list|)
operator|<<
literal|"seconds difference between the datetimes."
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_decl_stmt
DECL|variable|string
name|QString
name|string
init|=
literal|"Monday, 23 April 12 22:51:41"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|format
name|QString
name|format
init|=
literal|"dddd, d MMMM yy hh:mm:ss"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|invalid
name|QDateTime
name|invalid
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
name|string
argument_list|,
name|format
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_decl_stmt
DECL|variable|string
name|QString
name|string
init|=
literal|"Tuesday, 23 April 12 22:51:41"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|format
name|QString
name|format
init|=
literal|"dddd, d MMMM yy hh:mm:ss"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|valid
name|QDateTime
name|valid
init|=
name|QDateTime
operator|::
name|fromString
argument_list|(
name|string
argument_list|,
name|format
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [21]
end_comment
end_unit
