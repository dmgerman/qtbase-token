begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbitarray.h"
end_include
begin_include
include|#
directive|include
file|<qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QBitArray     \inmodule QtCore     \brief The QBitArray class provides an array of bits.      \ingroup tools     \ingroup shared     \reentrant      A QBitArray is an array that gives access to individual bits and     provides operators (\l{operator&()}{AND}, \l{operator|()}{OR},     \l{operator^()}{XOR}, and \l{operator~()}{NOT}) that work on     entire arrays of bits. It uses \l{implicit sharing} (copy-on-write)     to reduce memory usage and to avoid the needless copying of data.      The following code constructs a QBitArray containing 200 bits     initialized to false (0):      \snippet code/src_corelib_tools_qbitarray.cpp 0      To initialize the bits to true, either pass \c true as second     argument to the constructor, or call fill() later on.      QBitArray uses 0-based indexes, just like C++ arrays. To access     the bit at a particular index position, you can use operator[]().     On non-const bit arrays, operator[]() returns a reference to a     bit that can be used on the left side of an assignment. For     example:      \snippet code/src_corelib_tools_qbitarray.cpp 1      For technical reasons, it is more efficient to use testBit() and     setBit() to access bits in the array than operator[](). For     example:      \snippet code/src_corelib_tools_qbitarray.cpp 2      QBitArray supports \c{&} (\l{operator&()}{AND}), \c{|}     (\l{operator|()}{OR}), \c{^} (\l{operator^()}{XOR}),     \c{~} (\l{operator~()}{NOT}), as well as     \c{&=}, \c{|=}, and \c{^=}. These operators work in the same way     as the built-in C++ bitwise operators of the same name. For     example:      \snippet code/src_corelib_tools_qbitarray.cpp 3      For historical reasons, QBitArray distinguishes between a null     bit array and an empty bit array. A \e null bit array is a bit     array that is initialized using QBitArray's default constructor.     An \e empty bit array is any bit array with size 0. A null bit     array is always empty, but an empty bit array isn't necessarily     null:      \snippet code/src_corelib_tools_qbitarray.cpp 4      All functions except isNull() treat null bit arrays the same as     empty bit arrays; for example, QBitArray() compares equal to     QBitArray(0). We recommend that you always use isEmpty() and     avoid isNull().      \sa QByteArray, QVector */
comment|/*! \fn QBitArray::QBitArray()      Constructs an empty bit array.      \sa isEmpty() */
comment|/*!     Constructs a bit array containing \a size bits. The bits are     initialized with \a value, which defaults to false (0). */
DECL|function|QBitArray
name|QBitArray
operator|::
name|QBitArray
parameter_list|(
name|int
name|size
parameter_list|,
name|bool
name|value
parameter_list|)
block|{
if|if
condition|(
operator|!
name|size
condition|)
block|{
name|d
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|.
name|resize
argument_list|(
literal|1
operator|+
operator|(
name|size
operator|+
literal|7
operator|)
operator|/
literal|8
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|c
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|c
argument_list|,
name|value
condition|?
literal|0xff
else|:
literal|0
argument_list|,
name|d
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|c
operator|=
name|d
operator|.
name|size
argument_list|()
operator|*
literal|8
operator|-
name|size
expr_stmt|;
if|if
condition|(
name|value
operator|&&
name|size
operator|&&
name|size
operator|%
literal|8
condition|)
operator|*
operator|(
name|c
operator|+
literal|1
operator|+
name|size
operator|/
literal|8
operator|)
operator|&=
operator|(
literal|1
operator|<<
operator|(
name|size
operator|%
literal|8
operator|)
operator|)
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn int QBitArray::size() const      Returns the number of bits stored in the bit array.      \sa resize() */
end_comment
begin_comment
comment|/*! \fn int QBitArray::count() const      Same as size(). */
end_comment
begin_comment
comment|/*!     If \a on is true, this function returns the number of     1-bits stored in the bit array; otherwise the number     of 0-bits is returned. */
end_comment
begin_function
DECL|function|count
name|int
name|QBitArray
operator|::
name|count
parameter_list|(
name|bool
name|on
parameter_list|)
specifier|const
block|{
name|int
name|numBits
init|=
literal|0
decl_stmt|;
name|int
name|len
init|=
name|size
argument_list|()
decl_stmt|;
if|#
directive|if
literal|0
block|for (int i = 0; i< len; ++i)         numBits += testBit(i);
else|#
directive|else
comment|// See http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
specifier|const
name|quint8
modifier|*
name|bits
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint8
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
while|while
condition|(
name|len
operator|>=
literal|32
condition|)
block|{
name|quint32
name|v
init|=
name|quint32
argument_list|(
name|bits
index|[
literal|0
index|]
argument_list|)
operator||
operator|(
name|quint32
argument_list|(
name|bits
index|[
literal|1
index|]
argument_list|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|bits
index|[
literal|2
index|]
argument_list|)
operator|<<
literal|16
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|bits
index|[
literal|3
index|]
argument_list|)
operator|<<
literal|24
operator|)
decl_stmt|;
name|quint32
name|c
init|=
operator|(
operator|(
name|v
operator|&
literal|0xfff
operator|)
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x1001001001001
argument_list|)
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x84210842108421
argument_list|)
operator|)
operator|%
literal|0x1f
decl_stmt|;
name|c
operator|+=
operator|(
operator|(
operator|(
name|v
operator|&
literal|0xfff000
operator|)
operator|>>
literal|12
operator|)
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x1001001001001
argument_list|)
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x84210842108421
argument_list|)
operator|)
operator|%
literal|0x1f
expr_stmt|;
name|c
operator|+=
operator|(
operator|(
name|v
operator|>>
literal|24
operator|)
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x1001001001001
argument_list|)
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x84210842108421
argument_list|)
operator|)
operator|%
literal|0x1f
expr_stmt|;
name|len
operator|-=
literal|32
expr_stmt|;
name|bits
operator|+=
literal|4
expr_stmt|;
name|numBits
operator|+=
name|int
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|len
operator|>=
literal|24
condition|)
block|{
name|quint32
name|v
init|=
name|quint32
argument_list|(
name|bits
index|[
literal|0
index|]
argument_list|)
operator||
operator|(
name|quint32
argument_list|(
name|bits
index|[
literal|1
index|]
argument_list|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|bits
index|[
literal|2
index|]
argument_list|)
operator|<<
literal|16
operator|)
decl_stmt|;
name|quint32
name|c
init|=
operator|(
operator|(
name|v
operator|&
literal|0xfff
operator|)
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x1001001001001
argument_list|)
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x84210842108421
argument_list|)
operator|)
operator|%
literal|0x1f
decl_stmt|;
name|c
operator|+=
operator|(
operator|(
operator|(
name|v
operator|&
literal|0xfff000
operator|)
operator|>>
literal|12
operator|)
operator|*
name|Q_UINT64_C
argument_list|(
literal|0x1001001001001
argument_list|)
operator|&
name|Q_UINT64_C
argument_list|(
literal|0x84210842108421
argument_list|)
operator|)
operator|%
literal|0x1f
expr_stmt|;
name|len
operator|-=
literal|24
expr_stmt|;
name|bits
operator|+=
literal|3
expr_stmt|;
name|numBits
operator|+=
name|int
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|len
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|bits
index|[
name|len
operator|/
literal|8
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
operator|(
name|len
operator|-
literal|1
operator|)
operator|&
literal|7
operator|)
operator|)
condition|)
operator|++
name|numBits
expr_stmt|;
operator|--
name|len
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|on
condition|?
name|numBits
else|:
name|size
argument_list|()
operator|-
name|numBits
return|;
block|}
end_function
begin_comment
comment|/*!     Resizes the bit array to \a size bits.      If \a size is greater than the current size, the bit array is     extended to make it \a size bits with the extra bits added to the     end. The new bits are initialized to false (0).      If \a size is less than the current size, bits are removed from     the end.      \sa size() */
end_comment
begin_function
DECL|function|resize
name|void
name|QBitArray
operator|::
name|resize
parameter_list|(
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
operator|!
name|size
condition|)
block|{
name|d
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|s
init|=
name|d
operator|.
name|size
argument_list|()
decl_stmt|;
name|d
operator|.
name|resize
argument_list|(
literal|1
operator|+
operator|(
name|size
operator|+
literal|7
operator|)
operator|/
literal|8
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|c
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|>
operator|(
name|s
operator|<<
literal|3
operator|)
condition|)
name|memset
argument_list|(
name|c
operator|+
name|s
argument_list|,
literal|0
argument_list|,
name|d
operator|.
name|size
argument_list|()
operator|-
name|s
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|size
operator|%
literal|8
condition|)
operator|*
operator|(
name|c
operator|+
literal|1
operator|+
name|size
operator|/
literal|8
operator|)
operator|&=
operator|(
literal|1
operator|<<
operator|(
name|size
operator|%
literal|8
operator|)
operator|)
operator|-
literal|1
expr_stmt|;
operator|*
name|c
operator|=
name|d
operator|.
name|size
argument_list|()
operator|*
literal|8
operator|-
name|size
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \fn bool QBitArray::isEmpty() const      Returns true if this bit array has size 0; otherwise returns     false.      \sa size() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::isNull() const      Returns true if this bit array is null; otherwise returns false.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 5      Qt makes a distinction between null bit arrays and empty bit     arrays for historical reasons. For most applications, what     matters is whether or not a bit array contains any data,     and this can be determined using isEmpty().      \sa isEmpty() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::fill(bool value, int size = -1)      Sets every bit in the bit array to \a value, returning true if successful;     otherwise returns false. If \a size is different from -1 (the default),     the bit array is resized to \a size beforehand.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 6      \sa resize() */
end_comment
begin_comment
comment|/*!     \overload      Sets bits at index positions \a begin up to and excluding \a end     to \a value.      \a begin and \a end must be a valid index position in the bit     array (i.e., 0<= \a begin<= size() and 0<= \a end<= size()). */
end_comment
begin_function
DECL|function|fill
name|void
name|QBitArray
operator|::
name|fill
parameter_list|(
name|bool
name|value
parameter_list|,
name|int
name|begin
parameter_list|,
name|int
name|end
parameter_list|)
block|{
while|while
condition|(
name|begin
operator|<
name|end
operator|&&
name|begin
operator|&
literal|0x7
condition|)
name|setBit
argument_list|(
name|begin
operator|++
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|int
name|len
init|=
name|end
operator|-
name|begin
decl_stmt|;
if|if
condition|(
name|len
operator|<=
literal|0
condition|)
return|return;
name|int
name|s
init|=
name|len
operator|&
operator|~
literal|0x7
decl_stmt|;
name|uchar
modifier|*
name|c
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|c
operator|+
operator|(
name|begin
operator|>>
literal|3
operator|)
operator|+
literal|1
argument_list|,
name|value
condition|?
literal|0xff
else|:
literal|0
argument_list|,
name|s
operator|>>
literal|3
argument_list|)
expr_stmt|;
name|begin
operator|+=
name|s
expr_stmt|;
while|while
condition|(
name|begin
operator|<
name|end
condition|)
name|setBit
argument_list|(
name|begin
operator|++
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \fn bool QBitArray::isDetached() const      \internal */
end_comment
begin_comment
comment|/*! \fn void QBitArray::detach()      \internal */
end_comment
begin_comment
comment|/*! \fn void QBitArray::clear()      Clears the contents of the bit array and makes it empty.      \sa resize(), isEmpty() */
end_comment
begin_comment
comment|/*! \fn void QBitArray::truncate(int pos)      Truncates the bit array at index position \a pos.      If \a pos is beyond the end of the array, nothing happens.      \sa resize() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::toggleBit(int i)      Inverts the value of the bit at index position \a i, returning the     previous value of that bit as either true (if it was set) or false (if     it was unset).      If the previous value was 0, the new value will be 1. If the     previous value was 1, the new value will be 0.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      \sa setBit(), clearBit() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::testBit(int i) const      Returns true if the bit at index position \a i is 1; otherwise     returns false.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      \sa setBit(), clearBit() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::setBit(int i)      Sets the bit at index position \a i to 1.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      \sa clearBit(), toggleBit() */
end_comment
begin_comment
comment|/*! \fn void QBitArray::setBit(int i, bool value)      \overload      Sets the bit at index position \a i to \a value. */
end_comment
begin_comment
comment|/*! \fn void QBitArray::clearBit(int i)      Sets the bit at index position \a i to 0.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      \sa setBit(), toggleBit() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::at(int i) const      Returns the value of the bit at index position \a i.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      \sa operator[]() */
end_comment
begin_comment
comment|/*! \fn QBitRef QBitArray::operator[](int i)      Returns the bit at index position \a i as a modifiable reference.      \a i must be a valid index position in the bit array (i.e., 0<=     \a i< size()).      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 7      The return value is of type QBitRef, a helper class for QBitArray.     When you get an object of type QBitRef, you can assign to     it, and the assignment will apply to the bit in the QBitArray     from which you got the reference.      The functions testBit(), setBit(), and clearBit() are slightly     faster.      \sa at(), testBit(), setBit(), clearBit() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::operator[](int i) const      \overload */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::operator[](uint i)      \overload */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::operator[](uint i) const      \overload */
end_comment
begin_comment
comment|/*! \fn QBitArray::QBitArray(const QBitArray&other)      Constructs a copy of \a other.      This operation takes \l{constant time}, because QBitArray is     \l{implicitly shared}. This makes returning a QBitArray from a     function very fast. If a shared instance is modified, it will be     copied (copy-on-write), and that takes \l{linear time}.      \sa operator=() */
end_comment
begin_comment
comment|/*! \fn QBitArray&QBitArray::operator=(const QBitArray&other)      Assigns \a other to this bit array and returns a reference to     this bit array. */
end_comment
begin_comment
comment|/*! \fn void QBitArray::swap(QBitArray&other)     \since 4.8      Swaps bit array \a other with this bit array. This operation is very     fast and never fails. */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::operator==(const QBitArray&other) const      Returns true if \a other is equal to this bit array; otherwise     returns false.      \sa operator!=() */
end_comment
begin_comment
comment|/*! \fn bool QBitArray::operator!=(const QBitArray&other) const      Returns true if \a other is not equal to this bit array;     otherwise returns false.      \sa operator==() */
end_comment
begin_comment
comment|/*!     Performs the AND operation between all bits in this bit array and     \a other. Assigns the result to this bit array, and returns a     reference to it.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 8      \sa operator&(), operator|=(), operator^=(), operator~() */
end_comment
begin_function
DECL|function|operator &=
name|QBitArray
modifier|&
name|QBitArray
operator|::
name|operator
name|&=
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|other
parameter_list|)
block|{
name|resize
argument_list|(
name|qMax
argument_list|(
name|size
argument_list|()
argument_list|,
name|other
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|a1
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|a2
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|d
operator|.
name|constData
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
name|int
name|n
init|=
name|other
operator|.
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
name|int
name|p
init|=
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|-
name|n
decl_stmt|;
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
operator|*
name|a1
operator|++
operator|&=
operator|*
name|a2
operator|++
expr_stmt|;
while|while
condition|(
name|p
operator|--
operator|>
literal|0
condition|)
operator|*
name|a1
operator|++
operator|=
literal|0
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Performs the OR operation between all bits in this bit array and     \a other. Assigns the result to this bit array, and returns a     reference to it.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 9      \sa operator|(), operator&=(), operator^=(), operator~() */
end_comment
begin_function
DECL|function|operator |=
name|QBitArray
modifier|&
name|QBitArray
operator|::
name|operator
name||=
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|other
parameter_list|)
block|{
name|resize
argument_list|(
name|qMax
argument_list|(
name|size
argument_list|()
argument_list|,
name|other
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|a1
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|a2
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|d
operator|.
name|constData
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
name|int
name|n
init|=
name|other
operator|.
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
operator|*
name|a1
operator|++
operator||=
operator|*
name|a2
operator|++
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Performs the XOR operation between all bits in this bit array and     \a other. Assigns the result to this bit array, and returns a     reference to it.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 10      \sa operator^(), operator&=(), operator|=(), operator~() */
end_comment
begin_function
DECL|function|operator ^=
name|QBitArray
modifier|&
name|QBitArray
operator|::
name|operator
name|^=
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|other
parameter_list|)
block|{
name|resize
argument_list|(
name|qMax
argument_list|(
name|size
argument_list|()
argument_list|,
name|other
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|a1
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|data
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|a2
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|other
operator|.
name|d
operator|.
name|constData
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
name|int
name|n
init|=
name|other
operator|.
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
operator|*
name|a1
operator|++
operator|^=
operator|*
name|a2
operator|++
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a bit array that contains the inverted bits of this bit     array.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 11      \sa operator&(), operator|(), operator^() */
end_comment
begin_function
DECL|function|operator ~
name|QBitArray
name|QBitArray
operator|::
name|operator
name|~
parameter_list|()
specifier|const
block|{
name|int
name|sz
init|=
name|size
argument_list|()
decl_stmt|;
name|QBitArray
name|a
argument_list|(
name|sz
argument_list|)
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|a1
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|uchar
operator|*
argument_list|>
argument_list|(
name|d
operator|.
name|constData
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
name|uchar
modifier|*
name|a2
init|=
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|a
operator|.
name|d
operator|.
name|data
argument_list|()
argument_list|)
operator|+
literal|1
decl_stmt|;
name|int
name|n
init|=
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
operator|*
name|a2
operator|++
operator|=
operator|~
operator|*
name|a1
operator|++
expr_stmt|;
if|if
condition|(
name|sz
operator|&&
name|sz
operator|%
literal|8
condition|)
operator|*
operator|(
name|a2
operator|-
literal|1
operator|)
operator|&=
operator|(
literal|1
operator|<<
operator|(
name|sz
operator|%
literal|8
operator|)
operator|)
operator|-
literal|1
expr_stmt|;
return|return
name|a
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QBitArray      Returns a bit array that is the AND of the bit arrays \a a1 and \a     a2.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 12      \sa QBitArray::operator&=(), operator|(), operator^() */
end_comment
begin_function
DECL|function|operator &
name|QBitArray
name|operator
name|&
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|a1
parameter_list|,
specifier|const
name|QBitArray
modifier|&
name|a2
parameter_list|)
block|{
name|QBitArray
name|tmp
init|=
name|a1
decl_stmt|;
name|tmp
operator|&=
name|a2
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QBitArray      Returns a bit array that is the OR of the bit arrays \a a1 and \a     a2.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 13      \sa QBitArray::operator|=(), operator&(), operator^() */
end_comment
begin_function
DECL|function|operator |
name|QBitArray
name|operator
name||
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|a1
parameter_list|,
specifier|const
name|QBitArray
modifier|&
name|a2
parameter_list|)
block|{
name|QBitArray
name|tmp
init|=
name|a1
decl_stmt|;
name|tmp
operator||=
name|a2
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QBitArray      Returns a bit array that is the XOR of the bit arrays \a a1 and \a     a2.      The result has the length of the longest of the two bit arrays,     with any missing bits (if one array is shorter than the other)     taken to be 0.      Example:     \snippet code/src_corelib_tools_qbitarray.cpp 14      \sa QBitArray::operator^=(), operator&(), operator|() */
end_comment
begin_function
DECL|function|operator ^
name|QBitArray
name|operator
name|^
parameter_list|(
specifier|const
name|QBitArray
modifier|&
name|a1
parameter_list|,
specifier|const
name|QBitArray
modifier|&
name|a2
parameter_list|)
block|{
name|QBitArray
name|tmp
init|=
name|a1
decl_stmt|;
name|tmp
operator|^=
name|a2
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_comment
comment|/*!     \class QBitRef     \inmodule QtCore     \reentrant     \brief The QBitRef class is an internal class, used with QBitArray.      \internal      The QBitRef is required by the indexing [] operator on bit arrays.     It is not for use in any other context. */
end_comment
begin_comment
comment|/*! \fn QBitRef::QBitRef (QBitArray& a, int i)      Constructs a reference to element \a i in the QBitArray \a a.     This is what QBitArray::operator[] constructs its return value     with. */
end_comment
begin_comment
comment|/*! \fn QBitRef::operator bool() const      Returns the value referenced by the QBitRef. */
end_comment
begin_comment
comment|/*! \fn bool QBitRef::operator!() const      \internal */
end_comment
begin_comment
comment|/*! \fn QBitRef& QBitRef::operator= (const QBitRef& v)      Sets the value referenced by the QBitRef to that referenced by     QBitRef \a v. */
end_comment
begin_comment
comment|/*! \fn QBitRef& QBitRef::operator= (bool v)     \overload      Sets the value referenced by the QBitRef to \a v. */
end_comment
begin_comment
comment|/*****************************************************************************   QBitArray stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \relates QBitArray      Writes bit array \a ba to stream \a out.      \sa {Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|out
parameter_list|,
specifier|const
name|QBitArray
modifier|&
name|ba
parameter_list|)
block|{
name|quint32
name|len
init|=
name|ba
operator|.
name|size
argument_list|()
decl_stmt|;
name|out
operator|<<
name|len
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
name|out
operator|.
name|writeRawData
argument_list|(
name|ba
operator|.
name|d
operator|.
name|constData
argument_list|()
operator|+
literal|1
argument_list|,
name|ba
operator|.
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QBitArray      Reads a bit array into \a ba from stream \a in.      \sa {Serializing Qt Data Types}{Format of the QDataStream operators} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|in
parameter_list|,
name|QBitArray
modifier|&
name|ba
parameter_list|)
block|{
name|ba
operator|.
name|clear
argument_list|()
expr_stmt|;
name|quint32
name|len
decl_stmt|;
name|in
operator|>>
name|len
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
block|{
name|ba
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|in
return|;
block|}
specifier|const
name|quint32
name|Step
init|=
literal|8
operator|*
literal|1024
operator|*
literal|1024
decl_stmt|;
name|quint32
name|totalBytes
init|=
operator|(
name|len
operator|+
literal|7
operator|)
operator|/
literal|8
decl_stmt|;
name|quint32
name|allocated
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|allocated
operator|<
name|totalBytes
condition|)
block|{
name|int
name|blockSize
init|=
name|qMin
argument_list|(
name|Step
argument_list|,
name|totalBytes
operator|-
name|allocated
argument_list|)
decl_stmt|;
name|ba
operator|.
name|d
operator|.
name|resize
argument_list|(
name|allocated
operator|+
name|blockSize
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|in
operator|.
name|readRawData
argument_list|(
name|ba
operator|.
name|d
operator|.
name|data
argument_list|()
operator|+
literal|1
operator|+
name|allocated
argument_list|,
name|blockSize
argument_list|)
operator|!=
name|blockSize
condition|)
block|{
name|ba
operator|.
name|clear
argument_list|()
expr_stmt|;
name|in
operator|.
name|setStatus
argument_list|(
name|QDataStream
operator|::
name|ReadPastEnd
argument_list|)
expr_stmt|;
return|return
name|in
return|;
block|}
name|allocated
operator|+=
name|blockSize
expr_stmt|;
block|}
name|int
name|paddingMask
init|=
operator|~
operator|(
operator|(
literal|0x1
operator|<<
operator|(
name|len
operator|&
literal|0x7
operator|)
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
if|if
condition|(
name|paddingMask
operator|!=
operator|~
literal|0x0
operator|&&
operator|(
name|ba
operator|.
name|d
operator|.
name|constData
argument_list|()
index|[
name|ba
operator|.
name|d
operator|.
name|size
argument_list|()
operator|-
literal|1
index|]
operator|&
name|paddingMask
operator|)
condition|)
block|{
name|ba
operator|.
name|clear
argument_list|()
expr_stmt|;
name|in
operator|.
name|setStatus
argument_list|(
name|QDataStream
operator|::
name|ReadCorruptData
argument_list|)
expr_stmt|;
return|return
name|in
return|;
block|}
operator|*
name|ba
operator|.
name|d
operator|.
name|data
argument_list|()
operator|=
name|ba
operator|.
name|d
operator|.
name|size
argument_list|()
operator|*
literal|8
operator|-
name|len
expr_stmt|;
return|return
name|in
return|;
block|}
end_function
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
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QBitArray
modifier|&
name|array
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QBitArray("
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
name|array
operator|.
name|size
argument_list|()
condition|;
control|)
block|{
if|if
condition|(
name|array
operator|.
name|testBit
argument_list|(
name|i
argument_list|)
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|'1'
expr_stmt|;
else|else
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|'0'
expr_stmt|;
name|i
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|i
operator|%
literal|4
operator|)
operator|&&
operator|(
name|i
operator|<
name|array
operator|.
name|size
argument_list|()
operator|)
condition|)
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|' '
expr_stmt|;
block|}
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn DataPtr&QBitArray::data_ptr()     \internal */
end_comment
begin_comment
comment|/*!     \typedef QBitArray::DataPtr     \internal */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
