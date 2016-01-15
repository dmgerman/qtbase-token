begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"Test.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QStringList>
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
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QString
name|arg
decl_stmt|;
if|if
condition|(
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|arg
operator|=
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toLower
argument_list|()
operator|.
name|trimmed
argument_list|()
expr_stmt|;
name|Test
operator|::
name|Type
name|type
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"qt4client"
argument_list|)
condition|)
name|type
operator|=
name|Test
operator|::
name|Qt4Client
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"qt4server"
argument_list|)
condition|)
name|type
operator|=
name|Test
operator|::
name|Qt4Server
expr_stmt|;
else|else
block|{
name|qDebug
argument_list|(
literal|"usage: ./stressTest<qt4client|qt4server>"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|Test
name|test
argument_list|(
name|type
argument_list|)
decl_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
