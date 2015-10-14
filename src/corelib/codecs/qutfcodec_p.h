begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2013 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUTFCODEC_P_H
end_ifndef
begin_define
DECL|macro|QUTFCODEC_P_H
define|#
directive|define
name|QUTFCODEC_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qtextcodec.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextcodec_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QUtf8BaseTraits
struct|struct
name|QUtf8BaseTraits
block|{
DECL|member|isTrusted
specifier|static
specifier|const
name|bool
name|isTrusted
init|=
name|false
decl_stmt|;
DECL|member|allowNonCharacters
specifier|static
specifier|const
name|bool
name|allowNonCharacters
init|=
name|true
decl_stmt|;
DECL|member|skipAsciiHandling
specifier|static
specifier|const
name|bool
name|skipAsciiHandling
init|=
name|false
decl_stmt|;
DECL|member|Error
specifier|static
specifier|const
name|int
name|Error
init|=
operator|-
literal|1
decl_stmt|;
DECL|member|EndOfString
specifier|static
specifier|const
name|int
name|EndOfString
init|=
operator|-
literal|2
decl_stmt|;
DECL|function|isValidCharacter
specifier|static
name|bool
name|isValidCharacter
parameter_list|(
name|uint
name|u
parameter_list|)
block|{
return|return
name|int
argument_list|(
name|u
argument_list|)
operator|>=
literal|0
return|;
block|}
DECL|function|appendByte
specifier|static
name|void
name|appendByte
parameter_list|(
name|uchar
modifier|*
modifier|&
name|ptr
parameter_list|,
name|uchar
name|b
parameter_list|)
block|{
operator|*
name|ptr
operator|++
operator|=
name|b
expr_stmt|;
block|}
DECL|function|peekByte
specifier|static
name|uchar
name|peekByte
parameter_list|(
specifier|const
name|uchar
modifier|*
name|ptr
parameter_list|,
name|int
name|n
init|=
literal|0
parameter_list|)
block|{
return|return
name|ptr
index|[
name|n
index|]
return|;
block|}
DECL|function|availableBytes
specifier|static
name|qptrdiff
name|availableBytes
parameter_list|(
specifier|const
name|uchar
modifier|*
name|ptr
parameter_list|,
specifier|const
name|uchar
modifier|*
name|end
parameter_list|)
block|{
return|return
name|end
operator|-
name|ptr
return|;
block|}
DECL|function|advanceByte
specifier|static
name|void
name|advanceByte
parameter_list|(
specifier|const
name|uchar
modifier|*
modifier|&
name|ptr
parameter_list|,
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
name|ptr
operator|+=
name|n
expr_stmt|;
block|}
DECL|function|appendUtf16
specifier|static
name|void
name|appendUtf16
parameter_list|(
name|ushort
modifier|*
modifier|&
name|ptr
parameter_list|,
name|ushort
name|uc
parameter_list|)
block|{
operator|*
name|ptr
operator|++
operator|=
name|uc
expr_stmt|;
block|}
DECL|function|appendUcs4
specifier|static
name|void
name|appendUcs4
parameter_list|(
name|ushort
modifier|*
modifier|&
name|ptr
parameter_list|,
name|uint
name|uc
parameter_list|)
block|{
name|appendUtf16
argument_list|(
name|ptr
argument_list|,
name|QChar
operator|::
name|highSurrogate
argument_list|(
name|uc
argument_list|)
argument_list|)
expr_stmt|;
name|appendUtf16
argument_list|(
name|ptr
argument_list|,
name|QChar
operator|::
name|lowSurrogate
argument_list|(
name|uc
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|peekUtf16
specifier|static
name|ushort
name|peekUtf16
parameter_list|(
specifier|const
name|ushort
modifier|*
name|ptr
parameter_list|,
name|int
name|n
init|=
literal|0
parameter_list|)
block|{
return|return
name|ptr
index|[
name|n
index|]
return|;
block|}
DECL|function|availableUtf16
specifier|static
name|qptrdiff
name|availableUtf16
parameter_list|(
specifier|const
name|ushort
modifier|*
name|ptr
parameter_list|,
specifier|const
name|ushort
modifier|*
name|end
parameter_list|)
block|{
return|return
name|end
operator|-
name|ptr
return|;
block|}
DECL|function|advanceUtf16
specifier|static
name|void
name|advanceUtf16
parameter_list|(
specifier|const
name|ushort
modifier|*
modifier|&
name|ptr
parameter_list|,
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
name|ptr
operator|+=
name|n
expr_stmt|;
block|}
comment|// it's possible to output to UCS-4 too
DECL|function|appendUtf16
specifier|static
name|void
name|appendUtf16
parameter_list|(
name|uint
modifier|*
modifier|&
name|ptr
parameter_list|,
name|ushort
name|uc
parameter_list|)
block|{
operator|*
name|ptr
operator|++
operator|=
name|uc
expr_stmt|;
block|}
DECL|function|appendUcs4
specifier|static
name|void
name|appendUcs4
parameter_list|(
name|uint
modifier|*
modifier|&
name|ptr
parameter_list|,
name|uint
name|uc
parameter_list|)
block|{
operator|*
name|ptr
operator|++
operator|=
name|uc
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
DECL|struct|QUtf8BaseTraits
name|struct
name|QUtf8BaseTraitsNoAscii
range|:
name|public
name|QUtf8BaseTraits
block|{
DECL|member|skipAsciiHandling
specifier|static
specifier|const
name|bool
name|skipAsciiHandling
operator|=
name|true
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QUtf8Functions
block|{
comment|/// returns 0 on success; errors can only happen if \a u is a surrogate:
comment|/// Error if \a u is a low surrogate;
comment|/// if \a u is a high surrogate, Error if the next isn't a low one,
comment|/// EndOfString if we run into the end of the string.
name|template
operator|<
name|typename
name|Traits
operator|,
name|typename
name|OutputPtr
operator|,
name|typename
name|InputPtr
operator|>
specifier|inline
name|int
name|toUtf8
argument_list|(
argument|ushort u
argument_list|,
argument|OutputPtr&dst
argument_list|,
argument|InputPtr&src
argument_list|,
argument|InputPtr end
argument_list|)
block|{
if|if
condition|(
operator|!
name|Traits
operator|::
name|skipAsciiHandling
operator|&&
name|u
operator|<
literal|0x80
condition|)
block|{
comment|// U+0000 to U+007F (US-ASCII) - one byte
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
name|uchar
argument_list|(
name|u
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|u
operator|<
literal|0x0800
condition|)
block|{
comment|// U+0080 to U+07FF - two bytes
comment|// first of two bytes
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0xc0
operator||
name|uchar
argument_list|(
name|u
operator|>>
literal|6
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|QChar
operator|::
name|isSurrogate
argument_list|(
name|u
argument_list|)
condition|)
block|{
comment|// U+0800 to U+FFFF (except U+D800-U+DFFF) - three bytes
if|if
condition|(
operator|!
name|Traits
operator|::
name|allowNonCharacters
operator|&&
name|QChar
operator|::
name|isNonCharacter
argument_list|(
name|u
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
comment|// first of three bytes
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0xe0
operator||
name|uchar
argument_list|(
name|u
operator|>>
literal|12
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// U+10000 to U+10FFFF - four bytes
comment|// need to get one extra codepoint
if|if
condition|(
name|Traits
operator|::
name|availableUtf16
argument_list|(
name|src
argument_list|,
name|end
argument_list|)
operator|==
literal|0
condition|)
return|return
name|Traits
operator|::
name|EndOfString
return|;
name|ushort
name|low
init|=
name|Traits
operator|::
name|peekUtf16
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QChar
operator|::
name|isHighSurrogate
argument_list|(
name|u
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
if|if
condition|(
operator|!
name|QChar
operator|::
name|isLowSurrogate
argument_list|(
name|low
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
name|Traits
operator|::
name|advanceUtf16
argument_list|(
name|src
argument_list|)
expr_stmt|;
name|uint
name|ucs4
init|=
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
name|u
argument_list|,
name|low
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|Traits
operator|::
name|allowNonCharacters
operator|&&
name|QChar
operator|::
name|isNonCharacter
argument_list|(
name|ucs4
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
comment|// first byte
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0xf0
operator||
operator|(
name|uchar
argument_list|(
name|ucs4
operator|>>
literal|18
argument_list|)
operator|&
literal|0xf
operator|)
argument_list|)
expr_stmt|;
comment|// second of four bytes
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0x80
operator||
operator|(
name|uchar
argument_list|(
name|ucs4
operator|>>
literal|12
argument_list|)
operator|&
literal|0x3f
operator|)
argument_list|)
expr_stmt|;
comment|// for the rest of the bytes
name|u
operator|=
name|ushort
argument_list|(
name|ucs4
argument_list|)
expr_stmt|;
block|}
comment|// second to last byte
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0x80
operator||
operator|(
name|uchar
argument_list|(
name|u
operator|>>
literal|6
argument_list|)
operator|&
literal|0x3f
operator|)
argument_list|)
expr_stmt|;
block|}
comment|// last byte
name|Traits
operator|::
name|appendByte
argument_list|(
name|dst
argument_list|,
literal|0x80
operator||
operator|(
name|u
operator|&
literal|0x3f
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|bool
name|isContinuationByte
parameter_list|(
name|uchar
name|b
parameter_list|)
block|{
return|return
operator|(
name|b
operator|&
literal|0xc0
operator|)
operator|==
literal|0x80
return|;
block|}
end_function
begin_comment
comment|/// returns the number of characters consumed (including \a b) in case of success;
end_comment
begin_comment
comment|/// returns negative in case of error: Traits::Error or Traits::EndOfString
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Traits
operator|,
name|typename
name|OutputPtr
operator|,
name|typename
name|InputPtr
operator|>
specifier|inline
name|int
name|fromUtf8
argument_list|(
argument|uchar b
argument_list|,
argument|OutputPtr&dst
argument_list|,
argument|InputPtr&src
argument_list|,
argument|InputPtr end
argument_list|)
block|{
name|int
name|charsNeeded
block|;
name|uint
name|min_uc
block|;
name|uint
name|uc
block|;
if|if
condition|(
operator|!
name|Traits
operator|::
name|skipAsciiHandling
operator|&&
name|b
operator|<
literal|0x80
condition|)
block|{
comment|// US-ASCII
name|Traits
operator|::
name|appendUtf16
argument_list|(
name|dst
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|Traits
operator|::
name|isTrusted
operator|&&
name|Q_UNLIKELY
argument_list|(
name|b
operator|<=
literal|0xC1
argument_list|)
condition|)
block|{
comment|// an UTF-8 first character must be at least 0xC0
comment|// however, all 0xC0 and 0xC1 first bytes can only produce overlong sequences
return|return
name|Traits
operator|::
name|Error
return|;
block|}
elseif|else
if|if
condition|(
name|b
operator|<
literal|0xe0
condition|)
block|{
name|charsNeeded
operator|=
literal|2
expr_stmt|;
name|min_uc
operator|=
literal|0x80
expr_stmt|;
name|uc
operator|=
name|b
operator|&
literal|0x1f
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|b
operator|<
literal|0xf0
condition|)
block|{
name|charsNeeded
operator|=
literal|3
expr_stmt|;
name|min_uc
operator|=
literal|0x800
expr_stmt|;
name|uc
operator|=
name|b
operator|&
literal|0x0f
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|b
operator|<
literal|0xf5
condition|)
block|{
name|charsNeeded
operator|=
literal|4
expr_stmt|;
name|min_uc
operator|=
literal|0x10000
expr_stmt|;
name|uc
operator|=
name|b
operator|&
literal|0x07
expr_stmt|;
block|}
else|else
block|{
comment|// the last Unicode character is U+10FFFF
comment|// it's encoded in UTF-8 as "\xF4\x8F\xBF\xBF"
comment|// therefore, a byte higher than 0xF4 is not the UTF-8 first byte
return|return
name|Traits
operator|::
name|Error
return|;
block|}
end_if
begin_decl_stmt
name|int
name|bytesAvailable
init|=
name|Traits
operator|::
name|availableBytes
argument_list|(
name|src
argument_list|,
name|end
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bytesAvailable
operator|<
name|charsNeeded
operator|-
literal|1
argument_list|)
condition|)
block|{
comment|// it's possible that we have an error instead of just unfinished bytes
if|if
condition|(
name|bytesAvailable
operator|>
literal|0
operator|&&
operator|!
name|isContinuationByte
argument_list|(
name|Traits
operator|::
name|peekByte
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
if|if
condition|(
name|bytesAvailable
operator|>
literal|1
operator|&&
operator|!
name|isContinuationByte
argument_list|(
name|Traits
operator|::
name|peekByte
argument_list|(
name|src
argument_list|,
literal|1
argument_list|)
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
return|return
name|Traits
operator|::
name|EndOfString
return|;
block|}
end_if
begin_comment
comment|// first continuation character
end_comment
begin_expr_stmt
name|b
operator|=
name|Traits
operator|::
name|peekByte
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|isContinuationByte
argument_list|(
name|b
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
end_if
begin_expr_stmt
name|uc
operator|<<=
literal|6
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|uc
operator||=
name|b
operator|&
literal|0x3f
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|charsNeeded
operator|>
literal|2
condition|)
block|{
comment|// second continuation character
name|b
operator|=
name|Traits
operator|::
name|peekByte
argument_list|(
name|src
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isContinuationByte
argument_list|(
name|b
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
name|uc
operator|<<=
literal|6
expr_stmt|;
name|uc
operator||=
name|b
operator|&
literal|0x3f
expr_stmt|;
if|if
condition|(
name|charsNeeded
operator|>
literal|3
condition|)
block|{
comment|// third continuation character
name|b
operator|=
name|Traits
operator|::
name|peekByte
argument_list|(
name|src
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isContinuationByte
argument_list|(
name|b
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
name|uc
operator|<<=
literal|6
expr_stmt|;
name|uc
operator||=
name|b
operator|&
literal|0x3f
expr_stmt|;
block|}
block|}
end_if
begin_comment
comment|// we've decoded something; safety-check it
end_comment
begin_if
if|if
condition|(
operator|!
name|Traits
operator|::
name|isTrusted
condition|)
block|{
if|if
condition|(
name|uc
operator|<
name|min_uc
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
if|if
condition|(
name|QChar
operator|::
name|isSurrogate
argument_list|(
name|uc
argument_list|)
operator|||
name|uc
operator|>
name|QChar
operator|::
name|LastValidCodePoint
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
if|if
condition|(
operator|!
name|Traits
operator|::
name|allowNonCharacters
operator|&&
name|QChar
operator|::
name|isNonCharacter
argument_list|(
name|uc
argument_list|)
condition|)
return|return
name|Traits
operator|::
name|Error
return|;
block|}
end_if
begin_comment
comment|// write the UTF-16 sequence
end_comment
begin_if
if|if
condition|(
operator|!
name|QChar
operator|::
name|requiresSurrogates
argument_list|(
name|uc
argument_list|)
condition|)
block|{
comment|// UTF-8 decoded and no surrogates are required
comment|// detach if necessary
name|Traits
operator|::
name|appendUtf16
argument_list|(
name|dst
argument_list|,
name|ushort
argument_list|(
name|uc
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// UTF-8 decoded to something that requires a surrogate pair
name|Traits
operator|::
name|appendUcs4
argument_list|(
name|dst
argument_list|,
name|uc
argument_list|)
expr_stmt|;
block|}
end_if
begin_expr_stmt
name|Traits
operator|::
name|advanceByte
argument_list|(
name|src
argument_list|,
name|charsNeeded
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|charsNeeded
return|;
end_return
begin_enum
DECL|enum|DataEndianness
unit|} }
enum|enum
name|DataEndianness
block|{
DECL|enumerator|DetectEndianness
name|DetectEndianness
block|,
DECL|enumerator|BigEndianness
name|BigEndianness
block|,
DECL|enumerator|LittleEndianness
name|LittleEndianness
block|}
enum|;
end_enum
begin_struct
DECL|struct|QUtf8
struct|struct
name|QUtf8
block|{
specifier|static
name|QString
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|static
name|QString
name|convertToUnicode
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|)
decl_stmt|;
specifier|static
name|QByteArray
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|convertFromUnicode
argument_list|(
specifier|const
name|QChar
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QUtf16
struct|struct
name|QUtf16
block|{
specifier|static
name|QString
name|convertToUnicode
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|,
name|DataEndianness
operator|=
name|DetectEndianness
argument_list|)
decl_stmt|;
specifier|static
name|QByteArray
name|convertFromUnicode
argument_list|(
specifier|const
name|QChar
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|,
name|DataEndianness
operator|=
name|DetectEndianness
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QUtf32
struct|struct
name|QUtf32
block|{
specifier|static
name|QString
name|convertToUnicode
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|,
name|DataEndianness
operator|=
name|DetectEndianness
argument_list|)
decl_stmt|;
specifier|static
name|QByteArray
name|convertFromUnicode
argument_list|(
specifier|const
name|QChar
operator|*
argument_list|,
name|int
argument_list|,
name|QTextCodec
operator|::
name|ConverterState
operator|*
argument_list|,
name|DataEndianness
operator|=
name|DetectEndianness
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_decl_stmt
name|class
name|QUtf8Codec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
operator|~
name|QUtf8Codec
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|convertToUnicode
argument_list|(
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|convertFromUnicode
argument_list|(
argument|const QChar *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|convertToUnicode
argument_list|(
argument|QString *target
argument_list|,
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf16Codec
range|:
name|public
name|QTextCodec
block|{
name|protected
operator|:
name|public
operator|:
name|QUtf16Codec
argument_list|()
block|{
name|e
operator|=
name|DetectEndianness
block|; }
operator|~
name|QUtf16Codec
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|convertToUnicode
argument_list|(
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|convertFromUnicode
argument_list|(
argument|const QChar *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|DataEndianness
name|e
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf16BECodec
range|:
name|public
name|QUtf16Codec
block|{
name|public
operator|:
name|QUtf16BECodec
argument_list|()
operator|:
name|QUtf16Codec
argument_list|()
block|{
name|e
operator|=
name|BigEndianness
block|; }
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf16LECodec
range|:
name|public
name|QUtf16Codec
block|{
name|public
operator|:
name|QUtf16LECodec
argument_list|()
operator|:
name|QUtf16Codec
argument_list|()
block|{
name|e
operator|=
name|LittleEndianness
block|; }
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf32Codec
range|:
name|public
name|QTextCodec
block|{
name|public
operator|:
name|QUtf32Codec
argument_list|()
block|{
name|e
operator|=
name|DetectEndianness
block|; }
operator|~
name|QUtf32Codec
argument_list|()
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|convertToUnicode
argument_list|(
argument|const char *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|convertFromUnicode
argument_list|(
argument|const QChar *
argument_list|,
argument|int
argument_list|,
argument|ConverterState *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|DataEndianness
name|e
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf32BECodec
range|:
name|public
name|QUtf32Codec
block|{
name|public
operator|:
name|QUtf32BECodec
argument_list|()
operator|:
name|QUtf32Codec
argument_list|()
block|{
name|e
operator|=
name|BigEndianness
block|; }
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QUtf32LECodec
range|:
name|public
name|QUtf32Codec
block|{
name|public
operator|:
name|QUtf32LECodec
argument_list|()
operator|:
name|QUtf32Codec
argument_list|()
block|{
name|e
operator|=
name|LittleEndianness
block|; }
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|mibEnum
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUTFCODEC_P_H
end_comment
end_unit
