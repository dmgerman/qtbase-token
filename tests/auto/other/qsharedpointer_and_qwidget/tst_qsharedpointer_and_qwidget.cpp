begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QPushButton>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QtSharedPointer
namespace|namespace
name|QtSharedPointer
block|{
name|Q_CORE_EXPORT
name|void
name|internalSafetyCheckCleanCheck
parameter_list|()
function_decl|;
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_class
DECL|class|tst_QSharedPointer_and_QWidget
class|class
name|tst_QSharedPointer_and_QWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|weak_externalDelete
parameter_list|()
function_decl|;
name|void
name|weak_parentDelete
parameter_list|()
function_decl|;
name|void
name|weak_parentDelete_setParent
parameter_list|()
function_decl|;
name|void
name|strong_weak
parameter_list|()
function_decl|;
name|void
name|strong_sharedptrDelete
parameter_list|()
function_decl|;
public|public
name|slots
public|:
DECL|function|cleanup
name|void
name|cleanup
parameter_list|()
block|{
name|safetyCheck
argument_list|()
expr_stmt|;
block|}
public|public:
DECL|function|safetyCheck
specifier|inline
name|void
name|safetyCheck
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
name|QtSharedPointer
operator|::
name|internalSafetyCheckCleanCheck
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
class|;
end_class
begin_function
DECL|function|weak_externalDelete
name|void
name|tst_QSharedPointer_and_QWidget
operator|::
name|weak_externalDelete
parameter_list|()
block|{
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|ptr
init|=
name|w
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|w
expr_stmt|;
name|QVERIFY
argument_list|(
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|weak_parentDelete
name|void
name|tst_QSharedPointer_and_QWidget
operator|::
name|weak_parentDelete
parameter_list|()
block|{
name|QWidget
modifier|*
name|parent
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|ptr
init|=
name|w
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
name|QVERIFY
argument_list|(
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|weak_parentDelete_setParent
name|void
name|tst_QSharedPointer_and_QWidget
operator|::
name|weak_parentDelete_setParent
parameter_list|()
block|{
name|QWidget
modifier|*
name|parent
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|ptr
init|=
name|w
decl_stmt|;
name|w
operator|->
name|setParent
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
name|QVERIFY
argument_list|(
name|ptr
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// -- mixed --
end_comment
begin_function
DECL|function|strong_weak
name|void
name|tst_QSharedPointer_and_QWidget
operator|::
name|strong_weak
parameter_list|()
block|{
name|QSharedPointer
argument_list|<
name|QWidget
argument_list|>
name|ptr
argument_list|(
operator|new
name|QWidget
argument_list|)
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|weak
init|=
name|ptr
operator|.
name|data
argument_list|()
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|weak2
init|=
name|ptr
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|weak
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|weak2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|ptr
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// deletes
name|QVERIFY
argument_list|(
name|weak
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|weak2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// ---- strong management ----
end_comment
begin_function
DECL|function|strong_sharedptrDelete
name|void
name|tst_QSharedPointer_and_QWidget
operator|::
name|strong_sharedptrDelete
parameter_list|()
block|{
name|QWidget
modifier|*
name|parent
init|=
operator|new
name|QWidget
decl_stmt|;
name|QSharedPointer
argument_list|<
name|QWidget
argument_list|>
name|ptr
argument_list|(
operator|new
name|QWidget
argument_list|(
name|parent
argument_list|)
argument_list|)
decl_stmt|;
name|QWeakPointer
argument_list|<
name|QWidget
argument_list|>
name|weak
init|=
name|ptr
decl_stmt|;
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|check
init|=
name|ptr
operator|.
name|data
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|check
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|weak
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|ptr
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// deletes
name|QVERIFY
argument_list|(
name|check
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|weak
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|parent
expr_stmt|;
comment|// mustn't crash
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSharedPointer_and_QWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsharedpointer_and_qwidget.moc"
end_include
end_unit
