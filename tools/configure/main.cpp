begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|app
operator|.
name|validateArgs
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
comment|// Source file with path settings. Needed by qmake.
name|app
operator|.
name|generateQConfigCpp
argument_list|()
expr_stmt|;
comment|// Bootstrapped includes. Needed by qmake.
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
name|isOk
argument_list|()
condition|)
return|return
literal|3
return|;
comment|// Bootstrap qmake. Needed by config tests.
name|app
operator|.
name|buildQmake
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
comment|// Generate qdevice.pri
name|app
operator|.
name|generateQDevicePri
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
comment|// Prepare the config test build directory.
name|app
operator|.
name|prepareConfigTests
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
name|generateQConfigPri
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
