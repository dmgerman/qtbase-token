begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* ** Configure tool ** */
end_comment
begin_include
include|#
directive|include
file|"configureapp.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|runConfigure
name|int
name|runConfigure
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Configure
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isOk
argument_list|()
condition|)
return|return
literal|3
return|;
name|app
operator|.
name|parseCmdLine
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
name|app
operator|.
name|validateArgs
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|app
operator|.
name|displayHelp
argument_list|()
condition|)
return|return
literal|1
return|;
comment|// Read license now, and exit if it doesn't pass.
comment|// This lets the user see the command-line options of configure
comment|// without having to load and parse the license file.
name|app
operator|.
name|readLicense
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isOk
argument_list|()
condition|)
return|return
literal|3
return|;
comment|// Auto-detect modules and settings.
name|app
operator|.
name|autoDetection
argument_list|()
expr_stmt|;
comment|// After reading all command-line arguments, and doing all the
comment|// auto-detection, it's time to do some last minute validation.
comment|// If the validation fails, we cannot continue.
if|if
condition|(
operator|!
name|app
operator|.
name|verifyConfiguration
argument_list|()
condition|)
return|return
literal|3
return|;
name|app
operator|.
name|generateOutputVars
argument_list|()
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVAL
argument_list|)
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|generateCachefile
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|generateBuildKey
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|generateConfigfiles
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|displayConfig
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|generateHeaders
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|buildQmake
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|generateMakefiles
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|buildHostTools
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isDone
argument_list|()
condition|)
name|app
operator|.
name|showSummary
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|app
operator|.
name|isOk
argument_list|()
condition|)
return|return
literal|2
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QT_USE_NAMESPACE
return|return
name|runConfigure
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
end_unit
