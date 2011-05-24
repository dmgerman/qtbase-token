begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Most of the code here was originally written by Serika Kurusugawa
end_comment
begin_comment
comment|// a.k.a. Junji Takagi, and is included in Qt with the author's permission,
end_comment
begin_comment
comment|// and the grateful thanks of the Qt team.
end_comment
begin_comment
comment|/*! \class QSjisCodec     \reentrant     \internal */
end_comment
begin_include
include|#
directive|include
file|"qsjiscodec.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
name|enum
type|{
DECL|enumerator|Esc
name|Esc
init|=
literal|0x1b
end_decl_stmt
begin_define
DECL|macro|IsKana
unit|};
define|#
directive|define
name|IsKana
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0xa1)&& ((c)<= 0xdf))
end_define
begin_define
DECL|macro|IsSjisChar1
define|#
directive|define
name|IsSjisChar1
parameter_list|(
name|c
parameter_list|)
value|((((c)>= 0x81)&& ((c)<= 0x9f)) ||        \                          (((c)>= 0xe0)&& ((c)<= 0xfc)))
end_define
begin_define
DECL|macro|IsSjisChar2
define|#
directive|define
name|IsSjisChar2
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x40)&& ((c) != 0x7f)&& ((c)<= 0xfc))
end_define
begin_define
DECL|macro|IsUserDefinedChar1
define|#
directive|define
name|IsUserDefinedChar1
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0xf0)&& ((c)<= 0xfc))
end_define
begin_define
DECL|macro|QValidChar
define|#
directive|define
name|QValidChar
parameter_list|(
name|u
parameter_list|)
value|((u) ? QChar((ushort)(u)) : QChar(QChar::ReplacementCharacter))
end_define
begin_comment
comment|/*!   Creates a Shift-JIS codec. Note that this is done automatically by   the QApplication, you do not need construct your own. */
end_comment
begin_constructor
DECL|function|QSjisCodec
name|QSjisCodec
operator|::
name|QSjisCodec
parameter_list|()
member_init_list|:
name|conv
argument_list|(
name|QJpUnicodeConv
operator|::
name|newConverter
argument_list|(
name|QJpUnicodeConv
operator|::
name|Default
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys the Shift-JIS codec. */
end_comment
begin_destructor
DECL|function|~QSjisCodec
name|QSjisCodec
operator|::
name|~
name|QSjisCodec
parameter_list|()
block|{
operator|delete
operator|(
name|QJpUnicodeConv
operator|*
operator|)
name|conv
expr_stmt|;
name|conv
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QSjisCodec
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
name|int
name|rlen
init|=
literal|2
operator|*
name|len
operator|+
literal|1
decl_stmt|;
name|QByteArray
name|rstr
decl_stmt|;
name|rstr
operator|.
name|resize
argument_list|(
name|rlen
argument_list|)
expr_stmt|;
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
name|uint
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
operator|*
name|cursor
operator|++
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
name|conv
operator|->
name|unicodeToJisx0201
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0201 Latin or JIS X 0201 Kana
operator|*
name|cursor
operator|++
operator|=
name|j
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToSjis
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0208
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|&
literal|0xff
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToSjisibmvdc
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0208 IBM VDC
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|&
literal|0xff
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToCp932
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// CP932 (for lead bytes 87, ee& ed)
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|&
literal|0xff
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToJisx0212
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0212 (can't be encoded in ShiftJIS !)
operator|*
name|cursor
operator|++
operator|=
literal|0x81
expr_stmt|;
comment|// white square
operator|*
name|cursor
operator|++
operator|=
literal|0xa0
expr_stmt|;
comment|// white square
block|}
else|else
block|{
comment|// Error
operator|*
name|cursor
operator|++
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
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
begin_function
DECL|function|convertToUnicode
name|QString
name|QSjisCodec
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
name|uchar
name|buf
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|int
name|nbuf
init|=
literal|0
decl_stmt|;
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
name|nbuf
operator|=
name|state
operator|->
name|remainingChars
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|state
operator|->
name|state_data
index|[
literal|0
index|]
expr_stmt|;
block|}
name|int
name|invalid
init|=
literal|0
decl_stmt|;
name|uint
name|u
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
switch|switch
condition|(
name|nbuf
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|ch
operator|<
literal|0x80
condition|)
block|{
name|result
operator|+=
name|QValidChar
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsKana
argument_list|(
name|ch
argument_list|)
condition|)
block|{
comment|// JIS X 0201 Latin or JIS X 0201 Kana
name|u
operator|=
name|conv
operator|->
name|jisx0201ToUnicode
argument_list|(
name|ch
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsSjisChar1
argument_list|(
name|ch
argument_list|)
condition|)
block|{
comment|// JIS X 0208
name|buf
index|[
literal|0
index|]
operator|=
name|ch
expr_stmt|;
name|nbuf
operator|=
literal|1
expr_stmt|;
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
break|break;
case|case
literal|1
case|:
comment|// JIS X 0208
if|if
condition|(
name|IsSjisChar2
argument_list|(
name|ch
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|u
operator|=
name|conv
operator|->
name|sjisibmvdcToUnicode
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|,
name|ch
argument_list|)
operator|)
condition|)
block|{
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|u
operator|=
name|conv
operator|->
name|cp932ToUnicode
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|,
name|ch
argument_list|)
operator|)
condition|)
block|{
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsUserDefinedChar1
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|result
operator|+=
name|QChar
operator|::
name|ReplacementCharacter
expr_stmt|;
block|}
else|else
block|{
name|u
operator|=
name|conv
operator|->
name|sjisToUnicode
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|,
name|ch
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
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
name|nbuf
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|remainingChars
operator|=
name|nbuf
expr_stmt|;
name|state
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
name|buf
index|[
literal|0
index|]
expr_stmt|;
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
begin_function
DECL|function|_mibEnum
name|int
name|QSjisCodec
operator|::
name|_mibEnum
parameter_list|()
block|{
return|return
literal|17
return|;
block|}
end_function
begin_function
DECL|function|_name
name|QByteArray
name|QSjisCodec
operator|::
name|_name
parameter_list|()
block|{
return|return
literal|"Shift_JIS"
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the codec's mime name. */
end_comment
begin_function
DECL|function|_aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QSjisCodec
operator|::
name|_aliases
parameter_list|()
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|"SJIS"
comment|// Qt 3 compat
operator|<<
literal|"MS_Kanji"
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
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
end_unit
