begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFREELIST_P_H
end_ifndef
begin_define
DECL|macro|QFREELIST_P_H
define|#
directive|define
name|QFREELIST_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*! \internal      Element in a QFreeList. ConstReferenceType and ReferenceType are used as     the return values for QFreeList::at() and QFreeList::operator[](). Contains     the real data storage (_t) and the id of the next free element (next).      Note: the t() functions should be used to access the data, not _t. */
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QFreeListElement
name|QFreeListElement
block|{
DECL|typedef|ConstReferenceType
typedef|typedef
specifier|const
name|T
modifier|&
name|ConstReferenceType
typedef|;
end_expr_stmt
begin_typedef
DECL|typedef|ReferenceType
typedef|typedef
name|T
modifier|&
name|ReferenceType
typedef|;
end_typedef
begin_decl_stmt
DECL|member|_t
name|T
name|_t
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|next
name|QAtomicInt
name|next
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|t
specifier|inline
name|ConstReferenceType
name|t
argument_list|()
specifier|const
block|{
return|return
name|_t
return|;
block|}
end_expr_stmt
begin_function
DECL|function|t
specifier|inline
name|ReferenceType
name|t
parameter_list|()
block|{
return|return
name|_t
return|;
block|}
end_function
begin_comment
unit|};
comment|/*! \internal      Element in a QFreeList without a payload. ConstReferenceType and     ReferenceType are void, the t() functions return void and are empty. */
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|QFreeListElement
operator|<
name|void
operator|>
block|{
typedef|typedef
name|void
name|ConstReferenceType
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
name|ReferenceType
typedef|;
end_typedef
begin_decl_stmt
name|QAtomicInt
name|next
decl_stmt|;
end_decl_stmt
begin_expr_stmt
specifier|inline
name|void
name|t
argument_list|()
specifier|const
block|{ }
specifier|inline
name|void
name|t
argument_list|()
block|{ }
end_expr_stmt
begin_comment
unit|};
comment|/*! \internal      Defines default constants used by QFreeList:      - The initial value returned by QFreeList::next() is zero.      - QFreeList allows for up to 16777216 elements in QFreeList and uses the top       8 bits to store a serial counter for ABA protection.      - QFreeList will make a maximum of 4 allocations (blocks), with each       successive block larger than the previous.      - Sizes static int[] array to define the size of each block.      It is possible to define your own constants struct/class and give this to     QFreeList to customize/tune the behavior. */
end_comment
begin_struct
DECL|struct|QFreeListDefaultConstants
struct|struct
name|Q_AUTOTEST_EXPORT
name|QFreeListDefaultConstants
block|{
comment|// used by QFreeList, make sure to define all of when customizing
enum|enum
block|{
DECL|enumerator|InitialNextValue
name|InitialNextValue
init|=
literal|0
block|,
DECL|enumerator|IndexMask
name|IndexMask
init|=
literal|0x00ffffff
block|,
DECL|enumerator|SerialMask
name|SerialMask
init|=
operator|~
name|IndexMask
operator|&
operator|~
literal|0x80000000
block|,
DECL|enumerator|SerialCounter
name|SerialCounter
init|=
name|IndexMask
operator|+
literal|1
block|,
DECL|enumerator|MaxIndex
name|MaxIndex
init|=
name|IndexMask
block|,
DECL|enumerator|BlockCount
name|BlockCount
init|=
literal|4
block|}
enum|;
DECL|member|Sizes
specifier|static
specifier|const
name|int
name|Sizes
index|[
name|BlockCount
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/*! \internal      This is a generic implementation of a lock-free free list. Use next() to     get the next free entry in the list, and release(id) when done with the id.      This version is templated and allows having a payload of type T which can     be accessed using the id returned by next(). The payload is allocated and     deallocated automatically by the free list, but *NOT* when calling     next()/release(). Initialization should be done by code needing it after     next() returns. Likewise, cleanup() should happen before calling release().     It is possible to have use 'void' as the payload type, in which case the     free list only contains indexes to the next free entry.      The ConstantsType type defaults to QFreeListDefaultConstants above. You can     define your custom ConstantsType, see above for details on what needs to be     available. */
end_comment
begin_expr_stmt
DECL|variable|T
DECL|variable|ConstantsType
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|=
name|QFreeListDefaultConstants
operator|>
name|class
name|QFreeList
block|{
typedef|typedef
name|T
name|ValueType
typedef|;
end_expr_stmt
begin_typedef
typedef|typedef
name|QFreeListElement
operator|<
name|T
operator|>
name|ElementType
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|ElementType
operator|::
name|ConstReferenceType
name|ConstReferenceType
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|typename
name|ElementType
operator|::
name|ReferenceType
name|ReferenceType
expr_stmt|;
end_typedef
begin_comment
comment|// return which block the index \a x falls in, and modify \a x to be the index into that block
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|blockfor
parameter_list|(
name|int
modifier|&
name|x
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
name|ConstantsType
operator|::
name|BlockCount
condition|;
operator|++
name|i
control|)
block|{
name|int
name|size
init|=
name|ConstantsType
operator|::
name|Sizes
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|x
operator|<
name|size
condition|)
return|return
name|i
return|;
name|x
operator|-=
name|size
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|// allocate a block of the given \a size, initialized starting with the given \a offset
end_comment
begin_function
specifier|static
specifier|inline
name|ElementType
modifier|*
name|allocate
parameter_list|(
name|int
name|offset
parameter_list|,
name|int
name|size
parameter_list|)
block|{
comment|// qDebug("QFreeList: allocating %d elements (%ld bytes) with offset %d", size, size * sizeof(ElementType), offset);
name|ElementType
modifier|*
name|v
init|=
name|new
name|ElementType
index|[
name|size
index|]
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
name|v
index|[
name|i
index|]
operator|.
name|next
operator|.
name|store
argument_list|(
name|offset
operator|+
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_comment
comment|// take the current serial number from \a o, increment it, and store it in \a n
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|incrementserial
parameter_list|(
name|int
name|o
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
name|int
argument_list|(
operator|(
name|uint
argument_list|(
name|n
argument_list|)
operator|&
name|ConstantsType
operator|::
name|IndexMask
operator|)
operator||
operator|(
operator|(
name|uint
argument_list|(
name|o
argument_list|)
operator|+
name|ConstantsType
operator|::
name|SerialCounter
operator|)
operator|&
name|ConstantsType
operator|::
name|SerialMask
operator|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// the blocks
end_comment
begin_expr_stmt
name|QAtomicPointer
operator|<
name|ElementType
operator|>
name|_v
index|[
name|ConstantsType
operator|::
name|BlockCount
index|]
expr_stmt|;
end_expr_stmt
begin_comment
comment|// the next free id
end_comment
begin_decl_stmt
name|QAtomicInt
name|_next
decl_stmt|;
end_decl_stmt
begin_comment
comment|// QFreeList is not copyable
end_comment
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFreeList
argument_list|)
end_macro
begin_label
name|public
label|:
end_label
begin_function_decl
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFreeList
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
operator|~
name|QFreeList
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns the payload for the given index \a x
end_comment
begin_decl_stmt
specifier|inline
name|ConstReferenceType
name|at
argument_list|(
name|int
name|x
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|inline
name|ReferenceType
name|operator
function_decl|[]
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*         Return the next free id. Use this id to access the payload (see above).         Call release(id) when done using the id.     */
end_comment
begin_function_decl
specifier|inline
name|int
name|next
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|inline
name|void
name|release
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|function|QFreeList
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|QFreeList
argument_list|()
operator|:
name|_next
argument_list|(
argument|ConstantsType::InitialNextValue
argument_list|)
block|{ }
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|function|~QFreeList
specifier|inline
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
operator|~
name|QFreeList
argument_list|()
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
name|ConstantsType
operator|::
name|BlockCount
condition|;
operator|++
name|i
control|)
name|delete
index|[]
name|_v
index|[
name|i
index|]
operator|.
name|load
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|variable|T
DECL|function|at
specifier|inline
name|typename
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|ConstReferenceType
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|at
argument_list|(
argument|int x
argument_list|)
specifier|const
block|{
specifier|const
name|int
name|block
operator|=
name|blockfor
argument_list|(
name|x
argument_list|)
block|;
return|return
operator|(
name|_v
index|[
name|block
index|]
operator|.
name|load
argument_list|()
operator|)
index|[
name|x
index|]
operator|.
name|t
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|variable|T
DECL|function|operator
specifier|inline
name|typename
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|ReferenceType
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|operator
index|[]
operator|(
name|int
name|x
operator|)
block|{
specifier|const
name|int
name|block
operator|=
name|blockfor
argument_list|(
name|x
argument_list|)
block|;
return|return
operator|(
name|_v
index|[
name|block
index|]
operator|.
name|load
argument_list|()
operator|)
index|[
name|x
index|]
operator|.
name|t
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|function|next
specifier|inline
name|int
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|next
argument_list|()
block|{
name|int
name|id
block|,
name|newid
block|,
name|at
block|;
name|ElementType
operator|*
name|v
block|;
do|do
block|{
name|id
operator|=
name|_next
operator|.
name|load
argument_list|()
expr_stmt|;
name|at
operator|=
name|id
operator|&
name|ConstantsType
operator|::
name|IndexMask
expr_stmt|;
specifier|const
name|int
name|block
init|=
name|blockfor
argument_list|(
name|at
argument_list|)
decl_stmt|;
name|v
operator|=
name|_v
index|[
name|block
index|]
operator|.
name|loadAcquire
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|v
condition|)
block|{
name|v
operator|=
name|allocate
argument_list|(
operator|(
name|id
operator|&
name|ConstantsType
operator|::
name|IndexMask
operator|)
operator|-
name|at
argument_list|,
name|ConstantsType
operator|::
name|Sizes
index|[
name|block
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|_v
index|[
name|block
index|]
operator|.
name|testAndSetRelease
argument_list|(
literal|0
argument_list|,
name|v
argument_list|)
condition|)
block|{
comment|// race with another thread lost
name|delete
index|[]
name|v
decl_stmt|;
name|v
operator|=
name|_v
index|[
name|block
index|]
operator|.
name|loadAcquire
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|v
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}          newid
operator|=
name|v
index|[
name|at
index|]
operator|.
name|next
operator|.
name|load
argument_list|()
operator||
operator|(
name|id
operator|&
operator|~
name|ConstantsType
operator|::
name|IndexMask
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|} while
operator|(
operator|!
name|_next
operator|.
name|testAndSetRelaxed
argument_list|(
name|id
argument_list|,
name|newid
argument_list|)
operator|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// qDebug("QFreeList::next(): returning %d (_next now %d, serial %d)",
end_comment
begin_comment
comment|//        id& ConstantsType::IndexMask,
end_comment
begin_comment
comment|//        newid& ConstantsType::IndexMask,
end_comment
begin_comment
comment|//        (newid& ~ConstantsType::IndexMask)>> 24);
end_comment
begin_return
return|return
name|id
operator|&
name|ConstantsType
operator|::
name|IndexMask
return|;
end_return
begin_expr_stmt
unit|}  template
DECL|variable|T
operator|<
name|typename
name|T
operator|,
name|typename
name|ConstantsType
operator|>
DECL|variable|T
DECL|function|release
specifier|inline
name|void
name|QFreeList
operator|<
name|T
operator|,
name|ConstantsType
operator|>
operator|::
name|release
argument_list|(
argument|int id
argument_list|)
block|{
name|int
name|at
operator|=
name|id
operator|&
name|ConstantsType
operator|::
name|IndexMask
block|;
specifier|const
name|int
name|block
operator|=
name|blockfor
argument_list|(
name|at
argument_list|)
block|;
name|ElementType
operator|*
name|v
operator|=
name|_v
index|[
name|block
index|]
operator|.
name|load
argument_list|()
block|;
name|int
name|x
block|,
name|newid
block|;
do|do
block|{
name|x
operator|=
name|_next
operator|.
name|loadAcquire
argument_list|()
expr_stmt|;
name|v
index|[
name|at
index|]
operator|.
name|next
operator|.
name|store
argument_list|(
name|x
operator|&
name|ConstantsType
operator|::
name|IndexMask
argument_list|)
expr_stmt|;
name|newid
operator|=
name|incrementserial
argument_list|(
name|x
argument_list|,
name|id
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_while
while|while
condition|(
operator|!
name|_next
operator|.
name|testAndSetRelease
argument_list|(
name|x
argument_list|,
name|newid
argument_list|)
condition|)
empty_stmt|;
end_while
begin_comment
comment|// qDebug("QFreeList::release(%d): _next now %d (was %d), serial %d",
end_comment
begin_comment
comment|//        id& ConstantsType::IndexMask,
end_comment
begin_comment
comment|//        newid& ConstantsType::IndexMask,
end_comment
begin_comment
comment|//        x& ConstantsType::IndexMask,
end_comment
begin_comment
comment|//        (newid& ~ConstantsType::IndexMask)>> 24);
end_comment
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QFREELIST_P_H
end_comment
end_unit
