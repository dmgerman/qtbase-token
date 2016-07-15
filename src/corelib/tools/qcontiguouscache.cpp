begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcontiguouscache.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QCONTIGUOUSCACHE_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_QCONTIGUOUSCACHE_DEBUG
DECL|function|dump
name|void
name|QContiguousCacheData
operator|::
name|dump
parameter_list|()
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
literal|"capacity:"
operator|<<
name|alloc
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"count:"
operator|<<
name|count
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"start:"
operator|<<
name|start
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"offset:"
operator|<<
name|offset
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|allocate
name|QContiguousCacheData
modifier|*
name|QContiguousCacheData
operator|::
name|allocate
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|alignment
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QContiguousCacheData
operator|*
argument_list|>
argument_list|(
name|qMallocAligned
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|free
name|void
name|QContiguousCacheData
operator|::
name|free
parameter_list|(
name|QContiguousCacheData
modifier|*
name|data
parameter_list|)
block|{
name|qFreeAligned
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \class QContiguousCache     \brief The QContiguousCache class is a template class that provides a contiguous cache.     \ingroup tools     \ingroup shared     \reentrant     \since 4.6      The QContiguousCache class provides an efficient way of caching items for     display in a user interface view.  Unlike QCache, it adds a restriction     that elements within the cache are contiguous.  This has the advantage     of matching how user interface views most commonly request data, as     a set of rows localized around the current scrolled position.  This     restriction allows the cache to consume less memory and processor     cycles than QCache.  The QContiguousCache class also can provide     an upper bound on memory usage via setCapacity().      The simplest way of using a contiguous cache is to use the append()     and prepend().  \code MyRecord record(int row) const {     Q_ASSERT(row>= 0&& row< count());      while(row> cache.lastIndex())         cache.append(slowFetchRecord(cache.lastIndex()+1));     while(row< cache.firstIndex())         cache.prepend(slowFetchRecord(cache.firstIndex()-1));      return cache.at(row); } \endcode      If the cache is full then the item at the opposite end of the cache from     where the new item is appended or prepended will be removed.      This usage can be further optimized by using the insert() function     in the case where the requested row is a long way from the currently cached     items. If there is a gap between where the new item is inserted and the currently     cached items then the existing cached items are first removed to retain     the contiguous nature of the cache. Hence it is important to take some care then     when using insert() in order to avoid unwanted clearing of the cache.      The range of valid indexes for the QContiguousCache class are from     0 to INT_MAX.  Calling prepend() such that the first index would become less     than 0 or append() such that the last index would become greater     than INT_MAX can result in the indexes of the cache being invalid.     When the cache indexes are invalid it is important to call     normalizeIndexes() before calling any of containsIndex(), firstIndex(),     lastIndex(), at() or \l{QContiguousCache::operator[]()}{operator[]()}.     Calling these functions when the cache has invalid indexes will result in     undefined behavior. The indexes can be checked by using areIndexesValid()      In most cases the indexes will not exceed 0 to INT_MAX, and     normalizeIndexes() will not need to be used.      See the \l{Contiguous Cache Example}{Contiguous Cache} example. */
end_comment
begin_comment
comment|/*! \fn QContiguousCache::QContiguousCache(int capacity)      Constructs a cache with the given \a capacity.      \sa setCapacity() */
end_comment
begin_comment
comment|/*! \fn QContiguousCache::QContiguousCache(const QContiguousCache<T>&other)      Constructs a copy of \a other.      This operation takes \l{constant time}, because QContiguousCache is     \l{implicitly shared}.  This makes returning a QContiguousCache from a     function very fast.  If a shared instance is modified, it will be     copied (copy-on-write), and that takes \l{linear time}.      \sa operator=() */
end_comment
begin_comment
comment|/*! \fn QContiguousCache::~QContiguousCache()      Destroys the cache. */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::detach()     \internal */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::isDetached() const     \internal */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::setSharable(bool sharable)     \internal */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::value_type   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::pointer   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::const_pointer   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::reference   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::const_reference   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::difference_type   \internal  */
end_comment
begin_comment
comment|/*! \typedef QContiguousCache::size_type   \internal  */
end_comment
begin_comment
comment|/*! \fn QContiguousCache<T>&QContiguousCache::operator=(const QContiguousCache<T>&other)      Assigns \a other to this cache and returns a reference to this cache. */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::swap(QContiguousCache<T>&other)     \since 4.8      Swaps cache \a other with this cache. This operation is very     fast and never fails. */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::operator==(const QContiguousCache<T>&other) const      Returns true if \a other is equal to this cache; otherwise returns false.      Two caches are considered equal if they contain the same values at the same     indexes.  This function requires the value type to implement the \c operator==().      \sa operator!=() */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::operator!=(const QContiguousCache<T>&other) const      Returns true if \a other is not equal to this cache; otherwise     returns false.      Two caches are considered equal if they contain the same values at the same     indexes.  This function requires the value type to implement the \c operator==().      \sa operator==() */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::capacity() const      Returns the number of items the cache can store before it is full.     When a cache contains a number of items equal to its capacity, adding new     items will cause items farthest from the added item to be removed.      \sa setCapacity(), size() */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::count() const      Same as size(). */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::size() const      Returns the number of items contained within the cache.      \sa capacity() */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::isEmpty() const      Returns true if no items are stored within the cache.      \sa size(), capacity() */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::isFull() const      Returns true if the number of items stored within the cache is equal     to the capacity of the cache.      \sa size(), capacity() */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::available() const      Returns the number of items that can be added to the cache before it becomes full.      \sa size(), capacity(), isFull() */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::clear()      Removes all items from the cache.  The capacity is unchanged. */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::setCapacity(int size)      Sets the capacity of the cache to the given \a size.  A cache can hold a     number of items equal to its capacity.  When inserting, appending or prepending     items to the cache, if the cache is already full then the item farthest from     the added item will be removed.      If the given \a size is smaller than the current count of items in the cache     then only the last \a size items from the cache will remain.      \sa capacity(), isFull() */
end_comment
begin_comment
comment|/*! \fn const T&QContiguousCache::at(int i) const      Returns the item at index position \a i in the cache.  \a i must     be a valid index position in the cache (i.e, firstIndex()<= \a i<= lastIndex()).      The indexes in the cache refer to the number of positions the item is from the     first item appended into the cache.  That is to say a cache with a capacity of     100, that has had 150 items appended will have a valid index range of     50 to 149.  This allows inserting and retrieving items into the cache based     on a theoretical infinite list      \sa firstIndex(), lastIndex(), insert(), operator[]() */
end_comment
begin_comment
comment|/*! \fn T&QContiguousCache::operator[](int i)      Returns the item at index position \a i as a modifiable reference. If     the cache does not contain an item at the given index position \a i     then it will first insert an empty item at that position.      In most cases it is better to use either at() or insert().      \note This non-const overload of operator[] requires QContiguousCache      to make a deep copy. Use at() for read-only access to a non-const      QContiguousCache.      \sa insert(), at() */
end_comment
begin_comment
comment|/*! \fn const T&QContiguousCache::operator[](int i) const      \overload      Same as at(\a i). */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::append(const T&value)      Inserts \a value at the end of the cache.  If the cache is already full     the item at the start of the cache will be removed.      \sa prepend(), insert(), isFull() */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::prepend(const T&value)      Inserts \a value at the start of the cache.  If the cache is already full     the item at the end of the cache will be removed.      \sa append(), insert(), isFull() */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::insert(int i, const T&value)      Inserts the \a value at the index position \a i.  If the cache already contains     an item at \a i then that value is replaced.  If \a i is either one more than     lastIndex() or one less than firstIndex() it is the equivalent to an append()     or a prepend().      If the given index \a i is not within the current range of the cache nor adjacent     to the bounds of the cache's index range, the cache is first cleared before     inserting the item.  At this point the cache will have a size of 1.  It is     worthwhile taking effort to insert items in an order that starts adjacent     to the current index range for the cache.      The range of valid indexes for the QContiguousCache class are from     0 to INT_MAX. Inserting outside of this range has undefined behavior.       \sa prepend(), append(), isFull(), firstIndex(), lastIndex() */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::containsIndex(int i) const      Returns true if the cache's index range includes the given index \a i.      \sa firstIndex(), lastIndex() */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::firstIndex() const      Returns the first valid index in the cache.  The index will be invalid if the     cache is empty.      \sa capacity(), size(), lastIndex() */
end_comment
begin_comment
comment|/*! \fn int QContiguousCache::lastIndex() const      Returns the last valid index in the cache.  The index will be invalid if the cache is empty.      \sa capacity(), size(), firstIndex() */
end_comment
begin_comment
comment|/*! \fn T&QContiguousCache::first()      Returns a reference to the first item in the cache.  This function     assumes that the cache isn't empty.      \sa last(), isEmpty() */
end_comment
begin_comment
comment|/*! \fn T&QContiguousCache::last()      Returns a reference to the last item in the cache.  This function     assumes that the cache isn't empty.      \sa first(), isEmpty() */
end_comment
begin_comment
comment|/*! \fn const T& QContiguousCache::first() const      \overload */
end_comment
begin_comment
comment|/*! \fn const T& QContiguousCache::last() const      \overload */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::removeFirst()      Removes the first item from the cache.  This function assumes that     the cache isn't empty.      \sa removeLast() */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::removeLast()      Removes the last item from the cache.  This function assumes that     the cache isn't empty.      \sa removeFirst() */
end_comment
begin_comment
comment|/*! \fn T QContiguousCache::takeFirst()      Removes the first item in the cache and returns it.  This function     assumes that the cache isn't empty.      If you don't use the return value, removeFirst() is more efficient.      \sa takeLast(), removeFirst() */
end_comment
begin_comment
comment|/*! \fn T QContiguousCache::takeLast()      Removes the last item in the cache and returns it. This function     assumes that the cache isn't empty.      If you don't use the return value, removeLast() is more efficient.      \sa takeFirst(), removeLast() */
end_comment
begin_comment
comment|/*! \fn void QContiguousCache::normalizeIndexes()      Moves the first index and last index of the cache     such that they point to valid indexes.  The function does not modify     the contents of the cache or the ordering of elements within the cache.      It is provided so that index overflows can be corrected when using the     cache as a circular buffer.      \code     QContiguousCache<int> cache(10);     cache.insert(INT_MAX, 1); // cache contains one value and has valid indexes, INT_MAX to INT_MAX     cache.append(2); // cache contains two values but does not have valid indexes.     cache.normalizeIndexes(); // cache has two values, 1 and 2.  New first index will be in the range of 0 to capacity().     \endcode      \sa areIndexesValid(), append(), prepend() */
end_comment
begin_comment
comment|/*! \fn bool QContiguousCache::areIndexesValid() const      Returns whether the indexes for items stored in the cache are valid.     Indexes can become invalid if items are appended after the index position     INT_MAX or prepended before the index position 0.  This is only expected     to occur in very long lived circular buffer style usage of the     contiguous cache.  Indexes can be made valid again by calling     normalizeIndexs().      \sa normalizeIndexes(), append(), prepend() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
