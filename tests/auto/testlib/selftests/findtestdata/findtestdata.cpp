begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_define
DECL|macro|TESTFILE
define|#
directive|define
name|TESTFILE
value|"testfile"
end_define
begin_class
DECL|class|FindTestData
class|class
name|FindTestData
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|paths
parameter_list|()
function_decl|;
private|private:
name|bool
name|touch
parameter_list|(
name|QString
specifier|const
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|FindTestData
operator|::
name|initTestCase
parameter_list|()
block|{
comment|// verify that our qt.conf is working as expected.
name|QString
name|app_path
init|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
decl_stmt|;
name|QString
name|install_path
init|=
name|app_path
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|+
literal|"/Contents"
endif|#
directive|endif
operator|+
literal|"/tests"
decl_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|mkpath
argument_list|(
name|install_path
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|mkpath
argument_list|(
name|install_path
operator|+
literal|"/findtestdata"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|QLibraryInfo
operator|::
name|TestsPath
argument_list|)
argument_list|,
name|install_path
argument_list|)
expr_stmt|;
comment|// make fake source and build directories
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|mkpath
argument_list|(
name|app_path
operator|+
literal|"/fakesrc"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|mkpath
argument_list|(
name|app_path
operator|+
literal|"/fakebuild"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|FindTestData
operator|::
name|cleanupTestCase
parameter_list|()
block|{
name|QString
name|app_path
init|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
decl_stmt|;
name|QFile
argument_list|(
name|app_path
operator|+
literal|"/tests/findtestdata/"
name|TESTFILE
argument_list|)
operator|.
name|remove
argument_list|()
expr_stmt|;
name|QFile
argument_list|(
name|app_path
operator|+
literal|"/tests/"
name|TESTFILE
argument_list|)
operator|.
name|remove
argument_list|()
expr_stmt|;
name|QFile
argument_list|(
name|app_path
operator|+
literal|"/fakesrc/"
name|TESTFILE
argument_list|)
operator|.
name|remove
argument_list|()
expr_stmt|;
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|rmpath
argument_list|(
name|app_path
operator|+
literal|"/tests/findtestdata"
argument_list|)
expr_stmt|;
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|rmpath
argument_list|(
name|app_path
operator|+
literal|"/fakesrc"
argument_list|)
expr_stmt|;
name|QDir
argument_list|(
literal|"/"
argument_list|)
operator|.
name|rmpath
argument_list|(
name|app_path
operator|+
literal|"/fakebuild"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Create an empty file at the specified path (or return false)
end_comment
begin_function
DECL|function|touch
name|bool
name|FindTestData
operator|::
name|touch
parameter_list|(
name|QString
specifier|const
modifier|&
name|path
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to create %s: %s"
argument_list|,
name|qPrintable
argument_list|(
name|path
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|paths
name|void
name|FindTestData
operator|::
name|paths
parameter_list|()
block|{
comment|// There are three possible locations for the testdata.
comment|// In this test, we will put the testdata at all three locations,
comment|// then remove it from one location at a time and verify that
comment|// QFINDTESTDATA correctly falls back each time.
comment|// 1. relative to test binary.
name|QString
name|app_path
init|=
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
decl_stmt|;
name|QString
name|testfile_path1
init|=
name|app_path
operator|+
literal|"/"
name|TESTFILE
decl_stmt|;
name|QVERIFY
argument_list|(
name|touch
argument_list|(
name|testfile_path1
argument_list|)
argument_list|)
expr_stmt|;
comment|// 2. at the test install path (faked via qt.conf)
name|QString
name|testfile_path2
init|=
name|app_path
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|+
literal|"/Contents"
endif|#
directive|endif
operator|+
literal|"/tests/findtestdata/"
name|TESTFILE
decl_stmt|;
name|QVERIFY
argument_list|(
name|touch
argument_list|(
name|testfile_path2
argument_list|)
argument_list|)
expr_stmt|;
comment|// 3. at the source path (which we will fake later on)
name|QString
name|testfile_path3
init|=
name|app_path
operator|+
literal|"/fakesrc/"
name|TESTFILE
decl_stmt|;
name|QVERIFY
argument_list|(
name|touch
argument_list|(
name|testfile_path3
argument_list|)
argument_list|)
expr_stmt|;
comment|// OK, all testdata created.  Verify that they are found in correct priority order.
name|QCOMPARE
argument_list|(
name|QFINDTESTDATA
argument_list|(
name|TESTFILE
argument_list|)
argument_list|,
name|testfile_path1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFile
argument_list|(
name|testfile_path1
argument_list|)
operator|.
name|remove
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QFINDTESTDATA
argument_list|(
name|TESTFILE
argument_list|)
argument_list|,
name|testfile_path2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFile
argument_list|(
name|testfile_path2
argument_list|)
operator|.
name|remove
argument_list|()
argument_list|)
expr_stmt|;
comment|// We cannot reasonably redefine __FILE__, so we call the underlying function instead.
comment|// __FILE__ may be absolute or relative path; test both.
comment|// absolute:
name|QCOMPARE
argument_list|(
name|QTest
operator|::
name|qFindTestData
argument_list|(
name|TESTFILE
argument_list|,
name|qPrintable
argument_list|(
name|app_path
operator|+
literal|"/fakesrc/fakefile.cpp"
argument_list|)
argument_list|,
name|__LINE__
argument_list|)
argument_list|,
name|testfile_path3
argument_list|)
expr_stmt|;
comment|// relative: (pretend that we were compiled within fakebuild directory, pointing at files in ../fakesrc)
name|QCOMPARE
argument_list|(
name|QTest
operator|::
name|qFindTestData
argument_list|(
name|TESTFILE
argument_list|,
literal|"../fakesrc/fakefile.cpp"
argument_list|,
name|__LINE__
argument_list|,
name|qPrintable
argument_list|(
name|app_path
operator|+
literal|"/fakebuild"
argument_list|)
argument_list|)
argument_list|,
name|testfile_path3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QFile
argument_list|(
name|testfile_path3
argument_list|)
operator|.
name|remove
argument_list|()
argument_list|)
expr_stmt|;
comment|// Note, this is expected to generate a warning.
comment|// We can't use ignoreMessage, because the warning comes from testlib,
comment|// not via a "normal" qWarning.  But it's OK, our caller (tst_selftests)
comment|// will verify that the warning is printed.
name|QCOMPARE
argument_list|(
name|QFINDTESTDATA
argument_list|(
name|TESTFILE
argument_list|)
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|FindTestData
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"findtestdata.moc"
end_include
end_unit
