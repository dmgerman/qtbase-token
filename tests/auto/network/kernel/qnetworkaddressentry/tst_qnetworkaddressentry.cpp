begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkinterface.h>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QHostAddress
argument_list|)
end_macro
begin_class
DECL|class|tst_QNetworkAddressEntry
class|class
name|tst_QNetworkAddressEntry
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|prefixAndNetmask_data
parameter_list|()
function_decl|;
name|void
name|prefixAndNetmask
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|getSetCheck
name|void
name|tst_QNetworkAddressEntry
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QNetworkAddressEntry
name|entry
decl_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|ip
argument_list|()
argument_list|,
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setIp
argument_list|(
name|QHostAddress
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|ip
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setBroadcast
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|broadcast
argument_list|()
argument_list|,
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setBroadcast
argument_list|(
name|QHostAddress
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|broadcast
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// netmask and prefix length tested in the next test
name|entry
operator|.
name|setIp
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setBroadcast
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
expr_stmt|;
name|QNetworkAddressEntry
name|entry2
decl_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|!=
name|entry2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|entry
operator|==
name|entry2
operator|)
argument_list|)
expr_stmt|;
name|entry
operator|=
name|entry2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
argument_list|,
name|entry2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|==
name|entry
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|entry
operator|!=
name|entry2
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|prefixAndNetmask_data
name|void
name|tst_QNetworkAddressEntry
operator|::
name|prefixAndNetmask_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QHostAddress
argument_list|>
argument_list|(
literal|"ip"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QHostAddress
argument_list|>
argument_list|(
literal|"netmask"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"prefix"
argument_list|)
expr_stmt|;
comment|// IPv4 set:
name|QHostAddress
name|ipv4
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/0"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|AnyIPv4
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/32"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
literal|"255.255.255.255"
argument_list|)
operator|<<
literal|32
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/24"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
literal|"255.255.255.0"
argument_list|)
operator|<<
literal|24
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/23"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
literal|"255.255.254.0"
argument_list|)
operator|<<
literal|23
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/20"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
literal|"255.255.240.0"
argument_list|)
operator|<<
literal|20
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/invalid1"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/invalid2"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|AnyIPv6
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/invalid3"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|(
literal|"255.255.253.0"
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/invalid4"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|()
operator|<<
operator|-
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v4/invalid5"
argument_list|)
operator|<<
name|ipv4
operator|<<
name|QHostAddress
argument_list|()
operator|<<
literal|33
expr_stmt|;
comment|// IPv6 set:
name|QHostAddress
name|ipv6
argument_list|(
name|QHostAddress
operator|::
name|LocalHostIPv6
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/0"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|AnyIPv6
argument_list|)
operator|<<
literal|0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/128"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff"
argument_list|)
operator|<<
literal|128
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/64"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"ffff:ffff:ffff:ffff::"
argument_list|)
operator|<<
literal|64
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/63"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"ffff:ffff:ffff:fffe::"
argument_list|)
operator|<<
literal|63
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/60"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"ffff:ffff:ffff:fff0::"
argument_list|)
operator|<<
literal|60
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/48"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"ffff:ffff:ffff::"
argument_list|)
operator|<<
literal|48
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/3"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"e000::"
argument_list|)
operator|<<
literal|3
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/invalid1"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHostIPv6
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/invalid2"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|Any
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/invalid3"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|(
literal|"fffd::"
argument_list|)
operator|<<
operator|-
literal|1
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/invalid4"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|()
operator|<<
operator|-
literal|2
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"v6/invalid5"
argument_list|)
operator|<<
name|ipv6
operator|<<
name|QHostAddress
argument_list|()
operator|<<
literal|129
expr_stmt|;
block|}
end_function
begin_function
DECL|function|prefixAndNetmask
name|void
name|tst_QNetworkAddressEntry
operator|::
name|prefixAndNetmask
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QHostAddress
argument_list|,
name|ip
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QHostAddress
argument_list|,
name|netmask
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
name|QNetworkAddressEntry
name|entry
decl_stmt|;
comment|// first, without setting the IP, all must be invalid:
name|entry
operator|.
name|setNetmask
argument_list|(
name|netmask
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|entry
operator|.
name|setPrefixLength
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// set the IP:
name|entry
operator|.
name|setIp
argument_list|(
name|ip
argument_list|)
expr_stmt|;
comment|// set the netmask:
if|if
condition|(
operator|!
name|netmask
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|entry
operator|.
name|setNetmask
argument_list|(
name|netmask
argument_list|)
expr_stmt|;
comment|// was it a valid one?
if|if
condition|(
name|prefix
operator|!=
operator|-
literal|1
condition|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
argument_list|,
name|netmask
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// not valid
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|entry
operator|.
name|setNetmask
argument_list|(
name|QHostAddress
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// set the prefix
if|if
condition|(
name|prefix
operator|!=
operator|-
literal|1
condition|)
block|{
name|entry
operator|.
name|setPrefixLength
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
comment|// was it a valid one?
if|if
condition|(
operator|!
name|netmask
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QVERIFY
argument_list|(
operator|!
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
argument_list|,
name|netmask
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// not valid
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|entry
operator|.
name|setPrefixLength
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|entry
operator|.
name|netmask
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|entry
operator|.
name|prefixLength
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkAddressEntry
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkaddressentry.moc"
end_include
end_unit
