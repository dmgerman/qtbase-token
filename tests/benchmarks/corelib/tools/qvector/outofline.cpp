begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"qrawvector.h"
end_include
begin_decl_stmt
DECL|variable|N
specifier|const
name|int
name|N
init|=
literal|1000000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|s
name|double
name|s
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qvector_fill_and_return_helper
name|QVector
argument_list|<
name|double
argument_list|>
name|qvector_fill_and_return_helper
parameter_list|()
block|{
name|QVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_function
DECL|function|qrawvector_fill_and_return_helper
name|QVector
argument_list|<
name|double
argument_list|>
name|qrawvector_fill_and_return_helper
parameter_list|()
block|{
name|QRawVector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
return|return
name|v
operator|.
name|mutateToVector
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|mixedvector_fill_and_return_helper
name|QVector
argument_list|<
name|double
argument_list|>
name|mixedvector_fill_and_return_helper
parameter_list|()
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
return|return
name|QVector
argument_list|<
name|double
argument_list|>
operator|::
name|fromStdVector
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|stdvector_fill_and_return_helper
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|stdvector_fill_and_return_helper
parameter_list|()
block|{
name|std
operator|::
name|vector
argument_list|<
name|double
argument_list|>
name|v
argument_list|(
name|N
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|v
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_decl_stmt
DECL|member|shared_null
specifier|const
name|QVectorData
name|QVectorData
operator|::
name|shared_null
init|=
block|{
name|Q_REFCOUNT_INITIALIZE_STATIC
block|,
literal|0
block|,
literal|0
block|,
literal|false
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|alignmentThreshold
specifier|static
specifier|inline
name|int
name|alignmentThreshold
parameter_list|()
block|{
comment|// malloc on 32-bit platforms should return pointers that are 8-byte aligned or more
comment|// while on 64-bit platforms they should be 16-byte aligned or more
return|return
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|allocate
name|QVectorData
modifier|*
name|QVectorData
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
name|QVectorData
operator|*
argument_list|>
argument_list|(
name|alignment
operator|>
name|alignmentThreshold
argument_list|()
condition|?
name|qMallocAligned
argument_list|(
name|size
argument_list|,
name|alignment
argument_list|)
else|:
operator|::
name|malloc
argument_list|(
name|size
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|reallocate
name|QVectorData
modifier|*
name|QVectorData
operator|::
name|reallocate
parameter_list|(
name|QVectorData
modifier|*
name|x
parameter_list|,
name|int
name|newsize
parameter_list|,
name|int
name|oldsize
parameter_list|,
name|int
name|alignment
parameter_list|)
block|{
if|if
condition|(
name|alignment
operator|>
name|alignmentThreshold
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QVectorData
operator|*
argument_list|>
argument_list|(
name|qReallocAligned
argument_list|(
name|x
argument_list|,
name|newsize
argument_list|,
name|oldsize
argument_list|,
name|alignment
argument_list|)
argument_list|)
return|;
return|return
cast|static_cast
argument_list|<
name|QVectorData
operator|*
argument_list|>
argument_list|(
name|realloc
argument_list|(
name|x
argument_list|,
name|newsize
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|free
name|void
name|QVectorData
operator|::
name|free
parameter_list|(
name|QVectorData
modifier|*
name|x
parameter_list|,
name|int
name|alignment
parameter_list|)
block|{
if|if
condition|(
name|alignment
operator|>
name|alignmentThreshold
argument_list|()
condition|)
name|qFreeAligned
argument_list|(
name|x
argument_list|)
expr_stmt|;
else|else
operator|::
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grow
name|int
name|QVectorData
operator|::
name|grow
parameter_list|(
name|int
name|sizeOfHeader
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|sizeOfT
parameter_list|)
block|{
return|return
name|qCalculateGrowingBlockSize
argument_list|(
name|size
argument_list|,
name|sizeOfT
argument_list|,
name|sizeOfHeader
argument_list|)
operator|.
name|elementCount
return|;
block|}
end_function
end_unit
