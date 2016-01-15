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
file|"../qbearertestcommon.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfiguration.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkconfigmanager.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*   Although this unit test doesn't use QNetworkAccessManager   this include is used to ensure that bearer continues to compile against   Qt 4.7+ which has a QNetworkConfiguration enabled QNetworkAccessManager */
end_comment
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_macro
name|QT_USE_NAMESPACE
end_macro
begin_class
DECL|class|tst_QNetworkConfiguration
class|class
name|tst_QNetworkConfiguration
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
name|void
name|invalidPoint
parameter_list|()
function_decl|;
name|void
name|comparison
parameter_list|()
function_decl|;
name|void
name|children
parameter_list|()
function_decl|;
name|void
name|isRoamingAvailable
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function
DECL|function|invalidPoint
name|void
name|tst_QNetworkConfiguration
operator|::
name|invalidPoint
parameter_list|()
block|{
name|QNetworkConfiguration
name|pt
decl_stmt|;
name|QVERIFY
argument_list|(
name|pt
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pt
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pt
operator|.
name|isRoamingAvailable
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|pt2
argument_list|(
name|pt
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|pt2
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pt2
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt2
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt2
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Defined
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt2
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt2
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Active
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pt2
operator|.
name|isRoamingAvailable
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|comparison
name|void
name|tst_QNetworkConfiguration
operator|::
name|comparison
parameter_list|()
block|{
comment|//test copy constructor and assignment operator
comment|//compare invalid connection points
name|QNetworkConfiguration
name|pt1
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pt1
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|pt2
argument_list|(
name|pt1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|pt1
operator|==
name|pt2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt1
operator|!=
name|pt2
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|name
argument_list|()
argument_list|,
name|pt2
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|isValid
argument_list|()
argument_list|,
name|pt2
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|type
argument_list|()
argument_list|,
name|pt2
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|state
argument_list|()
argument_list|,
name|pt2
operator|.
name|state
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|purpose
argument_list|()
argument_list|,
name|pt2
operator|.
name|purpose
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|pt3
decl_stmt|;
name|pt3
operator|=
name|pt1
expr_stmt|;
name|QVERIFY
argument_list|(
name|pt1
operator|==
name|pt3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|pt1
operator|!=
name|pt3
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|name
argument_list|()
argument_list|,
name|pt3
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|isValid
argument_list|()
argument_list|,
name|pt3
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|type
argument_list|()
argument_list|,
name|pt3
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|state
argument_list|()
argument_list|,
name|pt3
operator|.
name|state
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pt1
operator|.
name|purpose
argument_list|()
argument_list|,
name|pt3
operator|.
name|purpose
argument_list|()
argument_list|)
expr_stmt|;
comment|//test case must run on machine that has valid connection points
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|preScanConfigs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY_WITH_TIMEOUT
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|,
name|TestTimeOut
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|(
name|QNetworkConfiguration
operator|::
name|Discovered
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|configs
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QNetworkConfiguration
name|defaultConfig
init|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|defaultConfig
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|defaultConfig
operator|.
name|type
argument_list|()
operator|!=
name|QNetworkConfiguration
operator|::
name|Invalid
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|defaultConfig
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|pt3
operator|=
name|defaultConfig
expr_stmt|;
name|QVERIFY
argument_list|(
name|defaultConfig
operator|==
name|pt3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|defaultConfig
operator|!=
name|pt3
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|name
argument_list|()
argument_list|,
name|pt3
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|isValid
argument_list|()
argument_list|,
name|pt3
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|type
argument_list|()
argument_list|,
name|pt3
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|state
argument_list|()
argument_list|,
name|pt3
operator|.
name|state
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|defaultConfig
operator|.
name|purpose
argument_list|()
argument_list|,
name|pt3
operator|.
name|purpose
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|children
name|void
name|tst_QNetworkConfiguration
operator|::
name|children
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|c
decl|,
name|configs
control|)
block|{
if|if
condition|(
name|c
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"found service network"
operator|<<
name|c
operator|.
name|name
argument_list|()
operator|<<
name|c
operator|.
name|children
argument_list|()
operator|.
name|count
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|c
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|members
init|=
name|c
operator|.
name|children
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|child
decl|,
name|members
control|)
block|{
name|QVERIFY
argument_list|(
name|child
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|configs
operator|.
name|contains
argument_list|(
name|child
argument_list|)
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"\t"
operator|<<
name|child
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|isRoamingAvailable
name|void
name|tst_QNetworkConfiguration
operator|::
name|isRoamingAvailable
parameter_list|()
block|{
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
argument_list|<
name|QNetworkConfiguration
argument_list|>
name|configs
init|=
name|manager
operator|.
name|allConfigurations
argument_list|()
decl_stmt|;
comment|//force update to get maximum list
name|QSignalSpy
name|spy
argument_list|(
operator|&
name|manager
argument_list|,
name|SIGNAL
argument_list|(
name|updateCompleted
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|manager
operator|.
name|updateConfigurations
argument_list|()
expr_stmt|;
comment|//initiate scans
name|QTRY_VERIFY_WITH_TIMEOUT
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|,
name|TestTimeOut
argument_list|)
expr_stmt|;
comment|//wait for scan to complete
foreach|foreach
control|(
name|QNetworkConfiguration
name|c
decl|,
name|configs
control|)
block|{
name|QVERIFY
argument_list|(
name|QNetworkConfiguration
operator|::
name|UserChoice
operator|!=
name|c
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QNetworkConfiguration
operator|::
name|Invalid
operator|!=
name|c
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|ServiceNetwork
condition|)
block|{
comment|//cannot test flag as some SNAPs may not support roaming anyway
comment|//QVERIFY(c.roamingavailable())
if|if
condition|(
name|c
operator|.
name|children
argument_list|()
operator|.
name|count
argument_list|()
operator|<=
literal|1
condition|)
name|QVERIFY
argument_list|(
operator|!
name|c
operator|.
name|isRoamingAvailable
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QNetworkConfiguration
name|child
decl|,
name|c
operator|.
name|children
argument_list|()
control|)
block|{
name|QCOMPARE
argument_list|(
name|QNetworkConfiguration
operator|::
name|InternetAccessPoint
argument_list|,
name|child
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|child
operator|.
name|children
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QVERIFY
argument_list|(
operator|!
name|c
operator|.
name|isRoamingAvailable
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkConfiguration
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkconfiguration.moc"
end_include
end_unit
