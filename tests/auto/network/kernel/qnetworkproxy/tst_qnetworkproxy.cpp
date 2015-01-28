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
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qnetworkproxy.h>
end_include
begin_class
DECL|class|tst_QNetworkProxy
class|class
name|tst_QNetworkProxy
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QNetworkProxy
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QNetworkProxy
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
name|capabilitiesPerType
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QNetworkProxy
name|tst_QNetworkProxy
operator|::
name|tst_QNetworkProxy
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QNetworkProxy
name|tst_QNetworkProxy
operator|::
name|~
name|tst_QNetworkProxy
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QNetworkProxy
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QNetworkProxy
name|obj1
decl_stmt|;
comment|// quint16 QNetworkProxy::port()
comment|// void QNetworkProxy::setPort(quint16)
name|obj1
operator|.
name|setPort
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0
argument_list|)
argument_list|,
name|obj1
operator|.
name|port
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPort
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|quint16
argument_list|(
literal|0xffff
argument_list|)
argument_list|,
name|obj1
operator|.
name|port
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|DefaultProxy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkProxy
operator|::
name|DefaultProxy
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|obj1
operator|.
name|type
argument_list|()
argument_list|,
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|capabilitiesPerType
name|void
name|tst_QNetworkProxy
operator|::
name|capabilitiesPerType
parameter_list|()
block|{
name|QNetworkProxy
name|proxy
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|TunnelingCapability
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|HostNameLookupCapability
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
argument_list|)
expr_stmt|;
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
expr_stmt|;
comment|// verify that the capabilities changed
name|QVERIFY
argument_list|(
operator|!
operator|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|HostNameLookupCapability
operator|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
argument_list|)
expr_stmt|;
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|HttpProxy
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|HostNameLookupCapability
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
operator|(
name|proxy
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
operator|)
argument_list|)
expr_stmt|;
comment|// now set the capabilities on stone:
name|proxy
operator|.
name|setCapabilities
argument_list|(
name|QNetworkProxy
operator|::
name|TunnelingCapability
operator||
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
argument_list|,
name|QNetworkProxy
operator|::
name|TunnelingCapability
operator||
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
argument_list|)
expr_stmt|;
comment|// changing the type shouldn't change the capabilities any more
name|proxy
operator|.
name|setType
argument_list|(
name|QNetworkProxy
operator|::
name|Socks5Proxy
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|proxy
operator|.
name|capabilities
argument_list|()
argument_list|,
name|QNetworkProxy
operator|::
name|TunnelingCapability
operator||
name|QNetworkProxy
operator|::
name|UdpTunnelingCapability
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QNetworkProxy
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qnetworkproxy.moc"
end_include
end_unit
