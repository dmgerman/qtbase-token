begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
literal|"Cannot open %s for writing"
argument_list|,
name|qPrintable
argument_list|(
name|f
operator|.
name|fileName
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
