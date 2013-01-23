begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QPointer
class|class
name|tst_QPointer
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|me
specifier|inline
name|tst_QPointer
modifier|*
name|me
parameter_list|()
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|tst_QPointer
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
block|}
private|private
name|slots
private|:
name|void
name|constructors
parameter_list|()
function_decl|;
name|void
name|destructor
parameter_list|()
function_decl|;
name|void
name|assignment_operators
parameter_list|()
function_decl|;
name|void
name|equality_operators
parameter_list|()
function_decl|;
name|void
name|isNull
parameter_list|()
function_decl|;
name|void
name|dereference_operators
parameter_list|()
function_decl|;
name|void
name|disconnect
parameter_list|()
function_decl|;
name|void
name|castDuringDestruction
parameter_list|()
function_decl|;
name|void
name|threadSafety
parameter_list|()
function_decl|;
name|void
name|qvariantCast
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|constructors
name|void
name|tst_QPointer
operator|::
name|constructors
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p2
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p3
argument_list|(
name|p2
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p3
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destructor
name|void
name|tst_QPointer
operator|::
name|destructor
parameter_list|()
block|{
comment|// Make two QPointer's to the same object
name|QObject
modifier|*
name|object
init|=
operator|new
name|QObject
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
init|=
name|object
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p2
init|=
name|object
decl_stmt|;
comment|// Check that they point to the correct object
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
expr_stmt|;
comment|// Destroy the guarded object
operator|delete
name|object
expr_stmt|;
comment|// Check that both pointers were zeroed
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|assignment_operators
name|void
name|tst_QPointer
operator|::
name|assignment_operators
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p2
decl_stmt|;
comment|// Test assignment with a QObject-derived object pointer
name|p1
operator|=
name|this
expr_stmt|;
name|p2
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|p2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Test assignment with a null pointer
name|p1
operator|=
literal|0
expr_stmt|;
name|p2
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|p2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Test assignment with a real QObject pointer
name|QObject
modifier|*
name|object
init|=
operator|new
name|QObject
decl_stmt|;
name|p1
operator|=
name|object
expr_stmt|;
name|p2
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|p2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Test assignment with the same pointer that's already guarded
name|p1
operator|=
name|object
expr_stmt|;
name|p2
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|object
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
argument_list|,
name|QPointer
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|p2
argument_list|)
argument_list|)
expr_stmt|;
comment|// Cleanup
operator|delete
name|object
expr_stmt|;
block|}
end_function
begin_function
DECL|function|equality_operators
name|void
name|tst_QPointer
operator|::
name|equality_operators
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p2
decl_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
name|p2
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|object
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
name|QWidget
modifier|*
name|widget
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
name|p1
operator|=
name|object
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
name|p2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
name|object
argument_list|)
expr_stmt|;
name|p2
operator|=
name|object
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|==
name|p1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|==
name|object
argument_list|)
expr_stmt|;
name|p1
operator|=
name|this
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|!=
name|p2
argument_list|)
expr_stmt|;
name|p2
operator|=
name|p1
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
name|p2
argument_list|)
expr_stmt|;
comment|// compare to zero
name|p1
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|0
operator|==
name|p1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
literal|0
operator|!=
name|p2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|==
name|object
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|==
name|p1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|!=
name|object
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|!=
name|p2
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
name|QVERIFY
argument_list|(
name|p1
operator|==
name|widget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|==
name|p1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p2
operator|!=
name|widget
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|!=
name|p2
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isNull
name|void
name|tst_QPointer
operator|::
name|isNull
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
decl_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|=
name|this
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|=
literal|0
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dereference_operators
name|void
name|tst_QPointer
operator|::
name|dereference_operators
parameter_list|()
block|{
name|QPointer
argument_list|<
name|tst_QPointer
argument_list|>
name|p1
init|=
name|this
decl_stmt|;
name|QPointer
argument_list|<
name|tst_QPointer
argument_list|>
name|p2
decl_stmt|;
comment|// operator->() -- only makes sense if not null
name|QObject
modifier|*
name|object
init|=
name|p1
operator|->
name|me
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|object
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// operator*() -- only makes sense if not null
name|QObject
modifier|&
name|ref
init|=
operator|*
name|p1
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|&
name|ref
argument_list|,
name|this
argument_list|)
expr_stmt|;
comment|// operator T*()
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|p1
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|p2
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// data()
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|data
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|data
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|disconnect
name|void
name|tst_QPointer
operator|::
name|disconnect
parameter_list|()
block|{
comment|// Verify that pointer remains guarded when all signals are disconencted.
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|p1
init|=
operator|new
name|QObject
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|p1
operator|->
name|disconnect
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|p1
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ChildObject
class|class
name|ChildObject
super|:
specifier|public
name|QObject
block|{
DECL|member|guardedPointer
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|guardedPointer
decl_stmt|;
public|public:
DECL|function|ChildObject
name|ChildObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|guardedPointer
argument_list|(
name|parent
argument_list|)
block|{ }
name|~
name|ChildObject
parameter_list|()
destructor_decl|;
block|}
class|;
end_class
begin_destructor
DECL|function|~ChildObject
name|ChildObject
operator|::
name|~
name|ChildObject
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|guardedPointer
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qobject_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|guardedPointer
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_class
DECL|class|ChildWidget
class|class
name|ChildWidget
super|:
specifier|public
name|QWidget
block|{
DECL|member|guardedPointer
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|guardedPointer
decl_stmt|;
public|public:
DECL|function|ChildWidget
name|ChildWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|guardedPointer
argument_list|(
name|parent
argument_list|)
block|{ }
name|~
name|ChildWidget
parameter_list|()
destructor_decl|;
block|}
class|;
end_class
begin_destructor
DECL|function|~ChildWidget
name|ChildWidget
operator|::
name|~
name|ChildWidget
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|guardedPointer
argument_list|)
argument_list|,
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|guardedPointer
argument_list|)
argument_list|,
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_endif
endif|#
directive|endif
end_endif
begin_class_decl
class_decl|class
name|DerivedChild
class_decl|;
end_class_decl
begin_class
DECL|class|DerivedParent
class|class
name|DerivedParent
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|derivedChild
name|DerivedChild
modifier|*
name|derivedChild
decl_stmt|;
public|public:
name|DerivedParent
parameter_list|()
constructor_decl|;
name|~
name|DerivedParent
parameter_list|()
destructor_decl|;
block|}
class|;
end_class
begin_class
DECL|class|DerivedChild
class|class
name|DerivedChild
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|parentPointer
name|DerivedParent
modifier|*
name|parentPointer
decl_stmt|;
DECL|member|guardedParentPointer
name|QPointer
argument_list|<
name|DerivedParent
argument_list|>
name|guardedParentPointer
decl_stmt|;
public|public:
DECL|function|DerivedChild
name|DerivedChild
parameter_list|(
name|DerivedParent
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|parentPointer
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|guardedParentPointer
argument_list|(
name|parent
argument_list|)
block|{ }
name|~
name|DerivedChild
parameter_list|()
destructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|DerivedParent
name|DerivedParent
operator|::
name|DerivedParent
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{
name|derivedChild
operator|=
operator|new
name|DerivedChild
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DerivedParent
name|DerivedParent
operator|::
name|~
name|DerivedParent
parameter_list|()
block|{
operator|delete
name|derivedChild
expr_stmt|;
block|}
end_destructor
begin_destructor
DECL|function|~DerivedChild
name|DerivedChild
operator|::
name|~
name|DerivedChild
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
cast|static_cast
argument_list|<
name|DerivedParent
operator|*
argument_list|>
argument_list|(
name|guardedParentPointer
argument_list|)
argument_list|,
name|parentPointer
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qobject_cast
argument_list|<
name|DerivedParent
operator|*
argument_list|>
argument_list|(
name|guardedParentPointer
argument_list|)
argument_list|,
name|parentPointer
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|castDuringDestruction
name|void
name|tst_QPointer
operator|::
name|castDuringDestruction
parameter_list|()
block|{
block|{
name|QObject
modifier|*
name|parentObject
init|=
operator|new
name|QObject
argument_list|()
decl_stmt|;
operator|(
name|void
operator|)
operator|new
name|ChildObject
argument_list|(
name|parentObject
argument_list|)
expr_stmt|;
operator|delete
name|parentObject
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
block|{
name|QWidget
modifier|*
name|parentWidget
init|=
operator|new
name|QWidget
argument_list|()
decl_stmt|;
operator|(
name|void
operator|)
operator|new
name|ChildWidget
argument_list|(
name|parentWidget
argument_list|)
expr_stmt|;
operator|delete
name|parentWidget
expr_stmt|;
block|}
endif|#
directive|endif
block|{
operator|delete
operator|new
name|DerivedParent
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|TestRunnable
class|class
name|TestRunnable
super|:
specifier|public
name|QObject
super|,
specifier|public
name|QRunnable
block|{
DECL|function|run
name|void
name|run
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|obj1
init|=
operator|new
name|QObject
decl_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|obj2
init|=
operator|new
name|QObject
decl_stmt|;
name|obj1
operator|->
name|moveToThread
argument_list|(
name|thread
argument_list|()
argument_list|)
expr_stmt|;
comment|// this is the owner thread
name|obj1
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
comment|// the delete will happen in the owner thread
name|obj2
operator|->
name|moveToThread
argument_list|(
name|thread
argument_list|()
argument_list|)
expr_stmt|;
comment|// this is the owner thread
name|obj2
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
comment|// the delete will happen in the owner thread
block|}
block|}
class|;
end_class
begin_function
DECL|function|threadSafety
name|void
name|tst_QPointer
operator|::
name|threadSafety
parameter_list|()
block|{
name|QThread
name|owner
decl_stmt|;
name|owner
operator|.
name|start
argument_list|()
expr_stmt|;
name|QThreadPool
name|pool
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
literal|300
condition|;
name|i
operator|++
control|)
block|{
name|QPointer
argument_list|<
name|TestRunnable
argument_list|>
name|task
init|=
operator|new
name|TestRunnable
decl_stmt|;
name|task
operator|->
name|setAutoDelete
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|task
operator|->
name|moveToThread
argument_list|(
operator|&
name|owner
argument_list|)
expr_stmt|;
name|pool
operator|.
name|start
argument_list|(
name|task
argument_list|)
expr_stmt|;
block|}
name|pool
operator|.
name|waitForDone
argument_list|()
expr_stmt|;
name|owner
operator|.
name|quit
argument_list|()
expr_stmt|;
name|owner
operator|.
name|wait
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qvariantCast
name|void
name|tst_QPointer
operator|::
name|qvariantCast
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QFile
argument_list|>
name|tracking
init|=
operator|new
name|QFile
decl_stmt|;
name|tracking
operator|->
name|setObjectName
argument_list|(
literal|"A test name"
argument_list|)
expr_stmt|;
name|QVariant
name|v
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|tracking
argument_list|)
decl_stmt|;
block|{
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|other
init|=
name|qPointerFromVariant
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|other
operator|->
name|objectName
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A test name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QPointer
argument_list|<
name|QIODevice
argument_list|>
name|other
init|=
name|qPointerFromVariant
argument_list|<
name|QIODevice
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|other
operator|->
name|objectName
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A test name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QPointer
argument_list|<
name|QFile
argument_list|>
name|other
init|=
name|qPointerFromVariant
argument_list|<
name|QFile
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|other
operator|->
name|objectName
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"A test name"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QPointer
argument_list|<
name|QThread
argument_list|>
name|other
init|=
name|qPointerFromVariant
argument_list|<
name|QThread
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|other
argument_list|)
expr_stmt|;
block|}
block|{
name|QPointer
argument_list|<
name|QFile
argument_list|>
name|toBeDeleted
init|=
operator|new
name|QFile
decl_stmt|;
name|QVariant
name|deletedVariant
init|=
name|QVariant
operator|::
name|fromValue
argument_list|(
name|toBeDeleted
argument_list|)
decl_stmt|;
operator|delete
name|toBeDeleted
expr_stmt|;
name|QPointer
argument_list|<
name|QObject
argument_list|>
name|deleted
init|=
name|qPointerFromVariant
argument_list|<
name|QObject
argument_list|>
argument_list|(
name|deletedVariant
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|deleted
argument_list|)
expr_stmt|;
block|}
comment|// Intentionally does not compile.
comment|//     QPointer<int> sop = qPointerFromVariant<int>(v);
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPointer
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpointer.moc"
end_include
end_unit
