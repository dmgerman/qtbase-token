begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qipaddress_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qlocale_tools_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtools_p.h"
end_include
begin_include
include|#
directive|include
file|"qvarlengtharray.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QIPAddressUtils
namespace|namespace
name|QIPAddressUtils
block|{
DECL|function|number
specifier|static
name|QString
name|number
parameter_list|(
name|quint8
name|val
parameter_list|,
name|int
name|base
init|=
literal|10
parameter_list|)
block|{
name|QChar
name|zero
argument_list|(
literal|0x30
argument_list|)
decl_stmt|;
return|return
name|val
condition|?
name|qulltoa
argument_list|(
name|val
argument_list|,
name|base
argument_list|,
name|zero
argument_list|)
else|:
name|zero
return|;
block|}
DECL|typedef|Buffer
typedef|typedef
name|QVarLengthArray
argument_list|<
name|char
argument_list|,
literal|64
argument_list|>
name|Buffer
typedef|;
DECL|function|checkedToAscii
specifier|static
specifier|const
name|QChar
modifier|*
name|checkedToAscii
parameter_list|(
name|Buffer
modifier|&
name|buffer
parameter_list|,
specifier|const
name|QChar
modifier|*
name|begin
parameter_list|,
specifier|const
name|QChar
modifier|*
name|end
parameter_list|)
block|{
specifier|const
name|ushort
modifier|*
specifier|const
name|ubegin
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|ushort
operator|*
argument_list|>
argument_list|(
name|begin
argument_list|)
decl_stmt|;
specifier|const
name|ushort
modifier|*
specifier|const
name|uend
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|ushort
operator|*
argument_list|>
argument_list|(
name|end
argument_list|)
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|src
init|=
name|ubegin
decl_stmt|;
name|buffer
operator|.
name|resize
argument_list|(
name|uend
operator|-
name|ubegin
operator|+
literal|1
argument_list|)
expr_stmt|;
name|char
modifier|*
name|dst
init|=
name|buffer
operator|.
name|data
argument_list|()
decl_stmt|;
while|while
condition|(
name|src
operator|!=
name|uend
condition|)
block|{
if|if
condition|(
operator|*
name|src
operator|>=
literal|0x7f
condition|)
return|return
cast|reinterpret_cast
argument_list|<
specifier|const
name|QChar
operator|*
argument_list|>
argument_list|(
name|src
argument_list|)
return|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|static
name|bool
name|parseIp4Internal
parameter_list|(
name|IPv4Address
modifier|&
name|address
parameter_list|,
specifier|const
name|char
modifier|*
name|ptr
parameter_list|,
name|bool
name|acceptLeadingZero
parameter_list|)
function_decl|;
DECL|function|parseIp4
name|bool
name|parseIp4
parameter_list|(
name|IPv4Address
modifier|&
name|address
parameter_list|,
specifier|const
name|QChar
modifier|*
name|begin
parameter_list|,
specifier|const
name|QChar
modifier|*
name|end
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|begin
operator|!=
name|end
argument_list|)
expr_stmt|;
name|Buffer
name|buffer
decl_stmt|;
if|if
condition|(
name|checkedToAscii
argument_list|(
name|buffer
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
condition|)
return|return
literal|false
return|;
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffer
operator|.
name|data
argument_list|()
decl_stmt|;
return|return
name|parseIp4Internal
argument_list|(
name|address
argument_list|,
name|ptr
argument_list|,
literal|true
argument_list|)
return|;
block|}
DECL|function|parseIp4Internal
specifier|static
name|bool
name|parseIp4Internal
parameter_list|(
name|IPv4Address
modifier|&
name|address
parameter_list|,
specifier|const
name|char
modifier|*
name|ptr
parameter_list|,
name|bool
name|acceptLeadingZero
parameter_list|)
block|{
name|address
operator|=
literal|0
expr_stmt|;
name|int
name|dotCount
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|dotCount
operator|<
literal|4
condition|)
block|{
if|if
condition|(
operator|!
name|acceptLeadingZero
operator|&&
operator|*
name|ptr
operator|==
literal|'0'
operator|&&
name|ptr
index|[
literal|1
index|]
operator|!=
literal|'.'
operator|&&
name|ptr
index|[
literal|1
index|]
operator|!=
literal|'\0'
condition|)
return|return
literal|false
return|;
specifier|const
name|char
modifier|*
name|endptr
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|quint64
name|ll
init|=
name|qstrtoull
argument_list|(
name|ptr
argument_list|,
operator|&
name|endptr
argument_list|,
literal|0
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|quint32
name|x
init|=
name|ll
decl_stmt|;
if|if
condition|(
operator|!
name|ok
operator|||
name|endptr
operator|==
name|ptr
operator|||
name|ll
operator|!=
name|x
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|*
name|endptr
operator|==
literal|'.'
operator|||
name|dotCount
operator|==
literal|3
condition|)
block|{
if|if
condition|(
name|x
operator|&
operator|~
literal|0xff
condition|)
return|return
literal|false
return|;
name|address
operator|<<=
literal|8
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dotCount
operator|==
literal|2
condition|)
block|{
if|if
condition|(
name|x
operator|&
operator|~
literal|0xffff
condition|)
return|return
literal|false
return|;
name|address
operator|<<=
literal|16
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dotCount
operator|==
literal|1
condition|)
block|{
if|if
condition|(
name|x
operator|&
operator|~
literal|0xffffff
condition|)
return|return
literal|false
return|;
name|address
operator|<<=
literal|24
expr_stmt|;
block|}
name|address
operator||=
name|x
expr_stmt|;
if|if
condition|(
name|dotCount
operator|==
literal|3
operator|&&
operator|*
name|endptr
operator|!=
literal|'\0'
condition|)
return|return
literal|false
return|;
elseif|else
if|if
condition|(
name|dotCount
operator|==
literal|3
operator|||
operator|*
name|endptr
operator|==
literal|'\0'
condition|)
return|return
literal|true
return|;
operator|++
name|dotCount
expr_stmt|;
name|ptr
operator|=
name|endptr
operator|+
literal|1
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|toString
name|void
name|toString
parameter_list|(
name|QString
modifier|&
name|appendTo
parameter_list|,
name|IPv4Address
name|address
parameter_list|)
block|{
comment|// reconstructing is easy
comment|// use the fast operator% that pre-calculates the size
name|appendTo
operator|+=
name|number
argument_list|(
name|address
operator|>>
literal|24
argument_list|)
operator|%
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|%
name|number
argument_list|(
name|address
operator|>>
literal|16
argument_list|)
operator|%
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|%
name|number
argument_list|(
name|address
operator|>>
literal|8
argument_list|)
operator|%
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
operator|%
name|number
argument_list|(
name|address
argument_list|)
expr_stmt|;
block|}
comment|/*!     \internal     \since 5.0      Parses one IPv6 address from \a begin to \a end and stores the     representation in \a address. Returns null if everything was parsed     correctly, or the pointer to the first bad character where parsing failed.     If the parsing failed for a reason not related to a particular character,     returns \a end. */
DECL|function|parseIp6
specifier|const
name|QChar
modifier|*
name|parseIp6
parameter_list|(
name|IPv6Address
modifier|&
name|address
parameter_list|,
specifier|const
name|QChar
modifier|*
name|begin
parameter_list|,
specifier|const
name|QChar
modifier|*
name|end
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|begin
operator|!=
name|end
argument_list|)
expr_stmt|;
name|Buffer
name|buffer
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|ret
init|=
name|checkedToAscii
argument_list|(
name|buffer
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
return|return
name|ret
return|;
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffer
operator|.
name|data
argument_list|()
decl_stmt|;
comment|// count the colons
name|int
name|colonCount
init|=
literal|0
decl_stmt|;
name|int
name|dotCount
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
block|{
if|if
condition|(
operator|*
name|ptr
operator|==
literal|':'
condition|)
operator|++
name|colonCount
expr_stmt|;
if|if
condition|(
operator|*
name|ptr
operator|==
literal|'.'
condition|)
operator|++
name|dotCount
expr_stmt|;
operator|++
name|ptr
expr_stmt|;
block|}
comment|// IPv4-in-IPv6 addresses are stricter in what they accept
if|if
condition|(
name|dotCount
operator|!=
literal|0
operator|&&
name|dotCount
operator|!=
literal|3
condition|)
return|return
name|end
return|;
name|memset
argument_list|(
name|address
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|address
argument_list|)
expr_stmt|;
if|if
condition|(
name|colonCount
operator|==
literal|2
operator|&&
name|end
operator|-
name|begin
operator|==
literal|2
condition|)
comment|// "::"
return|return
literal|0
return|;
comment|// if there's a double colon ("::"), this is how many zeroes it means
name|int
name|zeroWordsToFill
decl_stmt|;
name|ptr
operator|=
name|buffer
operator|.
name|data
argument_list|()
expr_stmt|;
comment|// there are two cases where 8 colons are allowed: at the ends
comment|// so test that before the colon-count test
if|if
condition|(
operator|(
name|ptr
index|[
literal|0
index|]
operator|==
literal|':'
operator|&&
name|ptr
index|[
literal|1
index|]
operator|==
literal|':'
operator|)
operator|||
operator|(
name|ptr
index|[
name|end
operator|-
name|begin
operator|-
literal|2
index|]
operator|==
literal|':'
operator|&&
name|ptr
index|[
name|end
operator|-
name|begin
operator|-
literal|1
index|]
operator|==
literal|':'
operator|)
condition|)
block|{
name|zeroWordsToFill
operator|=
literal|9
operator|-
name|colonCount
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|colonCount
argument_list|<
literal|2
operator|||
name|colonCount
argument_list|>
literal|7
condition|)
block|{
return|return
name|end
return|;
block|}
else|else
block|{
name|zeroWordsToFill
operator|=
literal|8
operator|-
name|colonCount
expr_stmt|;
block|}
if|if
condition|(
name|dotCount
condition|)
operator|--
name|zeroWordsToFill
expr_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|pos
operator|<
literal|15
condition|)
block|{
if|if
condition|(
operator|*
name|ptr
operator|==
literal|':'
condition|)
block|{
comment|// empty field, we hope it's "::"
if|if
condition|(
name|zeroWordsToFill
operator|<
literal|1
condition|)
return|return
name|begin
operator|+
operator|(
name|ptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
if|if
condition|(
name|pos
operator|==
literal|0
operator|||
name|pos
operator|==
name|colonCount
operator|*
literal|2
condition|)
block|{
if|if
condition|(
name|ptr
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|ptr
index|[
literal|1
index|]
operator|!=
literal|':'
condition|)
return|return
name|begin
operator|+
operator|(
name|ptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
operator|++
name|ptr
expr_stmt|;
block|}
name|pos
operator|+=
name|zeroWordsToFill
operator|*
literal|2
expr_stmt|;
name|zeroWordsToFill
operator|=
literal|0
expr_stmt|;
operator|++
name|ptr
expr_stmt|;
continue|continue;
block|}
specifier|const
name|char
modifier|*
name|endptr
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|quint64
name|ll
init|=
name|qstrtoull
argument_list|(
name|ptr
argument_list|,
operator|&
name|endptr
argument_list|,
literal|16
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
name|quint16
name|x
init|=
name|ll
decl_stmt|;
if|if
condition|(
operator|!
name|ok
operator|||
name|ll
operator|!=
name|x
condition|)
return|return
name|begin
operator|+
operator|(
name|ptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
if|if
condition|(
operator|*
name|endptr
operator|==
literal|'.'
condition|)
block|{
comment|// this could be an IPv4 address
comment|// it's only valid in the last element
if|if
condition|(
name|pos
operator|!=
literal|12
condition|)
return|return
name|begin
operator|+
operator|(
name|ptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
name|IPv4Address
name|ip4
decl_stmt|;
if|if
condition|(
operator|!
name|parseIp4Internal
argument_list|(
name|ip4
argument_list|,
name|ptr
argument_list|,
literal|false
argument_list|)
condition|)
return|return
name|begin
operator|+
operator|(
name|ptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
name|address
index|[
literal|12
index|]
operator|=
name|ip4
operator|>>
literal|24
expr_stmt|;
name|address
index|[
literal|13
index|]
operator|=
name|ip4
operator|>>
literal|16
expr_stmt|;
name|address
index|[
literal|14
index|]
operator|=
name|ip4
operator|>>
literal|8
expr_stmt|;
name|address
index|[
literal|15
index|]
operator|=
name|ip4
expr_stmt|;
return|return
literal|0
return|;
block|}
name|address
index|[
name|pos
operator|++
index|]
operator|=
name|x
operator|>>
literal|8
expr_stmt|;
name|address
index|[
name|pos
operator|++
index|]
operator|=
name|x
operator|&
literal|0xff
expr_stmt|;
if|if
condition|(
operator|*
name|endptr
operator|==
literal|'\0'
condition|)
break|break;
if|if
condition|(
operator|*
name|endptr
operator|!=
literal|':'
condition|)
return|return
name|begin
operator|+
operator|(
name|endptr
operator|-
name|buffer
operator|.
name|data
argument_list|()
operator|)
return|;
name|ptr
operator|=
name|endptr
operator|+
literal|1
expr_stmt|;
block|}
return|return
name|pos
operator|==
literal|16
condition|?
literal|0
else|:
name|end
return|;
block|}
DECL|function|toHex
specifier|static
specifier|inline
name|QChar
name|toHex
parameter_list|(
name|uchar
name|c
parameter_list|)
block|{
return|return
name|QtMiscUtils
operator|::
name|toHexLower
argument_list|(
name|c
argument_list|)
return|;
block|}
DECL|function|toString
name|void
name|toString
parameter_list|(
name|QString
modifier|&
name|appendTo
parameter_list|,
name|IPv6Address
name|address
parameter_list|)
block|{
comment|// the longest IPv6 address possible is:
comment|//   "1111:2222:3333:4444:5555:6666:255.255.255.255"
comment|// however, this function never generates that. The longest it does
comment|// generate without an IPv4 address is:
comment|//   "1111:2222:3333:4444:5555:6666:7777:8888"
comment|// and the longest with an IPv4 address is:
comment|//   "::ffff:255.255.255.255"
specifier|static
specifier|const
name|int
name|Ip6AddressMaxLen
init|=
sizeof|sizeof
expr|"1111:2222:3333:4444:5555:6666:7777:8888"
decl_stmt|;
specifier|static
specifier|const
name|int
name|Ip6WithIp4AddressMaxLen
init|=
sizeof|sizeof
expr|"::ffff:255.255.255.255"
decl_stmt|;
comment|// check for the special cases
specifier|const
name|quint64
name|zeroes
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|bool
name|embeddedIp4
init|=
literal|false
decl_stmt|;
comment|// we consider embedded IPv4 for:
comment|//  ::ffff:x.x.x.x
comment|//  ::x.x.x.y  except if the x are 0 too
if|if
condition|(
name|memcmp
argument_list|(
name|address
argument_list|,
name|zeroes
argument_list|,
literal|10
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|address
index|[
literal|10
index|]
operator|==
literal|0xff
operator|&&
name|address
index|[
literal|11
index|]
operator|==
literal|0xff
condition|)
block|{
name|embeddedIp4
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|address
index|[
literal|10
index|]
operator|==
literal|0
operator|&&
name|address
index|[
literal|11
index|]
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|address
index|[
literal|12
index|]
operator|!=
literal|0
operator|||
name|address
index|[
literal|13
index|]
operator|!=
literal|0
operator|||
name|address
index|[
literal|14
index|]
operator|!=
literal|0
condition|)
block|{
name|embeddedIp4
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|address
index|[
literal|15
index|]
operator|==
literal|0
condition|)
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
comment|// QString::reserve doesn't shrink, so it's fine to us
name|appendTo
operator|.
name|reserve
argument_list|(
name|appendTo
operator|.
name|size
argument_list|()
operator|+
operator|(
name|embeddedIp4
condition|?
name|Ip6WithIp4AddressMaxLen
else|:
name|Ip6AddressMaxLen
operator|)
argument_list|)
expr_stmt|;
comment|// for finding where to place the "::"
name|int
name|zeroRunLength
init|=
literal|0
decl_stmt|;
comment|// in octets
name|int
name|zeroRunOffset
init|=
literal|0
decl_stmt|;
comment|// in octets
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|address
index|[
name|i
index|]
operator|==
literal|0
operator|&&
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|==
literal|0
condition|)
block|{
comment|// found a zero, scan forward to see how many more there are
name|int
name|j
decl_stmt|;
for|for
control|(
name|j
operator|=
name|i
init|;
name|j
operator|<
literal|16
condition|;
name|j
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|address
index|[
name|j
index|]
operator|!=
literal|0
operator|||
name|address
index|[
name|j
operator|+
literal|1
index|]
operator|!=
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|j
operator|-
name|i
operator|>
name|zeroRunLength
condition|)
block|{
name|zeroRunLength
operator|=
name|j
operator|-
name|i
expr_stmt|;
name|zeroRunOffset
operator|=
name|i
expr_stmt|;
name|i
operator|=
name|j
expr_stmt|;
block|}
block|}
block|}
specifier|const
name|QChar
name|colon
init|=
name|ushort
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|zeroRunLength
operator|<
literal|4
condition|)
name|zeroRunOffset
operator|=
operator|-
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|zeroRunOffset
operator|==
literal|0
condition|)
name|appendTo
operator|.
name|append
argument_list|(
name|colon
argument_list|)
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
literal|16
condition|;
name|i
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|i
operator|==
name|zeroRunOffset
condition|)
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|colon
argument_list|)
expr_stmt|;
name|i
operator|+=
name|zeroRunLength
operator|-
literal|2
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|i
operator|==
literal|12
operator|&&
name|embeddedIp4
condition|)
block|{
name|IPv4Address
name|ip4
init|=
name|address
index|[
literal|12
index|]
operator|<<
literal|24
operator||
name|address
index|[
literal|13
index|]
operator|<<
literal|16
operator||
name|address
index|[
literal|14
index|]
operator|<<
literal|8
operator||
name|address
index|[
literal|15
index|]
decl_stmt|;
name|toString
argument_list|(
name|appendTo
argument_list|,
name|ip4
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|address
index|[
name|i
index|]
condition|)
block|{
if|if
condition|(
name|address
index|[
name|i
index|]
operator|>>
literal|4
condition|)
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
index|]
operator|>>
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|>>
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|address
index|[
name|i
index|]
operator|&
literal|0xf
condition|)
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|>>
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|>>
literal|4
condition|)
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|>>
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|appendTo
operator|.
name|append
argument_list|(
name|toHex
argument_list|(
name|address
index|[
name|i
operator|+
literal|1
index|]
operator|&
literal|0xf
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|!=
literal|14
condition|)
name|appendTo
operator|.
name|append
argument_list|(
name|colon
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
