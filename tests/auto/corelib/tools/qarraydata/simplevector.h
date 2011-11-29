begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_expr_stmt
DECL|function|SimpleVector
name|SimpleVector
argument_list|()
operator|:
name|d
argument_list|(
argument|Data::sharedNull()
argument_list|)
block|{     }
DECL|function|SimpleVector
name|SimpleVector
argument_list|(
specifier|const
name|SimpleVector
operator|&
name|vec
argument_list|)
operator|:
name|d
argument_list|(
argument|vec.d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
argument_list|()
block|;     }
DECL|function|SimpleVector
name|SimpleVector
argument_list|(
argument|size_t n
argument_list|,
argument|const T&t
argument_list|)
operator|:
name|d
argument_list|(
argument|Data::allocate(n)
argument_list|)
block|{
for|for
control|(
name|size_t
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
name|new
argument_list|(
argument|d->end()
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|++
name|d
operator|->
name|size
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}      explicit
DECL|function|SimpleVector
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
DECL|function|~SimpleVector
operator|~
name|SimpleVector
argument_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
block|{
specifier|const
name|T
modifier|*
specifier|const
name|data
init|=
name|d
operator|->
name|data
argument_list|()
decl_stmt|;
while|while
condition|(
name|d
operator|->
name|size
operator|--
condition|)
name|data
index|[
name|d
operator|->
name|size
index|]
operator|.
operator|~
name|T
argument_list|()
expr_stmt|;
name|Data
operator|::
name|deallocate
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}      SimpleVector
DECL|member|operator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SimpleVector
operator|&
name|vec
operator|)
block|{
name|SimpleVector
name|temp
argument_list|(
name|vec
argument_list|)
block|;
name|this
operator|->
name|swap
argument_list|(
name|temp
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|d
operator|==
name|Data
operator|::
name|sharedNull
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
begin_decl_stmt
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
begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|begin
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|end
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
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
begin_decl_stmt
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
begin_expr_stmt
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
name|void
name|clear
parameter_list|()
block|{
name|SimpleVector
name|tmp
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|=
name|Data
operator|::
name|sharedEmpty
argument_list|()
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|Data
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
