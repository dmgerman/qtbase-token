begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qvalidator.h>
end_include
begin_class
DECL|class|tst_QRegExpValidator
class|class
name|tst_QRegExpValidator
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|validate_data
parameter_list|()
function_decl|;
name|void
name|validate
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|validate_data
name|void
name|tst_QRegExpValidator
operator|::
name|validate_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"rx"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"value"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"state"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data0"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"0"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"12345"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[1-9]\\d{0,3}"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"1"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"\\S+"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"myfile.txt"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"\\S+"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"my file.txt"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a12345Z"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"A12345Z"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data7"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"[A-C]\\d{5}[W-Z]"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"B12"
argument_list|)
operator|<<
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data8"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"readme"
argument_list|)
operator|<<
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data9"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read me.txt"
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data10"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"read\\S?me(\\.(txt|asc|1st))?"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"readm"
argument_list|)
operator|<<
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validate
name|void
name|tst_QRegExpValidator
operator|::
name|validate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|rx
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|state
argument_list|)
expr_stmt|;
name|QRegExpValidator
name|rv
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|rv
argument_list|,
name|SIGNAL
argument_list|(
name|regExpChanged
argument_list|(
name|QRegExp
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|changedSpy
argument_list|(
operator|&
name|rv
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|rv
operator|.
name|setRegExp
argument_list|(
name|QRegExp
argument_list|(
name|rx
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|pos
init|=
operator|-
literal|1
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|rv
operator|.
name|validate
argument_list|(
name|value
argument_list|,
name|pos
argument_list|)
argument_list|,
name|state
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|QValidator
operator|::
name|Invalid
condition|)
name|QCOMPARE
argument_list|(
name|pos
argument_list|,
name|value
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|pos
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// untouched on Acceptable or Intermediate
name|QCOMPARE
argument_list|(
name|spy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QRegExpValidator
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qregexpvalidator.moc"
end_include
end_unit
