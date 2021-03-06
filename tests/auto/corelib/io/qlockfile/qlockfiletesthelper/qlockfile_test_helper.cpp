begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure+bluesystems@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QLockFile>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
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
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|argc
operator|<=
literal|1
condition|)
return|return
operator|-
literal|1
return|;
specifier|const
name|QString
name|lockName
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
name|QString
name|option
decl_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
name|option
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|==
literal|"-crash"
condition|)
block|{
name|QLockFile
name|lockFile
argument_list|(
name|lockName
argument_list|)
decl_stmt|;
name|lockFile
operator|.
name|lock
argument_list|()
expr_stmt|;
comment|// exit on purpose, so that the lock remains!
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|option
operator|==
literal|"-busy"
condition|)
block|{
name|QLockFile
name|lockFile
argument_list|(
name|lockName
argument_list|)
decl_stmt|;
name|lockFile
operator|.
name|lock
argument_list|()
expr_stmt|;
name|QThread
operator|::
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
else|else
block|{
name|QLockFile
name|lockFile
argument_list|(
name|lockName
argument_list|)
decl_stmt|;
if|if
condition|(
name|lockFile
operator|.
name|isLocked
argument_list|()
condition|)
comment|// cannot happen, before calling lock or tryLock
return|return
name|QLockFile
operator|::
name|UnknownError
return|;
name|lockFile
operator|.
name|tryLock
argument_list|()
expr_stmt|;
return|return
name|lockFile
operator|.
name|error
argument_list|()
return|;
block|}
block|}
end_function
end_unit
