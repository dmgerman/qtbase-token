begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdesktopservices.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_qdesktopservices
class|class
name|tst_qdesktopservices
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_qdesktopservices
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_qdesktopservices
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|openUrl
parameter_list|()
function_decl|;
name|void
name|handlers
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_qdesktopservices
name|tst_qdesktopservices
operator|::
name|tst_qdesktopservices
parameter_list|()
block|{
name|QCoreApplication
operator|::
name|setOrganizationName
argument_list|(
literal|"Nokia"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
literal|"tst_qdesktopservices"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~tst_qdesktopservices
name|tst_qdesktopservices
operator|::
name|~
name|tst_qdesktopservices
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_qdesktopservices
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_qdesktopservices
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|openUrl
name|void
name|tst_qdesktopservices
operator|::
name|openUrl
parameter_list|()
block|{
comment|// At the bare minimum check that they return false for invalid url's
name|QCOMPARE
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|()
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
comment|// this test is only valid on windows on other systems it might mean open a new document in the application handling .file
name|QCOMPARE
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|(
literal|"file://invalid.file"
argument_list|)
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_class
DECL|class|MyUrlHandler
class|class
name|MyUrlHandler
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|lastHandledUrl
name|QUrl
name|lastHandledUrl
decl_stmt|;
public|public
name|slots
public|:
DECL|function|handle
specifier|inline
name|void
name|handle
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|lastHandledUrl
operator|=
name|url
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|handlers
name|void
name|tst_qdesktopservices
operator|::
name|handlers
parameter_list|()
block|{
name|MyUrlHandler
name|fooHandler
decl_stmt|;
name|MyUrlHandler
name|barHandler
decl_stmt|;
name|QDesktopServices
operator|::
name|setUrlHandler
argument_list|(
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|,
operator|&
name|fooHandler
argument_list|,
literal|"handle"
argument_list|)
expr_stmt|;
name|QDesktopServices
operator|::
name|setUrlHandler
argument_list|(
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|,
operator|&
name|barHandler
argument_list|,
literal|"handle"
argument_list|)
expr_stmt|;
name|QUrl
name|fooUrl
argument_list|(
literal|"foo://blub/meh"
argument_list|)
decl_stmt|;
name|QUrl
name|barUrl
argument_list|(
literal|"bar://hmm/hmmmm"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|fooUrl
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|barUrl
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fooHandler
operator|.
name|lastHandledUrl
operator|.
name|toString
argument_list|()
argument_list|,
name|fooUrl
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|barHandler
operator|.
name|lastHandledUrl
operator|.
name|toString
argument_list|()
argument_list|,
name|barUrl
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qdesktopservices
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdesktopservices.moc"
end_include
end_unit
