begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*! \typedef QStringListIterator     \relates QStringList      The QStringListIterator type definition provides a Java-style const     iterator for QStringList.      QStringList provides both \l{Java-style iterators} and     \l{STL-style iterators}. The Java-style const iterator is simply     a type definition for QListIterator<QString>.      \sa QMutableStringListIterator, QStringList::const_iterator */
comment|/*! \typedef QMutableStringListIterator     \relates QStringList      The QStringListIterator type definition provides a Java-style     non-const iterator for QStringList.      QStringList provides both \l{Java-style iterators} and     \l{STL-style iterators}. The Java-style non-const iterator is     simply a type definition for QMutableListIterator<QString>.      \sa QStringListIterator, QStringList::iterator */
comment|/*!     \class QStringList     \brief The QStringList class provides a list of strings.      \ingroup tools     \ingroup shared     \ingroup string-processing      \reentrant      QStringList inherits from QList<QString>. Like QList, QStringList is     \l{implicitly shared}. It provides fast index-based access as well as fast     insertions and removals. Passing string lists as value parameters is both     fast and safe.      All of QList's functionality also applies to QStringList. For example, you     can use isEmpty() to test whether the list is empty, and you can call     functions like append(), prepend(), insert(), replace(), removeAll(),     removeAt(), removeFirst(), removeLast(), and removeOne() to modify a     QStringList. In addition, QStringList provides a few convenience     functions that make handling lists of strings easier:      \tableofcontents      \section1 Adding strings      Strings can be added to a list using the \l     {QList::append()}{append()}, \l     {QList::operator+=()}{operator+=()} and \l     {QStringList::operator<<()}{operator<<()} functions. For example:      \snippet doc/src/snippets/qstringlist/main.cpp 0      \section1 Iterating over the strings      To iterate over a list, you can either use index positions or     QList's Java-style and STL-style iterator types:      Indexing:      \snippet doc/src/snippets/qstringlist/main.cpp 1      Java-style iterator:      \snippet doc/src/snippets/qstringlist/main.cpp 2      STL-style iterator:      \snippet doc/src/snippets/qstringlist/main.cpp 3      The QStringListIterator class is simply a type definition for     QListIterator<QString>. QStringList also provide the     QMutableStringListIterator class which is a type definition for     QMutableListIterator<QString>.      \section1 Manipulating the strings      QStringList provides several functions allowing you to manipulate     the contents of a list. You can concatenate all the strings in a     string list into a single string (with an optional separator)     using the join() function. For example:      \snippet doc/src/snippets/qstringlist/main.cpp 4      To break up a string into a string list, use the QString::split()     function:      \snippet doc/src/snippets/qstringlist/main.cpp 6      The argument to split can be a single character, a string, or a     QRegExp.      In addition, the \l {QStringList::operator+()}{operator+()}     function allows you to concatenate two string lists into one. To     sort a string list, use the sort() function.      QString list also provides the filter() function which lets you     to extract a new list which contains only those strings which     contain a particular substring (or match a particular regular     expression):      \snippet doc/src/snippets/qstringlist/main.cpp 7      The contains() function tells you whether the list contains a     given string, while the indexOf() function returns the index of     the first occurrence of the given string. The lastIndexOf()     function on the other hand, returns the index of the last     occurrence of the string.      Finally, the replaceInStrings() function calls QString::replace()     on each string in the string list in turn. For example:      \snippet doc/src/snippets/qstringlist/main.cpp 8      \sa QString */
comment|/*!     \fn QStringList::QStringList()      Constructs an empty string list. */
comment|/*!     \fn QStringList::QStringList(const QString&str)      Constructs a string list that contains the given string, \a     str. Longer lists are easily created like this:      \snippet doc/src/snippets/qstringlist/main.cpp 9      \sa append() */
comment|/*!     \fn QStringList::QStringList(const QStringList&other)      Constructs a copy of the \a other string list.      This operation takes \l{constant time} because QStringList is     \l{implicitly shared}, making the process of returning a     QStringList from a function very fast. If a shared instance is     modified, it will be copied (copy-on-write), and that takes     \l{linear time}.      \sa operator=() */
comment|/*!     \fn QStringList::QStringList(const QList<QString>&other)      Constructs a copy of \a other.      This operation takes \l{constant time}, because QStringList is     \l{implicitly shared}. This makes returning a QStringList from a     function very fast. If a shared instance is modified, it will be     copied (copy-on-write), and that takes \l{linear time}.      \sa operator=() */
comment|/*!     \fn void QStringList::sort()      Sorts the list of strings in ascending order (case sensitively).      Sorting is performed using Qt's qSort() algorithm,     which operates in \l{linear-logarithmic time}, i.e. O(\e{n} log \e{n}).      If you want to sort your strings in an arbitrary order, consider     using the QMap class. For example, you could use a QMap<QString,     QString> to create a case-insensitive ordering (e.g. with the keys     being lower-case versions of the strings, and the values being the     strings), or a QMap<int, QString> to sort the strings by some     integer index.      \sa qSort() */
DECL|function|QStringList_sort
name|void
name|QtPrivate
operator|::
name|QStringList_sort
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|)
block|{
name|qSort
argument_list|(
operator|*
name|that
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QStringList QStringList::filter(const QString&str, Qt::CaseSensitivity cs) const      Returns a list of all the strings containing the substring \a str.      If \a cs is \l Qt::CaseSensitive (the default), the string     comparison is case sensitive; otherwise the comparison is case     insensitive.      \snippet doc/src/snippets/qstringlist/main.cpp 5     \snippet doc/src/snippets/qstringlist/main.cpp 10      This is equivalent to      \snippet doc/src/snippets/qstringlist/main.cpp 11     \snippet doc/src/snippets/qstringlist/main.cpp 12      \sa contains() */
end_comment
begin_function
DECL|function|QStringList_filter
name|QStringList
name|QtPrivate
operator|::
name|QStringList_filter
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
name|QStringMatcher
name|matcher
argument_list|(
name|str
argument_list|,
name|cs
argument_list|)
decl_stmt|;
name|QStringList
name|res
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
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|matcher
operator|.
name|indexIn
argument_list|(
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
operator|!=
operator|-
literal|1
condition|)
name|res
operator|<<
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QStringList::contains(const QString&str, Qt::CaseSensitivity cs) const      Returns true if the list contains the string \a str; otherwise     returns false. The search is case insensitive if \a cs is     Qt::CaseInsensitive; the search is case sensitive by default.      \sa indexOf(), lastIndexOf(), QString::contains()  */
end_comment
begin_function
DECL|function|QStringList_contains
name|bool
name|QtPrivate
operator|::
name|QStringList_contains
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|string
init|=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|string
operator|.
name|length
argument_list|()
operator|==
name|str
operator|.
name|length
argument_list|()
operator|&&
name|str
operator|.
name|compare
argument_list|(
name|string
argument_list|,
name|cs
argument_list|)
operator|==
literal|0
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_comment
comment|/*!     \fn QStringList QStringList::filter(const QRegExp&rx) const      \overload      Returns a list of all the strings that match the regular     expression \a rx. */
end_comment
begin_function
DECL|function|QStringList_filter
name|QStringList
name|QtPrivate
operator|::
name|QStringList_filter
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|)
block|{
name|QStringList
name|res
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
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|contains
argument_list|(
name|rx
argument_list|)
condition|)
name|res
operator|<<
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn QStringList&QStringList::replaceInStrings(const QString&before, const QString&after, Qt::CaseSensitivity cs)      Returns a string list where every string has had the \a before     text replaced with the \a after text wherever the \a before text     is found. The \a before text is matched case-sensitively or not     depending on the \a cs flag.      For example:      \snippet doc/src/snippets/qstringlist/main.cpp 5     \snippet doc/src/snippets/qstringlist/main.cpp 13      \sa QString::replace() */
end_comment
begin_function
DECL|function|QStringList_replaceInStrings
name|void
name|QtPrivate
operator|::
name|QStringList_replaceInStrings
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QString
modifier|&
name|before
parameter_list|,
specifier|const
name|QString
modifier|&
name|after
parameter_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
operator|(
operator|*
name|that
operator|)
index|[
name|i
index|]
operator|.
name|replace
argument_list|(
name|before
argument_list|,
name|after
argument_list|,
name|cs
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_comment
comment|/*!     \fn QStringList&QStringList::replaceInStrings(const QRegExp&rx, const QString&after)     \overload      Replaces every occurrence of the regexp \a rx, in each of the     string lists's strings, with \a after. Returns a reference to the     string list.      For example:      \snippet doc/src/snippets/qstringlist/main.cpp 5     \snippet doc/src/snippets/qstringlist/main.cpp 14      For regular expressions that contain \l{capturing parentheses},     occurrences of \bold{\\1}, \bold{\\2}, ..., in \a after are     replaced with \a{rx}.cap(1), \a{rx}.cap(2), ...      For example:      \snippet doc/src/snippets/qstringlist/main.cpp 5     \snippet doc/src/snippets/qstringlist/main.cpp 15 */
end_comment
begin_function
DECL|function|QStringList_replaceInStrings
name|void
name|QtPrivate
operator|::
name|QStringList_replaceInStrings
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
specifier|const
name|QString
modifier|&
name|after
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
operator|(
operator|*
name|that
operator|)
index|[
name|i
index|]
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
name|after
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn QString QStringList::join(const QString&separator) const      Joins all the string list's strings into a single string with each     element separated by the given \a separator (which can be an     empty string).      \sa QString::split() */
end_comment
begin_function
DECL|function|QStringList_join
name|QString
name|QtPrivate
operator|::
name|QStringList_join
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QString
modifier|&
name|sep
parameter_list|)
block|{
name|int
name|totalLength
init|=
literal|0
decl_stmt|;
specifier|const
name|int
name|size
init|=
name|that
operator|->
name|size
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
name|size
condition|;
operator|++
name|i
control|)
name|totalLength
operator|+=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
if|if
condition|(
name|size
operator|>
literal|0
condition|)
name|totalLength
operator|+=
name|sep
operator|.
name|size
argument_list|()
operator|*
operator|(
name|size
operator|-
literal|1
operator|)
expr_stmt|;
name|QString
name|res
decl_stmt|;
if|if
condition|(
name|totalLength
operator|==
literal|0
condition|)
return|return
name|res
return|;
name|res
operator|.
name|reserve
argument_list|(
name|totalLength
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
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
condition|)
name|res
operator|+=
name|sep
expr_stmt|;
name|res
operator|+=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QStringList QStringList::operator+(const QStringList&other) const      Returns a string list that is the concatenation of this string     list with the \a other string list.      \sa append() */
end_comment
begin_comment
comment|/*!     \fn QStringList&QStringList::operator<<(const QString&str)      Appends the given string, \a str, to this string list and returns     a reference to the string list.      \sa append() */
end_comment
begin_comment
comment|/*!     \fn QStringList&QStringList::operator<<(const QStringList&other)      \overload      Appends the \a other string list to the string list and returns a reference to     the latter string list. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&in, QStringList&list)     \relates QStringList      Reads a string list from the given \a in stream into the specified     \a list.      \sa {Serializing Qt Data Types} */
end_comment
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&out, const QStringList&list)     \relates QStringList      Writes the given string \a list to the specified \a out stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_function
DECL|function|indexOfMutating
specifier|static
name|int
name|indexOfMutating
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
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
name|that
operator|->
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|from
init|;
name|i
operator|<
name|that
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|rx
operator|.
name|exactMatch
argument_list|(
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|lastIndexOfMutating
specifier|static
name|int
name|lastIndexOfMutating
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
if|if
condition|(
name|from
operator|<
literal|0
condition|)
name|from
operator|+=
name|that
operator|->
name|size
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|from
operator|>=
name|that
operator|->
name|size
argument_list|()
condition|)
name|from
operator|=
name|that
operator|->
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|from
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|rx
operator|.
name|exactMatch
argument_list|(
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QStringList::indexOf(const QRegExp&rx, int from) const      Returns the index position of the first exact match of \a rx in     the list, searching forward from index position \a from. Returns     -1 if no item matched.      By default, this function is case sensitive.      \sa lastIndexOf(), contains(), QRegExp::exactMatch() */
end_comment
begin_function
DECL|function|QStringList_indexOf
name|int
name|QtPrivate
operator|::
name|QStringList_indexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
name|QRegExp
name|rx2
argument_list|(
name|rx
argument_list|)
decl_stmt|;
return|return
name|indexOfMutating
argument_list|(
name|that
argument_list|,
name|rx2
argument_list|,
name|from
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QStringList::indexOf(QRegExp&rx, int from) const     \overload indexOf()     \since 4.5      Returns the index position of the first exact match of \a rx in     the list, searching forward from index position \a from. Returns     -1 if no item matched.      By default, this function is case sensitive.      If an item matched, the \a rx regular expression will contain the     matched objects (see QRegExp::matchedLength, QRegExp::cap).      \sa lastIndexOf(), contains(), QRegExp::exactMatch() */
end_comment
begin_function
DECL|function|QStringList_indexOf
name|int
name|QtPrivate
operator|::
name|QStringList_indexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
return|return
name|indexOfMutating
argument_list|(
name|that
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QStringList::lastIndexOf(const QRegExp&rx, int from) const      Returns the index position of the last exact match of \a rx in     the list, searching backward from index position \a from. If \a     from is -1 (the default), the search starts at the last item.     Returns -1 if no item matched.      By default, this function is case sensitive.      \sa indexOf(), contains(), QRegExp::exactMatch() */
end_comment
begin_function
DECL|function|QStringList_lastIndexOf
name|int
name|QtPrivate
operator|::
name|QStringList_lastIndexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
specifier|const
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
name|QRegExp
name|rx2
argument_list|(
name|rx
argument_list|)
decl_stmt|;
return|return
name|lastIndexOfMutating
argument_list|(
name|that
argument_list|,
name|rx2
argument_list|,
name|from
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn int QStringList::lastIndexOf(QRegExp&rx, int from) const     \overload lastIndexOf()     \since 4.5      Returns the index position of the last exact match of \a rx in     the list, searching backward from index position \a from. If \a     from is -1 (the default), the search starts at the last item.     Returns -1 if no item matched.      By default, this function is case sensitive.      If an item matched, the \a rx regular expression will contain the     matched objects (see QRegExp::matchedLength, QRegExp::cap).      \sa indexOf(), contains(), QRegExp::exactMatch() */
end_comment
begin_function
DECL|function|QStringList_lastIndexOf
name|int
name|QtPrivate
operator|::
name|QStringList_lastIndexOf
parameter_list|(
specifier|const
name|QStringList
modifier|*
name|that
parameter_list|,
name|QRegExp
modifier|&
name|rx
parameter_list|,
name|int
name|from
parameter_list|)
block|{
return|return
name|lastIndexOfMutating
argument_list|(
name|that
argument_list|,
name|rx
argument_list|,
name|from
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn int QStringList::indexOf(const QString&value, int from = 0) const      Returns the index position of the first occurrence of \a value in     the list, searching forward from index position \a from. Returns     -1 if no item matched.      \sa lastIndexOf(), contains(), QList::indexOf() */
end_comment
begin_comment
comment|/*!     \fn int QStringList::lastIndexOf(const QString&value, int from = -1) const      Returns the index position of the last occurrence of \a value in     the list, searching backward from index position \a from. If \a     from is -1 (the default), the search starts at the last item.     Returns -1 if no item matched.      By default, this function is case sensitive.      \sa indexOf(), QList::lastIndexOf() */
end_comment
begin_comment
comment|/*!     \fn int QStringList::removeDuplicates()      \since  4.5      This function removes duplicate entries from a list.     The entries do not have to be sorted. They will retain their     original order.      Returns the number of removed entries. */
end_comment
begin_function
DECL|function|QStringList_removeDuplicates
name|int
name|QtPrivate
operator|::
name|QStringList_removeDuplicates
parameter_list|(
name|QStringList
modifier|*
name|that
parameter_list|)
block|{
name|int
name|n
init|=
name|that
operator|->
name|size
argument_list|()
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|seen
decl_stmt|;
name|seen
operator|.
name|reserve
argument_list|(
name|n
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
name|n
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|s
init|=
name|that
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|seen
operator|.
name|contains
argument_list|(
name|s
argument_list|)
condition|)
continue|continue;
name|seen
operator|.
name|insert
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|j
operator|!=
name|i
condition|)
operator|(
operator|*
name|that
operator|)
index|[
name|j
index|]
operator|=
name|s
expr_stmt|;
operator|++
name|j
expr_stmt|;
block|}
if|if
condition|(
name|n
operator|!=
name|j
condition|)
name|that
operator|->
name|erase
argument_list|(
name|that
operator|->
name|begin
argument_list|()
operator|+
name|j
argument_list|,
name|that
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|n
operator|-
name|j
return|;
block|}
end_function
begin_comment
comment|/*! \fn QStringList::QStringList(std::initializer_list<QString> args)     \since 4.8      Construct a list from a std::initializer_list given by \a args.      This constructor is only enabled if the compiler supports C++0x */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
