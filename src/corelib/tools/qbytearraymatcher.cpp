begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbytearraymatcher.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|bm_init_skiptable
specifier|static
specifier|inline
name|void
name|bm_init_skiptable
parameter_list|(
specifier|const
name|uchar
modifier|*
name|cc
parameter_list|,
name|int
name|len
parameter_list|,
name|uchar
modifier|*
name|skiptable
parameter_list|)
block|{
name|int
name|l
init|=
name|qMin
argument_list|(
name|len
argument_list|,
literal|255
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|skiptable
argument_list|,
name|l
argument_list|,
literal|256
operator|*
sizeof|sizeof
argument_list|(
name|uchar
argument_list|)
argument_list|)
expr_stmt|;
name|cc
operator|+=
name|len
operator|-
name|l
expr_stmt|;
while|while
condition|(
name|l
operator|--
condition|)
name|skiptable
index|[
operator|*
name|cc
operator|++
index|]
operator|=
name|l
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bm_find
specifier|static
specifier|inline
name|int
name|bm_find
parameter_list|(
specifier|const
name|uchar
modifier|*
name|cc
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|index
parameter_list|,
specifier|const
name|uchar
modifier|*
name|puc
parameter_list|,
name|uint
name|pl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|skiptable
parameter_list|)
block|{
if|if
condition|(
name|pl
operator|==
literal|0
condition|)
return|return
name|index
operator|>
name|l
condition|?
operator|-
literal|1
else|:
name|index
return|;
specifier|const
name|uint
name|pl_minus_one
init|=
name|pl
operator|-
literal|1
decl_stmt|;
specifier|register
specifier|const
name|uchar
modifier|*
name|current
init|=
name|cc
operator|+
name|index
operator|+
name|pl_minus_one
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|end
init|=
name|cc
operator|+
name|l
decl_stmt|;
while|while
condition|(
name|current
operator|<
name|end
condition|)
block|{
name|uint
name|skip
init|=
name|skiptable
index|[
operator|*
name|current
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|skip
condition|)
block|{
comment|// possible match
while|while
condition|(
name|skip
operator|<
name|pl
condition|)
block|{
if|if
condition|(
operator|*
operator|(
name|current
operator|-
name|skip
operator|)
operator|!=
name|puc
index|[
name|pl_minus_one
operator|-
name|skip
index|]
condition|)
break|break;
name|skip
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|skip
operator|>
name|pl_minus_one
condition|)
comment|// we have a match
return|return
operator|(
name|current
operator|-
name|cc
operator|)
operator|-
name|skip
operator|+
literal|1
return|;
comment|// in case we don't have a match we are a bit inefficient as we only skip by one
comment|// when we have the non matching char in the string.
if|if
condition|(
name|skiptable
index|[
operator|*
operator|(
name|current
operator|-
name|skip
operator|)
index|]
operator|==
name|pl
condition|)
name|skip
operator|=
name|pl
operator|-
name|skip
expr_stmt|;
else|else
name|skip
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|current
operator|>
name|end
operator|-
name|skip
condition|)
break|break;
name|current
operator|+=
name|skip
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
comment|// not found
block|}
end_function
begin_comment
comment|/*! \class QByteArrayMatcher     \inmodule QtCore     \brief The QByteArrayMatcher class holds a sequence of bytes that     can be quickly matched in a byte array.      \ingroup tools     \ingroup string-processing      This class is useful when you have a sequence of bytes that you     want to repeatedly match against some byte arrays (perhaps in a     loop), or when you want to search for the same sequence of bytes     multiple times in the same byte array. Using a matcher object and     indexIn() is faster than matching a plain QByteArray with     QByteArray::indexOf() if repeated matching takes place. This     class offers no benefit if you are doing one-off byte array     matches.      Create the QByteArrayMatcher with the QByteArray you want to     search for. Then call indexIn() on the QByteArray that you want to     search.      \sa QByteArray, QStringMatcher */
end_comment
begin_comment
comment|/*!     Constructs an empty byte array matcher that won't match anything.     Call setPattern() to give it a pattern to match. */
end_comment
begin_constructor
DECL|function|QByteArrayMatcher
name|QByteArrayMatcher
operator|::
name|QByteArrayMatcher
parameter_list|()
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|p
operator|.
name|p
operator|=
literal|0
expr_stmt|;
name|p
operator|.
name|l
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|p
operator|.
name|q_skiptable
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|p
operator|.
name|q_skiptable
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Constructs a byte array matcher from \a pattern. \a pattern   has the given \a length. \a pattern must remain in scope, but   the destructor does not delete \a pattern.  */
end_comment
begin_constructor
DECL|function|QByteArrayMatcher
name|QByteArrayMatcher
operator|::
name|QByteArrayMatcher
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
name|int
name|length
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|p
operator|.
name|p
operator|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|pattern
argument_list|)
expr_stmt|;
name|p
operator|.
name|l
operator|=
name|length
expr_stmt|;
name|bm_init_skiptable
argument_list|(
name|p
operator|.
name|p
argument_list|,
name|p
operator|.
name|l
argument_list|,
name|p
operator|.
name|q_skiptable
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a byte array matcher that will search for \a pattern.     Call indexIn() to perform a search. */
end_comment
begin_constructor
DECL|function|QByteArrayMatcher
name|QByteArrayMatcher
operator|::
name|QByteArrayMatcher
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pattern
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|q_pattern
argument_list|(
name|pattern
argument_list|)
block|{
name|p
operator|.
name|p
operator|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|pattern
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|l
operator|=
name|pattern
operator|.
name|size
argument_list|()
expr_stmt|;
name|bm_init_skiptable
argument_list|(
name|p
operator|.
name|p
argument_list|,
name|p
operator|.
name|l
argument_list|,
name|p
operator|.
name|q_skiptable
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Copies the \a other byte array matcher to this byte array matcher. */
end_comment
begin_constructor
DECL|function|QByteArrayMatcher
name|QByteArrayMatcher
operator|::
name|QByteArrayMatcher
parameter_list|(
specifier|const
name|QByteArrayMatcher
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|operator
name|=
parameter_list|(
name|other
parameter_list|)
function_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the byte array matcher. */
end_comment
begin_destructor
DECL|function|~QByteArrayMatcher
name|QByteArrayMatcher
operator|::
name|~
name|QByteArrayMatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Assigns the \a other byte array matcher to this byte array matcher. */
end_comment
begin_function
DECL|function|operator =
name|QByteArrayMatcher
modifier|&
name|QByteArrayMatcher
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QByteArrayMatcher
modifier|&
name|other
parameter_list|)
block|{
name|q_pattern
operator|=
name|other
operator|.
name|q_pattern
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|p
argument_list|,
operator|&
name|other
operator|.
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the byte array that this byte array matcher will search for     to \a pattern.      \sa pattern(), indexIn() */
end_comment
begin_function
DECL|function|setPattern
name|void
name|QByteArrayMatcher
operator|::
name|setPattern
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|pattern
parameter_list|)
block|{
name|q_pattern
operator|=
name|pattern
expr_stmt|;
name|p
operator|.
name|p
operator|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|pattern
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|.
name|l
operator|=
name|pattern
operator|.
name|size
argument_list|()
expr_stmt|;
name|bm_init_skiptable
argument_list|(
name|p
operator|.
name|p
argument_list|,
name|p
operator|.
name|l
argument_list|,
name|p
operator|.
name|q_skiptable
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Searches the byte array \a ba, from byte position \a from (default     0, i.e. from the first byte), for the byte array pattern() that     was set in the constructor or in the most recent call to     setPattern(). Returns the position where the pattern() matched in     \a ba, or -1 if no match was found. */
end_comment
begin_function
DECL|function|indexIn
name|int
name|QByteArrayMatcher
operator|::
name|indexIn
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|,
name|int
name|from
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|from
operator|<
literal|0
condition|)
name|from
operator|=
literal|0
expr_stmt|;
return|return
name|bm_find
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|ba
operator|.
name|size
argument_list|()
argument_list|,
name|from
argument_list|,
name|p
operator|.
name|p
argument_list|,
name|p
operator|.
name|l
argument_list|,
name|p
operator|.
name|q_skiptable
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Searches the char string \a str, which has length \a len, from     byte position \a from (default 0, i.e. from the first byte), for     the byte array pattern() that was set in the constructor or in the     most recent call to setPattern(). Returns the position where the     pattern() matched in \a str, or -1 if no match was found. */
end_comment
begin_function
DECL|function|indexIn
name|int
name|QByteArrayMatcher
operator|::
name|indexIn
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|from
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|from
operator|<
literal|0
condition|)
name|from
operator|=
literal|0
expr_stmt|;
return|return
name|bm_find
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|str
argument_list|)
argument_list|,
name|len
argument_list|,
name|from
argument_list|,
name|p
operator|.
name|p
argument_list|,
name|p
operator|.
name|l
argument_list|,
name|p
operator|.
name|q_skiptable
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QByteArray QByteArrayMatcher::pattern() const      Returns the byte array pattern that this byte array matcher will     search for.      \sa setPattern() */
end_comment
begin_function
DECL|function|findChar
specifier|static
name|int
name|findChar
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|,
name|char
name|ch
parameter_list|,
name|int
name|from
parameter_list|)
block|{
specifier|const
name|uchar
modifier|*
name|s
init|=
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|str
decl_stmt|;
name|uchar
name|c
init|=
operator|(
name|uchar
operator|)
name|ch
decl_stmt|;
if|if
condition|(
name|from
operator|<
literal|0
condition|)
name|from
operator|=
name|qMax
argument_list|(
name|from
operator|+
name|len
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|from
operator|<
name|len
condition|)
block|{
specifier|const
name|uchar
modifier|*
name|n
init|=
name|s
operator|+
name|from
operator|-
literal|1
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|e
init|=
name|s
operator|+
name|len
decl_stmt|;
while|while
condition|(
operator|++
name|n
operator|!=
name|e
condition|)
if|if
condition|(
operator|*
name|n
operator|==
name|c
condition|)
return|return
name|n
operator|-
name|s
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|qFindByteArrayBoyerMoore
specifier|static
name|int
name|qFindByteArrayBoyerMoore
parameter_list|(
specifier|const
name|char
modifier|*
name|haystack
parameter_list|,
name|int
name|haystackLen
parameter_list|,
name|int
name|haystackOffset
parameter_list|,
specifier|const
name|char
modifier|*
name|needle
parameter_list|,
name|int
name|needleLen
parameter_list|)
block|{
name|uchar
name|skiptable
index|[
literal|256
index|]
decl_stmt|;
name|bm_init_skiptable
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|needle
argument_list|,
name|needleLen
argument_list|,
name|skiptable
argument_list|)
expr_stmt|;
if|if
condition|(
name|haystackOffset
operator|<
literal|0
condition|)
name|haystackOffset
operator|=
literal|0
expr_stmt|;
return|return
name|bm_find
argument_list|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|haystack
argument_list|,
name|haystackLen
argument_list|,
name|haystackOffset
argument_list|,
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|needle
argument_list|,
name|needleLen
argument_list|,
name|skiptable
argument_list|)
return|;
block|}
end_function
begin_define
DECL|macro|REHASH
define|#
directive|define
name|REHASH
parameter_list|(
name|a
parameter_list|)
define|\
value|if (sl_minus_1< sizeof(uint) * CHAR_BIT) \         hashHaystack -= (a)<< sl_minus_1; \     hashHaystack<<= 1
end_define
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|qFindByteArray
name|int
name|qFindByteArray
parameter_list|(
specifier|const
name|char
modifier|*
name|haystack0
parameter_list|,
name|int
name|haystackLen
parameter_list|,
name|int
name|from
parameter_list|,
specifier|const
name|char
modifier|*
name|needle
parameter_list|,
name|int
name|needleLen
parameter_list|)
block|{
specifier|const
name|int
name|l
init|=
name|haystackLen
decl_stmt|;
specifier|const
name|int
name|sl
init|=
name|needleLen
decl_stmt|;
if|if
condition|(
name|from
operator|<
literal|0
condition|)
name|from
operator|+=
name|l
expr_stmt|;
if|if
condition|(
name|uint
argument_list|(
name|sl
operator|+
name|from
argument_list|)
operator|>
operator|(
name|uint
operator|)
name|l
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|!
name|sl
condition|)
return|return
name|from
return|;
if|if
condition|(
operator|!
name|l
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|sl
operator|==
literal|1
condition|)
return|return
name|findChar
argument_list|(
name|haystack0
argument_list|,
name|haystackLen
argument_list|,
name|needle
index|[
literal|0
index|]
argument_list|,
name|from
argument_list|)
return|;
comment|/*       We use the Boyer-Moore algorithm in cases where the overhead       for the skip table should pay off, otherwise we use a simple       hash function.     */
if|if
condition|(
name|l
operator|>
literal|500
operator|&&
name|sl
operator|>
literal|5
condition|)
return|return
name|qFindByteArrayBoyerMoore
argument_list|(
name|haystack0
argument_list|,
name|haystackLen
argument_list|,
name|from
argument_list|,
name|needle
argument_list|,
name|needleLen
argument_list|)
return|;
comment|/*       We use some hashing for efficiency's sake. Instead of       comparing strings, we compare the hash value of str with that       of a part of this QString. Only if that matches, we call memcmp().     */
specifier|const
name|char
modifier|*
name|haystack
init|=
name|haystack0
operator|+
name|from
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
init|=
name|haystack0
operator|+
operator|(
name|l
operator|-
name|sl
operator|)
decl_stmt|;
specifier|const
name|uint
name|sl_minus_1
init|=
name|sl
operator|-
literal|1
decl_stmt|;
name|uint
name|hashNeedle
init|=
literal|0
decl_stmt|,
name|hashHaystack
init|=
literal|0
decl_stmt|;
name|int
name|idx
decl_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|sl
condition|;
operator|++
name|idx
control|)
block|{
name|hashNeedle
operator|=
operator|(
operator|(
name|hashNeedle
operator|<<
literal|1
operator|)
operator|+
name|needle
index|[
name|idx
index|]
operator|)
expr_stmt|;
name|hashHaystack
operator|=
operator|(
operator|(
name|hashHaystack
operator|<<
literal|1
operator|)
operator|+
name|haystack
index|[
name|idx
index|]
operator|)
expr_stmt|;
block|}
name|hashHaystack
operator|-=
operator|*
operator|(
name|haystack
operator|+
name|sl_minus_1
operator|)
expr_stmt|;
while|while
condition|(
name|haystack
operator|<=
name|end
condition|)
block|{
name|hashHaystack
operator|+=
operator|*
operator|(
name|haystack
operator|+
name|sl_minus_1
operator|)
expr_stmt|;
if|if
condition|(
name|hashHaystack
operator|==
name|hashNeedle
operator|&&
operator|*
name|needle
operator|==
operator|*
name|haystack
operator|&&
name|memcmp
argument_list|(
name|needle
argument_list|,
name|haystack
argument_list|,
name|sl
argument_list|)
operator|==
literal|0
condition|)
return|return
name|haystack
operator|-
name|haystack0
return|;
name|REHASH
argument_list|(
operator|*
name|haystack
argument_list|)
expr_stmt|;
operator|++
name|haystack
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
