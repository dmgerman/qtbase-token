begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qvalidator.h>
end_include
begin_class
DECL|class|tst_QIntValidator
class|class
name|tst_QIntValidator
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
name|void
name|validateArabic
parameter_list|()
function_decl|;
name|void
name|validateFrench
parameter_list|()
function_decl|;
name|void
name|notifySignals
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_expr_stmt
DECL|variable|State
name|Q_DECLARE_METATYPE
argument_list|(
name|QValidator
operator|::
name|State
argument_list|)
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|INV
define|#
directive|define
name|INV
value|QValidator::Invalid
end_define
begin_define
DECL|macro|INT
define|#
directive|define
name|INT
value|QValidator::Intermediate
end_define
begin_define
DECL|macro|ACC
define|#
directive|define
name|ACC
value|QValidator::Acceptable
end_define
begin_function
DECL|function|validate_data
name|void
name|tst_QIntValidator
operator|::
name|validate_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"minimum"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"maximum"
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
name|QValidator
operator|::
name|State
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
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"50"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"500"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1a"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"5000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1b"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|0
operator|<<
name|QString
argument_list|(
literal|"50"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1c"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|0
operator|<<
name|QString
argument_list|(
literal|"500"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1d"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|0
operator|<<
name|QString
argument_list|(
literal|"5000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-35"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"a"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
literal|0
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data7"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-500"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data8"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-100"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data9"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"10"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data10"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|""
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data11"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data12"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"50"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data13"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"99"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data14"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data15"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"101"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data16"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"998"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data17"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"999"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data18"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"1000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data19"
argument_list|)
operator|<<
literal|100
operator|<<
literal|999
operator|<<
name|QString
argument_list|(
literal|"-10"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data20"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"50"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data21"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data22"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-1"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data23"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-10"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data24"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-100"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data25"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-500"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data26"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-998"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data27"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-999"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data28"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-1000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data29"
argument_list|)
operator|<<
operator|-
literal|999
operator|<<
operator|-
literal|100
operator|<<
name|QString
argument_list|(
literal|"-2000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1.1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|""
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"1.2"
argument_list|)
operator|<<
literal|10
operator|<<
literal|0
operator|<<
name|QString
argument_list|(
literal|""
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.2"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-0"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.3"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
operator|-
literal|1
operator|<<
name|QString
argument_list|(
literal|"+"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.4"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.5"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"+"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.6"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"+0"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.7"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"+1"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.8"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"+-"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"2.9"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-+"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"12345678901234567890"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.2"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-12345678901234567890"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.3"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"000000000000000000000"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.4"
argument_list|)
operator|<<
literal|1
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"000000000000000000000"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.5"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-000000000000000000000"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.6"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
operator|-
literal|1
operator|<<
name|QString
argument_list|(
literal|"-000000000000000000000"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"3.7"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
operator|-
literal|1
operator|<<
name|QString
argument_list|(
literal|"-0000000000000000000001"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|" "
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.2"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|" 1"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.3"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"1 "
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.4"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"1.0"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.5"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"0.1"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.6"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|".1"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"4.7"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-1.0"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.1"
argument_list|)
operator|<<
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.2"
argument_list|)
operator|<<
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"7"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.3"
argument_list|)
operator|<<
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"9"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.3a"
argument_list|)
operator|<<
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"19"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.4"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"-5"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.5"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"-7"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.6"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"-9"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.6a"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"-19"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.7"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.8"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"7"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.9"
argument_list|)
operator|<<
operator|-
literal|8
operator|<<
operator|-
literal|6
operator|<<
name|QString
argument_list|(
literal|"9"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.10"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"-5"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.11"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.12"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"-7"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.13"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"7"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.14"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"-9"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"5.15"
argument_list|)
operator|<<
operator|-
literal|6
operator|<<
literal|8
operator|<<
name|QString
argument_list|(
literal|"9"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"6.1"
argument_list|)
operator|<<
literal|100
operator|<<
literal|102
operator|<<
name|QString
argument_list|(
literal|"11"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"6.2"
argument_list|)
operator|<<
literal|100
operator|<<
literal|102
operator|<<
name|QString
argument_list|(
literal|"-11"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"7.1"
argument_list|)
operator|<<
literal|0
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"7.2"
argument_list|)
operator|<<
literal|0
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"7.3"
argument_list|)
operator|<<
literal|0
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"-100"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"7.4"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"100"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.1"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"+"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.2"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"+50"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.3"
argument_list|)
operator|<<
operator|-
literal|100
operator|<<
operator|-
literal|10
operator|<<
name|QString
argument_list|(
literal|"50"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.4"
argument_list|)
operator|<<
literal|10
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.5"
argument_list|)
operator|<<
literal|10
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-50"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.6"
argument_list|)
operator|<<
literal|10
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.7"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.8"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"-50"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.9"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"5"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.10"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"+"
argument_list|)
operator|<<
name|INT
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"8.11"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|100
operator|<<
name|QString
argument_list|(
literal|"+50"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.0"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"000"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.1"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"008"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.2"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-008"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.3"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"00010"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.4"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-00010"
argument_list|)
operator|<<
name|ACC
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.5"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"00020"
argument_list|)
operator|<<
name|INV
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"9.6"
argument_list|)
operator|<<
operator|-
literal|10
operator|<<
literal|10
operator|<<
name|QString
argument_list|(
literal|"-00020"
argument_list|)
operator|<<
name|INV
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validateArabic
name|void
name|tst_QIntValidator
operator|::
name|validateArabic
parameter_list|()
block|{
name|QString
name|arabicNum
decl_stmt|;
name|arabicNum
operator|+=
name|QChar
argument_list|(
literal|1633
argument_list|)
expr_stmt|;
comment|// "18" in arabic
name|arabicNum
operator|+=
name|QChar
argument_list|(
literal|1640
argument_list|)
expr_stmt|;
name|QIntValidator
name|validator
argument_list|(
operator|-
literal|20
argument_list|,
literal|20
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|validator
operator|.
name|setLocale
argument_list|(
name|QLocale
argument_list|(
name|QLocale
operator|::
name|Arabic
argument_list|,
name|QLocale
operator|::
name|SaudiArabia
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|arabicNum
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Acceptable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validateFrench
name|void
name|tst_QIntValidator
operator|::
name|validateFrench
parameter_list|()
block|{
name|QIntValidator
name|validator
argument_list|(
operator|-
literal|2000
argument_list|,
literal|2000
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|validator
operator|.
name|setLocale
argument_list|(
name|QLocale
operator|::
name|French
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
name|QString
name|s
init|=
name|QLatin1String
argument_list|(
literal|"1 "
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Acceptable
argument_list|)
expr_stmt|;
name|validator
operator|.
name|fixup
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|s
operator|=
name|QLatin1String
argument_list|(
literal|"1 000"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Acceptable
argument_list|)
expr_stmt|;
name|validator
operator|.
name|fixup
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|s
operator|=
name|QLatin1String
argument_list|(
literal|"1 0 00"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Intermediate
argument_list|)
expr_stmt|;
name|validator
operator|.
name|fixup
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s
argument_list|,
name|validator
operator|.
name|locale
argument_list|()
operator|.
name|toString
argument_list|(
literal|1000
argument_list|)
argument_list|)
expr_stmt|;
comment|// Confim no fallback to C locale
name|s
operator|=
name|QLatin1String
argument_list|(
literal|"1,000"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|validator
operator|.
name|setLocale
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|validator
operator|.
name|validate
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
argument_list|,
name|QValidator
operator|::
name|Acceptable
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|validate
name|void
name|tst_QIntValidator
operator|::
name|validate
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|minimum
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|maximum
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
name|QValidator
operator|::
name|State
argument_list|,
name|state
argument_list|)
expr_stmt|;
name|QIntValidator
name|iv
argument_list|(
name|minimum
argument_list|,
name|maximum
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|iv
operator|.
name|setLocale
argument_list|(
name|QLocale
operator|::
name|C
argument_list|)
expr_stmt|;
name|int
name|dummy
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|int
operator|)
name|iv
operator|.
name|validate
argument_list|(
name|value
argument_list|,
name|dummy
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|state
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notifySignals
name|void
name|tst_QIntValidator
operator|::
name|notifySignals
parameter_list|()
block|{
name|QLocale
operator|::
name|setDefault
argument_list|(
name|QLocale
argument_list|(
literal|"C"
argument_list|)
argument_list|)
expr_stmt|;
name|QIntValidator
name|iv
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QSignalSpy
name|topSpy
argument_list|(
operator|&
name|iv
argument_list|,
name|SIGNAL
argument_list|(
name|topChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|bottomSpy
argument_list|(
operator|&
name|iv
argument_list|,
name|SIGNAL
argument_list|(
name|bottomChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|changedSpy
argument_list|(
operator|&
name|iv
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|iv
operator|.
name|setTop
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topSpy
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
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|top
argument_list|()
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setBottom
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottomSpy
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
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|bottom
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setRange
argument_list|(
literal|1
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottomSpy
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
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|top
argument_list|()
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|bottom
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setRange
argument_list|(
literal|2
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottomSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|top
argument_list|()
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|bottom
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setRange
argument_list|(
literal|3
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottomSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|top
argument_list|()
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|iv
operator|.
name|bottom
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setRange
argument_list|(
literal|3
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|topSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|bottomSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setLocale
argument_list|(
name|QLocale
argument_list|(
literal|"C"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|iv
operator|.
name|setLocale
argument_list|(
name|QLocale
argument_list|(
literal|"en"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|changedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|6
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QIntValidator
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qintvalidator.moc"
end_include
end_unit
