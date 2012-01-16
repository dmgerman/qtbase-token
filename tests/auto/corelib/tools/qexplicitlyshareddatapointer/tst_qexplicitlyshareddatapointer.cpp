begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedData>
end_include
begin_comment
comment|/*!  \class tst_QExplicitlySharedDataPointer  \internal  \since 4.4  \brief Tests class QExplicitlySharedDataPointer.   */
end_comment
begin_class
DECL|class|tst_QExplicitlySharedDataPointer
class|class
name|tst_QExplicitlySharedDataPointer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|pointerOperatorOnConst
parameter_list|()
specifier|const
function_decl|;
name|void
name|pointerOperatorOnMutable
parameter_list|()
specifier|const
function_decl|;
name|void
name|copyConstructor
parameter_list|()
specifier|const
function_decl|;
name|void
name|clone
parameter_list|()
specifier|const
function_decl|;
name|void
name|data
parameter_list|()
specifier|const
function_decl|;
name|void
name|reset
parameter_list|()
specifier|const
function_decl|;
name|void
name|swap
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|mutating
name|void
name|mutating
parameter_list|()
block|{     }
DECL|function|notMutating
name|void
name|notMutating
parameter_list|()
specifier|const
block|{     }
DECL|function|operator =
name|MyClass
modifier|&
name|operator
name|=
parameter_list|(
specifier|const
name|MyClass
modifier|&
parameter_list|)
block|{
return|return
operator|*
name|this
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|Base
class|class
name|Base
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|~Base
specifier|virtual
name|~
name|Base
parameter_list|()
block|{ }
DECL|function|clone
specifier|virtual
name|Base
modifier|*
name|clone
parameter_list|()
block|{
return|return
operator|new
name|Base
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
DECL|function|isBase
specifier|virtual
name|bool
name|isBase
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|Derived
class|class
name|Derived
super|:
specifier|public
name|Base
block|{
public|public:
DECL|function|clone
specifier|virtual
name|Base
modifier|*
name|clone
parameter_list|()
block|{
return|return
operator|new
name|Derived
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
DECL|function|isBase
specifier|virtual
name|bool
name|isBase
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
block|}
class|;
end_class
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|clone
specifier|template
type|<>
name|Base
modifier|*
name|QExplicitlySharedDataPointer
argument_list|<
name|Base
argument_list|>
operator|::
name|clone
parameter_list|()
block|{
return|return
name|d
operator|->
name|clone
argument_list|()
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|pointerOperatorOnConst
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|pointerOperatorOnConst
parameter_list|()
specifier|const
block|{
comment|/* Pointer itself is const. */
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|->
name|notMutating
argument_list|()
expr_stmt|;
block|}
comment|/* Pointer itself is mutable. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|->
name|notMutating
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|pointerOperatorOnMutable
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|pointerOperatorOnMutable
parameter_list|()
specifier|const
block|{
comment|/* Pointer itself is const. */
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|->
name|notMutating
argument_list|()
expr_stmt|;
name|pointer
operator|->
name|mutating
argument_list|()
expr_stmt|;
operator|*
name|pointer
operator|=
name|MyClass
argument_list|()
expr_stmt|;
block|}
comment|/* Pointer itself is mutable. */
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|->
name|notMutating
argument_list|()
expr_stmt|;
name|pointer
operator|->
name|mutating
argument_list|()
expr_stmt|;
operator|*
name|pointer
operator|=
name|MyClass
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|copyConstructor
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|copyConstructor
parameter_list|()
specifier|const
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|copy
argument_list|(
name|pointer
argument_list|)
decl_stmt|;
block|}
end_function
begin_function
DECL|function|clone
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|clone
parameter_list|()
specifier|const
block|{
comment|/* holding a base element */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|Base
argument_list|>
name|pointer
argument_list|(
operator|new
name|Base
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|pointer
operator|->
name|isBase
argument_list|()
argument_list|)
expr_stmt|;
name|QExplicitlySharedDataPointer
argument_list|<
name|Base
argument_list|>
name|copy
argument_list|(
name|pointer
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|detach
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|pointer
operator|->
name|isBase
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/* holding a derived element */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|Base
argument_list|>
name|pointer
argument_list|(
operator|new
name|Derived
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointer
operator|->
name|isBase
argument_list|()
argument_list|)
expr_stmt|;
name|QExplicitlySharedDataPointer
argument_list|<
name|Base
argument_list|>
name|copy
argument_list|(
name|pointer
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|detach
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pointer
operator|->
name|isBase
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|data
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|data
parameter_list|()
specifier|const
block|{
comment|/* Check default value. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|MyClass
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* On const pointer. Must not mutate the pointer. */
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|data
argument_list|()
expr_stmt|;
comment|/* Check that this cast is possible. */
cast|static_cast
argument_list|<
specifier|const
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/* On mutatable pointer. Must not mutate the pointer. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
specifier|const
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|data
argument_list|()
expr_stmt|;
comment|/* Check that this cast is possible. */
cast|static_cast
argument_list|<
specifier|const
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/* Must not mutate the pointer. */
block|{
specifier|const
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|data
argument_list|()
expr_stmt|;
comment|/* Check that these casts are possible. */
cast|static_cast
argument_list|<
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
specifier|const
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/* Must not mutate the pointer. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|pointer
operator|.
name|data
argument_list|()
expr_stmt|;
comment|/* Check that these casts are possible. */
cast|static_cast
argument_list|<
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
specifier|const
name|MyClass
operator|*
argument_list|>
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|reset
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|reset
parameter_list|()
specifier|const
block|{
comment|/* Do reset on a single ref count. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|pointer
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|MyClass
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Do reset on a default constructed object. */
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|pointer
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|MyClass
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|pointer
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pointer
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|MyClass
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swap
name|void
name|tst_QExplicitlySharedDataPointer
operator|::
name|swap
parameter_list|()
specifier|const
block|{
name|QExplicitlySharedDataPointer
argument_list|<
name|MyClass
argument_list|>
name|p1
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|p2
argument_list|(
operator|new
name|MyClass
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p2
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|qSwap
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p2
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QExplicitlySharedDataPointer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qexplicitlyshareddatapointer.moc"
end_include
begin_comment
comment|// vim: et:ts=4:sw=4:sts=4
end_comment
end_unit
