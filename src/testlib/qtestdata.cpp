begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestdata.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qtesttable_p.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTestDataPrivate
class|class
name|QTestDataPrivate
block|{
public|public:
DECL|function|QTestDataPrivate
name|QTestDataPrivate
parameter_list|()
member_init_list|:
name|tag
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|parent
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|dataCount
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|tag
name|char
modifier|*
name|tag
decl_stmt|;
DECL|member|parent
name|QTestTable
modifier|*
name|parent
decl_stmt|;
DECL|member|data
name|void
modifier|*
modifier|*
name|data
decl_stmt|;
DECL|member|dataCount
name|int
name|dataCount
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTestData
name|QTestData
operator|::
name|QTestData
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|,
name|QTestTable
modifier|*
name|parent
parameter_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|QTestDataPrivate
expr_stmt|;
name|d
operator|->
name|tag
operator|=
name|qstrdup
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|d
operator|->
name|parent
operator|=
name|parent
expr_stmt|;
name|d
operator|->
name|data
operator|=
operator|new
name|void
operator|*
index|[
name|parent
operator|->
name|elementCount
argument_list|()
index|]
expr_stmt|;
name|memset
argument_list|(
name|d
operator|->
name|data
argument_list|,
literal|0
argument_list|,
name|parent
operator|->
name|elementCount
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QTestData
name|QTestData
operator|::
name|~
name|QTestData
parameter_list|()
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
name|d
operator|->
name|dataCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|d
operator|->
name|data
index|[
name|i
index|]
condition|)
name|QMetaType
operator|::
name|destroy
argument_list|(
name|d
operator|->
name|parent
operator|->
name|elementTypeId
argument_list|(
name|i
argument_list|)
argument_list|,
name|d
operator|->
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
operator|delete
index|[]
name|d
operator|->
name|data
expr_stmt|;
operator|delete
index|[]
name|d
operator|->
name|tag
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|append
name|void
name|QTestData
operator|::
name|append
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|d
operator|->
name|dataCount
operator|<
name|d
operator|->
name|parent
operator|->
name|elementCount
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|parent
operator|->
name|elementTypeId
argument_list|(
name|d
operator|->
name|dataCount
argument_list|)
operator|!=
name|type
condition|)
block|{
name|qDebug
argument_list|(
literal|"expected data of type '%s', got '%s' for element %d of data with tag '%s'"
argument_list|,
name|QMetaType
operator|::
name|typeName
argument_list|(
name|d
operator|->
name|parent
operator|->
name|elementTypeId
argument_list|(
name|d
operator|->
name|dataCount
argument_list|)
argument_list|)
argument_list|,
name|QMetaType
operator|::
name|typeName
argument_list|(
name|type
argument_list|)
argument_list|,
name|d
operator|->
name|dataCount
argument_list|,
name|d
operator|->
name|tag
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|data
index|[
name|d
operator|->
name|dataCount
index|]
operator|=
name|QMetaType
operator|::
name|create
argument_list|(
name|type
argument_list|,
name|data
argument_list|)
expr_stmt|;
operator|++
name|d
operator|->
name|dataCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|data
name|void
modifier|*
name|QTestData
operator|::
name|data
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|QTEST_ASSERT
argument_list|(
name|index
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|QTEST_ASSERT
argument_list|(
name|index
operator|<
name|d
operator|->
name|parent
operator|->
name|elementCount
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|data
index|[
name|index
index|]
return|;
block|}
end_function
begin_function
DECL|function|parent
name|QTestTable
modifier|*
name|QTestData
operator|::
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|parent
return|;
block|}
end_function
begin_function
DECL|function|dataTag
specifier|const
name|char
modifier|*
name|QTestData
operator|::
name|dataTag
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|tag
return|;
block|}
end_function
begin_function
DECL|function|dataCount
name|int
name|QTestData
operator|::
name|dataCount
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|dataCount
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
