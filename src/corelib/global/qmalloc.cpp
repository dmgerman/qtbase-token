begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|/*     Define the container allocation functions in a separate file, so that our     users can easily override them. */
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
comment|// Make sure they're defined to be exported
name|Q_CORE_EXPORT
name|void
modifier|*
name|qMalloc
argument_list|(
name|size_t
name|size
argument_list|)
name|Q_ALLOC_SIZE
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qFree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|Q_CORE_EXPORT
name|void
modifier|*
name|qRealloc
argument_list|(
name|void
operator|*
name|ptr
argument_list|,
name|size_t
name|size
argument_list|)
name|Q_ALLOC_SIZE
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qMalloc
name|void
modifier|*
name|qMalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|::
name|malloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFree
name|void
name|qFree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
operator|::
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qRealloc
name|void
modifier|*
name|qRealloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|::
name|realloc
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qMallocAligned
name|void
modifier|*
name|qMallocAligned
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
return|return
name|qReallocAligned
argument_list|(
literal|0
argument_list|,
name|size
argument_list|,
literal|0
argument_list|,
name|alignment
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qReallocAligned
name|void
modifier|*
name|qReallocAligned
parameter_list|(
name|void
modifier|*
name|oldptr
parameter_list|,
name|size_t
name|newsize
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
comment|// fake an aligned allocation
name|Q_UNUSED
argument_list|(
name|oldsize
argument_list|)
expr_stmt|;
name|void
modifier|*
name|actualptr
init|=
name|oldptr
condition|?
cast|static_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|oldptr
argument_list|)
index|[
operator|-
literal|1
index|]
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|alignment
operator|<=
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
condition|)
block|{
comment|// special, fast case
name|void
modifier|*
modifier|*
name|newptr
init|=
cast|static_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|realloc
argument_list|(
name|actualptr
argument_list|,
name|newsize
operator|+
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|newptr
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|newptr
operator|==
name|actualptr
condition|)
block|{
comment|// realloc succeeded without reallocating
return|return
name|oldptr
return|;
block|}
operator|*
name|newptr
operator|=
name|newptr
expr_stmt|;
return|return
name|newptr
operator|+
literal|1
return|;
block|}
comment|// malloc returns pointers aligned at least at sizeof(size_t) boundaries
comment|// but usually more (8- or 16-byte boundaries).
comment|// So we overallocate by alignment-sizeof(size_t) bytes, so we're guaranteed to find a
comment|// somewhere within the first alignment-sizeof(size_t) that is properly aligned.
comment|// However, we need to store the actual pointer, so we need to allocate actually size +
comment|// alignment anyway.
name|void
modifier|*
name|real
init|=
name|realloc
argument_list|(
name|actualptr
argument_list|,
name|newsize
operator|+
name|alignment
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|real
condition|)
return|return
literal|0
return|;
name|quintptr
name|faked
init|=
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|real
argument_list|)
operator|+
name|alignment
decl_stmt|;
name|faked
operator|&=
operator|~
operator|(
name|alignment
operator|-
literal|1
operator|)
expr_stmt|;
name|void
modifier|*
modifier|*
name|faked_ptr
init|=
cast|reinterpret_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|faked
argument_list|)
decl_stmt|;
comment|// now save the value of the real pointer at faked-sizeof(void*)
comment|// by construction, alignment> sizeof(void*) and is a power of 2, so
comment|// faked-sizeof(void*) is properly aligned for a pointer
name|faked_ptr
index|[
operator|-
literal|1
index|]
operator|=
name|real
expr_stmt|;
return|return
name|faked_ptr
return|;
block|}
end_function
begin_function
DECL|function|qFreeAligned
name|void
name|qFreeAligned
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ptr
condition|)
return|return;
name|void
modifier|*
modifier|*
name|ptr2
init|=
cast|static_cast
argument_list|<
name|void
operator|*
operator|*
argument_list|>
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|ptr2
index|[
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
