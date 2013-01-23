begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QARRAY_TEST_SIMPLE_VECTOR_H
end_ifndef
begin_define
DECL|macro|QARRAY_TEST_SIMPLE_VECTOR_H
define|#
directive|define
name|QARRAY_TEST_SIMPLE_VECTOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qarraydata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qarraydatapointer.h>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
DECL|struct|SimpleVector
name|SimpleVector
block|{
DECL|member|private
name|private
operator|:
typedef|typedef
name|QTypedArrayData
operator|<
name|T
operator|>
name|Data
expr_stmt|;
DECL|member|public
name|public
operator|:
end_expr_stmt
begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef
begin_typedef
DECL|typedef|iterator
typedef|typedef
name|typename
name|Data
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|const_iterator
typedef|typedef
name|typename
name|Data
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef
begin_macro
DECL|function|SimpleVector
name|SimpleVector
argument_list|()
end_macro
begin_block
block|{     }
end_block
begin_macro
DECL|function|SimpleVector
name|explicit
end_macro
begin_macro
DECL|function|SimpleVector
name|SimpleVector
argument_list|(
argument|size_t n
argument_list|)
end_macro
begin_macro
DECL|function|SimpleVector
unit|:
name|d
argument_list|(
argument|Data::allocate(n)
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|n
condition|)
name|d
operator|->
name|appendInitialize
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|SimpleVector
name|SimpleVector
argument_list|(
argument|size_t n
argument_list|,
argument|const T&t
argument_list|)
end_macro
begin_macro
DECL|function|SimpleVector
unit|:
name|d
argument_list|(
argument|Data::allocate(n)
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|n
condition|)
name|d
operator|->
name|copyAppend
argument_list|(
name|n
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
end_block
begin_expr_stmt
DECL|function|SimpleVector
name|SimpleVector
argument_list|(
specifier|const
name|T
operator|*
name|begin
argument_list|,
specifier|const
name|T
operator|*
name|end
argument_list|)
operator|:
name|d
argument_list|(
argument|Data::allocate(end - begin)
argument_list|)
block|{
if|if
condition|(
name|end
operator|-
name|begin
condition|)
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
name|SimpleVector
argument_list|(
name|QArrayDataPointerRef
operator|<
name|T
operator|>
name|ptr
argument_list|)
operator|:
name|d
argument_list|(
argument|ptr
argument_list|)
block|{     }
name|explicit
name|SimpleVector
argument_list|(
name|Data
operator|*
name|ptr
argument_list|)
operator|:
name|d
argument_list|(
argument|ptr
argument_list|)
block|{     }
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|size
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isNull
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isEmpty
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|empty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isStatic
name|bool
name|isStatic
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ref
operator|.
name|isStatic
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|isShared
name|bool
name|isShared
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ref
operator|.
name|isShared
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|isSharedWith
name|bool
name|isSharedWith
argument_list|(
specifier|const
name|SimpleVector
operator|&
name|other
argument_list|)
decl|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|isSharable
name|bool
name|isSharable
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ref
operator|.
name|isSharable
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|setSharable
name|void
name|setSharable
parameter_list|(
name|bool
name|sharable
parameter_list|)
block|{
name|d
operator|.
name|setSharable
argument_list|(
name|sharable
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|function|size
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|size
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|capacity
name|size_t
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|alloc
return|;
block|}
end_expr_stmt
begin_function
DECL|function|begin
name|iterator
name|begin
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|begin
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|end
name|iterator
name|end
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|end
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
DECL|function|begin
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|constBegin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|end
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|constEnd
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|constBegin
name|const_iterator
name|constBegin
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|constEnd
name|const_iterator
name|constEnd
argument_list|()
specifier|const
block|{
return|return
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_function
DECL|function|operator
name|T
modifier|&
name|operator
function|[]
parameter_list|(
name|size_t
name|i
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|<
name|size_t
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|detach
argument_list|()
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
end_function
begin_function
DECL|function|at
name|T
modifier|&
name|at
parameter_list|(
name|size_t
name|i
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|<
name|size_t
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|detach
argument_list|()
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
end_function
begin_decl_stmt
DECL|function|operator
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|i
argument_list|)
decl|const
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|<
name|size_t
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|at
specifier|const
name|T
modifier|&
name|at
argument_list|(
name|size_t
name|i
argument_list|)
decl|const
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|<
name|size_t
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
end_decl_stmt
begin_function
DECL|function|front
name|T
modifier|&
name|front
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|detach
argument_list|()
expr_stmt|;
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|back
name|T
modifier|&
name|back
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|detach
argument_list|()
expr_stmt|;
return|return
operator|*
operator|(
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|front
specifier|const
name|T
operator|&
name|front
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|back
specifier|const
name|T
operator|&
name|back
argument_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|isEmpty
argument_list|()
argument_list|)
block|;
return|return
operator|*
operator|(
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|reserve
name|void
name|reserve
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|n
operator|<=
name|capacity
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|capacityReserved
condition|)
return|return;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|isShared
argument_list|()
condition|)
block|{
name|d
operator|->
name|capacityReserved
operator|=
literal|1
expr_stmt|;
return|return;
block|}
block|}
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|qMax
argument_list|(
name|n
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
operator||
name|Data
operator|::
name|CapacityReserved
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
argument_list|()
condition|)
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|constBegin
argument_list|()
argument_list|,
name|constEnd
argument_list|()
argument_list|)
expr_stmt|;
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|resize
parameter_list|(
name|size_t
name|newSize
parameter_list|)
block|{
if|if
condition|(
name|size
argument_list|()
operator|==
name|newSize
condition|)
return|return;
if|if
condition|(
name|d
operator|.
name|needsDetach
argument_list|()
operator|||
name|newSize
operator|>
name|capacity
argument_list|()
condition|)
block|{
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|newSize
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|newSize
condition|)
block|{
if|if
condition|(
name|newSize
operator|<
name|size
argument_list|()
condition|)
block|{
specifier|const
name|T
modifier|*
specifier|const
name|begin
init|=
name|constBegin
argument_list|()
decl_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|newSize
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|size
argument_list|()
condition|)
block|{
specifier|const
name|T
modifier|*
specifier|const
name|begin
init|=
name|constBegin
argument_list|()
decl_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|detached
operator|.
name|d
operator|->
name|appendInitialize
argument_list|(
name|newSize
argument_list|)
expr_stmt|;
block|}
block|}
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|newSize
operator|>
name|size
argument_list|()
condition|)
name|d
operator|->
name|appendInitialize
argument_list|(
name|newSize
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|truncate
argument_list|(
name|newSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|prepend
name|void
name|prepend
parameter_list|(
name|const_iterator
name|first
parameter_list|,
name|const_iterator
name|last
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|size
condition|)
block|{
name|append
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return;
name|T
modifier|*
specifier|const
name|begin
init|=
name|d
operator|->
name|begin
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|.
name|needsDetach
argument_list|()
operator|||
name|capacity
argument_list|()
operator|-
name|size
argument_list|()
operator|<
name|size_t
argument_list|(
name|last
operator|-
name|first
argument_list|)
condition|)
block|{
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|size
argument_list|()
operator|+
operator|(
name|last
operator|-
name|first
operator|)
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
operator||
name|Data
operator|::
name|Grow
argument_list|)
argument_list|)
decl_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|d
operator|->
name|size
argument_list|)
expr_stmt|;
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|insert
argument_list|(
name|begin
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|append
parameter_list|(
name|const_iterator
name|first
parameter_list|,
name|const_iterator
name|last
parameter_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return;
if|if
condition|(
name|d
operator|.
name|needsDetach
argument_list|()
operator|||
name|capacity
argument_list|()
operator|-
name|size
argument_list|()
operator|<
name|size_t
argument_list|(
name|last
operator|-
name|first
argument_list|)
condition|)
block|{
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|size
argument_list|()
operator|+
operator|(
name|last
operator|-
name|first
operator|)
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
operator||
name|Data
operator|::
name|Grow
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|size
condition|)
block|{
specifier|const
name|T
modifier|*
specifier|const
name|begin
init|=
name|constBegin
argument_list|()
decl_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|d
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|copyAppend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insert
name|void
name|insert
parameter_list|(
name|int
name|position
parameter_list|,
name|const_iterator
name|first
parameter_list|,
name|const_iterator
name|last
parameter_list|)
block|{
if|if
condition|(
name|position
operator|<
literal|0
condition|)
name|position
operator|+=
name|d
operator|->
name|size
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|position
operator|<=
literal|0
condition|)
block|{
name|prepend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|size_t
argument_list|(
name|position
argument_list|)
operator|>=
name|size
argument_list|()
condition|)
block|{
name|append
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return;
name|T
modifier|*
specifier|const
name|begin
init|=
name|d
operator|->
name|begin
argument_list|()
decl_stmt|;
name|T
modifier|*
specifier|const
name|where
init|=
name|begin
operator|+
name|position
decl_stmt|;
specifier|const
name|T
modifier|*
specifier|const
name|end
init|=
name|begin
operator|+
name|d
operator|->
name|size
decl_stmt|;
if|if
condition|(
name|d
operator|.
name|needsDetach
argument_list|()
operator|||
name|capacity
argument_list|()
operator|-
name|size
argument_list|()
operator|<
name|size_t
argument_list|(
name|last
operator|-
name|first
argument_list|)
condition|)
block|{
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|size
argument_list|()
operator|+
operator|(
name|last
operator|-
name|first
operator|)
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
operator||
name|Data
operator|::
name|Grow
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|position
condition|)
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|where
argument_list|)
expr_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|where
argument_list|,
name|end
argument_list|)
expr_stmt|;
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|first
operator|>=
name|where
operator|&&
name|first
operator|<
name|end
operator|)
operator|||
operator|(
name|last
operator|>
name|where
operator|&&
name|last
operator|<=
name|end
operator|)
condition|)
block|{
comment|// Copy overlapping data first and only then shuffle it into place
name|T
modifier|*
name|start
init|=
name|d
operator|->
name|begin
argument_list|()
operator|+
name|position
decl_stmt|;
name|T
modifier|*
name|middle
init|=
name|d
operator|->
name|end
argument_list|()
decl_stmt|;
name|d
operator|->
name|copyAppend
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
name|std
operator|::
name|rotate
argument_list|(
name|start
argument_list|,
name|middle
argument_list|,
name|d
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|insert
argument_list|(
name|where
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|erase
name|void
name|erase
parameter_list|(
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return;
specifier|const
name|T
modifier|*
specifier|const
name|begin
init|=
name|d
operator|->
name|begin
argument_list|()
decl_stmt|;
specifier|const
name|T
modifier|*
specifier|const
name|end
init|=
name|begin
operator|+
name|d
operator|->
name|size
decl_stmt|;
if|if
condition|(
name|d
operator|.
name|needsDetach
argument_list|()
condition|)
block|{
name|SimpleVector
name|detached
argument_list|(
name|Data
operator|::
name|allocate
argument_list|(
name|d
operator|->
name|detachCapacity
argument_list|(
name|size
argument_list|()
operator|-
operator|(
name|last
operator|-
name|first
operator|)
argument_list|)
argument_list|,
name|d
operator|->
name|detachFlags
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|first
operator|!=
name|begin
condition|)
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|begin
argument_list|,
name|first
argument_list|)
expr_stmt|;
name|detached
operator|.
name|d
operator|->
name|copyAppend
argument_list|(
name|last
argument_list|,
name|end
argument_list|)
expr_stmt|;
name|detached
operator|.
name|swap
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|last
operator|==
name|end
condition|)
name|d
operator|->
name|truncate
argument_list|(
name|end
operator|-
name|first
argument_list|)
expr_stmt|;
else|else
name|d
operator|->
name|erase
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swap
name|void
name|swap
parameter_list|(
name|SimpleVector
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|clear
parameter_list|()
block|{
name|d
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|detach
name|void
name|detach
parameter_list|()
block|{
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|function|fromRawData
specifier|static
name|SimpleVector
name|fromRawData
argument_list|(
specifier|const
name|T
operator|*
name|data
argument_list|,
name|size_t
name|size
argument_list|,
name|QArrayData
operator|::
name|AllocationOptions
name|options
operator|=
name|Data
operator|::
name|Default
argument_list|)
block|{
return|return
name|SimpleVector
argument_list|(
name|Data
operator|::
name|fromRawData
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
name|options
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
DECL|variable|d
name|QArrayDataPointer
operator|<
name|T
operator|>
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|d
unit|};
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|isSharedWith
argument_list|(
name|rhs
argument_list|)
condition|)
return|return
name|true
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|lhs
operator|.
name|size
argument_list|()
operator|!=
name|rhs
operator|.
name|size
argument_list|()
condition|)
return|return
name|false
return|;
end_if
begin_return
return|return
name|std
operator|::
name|equal
argument_list|(
name|lhs
operator|.
name|begin
argument_list|()
argument_list|,
name|lhs
operator|.
name|end
argument_list|()
argument_list|,
name|rhs
operator|.
name|begin
argument_list|()
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
operator|!
operator|(
name|lhs
operator|==
name|rhs
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
name|std
operator|::
name|lexicographical_compare
argument_list|(
name|lhs
operator|.
name|begin
argument_list|()
argument_list|,
name|lhs
operator|.
name|end
argument_list|()
argument_list|,
name|rhs
operator|.
name|begin
argument_list|()
argument_list|,
name|rhs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|>
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
name|rhs
operator|<
name|lhs
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
operator|!
operator|(
name|rhs
operator|<
name|lhs
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|SimpleVector
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
return|return
operator|!
operator|(
name|lhs
operator|<
name|rhs
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|class
name|T
operator|>
name|void
name|swap
argument_list|(
argument|SimpleVector<T>&v1
argument_list|,
argument|SimpleVector<T>&v2
argument_list|)
block|{
name|v1
operator|.
name|swap
argument_list|(
name|v2
argument_list|)
block|;     }
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
