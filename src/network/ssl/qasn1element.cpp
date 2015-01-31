begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qasn1element_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|OidNameMap
typedef|typedef
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
name|OidNameMap
typedef|;
end_typedef
begin_function
DECL|function|createOidMap
specifier|static
name|OidNameMap
name|createOidMap
parameter_list|()
block|{
name|OidNameMap
name|oids
decl_stmt|;
comment|// used by unit tests
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"0.9.2342.19200300.100.1.5"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"favouriteDrink"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.2.840.113549.1.9.1"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"emailAddress"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.6.1.5.5.7.1.1"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"authorityInfoAccess"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.6.1.5.5.7.48.1"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"OCSP"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"1.3.6.1.5.5.7.48.2"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"caIssuers"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.29.14"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"subjectKeyIdentifier"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.29.15"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"keyUsage"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.29.17"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"subjectAltName"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.29.19"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"basicConstraints"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.29.35"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"authorityKeyIdentifier"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.10"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"O"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.11"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"OU"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.12"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"title"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.13"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"description"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.17"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"postalCode"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.3"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"CN"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.4"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"SN"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.41"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.42"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"GN"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.43"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"initials"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.46"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"dnQualifier"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.5"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"serialNumber"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.6"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"C"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.7"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"L"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.8"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"ST"
argument_list|)
argument_list|)
expr_stmt|;
name|oids
operator|.
name|insert
argument_list|(
name|oids
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"2.5.4.9"
argument_list|)
argument_list|,
name|QByteArrayLiteral
argument_list|(
literal|"street"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|oids
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|OidNameMap
argument_list|,
argument|oidNameMap
argument_list|,
argument|(createOidMap())
argument_list|)
end_macro
begin_constructor
DECL|function|QAsn1Element
name|QAsn1Element
operator|::
name|QAsn1Element
parameter_list|(
name|quint8
name|type
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
member_init_list|:
name|mType
argument_list|(
name|type
argument_list|)
member_init_list|,
name|mValue
argument_list|(
name|value
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|read
name|bool
name|QAsn1Element
operator|::
name|read
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|)
block|{
comment|// type
name|quint8
name|tmpType
decl_stmt|;
name|stream
operator|>>
name|tmpType
expr_stmt|;
if|if
condition|(
operator|!
name|tmpType
condition|)
return|return
literal|false
return|;
comment|// length
name|qint64
name|length
init|=
literal|0
decl_stmt|;
name|quint8
name|first
decl_stmt|;
name|stream
operator|>>
name|first
expr_stmt|;
if|if
condition|(
name|first
operator|&
literal|0x80
condition|)
block|{
comment|// long form
specifier|const
name|quint8
name|bytes
init|=
operator|(
name|first
operator|&
literal|0x7f
operator|)
decl_stmt|;
if|if
condition|(
name|bytes
operator|>
literal|7
condition|)
return|return
literal|false
return|;
name|quint8
name|b
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bytes
condition|;
name|i
operator|++
control|)
block|{
name|stream
operator|>>
name|b
expr_stmt|;
name|length
operator|=
operator|(
name|length
operator|<<
literal|8
operator|)
operator||
name|b
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// short form
name|length
operator|=
operator|(
name|first
operator|&
literal|0x7f
operator|)
expr_stmt|;
block|}
comment|// value
name|QByteArray
name|tmpValue
decl_stmt|;
name|tmpValue
operator|.
name|resize
argument_list|(
name|length
argument_list|)
expr_stmt|;
name|int
name|count
init|=
name|stream
operator|.
name|readRawData
argument_list|(
name|tmpValue
operator|.
name|data
argument_list|()
argument_list|,
name|tmpValue
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|count
operator|!=
name|length
condition|)
return|return
literal|false
return|;
name|mType
operator|=
name|tmpType
expr_stmt|;
name|mValue
operator|.
name|swap
argument_list|(
name|tmpValue
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|read
name|bool
name|QAsn1Element
operator|::
name|read
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QDataStream
name|stream
argument_list|(
name|data
argument_list|)
decl_stmt|;
return|return
name|read
argument_list|(
name|stream
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|write
name|void
name|QAsn1Element
operator|::
name|write
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|)
specifier|const
block|{
comment|// type
name|stream
operator|<<
name|mType
expr_stmt|;
comment|// length
name|qint64
name|length
init|=
name|mValue
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|length
operator|>=
literal|128
condition|)
block|{
comment|// long form
name|quint8
name|encodedLength
init|=
literal|0x80
decl_stmt|;
name|QByteArray
name|ba
decl_stmt|;
while|while
condition|(
name|length
condition|)
block|{
name|ba
operator|.
name|prepend
argument_list|(
name|quint8
argument_list|(
operator|(
name|length
operator|&
literal|0xff
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|length
operator|>>=
literal|8
expr_stmt|;
name|encodedLength
operator|+=
literal|1
expr_stmt|;
block|}
name|stream
operator|<<
name|encodedLength
expr_stmt|;
name|stream
operator|.
name|writeRawData
argument_list|(
name|ba
operator|.
name|data
argument_list|()
argument_list|,
name|ba
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// short form
name|stream
operator|<<
name|quint8
argument_list|(
name|length
argument_list|)
expr_stmt|;
block|}
comment|// value
name|stream
operator|.
name|writeRawData
argument_list|(
name|mValue
operator|.
name|data
argument_list|()
argument_list|,
name|mValue
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fromBool
name|QAsn1Element
name|QAsn1Element
operator|::
name|fromBool
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
return|return
name|QAsn1Element
argument_list|(
name|QAsn1Element
operator|::
name|BooleanType
argument_list|,
name|QByteArray
argument_list|(
literal|1
argument_list|,
name|val
condition|?
literal|0xff
else|:
literal|0x00
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fromInteger
name|QAsn1Element
name|QAsn1Element
operator|::
name|fromInteger
parameter_list|(
name|unsigned
name|int
name|val
parameter_list|)
block|{
name|QAsn1Element
name|elem
argument_list|(
name|QAsn1Element
operator|::
name|IntegerType
argument_list|)
decl_stmt|;
while|while
condition|(
name|val
operator|>
literal|127
condition|)
block|{
name|elem
operator|.
name|mValue
operator|.
name|prepend
argument_list|(
name|val
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|val
operator|>>=
literal|8
expr_stmt|;
block|}
name|elem
operator|.
name|mValue
operator|.
name|prepend
argument_list|(
name|val
operator|&
literal|0x7f
argument_list|)
expr_stmt|;
return|return
name|elem
return|;
block|}
end_function
begin_function
DECL|function|fromVector
name|QAsn1Element
name|QAsn1Element
operator|::
name|fromVector
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
modifier|&
name|items
parameter_list|)
block|{
name|QAsn1Element
name|seq
decl_stmt|;
name|seq
operator|.
name|mType
operator|=
name|SequenceType
expr_stmt|;
name|QDataStream
name|stream
argument_list|(
operator|&
name|seq
operator|.
name|mValue
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
for|for
control|(
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|items
operator|.
name|cbegin
argument_list|()
init|,
name|end
init|=
name|items
operator|.
name|cend
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
name|it
operator|->
name|write
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|seq
return|;
block|}
end_function
begin_function
DECL|function|fromObjectId
name|QAsn1Element
name|QAsn1Element
operator|::
name|fromObjectId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
name|QAsn1Element
name|elem
decl_stmt|;
name|elem
operator|.
name|mType
operator|=
name|ObjectIdentifierType
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|bits
init|=
name|id
operator|.
name|split
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|bits
operator|.
name|size
argument_list|()
operator|>
literal|2
argument_list|)
expr_stmt|;
name|elem
operator|.
name|mValue
operator|+=
name|quint8
argument_list|(
operator|(
name|bits
index|[
literal|0
index|]
operator|.
name|toUInt
argument_list|()
operator|*
literal|40
operator|+
name|bits
index|[
literal|1
index|]
operator|.
name|toUInt
argument_list|()
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|2
init|;
name|i
operator|<
name|bits
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|char
name|buffer
index|[
name|std
operator|::
name|numeric_limits
argument_list|<
name|unsigned
name|int
argument_list|>
operator|::
name|digits
operator|/
literal|7
operator|+
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|pBuffer
init|=
name|buffer
operator|+
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
operator|*
operator|--
name|pBuffer
operator|=
literal|'\0'
expr_stmt|;
name|unsigned
name|int
name|node
init|=
name|bits
index|[
name|i
index|]
operator|.
name|toUInt
argument_list|()
decl_stmt|;
operator|*
operator|--
name|pBuffer
operator|=
name|quint8
argument_list|(
operator|(
name|node
operator|&
literal|0x7f
operator|)
argument_list|)
expr_stmt|;
name|node
operator|>>=
literal|7
expr_stmt|;
while|while
condition|(
name|node
condition|)
block|{
operator|*
operator|--
name|pBuffer
operator|=
name|quint8
argument_list|(
operator|(
operator|(
name|node
operator|&
literal|0x7f
operator|)
operator||
literal|0x80
operator|)
argument_list|)
expr_stmt|;
name|node
operator|>>=
literal|7
expr_stmt|;
block|}
name|elem
operator|.
name|mValue
operator|+=
name|pBuffer
expr_stmt|;
block|}
return|return
name|elem
return|;
block|}
end_function
begin_function
DECL|function|toBool
name|bool
name|QAsn1Element
operator|::
name|toBool
parameter_list|(
name|bool
modifier|*
name|ok
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|*
name|this
operator|==
name|fromBool
argument_list|(
literal|true
argument_list|)
condition|)
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
operator|*
name|this
operator|==
name|fromBool
argument_list|(
literal|false
argument_list|)
condition|)
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
return|return
literal|false
return|;
block|}
else|else
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
end_function
begin_function
DECL|function|toDateTime
name|QDateTime
name|QAsn1Element
operator|::
name|toDateTime
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|mValue
operator|.
name|endsWith
argument_list|(
literal|'Z'
argument_list|)
condition|)
block|{
if|if
condition|(
name|mType
operator|==
name|UtcTimeType
operator|&&
name|mValue
operator|.
name|size
argument_list|()
operator|==
literal|13
condition|)
return|return
name|QDateTime
argument_list|(
name|QDate
argument_list|(
literal|2000
operator|+
name|mValue
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|4
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|,
name|QTime
argument_list|(
name|mValue
operator|.
name|mid
argument_list|(
literal|6
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|8
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|10
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|UTC
argument_list|)
return|;
elseif|else
if|if
condition|(
name|mType
operator|==
name|GeneralizedTimeType
operator|&&
name|mValue
operator|.
name|size
argument_list|()
operator|==
literal|15
condition|)
return|return
name|QDateTime
argument_list|(
name|QDate
argument_list|(
name|mValue
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|4
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|6
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|,
name|QTime
argument_list|(
name|mValue
operator|.
name|mid
argument_list|(
literal|8
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|10
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|mValue
operator|.
name|mid
argument_list|(
literal|12
argument_list|,
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|UTC
argument_list|)
return|;
block|}
return|return
name|QDateTime
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|toInfo
name|QMultiMap
argument_list|<
name|QByteArray
argument_list|,
name|QString
argument_list|>
name|QAsn1Element
operator|::
name|toInfo
parameter_list|()
specifier|const
block|{
name|QMultiMap
argument_list|<
name|QByteArray
argument_list|,
name|QString
argument_list|>
name|info
decl_stmt|;
name|QAsn1Element
name|elem
decl_stmt|;
name|QDataStream
name|issuerStream
argument_list|(
name|mValue
argument_list|)
decl_stmt|;
while|while
condition|(
name|elem
operator|.
name|read
argument_list|(
name|issuerStream
argument_list|)
operator|&&
name|elem
operator|.
name|mType
operator|==
name|QAsn1Element
operator|::
name|SetType
condition|)
block|{
name|QAsn1Element
name|issuerElem
decl_stmt|;
name|QDataStream
name|setStream
argument_list|(
name|elem
operator|.
name|mValue
argument_list|)
decl_stmt|;
if|if
condition|(
name|issuerElem
operator|.
name|read
argument_list|(
name|setStream
argument_list|)
operator|&&
name|issuerElem
operator|.
name|mType
operator|==
name|QAsn1Element
operator|::
name|SequenceType
condition|)
block|{
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|elems
init|=
name|issuerElem
operator|.
name|toVector
argument_list|()
decl_stmt|;
if|if
condition|(
name|elems
operator|.
name|size
argument_list|()
operator|==
literal|2
condition|)
block|{
specifier|const
name|QByteArray
name|key
init|=
name|elems
operator|.
name|front
argument_list|()
operator|.
name|toObjectName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|key
operator|.
name|isEmpty
argument_list|()
condition|)
name|info
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|elems
operator|.
name|back
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|info
return|;
block|}
end_function
begin_function
DECL|function|toInteger
name|qint64
name|QAsn1Element
operator|::
name|toInteger
parameter_list|(
name|bool
modifier|*
name|ok
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mType
operator|!=
name|QAsn1Element
operator|::
name|IntegerType
operator|||
name|mValue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|// NOTE: negative numbers are not handled
if|if
condition|(
name|mValue
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|&
literal|0x80
condition|)
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|0
return|;
block|}
name|qint64
name|value
init|=
name|mValue
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|&
literal|0x7f
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|mValue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|value
operator|=
operator|(
name|value
operator|<<
literal|8
operator|)
operator||
name|quint8
argument_list|(
name|mValue
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
return|return
name|value
return|;
block|}
end_function
begin_function
DECL|function|toVector
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|QAsn1Element
operator|::
name|toVector
parameter_list|()
specifier|const
block|{
name|QVector
argument_list|<
name|QAsn1Element
argument_list|>
name|items
decl_stmt|;
if|if
condition|(
name|mType
operator|==
name|SequenceType
condition|)
block|{
name|QAsn1Element
name|elem
decl_stmt|;
name|QDataStream
name|stream
argument_list|(
name|mValue
argument_list|)
decl_stmt|;
while|while
condition|(
name|elem
operator|.
name|read
argument_list|(
name|stream
argument_list|)
condition|)
name|items
operator|<<
name|elem
expr_stmt|;
block|}
return|return
name|items
return|;
block|}
end_function
begin_function
DECL|function|toObjectId
name|QByteArray
name|QAsn1Element
operator|::
name|toObjectId
parameter_list|()
specifier|const
block|{
name|QByteArray
name|key
decl_stmt|;
if|if
condition|(
name|mType
operator|==
name|ObjectIdentifierType
operator|&&
operator|!
name|mValue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|quint8
name|b
init|=
name|mValue
index|[
literal|0
index|]
decl_stmt|;
name|key
operator|+=
name|QByteArray
operator|::
name|number
argument_list|(
name|b
operator|/
literal|40
argument_list|)
operator|+
literal|'.'
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|b
operator|%
literal|40
argument_list|)
expr_stmt|;
name|unsigned
name|int
name|val
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|mValue
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|b
operator|=
name|mValue
index|[
name|i
index|]
expr_stmt|;
name|val
operator|=
operator|(
name|val
operator|<<
literal|7
operator|)
operator||
operator|(
name|b
operator|&
literal|0x7f
operator|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|b
operator|&
literal|0x80
operator|)
condition|)
block|{
name|key
operator|+=
literal|'.'
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|val
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
return|return
name|key
return|;
block|}
end_function
begin_function
DECL|function|toObjectName
name|QByteArray
name|QAsn1Element
operator|::
name|toObjectName
parameter_list|()
specifier|const
block|{
name|QByteArray
name|key
init|=
name|toObjectId
argument_list|()
decl_stmt|;
return|return
name|oidNameMap
operator|->
name|value
argument_list|(
name|key
argument_list|,
name|key
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|QAsn1Element
operator|::
name|toString
parameter_list|()
specifier|const
block|{
comment|// Detect embedded NULs and reject
if|if
condition|(
name|qstrlen
argument_list|(
name|mValue
argument_list|)
operator|<
name|uint
argument_list|(
name|mValue
operator|.
name|size
argument_list|()
argument_list|)
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|mType
operator|==
name|PrintableStringType
operator|||
name|mType
operator|==
name|TeletexStringType
operator|||
name|mType
operator|==
name|Rfc822NameType
operator|||
name|mType
operator|==
name|DnsNameType
operator|||
name|mType
operator|==
name|UniformResourceIdentifierType
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mValue
argument_list|,
name|mValue
operator|.
name|size
argument_list|()
argument_list|)
return|;
if|if
condition|(
name|mType
operator|==
name|Utf8StringType
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|mValue
argument_list|,
name|mValue
operator|.
name|size
argument_list|()
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
