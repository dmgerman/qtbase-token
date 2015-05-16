begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QVector     \inmodule QtCore     \brief The QVector class is a template class that provides a dynamic array.      \ingroup tools     \ingroup shared      \reentrant      QVector\<T\> is one of Qt's generic \l{container classes}. It     stores its items in adjacent memory locations and provides fast     index-based access.      QList\<T\>, QLinkedList\<T\>, and QVarLengthArray\<T\> provide     similar functionality. Here's an overview:      \list     \li For most purposes, QList is the right class to use. Operations        like prepend() and insert() are usually faster than with        QVector because of the way QList stores its items in memory        (see \l{Algorithmic Complexity} for details),        and its index-based API is more convenient than QLinkedList's        iterator-based API. It also expands to less code in your        executable.     \li If you need a real linked list, with guarantees of \l{constant        time} insertions in the middle of the list and iterators to        items rather than indexes, use QLinkedList.     \li If you want the items to occupy adjacent memory positions, or        if your items are larger than a pointer and you want to avoid        the overhead of allocating them on the heap individually at        insertion time, then use QVector.     \li If you want a low-level variable-size array, QVarLengthArray        may be sufficient.     \endlist      Here's an example of a QVector that stores integers and a QVector     that stores QString values:      \snippet code/src_corelib_tools_qvector.cpp 0      QVector stores a vector (or array) of items. Typically, vectors     are created with an initial size. For example, the following code     constructs a QVector with 200 elements:      \snippet code/src_corelib_tools_qvector.cpp 1      The elements are automatically initialized with a     \l{default-constructed value}. If you want to initialize the     vector with a different value, pass that value as the second     argument to the constructor:      \snippet code/src_corelib_tools_qvector.cpp 2      You can also call fill() at any time to fill the vector with a     value.      QVector uses 0-based indexes, just like C++ arrays. To access the     item at a particular index position, you can use operator[](). On     non-const vectors, operator[]() returns a reference to the item     that can be used on the left side of an assignment:      \snippet code/src_corelib_tools_qvector.cpp 3      For read-only access, an alternative syntax is to use at():      \snippet code/src_corelib_tools_qvector.cpp 4      at() can be faster than operator[](), because it never causes a     \l{deep copy} to occur.      Another way to access the data stored in a QVector is to call     data(). The function returns a pointer to the first item in the     vector. You can use the pointer to directly access and modify the     elements stored in the vector. The pointer is also useful if you     need to pass a QVector to a function that accepts a plain C++     array.      If you want to find all occurrences of a particular value in a     vector, use indexOf() or lastIndexOf(). The former searches     forward starting from a given index position, the latter searches     backward. Both return the index of the matching item if they found     one; otherwise, they return -1. For example:      \snippet code/src_corelib_tools_qvector.cpp 5      If you simply want to check whether a vector contains a     particular value, use contains(). If you want to find out how     many times a particular value occurs in the vector, use count().      QVector provides these basic functions to add, move, and remove     items: insert(), replace(), remove(), prepend(), append(). With     the exception of append() and replace(), these functions can be slow     (\l{linear time}) for large vectors, because they require moving many     items in the vector by one position in memory. If you want a container     class that provides fast insertion/removal in the middle, use     QList or QLinkedList instead.      Unlike plain C++ arrays, QVectors can be resized at any time by     calling resize(). If the new size is larger than the old size,     QVector might need to reallocate the whole vector. QVector tries     to reduce the number of reallocations by preallocating up to twice     as much memory as the actual data needs.      If you know in advance approximately how many items the QVector     will contain, you can call reserve(), asking QVector to     preallocate a certain amount of memory. You can also call     capacity() to find out how much memory QVector actually     allocated.      Note that using non-const operators and functions can cause     QVector to do a deep copy of the data. This is due to \l{implicit sharing}.      QVector's value type must be an \l{assignable data type}. This     covers most data types that are commonly used, but the compiler     won't let you, for example, store a QWidget as a value; instead,     store a QWidget *. A few functions have additional requirements;     for example, indexOf() and lastIndexOf() expect the value type to     support \c operator==().  These requirements are documented on a     per-function basis.      Like the other container classes, QVector provides \l{Java-style     iterators} (QVectorIterator and QMutableVectorIterator) and     \l{STL-style iterators} (QVector::const_iterator and     QVector::iterator). In practice, these are rarely used, because     you can use indexes into the QVector.      In addition to QVector, Qt also provides QVarLengthArray, a very     low-level class with little functionality that is optimized for     speed.      QVector does \e not support inserting, prepending, appending or replacing     with references to its own values. Doing so will cause your application to     abort with an error message.      \sa QVectorIterator, QMutableVectorIterator, QList, QLinkedList */
end_comment
begin_comment
comment|/*!     \fn QVector<T> QVector::mid(int pos, int length = -1) const      Returns a sub-vector which contains elements from this vector,     starting at position \a pos. If \a length is -1 (the default), all     elements after \a pos are included; otherwise \a length elements (or     all remaining elements if there are less than \a length elements)     are included. */
end_comment
begin_comment
comment|/*! \fn QVector::QVector()      Constructs an empty vector.      \sa resize() */
end_comment
begin_comment
comment|/*!     \fn QVector::QVector(QVector<T>&&other)      Move-constructs a QVector instance, making it point at the same     object that \a other was pointing to.      \since 5.2 */
end_comment
begin_comment
comment|/*! \fn QVector::QVector(int size)      Constructs a vector with an initial size of \a size elements.      The elements are initialized with a \l{default-constructed     value}.      \sa resize() */
end_comment
begin_comment
comment|/*! \fn QVector::QVector(int size, const T&value)      Constructs a vector with an initial size of \a size elements.     Each element is initialized with \a value.      \sa resize(), fill() */
end_comment
begin_comment
comment|/*! \fn QVector::QVector(const QVector<T>&other)      Constructs a copy of \a other.      This operation takes \l{constant time}, because QVector is     \l{implicitly shared}. This makes returning a QVector from a     function very fast. If a shared instance is modified, it will be     copied (copy-on-write), and that takes \l{linear time}.      \sa operator=() */
end_comment
begin_comment
comment|/*! \fn QVector::QVector(std::initializer_list<T> args)     \since 4.8      Constructs a vector from the std::initializer_list given by \a args.      This constructor is only enabled if the compiler supports C++11 initializer     lists. */
end_comment
begin_comment
comment|/*! \fn QVector::~QVector()      Destroys the vector. */
end_comment
begin_comment
comment|/*! \fn QVector<T>&QVector::operator=(const QVector<T>&other)      Assigns \a other to this vector and returns a reference to this     vector. */
end_comment
begin_comment
comment|/*!     \fn QVector<T>&QVector::operator=(QVector<T>&&other)      Move-assigns \a other to this QVector instance.      \since 5.2 */
end_comment
begin_comment
comment|/*! \fn void QVector::swap(QVector<T>&other)     \since 4.8      Swaps vector \a other with this vector. This operation is very fast and     never fails. */
end_comment
begin_comment
comment|/*! \fn bool QVector::operator==(const QVector<T>&other) const      Returns \c true if \a other is equal to this vector; otherwise     returns \c false.      Two vectors are considered equal if they contain the same values     in the same order.      This function requires the value type to have an implementation     of \c operator==().      \sa operator!=() */
end_comment
begin_comment
comment|/*! \fn bool QVector::operator!=(const QVector<T>&other) const      Returns \c true if \a other is not equal to this vector; otherwise     returns \c false.      Two vectors are considered equal if they contain the same values     in the same order.      This function requires the value type to have an implementation     of \c operator==().      \sa operator==() */
end_comment
begin_comment
comment|/*! \fn bool operator<(const QVector<T>&lhs, const QVector<T>&rhs)     \since 5.6     \relates QVector      Returns \c true if vector \a lhs is     \l{http://en.cppreference.com/w/cpp/algorithm/lexicographical_compare}     {lexicographically less than} \a rhs; otherwise returns \c false.      This function requires the value type to have an implementation     of \c operator<(). */
end_comment
begin_comment
comment|/*! \fn bool operator<=(const QVector<T>&lhs, const QVector<T>&rhs)     \since 5.6     \relates QVector      Returns \c true if vector \a lhs is     \l{http://en.cppreference.com/w/cpp/algorithm/lexicographical_compare}     {lexicographically less than or equal to} \a rhs; otherwise returns \c false.      This function requires the value type to have an implementation     of \c operator<(). */
end_comment
begin_comment
comment|/*! \fn bool operator>(const QVector<T>&lhs, const QVector<T>&rhs)     \since 5.6     \relates QVector      Returns \c true if vector \a lhs is     \l{http://en.cppreference.com/w/cpp/algorithm/lexicographical_compare}     {lexicographically greater than} \a rhs; otherwise returns \c false.      This function requires the value type to have an implementation     of \c operator<(). */
end_comment
begin_comment
comment|/*! \fn bool operator>=(const QVector<T>&lhs, const QVector<T>&rhs)     \since 5.6     \relates QVector      Returns \c true if vector \a lhs is     \l{http://en.cppreference.com/w/cpp/algorithm/lexicographical_compare}     {lexicographically greater than or equal to} \a rhs; otherwise returns \c false.      This function requires the value type to have an implementation     of \c operator<(). */
end_comment
begin_comment
comment|/*!     \fn uint qHash(const QVector<T>&key, uint seed = 0)     \since 5.6     \relates QVector      Returns the hash value for \a key,     using \a seed to seed the calculation.      This function requires qHash() to be overloaded for the value type \c T. */
end_comment
begin_comment
comment|/*! \fn int QVector::size() const      Returns the number of items in the vector.      \sa isEmpty(), resize() */
end_comment
begin_comment
comment|/*! \fn bool QVector::isEmpty() const      Returns \c true if the vector has size 0; otherwise returns \c false.      \sa size(), resize() */
end_comment
begin_comment
comment|/*! \fn void QVector::resize(int size)      Sets the size of the vector to \a size. If \a size is greater than the     current size, elements are added to the end; the new elements are     initialized with a \l{default-constructed value}. If \a size is less     than the current size, elements are removed from the end.      \sa size() */
end_comment
begin_comment
comment|/*! \fn int QVector::capacity() const      Returns the maximum number of items that can be stored in the     vector without forcing a reallocation.      The sole purpose of this function is to provide a means of fine     tuning QVector's memory usage. In general, you will rarely ever     need to call this function. If you want to know how many items are     in the vector, call size().      \sa reserve(), squeeze() */
end_comment
begin_comment
comment|/*! \fn void QVector::reserve(int size)      Attempts to allocate memory for at least \a size elements. If you     know in advance how large the vector will be, you can call this     function, and if you call resize() often you are likely to get     better performance. If \a size is an underestimate, the worst     that will happen is that the QVector will be a bit slower.      The sole purpose of this function is to provide a means of fine     tuning QVector's memory usage. In general, you will rarely ever     need to call this function. If you want to change the size of the     vector, call resize().      \sa squeeze(), capacity() */
end_comment
begin_comment
comment|/*! \fn void QVector::squeeze()      Releases any memory not required to store the items.      The sole purpose of this function is to provide a means of fine     tuning QVector's memory usage. In general, you will rarely ever     need to call this function.      \sa reserve(), capacity() */
end_comment
begin_comment
comment|/*! \fn void QVector::detach()      \internal */
end_comment
begin_comment
comment|/*! \fn bool QVector::isDetached() const      \internal */
end_comment
begin_comment
comment|/*! \fn void QVector::setSharable(bool sharable)      \internal */
end_comment
begin_comment
comment|/*! \fn bool QVector::isSharedWith(const QVector<T>&other) const      \internal */
end_comment
begin_comment
comment|/*! \fn T *QVector::data()      Returns a pointer to the data stored in the vector. The pointer     can be used to access and modify the items in the vector.      Example:     \snippet code/src_corelib_tools_qvector.cpp 6      The pointer remains valid as long as the vector isn't     reallocated.      This function is mostly useful to pass a vector to a function     that accepts a plain C++ array.      \sa constData(), operator[]() */
end_comment
begin_comment
comment|/*! \fn const T *QVector::data() const      \overload */
end_comment
begin_comment
comment|/*! \fn const T *QVector::constData() const      Returns a const pointer to the data stored in the vector. The     pointer can be used to access the items in the vector.     The pointer remains valid as long as the vector isn't     reallocated.      This function is mostly useful to pass a vector to a function     that accepts a plain C++ array.      \sa data(), operator[]() */
end_comment
begin_comment
comment|/*! \fn void QVector::clear()      Removes all the elements from the vector and releases the memory used by     the vector. */
end_comment
begin_comment
comment|/*! \fn const T&QVector::at(int i) const      Returns the item at index position \a i in the vector.      \a i must be a valid index position in the vector (i.e., 0<= \a     i< size()).      \sa value(), operator[]() */
end_comment
begin_comment
comment|/*! \fn T&QVector::operator[](int i)      Returns the item at index position \a i as a modifiable reference.      \a i must be a valid index position in the vector (i.e., 0<= \a i< size()).      Note that using non-const operators can cause QVector to do a deep     copy.      \sa at(), value() */
end_comment
begin_comment
comment|/*! \fn const T&QVector::operator[](int i) const      \overload      Same as at(\a i). */
end_comment
begin_comment
comment|/*!     \fn void QVector::append(const T&value)      Inserts \a value at the end of the vector.      Example:     \snippet code/src_corelib_tools_qvector.cpp 7      This is the same as calling resize(size() + 1) and assigning \a     value to the new last element in the vector.      This operation is relatively fast, because QVector typically     allocates more memory than necessary, so it can grow without     reallocating the entire vector each time.      \sa operator<<(), prepend(), insert() */
end_comment
begin_comment
comment|/*! \fn void QVector::append(const QVector<T>&value)      \overload      \since 5.5      Appends the items of the \a value vector to this vector.      \sa operator<<(), operator+=() */
end_comment
begin_comment
comment|/*! \fn void QVector::prepend(const T&value)      Inserts \a value at the beginning of the vector.      Example:     \snippet code/src_corelib_tools_qvector.cpp 8      This is the same as vector.insert(0, \a value).      For large vectors, this operation can be slow (\l{linear time}),     because it requires moving all the items in the vector by one     position further in memory. If you want a container class that     provides a fast prepend() function, use QList or QLinkedList     instead.      \sa append(), insert() */
end_comment
begin_comment
comment|/*! \fn void QVector::insert(int i, const T&value)      Inserts \a value at index position \a i in the vector. If \a i is     0, the value is prepended to the vector. If \a i is size(), the     value is appended to the vector.      Example:     \snippet code/src_corelib_tools_qvector.cpp 9      For large vectors, this operation can be slow (\l{linear time}),     because it requires moving all the items at indexes \a i and     above by one position further in memory. If you want a container     class that provides a fast insert() function, use QLinkedList     instead.      \sa append(), prepend(), remove() */
end_comment
begin_comment
comment|/*! \fn void QVector::insert(int i, int count, const T&value)      \overload      Inserts \a count copies of \a value at index position \a i in the     vector.      Example:     \snippet code/src_corelib_tools_qvector.cpp 10 */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::insert(iterator before, const T&value)      \overload      Inserts \a value in front of the item pointed to by the iterator     \a before. Returns an iterator pointing at the inserted item. */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::insert(iterator before, int count, const T&value)      Inserts \a count copies of \a value in front of the item pointed to     by the iterator \a before. Returns an iterator pointing at the     first of the inserted items. */
end_comment
begin_comment
comment|/*! \fn void QVector::replace(int i, const T&value)      Replaces the item at index position \a i with \a value.      \a i must be a valid index position in the vector (i.e., 0<= \a     i< size()).      \sa operator[](), remove() */
end_comment
begin_comment
comment|/*! \fn void QVector::remove(int i)      \overload      Removes the element at index position \a i.      \sa insert(), replace(), fill() */
end_comment
begin_comment
comment|/*! \fn void QVector::remove(int i, int count)      \overload      Removes \a count elements from the middle of the vector, starting at     index position \a i.      \sa insert(), replace(), fill() */
end_comment
begin_comment
comment|/*! \fn void QVector::removeAt(int i)     \since 5.2      Removes the element at index position \a i.     Equivalent to     \code     remove(i);     \endcode      Provided for compatibility with QList.      \sa remove(), QList::removeAt() */
end_comment
begin_comment
comment|/*! \fn int QVector::removeAll(const T&t)     \since 5.4      Removes all elements that compare equal to \a t from the     vector. Returns the number of elements removed, if any.      Provided for compatibility with QList.      \sa removeOne(), QList::removeAll() */
end_comment
begin_comment
comment|/*! \fn bool QVector::removeOne(const T&t)     \since 5.4      Removes the first element that compares equal to \a t from the     vector. Returns whether an element was, in fact, removed.      Provided for compatibility with QList.      \sa removeAll(), QList::removeOne() */
end_comment
begin_comment
comment|/*! \fn int QVector::length() const     \since 5.2      Same as size() and count().      Provided for compatibility with QList.      \sa size(), count(), QList::length() */
end_comment
begin_comment
comment|/*! \fn T QVector::takeAt(int i)     \since 5.2      Removes the element at index position \a i and returns it.      Equivalent to     \code     T t = at(i);     remove(i);     return t;     \endcode      Provided for compatibility with QList.      \sa takeFirst(), takeLast(), QList::takeAt() */
end_comment
begin_comment
comment|/*! \fn void QVector::removeFirst()     \since 5.1     Removes the first item in the vector. Calling this function is     equivalent to calling remove(0). The vector must not be empty. If     the vector can be empty, call isEmpty() before calling this     function.      \sa remove(), takeFirst(), isEmpty() */
end_comment
begin_comment
comment|/*! \fn void QVector::removeLast()     \since 5.1     Removes the last item in the vector. Calling this function is     equivalent to calling remove(size() - 1). The vector must not be     empty. If the vector can be empty, call isEmpty() before calling     this function.      \sa remove(), takeLast(), removeFirst(), isEmpty() */
end_comment
begin_comment
comment|/*! \fn T QVector::takeFirst()     \since 5.1      Removes the first item in the vector and returns it. This function     assumes the vector is not empty. To avoid failure, call isEmpty()     before calling this function.      \sa takeLast(), removeFirst() */
end_comment
begin_comment
comment|/*! \fn T QVector::takeLast()     \since 5.1      Removes the last item in the list and returns it. This function     assumes the vector is not empty. To avoid failure, call isEmpty()     before calling this function.      If you don't use the return value, removeLast() is more     efficient.      \sa takeFirst(), removeLast() */
end_comment
begin_comment
comment|/*! \fn QVector&QVector::fill(const T&value, int size = -1)      Assigns \a value to all items in the vector. If \a size is     different from -1 (the default), the vector is resized to size \a     size beforehand.      Example:     \snippet code/src_corelib_tools_qvector.cpp 11      \sa resize() */
end_comment
begin_comment
comment|/*! \fn int QVector::indexOf(const T&value, int from = 0) const      Returns the index position of the first occurrence of \a value in     the vector, searching forward from index position \a from.     Returns -1 if no item matched.      Example:     \snippet code/src_corelib_tools_qvector.cpp 12      This function requires the value type to have an implementation of     \c operator==().      \sa lastIndexOf(), contains() */
end_comment
begin_comment
comment|/*! \fn int QVector::lastIndexOf(const T&value, int from = -1) const      Returns the index position of the last occurrence of the value \a     value in the vector, searching backward from index position \a     from. If \a from is -1 (the default), the search starts at the     last item. Returns -1 if no item matched.      Example:     \snippet code/src_corelib_tools_qvector.cpp 13      This function requires the value type to have an implementation of     \c operator==().      \sa indexOf() */
end_comment
begin_comment
comment|/*! \fn bool QVector::contains(const T&value) const      Returns \c true if the vector contains an occurrence of \a value;     otherwise returns \c false.      This function requires the value type to have an implementation of     \c operator==().      \sa indexOf(), count() */
end_comment
begin_comment
comment|/*! \fn bool QVector::startsWith(const T&value) const     \since 4.5      Returns \c true if this vector is not empty and its first     item is equal to \a value; otherwise returns \c false.      \sa isEmpty(), first() */
end_comment
begin_comment
comment|/*! \fn bool QVector::endsWith(const T&value) const     \since 4.5      Returns \c true if this vector is not empty and its last     item is equal to \a value; otherwise returns \c false.      \sa isEmpty(), last() */
end_comment
begin_comment
comment|/*! \fn int QVector::count(const T&value) const      Returns the number of occurrences of \a value in the vector.      This function requires the value type to have an implementation of     \c operator==().      \sa contains(), indexOf() */
end_comment
begin_comment
comment|/*! \fn int QVector::count() const      \overload      Same as size(). */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::begin()      Returns an \l{STL-style iterators}{STL-style iterator} pointing to the first item in     the vector.      \sa constBegin(), end() */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::begin() const      \overload */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::cbegin() const     \since 5.0      Returns a const \l{STL-style iterators}{STL-style iterator} pointing to the first item     in the vector.      \sa begin(), cend() */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::constBegin() const      Returns a const \l{STL-style iterators}{STL-style iterator} pointing to the first item     in the vector.      \sa begin(), constEnd() */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::end()      Returns an \l{STL-style iterators}{STL-style iterator} pointing to the imaginary item     after the last item in the vector.      \sa begin(), constEnd() */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::end() const      \overload */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::cend() const     \since 5.0      Returns a const \l{STL-style iterators}{STL-style iterator} pointing to the imaginary     item after the last item in the vector.      \sa cbegin(), end() */
end_comment
begin_comment
comment|/*! \fn QVector::const_iterator QVector::constEnd() const      Returns a const \l{STL-style iterators}{STL-style iterator} pointing to the imaginary     item after the last item in the vector.      \sa constBegin(), end() */
end_comment
begin_comment
comment|/*! \fn QVector::reverse_iterator QVector::rbegin()     \since 5.6      Returns a \l{STL-style iterators}{STL-style} reverse iterator pointing to the first     item in the vector, in reverse order.      \sa begin(), crbegin(), rend() */
end_comment
begin_comment
comment|/*! \fn QVector::const_reverse_iterator QVector::rbegin() const     \since 5.6     \overload */
end_comment
begin_comment
comment|/*! \fn QVector::const_reverse_iterator QVector::crbegin() const     \since 5.6      Returns a const \l{STL-style iterators}{STL-style} reverse iterator pointing to the first     item in the vector, in reverse order.      \sa begin(), rbegin(), rend() */
end_comment
begin_comment
comment|/*! \fn QVector::reverse_iterator QVector::rend()     \since 5.6      Returns a \l{STL-style iterators}{STL-style} reverse iterator pointing to one past     the last item in the vector, in reverse order.      \sa end(), crend(), rbegin() */
end_comment
begin_comment
comment|/*! \fn QVector::const_reverse_iterator QVector::rend() const     \since 5.6     \overload */
end_comment
begin_comment
comment|/*! \fn QVector::const_reverse_iterator QVector::crend() const     \since 5.6      Returns a const \l{STL-style iterators}{STL-style} reverse iterator pointing to one     past the last item in the vector, in reverse order.      \sa end(), rend(), rbegin() */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::erase(iterator pos)      Removes the item pointed to by the iterator \a pos from the     vector, and returns an iterator to the next item in the vector     (which may be end()).      \sa insert(), remove() */
end_comment
begin_comment
comment|/*! \fn QVector::iterator QVector::erase(iterator begin, iterator end)      \overload      Removes all the items from \a begin up to (but not including) \a     end. Returns an iterator to the same item that \a end referred to     before the call. */
end_comment
begin_comment
comment|/*! \fn T& QVector::first()      Returns a reference to the first item in the vector. This     function assumes that the vector isn't empty.      \sa last(), isEmpty(), constFirst() */
end_comment
begin_comment
comment|/*! \fn const T& QVector::first() const      \overload */
end_comment
begin_comment
comment|/*! \fn const T& QVector::constFirst() const     \since 5.6      Returns a const reference to the first item in the vector. This     function assumes that the vector isn't empty.      \sa constLast(), isEmpty(), first() */
end_comment
begin_comment
comment|/*! \fn T& QVector::last()      Returns a reference to the last item in the vector. This function     assumes that the vector isn't empty.      \sa first(), isEmpty(), constLast() */
end_comment
begin_comment
comment|/*! \fn const T& QVector::last() const      \overload */
end_comment
begin_comment
comment|/*! \fn const T& QVector::constLast() const     \since 5.6      Returns a const reference to the last item in the vector. This function     assumes that the vector isn't empty.      \sa constFirst(), isEmpty(), last() */
end_comment
begin_comment
comment|/*! \fn T QVector::value(int i) const      Returns the value at index position \a i in the vector.      If the index \a i is out of bounds, the function returns     a \l{default-constructed value}. If you are certain that     \a i is within bounds, you can use at() instead, which is slightly     faster.      \sa at(), operator[]() */
end_comment
begin_comment
comment|/*! \fn T QVector::value(int i, const T&defaultValue) const      \overload      If the index \a i is out of bounds, the function returns     \a defaultValue. */
end_comment
begin_comment
comment|/*! \fn void QVector::push_back(const T&value)      This function is provided for STL compatibility. It is equivalent     to append(\a value). */
end_comment
begin_comment
comment|/*! \fn void QVector::push_front(const T&value)      This function is provided for STL compatibility. It is equivalent     to prepend(\a value). */
end_comment
begin_comment
comment|/*! \fn void QVector::pop_front()      This function is provided for STL compatibility. It is equivalent     to removeFirst(). */
end_comment
begin_comment
comment|/*! \fn void QVector::pop_back()      This function is provided for STL compatibility. It is equivalent     to removeLast(). */
end_comment
begin_comment
comment|/*! \fn T& QVector::front()      This function is provided for STL compatibility. It is equivalent     to first(). */
end_comment
begin_comment
comment|/*! \fn QVector::const_reference QVector::front() const      \overload */
end_comment
begin_comment
comment|/*! \fn QVector::reference QVector::back()      This function is provided for STL compatibility. It is equivalent     to last(). */
end_comment
begin_comment
comment|/*! \fn QVector::const_reference QVector::back() const      \overload */
end_comment
begin_comment
comment|/*! \fn bool QVector::empty() const      This function is provided for STL compatibility. It is equivalent     to isEmpty(), returning \c true if the vector is empty; otherwise     returns \c false. */
end_comment
begin_comment
comment|/*! \fn QVector<T>&QVector::operator+=(const QVector<T>&other)      Appends the items of the \a other vector to this vector and     returns a reference to this vector.      \sa operator+(), append() */
end_comment
begin_comment
comment|/*! \fn void QVector::operator+=(const T&value)      \overload      Appends \a value to the vector.      \sa append(), operator<<() */
end_comment
begin_comment
comment|/*! \fn QVector<T> QVector::operator+(const QVector<T>&other) const      Returns a vector that contains all the items in this vector     followed by all the items in the \a other vector.      \sa operator+=() */
end_comment
begin_comment
comment|/*! \fn QVector<T>&QVector::operator<<(const T&value)      Appends \a value to the vector and returns a reference to this     vector.      \sa append(), operator+=() */
end_comment
begin_comment
comment|/*! \fn QVector<T>&QVector::operator<<(const QVector<T>&other)      Appends \a other to the vector and returns a reference to the     vector. */
end_comment
begin_comment
comment|/*! \typedef QVector::iterator      The QVector::iterator typedef provides an STL-style non-const     iterator for QVector and QStack.      QVector provides both \l{STL-style iterators} and \l{Java-style     iterators}. The STL-style non-const iterator is simply a typedef     for "T *" (pointer to T).      \warning Iterators on implicitly shared containers do not work     exactly like STL-iterators. You should avoid copying a container     while iterators are active on that container. For more information,     read \l{Implicit sharing iterator problem}.      \sa QVector::begin(), QVector::end(), QVector::const_iterator, QMutableVectorIterator */
end_comment
begin_comment
comment|/*! \typedef QVector::const_iterator      The QVector::const_iterator typedef provides an STL-style const     iterator for QVector and QStack.      QVector provides both \l{STL-style iterators} and \l{Java-style     iterators}. The STL-style const iterator is simply a typedef for     "const T *" (pointer to const T).      \warning Iterators on implicitly shared containers do not work     exactly like STL-iterators. You should avoid copying a container     while iterators are active on that container. For more information,     read \l{Implicit sharing iterator problem}.      \sa QVector::constBegin(), QVector::constEnd(), QVector::iterator, QVectorIterator */
end_comment
begin_comment
comment|/*! \typedef QVector::reverse_iterator     \since 5.6      The QVector::reverse_iterator typedef provides an STL-style non-const     reverse iterator for QVector.      It is simply a typedef for \c{std::reverse_iterator<T*>}.      \warning Iterators on implicitly shared containers do not work     exactly like STL-iterators. You should avoid copying a container     while iterators are active on that container. For more information,     read \l{Implicit sharing iterator problem}.      \sa QVector::rbegin(), QVector::rend(), QVector::const_reverse_iterator, QVector::iterator */
end_comment
begin_comment
comment|/*! \typedef QVector::const_reverse_iterator     \since 5.6      The QVector::const_reverse_iterator typedef provides an STL-style const     reverse iterator for QVector.      It is simply a typedef for \c{std::reverse_iterator<const T*>}.      \warning Iterators on implicitly shared containers do not work     exactly like STL-iterators. You should avoid copying a container     while iterators are active on that container. For more information,     read \l{Implicit sharing iterator problem}.      \sa QVector::rbegin(), QVector::rend(), QVector::reverse_iterator, QVector::const_iterator */
end_comment
begin_comment
comment|/*! \typedef QVector::Iterator      Qt-style synonym for QVector::iterator. */
end_comment
begin_comment
comment|/*! \typedef QVector::ConstIterator      Qt-style synonym for QVector::const_iterator. */
end_comment
begin_comment
comment|/*! \typedef QVector::const_pointer      Typedef for const T *. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::const_reference      Typedef for T&. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::difference_type      Typedef for ptrdiff_t. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::pointer      Typedef for T *. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::reference      Typedef for T&. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::size_type      Typedef for int. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \typedef QVector::value_type      Typedef for T. Provided for STL compatibility. */
end_comment
begin_comment
comment|/*! \fn QList<T> QVector<T>::toList() const      Returns a QList object with the data contained in this QVector.      Example:      \snippet code/src_corelib_tools_qvector.cpp 14      \sa fromList(), QList::fromVector() */
end_comment
begin_comment
comment|/*! \fn QVector<T> QVector<T>::fromList(const QList<T>&list)      Returns a QVector object with the data contained in \a list.      Example:      \snippet code/src_corelib_tools_qvector.cpp 15      \sa toList(), QList::toVector() */
end_comment
begin_comment
comment|/*! \fn QVector<T> QVector<T>::fromStdVector(const std::vector<T>&vector)      Returns a QVector object with the data contained in \a vector. The     order of the elements in the QVector is the same as in \a vector.      Example:      \snippet code/src_corelib_tools_qvector.cpp 16      \sa toStdVector(), QList::fromStdList() */
end_comment
begin_comment
comment|/*! \fn std::vector<T> QVector<T>::toStdVector() const      Returns a std::vector object with the data contained in this QVector.     Example:      \snippet code/src_corelib_tools_qvector.cpp 17      \sa fromStdVector(), QList::toStdList() */
end_comment
begin_comment
comment|/*! \fn QDataStream&operator<<(QDataStream&out, const QVector<T>&vector)     \relates QVector      Writes the vector \a vector to stream \a out.      This function requires the value type to implement \c operator<<().      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_comment
comment|/*! \fn QDataStream&operator>>(QDataStream&in, QVector<T>&vector)     \relates QVector      Reads a vector from stream \a in into \a vector.      This function requires the value type to implement \c operator>>().      \sa{Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
end_unit
