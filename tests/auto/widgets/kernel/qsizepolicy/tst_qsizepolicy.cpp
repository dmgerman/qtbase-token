begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qsizepolicy.h>
end_include
begin_class
DECL|class|tst_QSizePolicy
class|class
name|tst_QSizePolicy
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSizePolicy
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSizePolicy
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|dataStream
parameter_list|()
function_decl|;
name|void
name|horizontalStretch
parameter_list|()
function_decl|;
name|void
name|verticalStretch
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSizePolicy
name|tst_QSizePolicy
operator|::
name|tst_QSizePolicy
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSizePolicy
name|tst_QSizePolicy
operator|::
name|~
name|tst_QSizePolicy
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QSizePolicy
operator|::
name|getSetCheck
parameter_list|()
block|{
block|{
comment|// check values of a default constructed QSizePolicy
name|QSizePolicy
name|sp
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalPolicy
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalPolicy
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalStretch
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalStretch
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalStretch
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|controlType
argument_list|()
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|hasWidthForHeight
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
block|{
specifier|static
specifier|const
name|QSizePolicy
operator|::
name|Policy
name|policies
index|[
literal|3
index|]
init|=
block|{
name|QSizePolicy
operator|::
name|Fixed
block|,
name|QSizePolicy
operator|::
name|Minimum
block|,
name|QSizePolicy
operator|::
name|Ignored
block|}
decl_stmt|;
specifier|static
specifier|const
name|QSizePolicy
operator|::
name|ControlType
name|controlTypes
index|[
literal|4
index|]
init|=
block|{
name|QSizePolicy
operator|::
name|DefaultType
block|,
name|QSizePolicy
operator|::
name|ButtonBox
block|,
name|QSizePolicy
operator|::
name|CheckBox
block|,
name|QSizePolicy
operator|::
name|ToolButton
block|}
decl_stmt|;
DECL|macro|ITEMCOUNT
define|#
directive|define
name|ITEMCOUNT
parameter_list|(
name|arr
parameter_list|)
value|sizeof(arr)/sizeof(arr[0])
name|QSizePolicy
name|sp
decl_stmt|,
name|oldsp
decl_stmt|;
ifdef|#
directive|ifdef
name|GENERATE_BASELINE
name|QFile
name|out
argument_list|(
name|QString
operator|::
name|fromAscii
argument_list|(
literal|"qsizepolicy-Qt%1%2.txt"
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|QT_VERSION
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|)
operator|.
name|arg
argument_list|(
operator|(
name|QT_VERSION
operator|)
operator|>>
literal|8
operator|&
literal|0xff
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|out
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
condition|)
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|out
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* Loop for permutating over the values most likely to trigger a bug:               - mininumum, maximum values               - Some values with LSB set, others with MSB unset. (check if shifts are ok)              */
comment|// Look specifically for
for|for
control|(
name|int
name|ihp
init|=
literal|0
init|;
name|ihp
operator|<
name|ITEMCOUNT
argument_list|(
name|policies
argument_list|)
condition|;
operator|++
name|ihp
control|)
block|{
name|QSizePolicy
operator|::
name|Policy
name|hp
init|=
name|policies
index|[
name|ihp
index|]
decl_stmt|;
for|for
control|(
name|int
name|ivp
init|=
literal|0
init|;
name|ivp
operator|<
name|ITEMCOUNT
argument_list|(
name|policies
argument_list|)
condition|;
operator|++
name|ivp
control|)
block|{
name|QSizePolicy
operator|::
name|Policy
name|vp
init|=
name|policies
index|[
name|ivp
index|]
decl_stmt|;
for|for
control|(
name|int
name|ict
init|=
literal|0
init|;
name|ict
operator|<
name|ITEMCOUNT
argument_list|(
name|controlTypes
argument_list|)
condition|;
operator|++
name|ict
control|)
block|{
name|QSizePolicy
operator|::
name|ControlType
name|ct
init|=
name|controlTypes
index|[
name|ict
index|]
decl_stmt|;
for|for
control|(
name|int
name|hst
init|=
literal|0
init|;
name|hst
operator|<=
literal|255
condition|;
name|hst
operator|+=
literal|85
control|)
block|{
comment|//[0,85,170,255]
for|for
control|(
name|int
name|vst
init|=
literal|0
init|;
name|vst
operator|<=
literal|255
condition|;
name|vst
operator|+=
literal|85
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
literal|3
condition|;
operator|++
name|j
control|)
block|{
name|bool
name|hfw
init|=
name|j
operator|&
literal|1
decl_stmt|;
name|bool
name|wfh
init|=
name|j
operator|&
literal|2
decl_stmt|;
comment|// cannot set hfw and wfh at the same time
name|oldsp
operator|=
name|sp
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
literal|5
condition|;
operator|++
name|i
control|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|0
case|:
name|sp
operator|.
name|setHorizontalPolicy
argument_list|(
name|hp
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|sp
operator|.
name|setVerticalPolicy
argument_list|(
name|vp
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|sp
operator|.
name|setHorizontalStretch
argument_list|(
name|hst
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|sp
operator|.
name|setVerticalStretch
argument_list|(
name|vst
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|sp
operator|.
name|setControlType
argument_list|(
name|ct
argument_list|)
expr_stmt|;
break|break;
case|case
literal|5
case|:
name|sp
operator|.
name|setHeightForWidth
argument_list|(
name|hfw
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setWidthForHeight
argument_list|(
name|wfh
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalPolicy
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|0
condition|?
name|hp
else|:
name|oldsp
operator|.
name|horizontalPolicy
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalPolicy
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|1
condition|?
name|vp
else|:
name|oldsp
operator|.
name|verticalPolicy
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalStretch
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|2
condition|?
name|hst
else|:
name|oldsp
operator|.
name|horizontalStretch
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalStretch
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|3
condition|?
name|vst
else|:
name|oldsp
operator|.
name|verticalStretch
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|controlType
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|4
condition|?
name|ct
else|:
name|oldsp
operator|.
name|controlType
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|5
condition|?
name|hfw
else|:
name|oldsp
operator|.
name|hasHeightForWidth
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|hasWidthForHeight
argument_list|()
argument_list|,
operator|(
name|i
operator|>=
literal|5
condition|?
name|wfh
else|:
name|oldsp
operator|.
name|hasWidthForHeight
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|Orientations
name|orients
decl_stmt|;
if|if
condition|(
name|sp
operator|.
name|horizontalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|ExpandFlag
condition|)
name|orients
operator||=
name|Qt
operator|::
name|Horizontal
expr_stmt|;
if|if
condition|(
name|sp
operator|.
name|verticalPolicy
argument_list|()
operator|&
name|QSizePolicy
operator|::
name|ExpandFlag
condition|)
name|orients
operator||=
name|Qt
operator|::
name|Vertical
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|expandingDirections
argument_list|()
argument_list|,
name|orients
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GENERATE_BASELINE
name|stream
operator|<<
name|sp
expr_stmt|;
endif|#
directive|endif
block|}
block|}
block|}
block|}
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|GENERATE_BASELINE
name|out
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|dataStream
name|void
name|tst_QSizePolicy
operator|::
name|dataStream
parameter_list|()
block|{
name|QByteArray
name|data
decl_stmt|;
name|QSizePolicy
name|sp
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
decl_stmt|;
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|ReadWrite
argument_list|)
decl_stmt|;
name|sp
operator|.
name|setHorizontalStretch
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setVerticalStretch
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setControlType
argument_list|(
name|QSizePolicy
operator|::
name|CheckBox
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setHeightForWidth
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|sp
expr_stmt|;
comment|// big endian
comment|/* |                     BYTE 0                    |                    BYTE 1                     | |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  | +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+ |               Horizontal stretch              |               Vertical stretch                | +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+  |                     BYTE 2                    |                    BYTE 3                     | | 16  | 17  | 18  | 19  | 20  | 21  | 22  | 23  | 24  | 25  | 26  | 27  | 28  | 29  | 30  | 31  | +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+ | pad | wfh |        Control Type         | hfw |    Vertical policy    |   Horizontal policy   | +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+ */
name|QCOMPARE
argument_list|(
operator|(
name|char
operator|)
name|data
index|[
literal|0
index|]
argument_list|,
name|char
argument_list|(
literal|42
argument_list|)
argument_list|)
expr_stmt|;
comment|// h stretch
name|QCOMPARE
argument_list|(
operator|(
name|char
operator|)
name|data
index|[
literal|1
index|]
argument_list|,
name|char
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// v stretch
name|QCOMPARE
argument_list|(
operator|(
name|char
operator|)
name|data
index|[
literal|2
index|]
argument_list|,
name|char
argument_list|(
literal|1
operator||
operator|(
literal|2
operator|<<
literal|1
operator|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// (hfw + CheckBox)
name|QCOMPARE
argument_list|(
operator|(
name|char
operator|)
name|data
index|[
literal|3
index|]
argument_list|,
name|char
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
operator||
operator|(
name|QSizePolicy
operator|::
name|Expanding
operator|<<
literal|4
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QSizePolicy
name|readSP
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|stream
operator|>>
name|readSP
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
argument_list|,
name|readSP
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|horizontalStretch
name|void
name|tst_QSizePolicy
operator|::
name|horizontalStretch
parameter_list|()
block|{
name|QSizePolicy
name|sp
decl_stmt|;
name|sp
operator|.
name|setHorizontalStretch
argument_list|(
literal|257
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalStretch
argument_list|()
argument_list|,
literal|255
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setHorizontalStretch
argument_list|(
operator|-
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|horizontalStretch
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|verticalStretch
name|void
name|tst_QSizePolicy
operator|::
name|verticalStretch
parameter_list|()
block|{
name|QSizePolicy
name|sp
decl_stmt|;
name|sp
operator|.
name|setVerticalStretch
argument_list|(
operator|-
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalStretch
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sp
operator|.
name|setVerticalStretch
argument_list|(
literal|257
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sp
operator|.
name|verticalStretch
argument_list|()
argument_list|,
literal|255
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSizePolicy
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsizepolicy.moc"
end_include
end_unit
