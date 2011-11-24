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
file|<qstandardpaths.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qstandardpaths.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_define
DECL|macro|Q_XDG_PLATFORM
define|#
directive|define
name|Q_XDG_PLATFORM
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//TESTED_CLASS=QStandardPaths
end_comment
begin_comment
comment|//TESTED_FILES=qstandardpaths.cpp
end_comment
begin_class
DECL|class|tst_qstandardpaths
class|class
name|tst_qstandardpaths
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testDefaultLocations
parameter_list|()
function_decl|;
name|void
name|testCustomLocations
parameter_list|()
function_decl|;
name|void
name|testLocateAll
parameter_list|()
function_decl|;
name|void
name|testDataLocation
parameter_list|()
function_decl|;
name|void
name|testFindExecutable
parameter_list|()
function_decl|;
name|void
name|testRuntimeDirectory
parameter_list|()
function_decl|;
name|void
name|testCustomRuntimeDirectory
parameter_list|()
function_decl|;
name|void
name|testAllWritableLocations_data
parameter_list|()
function_decl|;
name|void
name|testAllWritableLocations
parameter_list|()
function_decl|;
private|private:
DECL|function|setCustomLocations
name|void
name|setCustomLocations
parameter_list|()
block|{
name|m_thisDir
operator|=
name|QFileInfo
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"tst_qstandardpaths.cpp"
argument_list|)
argument_list|)
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
name|qputenv
argument_list|(
literal|"XDG_CONFIG_HOME"
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|m_thisDir
argument_list|)
argument_list|)
expr_stmt|;
name|QDir
name|parent
argument_list|(
name|m_thisDir
argument_list|)
decl_stmt|;
name|parent
operator|.
name|cdUp
argument_list|()
expr_stmt|;
name|m_globalDir
operator|=
name|parent
operator|.
name|path
argument_list|()
expr_stmt|;
comment|// gives us a trailing slash
name|qputenv
argument_list|(
literal|"XDG_CONFIG_DIRS"
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
name|m_globalDir
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|member|m_thisDir
name|QString
name|m_thisDir
decl_stmt|;
DECL|member|m_globalDir
name|QString
name|m_globalDir
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|testDefaultLocations
name|void
name|tst_qstandardpaths
operator|::
name|testDefaultLocations
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|qputenv
argument_list|(
literal|"XDG_CONFIG_HOME"
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|qputenv
argument_list|(
literal|"XDG_CONFIG_DIRS"
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|expectedConfHome
init|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/.config"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|)
argument_list|,
name|expectedConfHome
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|confDirs
init|=
name|QStandardPaths
operator|::
name|standardLocations
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|confDirs
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|confDirs
operator|.
name|contains
argument_list|(
name|expectedConfHome
argument_list|)
argument_list|)
expr_stmt|;
name|qputenv
argument_list|(
literal|"XDG_DATA_HOME"
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|qputenv
argument_list|(
literal|"XDG_DATA_DIRS"
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|genericDataDirs
init|=
name|QStandardPaths
operator|::
name|standardLocations
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|genericDataDirs
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|expectedDataHome
init|=
name|QDir
operator|::
name|homePath
argument_list|()
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/.local/share"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|genericDataDirs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|expectedDataHome
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|genericDataDirs
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/usr/local/share"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|genericDataDirs
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/usr/share"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testCustomLocations
name|void
name|tst_qstandardpaths
operator|::
name|testCustomLocations
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|setCustomLocations
argument_list|()
expr_stmt|;
comment|// test writableLocation()
name|QCOMPARE
argument_list|(
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|)
argument_list|,
name|m_thisDir
argument_list|)
expr_stmt|;
name|QString
name|thisDir_base
init|=
name|QFileInfo
argument_list|(
name|m_thisDir
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
comment|// test locate()
specifier|const
name|QString
name|thisFileName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"tst_qstandardpaths.cpp"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|QFile
operator|::
name|exists
argument_list|(
name|m_thisDir
operator|+
literal|'/'
operator|+
name|thisFileName
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|thisFile
init|=
name|QStandardPaths
operator|::
name|locate
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|,
name|thisFileName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|thisFile
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|thisFile
operator|.
name|endsWith
argument_list|(
name|thisFileName
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|dir
init|=
name|QStandardPaths
operator|::
name|locate
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"../"
argument_list|)
operator|+
name|thisDir_base
argument_list|,
name|QStandardPaths
operator|::
name|LocateDirectory
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|dir
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|thisDirAsFile
init|=
name|QStandardPaths
operator|::
name|locate
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"../"
argument_list|)
operator|+
name|thisDir_base
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|thisDirAsFile
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// not a file
specifier|const
name|QStringList
name|dirs
init|=
name|QStandardPaths
operator|::
name|standardLocations
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|dirs
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|m_thisDir
operator|<<
name|m_globalDir
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// We really need QTemporaryDir for this test...
end_comment
begin_function
DECL|function|testLocateAll
name|void
name|tst_qstandardpaths
operator|::
name|testLocateAll
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
specifier|const
name|QStringList
name|appsDirs
init|=
name|QStandardPaths
operator|::
name|locateAll
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|,
literal|"applications"
argument_list|,
name|QStandardPaths
operator|::
name|LocateDirectory
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|dir
decl|,
name|appsDirs
control|)
name|QVERIFY2
argument_list|(
name|dir
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/share/applications"
argument_list|)
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|dir
argument_list|)
argument_list|)
expr_stmt|;
name|setCustomLocations
argument_list|()
expr_stmt|;
specifier|const
name|QStringList
name|allFiles
init|=
name|QStandardPaths
operator|::
name|locateAll
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|,
literal|"qstandardpaths.pro"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|allFiles
operator|.
name|first
argument_list|()
argument_list|,
name|QString
argument_list|(
name|m_thisDir
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/qstandardpaths.pro"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testDataLocation
name|void
name|tst_qstandardpaths
operator|::
name|testDataLocation
parameter_list|()
block|{
comment|// On all platforms, DataLocation should be GenericDataLocation / organization name / app name
comment|// This allows one app to access the data of another app.
block|{
specifier|const
name|QString
name|base
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|app
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|DataLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|base
argument_list|,
name|app
argument_list|)
expr_stmt|;
block|}
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|setOrganizationName
argument_list|(
literal|"Qt"
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|setApplicationName
argument_list|(
literal|"QtTest"
argument_list|)
expr_stmt|;
block|{
specifier|const
name|QString
name|base
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|GenericDataLocation
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|app
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|DataLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|app
argument_list|,
name|base
operator|+
literal|"/Qt/QtTest"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testFindExecutable
name|void
name|tst_qstandardpaths
operator|::
name|testFindExecutable
parameter_list|()
block|{
comment|// Search for 'sh' on unix and 'cmd.exe' on Windows
ifdef|#
directive|ifdef
name|Q_OS_WIN
specifier|const
name|QString
name|exeName
init|=
literal|"cmd.exe"
decl_stmt|;
else|#
directive|else
specifier|const
name|QString
name|exeName
init|=
literal|"sh"
decl_stmt|;
endif|#
directive|endif
specifier|const
name|QString
name|result
init|=
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
name|exeName
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|QVERIFY
argument_list|(
name|result
operator|.
name|endsWith
argument_list|(
literal|"/cmd.exe"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QVERIFY
argument_list|(
name|result
operator|.
name|endsWith
argument_list|(
literal|"/bin/sh"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// full path as argument
name|QCOMPARE
argument_list|(
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
name|result
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
comment|// exe no found
name|QVERIFY
argument_list|(
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
literal|"idontexist"
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
literal|""
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// link to directory
specifier|const
name|QString
name|target
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QDir
operator|::
name|separator
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"link.lnk"
argument_list|)
decl_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|target
argument_list|)
expr_stmt|;
name|QFile
name|appFile
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|appFile
operator|.
name|link
argument_list|(
name|target
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
name|target
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|remove
argument_list|(
name|target
argument_list|)
expr_stmt|;
comment|// findExecutable with a relative path
ifdef|#
directive|ifdef
name|Q_OS_UNIX
specifier|const
name|QString
name|pwd
init|=
name|QDir
operator|::
name|currentPath
argument_list|()
decl_stmt|;
name|QDir
operator|::
name|setCurrent
argument_list|(
literal|"/bin"
argument_list|)
expr_stmt|;
name|QStringList
name|possibleResults
decl_stmt|;
name|possibleResults
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/bin/sh"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"/usr/bin/sh"
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|sh
init|=
name|QStandardPaths
operator|::
name|findExecutable
argument_list|(
literal|"./sh"
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|possibleResults
operator|.
name|contains
argument_list|(
name|sh
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|sh
argument_list|)
argument_list|)
expr_stmt|;
name|QDir
operator|::
name|setCurrent
argument_list|(
name|pwd
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testRuntimeDirectory
name|void
name|tst_qstandardpaths
operator|::
name|testRuntimeDirectory
parameter_list|()
block|{
specifier|const
name|QString
name|runtimeDir
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|RuntimeLocation
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|runtimeDir
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// Check that it can automatically fix permissions
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|QFile
name|file
argument_list|(
name|runtimeDir
argument_list|)
decl_stmt|;
specifier|const
name|QFile
operator|::
name|Permissions
name|wantedPerms
init|=
name|QFile
operator|::
name|ReadUser
operator||
name|QFile
operator|::
name|WriteUser
operator||
name|QFile
operator|::
name|ExeUser
decl_stmt|;
specifier|const
name|QFile
operator|::
name|Permissions
name|additionalPerms
init|=
name|QFile
operator|::
name|ReadOwner
operator||
name|QFile
operator|::
name|WriteOwner
operator||
name|QFile
operator|::
name|ExeOwner
decl_stmt|;
name|QCOMPARE
argument_list|(
name|file
operator|.
name|permissions
argument_list|()
argument_list|,
name|wantedPerms
operator||
name|additionalPerms
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|file
operator|.
name|setPermissions
argument_list|(
name|wantedPerms
operator||
name|QFile
operator|::
name|ExeGroup
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|runtimeDirAgain
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|RuntimeLocation
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|runtimeDirAgain
argument_list|,
name|runtimeDir
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QFile
argument_list|(
name|runtimeDirAgain
argument_list|)
operator|.
name|permissions
argument_list|()
argument_list|,
name|wantedPerms
operator||
name|additionalPerms
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|testCustomRuntimeDirectory
name|void
name|tst_qstandardpaths
operator|::
name|testCustomRuntimeDirectory
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_XDG_PLATFORM
name|qputenv
argument_list|(
literal|"XDG_RUNTIME_DIR"
argument_list|,
name|QFile
operator|::
name|encodeName
argument_list|(
literal|"/tmp"
argument_list|)
argument_list|)
expr_stmt|;
comment|// It's very unlikely that /tmp is 0600 or that we can chmod it
comment|// The call below outputs
comment|//   "QStandardPaths: wrong ownership on runtime directory /tmp, 0 instead of $UID"
comment|// but we can't reliably expect that it's owned by uid 0, I think.
specifier|const
name|uid_t
name|uid
init|=
name|geteuid
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QStandardPaths: wrong ownership on runtime directory /tmp, 0 instead of %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|uid
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|runtimeDir
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|RuntimeLocation
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|runtimeDir
operator|.
name|isEmpty
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|runtimeDir
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QStandardPaths::StandardLocation
argument_list|)
end_macro
begin_function
DECL|function|testAllWritableLocations_data
name|void
name|tst_qstandardpaths
operator|::
name|testAllWritableLocations_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStandardPaths
operator|::
name|StandardLocation
argument_list|>
argument_list|(
literal|"location"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DesktopLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|DesktopLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DocumentsLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|DocumentsLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"FontsLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|FontsLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ApplicationsLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|ApplicationsLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"MusicLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|MusicLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"MoviesLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|MoviesLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"PicturesLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|PicturesLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"TempLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|TempLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"HomeLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|HomeLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DataLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|DataLocation
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"DownloadLocation"
argument_list|)
operator|<<
name|QStandardPaths
operator|::
name|DownloadLocation
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testAllWritableLocations
name|void
name|tst_qstandardpaths
operator|::
name|testAllWritableLocations
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QStandardPaths
operator|::
name|StandardLocation
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|location
argument_list|)
expr_stmt|;
name|QStandardPaths
operator|::
name|displayName
argument_list|(
name|location
argument_list|)
expr_stmt|;
comment|// Currently all desktop locations return their writable location
comment|// with "Unix-style" paths (i.e. they use a slash, not backslash).
name|QString
name|loc
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|location
argument_list|)
decl_stmt|;
if|if
condition|(
name|loc
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
comment|// workaround for unlikely case of locations that return '/'
name|QCOMPARE
argument_list|(
name|loc
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qstandardpaths
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstandardpaths.moc"
end_include
end_unit
