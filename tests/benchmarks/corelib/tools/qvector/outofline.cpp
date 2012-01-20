begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
end_unit
