begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|MakeItem
name|class
name|MakeItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Configure
block|{
name|public
label|:
name|Configure
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|)
expr_stmt|;
operator|~
name|Configure
argument_list|()
expr_stmt|;
name|void
name|parseCmdLine
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|void
name|validateArgs
parameter_list|()
function_decl|;
endif|#
directive|endif
name|bool
name|displayHelp
parameter_list|()
function_decl|;
name|QString
name|defaultTo
parameter_list|(
specifier|const
name|QString
modifier|&
name|option
parameter_list|)
function_decl|;
name|bool
name|checkAvailability
parameter_list|(
specifier|const
name|QString
modifier|&
name|part
parameter_list|)
function_decl|;
name|void
name|autoDetection
parameter_list|()
function_decl|;
name|bool
name|verifyConfiguration
parameter_list|()
function_decl|;
name|void
name|generateOutputVars
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|void
name|generateHeaders
parameter_list|()
function_decl|;
name|void
name|generateBuildKey
parameter_list|()
function_decl|;
name|void
name|generateCachefile
parameter_list|()
function_decl|;
name|void
name|displayConfig
parameter_list|()
function_decl|;
name|void
name|buildQmake
parameter_list|()
function_decl|;
name|void
name|buildHostTools
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|generateMakefiles
parameter_list|()
function_decl|;
name|void
name|appendMakeItem
parameter_list|(
name|int
name|inList
parameter_list|,
specifier|const
name|QString
modifier|&
name|item
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|bool
name|copySpec
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|pfx
parameter_list|,
specifier|const
name|QString
modifier|&
name|spec
parameter_list|)
function_decl|;
name|void
name|generateConfigfiles
parameter_list|()
function_decl|;
name|void
name|detectArch
parameter_list|()
function_decl|;
name|void
name|generateQConfigPri
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|showSummary
parameter_list|()
function_decl|;
name|void
name|findProjects
parameter_list|(
specifier|const
name|QString
modifier|&
name|dirName
parameter_list|)
function_decl|;
name|QString
name|firstLicensePath
parameter_list|()
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|bool
name|showLicense
parameter_list|(
name|QString
name|licenseFile
parameter_list|)
function_decl|;
name|void
name|readLicense
parameter_list|()
function_decl|;
endif|#
directive|endif
name|QString
name|addDefine
parameter_list|(
name|QString
name|def
parameter_list|)
function_decl|;
enum|enum
name|ProjectType
block|{
name|App
block|,
name|Lib
block|,
name|Subdirs
block|}
enum|;
name|ProjectType
name|projectType
parameter_list|(
specifier|const
name|QString
modifier|&
name|proFileName
parameter_list|)
function_decl|;
name|bool
name|isDone
parameter_list|()
function_decl|;
name|bool
name|isOk
parameter_list|()
function_decl|;
name|int
name|platform
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|platformName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|qpaPlatformName
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|// Our variable dictionaries
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|dictionary
expr_stmt|;
name|QStringList
name|defaultBuildParts
decl_stmt|;
name|QStringList
name|buildParts
decl_stmt|;
name|QStringList
name|nobuildParts
decl_stmt|;
name|QStringList
name|licensedModules
decl_stmt|;
name|QStringList
name|allSqlDrivers
decl_stmt|;
name|QStringList
name|allConfigs
decl_stmt|;
name|QStringList
name|disabledModules
decl_stmt|;
name|QStringList
name|enabledModules
decl_stmt|;
name|QStringList
name|modules
decl_stmt|;
comment|//    QStringList sqlDrivers;
name|QStringList
name|configCmdLine
decl_stmt|;
name|QStringList
name|qmakeConfig
decl_stmt|;
name|QStringList
name|qtConfig
decl_stmt|;
name|QStringList
name|qmakeSql
decl_stmt|;
name|QStringList
name|qmakeSqlPlugins
decl_stmt|;
name|QStringList
name|qmakeStyles
decl_stmt|;
name|QStringList
name|qmakeStylePlugins
decl_stmt|;
name|QStringList
name|qmakeVars
decl_stmt|;
name|QStringList
name|qmakeDefines
decl_stmt|;
comment|//  makeList[0] for qt and qtmain
comment|//  makeList[1] for subdirs and libs
comment|//  makeList[2] for the rest
name|QList
operator|<
name|MakeItem
operator|*
operator|>
name|makeList
index|[
literal|3
index|]
expr_stmt|;
name|QStringList
name|qmakeIncludes
decl_stmt|;
name|QStringList
name|qmakeLibs
decl_stmt|;
name|QString
name|opensslLibs
decl_stmt|;
name|QString
name|psqlLibs
decl_stmt|;
name|QString
name|sybase
decl_stmt|;
name|QString
name|sybaseLibs
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|licenseInfo
expr_stmt|;
name|QString
name|outputLine
decl_stmt|;
name|QTextStream
name|outStream
decl_stmt|;
name|QString
name|sourcePath
decl_stmt|,
name|buildPath
decl_stmt|;
name|QDir
name|sourceDir
decl_stmt|,
name|buildDir
decl_stmt|;
comment|// Variables for usage output
name|int
name|optionIndent
decl_stmt|;
name|int
name|descIndent
decl_stmt|;
name|int
name|outputWidth
decl_stmt|;
name|QString
name|formatPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|QString
name|formatPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
function_decl|;
name|bool
name|filesDiffer
parameter_list|(
specifier|const
name|QString
modifier|&
name|file1
parameter_list|,
specifier|const
name|QString
modifier|&
name|file2
parameter_list|)
function_decl|;
name|bool
name|findFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|QString
name|findFileInPaths
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|paths
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|void
name|reloadCmdLine
parameter_list|()
function_decl|;
name|void
name|saveCmdLine
parameter_list|()
function_decl|;
endif|#
directive|endif
name|bool
name|tryCompileProject
parameter_list|(
specifier|const
name|QString
modifier|&
name|projectPath
parameter_list|,
specifier|const
name|QString
modifier|&
name|extraOptions
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|desc
parameter_list|(
specifier|const
name|char
modifier|*
name|description
parameter_list|,
name|int
name|startingAt
init|=
literal|0
parameter_list|,
name|int
name|wrapIndent
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|desc
parameter_list|(
specifier|const
name|char
modifier|*
name|option
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
name|bool
name|skipIndent
init|=
name|false
parameter_list|,
name|char
name|fillChar
init|=
literal|'.'
parameter_list|)
function_decl|;
name|void
name|desc
parameter_list|(
specifier|const
name|char
modifier|*
name|mark_option
parameter_list|,
specifier|const
name|char
modifier|*
name|mark
parameter_list|,
specifier|const
name|char
modifier|*
name|option
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
name|char
name|fillChar
init|=
literal|'.'
parameter_list|)
function_decl|;
name|void
name|applySpecSpecifics
parameter_list|()
function_decl|;
specifier|static
name|QString
name|locateFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|QString
name|locateFileInPaths
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|MakeItem
block|{
name|public
label|:
name|MakeItem
argument_list|(
argument|const QString&d
argument_list|,
argument|const QString&p
argument_list|,
argument|const QString&t
argument_list|,
argument|Configure::ProjectType qt
argument_list|)
block|:
name|directory
argument_list|(
name|d
argument_list|)
operator|,
name|proFile
argument_list|(
name|p
argument_list|)
operator|,
name|target
argument_list|(
name|t
argument_list|)
operator|,
name|qmakeTemplate
argument_list|(
argument|qt
argument_list|)
block|{ }
name|QString
name|directory
expr_stmt|;
name|QString
name|proFile
decl_stmt|;
name|QString
name|target
decl_stmt|;
name|Configure
operator|::
name|ProjectType
name|qmakeTemplate
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
