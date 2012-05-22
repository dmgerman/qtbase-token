begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QAuthenticator>
end_include
begin_include
include|#
directive|include
file|<private/qauthenticator_p.h>
end_include
begin_class
DECL|class|tst_QAuthenticator
class|class
name|tst_QAuthenticator
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QAuthenticator
parameter_list|()
constructor_decl|;
private|private
name|Q_SLOTS
private|:
name|void
name|basicAuth
parameter_list|()
function_decl|;
name|void
name|basicAuth_data
parameter_list|()
function_decl|;
name|void
name|ntlmAuth_data
parameter_list|()
function_decl|;
name|void
name|ntlmAuth
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QAuthenticator
name|tst_QAuthenticator
operator|::
name|tst_QAuthenticator
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|basicAuth_data
name|void
name|tst_QAuthenticator
operator|::
name|basicAuth_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"realm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"user"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"password"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"expectedReply"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"just-user"
argument_list|)
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"foo"
operator|<<
literal|""
operator|<<
name|QByteArray
argument_list|(
literal|"foo:"
argument_list|)
operator|.
name|toBase64
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"user-password"
argument_list|)
operator|<<
literal|""
operator|<<
literal|""
operator|<<
literal|"foo"
operator|<<
literal|"bar"
operator|<<
name|QByteArray
argument_list|(
literal|"foo:bar"
argument_list|)
operator|.
name|toBase64
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"user-password-realm"
argument_list|)
operator|<<
literal|"realm=\"secure area\""
operator|<<
literal|"secure area"
operator|<<
literal|"foo"
operator|<<
literal|"bar"
operator|<<
name|QByteArray
argument_list|(
literal|"foo:bar"
argument_list|)
operator|.
name|toBase64
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|basicAuth
name|void
name|tst_QAuthenticator
operator|::
name|basicAuth
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|user
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|password
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|expectedReply
argument_list|)
expr_stmt|;
name|QAuthenticator
name|auth
decl_stmt|;
name|auth
operator|.
name|detach
argument_list|()
expr_stmt|;
name|QAuthenticatorPrivate
modifier|*
name|priv
init|=
name|QAuthenticatorPrivate
operator|::
name|getPrivate
argument_list|(
name|auth
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|priv
operator|->
name|phase
operator|==
name|QAuthenticatorPrivate
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|headers
decl_stmt|;
name|headers
operator|<<
name|qMakePair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
name|QByteArray
argument_list|(
literal|"WWW-Authenticate"
argument_list|)
argument_list|,
literal|"Basic "
operator|+
name|data
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
name|priv
operator|->
name|parseHttpResponse
argument_list|(
name|headers
argument_list|,
comment|/*isProxy = */
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|auth
operator|.
name|realm
argument_list|()
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|auth
operator|.
name|option
argument_list|(
literal|"realm"
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|auth
operator|.
name|setUser
argument_list|(
name|user
argument_list|)
expr_stmt|;
name|auth
operator|.
name|setPassword
argument_list|(
name|password
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|priv
operator|->
name|phase
operator|==
name|QAuthenticatorPrivate
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|priv
operator|->
name|calculateResponse
argument_list|(
literal|"GET"
argument_list|,
literal|"/"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"Basic "
operator|+
name|expectedReply
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ntlmAuth_data
name|void
name|tst_QAuthenticator
operator|::
name|ntlmAuth_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"realm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"sso"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no-realm"
argument_list|)
operator|<<
literal|"TlRMTVNTUAACAAAAHAAcADAAAAAFAoEATFZ3OLRQADIAAAAAAAAAAJYAlgBMAAAAUQBUAC0AVABFAFMAVAAtAEQATwBNAEEASQBOAAIAHABRAFQALQBUAEUAUwBUAC0ARABPAE0AQQBJAE4AAQAcAFEAVAAtAFQARQBTAFQALQBTAEUAUgBWAEUAUgAEABYAcQB0AC0AdABlAHMAdAAtAG4AZQB0AAMANABxAHQALQB0AGUAcwB0AC0AcwBlAHIAdgBlAHIALgBxAHQALQB0AGUAcwB0AC0AbgBlAHQAAAAAAA=="
operator|<<
literal|""
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"with-realm"
argument_list|)
operator|<<
literal|"TlRMTVNTUAACAAAADAAMADgAAAAFAoECWCZkccFFAzwAAAAAAAAAAL4AvgBEAAAABQLODgAAAA9NAEcARABOAE8ASwACAAwATQBHAEQATgBPAEsAAQAcAE4ATwBLAC0AQQBNAFMAUwBTAEYARQAtADAAMQAEACAAbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQADAD4AbgBvAGsALQBhAG0AcwBzAHMAZgBlAC0AMAAxAC4AbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQAFACAAbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQAAAAAA"
operator|<<
literal|"NOE"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no-realm-sso"
argument_list|)
operator|<<
literal|"TlRMTVNTUAACAAAAHAAcADAAAAAFAoEATFZ3OLRQADIAAAAAAAAAAJYAlgBMAAAAUQBUAC0AVABFAFMAVAAtAEQATwBNAEEASQBOAAIAHABRAFQALQBUAEUAUwBUAC0ARABPAE0AQQBJAE4AAQAcAFEAVAAtAFQARQBTAFQALQBTAEUAUgBWAEUAUgAEABYAcQB0AC0AdABlAHMAdAAtAG4AZQB0AAMANABxAHQALQB0AGUAcwB0AC0AcwBlAHIAdgBlAHIALgBxAHQALQB0AGUAcwB0AC0AbgBlAHQAAAAAAA=="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"with-realm-sso"
argument_list|)
operator|<<
literal|"TlRMTVNTUAACAAAADAAMADgAAAAFAoECWCZkccFFAzwAAAAAAAAAAL4AvgBEAAAABQLODgAAAA9NAEcARABOAE8ASwACAAwATQBHAEQATgBPAEsAAQAcAE4ATwBLAC0AQQBNAFMAUwBTAEYARQAtADAAMQAEACAAbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQADAD4AbgBvAGsALQBhAG0AcwBzAHMAZgBlAC0AMAAxAC4AbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQAFACAAbQBnAGQAbgBvAGsALgBuAG8AawBpAGEALgBjAG8AbQAAAAAA"
operator|<<
literal|"NOE"
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|ntlmAuth
name|void
name|tst_QAuthenticator
operator|::
name|ntlmAuth
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|sso
argument_list|)
expr_stmt|;
name|QAuthenticator
name|auth
decl_stmt|;
if|if
condition|(
operator|!
name|sso
condition|)
block|{
name|auth
operator|.
name|setUser
argument_list|(
literal|"unimportant"
argument_list|)
expr_stmt|;
name|auth
operator|.
name|setPassword
argument_list|(
literal|"unimportant"
argument_list|)
expr_stmt|;
block|}
name|auth
operator|.
name|detach
argument_list|()
expr_stmt|;
name|QAuthenticatorPrivate
modifier|*
name|priv
init|=
name|QAuthenticatorPrivate
operator|::
name|getPrivate
argument_list|(
name|auth
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|priv
operator|->
name|phase
operator|==
name|QAuthenticatorPrivate
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
name|headers
decl_stmt|;
comment|// NTLM phase 1: negotiate
comment|// This phase of NTLM contains no information, other than what we're willing to negotiate
comment|// Current implementation uses flags:
comment|//  NTLMSSP_NEGOTIATE_UNICODE | NTLMSSP_NEGOTIATE_NTLM | NTLMSSP_REQUEST_TARGET
name|headers
operator|<<
name|qMakePair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
literal|"WWW-Authenticate"
argument_list|,
literal|"NTLM"
argument_list|)
expr_stmt|;
name|priv
operator|->
name|parseHttpResponse
argument_list|(
name|headers
argument_list|,
comment|/*isProxy = */
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|sso
condition|)
name|QVERIFY
argument_list|(
name|priv
operator|->
name|calculateResponse
argument_list|(
literal|"GET"
argument_list|,
literal|"/"
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"NTLM "
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|QCOMPARE
argument_list|(
name|priv
operator|->
name|calculateResponse
argument_list|(
literal|"GET"
argument_list|,
literal|"/"
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
literal|"NTLM TlRMTVNTUAABAAAABQIAAAAAAAAAAAAAAAAAAAAAAAA="
argument_list|)
expr_stmt|;
comment|// NTLM phase 2: challenge
name|headers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|headers
operator|<<
name|qMakePair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|(
name|QByteArray
argument_list|(
literal|"WWW-Authenticate"
argument_list|)
argument_list|,
literal|"NTLM "
operator|+
name|data
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
name|priv
operator|->
name|parseHttpResponse
argument_list|(
name|headers
argument_list|,
comment|/*isProxy = */
literal|false
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|"with-realm"
argument_list|,
literal|"NTLM authentication code doesn't extract the realm"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QEXPECT_FAIL
argument_list|(
literal|"with-realm-sso"
argument_list|,
literal|"NTLM authentication code doesn't extract the realm"
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|auth
operator|.
name|realm
argument_list|()
argument_list|,
name|realm
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|priv
operator|->
name|calculateResponse
argument_list|(
literal|"GET"
argument_list|,
literal|"/"
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"NTLM "
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QAuthenticator
name|QTEST_MAIN
argument_list|(
name|tst_QAuthenticator
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qauthenticator.moc"
end_include
end_unit
