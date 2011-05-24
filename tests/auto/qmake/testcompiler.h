begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TESTCOMPILER_H
end_ifndef
begin_define
DECL|macro|TESTCOMPILER_H
define|#
directive|define
name|TESTCOMPILER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_enum
DECL|enum|BuildType
DECL|enumerator|Exe
DECL|enumerator|Dll
DECL|enumerator|Lib
DECL|enumerator|Plain
enum|enum
name|BuildType
block|{
name|Exe
block|,
name|Dll
block|,
name|Lib
block|,
name|Plain
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|TestCompiler
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|TestCompiler
argument_list|()
block|;
name|virtual
operator|~
name|TestCompiler
argument_list|()
block|;
name|void
name|setBaseCommands
argument_list|(
argument|QString makeCmd
argument_list|,
argument|QString qmakeCmd
argument_list|)
block|;
name|void
name|resetEnvironment
argument_list|()
block|;
name|void
name|addToEnvironment
argument_list|(
argument|QString varAssignment
argument_list|)
block|;
comment|// executes a make clean in the specified workPath
name|bool
name|makeClean
argument_list|(
specifier|const
name|QString
operator|&
name|workPath
argument_list|)
block|;
comment|// executes a make dist clean in the specified workPath
name|bool
name|makeDistClean
argument_list|(
specifier|const
name|QString
operator|&
name|workPath
argument_list|)
block|;
comment|// executes a qmake on proName in the specified workDir, output goes to buildDir or workDir if it's null
name|bool
name|qmake
argument_list|(
specifier|const
name|QString
operator|&
name|workDir
argument_list|,
specifier|const
name|QString
operator|&
name|proName
argument_list|,
specifier|const
name|QString
operator|&
name|buildDir
operator|=
name|QString
argument_list|()
argument_list|)
block|;
comment|// executes a make in the specified workPath, with an optional target (eg. install)
name|bool
name|make
argument_list|(
specifier|const
name|QString
operator|&
name|workPath
argument_list|,
specifier|const
name|QString
operator|&
name|target
operator|=
name|QString
argument_list|()
argument_list|)
block|;
comment|// checks if the executable exists in destDir
name|bool
name|exists
argument_list|(
argument|const QString&destDir
argument_list|,
argument|const QString&exeName
argument_list|,
argument|BuildType buildType
argument_list|,
argument|const QString&version
argument_list|)
block|;
comment|// removes the makefile
name|bool
name|removeMakefile
argument_list|(
specifier|const
name|QString
operator|&
name|workPath
argument_list|)
block|;
comment|// returns each line of stdout of the last command append with a "new line" character(s) to suit the platform
name|QString
name|commandOutput
argument_list|()
specifier|const
block|;
comment|// clear the results of storage of stdout for running previous commands
name|void
name|clearCommandOutput
argument_list|()
block|;
name|private
operator|:
name|bool
name|runCommand
argument_list|(
argument|QString cmdLine
argument_list|)
block|;
name|QString
name|makeCmd_
block|;
name|QString
name|qmakeCmd_
block|;
name|QStringList
name|environment_
block|;
comment|// need to make this available somewhere
name|QStringList
name|testOutput_
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TESTCOMPILER_H
end_comment
end_unit
