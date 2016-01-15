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
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
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
modifier|*
name|argv
parameter_list|)
block|{
name|QCoreApplication
name|ca
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QFile
name|f
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|input
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|qint64
name|len
decl_stmt|;
while|while
condition|(
operator|(
name|len
operator|=
name|f
operator|.
name|read
argument_list|(
name|buf
argument_list|,
literal|1024
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|input
operator|.
name|append
argument_list|(
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
name|QFile
name|f2
argument_list|(
literal|"fileWriterProcess.txt"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f2
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
name|f2
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|f2
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
name|f2
operator|.
name|write
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|f2
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
