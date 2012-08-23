begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Most of the code here was originally written by Hans Petter Bieker,
end_comment
begin_comment
comment|// and is included in Qt with the author's permission, and the grateful
end_comment
begin_comment
comment|// thanks of the Qt team.
end_comment
begin_include
include|#
directive|include
file|"qtsciicodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|static
name|unsigned
name|char
name|qt_UnicodeToTSCII
parameter_list|(
name|ushort
name|u1
parameter_list|,
name|ushort
name|u2
parameter_list|,
name|ushort
name|u3
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|unsigned
name|int
name|qt_TSCIIToUnicode
parameter_list|(
name|unsigned
name|int
name|code
parameter_list|,
name|uint
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|IsTSCIIChar
define|#
directive|define
name|IsTSCIIChar
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x80)&& ((c)<= 0xfd))
end_define
begin_comment
comment|/*! \class QTsciiCodec     \inmodule QtCore     \reentrant     \internal */
end_comment
begin_comment
comment|/*!     Destroys the text codec object. */
end_comment
begin_destructor
DECL|function|~QTsciiCodec
name|QTsciiCodec
operator|::
name|~
name|QTsciiCodec
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Converts the first \a len characters in \a uc from Unicode to this     encoding, and returns the result in a byte array. The \a state contains     some conversion flags, and is used by the codec to maintain state     information. */
end_comment
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QTsciiCodec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|char
name|replacement
init|=
literal|'?'
decl_stmt|;
if|if
condition|(
name|state
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
condition|)
name|replacement
operator|=
literal|0
expr_stmt|;
block|}
name|int
name|invalid
init|=
literal|0
decl_stmt|;
name|QByteArray
name|rstr
argument_list|(
name|len
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|uchar
modifier|*
name|cursor
init|=
operator|(
name|uchar
operator|*
operator|)
name|rstr
operator|.
name|data
argument_list|()
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
name|len
condition|;
name|i
operator|++
control|)
block|{
name|QChar
name|ch
init|=
name|uc
index|[
name|i
index|]
decl_stmt|;
name|uchar
name|j
decl_stmt|;
if|if
condition|(
name|ch
operator|.
name|row
argument_list|()
operator|==
literal|0x00
operator|&&
name|ch
operator|.
name|cell
argument_list|()
operator|<
literal|0x80
condition|)
block|{
comment|// ASCII
name|j
operator|=
name|ch
operator|.
name|cell
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|qt_UnicodeToTSCII
argument_list|(
name|uc
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
name|uc
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
name|uc
index|[
name|i
operator|+
literal|2
index|]
operator|.
name|unicode
argument_list|()
argument_list|)
operator|)
condition|)
block|{
comment|// We have to check the combined chars first!
name|i
operator|+=
literal|2
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|qt_UnicodeToTSCII
argument_list|(
name|uc
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
name|uc
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
name|i
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|qt_UnicodeToTSCII
argument_list|(
name|uc
index|[
name|i
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{         }
else|else
block|{
comment|// Error
name|j
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
operator|*
name|cursor
operator|++
operator|=
name|j
expr_stmt|;
block|}
name|rstr
operator|.
name|resize
argument_list|(
name|cursor
operator|-
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|rstr
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
block|}
return|return
name|rstr
return|;
block|}
end_function
begin_comment
comment|/*!     Converts the first \a len characters in \a chars from this encoding     to Unicode, and returns the result in a QString. The \a state contains     some conversion flags, and is used by the codec to maintain state     information. */
end_comment
begin_function
DECL|function|convertToUnicode
name|QString
name|QTsciiCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|QChar
name|replacement
init|=
name|QChar
operator|::
name|ReplacementCharacter
decl_stmt|;
if|if
condition|(
name|state
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
condition|)
name|replacement
operator|=
name|QChar
operator|::
name|Null
expr_stmt|;
block|}
name|int
name|invalid
init|=
literal|0
decl_stmt|;
name|QString
name|result
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
name|len
condition|;
name|i
operator|++
control|)
block|{
name|uchar
name|ch
init|=
name|chars
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|ch
operator|<
literal|0x80
condition|)
block|{
comment|// ASCII
name|result
operator|+=
name|QLatin1Char
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsTSCIIChar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
comment|// TSCII
name|uint
name|s
index|[
literal|3
index|]
decl_stmt|;
name|uint
name|u
init|=
name|qt_TSCIIToUnicode
argument_list|(
name|ch
argument_list|,
name|s
argument_list|)
decl_stmt|;
name|uint
modifier|*
name|p
init|=
name|s
decl_stmt|;
while|while
condition|(
name|u
operator|--
condition|)
block|{
name|uint
name|c
init|=
operator|*
name|p
operator|++
decl_stmt|;
if|if
condition|(
name|c
condition|)
name|result
operator|+=
name|QChar
argument_list|(
name|c
argument_list|)
expr_stmt|;
else|else
block|{
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// Invalid
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
block|}
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the official name for the encoding that is handled by the codec.      \sa QTextCodec::name() */
end_comment
begin_function
DECL|function|name
name|QByteArray
name|QTsciiCodec
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"TSCII"
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the MIB enum for the encoding.      \sa QTextCodec::mibEnum() */
end_comment
begin_function
DECL|function|mibEnum
name|int
name|QTsciiCodec
operator|::
name|mibEnum
parameter_list|()
specifier|const
block|{
return|return
literal|2107
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|UnToTsLast
specifier|static
specifier|const
name|int
name|UnToTsLast
init|=
literal|124
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|UnToTsLast
comment|// 125 items -- so the last will be 124
end_comment
begin_decl_stmt
DECL|variable|UnToTs
specifier|static
specifier|const
name|ushort
name|UnToTs
index|[]
index|[
literal|4
index|]
init|=
block|{
comment|// *Sorted* list of TSCII maping for unicode chars
comment|//FIRST  SECOND  THIRD   TSCII
block|{
literal|0x00A0
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA0
block|}
block|,
block|{
literal|0x00A9
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA9
block|}
block|,
block|{
literal|0x0B83
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB7
block|}
block|,
block|{
literal|0x0B85
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAB
block|}
block|,
block|{
literal|0x0B86
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAC
block|}
block|,
block|{
literal|0x0B87
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAD
block|}
block|,
block|{
literal|0x0B88
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAE
block|}
block|,
block|{
literal|0x0B89
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAF
block|}
block|,
block|{
literal|0x0B8A
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB0
block|}
block|,
block|{
literal|0x0B8E
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB1
block|}
block|,
block|{
literal|0x0B8F
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB2
block|}
block|,
block|{
literal|0x0B90
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB3
block|}
block|,
block|{
literal|0x0B92
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB4
block|}
block|,
block|{
literal|0x0B93
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB5
block|}
block|,
block|{
literal|0x0B94
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB6
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB8
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xEC
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xCC
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xDC
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xB9
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xED
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0x99
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0x9B
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBA
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xEE
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xCD
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xDD
block|}
block|,
block|{
literal|0x0B9C
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x83
block|}
block|,
block|{
literal|0x0B9C
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0x88
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBB
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xEF
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0x9A
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0x9C
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBC
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF0
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BBF
block|,
literal|0x0000
block|,
literal|0xCA
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC0
block|,
literal|0x0000
block|,
literal|0xCB
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xCE
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xDE
block|}
block|,
block|{
literal|0x0BA1
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF2
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBD
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF1
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xCF
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xDF
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBE
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD0
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE0
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xBF
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF3
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD1
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE1
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC9
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xFD
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xDB
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xEB
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC0
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF4
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD2
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE2
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC1
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF5
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD3
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE3
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC2
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF6
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD4
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE4
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC3
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF7
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD5
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE5
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC8
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xFC
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xDA
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xEA
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC4
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF8
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD6
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE6
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC7
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xFB
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD9
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE9
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC6
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xFA
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD8
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE8
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xC5
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0xF9
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0xD7
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0xE7
block|}
block|,
block|{
literal|0x0BB7
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x84
block|}
block|,
block|{
literal|0x0BB7
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0x89
block|}
block|,
block|{
literal|0x0BB8
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x85
block|}
block|,
block|{
literal|0x0BB8
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0x8A
block|}
block|,
block|{
literal|0x0BB9
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x86
block|}
block|,
block|{
literal|0x0BB9
block|,
literal|0x0B82
block|,
literal|0x0000
block|,
literal|0x8B
block|}
block|,
block|{
literal|0x0BBE
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA1
block|}
block|,
block|{
literal|0x0BBF
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA2
block|}
block|,
block|{
literal|0x0BC0
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA3
block|}
block|,
block|{
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA4
block|}
block|,
block|{
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA5
block|}
block|,
block|{
literal|0x0BC6
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA6
block|}
block|,
block|{
literal|0x0BC7
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA7
block|}
block|,
block|{
literal|0x0BC8
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xA8
block|}
block|,
block|{
literal|0x0BCC
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0xAA
block|}
block|,
block|{
literal|0x0BE6
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x80
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x81
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0BB7
block|,
literal|0x0000
block|,
literal|0x87
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0BB7
block|,
literal|0x0B82
block|,
literal|0x8C
block|}
block|,
block|{
literal|0x0BE8
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x8D
block|}
block|,
block|{
literal|0x0BE9
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x8E
block|}
block|,
block|{
literal|0x0BEA
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x8F
block|}
block|,
block|{
literal|0x0BEB
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x90
block|}
block|,
block|{
literal|0x0BEC
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x95
block|}
block|,
block|{
literal|0x0BED
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x96
block|}
block|,
block|{
literal|0x0BEE
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x97
block|}
block|,
block|{
literal|0x0BEF
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x98
block|}
block|,
block|{
literal|0x0BF0
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x9D
block|}
block|,
block|{
literal|0x0BF1
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x9E
block|}
block|,
block|{
literal|0x0BF2
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x9F
block|}
block|,
block|{
literal|0x2018
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x91
block|}
block|,
block|{
literal|0x2019
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x92
block|}
block|,
block|{
literal|0x201C
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x93
block|}
block|,
block|{
literal|0x201C
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x94
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TsToUn
specifier|static
specifier|const
name|ushort
name|TsToUn
index|[]
index|[
literal|3
index|]
init|=
block|{
comment|// Starting at 0x80
block|{
literal|0x0BE6
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
comment|// unknown
block|{
literal|0x0B9C
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB7
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB8
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB9
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0BB7
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9C
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB7
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB8
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB9
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BE7
block|,
literal|0x0BB7
block|,
literal|0x0B82
block|}
block|,
block|{
literal|0x0BE8
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BE9
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BEA
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BEB
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x2018
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x2019
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x201C
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x201C
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
comment|// two of the same??
block|{
literal|0x0BEC
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BED
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BEE
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BEF
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BF0
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BF1
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BF2
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x00A0
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BBE
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BBF
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC0
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC1
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC2
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC6
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC7
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BC8
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x00A9
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BCC
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B85
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B86
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B87
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B88
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B89
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B8A
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B8E
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B8F
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B90
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B92
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B93
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B94
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B83
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0000
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BBF
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC0
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0BC1
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA4
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0BC2
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B95
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B99
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9A
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9E
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0B9F
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA3
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA1
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA8
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAA
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAE
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BAF
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB0
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB2
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB5
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB4
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB3
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BB1
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|,
block|{
literal|0x0BA9
block|,
literal|0x0B82
block|,
literal|0x0000
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|cmp
specifier|static
name|int
name|cmp
parameter_list|(
specifier|const
name|ushort
modifier|*
name|s1
parameter_list|,
specifier|const
name|ushort
modifier|*
name|s2
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|int
name|diff
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|&&
operator|(
name|diff
operator|=
operator|*
name|s1
operator|++
operator|-
operator|*
name|s2
operator|++
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
return|return
name|diff
return|;
block|}
end_function
begin_function
DECL|function|qt_UnicodeToTSCII
specifier|static
name|unsigned
name|char
name|qt_UnicodeToTSCII
parameter_list|(
name|ushort
name|u1
parameter_list|,
name|ushort
name|u2
parameter_list|,
name|ushort
name|u3
parameter_list|)
block|{
name|ushort
name|s
index|[
literal|3
index|]
decl_stmt|;
name|s
index|[
literal|0
index|]
operator|=
name|u1
expr_stmt|;
name|s
index|[
literal|1
index|]
operator|=
name|u2
expr_stmt|;
name|s
index|[
literal|2
index|]
operator|=
name|u3
expr_stmt|;
name|int
name|a
init|=
literal|0
decl_stmt|;
comment|// start pos
name|int
name|b
init|=
name|UnToTsLast
decl_stmt|;
comment|// end pos
comment|// do a binary search for the composed unicode in the list
while|while
condition|(
name|a
operator|<=
name|b
condition|)
block|{
name|int
name|w
init|=
operator|(
name|a
operator|+
name|b
operator|)
operator|/
literal|2
decl_stmt|;
name|int
name|j
init|=
name|cmp
argument_list|(
name|UnToTs
index|[
name|w
index|]
argument_list|,
name|s
argument_list|,
literal|3
argument_list|)
decl_stmt|;
if|if
condition|(
name|j
operator|==
literal|0
condition|)
comment|// found it
return|return
name|UnToTs
index|[
name|w
index|]
index|[
literal|3
index|]
return|;
if|if
condition|(
name|j
operator|<
literal|0
condition|)
name|a
operator|=
name|w
operator|+
literal|1
expr_stmt|;
else|else
name|b
operator|=
name|w
operator|-
literal|1
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_TSCIIToUnicode
specifier|static
name|unsigned
name|int
name|qt_TSCIIToUnicode
parameter_list|(
name|uint
name|code
parameter_list|,
name|uint
modifier|*
name|s
parameter_list|)
block|{
name|int
name|len
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
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|uint
name|u
init|=
name|TsToUn
index|[
name|code
operator|&
literal|0x7f
index|]
index|[
name|i
index|]
decl_stmt|;
name|s
index|[
name|i
index|]
operator|=
name|u
expr_stmt|;
if|if
condition|(
name|s
index|[
name|i
index|]
condition|)
name|len
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
return|return
name|len
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BIG_CODECS
end_comment
end_unit
