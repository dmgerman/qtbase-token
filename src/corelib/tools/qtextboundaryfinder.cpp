begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qtextboundaryfinder.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<private/qunicodetables_p.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"private/qharfbuzz_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTextBoundaryFinderPrivate
class|class
name|QTextBoundaryFinderPrivate
block|{
public|public:
DECL|member|attributes
name|HB_CharAttributes
name|attributes
index|[
literal|1
index|]
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
specifier|static
name|void
name|init
parameter_list|(
name|QTextBoundaryFinder
operator|::
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QChar
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|HB_CharAttributes
modifier|*
name|attributes
parameter_list|)
block|{
name|QVarLengthArray
argument_list|<
name|HB_ScriptItem
argument_list|>
name|scriptItems
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|string
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|ushort
operator|*
argument_list|>
argument_list|(
name|chars
argument_list|)
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|unicode
init|=
name|string
decl_stmt|;
comment|// correctly assign script, isTab and isObject to the script analysis
specifier|const
name|ushort
modifier|*
name|uc
init|=
name|unicode
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|e
init|=
name|uc
operator|+
name|length
decl_stmt|;
name|int
name|script
init|=
name|QUnicodeTables
operator|::
name|Common
decl_stmt|;
name|int
name|lastScript
init|=
name|QUnicodeTables
operator|::
name|Common
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|start
init|=
name|uc
decl_stmt|;
while|while
condition|(
name|uc
operator|<
name|e
condition|)
block|{
name|int
name|s
init|=
name|QUnicodeTables
operator|::
name|script
argument_list|(
operator|*
name|uc
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|!=
name|QUnicodeTables
operator|::
name|Inherited
condition|)
name|script
operator|=
name|s
expr_stmt|;
if|if
condition|(
operator|*
name|uc
operator|==
name|QChar
operator|::
name|ObjectReplacementCharacter
operator|||
operator|*
name|uc
operator|==
name|QChar
operator|::
name|LineSeparator
operator|||
operator|*
name|uc
operator|==
literal|9
condition|)
name|script
operator|=
name|QUnicodeTables
operator|::
name|Common
expr_stmt|;
if|if
condition|(
name|script
operator|!=
name|lastScript
condition|)
block|{
if|if
condition|(
name|uc
operator|!=
name|start
condition|)
block|{
name|HB_ScriptItem
name|item
decl_stmt|;
name|item
operator|.
name|pos
operator|=
name|start
operator|-
name|string
expr_stmt|;
name|item
operator|.
name|length
operator|=
name|uc
operator|-
name|start
expr_stmt|;
name|item
operator|.
name|script
operator|=
operator|(
name|HB_Script
operator|)
name|lastScript
expr_stmt|;
name|item
operator|.
name|bidiLevel
operator|=
literal|0
expr_stmt|;
comment|// ### what's the proper value?
name|scriptItems
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|start
operator|=
name|uc
expr_stmt|;
block|}
name|lastScript
operator|=
name|script
expr_stmt|;
block|}
operator|++
name|uc
expr_stmt|;
block|}
if|if
condition|(
name|uc
operator|!=
name|start
condition|)
block|{
name|HB_ScriptItem
name|item
decl_stmt|;
name|item
operator|.
name|pos
operator|=
name|start
operator|-
name|string
expr_stmt|;
name|item
operator|.
name|length
operator|=
name|uc
operator|-
name|start
expr_stmt|;
name|item
operator|.
name|script
operator|=
operator|(
name|HB_Script
operator|)
name|lastScript
expr_stmt|;
name|item
operator|.
name|bidiLevel
operator|=
literal|0
expr_stmt|;
comment|// ### what's the proper value?
name|scriptItems
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
name|qGetCharAttributes
argument_list|(
name|string
argument_list|,
name|length
argument_list|,
name|scriptItems
operator|.
name|data
argument_list|()
argument_list|,
name|scriptItems
operator|.
name|count
argument_list|()
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QTextBoundaryFinder
operator|::
name|Word
condition|)
name|HB_GetWordBoundaries
argument_list|(
name|string
argument_list|,
name|length
argument_list|,
name|scriptItems
operator|.
name|data
argument_list|()
argument_list|,
name|scriptItems
operator|.
name|count
argument_list|()
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
name|QTextBoundaryFinder
operator|::
name|Sentence
condition|)
name|HB_GetSentenceBoundaries
argument_list|(
name|string
argument_list|,
name|length
argument_list|,
name|scriptItems
operator|.
name|data
argument_list|()
argument_list|,
name|scriptItems
operator|.
name|count
argument_list|()
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!      \class QTextBoundaryFinder      \brief The QTextBoundaryFinder class provides a way of finding Unicode text boundaries in a string.      \since 4.4     \ingroup tools     \ingroup shared     \ingroup string-processing     \reentrant      QTextBoundaryFinder allows to find Unicode text boundaries in a     string, similar to the Unicode text boundary specification (see     http://www.unicode.org/reports/tr29/tr29-11.html).      QTextBoundaryFinder can operate on a QString in four possible     modes depending on the value of \a BoundaryType.      Units of Unicode characters that make up what the user thinks of     as a character or basic unit of the language are here called     Grapheme clusters. The two unicode characters 'A' + diaeresis do     for example form one grapheme cluster as the user thinks of them     as one character, yet it is in this case represented by two     unicode code points.      Word boundaries are there to locate the start and end of what a     language considers to be a word.      Line break boundaries give possible places where a line break     might happen and sentence boundaries will show the beginning and     end of whole sentences.      The first position in a string is always a valid boundary and     refers to the position before the first character. The last     position at the length of the string is also valid and refers     to the position after the last character. */
end_comment
begin_comment
comment|/*!     \enum QTextBoundaryFinder::BoundaryType      \value Grapheme Finds a grapheme which is the smallest boundary. It     including letters, punctation marks, numerals and more.     \value Word Finds a word.     \value Line Finds possible positions for breaking the text into multiple     lines.     \value Sentence Finds sentence boundaries. These include periods, question     marks etc. */
end_comment
begin_comment
comment|/*!   \enum QTextBoundaryFinder::BoundaryReason    \value NotAtBoundary  The boundary finder is not at a boundary position.   \value StartWord  The boundary finder is at the start of a word.   \value EndWord  The boundary finder is at the end of a word. */
end_comment
begin_comment
comment|/*!   Constructs an invalid QTextBoundaryFinder object. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|()
member_init_list|:
name|t
argument_list|(
name|Grapheme
argument_list|)
member_init_list|,
name|chars
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|length
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Copies the QTextBoundaryFinder object, \a other. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
specifier|const
name|QTextBoundaryFinder
modifier|&
name|other
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|other
operator|.
name|t
argument_list|)
member_init_list|,
name|s
argument_list|(
name|other
operator|.
name|s
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|other
operator|.
name|chars
argument_list|)
member_init_list|,
name|length
argument_list|(
name|other
operator|.
name|length
argument_list|)
member_init_list|,
name|pos
argument_list|(
name|other
operator|.
name|pos
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|,
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Assigns the object, \a other, to another QTextBoundaryFinder object. */
end_comment
begin_function
DECL|function|operator =
name|QTextBoundaryFinder
modifier|&
name|QTextBoundaryFinder
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QTextBoundaryFinder
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
operator|&
name|other
operator|==
name|this
condition|)
return|return
operator|*
name|this
return|;
name|t
operator|=
name|other
operator|.
name|t
expr_stmt|;
name|s
operator|=
name|other
operator|.
name|s
expr_stmt|;
name|chars
operator|=
name|other
operator|.
name|chars
expr_stmt|;
name|length
operator|=
name|other
operator|.
name|length
expr_stmt|;
name|pos
operator|=
name|other
operator|.
name|pos
expr_stmt|;
name|QTextBoundaryFinderPrivate
modifier|*
name|newD
init|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|realloc
argument_list|(
name|freePrivate
condition|?
name|d
else|:
literal|0
argument_list|,
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
argument_list|)
decl_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|newD
argument_list|)
expr_stmt|;
name|freePrivate
operator|=
literal|true
expr_stmt|;
name|d
operator|=
name|newD
expr_stmt|;
name|memcpy
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|,
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
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
comment|/*!   Destructs the QTextBoundaryFinder object. */
end_comment
begin_destructor
DECL|function|~QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|~
name|QTextBoundaryFinder
parameter_list|()
block|{
if|if
condition|(
name|freePrivate
condition|)
name|free
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   Creates a QTextBoundaryFinder object of \a type operating on \a string. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|type
argument_list|)
member_init_list|,
name|s
argument_list|(
name|string
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|string
operator|.
name|unicode
argument_list|()
argument_list|)
member_init_list|,
name|length
argument_list|(
name|string
operator|.
name|length
argument_list|()
argument_list|)
member_init_list|,
name|pos
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|freePrivate
argument_list|(
literal|true
argument_list|)
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|init
argument_list|(
name|t
argument_list|,
name|chars
argument_list|,
name|length
argument_list|,
name|d
operator|->
name|attributes
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Creates a QTextBoundaryFinder object of \a type operating on \a chars   with \a length.    \a buffer is an optional working buffer of size \a bufferSize you can pass to   the QTextBoundaryFinder. If the buffer is large enough to hold the working   data required, it will use this instead of allocating its own buffer.    \warning QTextBoundaryFinder does not create a copy of \a chars. It is the   application programmer's responsibility to ensure the array is allocated for   as long as the QTextBoundaryFinder object stays alive. The same applies to   \a buffer. */
end_comment
begin_constructor
DECL|function|QTextBoundaryFinder
name|QTextBoundaryFinder
operator|::
name|QTextBoundaryFinder
parameter_list|(
name|BoundaryType
name|type
parameter_list|,
specifier|const
name|QChar
modifier|*
name|chars
parameter_list|,
name|int
name|length
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|bufferSize
parameter_list|)
member_init_list|:
name|t
argument_list|(
name|type
argument_list|)
member_init_list|,
name|chars
argument_list|(
name|chars
argument_list|)
member_init_list|,
name|length
argument_list|(
name|length
argument_list|)
member_init_list|,
name|pos
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|buffer
operator|&&
operator|(
name|uint
operator|)
name|bufferSize
operator|>=
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
condition|)
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|buffer
expr_stmt|;
name|freePrivate
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|d
operator|=
operator|(
name|QTextBoundaryFinderPrivate
operator|*
operator|)
name|malloc
argument_list|(
name|length
operator|*
sizeof|sizeof
argument_list|(
name|HB_CharAttributes
argument_list|)
argument_list|)
expr_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|freePrivate
operator|=
literal|true
expr_stmt|;
block|}
name|init
argument_list|(
name|t
argument_list|,
name|chars
argument_list|,
name|length
argument_list|,
name|d
operator|->
name|attributes
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Moves the finder to the start of the string. This is equivalent to setPosition(0).    \sa setPosition(), position() */
end_comment
begin_function
DECL|function|toStart
name|void
name|QTextBoundaryFinder
operator|::
name|toStart
parameter_list|()
block|{
name|pos
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Moves the finder to the end of the string. This is equivalent to setPosition(string.length()).    \sa setPosition(), position() */
end_comment
begin_function
DECL|function|toEnd
name|void
name|QTextBoundaryFinder
operator|::
name|toEnd
parameter_list|()
block|{
name|pos
operator|=
name|length
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the current position of the QTextBoundaryFinder.    The range is from 0 (the beginning of the string) to the length of   the string inclusive.    \sa setPosition() */
end_comment
begin_function
DECL|function|position
name|int
name|QTextBoundaryFinder
operator|::
name|position
parameter_list|()
specifier|const
block|{
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the current position of the QTextBoundaryFinder to \a position.    If \a position is out of bounds, it will be bound to only valid   positions. In this case, valid positions are from 0 to the length of   the string inclusive.    \sa position() */
end_comment
begin_function
DECL|function|setPosition
name|void
name|QTextBoundaryFinder
operator|::
name|setPosition
parameter_list|(
name|int
name|position
parameter_list|)
block|{
name|pos
operator|=
name|qBound
argument_list|(
literal|0
argument_list|,
name|position
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn QTextBoundaryFinder::BoundaryType QTextBoundaryFinder::type() const    Returns the type of the QTextBoundaryFinder. */
end_comment
begin_comment
comment|/*! \fn bool QTextBoundaryFinder::isValid() const     Returns true if the text boundary finder is valid; otherwise returns false.    A default QTextBoundaryFinder is invalid. */
end_comment
begin_comment
comment|/*!   Returns the string  the QTextBoundaryFinder object operates on. */
end_comment
begin_function
DECL|function|string
name|QString
name|QTextBoundaryFinder
operator|::
name|string
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|chars
operator|==
name|s
operator|.
name|unicode
argument_list|()
operator|&&
name|length
operator|==
name|s
operator|.
name|length
argument_list|()
condition|)
return|return
name|s
return|;
return|return
name|QString
argument_list|(
name|chars
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Moves the QTextBoundaryFinder to the next boundary position and returns that position.    Returns -1 if there is no next boundary. */
end_comment
begin_function
DECL|function|toNextBoundary
name|int
name|QTextBoundaryFinder
operator|::
name|toNextBoundary
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
if|if
condition|(
name|pos
operator|<
literal|0
operator|||
name|pos
operator|>=
name|length
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
operator|++
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|==
name|length
condition|)
return|return
name|pos
return|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|charStop
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Word
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBoundary
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Sentence
case|:
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
case|case
name|Line
case|:
name|Q_ASSERT
argument_list|(
name|pos
argument_list|)
expr_stmt|;
while|while
condition|(
name|pos
operator|<
name|length
operator|&&
name|d
operator|->
name|attributes
index|[
name|pos
operator|-
literal|1
index|]
operator|.
name|lineBreakType
operator|<
name|HB_Break
condition|)
operator|++
name|pos
expr_stmt|;
break|break;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Moves the QTextBoundaryFinder to the previous boundary position and returns that position.    Returns -1 if there is no previous boundary. */
end_comment
begin_function
DECL|function|toPreviousBoundary
name|int
name|QTextBoundaryFinder
operator|::
name|toPreviousBoundary
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
if|if
condition|(
name|pos
operator|<=
literal|0
operator|||
name|pos
operator|>
name|length
condition|)
block|{
name|pos
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|pos
return|;
block|}
operator|--
name|pos
expr_stmt|;
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
return|return
name|pos
return|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|charStop
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Word
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBoundary
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Sentence
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
operator|!
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
case|case
name|Line
case|:
while|while
condition|(
name|pos
operator|>
literal|0
operator|&&
name|d
operator|->
name|attributes
index|[
name|pos
operator|-
literal|1
index|]
operator|.
name|lineBreakType
operator|<
name|HB_Break
condition|)
operator|--
name|pos
expr_stmt|;
break|break;
block|}
return|return
name|pos
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the object's position() is currently at a valid text boundary. */
end_comment
begin_function
DECL|function|isAtBoundary
name|bool
name|QTextBoundaryFinder
operator|::
name|isAtBoundary
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|pos
operator|<
literal|0
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|pos
operator|==
name|length
condition|)
return|return
literal|true
return|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|Grapheme
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|charStop
return|;
case|case
name|Word
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|wordBoundary
return|;
case|case
name|Line
case|:
return|return
operator|(
name|pos
operator|>
literal|0
operator|)
condition|?
name|d
operator|->
name|attributes
index|[
name|pos
operator|-
literal|1
index|]
operator|.
name|lineBreakType
operator|>=
name|HB_Break
else|:
literal|true
return|;
case|case
name|Sentence
case|:
return|return
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|sentenceBoundary
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the reasons for the boundary finder to have chosen the current position as a boundary. */
end_comment
begin_function
DECL|function|boundaryReasons
name|QTextBoundaryFinder
operator|::
name|BoundaryReasons
name|QTextBoundaryFinder
operator|::
name|boundaryReasons
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|NotAtBoundary
return|;
if|if
condition|(
operator|!
name|isAtBoundary
argument_list|()
condition|)
return|return
name|NotAtBoundary
return|;
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|whiteSpace
condition|)
return|return
name|NotAtBoundary
return|;
return|return
name|StartWord
return|;
block|}
if|if
condition|(
name|pos
operator|==
name|length
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|attributes
index|[
name|length
operator|-
literal|1
index|]
operator|.
name|whiteSpace
condition|)
return|return
name|NotAtBoundary
return|;
return|return
name|EndWord
return|;
block|}
specifier|const
name|bool
name|nextIsSpace
init|=
name|d
operator|->
name|attributes
index|[
name|pos
index|]
operator|.
name|whiteSpace
decl_stmt|;
specifier|const
name|bool
name|prevIsSpace
init|=
name|d
operator|->
name|attributes
index|[
name|pos
operator|-
literal|1
index|]
operator|.
name|whiteSpace
decl_stmt|;
if|if
condition|(
name|prevIsSpace
operator|&&
operator|!
name|nextIsSpace
condition|)
return|return
name|StartWord
return|;
elseif|else
if|if
condition|(
operator|!
name|prevIsSpace
operator|&&
name|nextIsSpace
condition|)
return|return
name|EndWord
return|;
elseif|else
if|if
condition|(
operator|!
name|prevIsSpace
operator|&&
operator|!
name|nextIsSpace
condition|)
return|return
name|BoundaryReasons
argument_list|(
name|StartWord
operator||
name|EndWord
argument_list|)
return|;
else|else
return|return
name|NotAtBoundary
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
