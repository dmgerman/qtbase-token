begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_if
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
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<crtdbg.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// Windows: Suppress crash notification dialog.
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
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
name|_CrtSetReportMode
argument_list|(
name|_CRT_ERROR
argument_list|,
name|_CRTDBG_MODE_DEBUG
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QTcpServer
name|server
decl_stmt|;
if|if
condition|(
operator|!
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|,
literal|49199
argument_list|)
condition|)
block|{
name|qDebug
argument_list|(
literal|"Failed to listen: %s"
argument_list|,
name|server
operator|.
name|errorString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|QFile
name|file
argument_list|(
name|QLatin1String
argument_list|(
literal|"/test_signal.txt"
argument_list|)
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
literal|"Listening\n"
argument_list|)
expr_stmt|;
name|file
operator|.
name|flush
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"Listening\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|server
operator|.
name|waitForNewConnection
argument_list|(
literal|5000
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"Crash"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
