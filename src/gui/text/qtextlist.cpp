begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtextlist.h"
end_include
begin_include
include|#
directive|include
file|"qtextobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTextListPrivate
class|class
name|QTextListPrivate
super|:
specifier|public
name|QTextBlockGroupPrivate
block|{
public|public:
DECL|function|QTextListPrivate
name|QTextListPrivate
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|)
member_init_list|:
name|QTextBlockGroupPrivate
argument_list|(
name|doc
argument_list|)
block|{     }
block|}
class|;
end_class
begin_comment
comment|/*!     \class QTextList     \reentrant      \brief The QTextList class provides a decorated list of items in a QTextDocument.      \ingroup richtext-processing      A list contains a sequence of text blocks, each of which is marked with a     bullet point or other symbol. Multiple levels of lists can be used, and     the automatic numbering feature provides support for ordered numeric and     alphabetical lists.      Lists are created by using a text cursor to insert an empty list at the     current position or by moving existing text into a new list.     The \l{QTextCursor::insertList()} function inserts an empty block into the     document at the cursor position, and makes it the first item in a list.      \snippet doc/src/snippets/textdocument-lists/mainwindow.cpp 0      The \l{QTextCursor::createList()} function takes the contents of the     cursor's current block and turns it into the first item of a new list.      The cursor's current list is found with \l{QTextCursor::currentList()}.      The number of items in a list is given by count(). Each item can be     obtained by its index in the list with the item() function. Similarly,     the index of a given item can be found with itemNumber(). The text of     each item can be found with the itemText() function.      Note that the items in the list may not be adjacent elements in the     document. For example, the top-level items in a multi-level list will     be separated by the items in lower levels of the list.      List items can be deleted by index with the removeItem() function.     remove() deletes the specified item in the list.      The list's format is set with setFormat() and read with format().     The format describes the decoration of the list itself, and not the     individual items.      \sa QTextBlock, QTextListFormat, QTextCursor */
end_comment
begin_comment
comment|/*!     \fn bool QTextList::isEmpty() const     \obsolete      Returns true if the list has no items; otherwise returns false.      \bold{Note:} Empty lists are automatically deleted by the QTextDocument that owns     them.      \sa count() */
end_comment
begin_comment
comment|/*! \internal  */
end_comment
begin_constructor
DECL|function|QTextList
name|QTextList
operator|::
name|QTextList
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|)
member_init_list|:
name|QTextBlockGroup
argument_list|(
operator|*
operator|new
name|QTextListPrivate
argument_list|(
name|doc
argument_list|)
argument_list|,
name|doc
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_destructor
DECL|function|~QTextList
name|QTextList
operator|::
name|~
name|QTextList
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the number of items in the list. */
end_comment
begin_function
DECL|function|count
name|int
name|QTextList
operator|::
name|count
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTextList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|blocks
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the \a{i}-th text block in the list.      \sa count() itemText() */
end_comment
begin_function
DECL|function|item
name|QTextBlock
name|QTextList
operator|::
name|item
parameter_list|(
name|int
name|i
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTextList
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|d
operator|->
name|blocks
operator|.
name|size
argument_list|()
condition|)
return|return
name|QTextBlock
argument_list|()
return|;
return|return
name|d
operator|->
name|blocks
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QTextList::setFormat(const QTextListFormat&format)      Sets the list's format to \a format. */
end_comment
begin_comment
comment|/*!     \fn QTextListFormat QTextList::format() const      Returns the list's format. */
end_comment
begin_comment
comment|/*!     \fn int QTextList::itemNumber(const QTextBlock&block) const      Returns the index of the list item that corresponds to the given \a block.     Returns -1 if the block was not present in the list. */
end_comment
begin_function
DECL|function|itemNumber
name|int
name|QTextList
operator|::
name|itemNumber
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|blockIt
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTextList
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|blocks
operator|.
name|indexOf
argument_list|(
name|blockIt
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QTextList::itemText(const QTextBlock&block) const      Returns the text of the list item that corresponds to the given \a block. */
end_comment
begin_function
DECL|function|itemText
name|QString
name|QTextList
operator|::
name|itemText
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|blockIt
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QTextList
argument_list|)
expr_stmt|;
name|int
name|item
init|=
name|d
operator|->
name|blocks
operator|.
name|indexOf
argument_list|(
name|blockIt
argument_list|)
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|item
operator|<=
literal|0
condition|)
return|return
name|QString
argument_list|()
return|;
name|QTextBlock
name|block
init|=
name|d
operator|->
name|blocks
operator|.
name|at
argument_list|(
name|item
operator|-
literal|1
argument_list|)
decl_stmt|;
name|QTextBlockFormat
name|blockFormat
init|=
name|block
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
name|QString
name|result
decl_stmt|;
specifier|const
name|int
name|style
init|=
name|format
argument_list|()
operator|.
name|style
argument_list|()
decl_stmt|;
name|QString
name|numberPrefix
decl_stmt|;
name|QString
name|numberSuffix
init|=
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
decl_stmt|;
if|if
condition|(
name|format
argument_list|()
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ListNumberPrefix
argument_list|)
condition|)
name|numberPrefix
operator|=
name|format
argument_list|()
operator|.
name|numberPrefix
argument_list|()
expr_stmt|;
if|if
condition|(
name|format
argument_list|()
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ListNumberSuffix
argument_list|)
condition|)
name|numberSuffix
operator|=
name|format
argument_list|()
operator|.
name|numberSuffix
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|style
condition|)
block|{
case|case
name|QTextListFormat
operator|::
name|ListDecimal
case|:
name|result
operator|=
name|QString
operator|::
name|number
argument_list|(
name|item
argument_list|)
expr_stmt|;
break|break;
comment|// from the old richtext
case|case
name|QTextListFormat
operator|::
name|ListLowerAlpha
case|:
case|case
name|QTextListFormat
operator|::
name|ListUpperAlpha
case|:
block|{
specifier|const
name|char
name|baseChar
init|=
name|style
operator|==
name|QTextListFormat
operator|::
name|ListUpperAlpha
condition|?
literal|'A'
else|:
literal|'a'
decl_stmt|;
name|int
name|c
init|=
name|item
decl_stmt|;
while|while
condition|(
name|c
operator|>
literal|0
condition|)
block|{
name|c
operator|--
expr_stmt|;
name|result
operator|.
name|prepend
argument_list|(
name|QChar
argument_list|(
name|baseChar
operator|+
operator|(
name|c
operator|%
literal|26
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|c
operator|/=
literal|26
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QTextListFormat
operator|::
name|ListLowerRoman
case|:
case|case
name|QTextListFormat
operator|::
name|ListUpperRoman
case|:
block|{
if|if
condition|(
name|item
operator|<
literal|5000
condition|)
block|{
name|QByteArray
name|romanNumeral
decl_stmt|;
comment|// works for up to 4999 items
specifier|static
specifier|const
name|char
name|romanSymbolsLower
index|[]
init|=
literal|"iiivixxxlxcccdcmmmm"
decl_stmt|;
specifier|static
specifier|const
name|char
name|romanSymbolsUpper
index|[]
init|=
literal|"IIIVIXXXLXCCCDCMMMM"
decl_stmt|;
name|QByteArray
name|romanSymbols
decl_stmt|;
comment|// wrap to have "mid"
if|if
condition|(
name|style
operator|==
name|QTextListFormat
operator|::
name|ListLowerRoman
condition|)
name|romanSymbols
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|romanSymbolsLower
argument_list|,
sizeof|sizeof
argument_list|(
name|romanSymbolsLower
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|romanSymbols
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|romanSymbolsUpper
argument_list|,
sizeof|sizeof
argument_list|(
name|romanSymbolsUpper
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|c
index|[]
init|=
block|{
literal|1
block|,
literal|4
block|,
literal|5
block|,
literal|9
block|,
literal|10
block|,
literal|40
block|,
literal|50
block|,
literal|90
block|,
literal|100
block|,
literal|400
block|,
literal|500
block|,
literal|900
block|,
literal|1000
block|}
decl_stmt|;
name|int
name|n
init|=
name|item
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|12
init|;
name|i
operator|>=
literal|0
condition|;
name|n
operator|%=
name|c
index|[
name|i
index|]
operator|,
name|i
operator|--
control|)
block|{
name|int
name|q
init|=
name|n
operator|/
name|c
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|q
operator|>
literal|0
condition|)
block|{
name|int
name|startDigit
init|=
name|i
operator|+
operator|(
name|i
operator|+
literal|3
operator|)
operator|/
literal|4
decl_stmt|;
name|int
name|numDigits
decl_stmt|;
if|if
condition|(
name|i
operator|%
literal|4
condition|)
block|{
comment|// c[i] == 4|5|9|40|50|90|400|500|900
if|if
condition|(
operator|(
name|i
operator|-
literal|2
operator|)
operator|%
literal|4
condition|)
block|{
comment|// c[i] == 4|9|40|90|400|900 => with subtraction (IV, IX, XL, XC, ...)
name|numDigits
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
comment|// c[i] == 5|50|500 (V, L, D)
name|numDigits
operator|=
literal|1
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// c[i] == 1|10|100|1000 (I, II, III, X, XX, ...)
name|numDigits
operator|=
name|q
expr_stmt|;
block|}
name|romanNumeral
operator|.
name|append
argument_list|(
name|romanSymbols
operator|.
name|mid
argument_list|(
name|startDigit
argument_list|,
name|numDigits
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|result
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|romanNumeral
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|=
name|QLatin1String
argument_list|(
literal|"?"
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|blockIt
operator|.
name|textDirection
argument_list|()
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
return|return
name|numberSuffix
operator|+
name|result
operator|+
name|numberPrefix
return|;
else|else
return|return
name|numberPrefix
operator|+
name|result
operator|+
name|numberSuffix
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the item at item position \a i from the list. When the last item in the     list is removed, the list is automatically deleted by the QTextDocument that owns     it.      \sa add(), remove() */
end_comment
begin_function
DECL|function|removeItem
name|void
name|QTextList
operator|::
name|removeItem
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QTextList
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>=
name|d
operator|->
name|blocks
operator|.
name|size
argument_list|()
condition|)
return|return;
name|QTextBlock
name|block
init|=
name|d
operator|->
name|blocks
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|remove
argument_list|(
name|block
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the given \a block from the list.      \sa add(), removeItem() */
end_comment
begin_function
DECL|function|remove
name|void
name|QTextList
operator|::
name|remove
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
block|{
name|QTextBlockFormat
name|fmt
init|=
name|block
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
name|fmt
operator|.
name|setIndent
argument_list|(
name|fmt
operator|.
name|indent
argument_list|()
operator|+
name|format
argument_list|()
operator|.
name|indent
argument_list|()
argument_list|)
expr_stmt|;
name|fmt
operator|.
name|setObjectIndex
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|block
operator|.
name|docHandle
argument_list|()
operator|->
name|setBlockFormat
argument_list|(
name|block
argument_list|,
name|block
argument_list|,
name|fmt
argument_list|,
name|QTextDocumentPrivate
operator|::
name|SetFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Makes the given \a block part of the list.      \sa remove(), removeItem() */
end_comment
begin_function
DECL|function|add
name|void
name|QTextList
operator|::
name|add
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
block|{
name|QTextBlockFormat
name|fmt
init|=
name|block
operator|.
name|blockFormat
argument_list|()
decl_stmt|;
name|fmt
operator|.
name|setObjectIndex
argument_list|(
name|objectIndex
argument_list|()
argument_list|)
expr_stmt|;
name|block
operator|.
name|docHandle
argument_list|()
operator|->
name|setBlockFormat
argument_list|(
name|block
argument_list|,
name|block
argument_list|,
name|fmt
argument_list|,
name|QTextDocumentPrivate
operator|::
name|SetFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
