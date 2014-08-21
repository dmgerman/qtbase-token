begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qsslconfiguration.h>
end_include
begin_include
include|#
directive|include
file|<qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|"../../../../auto/network-settings.h"
end_include
begin_class
DECL|class|tst_QSslSocket
class|class
name|tst_QSslSocket
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSslSocket
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSslSocket
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|rootCertLoading
parameter_list|()
function_decl|;
name|void
name|systemCaCertificates
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSslSocket
name|tst_QSslSocket
operator|::
name|tst_QSslSocket
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSslSocket
name|tst_QSslSocket
operator|::
name|~
name|tst_QSslSocket
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QSslSocket
operator|::
name|initTestCase
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|QtNetworkSettings
operator|::
name|verifyTestNetworkSettings
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QSslSocket
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSslSocket
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_comment
comment|//----------------------------------------------------------------------------------
end_comment
begin_function
DECL|function|rootCertLoading
name|void
name|tst_QSslSocket
operator|::
name|rootCertLoading
parameter_list|()
block|{
name|QBENCHMARK_ONCE
block|{
name|QSslSocket
name|socket
decl_stmt|;
name|socket
operator|.
name|connectToHostEncrypted
argument_list|(
name|QtNetworkSettings
operator|::
name|serverName
argument_list|()
argument_list|,
literal|443
argument_list|)
expr_stmt|;
name|socket
operator|.
name|waitForEncrypted
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|systemCaCertificates
name|void
name|tst_QSslSocket
operator|::
name|systemCaCertificates
parameter_list|()
block|{
comment|// The results of this test change if the benchmarking system changes too much.
comment|// Therefore this benchmark is only good for manual regression checking between
comment|// Qt versions.
name|QBENCHMARK_ONCE
block|{
name|QList
argument_list|<
name|QSslCertificate
argument_list|>
name|list
init|=
name|QSslSocket
operator|::
name|systemCaCertificates
argument_list|()
decl_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSslSocket
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsslsocket.moc"
end_include
end_unit
