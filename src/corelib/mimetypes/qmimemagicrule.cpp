begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_include
include|#
directive|include
file|"qmimemagicrule_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<qendian.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// in the same order as Type!
DECL|variable|magicRuleTypes_string
specifier|static
specifier|const
name|char
name|magicRuleTypes_string
index|[]
init|=
literal|"invalid\0"
literal|"string\0"
literal|"host16\0"
literal|"host32\0"
literal|"big16\0"
literal|"big32\0"
literal|"little16\0"
literal|"little32\0"
literal|"byte\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|magicRuleTypes_indices
specifier|static
specifier|const
name|int
name|magicRuleTypes_indices
index|[]
init|=
block|{
literal|0
block|,
literal|8
block|,
literal|15
block|,
literal|22
block|,
literal|29
block|,
literal|35
block|,
literal|41
block|,
literal|50
block|,
literal|59
block|,
literal|65
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|type
name|QMimeMagicRule
operator|::
name|Type
name|QMimeMagicRule
operator|::
name|type
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|theTypeName
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
name|String
init|;
name|i
operator|<=
name|Byte
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|theTypeName
operator|==
name|magicRuleTypes_string
operator|+
name|magicRuleTypes_indices
index|[
name|i
index|]
condition|)
return|return
name|Type
argument_list|(
name|i
argument_list|)
return|;
block|}
return|return
name|Invalid
return|;
block|}
end_function
begin_function
DECL|function|typeName
name|QByteArray
name|QMimeMagicRule
operator|::
name|typeName
parameter_list|(
name|QMimeMagicRule
operator|::
name|Type
name|theType
parameter_list|)
block|{
return|return
name|magicRuleTypes_string
operator|+
name|magicRuleTypes_indices
index|[
name|theType
index|]
return|;
block|}
end_function
begin_class
DECL|class|QMimeMagicRulePrivate
class|class
name|QMimeMagicRulePrivate
block|{
public|public:
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeMagicRulePrivate
modifier|&
name|other
parameter_list|)
specifier|const
function_decl|;
DECL|member|type
name|QMimeMagicRule
operator|::
name|Type
name|type
decl_stmt|;
DECL|member|value
name|QByteArray
name|value
decl_stmt|;
DECL|member|startPos
name|int
name|startPos
decl_stmt|;
DECL|member|endPos
name|int
name|endPos
decl_stmt|;
DECL|member|mask
name|QByteArray
name|mask
decl_stmt|;
DECL|member|pattern
name|QByteArray
name|pattern
decl_stmt|;
DECL|member|number
name|quint32
name|number
decl_stmt|;
DECL|member|numberMask
name|quint32
name|numberMask
decl_stmt|;
DECL|typedef|MatchFunction
typedef|typedef
name|bool
function_decl|(
modifier|*
name|MatchFunction
function_decl|)
parameter_list|(
specifier|const
name|QMimeMagicRulePrivate
modifier|*
name|d
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
function_decl|;
DECL|member|matchFunction
name|MatchFunction
name|matchFunction
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|operator ==
name|bool
name|QMimeMagicRulePrivate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeMagicRulePrivate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|type
operator|==
name|other
operator|.
name|type
operator|&&
name|value
operator|==
name|other
operator|.
name|value
operator|&&
name|startPos
operator|==
name|other
operator|.
name|startPos
operator|&&
name|endPos
operator|==
name|other
operator|.
name|endPos
operator|&&
name|mask
operator|==
name|other
operator|.
name|mask
operator|&&
name|pattern
operator|==
name|other
operator|.
name|pattern
operator|&&
name|number
operator|==
name|other
operator|.
name|number
operator|&&
name|numberMask
operator|==
name|other
operator|.
name|numberMask
operator|&&
name|matchFunction
operator|==
name|other
operator|.
name|matchFunction
return|;
block|}
end_function
begin_comment
comment|// Used by both providers
end_comment
begin_function
DECL|function|matchSubstring
name|bool
name|QMimeMagicRule
operator|::
name|matchSubstring
parameter_list|(
specifier|const
name|char
modifier|*
name|dataPtr
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|int
name|rangeStart
parameter_list|,
name|int
name|rangeLength
parameter_list|,
name|int
name|valueLength
parameter_list|,
specifier|const
name|char
modifier|*
name|valueData
parameter_list|,
specifier|const
name|char
modifier|*
name|mask
parameter_list|)
block|{
comment|// Size of searched data.
comment|// Example: value="ABC", rangeLength=3 -> we need 3+3-1=5 bytes (ABCxx,xABCx,xxABC would match)
specifier|const
name|int
name|dataNeeded
init|=
name|qMin
argument_list|(
name|rangeLength
operator|+
name|valueLength
operator|-
literal|1
argument_list|,
name|dataSize
operator|-
name|rangeStart
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|mask
condition|)
block|{
comment|// callgrind says QByteArray::indexOf is much slower, since our strings are typically too
comment|// short for be worth Boyer-Moore matching (1 to 71 bytes, 11 bytes on average).
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|rangeStart
init|;
name|i
operator|<
name|rangeStart
operator|+
name|rangeLength
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|+
name|valueLength
operator|>
name|dataSize
condition|)
break|break;
if|if
condition|(
name|memcmp
argument_list|(
name|valueData
argument_list|,
name|dataPtr
operator|+
name|i
argument_list|,
name|valueLength
argument_list|)
operator|==
literal|0
condition|)
block|{
name|found
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
return|return
literal|false
return|;
block|}
else|else
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
specifier|const
name|char
modifier|*
name|readDataBase
init|=
name|dataPtr
operator|+
name|rangeStart
decl_stmt|;
comment|// Example (continued from above):
comment|// deviceSize is 4, so dataNeeded was max'ed to 4.
comment|// maxStartPos = 4 - 3 + 1 = 2, and indeed
comment|// we need to check for a match a positions 0 and 1 (ABCx and xABC).
specifier|const
name|int
name|maxStartPos
init|=
name|dataNeeded
operator|-
name|valueLength
operator|+
literal|1
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
name|maxStartPos
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|d
init|=
name|readDataBase
operator|+
name|i
decl_stmt|;
name|bool
name|valid
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|valueLength
condition|;
operator|++
name|idx
control|)
block|{
if|if
condition|(
operator|(
operator|(
operator|*
name|d
operator|++
operator|)
operator|&
name|mask
index|[
name|idx
index|]
operator|)
operator|!=
operator|(
name|valueData
index|[
name|idx
index|]
operator|&
name|mask
index|[
name|idx
index|]
operator|)
condition|)
block|{
name|valid
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|valid
condition|)
name|found
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|found
condition|)
return|return
literal|false
return|;
block|}
comment|//qDebug()<< "Found"<< value<< "in"<< searchedData;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|matchString
specifier|static
name|bool
name|matchString
parameter_list|(
specifier|const
name|QMimeMagicRulePrivate
modifier|*
name|d
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
specifier|const
name|int
name|rangeLength
init|=
name|d
operator|->
name|endPos
operator|-
name|d
operator|->
name|startPos
operator|+
literal|1
decl_stmt|;
return|return
name|QMimeMagicRule
operator|::
name|matchSubstring
argument_list|(
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|,
name|d
operator|->
name|startPos
argument_list|,
name|rangeLength
argument_list|,
name|d
operator|->
name|pattern
operator|.
name|size
argument_list|()
argument_list|,
name|d
operator|->
name|pattern
operator|.
name|constData
argument_list|()
argument_list|,
name|d
operator|->
name|mask
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|matchNumber
specifier|static
name|bool
name|matchNumber
parameter_list|(
specifier|const
name|QMimeMagicRulePrivate
modifier|*
name|d
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
specifier|const
name|T
name|value
argument_list|(
name|d
operator|->
name|number
argument_list|)
decl_stmt|;
specifier|const
name|T
name|mask
argument_list|(
name|d
operator|->
name|numberMask
argument_list|)
decl_stmt|;
comment|//qDebug()<< "matchNumber"<< "0x"<< QString::number(d->number, 16)<< "size"<< sizeof(T);
comment|//qDebug()<< "mask"<< QString::number(d->numberMask, 16);
specifier|const
name|char
modifier|*
name|p
init|=
name|data
operator|.
name|constData
argument_list|()
operator|+
name|d
operator|->
name|startPos
decl_stmt|;
specifier|const
name|char
modifier|*
name|e
init|=
name|data
operator|.
name|constData
argument_list|()
operator|+
name|qMin
argument_list|(
name|data
operator|.
name|size
argument_list|()
operator|-
name|int
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
argument_list|,
name|d
operator|->
name|endPos
operator|+
literal|1
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|p
operator|<=
name|e
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|(
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|T
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
operator|&
name|mask
operator|)
operator|==
operator|(
name|value
operator|&
name|mask
operator|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|makePattern
specifier|static
specifier|inline
name|QByteArray
name|makePattern
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|value
parameter_list|)
block|{
name|QByteArray
name|pattern
argument_list|(
name|value
operator|.
name|size
argument_list|()
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|char
modifier|*
name|data
init|=
name|pattern
operator|.
name|data
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|p
init|=
name|value
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|e
init|=
name|p
operator|+
name|value
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|p
operator|<
name|e
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\\'
operator|&&
operator|++
name|p
operator|<
name|e
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'x'
condition|)
block|{
comment|// hex (\\xff)
name|char
name|c
init|=
literal|0
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
literal|2
operator|&&
name|p
operator|+
literal|1
operator|<
name|e
condition|;
operator|++
name|i
control|)
block|{
operator|++
name|p
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|>=
literal|'0'
operator|&&
operator|*
name|p
operator|<=
literal|'9'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'0'
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'a'
operator|&&
operator|*
name|p
operator|<=
literal|'f'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'a'
operator|+
literal|10
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'A'
operator|&&
operator|*
name|p
operator|<=
literal|'F'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|4
operator|)
operator|+
operator|*
name|p
operator|-
literal|'A'
operator|+
literal|10
expr_stmt|;
else|else
continue|continue;
block|}
operator|*
name|data
operator|++
operator|=
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|>=
literal|'0'
operator|&&
operator|*
name|p
operator|<=
literal|'7'
condition|)
block|{
comment|// oct (\\7, or \\77, or \\377)
name|char
name|c
init|=
operator|*
name|p
operator|-
literal|'0'
decl_stmt|;
if|if
condition|(
name|p
operator|+
literal|1
operator|<
name|e
operator|&&
name|p
index|[
literal|1
index|]
operator|>=
literal|'0'
operator|&&
name|p
index|[
literal|1
index|]
operator|<=
literal|'7'
condition|)
block|{
name|c
operator|=
operator|(
name|c
operator|<<
literal|3
operator|)
operator|+
operator|*
operator|(
operator|++
name|p
operator|)
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
name|p
operator|+
literal|1
operator|<
name|e
operator|&&
name|p
index|[
literal|1
index|]
operator|>=
literal|'0'
operator|&&
name|p
index|[
literal|1
index|]
operator|<=
literal|'7'
operator|&&
name|p
index|[
operator|-
literal|1
index|]
operator|<=
literal|'3'
condition|)
name|c
operator|=
operator|(
name|c
operator|<<
literal|3
operator|)
operator|+
operator|*
operator|(
operator|++
name|p
operator|)
operator|-
literal|'0'
expr_stmt|;
block|}
operator|*
name|data
operator|++
operator|=
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'n'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\n'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'r'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\r'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'t'
condition|)
block|{
operator|*
name|data
operator|++
operator|=
literal|'\t'
expr_stmt|;
block|}
else|else
block|{
comment|// escaped
operator|*
name|data
operator|++
operator|=
operator|*
name|p
expr_stmt|;
block|}
block|}
else|else
block|{
operator|*
name|data
operator|++
operator|=
operator|*
name|p
expr_stmt|;
block|}
block|}
name|pattern
operator|.
name|truncate
argument_list|(
name|data
operator|-
name|pattern
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|pattern
return|;
block|}
end_function
begin_constructor
DECL|function|QMimeMagicRule
name|QMimeMagicRule
operator|::
name|QMimeMagicRule
parameter_list|(
name|QMimeMagicRule
operator|::
name|Type
name|theType
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|theValue
parameter_list|,
name|int
name|theStartPos
parameter_list|,
name|int
name|theEndPos
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|theMask
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QMimeMagicRulePrivate
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|theValue
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|type
operator|=
name|theType
expr_stmt|;
name|d
operator|->
name|value
operator|=
name|theValue
expr_stmt|;
name|d
operator|->
name|startPos
operator|=
name|theStartPos
expr_stmt|;
name|d
operator|->
name|endPos
operator|=
name|theEndPos
expr_stmt|;
name|d
operator|->
name|mask
operator|=
name|theMask
expr_stmt|;
name|d
operator|->
name|matchFunction
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|type
operator|>=
name|Host16
operator|&&
name|d
operator|->
name|type
operator|<=
name|Byte
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|d
operator|->
name|number
operator|=
name|d
operator|->
name|value
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// autodetect
name|Q_ASSERT
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|d
operator|->
name|numberMask
operator|=
operator|!
name|d
operator|->
name|mask
operator|.
name|isEmpty
argument_list|()
condition|?
name|d
operator|->
name|mask
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|0
argument_list|)
else|:
literal|0
expr_stmt|;
comment|// autodetect
block|}
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
case|case
name|String
case|:
name|d
operator|->
name|pattern
operator|=
name|makePattern
argument_list|(
name|d
operator|->
name|value
argument_list|)
expr_stmt|;
name|d
operator|->
name|pattern
operator|.
name|squeeze
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|mask
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|mask
operator|.
name|size
argument_list|()
operator|>=
literal|4
operator|&&
name|d
operator|->
name|mask
operator|.
name|startsWith
argument_list|(
literal|"0x"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|mask
operator|=
name|QByteArray
operator|::
name|fromHex
argument_list|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|d
operator|->
name|mask
operator|.
name|constData
argument_list|()
operator|+
literal|2
argument_list|,
name|d
operator|->
name|mask
operator|.
name|size
argument_list|()
operator|-
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|mask
operator|.
name|size
argument_list|()
operator|==
name|d
operator|->
name|pattern
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|mask
operator|.
name|fill
argument_list|(
name|char
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|,
name|d
operator|->
name|pattern
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|mask
operator|.
name|squeeze
argument_list|()
expr_stmt|;
name|d
operator|->
name|matchFunction
operator|=
name|matchString
expr_stmt|;
break|break;
case|case
name|Byte
case|:
if|if
condition|(
name|d
operator|->
name|number
operator|<=
name|quint8
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|numberMask
operator|==
literal|0
condition|)
name|d
operator|->
name|numberMask
operator|=
name|quint8
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|matchFunction
operator|=
name|matchNumber
argument_list|<
name|quint8
argument_list|>
expr_stmt|;
block|}
break|break;
case|case
name|Big16
case|:
case|case
name|Host16
case|:
case|case
name|Little16
case|:
if|if
condition|(
name|d
operator|->
name|number
operator|<=
name|quint16
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|d
operator|->
name|number
operator|=
name|d
operator|->
name|type
operator|==
name|Little16
condition|?
name|qFromLittleEndian
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|d
operator|->
name|number
argument_list|)
else|:
name|qFromBigEndian
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|d
operator|->
name|number
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|numberMask
operator|==
literal|0
condition|)
name|d
operator|->
name|numberMask
operator|=
name|quint16
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|matchFunction
operator|=
name|matchNumber
argument_list|<
name|quint16
argument_list|>
expr_stmt|;
block|}
break|break;
case|case
name|Big32
case|:
case|case
name|Host32
case|:
case|case
name|Little32
case|:
if|if
condition|(
name|d
operator|->
name|number
operator|<=
name|quint32
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|d
operator|->
name|number
operator|=
name|d
operator|->
name|type
operator|==
name|Little32
condition|?
name|qFromLittleEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|d
operator|->
name|number
argument_list|)
else|:
name|qFromBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|d
operator|->
name|number
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|numberMask
operator|==
literal|0
condition|)
name|d
operator|->
name|numberMask
operator|=
name|quint32
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|matchFunction
operator|=
name|matchNumber
argument_list|<
name|quint32
argument_list|>
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
end_constructor
begin_constructor
DECL|function|QMimeMagicRule
name|QMimeMagicRule
operator|::
name|QMimeMagicRule
parameter_list|(
specifier|const
name|QMimeMagicRule
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QMimeMagicRulePrivate
argument_list|(
operator|*
name|other
operator|.
name|d
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QMimeMagicRule
name|QMimeMagicRule
operator|::
name|~
name|QMimeMagicRule
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|operator =
name|QMimeMagicRule
modifier|&
name|QMimeMagicRule
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QMimeMagicRule
modifier|&
name|other
parameter_list|)
block|{
operator|*
name|d
operator|=
operator|*
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QMimeMagicRule
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeMagicRule
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
operator|||
operator|*
name|d
operator|==
operator|*
name|other
operator|.
name|d
return|;
block|}
end_function
begin_function
DECL|function|type
name|QMimeMagicRule
operator|::
name|Type
name|QMimeMagicRule
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_function
DECL|function|value
name|QByteArray
name|QMimeMagicRule
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|value
return|;
block|}
end_function
begin_function
DECL|function|startPos
name|int
name|QMimeMagicRule
operator|::
name|startPos
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|startPos
return|;
block|}
end_function
begin_function
DECL|function|endPos
name|int
name|QMimeMagicRule
operator|::
name|endPos
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|endPos
return|;
block|}
end_function
begin_function
DECL|function|mask
name|QByteArray
name|QMimeMagicRule
operator|::
name|mask
parameter_list|()
specifier|const
block|{
name|QByteArray
name|result
init|=
name|d
operator|->
name|mask
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|String
condition|)
block|{
comment|// restore '0x'
name|result
operator|=
literal|"0x"
operator|+
name|result
operator|.
name|toHex
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|isValid
name|bool
name|QMimeMagicRule
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|matchFunction
return|;
block|}
end_function
begin_function
DECL|function|matches
name|bool
name|QMimeMagicRule
operator|::
name|matches
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|ok
init|=
name|d
operator|->
name|matchFunction
operator|&&
name|d
operator|->
name|matchFunction
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|,
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
comment|// No submatch? Then we are done.
if|if
condition|(
name|m_subMatches
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
comment|//qDebug()<< "Checking"<< m_subMatches.count()<< "sub-rules";
comment|// Check that one of the submatches matches too
for|for
control|(
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|m_subMatches
operator|.
name|begin
argument_list|()
init|,
name|end
init|=
name|m_subMatches
operator|.
name|end
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|matches
argument_list|(
name|data
argument_list|)
condition|)
block|{
comment|// One of the hierarchies matched -> mimetype recognized.
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
