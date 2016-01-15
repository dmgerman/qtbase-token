begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<windows.h>
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
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QStringList
name|args
init|=
name|app
operator|.
name|arguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|args
operator|.
name|count
argument_list|()
operator|!=
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: testDetached filename.txt\n"
argument_list|)
expr_stmt|;
return|return
literal|128
return|;
block|}
name|QFile
name|f
argument_list|(
name|args
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open %s for writing: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|f
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|f
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|f
operator|.
name|write
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|.
name|toUtf8
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|.
name|putChar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
name|f
operator|.
name|write
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|quint64
argument_list|(
name|getpid
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|f
operator|.
name|write
argument_list|(
name|QByteArray
operator|::
name|number
argument_list|(
name|quint64
argument_list|(
name|GetCurrentProcessId
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|f
operator|.
name|putChar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
