begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   Based on the public domain implementation of the SHA-1 algorithm   Copyright (C) Dominik Reichl<dominik.reichl@t-online.de> */
end_comment
begin_include
include|#
directive|include
file|<QtCore/qendian.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Test Vectors (from FIPS PUB 180-1)
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  SHA1("abc") =
end_comment
begin_comment
comment|//      A9993E36 4706816A BA3E2571 7850C26C 9CD0D89D
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  SHA1("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq") =
end_comment
begin_comment
comment|//      84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  SHA1(A million repetitions of "a") =
end_comment
begin_comment
comment|//      34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// #define or #undef this, if you want the to wipe all
end_comment
begin_comment
comment|// temporary variables after processing
end_comment
begin_define
DECL|macro|SHA1_WIPE_VARIABLES
define|#
directive|define
name|SHA1_WIPE_VARIABLES
end_define
begin_struct
DECL|struct|Sha1State
struct|struct
name|Sha1State
block|{
DECL|member|h0
name|quint32
name|h0
decl_stmt|;
DECL|member|h1
name|quint32
name|h1
decl_stmt|;
DECL|member|h2
name|quint32
name|h2
decl_stmt|;
DECL|member|h3
name|quint32
name|h3
decl_stmt|;
DECL|member|h4
name|quint32
name|h4
decl_stmt|;
DECL|member|messageSize
name|quint64
name|messageSize
decl_stmt|;
DECL|member|buffer
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
union|union
block|{
DECL|member|bytes
name|quint8
name|bytes
index|[
literal|64
index|]
decl_stmt|;
DECL|member|words
name|quint32
name|words
index|[
literal|16
index|]
decl_stmt|;
block|}
DECL|typedef|Sha1Chunk
name|Sha1Chunk
typedef|;
end_typedef
begin_function
DECL|function|rol32
specifier|static
specifier|inline
name|quint32
name|rol32
parameter_list|(
name|quint32
name|value
parameter_list|,
name|unsigned
name|int
name|shift
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_MSVC
return|return
name|_rotl
argument_list|(
name|value
argument_list|,
name|shift
argument_list|)
return|;
else|#
directive|else
return|return
operator|(
operator|(
name|value
operator|<<
name|shift
operator|)
operator||
operator|(
name|value
operator|>>
operator|(
literal|32
operator|-
name|shift
operator|)
operator|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sha1Word
specifier|static
specifier|inline
name|quint32
name|sha1Word
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|)
block|{
return|return
operator|(
name|chunk
operator|->
name|words
index|[
name|position
operator|&
literal|0xf
index|]
operator|=
name|rol32
argument_list|(
name|chunk
operator|->
name|words
index|[
operator|(
name|position
operator|+
literal|13
operator|)
operator|&
literal|0xf
index|]
operator|^
name|chunk
operator|->
name|words
index|[
operator|(
name|position
operator|+
literal|8
operator|)
operator|&
literal|0xf
index|]
operator|^
name|chunk
operator|->
name|words
index|[
operator|(
name|position
operator|+
literal|2
operator|)
operator|&
literal|0xf
index|]
operator|^
name|chunk
operator|->
name|words
index|[
operator|(
name|position
operator|)
operator|&
literal|0xf
index|]
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|sha1Round0
specifier|static
specifier|inline
name|void
name|sha1Round0
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|,
name|quint32
modifier|&
name|v
parameter_list|,
name|quint32
modifier|&
name|w
parameter_list|,
name|quint32
modifier|&
name|x
parameter_list|,
name|quint32
modifier|&
name|y
parameter_list|,
name|quint32
modifier|&
name|z
parameter_list|)
block|{
name|z
operator|+=
operator|(
operator|(
operator|(
name|w
operator|&
operator|(
name|x
operator|^
name|y
operator|)
operator|)
operator|^
name|y
operator|)
operator|+
name|chunk
operator|->
name|words
index|[
name|position
index|]
operator|+
literal|0x5A827999
operator|+
name|rol32
argument_list|(
name|v
argument_list|,
literal|5
argument_list|)
operator|)
expr_stmt|;
name|w
operator|=
name|rol32
argument_list|(
name|w
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1Round1
specifier|static
specifier|inline
name|void
name|sha1Round1
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|,
name|quint32
modifier|&
name|v
parameter_list|,
name|quint32
modifier|&
name|w
parameter_list|,
name|quint32
modifier|&
name|x
parameter_list|,
name|quint32
modifier|&
name|y
parameter_list|,
name|quint32
modifier|&
name|z
parameter_list|)
block|{
name|z
operator|+=
operator|(
operator|(
operator|(
name|w
operator|&
operator|(
name|x
operator|^
name|y
operator|)
operator|)
operator|^
name|y
operator|)
operator|+
name|sha1Word
argument_list|(
name|chunk
argument_list|,
name|position
argument_list|)
operator|+
literal|0x5A827999
operator|+
name|rol32
argument_list|(
name|v
argument_list|,
literal|5
argument_list|)
operator|)
expr_stmt|;
name|w
operator|=
name|rol32
argument_list|(
name|w
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1Round2
specifier|static
specifier|inline
name|void
name|sha1Round2
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|,
name|quint32
modifier|&
name|v
parameter_list|,
name|quint32
modifier|&
name|w
parameter_list|,
name|quint32
modifier|&
name|x
parameter_list|,
name|quint32
modifier|&
name|y
parameter_list|,
name|quint32
modifier|&
name|z
parameter_list|)
block|{
name|z
operator|+=
operator|(
operator|(
name|w
operator|^
name|x
operator|^
name|y
operator|)
operator|+
name|sha1Word
argument_list|(
name|chunk
argument_list|,
name|position
argument_list|)
operator|+
literal|0x6ED9EBA1
operator|+
name|rol32
argument_list|(
name|v
argument_list|,
literal|5
argument_list|)
operator|)
expr_stmt|;
name|w
operator|=
name|rol32
argument_list|(
name|w
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1Round3
specifier|static
specifier|inline
name|void
name|sha1Round3
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|,
name|quint32
modifier|&
name|v
parameter_list|,
name|quint32
modifier|&
name|w
parameter_list|,
name|quint32
modifier|&
name|x
parameter_list|,
name|quint32
modifier|&
name|y
parameter_list|,
name|quint32
modifier|&
name|z
parameter_list|)
block|{
name|z
operator|+=
operator|(
operator|(
operator|(
operator|(
name|w
operator||
name|x
operator|)
operator|&
name|y
operator|)
operator||
operator|(
name|w
operator|&
name|x
operator|)
operator|)
operator|+
name|sha1Word
argument_list|(
name|chunk
argument_list|,
name|position
argument_list|)
operator|+
literal|0x8F1BBCDC
operator|+
name|rol32
argument_list|(
name|v
argument_list|,
literal|5
argument_list|)
operator|)
expr_stmt|;
name|w
operator|=
name|rol32
argument_list|(
name|w
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1Round4
specifier|static
specifier|inline
name|void
name|sha1Round4
parameter_list|(
name|Sha1Chunk
modifier|*
name|chunk
parameter_list|,
specifier|const
name|uint
name|position
parameter_list|,
name|quint32
modifier|&
name|v
parameter_list|,
name|quint32
modifier|&
name|w
parameter_list|,
name|quint32
modifier|&
name|x
parameter_list|,
name|quint32
modifier|&
name|y
parameter_list|,
name|quint32
modifier|&
name|z
parameter_list|)
block|{
name|z
operator|+=
operator|(
operator|(
name|w
operator|^
name|x
operator|^
name|y
operator|)
operator|+
name|sha1Word
argument_list|(
name|chunk
argument_list|,
name|position
argument_list|)
operator|+
literal|0xCA62C1D6
operator|+
name|rol32
argument_list|(
name|v
argument_list|,
literal|5
argument_list|)
operator|)
expr_stmt|;
name|w
operator|=
name|rol32
argument_list|(
name|w
argument_list|,
literal|30
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1ProcessChunk
specifier|static
specifier|inline
name|void
name|sha1ProcessChunk
parameter_list|(
name|Sha1State
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|)
block|{
comment|// Copy state[] to working vars
name|quint32
name|a
init|=
name|state
operator|->
name|h0
decl_stmt|;
name|quint32
name|b
init|=
name|state
operator|->
name|h1
decl_stmt|;
name|quint32
name|c
init|=
name|state
operator|->
name|h2
decl_stmt|;
name|quint32
name|d
init|=
name|state
operator|->
name|h3
decl_stmt|;
name|quint32
name|e
init|=
name|state
operator|->
name|h4
decl_stmt|;
name|quint8
name|chunkBuffer
index|[
literal|64
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|chunkBuffer
argument_list|,
name|buffer
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|Sha1Chunk
modifier|*
name|chunk
init|=
cast|reinterpret_cast
argument_list|<
name|Sha1Chunk
operator|*
argument_list|>
argument_list|(
operator|&
name|chunkBuffer
argument_list|)
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
literal|16
condition|;
operator|++
name|i
control|)
name|chunk
operator|->
name|words
index|[
name|i
index|]
operator|=
name|qFromBigEndian
argument_list|(
name|chunk
operator|->
name|words
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|0
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|1
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|2
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|3
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|4
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|5
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|6
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|7
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|8
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|9
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|10
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|11
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|12
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|13
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|14
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round0
argument_list|(
name|chunk
argument_list|,
literal|15
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round1
argument_list|(
name|chunk
argument_list|,
literal|16
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round1
argument_list|(
name|chunk
argument_list|,
literal|17
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round1
argument_list|(
name|chunk
argument_list|,
literal|18
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round1
argument_list|(
name|chunk
argument_list|,
literal|19
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|20
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|21
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|22
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|23
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|24
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|25
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|26
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|27
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|28
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|29
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|30
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|31
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|32
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|33
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|34
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|35
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|36
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|37
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|38
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round2
argument_list|(
name|chunk
argument_list|,
literal|39
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|40
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|41
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|42
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|43
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|44
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|45
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|46
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|47
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|48
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|49
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|50
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|51
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|52
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|53
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|54
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|55
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|56
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|57
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|58
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round3
argument_list|(
name|chunk
argument_list|,
literal|59
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|60
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|61
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|62
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|63
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|64
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|65
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|66
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|67
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|68
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|69
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|70
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|71
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|72
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|73
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|74
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|75
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|76
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|77
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|78
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|sha1Round4
argument_list|(
name|chunk
argument_list|,
literal|79
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// Add the working vars back into state
name|state
operator|->
name|h0
operator|+=
name|a
expr_stmt|;
name|state
operator|->
name|h1
operator|+=
name|b
expr_stmt|;
name|state
operator|->
name|h2
operator|+=
name|c
expr_stmt|;
name|state
operator|->
name|h3
operator|+=
name|d
expr_stmt|;
name|state
operator|->
name|h4
operator|+=
name|e
expr_stmt|;
comment|// Wipe variables
ifdef|#
directive|ifdef
name|SHA1_WIPE_VARIABLES
name|a
operator|=
name|b
operator|=
name|c
operator|=
name|d
operator|=
name|e
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|chunkBuffer
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sha1InitState
specifier|static
specifier|inline
name|void
name|sha1InitState
parameter_list|(
name|Sha1State
modifier|*
name|state
parameter_list|)
block|{
name|state
operator|->
name|h0
operator|=
literal|0x67452301
expr_stmt|;
name|state
operator|->
name|h1
operator|=
literal|0xEFCDAB89
expr_stmt|;
name|state
operator|->
name|h2
operator|=
literal|0x98BADCFE
expr_stmt|;
name|state
operator|->
name|h3
operator|=
literal|0x10325476
expr_stmt|;
name|state
operator|->
name|h4
operator|=
literal|0xC3D2E1F0
expr_stmt|;
name|state
operator|->
name|messageSize
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1Update
specifier|static
specifier|inline
name|void
name|sha1Update
parameter_list|(
name|Sha1State
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|quint32
name|rest
init|=
cast|static_cast
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|state
operator|->
name|messageSize
operator|&
name|Q_UINT64_C
argument_list|(
literal|63
argument_list|)
argument_list|)
decl_stmt|;
name|quint64
name|availableData
init|=
cast|static_cast
argument_list|<
name|quint64
argument_list|>
argument_list|(
name|len
argument_list|)
operator|+
cast|static_cast
argument_list|<
name|quint64
argument_list|>
argument_list|(
name|rest
argument_list|)
decl_stmt|;
name|state
operator|->
name|messageSize
operator|+=
name|len
expr_stmt|;
if|if
condition|(
name|availableData
operator|<
name|Q_UINT64_C
argument_list|(
literal|64
argument_list|)
condition|)
block|{
name|memcpy
argument_list|(
operator|&
name|state
operator|->
name|buffer
index|[
name|rest
index|]
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qint64
name|i
init|=
cast|static_cast
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|64
operator|-
name|rest
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|state
operator|->
name|buffer
index|[
name|rest
index|]
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|,
cast|static_cast
argument_list|<
name|qint32
argument_list|>
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|sha1ProcessChunk
argument_list|(
name|state
argument_list|,
name|state
operator|->
name|buffer
argument_list|)
expr_stmt|;
name|qint64
name|lastI
init|=
name|len
operator|-
operator|(
operator|(
name|len
operator|+
name|rest
operator|)
operator|&
name|Q_INT64_C
argument_list|(
literal|63
argument_list|)
operator|)
decl_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|lastI
condition|;
name|i
operator|+=
literal|64
control|)
name|sha1ProcessChunk
argument_list|(
name|state
argument_list|,
operator|&
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|state
operator|->
name|buffer
index|[
literal|0
index|]
argument_list|,
operator|&
name|data
index|[
name|i
index|]
argument_list|,
name|len
operator|-
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sha1FinalizeState
specifier|static
specifier|inline
name|void
name|sha1FinalizeState
parameter_list|(
name|Sha1State
modifier|*
name|state
parameter_list|)
block|{
name|quint64
name|messageSize
init|=
name|state
operator|->
name|messageSize
decl_stmt|;
name|unsigned
name|char
name|sizeInBits
index|[
literal|8
index|]
decl_stmt|;
name|qToBigEndian
argument_list|(
name|messageSize
operator|<<
literal|3
argument_list|,
name|sizeInBits
argument_list|)
expr_stmt|;
name|sha1Update
argument_list|(
name|state
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
literal|"\200"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|unsigned
name|char
name|zero
index|[
literal|64
index|]
decl_stmt|;
name|memset
argument_list|(
name|zero
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
expr_stmt|;
if|if
condition|(
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|messageSize
operator|&
literal|63
argument_list|)
operator|>
literal|56
operator|-
literal|1
condition|)
block|{
name|sha1Update
argument_list|(
name|state
argument_list|,
name|zero
argument_list|,
literal|64
operator|-
literal|1
operator|-
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|messageSize
operator|&
literal|63
argument_list|)
argument_list|)
expr_stmt|;
name|sha1Update
argument_list|(
name|state
argument_list|,
name|zero
argument_list|,
literal|64
operator|-
literal|8
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sha1Update
argument_list|(
name|state
argument_list|,
name|zero
argument_list|,
literal|64
operator|-
literal|1
operator|-
literal|8
operator|-
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|messageSize
operator|&
literal|63
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|sha1Update
argument_list|(
name|state
argument_list|,
name|sizeInBits
argument_list|,
literal|8
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SHA1_WIPE_VARIABLES
name|memset
argument_list|(
name|state
operator|->
name|buffer
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|zero
argument_list|,
literal|0
argument_list|,
literal|64
argument_list|)
expr_stmt|;
name|state
operator|->
name|messageSize
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|sha1ToHash
specifier|static
specifier|inline
name|void
name|sha1ToHash
parameter_list|(
name|Sha1State
modifier|*
name|state
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|qToBigEndian
argument_list|(
name|state
operator|->
name|h0
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
name|qToBigEndian
argument_list|(
name|state
operator|->
name|h1
argument_list|,
name|buffer
operator|+
literal|4
argument_list|)
expr_stmt|;
name|qToBigEndian
argument_list|(
name|state
operator|->
name|h2
argument_list|,
name|buffer
operator|+
literal|8
argument_list|)
expr_stmt|;
name|qToBigEndian
argument_list|(
name|state
operator|->
name|h3
argument_list|,
name|buffer
operator|+
literal|12
argument_list|)
expr_stmt|;
name|qToBigEndian
argument_list|(
name|state
operator|->
name|h4
argument_list|,
name|buffer
operator|+
literal|16
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
