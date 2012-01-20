begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTELEMENTATTRIBUTE_P_H
end_ifndef
begin_define
DECL|macro|QTESTELEMENTATTRIBUTE_P_H
define|#
directive|define
name|QTESTELEMENTATTRIBUTE_P_H
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
file|<QtTest/private/qtestcorelist_p.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Test
parameter_list|)
name|namespace
name|QTest
decl_stmt|{      enum AttributeIndex
block|{
name|AI_Undefined
operator|=
operator|-
literal|1
operator|,
name|AI_Name
operator|=
literal|0
operator|,
name|AI_Result
operator|=
literal|1
operator|,
name|AI_Tests
operator|=
literal|2
operator|,
name|AI_Failures
operator|=
literal|3
operator|,
name|AI_Errors
operator|=
literal|4
operator|,
name|AI_Type
operator|=
literal|5
operator|,
name|AI_Description
operator|=
literal|6
operator|,
name|AI_PropertyValue
operator|=
literal|7
operator|,
name|AI_QTestVersion
operator|=
literal|8
operator|,
name|AI_QtVersion
operator|=
literal|9
operator|,
name|AI_File
operator|=
literal|10
operator|,
name|AI_Line
operator|=
literal|11
operator|,
name|AI_Metric
operator|=
literal|12
operator|,
name|AI_Tag
operator|=
literal|13
operator|,
name|AI_Value
operator|=
literal|14
operator|,
name|AI_Iterations
operator|=
literal|15
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|LogElementType
block|{
name|LET_Undefined
init|=
operator|-
literal|1
block|,
name|LET_Property
init|=
literal|0
block|,
name|LET_Properties
init|=
literal|1
block|,
name|LET_Failure
init|=
literal|2
block|,
name|LET_Error
init|=
literal|3
block|,
name|LET_TestCase
init|=
literal|4
block|,
name|LET_TestSuite
init|=
literal|5
block|,
name|LET_Benchmark
init|=
literal|6
block|,
name|LET_SystemError
init|=
literal|7
block|}
enum|;
end_enum
begin_label
unit|}  class
name|QTestElementAttribute
label|:
end_label
begin_expr_stmt
name|public
name|QTestCoreList
operator|<
name|QTestElementAttribute
operator|>
block|{
name|public
operator|:
name|QTestElementAttribute
argument_list|()
block|;
operator|~
name|QTestElementAttribute
argument_list|()
block|;
specifier|const
name|char
operator|*
name|value
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|;
name|QTest
operator|::
name|AttributeIndex
name|index
argument_list|()
specifier|const
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|bool
name|setPair
argument_list|(
argument|QTest::AttributeIndex attributeIndex
argument_list|,
argument|const char *value
argument_list|)
block|;
name|private
operator|:
name|char
operator|*
name|attributeValue
block|;
name|QTest
operator|::
name|AttributeIndex
name|attributeIndex
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
