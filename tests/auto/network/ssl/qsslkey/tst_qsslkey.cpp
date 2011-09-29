begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qsslkey.h>
end_include
begin_include
include|#
directive|include
file|<qsslsocket.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkproxy.h>
end_include
begin_class
DECL|class|tst_QSslKey
class|class
name|tst_QSslKey
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|struct|KeyInfo
struct|struct
name|KeyInfo
block|{
DECL|member|fileInfo
name|QFileInfo
name|fileInfo
decl_stmt|;
DECL|member|algorithm
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
decl_stmt|;
DECL|member|type
name|QSsl
operator|::
name|KeyType
name|type
decl_stmt|;
DECL|member|length
name|int
name|length
decl_stmt|;
DECL|member|format
name|QSsl
operator|::
name|EncodingFormat
name|format
decl_stmt|;
DECL|function|KeyInfo
name|KeyInfo
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|,
name|QSsl
operator|::
name|KeyAlgorithm
name|algorithm
parameter_list|,
name|QSsl
operator|::
name|KeyType
name|type
parameter_list|,
name|int
name|length
parameter_list|,
name|QSsl
operator|::
name|EncodingFormat
name|format
parameter_list|)
member_init_list|:
name|fileInfo
argument_list|(
name|fileInfo
argument_list|)
member_init_list|,
name|algorithm
argument_list|(
name|algorithm
argument_list|)
member_init_list|,
name|type
argument_list|(
name|type
argument_list|)
member_init_list|,
name|length
argument_list|(
name|length
argument_list|)
member_init_list|,
name|format
argument_list|(
name|format
argument_list|)
block|{}
block|}
struct|;
DECL|member|keyInfoList
name|QList
argument_list|<
name|KeyInfo
argument_list|>
name|keyInfoList
decl_stmt|;
name|void
name|createPlainTestRows
parameter_list|()
function_decl|;
public|public:
name|tst_QSslKey
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSslKey
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase_data
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
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
private|private
name|slots
private|:
name|void
name|emptyConstructor
parameter_list|()
function_decl|;
name|void
name|constructor_data
parameter_list|()
function_decl|;
name|void
name|constructor
parameter_list|()
function_decl|;
name|void
name|copyAndAssign_data
parameter_list|()
function_decl|;
name|void
name|copyAndAssign
parameter_list|()
function_decl|;
name|void
name|equalsOperator
parameter_list|()
function_decl|;
name|void
name|length_data
parameter_list|()
function_decl|;
name|void
name|length
parameter_list|()
function_decl|;
name|void
name|toPemOrDer_data
parameter_list|()
function_decl|;
name|void
name|toPemOrDer
parameter_list|()
function_decl|;
name|void
name|toEncryptedPemOrDer_data
parameter_list|()
function_decl|;
name|void
name|toEncryptedPemOrDer
parameter_list|()
function_decl|;
name|void
name|passphraseChecks
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSslKey
name|tst_QSslKey
operator|::
name|tst_QSslKey
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_MAC
comment|// applicationDirPath() points to a path inside the app bundle on Mac.
name|QDir
name|dir
argument_list|(
name|qApp
operator|->
name|applicationDirPath
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/../../../keys"
argument_list|)
argument_list|)
decl_stmt|;
else|#
directive|else
name|QDir
name|dir
argument_list|(
name|SRCDIR
operator|+
name|QLatin1String
argument_list|(
literal|"/keys"
argument_list|)
argument_list|)
decl_stmt|;
comment|// prefer this way to avoid ifdeffery and support shadow builds?
endif|#
directive|endif
name|QFileInfoList
name|fileInfoList
init|=
name|dir
operator|.
name|entryInfoList
argument_list|(
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Readable
argument_list|)
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
name|QLatin1String
argument_list|(
literal|"^(rsa|dsa)-(pub|pri)-(\\d+)\\.(pem|der)$"
argument_list|)
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QFileInfo
name|fileInfo
decl|,
name|fileInfoList
control|)
block|{
if|if
condition|(
name|rx
operator|.
name|indexIn
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
operator|>=
literal|0
condition|)
name|keyInfoList
operator|<<
name|KeyInfo
argument_list|(
name|fileInfo
argument_list|,
name|rx
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|==
name|QLatin1String
argument_list|(
literal|"rsa"
argument_list|)
condition|?
name|QSsl
operator|::
name|Rsa
else|:
name|QSsl
operator|::
name|Dsa
argument_list|,
name|rx
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1String
argument_list|(
literal|"pub"
argument_list|)
condition|?
name|QSsl
operator|::
name|PublicKey
else|:
name|QSsl
operator|::
name|PrivateKey
argument_list|,
name|rx
operator|.
name|cap
argument_list|(
literal|3
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|rx
operator|.
name|cap
argument_list|(
literal|4
argument_list|)
operator|==
name|QLatin1String
argument_list|(
literal|"pem"
argument_list|)
condition|?
name|QSsl
operator|::
name|Pem
else|:
name|QSsl
operator|::
name|Der
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~tst_QSslKey
name|tst_QSslKey
operator|::
name|~
name|tst_QSslKey
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase_data
name|void
name|tst_QSslKey
operator|::
name|initTestCase_data
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QSslKey
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSslKey
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|readFile
specifier|static
name|QByteArray
name|readFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|absFilePath
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QWARN
argument_list|(
literal|"failed to open file"
argument_list|)
expr_stmt|;
return|return
name|QByteArray
argument_list|()
return|;
block|}
return|return
name|file
operator|.
name|readAll
argument_list|()
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENSSL
end_ifndef
begin_function
DECL|function|emptyConstructor
name|void
name|tst_QSslKey
operator|::
name|emptyConstructor
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QSslKey
name|key
decl_stmt|;
name|QVERIFY
argument_list|(
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|key
operator|.
name|length
argument_list|()
operator|<
literal|0
argument_list|)
expr_stmt|;
name|QSslKey
name|key2
decl_stmt|;
name|QCOMPARE
argument_list|(
name|key
argument_list|,
name|key2
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QSsl::KeyAlgorithm
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QSsl::KeyType
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QSsl::EncodingFormat
argument_list|)
end_macro
begin_function
DECL|function|createPlainTestRows
name|void
name|tst_QSslKey
operator|::
name|createPlainTestRows
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"absFilePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|>
argument_list|(
literal|"algorithm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|KeyType
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"length"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|EncodingFormat
argument_list|>
argument_list|(
literal|"format"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|KeyInfo
name|keyInfo
decl|,
name|keyInfoList
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|keyInfo
operator|.
name|fileInfo
operator|.
name|fileName
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|<<
name|keyInfo
operator|.
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
operator|<<
name|keyInfo
operator|.
name|algorithm
operator|<<
name|keyInfo
operator|.
name|type
operator|<<
name|keyInfo
operator|.
name|length
operator|<<
name|keyInfo
operator|.
name|format
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|constructor_data
name|void
name|tst_QSslKey
operator|::
name|constructor_data
parameter_list|()
block|{
name|createPlainTestRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|constructor
name|void
name|tst_QSslKey
operator|::
name|constructor
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|absFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|EncodingFormat
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QByteArray
name|encoded
init|=
name|readFile
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
name|QSslKey
name|key
argument_list|(
name|encoded
argument_list|,
name|algorithm
argument_list|,
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copyAndAssign_data
name|void
name|tst_QSslKey
operator|::
name|copyAndAssign_data
parameter_list|()
block|{
name|createPlainTestRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copyAndAssign
name|void
name|tst_QSslKey
operator|::
name|copyAndAssign
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|absFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|EncodingFormat
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QByteArray
name|encoded
init|=
name|readFile
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
name|QSslKey
name|key
argument_list|(
name|encoded
argument_list|,
name|algorithm
argument_list|,
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QSslKey
name|copied
argument_list|(
name|key
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|key
argument_list|,
name|copied
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|algorithm
argument_list|()
argument_list|,
name|copied
operator|.
name|algorithm
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|type
argument_list|()
argument_list|,
name|copied
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|length
argument_list|()
argument_list|,
name|copied
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|toPem
argument_list|()
argument_list|,
name|copied
operator|.
name|toPem
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|toDer
argument_list|()
argument_list|,
name|copied
operator|.
name|toDer
argument_list|()
argument_list|)
expr_stmt|;
name|QSslKey
name|assigned
init|=
name|key
decl_stmt|;
name|QCOMPARE
argument_list|(
name|key
argument_list|,
name|assigned
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|algorithm
argument_list|()
argument_list|,
name|assigned
operator|.
name|algorithm
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|type
argument_list|()
argument_list|,
name|assigned
operator|.
name|type
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|length
argument_list|()
argument_list|,
name|assigned
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|toPem
argument_list|()
argument_list|,
name|assigned
operator|.
name|toPem
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|toDer
argument_list|()
argument_list|,
name|assigned
operator|.
name|toDer
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|equalsOperator
name|void
name|tst_QSslKey
operator|::
name|equalsOperator
parameter_list|()
block|{
comment|// ### unimplemented
block|}
end_function
begin_function
DECL|function|length_data
name|void
name|tst_QSslKey
operator|::
name|length_data
parameter_list|()
block|{
name|createPlainTestRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|length
name|void
name|tst_QSslKey
operator|::
name|length
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|absFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|EncodingFormat
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QByteArray
name|encoded
init|=
name|readFile
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
name|QSslKey
name|key
argument_list|(
name|encoded
argument_list|,
name|algorithm
argument_list|,
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|key
operator|.
name|length
argument_list|()
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toPemOrDer_data
name|void
name|tst_QSslKey
operator|::
name|toPemOrDer_data
parameter_list|()
block|{
name|createPlainTestRows
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toPemOrDer
name|void
name|tst_QSslKey
operator|::
name|toPemOrDer
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|absFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|EncodingFormat
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QByteArray
name|encoded
init|=
name|readFile
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
name|QSslKey
name|key
argument_list|(
name|encoded
argument_list|,
name|algorithm
argument_list|,
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QSsl
operator|::
name|Pem
condition|)
name|encoded
operator|.
name|replace
argument_list|(
literal|'\r'
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|format
operator|==
name|QSsl
operator|::
name|Pem
condition|?
name|key
operator|.
name|toPem
argument_list|()
else|:
name|key
operator|.
name|toDer
argument_list|()
argument_list|,
name|encoded
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toEncryptedPemOrDer_data
name|void
name|tst_QSslKey
operator|::
name|toEncryptedPemOrDer_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"absFilePath"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|>
argument_list|(
literal|"algorithm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|KeyType
argument_list|>
argument_list|(
literal|"type"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QSsl
operator|::
name|EncodingFormat
argument_list|>
argument_list|(
literal|"format"
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
name|QStringList
name|passwords
decl_stmt|;
name|passwords
operator|<<
literal|" "
operator|<<
literal|"foobar"
operator|<<
literal|"foo bar"
operator|<<
literal|"aAzZ`1234567890-=~!@#$%^&*()_+[]{}\\|;:'\",.<>/?"
expr_stmt|;
comment|// ### add more (?)
foreach|foreach
control|(
name|KeyInfo
name|keyInfo
decl|,
name|keyInfoList
control|)
block|{
foreach|foreach
control|(
name|QString
name|password
decl|,
name|passwords
control|)
block|{
name|QString
name|testName
init|=
name|QString
argument_list|(
literal|"%1-%2-%3-%4"
argument_list|)
operator|.
name|arg
argument_list|(
name|keyInfo
operator|.
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|keyInfo
operator|.
name|algorithm
operator|==
name|QSsl
operator|::
name|Rsa
condition|?
literal|"RSA"
else|:
literal|"DSA"
argument_list|)
operator|.
name|arg
argument_list|(
name|keyInfo
operator|.
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
condition|?
literal|"PrivateKey"
else|:
literal|"PublicKey"
argument_list|)
operator|.
name|arg
argument_list|(
name|keyInfo
operator|.
name|format
operator|==
name|QSsl
operator|::
name|Pem
condition|?
literal|"PEM"
else|:
literal|"DER"
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|testName
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|<<
name|keyInfo
operator|.
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
operator|<<
name|keyInfo
operator|.
name|algorithm
operator|<<
name|keyInfo
operator|.
name|type
operator|<<
name|keyInfo
operator|.
name|format
operator|<<
name|password
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|toEncryptedPemOrDer
name|void
name|tst_QSslKey
operator|::
name|toEncryptedPemOrDer
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSslSocket
operator|::
name|supportsSsl
argument_list|()
condition|)
return|return;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|absFilePath
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyAlgorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|KeyType
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QSsl
operator|::
name|EncodingFormat
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|password
argument_list|)
expr_stmt|;
name|QByteArray
name|plain
init|=
name|readFile
argument_list|(
name|absFilePath
argument_list|)
decl_stmt|;
name|QSslKey
name|key
argument_list|(
name|plain
argument_list|,
name|algorithm
argument_list|,
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|pwBytes
argument_list|(
name|password
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
condition|)
block|{
name|QByteArray
name|encryptedPem
init|=
name|key
operator|.
name|toPem
argument_list|(
name|pwBytes
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|encryptedPem
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QSslKey
name|keyPem
argument_list|(
name|encryptedPem
argument_list|,
name|algorithm
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|type
argument_list|,
name|pwBytes
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|keyPem
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|keyPem
argument_list|,
name|key
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|keyPem
operator|.
name|toPem
argument_list|()
argument_list|,
name|key
operator|.
name|toPem
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// verify that public keys are never encrypted by toPem()
name|QByteArray
name|encryptedPem
init|=
name|key
operator|.
name|toPem
argument_list|(
name|pwBytes
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|encryptedPem
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|plainPem
init|=
name|key
operator|.
name|toPem
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|plainPem
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|encryptedPem
argument_list|,
name|plainPem
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
condition|)
block|{
name|QByteArray
name|encryptedDer
init|=
name|key
operator|.
name|toDer
argument_list|(
name|pwBytes
argument_list|)
decl_stmt|;
comment|// ### at this point, encryptedDer is invalid, hence the below QEXPECT_FAILs
name|QVERIFY
argument_list|(
operator|!
name|encryptedDer
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QSslKey
name|keyDer
argument_list|(
name|encryptedDer
argument_list|,
name|algorithm
argument_list|,
name|QSsl
operator|::
name|Der
argument_list|,
name|type
argument_list|,
name|pwBytes
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
condition|)
name|QEXPECT_FAIL
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"We're not able to decrypt these yet..."
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|keyDer
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QSsl
operator|::
name|PrivateKey
condition|)
name|QEXPECT_FAIL
argument_list|(
name|QTest
operator|::
name|currentDataTag
argument_list|()
argument_list|,
literal|"We're not able to decrypt these yet..."
argument_list|,
name|Continue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|keyDer
operator|.
name|toPem
argument_list|()
argument_list|,
name|key
operator|.
name|toPem
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// verify that public keys are never encrypted by toDer()
name|QByteArray
name|encryptedDer
init|=
name|key
operator|.
name|toDer
argument_list|(
name|pwBytes
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|encryptedDer
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|plainDer
init|=
name|key
operator|.
name|toDer
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|plainDer
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|encryptedDer
argument_list|,
name|plainDer
argument_list|)
expr_stmt|;
block|}
comment|// ### add a test to verify that public keys are _decrypted_ correctly (by the ctor)
block|}
end_function
begin_function
DECL|function|passphraseChecks
name|void
name|tst_QSslKey
operator|::
name|passphraseChecks
parameter_list|()
block|{
block|{
name|QString
name|fileName
argument_list|(
name|SRCDIR
literal|"/rsa-with-passphrase.pem"
argument_list|)
decl_stmt|;
name|QFile
name|keyFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|keyFile
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// null passphrase => should not be able to decode key
block|}
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|,
literal|""
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// empty passphrase => should not be able to decode key
block|}
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|,
literal|"WRONG!"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// wrong passphrase => should not be able to decode key
block|}
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|,
literal|"123"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// correct passphrase
block|}
block|}
block|{
comment|// be sure and check a key without passphrase too
name|QString
name|fileName
argument_list|(
name|SRCDIR
literal|"/rsa-without-passphrase.pem"
argument_list|)
decl_stmt|;
name|QFile
name|keyFile
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// null passphrase => should be able to decode key
block|}
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|,
literal|""
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// empty passphrase => should be able to decode key
block|}
block|{
if|if
condition|(
operator|!
name|keyFile
operator|.
name|isOpen
argument_list|()
condition|)
name|keyFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|keyFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QSslKey
name|key
argument_list|(
operator|&
name|keyFile
argument_list|,
name|QSsl
operator|::
name|Rsa
argument_list|,
name|QSsl
operator|::
name|Pem
argument_list|,
name|QSsl
operator|::
name|PrivateKey
argument_list|,
literal|"xxx"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|key
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
comment|// passphrase given but key is not encrypted anyway => should work
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
argument|tst_QSslKey
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsslkey.moc"
end_include
end_unit
