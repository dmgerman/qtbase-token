begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qbuffer.h>
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
name|void
name|validateArgs
parameter_list|()
function_decl|;
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
name|generateQConfigCpp
parameter_list|()
function_decl|;
name|void
name|buildQmake
parameter_list|()
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
name|void
name|generateHeaders
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
name|void
name|generateQDevicePri
parameter_list|()
function_decl|;
name|void
name|prepareConfigTests
parameter_list|()
function_decl|;
name|void
name|showSummary
parameter_list|()
function_decl|;
name|QString
name|firstLicensePath
parameter_list|()
function_decl|;
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
name|bool
name|checkAngleAvailability
argument_list|(
name|QString
operator|*
name|errorMessage
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
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
name|allBuildParts
decl_stmt|;
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
name|skipModules
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
name|opensslLibsDebug
decl_stmt|;
name|QString
name|opensslLibsRelease
decl_stmt|;
name|QString
name|opensslPath
decl_stmt|;
name|QString
name|dbusPath
decl_stmt|;
name|QString
name|mysqlPath
decl_stmt|;
name|QString
name|psqlLibs
decl_stmt|;
name|QString
name|zlibLibs
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
name|void
name|substPrefix
parameter_list|(
name|QString
modifier|*
name|path
parameter_list|)
function_decl|;
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
name|QString
name|locateFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|bool
name|findFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
block|{
return|return
operator|!
name|locateFile
argument_list|(
name|fileName
argument_list|)
operator|.
name|isEmpty
argument_list|()
return|;
block|}
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
name|QStringList
modifier|&
name|paths
parameter_list|)
function_decl|;
name|void
name|reloadCmdLine
parameter_list|()
function_decl|;
name|void
name|saveCmdLine
parameter_list|()
function_decl|;
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
name|bool
name|compilerSupportsFlag
parameter_list|(
specifier|const
name|QString
modifier|&
name|compilerAndArgs
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
begin_decl_stmt
name|class
name|FileWriter
range|:
name|public
name|QTextStream
block|{
name|public
operator|:
name|FileWriter
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|bool
name|flush
argument_list|()
block|;
name|private
operator|:
name|QString
name|m_name
block|;
name|QBuffer
name|m_buffer
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
